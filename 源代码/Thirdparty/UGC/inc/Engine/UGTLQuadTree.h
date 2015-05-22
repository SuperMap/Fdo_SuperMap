//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			李绍俊
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	2004-4-7
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			TLQuadTree.h
// 类  名：			UGTLQuadTree (Three Level Quad Tree)
// 父  类：			
// 子  类：			
// 功能说明：		 处理有关四叉树操作的类。
// 调用说明：		
//					
//					
//------------------------------------------------------------------------------------------------
//! 修改说明: by zengzm 2007-4-10 添加注释, 调整代码, 解决在BigEndian上的隐患

#if !defined(AFX_UGTLQUADTREE_H__8AE407D7_0CC9_40A3_B2D8_21C73CEA7276__INCLUDED_)
#define AFX_UGTLQUADTREE_H__8AE407D7_0CC9_40A3_B2D8_21C73CEA7276__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGString.h"

namespace UGC
{

// 该宏放到cpp中,只有cpp中才会用到
// #define MacroForGetXEveryBit(x,y)


//! \brief 四叉树类。
class ENGINE_API UGTLQuadTree  
{
	union unPosition
	{
		UGushort s;
		struct
		{
			unsigned a1:1;
			unsigned a2:1;
			unsigned a3:1;
			unsigned a4:1;
			unsigned a5:1;
			unsigned a6:1;
			unsigned a7:1;
			unsigned a8:1;
			unsigned a9:1;
			unsigned a10:1;
			unsigned a11:1;
			unsigned a12:1;
			unsigned a13:1;
			unsigned a14:1;
			unsigned a15:1;
			unsigned a16:1;
		} a;
	};

public:
	//! \brief 默认构造函数
	UGTLQuadTree();
	//! \brief 析构函数
	virtual ~UGTLQuadTree();
	
	//! \brief 设置需要格子的层数
	void SetLevel(UGshort nLevel);
	//! \brief 设置需要打格子的Bounds
	void SetEntireBounds(UGRect2D rc2EntireBounds);
	//! \brief 同时设置格子的层数和Bounds
	void SetEntireBounds(UGRect2D rc2EntireBounds,UGshort nLevel);

	//! \brief 通过需要查询的bounds来得到 sql语句
	UGString BuildQdTreeSQL(UGRect2D rc2QueryBounds);

	//! \brief 得到可以 封装(envelop) 某个地理范围 的 最小格子(层次不定) 的编码
	UGint GetKeyByBounds(UGRect2D &rc2ObjBounds);
	//! \brief 得到可以 封装(envelop) 某个地理范围 的 最小格子(层次不定) 的编码
	UGint GetKeyByBounds(UGRect2D *prc2ObjBounds);

	//! \brief 
	UGint GetKeyByWNES(UGdouble dLeft,UGdouble dTop,UGdouble dRight,UGdouble dBottom);
	//! \brief 得到指定层次,指定 行列的格子 的编码(不带level的6位)
	UGint GetPointKeyByPosition(UGint nX,UGint nY,UGshort nLevel);
	//! \brief 得到 可以封装(envelop) 最大层的格子（X1 Y1到X2 Y2）的 最小的格子（层次不定）的编码
	UGint GetKeyByPosition(UGint nX1,UGint nY1,UGint nX2,UGint nY2);
	//! \brief 根据编码得到对应的Bounds
	UGbool GetBoundsByKey(UGint nKey,UGRect2D & rc2Bounds);
	//! \brief 判断两个编码(key)所对应的Bounds是否有交叠
	UGbool Intersect(UGint nKey1,UGint nKey2);

private:
	//! \brief 需要构造索引的bounds
	UGRect2D m_rc2EntireBounds;
	//! \brief bounds的left
	UGdouble m_dLeft;
	//! \brief bounds 的bottom
	UGdouble m_dBottom;
	//! \brief bounds的width
	UGdouble m_dWidth;
	//! \brief bounds的height
	UGdouble m_dHeight;
	//! \brief 一共分的层次数目
	UGshort m_nTotalLevel;
	//! \brief 当前正在处理的层次
	UGshort m_nCurLevel;
	//! \brief 当前层次，一个格子所代表的水平地理距离
	UGdouble m_dHOffset;
	//! \brief 当前层次，一个格子所代表的垂直地理距离
	UGdouble m_dVOffset;
	//! \brief 得到某一层的 格子（X，Y） 的 编码(不带level的6位)
	UGint GetPointKeyByPosition(unPosition X,unPosition Y,UGshort nLevel);
	//! \brief 得到 可以封装(envelop) 最大层的格子（X1 Y1到X2 Y2）的 最小的格子（层次不定）的编码
	UGint GetKeyByPosition(unPosition X1,unPosition Y1,unPosition X2,unPosition Y2);
	//! \brief 内部比较函数
	static UGint S_compare_ids (const void  *id_ptr_1,const void  *id_ptr_2);

};

}
#endif // !defined(AFX_QUADTREE_H__8AE407D7_0CC9_40A3_B2D8_21C73CEA7276__INCLUDED_)
