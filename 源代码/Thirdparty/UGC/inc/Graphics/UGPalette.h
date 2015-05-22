
/*!
   **************************************************************************************
    \file     UGPalette.h
   **************************************************************************************
    \author   陈国雄
    \brief    调色板类                                                               
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UGPALETTE_H
#define UGPALETTE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC {

class GRAPHICS_API UGPalette
{
public:
	struct UGPaletteEntry  //! \brief 一个调色板信息
	{
		UGbyte peRed;      //! \brief 红色的比重
		UGbyte peGreen;    //! \brief 绿色的比重
		UGbyte peBlue;     //! \brief 蓝色的比重
		UGbyte peFlags;    //! \brief 标识符
		
		UGPaletteEntry()
		{		
			peRed = 0;
			peGreen = 0;
			peBlue = 0;
			peFlags = 0;
		}
	};

public:
	UGPalette();
	~UGPalette();
	
public:
	//! \brief 查找调色板的位置
	//! \param paletteEntry 要查找的调色板
	//! \return 返回找到的调色板的位置，找不到返回 -1
	UGint Find(UGPaletteEntry paletteEntry) const;
    //! \brief 在数组最后添加一个调色板
	//! \param paletteEntry 要添加的调色板
	//! \return 返回添加后,调色板在数组中的位置
	UGint Add(UGPaletteEntry paletteEntry);
	//! \brief 在数组中移出调色板
	//! \param nIndex 要移出的调色板在数组的位置
	//! \remarks 指定位置必须在数组范围内
	//! \param nCount 移出的个数,默认为1
	//! \return 返回实际移出面板的个数
	//! \remarks 如果 nCount>UGArray.size-nIndex 返回  nCount>UGArray.size-nIndex
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief 在数组指定位置插入一个调色板
	//! \remarks 如果指定位置不在数组范围内,会自动调整到[0,size]
	//! \param nIndex 要插入的位置
	//! \param paletteEntry 要插入的调色板
	void InsertAt(UGint nIndex, UGPaletteEntry paletteEntry);
	//! \brief 在数组的指定位置替换调色板
	//! \param nIndex 指定的位置
	//! \remarks 指定位置必须在数组size范围之内
	//! \param paletteEntry 要替换的调色板
	void SetAt(UGint nIndex, UGPaletteEntry paletteEntry);
    //! \brief 获取指定位置的调色板
	//! \param nIndex 指定的位置
	//! \remarks 指定位置必须在数组size范围之内
	//! \return 返回获得的调色板
	UGPaletteEntry GetAt(UGint nIndex)const;
    //! 移除所有元素,同时清空所有空间
	void RemoveAll();
	//! \brief 得到数组内部指针(地址连续)
	//! \return 返回数组内部指针(地址连续) 
	UGPaletteEntry* GetData();
	//! \brief 在数组最后增加一个数组
	//! \brief palette 要增加的数组
	//! \return 返回加入数组的起始位置
	UGint Append(const UGPalette& palette);
	//! \brief 数组拷贝,原来的内容被覆盖
	//! \param palette 传入的数组
	void Copy(const UGPalette& palette);
	//! \brief 调整m_Palette的内存空间为 nSize, 
	//! \remarks 如果原有空间不够, 内存空间会增加, 
	//! \param nSize 指定的新的调色板个数
	void SetSize(UGint nSize);
	//! \brief 得到有用的调色板的个数
	//! \return 返回的调色板的个数
	UGint GetSize()const;
	//! \brief 判断数组是否为空
	//! \return 如果空返回 true,否则返回 false.
	UGbool IsEmpty()const;

protected:
	//! \brief 将调色板用数组实现
	UGArray<UGPaletteEntry> m_Palette;	

};

}

#endif


