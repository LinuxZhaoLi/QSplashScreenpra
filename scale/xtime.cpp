/*************************************************************************
* Copyright (c) 2008,������Ԫ�������������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief	�������ʱ�䴦��ĺ���
	\author	Chen
	\version	1.0
	\date	2008-04-23
*/

#include <stdio.h>
#include "xtime.h"

/*
 *	��������ÿһ���µ�����
 */
static const int s_mday_per_month_of_none_leap_year[12] = 
		{
			31,		//	1
			28,		//	2
			31,		//	3
			30,		//	4
			31,		//	5
			30,		//	6
			31,		//	7
			31,		//	8
			30,		//	9
			31,		//	10
			30,		//	11
			31		//	12
		};


/*
 *	������ÿһ���µ�����
 */
static const int s_mday_per_month_of_leap_year[12] = 
		{
			31,		//	1
			29,		//	2
			31,		//	3
			30,		//	4
			31,		//	5
			30,		//	6
			31,		//	7
			31,		//	8
			30,		//	9
			31,		//	10
			30,		//	11
			31		//	12
		};

/*
 *	������ʱ, ������ĳ��ʱ����������
 */
static const int s_yday_per_month_of_none_leap_year[12] = 
		{	
			0,		//	1	31
			31,		//	2	28
			59,		//	3	31
			90, 	//	4	30
			120,	//	5 	31
			151,	//	6 	30
			181,	//	7 	31
			212,	//	8 	31
			243,	//	9 	30
			273,	//	10 	31
			304,	//	11 	30
			334		//	12 	31
			//365
		};

/*
 *	����ʱ, ������ĳ��ʱ����������
 */
static const int s_yday_per_month_of_leap_year[12] = 
		{
			0,		//	1	31,	
			31, 	//	2	29,	
			60, 	//	3	31,	
			91, 	//	4	30,	
			121,	//	5 	31,	
			152,	//	6 	30,	
			182,	//	7 	31,	
			213,	//	8 	31,	
			244,	//	9 	30,	
			274,	//	10 	31,	
			305,	//	11 	30,	
			335		//	12 	31	
			//366
		};

#ifdef	WIN32

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif

struct tm *gmtime_r (const time_t *timer, struct tm *tp)
{
    struct tm *pTm = gmtime(timer);
    memcpy(tp, pTm, sizeof(struct tm));
    return pTm;
}

void FILETIME_2_timeval ( FILETIME*  pft, struct timeval* ptv )
{
	/*	The FILETIME structure is a 64-bit value representing 
		the number of 100-nanosecond intervals since January 1, 1601. */
	unsigned __int64   var = (unsigned __int64)pft->dwHighDateTime * (unsigned __int64)0x100000000 
					+ (unsigned __int64)pft->dwLowDateTime;

	unsigned __int64   sec ;
	unsigned __int64   usec;
	unsigned __int64   secs_between_1601_1970;

	sec = var / (unsigned __int64)10000000;
	usec = (var % (unsigned __int64)10000000) / 10;

	secs_between_1601_1970 
		= (unsigned __int64)HOW_MANY_DAYS_BETWEEN(1601, 1970) * (unsigned __int64)SECONDS_IN_DAY;
	
	ptv->tv_sec = (int)(sec - secs_between_1601_1970);
	ptv->tv_usec = (int)usec;
}

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
	FILETIME ft;
	unsigned __int64 tmpres = 0;
	static int tzflag = 0;
	
	if (NULL != tv)
	{
		GetSystemTimeAsFileTime(&ft);
		
		//FILETIME_2_timeval ( &ft, tv );
		
		#if 1
		tmpres |= ft.dwHighDateTime;
		tmpres <<= 32;
		tmpres |= ft.dwLowDateTime;
		
		tmpres /= 10;  /*convert into microseconds*/
		/*converting file time to unix epoch*/
		tmpres -= DELTA_EPOCH_IN_MICROSECS; 
		tv->tv_sec = (long)(tmpres / 1000000UL);
		tv->tv_usec = (long)(tmpres % 1000000UL);
		#endif
	}
	
	if (NULL != tz)
	{
		if (!tzflag)
		{
			_tzset();
			tzflag++;
		}
		tz->tz_minuteswest = _timezone / 60;
		tz->tz_dsttime = _daylight;
	}
	return 0;
}

