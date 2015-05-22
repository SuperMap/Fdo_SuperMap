/*
 * 
* Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
* 
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <share.h>
#include <io.h>
#else
#include <wchar.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#endif
#include "FdoCommonFile.h"
#include "FdoCommonStringUtil.h"

#ifdef _WIN32
const int FdoCommonFile::PATH_SIZE = MAX_PATH;
#else // _WIN32
const int FdoCommonFile::PATH_SIZE = PATH_MAX;
#endif // _WIN32

FdoCommonFile::FdoCommonFile () :
    m_handle (INVALID_MONIKER),
    m_FilePath (NULL),
    m_readOnly (false),
    m_newFile (false),
    m_tempFile (false)
{
}

FdoCommonFile::~FdoCommonFile ()
{
    CloseFile ();

    if (NULL != m_FilePath)
    {
        // delete temporary file
        if (IsTemporaryFile ())
            FdoCommonFile::Delete (m_FilePath);

        delete [] m_FilePath;
        m_FilePath = NULL;
    }
}

bool FdoCommonFile::OpenFile (const wchar_t* filePath, OpenFlags openFlags, ErrorCode& status)
{
    bool ret;

    // close any open file
    CloseFile ();

    // set read-only flag as appropriate
    m_readOnly = 0 != (openFlags & IDF_OPEN_READ);

    // determine if the this is a new file (if opening for read only
    // then safe to assume that it is not)
    if ((openFlags & IDF_OPEN_UPDATE) || (openFlags & IDF_CREATE_ALWAYS))
        m_newFile = !FileExists (filePath) || (openFlags & IDF_CREATE_ALWAYS);
    else
        m_newFile = false;

    // open the file using the specified open/creation flags
#ifdef _WIN32

    // attempt to open the file in the appropriate mode
    if (IDF_OPEN_READ & openFlags)
        m_handle = ::CreateFile (filePath, GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,
            OPEN_EXISTING, FILE_ATTRIBUTE_READONLY | FILE_FLAG_RANDOM_ACCESS, NULL);

    else if ((openFlags & IDF_OPEN_UPDATE) || (openFlags & IDF_CREATE_ALWAYS))
    {
        // setup ::CreateFile() parameters
        DWORD accessFlags = GENERIC_READ | GENERIC_WRITE;
        DWORD fileFlags = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS;
        DWORD createFlags;

        if (openFlags & IDF_CREATE_NEW)
            createFlags = CREATE_NEW;
        else if (openFlags & IDF_CREATE_ALWAYS)
            createFlags = CREATE_ALWAYS;
        else if (openFlags & IDF_OPEN_ALWAYS)
            createFlags = OPEN_ALWAYS;       
        else 
            createFlags = OPEN_EXISTING;

        // attempt to open the file
        m_handle = ::CreateFile (filePath, accessFlags, FILE_SHARE_READ, NULL, createFlags,
            fileFlags, NULL);

        // clear warning about the file already existing if necessary - this
        // warning flag gets set if the file already exists, and the CREATE_
        // ALWAYS or OPEN_ALWAYS flags were passed to ::CreateFile()
        if (INVALID_MONIKER != m_handle)
        {
            DWORD err = GetLastError ();
            if (ERROR_ALREADY_EXISTS == err)
                ::SetLastError (ERROR_SUCCESS);
        }
    }
    if (INVALID_MONIKER == m_handle)
    {
        DWORD lastError = ::GetLastError();
        switch (lastError)
        {
            case ERROR_FILE_NOT_FOUND:
                status = FILE_NOT_FOUND;
                break;
            case ERROR_PATH_NOT_FOUND:
                status = PATH_NOT_FOUND;
                break;
            case ERROR_TOO_MANY_OPEN_FILES:
                status = TOO_MANY_OPEN_FILES;
                break;
            case ERROR_ACCESS_DENIED:
                status = ACCESS_DENIED;
                break;
            case ERROR_WRITE_PROTECT:
                status = READ_ONLY;
                break;
            case ERROR_SHARING_VIOLATION: //The process cannot access the file because it is being used by another process. 
                status = ACCESS_DENIED;
                break;
			case ERROR_ALREADY_EXISTS:
				status = FILE_EXISTS;
				break;
            default:
                status = FAILED_TO_OPEN_FILE;
                break;
        }
    }
    else
        status = ERROR_NONE;

#else // _WIN32

    int flags;
    char* file;
    mode_t mode;

    flags = 0;
    mode = 0;
    if (m_readOnly)
        flags = O_RDONLY;
    else
        flags = O_RDWR;
    if (openFlags & IDF_CREATE_NEW)
    {
        flags |= (O_CREAT | O_EXCL);
        mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
    }
    else if (openFlags & IDF_CREATE_ALWAYS)
    {
        flags |= (O_CREAT | O_TRUNC);
        mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
    }
    else if ((openFlags & IDF_OPEN_ALWAYS) && m_newFile)
    {
        flags |= O_CREAT;
        mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
    }
    else if ((openFlags & IDF_OPEN_EXISTING) && m_newFile)
        return false;

    conv_wide_to_utf8 (file, filePath);
    m_handle = open (file, flags, mode);

    if (INVALID_MONIKER == m_handle)
    {
        switch (errno)
        {
            case ENOENT:
                status = FILE_NOT_FOUND;
                break;
            case ENFILE:
                status = TOO_MANY_OPEN_FILES;
                break;
            case EACCES:
                status = ACCESS_DENIED;
                break;
            case ENOTDIR:
                status = PATH_NOT_FOUND;
                break;
            default:
                status = FAILED_TO_OPEN_FILE;
                break;
        }
    }
    else
        status = ERROR_NONE;

#endif // _WIN32

    if (INVALID_MONIKER == m_handle)
        ret = false;
    else
    {
		if (NULL == m_FilePath) 
		{
			// allocate space for the pathname and make a copy of it
			m_FilePath = new wchar_t[::wcslen (filePath) + 1];
			::wcscpy ((wchar_t*)m_FilePath, filePath);
		}

        // file opened successfully, and initialization is complete
        ret = true;
    }

    return (ret);
}

wchar_t* FdoCommonFile::OpenFlagsToString (OpenFlags flags)
{
    wchar_t* ret;

    // big enough for "IDF_OPEN_READ|IDF_OPEN_UPDATE|IDF_CREATE_NEW|IDF_CREATE_ALWAYS|IDF_OPEN_ALWAYS|IDF_OPEN_EXISTING"
    ret = new wchar_t[100];
    ret[0] = L'\0';
    if (0 != (flags & IDF_OPEN_READ))
        wcscat (ret, L"IDF_OPEN_READ");
    if (0 != (flags & IDF_OPEN_UPDATE))
    {
        if (0 != ret[0])
            wcscat (ret, L"|");
        wcscat (ret, L"IDF_OPEN_UPDATE");
    }
    if (0 != (flags & IDF_CREATE_NEW))
    {
        if (0 != ret[0])
            wcscat (ret, L"|");
        wcscat (ret, L"IDF_CREATE_NEW");
    }
    if (0 != (flags & IDF_CREATE_ALWAYS))
    {
        if (0 != ret[0])
            wcscat (ret, L"|");
        wcscat (ret, L"IDF_CREATE_ALWAYS");
    }
    if (0 != (flags & IDF_OPEN_EXISTING))
    {
        if (0 != ret[0])
            wcscat (ret, L"|");
        wcscat (ret, L"IDF_OPEN_EXISTING");
    }

    return (ret);
}

FdoException* FdoCommonFile::ErrorCodeToException (ErrorCode status, const wchar_t* filePath, OpenFlags flags)
{
    wchar_t* open_flags;
    FdoString* message;
    FdoException* ret;

    open_flags = OpenFlagsToString (flags);
    switch (status)
    {
        case ERROR_NONE:
            return (NULL);
            break;
        case FILE_NOT_FOUND:
            // The file '%1$ls' was not found.
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_91_FILE_NOT_FOUND), filePath);
            break;
        case PATH_NOT_FOUND:
            // The path to file '%1$ls' was not found.
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_92_PATH_NOT_FOUND), filePath);
            break;
        case TOO_MANY_OPEN_FILES:
            // Already too many open files when opening file '%1$ls'.
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_93_TOO_MANY_OPEN_FILES), filePath);
            break;
        case ACCESS_DENIED:
            // Access to file '%1$ls' was denied.
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_94_ACCESS_DENIED), filePath);
            break;
        case READ_ONLY:
            // Location for file '%1$ls' is read-only.
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_96_READ_ONLY), filePath);
            break;
        case FILE_EXISTS:
            // File already exists
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_18_FILEOPENFAILURE), filePath, open_flags);
            break;
        case FAILED_TO_OPEN_FILE:
        default:
            // Failed to open file '%1$ls' with access modes: '%2$ls'.
            message = FdoException::NLSGetMessage (FDO_NLSID(FDO_18_FILEOPENFAILURE), filePath, open_flags);
            break;
    }
    delete[] open_flags;
    ret = FdoException::Create (message);

    return (ret);
}

bool FdoCommonFile::CloseFile ()
{
    bool ret;

    if (INVALID_MONIKER != m_handle)
    {
#ifdef _WIN32
        ret = 0 != ::CloseHandle (m_handle);
#else // _WIN32
        ret = 0 == close (m_handle);
#endif // _WIN32
        m_handle = INVALID_MONIKER;
    }
    else
        ret = false;

	m_readOnly = true;

    return (ret);
}

bool FdoCommonFile::ReadFile (void *buffer, long nBytesToRead, long* nBytesRead) 
    const
{
    bool ret;

#ifdef _WIN32
    DWORD bytes = 0;
    ret = (0 != ::ReadFile (m_handle, buffer, nBytesToRead, &bytes, NULL));
    // use GetLastError()?
#else // _WIN32
    ssize_t bytes = 0;
    ret = (-1 != (bytes = read (m_handle, buffer, nBytesToRead)));
    // use errno?
#endif // _WIN32

    if (NULL != nBytesRead)
        *nBytesRead = bytes;
    else if ((long)bytes < nBytesToRead)
        ret = false;  // User expects more bytes than we managed to read, and no way of knowing they didn't get all the bytes, so fail

    return (ret);
}

bool FdoCommonFile::WriteFile (void *buffer, long nBytesToWrite)
    const
{
#ifdef _WIN32
    DWORD nBytesWritten;
    bool bWritten = 0 != ::WriteFile (m_handle, buffer, nBytesToWrite, 
        &nBytesWritten, NULL);
    return (bWritten && (nBytesWritten == (DWORD)(nBytesToWrite)));
#else // _WIN32
    ssize_t bytes;

    bytes = write (m_handle, buffer, nBytesToWrite);
    return (-1 != bytes);
#endif // _WIN32
}

bool FdoCommonFile::SetFilePointer (long offset, FilePos moveMethod) const
{ 
#ifdef _WIN32
    return (INVALID_SET_FILE_POINTER != ::SetFilePointer (m_handle, offset, NULL, moveMethod));
#else
    return (-1L != lseek (m_handle, offset, moveMethod));
#endif

}

bool FdoCommonFile::SetFilePointer64 (FdoInt64 offset, FilePos moveMethod) const
{ 
	unsigned long LowPart = (unsigned long) offset;
	long		  HighPart = (long) (offset >> 32 );
	bool		  ret;

#ifdef _WIN32

	LowPart = ::SetFilePointer (m_handle, LowPart, &HighPart, moveMethod);

	ret = !(LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR);
#else
/*  _llseek() could not be found in the current Linux instalation. Use 32 bits variant instead. 

    loff_t	result;
	int		status;

    status = _llseek (m_handle, HighPart, LowPart, &result, SEEK_CUR);
	ret = (status == 0 && (result == offset));
*/
	ret = SetFilePointer (LowPart, moveMethod);

