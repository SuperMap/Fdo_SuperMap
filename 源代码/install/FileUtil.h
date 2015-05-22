#pragma once

class FileUtil
{
public:
	FileUtil(void);
	virtual ~FileUtil(void);

	enum PartType
	{
		DRIVE,
		DIR,
		FNAME,
		EXT
	};

public:
	static BOOL FileExists(CString strFile);

	static CString GetParentDir(CString strPath);
	static BOOL FolderExists(CString strPath);

/*  GetFullPath
	static char absFilename[3*MAX_PATH+1];
	::GetFullPathName((pFilename, 3*MAX_PATH, absFilename, NULL);
	return absFilename;
*/
	static BOOL SuperMkDir(CString strPath);

	static CString GetPartContent(CString strPathName, PartType nPartType);

	/// \brief
    /// Delete the specified file.
    /// 
    /// \param path 
    /// The file to delete.
    /// 
    /// \return
    /// Returns true if the file was deleted and false
    /// otherwise.
    /// 
    static BOOL Delete (const TCHAR* fileName, bool force = false);

    /// \brief
    /// Move (rename) the specified file.
    /// 
    /// \remarks
    /// If a file exists with the new name specified, then it is overwritten.
    /// 
    /// \param oldFileName 
    /// The original file name.
    /// \param newFileName 
    /// The new file name.
    /// 
    /// \return
    /// Returns true if the file was renamed and false
    /// otherwise.
    /// 
    static BOOL Move (const TCHAR* oldFileName, const TCHAR* newFileName);

};
