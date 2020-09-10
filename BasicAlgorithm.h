#ifndef BasicAlgorithm_H
#define BasicAlgorithm_H

#ifdef PRAGMA
#pragma interface "BasicAlgorithm.h"
#endif

/* {{{USR
******************************************************************************
* Copyright (c) 2008,������Ԫ�������������޹�˾�з���
* All rights reserved.
* 
* �ļ����ƣ�BasicAlgorithm.h
* �ļ���ʶ�������ù���ƻ���
* ժ    Ҫ�������㷨��
* 
* ��ǰ�汾��1.1
* ��    �ߣ�������
* ������ڣ�2008��5��12��
*
* ȡ���汾��1.0
* ԭ����  ��������
* ������ڣ�2007��5��10��
******************************************************************************
   }}}USR */

//#include <Experts.h>
//#include <ComplexEx.h>
#include"yhftypes.h"
#pragma pack(1)

struct SHComplex
{
	FLOAT64 re;
	FLOAT64 im;
	FLOAT64 mag; 
	FLOAT64 arg;
}; 

#pragma pack()

class BasicAlgorithm
{
public:
	/* {{{USR
	******************************************************************************
	  Function:     //BOOL SHGetSequence( FLOAT32 * pData[3], INT32 perCycPoints, FLOAT32 * pSequence )
	  Description:  //��������������಻ƽ���
	  Input:        //����pData[3]�������ݡ�perCycPointsÿ���ڵ���
	  Output:       //FLOAT32 *pSequence��pSequence[0��2��4]Ϊ����������Чֵ
					//pSequence[1��3��5]Ϊ����������ǣ���0->360��
					//pSequence[6]Ϊ���಻ƽ���
	  Return:       //BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pSequence��Ҫ��������������ռ�FLOAT32[7]
	******************************************************************************
	   }}}USR */
	BOOL SHGetSequence( FLOAT32 * pData[3], INT32 perCycPoints, FLOAT32 * pSequence );
	/* {{{USR
	******************************************************************************
	  Function:     //BOOL SHGetSequence( INT16 * pData[3], INT32 perCycPoints, FLOAT32 * pSequence )
	  Description:  //��������������಻ƽ���
	  Input:        //����pData[3]�������ݡ�perCycPointsÿ���ڵ���
	  Output:       //FLOAT32 *pSequence��pSequence[0��2��4]Ϊ����������Чֵ
					//pSequence[1��3��5]Ϊ����������ǣ���0->360��
					//pSequence[6]Ϊ���಻ƽ���
	  Return:       //BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pSequence��Ҫ��������������ռ�FLOAT32[7]
	******************************************************************************
	   }}}USR */
	BOOL SHGetSequence( INT16 * pData[3], FLOAT32 * multiplier, INT32 perCycPoints, FLOAT32 * pSequence );

	/* {{{USR
	******************************************************************************
	  Function:		//BOOL SHGetHarmonic( FLOAT32 * pData, INT32 maxNum, INT32 perCycPoints, FLOAT32 * pHarmonic )
	  Description:	//г�����㣬����0-��maxNum��г������0-ֱ������1-������
	  Input:		//FLOAT32 *pData��һ�ܲ����ݿ�ʼ��ַ
					//INT32 maxNum���������г��������������0'maxNum��г�������
					//INT32 perCycPoints��һ�ܲ�����
	  Output:		//FLOAT32 *pHarmonic��pHarmonic[2n]��n��г����Чֵ��pHarmonic[2n+1]��n��г����λ�ǣ�n��0��maxNum
					//pHarmonic[0]ֱ����pHarmonic[1]THDֵ��pHarmonic[2]������Чֵ��pHarmonic[3] ������λ��(0->360��)
	  Return:		//BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pHarmonic��Ҫ��������������ռ�FLOAT32[2*maxNum+2]
	******************************************************************************
	   }}}USR */
	BOOL SHGetHarmonic( FLOAT32 * pData, INT32 maxNum, INT32 perCycPoints, FLOAT32 * pHarmonic );

	/* {{{USR
	******************************************************************************
	  Function:		//BOOL SHGetHarmonic( INT16 * pData, FLOAT32 multiplier, INT32 perCycPoints, INT32 beginNum, INT32 maxNum, FLOAT32 * pHarmonic )
	  Description:	//г�����㣬����beginNum��maxNum��г������0-ֱ������1-������
	  Input:		//FLOAT32 *pData��һ�ܲ����ݿ�ʼ��ַ
					//multiplier:����ϵ��
					//INT32 beginNum����ʼ�����г��������������0'maxNum��г�������
					//INT32 maxNum���������г��������������0'maxNum��г�������
					//INT32 perCycPoints��һ�ܲ�����
	  Output:		//FLOAT32 *pHarmonic��pHarmonic[2n]�ڣ�n+beginNum����г����Чֵ��pHarmonic[2n+1]�ڣ�n+beginNum����г����λ��(0->360��)��n��0��maxNum
	  Return:		//BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pHarmonic��Ҫ��������������ռ�FLOAT32[2*��maxNum-beginNum��+2]
	******************************************************************************
	   }}}USR */
        BOOL SHGetHarmonic( /*INT16 **/unsigned short * pData, FLOAT32 multiplier, INT32 perCycPoints, INT32 beginNum, INT32 maxNum, FLOAT32 * pHarmonic );

