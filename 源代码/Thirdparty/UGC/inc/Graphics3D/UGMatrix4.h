// UGMatrix4.h: interface for the UGMatrix4 class.


#if !defined(UG_MATRIX4_H)
#define UG_MATRIX4_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include <Graphics3D/UGMatrix3.h>

namespace UGC
{
	/** 齐次矩阵
	@remarks
	    按照OpenGL的方式来组织矩阵,也就是说把矩阵的每一个列对应一个向量
        如果任意一个向量V要经过M1,M2,M3三种变换,则变换后的矩阵应为
        M3*M2*M1*V,这和D3D得方式正好相反
        M*V = 
       [ m[0][0]  m[0][1]  m[0][2]  m[0][3] ]   {x}
       | m[1][0]  m[1][1]  m[1][2]  m[1][3] | * {y}
       | m[2][0]  m[2][1]  m[2][2]  m[2][3] |   {z}
       [ m[3][0]  m[3][1]  m[3][2]  m[3][3] ]   {1}

	*/
	
	class GRAPHICS3D_API UGMatrix4  
	{
    protected:
        /// The matrix entries, indexed by [row][col].
        union 
		{
            Real  m[4][4];
            Real _m[16];
        };

	public:
	    static const UGMatrix4 ZERO;
	    static const UGMatrix4 IDENTITY;

    public:
        inline UGMatrix4()
        {
			//It does NOT initialize the matrix for efficiency
        }

	    inline UGMatrix4(
            Real m00, Real m01, Real m02, Real m03,
            Real m10, Real m11, Real m12, Real m13,
            Real m20, Real m21, Real m22, Real m23,
            Real m30, Real m31, Real m32, Real m33 )
        {

            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
            m[2][0] = m20;
            m[2][1] = m21;
            m[2][2] = m22;
            m[2][3] = m23;
            m[3][0] = m30;
            m[3][1] = m31;
            m[3][2] = m32;
            m[3][3] = m33;
        }

	    inline Real* operator [] ( UGuint iRow )
        {
            assert( iRow < 4 );
            return m[iRow];
        }

	    inline const Real *const operator [] ( UGuint iRow ) const
        {
            assert( iRow < 4 );
            return m[iRow];
        }

