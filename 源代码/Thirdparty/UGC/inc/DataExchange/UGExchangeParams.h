
/*!
    **************************************************************************************
     \file     UGExchangeParams.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换参数基类             
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                             <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGEXCHANGEPARAMS_H__8632CECD_F8B4_4D1C_83EB_B92EEEBA113B__INCLUDED_)
#define AFX_UGEXCHANGEPARAMS_H__8632CECD_F8B4_4D1C_83EB_B92EEEBA113B__INCLUDED_



#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Base/UGDict.h"
#include "FileParser/UGFileParseVector.h"


namespace UGC {




class DATAEXCHANGE_API UGExchangeParams  
{
public:
	UGExchangeParams();
	virtual ~UGExchangeParams();

public:
	//! \brief 设置文件格式类型
	UGbool SetFileType(UGint nFileType);
	//! \brief 得到文件格式类型
	UGint GetFileType() const;

	//! \brief 设置数据文件名
	void SetFilePathName(const UGString& strFilePathName);
	//! \brief 得到数据文件名 
	UGString GetFilePathName() const;
	
	//! \brief 设置是否显示进程条
	void SetShowProgress(UGbool bShowProgress);
	//! \brief 得到是否显示进程条
	UGbool IsShowProgress() const;

	//! \brief 添加一个符号风格映射
	void AddOneSymbolStyleMapper(UGString strSourceID, UGString strDesStyleID, UGdouble dbScale);
	UGSymbolStyleMapper GetSymbolStyleMapper() const;

	//! \brief 添加一个线型风格映射
	void AddOnePenStyleMapper(UGString strSourceID, UGString strDesStyleID);
	UGPenStyleMapper GetPenStyleMapper() const;

	//! \brief 添加一个填充风格映射
	void AddOneBrushStyleMapper(UGString strSourceID, UGString strDesStyleID);
	UGBrushStyleMapper GetBrushStyleMapper() const;

	//! \brief 添加一个字体风格映射
	void AddOneFontStyleMapper(UGString strSourceID, UGString strDesStyleID,UGdouble dbHeightScale,	
		UGdouble dbWidthScale, UGdouble dbRotateAngle);
	UGFontStyleMapper GetfontStyleMapper() const;

	//! \brief 设置临时文件的路径
	void SetTempPath(const UGString& strTempPath);
	
	//! \brief 得到临时文件的路径 
	UGString GetTempPath() const; 

	//! \brief 设置导入的坐标单位
	void SetDesUnits(UGint nDesUnits);

	//! \brief 得到导入的坐标单位
	UGint GetDesUnits() const;

	//! \brief 设置影像坐标参考文件的名字
	void SetImageGeoRefFileName(const UGString& strImageGeoRefFileName);

	//! \brief 得到影像坐标参考文件的名字
	UGString GetImageGeoRefFileName() const;

	//! \brief 设置所带的影像坐标参考文件的类型
	void SetImageGeoRefFileType(UGint nImageGeoRefFileType);

	//! \brief 得到所带的影像坐标参考文件的类型
	UGint GetImageGeoRefFileType() const;

	//! \brief 设置图层字段名字
	void SetLayerName(const UGString& strLayerName);
	//! \brief 得到图层字段名字
	UGString GetLayerName() const;

	//! \brief 设置其他导入导出参数
	void SetOtherParams(const UGString& strFileType, const UGString& strName, const UGVariant& varValue);

	//! \brief 根据文件类型得到其他参数的名字
	UGString GetOtherParamsName(const UGString& strFileType) const;

	//! \brief 根据文件类型得到其他参数的值
	UGVariant GetOtherParamsValue(const UGString& strFileType) const;
	
protected:
	//! \brief 数据格式类型
	UGint m_nFileType;
	
	//! \brief 数据主文件名
	UGString m_strFilePathName;
	
	//! \brief 是否显示进程条
	UGbool m_bShowProgress;
	
	//! \brief 点、线、字体、填充风格 映射表
	UGSymbolStyleMapper m_SymbolStyleMapper;
	UGPenStyleMapper m_PenStyleMapper;
	UGBrushStyleMapper m_BrushStyleMapper;
	UGFontStyleMapper m_FontStyleMapper;

	//! \brief 临时文件目录
	UGString m_strTempPath;

	//! \brief 	指定生成的外部文件的单位
	UGint m_nDesUnits; 

	//! \brief 	导出image数据集时，指定生成的影像参考文件的名字
	UGString m_strImageGeoRefFileName; 

	//! \brief	导出image数据集时，指定生成的影像参考文件的类型
	UGint m_nImageGeoRefFileType;

	//! \brief	图层字段名
	//! \remarks 导入时，为生成的、存放图层信息的字段（名）
	//! 导出时，用这个字段的值来设置当前记录导出后所属的图层
	UGString m_strLayerName;

protected:

	struct UGExchangeOtherParam
	{
		UGString m_strName; //! 参数什么意思
		UGVariant m_varValue; //! 此参数的值
		UGExchangeOtherParam() {}
		UGExchangeOtherParam(const UGString& strName, const UGVariant& varValue)
		{
			m_strName = strName;
			m_varValue = varValue;
		}
		UGExchangeOtherParam(const UGExchangeOtherParam& otherParams)
		{
			m_strName = otherParams.m_strName;
			m_varValue = otherParams.m_varValue;
		}
	};
	//! \brief	设置一些特殊参数或用户自定义参数
	UGDict<UGString, UGExchangeOtherParam> m_otherParams;
};



} //namespace UGC


#endif // !defined(AFX_UGEXCHANGEPARAMS_H__8632CECD_F8B4_4D1C_83EB_B92EEEBA113B__INCLUDED_)
