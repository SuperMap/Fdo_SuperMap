// UGRBFBuilder.h: interface for the UGRBFBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRBFBUILDER_H)
#define UGRBFBUILDER_H
#include "UGGridBuilder.h"

namespace UGC{
class UGQuadNode;
class UGKdTree;

class UGRBFBuilder: public UGGridBuilder
{
public:
	UGRBFBuilder();
	virtual ~UGRBFBuilder();
protected:
	//! \brief 通过查找最近点进行插值
	virtual UGbool DoInterpolation(UGDatasetRaster* pResultGrid,const UGGridOptions& options);	
	//! \brief 不进行搜索，用全部的点进行运算，这对于点数两比较少的时候比较有效
	UGbool Interpolate1(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief 按照KDTree找临近点的方法计算,指定点数
	UGbool Interpolate2(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief 按照KDTree找临时点,指定距离
	UGbool Interpolate21(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief 按照四茶树分块进行插值
	UGbool Interpolate3(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief Implemention details here
	void QuadInterpolate(UGDatasetRaster* pResultGrid,UGQuadNode* pTree);
	

//	UGbool InterpolateCRS();
	//!\brief Radial basis function - regularized spline with tension (d=2)
	//!\param r distance squared
	//!\param fi tension 
	UGdouble CRST(UGdouble r, UGdouble fi);
	//!\brief Derivatives of radial basis function - regularized spline with tension(d=2)
	//!\param r distance squared
	//!\param fi tension
	UGdouble CRSTG(UGdouble r, UGdouble fi,UGdouble *gd1,UGdouble *gd2);

protected:

	UGKdTree* m_pKdTree;
	UGQuadNode* m_pQuadRoot;
	UGint m_nNodeCount;
	UGint m_nCurrentNode;
	UGint m_nMax;
	UGint m_nMax2;
	UGdouble m_dTension;
	UGdouble m_dSmooth;
};	


}
#endif // !defined(UGRBFBUILDER_H)





















