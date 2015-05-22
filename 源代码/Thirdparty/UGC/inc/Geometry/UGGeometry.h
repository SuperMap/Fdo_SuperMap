/*! \file	 UGGeometry.h
 *  \brief	 几何对象基类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 */


#ifndef UGGEOMETRY_H
#define UGGEOMETRY_H

#include "Algorithm/UGRect2D.h"

#include "Base/UGStyle.h"
#include "Base/UGAutoPtr.h"

#include "Project/UGPrjCoordSys.h"
#include "Project/UGPrjTranslator.h"
#include "Project/UGRefTranslator.h"
#include "Geometry/UGDataCodec.h"
#include "Geometry/UGEditType.h"

namespace UGC {

class UGGeoLine;
class UGGeoRegion;

//added by xielin ^_^
#define  BOUND_HANDLE                   9      //固定句柄数目
//added by xielin ^_^ end

//! \brief 几何对象基类 
class GEOMETRY_API UGGeometry  
{
public:
	//! \brief 几何对象类型定义
	//! \remarks UGC 2.0版本支持的Geometry类型包括:
	//!  GeoPoint,GeoLine,GeoRegion,GeoText
	//!  GeoMultiPoint,GeoLineM,GeoCompound,
	//!  GeoRect,GeoRectRound,
	//!  GeoCircle,GeoEllipse,GeoPie,GeoArc,GeoEllipticArc,
	//!  GeoCardinal,GeoCurve,GeoBSpline
	//!  其它类型暂不支持
	enum Type
	{
		//! 空类型
		Null				= 0, 
		//! 点类型	
		GeoPoint			= 1, 
		//! 线类型
		GeoLine				= 3, 
		//! 面类型
		GeoRegion			= 5, 
		//! 文本类型
		GeoText				= 7, 
		
		//GeoRect			=11,	//矩形
		//! 矩形和斜矩形统一为带旋转角的矩形
		GeoRect				=12,
		//! 含线性坐标系的线(即带有M值的GeoLine)
		GeoLineM			=35,   

		//! 影像块, 类为UGImgBlock, 
		GeoImageBlock		=81,	
		//! 图标, 暂不提供, 不要开放出去
		GeoIcon				=87,	
	
		//! 复合对象, 该值同时代表Geometry对象类型的上限
		GeoCompound			=1000,	
#if PACKAGE_TYPE==PACKAGE_UGC
		
		//! 复合点
		GeoMultiPoint		= 2, 
			
		// modified by zengzm 2005-09-05 SFC中就没有 正的圆角矩形, type id==13 就是 带旋转角的圆角矩形
		// 为方便起见, 改为 原来的 13 
		//RectRound			=13,	//圆角矩形
		//GeoRectRound		=14,	//圆角矩形和斜圆角矩形统一为带旋转角的圆角矩形
		//! 带旋转角的圆角矩形
		GeoRectRound		=13,	
		//! 圆
		GeoCircle			=15,	
		//! 等边形, 暂不提供, 不要开放出去
		GeoEquilateral		=17,	
		//Ellipse			=19,	//椭圆
		//! 椭圆和斜椭圆统一为带旋转角的椭圆
		GeoEllipse			=20,	
		//! 椭圆扇面
		GeoPie				=21,	
		//! 弦, 暂不提供, 不要开放出去
		GeoChord			=23,	//a closed figure bounded by the intersection of an ellipse and a line segment.
		//! 圆弧
		GeoArc				=24,	
		//! 椭圆弧
		GeoEllipticArc		=25,	
		//! Cardinal曲线,保证曲线一定通过控制点
		GeoCardinal			=27,	
		//! 曲线 for dgn,具体在数学定义上是哪种类型的曲线,搞不太清楚了
		GeoCurve			=28,	
		//! 贝叶斯曲线
		GeoBSpline			=29,	
		//! 圆环, 暂不提供, 不要开放出去
		GeoDonut			=31,	
		//! 测量用, 暂不提供, 不要开放出去
		GeoTraverse			=33,	
		//! 多一线, 暂不提供, 不要开放出去
		GeoLwpline			=34,	
		//! for Survey, 暂不提供, 不要开放出去
		GeoPath				=41,	//
		//! 三维点, 暂不提供, 不要开放出去
		GeoPointZ			=101,	
		//! 三维多点, 暂不提供, 不要开放出去
		GeoMultiPointZ		=102,	
		//! 三维线, 暂不提供, 不要开放出去
		GeoLineZ			=103,	
		//! 三维面, 暂不提供, 不要开放出去
		GeoRegionZ			=105,	
		//! 三维文本, 暂不提供, 不要开放出去
		GeoTextZ			=107,	
		//! 三角形, 暂不提供, 不要开放出去
		GeoTriangle			=109,	
		//! 立方体, 暂不提供, 不要开放出去
		GeoCube				=111,	
		//! 测量用, 暂不提供, 不要开放出去
		GeoTraverseZ		=133,	
		//! 贝叶斯曲面, 暂不提供, 不要开放出去
		GeoBSurface			=135,	
		//! 多面体, 暂不提供, 不要开放出去
		GeoPolyhedron		=137,	
		//! 不规则三角面, Tin
		GeoTinBlock			=139	
#endif // end declare ugc sdk
	};
	
