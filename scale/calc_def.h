/*************************************************************************
* Copyright (c) 2010,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		���������ݽṹ�Ķ���
 	
	\author		Chen
	\version	1.0
	\date		2010-03-11
	
*/

#ifndef	__SH_CALC_DATA_STRUCT_DEFINE_H
#define	__SH_CALC_DATA_STRUCT_DEFINE_H

#include "yhftypes.h"
//#include "xtime.h"

#define	DFT_PNT_CNT_PER_CYC		20		/*!< ����DFT����ʱ��ÿ�ܲ����ݵĲ������� */

#define SEQT0			(0.3333333f)
#define SEQT1		    (0.1666667f)
#define SEQT2			(0.2886751f)

#ifdef __cplusplus
extern "C" {
#endif

#if 0
/*!
    \brief  ԭʼ����ʱ��    16Bytes
    
    ���ṹ��FPGA��ԭʼ�������ݵ�ʱ����ȫһ�£�
    ��DSP���ذ�ͨѶ�����У����е�����ʱ��Ҳ���ô�ʱ�꣮
    DSP�����κ���ʱ��ת����ز�����
 */
typedef struct
{
    INT16U   day;        /*!< �� */
    INT16U   hour;       /*!< ʱ */
    INT16U   min;        /*!< �� */
    INT16U   sec;        /*!< �� */
    INT16U   msec;       /*!< ���� */
    INT16U   usec;       /*!< ΢�� */
    INT16U   year;       /*!< �� */
    INT16U   month;      /*!< �� */
} SMP_TIMESTAMP;
#else
typedef struct timeval	SMP_TIMESTAMP;
#endif



/*!
    \brief  �����ṹ(ʵ�鲿��ʾ)
 */
typedef struct
{
    FLOAT32		Real;   /*!< ʵ�� */
    FLOAT32		Imag;   /*!< �鲿 */
} COMPLEX;


/*!
    \brief  �����ṹ(ʵ�鲿����Чֵ��ʾ)
 */
typedef struct
{
    FLOAT32		Real;   /*!< ʵ�� */
    FLOAT32		Imag;   /*!< �鲿 */
    FLOAT32		Rms;	/*!< ��Чֵ */
} COMPLEX_R;

/*!
    \brief  �����ṹ(ʵ�鲿����Чֵ����λ��ʾ)
 */
typedef struct
{
    FLOAT32		Real;   /*!< ʵ�� */
    FLOAT32		Imag;   /*!< �鲿 */
    FLOAT32		Rms;	/*!< ��Чֵ */
    FLOAT32		Phs;	/*!< ��λ */
} COMPLEX_RP;


/*!
    \brief  �����
 */
typedef struct
{
    FLOAT32		c1;		/*!< ���� */
    FLOAT32		c2;		/*!< ���� */
    FLOAT32		c0;		/*!< ���� */
} SEQ_VAL;

/*!
    \brief  ���ʷ���
 */
typedef struct
{
    FLOAT32         PPower;         /*!< �й�����*/
    FLOAT32         QPower;         /*!< �޹�����*/
    FLOAT32         ApparentPower;  /*!< ���ڹ���*/
} POWER_VAL;

/*!
    \brief  ģ��ͨ��������
 */
typedef  struct
{
    INT32U			IsValid;        /*!< �Ƿ���Ч */
    COMPLEX_R       ChVal;          /*!< ͨ�������� */    
    COMPLEX_R       Ha2Val;         /*!< 2��г��ֵ */
    COMPLEX_R       Ha3Val;         /*!< 3��г��ֵ */
    COMPLEX_R       Ha5Val;         /*!< 5��г��ֵ */
    COMPLEX_R       Ha7Val;         /*!< 7��г��ֵ */
    COMPLEX_R       Ha9Val;         /*!< 9��г��ֵ */
}ANCH_VAL;


/*!
    \brief  ��ѹ������
 */
typedef struct
{
    INT32U			IsValid;    /*!< �Ƿ���Ч 0 = ��Ч�� 1 = Ƶ�ʼ�����Ч�� 2 = �����������Ч�� 3 = Ƶ�ʡ�������������Ч*/
    FLOAT32         Hz;         /*!< Ƶ��*/
    FLOAT32         HzRte;      /*!< Ƶ�ʱ仯�� */
    FLOAT32         PsSeq;      /*!< ���� */
    FLOAT32         NgSeq;      /*!< ���� */
    FLOAT32         ZerSeq;     /*!< ���� */
}ULIN_VAL;


/*!
    \brief  ����������
 */
typedef struct
{
    INT32U			IsValid;        /*!< �Ƿ���Ч 0 = ��Ч��1 = ���ʼ�����Ч��2 = �����������Ч��3 = ���ʡ�������������Ч */
    FLOAT32         PPower;         /*!< �й�����*/
    FLOAT32         QPower;         /*!< �޹�����*/
    FLOAT32         ApparentPower;  /*!< ���ڹ���*/
    FLOAT32         PF;             /*!< ƽ����������*/
    FLOAT32         PsSeq;          /*!< ����*/
    FLOAT32         NgSeq;          /*!< ����*/
    FLOAT32         ZerSeq;         /*!< ����*/
}ILIN_VAL;


/*!
    \brief  ��ѹ��������
 */
typedef struct 
{
    INT32U			IsValid;            /*!< �Ƿ���Ч 0����Ч�� 1�������ű�����Ч�� 2��������Ч�� 3�������š���������Ч*/
    FLOAT32         OverExcition;       /*!< ��ѹ�������ű���*/
    FLOAT32         DiffAClc[3];        /*!< ��ѹ���������*/
    FLOAT32         ThrATimes[3];       /*!< ��ѹ����Խ��������*/
    FLOAT32         AperComponent[3];   /*!< ��ѹ�������ڷ���*/ 
    FLOAT32         RstA[3];            /*!< �ƶ�����*/
    FLOAT32         Resv[1];            /*!< Ϊ�Ժ���չʹ��*/
}TRN_VAL;


/*********************************2011.3.10�޸�**********************************************************/
/*!
    \brief  �����������
*/
typedef struct
{
    INT32U			IsValid;			/*!< �Ƿ���Ч 0����Ч�� 1�����ż�������Ч�� 2�����˼�������Ч�� 3����������˼���������Ч */
	FLOAT32			PPower;				/*!< �й����� */
	FLOAT32			QPower;				/*!< �޹����� */
	FLOAT32			ApparentPower;		/*!< ���ڹ��� */
	FLOAT32			P2Power;			/*!< ������ */
	FLOAT32			OverExcition;		/*!< ����������ű��� */
	FLOAT32			ExcVol;				/*!< ��������ŵ�ѹ */
	FLOAT32			StatorHar3;			/*!< �������������г����ѹ�� */
	FLOAT32			RotorHar2;			/*!< ת�Ӷ���г�� */
    FLOAT32			DifClc[3];			/*!< �����������ȫ�ݲ���� */
	FLOAT32			DifInClc[3];		/*!< ��������಻��ȫ�ݲ���� */
	FLOAT32			DifTranClc[3];		/*!< �������������� */
    FLOAT32			LowFreOvCur[3];		/*!< ��Ƶ�������ֵ */
}GN_VAL;

/**********************************************************************************************/

/*!
    \brief  �ܲ�������

    <pre>
    һ�ܲ������������������£�
    ���    ���ȣ��ֽڣ�                ˵��
    1       sizeof(YHFtimeval)       ʱ��
    2       sizeof(ANCH_VAL)*AnChCnt    ģ����ͨ����������
    3       sizeof(ULIN_VAL)*ULinCnt    ��ѹ��������
    4       sizeof(ILIN_VAL)*ILinCnt    ������������
    5       sizeof(GN_VAL)*GnCnt        �������������
    6       sizeof(TRN_VAL)*TrnCnt      ��ѹ����������
    </pre>
*/
typedef struct 
{
    YHFtimeval*      TimeStamp;  /*!< ʱ��*/
    ANCH_VAL*           AnChVal;    /*!< ģ����ͨ������������ʼλ��*/
    ULIN_VAL*           ULinVal;    /*!< ��ѹ����������ʼλ��*/
    ILIN_VAL*           ILinVal;    /*!< ��������������ʼλ��*/
    GN_VAL*             GnVal;      /*!< ���������������ʼλ��*/
    TRN_VAL*            TrnVal;     /*!< ��ѹ������������ʼλ��*/
}CALC_DATA_INFO;


/*************************************************************************
**************************************************************************/

//#define	PI			(3.1415926535897932f)
#define EPSINON 	(0.000001)

/*!
	\brief	����DFT�����������������ϵ�������ڷ�ֵ���㣬���ڶƵ��
	\param	psinf		[out]	����ϵ����
	\param	pcosf		[out]	����ϵ����
	\param	k			[in]	г������
	\param  sampleNum	[in]	ÿ�ܲ��ļ������
*/
void init_coefficient_table( float* pcosf, float* psinf, int k, int sampleNum);

/*!
	\brief	����DFT�����������������ϵ��������Ƶ�ʼ���
	\param	psinf	[out]	����ϵ����
	\param	pcosf	[out]	����ϵ����
	\param	N		[in]	ϵ�������
	\param  sample  [in]    ÿ�ܵ�ʵ�ʲ�������������ʱ�����̶�ʱ����ϵͳƵ�ʱ仯���仯
*/
void coefficient_table( float* pcosf, float* psinf, int N, float sampleNum );

/*!
	\brief	����DFT�����������������ϵ����
	\param	k				[in]	г������
	\param	N				[in]	ϵ�������
	\param  sampleNum		[in]    ÿ�ܲ�ʵ�ʲ�������
*/
float* creat_coefficient_table( int k, int N, float sampleNum );


/*!
	\brief	�Ľ�DFT���㣬���������5�Ρ�9��г��
	\param	pfSrc		[in]	����������ʼ��ַ
	\param  pcosf		[in]	����ϵ����
	\param	psinf		[in]	����ϵ����
	\param	quarterNum	[in]	�ֱ��Ӧ�ķ�֮һ�ܲ������ܲ����ķ�֮���ܲ���һ�ܲ��������
	\param	k			[in]	г����������Ӧ�ڻ�����5��9��г��
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void improved_DFT159( float* pfSrc, float* pcosf, float* psinf, int* quarterNum, COMPLEX_R* pComplex );

/*!
	\brief	�Ľ�DFT���㣬����3��7��г��
	\param	pfSrc		[in]	����������ʼ��ַ
	\param  pcosf		[in]	����ϵ����
	\param	psinf		[in]	����ϵ����
	\param	quarterNum	[in]	�ֱ��Ӧ�ķ�֮һ�ܲ������ܲ����ķ�֮���ܲ���һ�ܲ��������
	\param	k			[in]	г����������Ӧ��3��7��г��
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void improved_DFT37( float* pfSrc, float* pcosf, float* psinf, int* quarterNum, COMPLEX_R* pComplex );

/*!
	\brief	�Ľ�DFT��ֻ�������г��
	\param	pfSrc		[in]	����������ʼ��ַ
	\param  pcosf		[in]	����ϵ����
	\param	psinf		[in]	����ϵ����
	\param	quarterNum	[in]	�ֱ��Ӧ�ķ�֮һ�ܲ������ܲ����ķ�֮���ܲ���һ�ܲ��������
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void improved_DFT2( float* pfSrc, float* pcosf, float* psinf, int* quarterNum, COMPLEX_R* pComplex );

/*!
	\brief	��ʼ��DFT�����������������ϵ����
	\param	pcoeff	[in]	ϵ������ʼ��ַ
	\param	k		[in]	г������
	\param	N		[in]	ÿ�ܲ���������
	\param  skew    [in]    �Ƕ�ƫ��
*/
void init_coefficient_table_angle( float* pcoeff, int k, int N, float skew );

/*!
	\brief	DFT���㣬����ʵ�� �鲿����Чֵ, г����Чֵ��������Ƶ�ʵ��ڶƵ�����
	\param	pfSrc		[in]	����������ʼ��ַ
	\param	pcoeff		[in]	������ϵ�����׵�ַ
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void calc_DFT( float* pfSrc, float* pCoeff, COMPLEX_R* pComplex );

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
FLOAT32 calc_pos_angle( FLOAT32* prevSrc, FLOAT32* curSrc,FLOAT32* nextSrc, INT16* idxU, INT16 sampleNum, FLOAT32 prevFreq, INT32 ratedFreq);

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
float calc_Hz_DFT( float* pfSrc, float* nextSrc, float* pcosf, float* psinf, float fCnt, int sampleNum );

/*!
	\brief	ֱ������
	\param	pfdata		[in]	ԭʼ����������ʼ��ַ
	\param	fcnt		[in]	ԭʼ������ĸ���
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void calc_DC( float* pfsrc, int fcnt, COMPLEX_R* pComplex );

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
float calc_freq( float* pPrev, float* pCur, float* pNext, float currentHz, int sampleNum, INT32 ratedFreq );

/*!
	\brief	��������
	\param	phsA	[in]	A�������
	\param	phsB	[in]	B�������
	\param	phsC	[in]	C�������
	\param	pseq	[out]	�������������
*/
void calc_seq( COMPLEX_R* phsA, COMPLEX_R* phsB, COMPLEX_R* phsC, SEQ_VAL* pseq );

/*!
	\brief	�������㣺���ڵ�ѹ����������㣬�������������ʸ��ֵ������Ƶ�ʼ���
	\param	phsA	[in]	A�������
	\param	phsB	[in]	B�������
	\param	phsC	[in]	C�������
	\param	pseq	[out]	�������������
	\param  ps
*/
void calc_useq( COMPLEX_R* phsA, COMPLEX_R* phsB, COMPLEX_R* phsC, SEQ_VAL* pseq, FLOAT32* psangle );

/*!
	\brief	���๦�ʼ���
	\brief  pU	  [in]	��ѹ
	\brief	pI	  [in]	����
	\brief  power [out] ���๦��
*/
POWER_VAL cal_power( COMPLEX_R* pU, COMPLEX_R* pI);

/*!
	\brief	���๦�ʼ���
	\param	phsA	[in]	A�������
	\param	phsB	[in]	B�������
	\param	phsC	[in]	C�������
	\param	power3	[out]	���ʼ��������
*/
POWER_VAL cal_power3( COMPLEX_R* pUa, COMPLEX_R* pUb, COMPLEX_R* pUc, COMPLEX_R* pIa, COMPLEX_R* pIb, COMPLEX_R* pIc);

#ifdef __cplusplus
}
#endif


#endif	//__SH_CALC_DATA_STRUCT_DEFINE_H
