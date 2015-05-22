//========================================================================//
// 项目名：			SuperMap Universal GIS class (UGC) Library 0.9
// 作  者：			张立立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//------------------------------------------------------------------------//
//版权声明:         版权所有 1996-2003 北京超图地理信息技术有限公司，保留所有权利 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// 重要声明：		1. 
//					2. 
//					
//------------------------------------------------------------------------//
// 文件名：			SmPrjCoordSys.h
// 类  名：			UGPrjCoordSys
// 父  类：			
// 子  类：			

// 功能说明：		投影坐标系定义
// 调用说明：		
/*-------------------------------------版本更新---------------------------
V 0.92
作    者：输入作者（或修改者）名字
完成日期：2002年10月20日
更新说明：

V 0.91
作    者：输入作者（或修改者）名字
完成日期：2001年7月20日
更新说明：

V 0.9 
原作者  ：张立立
完成日期：
========================================================================*/
#if !defined(UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_)
#define UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_

#include "Base/UGThread.h"
#include "Base/UGString.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"
#include "UGGeoCoordSys.h"
#include "UGPrjParams.h"
#include "UGProjection.h"

namespace UGC{


class PROJECT_API UGPrjCoordSys : public UGSpatialRef
{
	friend class UGPrjFactory;
public:
	//! \brief 默认构造函数
	UGPrjCoordSys();
	//! \brief 通过投影坐标系类型构造投影坐标系对象
	UGPrjCoordSys(EmPrjCoordSysType nTypeID );
	//! \brief 拷贝构造函数
	UGPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);
	//! \brief 通过地理坐标系、投影方式、投影参数构造投影坐标系对象
	/**
	\param GeoCoordSys 地理坐标系对象[in]
	\param Projection 投影方式对象[in]
	\param PrjParams 投影参数[in]
	*/
	UGPrjCoordSys(const UGGeoCoordSys& GeoCoordSys,
				   const UGProjection& Projection,
				   const UGPrjParams& PrjParams
				  // Utility::UGString strName = ""
				  );


	UGPrjCoordSys& operator = (const UGPrjCoordSys& PrjCoordSys);
	// 下面两个函数会 hide 基类的同名(不同参数) 的函数
	UGbool operator == (const UGSpatialRef& PrjCoordSys) const;
	UGbool operator != (const UGSpatialRef& PrjCoordSys) const;

	//! \brief 保存至文件 尚未实现
	UGbool SaveToArray(const UGString& strFileName);
	//! \brief 从文件读取 尚未实现
	UGbool LoadFromArray(const UGString& strFileName); 	
	
	//! \brief 设置投影坐标系类型
	//! \brief 设置类型后，将会根据类型重构投影坐标系对象
	UGbool SetTypeID(EmPrjCoordSysType nTypeID);
	
	//! \brief 获取投影坐标系类型
	EmPrjCoordSysType GetTypeID() const;
	//! \brief 获取投影参数对象
	const UGPrjParams &GetPrjParams() const;
	//! \brief 获取地理坐标西对象
	const UGGeoCoordSys& GetGeoCoordSys() const;	
	//! \brief 获取投影方式对象
	const UGProjection &GetProjection() const;
//	UGString GetName() const;

	//! \brief 设置投影参数对象
	UGbool SetPrjParams(const UGPrjParams& PrjParams);
	//! \brief 设置地理坐标系对象
	UGbool SetGeoCoordSys(const UGGeoCoordSys& GeoCoordSys);	
	//! \brief 设置投影方式对象
	UGbool SetProjection(const UGProjection& Projection );
		
	//! \brief 获取参数个数
	UGint GetParamsCount();
	//! \brief 通过索引获取参数名称
	UGString GetParamName(UGint nIndex);
	//! \brief 通过索引获取参数值
	UGdouble GetParamValue(UGint nIndex);
	//! \brief 通过名称获取参数值
	UGdouble GetParamValue(const UGString& strName);
	//! \brief 通过索引设置参数值
	UGbool SetParamValue(UGint nIndex,UGdouble dValue);
	//! \brief 通过名称设置参数值
	UGbool SetParamValue(const UGString& strName,UGdouble dValue);
	
	//! \brief 正变换就是从经纬度变换至投影；逆变化则是从投影到经纬度
	UGbool Forward(UGPoint2D* pPoints, UGint nCount);
	UGbool Inverse(UGPoint2D* pPoints, UGint nCount);

	// 三维点转换只是对其中的x,y坐标作了投影变换处理，z值并不参与计算
	// 在RefTranslator中，z值表示高程，在地理坐标系不同的情况下，是参与计算的
	// 这一点需要多加小心
	UGbool Forward(UGPoint3D* pPoints, UGint nCount); 
	UGbool Inverse(UGPoint3D* pPoints, UGint nCount);


	UGString ToXML(UGint nVersion = 0)const;
	UGbool FromXML(const UGString& strPrjXml,UGint nVersion = 0);

//	UGString ToXMLEx(UGint nVersion = 0)const;

	//! \brief 从配置文件读取投影坐标系信息 dongfei 2007-04-04	
	UGbool FromConfigure( EmPrjCoordSysType nTypeID,UGint nVersion = 0);
	
	//! \brief 从数据流读取投影坐标系对象
	UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief 将投影坐标系对象输出到数据流
	UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream
	
	//! \brief 设置平面坐标系单位，同时将投影坐标系类型设置为平面坐标系
	UGbool SetPlanar(UGint nUnits );		//平面坐标系
	//! \brief 设置地理坐标系 同时设置投影坐标系类型为地理坐标系
	UGbool SetEarth( UGGeoCoordSys& geogCs);//地理坐标系
	
	//! \brief 获取投影坐标系单位
	virtual UGint GetUnit() const;
	//! \brief 获取投影坐标系量算单位
	virtual UGint GetDistUnit() const;
	//! \brief 设置投影坐标系单位
	virtual void SetUnit(UGint nUnit);
	//! \brief 设置投影坐标系量算单位
	virtual void SetDistUnit(UGint nUnit);
	
	virtual ~UGPrjCoordSys();

protected:
	EmPrjCoordSysType m_eTypeID;

	UGGeoCoordSys m_GeoCoordSys;
	UGPrjParams m_PrjParams;
	UGProjection m_Projection;
	UGMutex		m_mutex;

static UGString ms_PrjParamNames[];	
};

}//namespace UGC


#endif // !defined(UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_)
