/*! \file
    \brief      ����SHDFR����/��ֵ�ṹ
    \author     Chentm
    \version    2.0
    \date       2011-05-08
	<pre>
	
    ���ļ��ж�����SHDFR�������ϼ�¼װ�����á���ֵ��ؽṹ��Ϣ��

    ����Ϊ���ļ��и�����/������д��˵����
    An      Analogue                ģ����
    Bin     Binary                  ������(��IEC 61850����һ��)
    Bra     Branch
    Cfg     Config
    Cnt     Count
    Ch      Channels
    ECur    Electric Current
    Hz      Frequency
    Info    Information
    Hi      High
    Mi      Middle
    Lo      Low
    Mrk     Mark
    Trg     Trigger
    Num     Number
    Parm    Parameter
    Vol     Voltage
    Gn      Generator
    Flo     Fault Location
    Lev     Level
    Ena     Enable
    Stn     Station
    SetVal  SettingValue
    Trn     Transformer
    DFR     Digit Fault Recorder
    Rtg     Rating
    Idx     Index
    Glb     Global
    Cont    Continuous
    Smp     Sample
    Dur     Duration
    Resv    Reserve
    Bus     Bus bar         ĸ��    
    Trns    Transient       ��̬ 
	Cle     clearance       ��϶
	Pri     Primary         ��Ҫ�ģ�һ�ε�
	Scou    self-coupling   ����
    Comwinding        common winding    ��������
    
    ��ֵ����ṹ��
    +-------------------+---------------+-------+-----------+-------+-----------------------------------+
    |       ����        |  ����         |��С   |����       |LN     |˵��                               |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_DFR_PARM        |YH_DFR_PARM    |       |           |       |¼������Ϣ                         |
    | DfrCfg            |YH_DFR_CFG     |       | 1         |       |¼����������Ϣ                     |
    | DfrTrnsSet        |YH_TRNS_RCD_SET|       | 1         |RDRE_T |��̬RDRE��ֵ                       |
    | DfrContSet        |YH_CONT_RCD_SET|       | 1         |RDRE_C |��̬RDRE��ֵ                       |
    | HzTrnsSet         |YH_HZ_SET      |       | 1         |RFDR   |��̬Ƶ�ʶ�ֵ                       |
    | HzContSet         |YH_HZ_SET      |       | 1         |RFDR   |��̬Ƶ�ʶ�ֵ                       |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_ANCH_PARM       |YH_ANCH_PARM   |       | AnChCnt   |       |ģ����ͨ������                     |
    | AnCfg             |YH_ANCH_CFG    |       | 1         |       |ģ��ͨ���������ò���(������Ϣ)     |
    | AnTrnsSet         |YH_ANCH_SET    |       | 1         |RADR   |ģ��ͨ����̬��ֵ                   |
    | AnContSet         |YH_ANCH_SET    |       | 1         |RADR   |ģ��ͨ����̬��ֵ                   |
    | AnPQSet      	    |YH_PQ_ANCH_SET |       | 1         |       |ģ��ͨ������������ֵ               |    
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_BINCH_PARM      |YH_BINCH_PARM  |       | BinChCnt  |RBDR   |״̬��ͨ������                     |
    | BinCfg            |YH_BINCH_CFG   |       | 1         |RBDR   |״̬��ͨ������                     |
    | BinTrnsSet        |YH_BINCH_SET   |       | 1         |RBDR   |״̬��ͨ������                     |
    | BinContSet        |YH_BINCH_SET   |       | 1         |RBDR   |״̬��ͨ������                     |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_ILIN_PARM       |YH_ILIN_PARM   |       | ILinCnt   |       |����(��·)����                     |
    | LinCfg            |YH_ILIN_CFG    |       | 1         |       |�����������ò���(������Ϣ)         |
    | FloSet            |YH_ILIN_FLO_SET|       | 1         |RFLO   |���ϲ�ඨֵ  ******               |
    | LinTrnsSet        |YH_LIN_SET     |       | 1         |RDIS   |��������¼����ֵ  *****            |
    | LinContSet        |YH_LIN_SET     |       | 1         |RDIS   |��������¼���ֵ   ******          |
    | LinPQSet	        |YH_PQ_LIN_SET  |       |   1       |RDIA   |����������ֵ                       |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_ULIN_PARM       |YH_ULIN_PARM   |       | ULinCnt   |       |��ѹ����                           |
    | LinCfg            |YH_ULIN_CFG    |       | 1         |       |��ѹ�������ò���(������Ϣ)         |
    | LinTrnsSet        |YH_LIN_SET     |       | 1         |RDUS   |��ѹ����¼����ֵ                   |
    | LinContSet        |YH_LIN_SET     |       | 1         |RDUS   |��ѹ����¼���ֵ                   |
    | LinPQSet	        |YH_PQ_LIN_SET  |       | 1         |RDUA   |����������ֵ                       |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_TRN_PARM        |YH_TRN_PARM    |       | TrnCnt    |       |��ѹ����Ϣ                         |
    | TrnCfg            |YH_TRN_CFG     |       | 1         |       |��ѹ���������ò���(������Ϣ)       |
    | TrnTrnsSet        |YH_TRN_SET     |       | 1         |       |��ѹ������¼����ֵ                 |
    | TrnContSet        |YH_TRN_SET     |       | 1         |       |��ѹ������¼���ֵ                 |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    |YH_GN_PARM         |YH_GN_PARM     |       | GnCnt     |       |�������Ϣ                         |
    | GnCfg             |YH_GN_CFG      |       | 1         |       |������������ò���(������Ϣ)       |
    | GnTrnsSet         |YH_GN_SET      |       | 1         |       |���������¼����ֵ                 |
    | GnContSet         |YH_GN_SET      |       | 1         |       |���������¼���ֵ                 |
    +-------------------+---------------+-------+-----------+-------------------------------------------+   
    |CheckSum           |INT32U         |       | 1         |       |У���                             |
    +-------------------+---------------+-------+-----------+-------------------------------------------+
    
    ����˵����
    1.��̬����̬��ֵ�����ݽṹ��ȫ��ͬ��������������ͬ��
      ������̬���ԣ���Ena�������������ʶ��Ӧ�Ĵ���¼���Ƿ����ã�
      ������̬���ԣ���Ena�������������ʶ�Ƿ��¼��Ӧ�ı�ʶ�¼���

    2.��ֵ�ṹ��С��������ء�
    
    ע�⣺���Ķ���Ľṹ���Ѿ�Ϊδ��������Ԥ������Ӧ�Ŀռ䣬��δ����������ʱ��ֱ���������Ԥ���ռ䡣
          ����Ա�֤��ֵ������ǰ���ݡ�����չ����ʱ��Ҫ�ر�ע�Ᵽ֤�ֽڱ߽���롣
    
    �ṹ��ռ�ռ��Ϊ��
	sizeof( YH_DFR_CFG )           = 600
	sizeof( YH_TRNS_RCD_SET )      = 60
	sizeof( YH_CONT_RCD_SET )      = 40
	sizeof( YH_HZ_SET )            = 40
	sizeof( YH_ANCH_CFG )          = 120
	sizeof( YH_ANCH_SET )          = 80
	sizeof( YH_PQ_ANCH_SET )       = 160
	sizeof( YH_BINCH_CFG )         = 100
	sizeof( YH_BINCH_SET )         = 20
	sizeof( YH_ULIN_CFG )          = 160
	sizeof( YH_ILIN_CFG )          = 180
	sizeof( YH_LIN_SET )           = 80
	sizeof( YH_ILIN_FLO_SET )      = 80
	sizeof( YH_TRN_CFG )           = 240
	sizeof( YH_TRN_SET )           = 40
	sizeof( YH_GN_CFG )            = 100
	sizeof( YH_GN_SET )            = 40
	sizeof( YH_DFR_PARM )          = 780
	sizeof( YH_ANCH_PARM )         = 440
	sizeof( YH_BINCH_PARM )        = 140
	sizeof( YH_ULIN_PARM )         = 320
	sizeof( YH_ILIN_PARM )         = 420
	sizeof( YH_TRN_PARM )          = 320
	sizeof( YH_GN_PARM )           = 180
    </pre>
*/

