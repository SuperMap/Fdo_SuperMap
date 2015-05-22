// SdbRecordset.h: interface for the UGSdbPlusRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBRECORDSETPlus_H__017098A9_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)
#define AFX_SDBRECORDSETPlus_H__017098A9_099E_11D3_92D2_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGVariant.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGQueryDef.h"
#include "Engine/UGDatasetVectorInfo.h"

//#define SURVEYVERSION//added by shiww,请勿删除,对系统没有影响,如果没定义该宏
#define WM_RECORDSETSTATE WM_USER+2000
#define dbEditOfGeometry 3	//dbEditInProgress的一种,它包括空间数据的更改
//=======================================================
// 本工程各类的关系看起来似乎很复杂，其实很简单...
// 请查看Readme.txt文件的有关说明
//=======================================================

namespace UGC {

class UGSdbPlusDatasetVector;
class UGFileLogical;

class SDBPLUSENGINE_API UGSdbPlusRecordset : public UGRecordset  
{
	
public:
	UGSdbPlusRecordset();
	UGSdbPlusRecordset(UGSdbPlusDatasetVector *pDataset);
	~UGSdbPlusRecordset();

public:		//method
	UGbool HasField(UGString strFieldName);

	UGint GetID();	//当前记录ID
	UGbool IsEmpty();	//是否记录集为空(没有记录)
	UGbool IsBOF();	//当前记录指针是否指向头
	UGbool IsEOF();	//当前记录指针是否指向尾

	void Close();	//关闭
	
	//读字段值 
	UGbool GetFieldValue(const UGString &strName, UGVariant& varValue );	//根据字段名得到字段值
	UGbool GetFieldValue( UGint nIndex, UGVariant& varValue );	//根据字段序号得到字段值
	UGbool GetGeometryDirect(UGGeometry* &geometry);	//本引擎不支持!!!
	UGbool GetGeometry(UGGeometry *&geometry);	//得到geometry的指针,用完后请注意删除
	UGbool GetGeometryBounds(UGRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);	//得到三维Bounds,两维对象dMinZ与MaxZ无意义

	//写字段值
	UGbool SetFieldValue(const UGString &strName, const UGVariant& varValue);	//Set SDD field value according to field name
	UGbool SetFieldValue(UGint nOrdinal, const UGVariant& varValue);	//Set SDD field value according to field index
	UGbool SetFieldValue(const UGString &strName, const UGString &strValue); //Set SDD field value as string according to field name
	UGbool SetFieldValue(UGint nOrdinal, const UGString &strValue);	//Set SDD field value as string according to field index
	UGbool SetFieldValueNull(const UGString &strName);	//Set SDD field value to NULL according to field name
	UGbool SetFieldValueNull(UGint nOrdinal);	//Set SDD field value to NULL according to field index
	virtual UGbool SetGeometry(UGGeometry &geometry);	//set geometry

	//查找
	UGbool FindFirst(const UGString &strFilter) ;		//Locates the first record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.
	UGbool FindLast(const UGString &strFilter) ;		//Locates the last record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.
	UGbool FindNext(const UGString &strFilter) ;		//Locates the next record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.
	UGbool FindPrev(const UGString &strFilter) ;		//Locates the previous record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.

	UGbool Move(UGint nRows);	//Position the recordset nRows records from the current record
	UGbool MoveFirst();		//Positions the current record on the first record in the recordset. 
	UGbool MoveLast();		//Positions the current record on the last record in the recordset. 
	UGbool MoveNext();		//Positions the current record on the next record in the recordset .
	UGbool MovePrev();		//Positions the current record on the previous record in the recordset.

	UGbool MoveTo(UGint nRows);	//Position the recordset nRows records from the first record
	UGbool SeekID(UGint nID);	//Positions the current record on the one which SmId==nID

	//属性
	UGString GetFilter() ;	//return the property fileter of query
	UGint GetRecordCount();	//return the record count in itself

