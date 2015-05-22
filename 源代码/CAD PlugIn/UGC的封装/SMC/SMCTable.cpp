/*! 
	\file	SMCTable.cpp
    \brief	数据集基类（抽象类）预留在此以便扩展对属性数据的操作
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 初始化版本
*/

#include "UGC.h"
#include "SMCTable.h"

/*
SMCTable::SMCTable()
{
	m_pTable = NULL ;
}

SMCTable::~SMCTable()
{
	m_pTable = NULL ;
}*/
/*
bool SMCTable::UpdateField(const _tstring &strFieldName, const SMCVariant &varValue, const _tstring &strFilter)
{
	SMCTable* pTable = (SMCTable*) m_pTable;
	UGC::UGVariant tmpVariant;
	tmpVariant.Set((UGC::UGVariant::VarValue)varValue.m_value);
	return pTable->UpdateField(ASCII_STRING(strFieldName).c_str(), tmpVariant, ASCII_STRING(strFilter).c_str());
}*/
/*
bool SMCTable::UpdateFieldEx(const _tstring &strFieldName, const _tstring &strExpress, const _tstring &strFilter)
{
	UGC::UGTable* pTable = (UGC::UGTable*) m_pTable;
	return pTable->UpdateFieldEx(ASCII_STRING(strFieldName).c_str(), ASCII_STRING(strExpress).c_str(), ASCII_STRING(strFilter).c_str());
}

bool SMCTable::CopyField(const _tstring &strSrcField, const _tstring &strDestField)
{
	UGC::UGTable* pTable = (UGC::UGTable*) m_pTable;
	return pTable->CopyField(ASCII_STRING(strSrcField).c_str(), ASCII_STRING(strDestField).c_str());
}

bool SMCTable::CreateIndex(const _tstring &strFieldNameList, const _tstring &strIndexName)
{
	UGC::UGTable* pTable = (UGC::UGTable*) m_pTable;
	return pTable->CreateIndex(ASCII_STRING(strFieldNameList).c_str(), ASCII_STRING(strIndexName).c_str());
}

bool SMCTable::DropIndex(const _tstring &strIndexName)
{
	UGC::UGTable* pTable = (UGC::UGTable*) m_pTable;
	return pTable->DropIndex(ASCII_STRING(strIndexName).c_str());
}
*/
