// UGBoundBox.h: interface for the UGBoundBox class.


#if !defined(UG_BOUNDBOX_H)
#define UG_BOUNDBOX_H

#include <Graphics3D/UGMatrix4.h>  //其中已经包含UGSceneHeaders.h、UGVector3.h
#include <Graphics3D/UGMath.h>

#include <iostream>
using namespace std; 

namespace UGC
{

	class UGSphere;  //前置声明
	class UGPlane;

    /** A 3D box aligned with the x/y/z axes.
	    @remarks
		    1.该类封装简单的三维体盒Box(其边框与三个坐标轴平行);
            2.其内部记录8个顶点，以及x,y,z坐标最小、最大的2个顶点； 
			3.其坐标表示，使用的是右手(right-handed)坐标系
			  顶点次序如下(按逆时针)：
                  y
                  | 
                  |
			      1-------2
			     /|      /|
			    / |     / |
			    5------4  |
			    |  0---|--3---x
			    | /    | /
			    |/     |/
			    6------7
               /
			  z 
            4.该类通常用于可见性判断(视景体剔除VFC)以及物体碰撞(Collision)
    */
	class GRAPHICS3D_API UGBoundBox  
	{
    protected:
	    UGVector3 m_vMin;         //x,y,z坐标最小的顶点
	    UGVector3 m_vMax;         //x,y,z坐标最大的顶点
		UGVector3 m_vCorners[8];  //8个顶点
	    UGbool m_bNull;

	 
	    void UpdateCorners( void )
	    {
			//顶点次序见上图
			
			//后一个面的4个顶点( z值相同 = m_vMin.z )
		    m_vCorners[0] = m_vMin;
		    m_vCorners[1].x = m_vMin.x; m_vCorners[1].y = m_vMax.y; m_vCorners[1].z = m_vMin.z;
		    m_vCorners[2].x = m_vMax.x; m_vCorners[2].y = m_vMax.y; m_vCorners[2].z = m_vMin.z;
		    m_vCorners[3].x = m_vMax.x; m_vCorners[3].y = m_vMin.y; m_vCorners[3].z = m_vMin.z;            

			//前一个面的4个顶点( z值相同 = m_vMax.z )
		    m_vCorners[4] = m_vMax;
		    m_vCorners[5].x = m_vMin.x; m_vCorners[5].y = m_vMax.y; m_vCorners[5].z = m_vMax.z;
		    m_vCorners[6].x = m_vMin.x; m_vCorners[6].y = m_vMin.y; m_vCorners[6].z = m_vMax.z;
		    m_vCorners[7].x = m_vMax.x; m_vCorners[7].y = m_vMin.y; m_vCorners[7].z = m_vMax.z;            
	    }        

    public:
	    inline UGBoundBox()
	    {
		    SetMinimum( -0.5, -0.5, -0.5 );
		    SetMaximum( 0.5, 0.5, 0.5 );
		    m_bNull = TRUE; // 缺省为空的Box
	    }

	    inline UGBoundBox( const UGVector3& Min, const UGVector3& Max )
	    {
		    SetExtents( Min, Max );
	    }

	    inline UGBoundBox(
		    Real mx, Real my, Real mz,
		    Real Mx, Real My, Real Mz )
	    {
		    SetExtents( mx, my, mz, Mx, My, Mz );
	    }

	    inline void SetNull()
	    {
		    m_bNull = TRUE;
	    }

	    UGbool IsNull(void) const
	    {
		    return m_bNull;
	    }

	    inline const UGVector3& GetMinimum( void ) const
	    { 
		    return m_vMin; 
	    }

		inline const UGVector3& GetMaximum( void ) const
	    { 
		    return m_vMax;
	    }

	    inline void SetMinimum( const UGVector3& vec )
	    {
		    m_bNull = FALSE;
		    m_vMin = vec;
		    UpdateCorners();
	    }

	    inline void SetMinimum( Real x, Real y, Real z )
	    {
		    m_bNull = FALSE;
		    m_vMin.x = x;
		    m_vMin.y = y;
		    m_vMin.z = z;
		    UpdateCorners();
	    }

		inline void SetMaximum( const UGVector3& vec )
	    {
		    m_bNull = FALSE;
		    m_vMax = vec;
		    UpdateCorners();
	    }

	    inline void SetMaximum( Real x, Real y, Real z )
	    {
		    m_bNull = FALSE;
		    m_vMax.x = x;
		    m_vMax.y = y;
		    m_vMax.z = z;
		    UpdateCorners();
	    }

	    inline void SetExtents( const UGVector3& Min, const UGVector3& Max )
	    {
		    m_bNull = FALSE;
		    m_vMin = Min;
		    m_vMax = Max;
		    UpdateCorners();
	    }

