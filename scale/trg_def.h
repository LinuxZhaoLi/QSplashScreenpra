/*************************************************************************
* Copyright (c) 2010,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		¼��������Ϣ���ݽṹ�Ķ���
 	
	\author		chen
	\version	1.0
	\date		2010-03-11
*/

#ifndef	__SH_TRG_INFO_DATA_STRUCT_DEFINE_H
#define	__SH_TRG_INFO_DATA_STRUCT_DEFINE_H

#include "yhftypes.h"
#include "calc_def.h"
//#include "sg_def.h"


//SHDFR_B��̨�У����������ԭ����Ϣ

#define SHDFR_B_RcdTrg			0	/*!< �ֶ�¼�� */

#define	SHDFR_B_HzHiAct			101	/*!< Ƶ��Խ���� */
#define	SHDFR_B_HzLoAct			102	/*!< Ƶ��Խ���� */
#define	SHDFR_B_HzRteAct		103	/*!< Ƶ�ʱ仯�� */

#define	SHDFR_B_PsSeqHiAct		104	/*!< ����Խ���� */
#define	SHDFR_B_PsSeqLoAct		105	/*!< ����Խ���� */
#define	SHDFR_B_NgSeqHiAct		106	/*!< ����Խ���� */
#define	SHDFR_B_ZerSeqHiAct		107	/*!< ����Խ���� */
#define	SHDFR_B_ZerSeqDelAct	108	/*!< ����ͻ�� */

#define	SHDFR_B_SwgAct			109	/*!< �� */
#define	SHDFR_B_PHiAct			110	/*!< �й��������� */
#define	SHDFR_B_PRteAct			111	/*!< �й����ʱ仯�� */
#define	SHDFR_B_QHiAct			112	/*!< �޹��������� */
#define	SHDFR_B_QRteAct			113	/*!< �޹����ʱ仯�� */

#define	SHDFR_B_HiAct			201	/*!< ͨ��Խ���� */
#define	SHDFR_B_LoAct			202	/*!< ͨ��Խ���� */
#define	SHDFR_B_DelAct			203	/*!< ͨ��ͻ�� */
#define	SHDFR_B_Ha2Act			204	/*!< ͨ��2��г�� */
#define	SHDFR_B_Ha3Act			205	/*!< ͨ��3��г�� */
#define	SHDFR_B_Ha5Act			207	/*!< ͨ��5��г�� */
#define	SHDFR_B_Ha7Act			208	/*!< ͨ��9��г�� */
#define	SHDFR_B_Ha9Act			209	/*!< ͨ��9��г�� */

#define	SHDFR_B_BinAct			206	/*!< ���������� */

#define SHDFR_B_OvExAct			304	/*!< ��ѹ������������ */
#define SHDFR_B_DifAct			306	/*!< ��ѹ������������ֵ���� */

#define	MAX_ANCH_NUM	512		/*!< ���ģ����ͨ���� */
#define MAX_BINCH_NUM	1024	/*!< ��󿪹���ͨ����(������Ϊ8�ı���) */
#define MAX_ULIN_NUM	64		/*!< ����ѹ(����)�� */
#define MAX_ILIN_NUM	128		/*!< ������(����)�� */
#define MAX_TRN_NUM		16		/*!< ��������� */
#define MAX_GN_NUM		16		/*!< ��󷢵���� */

#define	MAX_BINCH_WORD_NUM		MAX_BINCH_NUM/8/2

