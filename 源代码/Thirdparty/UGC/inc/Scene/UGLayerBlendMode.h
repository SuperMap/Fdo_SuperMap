// UGLayerBlendMode.h: interface for the UGLayerBlendModeEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGLAYERBLENDMODEEX_H__AC04A498_8917_4DB5_8456_E78C99E86851__INCLUDED_)
#define AFX_UGLAYERBLENDMODEEX_H__AC04A498_8917_4DB5_8456_E78C99E86851__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGColorValue.h"

namespace UGC 
{
/** Type of texture blend mode.
    */
enum LayerBlendType
{
    LBT_COLOUR,
    LBT_ALPHA
};
/** Expert list of valid texture blending operations, for use with TextureUnitState::setColourOperationEx
        and TextureUnitState::setAlphaOperation, and internally in the LayerBlendModeEx class. It's worth
        noting that these operations are for blending <i>between texture layers</i> and not between rendered objects
        and the existing scene. Because all of these modes are only supported in multitexture hardware it may be
        required to set up a fallback operation where this hardware is not available.
    */
enum LayerBlendOperationEx {
    /// use source1 without modification
    LBX_SOURCE1,
    /// use source2 without modification
    LBX_SOURCE2,
    /// multiply source1 and source2 together
    LBX_MODULATE,
    /// as LBX_MODULATE but brighten afterwards (x2)
    LBX_MODULATE_X2,
    /// as LBX_MODULATE but brighten more afterwards (x4)
    LBX_MODULATE_X4,
    /// add source1 and source2 together
    LBX_ADD,
    /// as LBX_ADD, but subtract 0.5 from the result
    LBX_ADD_SIGNED,
    /// as LBX_ADD, but subtract product from the sum
    LBX_ADD_SMOOTH,
    /// subtract source2 from source1
    LBX_SUBTRACT,
    /// use interpolated alpha value from vertices to scale source1, then add source2 scaled by (1-alpha)
    LBX_BLEND_DIFFUSE_ALPHA,
    /// as LBX_BLEND_DIFFUSE_ALPHA, but use alpha from texture
    LBX_BLEND_TEXTURE_ALPHA,
    /// as LBX_BLEND_DIFFUSE_ALPHA, but use current alpha from previous stages
    LBX_BLEND_CURRENT_ALPHA,
    /// as LBX_BLEND_DIFFUSE_ALPHA but use a constant manual blend value (0.0-1.0)
    LBX_BLEND_MANUAL,
    /// dotproduct of color1 and color2 
    LBX_DOTPRODUCT,
    /// use interpolated color values from vertices to scale source1, then add source2 scaled by (1-color)
    LBX_BLEND_DIFFUSE_COLOUR
};
 /** List of valid sources of values for blending operations used
        in TextureUnitState::setColourOperation and TextureUnitState::setAlphaOperation,
        and internally in the LayerBlendModeEx class.
    */
enum LayerBlendSource
{
    /// the colour as built up from previous stages
    LBS_CURRENT,
    /// the colour derived from the texture assigned to this layer
    LBS_TEXTURE,
    /// the interpolated diffuse colour from the vertices
    LBS_DIFFUSE,
    /// the interpolated specular colour from the vertices
    LBS_SPECULAR,
    /// a colour supplied manually as a separate argument
    LBS_MANUAL
};
class SCENE_API UGLayerBlendModeEx  
{
public:
    /// The type of blending (colour or alpha)
    LayerBlendType blendType;
    /// The operation to be applied
    LayerBlendOperationEx operation;
    /// The first source of colour/alpha
    LayerBlendSource source1;
    /// The second source of colour/alpha
    LayerBlendSource source2;

    /// Manual colour value for manual source1
    UGColorValue colourArg1;
    /// Manual colour value for manual source2
    UGColorValue colourArg2;
    /// Manual alpha value for manual source1
    UGReal alphaArg1;
    /// Manual alpha value for manual source2
    UGReal alphaArg2;
    /// Manual blending factor
    UGReal factor;

    UGbool operator==(const UGLayerBlendModeEx& rhs) const
    {
        if (blendType != rhs.blendType) return false;

        if (blendType == LBT_COLOUR)
        {

            if (operation == rhs.operation &&
                source1 == rhs.source1 &&
                source2 == rhs.source2 &&
                colourArg1 == rhs.colourArg1 &&
                colourArg2 == rhs.colourArg2 &&
                factor == rhs.factor)
            {
                return true;
            }
        }
        else // if (blendType == LBT_ALPHA)
        {
            if (operation == rhs.operation &&
                source1 == rhs.source1 &&
                source2 == rhs.source2 &&
                alphaArg1 == rhs.alphaArg1 &&
                alphaArg2 == rhs.alphaArg2 &&
                factor == rhs.factor)
            {
                return true;
            }
        }
        return false;
    }

    bool operator!=(const UGLayerBlendModeEx& rhs) const
    {
        return !(*this == rhs);
    }

};
}
#endif // !defined(AFX_UGLAYERBLENDMODEEX_H__AC04A498_8917_4DB5_8456_E78C99E86851__INCLUDED_)
