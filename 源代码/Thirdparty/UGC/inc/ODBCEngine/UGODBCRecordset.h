// UGODBCRecordset.h: interface for the UGODBCRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCRECORDSET_H__5FB2901F_798F_425F_BEA5_0BFB1321B7BA__INCLUDED_)
#define AFX_UGODBCRECORDSET_H__5FB2901F_798F_425F_BEA5_0BFB1321B7BA__INCLUDED_

#include "Engine/UGRecordset.h"
#include "ODBCEngine/UGODBCDatasetVector.h"
#include "ODBCEngine/UGODBCConnection.h"
#include "Algorithm/UGRect.h"


namespace UGC
{
class UGEXPORT UGODBCRecordset  : public UGRecordset
{
public:
	UGODBCRecordset();
	UGODBCRecordset(UGODBCDatasetVector *pDatasetVector);
	virtual ~UGODBCRecordset();

public:
	//! \brief  删除所有记录
	virtual UGbool DeleteAll();

	//! \brief  按某种统计方法统计某个字段
	//! \param　strField　要统计的字段名[in]
	//! \param	nMode     统计的模式
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! \brief  刷新记录集,一般就是重新查询一遍
	virtual UGbool Refresh();

	//! \brief  复制字段值,
	//! \param SrcField　	源字段名[in]
	//! \param strDestField 目标字段名[in]
	//! 两个字段在数据库中必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);
	
	//! \brief  获取当前记录的ID
	virtual UGint GetID();

	//! \brief 是否记录集为空(没有记录)
	virtual UGbool IsEmpty();

	//! \brief  判断当前记录指针是否指向头
	virtual UGbool IsBOF();

	//! \brief  判断当前记录指针是否指向尾
	virtual UGbool IsEOF();
	
	//! \brief 关闭记录集
	virtual void Close();

	//! \brief  直接读出几何对象的指针,对于把所有数据都读到内存中的引擎(如dgn)来说，
	//! \brief  不需要拷贝几何对象，外面也不要去删除它,这样可以加快访问速度
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry);

	//! \brief  取得几何对象，返回的几何对象指针在函数内分配内存，
	//! \brief  外面负责删除，否则会有内存泄漏
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! \brief  通过字段名获取字段值
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! \brief  通过索引序号获取字段值
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! \brief  设置当前记录的几何对象
	virtual UGbool SetGeometry(UGGeometry &geometry);

	//! \brief  通过字段名设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! \brief  通过字段名设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! \brief  通过索引序号设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! \brief  通过索引序号设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);

	//! \brief  通过字段名设置字段值为空
	virtual UGbool SetFieldValueNull(const UGString& strName);

	//! \brief  通过索引设置字段值为空
	virtual UGbool SetFieldValueNull(UGint nIndex);

	//! \brief  在记录集中再次查询,查找符合条件的第一条记录
	virtual UGbool FindFirst(const UGString& strFilter);
	
	//! \brief  在记录集中再次查询,查找符合条件的最后一条记录
	virtual UGbool FindLast(const UGString& strFilter);

	//! \brief  在记录集中再次查询,查找符合条件的下一条记录
	virtual UGbool FindNext(const UGString& strFilter);

	//! \brief  在记录集中再次查询,查找符合条件的上一条记录
	virtual UGbool FindPrev(const UGString& strFilter);

	//! \brief  给定相应的数,向前或向后移动记录指针
	virtual UGbool Move(UGint nRows);

	//! \brief  移动记录指针到最前
	virtual UGbool MoveFirst();

	//! \brief  移动记录指针到最后
	virtual UGbool MoveLast();

	//! \brief  向下移动一位记录指针
	virtual UGbool MoveNext();

	//! \brief  向上移动一位记录指针
	virtual UGbool MovePrev();

	//! \brief  移动记录指针到指定位置
	virtual UGbool MoveTo(UGint nRow);

	//! \brief  通过ID定位记录指针
	virtual UGbool SeekID(UGint nID);

	//! \brief  获取记录个数
	virtual UGint GetRecordCount();

	//! \brief  收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos);
	
