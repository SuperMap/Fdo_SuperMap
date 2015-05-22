/*! \file	 UGTime.h
 *  \brief	 时间类
 *  \author	 zengzm
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGTime.h,v 1.8 2007/07/26 08:09:30 zengzm Exp $
	\remarks 更新说明：参考MFC中的COleDateTime重新实现，以兼容SFC对于日期时间的处理，
	并可以处理从 1 January 100 到 31 December 9999 的日期时间
 */

#ifndef UGTIME_H
#define UGTIME_H

#include "ugdefs.h"
#include "UGString.h"

namespace UGC {

//! 时间间隔类
class BASE_API UGTimeSpan 
{
public:
	// Constructors
	//! \brief 默认构造函数,时间间隔为0
	UGTimeSpan();
	//! \brief 指定时间间隔进行构造
	UGTimeSpan(UGint nDays, UGint nHours, UGint nMins, UGint nSecs);
	//! \brief 指定double时间进行构造,比较复杂,一般不要使用
	UGTimeSpan(double dTime);
	
	//! \brief 拷贝构造函数
	UGTimeSpan(const UGTimeSpan& timeSpanSrc);
	//! \brief 拷贝赋值函数
	const UGTimeSpan& operator=(const UGTimeSpan& timeSpanSrc);
	
	// Attributes
	//! \brief 得到日
	UGint GetDays() const;
	//! \brief 得到小时,日转化为24小时
	UGint GetTotalHours() const;
	//! \brief 得到小时,日不计算在内
	UGint GetHours() const;
	//! \brief 得到分钟,日和时都转化为分
	UGint GetTotalMinutes() const;
	//! \brief 得到分钟,日和时不计算在内
	UGint GetMinutes() const;
	//! \brief 得到秒,日时分都转化为秒
	UGint GetTotalSeconds() const;
	//! \brief 得到秒,日时分不计算在内
	UGint GetSeconds() const;
	
	// Operations
	// time math
	UGTimeSpan operator-(UGTimeSpan timeSpan) const;
	UGTimeSpan operator+(UGTimeSpan timeSpan) const;
	const UGTimeSpan& operator+=(UGTimeSpan timeSpan);
	const UGTimeSpan& operator-=(UGTimeSpan timeSpan);
	UGbool operator==(UGTimeSpan timeSpan) const;
	UGbool operator!=(UGTimeSpan timeSpan) const;
	UGbool operator<(UGTimeSpan timeSpan) const;
	UGbool operator>(UGTimeSpan timeSpan) const;
	UGbool operator<=(UGTimeSpan timeSpan) const;
	UGbool operator>=(UGTimeSpan timeSpan) const;
	
	// 没有人使用,暂时封起来
	//UGString Format(LPCTSTR pFormat) const;
	
private:
	double m_timeSpan; // 按天数进行计算的
	friend class UGTime;
};

//! \brief 时间类, 参照COleDateTime实现
//! \remarks implemented as a floating-point value, measuring days from midnight, 
//! 30 December 1899. So, midnight, 31 December 1899 is represented by 1.0. 
//! Similarly, 6 AM, 1 January 1900 is represented by 2.25, 
//! and midnight, 29 December 1899 is – 1.0. 
//! However, 6 AM, 29 December 1899 is – 1.25.
//! Now, UGTime can handle dates from 1 January 100 – 31 December 9999
class BASE_API UGTime  
{
public:
	static UGTime GetCurrentTime();

	//! \brief 得到以毫秒为计数的时间; 用来精确测算性能等; 
	static UGint GetMillisecond();
	
	//! \brief 默认构造函数
	UGTime();

	//! \brief 拷贝构造函数
	UGTime(const UGTime& timeSrc);

	//! \brief 通过time_t进行构造
	UGTime(time_t t);

	//! \brief 直接通过UGTime内部的double数值进行构造
	UGTime(double tValue);
	
	//! \brief 年月日构造函数
	UGTime(UGint nYear,UGint nMonth,UGint nDay);
	
	//! \brief 年月日时分秒构造函数
	UGTime(UGint nYear, UGint nMonth, UGint nDay, UGint nHour, UGint nMin, UGint nSec);

