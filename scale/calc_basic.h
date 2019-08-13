/*************************************************************************
* Copyright (c) 2010,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		ʵ��һЩ������Ļ������㷨���ߺ���
 	
	\author		Chen
	\version	1.0
	\date		2010-09-20
	
*/

#ifndef	__SH_CALC_BASIC_UTILITY_DEFINE_H
#define	__SH_CALC_BASIC_UTILITY_DEFINE_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
	\brief	��ʼ��DFT�����������������ϵ����
	\param	pcoeff	[in]	ϵ������ʼ��ַ
	\param	k		[in]	г������
	\param	N		[in]	ÿ�ܲ���������
	\param  skew    [in]    �Ƕ�ƫ��
*/
void init_coefficient_table( float* pcoeff, int k, int N, float skew );

/*!
	\brief	����DFT�����������������ϵ����
	\param	k		[in]	г������
	\param	N		[in]	ÿ�ܲ���������
	\param  skew    [in]    �Ƕ�ƫ��	
*/
float* creat_coefficient_table( int k, int N, float skew );


/*!
	\brief	DFT���㣬����ʵ�� �鲿����Чֵ, г����Чֵ
	\param	pfsrc		[in]	ԭʼ����������ʼ��ַ
	\param	fcnt		[in]	ԭʼ������ĸ���
	\param	pcoeff		[in]	������ϵ�����׵�ַ
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void calc_DFT( float* pfsrc, int fcnt, float* pcoeff, COMPLEX_R* pComplex );


/*!
	\brief	ֱ������
	\param	pfdata		[in]	ԭʼ����������ʼ��ַ
	\param	fcnt		[in]	ԭʼ������ĸ���
	\param	pComplex	[out]	ָ��������ṹ��ָ��
*/
void calc_DC( float* pfdata, int fcnt, COMPLEX_R* pComplex );


/*!
	\brief	Ƶ�ʼ���
	\param	pCur	[in]	��ǰ�ܲ�ʵ�鲿
	\param	pPrev	[in]	ǰһ�ܲ�ʵ�鲿
	\return ���ؼ�����
*/
float calc_freq( COMPLEX* pCur, COMPLEX* pPrev );


#ifdef __cplusplus
}
#endif


#endif	/* __SH_CALC_BASIC_UTILITY_DEFINE_H */
