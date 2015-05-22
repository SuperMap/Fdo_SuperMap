/** 
*  \file	 SuperMapIniFile.h
*  \author	 ºÂÓñ½­
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-25
*  \note:
*/

#ifndef __SUPERMAP_INI_FILE_H__
#define __SUPERMAP_INI_FILE_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if _MSC_VER > 1000
#pragma warning(disable:4786)
#endif

#include <vector>
#include <string>
#include <string.h>

//TOFIX? use some kind od map<> to speedup searches ?

class SuperMapIniFile
{
	//Ini file keys
	class SuperMapIniKey
	{
	public:
		SuperMapIniKey(){};
		SuperMapIniKey(const SuperMapIniKey &that){ operator =(that); }
		void operator = (const SuperMapIniKey &that)
		{
			if(this != &that)
			{   // don't copy yourself
				m_name          = that.m_name;
				m_value         = that.m_value;
			}
		}

		//needed for searching key list
		bool operator == (const SuperMapIniKey &that) { return 0 == strcmp(m_name.c_str(), that.m_name.c_str()); };

		std::string m_name;    //std::string
		std::string m_value;
	};

	//ini file section
	class SuperMapIniSection
	{
	public:
		SuperMapIniSection(){};
		SuperMapIniSection(const SuperMapIniSection &that){ operator =(that); }
		void operator = (const SuperMapIniSection &that)
		{
			if(this != &that)
			{   // don't copy yourself
				m_name          = that.m_name;
				m_Keys          = that.m_Keys;
			}
		}

		//needed for searching section list
		bool operator == (const SuperMapIniSection &that) { return 0 == strcmp(m_name.c_str(), that.m_name.c_str()); };

		std::string m_name;
		std::vector<SuperMapIniKey>  m_Keys;
	};

	typedef std::vector<SuperMapIniKey>::iterator        SuperMapIniKeyIterator;
	typedef std::vector<SuperMapIniSection>::iterator    SuperMapIniSectionIterator;

public:
	SuperMapIniFile();
	virtual ~SuperMapIniFile();

	bool Load(const char *szFile);
	bool Save();

	inline bool    GetDirty() const { return m_bDirty;  }
	inline std::string  GetPath()  const { return m_strPath; }
	void SetPath(const char *szFile) { m_strPath = szFile; }

	//
	bool ClearAll();

	//read values in different formats
	bool GetValue(const char *szSection, const char *szKey, std::string &value, const char *szDefault);
	bool GetValue(const char *szSection, const char *szKey, int  &nValue, int nDefault = 0);
	bool GetValue(const char *szSection, const char *szKey, unsigned short &nValue, int nDefault = 0);
	bool GetValue(const char *szSection, const char *szKey, bool &bValue, int nDefault = 0);

	//TOFIX support comment?
	bool SetValue(const char *szSection, const char *szKey, const char *szVal);
	bool SetValue(const char *szSection, const char *szKey, const int nValue);
	//bool SetValue(const char *szSection, const char *szKey, const bool &bValue);

	bool KeyExists(const char *szSection, const char *szKey);

	bool SectionExists(const char *szSection);
	bool AddSection(const char *szSection);
	bool RemoveSection(const char *szSection);
	bool RemoveKey(const char *szSection, const char *szKey);
	//TOFIX support section/key enumeration -> GetXXXCount, GetXXXName(index)

protected:
	bool FindKey(SuperMapIniKeyIterator &It, const char *szSection, const char *szKey);
	bool FindSection(SuperMapIniSectionIterator &It, const char *szSection);

	std::vector<SuperMapIniSection> m_contents;
	std::string m_strPath;
	bool m_bDirty;   //is content changed without saving
};

#endif // __SUPERMAP_INI_FILE_H__



