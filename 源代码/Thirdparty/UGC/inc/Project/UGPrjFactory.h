 //========================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 0.9
// 作  者：			张立立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//------------------------------------------------------------------------
//版权声明:         版权所有 1996-2003 北京超图地理信息技术有限公司，保留所有权利 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// 重要声明：		1. 
//					2. 
//					
//------------------------------------------------------------------------
// 文件名：			SmPrjFactory.h
// 类  名：			UGPrjFactory
// 父  类：			
// 子  类：			

// 功能说明：		标准类型的 投影坐标系、
//							   地理坐标系、
//							   大地参照系、
//							   单位、
//							   椭球体、
//							   中央经线
//                   的制造工厂
//                  
// 调用说明：	1、	重载了CreateObject系列函数,给出ID号和对象类指针，就能得到
//                  需要的那种对象

//                  例如:下列代码得到了一个标准UTM投影坐标系
//					UGPrjCoordSys PrjCoordSys;
//					UGPrjFactory::CreateOjbect(PCS_WGS_1984_UTM_1N,&PrjCoordSys);
//				2、 本类不导出，外面用不了	
/*-------------------------------------版本更新---------------------------
V 0.92
作    者：输入作者（或修改者）名字
完成日期：
更新说明：

V 0.91
作    者：输入作者（或修改者）名字
完成日期：
更新说明：

V 0.9 
原作者  ：张立立
完成日期：
========================================================================*/

#if !defined(AFX_SMPRJFACTORY_H__F6CA93D6_6D2B_47F0_9CD3_5CB0E1C0D27A__INCLUDED_)
#define AFX_SMPRJFACTORY_H__F6CA93D6_6D2B_47F0_9CD3_5CB0E1C0D27A__INCLUDED_


#include "UGPjCon.h"
#include "UGPrjCoordSys.h"
#include "UGTranslateParams.h"
#include "Base/UGMarkup.h"

namespace UGC{

class PROJECT_API UGPrjFactory  
{
public:
	//! \brief默认构造函数
	UGPrjFactory();
	virtual ~UGPrjFactory();

public:
	//! \brief 创建椭球体对象
	static	UGbool CreateObject(EmSpheroidType SpheroidID, UGSpheroid* pSpheroid );
	//! \brief 创建水平参考系对象
	static  UGbool CreateObject(EmHorizonDatumType HorizonDatumID, 
						UGHorizonDatum* pHorizonDatum);
	//! \brief 创建中央经线对象
	static  UGbool CreateObject(EmPrimeMeridianType PrimeMeridianID, 
					UGPrimeMeridian* pPrimeMeridian );
	//! \brief 创建投影坐标系对象
	static  UGbool CreateObject(EmPrjCoordSysType PrjCoordSysID,
					UGPrjCoordSys* pPrjCoordSys);
	//! \brief  创建地理坐标系对象
	static  UGbool CreateObject(EmGeoCoordSysType GeoCoordSysID,
					UGGeoCoordSys* pGeoCoordSys);

//	static  UGbool CreateObject(UGlong UnitID,
//					UGUnit* pUnit);
	//! \brief 创建投影方式对象
	static  UGbool CreateObject(EmPrjObjectType ProjectionID,
					UGProjection* pProjection);
	//! \brief 创建地理坐标系转换对象 尚未实现
	static  UGbool CreateObject(EmGeoCoordSysType GeoCoordSysID1,
		EmGeoCoordSysType GeoCoordSysID2,UGGeoTransParams& GeoTransParams);
	
	//! \brief added by dongfei 2007-04-02
//	static UGbool FromXML();
//	static UGString ToXML(UGint nVersion = 0);
	//! \brief added by dongfei 2007-04-03
//	static UGString ToXMLGeo(UGint nVersion = 0);
//	static UGString ToXMLPrimeMeridian(UGint nVersion = 0);
//	static UGString ToXMLSpheriod(UGint nVersion = 0);
//	static UGString ToXMLHorizonDatum(UGint nVersion = 0);
//	static UGString ToXMLPrjObj(UGint nVersion = 0);
//	static UGString WriteXML(UGint nVersion = 0);
	//! \brief 读取配置文件 added by dongfei 2007-04-04
//	static UGString 

};

//extern  PROJECT_API UGMarkup *  GetMarkup();
}//namespace UGC

#endif // !defined(AFX_SMPRJFACTORY_H__F6CA93D6_6D2B_47F0_9CD3_5CB0E1C0D27A__INCLUDED_)
