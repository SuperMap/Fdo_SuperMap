// UGMatrix3.h: interface for the UGMatrix3 class.


#if !defined(UG_MATRIX3_H)
#define UG_MATRIX3_H

#include <Scene/UGSceneHeaders.h>
#include <Scene/UGVector3.h>

namespace UGC
{
	class SCENE_API UGMatrix3  
	{
	private:
		///注意：m[row][column], 行在前，列在后
		Real m[3][3];
	
	public:
		static const Real      EPSILON;
		static const UGMatrix3 ZERO;
		static const UGMatrix3 IDENTITY;

	public:
		inline UGMatrix3 () 
		{
		}

		inline UGMatrix3 ( const Real arr[3][3] ) 
		{
			memcpy( m, arr, 9 * sizeof( Real ) );
		}

		inline UGMatrix3 ( const UGMatrix3& rkMatrix )
		{
			memcpy( m, rkMatrix.m, 9 * sizeof( Real ) );
		}

		inline UGMatrix3 ( Real _00, Real _01, Real _02,
			               Real _10, Real _11, Real _12,
					       Real _20, Real _21, Real _22 )
		{
			m[0][0] = _00;
			m[0][1] = _01;
			m[0][2] = _02;
			m[1][0] = _10;
			m[1][1] = _11;
			m[1][2] = _12;
			m[2][0] = _20;
			m[2][1] = _21;
			m[2][2] = _22;
		}
		
		inline Real* operator[] ( UGint iRow ) const
		{
			assert( iRow >=0 && iRow <=2 );

			return (Real*) m[iRow];
		}

		//类型转换-->转换成(Real*)
		inline operator Real* ()
		{
			return (Real*) m[0];
		}

		UGVector3 GetColumn ( UGint iCol ) const;
		void      SetColumn ( UGint iCol, const UGVector3& vec );
		void      FromAxes  ( const UGVector3& xAxis, 
			                  const UGVector3& yAxis, 
						      const UGVector3& zAxis );
		
		// assignment and comparison
		inline UGMatrix3& operator= ( const UGMatrix3& rkMatrix )
		{
			memcpy( m, rkMatrix.m, 9 * sizeof( Real ) );
			return *this;
		}
		
		UGbool operator == ( const UGMatrix3& rkMatrix ) const;
		inline UGbool operator!= ( const UGMatrix3& rkMatrix ) const
		{
			return !( operator==( rkMatrix ) );
		}
		
		// arithmetic operations
		UGMatrix3 operator+ ( const UGMatrix3& rkMatrix ) const;
		UGMatrix3 operator- ( const UGMatrix3& rkMatrix ) const;
		UGMatrix3 operator* ( const UGMatrix3& rkMatrix ) const;
		UGMatrix3 operator- () const;
		
		// matrix * vector [3x3 * 3x1 = 3x1]
		UGVector3 operator* ( const UGVector3& rkVector ) const;
		
		// vector * matrix [1x3 * 3x3 = 1x3]
		friend UGVector3 operator* ( const UGVector3& rkVector,
			                         const UGMatrix3& rkMatrix );
		
		// matrix * scalar
		UGMatrix3 operator* ( Real fScalar ) const;
		
		// scalar * matrix
		friend UGMatrix3 operator* ( Real fScalar, const UGMatrix3& rkMatrix );
		
		// utilities
		UGMatrix3 Transpose  () const;
		Real      Determinant() const;
		UGbool    Inverse    ( UGMatrix3& rkInverse, Real fTolerance = 1e-06 ) const;
		UGMatrix3 Inverse    ( Real fTolerance = 1e-06 ) const;
		
		
		// singular value decomposition
		void SingularValueDecomposition ( UGMatrix3& rkL, 
			                              UGVector3& rkS,
			                              UGMatrix3& rkR ) const;
		void SingularValueComposition   ( const UGMatrix3& rkL,
			                              const UGVector3& rkS, 
										  const UGMatrix3& rkR );
		
		// Gram-Schmidt orthonormalization (applied to columns of rotation matrix)
		void Orthonormalize ();
		
		// orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
		void QDUDecomposition ( UGMatrix3& rkQ, 
			                    UGVector3& rkD,
			                    UGVector3& rkU ) const;
		
		Real SpectralNorm () const;
		
		// matrix must be orthonormal
		void ToAxisAngle   ( UGVector3& rkAxis, Real& rfRadians ) const;
		void FromAxisAngle ( const UGVector3& rkAxis, Real fRadians );
		
		// The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
		// where yaw is rotation about the Up vector, pitch is rotation about the
		// Right axis, and roll is rotation about the Direction axis.
		UGbool   ToEulerAnglesXYZ ( float& rfYAngle, float& rfPAngle, float& rfRAngle ) const;
		UGbool   ToEulerAnglesXZY ( float& rfYAngle, float& rfPAngle, float& rfRAngle ) const;
		UGbool   ToEulerAnglesYXZ ( float& rfYAngle, float& rfPAngle, float& rfRAngle ) const;
		UGbool   ToEulerAnglesYZX ( float& rfYAngle, float& rfPAngle, float& rfRAngle ) const;
		UGbool   ToEulerAnglesZXY ( float& rfYAngle, float& rfPAngle, float& rfRAngle ) const;
		UGbool   ToEulerAnglesZYX ( float& rfYAngle, float& rfPAngle, float& rfRAngle ) const;
		void   FromEulerAnglesXYZ ( float fYAngle,   float fPAngle,   float fRAngle );
		void   FromEulerAnglesXZY ( float fYAngle,   float fPAngle,   float fRAngle );
		void   FromEulerAnglesYXZ ( float fYAngle,   float fPAngle,   float fRAngle );
		void   FromEulerAnglesYZX ( float fYAngle,   float fPAngle,   float fRAngle );
		void   FromEulerAnglesZXY ( float fYAngle,   float fPAngle,   float fRAngle );
		void   FromEulerAnglesZYX ( float fYAngle,   float fPAngle,   float fRAngle );
		
		// eigensolver, matrix must be symmetric
		void EigenSolveSymmetric ( Real afEigenvalue[3], UGVector3 akEigenvector[3] ) const;
		
		static void TensorProduct ( const UGVector3& rkU, 
			                        const UGVector3& rkV,
			                        UGMatrix3& rkProduct );
		
		protected:
			// support for eigensolver
			void Tridiagonal ( Real afDiag[3], Real afSubDiag[3] );
			UGbool QLAlgorithm ( Real afDiag[3], Real afSubDiag[3] );
			
			// support for singular value decomposition
			static const Real ms_fSvdEpsilon;
			static const UGint ms_iSvdMaxIterations;
			
			static void Bidiagonalize  ( UGMatrix3& kA, UGMatrix3& kL, UGMatrix3& kR );
			static void GolubKahanStep ( UGMatrix3& kA, UGMatrix3& kL, UGMatrix3& kR );
			
			// support for spectral norm
			static Real MaxCubicRoot (Real afCoeff[3]);
			
			friend class UGMatrix4;
		};
}

#endif

