/*************************************************************************
* Copyright (c) 2008,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*! \file
    \brief      ����SHDԭʼ¼���ļ�������ݽṹ
    \author     chen
    \version    1.0
    \date       2010-03-25
*/

#ifndef __SH_DFR_STRUCT_DEFINE_H
#define __SH_DFR_STRUCT_DEFINE_H

#include <stdio.h>
#include "yhftypes.h"
//#include "sg_def.h"
#include "calc_def.h"
#include "trg_def.h"

#define	SHD_FRM_TYPE_RT_DATA		0x33333333		/*!< ʵʱ����֡ */
#define	SHD_FRM_TYPE_TRNS_HEAD		0x44444444		/*!< ��̬����֡ */
#define	SHD_FRM_TYPE_TRNS_DATA		0x55555555		/*!< ��̬������֡ */
#define	SHD_FRM_TYPE_CONT_DATA		0x66666666		/*!< ��̬����֡ */

#ifdef __cplusplus
extern "C" {
#endif


/* ���ļ��ж�������нṹ�����1�ֽڶ��� */
#pragma pack (1)

/*
    FPGA��ԭʼ�������ݵ������������£�
    ���    ���ȣ��ֽڣ�                ˵��
    1       sizeof(SMP_TIMESTAMP)=16    ����ʱ��
    2       2*32                        1��ģ������ԭʼ��������
    3       2*32                        2��ģ������ԭʼ�������ݣ���ģ����������>=2ʱ���֣�
    4       2*32                        3��ģ������ԭʼ�������ݣ���ģ����������>=3ʱ���֣�
    5       8                           1�ſ�������״̬��ÿһλ��ʾһ����������״̬��
    6       8                           2�ſ�������״̬��ÿһλ��ʾһ����������״̬��
    7       8                           3�ſ�������״̬��ÿһλ��ʾһ����������״̬��
    8       2                           �������������
    9       2                           ��������Ÿ�λ
    10      2                           ��������ŵ�λ
    11      2*2                         1��ģ������33��34����ֵ
    12      2*2                         2��ģ������33��34����ֵ
    13      2*2                         3��ģ������33��34����ֵ
    14      6(96·)|10(64·)|14(32·)   Ԥ������֤FPGA���ݳ���Ϊ64��������
*/


/*!
    \brief  ʵʱ����֡ͷ
    
 */
typedef struct
{
    INT32U       FrmType;        /*!< ֡���ͱ�ʶ��ʵʱ����֡ͷԼ��ΪSHD_FRM_TYPE_RT_DATA */
    INT32U       FrmLen;         /*!< ֡���ȣ��˳���ָ�������ݳ��ȣ�������֡ͷ��֡У��� */
    INT32U       FrmIdx;         /*!< ֡��ţ���һ֡��1��ʼ������ÿ����һ֡��֡��Ӧ��1 */
    
    INT16U       AnChCnt;        /*!< ģ����ͨ���� */
    INT16U       BinChCnt;       /*!< ״̬��ͨ���� */
    
    INT16U       ULinCnt;        /*!< ��ѹ�� */
    INT16U       ILinCnt;        /*!< ������ */
    INT16U       TrnCnt;         /*!< ��ѹ���� */
    INT16U       GnCnt;          /*!< ������� */

    INT16U       SmpRate;        /*!< �����ʣ�ÿ�ܲ��������� */
    INT16U       CycleCnt;       /*!< �ܲ�������Ϊ5����������*/
    INT16U       CalDataLen;     /*!< �������ݵĳ��� */
    INT16U       Resv[1];        /*!< Ԥ��������֡ͷ��32�ֽڡ�*/
} FRM_HEAD_RT;


/*!
    \brief  ��̬����֡ͷ
    
 */
typedef struct 
{
    INT32U       FrmType;        /*!< ֡���ͱ�ʶ����̬֡����ӦΪSHD_FRM_TYPE_CONT_DATA */
    INT32U       FrmLen;         /*!< ֡���ȣ��˳���ָ�������ݳ��ȣ�������֡ͷ��֡У��� */
    INT32U       FrmIdx;         /*!< ֡��ţ���һ֡��1��ʼ������ÿ����һ֡��֡��Ӧ�� */

    INT16U       AnChCnt;        /*!< ģ����ͨ���� */
    INT16U       BinChCnt;       /*!< ״̬��ͨ���� */
    
    INT16U       ULinCnt;        /*!< ��ѹ�� */
    INT16U       ILinCnt;        /*!< ������ */
    INT16U       TrnCnt;         /*!< ��ѹ���� */
    INT16U       GnCnt;          /*!< ������� */

    INT16U       SmpRte;         /*!< �����ʣ���̬Ϊÿ������� */
    INT16U	 	 BinStateCnt;	 /*!< ��������λ��ĸ�����*/
    INT8U    	 IsTrg;      	 /*!< ��֡�����Ƿ����������Ϣ����Ϊ1����Ϊ0 */
    INT8U        Resv[3];        /*!< Ԥ��������֡ͷ��32�ֽڡ�*/
} FRM_HEAD_CONT;


/*!
    \brief  ��̬����֡ͷ
    
 */
typedef struct 
{
    INT32U       	FrmType;        /*!< ֡���ͱ�ʶ,��̬֡���ͱ�ʶӦΪSHD_FRM_TYPE_TRNS_HEAD */
    INT32U       	FrmLen;         /*!< ֡���ȣ���̬֡����ȷ�������ʼ��Ϊ0 */
    INT32U       	FrmIdx;         /*!< ֡��ţ���1��ʼ������������̬���ԣ�����ż�Ϊ¼���ļ���� */
    
    INT16U       	AnChCnt;        /*!< ģ����ͨ���� */
    INT16U       	BinChCnt;       /*!< ״̬��ͨ���� */

	INT16U			SmpLenPerPnt;	/*!< һ��ԭʼ�������ݶε����ݵ�ĳ��� */
	INT16U			CompLenPerPnt;	/*!< һ���������ݶε����ݵ�ĳ��� */
	INT16U			AnSmpLenPerPnt;	/*!< һ��ģ�����������ݵ�ĳ��� */
	INT16U			AnCompLenPerPnt;/*!< һ��ģ���������������ݵ�ĳ��� */
	INT16U			BinLenPerPnt;	/*!< һ���������������ݵ�ĳ��� */
  INT16U			BinStateItemLen;/*!< һ�����ر�λ��ĳ��� */
	
	INT16U			EndSmpRte;		/*!< �̶����0 */
    INT16U       	A2SmpRte;       /*!< A2 �μ�¼Ƶ�� */
    INT16U       	A1SmpRte;       /*!< A1 �μ�¼Ƶ�� */
    INT16U       	BSmpRte;        /*!< B  �μ�¼Ƶ�� */
    INT16U       	CSmpRte;        /*!< C  �μ�¼Ƶ�� */
    INT16U       	DSmpRte;        /*!< D  �μ�¼Ƶ�� */
    
    YHFtimeval		FltTime;   		/*!< ʱ�꣬���ϴ���ʱ��(��һ��B����ʼʱ��) */
    YHFtimeval		StartTime; 		/*!< ʱ�꣬��ʼʱ��(��һ��A2����ʼʱ��) */

    INT16U			FltNum;			/*!< ����������� */
    INT16U			TrgType;		/*!< �������� */
    INT16U			TrgInfoLen;		/*!< ������Ϣ�ĳ��� */
    
    INT8U			FlgFragment;	/*!< ���ļ���ʶ��ָ����¼���ļ�����һ��¼���ļ�������(��Ӧ�������������У��) */
    INT8U			CompDataType;	/*!< �������ݴ洢���� 0--�洢Ϊ������ 1--�洢ΪINT16(��DAT��ͬ����������ʧ) */
    
    INT8U       	Resv[20]; 		/*!< Ԥ����ʹ����֡ͷ��80�ֽڡ�*/
} FRM_HEAD_TRNS;



/*!
    \brief  ��̬������֡֡ͷ
    
 */
typedef struct
{
    INT32U	 FrmType;    /*!< ֡���ͱ�ʶ����̬������֡����ӦΪSHD_FRM_TYPE_TRNS_DATA */
    INT32U   FrmLen;	 /*!< ֡���� */
    INT32U   FrmIdx;     /*!< ֡��ţ�ÿ���ļ���֡��Ŵ�1��ʼ, 0��ʾ�ļ����� */

	INT32U	 SmpPntIdx;	 /*!< �����������ţ���־��֡�ĵ�һ�����������������¼�����̵Ĳ������(ʵ���Ͼ���DAT�ļ��еĲ��������) */
    INT16U   SmpNum;     /*!< ��֡�в�������*/
    INT16U   ReTrgNum;   /*!< ��������������½���A1�εĴ���������0��ʼ�����C��D��û�����룬��=1 */
    
    INT16U	 BinStateCnt;/*!< ��֡�п�������λ��ĸ�����*/
    INT8U    SegFlg;     /*!< �����жα�־������ΪA2=1��A1=2��B=3��C=4��D=5������ʾ����֡ */
    INT8U    DataType;   /*!< ���ݵ����� 0--ԭʼ�������� 1--������������ */

    INT8U    IsTrg;      /*!< ��֡�����Ƿ��������ԭ�򣬼����������Ƿ��ǵ�һ�ν���B �Ρ���Ϊ1�� ����Ϊ0*/
    INT8U    Resv1[3];   /*!< Ԥ������̬������֡֡ͷ����Ϊ32�ֽڡ�*/
    INT32U	 ChkSum;	 /*!< ֡У��ͣ�������������У��͡�*/
} FRM_HEAD_TRNS_DATA;


/*! һ�����������ݵ�ĳ���
    һ�����ݵ���������£�
    ���    ���ȣ��ֽڣ�            ˵��
    1       sizeof(SMP_TIMESTAMP)   ����ʱ��
    2       sizeof(COMPLEX)*32      1��ģ������ʵ�鲿���ݣ���ģ����������>=1ʱ���֣�
    3       sizeof(COMPLEX)*32      2��ģ������ʵ�鲿���ݣ���ģ����������>=2ʱ���֣�
    4       sizeof(COMPLEX)*32      3��ģ������ʵ�鲿���ݣ���ģ����������>=3ʱ���֣�
    5       8                       1�ſ�������״̬��ÿһλ��ʾһ����������״̬,������������>=1ʱ���֣�
    6       8                       2�ſ�������״̬��ÿһλ��ʾһ����������״̬,������������>=2ʱ���֣�
    7       8                       3�ſ�������״̬��ÿһλ��ʾһ����������״̬,������������>=3ʱ���֣�
*/


/*!
    \brief  ʵʱ����֡

    ÿһ�ܲ���ԭʼ����������FPGA���͵Ĳ������ݽṹ����ȫ��ͬ
	�䳤��ΪFPGA_SMP_DATA_LEN
*/
typedef struct
{
    FRM_HEAD_RT*        FrmHead;        /*!< ֡ͷ*/
    CALC_DATA_INFO      CalcDataInfo;  	/*!< 1�ܲ�����������*/
    INT8U*           	SmpData;		/*!< ԭʼ����������ʼλ�ã�5�ܲ��������ݣ�������Ϊ��̬B�β����ʣ�*/
    INT32U*           	ChkSum;         /*!< ֡У���*/
} FRM_RT_INFO;


/*!
    \brief  ��̬A1/B������֡��Ϣ
 */
typedef struct 
{
    FRM_HEAD_TRNS_DATA* FrmHead;    /*!< ֡ͷ*/
    TRG_INFO*           TrgInfo;    /*!< ������Ϣ����֡ͷ�е�IsTrg��־��0�������������Ϣ*/
    INT8U*           	A1BData;    /*!< A1��B��������ʼλ��*/
    INT32U*           	ChkSum;     /*!< ֡У���*/
} FRM_TRNS_A1B_INFO;


/*!
    \brief  ��̬A2/C/D������֡��Ϣ
 */
typedef struct
{
    FRM_HEAD_TRNS_DATA* FrmHead;    /*!< ֡ͷ*/
    TRG_INFO*           TrgInfo;    /*!< ������Ϣ��ʼ�գ�0*/
    INT8U*           	A2CDData;   /*!< A2��C��D��������ʼλ��*/
    INT32U*           	ChkSum;     /*!< ֡У���*/
} FRM_TRNS_A2CD_INFO;

/*!
    \brief  ��̬����֡

    ÿһ�ܲ�����̬��������
    ���    ���ȣ��ֽڣ�                ˵��
    1       SMP_DATA_LEN_PER_PNT        1�ܲ���������,����SmpPntΪÿ�ܲ���������
    2       CALC_DATA_LEN_PER_PNT       1�ܲ���������   
*/
typedef struct
{
    FRM_HEAD_CONT*      FrmHead;    /*!< ֡ͷ*/
    INT8U*           	ContData;   /*!< ��̬���ݣ���������ܲ�����̬���ݣ�����֡ͷ������*/
    INT32U*           	ChkSum;     /*!< ֡У���*/
} FRM_CONT_INFO;

#define	MAX_SHD_FRM_NUM		8192*5 /* 8192*5 */

/*!
    \brief  SHD������Ϣ 
*/
typedef struct
{
//	SHDFR_SG			DfrSg;						/*!< ��ֵ��Ϣ */
	INT8U*				BufAddr;					/*!< ��������ַ */
	INT32				BufLen;						/*!< ���������� */
	INT32				DataLen;					/*!< ����������Ч���ݵĳ���  */
	FRM_HEAD_TRNS		*FrmHead;					/*!< ¼��֡ͷ */
	FRM_HEAD_TRNS_DATA* FrmData[MAX_SHD_FRM_NUM];	/*!< ¼��������֡ */
	INT32				ShdFrmCnt;					/*!< ¼��������֡�ĸ���(��ǰ֡���) */
	FRM_HEAD_TRNS_DATA* FirstA2Frm;					/*!< ��һ��A2֡ */
	FRM_HEAD_TRNS_DATA* FirstA1Frm;					/*!< ��һ��A1֡ */		
	FRM_HEAD_TRNS_DATA* FirstBFrm;					/*!< ��һ��B֡ */
	TRG_INFO*			TrgInfo;					/*!< ������Ϣ */
	INT8U*				SgDataAddr;					/*!< ���л��Ķ�ֵ��������ʼ��ַ */
	INT32				SgDataLen;					/*!< ���л��Ķ�ֵ���������� */
	
}SHD_INFO;

#pragma pack () /* �ָ��ֽڶ����趨*/

void print_FRM_HEAD_TRNS_DATA( FRM_HEAD_TRNS_DATA* pframe, FILE* fp );

#ifdef __cplusplus
}
#endif


#endif  /* __SH_DFR_STRUCT_DEFINE_H */