	//! \brief GML版本信息定义
	enum GMLVersionType
	{
		SML = 0,	//supermap自定义格式
		GML212		= 212,	//GML2.1.2版本
		GML310		= 310,	//GML3.1.0版本
		GML311		= 311	//GML2.1.1版本
	};

public: //! 构造和析构函数
	//! \brief 构造函数
	UGGeometry();
	
	//! \brief 析构函数
	virtual ~UGGeometry();
	
public: //! 得到和设置一些信息
	
	//! \brief 清空地理数据
	virtual void Clear() =0;
	
	//! \brief 得到维度, 点为0维, 线/曲线等为1维, 面/曲面等为2维, GeoCompound/GeoText等为-1
	virtual UGint GetDimension() const = 0;
	
	//! \brief 得到类型
	virtual Type GetType() const = 0;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \return 返回内点
	virtual UGPoint2D GetInnerPoint() const = 0;
	
	
	//! \brief 得到空间数据, 主要用于需要按照维度相同时
	//! 来做统一处理的时候, 例如一些空间判断和操作的算法
	//! \param pPoints 传出的点坐标数组[out]。
	//! \param pPolyCount 传出的每个子对象点个数的数组[out]。
	//! \param nSubCount 传出的子对象个数[out]。
	//! \param nSegmentCount 对参数化对象, 每个弧段分割点的个数[in]。
	//! \remarks 参数采用了智能指针的技术,调用者不用释放内存空间
	//! \return 成功返回true,否则返回false。
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const = 0;	
	
	//! \brief 几何对象是否有效
	//! \return 有效返回true,无效返回false
	virtual UGbool IsValid() const = 0;
	
	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const = 0;
	
	//! \brief 缩放
	//! \param dRatioX X方向缩放比率
	//! \param dRatioY Y方向缩放比率
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY) = 0;
	
	//! \brief 缩放
	//! \param dRatio 缩放比率(X,Y方向相同)
	virtual void Inflate( UGdouble dRatio) = 0;
	
	//! \brief 平移
	//! \param dX 平移的X偏移量
	//! \param dY 平移的Y偏移量
	virtual void Offset( UGdouble dX, UGdouble dY) = 0;
	
	//! \brief 平移
	//! \param 偏移量(X,Y方向相同)
	virtual void Offset( UGdouble dOffset) = 0;
	
	//! \brief 平移
	//! \param 平移的偏移量(分别用UGSize2D中的x,y代表X,Y方向的偏移量)
	virtual void Offset( const UGSize2D &szOffset) = 0;
	
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
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0) = 0;
	
	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
	//! \return 成功返回true,失败返回false
	virtual UGbool Resize(const UGRect2D& rcNewBounds) = 0;

	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
public:
	//! \brief 得到对象内线
	//! \remarks 如果返回不为空，则必须在使用后delete
//	virtual UGGeoLine* GetInnerLine() const;
	
// 	//! \brief 得到对象周长
// 	//! \attention Dimension为2的对象才支持
// 	//! \return 返回对象周长
// 	virtual UGdouble GetPerimeter() const;
	
	//! \brief 得到对象面积
	//! \attention Dimension为2的对象才支持
	//! \return 返回面积
	virtual UGdouble GetArea() const;
	
	//! \brief 得到对象长度
	//! \attention Dimension为1or2的对象才支持
	//! \return 返回长度
	virtual UGdouble GetLength() const;
	
	//! \brief 得到子对象的个数
	//! \return 返回子对象的个数
	virtual UGint GetSubCount() const;

