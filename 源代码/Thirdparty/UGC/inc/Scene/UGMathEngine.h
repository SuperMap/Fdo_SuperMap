// UGMathEngine.h: interface for the UGMathEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_)
#define AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGQuaternion4d.h"
#include "Base/UGFile.h"
#include "Base/UGToolkit.h"
namespace UGC 
{
	struct UV
	{
		UV()
		{
			U = 0;
			V = 0;
		}
		UV(UGdouble u, UGdouble v)
		{
			U = u;
			V = v;
		}
		UGdouble U;
		UGdouble V;
	};
	typedef void* (*PJ_INIT)(UGint argc, UGchar* args[]);
	typedef char* (*PJ_FREE)(void* projPJ);
	typedef UV (*PJ_FWD)(UV uv, void* projPJ);
	typedef UV (*PJ_INV)(UV uv, void* projPJ);
	class SCENE_API UGSphereProject
	{
	public:
		UGSphereProject()
		{
			LoadProjectDLL();
		}
		virtual ~UGSphereProject()
		{
			UnLoadProjectDLL();
		}
		static void LoadProjectDLL()
		{
			UGchar*  projectionParameters[5] = {"proj=merc", "ellps=sphere", "a=6378137.0", "es=0.0", "no.defs"};
			//UGchar* strPrj[4]={ "proj=utm", "ellps=WGS84", "no.defs", "zone=32" };
			if (m_hProjectDLL==NULL)
			{
				UGString strFileName = UGFile::GetModulePath("SuBase");	
				m_hProjectDLL = UGToolkit::LoadDll(strFileName+"/proj.dll");
				if(m_hProjectDLL == NULL)
				{
					return;
				}
				
			}
			if (m_hProjectDLL!=NULL)
			{
				pj_init=(PJ_INIT)UGToolkit::GetProcAddress(m_hProjectDLL, "pj_init");
				pj_fwd=(PJ_FWD)UGToolkit::GetProcAddress(m_hProjectDLL, "pj_fwd");
				pj_inv=(PJ_INV)UGToolkit::GetProcAddress(m_hProjectDLL, "pj_inv");
				pj_free=(PJ_FREE)UGToolkit::GetProcAddress(m_hProjectDLL, "pj_free");
			}
			SetProject(5,projectionParameters);
			
		}
		static void UnLoadProjectDLL()
		{
			if (ms_pProjPJ != NULL)
			{
				//pj_free(ms_pProjPJ);
				ms_pProjPJ = NULL;
			}
			if (m_hProjectDLL!=NULL)
			{
				UGToolkit::FreeDll(m_hProjectDLL);
				m_hProjectDLL=NULL;
			}
			
			
		}
		static void SetProject(UGint argc, UGchar* args[])
		{
			if (ms_pProjPJ!=NULL)
			{
				pj_free(ms_pProjPJ);
			}
			ms_pProjPJ=pj_init(argc,args);
		}
		static UV Forward(UV uv)
		{
			return pj_fwd(uv, ms_pProjPJ);
		}
		static UV Inverse(UV uv)
		{
			return pj_inv(uv, ms_pProjPJ);
		}
	private:
		//! \brief Project的句柄
		static void* m_hProjectDLL;
		static void* ms_pProjPJ;
		static PJ_INIT pj_init;
		static PJ_FWD pj_fwd;
		static PJ_INV pj_inv;
		static PJ_FREE pj_free;
	};
	
class SCENE_API UGMathEngine  
{
public:
	UGMathEngine();
	virtual ~UGMathEngine();

	static UGdouble DegreesToRadians(UGdouble degrees);
	static UGdouble RadiansToDegrees(UGdouble dRadians);
	static UGVector3R SphericalToCartesian(UGdouble dLongitude, UGdouble dLatitude,UGdouble dRadius);
	static UGdouble Degree2Radian(UGdouble fDegree);
	static UGVector3R CartesianToSphericalD(UGdouble x, UGdouble y, UGdouble z);
	static UGVector3R QuaternionToEuler(UGQuaternion4d q);
	static UGQuaternion4d EulerToQuaternion(UGdouble yaw, UGdouble pitch, UGdouble roll);
	
	// 修改操作: 将返回值int类型修改成UGint类型
	// 修改人: luofx
	// 修改日期: 2007.8.16
//	static int GetRowFromLatitude(UGdouble latitude, UGdouble tileSize);
//	static int GetRowFromLatitude(UGdouble latitude, UGdouble tileSize);
//	static int GetColFromLongitude(UGdouble longitude, UGdouble tileSize);
//	static int GetColFromLongitude(UGdouble longitude, UGdouble tileSize);
    
	// 注意这四个函数传入的是角度而不是弧度
	static UGint GetRowFromLatitude(UGdouble latitude, UGdouble tileSize);
	static UGint GetColFromLongitude(UGdouble longitude, UGdouble tileSize);


	static UGint GetGoogleRowFromLatitude(UGdouble latitude, UGdouble tileSize);
	static UGint GetGoogleColFromLongitude(UGdouble longitude, UGdouble tileSize);
	static void  GetGoogleRowCol(UGdouble dLongitude, UGdouble dLatitude,UGint nLevel,UGint& nRow,UGint& nCol );
	static void  GetGoogleTileRange(UGint nRow, UGint nCol,UGint nLevel,UV& ul,UV& ur, UV& ll,UV& lr);
	static void  GetGoogleGeoTileRange( UV ul, UV lr,UGdouble& dNorth,UGdouble& dSouth,UGdouble& dWest,UGdouble& dEast);
	static UGdouble SphericalDistance( UGdouble lonA, UGdouble latA,UGdouble lonB,UGdouble latB);
	// 给一个顶点数组和索引数组计算三角型列表的向量
	static UGReal* ComputeVertexNormals(UGReal* pVertex,UGushort* pIndice,UGint nVertexCount,UGint nIndiceCount);
	// 没有索引数据,计算三角形列表的向量 
	static UGReal* ComputeVertexNormals(UGReal* pVertex,UGint nVertexCount);
	//  三角面片的向量
	static UGReal* ComputeFaceNormals(UGReal* pVertex,UGushort* pIndice,UGint nVertexCount,UGint nIndiceCount);
	// 没有索引数据,计算三角形列表的向量 
	static UGReal* ComputeFaceNormals(UGReal* pVertex,UGint nVertexCount);
	static UGVector3R GetVec1RotToVec2(const UGVector3R& vec1,const UGVector3R& vec2);
	static UGVector3R GetRotFormAngleAxies(UGfloat fAngle,const UGVector3R& vecAxies);
	static UGdouble Sign (UGdouble fValue);

	//! \brief 判断是否是合法实数。
	//! \param dValue 实数[in]。
	//! \return true为合法，false为非法。
	static UGbool IsRealNaN(UGdouble dValue);	
};
}
#endif // !defined(AFX_UGMATHENGINE_H__90331450_3347_42D5_B0A0_41353F9437C8__INCLUDED_)
