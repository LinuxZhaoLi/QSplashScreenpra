/*************************************************************************
* Copyright (c) 2011,������Ԫ�������������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		�����㷨������ʵ��
 	
	\author		chen
	\version	1.0
	\date		2011-12-22
	
	ʵ��һЩ�������㷨����
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "calc_def.h"

#if 1
	#define	dbg_printf(argv)	printf argv; printf("\n");
#else
	#define	dbg_printf(argv)
#endif

#define SQRT2		(1.4142135f)
static FLOAT32		gs_cosf[128];						//����ϵ��������Ƶ�ʼ���
static FLOAT32		gs_sinf[128];						//����ϵ��������Ƶ�ʼ���

/*!
	\brief	����DFT�����������������ϵ�������ڷ�ֵ���㣬���ڶƵ��
	\param	psinf		[out]	����ϵ����
	\param	pcosf		[out]	����ϵ����
	\param	k			[in]	г������
	\param  sampleNum	[in]	ÿ�ܲ��ļ������
*/
void init_coefficient_table( float* pcosf, float* psinf, int k, int sampleNum)
{
	int i;
	float miVar = (float)( 2 * k * PI / sampleNum);

	for ( i = 0; i < sampleNum; i++ )
	{
		*pcosf = (float)cos( i * miVar ) ;	
		*psinf = (float)sin( i * miVar );
		pcosf++;
		psinf++;
	}
}

/*!
	\brief	����DFT�����������������ϵ��������Ƶ�ʼ���
	\param	psinf	[out]	����ϵ����
	\param	pcosf	[out]	����ϵ����
	\param	N		[in]	ϵ�������
	\param  sample  [in]    ÿ�ܵ�ʵ�ʲ�������������ʱ�����̶�ʱ����ϵͳƵ�ʱ仯���仯
*/
void coefficient_table( float* pcosf, float* psinf, int N, float sampleNum )
{
	int i;

	float miVar = (float)( 2 * PI / sampleNum );

	for ( i = 0; i < N; i++ )
	{
		*pcosf = (float)cos( i * miVar ) ;	
		*psinf = (float)sin( i * miVar );
		pcosf++;
		psinf++;
	}
}


/*!
	\brief	��ʼ��DFT�����������������ϵ����
	\param	pcoeff	[in]	ϵ������ʼ��ַ
	\param	k		[in]	г������
	\param	N		[in]	ÿ�ܲ���������
	\param  skew    [in]    �Ƕ�ƫ��
*/
void init_coefficient_table_angle( float* pcoeff, int k, int N, float skew )
{
	int i;

	for ( i = 0; i < N; i++, pcoeff++ )
	{
		*pcoeff = (float)sin( k*i*2*PI/N + skew/k);		//����ϵ��
	}

	for ( i = 0; i < N; i++, pcoeff++ )
	{
		*pcoeff = (float)cos( k*i*2*PI/N + skew/k) ;	//����ϵ��
	}
}

/*!
	\brief	����DFT�����������������ϵ����
	\param	k		[in]	г������
	\param	N		[in]	ÿ�ܲ���������
	\param  skew    [in]    �Ƕ�ƫ��
*/
float* creat_coefficient_table( int k, int N, float skew )
{
	float *pfdata; 
	pfdata = (float*)malloc( 2 * N * sizeof(float) );
	if ( pfdata == NULL )
		return NULL;
			
	init_coefficient_table_angle( pfdata, k, N, skew );
	return pfdata;
}


