/*!	\file UGEfficiency.h
	\brief UGC内置性能测试工具。
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	\remarks 性能测试工具的目的在于: 1)能方便的记录某个函数一次运行的时间
	2)能方便记录一段代码一次运行的时间.
	对于1),在函数的入口处定义 UGEFF_FUN(fun_name), 
	对于2),在开始的地方写上 UGEFF_BEGIN, (注:UGEFF_FUN会自动开始代码段性能的记录)
	在需要报告性能的地方写上 UGEFF_REPORT(strReport), (UGEFF_REPORT可连续使用)
	在定义_UG_ENABLE_EFF宏或者debug版本下,	性能报告信息就会自动写入到日志文件中,级别为debug.
	举例如下:
1) 只记录函数整体性能
ClassName::FunName()
{
	UGEFF_FUN("ClassName::FunName") // 会自动记录这个函数作为一个整体,一次运行的时间
}
2) 只记录代码段性能
ClassName::FunName()
{
	// 不用记录的代码段
	UGEFF_BEGIN //开始记录
	// 需要记录性能的代码段
	UGEFF_REPORT("上述代码的性能")
	// 需要记录性能的代码段
	UGEFF_REPORT("上述代码的性能")
}
3) 同时记录函数整体性能和代码段性能
ClassName::FunName()
{
	UGEFF_FUN("ClassName::FunName") // 会自动记录这个函数作为一个整体,一次运行的时间. 同时开始代码段性能的测试
	// 需要记录性能的代码段
	UGEFF_REPORT("上述代码的性能")
	// 需要记录性能的代码段
	UGEFF_REPORT("上述代码的性能")
	// 不需要记录的代码段
	UGEFF_BEGIN //开始记录
	// 需要记录性能的代码段
	UGEFF_REPORT("上述代码的性能")
}
	<b>更新说明：。</b>
	<em>1、第一条说明。
	<em>2、第二条说明。
*/

#if !defined(AFX_UGEFFICIENT_H__3F256D18_BBDE_49E5_9AD1_D502D554FD16__INCLUDED_)
#define AFX_UGEFFICIENT_H__3F256D18_BBDE_49E5_9AD1_D502D554FD16__INCLUDED_

#include "ugdefs.h"
#include "UGString.h"
#include "UGLogFile.h"

// modified by zengzm 2007-6-11 默认都启动，由日志文件级别来控制是否把性能信息写到日志文件中（debug级别才写入）
#if !defined(_UG_ENABLE_EFF) //| defined(_DEBUG)
	#define _UG_ENABLE_EFF
#endif

#ifdef _UG_ENABLE_EFF
	#define UGEFF_FUN(strFunName)	UGC::UGEfficiency _ug_eff_fun(strFunName, __FILE__, __LINE__)
	#define UGEFF_BEGIN()				UGC::UGEfficiency::Begin(__FILE__, __LINE__) 
	#define UGEFF_REPORT(strReport) UGC::UGEfficiency::Report(strReport, __FILE__, __LINE__) 
#else
	#define UGEFF_FUN(strFunName)
	#define UGEFF_BEGIN			
	#define UGEFF_REPORT(strReport)
#endif


namespace UGC{

//! \brief 性能测试类。
/**
	\remarks 不推荐直接使用,而是采用UGEFF_***的几个宏来进行性能的测试。
*/
class BASE_API UGEfficiency
{
public:
	//! \brief 对象定义,即开始对函数整体的计时,同时会清空代码段的记录
	//! \param strFunName 需要给出函数名称,对类成员函数,推荐采用ClassName::FunName的方式
	//! \param strCodeFile 开始记录的代码段
	//! \param nCodeLine 开始记录的代码行
	UGEfficiency(const UGString& strFunName, const UGString& strCodeFile, int nCodeLine);
	//! \brief 对象结束时, 自动把函数整体的运行时间记录到日志文件中
	~UGEfficiency();

	//! \brief 开始计时, 在 测试一段代码(而不是一个函数)时使用
	//! \param strCodeFile 开始记录的代码段
	//! \param nCodeLine 开始记录的代码行
	static void Begin(const UGString& strCodeFile, int nCodeLine);

	//! \brief 报告代码段的性能测试记录,记录到日志文件中
	//! \param strReport   需要记录的其它自定义信息
	//! \param strCodeFile 开始记录的代码段
	//! \param nCodeLine 开始记录的代码行
	static void Report(const UGString& strReport, const UGString& strCodeFile, int nCodeLine);
	
private:
	UGString m_strFunName; 
	int m_nFunBegin;

	static int ms_nCodeBegin;
	static UGString ms_strCodeFile;
	static int ms_nCodeLine;

private:
	// 需要分操作系统写, 以便获得更精确的时间
	static int GetTime();
};


} //namespace UGC



#endif // !defined(AFX_UGEFFICIENT_H__3F256D18_BBDE_49E5_9AD1_D502D554FD16__INCLUDED_)
