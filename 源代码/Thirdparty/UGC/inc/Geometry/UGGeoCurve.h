// UGGeoCurve.h: interface for the UGGeoCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOCURVE_H__02C1EB1D_1DF5_4285_B810_47F6DF6DEA53__INCLUDED_)
#define AFX_UGGEOCURVE_H__02C1EB1D_1DF5_4285_B810_47F6DF6DEA53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGGeometry.h"
namespace UGC {

//! \brief 曲线对象,至少由6个控制点构成
//! \remarks 从SFC移植而来,存储和SFC保持兼容; 具体的数学含义尚不清楚,可能和DGN的某个对象对应;
//! 内部保存的是控制点, Curve对象的实际曲线并不经过控制点
class GEOMETRY_API UGGeoCurve : public UGGeometry  
{
public:
	//! \brief 构造函数。
	UGGeoCurve();	
	//! \brief 析构函数。
	virtual ~UGGeoCurve();
public:

	//! \brief 清空地理数据
	virtual void Clear();

	//! \brief 得到维度, 固定为1维
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型, 固定为UGGeoCurve
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	//! \remarks 现在是返回处于中间偏后2个位置的控制点,实际上还有问题,有待改进
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief 得到空间数据
	//! \param pPoints 传出的点坐标数组[out]。
	//! \param pPolyCount 传出的每个子对象点个数的数组[out]。
	//! \param nSubCount 传出的子对象个数[out]。
	//! \param nSegmentCount 对参数化对象, 每个弧段分割点的个数[in]。
	//! \remarks 参数采用了智能指针的技术,调用者不用释放内存空间
	//! \return 成功返回true,否则返回false。
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;

	//! \brief 几何对象是否有效, 对Curve, 至少6个点才能有效
	//! \return 有效返回true,无效返回false
	virtual UGbool IsValid() const;
	
	//! \brief 点击测试, 用于对象点选
	//! \param pntHitTest 用来测试选中的点
	//! \param dTolerance 容限
	//! \return 选中返回true, 否则返回false
	virtual UGbool HitTest(const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	//! \brief 缩放
	//! \param dRatioX X方向缩放比率
	//! \param dRatioY Y方向缩放比率
	virtual void Inflate(UGdouble dRatioX, UGdouble dRatioY);

	//! \brief 缩放
	//! \param dRatio 缩放比率(X,Y方向相同)
	virtual void Inflate(UGdouble dRatio);

	//! \brief 平移
	//! \param dX 平移的X偏移量
	//! \param dY 平移的Y偏移量
	virtual void Offset(UGdouble dX, UGdouble dY);

	//! \brief 平移
	//! \param 偏移量(X,Y方向相同)
	virtual void Offset(UGdouble dOffset);

	//! \brief 平移
	//! \param 平移的偏移量(分别用UGSize2D中的x,y代表X,Y方向的偏移量)
	virtual void Offset(const UGSize2D &szOffset);
	
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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0);

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

	//! \brief 调整几何数据,限定在新的Bounds中
	//! \param rcNewBounds 新的,限定范围的Bounds
	//! \return 成功返回true,失败返回false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	// 暂不提供了, 其它几个曲线也没有;固定为1个子对象
	//UGint GetSubCount() const;

	//! \brief 在对象上添加一个点
	//! \param pntPoint	要添加的点
	//! \return 返回true
	UGbool Add(const UGPoint2D &pntPoint);
	
	//! \brief 增加点串。
	//! \param pPoints [in] 点串指针。
	//! \param nPointCount [in] 点串的点个数。
	//! \return 点串指针为NULL,返回false。
	UGbool Add(const UGPoint2D *pPoints, UGint nPointCount);	
	
	//! \brief 插入一个点。
	//! \param nIndex [in]目标位置。
	//! \param pntPoint [in]要插入的点。
	//! \return 索引非法,返回false。
	UGbool InsertAt(UGint nIndex, const UGPoint2D &pntPoint);	
	
	//插入 nPointCount 个点
	//参数：
	//		nIndex		目标位置
	//		pPoints		要添加的点坐标串
	//		nPointCount	要添加的点数

	//! \brief 在指定位置插入一个点串。
	//! \param nIndex [in] 指定位置索引。
	//! \param pPoints [in] 要插入的点串指针。
	//! \param nPointCount [in] 点串的点个数。
	//! \return 索引位置非法,或者点串指针为NULL,返回false。
	UGbool InsertAt(UGint nIndex, const UGPoint2D *pPoints, UGint nPointCount);	
	
