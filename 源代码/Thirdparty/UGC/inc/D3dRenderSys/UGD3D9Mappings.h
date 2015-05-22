/* 
	\file UGD3D9Mappings.h
	\brief D3D对照类。
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


#if !defined(AFX_UGD3D9MAPPINGS_H__CC36DB88_243A_4E39_8171_528B1FA9858D__INCLUDED_)
#define AFX_UGD3D9MAPPINGS_H__CC36DB88_243A_4E39_8171_528B1FA9858D__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGTextureUnitState.h"
#include "Scene/UGLight.h"
#include "Scene/UGRenderSys.h"
#include "Scene/UGHardwareVertexBuffer.h"

namespace UGC
{


//! \brief D3D对照类。
class D3DRENDERSYS_API UGD3D9Mappings  
{


public:

	//! \brief D3D纹理类型。	
	enum eD3DTexType
	{
		/// standard texture
		D3D_TEX_TYPE_NORMAL,
		/// cube texture
		D3D_TEX_TYPE_CUBE,
		/// volume texture
		D3D_TEX_TYPE_VOLUME,
		/// just to have it...
		D3D_TEX_TYPE_NONE
	};

	
	//! \brief 纹理映射类型。
	enum eD3DFilterUsage
	{
		/// min filter
		D3D_FUSAGE_MIN,
		/// mag filter
		D3D_FUSAGE_MAG,
		/// mip filter
		D3D_FUSAGE_MIP
	};

	//! \brief return a D3D9 equivalent for a Ogre ShadeOptions value
	static DWORD Get(ShadeOptions so);


	//! \brief return a D3D9 equivalent for a Ogre LightTypes value
	static D3DLIGHTTYPE Get(UGC::UGLight::LightTypes lightType);

	//! \brief return a D3D9 equivalent for a Ogre TexCoordCalsMethod value
	static DWORD Get(TexCoordCalcMethod m, const D3DCAPS9& caps);
	//! \brief return a D3D9 equivalent for a Ogre TextureAddressingMode value
	static D3DTEXTUREADDRESS Get(UGTextureUnitState::TextureAddressingMode tam);
	//! \brief return a D3D9 equivalent for a Ogre LayerBlendType value
	static D3DTEXTURESTAGESTATETYPE Get(LayerBlendType lbt);
	//! \brief return a D3D9 equivalent for a Ogre LayerBlendOperationEx value
	static DWORD Get(LayerBlendOperationEx lbo, const D3DCAPS9& devCaps);
	//! \brief return a D3D9 equivalent for a Ogre LayerBlendSource value
	static DWORD Get(LayerBlendSource lbs, UGbool perStageConstants);
	//! \brief return a D3D9 equivalent for a Ogre SceneBlendFactor value
	static D3DBLEND Get(SceneBlendFactor sbf);
	//! \brief return a D3D9 equivalent for a Ogre CompareFunction value
	static DWORD Get(CompareFunction cf);
	//! \brief return a D3D9 equivalent for a Ogre CillingMode value
	static DWORD Get(CullingMode cm, UGbool flip);
	//! \brief return a D3D9 equivalent for a Ogre FogMode value
	static D3DFOGMODE Get(FogMode fm);
	//! \brief return a D3D9 equivalent for a Ogre PolygonMode value
	static D3DFILLMODE Get(PolygonMode level);
	//! \brief return a D3D9 equivalent for a Ogre StencilOperation value
	static DWORD Get(StencilOperation op, UGbool invert = false);
	//! \brief return a D3D9 state type for Ogre FilterType value
	static D3DSAMPLERSTATETYPE Get(FilterType ft);
	//! \brief return a D3D9 filter option for Ogre FilterType & FilterOption value
	static DWORD Get(FilterType ft, FilterOptions fo, const D3DCAPS9& devCaps, eD3DTexType texType);
	//! \brief return the D3DtexType equivalent of a Ogre tex. type
	static eD3DTexType Get(TextureType ogreTexType);
    /// return the combination of D3DUSAGE values for Ogre buffer usage
    //static DWORD get(HardwareBuffer::Usage usage);
    /// Get lock options
    //static DWORD get(HardwareBuffer::LockOptions options, HardwareBuffer::Usage usage);
    /// Get index type
    //static D3DFORMAT get(HardwareIndexBuffer::IndexType itype);
	//! \brief Get vertex data type
	static D3DDECLTYPE Get(VertexElementType vType);
	//! \brief Get vertex semantic
	static D3DDECLUSAGE Get(VertexElementSemantic sem);
    //! \brief Convert matrix to D3D style
    static 	D3DXMATRIX MakeD3DXMatrix( const UGMatrix4d& mat );
    //! \brief Convert matrix from D3D style
    static UGMatrix4d ConvertD3DXMatrix( const D3DXMATRIX& mat );

	//! \brief utility method, convert D3D9 pixel format to Ogre pixel format
	static UG3DPixelFormat GetPF(D3DFORMAT d3dPF);
	//! \brief utility method, convert Ogre pixel format to D3D9 pixel format
	static D3DFORMAT GetPF(UG3DPixelFormat ogrePF);
	//! \brief utility method, find closest Ogre pixel format that D3D9 can support
	static UG3DPixelFormat GetClosestSupportedPF(UG3DPixelFormat ogrePF);
};
}
#endif // !defined(AFX_UGD3D9MAPPINGS_H__CC36DB88_243A_4E39_8171_528B1FA9858D__INCLUDED_)
