#ifndef UGPREREQUISITES_H
#define UGPREREQUISITES_H

#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Base/UGList.h"
#include "Base/UGDict.h"
#include "Scene/UG3DCommon.h"

// disable: "conversion from 'double' to 'float', possible loss of data
#   pragma warning (disable : 4244)
// disable: "truncation from 'double' to 'float'
#   pragma warning (disable : 4305)

namespace UGC
{
// Pre-declare classes
// Allows use of pointers in header files without including individual .h
// so decreases dependencies between files
class UGMomentumCamera;
class UGCameraBase;
class UGViewport;
class UGMatrix4d;
class UGVector3R;
class UGQuaternion4d;
class UGMaterial;
class UGTexture;
class UGTerrainAccessor;
class UGTextureUnitState;
class UGRenderSystemCapabilities;
class UGPlane;
class UGColorValue;
class UGFrustum;
class UGBoundingBox;
class UGRenderable;
class UGRenderSys;
class UGTextureManager;
class UGTextureData;
class UGQuadTile;
class UGQuadTileSet;
class UGQuadGrid;
class UGQuadGridSet;
class UGRenderOperation;
class UGAngle;
class UGTerrainTile;
class UGTerrainTileServer;
class UGScene;
class UGQuadTileArgs;
class UGLayerBlendModeEx;
class UGVector4R;
class UGRenderTarget;
class UGColorValue;
class UGRoot;
class UGTerrainAccessor;
class UGTerrainManager;
class UGTerrainTileCacheEntry;
class UGImgServer;
class UGQuadDataset;
class UG3DLineStyle;
class UGMovableObject;
class UGNode;
class UGSceneNode;
class UGEntity;
class UGSubEntity;
class UGMesh;
class UGSubMesh;
class UGEntityMesh;
class UGVertexData;
class UGIndexData;

}

#endif