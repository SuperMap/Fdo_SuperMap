/** \file	 SuperMapExpressionCapabilities.cpp
*  \author	 郝玉江
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*/

#include "SuperMap.h"

SuperMapExpressionCapabilities::SuperMapExpressionCapabilities ()
{
}

SuperMapExpressionCapabilities::~SuperMapExpressionCapabilities ()
{
}

void SuperMapExpressionCapabilities::Dispose ()
{
	delete this;
}

/// <summary>Returns an array of FdoExpressionType objects the feature provider supports.</summary>
/// <param name="length">Input the number of expression types</param> 
/// <returns>Returns the list of expression types</returns> 
FdoExpressionType* SuperMapExpressionCapabilities::GetExpressionTypes (FdoInt32& length)
{
	TRACE(_T("调用 SuperMapExpressionCapabilities::GetExpressionTypes()... \n"));
	static FdoExpressionType types[] =
	{
		FdoExpressionType_Basic,//,
		//FdoExpressionType_Function,		//TODO::支持函数
	};

	length = sizeof (types) / sizeof (FdoExpressionType);

	return (types);
}

/// <summary>Returns a collection of FdoFunctionDefinition objects the feature provider supports within expressions.</summary>
/// <returns>Returns the collection of function definitions</returns> 
FdoFunctionDefinitionCollection* SuperMapExpressionCapabilities::GetFunctions()
{
	TRACE(_T("调用 SuperMapExpressionCapabilities::GetFunctions()... \n"));
	//before 2008年1月8日
	//FdoPtr<FdoFunctionDefinitionCollection> ret;
	//// TODO::目前使用FDO默认的功能，如需再加
	//ret = GetWellKnownFunctions ();
	//return (FDO_SAFE_ADDREF (ret.p));
	

	FdoPtr<FdoFunctionDefinitionCollection> ret = FdoFunctionDefinitionCollection::Create();

	// MOSAIC()
	FdoPtr<FdoArgumentDefinitionCollection> args = FdoArgumentDefinitionCollection::Create();
	FdoPtr<FdoArgumentDefinition> rasterArg = FdoArgumentDefinition::Create(L"raster", L"", FdoDataType_BLOB);
	args->Add(rasterArg);
	FdoPtr<FdoFunctionDefinition> mosaicFunction = FdoFunctionDefinition::Create(L"MOSAIC", L"", FdoDataType_BLOB, args);
	ret->Add(mosaicFunction);

	// CLIP()
	args = FdoArgumentDefinitionCollection::Create();
	rasterArg = FdoArgumentDefinition::Create(L"raster", L"", FdoDataType_BLOB);
	args->Add(rasterArg);

	FdoPtr<FdoArgumentDefinition> minXArg = FdoArgumentDefinition::Create(L"minX", L"", FdoDataType_Double);
	args->Add(minXArg);
	FdoPtr<FdoArgumentDefinition> minYArg = FdoArgumentDefinition::Create(L"minY", L"", FdoDataType_Double);
	args->Add(minYArg);
	FdoPtr<FdoArgumentDefinition> maxXArg = FdoArgumentDefinition::Create(L"maxX", L"", FdoDataType_Double);
	args->Add(maxXArg);
	FdoPtr<FdoArgumentDefinition> maxYArg = FdoArgumentDefinition::Create(L"maxY", L"", FdoDataType_Double);
	args->Add(maxYArg);

	FdoPtr<FdoFunctionDefinition> clipFunction = FdoFunctionDefinition::Create(L"CLIP", L"", FdoDataType_BLOB, args);
	ret->Add(clipFunction);

	// RESAMPLE()
	args = FdoArgumentDefinitionCollection::Create();
	rasterArg = FdoArgumentDefinition::Create(L"raster", L"", FdoDataType_BLOB);
	args->Add(rasterArg);

	minXArg = FdoArgumentDefinition::Create(L"minX", L"", FdoDataType_Double);
	args->Add(minXArg);
	minYArg = FdoArgumentDefinition::Create(L"minY", L"", FdoDataType_Double);
	args->Add(minYArg);
	maxXArg = FdoArgumentDefinition::Create(L"maxX", L"", FdoDataType_Double);
	args->Add(maxXArg);
	maxYArg = FdoArgumentDefinition::Create(L"maxY", L"", FdoDataType_Double);
	args->Add(maxYArg);

	FdoPtr<FdoArgumentDefinition> heightArg = FdoArgumentDefinition::Create(L"height", L"", FdoDataType_Int32);
	args->Add(heightArg);
	FdoPtr<FdoArgumentDefinition> widthArg = FdoArgumentDefinition::Create(L"width", L"", FdoDataType_Int32);
	args->Add(widthArg);
	FdoPtr<FdoFunctionDefinition> resampleFunction = FdoFunctionDefinition::Create(L"RESAMPLE", L"", FdoDataType_BLOB, args);
    ret->Add(resampleFunction);

	return (FDO_SAFE_ADDREF (ret.p));
}
