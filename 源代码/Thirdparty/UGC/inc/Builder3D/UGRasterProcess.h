// UGRasterProcess.h: UGUGinterface for the UGRasterProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRASTERPROCESS_H__73700726_96C8_46EB_B7BF_03D56AFC151D__INCLUDED_)
#define AFX_UGRASTERPROCESS_H__73700726_96C8_46EB_B7BF_03D56AFC151D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"Base/ugdefs.h"
#include "Base/UGString.h"
namespace UGC
{
class UGDatasetRaster;
class BUILDER3D_API UGRasterProcess  
{
public:
	UGRasterProcess();
	UGRasterProcess(UGDatasetRaster* pDataset, const UGString& strDestPath,const UGString& strExtName = "png",UGint nMaxLevel=9,UGint nSampleSize=512);
	virtual ~UGRasterProcess();
	UGbool Produce();
	void SetDestPath(const UGString& strDestPath);
	void SetDestDsName(const UGString& strDestPath);
	void SetDataset(UGDatasetRaster* pDataset);
	void SetFileExt(const UGString& strFileExt);
	void SetMaxLevel(UGint nMaxLevel=9);
	void SetSampleSize(UGint nSampleSize=512);
	UGint GetMaxLevel();
	// 这几个函数要在ComputParam()后调用才能返回有效值
	UGint GetLevelBegin();
	UGint GetLevelEnd();
	UGdouble GetL0Degree();

private:
	UGbool ComputParam();

	UGbool WriteXML(const UGString& strFileName);
	void BuildDir(UGint nLevel,UGdouble dNorth,UGdouble dSouth,UGdouble dEast,UGdouble dWest,UGProgress* pProgress=NULL);
	void OuputBlock(UGString strFileName, UGdouble x1, UGdouble x2, UGdouble y1, UGdouble y2);
	UGbool OuputRGBA(UGString strFileName, UGdouble x1, UGdouble x2, UGdouble y1, UGdouble y2);

private:
	UGString m_strDestDsName;
	UGString m_strDesPath;               // 目标路径 
	UGString m_strFileExt;				// 扩展名
	UGdouble m_dNorth;					// 北纬
	UGdouble m_dSouth;					// 南纬
	UGdouble m_dWest;						// 西经
	UGdouble m_dEast;						// 东经
	UGint m_nLevelBegin;					// 开始层数
	UGint m_nLevelEnd;				    // 结束层数
	UGdouble m_dL0LatDegree;			// 最小级别块的度数
	UGdouble m_dL0LonDegree;			// 最小级别块的度数
	UGDatasetRaster* m_pDatasetRaster;	 // 栅格数据集       
	UGint m_nSampleSize;
	UGint m_nMaxLevel;
	// 这个变量由m_strDesPath+"/"m_strDestDsName组成
	UGString m_strDestDir;
};

}

#endif // !defined(AFX_UGRASTERPROCESS_H__73700726_96C8_46EB_B7BF_03D56AFC151D__INCLUDED_)
