/*!
    **************************************************************************************
     \file     UGStyleMapperDefn.h
    **************************************************************************************
     \author   周芹
     \brief    风格对照文件               
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2007-03-09  周芹      Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

namespace UGC {
	
	//! \brief 符号风格
	struct FILEPARSER_API UGSymbolStyle
	{
		//! brief 目标风格
		UGString m_strDesStyleID;
		//! brief 缩放比例
		UGdouble m_dbScale;
		
		UGSymbolStyle()
		{
			m_strDesStyleID = "";
			m_dbScale = 0.0;
		}
		UGSymbolStyle(UGString strDesStyleID, UGdouble dbScale)
		{
			m_strDesStyleID = strDesStyleID;
			m_dbScale = dbScale;
		}
	};
	//! \remarks UGString 为 源风格。
	//! eg:导入时应该为外部文件的风格，而UGSymbolStyle中的m_strDesStyle为UGC的Style
	//! 导出时 UGString为UGC的Style，而UGSymbolStyle中的m_strDesStyle为外部文件的风格
	typedef UGDict<UGString, UGSymbolStyle> UGSymbolStyleMapper;

	//! \brief 线风格
	struct FILEPARSER_API UGPenStyle
	{
		//! brief 目标风格
		UGString m_strDesStyleID;
		
		UGPenStyle()
		{
			m_strDesStyleID = "";
		}
		UGPenStyle(UGString strDesStyleID)
		{
			m_strDesStyleID = strDesStyleID;
		}
	};
	//! \remarks UGString 为 源风格。
	//! eg:导入时应该为外部文件的风格，而UGSymbolStyle中的m_strDesStyle为UGC的Style
	//! 导出时 UGString为UGC的Style，而UGSymbolStyle中的m_strDesStyle为外部文件的风格
	typedef UGDict<UGString, UGPenStyle> UGPenStyleMapper;

	//! \brief 填充风格
	struct FILEPARSER_API UGBrushStyle
	{
		//! brief 目标风格
		UGString m_strDesStyleID;
		
		UGBrushStyle()
		{
			m_strDesStyleID = "";
		}
		UGBrushStyle(UGString strDesStyleID)
		{
			m_strDesStyleID = strDesStyleID;
		}
	};
	//! \remarks UGString 为 源风格。
	//! eg:导入时应该为外部文件的风格，而UGSymbolStyle中的m_strDesStyle为UGC的Style
	//! 导出时 UGString为UGC的Style，而UGSymbolStyle中的m_strDesStyle为外部文件的风格
	typedef UGDict<UGString, UGBrushStyle> UGBrushStyleMapper;

	//! \brief 字体风格
	struct FILEPARSER_API UGFontStyle
	{
		//! brief 目标风格
		UGString m_strDesStyleID;
		UGdouble m_dbHeightScale;
		UGdouble m_dbWidthScale;
		UGdouble m_dbRotateAngle;
		
		UGFontStyle()
		{
			m_strDesStyleID = "";
			m_dbHeightScale = 0.0;
			m_dbWidthScale = 0.0;
			m_dbRotateAngle = 0.0;
		}
		UGFontStyle(UGString strDesStyleID, UGdouble dbHeightScale, 
			UGdouble dbWidthScale, UGdouble dbRotateAngle)
		{
			m_strDesStyleID = strDesStyleID;
			m_dbHeightScale = dbHeightScale;
			m_dbWidthScale = dbWidthScale;
			m_dbRotateAngle = dbRotateAngle;
		}
	};
	//! \remarks UGString 为 源风格。
	//! eg:导入时应该为外部文件的风格，而UGSymbolStyle中的m_strDesStyle为UGC的Style
	//! 导出时 UGString为UGC的Style，而UGSymbolStyle中的m_strDesStyle为外部文件的风格
	typedef UGDict<UGString, UGFontStyle> UGFontStyleMapper;
}