#endif

	return (ret);
}

bool FdoCommonFile::GetFilePointer (unsigned long &filePointer) 
    const
{
    bool ret;

    // Get the file pointer
#ifdef _WIN32
    LONG high = 0L;
    filePointer = ::SetFilePointer (m_handle, 0, &high, FILE_CURRENT);
    ret = INVALID_SET_FILE_POINTER != filePointer;
    if (!ret)
        ret = NO_ERROR == GetLastError ();
    if (0L != high)
        ret = false;
#else
    off_t offset;
    offset = lseek (m_handle, 0, SEEK_CUR);
    ret = (off_t)-1 != offset;
    if (offset > ULONG_MAX)
        ret = false;
    else
        filePointer = (unsigned long)offset;
#endif

    return (ret);
}

bool FdoCommonFile::GetFilePointer64 (FdoInt64 &filePointer) 
    const
{
    bool ret;

#ifdef _WIN32

	unsigned long LowPart = 0L;
	long HighPart = 0;

	LowPart = ::SetFilePointer (m_handle, 0, &HighPart, FILE_CURRENT);

	filePointer = (FdoInt64) HighPart;
	filePointer = (filePointer << 32) | LowPart;

	ret = !(LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR);
	
#else
/*  _llseek() could not be found in the current Linux instalation. Use 32 bits variant instead.

    loff_t	result;
	int		status;

    status = _llseek (m_handle, 0, 0, &result, SEEK_CUR);
    filePointer = (FdoInt64)result;
	ret = (status == 0);
*/
	unsigned long LowPart = 0L;
	ret = GetFilePointer (LowPart);

	filePointer = LowPart;

#endif

    return (ret);
}