	//! \brief  通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! \brief  通过索引取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! \brief  获取字段个数
	virtual UGint GetFieldCount();
	
	//! \brief  更新，提交修改
	virtual UGint Update();

	//! \brief  取消修改
	virtual UGbool CancelUpdate();
	
	//! \brief  开始修改数据
	virtual UGbool Edit();

	//! \brief  添加新记录
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! \brief  删除当前记录
	virtual UGbool Delete();

	//! \brief  刷新记录
	virtual void FlushCurrentRecord();
	
	//! \brief  是否支持事务
	virtual UGbool CanTransact() const;

	//! \brief  是否可更新
	virtual UGbool CanUpdate();

	//! \brief  是否可添加
	virtual UGbool CanAppend();

	//! \brief 是否支持指定的操作
	virtual UGbool IsSupport(UGEngAction nAction);

	//! \brief  计算记录集的范围
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);

	//! \brief  非长事务状态下的锁定
	virtual UGbool Lock();

	//! \brief  非长事务状态下的解锁
	virtual UGbool UnLock();

	//! \brief  得到当前记录被谁给锁定了
	virtual UGString GetRecordCheckedBy();

	//! \brief  长事务相关函数
	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut);	
	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut);
	virtual UGbool CheckOutCurrent();
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool CheckOut();

	//! \brief 得到当前记录几何对象的范围
	//! \param rc2Bounds	几何对象的二维范围
	//! \param dMinZ		几何对象的最小高程(保留参数，留待后用)
	//! \param dMaxZ		几何对象的最大高程(保留参数，留待后用)
	//! \sa	GetGeometry
	virtual UGbool GetGeometryBounds(UGRect2D &rc2Bounds,
		UGdouble& dMinZ,UGdouble& dMaxZ);

	//! \brief  特殊的外键查询
	virtual UGbool GetForeignKeysVal(UGArray<UGString> &aryForeignKeys,UGArray<UGVariant> &aryVal);
	//! \brief  获取外键查询的值
	virtual UGbool FetchForeignKeysVal(UGArray<UGVariant> &aryVal);

	//! \brief  根据查询选项获取ID
	//! \param aryIDs	IDs数组[out]
	//! \param queryDef	查询选项[in]
	UGbool GetIDsByQueryDef(UGArray<UGint> &aryIDs,UGQueryDef queryDef);

	//! \brief 根据Numeric计算Double值
	//! \param	Numeric　[in]
	//! \return Double值
	UGdouble Numeric2Double(SQL_NUMERIC_STRUCT &Numeric);

public:
	//! \brief 创建记录集
	//! \param queryDef 查询选项[in]
	UGbool Create(const UGQueryDef& queryDef);

	//! \brief 外挂查询创建记录集
	//! \param linkItem 外挂查询选项
	UGbool Create2(UGLinkItem &linkItem);
	
	UGbool InitFields();

	//! \brief版本数据集过滤掉D表的ID，再获取A表的ID
	//! \remark 版本查询时需要
	//! \param  rcBounds	查询的范围	[in]
	//! \param	aryItemIDs	查出来的ID会追加到该数组内[in/out]
	UGbool RefineVersionTabIDs(UGRect2D rcBounds, UGArray<UGint> &aryItemIDs);
