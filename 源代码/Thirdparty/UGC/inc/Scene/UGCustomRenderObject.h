#if !defined(AFX_UGCUSTOMRENDEROBJECT_H__618530B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
#define AFX_UGCUSTOMRENDEROBJECT_H__618530B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_

#include "Scene/UGRenderObject.h"
#include "Scene/UG3DStyle.h"

namespace UGC 
{

class SCENE_API UGCustomRenderObject : public UGRenderObject
{
public:
	UGCustomRenderObject(void);
	~UGCustomRenderObject(void);

	UG3DLineStyle m_LineStyle;

public:
	virtual void Render();
};
}
#endif // !defined(AFX_UGCUSTOMRENDEROBJECT_H__618530B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)