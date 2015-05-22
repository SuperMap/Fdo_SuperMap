// SdbDatasetRaster.h: interface for the UGSdbPlusDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBDATASETRASTER49_H__D9758FB9_30E0_11D3_A626_0080C8EE6685__INCLUDED_)
#define AFX_SDBDATASETRASTER49_H__D9758FB9_30E0_11D3_A626_0080C8EE6685__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SM_SDB_RASTER_EMPTY_BLOCK_POSITION  -2		//压缩数据集的ImgBlock索引，如果是空的块，就不用存放到文件中,可以避免压缩和减压缩

namespace UGC{

class SDBPLUSENGINE_API UGSdbPlusDatasetRaster : public UGDatasetRaster
{
	friend class UGSdbPlusDataSource;

protected:

	UGSdbPlusDatasetRaster();
	UGSdbPlusDatasetRaster(UGDataSource *pDataSource);

public:	
	~UGSdbPlusDatasetRaster();

public:	//From CSmDataset
	
	UGbool Open();	//打开
	void Close();	//关闭
	virtual UGbool IsOpen() const;	//是否关闭

	UGbool SaveInfo();	//图层相关信息存盘

	//数据集属性
	UGTime GetDateLastUpdated();		//返回最后更新日期
	UGTime GetDateCreated();			//返回创建日期
	
	UGbool CanUpdate();		//是否可更新

	//边界
	UGbool ComputeBounds();	//好象暂时没意义,不知道放在这里干什么.
	
	virtual UGbool BuildPyramid(UGbool bShowProgress); 
	virtual UGbool Rename(const UGString& strNewName);			//数据集重命名

	virtual UGbool IsSupport(UGEngAction dwEngAction);

	virtual UGbool CacheByBlock(int nLeft,int nTop,int nWidth, int nHeight);

	virtual UGbool RemovePyramids();

	//! 注册选项信息
	virtual UGbool RegisterOption(UGint nOption);

	//! 反注册选项信息
	virtual UGbool UnRegisterOption(UGint nOption);

	//! 判断数据集是否有某个选项信息
	virtual UGbool HasFlag(UGint nOption);

public:
	virtual UGbool RefreshInfo();
	virtual UGString GetTableName();

protected:
	UGSdbDatasetInfo m_DatasetInfo;
//	UGGeoRegion m_ClipRgn;
	UGString m_strMrSIDPassword;
	
protected:
	UGFolder *m_pFolderDataset;			//图层的storage
	UGFolder *m_pFolderPyramid;			//金字塔库的Storage

	UGFileLogical	*m_stmGeometry;			//存放空间数据ImgBlock
	UGFileLogical	*m_stmIndex;			//存放空间数据位置索引,仅对压缩存储的数据集有效

	UGFileLogical	*m_pFileInfo;				//存放图层信息
	UGFileLogical	*m_stmMetadata;			//存放图层元数据
	UGFileLogical	*m_stmColorTable;		//存放图层调色板

	UGint*  m_pBlockIndex;		//Image块位置索引

protected:
	//元数据描述管理
	UGint GetMetadataDescCount();		//返回元数据描述个数
	UGbool GetMetadataDesc(UGint nIndex, UGString &strTitle, UGString &strContent);	//返回元数据描述
	UGint AddMetadataDesc(UGString strTitle, UGString strContent);	//追加元数据描述字符串在已有的元数据描述字符串后面，返回添加到的位置
	void ClearMetadataDesc();				//清除原有的元数据描述
	UGbool DeleteMetadataDesc(UGint nIndex);	//追加元数据描述字符串在已有的元数据描述字符串后面

protected:

	/////////////////////////////////////////////////////
	//核心!!以下两个函数从UGDatasetRaster中继承,必须实现
	/////////////////////////////////////////////////////
	UGImgBlock* LoadBlock(UGint lRowBlock,UGint lColBlock); //Load image block to mem
	UGbool SaveBlock(UGImgBlock* pImgBlock);	//Save image block to disk

protected:
	
	//strName:			图层名称，不得与已存在的图层同名，不区分大小写
	//nType:			图层类型，参见SmElemDatasetInfo.h中的定义。注意，图层类型可以是多个类型的组合，比如CAfcType::ltNetwork|CAfcTypeltRegion
	//ImgPixelFormat	Image格式,具体见SmDefStruct.h
	//lWidth			Image宽度(点的个数)
	//lHeight			Image高度(点的个数)
	//eBlockSize		Image块的边长大小,具体见SmDefStruct.h
	
	UGbool Create(const UGDatasetRasterInfo& Info);
	
	UGbool IsValidDataset();	//判断是否合法Dataset

	UGbool LoadBlockIndex();
	
	UGbool FillPyramidDatasets();
	
	UGbool ReleasePyramidDatasets();

	UGbool OpenPyramid(UGFolder* storage);		//金字塔数据集的打开，与普通的数据集相比，没有m_pDataSource;
	
	UGDatasetRaster* Tier(UGString strName, UGint lWidth,UGint lHeight,
						UGDatasetRasterInfo::IBSizeOption eBlockSize,UGint nOptions);
	
	UGbool SaveCompressedBlock(UGImgBlock* pImgBlock);
	UGImgBlock* LoadCompressedBlock(UGint lRowBlock,UGint lColBlock);
//	BYTE* m_pCompressBuffer;		//数据压缩的临时内存,大约是一个Image Bloc数据大小。
	
};

}

#endif // !defined(AFX_SDBDATASETRASTER49_H__D9758FB9_30E0_11D3_A626_0080C8EE6685__INCLUDED_)