public:
	//Projection..

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

public: //! 存储到外部介质中,或者从外部介质中生成
	
	//! \brief 得到ID
	//! \return 返回ID
	UGint GetID() const;
	
	//! \brief 设置ID
	//! \param 要设置的ID
	void SetID( UGint nID );
	
	//! \brief 得到外接矩形
	//! \return 返回外接矩形
	const UGRect2D& GetBounds() const;
	
	//! \brief 设置外接矩形,一般不要使用, 内部会维护Bounds的正确性
	//! \param rcBounds 要设置的Bounds
	void SetBounds( const UGRect2D& rcBounds );
	
	//! \brief 设置风格
	//! \param pStyle 风格指针
	//! \remarks 如果pStyle==NULL,则Geometry内部风格指针被删除; 否则会复制一份风格
	//! 对于文本对象等, 设置风格不起作用,因为文本对象有自己的TextStyle
	virtual void SetStyle(const UGStyle* pStyle);

	//! \brief 得到风格对象的指针,如果没有返回NULL
	//! \return 返回风格的指针,有可能为NULL
	UGStyle* GetStyle() const;

public:
	//! \brief 拷贝Geometry基类中的成员变量, 包括ID, Style, Bounds等
	//! \param geo 提供信息的Gemetry
	void CopyBaseData(const UGGeometry& geo);
	
	//! \brief 保存到存储流重
	//! \param stream 存储用的流, 调用之前应该先Open
	//! \param eCodecType 存储的编码方式
	//! \param bIgnoreStyle 是否忽略对象风格
	//! \return 成功返回true,失败返回false
	UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE, 
			UGbool bIgnoreStyle = TRUE) const;
	
	//! \brief 从流中装载数据
	//! \param stream 流
	//! \remarks Load时,由于很多信息已经存储在stream中了,所以存储编码和是否保存风格等参数就不需要了
	//! \return 成功返回true,失败返回false
	UGbool Load(UGStream& stream);

public:
//	UGdouble GetMaxZ();
//	void SetMaxZ(UGdouble z);
//	UGdouble GetMinZ();
//	void SetMinZ(UGdouble z);
	
	// zengzm 2005.8.16 被SDBPlus所迫,不得不public之
	//! \brief 只保存几何数据部分
	//! \param stream 存储流, 调用之前应该先Open
	//! \param eCodecType 存储的编码方式
	//! \param bSDBPlus 是否存储为SDBPlus的格式
	//! \remarks 由于SDBPlus引擎和数据库引擎的存储上差别较大,所以必须直接调用该函数,
	//! 并增加变量进行分别处理
	//! \return 成功返回true,失败返回false
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const = 0;

	//! \brief 只转载几何数据部分
	//! \param stream 流 
	//! \param eCodecType 编码方式
	//! \attention 还需要增加 UGbool bSDBPlus = FALSE 的参数
	//! \return 成功返回true,失败返回false
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE ) = 0;
	
	//! \brief 转化为线对象
	//! \param geoLine[out] 得到的线对象
	//! \param nSegmentCount 当曲线转化为线时,每一段用多少个点来模拟
	//! \return 成功返回true,失败返回false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief 转化为面对象
	//! \param geoRegion[out] 得到的面对象
	//! \param nSegmentCount 当曲面转化为面时,每一段用多少个点来模拟
	//! \return 成功返回true,失败返回false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;

