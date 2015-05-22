// UGTextureCacheEntry.h: interface for the UGTextureCacheEntry1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTURECACHEENTRY_H__2610B427_23D2_40CE_96B0_63D191FA1215__INCLUDED_)
#define AFX_UGTEXTURECACHEENTRY_H__2610B427_23D2_40CE_96B0_63D191FA1215__INCLUDED_
#include "Scene/UGPrerequisites.h"

namespace UGC
{

class SCENE_API UGTextureCacheEntry
{
public:
	UGTextureCacheEntry();
	UGTextureCacheEntry(UGTexture* pTexture);
	~UGTextureCacheEntry();

public:
	UGTexture* GetTexture();
	void SetTexture(UGTexture* pTexture);
	UGint ComparePath(const UGString& strPath);
	UGint ComparePath(UGTextureCacheEntry* pEntry);
	UGdouble CompareAccessTime(UGTextureCacheEntry* pEntry);
	UGdouble GetLastAccess();
	void SetLastAccess(UGdouble dLassAccess );

protected:
	UGdouble m_dLastAccess;
	UGTexture* m_pTexture;
};
}
#endif // !defined(AFX_UGTEXTURECACHEENTRY_H__2610B427_23D2_40CE_96B0_63D191FA1215__INCLUDED_)