bool FdoCommonFile::GetFileSize (unsigned long &fileSize) const
{
    bool ret;

#ifdef _WIN32
    DWORD high = 0L;
    fileSize = ::GetFileSize (m_handle, &high);
    ret = INVALID_FILE_SIZE != fileSize;
    if (!ret)
        ret = NO_ERROR == GetLastError ();
    if (0L != high)
        ret = false;
#else // _WIN32
    unsigned long original;
    if (GetFilePointer (original))
    {
        fileSize = lseek (m_handle, 0, SEEK_END);
        if (-1L == fileSize)
            ret = false;
        else
            ret = true;
        ret = SetFilePointer (original, FILE_POS_BEGIN) && ret;
    }
    else
        ret = false;
#endif // _WIN32

    return (ret);
}

bool FdoCommonFile::GetFileSize64 (FdoInt64 &fileSize) const
{
    bool ret = false;

#ifdef _WIN32
    LARGE_INTEGER li;

    ret = ( ::GetFileSizeEx (m_handle, &li) != 0 );

	fileSize = li.QuadPart;

#else // _WIN32
/*  _llseek() could not be found in the current Linux instalation. Use 32 bits variant instead.
    FdoInt64	original;
	loff_t		result;
	int			status;

    if (GetFilePointer64 (original))
    {
		status = _llseek (m_handle, 0, 0, &result, SEEK_END);
		fileSize = (FdoInt64)result;

        ret = SetFilePointer64 (original, FILE_POS_BEGIN) && (status == 0);
    }
*/
	unsigned long uFileSize;
	ret = GetFileSize( uFileSize );
	fileSize = ret ? (FdoInt64)uFileSize : -1; 

#endif // _WIN32

    return (ret);
}