#ifdef __cplusplus
extern "C" {
#endif


/*!
    \brief  ͨ��������Ϣ
    
    ����һ��ͨ��������״̬��Ϣ
 */
typedef struct ANCH_TRG_STRU
{
    /* ��һ���ֽ� */
    INT8U    DelAct : 1;     /*!< ͻ�䶯�� */
    INT8U    HiAct : 1;      /*!< Խ���޶��� */
    INT8U    LoAct : 1;      /*!< Խ���޶��� */
    INT8U    Ha2Act : 1;     /*!< ����г������ */
    INT8U    Ha3Act : 1;     /*!< ����г������ */
    INT8U    Ha5Act : 1;     /*!< ���г������ */
    INT8U    Ha7Act : 1;     /*!< �ߴ�г������ */
    INT8U    Ha9Act : 1;     /*!< �Ŵ�г������ */
    
    /* �ڶ����ֽ� */
	INT8U	 DelStr : 1;	 /*!< ͻ������ */
    INT8U    HiStr : 1;      /*!< Խ�������� */
    INT8U    LoStr : 1;      /*!< Խ�������� */
    INT8U    Ha2Str : 1;     /*!< ����г������ */
    INT8U    Ha3Str : 1;     /*!< ����г������ */
    INT8U    Ha5Str : 1;     /*!< ���г������ */
    INT8U    Ha7Str : 1;     /*!< �ߴ�г������ */
    INT8U    Ha9Str : 1;     /*!< �Ŵ�г������ */
    
	INT8U	 ReAct;			 /*!< �����־ */
	INT8U    Resv;			 /*!< Ԥ�� */
}ANCH_TRG;

/*!
    \brief  ��ѹ������Ϣ
    
    ����һ����ѹ����������Ϣ
 */
typedef struct ULIN_TRG_STRU
{
    /* ��һ���ֽ� */
    INT8U    PsSeqHiAct : 1;     /*!< ����Խ���޶��� */
    INT8U    PsSeqLoAct : 1;     /*!< ����Խ���޶��� */
    INT8U    NgSeqHiAct : 1;     /*!< ����Խ���޶��� */
    INT8U    ZerSeqHiAct: 1;     /*!< ����Խ���޶��� */
    INT8U    ZerSeqDelAct:1;     /*!< ����ͻ�䶯�� */
    INT8U    HzHiAct : 1;        /*!< Ƶ��Խ���޶��� */
    INT8U    HzLoAct : 1;        /*!< Ƶ��Խ���޶��� */
    INT8U    HzRteAct: 1;        /*!< Ƶ�ʱ仯��(ͻ��)���� */
    
    /* �ڶ����ֽ� */
    INT8U    PsSeqHiStr : 1;     /*!< ����Խ�������� */
    INT8U    PsSeqLoStr : 1;     /*!< ����Խ�������� */
    INT8U    NgSeqHiStr : 1;     /*!< ����Խ�������� */
    INT8U    ZerSeqHiStr: 1;     /*!< ����Խ�������� */
    INT8U    ZerSeqDelStr:1;     /*!< ����ͻ������ */
    INT8U    HzHiStr : 1;        /*!< Ƶ��Խ�������� */
    INT8U    HzLoStr : 1;        /*!< Ƶ��Խ�������� */
    INT8U    HzRteStr: 1;        /*!< Ƶ�ʱ仯��(ͻ��)���� */
    
	INT8U	 ReAct;				 /*!< �����־ */
    INT8U    Resv;			 	 /*!< Ԥ�� */
} ULIN_TRG;


/*!
    \brief  ������������Ϣ
    
    ����һ����������������Ϣ
 */
typedef struct ILIN_TRG_STRU
{
    /* ��һ���ֽ� */
    INT8U    NgSeqHiAct : 1;     /*!< ����Խ���޶��� */
    INT8U    ZerSeqHiAct: 1;     /*!< ����Խ���޶��� */
    INT8U    ZerSeqDelAct:1;     /*!< ����ͻ�䶯�� */
    INT8U    SwgAct : 1;         /*!< �񵴶��� */
    INT8U    PHiAct : 1;         /*!< �й�����Խ���޶��� */
    INT8U    PRteAct: 1;         /*!< �й����ʱ仯�ʶ��� */
    INT8U    QHiAct : 1;         /*!< �޹�����Խ���޶��� */
    INT8U    QRteAct: 1;         /*!< �޹����ʱ仯�ʶ��� */
    
    /* �ڶ����ֽ� */
    INT8U    NgSeqHiStr : 1;     /*!< ����Խ�������� */
    INT8U    ZerSeqHiStr: 1;     /*!< ����Խ�������� */
    INT8U    ZerSeqDelStr:1;     /*!< ����ͻ������ */
	INT8U    SwgStr : 1;		 /*!< ������ */
    INT8U    PHiStr : 1;         /*!< �й�����Խ�������� */
    INT8U    PRteStr: 1;         /*!< �й����ʱ仯������ */
    INT8U    QHiStr : 1;         /*!< �޹�����Խ�������� */
    INT8U    QRteStr: 1;         /*!< �޹����ʱ仯������ */
	
	INT8U	 ReAct;				 /*<  �����־ */
    INT8U    Resv;				 /*!< Ԥ�� */
} ILIN_TRG;

/************************2011.3.10�޸�**************************/
/*!
	\brief	�����������Ϣ
	
	����һ���������������Ϣ

	date	2011.3.10
*/
typedef struct GN_TRG_STRU
{
	INT8U	DifAAct: 1;			/*!< A���ݲ�� */
	INT8U	DifBAct: 1;			/*!< B���ݲ�� */
	INT8U	DifCAct: 1;			/*!< C���ݲ�� */
	INT8U	DifInAAct: 1;		/*!< A�಻��ȫ�ݲ�� */
	INT8U	DifInBAct: 1;		/*!< B�಻��ȫ�ݲ�� */
	INT8U	DifInCAct: 1;		/*!< C�಻��ȫ�ݲ�� */
	INT8U	DifTranAAct: 1;		/*!< A����� */
	INT8U	DifTranBAct: 1;		/*!< B����� */

	INT8U	DifTranCAct: 1;		/*!< C����� */
	INT8U	OvExAct: 1;			/*!< �����Ŷ��� */
	INT8U	LossExcAct: 1;		/*!< ʧ�Ŷ��� */
	INT8U	StatorEarthAct: 1;	/*!< ���ӽӵض��� */
	INT8U	ZeroSeqAct: 1;		/*!< ���������ѹ���� */
	INT8U	RotorHar2Act: 1;	/*!< ת�Ӷ���г������ */
	INT8U	ReversePoAct: 1;	/*!< �湦�ʶ��� */
	INT8U	LowFreOvCurAct: 1;	/*!< ��Ƶ�������� */

	INT8U	DifAStr: 1;			/*!< A���ݲ����� */
	INT8U	DifBStr: 1;			/*!< B���ݲ����� */
	INT8U	DifCStr: 1;			/*!< C���ݲ����� */
	INT8U	DifInAStr: 1;		/*!< A�಻��ȫ�ݲ����� */
	INT8U	DifInBStr: 1;		/*!< B�಻��ȫ�ݲ����� */
	INT8U	DifInCStr: 1;		/*!< C�಻��ȫ�ݲ����� */
	INT8U	DifTranAStr: 1;		/*!< A�������� */
	INT8U	DifTranBStr: 1;		/*!< B�������� */

	INT8U	DifTranCStr: 1;		/*!< C�������� */
	INT8U	OvExStr: 1;			/*!< ���������� */
	INT8U	LossExcStr: 1;		/*!< ʧ������ */
	INT8U	StatorEarthStr: 1;	/*!< ���ӽӵ����� */
	INT8U	ZeroSeqStr: 1;		/*!< ���������ѹ���� */
	INT8U	RotorHar2Str: 1;	/*!< ת�Ӷ���г������ */
	INT8U	ReversePoStr: 1;	/*!< �湦������ */
	INT8U	LowFreOvCurStr: 1;	/*!< ��Ƶ�������� */

	INT8U	ReAct;				/*!< �����־ >*/
	INT8U   Resv[3];			/*!< Ԥ�� */
} GN_TRG ;

/*****************************************************************************/

/*!
    \brief  ��ѹ��������Ϣ
    
    ����һ����ѹ����������Ϣ
 */
typedef struct TRN_TRG_STRU
{
    /* ��һ���ֽ� */
    INT8U    OvExAct: 1;     /*!< �����Ŷ��� */
    INT8U    ThrIAct: 1;     /*!< ��Խ�������� */
    INT8U    DifAAct: 1;     /*!< A���������� */
    INT8U    DifBAct: 1;     /*!< B���������� */
    INT8U    DifCAct: 1;     /*!< C���������� */
    INT8U    bit3: 1;        /*!< Ԥ�� */
    INT8U    bit2: 1;        /*!< Ԥ�� */
    INT8U    bit1: 1;        /*!< Ԥ�� */

	INT8U    OvExStr: 1;     /*!< �����Ŷ��� */
    INT8U    ThrIStr: 1;     /*!< ��Խ�������� */
    INT8U    DifAStr: 1;     /*!< A���������� */
    INT8U    DifBStr: 1;     /*!< B���������� */
    INT8U    DifCStr: 1;     /*!< C���������� */
    INT8U    bit6: 1;        /*!< Ԥ�� */
    INT8U    bit5: 1;        /*!< Ԥ�� */
    INT8U    bit4: 1;        /*!< Ԥ�� */

    /* �������ֽ� */
	INT8U	 ReAct;			 /*<  �����־ */
    INT8U    Resv;			 /*!< Ԥ�� */
} TRN_TRG;

/*!
	\brief	������Ϣ

	2011.1.17 Yuan Mingjun�޸ģ���������־ϸ�֣�����ͻ��������־λ���ڳ���Խ�޴��� 
*/
typedef struct TRG_FLG_STRU
{
    /* ��һ���ֽ� */
    INT8U    Act: 1;     	 /*!< ������־ */
    INT8U    ReAct: 1;     	 /*!< �����־ */
	INT8U    OscAct: 1;      /*!< �𵴶�����־ */
	INT8U    DelTrg: 1;      /*!< ͻ���������ô˱�־�����½���ABCD�Σ� */
	INT8U    HzRteAct: 1;    /*!< Ƶ�ʱ仯�ʶ�����־ */    	
	INT8U    bit3: 1;        /*!< Ԥ�� */
    INT8U    bit2: 1;        /*!< Ԥ�� */
    INT8U    bit1: 1;        /*!< Ԥ�� */
    
    /* �ڶ����ֽڣ�������־ */	
    INT8U    BinChAct: 1;    /*!< ������������־ */
    INT8U    AnChAct: 1;     /*!< ģ����ͨ��������־ */
	INT8U    ULineAct: 1;    /*!< ��·��ѹ�����־ */
	INT8U	 ILineAct: 1;	 /*!< ��·���������־ */
    INT8U    TrnAct: 1;      /*!< ��ѹ��������־ */
    INT8U    GnAct: 1;       /*!< �����������־ */
    INT8U    bit10: 1;       /*!< Ԥ�� */
    INT8U    bit9: 1;        /*!< Ԥ�� */

    /*  */
	INT16	 OscNum;		 /*!< ����ǰ���� */
}TRG_FLG;

typedef struct RESULT_FLG_STRU
{
	INT8U    Str: 1;		 /*!< ������־ */
	INT8U    Act: 1;		 /*!< ������־ */
	INT8U    bit6: 1;		 /*!< Ԥ�� */
    INT8U    bit5: 1;        /*!< Ԥ�� */
    INT8U    bit4: 1;        /*!< Ԥ�� */
    INT8U    bit3: 1;        /*!< Ԥ�� */
    INT8U    bit2: 1;        /*!< Ԥ�� */
    INT8U    bit1: 1;        /*!< Ԥ�� */
} RESULT_FLG;

/*!
    \brief  �����ṹ
 */
typedef struct TRG_INFO_STRU
{
    TRG_FLG			TrgFlg;							/*!< ������־ */
    ANCH_TRG    	AnChTrg[MAX_ANCH_NUM];  		/*!< ģ����ͨ��������Ϣ */
    ULIN_TRG    	ULinTrg[MAX_ULIN_NUM];    		/*!< ��ѹ������Ϣ */
    ILIN_TRG    	ILinTrg[MAX_ILIN_NUM];    		/*!< ����������Ϣ */
    GN_TRG      	GnTrg[MAX_GN_NUM];        		/*!< �����������Ϣ */
    TRN_TRG     	TrnTrg[MAX_TRN_NUM];      		/*!< ��ѹ��������Ϣ */

	/* ����ȫ���Ե�������Ϣ��ֻҪ���κ�һ��Ԫ�صĵ�������־Ϊ1����ȫ�ֵı�־Ϊ1��*/
	ANCH_TRG		GlbAnChTrg;						/*!< ȫ�ֵ�ģ����ͨ��������Ϣ */
	ULIN_TRG		GlbULinTrg;						/*!< ȫ�ֵĵ�ѹ������Ϣ */
	ILIN_TRG		GlbILinTrg;						/*!< ȫ�ֵĵ���������Ϣ */
	GN_TRG			GlbGnTrg;						/*!< ȫ�ֵķ����������Ϣ */
	TRN_TRG			GlbTrnTrg;						/*!< ȫ�ֵı�ѹ��������Ϣ */

	/* ���ж��������Ϣ������������¼���ǵ�һ��������Ϣ������ */
	INT16			IdxAnChTrg;						/*!< ������ ģ����ͨ��������Ϣ */
	INT16			IdxULinTrg;						/*!< ������ ��ѹ������Ϣ */
	INT16			IdxILinTrg;						/*!< ������ ����������Ϣ */
	INT16			IdxGnTrg;						/*!< ������ �����������Ϣ */
	INT16			IdxTrnTrg;						/*!< ������ ��ѹ��������Ϣ */
	INT16			IdxBinChTrg;					/*!< ������ ������ͨ��������Ϣ */

	INT32			BinTrgSmpIdx;					/*!< ����������ʱ(�׸���������λ)���ܲ��ڵĲ������ */
	YHFtimeval		BinTrgTimeStamp;				/*!< ����������ʱ(�׸���������λ)�ľ���ʱ�� */
	INT16U			BinChAct[MAX_BINCH_WORD_NUM];	/*!< ������ͨ������������Ϣ */
}TRG_INFO; 

/*!
    \brief  SHDFR_B������ԭ��ṹ
 */
typedef struct SHDFR_B_TRG_REASON_STRU
{
	INT32			TrgType;		/*!< �������� */
	INT32			ObjIndex;		/*!< ��Ӧͨ����Ż���·��� */
	INT32			RetrgTv;		/*!< ����ʱ�� */
	INT32			RetrgNo;		/*!< ������ */
}SHDFR_B_TRG_REASON;

/*!
 	\brief	������Ϣ����
 	\param	trg_info	¼��������֡
 	\param	dfr_cfg		�ò���ָ���˷���ʱ��ͨ��������·������Ϣ�����ΪNULL����ȱʡ�����ֵ���з�����
 */
void trginfo_analyse( TRG_INFO* trg_info, struct yh_dfr_cfg* dfr_cfg );

/*!
 	\brief	��������Ϣת��ΪSHDFR_B�е�����ԭ����Ϣ��
 */
void trginfo_2_shdfr_b( TRG_INFO* trg_info, SHDFR_B_TRG_REASON* trg_reson, int ulin_cnt );

#ifdef __cplusplus
}
#endif


#endif	/* __SH_TRG_INFO_DATA_STRUCT_DEFINE_H */
