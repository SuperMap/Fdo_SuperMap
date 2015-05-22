// UGUdbMetadata.h: interface for the UGUdbMetadata class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGUdbMetadata_H)
#define UGUdbMetadata_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGMetaData.h"

namespace UGC
{

class UDBENGINE_API UGUdbMetadata :public UGMetadata
{
public:
	UGUdbMetadata();
	UGUdbMetadata(UGDataSource *pDatasource);
	virtual ~UGUdbMetadata();
};

}

#endif // !defined(UGUdbMetadata_H)
