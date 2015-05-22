// UGMatrix3R.h: interface for the UGMatrix3R class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATRIX3R_H__87211562_9080_4FF0_99EB_741D322A0BB3__INCLUDED_)
#define AFX_UGMATRIX3R_H__87211562_9080_4FF0_99EB_741D322A0BB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{

class SCENE_API UGMatrix3R  
{
public:
/** Default constructor.
@note
It does <b>NOT</b> initialize the matrix for efficiency.
	*/
	inline UGMatrix3R () {};
	inline UGMatrix3R (const UGReal arr[3][3]) 
	{
		memcpy(m,arr,9*sizeof(UGReal));
	}
	inline UGMatrix3R (const UGMatrix3R& rkMatrix)
	{
		memcpy(m,rkMatrix.m,9*sizeof(UGReal));
	}
	UGMatrix3R (UGReal fEntry00, UGReal fEntry01, UGReal fEntry02,
		UGReal fEntry10, UGReal fEntry11, UGReal fEntry12,
		UGReal fEntry20, UGReal fEntry21, UGReal fEntry22)
	{
		m[0][0] = fEntry00;
		m[0][1] = fEntry01;
		m[0][2] = fEntry02;
		m[1][0] = fEntry10;
		m[1][1] = fEntry11;
		m[1][2] = fEntry12;
		m[2][0] = fEntry20;
		m[2][1] = fEntry21;
		m[2][2] = fEntry22;
	}
	
	// member access, allows use of construct mat[r][c]
	inline UGReal* operator[] (UGint iRow) const
	{
		return (UGReal*)m[iRow];
	}
	inline operator UGReal* ()
	{
		return (UGReal*)m[0];
	}
	UGVector3R GetColumn (UGint iCol) const;
	void SetColumn(UGint iCol, const UGVector3R& vec);
	void FromAxes(const UGVector3R& xAxis, const UGVector3R& yAxis, const UGVector3R& zAxis);
	
	// assignment and comparison
	inline UGMatrix3R& operator= (const UGMatrix3R& rkMatrix)
	{
		memcpy(m,rkMatrix.m,9*sizeof(UGReal));
		return *this;
	}
	UGbool operator== (const UGMatrix3R& rkMatrix) const;
	inline UGbool operator!= (const UGMatrix3R& rkMatrix) const
	{
		return !operator==(rkMatrix);
	}
	
	// arithmetic operations
	UGMatrix3R operator+ (const UGMatrix3R& rkMatrix) const;
	UGMatrix3R operator- (const UGMatrix3R& rkMatrix) const;
	UGMatrix3R operator* (const UGMatrix3R& rkMatrix) const;
	UGMatrix3R operator- () const;
	
	// matrix * vector [3x3 * 3x1 = 3x1]
	UGVector3R operator* (const UGVector3R& rkVector) const;
	
	// vector * matrix [1x3 * 3x3 = 1x3]
	friend UGVector3R operator* (const UGVector3R& rkVector,
		const UGMatrix3R& rkMatrix);
	
	// matrix * scalar
	UGMatrix3R operator* (UGReal fScalar) const;
	
	// scalar * matrix
	friend UGMatrix3R operator* (UGReal fScalar, const UGMatrix3R& rkMatrix);
	
	// utilities
	UGMatrix3R Transpose () const;
	UGbool Inverse (UGMatrix3R& rkInverse, UGReal fTolerance = 1e-06) const;
	UGMatrix3R Inverse (UGReal fTolerance = 1e-06) const;
	UGReal Determinant () const;
	
	// singular value decomposition
	void SingularValueDecomposition (UGMatrix3R& rkL, UGVector3R& rkS,
		UGMatrix3R& rkR) const;
	void SingularValueComposition (const UGMatrix3R& rkL,
		const UGVector3R& rkS, const UGMatrix3R& rkR);
	
	// Gram-Schmidt orthonormalization (applied to columns of rotation matrix)
	void Orthonormalize ();
	
	// orthogonal Q, diagonal D, upper triangular U stored as (u01,u02,u12)
	void QDUDecomposition (UGMatrix3R& rkQ, UGVector3R& rkD,
		UGVector3R& rkU) const;
	
	UGReal SpectralNorm () const;
	
	// matrix must be orthonormal
	void ToAxisAngle (UGVector3R& rkAxis, UGReal& rfRadians) const;
	void FromAxisAngle (const UGVector3R& rkAxis, UGReal fRadians);
	
	// The matrix must be orthonormal.  The decomposition is yaw*pitch*roll
	// where yaw is rotation about the Up vector, pitch is rotation about the
	// Right axis, and roll is rotation about the Direction axis.
	UGbool ToEulerAnglesXYZ (UGReal& rfYAngle, UGReal& rfPAngle,
		UGReal& rfRAngle) const;
	UGbool ToEulerAnglesXZY (UGReal& rfYAngle, UGReal& rfPAngle,
		UGReal& rfRAngle) const;
	UGbool ToEulerAnglesYXZ (UGReal& rfYAngle, UGReal& rfPAngle,
		UGReal& rfRAngle) const;
	UGbool ToEulerAnglesYZX (UGReal& rfYAngle, UGReal& rfPAngle,
		UGReal& rfRAngle) const;
	UGbool ToEulerAnglesZXY (UGReal& rfYAngle, UGReal& rfPAngle,
		UGReal& rfRAngle) const;
	UGbool ToEulerAnglesZYX (UGReal& rfYAngle, UGReal& rfPAngle,
		UGReal& rfRAngle) const;
	void FromEulerAnglesXYZ (UGReal fYAngle, UGReal fPAngle, UGReal fRAngle);
	void FromEulerAnglesXZY (UGReal fYAngle, UGReal fPAngle, UGReal fRAngle);
	void FromEulerAnglesYXZ (UGReal fYAngle, UGReal fPAngle, UGReal fRAngle);
	void FromEulerAnglesYZX (UGReal fYAngle, UGReal fPAngle, UGReal fRAngle);
	void FromEulerAnglesZXY (UGReal fYAngle, UGReal fPAngle, UGReal fRAngle);
	void FromEulerAnglesZYX (UGReal fYAngle, UGReal fPAngle, UGReal fRAngle);
	
	// eigensolver, matrix must be symmetric
	void EigenSolveSymmetric (UGReal afEigenvalue[3],
		UGVector3R akEigenvector[3]) const;
	
	static void TensorProduct (const UGVector3R& rkU, const UGVector3R& rkV,
		UGMatrix3R& rkProduct);
	
	static const UGReal EPSILON;
	static const UGMatrix3R ZERO;
	static const UGMatrix3R IDENTITY;
	
    protected:
        // support for eigensolver
        void Tridiagonal (UGReal afDiag[3], UGReal afSubDiag[3]);
        UGbool QLAlgorithm (UGReal afDiag[3], UGReal afSubDiag[3]);
		
        // support for singular value decomposition
        static const UGReal ms_fSvdEpsilon;
        static const UGint ms_iSvdMaxIterations;
        static void Bidiagonalize (UGMatrix3R& kA, UGMatrix3R& kL,
            UGMatrix3R& kR);
        static void GolubKahanStep (UGMatrix3R& kA, UGMatrix3R& kL,
            UGMatrix3R& kR);
        // support for spectral norm
        static UGReal MaxCubicRoot (UGReal afCoeff[3]);
        UGReal m[3][3];
        // for faster access
        friend class UGMatrix4d;
   };
}

#endif // !defined(AFX_UGMATRIX3R_H__87211562_9080_4FF0_99EB_741D322A0BB3__INCLUDED_)