#ifndef __YH_DFR_PARM_DEFINE_H
#define __YH_DFR_PARM_DEFINE_H

#include "yhftypes.h"

#define MAX_TRN_BRA 3

#ifdef __cplusplus
extern "C" {
#endif

/* ���ļ��ж�������нṹ�����1�ֽڶ��� */
#pragma pack (1)

typedef struct runtime_type RUNTIME_TYPE;

typedef struct
{
    char    ip[16];         /*!< IP��ַ */
    char    netmask[16];    /*!< ��������   */
}NET_CFG_INFO;

/*!
    \brief  ¼����������Ϣ
 */
typedef struct  yh_dfr_cfg
{
    INT32U          Ver;            /*!< �汾�� */
    INT32U          StnID;          /*!< ���վ�� */
    INT32U          DFRID;          /*!< ¼������ */
    char            StnName[64];    /*!< ���վ�� */
    char            DFRName[64];    /*!< ¼������ */
    
    INT32           AnChCnt;        /*!< ģ����ͨ���� */
    INT32           BinChCnt;       /*!< ״̬��ͨ���� */
    INT32           ULinCnt;        /*!< ��ѹ���� */
    INT32           ILinCnt;        /*!< ��·�� */
    INT32           FLinCnt;        /*!< Feeder ��·��  */
    INT32           TrnCnt;         /*!< ��ѹ���� */
    INT32           GnCnt;          /*!< ������� */

	INT32			AnBoardCnt;		/*!< ��ͳ������ģ�����忨�� */
	INT32			BinBoardCnt;	/*!< ��ͳ�������������忨�� */

    INT32           Freq;           /*!< ����Ƶ�ʣ�50��60Hz */

    NET_CFG_INFO    Mon1NetCfg[4];  /*!< ��ذ�1�豸Ip��ַ */
    NET_CFG_INFO    Mon2NetCfg[4];  /*!< ��ذ�2�豸Ip��ַ */

	/*
		1<<0 :������̬ҵ��
		1<<1 :������̬ҵ��
		1<<2 :������������ҵ��
		1<<3 :����PMUҵ��
		Ϊ0����ʾ�˼�ذ岻����
		ͨ������������������ҵ��
	*/

	INT32			DevBusiness;	/*!< �����豸������ҵ��Ϊ���濪����������壩 */
	INT32			MonBusiness[2];	/*!< ��ذ�������ҵ���� */

	INT8			MonitorNo;		/*!< ����ذ��ţ�=1 �� =2 */

    INT8            TrnsEna;        /*!< �Ƿ�������̬���� */
    INT8            ContEna;        /*!< �Ƿ�������̬���� */
    INT8            PQEna;			/*!< �Ƿ����õ����������� */
    
    INT8            DirMod;         /*!< ��Ŀ¼��ʽ;0=IEC 61850��׼Ŀ¼,1=�㶫��׼,2=�㽭��׼,3=���� */
    INT8            FileNaming;     /*!< �ļ�������ʽ:0=COMTRADE����׼��1���㶫��׼��2���㽭��׼��3������ */
    INT8            NasEna;         /*!< �Ƿ���������洢��,��̬��Ч */

	INT8			SntpEna;		/*!< �Ƿ�����SNTP��ʱ */
	INT8			Protocol103Ena;	/*!< �Ƿ�����103ͨѶ */

    INT8            Resv1[3];      	/*!< Ԥ������֤�ֽڶ��� */

	INT32			SmpCntPerCyc;	/*!< ϵͳÿ�ܲ���������(ԭʼ������) */
	INT32			RtCycCnt;		/*!< ʵʱ������ʾʱ���ܲ��� */

	INT8            Resv2[120];      /*!< Ԥ�����ṹ��СΪ 600 �ֽ� */

} YH_DFR_CFG;


/*!
    \brief  ¼��������¼����ֵ����
    
    ���ṹ������������RDRE_Trns�߼��ڵ���ڶ�Ӧ�Ĺ�ϵ��
 */
typedef struct  yh_trns_rcd_set
{
    INT32       A2NumCyc;       /*!< A2 �ε��ܲ��� 0 */
    INT32       A1NumCyc;       /*!< A1 �ε��ܲ��� 5 */
    INT32       BNumCyc;        /*!< B  �ε��ܲ��� 15 */
    INT32       CNumCyc;        /*!< C  �ε��ܲ��� 100 */
    INT32       DNumCyc;        /*!< D  �ε��ܲ��� 250 */
    
    INT32       A2SmpRte;       /*!< A2 �μ�¼Ƶ�� 50 */
    INT32       A1SmpRte;       /*!< A1 �μ�¼Ƶ�� 100000 */
    INT32       BSmpRte;        /*!< B  �μ�¼Ƶ�� 100000 */
    INT32       CSmpRte;        /*!< C  �μ�¼Ƶ�� 50 */
    INT32       DSmpRte;        /*!< D  �μ�¼Ƶ�� 10 */
    INT32       MaxNumRcd;      /*!< ����¼�ļ����� 1000 */
    INT8        Resv[16];       /*!< Ԥ������֤�����ṹ���СΪ 60 �ֽ� */
} YH_TRNS_RCD_SET;


/*!
    \brief  ¼��������¼���ֵ����
    
    ���ṹ������������RDRE_Cont�߼��ڵ���ڶ�Ӧ�Ĺ�ϵ��
 */
typedef struct  yh_cont_rcd_set
{
    INT32U      SmpRte;         /*!< ������¼������ 1000 */
    INT32U      RcdDur;         /*!< ������¼Сʱ�� (Сʱ) */
    INT32U      MaxNumRcd;      /*!< ����¼�ļ����� */
    INT32       RcdFileDur;     /*!< ÿ���ļ��ļ�¼ʱ�� 120s */
    INT8        Resv[24];       /*!< Ԥ������֤�����ṹ���СΪ 40 �ֽ� */
} YH_CONT_RCD_SET;


/*!
    \brief  Ƶ�ʶ�ֵ
    
    ���ṹ������������RFDR�߼��ڵ���ڶ�Ӧ�Ĺ�ϵ��
    ������Ƶ����صĶ�ֵ��洢�ڱ��ṹ�У���̬/��̬������һ��ʵ����
 */
typedef struct  yh_hz_set
{
    FLOAT32     HzDfTrgLev;     /*!< Ƶ�ʱ仯������ֵ */
    FLOAT32     HzHiTrgLev;     /*!< Ƶ������ֵ */
    FLOAT32     HzLoTrgLev;     /*!< Ƶ������ֵ */
	FLOAT32     HzDfTrgRtn;		/*!< Ƶ�ʱ仯�ʷ���ֵ */
	FLOAT32     HzHiTrgRtn;		/*!< Ƶ�����޷���ֵ */
	FLOAT32     HzLoTrgRtn;		/*!< Ƶ�����޷���ֵ */
 // FLOAT32     ResvVal[3];     /*!< Ԥ�� */
    
    INT8        HzDfTrgEna;     /*!< Ƶ�ʱ仯������ʹ�� */
    INT8        HzHiTrgEna;     /*!< Ƶ����������ʹ�� */
    INT8        HzLoTrgEna;     /*!< Ƶ����������ʹ�� */
    INT8        ResvEna[13];    /*!< Ԥ��, �ṹ���СΪ 40 �ֽ� */
} YH_HZ_SET;


#define		ANCH_TYPE_UNKNOWN	0	/*!< ģ����ͨ������ UnKnown */
#define		ANCH_TYPE_TV		1	/*!< ģ����ͨ������ ������ѹ */
#define		ANCH_TYPE_TA		2	/*!< ģ����ͨ������ �������� */
#define		ANCH_TYPE_DV		3	/*!< ģ����ͨ������ ֱ����ѹ */
#define		ANCH_TYPE_DA		4	/*!< ģ����ͨ������ ֱ������ */
#define		ANCH_TYPE_HF		5	/*!< ģ����ͨ������ ��Ƶ */
#define		ANCH_TYPE_FQ		6	/*!< ģ����ͨ������ Ƶ�� */

#define		PHS_TYPE_NULL		0	/*!< ��� UnKnown */
#define		PHS_TYPE_UNKNOWN	0	/*!< ��� UnKnown */
#define		PHS_TYPE_A			1	/*!< ��� A�� */
#define		PHS_TYPE_B			2	/*!< ��� B�� */
#define		PHS_TYPE_C			3	/*!< ��� C�� */
#define		PHS_TYPE_N			4	/*!< ��� N�� */

/*! \struct YH_ANCH_CFG
    \brief  ģ����ͨ������
 */
typedef struct  yh_anch_cfg
{
    char        Name[64];       /*!< ͨ������ */
    INT32       Index;          /*!< ͨ�������ţ���Ӧ������ͨ����(��ChnNum���岻ͬ��һ�������Ӧ������Ϊ��ȵ�ֵ) */
    INT32       ChNum;          /*!< ͨ����ţ���Ӧ��COMTRADE�ļ��е�ͨ���� */
       
    INT8        ChTyp;          /*!< ģ����ͨ�������ͣ�0=UnKnown 1=������ѹ(TV)��2=��������(TA)��3=ֱ����ѹ(DV)��4=ֱ������(DA); 5=��Ƶ(HF); 6=Ƶ��(FQ) */
    INT8        Unit;           /*!< ��λ,ֵ��IEC 61850��SIUnitEnumö��ֵ����һ�� */
    INT8        UnitMultiplier; /*!< ��λ����,ֵ��IEC 61850��multiplierEnumö��ֵ����һ�� */
    INT8        BindType;       /*!< ������,0--�ް�,1--��ѹ,2--���� */
    
    INT8		Resv1[2];		/*!< Ԥ������֤�ֽڶ��� */
    INT16       BindNum;        /*!< �����,��ʶ��ͨ������һ����ѹ���������*/
    
    FLOAT32     Freq;           /*!< ��ͨ���ĶƵ�ʣ����Խ���ͨ����Ч */
	FLOAT32     ACSecRtg;       /*!< ��ͨ���Ķ��ζֵ�����Խ���ͨ����Ч */

    /* 2011.05 ������������Ӷ�ֵ�����Ƶ����������У���Ϊ���۶�����̬����̬������������Ӧ�ã���Щ��������һ�µ� */
    FLOAT32     Offset;     	/*!< ƫ���� */
    FLOAT32     Scaler;     	/*!< ����ϵ�� */
    FLOAT32     Skew;       	/*!< ͨ���ǲ� */
    FLOAT32     Ratio;      	/*!< ��� */
    
    INT8U       SmpTyp;         /*!< �ɼ����ͣ�0 -- ��ͳ�������� 1 -- 60044-8���� 2 -- IEC61850-9-1 3 -- IEC61850-9-2LE 4 -- IEC61850-9-2   */
    INT8U       DsIdx;          /*!< ��ͨ������Ӧ�����ݼ���������,�������ֲ���������   */
    INT16U      FcdaIdx;        /*!< ��ͨ������Ӧ�����ݼ��ڵ�FCDA��������   */
    
    INT8        Resv[12];       /*!< Ԥ�������ڽ������ܵ���չӦ�ã����������ṹ���СΪ 120 �ֽ� */
} YH_ANCH_CFG;


/*!
    \brief  ģ����ͨ����ֵ
    
    ���ṹ������������RADR�߼��ڵ���ڶ�Ӧ�Ĺ�ϵ��
    ������ģ����ͨ����صĶ�ֵ��洢�ڱ��ṹ�У���̬/��̬ÿ��ģ����ͨ������һ��ʵ����
 */
typedef struct  yh_anch_set
{
    INT32       Index;		/*!< ˳�������ţ���1��ʼ������������ */
    FLOAT32     HiTrgLev;   /*!< ����������ֵ */
    FLOAT32     LoTrgLev;   /*!< ����������ֵ */
    FLOAT32     SaTrgLev;   /*!< ͻ��������ֵ��ע��SaΪsalient����д(ͻ����) */
    FLOAT32     Ha2TrgLev;  /*!< 2��г��������ֵ */
    FLOAT32     Ha3TrgLev;  /*!< 3��г��������ֵ */
    FLOAT32     Ha5TrgLev;  /*!< 5��г��������ֵ */
    FLOAT32     Ha7TrgLev;  /*!< 7��г��������ֵ */
    FLOAT32     Ha9TrgLev;  /*!< 9��г��������ֵ */

    FLOAT32     ResvLev[7]; /*!< Ԥ�������ڽ������ܵ���չӦ�� */
    
    INT8        HiTrgEna;   /*!< ��������ʹ�� */
    INT8        LoTrgEna;   /*!< ��������ʹ�� */
    INT8        SaTrgEna;   /*!< ͻ������ʹ�� */
    INT8        Ha2TrgEna;  /*!< 2��г������ʹ�� */
    INT8        Ha3TrgEna;  /*!< 3��г������ʹ�� */
    INT8        Ha5TrgEna;  /*!< 5��г������ʹ�� */
    INT8        Ha7TrgEna;  /*!< 7��г������ʹ�� */
    INT8        Ha9TrgEna;  /*!< 9��г������ʹ�� */
    
    INT8        ResvEna[8]; /*!< Ԥ�������ڽ������ܵ���չӦ�ã�����֤�����ṹ��ռ�� 80 �ֽڴ洢�ռ� */
} YH_ANCH_SET;

/*!
 	\brief	��������ģ����ͨ����ֵ
 	
 */
typedef struct  yh_PQ_anch_set
{
	INT32		Index;			/*!< ˳�������ţ���1��ʼ������������ */
	FLOAT32		HiTrgLev;		/*!< ��ѹ���޶�ֵ */
	FLOAT32		LoTrgLev;		/*!< ��ѹ���޶�ֵ */
	FLOAT32		VFTrgLev;		/*!< ��ѹ�������޶�ֵ VF=Voltage Fluctuation */
	FLOAT32		SSeverityTrgLev;/*!< ��ʱ�����޶�ֵ */
	FLOAT32		LSeverityTrgLev;/*!< ��ʱ�����޶�ֵ */
	FLOAT32		THDHiTrgLev;	/*!< �ܻ������޶�ֵ���ٷֱȣ� */
	FLOAT32		OddTrgLev;		/*!< ���г���޶�ֵ����ѹͨ�����ٷֱȣ� */
	FLOAT32		EvenTrgLev;		/*!< ż��г���޶�ֵ����ѹͨ�����ٷֱȣ� */
	FLOAT32		HaTrgLev[24];	/*!< 2~25��г����ֵ(������ͨ��) */
	
	/*��ָ̬��*/
	FLOAT32		VTranRisingTrgLev;	/*!< ������(�ٷֱȣ���ѹ��Ч) */
	FLOAT32		VTranfallingTrgLev;	/*!< �ݽ���(�ٷֱȣ���ѹ��Ч) */

	INT8		VTranRisingTrgEna;	/*!< ��������ʹ�� */
	INT8		VTranfallingTrgEna;	/*!< ��������ʹ�� */
	INT8		VIntTrgEna;	/*!< ��ѹ�ж�����ʹ�� */

	INT8		ResvEna[1];	/*!< Ԥ�������ڽ������ܵ���չӦ�ã�����֤�����ṹ��ռ��  �ֽڴ洢�ռ� */
} YH_PQ_ANCH_SET;


#define		BINCH_LEVEL_OTHERS			0	/*!< ������ͨ������ ���������� */
#define		BINCH_LEVEL_RELAY_ACT		1	/*!< ������ͨ������ �������� */
#define		BINCH_LEVEL_BREAKER_POS		2	/*!< ������ͨ������ ����λ�� */
#define		BINCH_LEVEL_SWITCH_POS		3	/*!< ������ͨ������ ��բλ�� */
#define		BINCH_LEVEL_DEVICE_ALARM	4	/*!< ������ͨ������ װ�ø澯 */

/*!
    \brief  ������ͨ��������
    
    <pre>
	ChLevel: �������źŵķ��ࣺ
	         1=����������2=����λ�ã�3=��բλ�ã�4=װ�ù��ϸ澯��0=�������͡�

	ChTyp:   �������źŵ����ͣ��������£�
	         ����������Relay_Act����
	                 1=��A��2=��B��3=��C��4=������5=�غ�բ��6=������7=���㣻
                     8=������9=�������10=��������11=�ӵ�����0=������
	         ����λ�ã�Breaker_Pos����
	                 1=A�ϣ�2=A����3=B�ϣ�4=B����5=C�ϣ�6=C����0=������
	         װ�ø澯��Device_Alarm����
	                 1=TA���ߣ�2=TV���ߣ�3=ͨ�����ϣ�0=������
	         ������������
	                 1=���ţ�2=���ţ�0=������
    
    ����ͬʱ���ڴ�ͳ������������GOOSE������������Ӧ����˵��
    Լ�����£���ͳ����������������ǰ��
    
    </pre>
 */
typedef struct  yh_binch_cfg
{
    char        Name[64];       /*!< ͨ������ */
    INT32       Index;          /*!< ͨ�������ţ���Ӧ������ͨ���� */
    INT32       ChNum;          /*!< ͨ����ţ���Ӧ��COMTRADE�ļ��е�ͨ���� */

    INT8        BindType;       /*!< ������,0--�ް�,1--��ѹ,2--���� */
    INT8        ChLevel;        /*!< �������źŵķ��� */    
	INT8        ChTyp;          /*!< ������������ */    
	INT8		Resv1[3];		/*!< Ԥ������֤�ֽڱ߽���� */  

	INT16       BindNum;        /*!< �����,��ʶ��ͨ������һ����ѹ������������μ�BindType����*/

    /*!
    ��������
    ���ػ��߱���/�󱸱�������1�ı�ţ� 0Ϊ��ȷ��
    ��typeΪJump_A��Jump_B��Jump_C��Jump_ABCʱ��Ӧ�Ŀ��ر�ţ���mΪ1��2�ֱ��Ӧ����1������2��
    ��typeΪJump_ ACT��Send��Recv��Jump_BK_ACTʱ�ֱ��Ӧ�ı���/�󱸱�����ţ�
    ��mΪ1��2�ֱ��Ӧ����1����������2�������ߺ󱸱���1�������󱸱���2������Jump_ BK_ACT����
    */
    INT32       GrID;
    
    INT8U       SmpTyp;         /*!< �ɼ����ͣ�0 -- ��ͳ�������� 1 -- GOOSE���� */
    INT8U       DsIdx;          /*!< ��ͨ������Ӧ�����ݼ���������,��SmpTypΪGOOSEʱ��������   */
    INT16U      FcdaIdx;        /*!< ��ͨ������Ӧ�����ݼ��ڵ�FCDA��������   */
    
    INT8        Resv[12];        /*!< Ԥ�������ڽ������ܵ���չӦ��,�����ṹ���СΪ  100 �ֽ� */
}YH_BINCH_CFG;


/*!
    \brief  ������ͨ����ֵ��    
 */
typedef struct  yh_binch_set
{
    INT32       Index;			/*!< ������˳�������ţ���1��ʼ������������ */
    
    INT8        StVal;          /*!< ��ʶ��ͨ���ǳ������ǳ��� 0--���� 1--���� */
    INT8        TrgEna;         /*!< ״̬������ʹ�� */
    
    INT8        Resv[14];       /*!< Ԥ�������ڽ������ܵ���չӦ��,�����ṹ���СΪ 20 �ֽ� */
} YH_BINCH_SET;


/*!
    \brief  ��ѹ�����ò���  
 */
typedef struct  yh_ulin_cfg
{
    char        Name[64];       /*!< ��ѹ���� */
    INT32       Index;          /*!< ˳�������ţ���1��ʼ������������ */
    
    INT8        VolLev;         /*!< ��ѹ�ȼ� -1 = unknown */
    INT8        PTType;         /*!< PT���� 0--ĸ��PT 1--��·PT(����ϵͳ�д���ĸ��PT,����һ�㲻���뵽¼����) */
    INT8        AssNum;         /*!< ĸ��PT����Ӧ��ĸ�ߺ�(ĸ�ߺ���ͬ������PT����Ϊ��Ϊ���õĹ�ϵ) ��·PT����Ӧ����·�� */
    INT8        PhTyp;          /*!< ���߷�ʽ,4-ABCN,3-ABC,2-AC,1-��ͨ�� 0 δ�� */

    INT16       ChNum[4];        /*!< ��Ӧ��ͨ����,=0������ */
    INT16       ChHfNum[2];      /*!< ��Ƶͨ����Ӧ��ͨ����,=0������Hf */

    INT16       ExtrAnCnt;      /*!< �����·��ص�����ģ������ͨ���ĸ��� */
    INT16       AnNumArr[8];    /*!< �����·��ص�����ģ������ͨ���� */
    
    INT16       ExtrBinCnt;     /*!< �����·��ص�����״̬����ͨ���ĸ��� */
    INT16       BinNumArr[16];  /*!< �����·��ص�����״̬����ͨ���� */

	INT8        FileRcdEna;     /*!< ��ʶ�Ƿ����ɸ���·�ķ�ͨ���ļ� */
	INT8		PQEnable;		/*!< �Ƿ����õ����������ܣ�1=����;0=������ */
    
    INT8        LinIdx2KD;      /*!< 2KD��·�����ţ�Ϊ��2KD��ֵ����ת������ӣ� */
    INT8        Resv[21];        /*!< Ԥ�������ڽ������ܵ���չӦ��,�����ṹ���СΪ  160 �ֽ� */
} YH_ULIN_CFG;

#define		LINE_TYPE_NORMAL			0	/*!< ��ͨ������· */
#define		LINE_TYPE_PARA				1	/*!< ��ͨ˫����· */
#define		LINE_TYPE_BYPASS			2	/*!< ��· */
#define		LINE_TYPE_BUS_CONNECTION	3	/*!< ĸ�� */
#define		LINE_TYPE_BUS_RAILWAY		4	/*!< ���� */
#define		LINE_TYPE_OTHERS			5	/*!< ���� */

#define		PHASE_TYPE_ABCN				4	/*!< ABCN���� */
#define		PHASE_TYPE_ABC				3	/*!< ABC���� */
#define		PHASE_TYPE_AC				2	/*!< AC���� */
#define		PHASE_TYPE_SINGLE			1	/*!< ��ͨ������ */
#define		PHASE_TYPE_UNKNOWN			0	/*!< δ֪���� */

/*!
    \brief  ��·(������)���ò���    
 */
typedef struct  yh_ilin_cfg
{
    char        Name[64];       /*!< ��·���� */
    INT32       Index;          /*!< ��·˳�������ţ���1��ʼ������������*/
    
    INT8U       LinTyp;         /*!< ��ʶ����·���ͣ�0--�����ߣ�1--˫���ߣ�2--��·����·���صĵ�������3--ĸ����4--�����ߣ�5--����*/
    INT8U       PhTyp;          /*!< ���߷�ʽ,4-ABCN,3-ABC,2-AC,1-��ͨ��*/
    INT8U		Resv1[2];		/*!< Ԥ��1����֤�ֽڱ߽���� */
    
    INT16       ULinNum;        /*!< ��·��Ӧ�ĵ�ѹ������ */
    INT16       ParaNum;        /*!< ��Ӧ��˫����·��(����˫����·������) */
    
    INT16       ChNum[4];		/*!< ��Ӧ��ͨ����,=0������ */
    
    INT16       ChHfNum[2];    /*!< ��Ƶͨ����Ӧ��ͨ����,=0������Hf */
   
    INT16       ExtrAnCnt;      /*!< �����·��ص�����ģ������ͨ���ĸ��� */
    INT16       AnNumArr[8];    /*!< �����·��ص�����ģ������ͨ���� */
    
    INT16       ExtrBinCnt;     /*!< �����·��ص�����״̬����ͨ���ĸ��� */
    INT16       BinNumArr[36];  /*!< �����·��ص�����״̬����ͨ���� */

    INT8        CurDir;         /*!< �������� */
    INT8        FltLocEna;      /*!< ��ʶ�Ƿ����ù��ϲ�� */
    INT8        FileRcdEna;     /*!< ��ʶ�Ƿ����ɸ���·�ķ�ͨ���ļ� */
    INT8		PQEnable;		/*!< �Ƿ����õ����������ܣ�1=����;0=�����á�*/
    
    INT8        LinIdx2KD;      /*!< 2KD��·�����ţ�Ϊ��2KD��ֵ����ת������ӣ� */
    
    INT8        ULinNumBak;     /*!< ���õ�ѹ������ */
    
    INT8        Resv[2];        /*!< Ԥ�������ڽ������ܵ���չӦ��,�����ṹ���СΪ  180 �ֽ� */        
} YH_ILIN_CFG;


/*!
    \brief  �����������ֵ����
    
    ������������ϵͳ�������������صĶ�ֵ����;
    ����û�����ֵ���/��ѹ����̬/��̬��ֵ,���ж�ֵ������������У�
    ������������Ե�ѹ�����壬������������Ե���������,�ɾ���Ӧ����������
 */
typedef struct  yh_lin_set
{
    INT32       Index;			/*!< ˳�������ţ���1��ʼ������������ */
    FLOAT32     PSHiTrgLev;     /*!< �������޶�ֵ */
    FLOAT32     PSLoTrgLev;     /*!< �������޶�ֵ */
    FLOAT32     NSHiTrgLev;     /*!< �������޶�ֵ */
    FLOAT32     ZSHiTrgLev;     /*!< �������޶�ֵ */
    FLOAT32     ZSSaTrgLev;     /*!< ����ͻ�䶨ֵ */
    FLOAT32     SwgTrgLev;      /*!< �񵴶�ֵ */

    FLOAT32     PHiTrgLev;      /*!< �й��������޶�ֵ(��̬��������Ч) */
    FLOAT32     PRteTrgLev;     /*!< �й��仯�ʶ�ֵ(��̬��������Ч) */
    FLOAT32     QHiTrgLev;      /*!< �޹��������޶�ֵ(��̬��������Ч) */
    FLOAT32     QRteTrgLev;     /*!< �޹��仯�ʶ�ֵ(��̬��������Ч) */

    FLOAT32     ResvLev[5];     /*!< Ԥ�������ڽ������ܵ���չӦ�� */

    INT8        PSHiTrgEna;     /*!< ��������ʹ�� */
    INT8        PSLoTrgEna;     /*!< ��������ʹ�� */
    INT8        NSHiTrgEna;     /*!< ��������ʹ�� */
    INT8        ZSHiTrgEna;     /*!< ��������ʹ�� */
    INT8        ZSSaTrgEna;     /*!< ����ͻ��ʹ�� */
    
    INT8        SwgTrgEna;      /*!< ������ʹ�� */
    
    INT8        PHiTrgEna;      /*!< �й�����ʹ�� */
    INT8        PRteTrgEna;     /*!< �й��仯��ʹ�� */
    INT8        QHiTrgEna;      /*!< �޹�����ʹ�� */
    INT8        QRteTrgEna;     /*!< �޹��仯��ʹ�� */
    INT8        ResvEna[6];     /*!< Ԥ��(��֤�����ṹ���СΪ 80 bytes)�����ڽ������ܵ���չӦ�� */
} YH_LIN_SET;


/*!	\struct	SHPQLinSet
 	\brief	�������������������ֵ����
 	
 	
 	������������ϵͳ�������������صĵ���������ֵ����;
 	����û�����ֵ���/��ѹ�����ж�ֵ������������У�
 	������������Ե�ѹ�����壬������������Ե���������,�ɾ���Ӧ����������
 */
typedef struct  yh_PQ_lin_set
{
    INT32	Index;
    FLOAT32	FreqHiTrgLev;		/*!< Ƶ�����޶�ֵ(��ѹ��Ч) */
    FLOAT32	FreqLoTrgLev;		/*!< Ƶ�����޶�ֵ(��ѹ��Ч) */	
    FLOAT32	UBTrgLev;		/*!< ���಻ƽ��ȵ���ֵ */
    INT8	ResvEna[4];		/*!< Ԥ��(��֤�����ṹ���СΪ    bytes)�����ڽ������ܵ���չӦ�� */
} YH_PQ_LIN_SET;

/*!
    \brief  ���ϲ�ඨֵ
    
    ע���������еĵ���/�翹���絼/����ֵΪʵ��ֵ
    ����֮�䲻���ڵ�·�����ϻ�Ϊ�����Ĺ�ϵ
 */
typedef struct  yh_ilin_flo_set
{
    INT32       Index;		/*!< ˳�������ţ���1��ʼ������������ */
    FLOAT32     R0;         /*!< ��·������� */  
    FLOAT32     X0;         /*!< ��·����翹 */
    FLOAT32     R1;     	/*!< ��·������� */
    FLOAT32     X1;         /*!< ��·����翹 */
    FLOAT32     G0;			/*!< ����絼 */
    FLOAT32     B0;			/*!< ������� */
    FLOAT32     G1; 		/*!< ����絼 */
    FLOAT32     B1;         /*!< ������� */    
    FLOAT32     NR0;        /*!< �Զ�������� */
    FLOAT32     NX0;        /*!< �Զ�����翹 */
    FLOAT32     NR1;    	/*!< �Զ�������� */
    FLOAT32     NX1;        /*!< �Զ�����翹 */
    FLOAT32     MR; 		/*!< ˫����·���򻥸е��裬����˫����·������ */
	FLOAT32     MX; 		/*!< ˫����·���򻥸е翹������˫����·������ */
    FLOAT32     LinLenKm;   /*!< ��·���ȣ���λ��km */

    FLOAT32		Reactor;	/*!< �����翹�������翹 */  
    INT8        Resv[12];   /*!< Ԥ��(��֤�����ṹ���СΪ 80 bytes)�����ڽ������ܵ���չӦ�� */  
} YH_ILIN_FLO_SET;


/*!
    \brief  ��ѹ��������Ϣ
*/
typedef struct 
{
	INT8		Coiling;	/*!< ������߷�ʽ��  0 -- Y���ͽ��� 1 -- D�����ν��� */
	INT8		PhsHour;	/*!< �������ƫ��(0--12) */
	INT8		Ground;		/*!< ���Ե�ӵط�ʽ��0 -- ���ӵ�    1 -- ֱ�ӽӵ� 2 -- ��϶�ӵ� */
	INT8		Resv;		/*!< Ԥ�� */
} YH_TRN_COIL ;

/*!
    \brief  ��ѹ��������Ϣ
    
    ���ڱ�ѹ����֧��<br>
    ��SH2000D����ǰ��¼������Ʒ�о�δ�����ǹ���ѹ������"T"�ӵ�Ӧ�ó��ϣ�
    ʵ��Ӧ���У���ѹ���ǿ���"T"�ӵģ���ʱ�ò����Ӧ���Ǹ�����֧����֮�͡�
    (���ֽ��߷�ʽ�����������˽⣬������110KV�����϶�Ĳ���������"T"�ӵķ�ʽ)��
    �ڡ��㶫������˾¼��װ�ü����淶��5.1.3.4���У��漰���˷�֧��������ݡ�
    ��ѹ�������ṹ���ոò���������ơ�
 */
typedef struct  yh_trn_cfg
{
    char        Name[64];               /*!< ��ѹ������ */
    INT32       Index;                  /*!< ��ѹ��˳�������ţ���1��ʼ������������ */

	FLOAT32		Capacity;				/*!< ��ѹ������� */

    FLOAT32     HiPriRVol;              /*!< ��ѹ��һ�ζ��ѹ��KV��*/
    FLOAT32     MiPriRVol;              /*!< ��ѹ��һ�ζ��ѹ��KV��*/ 
    FLOAT32     LoPriRVol;              /*!< ��ѹ��һ�ζ��ѹ��KV��*/

    YH_TRN_COIL HiCoiling;              /*!< ��ѹ��������߷�ʽ */
    YH_TRN_COIL MiCoiling;              /*!< ��ѹ��������߷�ʽ */
    YH_TRN_COIL LoCoiling;              /*!< ��ѹ��������߷�ʽ */

	INT8        TrnTyp;         		/*!< ��ѹ�����ͣ�MAIN=���䣻PLANT=���ñ䣻EXCITATION=���ű� */
	INT8		WindingNum;				/*!< ������, 1=�����, 2=�����, 3=����� */

    INT8        HiBraCnt;               /*!< ��ѹ���֧��,ȡֵ��Χ1--MAX_TRN_BRA */
    INT8        MiBraCnt;               /*!< ��ѹ���֧��,ȡֵ��Χ0--MAX_TRN_BRA(ע������WindingNumΪ3ʱ����������) */
    INT8        LoBraCnt;               /*!< ��ѹ���֧��,ȡֵ��Χ1--MAX_TRN_BRA */
	INT8		Resv1[3];				/*!< Ԥ��1����֤�ֽڱ߽���� */
    
    INT16       HiBraNum[MAX_TRN_BRA];  /*!< ��ѹ���֧��·�� */
    INT16       MiBraNum[MAX_TRN_BRA];  /*!< ��ѹ���֧��·�� */
    INT16       LoBraNum[MAX_TRN_BRA];  /*!< ��ѹ���֧��·�� */

    INT16       HiVolNum;  				/*!< ��ѹ���ѹ˳��� */
    INT16       MiVolNum;  				/*!< ��ѹ���ѹ˳��� */
    INT16       LoVolNum;  				/*!< ��ѹ���ѹ˳��� */

	INT16		HiZsChNum;				/*!< ��ѹ���������ͨ���� */
	INT16		MiZsChNum;				/*!< ��ѹ���������ͨ���� */
	INT16		LoZsChNum;				/*!< ��ѹ���������ͨ���� */

	INT16		HiCleChNum;				/*!< ��ѹ���϶�������ͨ���� */
    INT16		MiCleChNum;				/*!< ��ѹ���϶�������ͨ���� */
    INT16		LoCleChNum;				/*!< ��ѹ���϶�������ͨ���� */

	INT16		ExtrAnCnt;				/*!< ��������ص�����ģ������ͨ���ĸ��� */
	INT16		AnNumArr[8];			/*!< ��������ص�����ģ������ͨ���� */

    INT16       BinChCnt;               /*!< ��������ؿ������ĸ��� */
    INT16       BinNumArr[16];          /*!< ��������ؿ�������ͨ����,�������16�� */

    INT16       ScouComwinding;         /*!< ����乫���������Ե���·�� */
    
    INT8        Resv[46];               /*!< Ԥ������֤�����ṹ���СΪ 240 �ֽ� */
} YH_TRN_CFG;

/*!
    \brief  ��ѹ����ֵ����
 */
typedef struct  yh_trn_set
{
    INT32       Index;				/*!< ��ѹ��˳�������ţ���1��ʼ������������ */
    FLOAT32     OvExTrgLev;     	/*!< �����Ŷ�ֵ(����ӿ������ڶ�����ı���) */
    FLOAT32     ThrITrgLev;     	/*!< ��Խ������ֵ(��Խ��������ڶ�����ı�����������̬����������) */
    FLOAT32     DifATrgLev;     	/*!< ������ֵ */
    FLOAT32     ResvLev[4];     	/*!< Ԥ�� */
    
    INT8        OvExTrgEna;     	/*!< ����������ʹ�� */
    INT8        ThrITrgEna;     	/*!< ��Խ��������ʹ��(������̬����������) */
    INT8        DifATrgEna;     	/*!< ��������ʹ�� */
    INT8        ResvEna[5];     	/*!< Ԥ���������ṹ��ռ��  40 �ֽڿռ� */
} YH_TRN_SET;

/************************************2011.3.10�޸�***************************************/
/*
	\brief  �����������Ϣ
	\date   2011.3.10
*/
typedef struct
{
	INT16		DifChNumG;			/*!< ���˲����ͨ���ţ�0Ϊ������ */
	INT16		DifChNumN1;			/*!< ���Ե�����ͨ����1��0Ϊ������ */	
	INT16		DifChNumN2;			/*!< ���Ե�����ͨ����2��0Ϊ������ */
	INT16		inDifChNum;			/*!< ����ȫ�ݲ����ͣ� 0������ȫ�ݲ���ڣ� 1�����Ե���Ӧͨ��1�� 2�����Ե���Ӧͨ��2 */
	FLOAT32		DifKtr;				/*!< ������ϵ�� */
	FLOAT32		DifKin;				/*!< ����ȫ�ݲ����ϵ�� */
}YH_GN_DIF;


/*!
    \brief  �����������Ϣ
 */
typedef struct
{
	char        Name[64];           /*!< ��������� */
	INT32       Index;              /*!< �����˳�������ţ���1��ʼ������������ */

	INT16       VolNum;             /*!< ��������˵�ѹ˳��� */
	INT16		CurNum;				/*!< ��������˵���˳��� */
	INT16		NAIChNum;			/*!< ��������Ե����ͨ���� */
	INT16		NAUChNum;			/*!< ��������Ե��ѹͨ���� */
	INT16       UePosChNum;         /*!< ��������ŵ�ѹUe+ͨ���� */
	INT16       UeNegChNum;         /*!< ��������ŵ�ѹUe-ͨ���� */
	INT16       ExitIChNum;         /*!< ��������ŵ���ͨ���� */
	INT16		ZeroSeqVNum;		/*!< ��������������ѹͨ���� */
	
	YH_GN_DIF	DifCfg[3];			/*!< �����������Ϣ���ֱ�ΪA�������Ϣ��B�������Ϣ�� C�������Ϣ */
	
	INT8        GnIDir;             /*!< ��������˵������򣬴ӷ������������Ϊ1������-1*/
	INT8        NIDir;              /*!< ��������Ե��������򣬴����Ե������Ϊ1������Ϊ-1*/

	INT8		Resv[32];			/*!< Ԥ���� �����ṹ��ռ��160�ֽڿռ� */
}YH_GN_CFG;


/*!
    \brief  �������ֵ��Ϣ
 */
typedef struct  yh_gn_set
{
	 INT32      Index;				/*!< �����˳�������ţ���1��ʼ������������ */
	
	 FLOAT32	DifTrgLev;			/*!< �ݲֵ���ֱ��ӦA����ȫ�ݲֵ��B����ȫ�ݲֵ��C����ȫ�ݲֵ*/
	 FLOAT32	DifInTrgLev;		/*!< ����ȫ�ݲֵ���ֱ��ӦA�಻��ȫ�ݲֵ��B�಻��ȫ�ݲֵ��C�಻��ȫ�ݲֵ*/
	 FLOAT32	DifTranTrgLev;		/*!< ��ֵ���ֱ��ӦA���ֵ��B���ֵ��C���ֵ*/
	 FLOAT32	OvExTrgLev;     	/*!< �����Ŷ�ֵ */
	 FLOAT32	LossExcTrgLev;		/*!< ʧ��������ֵ */
	 FLOAT32	StatorZeroTrgLev;	/*!< ���ӽӵ�֮�����ѹ��ֵ */
	 FLOAT32	StatorHar3TrgLev;	/*!< ���ӽӵ�֮����г����ѹ�ȶ�ֵ */
	 FLOAT32	ZeroSeqTrgLev;		/*!< ���������ѹʽ���������Ѽ��·��ֵ*/

	 FLOAT32	RotorHar2TrgLev;	/*!< ת�Ӷ���г����ֵ*/
	 FLOAT32	ReversePoTrgLev;	/*!< �湦�ʶ�ֵ*/
	 FLOAT32	LowFreOvCurTrgLev;	/*!< ��Ƶ������ֵ */

	 FLOAT32	ResvLev[4];			/*!< Ԥ�� */

	 INT8		DifTrgEna;			/*!< ��ȫ�ݲ�����ʹ�� */
	 INT8		DifInTrgEna;		/*!< ����ȫ�ݲ�����ʹ�� */
	 INT8		DifTranTrgEna;		/*!< �������ʹ�� */
	 INT8		OvExTrgEna;			/*!< ����������ʹ�� */
	 INT8		LossExcTrgEna;		/*!< ʧ������ʹ�� */
	 INT8		StatorEarthTrgEna;	/*!< �������鵥��ӵ�����ʹ�� */
	 INT8		ZeroSeqTrgEna;		/*!< ���������ѹʽ���������Ѽ��·����ʹ�� */
	 INT8		RotorHar2TrgEna;	/*!< ת�Ӷ���г������ʹ�� */

	 INT8		ReversePoTrgEna;	/*!< �湦��ʹ�� */
	 INT8		LowFreOvCurTrgEna;	/*!< ��Ƶ����ʹ�� */

	 INT8		ResvEna[6];			/*!< Ԥ���������ṹ��ռ��80�ֽ� */
}YH_GN_SET;


/*! \struct SHDFRParm
    \brief  DFRȫ���Բ���
 */
typedef struct  yh_dfr_parm
{
     YH_DFR_CFG         DfrCfg;         /*!< ¼����ȫ����������Ϣ */
     YH_TRNS_RCD_SET    DfrTrnsSet;     /*!< ��̬RDRE��ֵ */
     YH_HZ_SET          HzTrnsSet;      /*!< ��̬Ƶ�ʶ�ֵ */
     YH_CONT_RCD_SET    DfrContSet;     /*!< ��̬RDRE��ֵ */
     YH_HZ_SET          HzContSet;      /*!< ��̬Ƶ�ʶ�ֵ */
} YH_DFR_PARM;


/*!
    \brief  ģ����ͨ������
 */
typedef struct  yh_anch_parm
{
     YH_ANCH_CFG        AnCfg;      /*!< ģ��ͨ���������ò���(������Ϣ) */
     YH_ANCH_SET        AnTrnsSet;  /*!< ��̬��ֵ */
     YH_ANCH_SET        AnContSet;  /*!< ��̬��ֵ */
     YH_PQ_ANCH_SET 	AnPQSet;	/*!< ����������ֵ */
} YH_ANCH_PARM;

/*!
    \brief  ������ͨ������
 */
typedef struct  yh_binch_parm
{
     YH_BINCH_CFG       BinCfg;     /*!< ������ͨ���������ò���(������Ϣ)   */
     YH_BINCH_SET       BinTrnsSet; /*!< ��̬��ֵ */
     YH_BINCH_SET       BinContSet; /*!< ��̬��ֵ */
} YH_BINCH_PARM;

/*!
    \brief  ��ѹ������
 */
typedef struct  yh_ulin_parm
{
     YH_ULIN_CFG        LinCfg;         /*!< ��ѹ�������ò���(������Ϣ) */
     YH_LIN_SET         LinTrnsSet;     /*!< ��·��̬������ֵ */
     YH_LIN_SET         LinContSet;     /*!< ��·��̬����¼���ֵ */
     YH_PQ_LIN_SET  	LinPQSet;		/*!< ����������ֵ */
} YH_ULIN_PARM;

/*!
    \brief  ��·����
 */
typedef struct  yh_ilin_parm
{
     YH_ILIN_CFG        LinCfg;         /*!< ��·�������ò���(������Ϣ�����а����˷�ͨ���ļ���Ϣ) */
     YH_ILIN_FLO_SET    FloSet;         /*!< ��ඨֵ���� */
     YH_LIN_SET         LinTrnsSet;     /*!< ��·��̬������ֵ */
     YH_LIN_SET         LinContSet;     /*!< ��·��̬����¼���ֵ */
     YH_PQ_LIN_SET  	LinPQSet;		/*!< ����������ֵ */
} YH_ILIN_PARM;

/*!
    \brief  ��ѹ������
 */
typedef struct  yh_trn_parm
{
     YH_TRN_CFG     TrnCfg;         /*!< ��ѹ���������ò���(������Ϣ) */
     YH_TRN_SET     TrnTrnsSet;     /*!< ��ѹ����̬������ֵ */
     YH_TRN_SET     TrnContSet;     /*!< ��ѹ����̬����¼���ֵ */
} YH_TRN_PARM;


/*!
    \brief  ���������
 */
typedef struct yh_gn_parm 
{
    YH_GN_CFG       GnCfg;              /*!< ������������ò���(������Ϣ) */
    YH_GN_SET       GnTrnsSet;          /*!< �������̬������ֵ */
    YH_GN_SET       GnContSet;          /*!< �������̬������ֵ */
}YH_GN_PARM;


typedef struct
{
	INT8U				dstMac[6];		/*!< Ŀ��Mac��ַ */
	INT8U				srcMac[6];		/*!< ԴMac��ַ */
	INT16U				AppID;			/*!< AppID */
	INT8U               Resv[2];        /*!< Ԥ�� */
}SG_LPDU_CFG;

/*!
    \brief  ��ֵ�ṹ��Ϣ
 */
typedef struct yh_sg_info
{
    YH_DFR_PARM*        pDFRParm;       /*!< ȫ�ֲ��� */
    YH_ANCH_PARM*       pAnChParm;      /*!< ģ����ͨ����Ϣ */
    YH_BINCH_PARM*      pBinChParm;     /*!< ״̬��ͨ����Ϣ */
    YH_ULIN_PARM*       pULinParm;      /*!< ��ѹ����Ϣ */
    YH_ILIN_PARM*       pILinParm;      /*!< ��·��Ϣ */
    YH_TRN_PARM*        pTrnParm;       /*!< ��ѹ����Ϣ */
    YH_GN_PARM*         pGnParm;        /*!< �������Ϣ */
    
    INT32U*             DataAddr;       /*!< ��������ʼ��ַ */
    INT32U              BufLen;         /*!< ���������� */
} SHDFR_SG;


#pragma pack () /* �ָ��ֽڶ����趨*/
#ifdef __cplusplus
}
#endif

#endif  /*__YH_DFR_PARM_DEFINE_H*/

