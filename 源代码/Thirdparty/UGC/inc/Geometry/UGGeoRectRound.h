#ifndef UGGEORECTROUND_H
#define UGGEORECTROUND_H

#include "UGGeoRect.h"
#include "UGGeometry.h"

namespace UGC {

//! \brief 圆角矩形(斜)对象
//! \remarks 圆角矩形对象的形状决定如下: 先矩形放置好,
//!	然后把四个角改为1/4椭圆弧(椭圆的长半轴和短半轴分别为:m_dRadiusX和m_dRadiusY)
//! 最后按逆时针旋转角度, 即得到斜圆角矩形
class GEOMETRY_API UGGeoRectRound : public UGGeometry
{
public:
	//! \brief 构造函数
    UGGeoRectRound();

	//! \brief 析构函数
    virtual ~UGGeoRectRound();
	
public: //pure virtual 
	
	//! \brief 清空地理数据
	virtual void Clear();
	
	//! \brief 得到维度, 固定为2维
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型, 固定为 GeoRectRound
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \remarks 即为中心点
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief 得到对象长度
	//! \attention Dimension为1or2的对象才支持
	//! \return 返回长度
	virtual UGdouble GetLength() const;
	
	//! \brief 得到对象面积
	//! \return 返回面积
	virtual UGdouble GetArea() const;
	
	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false	
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
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
	
	//! \brief 几何对象是否有效
	//! \return 高度/宽度/长半轴/短半轴有一个小于0, 返回false
	//!			如果长半轴大于宽度的一半,或者短半轴大于高度的一般, 也返回false
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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
	//! \remarks 斜椭圆resize后, 可能不能完全填充新的bounds; 
	//!			 再计算得到的Bounds也有可能不等于resize的参数
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

	//! \brief 拷贝复制构造圆角矩形。
	//! \param geoRectRound [in] 已有的圆角矩形。
	//! \return 以后对象非法,返回false。
	UGbool Make(const UGGeoRectRound& geoRectRound);	
	
	//! \brief 通过中心点/Size/旋转角度/长半轴/短半轴构造圆角矩形。
	//! \param pntCenter [in] 中心点。
	//! \param szSize [in] 矩形的Size。
	//! \param dAngle [in] 旋转角度。
	//! \param dRadiusX [in] 圆角的长半轴。
	//! \param dRadiusY [in] 圆角的短半轴。
	//! \return 长半轴或短半轴如果小于0,返回false。
	UGbool Make(const UGPoint2D &pntCenter, const UGSize2D& szSize, UGdouble dAngle,
				UGdouble dRadiusX, UGdouble dRadiusY);    
	
	//! \brief 通过矩形对象和圆角长短半轴构造圆角矩形。
	//! \param geoRect [in] 矩形对象。
	//! \param dRadiusX [in] 圆角长半轴。
	//! \param dRadiusY [in] 圆角短半轴。
	//! \return 长半轴或短半轴如果小于0,返回false。
	UGbool Make(const UGGeoRect& geoRect, UGdouble dRadiusX, UGdouble dRadiusY);    
	
	//! \brief 通过矩形/旋转角度/圆角长短半轴构造圆角矩形。
	//! \param rect [in] 矩形。
	//! \param dAngle [in] 旋转角度。
	//! \param dRadiusX [in] 圆角长半轴。
	//! \param dRadiusY [in] 圆角短半轴。
	//! \return 长半轴或短半轴如果小于0,返回false。
	UGbool Make(const UGRect2D& rect, UGdouble dAngle, UGdouble dRadiusX, UGdouble dRadiusY);	
	
	//! \brief 得到中心点。
	//! \return 返回中心点。
	UGPoint2D GetCenterPoint() const;    
	
	//! \brief 设置中心点。
	//! \param pntCenter [in] 中心点。
	void SetCenterPoint( const UGPoint2D& pntCenter );    
	
	//! \brief 得到旋转角度。
	//! \return 返回旋转角度。
	UGdouble GetAngle() const;    
	
	//! \brief 设置旋转角度。
	//! \param dAngle [in] 旋转角度。
	void SetAngle( UGdouble dAngle );    
	
	//! \brief 得到圆角长半轴。
	//! \return 返回圆角长半轴。
	UGdouble GetRadiusX() const;    
	
	//! \brief 设置圆角长半轴。
	//! \param dRadiusX [in] 圆角长半轴。
	//! \return 如果长半轴小于0,返回false。
	UGbool SetRadiusX(UGdouble dRadiusX);    
	
	//! \brief 得到圆角短半轴。
	//! \return 返回圆角短半轴。
	UGdouble GetRadiusY() const;    
	
	//! \brief 设置圆角短半轴。
	//! \param dRadiusY [in] 圆角短半轴。
	//! \return 如果短半轴小于0,返回false。
    UGbool SetRadiusY(UGdouble dRadiusY);
	
	//! \brief 得到矩形高度。
	//! \return 返回矩形高度。
	UGdouble GetHeight() const;	
	
	//! \brief 设置矩形高度。
	//! \param dHeight [in] 要设置的矩形高度。
	//! \return 高度小于等于0,返回false。
	UGbool SetHeight( UGdouble dHeight );	
	
	//! \brief 得到矩形宽度。
	//! \return 返回矩形宽度。
	UGdouble GetWidth() const;
	
	//! \brief 设置矩形宽度。
	//! \param dWidth [in] 要设置的矩形宽度。
	//! \return 宽度小于等于0,返回false。
	UGbool SetWidth( UGdouble dWidth );
	
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

 	//! \brief 计算对象绘制时的辅助点，返回的是点的数目,nHandleType返回的是辅助点的类型,参考UGEditType::EditHandleType
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param eAssistantPoints 点串,返回的辅助点点串
	//! \param nEditType 绘制对象的类型，参考UGEditType
	 virtual void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);

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

	 

	//added by xielin ^_^ 编辑相关函数,把编辑和geometry统一 end
protected:
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;
	
	virtual void SetBoundsInside( const UGRect2D & rcBounds );*/
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
	// by zengzm 2007-9-6 IsPointInRoundRect实现的过去复杂,且又没有考虑容限,先封起来
	//UGbool IsPointInRoundRect(const UGPoint2D &pntHitTest) const;
	
private:
	//! \brief 中心点
	UGPoint2D m_pntCenter;
	
	//! \brief 矩形宽度
	UGdouble m_dWidth;
	
	//! \brief 矩形高度
	UGdouble m_dHeight;
	
	//! \brief 圆角长半轴
	UGdouble m_dRadiusX;
	
	//! \brief 圆角短半轴
	UGdouble m_dRadiusY;
	
	// modified by zengzm 2007-4-27 
	//UGint m_nAngle;
	//! \brief 旋转角度
	//! \remarks 内存中改为double,角度单位,存储时和SFC保持兼容
	UGdouble m_dAngle;
};

} // namespace UGC


#endif /* INCLUDE_GEOMETRY_UGGEORECTROUND_H_HEADER_INCLUDED_BE22541D */