	//! \brief 设置指定位置的点, 原来位置的点被替换。
	//! \param nIndex [in] 位置索引。
	//! \param pntPoint [in] 点坐标。
	//! \return 索引非法,返回false。
	UGbool SetAt(UGint nIndex, const UGPoint2D &pntPoint);	
	
	//! \brief 得到指定位置的点。
	//! \param nIndex [in] 位置索引。
	//! \param pntPoint [out] 指定位置的点。
	//! \return 索引非法,返回false。
	UGbool GetAt(UGint nIndex, UGPoint2D &pntPoint);	
	
	//! \brief 移除指定位置的点。
	//! \param nIndex [in]要移除的点位置索引。
	//! \return 索引非法,返回false。
	UGbool RemoveAt(UGint nIndex);	
	
	//! \brief 移除从指定位置开始的若干个点。
	//! \param nFrom [in] 开始移除的位置。
	//! \param nCount [in] 要移除的点数目。
	//! \return 真正移除的点数目。
	UGint Remove(UGint nFrom, UGint nCount);	
	
	//! \brief 移除所有点。
	void RemoveAll();	

public:	
	//! \brief 根据投影转化器的设置和转化方向要求, 进行投影转化
	//! \param pPJTranslator 投影转化器
	//! \param bForward 转化方向, true代表从UGRefTranslator的源(Src)转化到目的(Des), false则相反
	virtual void PJConvert(UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief 从经纬坐标系统转化为投影坐标系统
	//! \param pCoordSys 投影坐标系统
	virtual void PJForward(UGPrjCoordSys *pCoordSys);

	//! \brief 从投影坐标系统转化为经纬坐标
	//! \param pCoordSys 投影坐标系统
	virtual void PJInverse(UGPrjCoordSys *pCoordSys);
	
public:

	//! \brief 通过控制点串构造Curve对象。
	//! \param pPoints [in] 点串指针。
	//! \param nPointCount [in] 点串的点数目。
	//! \return 如果指针为NULL或者点数为0,返回false。
	UGbool Make(const UGPoint2D * pPoints, UGint nPointCount);	

	//! \brief 通过已有对象复制构造Curve对象。
	//! \param geoCurve [in] 以后的Curve对象。
	//! \return 已有对象非法,返回false。
	UGbool Make(const UGGeoCurve &geoCurve);	

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
	 virtual UGint GetHandle(UGint nHandle, UGPoint2D& point);


	//! \brief 移动控制点到指定坐标,主要用于绘制对象，修改对象节点等操作
	//! \param nHandle 控制点句柄
	//! \param point 控制点坐标
	virtual void MoveHandle(UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief 节点编辑时可用来插入一个控制点,也可以用于绘制对象时加入节点
	//! \param nHandle 插入位置
	//! \param pnt2D 插入点的地理坐标
	virtual void AddHandle(UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief 删除编辑对象的指定节点
	//! \param nHandle 节点句柄
     virtual UGuint DelNode(UGint nHandle);

	//! \brief 计算对象绘制时的辅助线，返回的是一个复合对象
	//! \param pPoints 点串
	//! \param nPntCount  点的个数
	//! \param nEditType 绘制对象的类型，参考UGEditType
	//! \param pStyle	 辅助线的风格，如果传入为NULL，用默认的风格
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	//added by xielin ^_^ 编辑相关函数,把编辑和geometry统一 end
	 
protected: //! 子类需要实现的一些不公开函数
	virtual UGRect2D ComputeBounds() const;

	/*virtual UGRect2D GetBoundsInside() const;

	virtual void SetBoundsInside(const UGRect2D & rcBounds);*/

	//! \brief 存储到Stream中
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;

	//! \brief 从Stream中生成Geometry
	virtual UGbool LoadGeoData(UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE);

	// 请分析组把下面两个类似的函数 整理为一个后, 放到算法库的UGOpLines中
	UGbool Curve2Line(UGPoint2D *pCtrlPoints, UGlong lCtrnPointCount,
				UGPoint2D *&pResultPoints, UGint &lResultPointCount, UGint nPointCountPerSegment = 20) const;

	static void CurveToPolyline(UGPoint2D *pPoints, UGlong nPointCount, UGArray <UGPoint2D> &pPointsDraw, 
		UGlong &nDrawPointCount, UGdouble dAngleGrain = 0.05);

private:
	//! \brief 控制点数组
	//! \remarks Curve的实际位置并不经过控制点
	UGArray<UGPoint2D> m_Points;
};

}
#endif // !defined(AFX_UGGEOCURVE_H__02C1EB1D_1DF5_4285_B810_47F6DF6DEA53__INCLUDED_)
