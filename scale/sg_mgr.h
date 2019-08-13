/*************************************************************************
* Copyright (c) 2008,������Ԫ������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file		
 	\brief		��ֵ�ļ���/д�ӿ�
	\author		Chentm
	\version	2.0
	\date		2011-05-04
*/

#ifndef DFR_SG_MGR_INCLUDED_
#define DFR_SG_MGR_INCLUDED_

#include <stdio.h>
#include "sg_def.h"

/*!< ��ֵ�ļ��汾�� */
#define	SG_FILE_VERSION		0x0100

/*!
 	\brief	¼������ֵ���ļ�ͷ�ṹ
 */
struct DfrSGFileHead
{
	char			ShFlg[4];		/*!< �Զ����ļ���ʽ��־,�̶�Ϊ"yhf" */
	char			ShExt[4];		/*!< �ļ���չ���̶�Ϊ"sg" */
	INT8			FileType;		/*!< �ļ����� */
	INT8			Endian;			/*!< �ļ��ֽ�˳�� */
	INT8			Resv1[2];		/*!< Ԥ������֤4�ֽڶ��� */
	INT32			FileVer;		/*!< �ļ��汾 */
	INT32			FileLen;		/*!< �ļ�����,=0ʱ��ʾ����δ֪ */
	INT32			LenOfSG;		/*!< ��ֵ���ݵĳ��� */
	unsigned char	Resv[16];		/*!< Ԥ��18�ֽ�,��֤�ļ�ͷ�ܵĴ�СΪ40�ֽ� */
};

/*!
 	\brief	��ֵ������
	
	���豸���й����У�����ֵ/������Ϣ����ʱ��
	���������е�ģ�����Ҫ���½������û��ʼ����
	��ֵ����������Эͬ����ģ�鶯̬�ĸ���������Ϣ��
 */
class SGManager
{
public:

/*!
	\brief	���캯��
*/
	SGManager();
	
/*!
	\brief	��������
*/
	~SGManager();

/*!
	\brief	��ʼ����ֵ�ṹ��Ϣ
	\param	dfr_sg		[in,out]	��ֵ���ļ�
	\return	�ɹ�����0,���򷵻ش����
*/
	int initDfrSgData( SHDFR_SG* pSg );

/*!
	\brief	��ȡDFR��ֵ����
	\param	sg_fname	[in]	��ֵ���ļ�
	\param	dfr_sg		[out]	��Ŷ�ֵ�����ݵĽṹ
	\return	�ɹ�����0,���򷵻ش����	
*/
	int readDfrSGData( const char* sg_fname, SHDFR_SG* dfr_sg, DfrSGFileHead* sg_file_head );

/*!
	\brief	��ȡDFR FileHead
	\param	sg_fname	[in]	��ֵ���ļ�
	\param	psg_file_head	[out]	��Ŷ�ֵ�ļ�ͷ
	\return	�ɹ�����0,���򷵻ش����	
*/
	int readSGFileHead( const char* sg_fname, DfrSGFileHead* psg_file_head );

/*!
	\brief	д��ֵ�ļ�
	\param	sg_fname	[in]	��ֵ���ļ�
	\param	dfr_sg		[out]	��Ŷ�ֵ�����ݵĽṹ
	\return	�ɹ�����0,���򷵻ش����
	\sa		readDfrSGData()
	
	����ö�ֵ�ļ����ڣ����д��ֵ�ļ������ݣ�
	����ö�ֵ�ļ������ڣ��򴴽��ö�ֵ�ļ���
*/	
	int writeDfrSGData( const char* sg_fname, const SHDFR_SG* dfr_sg );

/*!
	\brief	д��ֵͷ
	\param	sg_fname	    [in]	��ֵ���ļ�
	\param	sg_file_head	[out]	��Ŷ�ֵͷ���ݵĽṹ
	\return	�ɹ�����0,���򷵻ش����
	
	����ö�ֵ�ļ����ڣ����д��ֵ�ļ������ݣ�
	����ö�ֵ�ļ������ڣ��򴴽��ö�ֵ�ļ���
*/	
	int writeSGFileHead ( const char* sg_fname, const DfrSGFileHead* sg_file_head );

/*!
	\brief	����һ����ֵ�ļ�
	\param	sg_fname	[in]	��ֵ���ļ�
	\param	dfr_sg		[out]	��Ŷ�ֵ�����ݵĽṹ
	\return	�ɹ�����0,���򷵻ش����
	\sa		writeDfrSGData()
	
	����ö�ֵ�ļ����ڣ���Ḳ�Ǹ��ļ���
	����ö�ֵ�ļ������ڣ��򴴽��ö�ֵ�ļ���
*/	
	int createDfrSGFile( const char* sg_fname, const SHDFR_SG* dfr_sg );

/*!
	\brief	 ������ֵ��������
	\param	 nUnum	[in]		��ѹ��·
	\param	 nInum	[in,out]	������·
	\return	 �ɹ�����0,���򷵻ش����
	ע�⣺����������ΪĿ�Ķ�ֵ���ݷ�����ͬԴ��ֵ����ͬ����С���ڴ�ռ䣬��Ҫ�ɵ������Լ�ȥ�ͷš�
*/	
	SHDFR_SG* dfr_sg_pt_cpy(SHDFR_SG* sg_dst, int nUnum, int nInum, const SHDFR_SG* sg_src);

/*!
	\brief	������ֵ����
	\param	anChCnt		[in]	ģ����ͨ����
	\param	binChCnt	[in]	������ͨ����
	\param	ilinCnt		[in]	��������
	\param	ulinCnt		[in]	��ѹ����
	\param	trnCnt		[in]	��ѹ����
	\param	gnCnt		[in]	�������
	\return	���ش����Ķ�ֵ���ݵ�ָ�룬���ʧ���򷵻�NULL
	
	������ֻ��Ϊ��ֵ���ݷ����˺��ʵĿռ䣬���ж�ֵ����ֵ��δ��ʼ����
*/	
	SHDFR_SG* createDfrSGData( int anChCnt, int binChCnt, 
						   int ilinCnt, int ulinCnt, 
						   int trnCnt,  int gnCnt );

/*!
	\brief	������ֵ����(�Ӷ�ֵ�ļ��ж�ȡ)
	\param	sg_fname	[in]	��ֵ���ļ�
	\param	sg_fname	[out]	��� m_psg
	\return	���ʧ���򷵻�false
	\sa		createDfrSGData(),destroyDfrSGData()
*/	
	bool createDfrSGFromFile( const char* sg_fname );

/*!
	\brief	��¡һ�ݶ�ֵ����
	\param	sg_src		[in]	��ֵ����Դ
	\return	���ش����Ķ�ֵ���ݵ�ָ�룬���ʧ���򷵻�NULL
	\sa		createDfrSGData(),destroyDfrSGData()
*/
	SHDFR_SG* cloneDfrSGData( const SHDFR_SG* sg_src );

/*!
	\brief	�ͷŶ�ֵ�����ڴ�ռ�
	\param	dfr_sg		[in]	��ֵ����
	\sa		createDfrSGData(),createDfrSGFromFile()
	
	�����������ͷ�ͨ��createDfrSGData(),createDfrSGFromFile(),cloneDfrSGData()���ɵĶ�ֵ�����ڴ�ռ䡣
*/	
	void destroyDfrSGData( SHDFR_SG* &dfr_sg );

/*!
	\brief	���㶨ֵ����У���
*/
	INT32U calc_sg_chksum( SHDFR_SG* psg );

/*!
	\brief	����Ĭ�϶�ֵ
*/	
	SHDFR_SG* createDefaultDfrSG();

