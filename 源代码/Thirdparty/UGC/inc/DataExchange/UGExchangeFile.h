
/*!
    **************************************************************************************
     \file     UGExchangeFile.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换层中-----数据转换基类                     
     \remarks   数据转换层中-----数据转换基类                                        <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGEXCHANGEFILE_H__EE8820FE_B390_46E2_A796_E0F03AABD822__INCLUDED_)
#define AFX_UGEXCHANGEFILE_H__EE8820FE_B390_46E2_A796_E0F03AABD822__INCLUDED_


#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Base/UGDict.h" 
#include "Engine/UGDataset.h"
#include "FileParser/UGFileParseVector.h"

namespace UGC {

	class UGDataSource;


class UGExchangeFile
{
public:
	UGExchangeFile();
	virtual ~UGExchangeFile();

	//! \brief	设置导入一个数据集的信息
	void AddOneDatasetInfo(UGString strName, UGDataset::DatasetType nType, UGint nEncType);

	//! \brief	设置文件格式类型
	void SetFileType(UGint nFileType);

	//! \brief	设置文件的路径
	void SetFilePathName(const UGString& strFilePathName);

	//! \brief 设置数据主文件名
	void SetShowProgress(UGbool bShowProgress);

	//! \brief 设置对照表
	void SetMappingFile(const UGString& strMappingFile);

	//! \brief 设置临时路径
	void SetTempPath(const UGString& strTempPath);

	void SetIsIgnoreCoordSys(UGbool bIgnoreCoordSys);

	void SetIsIgnoreAttribute(UGbool bIgnoreAttribute);

	//! \brief	设置导出数据集的名字
	void SetExportDatasetName(const UGString& strDatasetName);

	//! \brief	设置坐标单位			
	void SetDesUnits(UGint nDesUnits);

	//! \brief	设置导出的版本
	void SetImportVersion(UGint nVersion);

	//! \brief	设置一个其他的参数（可以是特殊的格式和用户自定义参数）
	void SetOneParam(const UGString& strFileType, const UGString& strName, const UGVariant& varValue);

public:
	//! \brief	导入为矢量数据集
	virtual UGbool Import(UGDataSource* pDataSource, const UGString& strFilePathName);

	//! \brief	导入为复合数据集
	virtual UGbool ImportCAD(UGDataSource* pDataSource, const UGString& strFilePathName);
	
	////! \brief 数据集导出（预留方法）
	virtual UGbool Export(UGDataSource* pDataSource, const UGString& strFilePathName);


protected:
	//导入和导出的公共参数

	//! \brief 数据格式类型
	UGint m_nFileType;
	
	//! \brief 数据主文件名
	UGString m_strFilePathName;
	
	//! \brief 是否显示进程条
	UGbool m_bShowProgress;

	//! \brief 对照文件全路径
	UGString m_strMappingFile;
	
	//! \brief 临时文件目录
	UGString m_strTempPath;

	//! \brief 	是否忽略源文件的坐标系统，
	UGbool m_bIgnoreCoordSys; 
	//! \brief 	是否忽略属性信息（影象：如 Arcinfo 二进制Grid ）
	UGbool m_bIgnoreAttribute; 

protected:
	//以矢量和栅格划分

	//导入的专用参数
	//! \brief 图层字段名
	struct UGImportDatasetInfo
	{
		//! \brief	数据集名称
		UGString m_strName; 

		//! \brief	数据编码类型
		UGint m_nCodecType;	

		UGImportDatasetInfo()
		{
			m_nCodecType = UGDataCodec::encNONE;
		}
	};
	
	typedef UGDict<UGDataset::DatasetType, UGImportDatasetInfo> UGImportDatasetInfos;
	//! \brief	数据集参数
	UGImportDatasetInfos m_importDatasetInfos;

protected:
	//以矢量和栅格划分

	//导出的专用参数
	//! \brief 	导出数据集的名字 
	UGString m_strDatasetName;

	//! \brief 	指定生成的外部文件的单位
	UGint m_nDesUnits; 

	//! \brief	用一个整型变量来设置导出文件格式是什么类型，其值应该是一些枚举型
	UGint m_nVersion;
};







} //namespace UGC

#endif // !defined(AFX_UGEXCHANGEFILE_H__EE8820FE_B390_46E2_A796_E0F03AABD822__INCLUDED_)