/*!
	\brief	�Ľ�DFT���㣬���������5�Ρ�9��г��
	\param	pfSrc		[in]	����������ʼ��ַ
	\param  pcosf		[in]	����ϵ����
	\param	psinf		[in]	����ϵ����
	\param	quarterNum	[in]	�ֱ��Ӧ�ķ�֮һ�ܲ������ܲ����ķ�֮���ܲ���һ�ܲ��������
	\param	k			[in]	г����������Ӧ�ڻ�����5��9��г��
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void improved_DFT159( float* pfSrc, float* pcosf, float* psinf, int* quarterNum, COMPLEX_R* pComplex )
{
	int i = 1;
	
	pComplex->Real = pComplex->Imag = 0;
	
	for ( ; i< *quarterNum; i++)
	{
		pComplex->Imag += *(pcosf+i) * ( *(pfSrc+i) - *(pfSrc+*(quarterNum+1)-i) - *(pfSrc+*(quarterNum+1)+i) + *(pfSrc+*(quarterNum+3)-i) );
		pComplex->Real += *(psinf+i) * ( *(pfSrc+i) + *(pfSrc+*(quarterNum+1)-i) - *(pfSrc+*(quarterNum+1)+i) - *(pfSrc+*(quarterNum+3)-i) );
	}

	//����λ���ķ�֮һ�ܲ����������
	pComplex->Imag += *pfSrc - *(pfSrc+*(quarterNum+1));
	pComplex->Real += *(pfSrc+*quarterNum) - *(pfSrc+*(quarterNum+2));

	pComplex->Real = SQRT2 * pComplex->Real / *(quarterNum+3);
	pComplex->Imag = SQRT2 * pComplex->Imag / *(quarterNum+3);
	pComplex->Rms  = (float)( sqrt( pComplex->Real * pComplex->Real + pComplex->Imag * pComplex->Imag ) );
}

/*!
	\brief	�Ľ�DFT���㣬����3��7��г��
	\param	pfSrc		[in]	����������ʼ��ַ
	\param  pcosf		[in]	����ϵ����
	\param	psinf		[in]	����ϵ����
	\param	quarterNum	[in]	�ֱ��Ӧ�ķ�֮һ�ܲ������ܲ����ķ�֮���ܲ���һ�ܲ��������
	\param	k			[in]	г����������Ӧ��3��7��г��
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void improved_DFT37( float* pfSrc, float* pcosf, float* psinf, int* quarterNum, COMPLEX_R* pComplex )
{
	int i = 1;
	
	pComplex->Real = pComplex->Imag = 0;
	
	for ( ; i< *quarterNum; i++)
	{
		pComplex->Imag += *(pcosf+i) * ( *(pfSrc+i) - *(pfSrc+*(quarterNum+1)-i) - *(pfSrc+*(quarterNum+1)+i) + *(pfSrc+*(quarterNum+3)-i) );
		pComplex->Real += *(psinf+i) * ( *(pfSrc+i) + *(pfSrc+*(quarterNum+1)-i) - *(pfSrc+*(quarterNum+1)+i) - *(pfSrc+*(quarterNum+3)-i) );
	}

	//����λ���ķ�֮һ�ܲ����������
	pComplex->Imag += *pfSrc - *(pfSrc+*(quarterNum+1));
	pComplex->Real += -*(pfSrc+*quarterNum) + *(pfSrc+*(quarterNum+2));

	pComplex->Real = SQRT2 * pComplex->Real / *(quarterNum+3);
	pComplex->Imag = SQRT2 * pComplex->Imag / *(quarterNum+3);
	pComplex->Rms  = (float)( sqrt( pComplex->Real * pComplex->Real + pComplex->Imag * pComplex->Imag ) );
}


/*!
	\brief	�Ľ�DFT��ֻ�������г��
	\param	pfSrc		[in]	����������ʼ��ַ
	\param  pcosf		[in]	����ϵ����
	\param	psinf		[in]	����ϵ����
	\param	quarterNum	[in]	�ֱ��Ӧ�ķ�֮һ�ܲ������ܲ����ķ�֮���ܲ���һ�ܲ��������
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void improved_DFT2( float* pfSrc, float* pcosf, float* psinf, int* quarterNum, COMPLEX_R* pComplex )
{
	int i = 1;

	pComplex->Real = pComplex->Imag = 0;

	for ( ; i< *quarterNum; i++)
	{
		pComplex->Imag += *(pcosf+i) * ( *(pfSrc+i) - *(pfSrc+*quarterNum+i) + *(pfSrc+*(quarterNum+1)+i) - *(pfSrc+*(quarterNum+2)+i) );
		pComplex->Real += *(psinf+i) * ( *(pfSrc+i) - *(pfSrc+*quarterNum+i) + *(pfSrc+*(quarterNum+1)+i) - *(pfSrc+*(quarterNum+2)+i) );
	}
	
	pComplex->Imag +=  *pfSrc - *(pfSrc+*quarterNum) + *(pfSrc+*(quarterNum+1)) - *(pfSrc+*(quarterNum+2));

	pComplex->Real = SQRT2 * pComplex->Real / *(quarterNum+3);
	pComplex->Imag = SQRT2 * pComplex->Imag / *(quarterNum+3);
	pComplex->Rms  = (float)( sqrt( pComplex->Real * pComplex->Real + pComplex->Imag * pComplex->Imag ) );
}


/*!
	\brief	DFT���㣬����ʵ�� �鲿����Чֵ, г����Чֵ��������Ƶ�ʵ��ڶƵ�����
	\param	pfSrc		[in]	����������ʼ��ַ
	\param	pcoeff		[in]	������ϵ�����׵�ַ
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void calc_DFT( float* pfSrc, float* pCoeff, COMPLEX_R* pComplex )
{
	int     i;
	float	*pfData, *cosAdr, *sinAdr;
	float	ak = 0.0, bk = 0.0;          

	pfData = pfSrc;
	cosAdr = pCoeff;
	sinAdr = pCoeff + DFT_PNT_CNT_PER_CYC;
	for (i = 0; i < DFT_PNT_CNT_PER_CYC; i++)			
	{	
		ak += (*cosAdr) * (*pfData);						/*! DFT����ʵ�� */
		bk += (*sinAdr) * (*pfData);						/*! DFT�����鲿 */
		cosAdr++;
		sinAdr++;
		pfData++;
	}

	pComplex->Real =   SQRT2 * bk / DFT_PNT_CNT_PER_CYC;
	pComplex->Imag =   SQRT2 * ak / DFT_PNT_CNT_PER_CYC;	
	pComplex->Rms  = (float)( sqrt( pComplex->Real * pComplex->Real + pComplex->Imag * pComplex->Imag ) );	
}

