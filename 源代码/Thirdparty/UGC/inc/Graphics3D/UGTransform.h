// UGTransform.h: interface for the UGTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGTRANSFORM_H )
#define UGTRANSFORM_H 

#include "UGGroup.h"

namespace UGC{
class UGMatrix;
class UGNodeVisitor;	
class GRAPHICS3D_API UGTransform:public UGGroup 
{
public:
	enum ReferenceFrame
	{
		RELATIVE_RF,
        ABSOLUTE_RF
	};
public:
	UGTransform();
	virtual ~UGTransform();	
	void SetReferenceFrame(ReferenceFrame frame);
	ReferenceFrame GetReferenceFrame();

	//!\brief switch between the world matrix and the local matrix
	virtual UGbool ComputeLocalToWorldMatrix(UGMatrix& matrix,UGNodeVisitor*) const{return FALSE;};
	virtual UGbool ComputeWorldToLocalMatrix(UGMatrix& matrix,UGNodeVisitor*) const{return FALSE;};

	
protected:
	ReferenceFrame m_enReferenceFrame;
};
}

#endif // !defined(UGTRANSFORM_H)
