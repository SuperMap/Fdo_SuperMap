// UGTrackingLayer.h: interface for the UGTrackingLayer class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGTrackingLayer.h
   **************************************************************************************
    \author   陈国雄
    \brief    跟踪图层类，是一个内存图层，总是在其他图层的最上面，用于临时对象的显示。                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)
#define AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_

#include "UGGeoEvent.h"
#include "Base/UGList.h"
#include "Drawing/UGDrawing.h"

namespace UGC {

class MAP_API UGTrackingLayer  
{
public:
	UGTrackingLayer();
	virtual ~UGTrackingLayer();

public:
	//! \brief  点击事件
	UGint HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance);

	//! \brief  是否可见
	UGbool IsVisible()const;
	//! \brief  设置是否可见
	void SetVisible(UGbool bVisible = true);

	//! \brief  是否可选择
	UGbool IsSelectable()const;
	//! \brief  设置是否可选择
	void SetSelectable(UGbool bSelectable = false);

	//! \brief  是否可编辑
	UGbool IsEditable()const;
	//! \brief  设置是否可编辑
	void SetEditable(UGbool bEditable = false);

	//! \brief  是否可捕捉
	UGbool IsSnapable()const;
	//! \brief  设置是否可捕捉
	void SetSnapable(UGbool bSnapable = false);

	//! \brief 是否符号随着图层的缩放而缩放
	UGbool IsSymbolScalable()const;
	//! \brief 设置符号是否可缩放
	void SetSymbolScalable(UGbool bSymbolScalable = false);

	//! \brief 是否设置文本叠盖
	UGbool IsAllowTextOverlap()const;
	//! \brief 设置文本叠盖
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = true);

	//! \brief 查找对应标签的跟踪层对象
	/**
	\return  对应标签的索引
	*/
	UGint Find(const UGString &strTag, UGint nFromIndex = 0) const;
	//! \brief 查找对应几何对象的跟踪层对象
	/**
	\return  对应几何对象的索引
	*/
	UGint Find(const UGGeometry* pGeometry, UGint nFromIndex = 0);

	//! \brief 移除指定标签的对象
	UGbool Remove(const UGString &strTag, UGint nFromIndex = 0);
	//! \brief 移除指定索引的对象
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief 增加几何对象到跟踪层
	UGGeoEvent* Add(const UGGeometry* pGeometry, const UGString &strTag);
	//! \brief 得到指定索引的跟踪层对象
	UGGeoEvent* GetAt(UGint nIndex) const;
	//! \brief 移除跟踪层所有对象
	void RemoveAll();
	//! \brief 获取对象个数
	UGint GetCount()const;

	//! \brief 设置指定索引对象的标签
	void SetTagAt(UGint nIndex, const UGString &strTag);

	//! \brief 绘制跟踪层
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing);

	//! \brief 设置指定的字符编码
	void SetCharset(UGTextCodec::Charset nCharset);
	//! \brief 得到指定的字符编码
	UGTextCodec::Charset GetCharset()const;

	//! \brief 得到最大符号大小
	UGdouble GetMaxMarkerSize() const;
	//! \brief 得到有效区域
	UGRect2D GetInvalidRect() const;
	//! \brief 设置有效区域
	void SetInvalidRect(const UGRect2D& rcInvalid);

	UGdouble GetSymScaleDefinition() const;
	void SetSymScaleDefinition(UGdouble dSymScaleDefinition);

	UGdouble CalculateSymbolScale(UGdouble dScale) const;
	void SetDrawing(UGDrawing* pDrawing);
	
	//! \brief 获取填充原点的模式
	UGint GetFillOrgMode() const;					
	//! \brief 设置填充原点模式
	void SetFillOrgMode(UGint nFillOrgMode);		
	UGbool BuildSpatialIndex(UGSpatialIndexInfo  &spatial);

	//! \brief 开始事务
	UGbool BeginTrans() ;
	
	//! \brief 提交事务
	void Commit() ;
	
	//! \brief 撤消事务
	void Rollback();
	
	//! \brief 判断事务是否开始 
	UGbool IsTransStarted() ;
	
	//added by xielin 2007-10-17 用于优化跟踪层的显示速度
	//! \brief 显示的时候是否按照对象类型排序显示，默认按照对象类型排序显示。这样对大部分的跟踪应用（一个跟踪点一个标注，注意不要弄成复合对象），能提高绘制速度
	void SetOrderByGeometryType(UGbool bOrderByGeometryType=true);
	//! \brief 返回是否按照对象类型排序显示
	UGbool IsOrderByGeometryType();

	//! \brief  是否为线光滑模式
	UGbool IsLineSmoothingMode()const;
	//! \brief  设置线光滑模式
	void SetLineSmoothingMode(UGbool bSmoothingMode = true);			
	//! \brief  是否为文本光滑模式
	UGbool IsTextSmoothingMode()const;									
	//! \brief  设置文本光滑模式
	void SetTextSmoothingMode(UGbool bSmoothingMode = true);		

private:
	//modified by lugw 2007-05-11 此函数改为私有，外部暂不使用
	void SetGeometryAt(UGint nIndex, const UGGeometry* pGeometry);
	//! \brief 创建内存数据源,如果成员数据源不为空，返回true，为空返回false
	UGbool CreateMemoryDs();

protected:
	UGDrawing* m_pDrawing;
	UGRect2D m_rcInvalid;
	UGdouble m_dMaxMarkerSize;//最大的符号的大小。这是逼不得已的，必须随时维护
	UGuint m_unOptions;
	UGList<UGGeoEvent*> m_Events;

	UGDataSource* m_pDs;
	UGDatasetVector* m_pDv;
	UGRecordset* m_pRecordset; 

	UGTextCodec::Charset m_nCharset;
	UGdouble m_dSymScaleDefinition;	//符号缩放比例尺
	UGint m_nFillOrgMode;
	UGbool m_bOrderByGeometryType;
	UGbool m_bLineSmoothingMode;
	UGbool m_bTextSmoothingMode;

	UGMutex m_mutex;
};

}

#endif // !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)