bool FdoCommonFile::SetFileSize (unsigned long fileSize) const
{
    bool ret;

    if (SetFilePointer (fileSize, FILE_POS_BEGIN))
#ifdef _WIN32
        ret = 0 != ::SetEndOfFile (m_handle);
#else // _WIN32
        ret = 0 == ftruncate (m_handle, fileSize);
#endif // _WIN32
    else
        ret = false;

    return (ret);

}

bool FdoCommonFile::SetFileSize64 (FdoInt64 fileSize) const
{
    bool ret = false;

    if ( SetFilePointer64 (fileSize, FILE_POS_BEGIN) ) 
	{
#ifdef _WIN32
        ret = 0 != ::SetEndOfFile (m_handle);
#else // _WIN32
		// TODO: apparently there is no ftruncate() 64 bits flavour.
		if ( fileSize <= ULONG_MAX )
			ret = 0 == ftruncate (m_handle, (off_t)fileSize);
#endif // _WIN32
	}

    return (ret);
}

FdoException* FdoCommonFile::LastErrorToException (wchar_t* context)
{
    FdoException* ret;

#ifdef _WIN32

    DWORD error;
    wchar_t* message;
    
    error = GetLastError ();
    if (error != ERROR_SUCCESS)
    {
        FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&message, 0, NULL);
        // File '%1$ls' I/O error in context '%2$ls': %3$ls
        ret = FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID(FDO_95_FILE_IO_ERROR), FileName (), context, message));
        LocalFree (message);
    }
    else
        ret = NULL;

#else // _WIN32

    char message[2048];
    wchar_t* msg;

    if (0 != errno)
    {
        strerror_r (errno, message, sizeof (message));
        multibyte_to_wide (msg, message);
        // File '%1$s' I/O error in context '%2$s': %3$s
        ret = FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID(FDO_95_FILE_IO_ERROR), FileName (), context, message));
    }
    else
        ret = NULL;
#endif // _WIN32

    return (ret);
}

bool FdoCommonFile::FileExists (const wchar_t* filePath)
{
    bool ret;

#ifdef _WIN32
    size_t length = wcslen (filePath);
    wchar_t* path = (wchar_t*)alloca (sizeof (wchar_t) * (length + 3)); // in case we need to add a \*
    wcscpy (path, filePath);
    if (0 < length)
    {
        // trim off trailing slash
        if (FILE_PATH_DELIMITER == path[length - 1])
            path[--length] = L'\0';
        else if (FILE_PATH_DELIMITER2 == path[length - 1])
            path[--length] = L'\0';
    }
    if ((1 < length) && (L':' == path[length - 1]))
        wcscat (path, L"\\*");
    WIN32_FIND_DATA findData;
    HANDLE findHandle = ::FindFirstFile (path, &findData);
    if (INVALID_HANDLE_VALUE != findHandle)
    {
        ::FindClose (findHandle);
        ret = true;
    }
    else
        ret = false;

#else // _WIN32

    char* file;
    int f;

    conv_wide_to_utf8 (file, filePath);
    size_t length = strlen (file);
    if (FILE_PATH_DELIMITER2 == file[length - 1])
        file[length - 1] = FILE_PATH_DELIMITER;
    f = open (file, O_RDONLY, 0);
    ret = (-1 != f);
    if (ret)
        close (f);
#endif

    return (ret);
}

