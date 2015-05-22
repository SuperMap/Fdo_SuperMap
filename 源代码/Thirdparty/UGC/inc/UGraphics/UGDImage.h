/*! \file	 UGDImage.h
 *  \brief	 存储UGColor格式图像内存区的类,平台无关,仅提供平台相关的函数指针.
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDImage.h,v 1.2 2007/04/03 05:44:20 zengzm Exp $
 */

#ifndef UGDImage_H
#define UGDImage_H

#include "ugdefs.h"
#include "UGStream.h"

namespace UGC 
{
class UGDImage;

//! 用于创建对象的用户自定义函数类型
//! 例如:在X11中是创建在服务器端的Pixmap对象, 在Windows下是创建一个HBITMAP对象
typedef UGbool (*CreateUserData)(UGDImage& im);


//! 用于销毁对象的用户自定义函数类型
//! 例如:在X11中是销毁在服务器端的Pixmap对象, 在Windows下是销毁一个HBITMAP对象
typedef void (*DestroyUserData)(UGDImage& im);


class BASE_API UGDImage  
{
public:

	//! 用于指示在Load和Save函数中所传图像的格式(bmp, png, jpg, ico)
	enum ImageType
	{
		BMPImage = 0,
		PNGImage = 1,
		JPGImage = 2,
		ICOImage = 3
	};

	UGDImage();	
	UGDImage(UGint w,UGint h,UGColor c = UGRGB(255,255,255));	
	virtual ~UGDImage();
			
	//! 由外部数据(一块UGColor内存区)创建一个UGDImage对象
	UGbool Copy(UGint w,UGint h,UGColor* data);

	UGColor *GetData() const { return m_pData; }
			
	UGint GetWidth() const;
	UGint GetHeight() const;
	
	//! 取图像中(x, y)点的像素值
	UGColor GetPixel(UGint x,UGint y) const;
	

	//! 设置图像中(x, y)点的像素值
	void SetPixel(UGint x,UGint y,UGColor c);
	
	
	//! 猜测透明颜色, 返回透明色
	UGColor GuessTransparent() const;
	

	//! 设置透明色
	void SetTransparent(UGColor t);
	

	//! 获取透明色
	UGColor GetTransparent() const;
	

	//! 判断是否是单值图像
	UGbool IsMonochrom() const;	
	

	//! 设置为单值图像
	void SetMonochrom(UGbool m);
	

	//! 设置图像输出的质量(目前仅仅对JPEG格式起作用)
	void SetQuality(UGint q);
	

	//! 获取图像输出的质量(目前只获取JPEG格式)
	UGint GetQuality() const;
	

	//! 导出为磁盘文件
	UGbool Save(UGStream& store,ImageType type) const;
	

	//! 从磁盘文件导入
	UGbool Load(UGStream& store,ImageType type);	
	

	//! 改变m_pData内存区的大小
	void Scale(UGint w,UGint h, UGbool bIsResample=true);
	

	//! 获取用户数据(取出用户自定义资源标识)
	void* GetUserData() const { return m_hUserData; }
	

	//! 设置用户数据(设置用户自定义资源标识)
	void SetUserData(void* pUserData) { m_hUserData = pUserData; }
	
private:
	//! 用户自定义资源的标识
	//! 例如:在X11中为指向服务器端的缓存图像, 在Windows下为HBITMAP
	void* m_hUserData;	
	
protected:
	UGColor* m_pData;			// 存储图像的数据区
	UGColor  m_clrTransparent;	// 保存透明颜色的值
	UGbool   m_bMonochrom;		// 是否是单值图像的标志
	UGint    m_nQuality;		// jpeg图像格式的压缩质量
	UGint    m_nWidth;			// 图像宽度
	UGint    m_nHeight;			// 图像高度

	
public:
	//! 创建对象的用户自定义函数指针
	static CreateUserData m_pCreateUserDataFunc;
	

	//! 销毁对象的用户自定义函数指针
	static DestroyUserData m_pDestroyUserDataFunc;

};
	
}

#endif


