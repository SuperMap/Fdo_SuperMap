// UGMath.h: interface for the UGMath class.


#if !defined(UGMATH_H)
#define UGMATH_H

#include <Scene/UGSceneHeaders.h>

namespace UGC
{		
	//注意：这里的前置声明必须放在namaspace UGC之中
	class UGSphere;
	class UGBoundBox;
	class UGPlane;
	class UGRay;

	#ifndef UG_PI
		#define UG_PI 3.14159265358979323846
	#endif

	#ifndef UG_TWO_PI
		#define UG_TWO_PI 6.2831853071795864769
	#endif

	#ifndef UG_HALF_PI
		#define UG_HALF_PI 1.5707963267948966
	#endif

	#ifndef UG_DEG_TO_RAD
		#define UG_DEG_TO_RAD 0.0174532925199432958
	#endif

	#ifndef UG_RAD_TO_DEG
		#define UG_RAD_TO_DEG 57.29577951308232
	#endif
	
	 /** 基础数学类－－改类封装了一些三维引擎中常用到的数学运算函数
        @remarks
             为了能对基本的数学函数做优化，单独实现一个基础数学类
             该类不开放给用户，仅在三维引擎内部使用，使用时只需要new一次
             而且也只能New一次，否则会有内存泄漏
             让m_pSinTable , m_pTanTable ,始终保持在内存中
             使用时可以直接CSmMath::Sin()调用也可以CSmMath::GetSingleton.Sin()调用
             速度快，但不够精确，单位: 弧度(Radian)
    */
	class SCENE_API UGMath  
	{
	public:
		/** trigTableSize Optional parameter to set the size of the tables 
		    used to implement Sin, Cos, Tan
		*/
		UGMath(UGuint trigTableSize = 4096);
		~UGMath();
		
	public:
		/// 三角函数
		static Real Sin( Real fRadian, UGbool bUseTable = false );
		static Real Cos( Real fRadian, UGbool bUseTable = false );
		static Real Tan( Real fRadian, UGbool bUseTable = false );

		/// 反三角函数
		static Real ACos( Real fValue );
		static Real ASin( Real fValue );
		static Real ATan( Real fValue );
		static Real ATan2( Real fY, Real fX ); 

		static Real Degree2Radian( Real fDegree );
		static Real Radian2Degree( Real fRadian );

		static Real Sqrt( Real fValue );
		static Real InvSqrt( Real fValue ); ///平方根倒数 即: 1 / Sqrt(x)

		static Real   Abs( Real fValue );
		static UGuint Log2( UGuint n );

		/// 返回距离basevalue最近的2^N + 1 的值
		static UGuint NextPOW2p1(UGuint basevalue);
		
		//判断射线和面，box, sphere相交的情况，并返回距离 
		static UGbool Intersects(const UGRay& ray, const UGPlane& plane,   Real& fDistance);
		static UGbool Intersects(const UGRay& ray, const UGBoundBox& box,  Real& fDistance);
		static UGbool Intersects(const UGRay& ray, const UGSphere& sphere, Real& fDistance);
		
		static UGbool Intersects(const UGSphere& sphere, const UGBoundBox& box);
		static UGbool Intersects(const UGSphere& sphere, const UGPlane& plane);
		static UGbool Intersects(const UGPlane& plane,   const UGBoundBox& box);
//		
//		static UGbool Intersect(const UGRay& ray,const CSmPlane& plane,Real& fDistance,CSmVector3& vIntersection);
//
		
	protected:
	    /// 创建三角函数表
        void BuildTrigTables();
	
	protected:
	    
		/// 三角函数表的大小 --在构造函数中根据外部传递进来的参数来确定
        static UGint m_nTrigTableSize;

        /// Radian -> index factor value ( mTrigTableSize / 2 * PI )
        static Real  m_fTrigTableFactor;
        static Real* m_pSinTable;
        static Real* m_pTanTable;

	private:
        /** 明确禁止拷贝构造 --参见Scott Meyers 『Effective C++』*/
		UGMath(const UGMath& rhs);

		/** 明确禁止该类对象的拷贝 --参见Scott Meyers 『Effective C++』*/
		UGMath& operator=(const UGMath& rhs);
		
	};
}

#endif // !defined(UGMATH_H)

