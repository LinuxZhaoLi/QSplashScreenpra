/*************************************************************************
* Copyright (c) 2011,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		����¼������������ݵ�Ԫ����ĳ���
 	
	\author		chentm
	\version	1.0
	\date		2011-08-23
*/

#ifndef	__SH_RECORD_DATA_UNIT_LEN_DEFINE_H
#define	__SH_RECORD_DATA_UNIT_LEN_DEFINE_H

#include "sg_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 	\brief	��ȡһ��ģ����������ĳ���
 	\return	����ģ����������ĳ���
 */
int rdu_getAnSmpPntLen ( int AnChCnt  );

/*!
 	\brief	����һ��������������ĳ���
 	\return	���ؿ�����������ĳ���
 */
int rdu_getBinSmpPntLen( int BinChCnt );


/*!
 	\brief	����һ����������ĳ���
 	\return	���ؼ�������ĳ���
// */
int rdu_getCalcPntLen( YH_DFR_CFG* dfr_cfg );

///*!
// 	\brief	����ʵʱ����֡�ĳ���
// 	\return	����ʵʱ����֡�ĳ���
// */
//int rdu_getRtFrmLen  ( YH_DFR_PARM* dfr_parm );

///*!
// 	\brief	������̬����֡�ĳ���
// 	\return	������̬����֡�ĳ���
// */
//int rdu_getContFrmLen( YH_DFR_PARM* dfr_parm );

#ifdef __cplusplus
}
#endif

#endif	/*__SH_RECORD_DATA_UNIT_LEN_DEFINE_H*/