int settimeofday(const struct timeval *tv ,  const struct timezone *tz)
{
	SYSTEMTIME systime;
	
	if(tv == NULL)
		return -1;

	timeval_2_SYSTEMTIME ((YHFtimeval *)tv, &systime );

	if(SetLocalTime(&systime) == 0)
		return -1;

    tz;

	return 0;
}
#endif	//WIN32

#ifdef VXWORKS
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    struct timespec tp;
    
    clock_gettime (CLOCK_REALTIME, &tp);
    
	tv->tv_sec  = tp.tv_sec;
	tv->tv_usec = tp.tv_nsec / 1000;
	
	tz;
	
    return 0;
}

int settimeofday(const struct timeval *tv ,  const struct timezone *tz)
{
    struct timespec tp;
	tp.tv_sec  = tv->tv_sec;
	tp.tv_nsec = tv->tv_usec * 1000;
	
	tz;
	
    return clock_settime (CLOCK_REALTIME, &tp);
}

#endif	//VXWORKS


//timevalʱ��ptvת��ΪSYSTEMTIME���͵�ʱ��pstm
void timeval_2_SYSTEMTIME(YHFtimeval * ptv, SYSTEMTIME* pstm)
{
	struct tm	tmv;

	time_t  tmt = ptv->tv_sec + __TIMEZONE__ * SECONDS_IN_HOUR;
	gmtime_r(&tmt, &tmv);

	pstm->wYear = (WORD)(tmv.tm_year + 1900);
	pstm->wMonth = (WORD)(tmv.tm_mon + 1);
	pstm->wDay = (WORD)tmv.tm_mday;
	pstm->wDayOfWeek = (WORD)tmv.tm_wday;
	pstm->wHour = (WORD)tmv.tm_hour;
	pstm->wMinute = (WORD)tmv.tm_min;
	pstm->wSecond = (WORD)tmv.tm_sec;
	pstm->wMilliseconds = (WORD)(ptv->tv_usec / 1000);
}

//timevalʱ��ptvת��ΪYHFTmStruct���͵�ʱ��pstm
void timeval_2_YHFTmStru(YHFtimeval * ptv, struct YHFTmStruct* pstm)
{
	struct tm	tmv;

	time_t  tmt = ptv->tv_sec + __TIMEZONE__ * SECONDS_IN_HOUR;
	gmtime_r(&tmt, &tmv);

	pstm->Year = (WORD)(tmv.tm_year + 1900);
	pstm->Month = (WORD)(tmv.tm_mon + 1);
	pstm->Day = (WORD)tmv.tm_mday;
	pstm->Hour = (WORD)tmv.tm_hour;
	pstm->Minute = (WORD)tmv.tm_min;
	pstm->Second = (WORD)tmv.tm_sec;
	pstm->Millisecond = (WORD)(ptv->tv_usec / 1000);
	pstm->Microsecond = (WORD)(ptv->tv_usec % 1000);
}

//	SYSTEMTIMEʱ��pstmת��Ϊtimeval���͵�ʱ��ptv
void SYSTEMTIME_2_timeval(SYSTEMTIME * pstm, struct timeval * ptv)
{
	int days = (pstm->wYear - TIMET_START_YEAR) * DAYS_IN_YEAR 
					+ EXP_HOW_MANY_LEAP_YEAR_BETWEEN(TIMET_START_YEAR, pstm->wYear);
	days += (EXP_IS_LEAP_YEAR(pstm->wYear) 
				? s_yday_per_month_of_leap_year[pstm->wMonth - 1] 
					: s_yday_per_month_of_none_leap_year[pstm->wMonth - 1])
			+ (pstm->wDay - 1);

	ptv->tv_sec = days * SECONDS_IN_DAY 
					+ pstm->wHour * SECONDS_IN_HOUR
					+ pstm->wMinute * SECONDS_IN_MINUTE 
					+ pstm->wSecond - __TIMEZONE__ * SECONDS_IN_HOUR;

	ptv->tv_usec = (int)pstm->wMilliseconds * 1000;
}


