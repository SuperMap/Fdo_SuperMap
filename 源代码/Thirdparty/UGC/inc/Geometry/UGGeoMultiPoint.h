#ifndef INCLUDE_GEOMETRY_UGGEOMULTIPOINT_H_HEADER_INCLUDED_BE224D0F
#define INCLUDE_GEOMETRY_UGGEOMULTIPOINT_H_HEADER_INCLUDED_BE224D0F

#include "UGGeometry.h"
#include "UGGeoPoint.h"

namespace UGC {

//! \brief 多点对象
//! \remarks GeoPoint和GeoLine,GeoRegion有一点不一样, GeoPoint没有复杂对象一说,即GeoPoint只能有一个点,
//! 不能有多个子对象(点数据集也只能有GeoPoint对象,不能有多点对象);
//! 需要表达多点时, 使用GeoMultiPoint(注意,GeoMultiPoint不能加入到点数据集中,只能加入到复合数据集中)
class GEOMETRY_API UGGeoMultiPoint : public UGGeometry
{
public:
	//! \brief 构造函数
    UGGeoMultiPoint();

	//! \brief 析构函数
    virtual ~UGGeoMultiPoint();

public: //pure virtual 

	//! \brief 清除Geometry内部数据
	virtual void Clear();

	//! \brief 得到维度, 固定为0
	virtual UGint GetDimension() const;

	//! \brief 得到类型, 固定为 GeoMultiPoint
	virtual Type GetType() const;

	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \remarks 暂时先返回中间顺序的点,以后可以考虑用距离Bounds中心最近的点
	//! \return 返回内点
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief 得到子对象数目。
	//! \return 返回子对象数据。
	virtual UGint GetSubCount() const;	
	
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
	//! \return 子对象不为0,返回true
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

	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
	//! \remarks 坐标点变为Bounds的中心点
	//! \return 成功返回true,失败返回false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

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
	
	//! \brief 复制构造多点对象。
	//! \param geoMultiPoint [in] 已有的多点对象。
	//! \return 已有对象非法，返回false。
	UGbool Make(const UGGeoMultiPoint& geoMultiPoint);	

	//! \brief 通过点串构造多点对象。
	//! \param pPoints [in] 点串指针。
	//! \param nPntCount [in] 点串中点的个数。
	//! \return 点数为0，返回false。
	UGbool Make(const UGPoint2D* pPoints, UGint nPntCount);	

	//! \brief 得到内部点串。
	//! \return 返回点串，为const类型，外面一般不要修改。
	const UGPoint2D *GetPoints();    

	//! \brief 得到点的个数。
	//! \return 返回点的个数。
	UGint GetPointCount();    

	//! \brief 得到指定索引的点坐标。
	//! \param nIndex [in] 指定的索引。
	//! \param pntPoint [out] 嗲你点坐标。
	//! \return 索引非法，返回false。
	UGbool GetPoint(UGint nIndex, UGPoint2D& pntPoint);    

	//! \brief 设置指定索引的点坐标。
	//! \param nIndex [in] 指定的索引。
	//! \param pntPoint [in] 点坐标。
	//! \return 索引非法，返回false。
	UGbool SetPoint(UGint nIndex, const UGPoint2D &pntPoint);    

	//! \brief 增加点。
	//! \param pntPoint [in] 点坐标。
	//! \return 返回true。
	UGbool AddPoint(const UGPoint2D &pntPoint);    
	
	//! \brief 通过指定索引的子对象，构造出点对象
	//! \param nIndex [in] 指定的索引。
	//! \param pGeoPoint [out] 得到的点对象，如果指针传入时为NULL，内部会new出来。
	//! \return 索引非法，返回false。
	UGbool GetSub(UGint nIndex, UGGeoPoint *&pGeoPoint);	
	
	//! \brief 插入点。
	//! \param nIndex [in] 插入的位置索引。
	//! \param pntPoint [in] 要插入的点。
	//! \return 索引非法,返回false。
	UGbool InsertPoint(UGint nIndex,const UGPoint2D &pntPoint);    

	//! \brief 移除指定位置的点。
	//! \param nIndex [in] 指定位置索引。
	//! \return 索引非法,返回false。
	UGbool RemovePoint(UGint nIndex);    

	//! \brief 增加点串。
	//! \param pPoints [in] 点串的指针。
	//! \param nPointCount [in] 点串的点个数。
	//! \return 返回true。
	UGbool AddPoints(const UGPoint2D *pPoints, UGint nPointCount);    

	//! \brief 在指定位置插入一个点串。
	//! \param nIndex [in] 指定的索引位置。
	//! \param pPoints [in] 插入的点串。
	//! \param nPointCount [in] 点串的点个数。
	//! \return 索引位置非法,返回false。
	UGbool InsertPoints(UGint nIndex, const UGPoint2D *pPoints, UGint nPointCount);    

	//! \brief 移除若干个点。
	//! \param nIndex [in] 要开始移除的位置索引。
	//! \param nPointCount [in] 要移除的点个数。
	//! \return 位置索引非法,返回false。
	UGbool RemovePoints(UGint nIndex, UGint nPointCount);    
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

	//added by xielin ^_^ 编辑相关函数,把编辑和geometry统一 end
protected:
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;

	virtual void SetBoundsInside( const UGRect2D & rcBounds );*/

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

private:
	//! \brief 内部用点数组来存储多个点坐标
	UGArray<UGPoint2D> m_Points;

};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOMULTIPOINT_H_HEADER_INCLUDED_BE224D0F */
