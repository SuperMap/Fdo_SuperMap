// UGODBCCacheRecordset.h: interface for the UGODBCCacheRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCCACHERECORDSET_H__714DEB52_4A6F_46DA_B9A7_0F2CC5D6AD48__INCLUDED_)
#define AFX_UGODBCCACHERECORDSET_H__714DEB52_4A6F_46DA_B9A7_0F2CC5D6AD48__INCLUDED_


#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRectUInt.h"
#include "Geometry/UGGeometry.h"
#include "Base/UGVariant.h"
#include "UGODBCRecordset.h"

namespace UGC
{
class UGODBCDatasetVector;
class UGEXPORT UGODBCCacheRecordset: public UGODBCRecordset
{
public:
	UGODBCCacheRecordset();
	UGODBCCacheRecordset(UGODBCDatasetVector *pDataset);
	virtual ~UGODBCCacheRecordset();

	UGbool Open(UGArray<UGString> & aryField);

	virtual UGbool GetWordRectBounds(UGRectUInt & rcWdRectBounds);

	
	//! \brief 关闭记录集
	//! \param 
	virtual void Close();
	//! \brief 当前记录指针是否指向尾
	//  \param 
	virtual UGbool IsEOF();

	//! \brief 当前记录指针是否指向头
	//  \param 
	virtual UGbool IsBOF();

	//! \brief 得到当前记录的ID
	// \param
	virtual UGint GetID();

	//! \brief 是否记录集为空(没有记录)
	//  \param 
	virtual UGbool IsEmpty();

	//! \brief 取得几何对象
	//  \param 
	//  \remarks *geometry在函数内分配内存，外面负责删除，否则会有内存泄漏!
	virtual UGbool GetGeometry(UGGeometry *&geometry);

	//! \brief 获得字段的值
	//  \param	strName   字段的名字
	//  \param	varValue  返回的字段值
	//  \remarks 这个字段必须是OPEN的时候传入的字段.否则不好使
	virtual UGbool GetFieldValue(const UGString &strName, UGVariant& varValue );

	//! \brief 获得字段的值
	//  \param nIndex     字段的索引号
	//  \param varValue   返回的字段值
	//  \remarks 由于缓存模式字段信息问题,这个索引号不好用
	virtual UGbool GetFieldValue( UGint nIndex, UGVariant& varValue );


	//! \brief 将当前游标位置移动指定的行数
	//  \attention	只有当前游标类型为dynaset或是snapshot时才支持此操作
	//  \param nRows，移动的行数，如果为正数，向记录集尾方向移动，如果为负数，向记录集头方向移动
	//  \sa	MoveFirst,MoveLast, MoveNext, MovePrev, MoveTo, SeekID
	virtual UGbool Move(UGint nRows);

	//! \brief 将当前游标位置移动到记录集的头
	//  \attention	只有当前游标类型为dynaset或是snapshot时才支持此操作
	//  \sa	Move,MoveLast, MoveNext, MovePrev, MoveTo, SeekID
	virtual UGbool MoveFirst();

	//! \brief 将当前游标位置移动到记录集的尾
	//  \sa	MoveFirst,Move, MoveNext, MovePrev, MoveTo, SeekID
	virtual UGbool MoveLast();

	//! \brief 将当前游标位置向后移动一行
	//  \sa	MoveFirst,MoveLast, Move, MovePrev, MoveTo, SeekID
	virtual UGbool MoveNext();

	//! \brief 将当前游标位置向前移动一行
	//  \attention	只有当前游标类型为dynaset或是snapshot时才支持此操作
	//  \sa	MoveFirst,MoveLast, MoveNext, Move, MoveTo, SeekID
	virtual UGbool MovePrev();

	//! \brief 将当前游标位置移动到指定的行
	//  \param nRows，移动的目标位置
	//  \attention	只有当前游标类型为dynaset或是snapshot时才支持此操作
	//  \sa	MoveFirst,MoveLast, MoveNext, MovePrev, Move, SeekID
	virtual UGbool MoveTo(UGint nRows);

	virtual UGbool SeekID(UGint nID);

private:
	UGbool RefreshCurrentIdxItem();

	//! \brief　取数据
	UGbool FetchData(const UGString &strSQL);
	//! \brief 刷新当前记录
	void FlushCurrentRecord();
public:
	UGint m_nLibTileID;
private:
	FILE m_DataFile;
	UG_DATA_CACHE_FILE_HEADER m_dfh;
	UG_INDEX_CACHE_FILE_HEADER m_ifh;
	UGbyte * m_pIndexData;
	UGbyte * m_pGeoData;

	UGint m_nTotalGeoLen;
	UGint m_nCurrentPos;

	UG_SUPER_INDEX_ITEM  m_CurIndexItem;

	UGint m_nCurrentID;
};

}
#endif // !defined(AFX_UGODBCCACHERECORDSET_H__714DEB52_4A6F_46DA_B9A7_0F2CC5D6AD48__INCLUDED_)
