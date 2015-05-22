// UGQuadTileArgs.h: UGinterface for the UGQuadTileArgs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADTILEARGS_H__B726612A_91CD_4533_AC27_C59604F40BF9__INCLUDED_)
#define AFX_UGQUADTILEARGS_H__B726612A_91CD_4533_AC27_C59604F40BF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
//#include "Scene/UGImgAccessor.h"
namespace UGC
{
class SCENE_API UGQuadTileArgs  
{
public:
	UGQuadTileArgs();
//	UGQuadTileArgs(ImgAccessorArray* pArrayTerrainAccessor,UGTerrainAccessor* pTerrainAccessor,
//					UGdouble dL0TileSizeDeg=36,UGfloat m_fTileDrawDistance=3.5, UGfloat fTileDrawSpread=2.8f);
	virtual ~UGQuadTileArgs();
//public:
//	void SetParam(ImgAccessorArray* pArrayImgAccessor=NULL,UGTerrainAccessor* pTerrainAccessor=NULL,
//					UGdouble dL0TileSizeDeg=36,UGfloat m_fTileDrawDistance=3.5, UGfloat fTileDrawSpread=2.8f
//		);
//
//public:
//	static UGint m_sMaxConcurrentDownloads;
//public:
//	UGbool m_bAlwaysRenderBaseTiles;
//	UGfloat m_fTileDrawSpread;
//	UGfloat m_fTileDrawDistance;
//	UGdouble m_dL0TileSizeDeg;
//	UGint m_TransparentColor;
//	UGbool m_bRenderFileNames;
//	UGbool m_bDownloadingElevation;
//	UGint m_nNumberRetries;
//	ImgAccessorArray* m_pArrayImgAccessor;
//	UGTerrainAccessor*  m_pTerrainAccessor;

};
}
#endif // !defined(AFX_UGQUADTILEARGS_H__B726612A_91CD_4533_AC27_C59604F40BF9__INCLUDED_)