public:
#if PACKAGE_TYPE==PACKAGE_UGC

	//! \brief 生成XML格式的信息
	/*支持
		SML,	//supermap自定义格式
		GML212,	//GML2.1.2版本
		GML310,	//GML3.1.0版本
		GML311　//GML2.1.1版本
		其中GML212仅支持GeoPoint、GeoLine、GeoRegion、GeoMultiPoint
	*/
	//! \param versionType GML的版本
	//! \param nPace 缩进的空格数目,使得xml字符串更加易于人工阅读; 
	//! 主要用于如果返回的xml字符串是一个大标签中的一部分, 通过指定空格数目,可以使层次清晰
	//! \return 返回指定GML版本的xml字符串
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0)  const = 0;
	
	//! \brief 从XML字符串中生成Geometry
	//! \param strXML xml格式字符串
	//! \param versionType xml字符串的GML版本
	//! \return 返回指定GML版本的xml字符串
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType) = 0;

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
	 virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,
				 UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief 节点编辑时可用来插入一个控制点,也可以用于绘制对象时加入节点
	//! \param nHandle 插入位置
	//! \param pnt2D 插入点的地理坐标
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,
				UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief 删除编辑对象的指定节点
	//! \param nHandle 节点句柄
     virtual UGuint DelNode( UGint nHandle );

	//! \brief 计算对象绘制时的辅助线，返回的是一个复合对象
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param nEditType 绘制对象的类型，参考UGEditType
	//! \param pStyle	 辅助线的风格，如果传入为NULL，用默认的风格
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,
				UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);


	//! \brief 计算对象绘制时的辅助点，返回的是点的数目,
	//! nHandleType返回的是辅助点的类型,参考UGEditType::EditHandleType
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param eAssistantPoints 点串,返回的辅助点点串
	//! \param nEditType 绘制对象的类型，参考UGEditType
	 virtual void CalAssistantPoints(const UGPoint2D* pPoints, UGint nPntCount,
				UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,
				UGEditType::EditToolShape nEditType);

	 //! \brief 根据传入的点串生成对象，主要用于编辑中的参数化等没有内部数组保存点串的对象，
	 //! 也用于自定义对象,对于有内部数组保存点串的对象，该函数直接return既可，
	 //! 比如GeoLine等对象就直接用AddHandle来生成，效率比较高 
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,
				UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief 获取对象需要捕捉的点串
	//! \param aryPnts 点串，传出去的要捕捉的点串
	//! \return 如果是true表示有需要捕捉的点串，如果返回false表示该对象没有需要捕捉的点串
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief 获取对象需要捕捉的线段数组
	//! \param aryLines 需要捕捉的线数组（如果有多个part，那么aryLines就应该有多少个count）
	//! \return 如果是true表示有需要捕捉的线，如果返回false表示该对象没有需要捕捉的线
	virtual UGbool GetSnapLines(UGLineArray& aryLines);

	//added by xielin ^_^ 编辑相关函数,把编辑和geometry统一 end

	//! \brief 设置几何对象中字符串的Charset,主要针对文本对象，复合对象中的文本字符串,只set，不转换字符串内容
	virtual void SetTextCharset(UGTextCodec::Charset nCharset);

	//! \brief 改变几何对象中字符串的Charset,主要针对文本对象，复合对象中的文本字符串,转换字符串内容
	virtual void ChangeTextCharset(UGTextCodec::Charset nCharset);

protected:
	
	//! \brief 真正计算Bounds
	//! \return 返回得到的Bounds
	virtual UGRect2D ComputeBounds() const = 0;
	
	//virtual UGRect2D GetBoundsInside() const = 0;
	
	// modified by zengzm 
	//virtual void SetBoundsInside( const UGRect2D & rcBounds ) = 0;

	//! \brief		判断Bounds是否脏了
	//! \return		如果脏了, 返回true; 不脏返回false
	UGbool IsBoundsDirty() const;

	//! \brief		设置Bounds是否脏了
	//! \param		bBoundsDirty	Bounds是否脏, 默认为设置脏
	void SetBoundsDirty(UGbool bBoundsDirty=true);
	
protected:
	//! \brief 几何对象ID，默认为0
	UGint m_nID;
	
	//! \brief 几何对象自带风格，默认为NULL
	UGStyle* m_pStyle;
	
	// modified by zengzm 2005-8-24 放到 private 中, 子类用 SetBoundsDirty
	//! \brief 几何对象内部存储的Bounds是否已经脏了（和实际数据不相同了）
	//UGbool m_bBoundsDirty;
	
	//! \brief 几何对象BOUNDs
	UGRect2D m_rcBounds;

private:
	//! \brief 几何对象内部存储的Bounds是否已经脏了（和实际数据不相同了）
	UGbool m_bBoundsDirty;
};

}

#endif // !defined(AFX_UGGEOMETRY_H__8844E5E9_172A_4931_913C_5B1322A02D82__INCLUDED_)
