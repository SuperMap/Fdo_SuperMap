// UGEditSnapBuffer.h: interface for the UGEditSnapBuffer class.
//
//=====================================================================================
// 项目名：			Supermap Foundation Class (SFC) Library 2.0
// 作  者：			宋关福
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为Supermap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGEditSnapBuffer.h
// 类  名：			UGEditSnapElement、UGEditSnapBuffer
// 父  类：			
// 子  类：			
// 功能说明：		UGEditSnapElement:捕捉记录元素
//					UGEditSnapBuffer:提供捕捉元素堆栈
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITSNAPBUFFER_H__DECB27E6_E117_11D2_A58F_0080C8EE6684__INCLUDED_)
#define AFX_UGEDITSNAPBUFFER_H__DECB27E6_E117_11D2_A58F_0080C8EE6684__INCLUDED_

#include "Base/ugexports.h"
#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Base/UGList.h"
#include "Algorithm/UGRect2D.h"
#include "Editor/UGEditDef.h"
#include "Map/UGLayer.h"


namespace UGC {


class EDITOR_API UGEditSnapElement
{
public:
	UGEditSnapElement();
    UGEditSnapElement(UGuint uAction ,UGint nID,UGLayer* pLayer );
	virtual ~UGEditSnapElement();
public:
	//设置捕捉的类型
	//uAction为：捕捉类型常量
    void    SetValue( UGuint uAction);

	//获得捕捉类型
    UGuint	GetValue();

	//和其他图素点水平、垂直、点和别的图素点重合、线和其他图素相交
	//将捕捉到的点加到捕捉元素中
    UGbool    SetPoint  ( const UGPoint2D& pnt2D );

	//和其他图素点水平、垂直、点和别的图素点重合、线和其他图素相交
	//从捕捉元素中读出捕捉点
    UGbool    GetPoint  ( UGPoint2D& pnt2D );

	//线段水平、垂直、固定长度、同一线段成固定角度、和其他图素线段平行、和其他图素线段垂直
	//将捕捉到的点加到捕捉元素中
    UGbool    SetPoint  ( const UGPoint2D& pnt2D1, const UGPoint2D& pnt2D2 );

	//线段水平、垂直、固定长度、同一线段成固定角度、和其他图素线段平行、和其他图素线段垂直
	//从捕捉元素中读出捕捉点
    UGbool    GetPoint  ( UGPoint2D& pnt2D1, UGPoint2D& pnt2D2 );
	
	//点在别的图素线上、点在线性图素的中点、在其他线性图素的延长线上时
	//将捕捉加到的点加到捕捉元素中
    UGbool    SetPoint  ( const UGPoint2D& pnt2D1, const UGPoint2D& pnt2D2 , const UGPoint2D& pnt2D3 );
	
	//点在别的图素线上、点在线性图素的中点、在其他线性图素的延长线上时
	//从捕捉元素中读出捕捉点
    UGbool    GetPoint  ( UGPoint2D& pnt2D1, UGPoint2D& pnt2D2 , UGPoint2D& pnt2D3 );
	
	//设置指定线上的指定节点
    UGbool    SetLineIndex( UGint lLineIndex, UGint lVertexIndex );
	
	//取得捕捉元素的指定线上的指定节点
    UGbool    GetLineIndex( UGint& lLineIndex, UGint& lVertexIndex );

	//判断两个捕捉元素是否相同
    UGbool    IsSameOne   ( const UGEditSnapElement* pElement );

	//是否应该删除指定元素
    UGbool    IsDeleteLine( const UGEditSnapElement* pElement );

	//判断一个捕捉要素是否有用
    UGbool    IsSelfUseful( const UGEditSnapElement* pElement );

		
	//将编辑的线段过某一点时，将捕捉到的节点加到对象中
	//point2D:捕捉到的点的坐标
	//bPrev:是否为前一条线段
    UGbool    GetSnapAddPoint( UGPoint2D& pnt2D, UGbool& bPrev );

	//added by xielin 2007-05-31
	//! \brief 获取该捕捉对象的ID
	UGint	  GetID();

	//added by xielin 2007-05-31
	//! \brief 设置该捕捉对象的ID
	void	  SetID(UGint nID);

	//! \brief 获取该捕捉对象所在图层指针
	UGLayer*	  GetLayer();

	//added by xielin 2007-05-31
	//! \brief 设置该捕捉对象所在图层指针
	void	  SetLayer(UGLayer* pLayer);

public:
//Attribute
    UGuint            m_uAction;
    UGPoint2D*       m_pPoints;
    UGint            m_lLineIndex;
    UGint            m_lVertexIndex;

	//added by xielin 2007-05-31  增加该捕捉到对象所在图层指针和该对象的id，返回给用户
	//总共返回给用户的信息有：ID，pLayer，SnapAction，SnapedPoints，后面两个已经有了
	UGint			m_nID;
	UGLayer*       m_pLayer;
	//added by xielin 2007-05-31 end
};

typedef UGList<UGEditSnapElement*> UGEditSnapElementList;

class EDITOR_API UGEditSnapBuffer  
{
public:
//Implement of structure
	UGEditSnapBuffer();
	virtual ~UGEditSnapBuffer();

//Implement of resolvent
    UGint     GetMaxSize();
    void    SetMaxSize( UGint uSize );
    UGbool    Push ( UGEditSnapElement* pElement );
    UGbool    Pop  ( UGEditSnapElement** ppElement );
	
	//将编辑的线段过某一点时，将捕捉到的节点加到对象中
	//point2D:捕捉到的点的坐标
	//nIndex:捕捉元素的索引
	//bPrev:是否为前一条线段
    UGbool    GetSnapAddPoint( UGPoint2D& pnt2D, UGint& nIndex, UGbool& bPrev );

	//通过索引，取得捕捉的线的索引和相应节点的的索引
    UGbool    GetLineIndex( UGint& nIndex, UGint& lLineIndex, UGint& lVertexIndex );

	//判断一个捕捉要素是否已存在
    UGbool    IsUnique( const UGEditSnapElement* pNewElement );

	//判断一个捕捉要素是否有用
    UGbool    IsUseful( UGEditSnapElement* pNewElement );

	//删除没用的捕捉元素
    UGbool    DeleteSnapedLine( const UGEditSnapElement* pNewElement );

	//从新设置捕捉缓冲区
    UGbool    ReSet();


    UGbool    ResetSP();

public:
//Attribute 
    UGRect2D                 m_rcLast;           // for user invalid rect
    UGuint                    m_uSnapType;        // user have done snap type
    UGint                     m_nBufferMaxSize;   // max length of the buffer
    UGint                     m_nSP;
    UGEditSnapElementList m_listBuffer;       // buffer body
};

}

#endif // !defined(AFX_UGEDITSNAPBUFFER_H__DECB27E6_E117_11D2_A58F_0080C8EE6684__INCLUDED_)
