// UGImgCompiler.h: interface for the UGImgCompiler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGImgCompiler_H__B1FD16A8_BBE5_44D1_82C3_2033C1CDD4F9__INCLUDED_)
#define AFX_UGImgCompiler_H__B1FD16A8_BBE5_44D1_82C3_2033C1CDD4F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
namespace UGC
{
/*
class SCENE_API UGImgCompiler  
{
public:
	CSmImageCompiler(int nWidth=128,float fLevelZeroDegree=CSmQuadTileSet::ms_fLevelZeroTileSizeDegrees);
	virtual ~CSmImageCompiler();
public:
	void SetWidth(int nWidth);
	int GetWidth();
	void SetLevelZeroDegree(float fLevelZeroDegree);
	float GetLevelZeroDegree();
	int GetPixelBytes(const ImgPixelFormat& ePixelFormat);
	// Image采样成nWidth,nHeight的jpg文件放到strDest中去，默认空为临时目录中compiletemp.jpg文件
	// strDest是采样后生成的文件指定存放的目录,返回采样后的文件路径
	CString Resample(CImgFile* pImageFile,ImgType eType,int nWidth,int nHeigt,CString strDest="");
	// bWriteOver表示如果文件存在是否覆盖生成的文件,该函数表示生成一个nLevel-ncol-nRow处的jpg文件
	//并返回文件路径
	//CString GenFileName(const CString& strFileDir,bool bWriteOver,int nLevel,int nCol,int nRow);
	// 编译生成四叉树RGB数据文件
	//void CompileFile(CString strFilePath,const CString& strDestDirectory,const CRect2D& rcGeoRect,int nQuality=100);

private:
    //分割而成得四叉树文件的大小,以及最上层原始块对应得经纬度范围跨度
	int m_nWidth;
	float m_fLevelZeroDegree;
	//CImgFileJPEG m_ImgDest; //将原始文件编译成四叉树目录级结构的Jpeg文件

};
*/

}

#endif // !defined(AFX_UGImgCompiler_H__B1FD16A8_BBE5_44D1_82C3_2033C1CDD4F9__INCLUDED_)
