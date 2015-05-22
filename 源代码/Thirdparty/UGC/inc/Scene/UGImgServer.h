// UGImgServer.h: interface for the UGImgServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMGSERVER_H__E1DEB11B_362A_4D88_B113_49CFBA2C14FC__INCLUDED_)
#define AFX_UGIMGSERVER_H__E1DEB11B_362A_4D88_B113_49CFBA2C14FC__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC
{
class SCENE_API UGImgServer  
{
public:
	UGImgServer(UGString strServerUrl);
	virtual ~UGImgServer();

public:
	UGbool DownloadImgDataFile(UGQuadTile* pQuadTile, UGString strFileExt, UGString strLocalPath);
	
protected:
	UGString m_strServerUrl;
};

}
#endif // !defined(AFX_UGIMGSERVER_H__E1DEB11B_362A_4D88_B113_49CFBA2C14FC__INCLUDED_)
