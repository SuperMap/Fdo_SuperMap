/*! \file	 UGGeoRegion.h
 *  \brief	 面几何对象
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoRegion.h,v 1.49 2007/12/24 10:22:18 qiuli Exp $
 *  \version $Id: UGGeoRegion.h,v 1.49 2007/12/24 10:22:18 qiuli Exp $
*/


#ifndef UGGEOREGION_H
#define UGGEOREGION_H

#include "UGGeometry.h"

namespace UGC {

//! \brief 面几何对象
class GEOMETRY_API UGGeoRegion  : public UGGeometry
{
public:
	//! \brief 构造函数
	UGGeoRegion();
	
	//! \brief 析构函数
	virtual ~UGGeoRegion();
	
public: //pure virtual 
	
	//! \brief 清空几何数据
	virtual void Clear();
	
	//! \brief 得到维数, Region固定为2维
	//! \return 返回维数,固定为2
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型, 固定为GeoRegion
	//! \return 返回类型, 固定为GeoRegion
	virtual Type GetType() const;
	
	//! \brief 得到内点
	//! \remarks 内部采用UGOpRegions::InnerPoint实现
	//! \return 返回内点
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief 得到对象长度
	//! \attention Dimension为1or2的对象才支持
	//! \return 返回长度
	virtual UGdouble GetLength() const;
	
	//! \brief 计算得到面积
	//! \return 返回面积
	virtual UGdouble GetArea() const;

	//! \brief 计算得到在某个投影系统下的地理面积(非几何面积)
	//! \param pPJCoordSys 投影坐标系
	//! \return 返回在投影坐标系下的地理面积
	UGdouble GetArea(UGPrjCoordSys* pPJCoordSys);
	
	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;	
	
	//! \brief 得到空间数据, 主要用于需要按照维度相同时
	//! 来做统一处理的时候, 例如一些空间判断和操作的算法
	//! \param pPoints 传出的点坐标数组[out]。
	//! \param pPolyCount 传出的每个子对象点个数的数组[out]。
	//! \param nSubCount 传出的子对象个数[out]。
	//! \param nSegmentCount 对参数化对象, 每个弧段分割点的个数[in]。
	//! \remarks 参数采用了智能指针的技术,调用者不用释放内存空间
	//! \return 成功返回true,否则返回false。
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief 得到子对象的个数
	//! \return 返回子对象的个数
	virtual UGint GetSubCount() const;
	
	//! \brief 几何对象是否有效
	//! \return 有效返回true,无效返回false
	virtual UGbool IsValid()const;
	
	//! \brief 缩放
	//! \param dRatioX X方向缩放比率
	//! \param dRatioY Y方向缩放比率
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief 缩放
	//! \param dRatio 缩放比率(X,Y方向相同)
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief 平移
	//! \param dX 平移的X偏移量
	//! \param dY 平移的Y偏移量
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief 平移
	//! \param 偏移量(X,Y方向相同)
	virtual void Offset( UGdouble dOffset);
	