#if !defined( WIN32 )
void SetLocalTime(SYSTEMTIME * pstm)
{
	struct timeval	tv;
	SYSTEMTIME_2_timeval(pstm, &tv);
	settimeofday(&tv, NULL);
}

void GetLocalTime(SYSTEMTIME * pstm)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	//ctm timeval_2_SYSTEMTIME(&tv, pstm);
}
#endif


#define	UTIL_DATE_TIME_STR_FORMAT			("%04d-%02d-%02d %02d:%02d:%02d.%03d")


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
char * get_cur_dt_str(char * pszdt_str)
{
	SYSTEMTIME	stmNow;

	GetLocalTime(&stmNow);
	
	get_SYSTEMTIME_str(&stmNow, pszdt_str);

	return pszdt_str;
}


/*
 *	ȡָ��ʱ��(SYSTEMTIME)������ʱ���ַ�������
 *
 *	����
 *		pstn	--	SYSTEMTIME_t���͵�ʱ��
 *		pszdt_str	--	��������ʱ���ַ���
 *
 *	����ֵ
 *		��ʽ����ɺ���ַ���, ʵ���ϵ���pszdt_str
 *
 *	��ע
 *		ʱ���ַ����ĸ�ʽΪ(%04d-%02d-%02d %02d:%02d:%02d.%03d), ���, ʱ���ַ������
 *		����32�ַ�(����null�ַ�), ��˶���MAX_DATATIME_STRING_L=32
 *
 */
char * get_SYSTEMTIME_str(SYSTEMTIME * pstm, char * pszdt_str)
{
	sprintf(pszdt_str, 
				UTIL_DATE_TIME_STR_FORMAT,
				pstm->wYear,
				pstm->wMonth,
				pstm->wDay,
				pstm->wHour,
				pstm->wMinute,
				pstm->wSecond,
				pstm->wMilliseconds);

	return pszdt_str;
}


/*
 *	ȡָ��ʱ��(timeval)������ʱ���ַ�������
 *
 *	����
 *		ptv	--	timeval���͵�ʱ��
 *		pszdt_str	--	��������ʱ���ַ���
 *
 *	����ֵ
 *		��ʽ����ɺ���ַ���, ʵ���ϵ���pszdt_str
 *		
 *	��ע
 *		ʱ���ַ����ĸ�ʽΪ(%04d-%02d-%02d %02d:%02d:%02d.%06d), ���, ʱ���ַ������
 *		����32�ַ�(����null�ַ�), ��˶���MAX_DATATIME_STRING_L=32
 *
 */
char * get_timeval_str( YHFtimeval * ptv, char * pszdt_str)
{
	SYSTEMTIME	stm;
	timeval_2_SYSTEMTIME(ptv, &stm);
	sprintf(pszdt_str, 
				"%04d-%02d-%02d %02d:%02d:%02d.%06d",
				stm.wYear,
				stm.wMonth,
				stm.wDay,
				stm.wHour,
				stm.wMinute,
				stm.wSecond,
				ptv->tv_usec);
	return pszdt_str;
}


char * get_tm_str(struct tm* ptm, char * pszdt_str)
{
	sprintf(pszdt_str, 
				UTIL_DATE_TIME_STR_FORMAT,
				ptm->tm_year + 1900,
				ptm->tm_mon + 1,
				ptm->tm_mday,
				ptm->tm_hour,
				ptm->tm_min,
				ptm->tm_sec,
				0);

	return pszdt_str;
}

/*
 *	ʱ��Ƚ�, ���������ֵ�ľ���ֵ
 *
 *	����
 *		ptv1	--	ʱ��1
 *		ptv2	--	ʱ��2
 *		ptv_abs_delta --	���ز�ֵ�ľ���ֵ, ����ò�����ΪNULL.
 *
 *	����ֵ
 *		С��0	--	ptv1 С��(����) ptv2
 *		����0	--	ptv1 ����(����) ptv2
 *		����0	--	ptv1 ����(����) ptv2
 */
