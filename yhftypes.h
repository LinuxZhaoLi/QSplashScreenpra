/*!	\file      yhftypes.h
 	\brief	   ����YHF�����������Ͷ���
	 	       ���ļ��ж�������Ŀ�л�����������,���ļ����������͵�������ʽ��
 	           IEC 61850�е��������ͱ���һ�¡�����Ŀ�ж������ݽṹʱ��ʹ����
 	           Щ�����������ͽ��ж��壬��Ҫֱ��ʹ��char,int,short�����ͣ���Ϊ�ڲ�ͬ��
 	           ��ϵͳƽ̨�£�������ռ�ÿռ��С��һ��
	\author	   Chen
	\version   1.0
	\date	   2011-11-7
*/

#ifndef __YHF_TYPEDEF_H
#define __YHF_TYPEDEF_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* WIN32 SYSTEM															*/
/************************************************************************/
#if defined(WIN32)				/*! VC++, 32-Bit		*/

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef INT8
typedef signed char		INT8;
#endif
typedef signed short	INT16;
typedef signed int		INT32;
//typedef signed __int64		INT64;

typedef	unsigned char   	BYTE, INT8U;
typedef	unsigned short		WORD, INT16U;
typedef	unsigned long		DWORD, INT32U;
//typedef	unsigned __int64	INT64U;

typedef int                 	BOOL;
//typedef unsigned char		BOOLEAN;
typedef	float			FLOAT32;
typedef	double			FLOAT64;
#endif	/*_WIN32*/

/************************************************************************/
/* LINUX SYSTEM															*/
/************************************************************************/
#if defined(linux)

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef INT8
#undef INT8
typedef signed char		INT8;
#endif

typedef signed short		INT16;
typedef signed int		    INT32;
typedef signed long long	INT64;

typedef	unsigned char   	BYTE, INT8U;	
typedef	unsigned short		WORD, INT16U;
typedef	unsigned long		DWORD, INT32U;
typedef	unsigned long long	INT64U;

typedef int                 BOOL;
//typedef unsigned char		BOOLEAN;
typedef	float			    FLOAT32;
typedef	double			    FLOAT64;

#endif	/* linux */

/*
#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKELONG(a, b)      ((INT32)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define LOWORD(l)           ((WORD)(l))
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#define LOBYTE(w)           ((BYTE)(w))
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))
*/
#ifndef NOMINMAX

//#ifndef max
//#define max(a,b)            (((a) > (b)) ? (a) : (b))
//#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif  /* NOMINMAX */

#ifndef PI
#define PI		3.1415926535897932384626433832795
#endif

#ifndef SQRT_2
#define SQRT_2		1.4142135623730950488016887242097
#endif

#ifndef SQRT_3
#define SQRT_3		1.7320508075688772935274463415059
#endif

#pragma pack(1)

/*!	\struct YHFTmStruct
 	\brief	ʱ��ṹ��YHFTmStruct
*/
struct YHFTmStruct
{ 
	WORD	Year;		    /*!< �� (xxxx) */
	WORD	Month;		    /*!< �� (1-12) */
	BYTE	Day;		    /*!< �� (1-31) */
	BYTE	Hour;		    /*!< ʱ (0�C23) */
	BYTE	Minute;		    /*!< �� (0�C59) */
	BYTE	Second;		    /*!< �� (0�C59) */
	WORD	Millisecond;	/*!< ����0.001s */
	WORD	Microsecond;	/*!< ΢��0.001*0.001 */
};

/*!	\struct YHFtimeval
 	\brief	ʱ��ṹ��YHFtimeval
*/
typedef struct  yhftimeval
{
  long tv_sec;      /*!< �� */
  long tv_usec;     /*!< ΢�� */
}YHFtimeval;

#pragma pack()

#ifdef __cplusplus
}
#endif

#endif /* __YH_IEC61850_TYPEDEF_H */