		// 右乘m2
	    inline UGMatrix4 Concatenate(const UGMatrix4 &m2)
        {
            UGMatrix4 r;

            r.m[0][0] = m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0] + m[0][3] * m2.m[3][0];
            r.m[0][1] = m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1] + m[0][3] * m2.m[3][1];
            r.m[0][2] = m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2] + m[0][3] * m2.m[3][2];
            r.m[0][3] = m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3] * m2.m[3][3];

            r.m[1][0] = m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0] + m[1][3] * m2.m[3][0];
            r.m[1][1] = m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1] + m[1][3] * m2.m[3][1];
            r.m[1][2] = m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2] + m[1][3] * m2.m[3][2];
            r.m[1][3] = m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3] * m2.m[3][3];

            r.m[2][0] = m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0] + m[2][3] * m2.m[3][0];
            r.m[2][1] = m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1] + m[2][3] * m2.m[3][1];
            r.m[2][2] = m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2] + m[2][3] * m2.m[3][2];
            r.m[2][3] = m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3] * m2.m[3][3];

            r.m[3][0] = m[3][0] * m2.m[0][0] + m[3][1] * m2.m[1][0] + m[3][2] * m2.m[2][0] + m[3][3] * m2.m[3][0];
            r.m[3][1] = m[3][0] * m2.m[0][1] + m[3][1] * m2.m[1][1] + m[3][2] * m2.m[2][1] + m[3][3] * m2.m[3][1];
            r.m[3][2] = m[3][0] * m2.m[0][2] + m[3][1] * m2.m[1][2] + m[3][2] * m2.m[2][2] + m[3][3] * m2.m[3][2];
            r.m[3][3] = m[3][0] * m2.m[0][3] + m[3][1] * m2.m[1][3] + m[3][2] * m2.m[2][3] + m[3][3] * m2.m[3][3];

            return r;
        }

        /** Matrix concatenation using '*'.
        */
	    inline UGMatrix4 operator * ( const UGMatrix4 &m2 )
        {
            return Concatenate( m2 );
        }

        /** Vector transformation using '*'.
            @remarks
                Transforms the given 3-D vector by the matrix, projecting the 
                result back into <i>w</i> = 1.
            @note
                This means that the initial <i>w</i> is considered to be 1.0,
                and then all the tree elements of the resulting 3-D vector are
                divided by the resulting <i>w</i>.
        */
	    inline UGVector3 operator * ( const UGVector3 &v ) const
        {
			assert( m[3][3] == 1.0 );

            UGVector3 r;

            Real fInvW = 1.0 / ( m[3][0] + m[3][1] + m[3][2] + m[3][3] );

            r.x = ( m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] ) * fInvW;
            r.y = ( m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] ) * fInvW;
            r.z = ( m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] ) * fInvW;

            return r;
        }
        /** Matrix addition.
        */
	    inline UGMatrix4 operator + ( const UGMatrix4 &m2 ) const
        {
            UGMatrix4 r;

            r.m[0][0] = m[0][0] + m2.m[0][0];
            r.m[0][1] = m[0][1] + m2.m[0][1];
            r.m[0][2] = m[0][2] + m2.m[0][2];
            r.m[0][3] = m[0][3] + m2.m[0][3];

            r.m[1][0] = m[1][0] + m2.m[1][0];
            r.m[1][1] = m[1][1] + m2.m[1][1];
            r.m[1][2] = m[1][2] + m2.m[1][2];
            r.m[1][3] = m[1][3] + m2.m[1][3];

            r.m[2][0] = m[2][0] + m2.m[2][0];
            r.m[2][1] = m[2][1] + m2.m[2][1];
            r.m[2][2] = m[2][2] + m2.m[2][2];
            r.m[2][3] = m[2][3] + m2.m[2][3];

            r.m[3][0] = m[3][0] + m2.m[3][0];
            r.m[3][1] = m[3][1] + m2.m[3][1];
            r.m[3][2] = m[3][2] + m2.m[3][2];
            r.m[3][3] = m[3][3] + m2.m[3][3];

            return r;
        }

        /** Matrix subtraction.
        */
	    inline UGMatrix4 operator - ( const UGMatrix4 &m2 )
        {
            UGMatrix4 r;
            r.m[0][0] = m[0][0] - m2.m[0][0];
            r.m[0][1] = m[0][1] - m2.m[0][1];
            r.m[0][2] = m[0][2] - m2.m[0][2];
            r.m[0][3] = m[0][3] - m2.m[0][3];

            r.m[1][0] = m[1][0] - m2.m[1][0];
            r.m[1][1] = m[1][1] - m2.m[1][1];
            r.m[1][2] = m[1][2] - m2.m[1][2];
            r.m[1][3] = m[1][3] - m2.m[1][3];

            r.m[2][0] = m[2][0] - m2.m[2][0];
            r.m[2][1] = m[2][1] - m2.m[2][1];
            r.m[2][2] = m[2][2] - m2.m[2][2];
            r.m[2][3] = m[2][3] - m2.m[2][3];

            r.m[3][0] = m[3][0] - m2.m[3][0];
            r.m[3][1] = m[3][1] - m2.m[3][1];
            r.m[3][2] = m[3][2] - m2.m[3][2];
            r.m[3][3] = m[3][3] - m2.m[3][3];

            return r;
        }

        /** Tests 2 matrices for equality.
        */
	    inline UGbool operator == ( const UGMatrix4& m2 ) const
        {
            if( 
                m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] || m[0][3] != m2.m[0][3] ||
                m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[0][2] || m[1][3] != m2.m[0][3] ||
                m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[0][2] || m[2][3] != m2.m[0][3] ||
                m[3][0] != m2.m[3][0] || m[3][1] != m2.m[3][1] || m[3][2] != m2.m[0][2] || m[3][3] != m2.m[0][3] )
                return false;
            return true;
        }

        /** Tests 2 matrices for inequality.
        */
	    inline UGbool operator != ( UGMatrix4& m2 ) const
        {
            if( 
                m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] || m[0][3] != m2.m[0][3] ||
                m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[0][2] || m[1][3] != m2.m[0][3] ||
                m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[0][2] || m[2][3] != m2.m[0][3] ||
                m[3][0] != m2.m[3][0] || m[3][1] != m2.m[3][1] || m[3][2] != m2.m[0][2] || m[3][3] != m2.m[0][3] )
                return true;
            return false;
        }

        /** Assignment from 3x3 matrix.
        */
	    inline void operator = ( const UGMatrix3& mat3 )
        {
            m[0][0] = mat3.m[0][0]; m[0][1] = mat3.m[0][1]; m[0][2] = mat3.m[0][2];
            m[1][0] = mat3.m[1][0]; m[1][1] = mat3.m[1][1]; m[1][2] = mat3.m[1][2];
            m[2][0] = mat3.m[2][0]; m[2][1] = mat3.m[2][1]; m[2][2] = mat3.m[2][2];
        }

	    inline UGMatrix4 Transpose(void)
        {
            return UGMatrix4(m[0][0], m[1][0], m[2][0], m[3][0],
                           m[0][1], m[1][1], m[2][1], m[3][1],
                           m[0][2], m[1][2], m[2][2], m[3][2],
                           m[0][3], m[1][3], m[2][3], m[3][3]);
        }

		/** Make Identity Matrix*/
		inline void MakeIdentity()
		{
			m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
            m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
            m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
            m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
		}

        /*
        -----------------------------------------------------------------------
        Translation Transformation
        -----------------------------------------------------------------------
        */
        /** Sets the translation transformation part of the matrix.
        */
	    inline void SetTrans( const UGVector3& v )
        {
            m[0][3] = v.x;
            m[1][3] = v.y;
            m[2][3] = v.z;
        }

        /** Builds a translation matrix
        */
	    inline void MakeTrans( const UGVector3& v )
        {
            m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = v.x;
            m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = v.y;
            m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = v.z;
            m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
        }
		
	    inline void MakeTrans( Real tx, Real ty, Real tz )
        {
            m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = tx;
            m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = ty;
            m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = tz;
            m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
        }

        /** Gets a translation matrix. 
        */
	    inline static UGMatrix4 GetTrans( const UGVector3& v )
        {
            UGMatrix4 r;

            r.m[0][0] = 1.0; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = v.x;
            r.m[1][0] = 0.0; r.m[1][1] = 1.0; r.m[1][2] = 0.0; r.m[1][3] = v.y;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = 1.0; r.m[2][3] = v.z;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        /** Gets a translation matrix - variation for not using a vector.
        */
	    inline static UGMatrix4 GetTrans( Real t_x, Real t_y, Real t_z )
        {
            UGMatrix4 r;

            r.m[0][0] = 1.0; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = t_x;
            r.m[1][0] = 0.0; r.m[1][1] = 1.0; r.m[1][2] = 0.0; r.m[1][3] = t_y;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = 1.0; r.m[2][3] = t_z;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        /*
        -----------------------------------------------------------------------
        Scale Transformation
        -----------------------------------------------------------------------
        */
        /** Sets the scale part of the matrix.
        */
	    inline void SetScale( const UGVector3& v )
        {
            m[0][0] = v.x;
            m[1][1] = v.y;
            m[2][2] = v.z;
        }

        /** Gets a scale matrix.
        */
	    inline static UGMatrix4 GetScale( const UGVector3& v )
        {
            UGMatrix4 r;
            r.m[0][0] = v.x; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = 0.0;
            r.m[1][0] = 0.0; r.m[1][1] = v.y; r.m[1][2] = 0.0; r.m[1][3] = 0.0;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = v.z; r.m[2][3] = 0.0;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        /** Gets a scale matrix - variation for not using a vector.
        */
	    inline static UGMatrix4 GetScale( Real s_x, Real s_y, Real s_z )
        {
            UGMatrix4 r;
            r.m[0][0] = s_x; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = 0.0;
            r.m[1][0] = 0.0; r.m[1][1] = s_y; r.m[1][2] = 0.0; r.m[1][3] = 0.0;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = s_z; r.m[2][3] = 0.0;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        /** Extracts the rotation / scaling part of the Matrix as a 3x3 matrix. 
        @param m3x3 Destination Matrix3
        */
	    inline void Extract3x3Matrix(UGMatrix3& m3x3)
        {
            m3x3.m[0][0] = m[0][0];
            m3x3.m[0][1] = m[0][1];
            m3x3.m[0][2] = m[0][2];
            m3x3.m[1][0] = m[1][0];
            m3x3.m[1][1] = m[1][1];
            m3x3.m[1][2] = m[1][2];
            m3x3.m[2][0] = m[2][0];
            m3x3.m[2][1] = m[2][1];
            m3x3.m[2][2] = m[2][2];

        }
		#define MATSWAP(a,b) {temp=(a);(a)=(b);(b)=temp;}
		inline int Inverse(void)
		{
			
			Real matr[4][4], ident[4][4];
			int i, j, k, l, ll;
			int icol=0, irow=0;
			int indxc[4], indxr[4], ipiv[4];
			Real big, dum, pivinv, temp;
			
			for (i=0; i<4; i++) {
				for (j=0; j<4; j++) {
					matr[i][j] = m[i][j];
					ident[i][j] = 0.0f;
				}
				ident[i][i]=1.0f;
			} 
			// Gauss-jordan elimination with full pivoting.  Yes, folks, a 
			// GL Matrix4 is inverted like any other, since the identity is 
			// still the identity.
			
			// from numerical recipies in C second edition, pg 39
			
			for(j=0;j<=3;j++) ipiv[j] = 0;
			for(i=0;i<=3;i++) {
				big=0.0;
				for (j=0;j<=3;j++) {
					if(ipiv[j] != 1) {
						for (k=0;k<=3;k++) {
							if(ipiv[k] == 0) {
								if(fabs(matr[j][k]) >= big) {
									big = (float) fabs(matr[j][k]);
									irow=j;
									icol=k;
								}
							} else if (ipiv[k] > 1) return 1;
						} 
					}
				}
				++(ipiv[icol]);
				if (irow != icol) {
					for (l=0;l<=3;l++) MATSWAP(matr[irow][l],matr[icol][l]);
					for (l=0;l<=3;l++) MATSWAP(ident[irow][l],ident[icol][l]);
				}
				indxr[i]=irow;
				indxc[i]=icol;
				if(matr[icol][icol] == 0.0f) return 1; 
				pivinv = 1.0f / matr[icol][icol];
				matr[icol][icol]=1.0f;
				for (l=0;l<=3;l++) matr[icol][l] *= pivinv;
				for (l=0;l<=3;l++) ident[icol][l] *= pivinv;
				for (ll=0;ll<=3;ll++) {
					if (ll != icol) {
						dum=matr[ll][icol];
						matr[ll][icol]=0.0f;
						for (l=0;l<=3;l++) matr[ll][l] -= matr[icol][l]*dum;
						for (l=0;l<=3;l++) ident[ll][l] -= ident[icol][l]*dum;
					}
				}
			}
			for (l=3;l>=0;l--) {
				if (indxr[l] != indxc[l]) {
					for (k=0;k<=3;k++) {
						MATSWAP(matr[k][indxr[l]],matr[k][indxc[l]]);
					}
				}
			}
			for (i=0; i<4; i++) 
				for (j=0; j<4; j++)
					m[i][j] = matr[i][j];
				return 0;				
		}


        /** Function for writing to a stream.
        */
		inline friend std::ostream& operator <<
			( std::ostream& o, const UGMatrix4& m )
		{
			o << "UGMatrix4(";
			for (int i = 0; i < 4; ++i)
			{
				o << " row" << i << "{";
				for(int j = 0; j < 4; ++j)
				{
					o << m[i][j] << " ";
				}
				o << "}";
			}
			o << ")";
			return o;
		}
		
		
	};
}

#endif // !defined(UGMATRIX4_H)

