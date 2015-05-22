// UGImgAccessor.h: interface for the UGImgAccessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMGACCESSOR_H__001DE66D_8068_487E_82F3_54013FEBFD61__INCLUDED_)
#define AFX_UGIMGACCESSOR_H__001DE66D_8068_487E_82F3_54013FEBFD61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"


namespace UGC
{
class UGGoogleLayerTile;
class UGVeTile;
class SCENE_API UGImgAccessor  
{
public:
	UGImgAccessor();
	virtual ~UGImgAccessor();
	UGImgAccessor(
		UGString permanentTextureDirectory, 
		UGint textureSizePixels, 
		UGint numberLevels,
		UGString imageFileExtension,
		UGString cacheDirectory);
	UGString GetLocalPath(UGQuadTile* pQuadTile);
	UGString GetLocalPath(UGGoogleLayerTile* pQuadTile);
	UGString GetLocalPath(UGVeTile* pQuadTile);
	UGString GetLocalPath(UGint nRow,UGint nCol,UGint nLevel);
	void DeleteLocalCopy(UGQuadTile* pQuadTile);
public:
	UGint GetNumberLevels();

protected:	
	UGImgServer *m_pImgServer;
	UGint m_nNumberLevels;	
	
	UGint	m_nTexSize;
	UGString m_strImgExt;
	UGString m_strCacheDir;
	UGString m_strDuplicateTexPath;
	UGString m_strImgPath;
};
}
#endif 