	//! \brief 平移
	//! \param 平移的偏移量(分别用UGSize2D中的x,y代表X,Y方向的偏移量)
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief 旋转
	//! \param pntOrigin 旋转的中心点(锚点,不动点)
	//! \param dAngle 旋转角度
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief 旋转,增加一些参数,以便内部可以不用进行cos,sin, 在批量处理的时候有利于提高效率
	//! \remarks dAngle看似多余,但GeoText需要,所以要保留
	//! \param pntOrigin 旋转的中心点(锚点,不动点)
	//! \param dCosAngle 旋转的cos值
	//! \param dSinAngle 旋转的sin值
	//! \param dAngle 旋转角度
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
	//! \return 成功返回true,失败返回false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 
	
public:
	//! \brief 根据投影转化器的设置和转化方向要求, 进行投影转化
	//! \param pPJTranslator 投影转化器
	//! \param bForward 转化方向, true代表从UGRefTranslator的源(Src)转化到目的(Des), false则相反
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief 从经纬坐标系统转化为投影坐标系统
	//! \param pCoordSys 投影坐标系统
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief 从投影坐标系统转化为经纬坐标
	//! \param pCoordSys 投影坐标系统
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:
	//! \brief 创建简单线对象
	//! \param pPoints [in] 点串指针。
	//! \param nPntCount [in] 点串的点数目。
	//! \remarks 形成一个子对象，传入的点的个数至少要3个; 如果没有闭合，函数内部会自动闭合
	//! \return 点数小于3个,返回false。
	UGbool Make(const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief 创建复杂线对象
	//! \param pPoints [in] 点串指针。
	//! \param pPolyCount [in] 子对象中点数的数组。
	//! \param nSubCount [in] 子对象数目。
	//! \return 所有子对象的点数都小于3个,返回false。
	UGbool Make(const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount);
	
	//! \brief 拷贝构造GeoRegion
	//! \param geoRegion [in] 已有面对象。
	//! \return 已有面对象非法, 返回false。
	UGbool Make(const UGGeoRegion& geoRegion);
	
	//! \brief 通过矩形构造面对象。
	//! \param rect [in] 矩形。
	//! \param 0 [in] 矩形的边插入点的个数,一般用默认值0即可。
	//! \return 矩形为空,返回false。
	UGbool Make(const UGRect2D& rect, UGint nSegmentCount = 0);	
	
	//! \brief 增加子对象
	//! \param pPoints [in] 点串指针。
	//! \param nPntCount [in] 点串个数。
	//! \return 点的个数少于3个,返回false。
	UGbool AddSub(const UGPoint2D* pPoints, UGint nPntCount);	
	
	//! \brief 插入子对象。
	//! \param nIndex [in] 要插入的位置索引。
	//! \param pPoints [in] 点串指针。
	//! \param nPntCount [in] 点串中点的个数。
	//! \return 点个数小于3或者索引位置非法,返回false。
	UGbool InsertSub(UGint nIndex, const UGPoint2D* pPoints, UGint nPntCount);	
	
	//! \brief 删除子对象。
	//! \param nIndex [in] 要删除的子对象的位置索引。
	//! \return 索引非法, 返回false。
	UGbool DelSub(UGint nIndex);
	
	//! \brief 得到某个子对象, 并构造得到GeoRegion。
	//! \param nSubIndex [in] 子对象索引。
	//! \param pGeoRegion [out] 通过该子对象构造得到的GeoRegion; 如果pGeoRegion为NULL,函数内部会new出来。
	//! \return 索引非法, 返回false。
	UGbool GetSub(UGint nSubIndex, UGGeoRegion *&pGeoRegion);
	
	//! \brief 得到子对象数目的数组指针。
	//! \return 返回子对象数目的数组指针。
	const UGint* GetPolyCounts() const;
	
	//! \brief 得到某个子对象的点的个数。
	//! \param nSubIndex [in] 子对象索引。
	//! \return 返回某个子对象的点的个数。
	UGint GetSubPntCount(UGint nSubIndex) const;
	
	//! \brief 得到所有子对象的点的个数总和。
	//! \return 返回所有子对象的点的个数总和。
	UGint GetPointCount() const;
	
	//! \brief 得到指定子对象的点串的指针。
	//! \param nSubIndex [in] 子对象索引。
	//! \return 返回子对象的点串的指针。
	const UGPoint2D* GetPoints(UGint nSubIndex=0) const;
	
public:
	//! \brief 判断点是否在面内
	//! \param &point [in] 要判断的点。
	//! \param bBorder [in] 判断时是否包括边界。
	//! \return 点在面内(bBorder为true时,在边界也算)时,返回true;否则返回false。
	UGbool PtInRegion(const UGPoint2D &point, UGbool bBorder = true);	

	//! \brief 存储到Stream中
	//! \remarks 参考UGGeometry的说明
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;

	//! \brief 从Stream中生成Geometry
	//! \remarks 参考UGGeometry的说明
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
	//! \brief 转化为线对象
	//! \param geoLine[out] 得到的线对象
	//! \param nSegmentCount 当曲线转化为线时,每一段用多少个点来模拟; 本函数中不起作用
	//! \return 成功返回true,失败返回false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief 转化为面对象
	//! \param geoRegion[out] 得到的面对象
	//! \param nSegmentCount 当曲面转化为面时,每一段用多少个点来模拟; 本函数中不起作用
	//! \return 成功返回true,失败返回false
	//! \remarks 返回本身
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;
	
	//! \brief 判断面之间岛洞关系的函数
	//! \attention 如果不是和GeoRegion紧密绑定, 建议放到 UGOpRegions等类中, GeoRegion中使用就可以了.
	void CheckPolygon(const UGPoint2D *pPoints, const UGint *plPolyCounts, UGint nSubCount, UGint *plPolyArea) const;
	
	//! \brief 判断子多边形的走向
	//! \param nIndex 子对象索引
	//! \remarks 返回-1，多边形异常，返回0 顺时针；返回1 逆时针；
	UGint IsCounterClockwise(UGint nIndex);

	//! \brief 逆序某个子对象中点的顺序
	//! \param nSubIndex [in] 要逆序的子对象索引。
	//! \return 索引非法,返回false。
	UGbool Reverse(UGint nSubIndex);	

#if PACKAGE_TYPE==PACKAGE_UGC
public:		
			
	//! \brief 生成XML格式的信息
	//! \param versionType GML的版本
	//! \param nPace 缩进的空格数目,使得xml字符串更加易于人工阅读; 
	//! 主要用于如果返回的xml字符串是一个大标签中的一部分, 通过指定空格数目,可以使层次清晰
	//! \return 返回指定GML版本的xml字符串
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;
	
	//! \brief 从XML字符串中生成Geometry
	//! \param strXML xml格式字符串
	//! \param versionType xml字符串的GML版本
	//! \return 返回指定GML版本的xml字符串
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);
		
	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

#endif // end declare ugc sdk
public:
	//added by xielin ^_^ 编辑相关函数,把编辑和geometry统一
	
