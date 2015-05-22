// UGEditSnapGrid.h: interface for the UGEditSnapGrid class.
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
// 文件名：			UGEditSnapGrid.h	
// 类  名：			UGEditSnapPoints、UGEditSnapVertexs、UGEditSnapLineChart、UGEditSnapLineGrid、UGEditSnapPointGrid
// 父  类：			
// 子  类：			
// 功能说明：		UGEditSnapPoints:捕捉的点索引
//					UGEditSnapVertexs:捕捉的节点索引
//					UGEditSnapLineChart:捕捉线表
//					UGEditSnapLineGrid:捕捉线网格
//					UGEditSnapPointGrid:捕捉点网格
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_AFCEDITSNAPGRID_H__12695D03_E19B_11D2_A590_0080C8EE6684__INCLUDED_)
#define AFX_AFCEDITSNAPGRID_H__12695D03_E19B_11D2_A590_0080C8EE6684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Algorithm/UGPoint2D.h"
#include "Editor/UGEditDef.h"
#include "Geometry/UGEditType.h"
#include "Map/UGLayer.h"

namespace UGC {

class EDITOR_API UGEditSnapPoints 
{
//Constructs/Destructs
public:
    UGEditSnapPoints();
    virtual ~UGEditSnapPoints();

//Implement
	//取出一个点的索引
	//nIndex:点索引的索引
	//lPointIndex:点的索引的值
	void GetAt(UGint nIndex, UGint& lPointIndex );

	//设置一个点的索引
	//nIndex:点索引的索引
	//lPointIndex:点的索引的值
	void SetAt(UGint nIndex, UGint lPointIndex );
	UGint  Add  (UGint lPointIndex );

	//取得点索引的数目
    inline UGint  GetSize( ) const { return m_PointIndexArray.GetSize(); };

	//取得上限
	inline UGint  GetUpperBound( ) const { return m_PointIndexArray.GetUpperBound(); };

public:
    UGArray<UGint>    m_PointIndexArray;//捕捉点索引
};

class EDITOR_API UGEditSnapVertexs
{
//Constructs/Destructs
public:
    UGEditSnapVertexs();
    virtual ~UGEditSnapVertexs();

//Implement
    //取出索引
	void GetAt(UGint nIndex, UGint& lLineIndex, UGint& lVertexIndex );

	//设置索引
	void SetAt(UGint nIndex, UGint lLineIndex, UGint lVertexIndex );

	//添加一个索引
	UGint  Add  (UGint lLineIndex, UGint lVertexIndex );

	//返回指定的节点是否唯一
    UGbool IsUnique( UGint lLineIndex, UGint lVertexIndex );

	//取得保存的索引的数量
    inline UGint  GetSize( ) const { return m_LineIndexArray.GetSize(); };

	//取得保存的索引的上限
	inline UGint  GetUpperBound( ) const { return m_LineIndexArray.GetUpperBound(); };

public:
    UGArray<UGint>    m_LineIndexArray;  //线索引的数组
    UGArray<UGint>    m_VertexIndexArray;//节点索引数组
};



class EDITOR_API UGEditSnapPointGrid  
{
//Constructs/Destructs
public:
	UGEditSnapPointGrid( UGint lGridCount = 20 );
	virtual ~UGEditSnapPointGrid();

//Implement
public:
    void Reset( UGint lGridCount = 20 );

//Attribute
public:
    UGint                    m_lPointGridCount;  //捕捉点的计数
    UGEditSnapPoints*     m_pGridPointUnits;   //捕捉点索引数组
    UGPnt2DArray             m_Pnt2DArray;		//捕捉点数组	
	//added by xielin 2007-05-31  增加保存捕捉点所在对象的id和所在对象所处的图层指针
	UGArray<UGint>			m_aryIDs;
	UGArray<UGLayer*>       m_aryLayers;
	//added by xielin 2007-05-31 end

};



class EDITOR_API UGEditSnapLineGrid  
{
//Constructs/Destructs
public:
	UGEditSnapLineGrid( UGint lVertexGridCount = 20, UGint lLineGridCount = 20 );
	virtual ~UGEditSnapLineGrid();

//Implement
public:
    void Reset( UGint lVertexGridCount = 20, UGint lLineGridCount = 20 );

//Attribute
public:
    UGint                    m_lVertexGridCount;//节点总数
    UGint                    m_lLineGridCount;//线总数
    UGEditSnapVertexs*    m_pGridVertexUnits;//节点索引数组
    UGEditSnapVertexs*    m_pGridSectUnits;//线段索引数组
	UGLineArray              m_LineArray;//线段数组
	//added by xielin 2007-05-31  增加保存捕捉点所在对象的id和所在对象所处的图层指针,再增加一个保存线段是属于第几个sub对象的数组
	UGArray<UGint>			m_aryIDs;
	UGArray<UGLayer*>       m_aryLayers;
	//UGArray<UGint>			m_arySubIndex;
	//added by xielin 2007-05-31 end
};

//UGEditSnapLineChart类可以不使用了，先留着吧
class UGEditSnapLineChart
{
//Constructs/Destructs
public:
    UGEditSnapLineChart();
    virtual ~UGEditSnapLineChart();

//Implement
public:
    void Create( UGint nGeometryBaseIndex );//生成捕捉线表
	void Add   ( UGint lGeometryID, UGint lSubLineIndex ,UGLayer* pLayer); //添加一个捕捉几何对象和捕捉线的索引
    UGbool GetGeometryInfo( UGint nLineIndex, UGint& lGeometryID, UGint& lSubLineIndex,UGLayer*& pLayer );//取得一个捕捉几何对象和捕捉线的索引还有geometry所在图层
    void Reset();//清空

//Attribute
public:
    UGbool                    m_bEnable;
    UGint                     m_nBaseIndex;
    UGArray<UGint>        m_arrayGeometrysID;//被捕捉的几何对象的ID数组
    UGArray<UGint>        m_SubLineIndexArray;//捕捉子线段的索引
	//added by xielin 2007-05-31  增加保存捕捉点所在对象所处的图层指针
	UGArray<UGLayer*>       m_aryLayers;
	//added by xielin 2007-05-31 end
};
/*
typedef CTypedPtrArray <CPtrArray, UGImgGrid*> UGImgArray;

class UGEditSnapImgArray
{
//Constructs/Destructs
public:
    UGEditSnapImgArray();
    virtual ~UGEditSnapImgArray();

//Implement
public:
	void GetAt(UGint nIndex, UGImgGrid** pImg );
	void SetAt(UGint nIndex, UGImgGrid* pImg );
	UGint  Add  (UGImgGrid* pImg );

    inline UGint  GetSize( ) const { return m_arraySmImg.GetSize(); };
	inline UGint  GetUpperBound( ) const { return m_arraySmImg.GetUpperBound(); };
    void Reset();

//Attribute
public:
    UGImgArray            m_arraySmImg;
};
*/
}

#endif // !defined(AFX_AFCEDITSNAPGRID_H__12695D03_E19B_11D2_A590_0080C8EE6684__INCLUDED_)
