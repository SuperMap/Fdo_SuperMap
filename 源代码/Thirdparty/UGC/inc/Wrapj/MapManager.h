// MapManager.h: interface for the MapManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPMANAGER_H__B15C5511_8F0B_4FE0_AE05_1389F8D6C518__INCLUDED_)
#define AFX_MAPMANAGER_H__B15C5511_8F0B_4FE0_AE05_1389F8D6C518__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Wrapj/UJImage.h"
#include "Wrapj/SuperMapStubH.h"

// m_nRepaintType如果为1表示需要OnDraw，如果为2表示需要更新Image。
typedef struct MapConnection
{	
	UGMapWnd* m_MapWnd;
	UGint m_nRepaintType;
};



class MapManager  
{
public:	
	MapManager();
	virtual ~MapManager();
	void ADDMapConnection(MapConnection* pConnection);
	
public:
	UGint HasMapHandle(UGlong MapHandle);
	UGArray<MapConnection*> m_MapManager;
};

MapManager * GetMapManager();


#endif // !defined(AFX_MAPMANAGER_H__B15C5511_8F0B_4FE0_AE05_1389F8D6C518__INCLUDED_)