	//! \brief 获得编辑对象的句柄的数目
	//! \remarks 对于固定句柄对象为9包括了改变大小的8个控制点和一个旋转控制点
     virtual UGint  GetHandleCount();

	
	//nHandle:的值与控制点的关系如右图                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
    //										|   ____________    |     |
    //										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8
	
	//! \brief 根据句柄获得相应控制点的值
	//! \param nHandle 控制点句柄
	//! \param point 句柄对应的控制点的坐标值
	//! \return 返回辅助点的类型
	 virtual UGint GetHandle( UGint nHandle, UGPoint2D& point);


	//! \brief 移动控制点到指定坐标,主要用于绘制对象，修改对象节点等操作
	//! \param nHandle 控制点句柄
	//! \param point 控制点坐标
	virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief 节点编辑时可用来插入一个控制点,也可以用于绘制对象时加入节点
	//! \param nHandle 插入位置
	//! \param pnt2D 插入点的地理坐标
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief 删除编辑对象的指定节点
	//! \param nHandle 节点句柄
    virtual UGuint DelNode( UGint nHandle );

	//! \brief 计算对象绘制时的辅助线，返回的是一个复合对象
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param nEditType 绘制对象的类型，参考UGEditType
	//! \param pStyle	 辅助线的风格，如果传入为NULL，用默认的风格
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	//! \brief 根据传入的点串生成对象，主要用于编辑中的参数化等没有内部数组保存点串的对象，
	//也用于自定义对象,对于有内部数组保存点串的对象，该函数直接return既可，比如GeoLine
	//GeoLine等对象就直接用AddHandle来生成，效率比较高 
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
    virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	 //! \brief 获取对象需要捕捉的点串
	//! \param aryPnts 点串，传出去的要捕捉的点串
	//! \return 如果是true表示有需要捕捉的点串，如果返回false表示该对象没有需要捕捉的点串
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief 获取对象需要捕捉的线段数组
	//! \param aryLines 需要捕捉的线数组（如果有多个part，那么aryLines就应该有多少个count）
	//! \return 如果是true表示有需要捕捉的线，如果返回false表示该对象没有需要捕捉的线
	virtual UGbool GetSnapLines(UGLineArray& aryLines);
	
	//! \brief 合并对象
	//! \param 
	//! \return 
	UGbool Combination(UGGeoRegion *pGeoRegion);


	//added by xielin ^_^ 编辑相关函数,把编辑和geometry统一 end
protected:
	struct BoundsNode 
	{
		UGint  lNumber;
		UGRect2D  rcBounds;
		UGdouble GetArea() { return rcBounds.Width() * rcBounds.Height(); }
		void operator =(BoundsNode node) { lNumber = node.lNumber; rcBounds = node.rcBounds; };
	};
	
	typedef UGArray<BoundsNode*> BoundsNodes;
	
	//! \brief 判断面之间岛洞关系的函数
	//! \attention 如果不是和GeoRegion紧密绑定, 建议放到 UGOpRegions等类中, GeoRegion中使用就可以了.
	void CheckPolyCounts( const UGPoint2D *pPoints, const UGint *plPolyCounts, UGint nSubCount,UGint* plPolyArea ) const; 
	
	//! \brief 判断面之间岛洞关系的函数
	//! \attention 如果不是和GeoRegion紧密绑定, 建议放到 UGOpRegions等类中, GeoRegion中使用就可以了.
	void CheckPolygon( const UGPoint2D *pPoints, const UGint *pPolyCounts1, const UGint *pPolyCounts2, BoundsNodes &Polygons, UGint *pPolyCountsAll, UGint nSubCount ) const;
	
	
private: //! 内部地理数据

	//! \brief 坐标点点串
	UGArray<UGPoint2D> m_Points;

	//! \brief 用来存放 所有子对象的点的个数 信息的整型数组
	UGArray<UGint> m_PolyCounts;
	
protected: //! 子类需要实现的一些不公开函数
	//! \brief 实际计算Bounds
	virtual UGRect2D ComputeBounds() const;
	/*virtual UGRect2D GetBoundsInside() const;
	virtual void SetBoundsInside(const UGRect2D & rcBounds);*/
};

}

#endif
