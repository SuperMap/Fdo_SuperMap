// UGBillboard.h: interface for the UGBillboard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGBILLBOARD_H)
#define UGBILLBOARD_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGGeode.h"
namespace UGC{
class GRAPHICS3D_API UGBillboard :public UGGeode
{
public:
	enum Mode
	{
		POINT_ROT_EYE,  //始终对着眼坐标系中的某一点
        POINT_ROT_WORLD, //始终对着世界坐标系的某一点
        AXIAL_ROT //始终围绕着某一轴
	};
public:
	UGBillboard();
	virtual ~UGBillboard();
	void SetMode(Mode enMode);
	inline Mode GetMode()const{return m_enMode;}

	void SetAxis(const UGVector3& vecAxis);
	inline UGVector3& GetAxis(){return m_vAxis;}
	inline const UGVector3& GetAxis()const{return m_vAxis;}

	void SetNormal(const UGVector3& vecNormal);
	inline UGVector3& GetNormal();
	inline const UGVector3& GetNormal()const;

	void SetPosition(UGint nIndex,UGVector3& vPosition);
	inline UGVector3& GetPosition(UGint nIndex);
	inline const UGVector3& GetPosition(UGint nIndex)const;

	//!\brief Add the Drawable object and set its default position to (0,0,0)
	virtual UGbool AddDrawable(UGDrawable* pObject);
	//!\brief Add the Drawable object and set its position vPos
	virtual UGbool AddDrawable(UGDrawable* pObject, UGVector3& vPos);
	//!\brief Remove the drawable object and its corresponding position
	virtual UGbool RemoveDrawable(UGDrawable* pObject);

	UGbool ComputeMatrix(UGMatrix4& modelview, const UGVector3& eye_local, const UGVector3& pos_local) const;

protected:
	//!\brief define the mode of the billboard node type
	Mode m_enMode;
	//!\brief store the position of the orgin of the billboard
	UGVec3Array m_PositionArray; 
	//!\brief store the axis the billboard rotate around
	UGVector3 m_vAxis;
	//!\brief store the front face of the billboard.
	UGVector3 m_vNormal;
};
}

#endif // !defined(UGBILLBOARD_H)
