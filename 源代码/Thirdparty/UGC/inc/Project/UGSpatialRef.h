//=====================================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 0.9
// 作  者：			张立立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
//版权声明:         版权所有 1996-2003 北京超图地理信息技术有限公司，保留所有权利 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// 重要声明：		1. 
//					2. 
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGSpatialReference.h 
// 类  名：			UGSpatialRef
// 父  类：			
// 子  类：			UGGeoCoordSys,UGPrjCoordSys

// 功能说明：		空间坐标系
// 调用说明：		
/*-------------------------------------版本更新---------------------------

$Revision: 1.15 $
$Log: UGSpatialRef.h,v $
Revision 1.15  2007/12/17 08:13:38  dongfei
添加注释

Revision 1.14  2007/06/18 02:39:55  dongfei
uglong改为ugint型

Revision 1.13  2006/03/01 06:19:46  chengx
修改投影坐标系取单位错误问题

Revision 1.12  2005/07/18 15:25:09  zhangli
1 增加m_nDistUnit，测量时使用的距离单位
2 增加GetDistUnit和SetDistUnit,用于设置距离单位

$Author: dongfei $
$Date: 2007/12/17 08:13:38 $

========================================================================*/

#if !defined(UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_)
#define UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_

//// #include "SmImport.h"

#include "Base/UGString.h"
#include "Project/UGPjCon.h"

namespace UGC{


class PROJECT_API UGSpatialRef
{
public:
	//! \brief 默认构造函数
	UGSpatialRef();
	virtual ~UGSpatialRef();

	virtual UGSpatialRef& operator = (const UGSpatialRef& SpatialRef);
	virtual UGbool operator == (const UGSpatialRef& SpatialRef) const; 
	virtual UGbool operator != (const UGSpatialRef& SpatialRef) const;
	
	//! \brief 保存到文件
	virtual UGbool SaveToArray(const UGString& strFileName);
	//! \brief 从文件加载
	virtual UGbool LoadFromArray(const UGString& strFileName); 

	//! \brief 输出为XML字符串
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML字符串加载空间坐标系
	virtual UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief 从数据流读取空间坐标系信息
	virtual UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief 将空间坐标系信息输出到数据流
	virtual UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream

	//! \brief 获取空间坐标系名称
	UGString GetName() const;			
	//! \brief 设置空间坐标系名称
	virtual void SetName(const UGString& strName);
	//! \brief 获取空间坐标系类型
	EmSpatialRefType GetSpatialRefType() const;
	//! \brief 设置空间坐标系类型
	virtual void SetSpatialRefType(EmSpatialRefType eType);

	//! \brief 获取空间坐标系单位
	virtual UGint GetUnit() const;
	//! \brief 获取空间坐标系量算单位
	virtual UGint GetDistUnit() const;
//	virtual void SetUnit(UGint nUnit);
	//! \brief 设置空间坐标系单位
	virtual void SetUnit(UGint nUnit);
	//! \brief 设置空间坐标系量算单位
	virtual void SetDistUnit(UGint nUnit);
	//! \brief 获取空间坐标系描述信息
	UGString GetDescription() const;
	//! \brief 设置空间坐标系描述信息
	virtual void SetDescription(const UGString& strDescription);

//	enum ReferenceType
//	{
//		Plannar = 0,
//      Geography = 1,
//	    Project = 2,
//  };

protected:
	UGString m_strName;			// 坐标系名称
	UGString m_strDescription;	// 坐标系描述

	EmSpatialRefType m_eType;	 //坐标系标志号，
					 // 用以区分平面坐标系、地理坐标系、投影坐标系
	                 // 对这个属性的设置存有一定的疑问。
	
	//UGint   m_nTypeID;//坐标系类型号，用以唯一标志这个坐标系	
	
	//UGUnit m_Unit;	 
	UGint m_nUnit;      // 坐标系单位
	UGint m_nDistUnit;  // 坐标系距离单位，只能为长度单位

};


}//namespace UGC



#endif // !defined(UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_)
