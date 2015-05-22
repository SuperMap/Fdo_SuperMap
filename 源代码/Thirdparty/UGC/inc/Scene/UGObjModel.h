// UGObjModel.h: interface for the UGObjModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGOBJMODEL_H__90EBCFF7_F805_4883_AF5B_E9F1225F64FE__INCLUDED_)
#define AFX_UGOBJMODEL_H__90EBCFF7_F805_4883_AF5B_E9F1225F64FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGModel.h"
namespace UGC
{

/* UGgroup: Structure that defines a group in a model.
 */
typedef struct _UGtriangle {
  UGuint vindices[3];			/* array of triangle vertex indices */
  UGuint nindices[3];			/* array of triangle normal indices */
  UGuint tindices[3];			/* array of triangle texcoord indices*/
  UGint nMaterialID;
} UGTriangle;



// 注意在这个模型中，ReadModel后，m_Mesh.m_RenderOperation.m_pVertex 实际存储的个数为
// m_Mesh.m_RenderOperation.m_nVertexCount+1
class SCENE_API UGObjModel:public  UGModel
{
public:
	UGObjModel();
	UGObjModel(const UGString& strModelPath );
	virtual ~UGObjModel();
	virtual void GenRenderOperation();

//void UGLinearTexture(UGmodel* model);
//void UGSpheremapTexture(UGmodel* model);
//void UGDelete(UGmodel* model);
//void UGWriteOBJ(UGmodel* model, const UGString& filename, UGuint mode);
//UGuint UGList(UGmodel* model);

protected:
	virtual UGbool ReadModel(const UGString& filename);

	//virtual void Unitize();
	virtual void Scale(UGfloat scale);
	UGuint FindMaterial(const UGString& strName);
	void FirstPass(FILE* file);
	void SecondPass(FILE* file); 
	void Dimensions(UGfloat* dimensions);
	void ReverseWinding();

private:
	void ReadMTL(const UGString& strName);
//virtual void Render(DrawArgs &drawArgs);
//virtual void Initialize(DrawArgs &drawArgs);
//virtual void Update(DrawArgs &drawArgs);
public:
	UGString m_strMtllibname;
	UGuint m_nNumTriangles;
	UGTriangle* m_pTriangles;
};
}
 
#endif // !defined(AFX_UGOBJMODEL_H__90EBCFF7_F805_4883_AF5B_E9F1225F64FE__INCLUDED_)