	/* {{{USR
	******************************************************************************
	  Function:		//BOOL SHGetHarmonic( INT16 * pData, FLOAT32 multiplier, INT32 perCycPoints, INT32 beginNum, INT32 maxNum, FLOAT32 * pHarmonic )
	  Description:	//г�����㣬����0-��maxNum��г������0-ֱ������1-������
	  Input:		//FLOAT32 *pData��һ�ܲ����ݿ�ʼ��ַ
					//INT32 beginNum����ʼ�����г��������������0'maxNum��г�������
					//INT32 maxNum���������г��������������0'maxNum��г�������
					//INT32 perCycPoints��һ�ܲ�����
	  Output:		//FLOAT32 *pHarmonic��pHarmonic[2n]�ڣ�n+beginNum����г����Чֵ��pHarmonic[2n+1]�ڣ�n+beginNum����г����λ��(0->360��)��n��0��maxNum
	  Return:		//BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pHarmonic��Ҫ��������������ռ�FLOAT32[2*��maxNum-beginNum��+2]
	******************************************************************************
	   }}}USR */
	BOOL SHGetHarmonic( FLOAT32 * pData, INT32 perCycPoints, INT32 beginNum, INT32 maxNum, FLOAT32 * pHarmonic );

	/* {{{USR
	*****************************************************************************
	*/
	/* {{{USR
	******************************************************************************
	  Function:		//BOOL SHGetPower( FLOAT32 * pDataU, FLOAT32 * pDataI, INT32 perCycPoints, FLOAT32 * pPower )
	  Description:	//�����й����޹������ڡ��������ء�����
	  Input:		//FLOAT32 *pDataU, *pDataI��һ�ܲ���ѹ��������ֵ��ַ
					//INT32 perCycPoints��ÿ�ܲ���������
					//FLOAT32 Channel_Skew: ͬ������ʱ����ѹ-������
	  Output:		//FLOAT32 *pPower�����δ�Ź��ʣ�power[0]�й���power[1]�޹���power[2]���ڹ��ʡ�power[3]�������ء�power[4]�Զȱ�ʾ�Ĺ��ǣ�
	  Return:		//BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pPower��Ҫ��������������ռ�FLOAT32[5]
	******************************************************************************
	   }}}USR */
	BOOL SHGetPower( FLOAT32 * pDataU, FLOAT32 * pDataI, FLOAT32 Channel_Skew, INT32 perCycPoints, FLOAT32 * pPower );
	/* {{{USR
	******************************************************************************
	  Function:		//BOOL SHGetPower(  INT16 * pDataU, INT16 * pDataI, FLOAT32 Channel_Skew, INT32 perCycPoints, FLOAT32 * pPower  )
	  Description:	//�����й����޹������ڡ��������ء�����
	  Input:		//INT16 *pDataU, *pDataI��һ�ܲ���ѹ��������ֵ��ַ
					//INT32 perCycPoints��ÿ�ܲ���������
					//FLOAT32 Channel_Skew: ͬ������ʱ����ѹ-������
	  Output:		//FLOAT32 *pPower�����δ�Ź��ʣ�power[0]�й���power[1]�޹���power[2]���ڹ��ʡ�power[3]�������ء�power[4]�Զȱ�ʾ�Ĺ��ǣ�
	  Return:		//BOOL������ɹ�����True��ʧ�ܷ���False
	  Others:		//pPower��Ҫ��������������ռ�FLOAT32[5]
	******************************************************************************
	   }}}USR */
	BOOL SHGetPower( INT16 * pDataU, INT16 * pDataI, FLOAT32 Channel_Skew, INT32 perCycPoints, FLOAT32 * pPower );
	/* {{{USR
	******************************************************************************
	  Function:     //FLOAT32 SHGetFrequency( FLOAT32 * pData, INT32 smpRate )
	  Description:  //����Ƶ��
	  Input:        //pData�������ݡ�smpRate����Ƶ��
	  Output:       //��
	  Return:       //��� frequency������Ƶ�ʽ��
	  Others:		//pData�������ݱ������3���ܲ�  
	******************************************************************************
	   }}}USR */
	FLOAT32 SHGetFrequency( FLOAT32 * pData, INT32 smpRate );
	/* {{{USR
	******************************************************************************
	  Function:     //FLOAT32 SHGetFrequency( INT16 * pData, INT32 smpRate )
	  Description:  //����Ƶ��
	  Input:        //pData�������ݡ�smpRate����Ƶ��
	  Output:       //��
	  Return:       //��� frequency������Ƶ�ʽ��
	  Others:		//pData�������ݱ������3���ܲ�  
	******************************************************************************
	   }}}USR */
	FLOAT32 SHGetFrequency( INT16 * pData, INT32 smpRate );
	/* {{{USR
	******************************************************************************
	  Function:     //FLOAT32 SHGetRmsAmp( INT16 * pData, FLOAT32 multiplier, FLOAT32 offset, INT32 perCycPoints )
	  Description:  //������Чֵ
	  Input:        //pDATA�������ݡ�multiplier����ϵ����offset Comtrade��ʽ��Ư��perCycPointsÿ�ܲ�����
	  Output:       //�� 
	  Return:       //��Чֵ
	  Others:		//pData 1�����ڲ�������
	******************************************************************************
	   }}}USR */
        FLOAT32 SHGetRmsAmp(INT16 * pData, FLOAT32 multiplier, FLOAT32 offset, INT32 perCycPoints );
	/* {{{USR
	******************************************************************************
	  Function:     //FLOAT32 SHGetRmsAmp( FLOAT32 * pData, INT32 perCycPoints, int nType )
	  Description:  //������Чֵ
	  Input:        //pDATA��������, perCycPointsÿ�ܲ�����;
					//int nType:ͨ������
					//1��ʾ������ѹ, 2 ��ʾ��������, 3��ʾ��Ƶ, 4 ��ʾֱ����5 ��������
	  Output:       //�� 
	  Return:       //��Чֵ
	  Others:		//pData 1�����ڲ������ݣ�����0.07 ֱ��0.2���·���(ֱ���ͻ�������)
	******************************************************************************
	   }}}USR */
	FLOAT32 SHGetRmsAmp( FLOAT32 * pData, INT32 perCycPoints, INT32 nChType );
	/* {{{USR
	******************************************************************************
	  Function:     //void SHGetAnotherTime( YHFTmStruct srcTime, FLOAT64 relativeTime, YHFTmStruct & destTime )
	  Description:  //�������ʱ��
	  Input:        //srcTime: ��ʼʱ��, relativeTime:���ʱ��(��λ:ms)
	  Output:       //destTime: ����ʱ��(srcTime��relativeTime֮��) 
	  Return:       //��
	  Others:		//��
	******************************************************************************
	   }}}USR */
	void SHGetAnotherTime( YHFTmStruct srcTime, FLOAT64 relativeTime, YHFTmStruct & destTime );
	/* {{{USR
	******************************************************************************
	  Function:     //FLOAT32 SHGetMeanValue( INT16 * pData, FLOAT32 multiplier, FLOAT32 offset, INT32 perCycPoints )
	  Description:  //����ƽ��ֵ
	  Input:        //pDATA�������ݡ�multiplier����ϵ����offset Comtrade��ʽ��Ư��perCycPointsÿ�ܲ�����
	  Output:       //�� 
	  Return:       //ƽ��ֵ
	  Others:		//pData 1�����ڲ�������
	******************************************************************************
	   }}}USR */
        FLOAT32 SHGetMeanValue( /*INT16 **/unsigned short * pData, FLOAT32 multiplier, FLOAT32 offset, INT32 perCycPoints );
	/* {{{USR
	******************************************************************************
	  Function:     //FLOAT32 SHGetMeanValue( FLOAT32 * pData, INT32 perCycPoints )
	  Description:  //����ƽ��ֵ
	  Input:        //pDATA�������ݡ�perCycPointsÿ�ܲ�����
	  Output:       //�� 
	  Return:       //ƽ��ֵ
	  Others:		//pData 1�����ڲ�������
	******************************************************************************
	   }}}USR */
	FLOAT32 SHGetMeanValue( FLOAT32 * pData, INT32 perCycPoints );
	/******************************************************************************
	Function:		//FLOAT32 SHGetDecayTimeConstant ( FLOAT32 * pData, INT32 length, INT32 smpRate)
	Description:	//������ڷ���˥��ʱ�䳣��
	Input:			//FLOAT32 * pData: ͨ�����ݿ�ʼ��ַ
					//INT32 length: ���ݵ㳤��
					//INT32 smpRate: ����Ƶ��
	Output:			//��
	Return:			//FLOAT32: �����ڷ���˥��ʱ�䳣�� (-1Ϊ��Ч)
	Others:			//���ݳ���Ϊ3.5 - 15.5�ܲ�������Ӧ��Ϊ������˥���������ݣ���Ч����-1
	******************************************************************************/
	FLOAT32 SHGetDecayTimeConstant ( FLOAT32 * pData, INT32 length, INT32 smpRate);
};

#endif /* BasicAlgorithm_H */
