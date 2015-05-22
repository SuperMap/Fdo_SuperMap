// UGContourToGrid.h: interface for the UGContourToGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGCONTOURTOGRID_H)
#define UGCONTOURTOGRID_H
#include "GridAnalyst/UGGridAnalystHeaders.h"
#include "UGGridBuilder.h"
#include "Base/UGArray.h"
#include "GridAnalyst/UGGridOptions.h"
namespace UGC
{
struct demRowData
{
	UGbool bNoData;
	UGArray<UGint>nCols;
	UGArray<UGfloat>fValues;
	void operator =(demRowData& ArgRowData);
	UGshort Find(UGshort nIndex);
};
typedef UGArray<demRowData*>demRowDataArray;
struct demColData
{
	UGbool  bNoData;
	UGArray<UGint>nRows;
	UGArray<UGfloat>fValues;
	void operator =(demColData& ArgColData);
	
};
typedef UGArray<demColData*>demColDataArray;

class UGContourToGrid:public UGGridBuilder  
{
public:
	UGContourToGrid();
	virtual ~UGContourToGrid();
	UGbool Interpolating(UGDatasetVector* pVector,const UGString& strField,
		const UGfloat fZScale,const UGGridOptions& options, UGDatasetRaster* pResultGrid,UGbool bProgress);

	UGbool Interpolate(UGDatasetVector* pLine,const UGString& strLineField,
						UGDatasetVector* pPoint,const UGString& strPointField,
						const UGfloat fZScale,const UGGridOptions& options, 
						UGDatasetRaster* pResultGrid,UGbool bProgress);


protected:
	UGbool Interpolating(UGGridOptions::InterpolationMode nMode = UGGridOptions::FourDirections);
	UGbool GridContour(UGDatasetVector* pVector,const UGString& strField,const UGfloat fZScale,UGdouble dResolution);
	UGbool GridPoint(UGDatasetVector* pVector,const UGString& strField,const UGfloat fZScale,UGdouble dResolution);	
	void BinarySearch(UGint i, UGint *pData,UGint nSize,UGint & nLeft, UGint & nRight);
	//矢量栅格化采用Bresennham算法
	void RasterLine(UGint FromX,UGint FromY,UGint ToX,UGint ToY,UGdouble dValue); 
	void PolyPolyLine(UGPoint* pPoints, UGint *lpPolyCounts, UGint nSubCount);
	void PolyLine(UGPoint* pPoints,UGint nCount);
	void MoveTo(UGint X,UGint Y);
	void LineTo(UGint X,UGint Y);
private:
	UGDatasetRaster* m_pGrid;
	UGdouble m_dCurrentValue;
	UGint m_nPosX,m_nPosY;
	demRowDataArray m_arrRowData;
	demColDataArray m_arrColData;
	
	

};

}

#endif // !defined(UGCONTOURTOGRID_H)
