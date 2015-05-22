/*! \file	 UGGeoFactory.h
 *  \brief	 用来创建Geometry的工厂类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoFactory.h,v 1.11 2007/11/09 00:52:16 lugw Exp $
 */


#if !defined(AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_)
#define AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_

#include "Base/ugdefs.h"
#include "UGGeometry.h"

namespace UGC{

//added by xielin 2007-04-30 
//! \brief 回调函数，用于扩展对象绘制
//! \param 		pGeometry		外部要创建的扩展对象
//! \param 		eGeoType		扩展对象的类型
//! \param 		pWnd			实现该回调函数对象的指针
typedef void (UGSTDCALL *CREATECUSTOMGEOMETRYCALLBACKPROC)
(UGGeometry** pGeometry,UGint eGeoType,UGlong pWnd);


//! \brief 用来创建Geometry的工厂类
class GEOMETRY_API UGGeoFactory
{
private: // 不允许用工厂类的对象，请按照UGGeoFactory::Fun()等形式直接使用静态函数
	UGGeoFactory();

public:
	//! \brief 传入Geometry类型，生成Geometry
	//! \param eGeoType 要创建的Geometry的类型
	//! \attention 返回的Geometry指针, 请使用后delete
	//! \return 成功,返回创建的Geometry的指针; 失败返回NULL
	static UGGeometry* CreateGeometry(UGGeometry::Type eGeoType);

	//! \brief 传入类型和数据，生成构造好的Geometry
	//! \param eGeoType 要创建的Geometry的类型
	//! \param pData 数据区指针
	//! \param nSize 数据区大小(字节)
	//! \attention 返回的Geometry指针, 请使用后delete
	//! \return 成功,返回创建的Geometry的指针; 失败返回NULL
	static UGGeometry* CreateGeometry(UGGeometry::Type eGeoType, 
								const UGbyte* pData, UGint nSize);
	//! \brief 克隆Geometry
	//! \param pGeometry 要被克隆的Geometry对象指针, 不能为NULL
	//! \attention 返回的Geometry指针, 请使用后delete
	//! \return 成功,返回创建的Geometry的指针; 失败返回NULL
	static UGGeometry* CloneGeometry(const UGGeometry* pGeometry);

	//! \brief 传入类型名，返回UGGeometry::Type
	//! \param strGeometryType 几何对象类型的名字
	//! \attention 严格区分大小写, 请参照"GeoPoint"的形式
	//! \return 成功返回几何对象类型枚举, 失败返回UGGeometry::Null
	static UGGeometry::Type GetGeometryType(const UGString& strGeometryType);
	
	//! \brief 拷贝Geometry
	//! \param pGeometrySrc 原Geometry指针, 不得为NULL
	//! \param pGeometryTag 目标Geometry指针, 不得为NULL
	//! \remarks 两个Geometry参数类型必须一致
	//! \return 成功返回true,失败返回false
	static UGbool CopyGeometry(const UGGeometry* pGeometrySrc, UGGeometry* pGeometryTag);

	//! \brief 确保pGeometry是指定的类型
	//! \param pGeometry 几何对象指针
	//! \param eType 指定的类型
	//! \remarks 本函数主要用在: 从外面传入一个几何对象类型, 但有可能为NULL, 也有可能不是需要的类型
	//!			 这时,就需要 重新分配 Geometry指针,new 出需要类型的Geometry来; 主要用在Recordeset的AddNew等地方
	//! \return 如果对象重新分配空间了,返回true; 否则返回false
	static UGbool AssureGeoType(UGGeometry* & pGeometry, UGGeometry::Type eType);

	//added by lugw 2007-11-09
	//! \brief 比较两个geometry是否相同
	//! \param pGeometrySrc 对比指针1
	//! \param pGeometryTag 对比指针2
	//! \return 返回如果相同为true，反之为false
	static UGbool CompareGeometry(const UGGeometry* pGeometrySrc, const UGGeometry* pGeometryTag);

	//added by xielin 2007-04-30 
	static void SetCreateCustomGeometryFunc(CREATECUSTOMGEOMETRYCALLBACKPROC pCreateCustomGeometryFunc,
		UGlong pWnd);
	
};



}

#endif // !defined(AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_)