	const UGTime& operator=(const UGTime& timeSrc);
	const UGTime& operator=(time_t t);

//	struct tm* GetGmtTm(struct tm* ptm = NULL) const;
//	struct tm* GetLocalTm(struct tm* ptm = NULL) const;

	//! \brief 得到UGTime内部的数据
	double GetTime() const;

	//! \brief 得到年(公元)。
	UGint GetYear() const;	
	//! \brief 得到月(从1-12)
	//! \remarks month of year (1 = Jan)
	UGint GetMonth() const;       // 
	//! \brief 得到日(每个月的日,从1-31)
	//! \remarks day of month
	UGint GetDay() const;         // 
	//! \brief 得到小时(从0-23)
	UGint GetHour() const;
	//! \brief 得到分钟(从0-59)
	UGint GetMinute() const;
	//! \brief 得到秒(从0-59)
	UGint GetSecond() const;
	//! \brief 得到日(每周内的日,周日为1)
	//! \remarks 1=Sun, 2=Mon, ..., 7=Sat
	UGint GetDayOfWeek() const;   // 
	//! \brief 得到日(每年内的日, 1月1日为1)
	UGint GetDayOfYear() const;   // 
	
	UGTimeSpan operator-(UGTime time) const;
	UGTime operator-(UGTimeSpan timeSpan) const;
	UGTime operator+(UGTimeSpan timeSpan) const;
	const UGTime& operator+=(UGTimeSpan timeSpan);
	const UGTime& operator-=(UGTimeSpan timeSpan);

	UGbool operator==(UGTime time) const;
	UGbool operator!=(UGTime time) const;
	UGbool operator< (UGTime time) const;
	UGbool operator> (UGTime time) const;
	UGbool operator<=(UGTime time) const;
	UGbool operator>=(UGTime time) const;

	//! \brief 传入一个格式化字符串,把UGTime的信息生成一个便于阅读的字符串
	//! \remarks 可参考MSDN中关于strftime的说明. 常用的格式化字符包括:
	//! %d Day of month as decimal number (01 – 31);
	//! %H Hour in 24-hour format (00 – 23);
	//! %m Month as decimal number (01 – 12)
	//! %M Minute as decimal number (00 – 59)
	//! %S Second as decimal number (00 – 59)
	//! %y Year without century, as decimal number (00 – 99)
	//! %Y Year with century, as decimal number
	UGString Format(LPCTSTR pFormat) const;
//	UGString FormatGmt(LPCTSTR pFormat) const;

	// deleted by zengzm 2007-4-12 ToString以前采用ctime实现, 现在UGTime支持更广泛时间,就不能用ToString了.
	// 建议用Format("%Y-%m-%d %X")代替
	//! 等同于 ctime(), MSDN上的说明如下, 例:Fri Apr 29 12:25:12 1994
	//! Convert a time value to a string and adjust for local time zone settings.
	// UGString ToString() const;

	//! \brief Parses a string to read a date/time value
	//! \remarks 例如: strFormat为"%Y-%m-%d %H:%M:%S", strDateTime为"1487-05-29 14:25:59", 
	//! 最后得到的UGTime为: 1487年05月29日 14时25分59秒
	//! \attention UGTime的ParseDateTime远没有MFC中COleDateTime的ParseDateTime强大, 
	//! COleDateTime的ParseDateTime中调用了Win32 API VarDateFromStr,其内部实现看不到,
	//! 实际上, UGC中也不用这么强大. 因此,请严格按照上述例子中的用法, 尤其注意多余的0也要写上
	UGbool ParseDateTime(UGString strDateTime,UGString strFormat);

private:
	//! \brief 把年月日时分秒转化为 内部的double数值
	void SetDateTime(UGint nYear, UGint nMonth, UGint nDay, UGint nHour, UGint nMin, UGint nSec);
	//! \brief 把double数值转化为tm结构
	void GetDateTime(struct tm& tmDest) const;
	//! \brief 得到标准的tm结构
	void GetStandardTm(struct tm& tmDest) const;

	//! \brief 得到处理后的double值
	//! \remarks 等同于MFC中的_AfxDoubleFromDate
	double GetDoubleValue() const;
	//! \brief 从处理后的double值中得到time
	//! \remarks 等同于MFC中的_AfxDateFromDouble
	void FromDoubleValue(double dbl);

	//time_t m_time;
	double m_time;
};

}

#endif 

