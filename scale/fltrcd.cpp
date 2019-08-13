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

#include "../scale/fltrcd.h"

//#include "tmp.h"
//#include "sg_mgr.h"
//ctm #include "rt_comtrade.h"

//#include "rcd_dbg.h"

//DBG_CTL	g_dbgCtl  = {0};		/*!< ����ѡ����� */
RT_CTL		*g_rtCtl  = NULL;		/*!< ʵʱ���� */
TRNS_RCD_CTL	*g_rcdCtl = NULL;	/*!< ��̬¼������ */
//WAVE_SMP_CTL	*g_waveCtl= NULL;	/*!< ʵʱ�������ݳ�ȡ���� */

int fltrcd_init( SHDFR_SG* pSg )
{
    int ret;
    MK_SHD_CTL *pShdCtl;

    //����ʵʱ������Ϣ
    g_rtCtl = rt_ctl_create( pSg, RT_BUFF_CYC_NUM );	//12 s ������
    if ( NULL == g_rtCtl )
    {
        printf( "rt_ctl_create() failed!\n" );
        return -1;
  }

    ret = rt_ctl_init( g_rtCtl, pSg );
 // tmp::setDigital();
    if ( ret != 0 )
    {
        printf( "rt_ctl_init() failed!\n" );
        fltrcd_destory();
        return -1;
    }

    //print_rt_ctl( g_rtCtl, stdout );

//    g_rcdCtl = rcd_ctl_create();
//    if ( NULL == g_rtCtl )
//    {
//        printf( "rcd_ctl_create() failed!\n" );
//        fltrcd_destory();
//        return -1;
//    }

//    ret = rcd_ctl_init( g_rcdCtl, pSg );
//    if ( ret != 0 )
//    {
//        printf( "rcd_ctl_init() failed!\n" );
//        fltrcd_destory();
//        return -1;
//    }

//	g_waveCtl = wave_smp_ctl_create( pSg );
    if ( NULL == g_rtCtl )
    {
        printf( "wave_smp_ctl_create() failed!\n" );
        fltrcd_destory();
        return -1;
    }

/*	ret = wave_smp_ctl_init( g_waveCtl, pSg );
    if ( ret != 0 )
    {
        printf( "wave_smp_ctl_init() failed!\n" );
        fltrcd_destory();
        return -1;
    }
*/
    pShdCtl = shd_ctl_create( 52 * 1024 *1024 );
    if ( NULL == pShdCtl )
    {
        printf( "shd_ctl_create() failed!\n" );
        fltrcd_destory();
        return -1;
    }
    //g_rcdCtl->FltInfo1->MkShdCtl = pShdCtl;

//    ret = shd_ctl_init( pShdCtl, pSg, NULL, NULL, 0 );
//    if ( ret != 0 )
//    {
//        printf( "shd_ctl_init() failed!\n" );
//        fltrcd_destory();
//        return -1;
//    }

    pShdCtl = shd_ctl_create( 52 * 1024 *1024 );
    if ( NULL == pShdCtl )
    {
        printf( "shd_ctl_create() failed!\n" );
        fltrcd_destory();
        return -1;
    }
   // g_rcdCtl->FltInfo2->MkShdCtl = pShdCtl;

  //  ret = shd_ctl_init( pShdCtl, pSg, NULL, NULL, 0 );
    if ( ret != 0 )
    {
        printf( "shd_ctl_init() failed!\n" );
        fltrcd_destory();
        return -1;
    }

    return 0;
}

int fltrcd_reinit()
{
    return 0;
}

int fltrcd_destory()
{
    if ( g_rtCtl != NULL )
    {
        rt_ctl_destory( g_rtCtl );
        g_rtCtl = NULL;
    }

/*	if ( g_waveCtl != NULL )
    {
        wave_smp_ctl_destory( g_waveCtl );
        g_waveCtl = NULL;
    }
*/
//    if ( g_rcdCtl != NULL )
//    {
//        rcd_ctl_destory( g_rcdCtl );
//        g_rcdCtl = NULL;
//    }

    return 0;
}
