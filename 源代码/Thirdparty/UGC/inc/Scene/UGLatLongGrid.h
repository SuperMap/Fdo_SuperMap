// UGLatLongGrid.h: interface for the UGLatLongGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGLATLONGGRID_H__18708F47_91CB_45B5_9FB1_431ABE14B058__INCLUDED_)
#define AFX_UGLATLONGGRID_H__18708F47_91CB_45B5_9FB1_431ABE14B058__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"

namespace UGC 
{

class SCENE_API UGLatLongGrid : public UGRenderObject
{
public:
	UGLatLongGrid();
	UGLatLongGrid(UGdouble dWorldRadius);
	virtual ~UGLatLongGrid();

	virtual void Initialize();	
	virtual void Update();
	virtual void Render();
	virtual void Release();
	
private:
	void ComputeGridValues();

private:
	UGint m_nLatitudeInterval;
	UGint m_nLongitudeInterval;
	UGdouble m_dRadius;
	UGdouble m_dWorldRadius;
	UGint m_nMinVisibleLongitude;
	UGint m_nMaxVisibleLongitude;
	UGint m_nMinVisibleLatitude;
	UGint m_nMaxVisibleLatitude;
	UGint m_nLongitudePointCount;
	UGint m_nLatitudePointCount;
	UGbool m_bUseZBuffer;
};

}
#endif // !defined(AFX_UGLATLONGGRID_H__18708F47_91CB_45B5_9FB1_431ABE14B058__INCLUDED_)