/*!
	\brief	�����ܲ�������ǲ���㣬������Ƶ�ʲ����ڶƵ�����
	\param	prevSrc			[in]	��һ�ܲ���������
	\param  curSrc			[in]	��ǰ�ܲ���������
	\param  nextSrc			[in]	��һ�ܲ���������
	\param	idxU			[in]	A��B��C�����ѹͨ����
	\param	sampleNum		[in]	ÿ�ܲ��������
	\param	prevFreq		[in]	��һ�ܲ�Ƶ��
	\param  ratedFreq		[in]	�Ƶ��
	\param	curAngle		[out]	ָ���������ָ��
*/
FLOAT32 calc_pos_angle( FLOAT32* prevSrc, FLOAT32* curSrc,FLOAT32* nextSrc, INT16* idxU, INT16 sampleNum, FLOAT32 prevFreq, INT32 ratedFreq)
{
	int			i, j, iCnt, iDif;
	float		*prevData, *curData, *pf_cosf, *pf_sinf, fcnt;
	float		prev_real[3], prev_imag[3], cur_real[3], cur_imag[3], prev_pos_real, prev_pos_imag, cur_pos_real, cur_pos_imag;          
	
	if ( prevFreq >= (0.5*ratedFreq) )
		fcnt = (float)(ratedFreq * sampleNum / prevFreq );	
	else
		fcnt = sampleNum;

	coefficient_table( gs_cosf, gs_sinf, (int)( fcnt + 1 ), fcnt);	
	
	iCnt = (int)fcnt;
	
	for (j=0; j<3; j++)
	{
		prev_real[j] = 0;
		prev_imag[j] = 0;
		cur_real[j] = 0;
		cur_imag[j] = 0;

		pf_cosf = gs_cosf;
		pf_sinf = gs_sinf;
		prevData = prevSrc + *(idxU + j) * sampleNum;
		curData  = curSrc + *(idxU + j) * sampleNum;

		if ( fcnt < sampleNum )										/*! Ƶ�ʴ��ڶֵ��ʵ�ʵ���С�ڲ������� */
		{
			for (i=0; i<iCnt; i++)			
			{	
				prev_real[j] += (*pf_sinf) * (*prevData);							
				prev_imag[j] += (*pf_cosf) * (*prevData);	
				cur_real[j]  += (*pf_sinf) * (*curData);							
				cur_imag[j]  += (*pf_cosf) * (*curData);

				pf_cosf++;
				pf_sinf++;
				prevData++;
				curData++;
			}
		}
		else														/*! Ƶ��С�ڶֵ��ʵ�ʵ������ڲ������� */
		{
			iDif = iCnt - sampleNum;
			for (i=0; i< sampleNum; i++)			
			{	
				prev_real[j] += (*pf_sinf) * (*prevData);							
				prev_imag[j] += (*pf_cosf) * (*prevData);	
				cur_real[j]  += (*pf_sinf) * (*curData);							
				cur_imag[j]  += (*pf_cosf) * (*curData);

				pf_cosf++;
				pf_sinf++;
				prevData++;
				curData++;
			}

			prevData = curSrc + *(idxU + j) * sampleNum;
			curData  = nextSrc + *(idxU + j) * sampleNum;

			for (i=0; i<iDif; i++)
			{
				prev_real[j] += (*pf_sinf) * (*prevData);							
				prev_imag[j] += (*pf_cosf) * (*prevData);	
				cur_real[j]  += (*pf_sinf) * (*curData);							
				cur_imag[j]  += (*pf_cosf) * (*curData);

				pf_cosf++;
				pf_sinf++;
				prevData++;
				curData++;
			}
		}

		//�������һ����
		prev_real[j] += (fcnt - iCnt) * (*pf_sinf) * (*prevData) ;
		prev_imag[j] += (fcnt - iCnt) * (*pf_cosf) * (*prevData);
		cur_real[j]  += (fcnt - iCnt) * (*pf_sinf) * (*curData) ;
		cur_imag[j]  += (fcnt - iCnt) * (*pf_cosf) * (*curData);	
	}
	
	prev_pos_real = SEQT0 * prev_real[0] - SEQT1 * (prev_real[1] + prev_real[2]) - SEQT2 * ( prev_imag[1] - prev_imag[2]);
	prev_pos_imag = SEQT0 * prev_imag[0] - SEQT1 * (prev_imag[1] + prev_imag[2]) + SEQT2 * ( prev_real[1] - prev_real[2]);
	cur_pos_real  = SEQT0 * cur_real[0] - SEQT1 * (cur_real[1] + cur_real[2]) - SEQT2 * ( cur_imag[1] - cur_imag[2]);
	cur_pos_imag  = SEQT0 * cur_imag[0] - SEQT1 * (cur_imag[1] + cur_imag[2]) + SEQT2 * ( cur_real[1] - cur_real[2]);

	return atan2(cur_pos_imag, cur_pos_real) - atan2(prev_pos_imag, prev_pos_real);

	//pComplex->Real = 2 * ak / fCnt;
	//pComplex->Imag = - 2 * bk / fCnt;	
	//pComplex->Rms  = (float)( sqrt( pComplex->Real * pComplex->Real + pComplex->Imag * pComplex->Imag ) );	
}



