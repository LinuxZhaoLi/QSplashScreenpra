/*************************************************************************
* Copyright (c) 2008,������YHF�����������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief	ʵ����OS�޹ص�ϵͳʱ�亯��
	\author	chen
	\version	1.0
	\date	2008-04-23
	
	�ڽ��п�ƽ̨��ϵͳ���ʱ��������ʱ��ṹ��ʱ�亯����һ�µ������
	���ļ�����Բ�ͬ�Ĳ���ϵͳƽ̨��ʵ����ͬ��ʱ��ṹ��ʱ�亯������ʵ�ֿ�ƽ̨�ĸ߾���ʱ��Ŀ�ġ�
	ʵ�ַ�����
	1.�ڷ�Windowsƽ̨�£�������SYSTEMTIMEʱ��ṹ���ýṹ��Windows����ϵͳ�µ�SYSTEMTIME�ṹ��ȫһ�£�
	2.�ڷ�Windowsƽ̨�£�����ΪSetLocalTime��GetLocalTime������
	3.��Windows/VxWorksƽ̨�£�������gettimeofday��settimeofday��������ӿ���Linuxϵͳ�µ�gettimeofday/settimeofday��ȫһ��;
	4.������timeval�ṹ��SYSTEMTIME�ṹ֮������໥ת���ĺ�����
*/

#ifndef	__XTIME_H__
#define	__XTIME_H__

#include "yhftypes.h"

#if defined(WIN32)
#include <time.h>
//#include <winsock2.h>
#include <windows.h>
#endif


#if defined(linux)
#include <time.h>
#include <sys/time.h>
#endif

#if !defined( ACSI_DLL )
#define ACSI_DLL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(WIN32)
/*!
*	\brief ����ʱ����Ϣ�Ľṹ����
*/
//struct timezone
//{
//    int  tz_minuteswest; /*!< minutes W of Greenwich */
//    int  tz_dsttime;     /*!< type of dst correction */
//};
#endif


#if defined(WIN32)
//ACSI_DLL struct tm* gmtime_r (const time_t *timer, struct tm *tp);
ACSI_DLL void  FILETIME_2_timeval ( FILETIME*  pft, struct timeval* ptv );
ACSI_DLL int   gettimeofday(struct timeval *tv, struct timezone *tz);
ACSI_DLL int   settimeofday(const struct timeval *tv, const struct timezone *tz);
#elif defined(VXWORKS)
ACSI_DLL int   gettimeofday(struct timeval *tv, struct timezone *tz);
ACSI_DLL int   settimeofday(const struct timeval *tv, const struct timezone *tz);
#endif	//VXWORKS

/*!
* 	\brief �������ڵ�ʱ��
*/
#ifndef __TIMEZONE__
	#define	__TIMEZONE__			8
#endif

/*!
*	\brief ����time_t�������ͱ�ʾ�����ڵ���ʼ���� 1970/01/01 00:00:00
*
*	�Զ������1970/01/01 00:00:00������time_tʱ��ת������Ҫ�ĺ�
*	��� \ref systemtime_2_timeval ��\ref ndatetime_2_timeval
 */
#define	TIMET_START_YEAR		1970

/*!
* 	\brief �������������ܹ�������
 */
#define	DAYS_IN_YEAR			365


/*!
*	\brief һ�������		= 24 * 3600
*/
#define	SECONDS_IN_DAY			86400

/*!
*	\brief һСʱ������	= 60 * 60
*/
#define	SECONDS_IN_HOUR			3600

/*!
*	\brief һ���ӵ�����	= 60
*/
#define	SECONDS_IN_MINUTE		60

/*!	
*	\brief һСʱ�ڵķ����� 
*/
#define	MINUTES_IN_HOUR			60

/*!	
*	\brief һ���е�����
*/
#define DAYS_IN_WEEK	        7

/*!	
*	\brief һ���е�����
*/
#define MONTHS_IN_YEAR			12

/*!	
*	\brief һ���¿��ܵ��������
*/
#define MAX_DAYS_IN_MONTH       31

/*!	
*	\brief һ����ܵ��������
*/
#define MAX_DAYS_IN_YEAR		366


/*!
* 	\brief �ж�ĳ���Ƿ�Ϊ����ı��ʽ�궨��
*
*	\param year	--[in]	�μ������жϵ����
 */
#define	EXP_IS_LEAP_YEAR(year)		\
		(((0 == (year) % 400) || (0 == (year) % 4 && 0 != (year) % 100))  \
			? 1 : 0) \


