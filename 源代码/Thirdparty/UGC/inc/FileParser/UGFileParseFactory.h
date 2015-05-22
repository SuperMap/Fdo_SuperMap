
/*!
    **************************************************************************************
     \file     UGFileParseFactory.h
    **************************************************************************************
     \author   艾国
     \brief    文件解析工厂类               
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


#if !defined(AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)
#define AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/ugexports.h"

namespace UGC {


	class UGFileParseVector;
	class UGFileParseRaster;


class FILEPARSER_API UGFileParseFactory  
{
public:
	UGFileParseFactory();
	~UGFileParseFactory();


	//! \brief 创建矢量文件解析类
	static UGFileParseVector* CreateFileVector(UGint nFileType);
	
	//! \brief 创建栅格文件解析类
	static UGFileParseRaster* CreateFileRaster(UGint nFileType);


	static void DestroyFileVector(UGFileParseVector* pFileVector);

	static void DestroyFileRaster(UGFileParseRaster* pFileRaster);
};


} //namespace UGC


#endif // !defined(AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)

