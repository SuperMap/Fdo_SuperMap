
/*!
    **************************************************************************************
     \file     UGDataExchange.h
    **************************************************************************************
     \author   艾国
     \brief    用户层-----数据转换类
     \remarks   数据转换类，用户只要调用此类的接口就可以进行数据转换                                                             <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGDATAEXCHANGE_H__B21A086A_BC85_4DE2_BFB1_FDD674B68AA8__INCLUDED_)
#define AFX_UGDATAEXCHANGE_H__B21A086A_BC85_4DE2_BFB1_FDD674B68AA8__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/ugexports.h"


namespace UGC {

	class UGDataSource;
	class UGExchangeParams;
	class UGImportParams;
	class UGExportParams;
	class UGExchangeFile;
	class UGExchangeVector;
	class UGExchangeRaster;
	
class DATAEXCHANGE_API UGDataExchange  
{
public:
	UGDataExchange();
	virtual ~UGDataExchange();


	//! \brief 		传入要转换的数据源
	//! \return 	UGbool			传入成功返回true, 否则返回false
	//! \param 		pDataSource		数据源指针
	//! \remarks 	外界必须先调用AttachDataSource，传递进来CSmDataSource的指针的地址，	
	UGbool AttachDataSource(UGDataSource* pDataSource);
	

	//! \brief 		导入数据
	//! \return 	UGbool			成功返回true,否则返回false
	//! \param 		importParams	导入参数类
	//! \remarks 	在导入之前必须把importParams设置好	
	UGbool Import(const UGImportParams& importParams);


	//! \brief 		导出数据
	//! \return 	UGbool			成功返回true,否则返回false
	//! \param 		exportParams	导出参数类
	//! \remarks 	在导入之前必须把importParams设置好		
	UGbool Export(const UGExportParams& exportParams);

private:
	//! \brief 导入矢量格式文件
	UGbool ImportVector(const UGImportParams& importParams);

	//! \brief 导入栅格格式文件
	UGbool ImportRaster(const UGImportParams& importParams);

	//! \brief 导出矢量类型数据集
	UGbool ExportVector(const UGExportParams& exportParams);

	//! \brief 导出栅格格式数据集
	UGbool ExportRaster(const UGExportParams& exportParams);

private:
	//! \brief 设置导入矢量数据集的名字等信息
	void SetDatasetVectorInfo(UGExchangeVector* pExchangeVector, const UGImportParams& importParams);

	//! \brief 设置导入栅格数据集的名字等信息
	void SetDatasetRasterInfo(UGExchangeRaster* pExchangeRaster, const UGImportParams& importParams);

	//! \brief 拷贝用户自定义参数
	void CopyUserParams(UGExchangeFile* pExchangeFile, const UGExchangeParams& exchangeParams);

	//! \brief 根据importParams中的参数，判断是否导入为复合数据集，如果用户没有设置这个参数，系统将根据导入文件类型推荐一个值
	UGbool IsimportAsCADDataset(const UGImportParams& importParams);
		//! brief 根据导入的文件类型确定是否导入为复合数据集，在用户未设置m_bImportAsCADDataset时使用
		UGbool GetRecommendIsAsCAD(const UGImportParams& importParams);

	//! \brief 根据importParams中的参数，判断是否导入为Grid数据集，如果用户没有设置这个参数，系统将根据导入文件类型推荐一个值
	UGbool IsimportAsGridDataset(const UGImportParams& importParams);
		//! brief 根据导入的文件类型确定是否导入为复合数据集，在用户未设置m_bImportAsGridDataset时使用
		UGbool GetRecommendIsAsGrid(const UGImportParams& importParams);
private:
	//! \brief 数据源
	UGDataSource* m_pDataSource;  
};


} //namespace


#endif // !defined(AFX_UGDATAEXCHANGE_H__B21A086A_BC85_4DE2_BFB1_FDD674B68AA8__INCLUDED_)
