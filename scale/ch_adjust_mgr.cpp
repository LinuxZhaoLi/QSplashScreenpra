#include "ch_adjust_mgr.h"
#include "stdio.h"
#include "math.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <QDebug>
#include "fltrcd.h"
#include "BasicAlgorithm.h"

#define PI 3.1415926535897932384626433832795
#define RT_DATA_CYC_NUM 3       /*ÿ��ͨ�������ܲ���*/

ChAdjustMgr::ChAdjustMgr()
{
	int i;
    m_bDataValid = false;		    //�����Ƿ���Ч
	m_pDataBuff = NULL;

	for(i=0; i<AN_CH_MAX_VIRTUAL; i++)
	{	
		m_ChInputVal[i] = 0.01;	//����ֵ
    	m_ChOutputVal[i] = 0;	//���ֵ
		m_ChSelected[i] = 0;	//���Ҫ���ڵ�ͨ��
	}	
}

ChAdjustMgr::~ChAdjustMgr()
{
	//��������
	if (m_pDataBuff != NULL)
	{
		delete [] m_pDataBuff;
		m_pDataBuff = NULL;
	}
}

void ChAdjustMgr::Init( )
{
    //ͨ����12
//    pAnCfg->Offset = 0.0;
//    pAnCfg->Scaler = 0.0015f;
//    pAnCfg->Skew   = 0.0;
//    pAnCfg->Ratio  = 2200.0f;
    m_nAnChCnt = 16;
    //qDebug()<<"m_nAnChCnt:"<<m_nAnChCnt;
	for(int i=0; i<m_nAnChCnt; i++)
	{
       // m_Offset[i] = 0.0;
        //m_Scaler[i] = 0.0015;
        //m_Skew[i] = 0.0;
        //m_Offset0[i] = - m_Offset[i]/m_Scaler[i];

	}

    m_nPerCycPoint = 200;		//ÿ�ܲ���������
	m_nPtCount = RT_DATA_CYC_NUM * m_nPerCycPoint;	//ÿ��ͨ�����ݳ���
	m_rateFreq = 50;			//�����Ƶ��(50\60 Hz)

	m_bDataChanged = false;		//�����Ƿ��Ѿ�����
	ErrStr[0] = 0;				//������Ϣ

	if(m_pDataBuff == NULL)
	{
		m_pDataBuff = new char[m_nAnChCnt*m_nPtCount*sizeof(short)];
	}

	for(int i=0; i<m_nAnChCnt; i++)
	{
		m_pChData[i] = (short*)(m_pDataBuff + (i * m_nPtCount * sizeof(short)));
	}
};

bool ChAdjustMgr::GetRealtimeData(RT_CTL* rtCtl)
{
	int i, j;

	assert(m_pDataBuff != NULL);
    assert(rtCtl != NULL);
        assert( rtCtl->SmpBufAddr != NULL);



	//�Ӳ�����������ȡ����
	int pntbegin = rtCtl->CurSmpPntPos;
	pntbegin = (pntbegin + (rtCtl->CycCnt - 6) * rtCtl->SmpCntPerCyc) % rtCtl->SmpPntCnt;
	if(pntbegin > rtCtl->SmpPntCnt - 10 * rtCtl->SmpCntPerCyc )
	{
		pntbegin -= 10 * rtCtl->SmpCntPerCyc;
	}
	unsigned short *pDataSrc = (unsigned short *)(rtCtl->SmpBufAddr + pntbegin * rtCtl->SmpDataLenPerPnt + sizeof(YHFtimeval));
    assert(pDataSrc != NULL);
	for(j=0; j<m_nPtCount; j++)
	{
		for(i=0; i<m_nAnChCnt; i++)
		{
      m_pChData[i][j] = *(pDataSrc + i)-32768 ;	//ctm
  //   if(i==12){
     //  qDebug()<<12<< *(pDataSrc + i) ;
   // }


        }


		pDataSrc += (rtCtl->SmpDataLenPerPnt / 2);
	}
	m_bDataValid = true;

	return true;
}

