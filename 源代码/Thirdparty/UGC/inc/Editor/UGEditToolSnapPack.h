// SmEditToolSnapPack.h: interface for the UGEditToolSnapPack class.
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
// 文件名：			SmEditToolSnapPack.h
// 类  名：			UGEditToolSnapPack
// 父  类：			
// 子  类：			
// 功能说明：		控制捕捉的源点、源线
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITTOOLSNAPPACK_H__BFEE1573_E724_11D2_A5A2_0080C8EE6684__INCLUDED_)
#define AFX_UGEDITTOOLSNAPPACK_H__BFEE1573_E724_11D2_A5A2_0080C8EE6684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Base/ugexports.h"
#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeometry.h"
#include "Editor/UGEditDef.h"


namespace UGC {


class EDITOR_API UGEditToolSnapPack  
{
//Construct/Destruct
public:
	UGEditToolSnapPack();
	virtual ~UGEditToolSnapPack();
	
	//设置捕捉工具包的一些基本信息
	//uSnapPackType:
	//pPntSnaping:
	//uChangedType:
	//pObj:
	//nSnapHandle:
    void SetValue(  UGuint                uSnapPackType,
                    UGPoint2D*           pPntSnaping,
                    UGuint                uChangedType = AFC_SNAP_CHANGED_NONE,
                    UGGeometry*        pObj = NULL,
                    UGint                 nSnapHandle = 0 );
	
	//设置捕捉线
    void SetSnapedLine( const UGPoint2D& pnt1, const UGPoint2D& pnt2 );
	
	//取得捕捉线
    UGbool GetSnapedLine( UGPoint2D& pnt1, UGPoint2D& pnt2 );

	//清空捕捉工具包参数
    void Reset();
//Attrubute
public:
    UGuint   m_uSnapPackType;//捕捉工具包类型
    UGuint   m_uChangedType;//可以改变的捕捉类型
    UGPoint2D*   m_pPntSnaping;//当前的捕捉源点
    UGGeometry* m_pObj;//编辑对象

    UGint  m_nSnapHandle;//捕捉句柄
protected:
    UGPoint2D*   m_pPntSnapedLine;//当前进行捕捉的线
};

}

#endif // !defined(AFX_AFCEDITTOOLSNAPPACK_H__BFEE1573_E724_11D2_A5A2_0080C8EE6684__INCLUDED_)