bool FdoCommonFile::IsDirectory (const wchar_t* name)
{
    size_t length;
    wchar_t* _name;

    length = wcslen (name);
    _name = (wchar_t*)alloca (sizeof (wchar_t) * (length + 1));
    wcscpy (_name, name);
    if (1 <= length)
    {
        if (_name[length - 1] == FILE_PATH_DELIMITER)
            _name[length - 1] = '\0';
        else if (_name[length - 1] == FILE_PATH_DELIMITER2)
            _name[length - 1] = '\0';
    }

#ifdef _WIN32
    struct _stat statInfo;
    // Root directory is a special case that _stat() doesn't understand, so handle it differently:
    if (FileExists(name) && (wcslen(name) > 1) && ((name[wcslen(name)-1]==L':') || (name[wcslen(name)-2]==L':')))
        return true;
    else
        return (0==_wstat (_name, &statInfo)) ? (statInfo.st_mode & _S_IFDIR) > 0 : false;
#else // _WIN32
    struct stat statInfo;
    char *mbName;

    conv_wide_to_utf8 (mbName, _name);
    return (0==stat(mbName, &statInfo)) ? (statInfo.st_mode & S_IFDIR) > 0 : false;
#endif // _WIN32
}


bool FdoCommonFile::Delete (const wchar_t* fileName, bool force)
{
    bool ret;
#ifdef _WIN32

    ret = 0 != ::DeleteFile (fileName);

	// Make the file writable if required
	if ( !ret && force ) {
        DWORD accessFlags = GENERIC_READ | GENERIC_WRITE;
        DWORD fileFlags = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS;
        DWORD createFlags = OPEN_EXISTING;

		::CreateFile (fileName, accessFlags, FILE_SHARE_READ, NULL, createFlags, fileFlags, NULL);

	    ret = 0 != ::DeleteFile (fileName);
	}

#else // _WIN32
    char* file;
    conv_wide_to_utf8 (file, fileName);
    ret = 0 == unlink (file);

#endif // _WIN32

    return (ret);
}


bool FdoCommonFile::Move (const wchar_t* oldFileName, const wchar_t* newFileName)
{
    bool ret;

#ifdef _WIN32
    // try using ::MoveFileEx() since it is the safest way to move a file

    DWORD moveFlags = MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED;
    ret = 0 != ::MoveFileEx (oldFileName, newFileName, moveFlags);
 
    // if the move failed because the ::MoveFileEx() call is not supported
    // (this is the case under Windows 95), then do a delete-file followed
    // by a move-file

    if (!ret && (ERROR_CALL_NOT_IMPLEMENTED == ::GetLastError ()))
        if (!FileExists (newFileName) || Delete (newFileName))
            ret = 0 != ::MoveFile (oldFileName, newFileName);

#else // _WIN32
    char* oldpath;
    char* newpath;
    conv_wide_to_utf8 (oldpath, oldFileName);
    conv_wide_to_utf8 (newpath, newFileName);
    int rename_result = rename (oldpath, newpath);

    // If we failed to do a simple rename operation (for whatever reasons),
    // attempt to do Copy/Delete operations instead:
    if (-1 == rename_result)
    {
        ret = Copy(oldFileName, newFileName);
        if (ret)
        {
            ret = Delete(oldFileName);
            if (!ret)
            {
                // OK failed to delete original "old" file, revert back to original state of affairs and fail:
                bool bDummy = Delete(newFileName);
                ret = false;
            }
        }
    }
    else
        ret = (0 == rename_result);
#endif // _WIN32

    return (ret);
}



bool FdoCommonFile::Copy (const wchar_t* oldFileName, const wchar_t* newFileName)
{
    FdoCommonFile oldFile;
    FdoCommonFile newFile;
    ErrorCode err;
    bool ret, bDummy;
    char buff[4096];
    long bytesRead;

    ret = oldFile.OpenFile(oldFileName, IDF_OPEN_READ, err);
    if (ret)
    {
        ret = newFile.OpenFile(newFileName, IDF_CREATE_ALWAYS, err);
        if (ret)
        {
            while (oldFile.ReadFile(buff, sizeof(buff), &bytesRead) && (bytesRead > 0))
            {
                ret = newFile.WriteFile(buff, bytesRead);
            }

            bDummy = oldFile.CloseFile();
            bDummy = newFile.CloseFile();
        }
    }

    return ret;
}



bool FdoCommonFile::GetTempFile (wchar_t** name, const wchar_t* path)
{
    bool ret;

#ifdef _WIN32

    wchar_t tempPath[MAX_PATH + 1];
    wchar_t tempName[MAX_PATH + 1];

    if ((NULL == path) || (0==wcslen(path)))
        ret = 0 != ::GetTempPath (MAX_PATH, tempPath);
    else
    {
        wcscpy (tempPath, path);
        ret = true;
    }
    if (ret)
        ret = 0 != ::GetTempFileName (tempPath, L"IDF", 0, tempName);
    if (ret)
        // on Windows the file is actually created by GetTempFileName
        FdoCommonFile::Delete (tempName);

#else // _WIN32

    char* mbPath;
    char* generated;
    wchar_t* tempName;
    
    // even though the man pages say explicitly don't use this function...
    mbPath = NULL;
    if (NULL != path)
        conv_wide_to_utf8 (mbPath, path);
    generated = tempnam (mbPath, "idf");
    if (NULL == generated)
        ret = false;
    else
    {
        try
        {
           conv_utf8_to_wide (tempName, generated);
        }
        catch (FdoException* exception)
        {
          free (generated);
          throw exception;
        }
        free (generated);
        ret = true;
    }

#endif // _WIN32

    if (ret)
    {
        // allocate space for the pathname and make a copy of it
        *name = new wchar_t[::wcslen (tempName) + 1];
        ::wcscpy (*name, tempName);
    }

    return (ret);
}

