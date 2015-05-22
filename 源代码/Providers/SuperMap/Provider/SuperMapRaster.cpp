/** \file	 SuperMapRaster.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#include "SuperMap.h"

SuperMapRaster::SuperMapRaster(UGC::UGDatasetRaster *pDatasetRaster, FdoClassDefinition* ClassDef)
{
	TRACE(_T("调用 SuperMapRaster::SuperMapRaster()... \n"));
	m_nBandNum = 1;
	m_nCurBand = 1;
	m_bNull = false;
	m_pDatasetRaster = pDatasetRaster;
	m_ClassDef = ClassDef;
}

SuperMapRaster::~SuperMapRaster(void)
{
	TRACE(_T("调用 SuperMapRaster::~SuperMapRaster()... \n"));
}

void SuperMapRaster::Dispose()
{
	TRACE(_T("调用 SuperMapRaster::Dispose()... \n"));
	delete this;
}

FdoInt32 SuperMapRaster::GetNumberOfBands ()
{
	TRACE(_T("调用 SuperMapRaster::GetNumberOfBands()... \n"));
	return m_nBandNum;
}

void SuperMapRaster::SetNumberOfBands (FdoInt32 value)
{
	TRACE(_T("调用 SuperMapRaster::SetNumberOfBands()... \n"));
	m_nBandNum = value;
}

FdoInt32 SuperMapRaster::GetCurrentBand ()
{
	TRACE(_T("调用 SuperMapRaster::GetCurrentBand()... \n"));
	return m_nCurBand;
}

void SuperMapRaster::SetCurrentBand (FdoInt32 value)
{
	TRACE(_T("调用 SuperMapRaster::SetCurrentBand()... \n"));
	m_nCurBand = value;
}

bool SuperMapRaster::IsNull ()
{
	TRACE(_T("调用 SuperMapRaster::IsNull()... \n"));
	return m_bNull;
}

void SuperMapRaster::SetNull ()
{
	TRACE(_T("调用 SuperMapRaster::SetNull()... \n"));
	m_bNull = true;        
}

FdoByteArray* SuperMapRaster::GetBounds ()
{
	TRACE(_T("调用 SuperMapRaster::GetBounds()... \n"));
	FdoPtr<FdoByteArray> ret;
	FdoPtr<FdoIEnvelope> envelope;                      //包围盒

	if( NULL != m_pDatasetRaster )
	{
		UGC::UGRect2D recBound = m_pDatasetRaster->GetBounds();

		TRACE(_T("调用 SuperMapRaster::GetBounds()...left=[%f],bottom=[%f],top=[%f],right=[%f] \n"),
			recBound.left, recBound.bottom, recBound.top, recBound.right);

		FdoFgfGeometryFactory *pFactory = FdoFgfGeometryFactory::GetInstance();
		if( NULL != pFactory )
		{
			envelope = pFactory->CreateEnvelopeXY(recBound.left, 
				recBound.bottom,
				recBound.right, 
				recBound.top);
			FdoPtr<FdoIGeometry> geometry = pFactory->CreateGeometry(envelope);
			ret = pFactory->GetFgf(geometry.p);
		}
	}

	return FDO_SAFE_ADDREF(ret.p); 
}

void SuperMapRaster::SetBounds (FdoByteArray* bounds)
{
	TRACE(_T("调用 SuperMapRaster::SetBounds()... \n"));
	int *pGeoArray = (int*)bounds->GetData();
	bool bThreeDim = false; //判断是否是三维
	double MaxX, MaxY, MinX, MinY;
	if(FdoGeometryType_Polygon != *(pGeoArray++)) //判断类型
	{
		return;
	}
	else
	{
		if(FdoDimensionality_XY != *(pGeoArray++))
		{
			bThreeDim = true;
		}
		if( 1 !=*(pGeoArray++) ) //多个环的情况
		{
			return;
		}
		if( 5 != *(pGeoArray++) )//多余5各点的环
		{
			return;
		}
		double *pCoordinate = (double *)pGeoArray;
		MinX = MaxX = *(pCoordinate++);
		MaxY = MinY = *(pCoordinate++);
		if(bThreeDim)
		{
			pCoordinate++; //忽略第三维
		}
		for(int i = 0; i< 4; i++)
		{
			double CoordinateX = *(pCoordinate++);
			if(MinX > CoordinateX)
			{
				MinX = CoordinateX;
			}
			if(MaxX < CoordinateX)
			{
				MaxX = CoordinateX;
			}
			double CoordinateY = *(pCoordinate++);
			if(MinY > CoordinateY)
			{
				MinY = CoordinateY;
			}
			if(MaxY < CoordinateY)
			{
				MaxY = CoordinateY;
			}
			if(bThreeDim)
			{
				pCoordinate++; //忽略第三维
			}
		}//for
		if( NULL != m_pDatasetRaster )
		{
			UGC::UGRect2D recBound(MinX, MaxY, MaxX, MinY);
			m_pDatasetRaster->SetBounds(recBound);
		}

	}//else
}

FdoRasterDataModel* SuperMapRaster::GetDataModel ()
{
	TRACE(_T("调用 SuperMapRaster::GetDataModel()... \n"));
	if(NULL != m_dataModel)
	{
		return  FDO_SAFE_ADDREF(m_dataModel.p);
	}
	m_dataModel = FdoRasterDataModel::Create();
	if( NULL != m_pDatasetRaster )
	{
		UGC::UGDatasetRasterInfo* pRasterInfo = m_pDatasetRaster->GetInfo();
		if( NULL != pRasterInfo )
		{	
			m_dataModel->SetTileSizeX(m_pDatasetRaster->GetWidth()); // 设置块的大小
			m_dataModel->SetTileSizeY(m_pDatasetRaster->GetHeight()); 
			m_dataModel->SetOrganization(FdoRasterDataOrganization_Pixel);

			FdoRasterDataModelType nDataModelType = FdoRasterDataModelType_RGB;
			FdoRasterDataType nDataType = FdoRasterDataType_UnsignedInteger;
			switch(pRasterInfo->m_ePixelFormat)
			{
			case UGC::IPF_MONO: //单值图像
			case UGC::IPF_BYTE: //8位图像，有可能是灰度图像，也有可能是带有调色板的彩色图像
				if( IsPalletteImage() )
				{
					nDataModelType = FdoRasterDataModelType_RGB;
					nDataType = FdoRasterDataType_UnsignedInteger;
					m_dataModel->SetBitsPerPixel( RGB24 ); 
				}
				else //灰度图像
				{
					nDataModelType = FdoRasterDataModelType_Gray;
					nDataType = FdoRasterDataType_UnsignedInteger;
					m_dataModel->SetBitsPerPixel( GRAYORMONO ); 
				}
				break;

			case UGC::IPF_RGB: //RGB图像
			case UGC::IPF_TBYTE: //16位彩色图像
			case UGC::IPF_FBIT: //4位彩色图像
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( RGB24 ); 
				break;

			case UGC::IPF_RGBA: //RGBA图像
				nDataModelType = FdoRasterDataModelType_RGBA;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( RGBA32 ); 
				TRACE(_T("调用 SuperMapRaster::GetDataModel()...RGBA模式 \n"));
				break;
			case UGC::IPF_TRGB: //TRGB图像
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( TRGB48 ); 
				break;

			case UGC::IPF_LONGLONG:
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( RGB64 ); 
				break;

			case UGC::IPF_FLOAT:
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_Float;
				m_dataModel->SetBitsPerPixel( RGBA32 ); 
				break;

			case UGC::IPF_DOUBLE:
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_Double;
				m_dataModel->SetBitsPerPixel( RGB64 ); 
				break;

			default:
				break;
			}
			m_dataModel->SetDataModelType(nDataModelType);
			m_dataModel->SetDataType( nDataType );
		}
	}
	return  FDO_SAFE_ADDREF(m_dataModel.p);
}

void SuperMapRaster::SetDataModel (FdoRasterDataModel* datamodel)
{
	TRACE(_T("调用 SuperMapRaster::SetDataModel()... \n"));
	if (datamodel == NULL || !m_bNull)
	{
		return;
	}
	FdoPtr<SuperMapRasterCapabilities> rasterCap = new SuperMapRasterCapabilities();
	if (!rasterCap->SupportsDataModel(datamodel))
	{
		return;
	}
	m_dataModel = FDO_SAFE_ADDREF(datamodel);
}

FdoInt32 SuperMapRaster::GetImageXSize ()
{
	int nImageX = 0;
	if(NULL != m_dataModel)
	{
		nImageX = m_dataModel->GetTileSizeX( );
	}
	else if( NULL != m_pDatasetRaster)
	{
		nImageX = m_pDatasetRaster->GetWidth();
	}
	TRACE(_T("调用 SuperMapRaster::GetImageXSize()...X=[%d] \n"), nImageX);
	return nImageX;
}

void SuperMapRaster::SetImageXSize (FdoInt32 size)
{
	TRACE(_T("调用 SuperMapRaster::SetImageXSize()...X=[%d] \n"), size);
	if(NULL != m_dataModel)
	{
		m_dataModel->SetTileSizeX(size);
	}
}

FdoInt32 SuperMapRaster::GetImageYSize ()
{
	int nImageY = 0;
	if(NULL != m_dataModel)
	{
		nImageY = m_dataModel->GetTileSizeY( );
	}
	else if( NULL != m_pDatasetRaster)
	{
		nImageY = m_pDatasetRaster->GetHeight();
	}
	TRACE(_T("调用 SuperMapRaster::GetImageYSize()...Y=[%d] \n"), nImageY);
	return nImageY;

}

void SuperMapRaster::SetImageYSize (FdoInt32 size)
{
	TRACE(_T("调用 SuperMapRaster::SetImageYSize()...Y=[%d] \n"), size);
	if(NULL != m_dataModel)
	{
		m_dataModel->SetTileSizeY(size);
	}
}

FdoIRasterPropertyDictionary* SuperMapRaster::GetAuxiliaryProperties ()
{
	TRACE(_T("调用 SuperMapRaster::GetAuxiliaryProperties()... \n"));
	return NULL;
}

FdoDataValue* SuperMapRaster::GetNullPixelValue ()
{
	TRACE(_T("调用 SuperMapRaster::GetNullPixelValue()... \n"));
	FdoPtr<FdoDataValue> val;
	if( NULL != m_pDatasetRaster )
	{
		double noValue = m_pDatasetRaster->GetNoValue();
		val = FdoDoubleValue::Create(noValue);
	}
	return FDO_SAFE_ADDREF(val.p);
}

void SuperMapRaster::SetStreamReader (FdoIStreamReader* reader)
{
	TRACE(_T("调用 SuperMapRaster::SetStreamReader()... \n"));
}

FdoIStreamReader* SuperMapRaster::GetStreamReader ()
{
	TRACE(_T("调用 SuperMapRaster::GetStreamReader()... \n"));
	FdoPtr<FdoIStreamReader> streamReader = new SuperMapStreamReader(m_pDatasetRaster, 
		FDO_SAFE_ADDREF(m_dataModel.p));
	return FDO_SAFE_ADDREF(streamReader.p);
}

FdoString* SuperMapRaster::GetVerticalUnits ()
{
	TRACE(_T("调用 SuperMapRaster::GetVerticalUnits()... \n"));
	return L"";
}

void SuperMapRaster::SetVerticalUnits (FdoString* units)
{
	TRACE(_T("调用 SuperMapRaster::SetVerticalUnits()... \n"));
}


bool SuperMapRaster::IsPalletteImage()
{
	if(NULL == m_pDatasetRaster)
	{
		return false;
	}
	if( m_pDatasetRaster->GetColorset().GetSize() == 0 ) //无调色板
	{
		return false;
	}
	else
	{
		return true;
	}
}