/*************************************************************************
* Copyright (c) 2011,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		
 	
	\author		chentm
	\version	1.0
	\date		2011-03-18
	
*/

#ifndef	__YH_SHD_CONTROL_DEFINE_H
#define	__YH_SHD_CONTROL_DEFINE_H

#include "shd_def.h"
#include "rcd_ctl.h"
#include "../scale/sg_def.h"

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_SHD_FILE_LEN	50*1024*1024


typedef int (*FN_SHD_PROC)(struct mk_shd_ctl_t*);

/*!
 	\brief	����SHD�Ŀ��ƽṹ

	���ṹ��������ԭʼ¼������SHD�ļ�
 */
typedef struct mk_shd_ctl_t 
{
	/*������������ SHD_INFO�ṹ��ȫһ�£��Է��㴦�� */
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
	//INT8U*			SgDataAddr;					/*!< ���л��Ķ�ֵ��������ʼ��ַ */	//ctm
	//INT32				SgDataLen;					/*!< ���л��Ķ�ֵ���������� */		//ctm 
	
	INT32				AnChCnt;					/*!< ģ����ͨ���� */
	INT32				BinChCnt;					/*!< ������ͨ���� */
	INT32				SmpLenPerPnt;				/*!< һ��ԭʼ�����ε����ݵ�ĳ��� */
	INT32				CompLenPerPnt;				/*!< һ�������ε����ݵ�ĳ��� */
	INT32				AnSmpLenPerPnt;				/*!< һ��ģ�����������ݵ�ĳ��� */
	INT32				AnCompLenPerPnt;			/*!< һ��ģ���������������ݵ�ĳ��� */
	INT32				BinLenPerPnt;				/*!< һ���������������ݵ�ĳ��� */

	/*
	����ÿ�ܲ��Ĳ���������������Լ����
	>0ʱ����ʾΪԭʼ����
	<1ʱ����ʾΪ���������������ֵ��ʾÿ�����ܲ���һ���������ݵ�
	*/
	INT32				A2SmpPntPerCyc;				/*!< A2��ÿ�ܲ��������� */
	INT32				A1SmpPntPerCyc;				/*!< A1��ÿ�ܲ��������� */
	INT32				BSmpPntPerCyc;				/*!< B��ÿ�ܲ��������� */
	INT32				CSmpPntPerCyc;				/*!< C��ÿ�ܲ��������� */
	INT32				DSmpPntPerCyc;				/*!< D��ÿ�ܲ��������� */

//	YH_TRNS_RCD_SET		Setting;					/*!< ��ֵ��Ϣ */

	INT32				Status;						/*!< ״̬ */
	FAULT_INFO* 		CurFltInfo;					/*!< ��ǰ���ڴ���Ĺ�����Ϣ */
	FAULT_SEG_INFO*		CurFltSeg;					/*!< ��ǰ���ڴ���Ĺ�����Ϣ�� */

	INT32				ShdFltCycCnt;				/*!< ���ι����Ѿ���������ܲ��� */
	INT32				ShdSegCycCnt;				/*!< �������Ѿ�������ܵ��ܲ��� */
	
	INT32				FltNum;						/*!< ������� */
	INT32				FlgFWriteShd;				/*!< ��־�Ƿ���ҪдSHDԭʼ�ļ� */
	char				ShdFileName[128];			/*!< SHD�ļ���(������·������չ��) */
	char				ShdFilePath[256];			/*!< SHD�ļ�ȫ·�� */
	FILE*				ShdFp;						/*!< SHD�ļ�����ָ�� */
	INT32				ShdFWriteLen;				/*!< �Ѿ�д��SHD�ļ������ݵĳ��� */

	//INT32				ShdSgType;					/*!< ����SHD�ļ�ʱ������Ķ�ֵ�ĸ�ʽ */

	FN_SHD_PROC			PtrStartProc;				/*!< ¼����ʼʱ�Ĵ����� */
	FN_SHD_PROC			PtrRcdProc;					/*!< ¼�������еĴ����� */
	FN_SHD_PROC			PtrStopProc;				/*!< ¼������ʱ�Ĵ����� */
}MK_SHD_CTL;


/*!
 	\brief	SHD���ƽṹ�Ĵ���
 	\return	�ɹ����ش�����SHD���ƽṹ��ָ�룬���򷵻�NULL
 */
MK_SHD_CTL* shd_ctl_create( int buf_len );

/*!
 	\brief	SHD���ƽṹ�ĳ�ʼ��
 	\return	�ɹ�����0�����򷵻ط�0�����
 */
//int shd_ctl_init( MK_SHD_CTL* pShdCtl, SHDFR_SG* psg, FAULT_INFO* flt_info, void* sgdata, int data_len );

/*!
 	\brief	SHD���ƽṹ������
 	\return	�ɹ�����0�����򷵻ط�0�����
 */
int shd_ctl_destory( MK_SHD_CTL* pShdCtl );


#ifdef __cplusplus
}
#endif

#endif	//__YH_SHD_CONTROL_DEFINE_H
