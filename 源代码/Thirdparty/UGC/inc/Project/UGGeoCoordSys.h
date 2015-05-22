//========================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 0.9
// 作  者：			张立立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以版本更新完成日期为准
//------------------------------------------------------------------------
//版权声明:         版权所有 1996-2003 北京超图地理信息技术有限公司，保留所有权利 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved
// 重要声明：		1. 
//					2. 
//					
//------------------------------------------------------------------------
// 文件名：			SmGeoCoordSys.h
// 类  名：			UGGeoCoordSys
// 父  类：			
// 子  类：			

// 功能说明：		地理坐标系定义
// 调用说明：		共有四个构造函数
//			1		UGGeoCoordSys()//生成一个WGS84地理坐标系
//          2       UGGeoCoordSys(EmGeoCoordSysType nTypeID );构造一个内置地理坐标系
//          3       拷贝构造                       
//          4       生成一个自定义的地理坐标系

//          SetTypeID(EmGeoCoordSysType nTypeID);可以通过设置类型号来设置地理坐标系的
//                                              类型


#if !defined(UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_)
#define UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_

#include "Base/UGThread.h"

#include "UGSpatialRef.h"
#include "UGPrimeMeridian.h"
#include "UGHorizonDatum.h"

namespace UGC{


class PROJECT_API UGGeoCoordSys  : public UGSpatialRef
{
	friend class UGPrjFactory;
public:
	//! \brief 默认构造函数	
	UGGeoCoordSys();//
	//! \brief 根据地理坐标系类型构造地理坐标系	
	UGGeoCoordSys(EmGeoCoordSysType nTypeID );
	//! \brief 拷贝构造函数
	UGGeoCoordSys(const UGGeoCoordSys& GeoCoordSys);
	//! \brief 根据水平参考系、中央经线、坐标单位以及坐标系名称构造地理坐标系	
	/**
	\param HorizonDatum    水平参考系[in]
	\param PrimeMeridian           中央经线[in]
	\param nUnit            坐标单位，不是坐标量算单位[in]
	\param strName         坐标系名称[in]
	*/
	UGGeoCoordSys(UGHorizonDatum& HorizonDatum,
				   UGPrimeMeridian& PrimeMeridian,
				   UGint nUnit,
				   UGString strName = "");

	UGGeoCoordSys& operator = (const UGGeoCoordSys& GeoCoordSys);
	// 下面两个函数会 hide 基类的同名(不同参数) 的函数
	UGbool operator == (const UGSpatialRef& GeoCoordSys) const;
	UGbool operator != (const UGSpatialRef& GeoCoordSys) const;

	//! \brief 保存到文件 尚未实现
	UGbool SaveToArray(const UGString& strFileName);
	//! \brief 从文件读取 尚未实现
	UGbool LoadFromArray(const UGString& strFileName); 	
	
	virtual ~UGGeoCoordSys();
	
	//! \brief 设置地理坐标系类型
	/**
	\param nTypeID 地理坐标系类型
	\return 类型设置成功返回TRUE 否则返回FALSE
	\remarks 由于地理坐标类型是地理坐标系的唯一标识符 所以类型设置后，所有的参数也相应变化了
	*/
	UGbool SetTypeID(EmGeoCoordSysType nTypeID);	
	//! \brief 返回地理坐标系类型
	EmGeoCoordSysType GetTypeID() const;

//	UGString GetName() const;

	//! \brief 获取水平参考系参数
	/**
	\return 水平参考系
	*/
	const UGHorizonDatum &GetHorizonDatum() const;
	//! \brief 设置水平参考系
	/**
	\param datum 水平参考系 [in]
	\return 设置成功返回TRUE 否则返回FALSE
	*/
	UGbool SetHorizonDatum(const UGHorizonDatum& datum);

	//! \brief 获取中央经线对象
	const UGPrimeMeridian& GetPrimeMeridian() const;
	//! \brief 设置中央经线对象
	/**
	\param primeMeridian 中央经线 [in]
	\return 设置成功返回TRUE 否则返回FALSE
	*/
	UGbool SetPrimeMeridian(const UGPrimeMeridian& primeMeridian);

	//! \ brief 输出为XML字符串
	/**
	\param nVersion 输出为XML的版本 默认为当前版本 [in]
	\return 输出的XML字符串
	*/
	UGString ToXML(UGint nVersion = 0)const;
	
	//! \brief 从XML字符串读取
	/**
	\param strPrjXML 读入的XML字符串[in]
	\param nVersion 读入XML字符串的版本
	\return 读入XML字符串成功返回真 否则返回假
	*/
	UGbool FromXML(const UGString& strPrjXml,UGint nVersion = 0);

	//! \brief dongfei 2007-04-03
	/* 更改xml结构，投影坐标系中只存投影方式、地理坐标系的类型，不存其实际数据
	 * 水平参考系、子午线在地理坐标系中也是同样方式 主要是为了导出所有的投影坐标系数据
	 * 可能以后用不着
	 */
//	UGString ToXMLEx(UGint nVersion = 0)const;
	
	//! \brief 从配置文件读取地理坐标系信息 dongfei 2007-04-04	
	UGbool FromConfigure(EmGeoCoordSysType nTypeID,UGint nVersion = 0);

	//! \brief 根据数据流创建地理坐标系
	UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief 输出地理坐标系到数据流
	UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream

	
protected:
	UGHorizonDatum  m_HorizonDatum; //大地水平参照系
	UGPrimeMeridian m_PrimeMeridian;//本初子午线

//	UGString m_strName;
	EmGeoCoordSysType   m_eTypeID;
	UGMutex				m_mutex;
	
};

}//namespace UGC



#endif // !defined(UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_)