/*!
	\brief	DFT���㣬����ʵ�� �鲿����Чֵ, г����Чֵ��������Ƶ�ʲ����ڶƵ�������
			С�ڶƵ��ʱ���õ���һ�ܲ�����
	\param	pfSrc		[in]	��ǰ�ܲ���������
	\param  nextSrc		[in]	��һ�ܲ���������
	\param	psinf		[in]	����ϵ����
	\param	pcosf		[in]	����ϵ����
	\param	fCnt		[in]	ÿ�ܲ���ʵ�ʵ���
	\param  sampleNum	[in]	ÿ�ܲ����������������ÿ�ܲ�������20���32�㣩
*/
float calc_Hz_DFT( float* pfSrc, float* nextSrc, float* pcosf, float* psinf, float fCnt, int sampleNum )
{
	int     i, iCnt, iDif;
	float	*pfData;
	float	ak = 0.0, bk = 0.0;          
	
	iCnt = (int)fCnt;
	pfData = pfSrc;
	
	if ( fCnt < sampleNum )										/*! Ƶ�ʴ��ڶֵ��ʵ�ʵ���С�ڲ������� */
	{
		for (i = 0; i < iCnt; i++)			
		{	
			ak += (*psinf) * (*pfData);							
			bk += (*pcosf) * (*pfData);				
			pcosf++;
			psinf++;
			pfData++;
		}
	}
	else														/*! Ƶ��С�ڶֵ��ʵ�ʵ������ڲ������� */
	{
		iDif = iCnt - sampleNum;
		for (i = 0; i < sampleNum; i++)			
		{	
			ak += (*psinf) * (*pfData);							
			bk += (*pcosf) * (*pfData);				
			pcosf++;
			psinf++;
			pfData++;
		}

		pfData = nextSrc;
		for (i = 0; i < iDif; i++)
		{
			ak += (*psinf) * (*pfData);							
			bk += (*pcosf) * (*pfData);				
			pcosf++;
			psinf++;
			pfData++;
		}
	}

	//�������һ����
	ak += (fCnt - iCnt) * (*psinf) * (*pfData) ;						
	bk += (fCnt - iCnt) * (*pcosf) * (*pfData);					

	return ( (float)atan2( bk, ak ) );
	
	//pComplex->Real = 2 * ak / fCnt;
	//pComplex->Imag = - 2 * bk / fCnt;	
	//pComplex->Rms  = (float)( sqrt( pComplex->Real * pComplex->Real + pComplex->Imag * pComplex->Imag ) );	
}

