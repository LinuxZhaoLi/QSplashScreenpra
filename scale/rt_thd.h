/*************************************************************************
* Copyright (c) 2011, ������Ԫ�������������޹�˾
* All rights reserved.

**************************************************************************/

/*!	\file
 	\brief		ʵʱ�����߳�
 	
	\author		Chen
	\version	1.0
	\date		2011-03-18
*/

#ifndef	__SH_REAL_TIME_PROC_THREAD_DEFINE_H
#define	__SH_REAL_TIME_PROC_THREAD_DEFINE_H

#include <QThread>
#include "fltrcd.h"

//#include "MergeMgr.h"
//#include "rcv_mgr.h"

class RtProcThread : public QThread
{
 //   Q_OBJECT
public:
        RtProcThread();//QObject *parent = 0
        ~RtProcThread();

        void run();

private:

};

#endif	//__SH_REAL_TIME_PROC_THREAD_DEFINE_H