protected:
	//! \brief 判断记录集是否打开
	UGbool IsOpen();
	//! \brief General查询
	//! \param queryDef 查询选项[in]
	virtual UGbool CreateWithGeneral(const UGQueryDef &querydef);
	//! \brief IDs查询
	//! \param pIDs id数组[in]
	//! \param　nCount　id数目[in]
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGString &strFieldName);
	//! \brief Bounds查询
	//! \param rc2Bounds 查询范围[in]
	//! \param　nOptions　选项信息[in]
	virtual UGbool CreateWithBounds(const UGRect2D &rc2Bounds, UGint nOptions, UGint  nMode);

	//! \brief 根据条件过滤ID
	//! \param strFilter  过滤条件[in]
	//! \param aryItemIDs IDs数组[in]
	void EnhanceIDs(UGString &strFilter,UGArray<UGint> &aryItemIDs);

	//! \brief 计算记录数目
	//! \param strSQL  SQL语句[in]
	UGint StatisticRecordCount (const UGString& strSQL);

	//! \brief 构造Bounds查询的SQL语句
	//! \param rc2Bounds  查询的范围[in]
	UGString BuildBoundsSQL(const UGRect2D &rc2Bounds);
	//! \brief 构造General查询的SQL语句
	UGString BuildGeneralSQL();
	UGString BuildLTFilter();
	
	//! \brief 对字段进行过滤
	//! \param　fields 字段数组[in]
	void CheckFields(UGArray<UGString> &fields);
	//! \brief 对字段信息进行过滤
	//! \param　cursor　用游标来对字段信息过滤[in]
	//! \param　fieldInfos 字段信息[out]
	UGbool OrganiseFields(UGODBCCursor &cursor,UGFieldInfos &fieldInfos);

	//! \brief 获得连接
	UGODBCConnection * GetConnection();

	//! \brief 清空内存
	void ClearBuffer();
	//! \brief 刷新内存
	void ResetBuffer();

	//! \brief 刷新记录集
	UGbool RefreshPos();

	//! \brief  版本数据集 视图名替换表名
	UGString ReplaceTNameByVName(UGString strSQL);

	//! \brief  外挂表查询
	UGbool PrepareLink();

	//! \brief  网格索引的查询
	UGString BuildDynamicSQL(UGRect2D SearchBounds);

	//! \brief  计算某范围经过的网格
//	UGbool FindQueryGrids();

	//! \brief  分析QueryDefine，判断是否需要扩充查询字段
	UGbool IsStatisticalQuery();

	//! \brief  判断数据集是否是点集
	UGbool IsEnableGranule();

	//! \brief 获取SmKey=0（不被R树索引管理的）ID
	UGbool GetNonRTreeIDs(UGRect2D rcBounds, UGArray<UGint> &aryIDs);

	//! \brief 获取SmIDs,通过其他字段的ID查询
	UGbool GetIDsByFieldQuery(UGint *pIDs,UGint nCount,UGString &strFieldName);
private:

	//! \brief 获取数据
	UGbool FetchData (const UGString & strSQL);

	//! \brief 外挂表获取数据
	UGbool FetchData2(const UGString & strSQL);

public:
	UGArray<UGRecordset *> m_AryLinkRecords;

protected:
	UGFieldInfos m_fieldInfos;
	// 二进制字段的处理
	UGFieldInfos m_BinaryFieldInfos;
	UGbool m_bOpen;
	UGString m_strFilter;
	UGint m_nRecordCount;
	UGint  m_nCurrentIndex;

	UGArray<UGString> m_Fields;
	UGbool m_bStatistic;

	UGODBCCursor m_GeometryCursor;
	
	UGint	m_nAttrRowSize;
	UGbool	m_bQueryByID;
	UGint	*m_pIndicator;
	UGint *	m_pBindIDs;
	UGArray<UGint> m_arrIDs;
	UGint m_nGeoRowSize;
	UGuchar	*m_pAttrBuffer;
	UGuchar *m_pGeoBuffer;
	UGint m_nBeginIndex;
	UGint m_nEndIndex;
	UGint m_nOnceFetchCount;
	UGint m_nReturnRow;
	UGint m_nEditMode;

	UGint m_nGeoPos;
		
	UGint m_nBindFetchIDsCount;

	UGODBCBinds m_Binds;
	UGODBCBinds m_DefineBinds;

	// 具体查询的语句
	UGString m_strSql;
	UGODBCBinds m_aryDefine;

	// Dynamic查询框的grids
//	UGArray<UGRect> m_aryGrids;
	UGArray<UGPoint> m_aryGrids;
	// 查询框的Bounds
	UGRect2D m_rcDynamicBounds;

	UGString m_strDynamicSql;

};

}

#endif // !defined(AFX_UGODBCRECORDSET_H__5FB2901F_798F_425F_BEA5_0BFB1321B7BA__INCLUDED_)
