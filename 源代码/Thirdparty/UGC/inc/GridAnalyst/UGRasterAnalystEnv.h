// UGRasterAnalystEnv.h: interface for the UGRasterAnalystEnv class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRASTERANALYSTENV_H)
#define UGRASTERANALYSTENV_H

#include "GridAnalyst/UGGridAnalystHeaders.h"
#include "Base/UGString.h"

namespace UGC{
	
class GRIDANALYST_API UGRasterAnalystEnv  
{
public:
	UGRasterAnalystEnv();
	virtual ~UGRasterAnalystEnv();
	void SetOutputDataSource(UGDataSource* pOutputDataSource);
	UGDataSource* GetOutputDataSource();


	UGString GetDftOutputRasterPre();
	void SetDftOutputRasterPre(const UGString& strPrefix);

	UGString GetDftOutputVectorPre();
	void SetDftOutputVecterPre(const UGString& strPrefix);

//	void SetProjectionTransformation(UGbool bTransformation);
//	UGbool GetProjectionTransformation();
	
	void SetShowProgress(UGbool bShow);
	UGbool GetShowProgress();

protected:
	
	UGString GetOutputName(UGbool bIsVector);
private:
	UGDataSource* m_pDatasource;
	UGbool  m_bShowProgress;
	UGString m_strDefaultOutputRasterPrefix;
	UGString m_strDefaultOutputVectorPrefix;
	//!switch on/off the transformation of the projection when the 
	//!the source projection and the destination projection is different
//	UGbool  m_bProjectionTransform;
	
};
}

#endif // !defined(UGRASTERANALYSTENV_H)
