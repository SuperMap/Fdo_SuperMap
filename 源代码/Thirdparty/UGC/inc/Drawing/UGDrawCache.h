// UGDrawCache.h: interface for the UGDrawCache class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawCache.h
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    显示缓存类。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWCACHE_H__0B86E90F_8CA8_44B4_AC42_105FDCA8E9BE__INCLUDED_)
#define AFX_UGDRAWCACHE_H__0B86E90F_8CA8_44B4_AC42_105FDCA8E9BE__INCLUDED_

#include "Graphics/UGGraphics.h"

namespace UGC {

class UGDrawParamaters;

class DRAWING_API UGDrawCache  
{
public:
	//! \brief 构造函数
	UGDrawCache();
	//! \brief 析构函数
	virtual ~UGDrawCache();

public:
	//! \brief 判断是否已经缩放
	//! \return 是否已经缩放
	UGbool IsUsingPreZoom() const;
	//! \brief 设置是否已经缩放
	//! \param bUsingPreZoom 是否已经缩放
	void SetUsingPreZoom(UGbool bUsingPreZoom);
	//! \brief 判断是否已经优化
	//! \return 是否已经优化
	UGbool IsOptimizedDraw() const;
	//! \brief 设置是否已经优化
	//! \param bUsingPreZoom 是否已经优化
	void SetOptimizedDraw(UGbool bOptimizedDraw);
	//! \brief 判断是否需要更新
	//! \return 是否已经更新
	UGbool IsRefreshRequired() const;
     //! \brief 设置是否需要更新
	//! \param bUsingPreZoom 是否有更新要求
	void SetRefreshRequired(UGbool bRefreshRequired);
   //! \brief  获取当前图形显示基类
	//! \return 显示基类
	UGGraphics* GetGraphics();
	//! \brief 设置显示参数
	//! \param pGraphics 要设置当前图形显示基类
	//! \param pDrawParam 要设置的画笔参数
	//! \return 设置是否成功
	UGbool Prepare(UGGraphics *pGraphics, UGDrawParamaters *pDrawParam);
	//! \brief 释放当前对象
	void Release();
	//! \brief 判断是否已经准备好
	//! \return 是否已经准备好
	UGbool IsPrepared();	
	//! \brief 实际坐标转换到逻辑坐标
	//! \param szSize 要转换的实际坐标,返回转换后的逻辑坐标
	void DPtoLP(UGSize &szSize);
	//! \brief 实际坐标转换到逻辑坐标
	//! \param rcRect 要转换的矩形,返回转换后的逻辑坐标的矩形
	void DPtoLP(UGRect &rcRect);
	//! \brief 逻辑坐标转换到实际坐标
	//! \param pPoints 要转换的坐标列指针,返回转换后的实际坐标
	//! \param nCount 坐标个数
	void DPtoLP(UGPoint *pPoints, UGint nCount = 1);
	//! \brief 逻辑坐标转换到实际坐标
	//! \param szSize 要转换的逻辑坐标,返回转换后的逻辑坐标
	
	void LPtoDP(UGSize &szSize);
	//! \brief 逻辑坐标转换到实际坐标
	//! \param rcRect 要转换的矩形,返回转换后的实际坐标的矩形
	void LPtoDP(UGRect &rcRect);
	//! \brief 逻辑坐标转换到实际坐标
	//! \param pPoints 要转换的坐标列指针,返回转换后的实际坐标
	//! \param nCount 坐标个数
	void LPtoDP(UGPoint *pPoints, UGint nCount = 1);

protected:
	UGImage* m_pImage;			//显示缓存
	UGImage * m_pOldImage;	
	UGGraphics* m_pGraphics;
	UGint m_nHeight;
	UGint m_nWidth;

	UGbool m_bIsUsingPreZoom;
	UGbool m_bOptimizedDraw;
	UGbool m_bRefreshRequired;
	UGbool m_bPrepared;
};

}

#endif // !defined(AFX_UGDRAWCACHE_H__0B86E90F_8CA8_44B4_AC42_105FDCA8E9BE__INCLUDED_)