/*!
*	\brief �ӹ�ԪԪ�굽����Ŀ�ʼһ�������˶��ٸ�����
*
*	\param year	--[in]	�����е���ʼ��ݣ�Ҫ�� \c year ����400��������㽫��׼ȷ��
 */
#define	EXP_HOW_MANY_LEAP_YEAR(year)		\
			(  ((year) - 1) / 4				\
			-  ((year) - 1) / 100			\
			+  ((year) - 1) / 400 + 1 )		\


/*!
*	\brief ��ָ�������֮�䷢���˶��ٸ�����
*
*	\param start	--[in]	��ʼ��ݣ�Ҫ�� \c start ����400��
*	\param end		--[in]	������ݣ�Ҫ�� \c end ����400���ڼ���ʱ��������������� \c end ����
 */
#define	EXP_HOW_MANY_LEAP_YEAR_BETWEEN(start, end)		\
		( EXP_HOW_MANY_LEAP_YEAR (end) - \
			EXP_HOW_MANY_LEAP_YEAR (start))

/*!
*	\brief ��ָ�������֮��ľ���������
* 
*	����start/01/01��end/01/01�ڼ�������������
*
*	\param start	--[in]	��ʼ��ݣ�Ҫ�� \c start ����400��
*	\param end		--[in]	������ݣ�Ҫ�� \c end ����400���ڼ���ʱ��������������� \c end ����
 */
#define	HOW_MANY_DAYS_BETWEEN(start, end)						\
			((end - start) * DAYS_IN_YEAR						\
				+ EXP_HOW_MANY_LEAP_YEAR_BETWEEN (start, end))

/*!
* 	\brief �� TIMET_START_YEAR ��������ݵ�1��1���� \c year ���1��1��, �����˶����죬
*			������ \c year ���1��1����һ�졣
*	
*	\param year	--[in]	��ʼ��ݣ�Ҫ�� \c year ����400��
 */
#define	HOW_MANY_DAYS_SINCE_TIMET_START_YEAR(year)			\
			HOW_MANY_DAYS_BETWEEN ( TIMET_START_YEAR,		\
									year)

#if !defined( WIN32 )

/*!
*	\brief �ڷ�Windowsƽ̨�ϵĶ���Windowsϵͳ����ʱ��ṹ����
 */
typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

/*!
 *	\brief ����ϵͳʱ��
 *
 *	\param	pstm	--[in]	ʹ�øò�������������ʱ��ȥ����ϵͳ�ĵ�ǰʱ��
 *
 *	\note
 *		����pstm����������ʱ���ǵ���ʱ��, ��û����ʱ�ơ�
 *		�ڵ��ñ�����ʱ, ������Ȩ�޼�������.
 */
ACSI_DLL void SetLocalTime(SYSTEMTIME * pstm);

/*!
 *	\brief ȡϵͳ��ǰʱ��.
 *
 *	\param	pstm	--[out]	ȡ�õ�ϵͳʱ����õ��ò�����.
 *
 *	\note
 *		ȡ�õ�ʱ������ǵ���ʱ��, ��û����ʱ�ơ�
 */
ACSI_DLL void GetLocalTime(SYSTEMTIME * pstm);

#endif // !defined( WIN32 )

/*!
 *	\brief timevalʱ��ת��ΪSYSTEMTIME���͵�ʱ��
 *
 *	\param	ptv 	--[in]	Ҫת����ʱ��
 *	\param	pstm	--[out]	��ת�����ʱ��
 */
ACSI_DLL void timeval_2_SYSTEMTIME(YHFtimeval * ptv, SYSTEMTIME * pstm);

ACSI_DLL void timeval_2_YHFTmStru(YHFtimeval * ptv, struct YHFTmStruct * pstm);

/*!
 *	\brief timevalʱ��ת��ΪSYSTEMTIME���͵�ʱ��
 *
 *	\param	pstm	--[in]	��ת����ʱ��
 *	\param	ptv 	--[out]	ת�����ʱ��
 */
ACSI_DLL void SYSTEMTIME_2_timeval(SYSTEMTIME * pstm, struct timeval * ptv);
/*!
 *	\brief timevalʱ��ת��ΪSYSTEMTIME���͵�ʱ��
 *
 *	\param	pstm	--[in]	��ת����ʱ��
 *	\param	ptv 	--[out]	ת�����ʱ��
 */

/*!
 *	\brief ȡָ��ʱ��(SYSTEMTIME)������ʱ���ַ�������
 *
 *	\param	pstm		--[in]	SYSTEMTIME���͵�ʱ��
 *	\param	pszdt_str	--[out]	��������ʱ���ַ���
 *
 *  \return
 *		��ʽ����ɺ���ַ���, ʵ���ϵ���pszdt_str
 *
 *	\note
 *		ʱ���ַ����ĸ�ʽΪ(%04d-%02d-%02d %02d:%02d:%02d.%03d), ���, ʱ���ַ������
 *		����32�ַ�(����null�ַ�), ��˶���MAX_DATATIME_STRING_L=32
 *
 */