#ifdef _WIN32
#include <io.h>
void FdoCommonFile::GetAllFiles (const wchar_t* path, std::vector<std::wstring>& files)
{
    size_t length;
    wchar_t* pattern;
    struct _wfinddata_t file;
    intptr_t handle;

    length = wcslen (path);
    pattern = (wchar_t*)alloca (sizeof (wchar_t) * (length + 3));
    wcscpy (pattern, path);
    if (0 < length)
    {
        // add trailing slash if necessary
        if (FILE_PATH_DELIMITER != pattern[length - 1])
            wcscat (pattern, L"\\");
    }
    wcscat (pattern, L"*");
    if (-1L != (handle = _wfindfirst (pattern, &file )))
    {
        do 
            if (0 != file.size)
                files.push_back (file.name);
        while (0 == _wfindnext (handle, &file));
        _findclose (handle);
    }
}
#else // for linux
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <dirent.h>
void append_file (std::vector<std::wstring>& files, char* name)
{
    wchar_t* _name;

    conv_utf8_to_wide (_name, name);
    files.push_back (_name);
}
void FdoCommonFile::GetAllFiles (const wchar_t* path, std::vector<std::wstring>& files)
{
    char* _path;
    struct dirent* dptr;
    DIR* dirp;

    // note: there is no standard wide equivalent of opendir etc.
    // Symbian wopendir
    // Samba wsys_opendir
    // mingw,Watcom _wopendir
    conv_wide_to_utf8 (_path, path);
    if (NULL != (dirp = opendir(_path)))
    {
        while (NULL != (dptr = readdir (dirp)))
            append_file (files, dptr->d_name);
        closedir (dirp);
    }
}
#endif

bool FdoCommonFile::MkDir (const wchar_t* path)
{
#ifdef _WIN32
    return (0 != CreateDirectory (path, NULL));
#else
    char* _path;

    conv_wide_to_utf8 (_path, path);
    return (0 == mkdir (_path, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP));
#endif
}

bool FdoCommonFile::RmDir (const wchar_t* path)
{
#ifdef _WIN32
    return (0 != RemoveDirectory (path));
#else
    char* _path;

    conv_wide_to_utf8 (_path, path);
    return (0 == rmdir (_path));
#endif
}


void FdoCommonFile::DelimitPath(FdoStringP &path)
{
    // Build a one-character-long delimiter wide string:
    wchar_t delimiterString[2];
    delimiterString[0] = FILE_PATH_DELIMITER;
    delimiterString[1] = L'\0';

    // add the delimiter if not already present:
    size_t length = path.GetLength ();
    if (0 == length)
        path = delimiterString;
    else
    {
        wchar_t actualDelimiter = *((const wchar_t*)path + length - 1);
        if (FILE_PATH_DELIMITER2 == actualDelimiter)
        {
            path = path.Mid (0, length - 1);
            length--;
            if (0 == length)
            {
                path = delimiterString;
                length = 1;
            }
            actualDelimiter = *((const wchar_t*)path + length - 1);
        }
        if (FILE_PATH_DELIMITER != actualDelimiter)
            path += delimiterString;
    }
}

