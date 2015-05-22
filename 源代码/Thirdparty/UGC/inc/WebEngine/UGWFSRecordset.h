//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWFSRecordset.h
//!  \brief UGWFSRecordset 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWFSRECORDSET_H
#define UGWFSRECORDSET_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "WebEngine/UGWebRecordSet.h"

namespace UGC{


class WEBENGINE_API UGWFSRecordset :public UGWebRecordSet
{
public:
	UGWFSRecordset();

	UGWFSRecordset(UGDatasetVector * pDataset);

	virtual ~UGWFSRecordset();

public:
	virtual UGbool CreateWithBounds(const UGRect2D& rc2Bounds, 
		UGint nOptions,UGint nMode);
protected:
	UGbool ParseGeometrys(UGString &strFile);
	void ParseString(const UGString& strBufferConst,
		UGArray<UGdouble> &aryDouble, const UGString& strSeparator);

};

}
#endif // !defined(UGWFSRECORDSET_H)
