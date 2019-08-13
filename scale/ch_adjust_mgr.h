
#if !defined(AFX_CH_AJUST_MGR_H_)
#define AFX_CH_AJUST_MGR_H_

#if _MSC_VER > 1000
#pragma once
#endif

//#include "sg_def.h"
#include "rt_ctl.h"

//���ģ������
#define AN_CH_MAX_VIRTUAL 16

//��󿪹�����
#define DN_CH_MAX 16

class ChAdjustMgr  
{
public:
    bool	m_bDataValid;				/*!< �����Ƿ���Ч */
	int		m_nAnChCnt;					/*!< ģ����ͨ���� */
	int		m_nPtCount;					/*!< ÿ��ͨ�����ݳ��� */
	int		m_nPerCycPoint;				/*!< ÿ�ܲ��������� */
	float	m_rateFreq;					/*!< �����Ƶ��(50\60 Hz) */
	char	m_AnChName[AN_CH_MAX_VIRTUAL][64];	/*!< ģ����ͨ������ */
	short	*m_pChData[AN_CH_MAX_VIRTUAL];		/*!< ģ�������� */


	//ͨ�����ͺ͵�λ
	char	m_ChTyp[AN_CH_MAX_VIRTUAL];			    /*!< ģ����ͨ�������ͣ�0=UnKnown 1=������ѹ(TV)��2=��������(TA)��3=ֱ����ѹ(DV)��4=ֱ������(DA); 5=��Ƶ(HF); 6=Ƶ��(FQ) */
	float	m_BackupOffset0[AN_CH_MAX_VIRTUAL];     /*!< ����ԭʼ��Ư��û�г˱���ϵ�� */
	float	m_BackupOffset[AN_CH_MAX_VIRTUAL];     	/*!< ������Ư */
    float	m_BackupScaler[AN_CH_MAX_VIRTUAL];     	/*!< ���ݱ���ϵ�� */
    float	m_BackupSkew[AN_CH_MAX_VIRTUAL];       	/*!< ����ͨ���ǲ� */

	float	m_Offset0[AN_CH_MAX_VIRTUAL];     	/*!< ԭʼ��Ư��û�г˱���ϵ�� */
	float	m_Offset[AN_CH_MAX_VIRTUAL];     	/*!< ��Ư */
    float	m_Scaler[AN_CH_MAX_VIRTUAL];     	/*!< ����ϵ�� */
    float	m_Skew[AN_CH_MAX_VIRTUAL];       	/*!< ͨ���ǲ� */

	float	m_ChInputVal[AN_CH_MAX_VIRTUAL];	/*!< ����ֵ */    
    float	m_ChOutputVal[AN_CH_MAX_VIRTUAL];	/*!< ���ֵ */

	char	m_ChSelected[AN_CH_MAX_VIRTUAL];	/*!< ���Ҫ���ڵ�ͨ�� */	

	bool m_bDataChanged;				/*!< �����Ƿ��Ѿ����� */

	char ErrStr[64];					/*!< ������Ϣ */

	bool GetRealtimeData(RT_CTL* rtCtl);	//ȡ�ɼ�����

	bool GetSG();							//��ʼ��ʱ��ȡ��ֵ����

    void Init( );

/*! 
	 *  \fn			void CalcOffset()
	 *  \brief		������Ư
	 *  \param[in]	pChData:ԭʼ��������
	 *  \param[in]	pScaler:����ϵ��
	 *  \param[in]	pChSelected:Ҫ���ڵ�ͨ��=1
	 *  \param[in]	nAnChCnt:ͨ����
	 *  \param[in]	nPtCount:ÿͨ���������ݵ���
	 *  \param[in]	nPerCycPoint:ÿ�ܲ��������ݵ���
	 *  \param[out]	pOffset:��Ư
	 *  \param[out]	pOffset0:ԭʼ��Ư
	 *  \param[out]	pOutputVal:���ֵ������������ʾ��Ư��Чֵ
	 *  \return		none
	 *  \note		none
*/
	void CalcOffset(short **pChData, float *pScaler, char *pChSelected, int nAnChCnt, int nPtCount, int nPerCycPoint, float *pOffset, float *pOffset0, float *pOutputVal);

/*! 
	 *  \fn			void CalcOffset()
	 *  \brief		�������ϵ��
	 *  \param[in]	pChData:ԭʼ��������
	 *  \param[in]	pInputVal:ʵ������ֵ
	 *  \param[in]	pChSelected:Ҫ���ڵ�ͨ��=1
	 *  \param[in]	pOffset0:ԭʼ��Ư
	 *  \param[in]	nAnChCnt:ͨ����
	 *  \param[in]	nPtCount:ÿͨ���������ݵ���
	 *  \param[in]	nPerCycPoint:ÿ�ܲ��������ݵ���
	 *  \param[out]	pScaler:����ϵ��
	 *  \param[out]	pOffset:��Ư
	 *  \param[out]	pOutputVal:���ֵ������������ʾ��Ư��Чֵ
	 *  \return		none
	 *  \note		A/D < 80 ������
*/
	void CalcScaler(short **pChData, float *pInputVal, char *pChSelected, float *pOffset0, int nAnChCnt, int nPtCount, int nPerCycPoint, float *pScaler,float *pOffset, float *pOutputVal);		// �������ϵ��

/*! 
	 *  \fn			void CalcSkew()
	 *  \brief		�������ͬ����(�ǲ�)
	 *  \param[in]	pChData:ԭʼ��������
	 *  \param[in]	pChSelected:Ҫ���ڵ�ͨ��=1
	 *  \param[in]	nAnChCnt:ͨ����
	 *  \param[in]	nPtCount:ÿͨ���������ݵ���
	 *  \param[in]	nPerCycPoint:ÿ�ܲ��������ݵ���
	 *  \param[out]	pSkew:����ͬ����
	 *  \param[out]	pOutputVal:���ֵ������������ʾͨ���ǲ�
	 *  \return		none
	 *  \note		Ҫ����ͬһ��λ��������
*/
    //void CalcSkew(short **pChData, char *pChSelected, int nAnChCnt, int nPtCount, int nPerCycPoint, float *pSkew, float *pOutputVal);

	ChAdjustMgr();
	~ChAdjustMgr();

private:
	char *m_pDataBuff;				/*!< �������ݻ����� */
};

#endif 
