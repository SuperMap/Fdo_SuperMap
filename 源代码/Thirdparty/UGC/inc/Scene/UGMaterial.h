// UGMaterial.h: interface for the UGMaterial1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATERIAL_H__E85252C6_682E_4604_B276_C6EDA7B0F030__INCLUDED_)
#define AFX_UGMATERIAL_H__E85252C6_682E_4604_B276_C6EDA7B0F030__INCLUDED_
#include "Scene/UGPrerequisites.h"

namespace UGC
{

class SCENE_API UGMaterial 
{
public:
	UGMaterial();
	~UGMaterial();

public:
	void SetTexPath(UGString value);
	UGString GetTexPath();
	void SetName(UGString value);
	UGString GetName();
	void SetAmbient(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	void SetAmbient(UGfloat ambient[4]);
	void SetDiffuse(UGfloat diffuse[4]);
	void SetSpecular(UGfloat specular[4]);
	void SetEmmissive(UGfloat emmissive[4]);
	UGfloat *GetAmbient();
	void SetDiffuse(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	UGfloat *GetDiffuse();
	void SetSpecular(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	UGfloat *GetSpecular();
	void SetEmmissive(UGfloat r, UGfloat g, UGfloat b, UGfloat alpha);
	UGfloat *GetEmmissive();
	void SetShininess(UGfloat value);
	UGfloat GetShininess();
	UGushort GetLodIndexSquaredDepth(UGReal squaredDistance) const;

protected:
	UGString m_strTexPath;
	UGString m_strName;				    /* name of material */
	UGfloat m_diffuse[4];			       /* diffuse component */
	UGfloat m_ambient[4];			       /* ambient component */
	UGfloat m_specular[4];		   	   /* specular component */
	UGfloat m_emmissive[4];			/* emmissive component */
	UGfloat m_fShininess;			/* specular exponent */  
} ;
}

#endif // !defined(AFX_UGMATERIAL_H__E85252C6_682E_4604_B276_C6EDA7B0F030__INCLUDED_)
