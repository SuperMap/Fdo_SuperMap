// UGTerrainTile.h: interface for the UGTerrainTile class.
/* 
	\file UGTerrainTile.h
	\brief 地形块头文件。
	\author 马柳青
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINTILE_H__0C84FBA0_9FA0_45FC_9556_9197E8D6DAFF__INCLUDED_)
#define AFX_UGTERRAINTILE_H__0C84FBA0_9FA0_45FC_9556_9197E8D6DAFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{
//! \brief 地形块。	
class SCENE_API UGTerrainTile  
{
public:
	//! \brief 构造函数。
	UGTerrainTile();
	//! \brief 构造函数。
	//! \param pTerraUGintileServer 地形数据服务[in]。
	UGTerrainTile( UGTerrainTileServer* pTerraUGintileServer );
	//! \brief 析构函数。
	virtual ~UGTerrainTile();	

public:
	//! \brief 获取东边界。
	//! \return 东边界。
	UGdouble GetEast();	
	//! \brief 设置东边界。
	//! \param value 东边界[in]。
	void SetEast(UGdouble value);	
	//! \brief 获取南边界。
	//! \return 南边界。
	UGdouble GetSouth();
	//! \brief 设置南边界。
	//! \param value 南边界[in]。
	void SetSouth(UGdouble value);
	//! \brief 获取西边界。
	//! \return 西边界。
	UGdouble GetWest();	
	//! \brief 设置西边界。
	//! \param value 西边界[in]。
	void SetWest(UGdouble value);
	//! \brief 获取北边界。
	//! \return 北边界。
	UGdouble GetNorth();	
	//! \brief 设置北边界。
	//! \param value 北边界[in]。
	void SetNorth(UGdouble value);
	//! \brief 设置分辨率。
	//! \param value 分辨率[in]。
	void SetSamplesPerTile(UGint value);	
	//! \brief 获取地块所在层。
	//! \return 地块所在层。
	UGint GetTargetLevel();
	//! \brief 设置地块所在层。
	//! \param value 地块所在层[in]。
	void SetTargetLevel(UGint value);
	//! \brief 获取行号。
	//! \return 行号。
	UGint GetRow();
	//! \brief 设置行号。
	//! \param value 行号[in]。
	void SetRow(UGint value);
	//! \brief 获取列号。
	//! \return 列号。
	UGint GetCol();
	//! \brief 设置列号。
	//! \param value 列号[in]。
	void SetCol(UGint value);
	//! \brief 获取块对应的本地文件名。
	//! \return 文件名。
	UGString GetTileFilePath();
	//! \brief 设置块对应的本地文件名。
	//! \param value 文件名[in]。
	void SetTileFilePath(UGString value);

	//! \brief 是否初始化完毕。
	//! \return 是否初始化。
	UGbool IsInitialized();
	//! \brief 设置初始化标志。
	//! \param value 初始化标志[in]。
	void SetInitialized(UGbool value);
	//! \brief 是否有效。
	//! \return 是否有效。
	UGbool IsValid();
	//! \brief 设置有效标志。
	//! \param value 有效标志[in]。
	void SetValid(UGbool value);

	//! \brief 获取每块的度数。
	//! \return 每块的度数。
	UGdouble GetTileSizeDeg();
	//! \brief 设置每块的度数。
	//! \param value 每块的度数[in]。
	void SetTileSizeDeg(UGdouble value);

	//! \brief 获取地形数据。
	//! \return 地形数据指针。
	UGfloat* GetElevationData();
	//! \brief 设置地形数据。
	//! \param pElevationData 地形数据指针[in]。
	void SetElevationData(UGfloat* pElevationData);
	//! \brief 获取地形数据的最小值。
	//! \return 地形数据最小值。
	UGdouble GetMinValue();
	//! \brief 设置地形数据的最小值。
	//! \param value 地形数据最小值[in]。
	void SetMinValue(UGdouble value);
	//! \brief 获取地形数据的最大值。
	//! \return 地形数据最大值。
	UGdouble GetMaxValue();
	//! \brief 设置地形数据的最大值。
	//! \param value 地形数据最大值[in]。
	void SetMaxValue(UGdouble value);	
	
	//! \brief 初始化地形数据。
	void Initialize();	
	//! \brief 获取指定经纬度的高度。
	//! \param lat 经度[in]。
	//! \param lon 纬度[in]。
	//! \return 高度。
	UGfloat GetElevationAt(UGdouble lat, UGdouble lon);	

protected:
	//! \brief 地形数据文件名。
	UGString m_strTileFilePath;
	//! \brief 每块地形度数。
	UGdouble m_dTileSizeDeg;
	//! \brief 分辨率。
	UGint m_nSamplesPerTile;
	//! \brief 南边界。
	UGdouble m_dSouth;
	//! \brief 北边界。
	UGdouble m_dNorth;
	//! \brief 西边界。
	UGdouble m_dWest;
	//! \brief 东边界。
	UGdouble m_dEast;
	//! \brief 行号。
	UGint m_nRow;
	//! \brief 列号。
	UGint m_nCol;
	//! \brief 层数。
	UGint m_nTargetLevel;
	//! \brief 初始化标志。
	UGbool m_bInitialized;
	//! \brief 有效标志。
	UGbool m_bValid;
	//! \brief 地形数据最大值。
	UGdouble m_dMaxValue;
	//! \brief 地形数据最小值。
	UGdouble m_dMinValue;
	//! \brief 地形数据服务。
	UGTerrainTileServer* m_pTerrainTileServer;
private:
	//! \brief 地形数据。
	UGfloat* m_pElevationData;

};
}
#endif // !defined(AFX_UGTERRAINTILE_H__0C84FBA0_9FA0_45FC_9556_9197E8D6DAFF__INCLUDED_)