	SHDFR_SG * m_psg; /*!< ��ֵ���� */ 
};

/*!
	\brief	��ʼ����ֵ�ṹ��Ϣ
	\param	dfr_sg		[in,out]	��ֵ���ļ�
	\param	sg_data		[in]		��ֵ������
	\param	sg_size		[in]		��ֵ����������
	\param	chkSum		[in]		�Ƿ����¼���У���
	\return	�ɹ�����0,���򷵻ش����
*/
	int initDfrSg( SHDFR_SG* dfr_sg, void* sg_data, int sg_size, int chkSum );

/*!
	\brief	�Ƚ�������ֵ�ṹ������Ϣ�Ƿ���ͬ
	\param	pdfr_sg1	[in]	��ֵ�ṹ1
	\param	pdfr_sg2	[in]	��ֵ�ṹ2
	\return	��ͬ����0,�����0ֵ
	
	ֻ�е�ͨ��������·���������л���������Ϣ��ȫ��ͬʱ�����ж�Ϊ��ͬ��
*/	
	int sg_comp_dfrcfg( const SHDFR_SG* pdfr_sg1, const SHDFR_SG* pdfr_sg2 );

/*!
	\brief	������ֵ����
	\param	sg_src	[in]		��ֵ����Դ
	\param	sg_dst	[in,out]	Ŀ�Ķ�ֵ����
	\param  flg		[in]		��ֵ���ò�ƥ��ʱ�Ĵ���ʽ
	\return	�ɹ�����0,���򷵻ش����
	
	��flgΪ0ʱ,����ֵ��ƥ�䣬�򷵻ش���;
	��flg��0ʱ,����ֵ��ƥ�䣬���Ϊsg_dst���·������ڴ�ռ�;
	ע�⣺����������ΪĿ�Ķ�ֵ���ݷ�����ͬԴ��ֵ����ͬ����С���ڴ�ռ䣬��Ҫ�ɵ������Լ�ȥ�ͷš�
*/	
	int dfr_sg_cpy( SHDFR_SG* sg_dst, const SHDFR_SG* sg_src, int flg );

/*!
	\brief	�õ�ģ����ͨ������λ
	\param	psg			��ֵ����
	\param	nChannelID	ͨ����
*/	
	const char* getAnChPhase( const SHDFR_SG* psg, int nChannelID);

/*!
	\brief	�õ���λ�ַ���
	\param	nMultiplier	����
	\param	nUnitType	��λ
	
	��ֵ�ṹ�У���λ�ı�ʾ�Ǹ���IEC 61850�е�λ��ʾ��ʽһ�µġ�
	������ʵ�ֽ���ת��Ϊ����ĵ�λ�ַ�����
*/
	const char* getUnitStr(int nMultiplier, int nUnitType, char* buf );

/*!
	\brief	�Ƚ�������ֵ��������ֵ
	\param	pdfr_sg1	[in]	��ֵ�ṹ1
	\param	pdfr_sg2	[in]	��ֵ�ṹ2
	\return	��ͬ����0,����-1ֵ
	
	ֻ�е�ͨ��������·����������ֵ��ȫ��ͬʱ�����ж�Ϊ��ͬ��
*/	
	int sg_comp_dfr_val( const SHDFR_SG* pdfr_sg1, const SHDFR_SG* pdfr_sg2 );

#endif	/* DFR_SG_MGR_INCLUDED */

