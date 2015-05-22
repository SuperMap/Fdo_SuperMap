// UGImage.h: interface for the UGImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGIMAGE_H)
#define UGIMAGE_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"

namespace UGC{	
class UGDatasetRaster;
class GRAPHICS3D_API UGImageEx  
{
public:
	enum PixelFormat
	{
		COLOUR_INDEX, //GL_COLOUR_INDEX
		STENCIL_INDEX,	//COLOR_INDEX	
		DEPTH,	//GL_DEPTH_COMPONENT							
		RED, //GL_RED
		GREEN,//GL_GREEN
		BLUE,//GL_BLUE
		ALPHA,//GL_ALPHA
		RGB,//GL_RGB
		RGBA,//GL_RGBA					
		BGR, //GL_BGA							 
		BGRA, //GL_BGRA								
		LUMINANCE, //GL_LUMINANCE
		LUMINANCE_ALPHA, //GL_LUMINNANCE_ALPHA		
		RGB_DXT1, //GL_COMPRESSED_RGB_S3TC_DXT1_EXT
		RGBA_DXT1, //GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
		RGBA_DXT3, //GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
		RGBA_DXT5, //GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
	};
	enum DataType
	{
		UNSIGNEDBYTE, //GL_UNSIGNED_BYTE
		BYTE, //GL_BYTE
		BITMAP, //GL_BITMAP
		UNSIGNEDSHORT,//GL_UNSIGNED_SHORT
		SHORT, //GL_SHORT
		UNSIGNEDINT,//GL_UNSIGNED_INT
		INT, //GL_INT
		FLOAT//GL_FLOAT
			//extensions....
	};
public:
	UGImageEx();
	virtual ~UGImageEx();
	void SetFileName(const UGString& strFileName);
	UGString GetFileName();

	void SetDataset(const UGDatasetRaster* pRaster);
	UGDatasetRaster* GetDataset();

	void Load(const UGString& strName);
	void Load(UGDatasetRaster* pDataset);
	
	//!\brief Get the corresponding information about this image 
	UGint GetWidth();
	UGint GetHeight();
	UGint GetDepth();
	UGint GetImageSizeInBytes();
	UGint GetComponentCount();
	UGint GetPixelSizeInBits();
	UGint GetRowWidthInBytes();
	UGint ComputeComponentCount(PixelFormat pf);
	UGint ComputePixelSizeInBits(PixelFormat pf, DataType dt);
	UGint ComputeRowWidthInBytes(UGint nWidth, PixelFormat pf,DataType dt, UGint nPacking);
	UGint GetMipmapLevels()const;
	UGint IsMipmap()const;
	UGbool HasAlpha();
	UGuchar* GetData();
	const UGuchar* GetData()const;
	UGchar* GetMipmapData(UGint nLevels)const;
	PixelFormat GetPixelFormat();

	//!\brief Some operations on this image;
	void SetPixelFormat(PixelFormat pf);
	//!\brief allocate the meomory
	void AllocateImage(UGint nWidth,UGint nHeight, UGint nDepth,PixelFormat pf, DataType dt,UGint nPacking);
	void DelocateImage();
	void ReadPixels(UGint nX, UGint nY, UGint nWidth, UGint nHeight,PixelFormat pf,DataType dt);
	void EnsureValidSizeForTexture(UGint nTextureSize);	
	void ScaleImage(UGint nNewWidth,UGint nNewHeight, UGint nNewDepth, DataType dt);
	void FlipHorizonal();
	void FlipVertical();

protected:
	UGString m_strName;
	UGint m_nWidth;
	UGint m_nHeight;
	UGint m_nDepth;
	UGuchar *m_pData;
	PixelFormat m_enPixelFormat;
	DataType m_enDataType;
	UGint m_nPacking;
	UGbool m_bModified;
	UGArray<UGint>m_MipmapData;
	UGDatasetRaster* m_pRaster;
};
}

#endif // !defined(UGIMAGE_H)
