/*************************************************************************
* Copyright (c) 2010,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		��̬¼������
 	
	\author		Chen
	\version	1.0
	\date		2010-03-18
	
*/

#ifndef	__SH_SHC_CONTROL_DEFINE_H
#define	__SH_SHC_CONTROL_DEFINE_H

#include "shd_def.h"
#include "rcd_ctl.h"
//#include "sg_def.h"

#if defined( WIN32 )
#define		CONT_TEMP_DIR			"temp_cont"
#define		CONF_FNAME_SHC_TEMP		"dfrserver/conf/shctemp.conf"
#else
#define		CONT_TEMP_DIR			"/temp_cont"
#define		CONF_FNAME_SHC_TEMP		"/dfrserver/conf/shctemp.conf"
#endif


typedef int (*FN_SHC_PROC)(struct mk_shc_ctl_t*);

/*!
 	\brief	��̬¼�����ƽṹ

	���ṹ��������ԭʼ¼������SHC�ļ�
 */
typedef struct mk_shc_ctl_t 
{
	/*������������ SHC_INFO�ṹ��ȫһ�£��Է��㴦�� */
	SHDFR_SG			DfrSg;						/*!< ��ֵ��Ϣ */
	INT8U*				BufAddr;					/*!< ��������ַ */
	INT32				BufLen;						/*!< ���������� */
	INT32				DataLen;					/*!< ����������Ч���ݵĳ���  */
	FRM_HEAD_CONT* 		FrmData[1024];				/*!< ¼��������֡ */
	INT32				ShcFrmCnt;					/*!< ¼��������֡�ĸ���(��ǰ֡���) */
	TRG_INFO*			TrgInfo;					/*!< ������Ϣ */
	INT8U*				SgDataAddr;					/*!< ���л��Ķ�ֵ��������ʼ��ַ */
	INT32				SgDataLen;					/*!< ���л��Ķ�ֵ���������� */
	
	INT32				AnChCnt;					/*!< ģ����ͨ���� */
	INT32				BinChCnt;					/*!< ������ͨ���� */
	INT32				SmpLenPerPnt;				/*!< һ��ԭʼ�����ε����ݵ�ĳ��� */
	INT32				CompLenPerPnt;				/*!< һ�������ε����ݵ�ĳ��� */
	INT32				AnSmpLenPerPnt;				/*!< һ��ģ�����������ݵ�ĳ��� */
	INT32				AnCompLenPerPnt;			/*!< һ��ģ���������������ݵ�ĳ��� */
	INT32				BinLenPerPnt;				/*!< һ���������������ݵ�ĳ��� */
	
	INT32				FltNum;						/*!< ������� */
	INT32				FlgFWriteShc;				/*!< ��־�Ƿ���ҪдSHCԭʼ�ļ� */
	char				ShcFileName[128];			/*!< SHC�ļ���(������·������չ��) */
	char				ShcFilePath[256];			/*!< SHC�ļ�ȫ·�� */
	FILE*				ShcFp;						/*!< SHC�ļ�����ָ�� */
	INT32				ShcFWriteLen;				/*!< �Ѿ�д��SHC�ļ������ݵĳ��� */

	INT32				ShcSgType;					/*!< ����SHC�ļ�ʱ������Ķ�ֵ�ĸ�ʽ */

	FN_SHC_PROC			PtrRcdProc;					/*!< ¼�������еĴ����� */
}MK_SHC_CTL;


#endif //__SH_SHC_CONTROL_DEFINE_H
