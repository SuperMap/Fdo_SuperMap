//$ID$
//$Author: caogf $
//$Date: 2005/06/10 08:09:10 $
//$Source: /export/home/UGC60/01_SourceCode/Include/GridAnalyst/UGGridBuilder.h,v $
//$Revision: 1.3 $
//$Log: UGGridBuilder.h,v $
//Revision 1.3  2005/06/10 08:09:10  caogf
//no message
//
//Revision 1.2  2005/06/09 23:53:03  caogf
//no message
//
#if !defined(UGGRIDBUILDER_H)
#define UGGRIDBUILDER_H

#include "GridAnalyst/UGGridAnalystHeaders.h"
#include "Base/UGReferenced.h"
#include "Algorithm/UGRect2D.h"
namespace UGC{
class UGProgress;
class UGGridOptions;
class UGPoint3D;
class GRIDANALYST_API UGGridBuilder: public UGReferenced
{
public:

	UGGridBuilder();
	//! \brief Interpolate the Grid dataset from one dataset;
	virtual UGbool Interpolate(UGDatasetVector* pVector,const UGString& strField,
		const UGfloat fZScale,const UGGridOptions& options, UGDatasetRaster* pResultGrid,UGbool bProgress);

	//! \brief Cross Validation is a general way to test the accuracy of the result
	virtual UGbool CrossValidate(UGDatasetVector* pVector,const UGString& strField,const UGfloat fZScale,
		const UGGridOptions& options,UGbool bProgress);

	//! \brief Interpolate the Grid dataset from multiple datasets;
	virtual UGbool Interpolate(UGDatasetVector* pLine,const UGString& strLineField,
								UGDatasetVector* pPoint,const UGString& strPointField,
								const UGfloat fZScale,const UGGridOptions& options, 
								UGDatasetRaster* pResultGrid,UGbool bProgress){return FALSE;}

	
protected:
	virtual ~UGGridBuilder();
   	//! \brief Filling the Point Data
	virtual UGbool FillDataArray(UGDatasetVector* pVector,const UGString& strField,const UGfloat fZScale,UGbool bProgress);
	//! \brief Implemention details here
	virtual UGbool DoInterpolation(UGDatasetRaster* pResultGrid,const UGGridOptions& options){return FALSE;}
	//!\ brief Implemention details here
	virtual UGbool DoCrossValidation(const UGGridOptions& options){return FALSE;}
	
protected:
	UGProgress* m_pProgress;
	UGPoint3D* m_pPointList;
	UGint m_nPointCount;
	//! \brief The bounds of the input data
	UGRect2D m_rcBounds;
};

static void UniquePoints(UGPoint3D* pPointList,UGint nCount,UGint& nTotalCount);

}

#endif // !defined(UGGRIDBUILDER_H)