int timeval_compare(YHFtimeval * ptv1, YHFtimeval * ptv2, YHFtimeval * ptv_abs_delta)
{
	int ret = 0;

	int del_sec = ptv1->tv_sec - ptv2->tv_sec;
	int del_usec = ptv1->tv_usec - ptv2->tv_usec;

	ret = (del_sec != 0) ? del_sec : del_usec;

	if ( ptv_abs_delta )
	{
		if ( ret < 0 )
		{
			del_sec = -del_sec;
			del_usec = -del_usec;
		}

		if ( del_usec < 0 )
		{
			del_usec += 1000000;
			del_sec--;
		}

		ptv_abs_delta->tv_sec = del_sec;
		ptv_abs_delta->tv_usec = del_usec;
	}

	return ret;
}

/*
 *	ȡ���е�����
 *
 *	����
 *		ptmt	--	time_t��ʽ������ʱ��
 *	
 *	����ֵ
 *		���ڼ�	--	0 -- 6; ����0 -- ������, 1 -- ����һ ... 6 -- ������
 */
int get_wday(time_t * ptmt)
{
	struct tm	tmv;

	time_t  tmt = *ptmt + __TIMEZONE__ * SECONDS_IN_HOUR;
	gmtime_r(&tmt, &tmv);

	return tmv.tm_wday;
}

/*
 *	ȡĳ�������ڵ������һ��
 *
 *	����
 *		ptmt	--	time_t��ʽ�ĸ�
 *
 *	����ֵ
 *		0 -- 365; 0����1��1��, 364(������)/365(����)����12��31��
 */
int get_yday(time_t * ptmt)
{
	struct tm	tmv;
	time_t  tmt = *ptmt + __TIMEZONE__ * SECONDS_IN_HOUR;
	gmtime_r(&tmt, &tmv);
	return tmv.tm_yday;
}


/*
 *	��timeval�ṹ�е�ʱ������.
 *
 *	����
 *		ptv --	�������򻯵�timeval���͵�ʱ��, ��������Ϊ��.
 *		
 *	����ֵ
 *		0 -- *ptv�а�������Ч��ʱ��, ͬʱ*ptv�ڷ���ʱ���������ֵ
 *		��0 -- *ptv�а�������Ч��ʱ��, ͬʱ*ptv��Ϊ�������ʱ��ֵ
 *
 *	��ע
 *		1. �����򻯹�����, ���*ptv����Ϊ������Ϊ��Ч��ʱ��.
 *		2. ������ʱ��(time zone)����.
 */
int timeval_normalize ( struct timeval * ptv )
{
	int usec = ptv->tv_usec;
	int sec = 0;

	if ( usec > 0 )
	{
		sec = usec / 1000000;
		usec = usec % 1000000;
	}
	else
	{
		sec = usec / 1000000;
		usec = usec - sec * 1000000;
		if ( usec < 0 )
		{
			sec--;
			usec += 1000000;
		}
	}

	sec = ptv->tv_sec + sec;

	if ( sec < 0 )
		return 0;
	else
	{
		ptv->tv_sec = sec;
		ptv->tv_usec = usec;

		return 1;
	}
}

void timeval_add( struct timeval * ptv_dst, struct timeval * ptv_add )
{
	ptv_dst->tv_sec  += ptv_add->tv_sec;
	ptv_dst->tv_usec += ptv_add->tv_usec;
	if ( ptv_dst->tv_usec >= 1000 * 1000 )
	{
		ptv_dst->tv_sec++;
		ptv_dst->tv_usec -= 1000 * 1000;
	}
}

void timeval_sub( struct timeval * ptv_dst, struct timeval * ptv_sub )
{
	int delta = ptv_dst->tv_usec - ptv_sub->tv_usec;
	ptv_dst->tv_sec  -= ptv_sub->tv_sec;
	if ( delta < 0 )
	{
		ptv_dst->tv_sec--;
		ptv_dst->tv_usec = delta + 1000*1000;
	}
}

void timeval_add_usec( struct timeval * ptv, int usec )
{
	ptv->tv_sec  += usec/(1000*1000);
	ptv->tv_usec += usec%(1000*1000);
	
	if ( ptv->tv_usec < 0 )
	{
		ptv->tv_sec--;
		ptv->tv_usec += 1000 * 1000;
		return;
	}
	
	if ( ptv->tv_usec >= 1000*1000 )
	{
		ptv->tv_sec++;
		ptv->tv_usec -= 1000 * 1000;
	}
}