/*!
	\brief	ֱ������
	\param	pfData		[in]	ԭʼ����������ʼ��ַ
	\param	fcnt		[in]	ԭʼ������ĸ���
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void calc_DC( float* pfsrc, int fcnt, COMPLEX_R* pComplex )
{
	float	DC_value = 0;
	float	*pfData = pfsrc;
	float	*pfData_end = pfsrc + fcnt;

	for ( ; pfData < pfData_end; pfData++ )
	{
		DC_value += (*pfData) * (*pfData);
	}
	
	DC_value = (float) sqrt(DC_value / fcnt);
	pComplex->Real = DC_value;
	pComplex->Imag = 0.0;
	pComplex->Rms  = pComplex->Real;
}

/*!
	\brief	Ƶ�ʼ���
	\param	pFront		[in]	ǰһ�ܲ�����������ʼ��ַ
	\param	pCur		[in]	��ǰԭʼ����������ʼ��ַ
	\param  pNext       [in]	��һ�ܲ�����ֵ��ʼ��ַ
	\param  currentHz	[in]    ��ǰ���õ�ϵͳƵ��
	\param	sampleNum	[in]	ÿ�ܲ������ʣ������ÿ�ܲ�������20���32�� ��
	\param  ratedFreq	[in]	�Ƶ��
	\return ���ؼ�����
*/
float calc_freq( float* pPrev, float* pCur, float* pNext, float currentHz, int sampleNum, INT32 ratedFreq )
{
	float freq, fcnt, curAngle, prevAngle, difAngle;
	
	if (currentHz <= (0.5 * ratedFreq) )
	{
		currentHz = (float)ratedFreq;
	}

	//ÿ��ʵ�ʲ�������
	fcnt = (float)(ratedFreq * sampleNum / currentHz );	
	coefficient_table( gs_cosf, gs_sinf, (int)( fcnt + 1 ), fcnt);				
	
	//�����������ܲ���λ��
	curAngle  = calc_Hz_DFT(pCur, pNext, gs_cosf, gs_sinf, fcnt, sampleNum);
	prevAngle = calc_Hz_DFT(pPrev, pCur, gs_cosf, gs_sinf, fcnt, sampleNum);
	difAngle  = curAngle - prevAngle;

	//�������������PIʱ���ܵ��µĴ���
	if( difAngle > PI )
	{
		difAngle -= 2 * PI;
	}
	else if ( difAngle < -PI )
	{
		difAngle += 2 * PI;
	}

	freq = (float)(ratedFreq + 0.5 * difAngle * ratedFreq  / PI);

	/*! ����Ƶ����ԭƵ�ʲ������ʱ���ټ���һ�� */
	if ( fabs( currentHz  - freq ) > 0.5 )		
	{
		if (freq <= (0.5 * ratedFreq) )
		{
			freq = (float)ratedFreq;
		}

		//ÿ��ʵ�ʲ�������
		fcnt = (float)(ratedFreq * sampleNum / freq );	
		coefficient_table( gs_cosf, gs_sinf, (int)( fcnt + 1 ), fcnt);					

		//�����������ܲ���λ��
		curAngle  = calc_Hz_DFT(pCur, pNext, gs_cosf, gs_sinf, fcnt, sampleNum);
		prevAngle = calc_Hz_DFT(pPrev, pCur, gs_cosf, gs_sinf, fcnt, sampleNum);
		difAngle  = curAngle - prevAngle;

		//�������������PIʱ���ܵ��µĴ���
		if( difAngle > PI )
		{
			difAngle -= 2 * PI;
		}
		else if ( difAngle < -PI )
		{
			difAngle += 2 * PI;
		}

		freq = (float)(ratedFreq + 0.5 * difAngle * ratedFreq  / PI);
	}
	

	if((freq > (1.5 * ratedFreq) ) || (freq < (0.5 * ratedFreq) ))
	{
		freq = (float)ratedFreq;
	}
	return freq;
}