//ch�Ӳ�����������ȡ���ݣ���������Ư����
void ChAdjustMgr::CalcOffset(short **pChData, float *pScaler, char *pChSelected, int nAnChCnt, int nPtCount, int nPerCycPoint, float *pOffset, float *pOffset0, float *pOutputVal)
{
	int i, j;
	double sum;

	assert(pChData != NULL
		&& nAnChCnt > 2
		&& nPtCount > nPerCycPoint
		&& pOutputVal != NULL);

	GetRealtimeData(g_rtCtl);


	for(i=0; i<nAnChCnt; i++)
    {
//        pChSelected[i]='1';
//		if (pChSelected[i])
//		{
            pScaler[i]=0.0015;
			sum = 0;
			for(j=0; j<nPtCount; j++)
			{
				sum += pChData[i][j];
			}
			sum /= nPtCount;
			pOffset0[i] = sum;

			pOffset[i] = - pScaler[i] * sum;

			//���ֵ
			sum = 0;
			for(j=0; j<nPerCycPoint; j++)
			{
				sum += (pChData[i][j] - pOffset0[i]) * (pChData[i][j] - pOffset0[i]);
			}
			sum /= nPerCycPoint;
			pOutputVal[i] = sqrt(sum) * pScaler[i] ;
//            if(i==1)
//               qDebug()<<"offeset"<<pOffset[i] ;

		}
    //}
}

// �������ϵ��
void ChAdjustMgr::CalcScaler(short **pChData, float *pInputVal, char *pChSelected, float *pOffset0, int nAnChCnt, int nPtCount, int nPerCycPoint, float *pScaler,float *pOffset,  float *pOutputVal)
{
	int i, j;
	double sum;

	assert(pChData != NULL
		&& nAnChCnt > 2
		&& nPtCount > nPerCycPoint
		&& pOutputVal != NULL);

	GetRealtimeData(g_rtCtl);

	for(i=0; i<nAnChCnt; i++)
	{
        if (pChSelected[i])
		{
			sum = 0;
			for(j=0; j<nPtCount; j++)
			{
				sum += (pChData[i][j] - pOffset0[i]) * (pChData[i][j] - pOffset0[i]);
			}
			sum = sqrt(sum/nPtCount);
			if (sum < 50)
			{
				continue;
				printf("Warning: ch[%d]: A/D = %f < 50, Too small\n", i+1, sum);
			}

			pScaler[i] = pInputVal[i] / sum;
			pOffset[i] = - pScaler[i] * pOffset0[i];

			//���ֵ
			sum = 0;
			for(j=0; j<nPerCycPoint; j++)
			{
				sum += (pChData[i][j] - pOffset0[i]) * (pChData[i][j] - pOffset0[i]);
			}
			sum /= nPerCycPoint;
			pOutputVal[i] = sqrt(sum) * pScaler[i];
           // printf("CalcScalerAN:%d__%d___pOutputVal:%lf---scale:%lf\r\n",nAnChCnt,i,pOutputVal[i],pScaler[i]);
		}
	}
}

// ����ǲ�
//void ChAdjustMgr::CalcSkew(short **pChData, char *pChSelected, int nAnChCnt, int nPtCount, int nPerCycPoint, float *pSkew, float *pOutputVal)
//{
//	int i;
//	float tempValue[2], firstAng = 0;
//	BasicAlgorithm ba;

//	assert(pChData != NULL
//		&& nAnChCnt > 2
//		&& nPtCount > nPerCycPoint
//		&& pOutputVal != NULL);

//	GetRealtimeData(g_rtCtl);

//	//�������
//	for(i=0; i<nAnChCnt; i++)
//	{
//		if (pChSelected[i])
//		{
//			ba.SHGetHarmonic(pChData[i], 1, nPerCycPoint, 1, 1, tempValue );
//			if (tempValue[0] < 50)
//			{
//				pOutputVal[i] = 888;
//				printf("Warning: ch %d, A/D = %f < 50, Too small\n", i+1, tempValue[0]);
//			}
//			pOutputVal[i] = tempValue[1];	//ctm ��ξ�ȷ��
//		}
//		//printf("Warning: ch %d, A/D = %f��%.3f\n", i+1, tempValue[0], tempValue[1]);
//	}

//	//�ҵ�һ���ο���
//	for (i=0; i<nAnChCnt; i++)
//	{
//		if (pChSelected[i])
//		{
//			firstAng = pOutputVal[i];
//			break;
//		}
//	}

//	//ȫ�����һ��ͨ���Ƚ�У��
//	for (i=0; i<nAnChCnt; i++)	//ctm
//	{
//		if ( pChSelected[i] )
//		{
//			pOutputVal[i] -= firstAng;

//			//Խ�粹��
//			if (pOutputVal[i] > 20 || pOutputVal[i] < -20)
//			{
//				pOutputVal[i] = (pOutputVal[i]>0) ? pOutputVal[i]-360 : pOutputVal[i]+360;
//			}

//			//����20����Ϊ��Ч
//			if (pOutputVal[i] > 20 || pOutputVal[i] < -20)
//			{
//				pOutputVal[i] = 0;
//			}
//			pSkew[i] = pOutputVal[i] * 20000.0 / 360;	//ctm us
//		}
//	}
//}
