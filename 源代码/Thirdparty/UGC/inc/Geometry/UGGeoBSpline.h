#ifndef INCLUDE_GEOMETRY_UGGEOBSPLINE_H_HEADER_INCLUDED_BE221461
#define INCLUDE_GEOMETRY_UGGEOBSPLINE_H_HEADER_INCLUDED_BE221461

#include "UGGeometry.h"

namespace UGC {

//! \brief B样条曲线, 至少由4个点构成
//! \remarks 从SFC移植而来, 具体科学意义上是哪个东东, 还不是很清楚, 有待查实
class GEOMETRY_API UGGeoBSpline : public UGGeometry
{
public:
	//! \brief 构造函数。
	UGGeoBSpline();    
	//! \brief 析构函数。
    virtual ~UGGeoBSpline();
	
public: //pure virtual 
	//! \brief 清空地理数据
	virtual void Clear();

	//! \brief 得到维度, 固定为1维
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型, 固定为UGGeoBSpline
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \remarks 现在是返回处于中间的控制点,实际上还有问题,有待改进
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
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
	
	//! \brief 得到空间数据
	//! \param pPoints 传出的点坐标数组[out]。
	//! \param pPolyCount 传出的每个子对象点个数的数组[out]。
	//! \param nSubCount 传出的子对象个数[out]。
	//! \param nSegmentCount 对参数化对象, 每个弧段分割点的个数[in]。
	//! \remarks 参数采用了智能指针的技术,调用者不用释放内存空间
	//! \return 成功返回true,否则返回false。
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief 几何对象是否有效, 对BSpline, 至少4个点才能有效
	//! \return 有效返回true,无效返回false
	virtual UGbool IsValid() const;
	
	//! \brief 两点镜像
	//! \param pntMirror1 构成镜面的第一个点
	//! \param pntMirror2 构成镜面的第二个点
	//! \return 成功返回true,失败返回false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

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

	//! \brief 通过控制点点串构造BSpline。
	//! \param pPoints [in] 控制点点串指针。
	//! \param nPointCount [in] 控制点数目。
	//! \return 小于四个点,构造不成功,返回false。
	UGbool Make( UGPoint2D* pPoints, UGint nPointCount );    
	
	//! \brief 通过复制构造BSpline。
	//! \param geoBSpline [in] 原有的BSpline。
	//! \return 原有BSpline非法, 返回false。
	UGbool Make(const UGGeoBSpline& geoBSpline);	

	//! \brief 得到内部控制点数组的指针。
	//! \return 返回内部控制点数组的指针, 为const类型,一般不要直接修改。
	const UGPoint2D *GetPoints() const;    
	
	//! \brief 得到控制点个数。
	//! \return 返回控制点个数。
	UGint GetPointCount() const;    
	
	//! \brief 增加一个控制点。
	//! \param pntPoint [in] 要增加的控制点。
	//! \return 返回true。
	UGbool Add( const UGPoint2D& pntPoint );    
	
	//! \brief 增加控制点点串。
	//! \param pPoints [in] 控制点点串指针。
	//! \param nPointCount [in] 控制点数目。
	//! \return 返回true。
	UGbool Add( const UGPoint2D *pPoints, UGint nPointCount );    
	
	//! \brief 插入控制点。
	//! \param nIndex [in] 要插入的位置索引。
	//! \param pntPoint [in] 要插入的控制点。
	//! \return 索引在有效范围内, 返回true; 否则返回false。
	UGbool InsertAt( UGint nIndex, const UGPoint2D& pntPoint );    
	
	//! \brief 在指定位置设置控制点。
	//! \param nIndex [in] 要设置的位置索引。
	//! \param pntPoint [in] 要设置的控制点。
	//! \return 索引在有效范围内, 返回true; 否则返回false。
	//! \remarks 原来位置的控制点会被替代。
	UGbool SetAt( UGint nIndex, const UGPoint2D& pntPoint );    

	//! \brief 得到指定索引的控制点。
	//! \param nIndex [in] 指定的索引。
	//! \param pntPoint [out] 得到的控制点。
	//! \return 索引在有效范围内, 返回true; 否则返回false。
	//! \remarks 返回false时, pntPoint为无效值。
	UGbool GetAt( UGint nIndex, UGPoint2D& pntPoint ) const;    
	
	//! \brief 移除指定索引的控制点。
	//! \param nIndex [in] 要移除的索引位置。
	//! \return 索引在有效范围内, 返回true; 否则返回false。
	UGbool RemoveAt( UGint nIndex );    
	
	//! \brief 移除所有控制点
    void RemoveAll();

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
	
	//virtual UGRect2D GetBoundsInside() const;
	
	//virtual void SetBoundsInside( const UGRect2D & rcBounds );
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	
	//! \brief 控制点数组
	//! \remarks 注意,这里保存的是B样条形状的控制点,而非实际位置点 
	UGArray<UGPoint2D> m_Points;
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOBSPLINE_H_HEADER_INCLUDED_BE221461 */
