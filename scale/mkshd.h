/*************************************************************************
* Copyright (c) 2011,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		���SHD֡������SHD�ļ����ʽӿ�
 	
	\author		chen
	\version	1.0
	\date		2011-06-23
*/

#ifndef	__SH_MAKE_SHD_DEFINE_H
#define	__SH_MAKE_SHD_DEFINE_H

#include "shd_ctl.h"

#ifdef __cplusplus
extern "C" {
#endif

	
#define SHD_FILE_VERSION	0x1000


/*
	+------+----------------+-----------+-----------------------------------------------+
	| ��� | ����           |  ����		|	˵��	        							|
	+------+----------------+-----------+-----------------------------------------------+
	|	1  | �ļ�ͷ	        |	40Bytes	|												|
	+------+----------------+-----------+-----------------------------------------------+	
	|   2  | ��ֵ����		|	        |												|
	+------+----------------+-----------+-----------------------------------------------+		
	|   3  | ¼��ԭʼ����֡	|	        |												|
	+------+----------------+-----------+-----------------------------------------------+
*/

/*!
 	\brief	¼������ֵ���ļ�ͷ�ṹ
	
 */
typedef struct shd_file_head_t
{
	char			ShFlg[4];		/*!< ��˾�Զ����ļ���ʽ��־,�̶�Ϊ"YHF" */
	char			ShExt[4];		/*!< �ļ���չ���̶�Ϊ"shd" */
	INT8			SgDataType;		/*!< ��ֵ���ݵ����� 0 -- SHDFR_SG��ֵ���� 1 -- ���л���SGDfrObject���� */
	INT8			Endian;			/*!< �ļ��ֽ�˳�� */
	INT8			Resv1[2];		/*!< Ԥ������֤4�ֽڶ��� */
	INT32			FileVer;		/*!< �ļ��汾 */
	INT32			FileLen;		/*!< �ļ�����,=0ʱ��ʾ����δ֪ */

	//INT32			SgDataLen;		/*!< ��ֵ���ݵĳ��� */
	INT8			Resv2[20];		/*!< Ԥ��20�ֽ�,��֤�ļ�ͷ�ܵĴ�СΪ40�ֽ� */
} SHD_FILE_HEAD ;


int create_shd_file( MK_SHD_CTL* pShdCtl );
int write_shd_file ( MK_SHD_CTL* pShdCtl, int shd_pos );
int close_shd_file ( MK_SHD_CTL* pShdCtl );

int fill_shd_start( MK_SHD_CTL* pShdCtl );
/*!
 	\brief	����SHDԭʼ����֡
	\param	pShdCtl	����SHD�ļ��Ŀ�����Ϣ
 */
int fill_shd_proc( MK_SHD_CTL* pShdCtl );

int fill_shd_stop( MK_SHD_CTL* pShdCtl );

/*!
 	\brief	����comtrade����
	\param	pShdCtl	����SHD�ļ��Ŀ�����Ϣ
 */
int fill_ctd_stop( MK_SHD_CTL* pShdCtl );
int fill_ctd_proc( MK_SHD_CTL* pShdCtl );
int write_ctd_file ( MK_SHD_CTL* pShdCtl, int shd_pos );

#ifdef __cplusplus
}
#endif

#endif	//__SH_MAKE_SHD_DEFINE_H
