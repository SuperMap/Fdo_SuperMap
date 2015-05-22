// UGTerrainTileServer.h: interface for the UGTerrainTileServer class.
/* 
	\file UGTerrainTileServer.h
	\brief 地形数据服务头文件。
	\author 张艳良、马柳青
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINTILESERVER_H__2071A872_1E06_40CD_B1CB_6D809CDC7D19__INCLUDED_)
#define AFX_UGTERRAINTILESERVER_H__2071A872_1E06_40CD_B1CB_6D809CDC7D19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{

//! \brief 地形数据服务。
class SCENE_API UGTerrainTileServer  
{
public:
	//! \brief 构造函数。
	UGTerrainTileServer();
	//! \brief 构造函数。
	//! \param serverUrl 获取地形的服务URL地址[in]。	
	//! \param levelZeroTileSizeDegrees 第0层每块的度数[in]。
	//! \param samplesPerTile 每块分辨率[in]。
	//! \param fileExtension 数据扩展名[in]。
	//! \param numberLevels 层数[in]。
	//! \param terraintileDirectory 地形数据本地存储目录[in]。
	//! \param dataType 地形数据类型[in]。
	UGTerrainTileServer(
		const UGString& serverUrl,
		UGdouble levelZeroTileSizeDegrees,
		UGint samplesPerTile,
		const UGString& fileExtension,
		UGint numberLevels,
		const UGString& terraintileDirectory,
		const UGString& dataType,UGdouble dNorth=PI/2,UGdouble dSouth=-PI/2, UGdouble dWest=-PI, UGdouble dEast=PI);
	//! \brief 析构函数。
	virtual ~UGTerrainTileServer();

public:
	//! \brief 下载指定的地形块的地形数据。
	//! \param pTerrainTile 地形块指针[in]。
	//! \return 是否下载成功。
	UGbool DownloadTerrainDataFile(UGTerrainTile *pTerrainTile);	
	//! \brief 获取数据文件的宽度类型。
	//! \return 宽度类型。
	//! \remarks 字符串"Int16"为整型16位, 字符串"Float32"为浮点型32位 。
	UGString GetDataType();	
	//! \brief 获取指定的经纬度对对应的地块。
	//! \param latitude 经度[in]。
	//! \param longitude 纬度[in]。
	//! \param samplesPerDegree 分辨率[in]。
	//! \return 地块指针。
	UGTerrainTile* GetTerrainTile(UGdouble latitude, UGdouble longitude, 
		UGdouble samplesPerDegree);	
	UGdouble GetNorth(){return m_dNorth;};
	UGdouble GetSouth(){return m_dSouth;};
	UGdouble GetWest(){return m_dWest;};
	UGdouble GetEast(){return m_dEast;};

protected:
	//! \brief 获取地形的服务URL地址。
	UGString m_strServerUrl;
	//! \brief 第0层每块的度数。
	UGdouble m_dL0TileSizeDeg;
	//! \brief 每块分辨率。
	UGint m_nSamplesPerTile;
	//! \brief 层数。
	UGint m_nNumberLevels;
	//! \brief 数据扩展名。
	UGString m_strFileExt;
	//! \brief 地形数据本地存储目录。
	UGString m_strTileDir;
	//! \brief 地形数据类型。
	UGString m_strDataType;
	UGdouble m_dNorth;
	UGdouble m_dSouth;
	UGdouble m_dWest;
	UGdouble m_dEast;
};
}

#endif // !defined(AFX_UGTERRAINTILESERVER_H__2071A872_1E06_40CD_B1CB_6D809CDC7D19__INCLUDED_)