#ifndef _WIN32
char* FdoCommonFile::get_fulpath_folder (const char* foldername, char* destval)
{
	char cwd[3*FdoCommonFile::PATH_SIZE+1];
	if (!getcwd (cwd, 3*FdoCommonFile::PATH_SIZE+1) || chdir (foldername) )
		return NULL;

	if (!getcwd (destval, 3*FdoCommonFile::PATH_SIZE+1) )
		destval = NULL;

	chdir(cwd);
	return destval;
}
#endif
const wchar_t* FdoCommonFile::GetAbsolutePath(const wchar_t *pFilename)
{
	static wchar_t absFilename[3*FdoCommonFile::PATH_SIZE+1];
#ifdef _WIN32
	::GetFullPathNameW (pFilename, 3*FdoCommonFile::PATH_SIZE, absFilename, NULL);
	return absFilename;
#else
    struct stat statInfo;
    char *mbName;
	char destfolder[3*FdoCommonFile::PATH_SIZE+1];
    conv_wide_to_utf8 (mbName, pFilename);
    if(0 != stat (mbName, &statInfo))
		return pFilename;
	if(statInfo.st_mode & S_IFDIR)
	{ // it's a folder
		if (get_fulpath_folder(mbName, destfolder) != NULL)
		{
			wchar_t* _name;
			conv_utf8_to_wide (_name, destfolder);
			wcscpy (absFilename, _name);
			size_t length = wcslen (absFilename);
			if (absFilename[length] != FILE_PATH_DELIMITER)
			{
				absFilename[length] = FILE_PATH_DELIMITER;
				absFilename[length+1] = L'\0';
			}

			return absFilename;
		}
	}
	else
	{ // it's a file
		size_t length = wcslen (pFilename);
		const wchar_t* filePathtmp = pFilename + length;
		while (filePathtmp-- != pFilename && *filePathtmp != FILE_PATH_DELIMITER && *filePathtmp != FILE_PATH_DELIMITER2);
		wcscpy (absFilename, pFilename);
		absFilename[filePathtmp-pFilename] = L'\0';

		if(filePathtmp != pFilename)
		{
			conv_wide_to_utf8 (mbName, absFilename);
			if (get_fulpath_folder(mbName, destfolder) != NULL)
			{
				wchar_t* _name;
				conv_utf8_to_wide (_name, destfolder);
				wcscpy(absFilename, _name);
				size_t length = wcslen (absFilename);

				if (absFilename[length] != FILE_PATH_DELIMITER)
					wcscpy (absFilename+length, filePathtmp);
				else
					wcscpy (absFilename+length, filePathtmp+1);

				return absFilename;
			}
		}
	}
	return pFilename;
#endif
}

const wchar_t* FdoCommonFile::GetRelativePath(const wchar_t *currentDirectory, const wchar_t *absoluteFilename)
{
	size_t afMarker = 0, rfMarker = 0;
	size_t cdLen = 0, afLen = 0;
	size_t i = 0;
	size_t levels = 0;
	static wchar_t relativeFilename[FdoCommonFile::PATH_SIZE+1];

	cdLen = wcslen (currentDirectory);
	afLen = wcslen (absoluteFilename);
	if (cdLen > FdoCommonFile::PATH_SIZE || cdLen < ABSOLUTE_NAME_START+1 || afLen > FdoCommonFile::PATH_SIZE || afLen < ABSOLUTE_NAME_START+1 ||
		!IsAbsolutePath (currentDirectory) || !IsAbsolutePath (absoluteFilename) || currentDirectory[0] != absoluteFilename[0])
		return absoluteFilename;

	i = ABSOLUTE_NAME_START;
	if (absoluteFilename[0] == FILE_PATH_DELIMITER && absoluteFilename[0] == absoluteFilename[1])
	{
		i = 2;
		while (i < afLen && i < cdLen && currentDirectory[i] == absoluteFilename[i] && currentDirectory[i] != FILE_PATH_DELIMITER) i++;
		if (currentDirectory[i] != FILE_PATH_DELIMITER) // different remote paths win only
			return absoluteFilename;
	}
	while (i < afLen && i < cdLen && currentDirectory[i] == absoluteFilename[i]) i++;

	if (i == cdLen && (absoluteFilename[i] == FILE_PATH_DELIMITER || absoluteFilename[i-1] == FILE_PATH_DELIMITER))
	{
		if (absoluteFilename[i] == FILE_PATH_DELIMITER)
			i++;
		wcscpy (relativeFilename, &absoluteFilename[i]);
		return relativeFilename;
	}

	afMarker = i;
	levels = 1;
	while (i < cdLen)
	{
		i++;
		if (currentDirectory[i] == FILE_PATH_DELIMITER)
		{
			i++;
			if (currentDirectory[i] != L'\0')
				levels++;
		}
	}

	while (afMarker > 0 && absoluteFilename[afMarker-1] != FILE_PATH_DELIMITER) afMarker--;

	if (levels * 3 + afLen - afMarker > FdoCommonFile::PATH_SIZE)
		return NULL;

	// add the appropriate number of "..\"s.
	rfMarker = 0;
	for (i = 0; i < levels; i++)
	{
		relativeFilename[rfMarker++] = L'.';
		relativeFilename[rfMarker++] = L'.';
		relativeFilename[rfMarker++] = FILE_PATH_DELIMITER;
	}

	wcscpy (&relativeFilename[rfMarker], &absoluteFilename[afMarker]);
	return relativeFilename;
}

bool FdoCommonFile::IsAbsolutePath(const wchar_t *pFilename)
{
	if(pFilename == NULL || wcslen(pFilename) == 0)
		return false;
#ifdef _WIN32
	return (pFilename[1] == L':' && pFilename[2] == FILE_PATH_DELIMITER) |
		(pFilename[0] == FILE_PATH_DELIMITER && pFilename[1] == FILE_PATH_DELIMITER);
#else
	return (pFilename[0] == FILE_PATH_DELIMITER);
#endif
}

