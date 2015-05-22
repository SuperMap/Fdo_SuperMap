#ifndef __UTILSTRING_H__
#define __UTILSTRING_H__


#include <string>
#include <windows.h>
#include <tchar.h>
#include <sstream>
#include <algorithm>
#include <vector>

class SuperMapUtil
{
public:

	/*! \fn std::string WcharToString(const wchar_t* wstr)
	* \brief 宽字符边转ASCII
	* \param [in] wstr a wstring.
	* \return a string.
	*/
	static std::string WcharToString(const wchar_t* wstr);

	/*! \fn std::wstring StringToWString(const std::string &str)
	* \brief ASCII转换为宽字符
	* \param [in] str a string.
	* \return a wstring.
	*/
	static std::wstring StringToWString(const std::string &str);

	/*! \fn std::string MakeLower(const std::string& str)
	* \brief 转换成小写字符
	* \param [in] str a string.
	* \return a string.
	*/
	static std::string MakeLower(const std::string& str);

	/*! \fn std::string MakeUpper(const std::string& str)
	* \brief 转换成大写字符
	* \param [in] str a string.
	* \return a string.
	*/
	static std::string MakeUpper(const std::string& str);


	/*! \fn int ToInt(const std::string& str)
	* \brief 转换正数
	* \param [in] str a string.
	* \return a int.
	*/
	static int ToInt(const std::string& str);

	/*! \fn double ToDouble(const std::string& str)
	* \brief 转换成Double
	* \param [in] str a string.
	* \return a double.
	*/
	static double ToDouble(const std::string& str);

	/*! \fn bool ToBool(const std::string& str)
	* \brief 转换成bool
	* \param [in] str a string.
	* \return a bool.
	*/
	static bool ToBool(const std::string& str);


	/*! \fn std::string GetFileExt(const std::string &strFileName)
	* \brief 返回文件扩展名
	* \param strFileName a string.
	* \return a string.
	*/
	static std::string GetFileExt(const std::string &strFileName);

	/*! \fn std::string GetFileName(const std::string &strPathName)
	* \brief 返回文件名
	* \param strPathName a string.
	* \return a string.
	*/
	static std::string GetFileName(const std::string &strPathName);

	/*! \fn std::vector<std::string> Split(const std::string& SeparatorList)
	* \brief 分割字符串
	*/
	static std::vector<std::string> SplitString(const std::string & str, const std::string& SeparatorList);

	/*! \fn std::string JoinString(const std::vector<std::string>& StringList, const std::string& Separator)
	* \brief 连接字符串
	*/
	static std::string JoinString(const std::vector<std::string>& StringList, const std::string& Separator);

};


#endif