/*************************************************************************
* Copyright (c) 2011,������Ԫ�������������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
    \brief
    \author		chen
    \version	1.0
    \date		2011-03-18
*/

#ifndef	__YH_DIGIT_FAULT_RECOED_H
#define	__YH_DIGIT_FAULT_RECOED_H

//#include "dbg_ctl.h"
#include "rt_ctl.h"
//#include "rt_analyse.h"
#include "rcd_ctl.h"
#include "shd_ctl.h"
//#include "mkshd.h"
//#include "wave_smp_ctl.h"

#ifdef __cplusplus
extern "C" {
#endif

extern RT_CTL*			g_rtCtl;		/*!< ʵʱ���ݿ��� */
extern TRNS_RCD_CTL*	g_rcdCtl;		/*!< ¼������ */
//extern WAVE_SMP_CTL*	g_waveCtl;		/*!< ʵʱ�������ݳ�ȡ���� */

int fltrcd_init( SHDFR_SG* pSg );
int fltrcd_reinit();
int fltrcd_destory();

/*!
    \brief	ʵʱ����
    \param	cyc_cnt		�ܲ���
    \return	��־�Ƿ����³�ʼ�������ϵͳ�Ѿ����³�ʼ���������¼��ض�ֵ��������1.���򷵻�0.
*/
int rt_proc( int cyc_cnt );


void rt_calc( CYC_DATA_IDX* pCycData );

/*!
    \brief	��ԭʼ�������������ٳ�ȡ����
    \param	dst_addr	Ŀ�ĵ�ַ
    \param	start_pos	��ȡ���ݵ���ʼλ��
    \param	pnt_cnt		��ȡ��ĸ���
    \param	step		��ȡ�Ĳ�������ʹ��step�����ȡһ���㣩
*/
void smpdata_from_rtbuf( INT8U* dst_addr, int start_pos, int pnt_cnt, int step );


/*!
    \brief	��̬¼������
    ʵʱ��̬¼������ÿ����һ�ܲ������ݣ�����һ�Ρ�
 */
void trns_rcd_proc( int cur_pos );

void cont_rcd_proc( int cur_pos );

void pq_rcd_proc( int cur_pos );

//char* FltSegFlg_itoa( int SegFlg );
void  print_rt_ctl  ( RT_CTL* prtCtl, FILE* fp );
void  print_shd_ctl ( MK_SHD_CTL* pShdCtl, FILE* fp );
void  print_rcd_ctl ( TRNS_RCD_CTL* prcdCtl, FILE* fp );
//void  print_flt_info( FAULT_INFO* pfltInfo, FILE* fp );

#ifdef __cplusplus
}
#endif

#endif	//__YH_DIGIT_FAULT_RECOED_H