bool FdoCommonFile::GetFileDirectoryAndName(const wchar_t *location, FdoStringP& directory, FdoStringP& filename)
{
#ifndef _WIN32
    struct stat my_stat;
    char* mbLocation = NULL;
    wide_to_multibyte(mbLocation, location);
    if (0 != stat (mbLocation, &my_stat))
        return false;
#else
    DWORD attributes = GetFileAttributesW (location);
    if ((INVALID_FILE_ATTRIBUTES == attributes))
        return false;
#endif

    // Extract the file name and path from location. There are two kinds of delimiters, 
    // The last one appears would be selected to extract the file name.
    // e.g. location1="c:\\path1/test.bmp", index would be set at "/".
    const wchar_t* pdest = wcsrchr(location, FILE_PATH_DELIMITER); // L'\\'
    const wchar_t* pdest2 = wcsrchr(location, FILE_PATH_DELIMITER2); // L'/'

    int index = (int)(pdest - location);
    int index2 = (int)(pdest2 - location);

    if (index2 > index) {
        index = index2;
        pdest = pdest2;
    }

    // extract the filename
    if (pdest) {
        size_t len = wcslen(pdest + 1) + 1;
        wchar_t *lfilename = new wchar_t[len];
#ifdef _WIN32            
        wcscpy_s(lfilename, len, pdest + 1);
#else
        wcscpy(lfilename, pdest + 1);
#endif
        filename = lfilename;
        delete []lfilename;
    }

    // extract the directory name
    if (index) {
        size_t len = index + 1;
        wchar_t *path = new wchar_t[len];
#ifdef _WIN32            
        wcsncpy_s(path, len, location, index);
#else
        wcsncpy(path, location, index);
        path[index] = '\0';
#endif
        directory = path;
        delete []path;
    }

    return true;
}

void FdoCommonFile::Chmod(FdoString* filePath, bool bReadWrite)
{
#ifdef _WIN32
    if (-1 == _wchmod(filePath, bReadWrite ? _S_IREAD|_S_IWRITE : _S_IREAD))
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_94_ACCESS_DENIED, "Access to file '%1$ls' was denied.", filePath));
#else
    char *utf8FilePath = NULL;
    conv_wide_to_utf8(utf8FilePath , filePath);

    // Get current file access mode:
    struct stat fileStat;
    if (-1 == stat(utf8FilePath, &fileStat))
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_94_ACCESS_DENIED, "Access to file '%1$ls' was denied.", filePath));

    // Set file access mode:
    mode_t mode = (fileStat.st_mode & (S_IRWXO|S_IRWXG|S_IRUSR|S_IXUSR|S_ISUID|S_ISGID|S_ISVTX));  // strip out irrelevant bits and owner write bit
    if (bReadWrite) mode = mode | S_IWUSR;  // set owner write bit if requested
    if (-1 == chmod(utf8FilePath, mode))
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_94_ACCESS_DENIED, "Access to file '%1$ls' was denied.", filePath));

/*  stat() docs:

       S_IFMT     0170000   bitmask for the file type bitfields
       S_IFSOCK   0140000   socket
       S_IFLNK    0120000   symbolic link
       S_IFREG    0100000   regular file
       S_IFBLK    0060000   block device
       S_IFDIR    0040000   directory
       S_IFCHR    0020000   character device
       S_IFIFO    0010000   fifo
       S_ISUID    0004000   set UID bit
       S_ISGID    0002000   set GID bit (see below)
       S_ISVTX    0001000   sticky bit (see below)
       S_IRWXU    00700     mask for file owner permissions
       S_IRUSR    00400     owner has read permission
       S_IWUSR    00200     owner has write permission
       S_IXUSR    00100     owner has execute permission
       S_IRWXG    00070     mask for group permissions
       S_IRGRP    00040     group has read permission
       S_IWGRP    00020     group has write permission
       S_IXGRP    00010     group has execute permission
       S_IRWXO    00007     mask for permissions for others (not in group)
       S_IROTH    00004     others have read permission
       S_IWOTH    00002     others have write permisson
       S_IXOTH    00001     others have execute permission
*/

/* chmod() docs:
       Modes are specified by orâing the following:

          S_ISUID   04000 set user ID on execution
          S_ISGID   02000 set group ID on execution
          S_ISVTX   01000 sticky bit
          S_IRUSR (S_IREAD)
                    00400 read by owner
          S_IWUSR (S_IWRITE)
                    00200 write by owner
          S_IXUSR (S_IEXEC)
                    00100 execute/search by owner
          S_IRGRP   00040 read by group
          S_IWGRP   00020 write by group
          S_IXGRP   00010 execute/search by group
          S_IROTH   00004 read by others
          S_IWOTH   00002 write by others
          S_IXOTH   00001 execute/search by others
*/

#endif
}
