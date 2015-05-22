/** \file	 SuperMapStreamReader.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#include "SuperMap.h"

SuperMapStreamReader::SuperMapStreamReader(UGC::UGDatasetRaster *pDatasetRaster, 
										   FdoRasterDataModel* datamodel)
{
	TRACE(_T("调用 SuperMapStreamReader::SuperMapStreamReader()... \n"));
	m_pDatasetRaster = pDatasetRaster;
	m_nStreamIndex = 0; 
	m_dataModel = datamodel;
	m_nBytesPerPixel = 0;
}

SuperMapStreamReader::~SuperMapStreamReader(void)
{
	TRACE(_T("调用 SuperMapStreamReader::~SuperMapStreamReader()... \n"));
}

void SuperMapStreamReader::Dispose()
{
	TRACE(_T("调用 SuperMapStreamReader::Dispose()... \n"));
	delete this;
}

FdoInt64 SuperMapStreamReader::GetLength()
{
	TRACE(_T("调用 SuperMapStreamReader::GetLength()... \n"));

	//该处的长度是指流中整个影像中字节的总个数，计算方法为: 每个像素的字节数*影像的总像素
	FdoInt64 nStreamLength = 0;
	int nXLength = 0;
	int nYLength = 0;

	if(NULL != m_pDatasetRaster)
	{
		switch( m_pDatasetRaster->GetPixelFormat() )
		{
		case UGC::IPF_MONO: //单值
		case UGC::IPF_BYTE:
			if( IsPalletteImage() )
			{
				m_nBytesPerPixel = THREEBYTESPIXEL;
			}
			else
			{
				m_nBytesPerPixel = ONEBYTEPIXEL;
			}
			break;

		case UGC::IPF_FBIT: //4 bits
		case UGC::IPF_TBYTE: //16 bits
		case UGC::IPF_RGB: //24 bits
			m_nBytesPerPixel = THREEBYTESPIXEL;
			break;

		case UGC::IPF_RGBA: //32 bits
			m_nBytesPerPixel = FOURBYTESPIXEL;
			break;

		case UGC::IPF_TRGB: //48 bits
			m_nBytesPerPixel = SIXBYTESPERPIXEL;
			break;

		case UGC::IPF_LONGLONG: //64 bits
			m_nBytesPerPixel = EIGHTBYTESPERPIXEL;
			break;

		case UGC::IPF_FLOAT: //32 bits
			m_nBytesPerPixel = FOURBYTESPIXEL;
			break;

		case UGC::IPF_DOUBLE: //64 bits
			m_nBytesPerPixel = EIGHTBYTESPERPIXEL;
			break;

		default:
			m_nBytesPerPixel = THREEBYTESPIXEL;
			break;
		}
		nStreamLength  = m_pDatasetRaster->GetWidth() * m_pDatasetRaster->GetHeight() * m_nBytesPerPixel;
	}
	return nStreamLength;
}

void SuperMapStreamReader::Skip(const FdoInt32 offset)
{
	TRACE(_T("调用 SuperMapStreamReader::Skip()... \n"));
}

FdoInt64 SuperMapStreamReader::GetIndex()
{
	TRACE(_T("调用 SuperMapStreamReader::GetIndex()... \n"));
	return m_nStreamIndex;
}

void SuperMapStreamReader::Reset()
{
	TRACE(_T("调用 SuperMapStreamReader::Reset()... \n"));
}

FdoInt32 SuperMapStreamReader::ReadNext( FdoByte* buffer, const FdoInt32 offset, const FdoInt32 count)
{
	TRACE(_T("调用 SuperMapStreamReader::ReadNext(Byte)...偏移量[%d]..字节数[%d] \n"), offset, count);
	int nReadBytes = 0;
	if (count < -1 || offset < 0 || NULL == buffer || NULL == m_pDatasetRaster)
	{
		TRACE(_T("SuperMapStreamReader异常！！！"));
		return nReadBytes;
	}

	int nXLength = 0;  //图像的实际像素宽
	int nYLength = 0;  //图像的实际像素高
	int nImgColorType = IMGRGB24; // 默认为RGB格式
	UGC::UGDatasetRasterInfo* pRasterInfo = m_pDatasetRaster->GetInfo();
	if(NULL != pRasterInfo)
	{
		nXLength = pRasterInfo->m_nWidth;    
		nYLength = pRasterInfo->m_nHeight;

		switch( pRasterInfo->m_ePixelFormat )
		{
		case UGC::IPF_MONO: //单值
			nImgColorType = IMGMONO;
			break;

		case UGC::IPF_FBIT: //4 bits
			nImgColorType = IMGRGB4;
			break;

		case UGC::IPF_BYTE: //灰度
			nImgColorType = IMGGRAY;
			break;

		case UGC::IPF_TBYTE: //16 bits
			nImgColorType = IMGRGB16;
			break;

		case UGC::IPF_RGB: //24 bits
			nImgColorType = IMGRGB24;
			break;

		case UGC::IPF_RGBA: //32 bits
			nImgColorType = IMGRGB32;
			break;

		case UGC::IPF_TRGB: //48 bits 
			nImgColorType = IMGRGB48;
			break;

		case UGC::IPF_LONGLONG: //64 bits
			nImgColorType = IMGRGB64;
			break;

		case UGC::IPF_FLOAT: //float 32 bits
			nImgColorType = IMGRGBFLOAT;
			break;

		case UGC::IPF_DOUBLE: //double 64 bits
			nImgColorType = IMGRGBDOUBLE;
			break;

		default:
			break;
		}
	}
	int nViewXLength = nXLength;	//重采样后显示图像的宽度
	int nViewYLength = nYLength;	//重采样后显示图像的高度
	
	if(NULL != m_dataModel)			//获取显示图像的宽度和高度
	{
		nViewXLength = m_dataModel->GetTileSizeX();
		nViewYLength = m_dataModel->GetTileSizeY();
	}

	buffer += offset;
	return FuncRatioResample(buffer, nXLength, nYLength, nViewXLength, nViewYLength, nImgColorType, count);
}

FdoInt32 SuperMapStreamReader::ReadNext(  FdoArray<FdoByte> * &buffer, const FdoInt32 offset, const FdoInt32 count )
{
	TRACE(_T("调用 SuperMapStreamReader::ReadNext(FdoArray)... \n"));
	return ReadNext(buffer->GetData(), offset, count);
}

//目前UGC可支持读取像素最大长度为32位，还不支持48和64位的彩色图像，另外，像素值为double类型影像
//是DEM和ECW格式的，本系统暂不支持，但都留有接口，以下重采样函数只是读取如下格式的影像：
// 1、4、8、16、24、32位的影像，可以带调色板，也可以不带调色板
int SuperMapStreamReader::FuncRatioResample(FdoByte* buffer, int nFileXlen, int nFileYLen, 
		int nViewXLen, int nViewYLen, int nImgColorType, int nCount)
{
	TRACE(_T("调用 SuperMapStreamReader::FuncRatioResample()要读取的字节数[%d]... \n"), nCount);
	//FdoInt64 nStreamLenth = GetLength();
	//int nReadBytes = (nStreamLenth - m_nStreamIndex * m_nBytesPerPixel >= nCount) ? 
								//nCount : (nStreamLenth - m_nStreamIndex * m_nBytesPerPixel);
	int nReadBytes = nCount;
	double fXShowRatio = 1;			//X方向采样比例，默认为1
	double fYShowRatio = 1;			//Y方向采样比例，默认为1
	bool bImgSITFile = false;		//判断是否是SIT文件方式，SIT不能按块来缓冲
	if(m_pDatasetRaster->GetDataSource()->GetEngineType() == UGC::ImagePlugins)
	{
		bImgSITFile = true;
	}

	if(nViewXLen && nViewYLen)
	{
		fXShowRatio = double(nFileXlen) / double(nViewXLen);
		fYShowRatio = double(nFileYLen) / double(nViewYLen);
	}
	//影像金字塔的操作
	int ntPyramidCount = m_pDatasetRaster->GetPyramidDatasets().GetSize();
	if(ntPyramidCount > 0)
	{
		UGC::UGDatasets PyramidDatasets = m_pDatasetRaster->GetPyramidDatasets();
		int nPyramidIndex = int(log(double(fXShowRatio)) / log(double(2)) + 0.5);
		//如果对原图进行等大或者放大显示，直接读取原图即可
		if( nPyramidIndex <= 0)
		{
			m_pDatasetRaster = m_pDatasetRaster;
		}
		//对原图进行缩小显示，并且在金字塔范围内
		else if( nPyramidIndex > 0 && nPyramidIndex < ntPyramidCount) 
		{
			m_pDatasetRaster = (UGC::UGDatasetRaster *)PyramidDatasets.GetAt(nPyramidIndex - 1);
		}
		//对原图进行缩小显示，并且已经超出金字塔范围，直接取最上面一层
		else if( nPyramidIndex >= ntPyramidCount ) 
		{
			m_pDatasetRaster = (UGC::UGDatasetRaster *)PyramidDatasets.GetAt(ntPyramidCount - 1);
		}
		//取了金字塔的某一层后，需要重新计算要取图层的宽度和高度以及缩放比率
		if( !m_pDatasetRaster->IsOpen() )
		{
			m_pDatasetRaster->Open();
		}
		nFileXlen = m_pDatasetRaster->GetWidth();
		nFileYLen = m_pDatasetRaster->GetHeight();
		fXShowRatio = double(nFileXlen) / double(nViewXLen);
		fYShowRatio = double(nFileYLen) / double(nViewYLen);
		TRACE(_T("调用 SuperMapStreamReader::FuncRatioResample()金字塔共[%d]层.取得[%d]层.. \n"), ntPyramidCount, nPyramidIndex);
	}
	
	int nBlockSize = m_pDatasetRaster->GetBlockSize(); //影像块的大小
	int nColBlockCount = m_pDatasetRaster->GetColBlockCount(); //横向Block的个数
	int nRowIndex = 0; //行读取的索引
	int nRowBlockIndex = 0; //已经读取的块的行索引
	//SIT文件影像不能缓冲
	if( !bImgSITFile )
	{
		m_pDatasetRaster->CacheByBlock(0, nRowBlockIndex++, nColBlockCount, 1);
	}
	nRowIndex += nBlockSize;
	int nReadPixel = 0;
	bool bPalletteImage = IsPalletteImage();
	if(bPalletteImage)
	{
		TRACE(_T("调用 SuperMapStreamReader::ReadNext()有调色板信息]... \n"));
	}
	for(int i = 0; i < nViewYLen; i++)
	{
		for(int j = 0; j < nViewXLen; j++)
		{
			int nPixelX = int(j * fXShowRatio + 0.5);
			int nPixelY = int(i * fYShowRatio + 0.5);

			//如果当前像素不在已经缓冲的块内，就释放所有块
			if( nPixelY >= nRowIndex) 
			{
				m_pDatasetRaster->ReleaseAllBlock();
				//SIT文件影像不能缓冲
				if( !bImgSITFile )
				{
					m_pDatasetRaster->CacheByBlock(0, nRowBlockIndex++, nColBlockCount, 1);
				}
				nRowIndex += nBlockSize;
			}
			UGC::UGuint color = m_pDatasetRaster->GetPixel(nPixelX, nPixelY);
			if(bPalletteImage)
			{
				*(buffer++) = UGC::UGREDVAL(color);
				*(buffer++) = UGC::UGGREENVAL(color);
				*(buffer++) = UGC::UGBLUEVAL(color);
			}
			else //无调色板
			{
				switch(nImgColorType)
				{
				case IMGMONO: //单值
					{
						*(buffer++) = color & 0XFF;
						break;
					}
				case IMGRGB4: //4 bits
					{
						/*UGC::UGbyte colorB = (color >> 3) & 0X01;
						UGC::UGbyte colorG = (color >> 1) & 0X03;
						UGC::UGbyte colorR = color & 0X01;

						*(buffer++) = colorR;
						*(buffer++) = colorG;
						*(buffer++) = colorB;*/
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						break;
					}
				case IMGGRAY: //灰度
					{
						*(buffer++) = color & 0XFF;
						break;
					}
				case IMGRGB16: //16 bits
					{
						/*UGC::UGbyte colorB = (color >> 11) & 0X1F;
						UGC::UGbyte colorG = (color >> 5) & 0X3F;
						UGC::UGbyte colorR = color & 0X1F;

						*(buffer++) = colorR;
						*(buffer++) = colorG;
						*(buffer++) = colorB;*/
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						//TRACE(_T("调用 SuperMapStreamReader::红=[%d]绿=[%d]蓝=[%d]... \n"), UGC::UGREDVAL(color), UGC::UGGREENVAL(color), UGC::UGBLUEVAL(color));
						break;
					}
				case IMGRGB24: //24 bits
					{
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						break;
					}
				case IMGRGB32: //32 bits
					{
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						*(buffer++) = UGC::UGALPHAVAL(color);
						break;
					}
				case IMGRGB48: //48 bits	
				case IMGRGB64: //64 bits
					break;

				case IMGRGBFLOAT: //float 32 bits
				case IMGRGBDOUBLE: //double 64 bits
					break;

				default:
					break;
				}//switch
			}//else
			nReadPixel++;
		} //for
	} //for
	m_pDatasetRaster->ReleaseAllBlock(); //释放所有块
	m_nStreamIndex += nReadPixel;
	TRACE(_T("调用 SuperMapStreamReader::ReadNext()读取的字节数[%d]... \n"), nReadBytes);
	return nReadBytes;
}

bool SuperMapStreamReader::IsPalletteImage()
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