/*************************************************************************
* Copyright (c) 2010,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		
 	
	\author		Chen
	\version	1.0
	\date		2010-03-18
	
*/

#ifndef	__SH_RECORD_CONTROL_DEFINE_H
#define	__SH_RECORD_CONTROL_DEFINE_H

#include "rt_ctl.h"
//#include "sg_def.h"
#include "calc_def.h"
#include "yhftypes.h"

#define		FAULT_A2SEG		1
#define		FAULT_A1SEG		2
#define		FAULT_BSEG		3
#define		FAULT_CSEG		4
#define		FAULT_DSEG		5
#define		FAULT_END_SEG	0

#define		MAX_RETRG_NUM_PER_FLT	100			/*!< ÿ����������������*/
#define		MAX_CYC_NUM_PER_FLT		50*60*30	/*!< ÿ����������¼�ܲ���*/

#define		MAX_FAULT_SEG_NUM		500			/*!< �����϶���*/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 	\brief	�������ݶ�

	¼������ʱ��A2/A1/C/D�Σ�ÿ�ζ�Ӧ��һ��FAULT_SEG�ṹ
	����B�Σ�ÿ����һ�Σ���Ӧһ���µ�FAULT_SEG�ṹ

	�������ݶ���Ϣ�ṹ��������������¼�����ݣ�ֻ�Ǳ���¼�����ݵ�������Ϣ��
	��ϵͳʵʱ�������㹻���ʱ�򣬿ɸ�����Щ��Ϣ��׷������¼���Ĺ��̡�

 */
typedef struct fault_seg_info_t
{
	INT32				SegFlg;     	/*!< ���α�־������ΪA2=1��A1=2��B=3��C=4��D=5, END=0*/
	INT32				CycNum;			/*!< �����ܵ��ܲ���*/
	INT32				LeftCycNum;		/*!< ����ʣ���ܲ���*/
	INT32				StartPos;		/*!< ������ʼλ�� */
	INT32				TrgOffset;		/*!< ������Ϣ��ƫ���ܲ���(��Ϊ�����жϿ����ͺ�����ʼλ��,����B��������...) */
} FAULT_SEG_INFO;


typedef struct	fault_info_t
{
	FAULT_SEG_INFO*		SegInfo;		/*!< ���϶ε��׵�ַ */
	INT32				MaxSegCnt;		/*!< �����϶εĸ��� */
	INT32				SegCnt;			/*!< ���϶ε��ܵĸ��� */
	INT32				CycCnt;			/*!< ���й��������ܵ��ܲ��� */

	INT32				FlgRcding;		/*!< ��־�Ƿ���¼��������... */
	INT32				FlgShdMading;	/*!< ��־�Ƿ���SHD�����ɹ�����... */
	INT32				FlgNeedSplit;	/*!< ��־�Ƿ���Ҫ���з��ļ��Ĵ���... */

	YHFtimeval			FltTime;		/*!< ���Ϸ���ʱ�� */
	YHFtimeval			StartTime;		/*!< ��ʼʱ�� */

//	TRG_FLG				LastTrgFlg;		/*!< �ϴδ�����־�����������жϼ�¼���ֶδ��� */

	INT32				ReTrgCnt;		/*!< ������� */
	INT32				FltFileLen;		/*!< �����ļ�����(�ֽ���) */
	
	struct mk_shd_ctl_t*	MkShdCtl;	/*!< SHD���ɶ��� */
} FAULT_INFO;

#define		TRNS_RCD_STATUS_NO_RCD		0		/*!< ��¼�� */
#define		TRNS_RCD_STATUS_START_RCD	1		/*!< ��ʼ¼�� */
#define		TRNS_RCD_STATUS_RCDING		2		/*!< ¼�������� */
#define		TRNS_RCD_STATUS_STOP_RCD	3		/*!< ����¼�� */

/*!
 	\brief	��̬¼������
 */
typedef struct trns_rcd_ctl_t
{
	int					Mod;				/*!< ��ǰϵͳ����״̬ 0���� 1���� */
	
	int					FltNum;				/*!< ����������� */
	
	int					FlgReInit;			/*!< ϵͳ���³�ʼ����־ 0 1 */
	int					FlgStopRec;			/*!< ϵͳֹͣ¼����־ 0 1 */
	int					FlgRcdTrg;			/*!< ����¼��(�ֶ�¼��)��־ 0 1*/
	int					FlgRcdStr;			/*!< ¼��������־ */
	int					FlgRcdMade;			/*!< ����¼���ļ��ı�־ */

	int					FlgSplit;			/*!< ���ļ��ı�־ */

	FAULT_INFO*			FltInfo1;			/*!< ������Ϣ1 */
	FAULT_INFO*			FltInfo2;			/*!< ������Ϣ2 */

//	YH_TRNS_RCD_SET		Setting;			/*!< ��ֵ��Ϣ */

	FAULT_INFO*			CurFltInfo;			/*!< ��ǰ����¼����Ϣ */
}TRNS_RCD_CTL;


//TRNS_RCD_CTL * rcd_ctl_create();
//int  rcd_ctl_init( TRNS_RCD_CTL* prcdCtl, SHDFR_SG* psg );
//int  rcd_ctl_destory( TRNS_RCD_CTL* prcdCtl );
//int  flt_info_init( FAULT_INFO* flt_info, SHDFR_SG* psg );

#ifdef __cplusplus
}
#endif

#endif	//__SH_RECORD_CONTROL_DEFINE_H
