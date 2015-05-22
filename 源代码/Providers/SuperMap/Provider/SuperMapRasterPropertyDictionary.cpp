/** \file	 SuperMapRasterPropertyDictionary.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-08
*/

#include "SuperMap.h"

SuperMapRasterPropertyDictionary::SuperMapRasterPropertyDictionary(UGC::UGDatasetRaster * pDatasetRaster)
{
	m_pDatasetRaster = pDatasetRaster;
}

SuperMapRasterPropertyDictionary::~SuperMapRasterPropertyDictionary(void)
{

}

void SuperMapRasterPropertyDictionary::Dispose()
{
	delete this;
}

//目前只设置两个属性，一个是"Pallette"调色板的数据，一个是"NumOfPalletteEntries"调色板中颜色数
FdoStringCollection* SuperMapRasterPropertyDictionary::GetPropertyNames ()
{
	FdoPtr<FdoStringCollection> propertyNames = FdoStringCollection::Create();
	if(NULL != m_pDatasetRaster)
	{
		if(m_pDatasetRaster->GetColorset().GetSize() > 0) //有调色板
		{
			propertyNames->Add(PALETTEATTRNAME);
			propertyNames->Add(NUMOFPALETTEENTRIESATTRNAME);
		}
	}
    return FDO_SAFE_ADDREF(propertyNames.p);
}

FdoDataType SuperMapRasterPropertyDictionary::GetPropertyDataType (FdoString* name)
{
	if(NULL == name)
	{
		throw FdoException::Create( NlsMsgGet(SUPERMAP_UNEXPECTED_PARAMETER, 
			"Bad parameter to method.") );
	}
	FdoDataType dataType;
	if(NULL != m_pDatasetRaster)
	{
		if(m_pDatasetRaster->GetColorset().GetSize() > 0) //有调色板
		{
			if( wcscmp(name, PALETTEATTRNAME) == 0 )
			{
				dataType = FdoDataType_BLOB;
			}
			else if( wcscmp(name, NUMOFPALETTEENTRIESATTRNAME) == 0 )
			{
				dataType = FdoDataType_Int32;
			}
			else
			{
				throw FdoException::Create( NlsMsgGet(SUPERMAP_UNEXPECTED_PARAMETER, 
					"Bad parameter to method.") );
			}
		}
	}
    return dataType;
}

FdoDataValue* SuperMapRasterPropertyDictionary::GetProperty (FdoString* name)
{
	if(NULL == name)
	{
		throw FdoException::Create( NlsMsgGet(SUPERMAP_UNEXPECTED_PARAMETER, 
			"Bad parameter to method.") );
	}

    FdoPtr<FdoDataValue> dataValve;
    int numOfEntries = 0;

	if(NULL != m_pDatasetRaster)
	{
		UGC::UGColorset colorSet = m_pDatasetRaster->GetColorset();
		if(colorSet.GetSize() > 0) //有调色板
		{
			if( wcscmp(name, PALETTEATTRNAME) == 0 )
			{
				numOfEntries = colorSet.GetSize();
				FdoByte *palette = new FdoByte[4 * numOfEntries];
				if(NULL != palette)
				{
					for(int iEntry = 0; iEntry < numOfEntries; iEntry++)
					{
						palette[iEntry*4 + 0] = (colorSet.GetAt(iEntry) >> 16 ) & 0XFF;
						palette[iEntry*4 + 1] = (colorSet.GetAt(iEntry) >> 8 ) & 0XFF;
						palette[iEntry*4 + 2] = colorSet.GetAt(iEntry) & 0XFF;
						palette[iEntry*4 + 3] = 0X00;
					}
				}
				dataValve = FdoDataValue::Create((FdoByte*)palette, 4 * numOfEntries, FdoDataType_BLOB);
				delete[] palette;
			}
			else if( wcscmp(name, NUMOFPALETTEENTRIESATTRNAME) == 0 )
			{
				dataValve = FdoDataValue::Create( colorSet.GetSize() );
			}
			else
			{
				throw FdoException::Create( NlsMsgGet(SUPERMAP_UNEXPECTED_PARAMETER, 
					"Bad parameter to method.") );
			}
		}
	}
    return FDO_SAFE_ADDREF(dataValve.p);;
}

void SuperMapRasterPropertyDictionary::SetProperty (FdoString* name, FdoDataValue* value)
{
	return;
}

FdoDataValue* SuperMapRasterPropertyDictionary::GetPropertyDefault (FdoString* name)
{
	return NULL;
}

bool SuperMapRasterPropertyDictionary::IsPropertyRequired (FdoString* name)
{
	return false;
}

bool SuperMapRasterPropertyDictionary::IsPropertyEnumerable (FdoString* name)
{
	return false;
}

FdoDataValueCollection* SuperMapRasterPropertyDictionary::GetPropertyValues (FdoString* name)
{
	return NULL;
}

void SuperMapRasterPropertyDictionary::SetPropertyValues (FdoString* name, 
														  FdoDataValueCollection* collection)
{
	return;
}