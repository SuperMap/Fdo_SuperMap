// UGQuaternion.h: interface for the UGQuaternion class.


#if !defined(UG_QUATERNION_H)
#define UG_QUATERNION_H

#include <Scene/UGSceneHeaders.h>

namespace UGC
{
	class UGVector3;
	class UGMatrix3;

	/** 实现一个四元组
	   @remarks
			以前采用的是Euler Angles的方法，分别针对三个轴，按顺序进行变换
			这样的后果是会出现Gimbal Lock(万象节)现象
			也就是分别按照三个轴进行顺序变换的后果是可能出现两个轴重合的情况
			更好的方法是采用Quaternion(四元组),对三个轴的变换同时进行

            在许多情况下用四元组代替旋转矩阵会有更多的好处，
			因为四元组需要的存储空间更少，四元组之间的连接运算需要的算术更少，
			在产生平滑的三维动画时，用四元组更容易进行修改。

			如下表示一个四元组
			q = [w,x,y,z] = w + x*i + y*j + z*k
			              = s + V
						  s 表示数量部分，对应于q的w分量，
						  V 表示向量部分，对应于q的x、y、z分量
	*/
	
	class SCENE_API UGQuaternion  
	{
	public:
		// 4 components
		Real w, x, y, z;

		// cutoff for sine near zero
		static Real ms_fEpsilon;
		
		// special values
		static UGQuaternion ZERO;
		static UGQuaternion IDENTITY;
		
	public:
		UGQuaternion ( Real fW = 1.0,
			           Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0 );
		UGQuaternion ( const UGQuaternion& rkQ );
		
		//变换矩阵和相应的Quaternion之间的转化
		void FromRotationMatrix ( const UGMatrix3& kRot );
		void ToRotationMatrix ( UGMatrix3& kRot ) const;
		
		void FromAngleAxis ( const Real& rfAngle, const UGVector3& rkAxis );
		void ToAngleAxis ( Real& rfAngle, UGVector3& rkAxis ) const;
		
		void FromAxes ( const UGVector3* akAxis );
		void FromAxes ( const UGVector3& xAxis, const UGVector3& yAxis, const UGVector3& zAxis );
		void ToAxes ( UGVector3& xAxis, UGVector3& yAxis, UGVector3& zAxis );
		void ToAxes ( UGVector3* akAxis ) const;
		
		UGQuaternion& operator= ( const UGQuaternion& rkQ );
		UGQuaternion  operator+ ( const UGQuaternion& rkQ ) const;
		UGQuaternion  operator- ( const UGQuaternion& rkQ ) const;
		UGQuaternion  operator* ( const UGQuaternion& rkQ ) const;
		UGQuaternion  operator* ( Real fScalar ) const;
		UGQuaternion  operator- () const;
		UGbool          operator== ( const UGQuaternion& rhs ) const;
		friend UGQuaternion operator* ( Real fScalar, const UGQuaternion& rkQ );
		
		Real Dot (const UGQuaternion& rkQ) const;  // dot product
		Real Norm () const;                        // squared-length
		UGQuaternion Inverse () const;             // apply to non-zero CQuaternion
		UGQuaternion UnitInverse () const;         // apply to unit-length CQuaternion
		UGQuaternion Exp () const;
		UGQuaternion Log () const;
		
		// 使用该CQuaternion
		UGVector3 operator* (const UGVector3& rkVector) const;
		
		// spherical linear interpolation  球形线性插值
		static UGQuaternion Slerp ( Real fT, const UGQuaternion& rkP, const UGQuaternion& rkQ );
		
		static UGQuaternion SlerpExtraSpins (Real fT,
			const UGQuaternion& rkP, const UGQuaternion& rkQ,
			int iExtraSpins);
		
		// setup for spherical quadratic interpolation
		static void Intermediate (const UGQuaternion& rkQ0,
			const UGQuaternion& rkQ1, const UGQuaternion& rkQ2,
			UGQuaternion& rka, UGQuaternion& rkB);
		
		// spherical quadratic interpolation
		static UGQuaternion Squad (Real fT, const UGQuaternion& rkP,
			const UGQuaternion& rkA, const UGQuaternion& rkB,
			const UGQuaternion& rkQ);
		

		
		/** Function for writing to a stream.
		*/
		inline friend std::ostream& operator <<
			( std::ostream& o, const UGQuaternion& q )
		{
			o << "UGQuaternion(" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << ")";
			return o;
		}		
	};
}


#endif // !defined(UG_QUATERNION_H)