/*!
	\brief	��������
	\param	phsA	[in]	A�������
	\param	phsB	[in]	B�������
	\param	phsC	[in]	C�������
	\param	pseq	[out]	�������������
*/
void calc_seq( COMPLEX_R* phsA, COMPLEX_R* phsB, COMPLEX_R* phsC, SEQ_VAL* pseq )
{	
	float real,imag, tmp1, tmp2, tmp3, tmp4;
	
	//���򡢸�������д�����ͬ�ļ�����̣��ڴ�����ʱ�����������������������Ч��
	tmp1 = SEQT0 * phsA->Real - SEQT1 * (phsB->Real + phsC->Real);
	tmp2 = SEQT2 * (phsB->Imag - phsC->Imag);
	tmp3 = SEQT0 * phsA->Imag - SEQT1 * (phsB->Imag + phsC->Imag);
	tmp4 = SEQT2 * (phsB->Real - phsC->Real);
	
	//�������
	real = tmp1 - tmp2;
	imag = tmp3 + tmp4;
    pseq->c1 = (float)sqrt((real*real + imag*imag));
    
    //�������
	real = tmp1 + tmp2;
	imag = tmp3 - tmp4;
    pseq->c2 = (float)sqrt((real*real + imag*imag));
    
    //������� 3U0/3I0
    real = phsA->Real + phsB->Real + phsC->Real;
    imag = phsA->Imag + phsB->Imag + phsC->Imag;
    pseq->c0 = (float)sqrt((real*real + imag*imag));
}

/*!
	\brief	�������㣺���ڵ�ѹ����������㣬�������������ʸ��ֵ������Ƶ�ʼ���
	\param	phsA	[in]	A�������
	\param	phsB	[in]	B�������
	\param	phsC	[in]	C�������
	\param	pseq	[out]	�������������
*/
void calc_useq( COMPLEX_R* phsA, COMPLEX_R* phsB, COMPLEX_R* phsC, SEQ_VAL* pseq, FLOAT32* psangle )
{	
	float real,imag, tmp1, tmp2, tmp3, tmp4;
	
	//���򡢸�������д�����ͬ�ļ�����̣��ڴ�����ʱ�����������������������Ч��
	tmp1 = SEQT0 * phsA->Real - SEQT1 * (phsB->Real + phsC->Real);
	tmp2 = SEQT2 * (phsB->Imag - phsC->Imag);
	tmp3 = SEQT0 * phsA->Imag - SEQT1 * (phsB->Imag + phsC->Imag);
	tmp4 = SEQT2 * (phsB->Real - phsC->Real);
	
	//�������
	real = tmp1 - tmp2;
	imag = tmp3 + tmp4;
	*psangle = atan2(imag,real);
    pseq->c1 = (float)sqrt((real*real + imag*imag));
    
    //�������
	real = tmp1 + tmp2;
	imag = tmp3 - tmp4;
    pseq->c2 = (float)sqrt((real*real + imag*imag));
    
    //������� 3U0/3I0
    real = phsA->Real + phsB->Real + phsC->Real;
    imag = phsA->Imag + phsB->Imag + phsC->Imag;
    pseq->c0 = (float)sqrt((real*real + imag*imag));
}


/*!
	\brief	���๦�ʼ���
	\brief  pU	  [in]	��ѹ
	\brief	pI	  [in]	����
	\brief  power [out] ���๦��
*/
POWER_VAL cal_power( COMPLEX_R* pU, COMPLEX_R* pI)
{
	POWER_VAL power; 
	power.PPower = pU->Real * pI->Real + pU->Imag * pI->Imag;
	power.QPower = pU->Imag * pI->Real - pU->Real * pI->Imag;
	power.ApparentPower = pU->Rms * pI->Rms;
	
	return power;
}

/*!
	\brief	���๦�ʼ���
	\param	phsA	[in]	A�������
	\param	phsB	[in]	B�������
	\param	phsC	[in]	C�������
	\param	power3	[out]	���ʼ��������
*/
POWER_VAL cal_power3( COMPLEX_R* pUa, COMPLEX_R* pUb, COMPLEX_R* pUc, COMPLEX_R* pIa, COMPLEX_R* pIb, COMPLEX_R* pIc)  
{
	POWER_VAL power3;

	power3.PPower = pUa->Real * pIa->Real + pUb->Real * pIb->Real + pUc->Real * pIc->Real +
					pUa->Imag * pIa->Imag + pUb->Imag * pIb->Imag + pUc->Imag * pIc->Imag;

	power3.QPower = -pUa->Real * pIa->Imag - pUb->Real * pIb->Imag - pUc->Real * pIc->Imag +
					pUa->Imag * pIa->Real + pUb->Imag * pIb->Real + pUc->Imag * pIc->Real;

	power3.ApparentPower = pUa->Rms * pIa->Rms + pUb->Rms * pIb->Rms + pUc->Rms * pIc->Rms;
										
	
	return power3;
}
