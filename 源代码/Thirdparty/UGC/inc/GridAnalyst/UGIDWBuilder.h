// UGIDW.h: interface for the UGIDW class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGIDWBUILDER_H)
#define UGIDWBUILDER_H

#include "GridAnalyst/UGGridBuilder.h"

namespace UGC{
class UGKdTree;
class UGIDWBuilder : public UGGridBuilder
{
public:
	UGIDWBuilder();
	virtual ~UGIDWBuilder();
protected:
	UGbool DoInterpolation(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	UGbool DoCrossValidation(const UGGridOptions& options);
	//! \brief Interpolate without search(including all the points) useful when the points set is not too large
	UGbool Interpolate1(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief Interpolate with search by certain amount of points specified by the users.
	UGbool Interpolate2(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief Interpolate with search by certain distance specified by the users.
	UGbool Interpolate3(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	
	UGKdTree* m_pKdTree;
};
}

#endif // !defined(UGIDWBUILDER_H)





















