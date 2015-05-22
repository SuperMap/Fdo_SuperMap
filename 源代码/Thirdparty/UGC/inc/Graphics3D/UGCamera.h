// UGCamera.h: interface for the UGCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGCAMERA_H)
#define UGCAMERA_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGVector3.h"
#include "UGQuaternion.h"
#include "UGFrustum.h"
#include "UGMatrix4.h"
#include "Base/UGString.h"

namespace UGC{

enum ProjectionType
{
	PT_ORTHOGRAPHIC,
	PT_PERSPECTIVE
};
class GRAPHICS3D_API UGCamera  
{
public:
	UGCamera();
	virtual ~UGCamera();

	const UGString& GetName(void);
	void  SetName(const UGString& strName);	
	//!\brief set or get the projection type
	void  SetProjectionType(ProjectionType enType);
	ProjectionType    GetProjectionType(void);
	
	//!\brief Set or get the position of the camera;
	void	 SetPosition(Real x, Real y, Real z);
	void	 SetPosition(const UGVector3& v);
	UGVector3 GetPosition(void);

	//!\brief Set or get the direction of the camera;
	void	SetDirection(Real x, Real y,Real z);
	void	SetDirection(const UGVector3& vec);
	UGVector3  GetDirection(void);
	
	void	SetOrientation(const UGQuaternion& quaternion);
	void	SetOrientation(Real x, Real y,Real z,Real w);
	UGQuaternion GetOrientation(void);

	//!\brief operations on the modelview matrix, and it will not affect the projection matrix
	void	Move(const UGVector3& vec);
	void    MoveRelative(const UGVector3& vec);
	void    Rotate(const UGVector3& vec, Real degrees);
	void    Rotate(const UGQuaternion& quaternion);	
	void	LookAt(Real x,Real y,Real z);
	void    LookAt(const UGVector3& vec);
	void	Roll(Real fDegrees);
	void	Yaw(Real fDegrees);
	void    Pitch(Real fDegrees);

	//!\brief operations on the frustum,and they will not affect the modelview matrix
	void    SetFoVy(Real fDegrees);
	Real    GetFoVy(void);
	void	SetNearClipDist(Real fNearDist);
	Real	GetNearClipDist(void);
	void    SetFarClipDist(Real fFarDist);
	Real	GetFarClipDist(void);
	void    SetAspectRatio(Real fAspect);
	Real	GetAspectRatio(void);
	
	//!\brief Get the projection matrix;
	const UGMatrix4&  GetProjMatrix(void)const;
	//!\brief Get the view matrix;
	const UGMatrix4&  GetViewMatrix(void)const;
	//!\brief Get the frustum;
	const UGFrustum& GetFrustum()const;

	//!\brief Just for the advanced users
	void SetProjectionMatrix(const UGMatrix4& projmatrix);
	//!\brief Just for the advanced users
	void SetViewMatrix(const UGMatrix4& viewmatrix);

	//!\brief еп╤о©ийспт
	UGbool IsVisible(const UGVector3& vPoint);
	UGbool IsVisible(const UGBoundBox& bBox);
	UGbool IsVisible(const UGBoundSphere& bs);

	UGFrustum* GetFrustum();

protected:
	
	void UpdateFrustum(void);
    void UpdateView(void);
	bool IsViewOutOfDate(void);
    bool IsFrustumOutOfDate(void)const;
	UGString m_strName;
	UGQuaternion m_qOrientation;
	UGVector3    m_vPosition;
	
	Real  m_fFovy;
	Real  m_fFarDist;
	Real  m_fNearDist;
	Real  m_fAspect;
	
	UGMatrix4   m_mProjMatrix;
	UGbool  m_bRecalFrustum;

	UGMatrix4   m_mViewMatrix;
	UGbool m_bRecalView;
	UGbool m_bYawFixed;
	UGVector3 m_vFixedYaw;

	UGFrustum m_Frustum;
	
};
}

#endif // !defined(UGCAMERA_H)
