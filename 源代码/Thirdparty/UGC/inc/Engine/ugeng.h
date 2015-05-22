/*! \file	 ugeng.h
 *  \brief	 数据引擎的相关类型定义
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: ugeng.h,v 1.6 2007/05/16 00:44:56 liwl Exp $
 */

#ifndef UGENG_H
#define UGENG_H

namespace UGC {

enum UGEngAction {
	eaBeginTrans		= 1,
	eaCommitTrans		= 2,
	eaRollbackTrans		= 3,
	eaCheckOut			= 4,
	eaCheckIn			= 5,
	eaUndoCheckOut		= 6,
	eaLock				= 7,
	eaUnlock			= 8,
	eaShowSequence		= 9,
	eaShowMiniature		= 10,
	eaLoginLongTrans	= 11,
	eaLogoutLongTrans	= 12,
	eaUserLock			= 13,
	eaTrans				= 14,
	eaLongTrans			= 15,
	eaBuildPyramid		= 16,
	eaCache				= 17,
	eaReadOnly			= 18,
	eaTIN				= 19,
	eaRename			= 20

};

//! 引擎支持的能力
enum UGEngAbility
{
	ebReadOnly			= 1,
	ebLibrary			= 2,
	ebFileCache			= 3,
	ebLongTrans			= 4,
	ebSequence			= 5,
	ebUserLock			= 6
};

enum UGStatisticMode
{
	smMax				= 1,	//! 最大值
	smMin				= 2,	//! 最小值
	smAvg				= 3,	//! 平均值 
	smSum				= 4,	//! 总和
	smStdev				= 5,	//! 标准差
	smVar				= 6		//! 方差
};

struct UGDataVersionInfo
{
	UGint nVersionID;
	UGString strDataVersionName;
	UGString strDescription;
	UGTime	CreateTime;
};

struct UGCheckConflict
{
	//对象ID
	UGint nDataID;
	//C表中SmID = nDataID的且有冲突的版本ID
	UGint nDataVersionID;
	//冲突类型
	// 0  无意义
	// 1  Add
	// 2  Edit
	// 3  Del
	//		C表			D表
	//		Src      Dataversion
	//		Edit  \	/   Edit
	//		Del   / \   Del  
	//	1   Edit	Edit
	//	2   Edit	Del
	//	3	Del		Edit
	//	4	Del		Del
	UGint nConflictType;
};

enum UGPostOption
{
	POConflictCheck			= 1, //报告冲突
	POConflictPrev			= 2, //遇到冲突以原始版本为准
	POConflictLast			= 3, //遇到冲突以提交的版本为准
	POConflictUnion			= 4, //遇到冲突，Union空间对象
};

}

#endif
