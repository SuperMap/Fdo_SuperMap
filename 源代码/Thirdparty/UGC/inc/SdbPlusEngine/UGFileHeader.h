 // ElemFileHeader.h: interface for the CElemFileHeader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMFILEHEADER_H__FED15637_17D0_11D3_92ED_0080C8EE62D1__INCLUDED_)
#define AFX_ELEMFILEHEADER_H__FED15637_17D0_11D3_92ED_0080C8EE62D1__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGColorset.h"
#include "Base/UGColorTable.h"

#include "Algorithm/UGRect2D.h"
#include "Geometry/UGGeometry.h"

// added by zengzm 2007-4-21 消除无用的编译警告:名称被标记为 #pragma deprecated
#pragma warning(disable : 4995)

namespace UGC{

#define SM_SDB_ENGINE_NAME			("SuperMap Spatial Database(SDB)")
#define SM_SDB_FOLDER_DATASETS		("Datasets")
#define SM_SDB_FOLDER_SDBINFO		("SdbInfo")
#define SM_SDB_FILE_SDBINFO			("Info")
#define SM_SDB_FILE_PROJECTION		("Projection")
#define SM_SDB_FILE_GEOMETRY		("Geometry")
#define SM_SDB_FILE_DATASETINFO		("Info")
#define SM_SDB_FILE_METADATA		("Metadata")
#define SM_SDB_FILE_INDEX			("Index")
#define SM_SDB_FILE_TREE			("IndexTree")
#define SM_SDB_FILE_COLOR_TABLE		("Color Table")
#define SM_SDB_FILE_NODES			("Nodes")
#define SM_SDB_FILE_NODEINDEX		("Node Index")
#define SM_SDB_FILE_TINPOINT		("Tin Point")
#define SM_SDB_FOLDER_PYRAMID		("Pyramid")
#define SM_SDB_FOLDER_TIER			("Tier")
#define SM_SDB_FILE_EXT				(".sdb")
#define SM_SDD_FILE_EXT				(".sdd")

//The follwing is definition for file flags
#define SM_FLAG_GEOMETRY		0x4D476D53 //SmGM
#define SM_FLAG_INDEX			0x4E496D53 //SmIN
#define SM_FLAG_DATASET_INFO	0x49446D53 //SmDI
#define SM_FLAG_SDB_INFO		0x49536D53 //SmSI
#define SM_FLAG_PROJECTION		0x4A506D53 //SmPJ
#define SM_FLAG_COLOR_TABLE		0x54436D53 //SmCT
#define SM_FLAG_NODES			0x444E6D53 //SmND
#define SM_FLAG_NODE_INDEX		0x494E6D53 //SmNI
#define SM_FLAG_METADATA		0x444D6D53 //SmMD
#define SM_FLAG_TINPOINT		0x50546D53 //SmTP	  

#define SM_FLAG_LAYER			0x414C6D53 //SmLA
#define SM_FLAG_LINE_STYLE_LIB	0x534C6D53 //SmLS
#define SM_FLAG_SYMBOL_LIB		0x4C536D53 //SmSL
#define SM_FLAG_ICON_LIB		0x4C496D53 //SmIL
#define SM_FLAG_MATERIAL_LIB	0x4C4D6D53 //SmML

#define SM_FILE_VERSION			2001999

class UGFileHeader 
{
public:
	enum
	{
		HasRecordHeader		=0x00000001,
//		FixedRecordSize		=0x00000002,
	};
public:
	UGint m_nFlag;
	UGint m_nVersion;	//=SM_FILE_VERSION
	UGint m_nOptions;
	UGint m_nRecordCount;
public:
	UGFileHeader();
	~UGFileHeader();
public:
//	UGbool Read(CFile *pFile);
//	UGbool Write(CFile *pFile);
};


class UGRecordHeader
{
public:
	enum
	{
		Deleted		=0x00000001,
		Modified	=0x00000002,
		Locked		=0x00000004,
		HasBounds	=0x00000008,
		HasStyle	=0x00000010,
		Zipped		=0x00000020,
		CellOrigin  =0x00000040,
		Hignlight	=0x00000080,
		Normalize	=0x00000100,     //坐标转成long或short存储
	};
public:
	UGint ID;
	UGint m_nType;
	UGint m_nOptions;
	UGint m_nElementSize;
public:
	UGRecordHeader()
	{
		ID = -1;
		m_nType = 0;
		m_nOptions = 0;
		m_nElementSize = 0;
	};
	~UGRecordHeader()
	{
	};
public:
	void operator = (const UGRecordHeader &value)
	{
		ID = value.ID;
		m_nType = value.m_nType;
		m_nOptions = value.m_nOptions;
		m_nElementSize = value.m_nElementSize;
	};
	void GetFrom(const UGColorset* pColorset);
	void GetFrom(const UGImgBlock* pImgBlock);
	void GetFrom(const UGGeometry* pGeometry);
	

	/*
	BOOL Read(CFile *pFile)
	{
		if(pFile)
		{
			try
			{
				pFile->Read((void *)this, sizeof(UGRecordHeader));
			}
			catch(CException *e)
			{
				SmGetErrorMsgObj()->CatchException(e);
				e->Delete();
			}
			return TRUE;
		}
		return FALSE;
	};

	BOOL Write(CFile *pFile)
	{
		if(pFile)
		{
			try
			{
				pFile->Write((void *)this, sizeof(UGRecordHeader));
			}
			catch(CFileException *e)
			{
				SmGetErrorMsgObj()->CatchFileException(e);
				e->Delete();
				return FALSE;
			}
			return TRUE;
		}
		return FALSE;
	};
	*/
};


extern "C" void CheckError(CDaoException *e,const char * strFileName,LONG nLineNumber);

}
#endif // !defined(AFX_ELEMFILEHEADER_H__FED15637_17D0_11D3_92ED_0080C8EE62D1__INCLUDED_)
