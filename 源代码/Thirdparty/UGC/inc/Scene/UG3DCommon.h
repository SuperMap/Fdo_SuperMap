#ifndef UG3DCOMMON_H
#define UG3DCOMMON_H

namespace UGC
{
static UGString g_stStringBlank = "";

typedef UGfloat UGReal;
typedef UGuint RGBA;
typedef UGuint ARGB;
typedef UGuint ABGR;

//定义每个顶点对应的最多文理数
#define SMSCN_MAX_TEXTURE_COORD_SETS 6
#define MAX_TEXTURE_NUM              1000
#define FLOAT_EPSILON                1.401298e-45
#define VALUE_NAN                    UG_FLTMAX      // .net中是double.NaN,这里暂时以9999.0代替之,可能会有问题

#define MAX_LIGHTS                   8        // 定义光源最多个数

/** Light shading modes. */
enum ShadeOptions
{
    SO_FLAT,
    SO_GOURAUD,
    SO_PHONG
};
/** Defines the frame buffer types. */
enum FrameBufferType {
        FBT_COLOUR  = 0x1,
        FBT_DEPTH   = 0x2,
        FBT_STENCIL = 0x4
    };

/** The broad type of detail for rendering. */
// 绘制物体模式
// modified by luofx 07.12.5
//enum SceneDetailLevel
//{
//	/// Only points are rendered.
//	// 绘制点
//	SDL_POINTS = 1,
//	
//	/// Wireframe models are rendered.
//    // 绘制线框
//	SDL_WIREFRAME = 2,
//
//	/// Solid polygons are rendered.
//    // 绘制实心
//	SDL_SOLID = 3
//
//};

enum SceneNormalMode
{
	/// Only points are rendered.
	SNM_NONE = 1,
	/// Wireframe models are rendered.
    SNM_FLAT = 2,
	/// Solid polygons are rendered.
    SNM_SMOOTH = 3
};

enum UG3DPixelFormat
{
	 /// Unknown pixel format.
    PF_UNKNOWN = 0,
    /// 8-bit pixel format, all bits luminace.
    PF_L8 = 1,
	PF_BYTE_L = PF_L8,
    /// 16-bit pixel format, all bits luminace.
    PF_L16 = 2,
	PF_SHORT_L = PF_L16,
    /// 8-bit pixel format, all bits alpha.
    PF_A8 = 3,
	PF_BYTE_A = PF_A8,
    /// 8-bit pixel format, 4 bits alpha, 4 bits luminace.
    PF_A4L4 = 4,
	/// 2 byte pixel format, 1 byte luminance, 1 byte alpha
	PF_BYTE_LA = 5,
    /// 16-bit pixel format, 5 bits red, 6 bits green, 5 bits blue.
    PF_R5G6B5 = 6,
	/// 16-bit pixel format, 5 bits red, 6 bits green, 5 bits blue.
    PF_B5G6R5 = 7,
    /// 8-bit pixel format, 2 bits blue, 3 bits green, 3 bits red.
    PF_R3G3B2 = 31,
    /// 16-bit pixel format, 4 bits for alpha, red, green and blue.
    PF_A4R4G4B4 = 8,
    /// 16-bit pixel format, 5 bits for blue, green, red and 1 for alpha.
    PF_A1R5G5B5 = 9,
    /// 24-bit pixel format, 8 bits for red, green and blue.
    PF_R8G8B8 = 10,
    /// 24-bit pixel format, 8 bits for blue, green and red.
    PF_B8G8R8 = 11,
    /// 32-bit pixel format, 8 bits for alpha, red, green and blue.
    PF_A8R8G8B8 = 12,
    /// 32-bit pixel format, 8 bits for blue, green, red and alpha.
    PF_A8B8G8R8 = 13,
    /// 32-bit pixel format, 8 bits for blue, green, red and alpha.
    PF_B8G8R8A8 = 14,
	/// 32-bit pixel format, 8 bits for red, green, blue and alpha.
	PF_R8G8B8A8 = 28,
    /// 32-bit pixel format, 8 bits for red, 8 bits for green, 8 bits for blue
    /// like PF_A8R8G8B8, but alpha will get discarded
    PF_X8R8G8B8 = 26,
    /// 32-bit pixel format, 8 bits for blue, 8 bits for green, 8 bits for red
    /// like PF_A8B8G8R8, but alpha will get discarded
    PF_X8B8G8R8 = 27,
	/// 3 byte pixel format, 1 byte for red, 1 byte for green, 1 byte for blue
	PF_BYTE_RGB = PF_B8G8R8,
	/// 3 byte pixel format, 1 byte for blue, 1 byte for green, 1 byte for red
	PF_BYTE_BGR = PF_R8G8B8,
	/// 4 byte pixel format, 1 byte for blue, 1 byte for green, 1 byte for red and one byte for alpha
	PF_BYTE_BGRA = PF_A8R8G8B8,
	/// 4 byte pixel format, 1 byte for red, 1 byte for green, 1 byte for blue, and one byte for alpha
	PF_BYTE_RGBA = PF_A8B8G8R8,
    /// 32-bit pixel format, 2 bits for alpha, 10 bits for red, green and blue.
    PF_A2R10G10B10 = 15,
    /// 32-bit pixel format, 10 bits for blue, green and red, 2 bits for alpha.
    PF_A2B10G10R10 = 16,
    /// DDS (DirectDraw Surface) DXT1 format
    PF_DXT1 = 17,
    /// DDS (DirectDraw Surface) DXT2 format
    PF_DXT2 = 18,
    /// DDS (DirectDraw Surface) DXT3 format
    PF_DXT3 = 19,
    /// DDS (DirectDraw Surface) DXT4 format
    PF_DXT4 = 20,
    /// DDS (DirectDraw Surface) DXT5 format
    PF_DXT5 = 21,
	// 16-bit pixel format, 16 bits (float) for red
    PF_FLOAT16_R = 32,
    // 48-bit pixel format, 16 bits (float) for red, 16 bits (float) for green, 16 bits (float) for blue
    PF_FLOAT16_RGB = 22,
    // 64-bit pixel format, 16 bits (float) for red, 16 bits (float) for green, 16 bits (float) for blue, 16 bits (float) for alpha
    PF_FLOAT16_RGBA = 23,
	// 16-bit pixel format, 16 bits (float) for red
    PF_FLOAT32_R = 33,
   // 96-bit pixel format, 32 bits (float) for red, 32 bits (float) for green, 32 bits (float) for blue
    PF_FLOAT32_RGB = 24,
    // 128-bit pixel format, 32 bits (float) for red, 32 bits (float) for green, 32 bits (float) for blue, 32 bits (float) for alpha
    PF_FLOAT32_RGBA = 25,
	// Depth texture format
	PF_DEPTH = 29,
	// 64-bit pixel format, 16 bits for red, green, blue and alpha
	PF_SHORT_RGBA = 30,
	// Number of pixel formats currently defined
    PF_COUNT = 34,							
	/// 8-bit pixel format, 4 bits luminace, 4 bits alpha.
	PF_L4A4 = 35,
	/// 16-bit pixel format, 4 bits for blue, green, red and alpha.
	PF_B4G4R4A4 = 36,
	/// 24-bit pixel format, 8 bits for blue, green and red.
	PF_B8R8G8 = 37,
	/// 32-bit pixel format, 10 bits for blue, green and red, 2 bits for alpha.
	PF_B10G10R10A2 = 38
};
enum TextureType
{
	/// 1D texture, used in combination with 1D texture coordinates
	TEX_TYPE_1D = 1,
	/// 2D texture, used in combination with 2D texture coordinates (default)
	TEX_TYPE_2D = 2,
	/// 3D texture, used in combination with 3D texture coordinates
	TEX_TYPE_3D = 3,
	/// 3D cube map, used in combination with 3D texture coordinates
	TEX_TYPE_CUBE_MAP = 4,
};
enum FilterType
{
    /// The filter used when shrinking a texture
    FT_MIN,
    /// The filter used when magnifiying a texture
    FT_MAG,
    /// The filter used when determining the mipmap
    FT_MIP
};
/** Filtering options for textures / mipmaps. */
enum FilterOptions
{
    /// No filtering, used for FILT_MIP to turn off mipmapping
    FO_NONE,
    /// Use the closest pixel
    FO_POINT,
    /// Average of a 2x2 pixel area, denotes bilinear for MIN and MAG, trilinear for MIP
    FO_LINEAR,
    /// Similar to FO_LINEAR, but compensates for the angle of the texture plane
    FO_ANISOTROPIC
};
 /** Blending factors for manually blending objects with the scene. If there isn't a predefined
    SceneBlendType that you like, then you can specify the blending factors directly to affect the
    combination of object and the existing scene. See Material::setSceneBlending for more details.
*/
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
/** Comparison functions used for the depth/stencil buffer operations and 
	others. */
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
/** Hardware culling modes based on vertex winding.
    This setting applies to how the hardware API culls triangles it is sent. */
enum CullingMode
{
    /// Hardware never culls triangles and renders everything it receives.
    CULL_NONE = 1,
    /// Hardware culls triangles whose vertices are listed clockwise in the view (default).
    CULL_CLOCKWISE = 2,
    /// Hardware culls triangles whose vertices are listed anticlockwise in the view.
    CULL_ANTICLOCKWISE = 3
};
/** Fog modes. */
enum FogMode
{
    /// No fog. Duh.
    FOG_NONE,
    /// Fog density increases  exponentially from the camera (fog = 1/e^(distance * density))
    FOG_EXP,
    /// Fog density increases at the square of FOG_EXP, i.e. even quicker (fog = 1/e^(distance * density)^2)
    FOG_EXP2,
    /// Fog density increases linearly between the start and end distances
    FOG_LINEAR
};
/** The polygon mode to use when rasterising. */
enum PolygonMode
{
	/// Only points are rendered.
    PM_POINTS = 1,
	/// Wireframe models are rendered.
    PM_WIREFRAME = 2,
	/// Solid polygons are rendered.
    PM_SOLID = 3
};
/** Enumerates the wave types usable with the Ogre engine. */
enum WaveformType
{
    /// Standard sine wave which smoothly changes from low to high and back again.
    WFT_SINE,
    /// An angular wave with a constant increase / decrease speed with pointed peaks.
    WFT_TRIANGLE,
    /// Half of the time is spent at the min, half at the max with instant transition between.
    WFT_SQUARE,
    /// Gradual steady increase from min to max over the period with an instant return to min at the end.
    WFT_SAWTOOTH,
    /// Gradual steady decrease from max to min over the period, with an instant return to max at the end.
    WFT_INVERSE_SAWTOOTH,
	/// Pulse Width Modulation. Works like WFT_SQUARE, except the high to low transition is controlled by duty cycle. 
	/// With a duty cycle of 50% (0.5) will give the same output as WFT_SQUARE.
	WFT_PWM
};
/** The broad type of detail for rendering. */
enum PolygonFrontFace
{
	/// Only points are rendered.
	PFF_NONE = 1,
	/// Wireframe models are rendered.
    PFF_CW = 2,
	/// Solid polygons are rendered.
    PFF_CCW = 3
};

}

#endif