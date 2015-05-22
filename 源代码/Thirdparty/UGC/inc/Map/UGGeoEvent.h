// UGGeoEvent.h: interface for the UGGeoEvent class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGeoEvent.h
   **************************************************************************************
    \author   陈国雄
    \brief    跟踪图层事件对象类。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_)
#define AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_

#include "Geometry/UGGeometry.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class MAP_API UGGeoEvent  
{
public:
	UGGeoEvent(UGRecordset* pRecordset );
	virtual ~UGGeoEvent();

public:	
	//! \brief 获取该几何对象
	UGGeometry* GetGeometry()const;
	//! \brief 设置对应几何对象
	/**
	\return 设置几何对象是否成功
	*/
	UGbool SetGeometry(const UGGeometry* pGeometry);
	//! \brief 设置几何对象对应的风格
	void SetStyle(const UGStyle& style);
	//! \brief 释放几何对象
	void ReleaseGeometry();
	//! \brief 几何对象移动到
	void MoveTo(UGdouble dx, UGdouble dy);	
	//! \brief 几何对象移动
	void Move(UGdouble dx, UGdouble dy);	

	//! \brief 得到几何对象的标签
	UGString GetTag()const;
	//! \brief 设置几何对象的标签
	void SetTag(const UGString& strTag);

//	UGPoint2D GetCurPos()const;
//	void SetCurPos(const UGPoint2D& pntCurPos);

public:
	UGRecordset* m_pRecordset; 
	UGint m_nSmid;
	UGString m_strTag;		//! \brief 标签
//	UGPoint2D m_pntCurPos;	//当前位置

};

}

#endif // !defined(AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_)
