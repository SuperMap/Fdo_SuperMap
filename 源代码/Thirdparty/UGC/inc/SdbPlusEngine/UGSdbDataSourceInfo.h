// UGSdbDataSourceInfo.h: interface for the UGSdbDataSourceInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMSDBINFO_H__6D771C53_0F1E_11D3_92DE_0080C8EE62D1__INCLUDED_)
#define AFX_ELEMSDBINFO_H__6D771C53_0F1E_11D3_92DE_0080C8EE62D1__INCLUDED_

#include "Base/UGArray.h"
#include "Engine/UGDatasetVectorInfo.h"
#include "Engine/UGDatasetRasterInfo.h"

#include "CompoundFile/UGFileLogical.h"

namespace UGC{

class UGRecordHeader;

class UGSdbDataSourceInfo
{
public:
	void SetDescription(UGString strDescription);//描述信息
	UGString GetDescription();

	//距离单位，不能为度
	void SetDistanceUnit(UGint  nDistanceUnit);	//CSmElement::Units
	UGint GetDistanceUnit();		//CSmElement::Units 

	//坐标单位，可能是度
	void SetCoordinateUnit(UGint nCoordUnit);	//CSmElement::Units 
	UGint GetCoordinateUnit();		//CSmElement::Units 

	//坐标系统号，> 1 为预定义地理投影坐标系，也可能是无效的坐标系,
	//			  = 1 为地理经纬坐标系，
	//            = 0 为普通非地理平面坐标系，
	//            =-1 为自定义地理投影坐标系,
	//			  <-1 为无效的坐标系.
	void SetCoordinateSystem(UGint nCoordSys);
	UGint GetCoordinateSystem();

	//版本号
	void SetVersion(UGint nVersion);
	UGint GetVersion();

	//投影系统的字符描述串
//	void SetProjectionString( CString strProjection );
//	CString GetProjectionString();

	UGuchar* GetData() 
	{
		return m_Data.GetData();
	}
	UGint GetDataSize()
	{
		return m_Data.GetSize();
	}

	// 从文件中读取nDataSize大小的数据, 
	UGbool Load(UGFileLogical* pFile, int nDataSize);


public:
	UGbool IsValid();				//是否有效对象
//	CSmElement::Type GetType();	//返回Element类型
	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);	//保存记录头到内存块
	//UGbool WriteRecordHeader(CFile *pFile,UGRecordHeader *pRcdHdr=NULL);				//保存记录头到文件
public:	
	UGbool GetModifiedFlag();
	void SetModifiedFlag(UGbool bModified=TRUE);
	UGSdbDataSourceInfo();
	UGSdbDataSourceInfo(UGint nCoordSys, UGint nCoordUnit, UGint nDistanceUnit/*, CString strDescription*/);

	virtual ~UGSdbDataSourceInfo();

protected:
	UGArray<UGuchar> m_Data;
	UGbool m_bModified;
};


class UGSdbDatasetInfo
{
public:
	UGSdbDatasetInfo();
	~UGSdbDatasetInfo();

public:

	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);
	UGuchar* GetData();
	UGint GetDataSize();

	void From(const UGDatasetVectorInfo& Info,UGint nNextID,UGint nEncrypt1,UGint nEncrypt2);
	void To(UGDatasetVectorInfo& Info,UGint& nNextID,UGint& nEncrypt1,UGint& nEncrypt2);

	void From(const UGDatasetRasterInfo& Info);
	void To(UGDatasetRasterInfo& Info);


	UGbool HasPyramid();
	void SetPyramidFlag(UGbool bPyramid);

	UGuint GetKey();
	UGint GetNextID();
	void SetNextID(UGint nNextID);
	UGint GetRecordCount();

	void SetDatasetType(UGint nType);
	int  GetDatasetType();

	//! 选项信息
	UGint	GetOptions();
				
	//! 数据编码类型
	UGint	GetCodecType();
				
	//! 三维Bounds的最小值
	UGdouble	GetMinZ();
				
	//! 三维Bounds的最大值
	UGdouble	GetMaxZ();	

protected:
	UGArray<UGuchar> m_Data;
};




}

#endif // !defined(AFX_ELEMSDBINFO_H__6D771C53_0F1E_11D3_92DE_0080C8EE62D1__INCLUDED_)
