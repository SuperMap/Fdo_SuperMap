// UGLOD.h: interface for the UGLOD class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGLOD_H_)
#define UGLOD_H_

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGGroup.h"
#include "UGBoundSphere.h"
namespace UGC{

class UGNodeVisitor;

/** LOD - Level Of Detail group node which allows switching between children
depending on distance from eye point.Typical uses are for load balancing - objects further away from
the eye point are rendered at a lower level of detail, and at times
of high stress on the graphics pipeline lower levels of detail can
also be chosen.The children are ordered from most detailed (for close up views) to the least 
(see from a distance), and a set of ranges are used to decide which LOD is used 
at different view distances, the criteria used is child 'i' is used when 
range[i]<dist<range[i+1] is true. This requires there to be n+1 range values where the number of
children is n, since no maximum distance of infinity is assumed.  If the number of range values (m)
is insufficient then the children m through to n will be ignored, only 0..m-1 will be used
during rendering.
	*/
class GRAPHICS3D_API UGLOD  :public UGGroup
{
public:
	enum CenterMode
	{
		USE_BOUNDING_SPHERE_CENTER,
        USER_DEFINED_CENTER
	};
	enum RangeMode
	{
		DISTANCE_FROM_EYEPOINT,
        PIXEL_SIZE_SCREEN
	};
	struct MinMaxValue
	{
		UGfloat m_fMinValue;
		UGfloat m_fMaxValue;
	};
	typedef UGArray<MinMaxValue>RangeList;
public:
	UGLOD();
	virtual ~UGLOD();
	virtual void Traverse(UGNodeVisitor& nv){return ;}
	virtual UGbool AddChild(UGNode *child){return FALSE;}
	virtual UGbool AddChild(UGNode *child, UGfloat min, UGfloat max){return FALSE;}
	virtual UGbool RemoveChild(UGNode* pNode){return FALSE;}

	/** Set how the center of object should be determined when computed which child is active.*/
	void SetCenterMode(CenterMode mode) { m_enCenterMode=mode; }
	
	/** Get how the center of object should be m_enCenterMode when computed which child is active.*/
	CenterMode GetCenterMode() const { return m_enCenterMode; }
	
	inline void SetCenter(const UGVector3& center) { m_enCenterMode=USER_DEFINED_CENTER; m_vUserDefinedCenter = center; }
	
	inline const UGVector3& GetCenter() const 
	{ 
		if (m_enCenterMode==USER_DEFINED_CENTER) 
		{	
			return m_vUserDefinedCenter; 
		}
		else 
		{
			return GetBound().GetCenter(); 
		}
	}
	
	/** Set the object-space reference radius of the volume enclosed by the LOD. 
	* Used to detmine the bounding sphere of the LOD in the absense of any children.*/
	inline void SetRadius(UGfloat radius) { m_fRadius = radius; }
	
	/** Get the object-space radius of the volume enclosed by the LOD.*/
	inline UGfloat GetRadius() const { return m_fRadius; }

	/** Set how the range values should be intepreted when computing which child is active.*/
	void SetRangeMode(RangeMode mode) { m_enRangeMode = mode; }
	
	/** Get how the range values should be intepreted when computing which child is active.*/
	RangeMode GetRangeMode() const { return m_enRangeMode; }
	
	/** Sets the min and max visible ranges of range of specifiec child.
	Values are floating point distance specified in local objects coordinates.*/
	void SetRange(UGint childNo, UGfloat min,UGfloat max);
	
	/** returns the min visible range for specified child.*/
	inline float GetMinRange(UGint childNo) const { return m_RangeList[childNo].m_fMinValue; }
	
	/** returns the max visible range for specified child.*/
	inline float GetMaxRange(UGint childNo) const { return m_RangeList[childNo].m_fMaxValue; }
	
	/** returns the number of ranges currently set. 
	* An LOD which has been fully set up will have getNumChildren()==getNumRanges(). */
	inline unsigned int GetNumRanges() const { return m_RangeList.GetSize();}
	
	/** return the list of MinMax ranges for each child.*/
	inline const RangeList& getRangeList() const { return m_RangeList; }
	
protected:
	virtual UGbool ComputeBounds(){return FALSE;};	
	CenterMode  m_enCenterMode;
	RangeMode  m_enRangeMode;
	RangeList  m_RangeList;
	UGVector3 m_vUserDefinedCenter;
	UGfloat m_fRadius;
};
}

#endif // !defined(UGLOD_H_)
