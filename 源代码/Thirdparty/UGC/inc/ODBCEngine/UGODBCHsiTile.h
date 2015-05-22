// UGODBCHsiTile.h: interface for the UGODBCHsiTile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCHSITILE_H__D9C25AB6_095A_4104_945E_325C346C0C2B__INCLUDED_)
#define AFX_UGODBCHSITILE_H__D9C25AB6_095A_4104_945E_325C346C0C2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ODBCEngine/UGODBCDatasetVector.h"
#include "Geometry/UGGeoRect.h"
namespace UGC{
class UGEXPORT UGODBCHsiTile  
{
public:
	enum HSI_TYPE
	{
		HSI_GRID = 0,
			HSI_FIELD = 1,	
	};
	UGbool AddGeometry(UGint nID, UGdouble dL, UGdouble dT, UGdouble dR, UGdouble dB);
	//! \brief三级索引向索引表写数据
	UGbool Build();
	UGODBCHsiTile();
	virtual ~UGODBCHsiTile();

	HSI_TYPE m_nType;
	UGVariant m_varValue;
	UGint m_nLibTileID;
	UGint m_nRow;
	UGint m_nCol;
	UGRect2D m_rc2Grid;
	UGRect2D m_rc2GeoBounds;
	UGArray<UGint> m_IDs;

	UGODBCDatasetVector * m_pVector;

};

}

#endif // !defined(AFX_UGODBCHSITILE_H__D9C25AB6_095A_4104_945E_325C346C0C2B__INCLUDED_)
