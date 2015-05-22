// UGThemes.h: interface for the UGThemes class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemes.h
   **************************************************************************************
    \author   陈国雄
    \brief    专题图集合类。                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMES_H__869EEDDC_C92D_4D07_9903_4345F3138D0A__INCLUDED_)
#define AFX_UGTHEMES_H__869EEDDC_C92D_4D07_9903_4345F3138D0A__INCLUDED_

#include "UGTheme.h"

namespace UGC {

class UGThemeStyle;
class UGThemeLabel;
class UGThemeSymbol;
class UGThemeDotDensity;
class UGThemeGridUnique;
class UGThemeGridRange;

class MAP_API UGThemes  
{
public:
	UGThemes();
	virtual ~UGThemes();
	UGThemes(const UGThemes& Themes);
	UGThemes& operator =(const UGThemes& Themes);

public:
	static UGTheme* CreateTheme(UGint nThemeType);
	static UGTheme* CloneTheme(UGTheme* pTheme);

	UGThemeStyle* GetVisibleStyleTheme(UGdouble dScale)const;
	UGThemeDotDensity* GetVisibleDotDensityTheme(UGdouble dScale)const;
	UGThemeSymbol* GetVisibleSymbolTheme(UGdouble dScale)const;
	UGThemeLabel* GetVisibleLabelTheme(UGdouble dScale)const;
	UGTheme* GetVisibleGridTheme(UGdouble dScale)const;
	
	UGbool MoveTo(UGint nIndexFrom, UGint nIndexTo);
	UGbool MoveBottom(UGint nIndex);
	UGbool MoveDown(UGint nIndex);
	UGbool MoveUp(UGint nIndex);
	UGbool MoveTop(UGint nIndex);

	UGint Append(const UGThemes& Themes);

	UGint Add(UGTheme* pTheme);
	void InsertAt(UGint nIndex, UGTheme* pTheme);
	void SetAt(UGint nIndex, UGTheme* pTheme);
	UGTheme* GetAt(UGint nIndex)const;

	void RemoveAll();
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);

	UGint GetCount()const;
	UGbool IsEmpty()const;

	UGbool IsModified()const;
	void SetModifiedFlag(UGbool bModified = true);
	
	UGint Find(UGTheme* pTheme) const;
	UGString ToXML(UGint nVersion = 0)const;
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);

protected:
	UGbool m_bModified;
	UGArray<UGTheme*> m_Themes;

};

}

#endif // !defined(AFX_UGTHEMES_H__869EEDDC_C92D_4D07_9903_4345F3138D0A__INCLUDED_)
