/** 
*  \file	 SuperMapIniFile.cpp
*  \author	 ºÂÓñ½­
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-25
*  \note:
*/


#include <SuperMapIniFile.h>
#include <algorithm>    //find() function
#include <string>
#include <fstream>

#ifdef _WIN32
#	define snprintf _snprintf
#endif

SuperMapIniFile::SuperMapIniFile()
{
	m_bDirty = false;
}

SuperMapIniFile::~SuperMapIniFile()
{
}

bool SuperMapIniFile::Load(const char *szFile)
{
	m_bDirty = false;   //init flag
	m_contents.clear(); //clear storage
	SetPath(szFile);

	std::string line;

	//open the INI file for reading
	std::fstream iniFile(szFile, std::ios::in/*|std::ios::nocreate*/);    
	if(!iniFile.is_open())
	{
		return false;
	}

	//read from file line by line
	bool bDone = false;
	char szBuffer[4000];

	while(!bDone)
	{
		szBuffer[0] = '\0';
		iniFile.getline(szBuffer, sizeof(szBuffer));

		line = szBuffer;

		//is that a section in the buffer
		if('[' == line[0])
		{
			size_t nPos = line.find_first_of(']');
			if(-1 != nPos)
			{
				SuperMapIniSection section;
				section.m_name = line.substr(1, nPos-1).c_str();

				//add new section to the end of storage
				m_contents.push_back(section);
			}
		}
		else
		{
			//else is the line "key=value"
			size_t nPos = line.find_first_of('=');

			if(nPos > 0)    //there must be space for key name
			{
				//add new key to the last section in the storage
				SuperMapIniKey key;
				key.m_name  = line.substr(0, nPos).c_str();
				key.m_value = line.substr(nPos+1, line.size()-nPos-1).c_str();

				size_t size = m_contents.size();
				if(size > 0)
				{
					m_contents[size-1].m_Keys.push_back(key);
				}
			}
		}

		//check for exit
		bDone = iniFile.eof() || iniFile.bad() || iniFile.fail();
	}

	return true;
}

bool SuperMapIniFile::Save()
{
	//return true;
	m_bDirty = false;   //reset flag

	//ensure directory exists
	std::string strDir = m_strPath;

	//open the INI file for writing
	std::fstream iniFile(m_strPath.c_str(), std::ios::out|std::ios::trunc);
	if(!iniFile.is_open())
	{
		return false;
	}

	char szBuffer[4000];

	size_t size = m_contents.size();
	for(size_t i = 0; i < size; i++)
	{
		//write line with section name
		snprintf(szBuffer, sizeof(szBuffer), "[%s]\n", m_contents[i].m_name.c_str());
		iniFile.write(szBuffer, (std::streamsize)strlen(szBuffer));

		size_t count = m_contents[i].m_Keys.size();
		for(size_t j = 0; j < count; j++)
		{
			//write "key = value"
			snprintf(szBuffer, sizeof(szBuffer), "%s=%s\n",
				m_contents[i].m_Keys[j].m_name.c_str(),
				m_contents[i].m_Keys[j].m_value.c_str());

			iniFile.write(szBuffer, (std::streamsize)strlen(szBuffer)); 
		}

		iniFile.write("\n", 1);
	}

	return true;
}

bool SuperMapIniFile::ClearAll()
{
	m_bDirty = true;
	m_contents.clear();
	return true;
}

bool SuperMapIniFile::SectionExists(const char *szSection)
{
	SuperMapIniSectionIterator It;
	return FindSection(It, szSection);
}

bool SuperMapIniFile::KeyExists(const char *szSection, const char *szKey)
{
	SuperMapIniKeyIterator It;
	return FindKey(It, szSection, szKey);
}

bool SuperMapIniFile::GetValue(const char *szSection, const char *szKey, std::string &value, const char *szDefault)
{
	SuperMapIniKeyIterator It;
	if(FindKey(It, szSection, szKey)){
		value = It->m_value;
		return true;
	}

	value = szDefault;
	return false;
}

bool SuperMapIniFile::GetValue(const char *szSection, const char *szKey, int  &nValue, int nDefault)
{
	SuperMapIniKeyIterator It;
	if(FindKey(It, szSection, szKey)){
		nValue = atoi(It->m_value.c_str());
		return true;
	}

	nValue = nDefault;
	return false;
}

bool SuperMapIniFile::GetValue(const char *szSection, const char *szKey, unsigned short &nValue, int nDefault)
{
	SuperMapIniKeyIterator It;
	if(FindKey(It, szSection, szKey)){
		nValue = atoi(It->m_value.c_str());
		return true;
	}

	nValue = nDefault;
	return false;
}

bool SuperMapIniFile::GetValue(const char *szSection, const char *szKey, bool &bValue, int nDefault)
{
	SuperMapIniKeyIterator It;
	if(FindKey(It, szSection, szKey)){
		bValue = atoi(It->m_value.c_str()) > 0;
		return true;
	}

	bValue = nDefault > 0;
	return false;
}

bool SuperMapIniFile::SetValue(const char *szSection, const char *szKey, const int nValue)
{
	char szNumber[30] = "";
	snprintf(szNumber, sizeof(szNumber), "%d", nValue);

	return SetValue(szSection, szKey, szNumber);
}

bool SuperMapIniFile::SetValue(const char *szSection, const char *szKey, const char *szVal)
{
	m_bDirty = true;    //content changes

	SuperMapIniKeyIterator It;
	if(FindKey(It, szSection, szKey))
	{
		It->m_value = szVal;    //update existing key
		return true;
	}

	if(AddSection(szSection))   //ensure section exists
	{
		SuperMapIniSectionIterator SecIt;
		if(FindSection(SecIt, szSection))
		{
			SuperMapIniKey key;
			key.m_name  = szKey;
			key.m_value = szVal;

			SecIt->m_Keys.push_back(key);
			return true;
		}
	}

	return false;
}

bool SuperMapIniFile::AddSection(const char *szSection)
{
	m_bDirty = true;    //content changes

	SuperMapIniSectionIterator It;

	if(!FindSection(It, szSection))
	{
		SuperMapIniSection section;
		section.m_name = szSection;

		m_contents.push_back(section);
		return true;
	}

	return true;    //section already exists
}

bool SuperMapIniFile::RemoveSection(const char *szSection)
{
	SuperMapIniSectionIterator It;

	if(FindSection(It, szSection))
		m_contents.erase(It);

	return true;
}

bool SuperMapIniFile::FindSection(SuperMapIniSectionIterator &It, const char *szSection)
{
	SuperMapIniSection section;
	section.m_name = szSection;

	It = std::find(m_contents.begin(), m_contents.end(), section);

	return (It != m_contents.end());
}

bool SuperMapIniFile::FindKey(SuperMapIniKeyIterator &It, const char *szSection, const char *szKey)
{
	SuperMapIniSectionIterator SecIt;

	if(FindSection(SecIt, szSection)) //section exists
	{
		SuperMapIniKey key;
		key.m_name = szKey;

		It = std::find(SecIt->m_Keys.begin(), SecIt->m_Keys.end(), key);

		return (It != SecIt->m_Keys.end());
	}

	return false;
}

