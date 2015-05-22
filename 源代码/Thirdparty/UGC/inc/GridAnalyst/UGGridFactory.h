// UGGridFactory.h: interface for the UGModelingOptions class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGRIDFACTORY_H)
#define UGGRIDFACTORY_H

#include "Base/UGRefPtr.h"
#include "UGGridOptions.h"

namespace UGC{

class UGRasterAnalystEnv;
class UGGridBuilder;
class GRIDANALYST_API UGGridFactory
{
public:
	UGGridFactory();
	virtual ~UGGridFactory();
	
public:
    //! \brief Set the Analyzing Enviroment 
	void SetAnalystEnv(UGRasterAnalystEnv* pAnalystEnv);
	UGRasterAnalystEnv* GetAnalystEnv();
    //! \brief Interplating from one scatter dataset
	UGDatasetRaster* Interpolate(UGDatasetVector* pVector,const UGString& strField,
		                const UGfloat fZScale,PixelFormat enPixelFormat,const UGString& strOutDtName,
						const UGGridOptions& options);
	//! \brief Interplating from two scatter datasets(point and the line)
	UGDatasetRaster* Interpolate(UGDatasetVector* pLine,const UGString& strLineField,
		                         UGDatasetVector* pPoint,const UGString& strPointField,
								 const UGfloat fZScale,PixelFormat enPixelFormat,
								 const UGString& strOutDtName,const UGGridOptions& options);
	//! \brief Test the accuracy of the selected methods and save it in the stream file of GridOptions
	//! \brief and now cross validation for the multible datasets interpolation had not been supported yet.
	void CrossValidate(UGDatasetVector* pVector,const UGString& strField,
		const UGfloat fZScale,const UGGridOptions& options);
protected:
	UGDatasetRaster* CreateResultGrid(UGDatasetVector* pVector,const UGString& strField,
									PixelFormat enPixelFormat,const UGString& strOutDtName,
									const UGGridOptions& options);
	UGGridBuilder* GetGridBuilder(const UGGridOptions::InterpolationType enType,const UGGridOptions::InterpolationMethods nMethods);
	UGRasterAnalystEnv* m_pAnalystEnv;
	UGRefPtr<UGGridBuilder> m_pGridBuilder;
};

}
#endif // !defined(UGGRIDFACTORY_H)





