	//字段
	UGbool GetFieldInfos(UGFieldInfos &fieldInfos/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//Get all fieldinfos
	UGbool GetFieldInfo(const UGString &strName, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//Get fieldinfo according to the field name
	UGbool GetFieldInfo(UGint nIndex, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//Get fieldinfo according to the field index
	UGint GetFieldCount();	//Get SDD fields coutn,not including Geometry

	//记录更新
	//dbEditNone(0) -- No editing operation is in progress. 
	//dbEditInProgress(1) -- Edit has been called. 
	//dbEditAdd(2) -- AddNew Edithas been called. 
	short GetEditMode();	//取得EditMode,含义见上

	//! \brief 增加新记录,成功，返回TRUE值，失败返回FALSE值；
	//! \param *pGeometry [in] 添加的Geometry指针
	//! \param bReturnID=FALSE [in] 此参数已经不起作用。
	//! \return True 和 False 的值
	//! \remarks 如果想得到新对象的ID，那么马上调用GetId方法
	virtual UGint AddNew(UGGeometry *pGeometry,UGbool bReturnID=FALSE);	
	virtual UGbool Edit();	//SetXXX前需要设置Edit状态
	virtual UGint Update();	//Addnew或SetXXX更新,注意空间数据update前不可删除
	virtual UGbool CancelUpdate();//取消Update
	virtual UGbool Delete();	//记录删除
	virtual UGbool DeleteAll();		//删除所有的记录
	virtual void FlushCurrentRecord();	//记录刷新
	virtual UGbool Refresh();			//刷新记录集
	
	//状态
	UGbool CanTransact() const;	//return the status of transacted
	UGbool CanUpdate();	//return the status of updatable
	UGbool CanAppend();	//return the status of appendable
	virtual UGbool IsSupport(UGEngAction nAction);


	//计算项
	UGbool ComputeBounds(UGRect2D &rc2Bounds,double &dMinZ,double &dMaxZ);	//计算本Recordset的Bounds,通过参数引用返回结果
	UGVariant Statistic(const UGString& strField,UGStatisticMode nMode);		//统计功能
	UGbool CopyField(const UGString& strSrcField,const UGString& strDestField); //字段值拷贝，strSrcField和strDestField必须都存在且字段类型匹配，字段类型匹配表参看CDatasetVector.h
	
	//! 非长事务状态下的锁定
	virtual UGbool Lock();

	//! 非长事务状态下的解锁
	virtual UGbool UnLock();

	//! 得到当前记录被谁给锁定了
	virtual UGString GetRecordCheckedBy();

	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut);
	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut);
	virtual UGbool CheckOutCurrent();
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool CheckOut();
	
//	UGbool Export2Txt(UGString strFileName,		//得到的文本文件的路径和名字
//					   double dGridSize,		//*************************
//					   UGString strTerminate = "--$",		//用以间隔字节段的间隔符
//					   UGint nMinSmID = 1			//起始的SmID
//					   );		
//	UGbool ExportSqlPlusTxt(UGString strFileName,		//得到的文本文件的路径和名字
//						  UGint & nRecordCount,
//						   UGRect2D & rc2Bounds,		//*************************
//						   UGString strTerminate = "--$", /*= '--$'*/		//用以间隔字节段的间隔符
//						   UGint nMinSmID = 1,			/* = 0 */
//						  UGbool bShowProgressCtrl = TRUE
//						  );
//	UGbool ExportSybaseTxt( UGString strFileName,		//得到的文本文件的路径和名字
//						   UGint & nRecordCount,
//						   UGRect2D & rc2Bounds,		//*************************
//						   UGString strTerminate = "--$", /*= '--$'*/		//用以间隔字节段的间隔符
//						   UGint nMinSmID = 1			/* = 0 */
//						   );

protected:	//attribute

//	UGQueryDef m_querydef;

	CDaoRecordset m_Recordset;			//查询MDB时使用
	UGSdbPlusRecordset *m_prsTINVertex;	//TIN图层查询TINVertex图层端点的空间数据

	BYTE *m_pInSplFilter;			//存储检索标志,按bit存储
									//每一bit对应于DatasetVector中的一条记录索引
									//1 -- 选中,0 -- 未选中
	
	UGint m_nCurrentPos;				//当前记录
	UGint m_nRecordCount;			//记录数
	UGint m_nFirst,m_nLast;			//第一条和最后一条记录指针
	UGint m_nAbsolutePosition;		//当前绝对位置，即在Recordset中处在第几行,注意，它从0开始。
	
	UGFieldInfos m_FieldInfos;
	
	UGGeometry *m_pGeometry;		//存储Addnew时pGeometry的指针,Update的时候存盘并致空

	UGuchar *m_pZipBuffer;				//压缩缓冲区，避免每次压缩重新分配内存
	UGuint m_lZipBfrLen;		//压缩缓冲区大小

	UINT m_uRecordsetType;
	UGString m_strIDFieldName;		//SmID字段的名称，一般是SmID,有外挂表就可能是table.smid

	UGuint m_dwStates;				// byte0:editmode
									// byte1:edit changed
									// byte2:some options,such as send message to suery,read node color
									// byte3:reserved
	void SetEditMode(BYTE nEditMode);
	UGbool GetFirstChanged() const;
	void SetFirstChanged(UGbool bValue);
	UGbool GetLastChanged() const;			//第一条和最后一条记录指针改变标志
	void SetLastChanged(UGbool bValue);		
	UGbool GetEmptyChanged() const;			//纪录集刚被清空标志
	void SetEmptyChanged(UGbool bValue);		
	
	UGbool GetNeedReadNodeColor() const;		//是否需要读取子图层中节点颜色字段
	void SetNeedReadNodeColor(UGbool bValue);		//是否需要读取子图层中节点颜色字段

protected:
	
	//Recorset是否打开
	UGbool IsOpen();

	//对应Dataset的Query函数,对应调用CreateWith...且如果是TIN图层,另外生成一个对TINVertex的查询
	UGbool Create(const UGQueryDef &querydef);	
	UGbool CreateWithGeneral(const UGQueryDef &querydef);	//普通方式查询,
	UGString BuildSql(const UGQueryDef &querydef);	//根据Querydef的选项构造SDD的sql查询语句

	UGbool CreateWithBounds(const UGRect2D &rc2Bounds,UGint nOptions,UGint nMode,UGString strFilter=(""),UGString strSort=(""));	//Bounds查询
	//以下两个函数被CreateBounds()调用
	void CheckCertainKeys(UGArray<UGint>& arCertainKeys,UGbool bQualification,UGint* plFilterIDs=NULL,UGint nFilterCount=0);
	void CheckMaybeKeys(UGArray<UGint>& arMaybeKeys,UGRect2D& rc2Bounds,UGbool bQualification,UGint* plFilterIDs=NULL,UGint nFilterCount=0);

	UGbool CreateWithIDs(UGint *pIds,UGint nCount,UGint nOptions,UGint nMode);	//IDs查询

	UGbool GetGeometryDirectly(UGint nIndex,UGGeometry* &pGeometry);	//根据文件中位置读取Geometry
	UGbool GetGeometryBoundsDirectly(UGint nIndex,UGRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);	//根据文件中位置读取Geometry Bounds

	//数据集清空后复位
	void ResetAfterEmpty();

	//更新数据
	UGbool UpdateAfterAddNew();			//AddNew以后更新
	UGbool UpdateAfterEditOfGeometry();	//SetGeometry以后更新
	UGint CompressGeometryData(UGbool& bZipFlag,UGint& nSizeBeforeZip);	//压缩Geometry的数据，这个函数仅仅被上面两个函数调用。

	UGbool InitSpatialFilterFlag();  //初始化，为m_pInSplFilter分配空间
	inline void SetSpatialFilterFlag(UGint nRows,UGbool bIn);	//设置存储检索标志
	inline UGbool GetSpatialFilterFlag(UGint nRows);	//得到存储检索标志

	//以下两个函数与TIN图层有关
//	UGbool AppendTinVertex(CGeoTriangle *pTriangle,UGint *pTinVertexNo);	//在TinVertex子图层中加入三角面的空间坐标,并返回加入点的记录号	
//	UGbool GetTinVertexFromNo(UGint nNo,CPoint3D *pPoint3D,float *pNormal,COLORREF& color);//在PointGL图层中根据点的序列号从m_stmTinVertex中取得点的坐标和法向量，以及点的颜色。

	//恢复删除的记录
	//const UGint & nID,记录的ID
	//UGGeometry *pGeometry	//几何对象
	//CDaoRecordset *pRs;		//Undo数据集
	UGbool Restore(const UGint & nID, UGGeometry *pGeometry,CDaoRecordset *pRs);
	
	UGbool SeekSmID(UGint nID);  //把 m_Recordset的指针移动到SmId = nID 的位置
	
	static UGbool IsQueryAll(const UGQueryDef& querydef);
	UGbool CanOpenTableMode();  //能否以dbOpenTable模式打开

	 //根据字段类型，转换变体的值
	static UGbool ChangeVariantType(UGVariant& varValue,short nFieldType);
	static UGbool Ole2UG(const COleVariant& varValue,UGVariant& ugVar);
	static UGbool UG2Ole(const UGVariant& ugVar,COleVariant& varValue,int nCharset);
	static void UG2Dao(const UGFieldInfo& fieldInfo, CDaoFieldInfo& daoFieldInfo);
	static void Dao2UG(CDaoFieldInfo& daoFieldInfo, UGFieldInfo& fieldInfo);

	//static void ReadGeometry(UGFileLogical*pFile, UGGeometry* pGeometry);
	static void ReadGeoData(UGFileLogical*pFile, UGGeometry* pGeometry);

	static void WriteGeometry(UGFileLogical*pFile, UGGeometry* pGeometry);
	static void WriteGeoStyle(UGFileLogical* pFile, UGGeometry* pGeometry);
	// 只写入Geo Data部分的数据
	static void WriteGeoData(UGFileLogical* pFile, UGGeometry* pGeometry);

	static UGbool HasBounds(UGGeometry* pGeometry);
	static UGbool Has3DBounds(UGGeometry* pGeometry);

//	void GetRecordHeader(UGGeometry* pGeometry, UGRecordHeader* pRecordHeader);

	// 慎用, 内部会 真正先Save一把, 然后看Size
	static UGint GetGeoDataSize(UGGeometry* pGeometry);

	//UGbool UGSdbPlusRecordset::AppendTinVertex(UGGeoTriangle *pTriangle,UGint *pTINVertexNo);

	static void CheckBounds(UGDatasetVectorInfo& datasetInfo, const UGRect2D& bounds);
	static void CheckBounds(UGDatasetVectorInfo& datasetInfo, const UGRect2D& bounds, 
							double dMinZ, double dMaxZ);

	static void UnionBounds(UGRect2D &rc2Bounds, double &dMinZ, double &dMaxZ,
					const UGRect2D &rc2ObjBounds, double dObjMinZ, double dObjMaxZ, UGbool bInit);

private:
	UGbool m_bCalculateAreaAndLengthWhenAddNew;

	//进行统计时，如果需要，创建一个临时表
	CDaoTableDef* m_pStatisticTable;		//统计用临时表
	UGbool CreateStaticTable();				//创建临时统计表
					
	UGbool WriteLog(UGString strActionCode, int nReturnCode, UGString strActionDesc);
	int GetLogLevel();

	friend class UGSdbPlusDatasetVector;
	friend class UGSdbPlusDataSource;
//	friend class CSmUndoRecordset;
//	friend class CSmEditHistory;

};

inline void UGSdbPlusRecordset::SetEditMode(BYTE nEditMode)
{
	m_dwStates &= 0xffffff00;
	m_dwStates = m_dwStates + nEditMode;
}

//返回EditMode
inline short UGSdbPlusRecordset::GetEditMode() 
{
	//dbEditOfGeometry是Edit后SetGeometry时Recordset的状态
	BYTE nEditMode = BYTE(m_dwStates & 0x000000ff);
	return nEditMode;

};

inline UGbool UGSdbPlusRecordset::GetFirstChanged() const
{
	return (m_dwStates & 0x00000100)!=0;
}

inline void UGSdbPlusRecordset::SetFirstChanged(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00000100;
	}
	else
	{
		m_dwStates &= ~(0x00000100);
	}

}

inline UGbool UGSdbPlusRecordset::GetLastChanged() const
{
	return 	(m_dwStates & 0x00000200)!=0;
	
}

inline void UGSdbPlusRecordset::SetLastChanged(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00000200;
	}
	else
	{
		m_dwStates &= ~(0x00000200);
	}
}

inline UGbool UGSdbPlusRecordset::GetEmptyChanged() const
{
	return	(m_dwStates & 0x00000400)!=0;
}

inline void UGSdbPlusRecordset::SetEmptyChanged(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00000400;
	}
	else
	{
		m_dwStates &= ~(0x00000400);
	}
}


inline UGbool UGSdbPlusRecordset::GetNeedReadNodeColor() const
{
	return	(m_dwStates & 0x00010000)!=0;
}

inline void UGSdbPlusRecordset::SetNeedReadNodeColor(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00020000;
	}
	else
	{
		m_dwStates &= ~(0x00020000);
	}
}

}

#endif // !defined(AFX_SDBRECORDSETPlus_H__017098A9_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)


