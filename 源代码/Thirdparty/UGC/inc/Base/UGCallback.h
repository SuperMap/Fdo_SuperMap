/* 
	\file UGCallback.h
	\brief 回调函数类。
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。
	<em>2、第二条说明。
*/

#ifndef UGCALLBACK_H
#define UGCALLBACK_H
#include "ugdefs.h"

namespace UGC {

//! \brief 错误信息回调函数
// typedef void (*ErrorInfoProc)(const UGchar* pchErrorInfo);

//! \brief 进程条信息回调函数
//! \remarks add the argument bCancel to communicate with the outside functions.caogf
// typedef void (*ProgressProc)(const UGchar* pchTitle,const UGchar* pchMessage,
//							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel);

//! \brief 回调函数类。
/**
	\attention 基于UGC中使用回调函数的地方日益增加，所有的回调的地方都放到与之相关的类中，
	错误处理、进程条信息回调也分别放到UGErrorObj和UGProgress中；UGCallback声明作废，相关函数封存
*/

/*
class BASE_API UGCallback  
{
public:	
	//! \brief 清空回调函数指针
	//static void Clear();
	
	//! \brief 设置错误处理的回调函数指针
	//static void SetErrorInfoProc(ErrorInfoProc pErrorInfoFun);	

	// by zengzm 2007-4-10 没有使用,暂时封存
	//static ErrorInfoProc GetErrorInfoProc();

	//! \brief 设置进程条信息的回调函数指针
	//static void SetProgressProc(ProgressProc pProgressFun);	
	
	// by zengzm 2007-4-10 没有使用,暂时封存
	//static ProgressProc GetProgressProc();

private: // by zengzm 2007-4-10 把回调函数的调用放到private中,避免外面的误用
	// 在UGErrorObj和UGProgress中调用下面的回调函数
	friend class UGErrorObj;
	friend class UGProgress;

	//! \brief 调用错误信息回调函数,仅在UGErrorObj中使用
	static void CallErrorInfo(const UGchar* pchErrorInfo);	
	//! \brief 调用进程条回调函数,仅在UGProgress中使用
	static void CallProgress(const UGchar* pchTitle,const UGchar* pchMessage,
							 UGint nPercent, const UGchar* pchRemainTime,UGbool& bCancel);
private:
	//! \brief 错误信息回调函数指针
	static ErrorInfoProc m_pErrorInfoFun;
	//! \brief 进程条回调函数指针
	static ProgressProc	m_pProgressFun;
};
*/
}

#endif 


