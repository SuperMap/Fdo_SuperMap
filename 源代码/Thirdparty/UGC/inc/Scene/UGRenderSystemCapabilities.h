// UGRenderSystemCapabilities.h: interface for the UGRenderSystemCapabilities class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRENDERSYSTEMCAPABILITIES_H__26CEEA28_FC88_48C7_A0A0_9413991E9B5F__INCLUDED_)
#define AFX_UGRENDERSYSTEMCAPABILITIES_H__26CEEA28_FC88_48C7_A0A0_9413991E9B5F__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC 
{
	
/// Enum describing the different hardware capabilities we want to check for
enum Capabilities
{
    //RSC_MULTITEXTURE          = 0x00000001,
    /// Supporta generating mipmaps in hardware
    RSC_AUTOMIPMAP              = 0x00000002,
    RSC_BLENDING                = 0x00000004,
    /// Supports anisotropic texture filtering
    RSC_ANISOTROPY              = 0x00000008,
    /// Supports fixed-function DOT3 texture blend
    RSC_DOT3                    = 0x00000010,
    /// Supports cube mapping
    RSC_CUBEMAPPING             = 0x00000020,
    /// Supports hardware stencil buffer
    RSC_HWSTENCIL               = 0x00000040,
    /// Supports hardware vertex and index buffers
    RSC_VBO                     = 0x00000080,
    /// Supports vertex programs (vertex shaders)
	RSC_VERTEX_PROGRAM          = 0x00000200,
    /// Supports fragment programs (pixel shaders)
	RSC_FRAGMENT_PROGRAM        = 0x00000400,
    /// Supports compressed textures
	RSC_TEXTURE_COMPRESSION     = 0x00000800,
    /// Supports compressed textures in the DXT/ST3C formats
	RSC_TEXTURE_COMPRESSION_DXT = 0x00001000,
    /// Supports compressed textures in the VTC format
	RSC_TEXTURE_COMPRESSION_VTC = 0x00002000,
    /// Supports performing a scissor test to exclude areas of the screen
    RSC_SCISSOR_TEST            = 0x00004000,
    /// Supports separate stencil updates for both front and back faces
    RSC_TWO_SIDED_STENCIL       = 0x00008000,
    /// Supports wrapping the stencil value at the range extremeties
    RSC_STENCIL_WRAP            = 0x00010000,
    /// Supports hardware occlusion queries
    RSC_HWOCCLUSION				= 0x00020000,
    /// Supports user clipping planes
    RSC_USER_CLIP_PLANES		= 0x00040000,
	/// Supports the VET_UBYTE4 vertex element type
	RSC_VERTEX_FORMAT_UBYTE4	= 0x00080000,
	/// Supports infinite far plane projection
	RSC_INFINITE_FAR_PLANE      = 0x00100000,
    /// Supports hardware render-to-texture (bigger than framebuffer)
    RSC_HWRENDER_TO_TEXTURE     = 0x00200000,
    /// Supports float textures and render targets
    RSC_TEXTURE_FLOAT           = 0x00400000,
    /// Supports non-power of two textures
    RSC_NON_POWER_OF_2_TEXTURES = 0x00800000,
	/// Supports 3d (volume) textures
	RSC_TEXTURE_3D				= 0x01000000,
	/// Supports basic point sprite rendering
	RSC_POINT_SPRITES		    = 0x02000000,
	/// Supports extra point parameters (minsize, maxsize, attenuation)
	RSC_POINT_EXTENDED_PARAMETERS = 0x04000000
};
class SCENE_API UGRenderSystemCapabilities  
{
public:
	UGRenderSystemCapabilities();
	virtual ~UGRenderSystemCapabilities();
	
	UGushort GetNumTextureUnits();
	UGReal GetMaxPointSize(void) const;
	/** Checks for a capability
    */
    UGbool HasCapability(const Capabilities c) const;
	void SetMaxPointSize(UGReal s);
	void SetNumTextureUnits(UGushort num);
private:
	UGushort m_unNumTextureUnits;
	UGReal m_MaxPointSize;
	int m_nCapabilities;
};
}
#endif // !defined(AFX_UGRENDERSYSTEMCAPABILITIES_H__26CEEA28_FC88_48C7_A0A0_9413991E9B5F__INCLUDED_)