ACSI_DLL char* get_SYSTEMTIME_str(SYSTEMTIME * pstm, char * pszdt_str);

/*!
 *	\brief ȡָ��ʱ��(timeval)������ʱ���ַ�������
 *
 *	\param	ptv			--[in]	timeval���͵�ʱ��
 *	\param	pszdt_str	--[out]	��������ʱ���ַ���
 *
 *	\return
 *		��ʽ����ɺ���ַ���, ʵ���ϵ���pszdt_str
 *		
 *	\note
 *		ʱ���ַ����ĸ�ʽΪ(%04d-%02d-%02d %02d:%02d:%02d.%03d), ���, ʱ���ַ������
 *		����32�ַ�(����null�ַ�), ��˶��� MAX_DATATIME_STRING_L=32
 *
 */
ACSI_DLL char* get_timeval_str(YHFtimeval * ptv, char * pszdt_str);//

/*!
 *	\brief ȡָ��ʱ��(tm)������ʱ���ַ�������
 *
 *	\param	ptm			--[in]	tm���͵�ʱ��
 *	\param	pszdt_str	--[out]	��������ʱ���ַ���
 *
 *	\return
 *		��ʽ����ɺ���ַ���, ʵ���ϵ���pszdt_str
 *		
 *	\note
 *		ʱ���ַ����ĸ�ʽΪ(%04d-%02d-%02d %02d:%02d:%02d.%03d), ���, ʱ���ַ������
 *		����32�ַ�(����null�ַ�), ��˶��� MAX_DATATIME_STRING_L=32
 *
 */
ACSI_DLL char* get_tm_str(struct tm * ptv, char * pszdt_str);

/*
 *	ȡ��ǰ������ʱ���ַ���
 *
 *	����
 *		pszdt_str	--	��������ʱ���ַ���, ��һ��MAX_DATATIME_STRING_L���ȵ��ַ���ָ��
 *
 *	����ֵ
 *		��ʽ����ɺ���ַ���, ʵ���ϵ���pszdt_str
 *
 *	��ע
 *		ʱ���ַ����ĸ�ʽΪ(%04d-%02d-%02d %02d:%02d:%02d.%03d), ���, ʱ���ַ������
 *		����32�ַ�(����null�ַ�), ��˶���MAX_DATATIME_STRING_L=32
 *
 */
ACSI_DLL char* get_cur_dt_str(char * pszdt_str);

/*!
 *	\brief ʱ��Ƚ�, ���������ֵ�ľ���ֵ
 *
 *	\param	ptv1			--[in]	ʱ��1
 *	\param	ptv2			--[in]	ʱ��2
 *	\param	ptv_abs_delta	--[out]	���ز�ֵ�ľ���ֵ, ����ò�����ΪNULL.
 *
 *	\retval	С��0	--	ptv1 С��(����) ptv2
 *	\retval	����0	--	ptv1 ����(����) ptv2
 *	\retval	����0	--	ptv1 ����(����) ptv2
 */
ACSI_DLL int timeval_compare(YHFtimeval * ptv1, YHFtimeval * ptv2, YHFtimeval * ptv_abs_delta);

/*!
 *	\brief ȡ���е�����
 *
 *	\param	ptmt	--[in]	time_t��ʽ������ʱ��
 *	
 *	\return
 *		���ڼ�	--	0 -- 6; ����0 -- ������, 1 -- ����һ ... 6 -- ������
 */
ACSI_DLL int get_wday(time_t * ptmt);

/*!
*	\brief ȡĳ�������ڵ������һ��
*
*	\param	ptmt	--[in]	time_t��ʽ�ĸ�
*
*	\return
*		����ֵ��Χ��[0, 365] \n
*			- 0 ����1��1��
*			- 364 �ڷ��������12��31�գ������꣬����12��30�ա�
*			- 365 ���������12��31�գ��ڷ����꣬�����ܷ��ظ�ֵ��
*/
ACSI_DLL int get_yday(time_t * ptmt);


void timeval_add( struct timeval * ptv_dst, struct timeval * ptv_add );
void timeval_sub( struct timeval * ptv_dst, struct timeval * ptv_sub );
void timeval_add_usec( struct timeval * ptv_dst, int u_sec );

#ifdef __cplusplus
}
#endif

#endif	//__XTIME_H__

