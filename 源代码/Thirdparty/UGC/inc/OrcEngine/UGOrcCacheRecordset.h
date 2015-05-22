// UGOrcCacheRecordset.h: interface for the UGOrcCacheRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCCACHERECORDSET_H__60D395E7_A724_492F_A4F8_721C3485CD29__INCLUDED_)
#define AFX_UGORCCACHERECORDSET_H__60D395E7_A724_492F_A4F8_721C3485CD29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGOrcRecordset.h"
#include "Base/UGArray.h"
#include "Base/UGVariant.h"
#include "Base/UGFileStream.h"
#include "Algorithm/UGRect.h"

namespace UGC {

//ColumnValues存储一列的数据
class UGColumnValues
{
public:
	UGString strFieldName;
	UGArray<UGVariant> varValues;
	void operator =(UGColumnValues colValues)
	{
		strFieldName = colValues.strFieldName;
		varValues.SetSize(colValues.varValues.GetSize());
		for(UGint i=0;i<colValues.varValues.GetSize();i++)
		{
			varValues[i] = colValues.varValues[i];
		}
	};
};

typedef UGArray<UGColumnValues> DtAttrValues;

class UGOrcCacheRecordset : public UGOrcRecordset  
{
public:
	UGOrcCacheRecordset();
	UGOrcCacheRecordset(UGOrcDatasetVector * pDataset);
	virtual ~UGOrcCacheRecordset();

private:
	//添加下面三个函数，用于将属性数据加载到内存中，提高速度
	UGbool LoadColAttrValues(const UGString &strColName);
	void ReleaseColAttrValues(const UGString &strColName);
	void ReleaseAllAttrValues();

	UGbool RefreshCurrentIdxItem();
	UGbool FetchData(const UGString &strSQL);
	ub2 GetOCIType(UGint nDAOType);

public:
	virtual UGbool GetWordRectBounds(UGRect & rcWdRectBounds);
	
	UGbool Open(UGArray<UGString>& aryField);
	
public:
	//! 按某种统计方法统计某个字段
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! 获取当前记录的ID
	virtual UGint GetID();
	
	//! 判断当前记录指针是否指向头
	virtual UGbool IsBOF();
	
	//! 判断当前记录指针是否指向尾
	virtual UGbool IsEOF();
	
	//! 关闭记录集
	virtual void Close();

//	virtual UGbool IsEmpty() ;	//是否记录集为空(没有记录)
	
	//! 取得几何对象，返回的几何对象指针在函数内分配内存，
	//! 外面负责删除，否则会有内存泄漏
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);
	
	//! 通过字段名获取字段值
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);
	
	//! 通过索引序号获取字段值
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

//	virtual BOOL GetGeometryBounds(CRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);	//取得几何对象的三维Bounds
	
	//! 给定相应的数,向前或向后移动记录指针
	virtual UGbool Move(UGint nRows);
	
	//! 移动记录指针到最前
	virtual UGbool MoveFirst();
	
	//! 移动记录指针到最后
	virtual UGbool MoveLast();
	
	//! 向下移动一位记录指针
	virtual UGbool MoveNext();
	
	//! 向上移动一位记录指针
	virtual UGbool MovePrev();
	
	//! 移动记录指针到指定位置
	virtual UGbool MoveTo(UGint nRow);
	
	//! 通过ID定位记录指针
	virtual UGbool SeekID(UGint nID);

	//属性 
	UGString GetFilter() const {return m_strFilter;}

	//! 获取记录个数
	virtual UGint GetRecordCount();

	//! 刷新记录
	virtual void FlushCurrentRecord();

	//! 计算记录集的范围
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);

private:
	DtAttrValues m_attrValues;
	UGRect2D m_rc2Bounds;
	UGint m_nCurrentPos;
	
	UGOCIBind m_OCIBind;
	
	UGint m_nCurrentID;
	
	UGint m_nTotalGeoLen;
	UGFileStream m_DataFile;
	UG_DATA_CACHE_FILE_HEADER m_dfh;
	UG_INDEX_CACHE_FILE_HEADER m_ifh;
	UG_SUPER_INDEX_ITEM  m_CurIndexItem;

	UGbyte * m_pIndexData;
	UGbyte * m_pGeoData;

public:		
	//我的公有财产
	UGint m_nLibTileID;
};

}
#endif // !defined(AFX_UGORCCACHERECORDSET_H__60D395E7_A724_492F_A4F8_721C3485CD29__INCLUDED_)
