
/*!
    **************************************************************************************
     \file     UGExchangeRaster.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换层中-----数据转换栅格类                       
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGEXCHANGERASTER_H__0260A745_42E5_4180_A01B_A14D1BE55D10__INCLUDED_)
#define AFX_UGEXCHANGERASTER_H__0260A745_42E5_4180_A01B_A14D1BE55D10__INCLUDED_



#include "UGExchangeFile.h"
#include "Base//UGDataExchangeConstant.h"
#include "Engine/UGDataset.h"



namespace UGC {

	class UGDatasetRaster;
	class UGDataSource;
	class UGFileParseRaster;

class UGExchangeRaster : public UGExchangeFile  
{
public:
	UGExchangeRaster();
	virtual ~UGExchangeRaster();

public:
	

	//! \brief 		导入数据
	//! \return 	UGbool			成功返回true,否则返回false
	//! \param 		pDataSource		数据源指针
	//! \param 		strFilePathName 导入数据的名字（全路径）
	//! \remarks 	在导入之前应该进行设置，调用Set***
	virtual UGbool Import(UGDataSource* pDataSource, const UGString& strFilePathName);

	//! \brief 		导出数据
	//! \return 	UGbool			成功返回true,否则返回false
	//! \param 		pDataSource		数据源指针
	//! \param 		strFilePathName 导入数据的名字（全路径）
	//! \remarks 	在导出之前应该进行设置，调用Set***
	virtual UGbool Export(UGDataSource* pDataSource, const UGString& strFilePathName);
public:
	
	//! \brief 设置导入栅格的名字
	void SetImageName(const UGString& strDatasetImage);

	//! \brief 设置导入栅格数据的类型
	void SetGridDataType(UGint nGridDataType);

	//! \brief 设置导入或导出影像数据时，所带的影像坐标参考文件的名字
	void SetImageGeoRefFileName(const UGString& strImageGeoRefFileName);

	//! \brief 设置导入或导出影像数据时，所带的影像坐标参考文件的类型
	void SetImageGeoRefFileType(UGint nImageGeoRefFileType);
	

	void SetIsBuildPyramid(UGbool bBuildPyramid);
protected:
	
	//! \brief 	导出image数据集时，指定生成的影像参考文件的名字
	UGString m_strImageGeoRefFileName; 

	//! \brief	导出image数据集时，指定生成的影像参考文件的类型
	UGint m_nImageGeoRefFileType;

	//! \brief	转入image文件时，生成的image类型的数据集的名字
	UGString m_strDatasetImage;

	//! \brief 	转入影像数据后，每个栅格的数据类型（几个字节来表示一个栅格数据），有预定义的宏
	UGint m_nGridDataType; 

	//! \brief 	存放导入数据集的名字
	UGString m_strDatasetName;

	//! \brief 栅格数据导入后是否自动建立影像金字塔
	UGbool m_bBuildPyramid;

	//UGDatasets m_datasets;
private:

	//! \brief 	创建数据集
	UGDatasetRaster* CreateDataset(UGDataSource* pDatasource, UGFileParseRaster* pFileRaster, UGint nIndex);
	//! \brief 	读取扫描行数据
	UGbool ReadScanlineData(UGDatasetRaster* pDatasetRaster, UGFileParseRaster* pFileRaster, UGint nBandIndex = 0);
	//! \brief 	读取快状数据
	UGbool ReadBlockData(UGDatasetRaster* pDatasetRaster, UGFileParseRaster* pFileRaster, UGint nBandIndex = 0);

	//! \brief 	读取影像坐标参考文件
	UGbool ImportGeoRefFile(UGDatasetRaster* pDatasetRaster); 
	//! \brief 	生成影像坐标参考文件
	UGbool ExportGeoRefFile(UGDatasetRaster* pDatasetRaster); 
	//! \brief 	得到影象的波段

	
};


} //namespace UGC


#endif // !defined(AFX_UGEXCHANGERASTER_H__0260A745_42E5_4180_A01B_A14D1BE55D10__INCLUDED_)
