//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 5.0
// 原作者：			李绍俊
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGMemVector.h,UGMemVector.cpp
// 类  名：			UGMemVector
// 父  类：			UGDatasetVector
// 子  类：			
// 功能说明：		内存矢量数据集
// 调用说明：		
//=====================================================================================

#if !defined(UGMEMVECTOR_H)
#define UGMEMVECTOR_H

#include "Engine/UGDatasetVector.h"
#include "Geometry/UGGeometry.h"
#include "Base/UGBitArray.h"
#include "Base/UGFileStream.h"

namespace UGC
{
class UGMemDataSource;

class MEMENGINE_API UGMemVector : public UGDatasetVector  
{
	friend class UGMemRecordset;

public:
	enum SQL_OPERATOR
	{
		opEqual = 0,	//! =	Equal
		opLT	= 1,	//! <	Less Than
		opGT	= 2,	//! <	Greater Than
		opLTOE	= 3,	//! >=	Less Than Or Equal
		opGTOE	= 4,	//! <=	Greater Than Or Equal
		opNE	= 5,	//! !=	Not Equal
		opLike	= 6,	//! like	Like
	};
	enum SQL_FILTER_REL
	{
		relAND = 0,
		relOR = 1,
	};

	struct UG_MEM_VECTOR_FIELD
	{
		UGFieldInfo fieldInfo;
		UGArray<UGVariant> aryValues;

		void operator =(const UG_MEM_VECTOR_FIELD &VectorField)
		{
			fieldInfo = VectorField.fieldInfo;
			aryValues.Copy(VectorField.aryValues);
		}
	};

	typedef UGArray<UG_MEM_VECTOR_FIELD> UG_MEM_VECTOR_FIELDS;

	struct UG_MEM_VECTOR_EXPRESSION
	{
		UGString strFieldName;
		SQL_OPERATOR op;
		UGString strValue;
		SQL_FILTER_REL rel;
		UG_MEM_VECTOR_EXPRESSION * pNext;
		UG_MEM_VECTOR_EXPRESSION * pChild;
		UG_MEM_VECTOR_EXPRESSION * pParent;

		UG_MEM_VECTOR_EXPRESSION()
		{
			strFieldName = "";
			op = opEqual;
			rel = relOR;
			strValue = "";
			pNext = NULL;
			pChild = NULL;
			pParent = NULL;
		}
		~UG_MEM_VECTOR_EXPRESSION()
		{
			if(pChild != NULL)
			{
				delete pChild;
				pChild = NULL;
			}
			if(pNext != NULL)
			{
				delete pNext;
				pNext = NULL;
			}
		}
	};

public:
	UGMemVector();
	UGMemVector(UGMemDataSource *pDataSource);
	virtual ~UGMemVector(); 
	
	//! 打开数据集
	virtual UGbool Open();

	//! 关闭数据集
	virtual void Close();

	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! 返回创建时间
	virtual UGTime GetDateCreated();

	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! 保存数据集信息
	virtual UGbool SaveInfo();

	//! 刷新数据集信息
	virtual UGbool RefreshInfo();

	//! 查询大表图库中一个图幅的数据
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! 通过矩形范围查询图幅序号
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);

	//! 得到一个图幅的信息
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	
	//! 通过值更新字段值
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");

