// UGLightNode.h: interface for the UGLightNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGLIGHTNODE_H)
#define UGLIGHTNODE_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGNode.h"

namespace UGC
{
class GRAPHICS3D_API UGLightNode:public UGNode 
{
public:
	enum ReferenceFrame
	{
		RELATIVE_RF,
        ABSOLUTE_RF
	};
	enum ModeValue
	{
		LIGHT_ON = 0,
		LIGHT_OFF = 1
	};
public:
	UGLightNode();
	virtual ~UGLightNode();
	

	void SetLight(UGLight* pLight);
	UGLight* GetLight();

	void SetReferenceFrame(ReferenceFrame enFrame);
	ReferenceFrame  GetReferenceFrame();

	void SetModeValue(ModeValue enValue);
	ModeValue GetModeValue();
	
protected:
	UGLight* m_pLight;
	ReferenceFrame m_ReferenceFrame;
	ModeValue m_enModeValue;
};

}

#endif // !defined(AFX_UGLIGHTNODE_H__9B466BEC_A515_4B12_9813_EA7EE992B5C8__INCLUDED_)
