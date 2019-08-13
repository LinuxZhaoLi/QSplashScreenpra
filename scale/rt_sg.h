/*************************************************************************
* Copyright (c) 2008,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*! \file
    \brief      ����ʵʱ����ֵ������Ϣ
    \author     chentm
    \version    1.0
    \date       2011-05-10
    
	ʵʱ��������п���ʹ�õ�һЩ�������趨ֵ����Щ��������ԭʼ��ֵ�ṹ�в����ڣ�
	��������Ҫͨ��ԭʼ��ֵ�ṹ�����õ�����ˣ����������Ľṹ����������Щ��Ϣ��
	���������ŵ㣺
	1.����ϵͳ��ܽṹ�ȽϺ���������������ϵͳ����չ��
	2.���Լ���һЩ�м������̣����������ϵͳ���������ܣ�
	  (���磺����Խ�޷���ֵ���粻���ýṹ�洢��������ÿ�ܲ��ж�ʱ��Ҫ��һ�γ˷�����)
*/

#ifndef __YH_DFR_RT_PARM_DEFINE_H
#define __YH_DFR_RT_PARM_DEFINE_H

#include "sg_def.h"
#include "trg_def.h"


#ifdef __cplusplus
extern "C" {
#endif

/*!
    \brief  ģ����ͨ��ʵʱ�����Ӳ���
 */
typedef struct
{
    FLOAT32     HiTrgRtn;   /*!< ������������ֵ */
    FLOAT32     LoTrgRtn;   /*!< ������������ֵ */
	FLOAT32     SaTrgRrn;	/*!< ͻ����������ֵ */
    FLOAT32     Ha2TrgRtn;  /*!< 2��г����������ֵ */
    FLOAT32     Ha3TrgRtn;  /*!< 3��г����������ֵ */
    FLOAT32     Ha5TrgRtn;  /*!< 5��г����������ֵ */
    FLOAT32     Ha7TrgRtn;  /*!< 7��г����������ֵ */
    FLOAT32     Ha9TrgRtn;  /*!< 9��г����������ֵ */
//	FLOAT32     SwgTrgRtn;  /*!< �񵴷���ֵ */
//	FLOAT32		OscSaTrgLev;/*!< ��ͻ������ֵ */

	FLOAT32		Threshold;	/*!< ��Ч��ֵ */

} RT_ANCH_SET;


/*!
    \brief  ģ����ͨ��ʵʱ�����Ӳ���
 */
typedef struct
{
    FLOAT32     PSHiTrgRtn;     /*!< �������޷���ֵ */
    FLOAT32     PSLoTrgRtn;     /*!< �������޷���ֵ */
    FLOAT32     NSHiTrgRtn;     /*!< �������޷���ֵ */
    FLOAT32     ZSHiTrgRtn;     /*!< �������޷���ֵ */
  //  FLOAT32     ZSSaTrgRtn;     /*!< ����ͻ�䷵��ֵ */
    FLOAT32     SwgTrgRtn;      /*!< �񵴷���ֵ */

    FLOAT32     PHiTrgRtn;      /*!< �й��������޷���ֵ(��̬��������Ч) */
    FLOAT32     PRteTrgRtn;     /*!< �й��仯�ʷ���ֵ(��̬��������Ч) */
    FLOAT32     QHiTrgRtn;      /*!< �޹��������޷���ֵ(��̬��������Ч) */
    FLOAT32     QRteTrgRtn;     /*!< �޹��仯�ʷ���ֵ(��̬��������Ч) */
} RT_LIN_SET;


/*!
    \brief  ��ѹ��ʵʱ�����Ӳ���
 */
typedef struct
{
    FLOAT32     OvExTrgRtn;     	/*!< �����ŷ���ֵ(����ӿ������ڶ�����ı���) */
    FLOAT32     ThrITrgRtn;     	/*!< ��Խ��������ֵ(��Խ��������ڶ�����ı�����������̬����������) */
    FLOAT32     DifATrgRtn;     	/*!< ��������ֵ */
    FLOAT32     ResvLev[4];     	/*!< Ԥ�� */
    
} RT_TRN_SET;

/*!
	\brief �����ʵʱ�����Ӳ���
*/
typedef struct
{
	 FLOAT32	DifTrgRtn;			/*!< ��ȫ�ݲ��ֵ���ֱ��ӦA����ȫ�ݲ��ֵ��B����ȫ�ݲ��ֵ��C����ȫ�ݲ��ֵ */
	 FLOAT32	DifInTrgRtn;		/*!< ����ȫ�ݲ��ֵ���ֱ��ӦA�಻��ȫ�ݲ��ֵ��B�಻��ȫ�ݲ��ֵ��C�಻��ȫ�ݲ��ֵ */
	 FLOAT32	DifTranTrgRtn;		/*!< ����ֵ���ֱ��ӦA�����ֵ��B�����ֵ��C�����ֵ */

	 FLOAT32	OvExTrgRtn;     	/*!< �����ŷ���ֵ */
	 FLOAT32	LossExcTrgRtn;		/*!< ʧ��������ֵ */
	 FLOAT32	StatorZeroTrgRtn;	/*!< ���ӽӵ�֮�����ѹ����ֵ */
	 FLOAT32	StatorHar3TrgRtn;	/*!< ���ӽӵ�֮����г����ѹ�ȷ���ֵ */
	 FLOAT32	ZeroSeqTrgRtn;		/*!< ���������ѹʽ���������Ѽ��·����ֵ */
	 FLOAT32	RotorHar2TrgRtn;	/*!< ת�Ӷ���г������ֵ */
	 FLOAT32	ReversePoTrgRtn;	/*!< �湦�ʷ���ֵ */
	 FLOAT32	LowFreOvCurTrgRtn;	/*!< ��Ƶ��������ֵ */
}RT_GN_SET;

/*!
    \brief  ģ����ͨ������������ֵ
 */
typedef struct
{
     YH_ANCH_CFG        AnCfg;      /*!< ģ��ͨ���������ò���(������Ϣ) */
     YH_ANCH_SET        AnTrnsSet;  /*!< ��̬��ֵ */
     YH_ANCH_SET        AnContSet;  /*!< ��̬��ֵ */
     YH_PQ_ANCH_SET		AnPQSet;	/*!< ����������ֵ add by libo */
     
     RT_ANCH_SET		RtTrnsSet;	/*!< ��̬ʵʱ������� */
     RT_ANCH_SET		RtContSet;	/*!< ��̬ʵʱ������� */
} RT_ANCH_PARM;

/*!
    \brief  ��ѹͨ������������ֵ
 */
typedef struct
{
     YH_ULIN_CFG        LinCfg;         /*!< ��ѹ�������ò���(������Ϣ) */
     YH_LIN_SET         LinTrnsSet;     /*!< ��·��̬������ֵ */
     YH_LIN_SET         LinContSet;     /*!< ��·��̬����¼���ֵ */
     
     RT_LIN_SET			RtTrnsSet;		/*!< ��̬ʵʱ������� */
     RT_LIN_SET			RtContSet;		/*!< ��̬ʵʱ������� */
} RT_ULIN_PARM;

/*!
    \brief  ����ͨ������������ֵ
 */
typedef struct
{
     YH_ILIN_CFG        LinCfg;         /*!< ��·�������ò���(������Ϣ�����а����˷�ͨ���ļ���Ϣ) */
     YH_ILIN_FLO_SET    FloSet;         /*!< ��ඨֵ���� */
     YH_LIN_SET         LinTrnsSet;     /*!< ��·��̬������ֵ */
     YH_LIN_SET         LinContSet;     /*!< ��·��̬����¼���ֵ */

     RT_LIN_SET			RtTrnsSet;		/*!< ��̬ʵʱ������� */
     RT_LIN_SET			RtContSet;		/*!< ��̬ʵʱ������� */
} RT_ILIN_PARM;

/*!
    \brief  ��ѹ������������ֵ
 */
typedef struct
{
    YH_TRN_CFG     TrnCfg;         /*!< ��ѹ���������ò���(������Ϣ) */
    YH_TRN_SET     TrnTrnsSet;     /*!< ��ѹ����̬������ֵ */
    YH_TRN_SET     TrnContSet;     /*!< ��ѹ����̬����¼���ֵ */

	RT_TRN_SET     RtTrnsSet;     /*!< ��ѹ����̬�������ض�ֵ */
    RT_TRN_SET     RtContSet;     /*!< ��ѹ����̬����¼����ض�ֵ */
} RT_TRN_PARM;

/*!
	\brief	����������� ����ֵ
*/
typedef struct
{
	YH_GN_CFG		GnCfg;		 /*!< ������������ò��� */
	YH_GN_SET		GnTrnsSet;	 /*!< �������̬������ֵ */
	YH_GN_SET		GnContSet;	 /*!< �������̬����¼���ֵ */

	RT_GN_SET		RtTrnsSet;	 /*!< �������̬�������ض�ֵ */
	RT_GN_SET		RtContSet;	 /*!< �������̬����¼����ض�ֵ*/
}RT_GN_PARM;


typedef struct yh_binch_parm	RT_BINCH_PARM;
//typedef struct sh_trn_parm		RT_TRN_PARM;
//typedef struct sh_gn_parm		RT_GN_PARM;

typedef struct
{
    YH_DFR_PARM*        pDFRParm;      						/*!< ȫ�ֲ��� */
    RT_ANCH_PARM*       pAnChParm;      					/*!< ģ����ͨ����Ϣ */
    RT_BINCH_PARM*      pBinChParm;     					/*!< ״̬��ͨ����Ϣ */
    RT_ULIN_PARM*       pULinParm;      					/*!< ��ѹ����Ϣ */
    RT_ILIN_PARM*       pILinParm;      					/*!< ��·��Ϣ */
    RT_TRN_PARM*        pTrnParm;       					/*!< ��ѹ����Ϣ */
    RT_GN_PARM*         pGnParm;        					/*!< �������Ϣ */

    INT16U				BinTrgTrnsMsk[MAX_BINCH_WORD_NUM];	/*!< ������ͨ����̬��������    */
    INT16U				BinTrgContMsk[MAX_BINCH_WORD_NUM];	/*!< ������ͨ����̬��������    */
 
    INT32U              BufLen;         					/*!< ���������� */
    INT32U*             DataAddr;       					/*!< ��������ʼ��ַ */
} RTDFR_SG;

/*!
	\brief	��ʼ����ֵ�ṹ��Ϣ
	\param	rt_sg		[in,out]	��ֵ���ļ�
	\param	dfr_sg		[in]		��ֵ������
	\return	�ɹ�����0,���򷵻ش����
*/
int init_rt_sg( RTDFR_SG* rt_sg, SHDFR_SG* dfr_sg );

RTDFR_SG* create_rt_sg( SHDFR_SG* dfr_sg );

void destory_rt_sg( RTDFR_SG* rt_sg );

#ifdef __cplusplus
}
#endif

#endif	/*__YH_DFR_RT_PARM_DEFINE_H*/