	//! 通过表达式更新字段值
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");

	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);

	//! 建立空间索引
	virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);
	//! 清除空间索引
	virtual UGbool DropSpatialIndex();
	//! 是否需要重建空间索引
	virtual UGbool IsSpatialIndexDirty();
	//! 返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考
	virtual UGint GetDirtyRecordCount();

	//! 建普通索引
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);
	//! 删除索引
	virtual UGbool DropIndex(const UGString& strIndexName);


	//! R树操作函数
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	//! 空间数据列的字段名
	virtual UGString GetGeoColName() const;

	//! 是否有几何数据，除了Tablur数据集，都有几何数据
	virtual UGbool HasGeometry() const;

	//! 查询通用入口
	virtual UGRecordset* Query(const UGQueryDef& querydef);

	//! 通过Bounds查询
	virtual UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);

	//! 通过IDs查询
	virtual UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);

	//! 创建多个字段
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
	
	//! 通过FieldInfo创建字段
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo);

	//! 创建字段
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
		UGint nSize,UGint nAttributes = 0);

	//! 通过字段名称删除字段
	virtual UGbool DeleteField(const UGString& strName);

	//! 通过索引号删除字段
	virtual UGbool DeleteField(UGint nIndex);

	//! 收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
		UGbool bSystemFieldExcluded = FALSE);

	//! 通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! 通过索引获取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! 通过字段名设置字段信息
	virtual UGbool SetFieldInfo(const UGString& strName,
		const UGFieldInfo& fieldInfo);

	//! 通过索引设置字段信息
	virtual UGbool SetFieldInfo(UGint nIndex,
		const UGFieldInfo& fieldInfo);
	
	//! 获取字段个数
	virtual UGint GetFieldCount();

	//! 删除表中所有数据
	virtual UGbool Truncate();

	//! 统计字段值
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);
	
	//! 计算字段单值个数
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,
		UGArray<UGVariant>& varKeys);

	//! 真正的SQL查询记录个数,更新Register表
	virtual UGbool ComputeRecCount();

	//! 获取最大空间对象的字节大小
	virtual UGint GetMaxGeoSize();

	//! 设置最大空间对象的字节大小
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);

	//! 通过ID数组删除数据集中的记录
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);

	//! 追加记录
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

	//! 追加网络数据集记录
	virtual UGbool AppendNetwork(UGRecordset *pNetRecordset,
		UGbool bShowProgress = TRUE);
	//! 返回记录集个数
	virtual UGint GetRecordsetCount();

	//! 返回指定索引的数据集指针
	virtual UGRecordset* GetRecordsetAt(UGint nIndex);

	//! 通过索引释放记录集
	virtual UGbool ReleaseRecordset(UGint nIndex);

	//! 通过引用释放记录集
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);

	//! 设置是否每个对象有自己的风格
	virtual void SetFlag(UGint nOption,UGbool bHas);

	//! 判断字段名是否有效
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! 得到未被占用的字段名
	virtual UGString GetUnoccupiedFieldName(const UGString& strFieldName);

	//! 得到图库索引图的名字	
	virtual UGString GetMiniatureDtName();
	
	//! 找到最近的空间对象
	//virtual UGGeometry* FindClosestGeometry(const UGPoint2D& pntHitTest,
	//	DistanceType nType);	
		
	//! 通过类别获取字段名
	virtual UGString GetFieldNameBySign(FieldSign nSign);
	
	//! 设置字段的类别
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

		//! 长事务处理函数
	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

		//! 时序数据的注册时间
	virtual UGTime GetRegistSequenceTime();

	//! 时序数据的最新更新时间
	virtual UGTime GetLUSequenceTime();
	
		//! 重采样，仅对线数据集有效
	virtual UGbool Resample(UGdouble dTolerance,
		UGbool bShowProgress=TRUE);

	virtual UGbool CanUpdate();

public:
	//!创建数据集
	UGbool Create(UGMemVector *pDatasetParent,const UGDatasetVectorInfo & vInfo);

	UGbool Delete(UGint nID);
	UGint GetID();
	UGbool SeekID(UGint nID);
	UGbool GetFieldValue(UGint nFieldIndex, UGVariant & varValue);
	UGbool GetFieldValue(const UGString & strFieldName, UGVariant & varValue);
	UGbool SetFieldValue(UGint nFieldIndex, const UGVariant &varValue);
	UGbool SetFieldValue(const UGString & strFieldName, const UGVariant & varValue);
	UGbool GetGeometry(UGGeometry *& pGeometry);
	UGbool GetGeometryDirect(UGGeometry *& pGeometry);
	UGbool SetGeometry(UGGeometry &geometry);
	UGint AddNew();

	UGint GetIDsByBounds(const UGRect2D &rc2Bounds, UGArray<UGint> & aryIDs);
	UGint GetIDsByFilter(const UGString & strFilter, UGArray<UGint> & aryIDs);

	UGbool Save2File(UGString strFileName,UGTime tCurrentTime);
	UGbool LoadFromFile(UGString strFileName,UGTime tCurrentTime);
	UGbool SetDatetimeLastUpdate(UGTime dateTime);

private:
	UGbool SaveDatasetInfo(UGFileStream &stream);
	UGbool ReadDatasetInfo(UGFileStream &stream);
	UGbool SaveFieldInfo(UGFileStream &stream,UGFieldInfo &fieldInfo);
	UGbool ReadFieldInfo(UGFileStream &stream,UGFieldInfo &fieldInfo);

protected:
	UGFieldInfos m_fieldInfos;

	/// \brief 父数据集指针
	/// \remark	仅供Node与TINVertex图层使用,普通图层为NULL
	UGMemVector	*m_pDatasetParent;

	UG_MEM_VECTOR_FIELDS m_structFields;
	UGint m_nIDFieldIndex;
	UGArray<UGGeometry*> m_Geometrys;
	UGBitArray m_aryDelFlag;
	UGint m_nMaxID;

	UGint m_nCurrentIndex;

	UGint m_nRecordCount;

	UGTime m_dateTimeLastUpdate;
};

}

#endif // !defined(UGMEMVECTOR_H)
