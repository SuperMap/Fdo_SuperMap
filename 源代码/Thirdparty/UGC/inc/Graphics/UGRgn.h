// UGRgn.h: interface for the UGRgn class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGRgn.h   
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    裁剪多边形类                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGRGN_H__0CE6353D_7685_473C_940D_381AE7E4FE1D__INCLUDED_)
#define AFX_UGRGN_H__0CE6353D_7685_473C_940D_381AE7E4FE1D__INCLUDED_

#include "Algorithm/UGRect.h"

namespace UGC
{

class GRAPHICS_API UGRgn  
{
public:
	struct UGRegionData
	{
		UGuint nCount;   //! \brief 区域的子多边形的个数
		UGuint nRgnSize; //! \brief 区域的总共大小
		UGRect rcBound;  //! \brief 区域的外接矩形
		UGbyte* pRect;	 //! \brief 区域的内容	
		UGRegionData()
		{
			nCount = 0;
			nRgnSize = 0;
			rcBound = UGRect(0,0,0,0);
			pRect = NULL;
		}
		virtual ~UGRegionData()
		{
			if(pRect != NULL)
			{
				delete pRect;
				pRect = NULL;
			}
		}
	};

	enum RgnCombineMode				// 配合Combine成员函数的选项,处理Region操作
	{					
		UGRGN_AND = 1,			// 逻辑与操作
		UGRGN_OR = 2,			// 逻辑或操作
		UGRGN_XOR = 3,			// 逻辑异或操作		
		UGRGN_DIFF = 4,			// 
		UGRGN_COPY = 5			// 与Copy选择一个.
	};

protected:
	// 创建矩形的区域
	UGRgn();
public:
	// destructor
	virtual ~UGRgn();

	//! \brief 区域之间的复制
	//! \param Rgn 要被复制的区域
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool Copy(const UGRgn& Rgn) = 0;
    //! \brief 创建一个矩形区域
    //! \param x1 矩形的左上角X坐标
    //! \param y1 矩形的左上角Y坐标
	//! \param x2 矩形的右下角X坐标
    //! \param y2 矩形的右下角Y坐标
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreateRect(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
	//! \brief 创建一个矩形区域
    //! \param rect 依据的矩形对象
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreateRect(UGRect &rect) = 0;
	//! \brief 创建一个椭圆形
    //! \param x1 依据的矩形的左上角X坐标
    //! \param y1 依据的矩形的左上角Y坐标
	//! \param x2 依据的矩形的右下角X坐标
    //! \param y2 依据的矩形的右下角Y坐标
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreateElliptic(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
    //! \brief 创建一个椭圆形区域
    //! \param rect 依据的矩形对象
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreateElliptic(UGRect &rect) = 0;
	//! \brief 创建一个椭圆形区域
	//! \param x1 依据的矩形的左上角X坐标
    //! \param y1 依据的矩形的左上角Y坐标
	//! \param x2 依据的矩形的右下角X坐标
    //! \param y2 依据的矩形的右下角Y坐标
	//! \param x3 椭圆圆角的X轴宽度
    //! \param y3 椭圆圆角的Y轴宽度
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreateRoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3) = 0;
	//! \brief 创建一个椭圆形区域
    //! \param rect 依据的矩形对象
	//! \param point 椭圆圆角的XY轴宽度
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreateRoundRect(UGRect &rect, UGPoint point) = 0;
    //! \brief 创建一个多边形区域
    //! \param pPoints 多边形的点列指针
	//! \param point 有多少个点
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreatePolygon(const UGPoint* pPoints, UGint nCount) = 0;
	//! \brief 创建多个多边形区域
    //! \param pPoints 多边形的点列指针
	//! \param pPolyCounts 每个多边形的点数
	//! \param nCount 多边形的个数
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool CreatePolyPolygon(const UGPoint* pPoints, const UGint* pPolyCounts, UGint nCount) = 0;

	//! \brief 删除Rgn
	virtual void DeleteObject() = 0;

	//! \brief 区域的之间结合
    //! \param Rgn1 区域1
	//! \param Rgn2 区域2
	//! \param nCombineMode 结合类型
	virtual UGbool Combine(const UGRgn& Rgn1, const UGRgn& Rgn2, UGint nCombineMode) = 0;

	//! \brief 获取区域的边框
	//! \return 返回区域的边框，一个矩形
	virtual UGRect GetBox() const = 0;

	//! \brief 移动区域
	//! \param x 沿X轴移动的长度
	//! \param y 沿Y轴移动的长度
	virtual void Offset(UGint x, UGint y) = 0;
	//! \brief 移动区域
	//! \param point 移动的向量
	virtual void Offset(const UGPoint& point) = 0;
	
	//! \brief 判断两个区域是否相等
    //! \param Rgn 拿来比较的矩形
	virtual UGbool IsEqual(const UGRgn& Rgn) const = 0;
	
	//! \brief 判断点否在区域中
	//! \param x 被判断的点的X坐标
	//! \param y 被判断的点的Y坐标
	virtual UGbool PtInRegion(UGint x, UGint y) const = 0;
	//! \brief 判断点否在区域中
	//! \param point 被判断的点的坐标
	virtual UGbool PtInRegion(const UGPoint &point) const = 0;
    //! \brief 判断矩形是否在区域中
	//! \param x1 被判断的矩形的左上角X坐标
    //! \param y1 被判断的矩形的左上角Y坐标
	//! \param x2 被判断的矩形的右下角X坐标
    //! \param y2 被判断的矩形的右下角Y坐标
	virtual UGbool RectInRegion(UGint x1, UGint y1, UGint x2, UGint y2) const = 0;
	//! \brief 判断矩形是否在区域中
	//! \param rect 被判断的矩形
	virtual UGbool RectInRegion(const UGRect &rect) const = 0;
	//! \brief 获取区域的数据
	//! \param RgnData 保存区域数据的变量
	virtual UGbool GetRegionData(UGRegionData &RgnData) const = 0;

	//! \brief 获取实际对象
	void* GetNative() const;
	//! \brief 设置实际对象
	//! \param pNative 被设置的对象
	void SetNative(void* pNative);
	// 获取显示引擎类型
	virtual UGint GetGraphicsType();
	
protected:
	
	void *m_pNative;
	UGint m_nGraphicsType;	
};

}
#endif // !defined(AFX_UGRGN_H__0CE6353D_7685_473C_940D_381AE7E4FE1D__INCLUDED_)
