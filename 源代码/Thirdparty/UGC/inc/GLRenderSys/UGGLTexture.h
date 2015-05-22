/* 
	\file UGGLTexture.h
	\brief GL纹理类。
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGGLTEXTURE_H__39CECD8E_D6E2_4170_9BB7_836B7F219212__INCLUDED_)
#define AFX_UGGLTEXTURE_H__39CECD8E_D6E2_4170_9BB7_836B7F219212__INCLUDED_

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGTexture.h"

namespace UGC
{

//! \brief GL纹理类。
class GLRENDERSYS_API UGGLTexture : public UGTexture
{
public:

	//! \brief 构造函数。
	UGGLTexture();	
	
	//! \brief 带参数构造函数。
	//! \param strImgPath 路径[in]。
	//! \param *pGLSupport GL支持对象指针[in]。
	UGGLTexture(const UGString& strImgPath, UGGLSupport *pGLSupport);	
	
	//! \brief 析构函数。
	virtual ~UGGLTexture();	

public:

	//! \brief 绑定纹理。
	virtual void BindTexture();	
	
	//! \brief 加载纹理。
	//! \param bReleaseImgData 缺省为TRUE，释放图像数据[in]。
	virtual void LoadTexture(UGbool bReleaseImgData=TRUE) ;	
	
	//! \brief 删除纹理。
	//! \param bReleaseImgData 缺省为TRUE，释放图像数据[in]。
	virtual void DeleteTexture(UGbool bReleaseImgData=TRUE) ;	

private:
	
	//! \brief GLSupport指针。
	UGGLSupport *m_pGLSupport;

};

}
#endif // !defined(AFX_UGGLTEXTURE_H__39CECD8E_D6E2_4170_9BB7_836B7F219212__INCLUDED_)
