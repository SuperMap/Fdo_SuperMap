// UGMaterial.h: interface for the UGMaterial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGMATERIAL_H)
#define UGMATERIAL_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGString.h"
#include "UGColorValue.h"
#include "UGTextureUnitState.h"
namespace UGC{
class UGTextureUnitState;
class UGDatasetRaster;
#define SMSCN_MAX_TEXTURE_LAYERS 8
enum CompareFunction
{
	CMPF_ALWAYS_FAIL,
	CMPF_ALWAYS_PASS,
	CMPF_LESS,
	CMPF_LESS_EQUAL,
	CMPF_EQUAL,
	CMPF_NOT_EQUAL,
	CMPF_GREATER_EQUAL,
	CMPF_GREATER
};
enum SceneBlendType
{
	/// Make the object transparent based on the final alpha values in the texture
	SBT_TRANSPARENT_ALPHA,
    /// Make the object transparent based on the colour values in the texture (brighter = more opaque)
    SBT_TRANSPARENT_COLOUR,
    /// Add the texture values to the existing scene content
    SBT_ADD
    // TODO : more
};
enum SceneBlendFactor
{
	SBF_ONE,
    SBF_ZERO,
    SBF_DEST_COLOUR,
    SBF_SOURCE_COLOUR,
    SBF_ONE_MINUS_DEST_COLOUR,
    SBF_ONE_MINUS_SOURCE_COLOUR,
    SBF_DEST_ALPHA,
    SBF_SOURCE_ALPHA,
    SBF_ONE_MINUS_DEST_ALPHA,
    SBF_ONE_MINUS_SOURCE_ALPHA		
};
enum CullingMode
{
	/// Hardware never culls triangles and renders everything it receives.
	CULL_NONE = 1,
    /// Hardware culls triangles whose vertices are listed clockwise in the view (default).
    CULL_CLOCKWISE = 2,
    /// Hardware culls triangles whose vertices are listed anticlockwise in the view.
    CULL_ANTICLOCKWISE = 3
};
//TODO: Multipass-rendering and the vertex program & fragement program
class GRAPHICS3D_API UGMaterial
{
public:
	enum RenderingHint
	{
		DEFAULT_BIN = 0,
        OPAQUE_BIN = 1,
        TRANSPARENT_BIN = 2
	};
public:
	UGMaterial();
	virtual ~UGMaterial();

	//!设置所在的RenderBin number;
	void SetRenderingHint(UGint nNum);
	UGint GetRenderingHint();

	void SetAmbient(Real red, Real green, Real blue);
	void SetAmbient(const UGColorValue& ambient);
	const UGColorValue& GetAmbient(void) const;
	
	void SetDiffuse(Real red, Real green, Real blue);
	void SetDiffuse(const UGColorValue& diffuse);
	const UGColorValue& GetDiffuse(void) const;
	
	
	void SetSpecular(Real red, Real green, Real blue);
	void SetSpecular(const UGColorValue& specular);
	const UGColorValue& GetSpecular(void) const;
	
	void SetShininess(Real val);
	Real GetShininess(void) const;
	
	void SetSelfIllumination(Real red, Real green, Real blue);
	void SetSelfIllumination(const UGColorValue& selfIllum);
	const UGColorValue& GetSelfIllumination(void) const;

	void AddTextureUnit(UGTextureUnitState* pUnit);
	UGTextureUnitState* AddTextureUnit(const UGString& strTextureName, int nTexCoordSet = 0);
	UGTextureUnitState* AddTextureUnit(UGDatasetRaster* pDataset,int nTexCoodSet = 0);	
	UGTextureUnitState* GetTextureUnit(int nIndex) const;
	void RemoveTextureUnit();
	void RemoveAllTextureUnit(void);
	int GetNumTextureUnits(void) const;
	
	void SetDepthCheckEnabled(UGbool enabled);
	bool GetDepthCheckEnabled(void) const;
	void SetDepthWriteEnabled(UGbool enabled);
	bool GetDepthWriteEnabled(void) const;	
	void SetDepthFunction( CompareFunction func );
	CompareFunction GetDepthFunction(void) const;
	void SetDepthBias(unsigned short bias);
	UGshort GetDepthBias(void) const;
	
	void SetSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor);
	void SetSceneBlending(SceneBlendType sbt);
	SceneBlendFactor GetSrcBlendFactor();
	SceneBlendFactor GetDestBlendFactor();
	
	
	CullingMode GetCullingMode(void) const;
	void SetCullingMode(CullingMode nCullingMode);
	
	//!\brief 判断俩个Material的大小,排序用
	UGint Compare(const UGMaterial& material)const;

	//!\brief 设置 ColorMaterial属性,special for the OpenGL rendering system
	UGbool IsColorMaterialEnabled();
	void SetColorMaterial(UGbool bEnable);


protected:
	UGString m_strName;
	UGColorValue  m_Ambient;
	UGColorValue  m_Diffuse;
	UGColorValue  m_Specular;    
	UGColorValue  m_Emissive;
	Real  m_Shininess;	
	UGbool  m_bColorMaterial;
	UGbool m_bDepthCheck;		
	UGbool m_bDepthWrite;
	CompareFunction m_DepthFunc;
	UGshort m_nDepthBias;
	SceneBlendFactor m_SourceBlendFactor;    
	SceneBlendFactor m_DestBlendFactor;
	CullingMode m_CullMode;	
	int m_nNumTextureLayers;
	UGTextureUnitState m_TextureLayers[SMSCN_MAX_TEXTURE_LAYERS];

	UGint m_nRenderHint;

};
//!\brief Define one default global material
extern UGMaterial m_gDefaultMaterial;
}
#endif // !defined(UGMATERIAL_H)
