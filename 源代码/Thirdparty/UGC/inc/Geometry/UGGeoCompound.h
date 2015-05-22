#ifndef UGGEOCOMPOUND_H
#define UGGEOCOMPOUND_H

#include "UGGeometry.h"

namespace UGC {

//! \brief 复合对象
//! \remarks 复合对象使用了设计模式中的"聚合模式",即可以把其它任意几何对象(包括复合对象本身)聚合在一起,
//! 形成一个树状的结构;值得注意的是,给复合对象聚合的几何对象必须是指针的形式,且之后就归复合对象管理这块内存了.
class GEOMETRY_API UGGeoCompound : public UGGeometry
{
public:
	//! \brief 构造函数
    UGGeoCompound();
	//! \brief 析构函数
    virtual ~UGGeoCompound();
	
public: //pure virtual 
	
	//! \brief 清空地理数据
	virtual void Clear();
	
	//! \brief 得到维度,固定为-1
	virtual UGint GetDimension() const;

	//! \brief 得到类型,固定为GeoCompound
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \remarks 内点为靠近中间顺序(不是中间位置)的几何对象的内点
	//! \return 返回内点
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief 得到对象面积
	//! \return 返回面积
	virtual UGdouble GetArea() const;
	
	//! \brief 得到对象长度
	//! \return 返回长度
	virtual UGdouble GetLength() const;	

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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
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
	virtual void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);
	
	//! \brief 从经纬坐标系统转化为投影坐标系统
	//! \param pCoordSys 投影坐标系统
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief 从投影坐标系统转化为经纬坐标
	//! \param pCoordSys 投影坐标系统
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:

	
	//! \brief 复制构造复合对象。
	//! \param geoCompound [in] 已有的复合对象。
	//! \return 已有复合对象非法,返回false。
	UGbool Make(const UGGeoCompound& geoCompound);	
	
	//! \brief 增加一个几何对象。
	//! \param pGeometry [in] 几何对象指针。
	//! \param bByDimension [in] 如果bByDimension为true时,函数会避免新增加的几何对象把已有对象盖住
	//!			直到找到一个二维对象且不会被新增加对象完全覆盖的对象为止,或者直到最底层。
	//! \return 新增加的几何对象指针不为NULL,返回true。
	UGbool AddCompound(UGGeometry *pGeometry, UGbool bByDimension = TRUE);    
	
	//! \brief 给指定的位置设置结合对象。
	//! \param nIndex [in] 指定的位置索引。
	//! \param pGeometry [in] 几何对象指针。
	//! \return 几何对象指针不为NULL,返回true。
	//! \remarks 指定位置上原有的几何对象将被delete掉。
	UGbool SetCompound(UGint nIndex, UGGeometry *pGeometry);    
	
	//! \brief 在指定的位置插入一个几何对象。
	//! \param nIndex [in] 指定的位置索引。
	//! \param pGeometry [in] 几何对象指针。
	//! \return 几何对象指针不为NULL,返回true。
	UGbool InsertCompound(UGint nIndex, UGGeometry *pGeometry);    
	
	//! \brief 移除(并delete)指定位置的子对象。
	//! \param nIndex [in] 指定的位置索引。
	//! \return 索引非法,返回false。
	UGbool RemoveGeometry(UGint nIndex);    
	
	//! \brief 按照子对象Bounds的大小来重新排列复合对象中各个子对象的上下顺序。
	//! \param bMoveUptheMinObj [in] 为true时,小对象在上面;为false时小对象在下面。
	void Adjust(UGbool bMoveUptheMinObj = true);    
	
	//! \brief 得到指定位置的子对象(也是Geometry)指针。
	//! \param nIndex [in] 指定的位置索引。
	//! \return 子对象指针, 位置非法时,返回NULL。
	UGGeometry *GetGeometry( UGint nIndex );	

	//! \brief 得到指定位置的子对象(也是Geometry)指针。
	//! \param nIndex [in] 指定的位置索引。
	//! \return const类型子对象指针,外面不能修改, 位置非法时,返回NULL。
    const UGGeometry *GetGeometry( UGint nIndex ) const;
	
	//! \brief 分解复合对象
	//! \param arrGeometry [out] 分解后得到的子对象的数组
	//! \param bToLeaf 是否分解到叶对象, 默认为false
	//! \remarks 复合对象是一颗树, 如果不分解到叶对象, 则传出的arrGeometry仍然可能存在复合对象(非叶)
	//  如果bToLeaf =true, 则传出的arrGeometry中肯定没有 复合对象
	//! \attention 取出来的几何对象指针数组, 这些指针仍然是指向GeoCompound内部的内存地址, 外面使用后不要delete;
	//! 在GeoCompound发生变化(如插入子对象,或者清空等)后,不要再使用这些指针,因为有可能为野指针
	UGbool Divide(UGArray<UGGeometry *> &arrGeometry, UGbool bToLeaf=false);

	//! \brief 转化为面对象。
	//! \param geoRegion [out] 得到的面对象。
	//! \param nSegmentCount [in] 参数化对象每段的插值的点数。
	//! \return 面对象加入子对象成功,返回true。
	//! \remarks 内部实现就是把GeoCompound中的每一个子对象转化为Region,再加入到geoRegion引用参数中。
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;		
	
	//! \brief 转化为线对象。
	//! \param geoLine [out] 得到的线对象。
	//! \param nSegmentCount [in] 参数化对象每段的插值的点数。
	//! \return 线对象加入子对象成功,返回true。
	//! \remarks 内部实现就是把GeoCompound中的每一个子对象转化为Line,再加入到geoLine引用参数中。
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;	

#if PACKAGE_TYPE==PACKAGE_UGC
public:			
	//! \brief 把GeoCompound中不为空线形的线和现状几何对象加入到引用型参中。
	//! \param geoLine [out] 取出数据的线对象。
	//! \param nSegmentCount [in] 曲线转化为线,每一段的插值点数。
	//! \return 加入子对象成功,返回true。
	UGbool GetLine(UGGeoLine &geoLine, UGint nSegmentCount) const;    

	//! \brief 把GeoCompound中所有类型为GeoRegion的子对象增加到引用型参数中返回。
	//! \param geoRegion [out] 从GeoCompound中取出类型为GeoRegion的引用型参数。
	//! \return 子对象增加成功,返回true。
	UGbool GetRegion(UGGeoRegion &geoRegion) const;    

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
	void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);


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

	//! \brief 设置几何对象中字符串的Charset,主要针对文本对象，复合对象中的文本字符串
	virtual void SetTextCharset(UGTextCodec::Charset nCharset);

	//! \brief 改变几何对象中字符串的Charset,主要针对文本对象，复合对象中的文本字符串,转换字符串内容
	virtual void ChangeTextCharset(UGTextCodec::Charset nCharset);

#endif // end declare ugc sdk
protected:
	
	virtual UGRect2D ComputeBounds() const;
	
	//virtual UGRect2D GetBoundsInside() const;
	
	//virtual void SetBoundsInside( const UGRect2D & rcBounds );
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	//! \brief 用来存放几何对象(作为子对象看待)指针的数组
	UGArray< UGGeometry* > m_GeometryArray;
};

}



#endif 