	    inline void SetExtents(
		    Real mx, Real my, Real mz,
		    Real Mx, Real My, Real Mz )
	    {
			assert( Mx > mx && My > my && Mz > mz );

		    m_bNull = FALSE;

		    m_vMin.x = mx;
		    m_vMin.y = my;
		    m_vMin.z = mz;

		    m_vMax.x = Mx;
		    m_vMax.y = My;
		    m_vMax.z = Mz;

		    UpdateCorners();
	    }

	    inline const UGVector3* GetAllCorners( void ) const
	    {
		    assert( m_bNull != FALSE );

		    return (const UGVector3*)m_vCorners;
	    }

	    friend std::ostream& operator<<( std::ostream& o, const UGBoundBox& bb )
	    {
		    if ( bb.IsNull() )
		    {
			    o << "UGBoundBox(null)";
		    }
		    else
		    {
			    o << "UGBoundBox(Min=" << bb.m_vMin << ", Max=" << bb.m_vMax;
			    o << ", corners=\n";
				for (UGint i = 0; i < 7; ++i)
				{
					o << bb.m_vCorners[i] << ", ";
				}
					
				o << bb.m_vCorners[7] << ")";
				
		    }
		    return o;
	    }

	    /** 将传递过来的rhs Box合并到该Box中
	    */
	    void Merge( const UGBoundBox& rhs )
	    {
		    if ( rhs.IsNull() )
		    {
			    return;
			}
		    else if ( this->IsNull() )
		    {
			    SetExtents( rhs.m_vMin, rhs.m_vMax );
		    }
		    else
		    {
			    UGVector3 Min = m_vMin;
			    UGVector3 Max = m_vMax;
			    Max.MakeCeil( rhs.m_vMax );
			    Min.MakeFloor( rhs.m_vMin );

			    SetExtents( Min, Max );
		    }
	    }

	    /** 根据矩阵matrix将该Box进行变换
		*/
	    void Transform( const UGMatrix4& matrix )
	    {
		    if( m_bNull ) return;

		    UGVector3 Min, Max, temp;
		    UGbool first = TRUE;
		    UGint i;
			
		    for( i = 0; i < 8; ++i )
		    {			    
				//依次变换8个顶点
			    temp = matrix * m_vCorners[i];

				cout << temp.x << endl;

				//变换顶点之后，检测出最大最小顶点
			    if( first || temp.x > Max.x )
				    Max.x = temp.x;
			    if( first || temp.y > Max.y )
				    Max.y = temp.y;
			    if( first || temp.z > Max.z )
				    Max.z = temp.z;
			    if( first || temp.x < Min.x )
				    Min.x = temp.x;
			    if( first || temp.y < Min.y )
				    Min.y = temp.y;
			    if( first || temp.z < Min.z )
				    Min.z = temp.z;

			    first = FALSE;
		    }

		    SetExtents( Min,Max );

	    }

        /** 检测2个Box是否相交 */
        inline UGbool Intersects( const UGBoundBox& b2 ) const
        {
            if ( this->IsNull() || b2.IsNull() )
			{
                return FALSE;
			}

            //根据6个面的位置进行检测 
            if ( m_vMax.x < b2.m_vMin.x )
                return FALSE;
            if ( m_vMax.y < b2.m_vMin.y )
                return FALSE;
            if ( m_vMax.z < b2.m_vMin.z )
                return FALSE;

            if ( m_vMin.x > b2.m_vMax.x )
                return FALSE;
            if ( m_vMin.y > b2.m_vMax.y )
                return FALSE;
            if ( m_vMin.z > b2.m_vMax.z )
                return FALSE;

            // 到这里，必定相交了
            return TRUE;

        }

        inline void Scale(const UGVector3& s)
        {
            // note: 以原点为中心进行缩放
            m_vMin = m_vMin * s;
            m_vMax = m_vMax * s;
        }

		inline void Scale( Real x_scale, Real y_scale, Real z_scale )
        {
            // note: 以原点为中心进行缩放
            m_vMin.x *= x_scale;
            m_vMin.y *= y_scale;
			m_vMin.z *= z_scale;

			m_vMax.x *= x_scale;
			m_vMax.y *= y_scale;
			m_vMax.z *= z_scale;
        }

		inline UGbool Intersects( const UGSphere& s ) const
		{
			return UGMath::Intersects(s, *this); 
		}
		
		inline UGbool Intersects( const UGPlane& p ) const
		{
			return UGMath::Intersects(p, *this);
		}

	};
}

#endif // !defined(UG_BOUNDBOX_H)

