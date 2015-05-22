// UGModel.h: interface for the UGModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMODEL_H__672B0943_8A21_4A5A_A866_1671BAAFEB30__INCLUDED_)
#define AFX_UGMODEL_H__672B0943_8A21_4A5A_A866_1671BAAFEB30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderOperation.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGMesh.h"
#include "Base/UGThread.h"

namespace UGC
{
class SCENE_API UGModel: public UGRenderObject
{
public:
	UGModel();
	UGModel(const UGString& strModelPath);
	virtual ~UGModel();
	void SetTexture(const UGString& strImgPath);
	virtual void SetNormalMode(UGint normalMode);
	virtual void SetFrontFace(UGint enFrontFace);
	virtual void Render();
	virtual void Initialize();
	virtual void Update();
	virtual UGbool ReadModel();
	virtual void GenRenderOperation();
	void  UnitizeBaseBottom();
	void  UnitizeBaseCenter();
	void ComputerVertexNormals();
	


	static UGModel* CreateModel(const UGString& strModelPath );
	static void ConvertToSGM(const UGString& strSrc,const UGString& strDest);

	virtual UGMatrix4d GetModelViewMatrix();
	virtual UGMatrix4d GetLocalViewMatrix();
	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	/* 这个函数可能会出问题，因为可能是"\\"定义路径的，所以直接用 UGFile的GetDir函数即可
	static UGString DirPathName(const UGString& strPath)
	{
		UGString dir;
		UGchar* s;
		dir = strPath;
		s=(UGchar*)strrchr(dir, '/');
		if(s)
			s[1] = '\0';
		else
			dir[0] = '\0';
		return dir;
	}
	*/
protected:
	virtual UGbool ReadModel(const UGString& strFileName);
	virtual void SetModelNormalMode(UGint normalMode);
	virtual void SetModelFrontFace(UGint enFrontFace);
	virtual void Scale(UGfloat fScale);
	virtual void ReleaseModel();
	virtual void Release();
	void SaveSGM(const UGString& strFilePath);
public:
	UGString m_strModelPath;
	UGMesh m_Mesh;
	UGMutex m_mutex;
	UGbool m_bLoaded;
	UGbool m_bOpGened;
	// 可能与BoudingBox重合
	UGVector3R m_vecMax;
	UGVector3R m_vecMin;

protected:
	// 添加保存模型模型视点矩阵矩阵
	UGMatrix4d m_ModelViewMatrix;
	UGMatrix4d m_matLocalView;
	

};
class SCENE_API  UGSgmModel : public UGModel
{
public:
	UGSgmModel();
	UGSgmModel(const UGString& strModelPath );
	virtual ~UGSgmModel();
	virtual void GenRenderOperation();
protected:
	virtual UGbool ReadModel(const UGString& strFilePath);
	virtual void Scale(UGfloat scale){};
};
}
#endif // !defined(AFX_UGMODEL_H__672B0943_8A21_4A5A_A866_1671BAAFEB30__INCLUDED_)
