/*
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
 */

#ifndef FDO_COMMON_FILE_H
#define FDO_COMMON_FILE_H

#ifdef _WIN32
#define FILE_PATH_DELIMITER L'\\'
#define FILE_PATH_DELIMITER2 L'/'
#define ABSOLUTE_NAME_START 3
#else
#define FILE_PATH_DELIMITER L'/'
#define FILE_PATH_DELIMITER2 L'\\'
#define ABSOLUTE_NAME_START 1
#endif

#include <vector>

class FdoException;

class FdoCommonFile
{
    /// maximum path length
    static const int PATH_SIZE;

#ifdef _WIN32

    /// underlying file handle
    typedef HANDLE Moniker;
    #define INVALID_MONIKER INVALID_HANDLE_VALUE

public:

    /// relative file positions for SetFilePointer()
    typedef enum FilePos
    {
        FILE_POS_BEGIN   = FILE_BEGIN,
        FILE_POS_CURRENT = FILE_CURRENT,
        FILE_POS_END     = FILE_END
    };

#else // _WIN32

    /// underlying file handle
    typedef int Moniker;
    #define INVALID_MONIKER (-1)

public:

    /// relative file positions for SetFilePointer()
    typedef enum FilePos
    {
        FILE_POS_BEGIN   = SEEK_SET,
        FILE_POS_CURRENT = SEEK_CUR,
        FILE_POS_END     = SEEK_END
    };

#endif // _WIN32

    /// file open/creation flags
    typedef enum OpenFlags
    {
        IDF_OPEN_READ     = 0x01,
        IDF_OPEN_UPDATE   = 0x02,
        IDF_CREATE_NEW    = 0x04,
        IDF_CREATE_ALWAYS = 0x08,
        IDF_OPEN_ALWAYS   = 0x10,
        IDF_OPEN_EXISTING = 0x20
    };

    /// error codes from OpenFile
    typedef enum ErrorCode
    {
        ERROR_NONE = 0,
        FAILED_TO_OPEN_FILE = -1,
        FILE_NOT_FOUND = -2,
        PATH_NOT_FOUND = -3,
        TOO_MANY_OPEN_FILES = -4,
        ACCESS_DENIED = -5,
        READ_ONLY = -6,
		FILE_EXISTS = -7
    };

protected:
    Moniker m_handle;           // handle of the file
    const wchar_t* m_FilePath;  // path of the file
    bool m_readOnly;            // was the file opened for reading only?
    bool m_newFile;             // is this a newly created file?
    bool m_tempFile;            // is this a temporary file?

#ifndef _WIN32
private:
	static char* get_fulpath_folder (const char* foldername, char* destval);
#endif
public:

    /// \brief
    /// Constructor.
    /// 
    /// \remarks
    /// Initialize a instance of the FdoCommonFile object. Initialization
    /// should be completed by calling the OpenFile() member function.
    /// 
    FdoCommonFile ();

    /// \brief
    /// Destructor.
    /// 
    /// \remarks
    /// Closes the file and release all dynamically allocated 
    /// resources.
    /// 
    virtual ~FdoCommonFile ();

    /// \brief
    /// Open a file.
    /// 
    /// \param path 
    /// The path of the file.
    /// \param flags 
    /// A bitwise combination of the file-open flags
    /// These flags are loosely modelled after the flags for the Win32 CreateFile() 
    /// function; the meanings of the flags are as follows:
    /// \li \c IDF_OPEN_READ - open the file for reading only.
    /// \li \c IDF_OPEN_UPDATE - create the file for update 
    /// (reading and writing).
    /// The following flags can be combined (via the bitwise 
    /// OR operator) with IDF_OPEN_UPDATE:
    /// \li \c IDF_CREATE_NEW - create a new file, failing if
    /// a file of the specified name already exists.
    /// \li \c IDF_CREATE_ALWAYS - create a new file, truncating
    /// the named file if it already exists.
    /// \li \c IDF_OPEN_ALWAYS - opens the file if it already
    /// exists, otherwise a new file is created.
    /// \li \c IDF_OPEN_EXISTING - opens the named file, 
    /// failing if it does not already exist. 
    /// \param status 
    /// Further information on the outcome of the open.
    /// 
    /// \return
    /// Returns true if the file was successfully opened, and 
    /// false otherwise.
    /// 
    virtual bool OpenFile (const wchar_t* path, OpenFlags flags, ErrorCode& status);

    /// \brief
    /// Converts the bit filed open flags into a string.
    /// 
    /// \param flags 
    /// A bitwise combination of the file-open flags.
    /// 
    /// \return
    /// Returns a string representing the bit flags. This must be deleted by the caller.
    /// 
    static wchar_t* OpenFlagsToString (OpenFlags flags);

    /// \brief
    /// Converts an error code returned by OpenFile into an exception.
    /// 
    /// \param status 
    /// Input the status returned from OpenFile.
    /// \param filePath 
    /// The file name used in the OpenFile call.
    /// \param flags 
    /// A bitwise combination of the file-open flagsused in the OpenFile call.
    /// 
    /// \return
    /// Returns an exception with an appropriate error message,
    /// or NULL if the open was successful.
    /// 
    static FdoException* ErrorCodeToException (ErrorCode status, const wchar_t* filePath, OpenFlags flags);

    /// \brief
    /// Close the file.
    /// 
    /// \return
    /// Returns true if the file was successfully closed, and 
    /// false otherwise.
    /// 
    virtual bool CloseFile();

    /// file I/O methods

    /// \brief
    /// File is open predicate.
    /// 
    /// \return
    /// Returns true if the file is open, and 
    /// false otherwise.
    /// 
    virtual bool IsOpen () const { return (INVALID_MONIKER != m_handle); }

    /// \brief
    /// File is new predicate.
    /// 
    /// \return
    /// Returns true if the file was created by open, and 
    /// false otherwise.
    /// 
    virtual bool IsNew () const { return (m_newFile); }

    /// \brief
    /// File is read-only predicate.
    /// 
    /// \return
    /// Returns true if the file is open for read only, and 
    /// false otherwise.
    /// 
    virtual bool IsReadOnly () const { return (m_readOnly); }

    /// \brief
    /// Set whether this file is temporary or not.
    /// 
    /// \return
    /// If set to true, the file will be deleted when closed.
    /// 
    void SetTemporaryFile (bool temp){ m_tempFile = temp; }

    /// \brief
    /// File is temporary predicate.
    /// 
    /// \return
    /// Returns true if the file is temporary (will be deleted on close), and 
    /// false otherwise.
    /// 
    bool IsTemporaryFile ()          { return (m_tempFile); }

    /// \brief
    /// File name accessor.
    /// 
    /// \return
    /// Returns the name of the file or NULL if the file is not open.
    /// 
    virtual const wchar_t* FileName () const { return (m_FilePath); }

    /// \brief
    /// Read from the file.
    /// 
    /// \param buffer 
    /// The memory to fill with the file contents.
    /// \param bytes 
    /// The number of bytes to read.
    /// \param read 
    /// The number of bytes actually read.
    /// 
    /// \return
    /// Returns true if all the bytes were successfully read,
    /// or if less bytes were read than requested and read!=NULL in which case
    /// read will contain the number actually read.
    /// If less bytes were read than requested and read==NULL, then false is returned.
    /// If any other problem occurs, false is returned.
    /// 
    virtual bool ReadFile (void *buffer, long bytes, long* read = NULL) const;

    /// \brief
    /// Write to the file.
    /// 
    /// \param buffer 
    /// The memory to save in the file.
    /// \param bytes 
    /// The number of bytes to write.
    /// 
    /// \return
    /// Returns true if the bytes were successfully written and false
    /// otherwise.
    /// 
    virtual bool WriteFile (void *buffer, long bytes) const;

    /// \brief
    /// Set the file pointer to the specified position.
    /// 
    /// \param offset 
    /// The number of bytes to move the file pointer.
    /// \param method 
    /// The indication where the file position should be
    /// relative to. One of the constants:
    /// \li \c FILE_POS_BEGIN - relative to the beginning of the file.
    /// \li \c FILE_POS_CUR - relative to the current location.
    /// \li \c FILE_POS_END - relative to the end of the file.
    /// 
    /// \return
    /// Returns true if the pointer was successfully set and false
    /// otherwise.
    /// 
    virtual bool SetFilePointer (long offset, FilePos method = FILE_POS_BEGIN) const;

    /// \brief
	/// Set the file pointer to the specified position (offset: max int64).
    /// 
    /// \param offset 
    /// The number of bytes to move the file pointer.
    /// \param method 
    /// The indication where the file position should be
    /// relative to. One of the constants:
    /// \li \c FILE_POS_BEGIN - relative to the beginning of the file.
    /// \li \c FILE_POS_CUR - relative to the current location.
    /// \li \c FILE_POS_END - relative to the end of the file.
    /// 
    /// \return
    /// Returns true if the pointer was successfully set and false
    /// otherwise.
    /// 
    virtual bool SetFilePointer64 (FdoInt64 offset, FilePos method = FILE_POS_BEGIN) const;

    /// \brief
    /// Get the current file pointer.
    /// 
    /// \param offset 
    /// Output, the current file pointer position.
    /// 
    /// \return
    /// Returns true if the pointer was successfully obtained and false
    /// otherwise.
    /// 
    virtual bool GetFilePointer (unsigned long &offset) const;

    /// \brief
    /// Get the current file pointer (offset: max int64).
    /// 
    /// \param offset 
    /// Output, the current file pointer position.
    /// 
    /// \return
    /// Returns true if the pointer was successfully obtained and false
    /// otherwise.
    /// 
    virtual bool GetFilePointer64 (FdoInt64 &offset) const;

    /// \brief
    /// Get the size of the file.
    /// 
    /// \param size 
    /// Output, the file size in bytes.
    /// 
    /// \return
    /// Returns true if the size was successfully obtained and false
    /// otherwise.
    /// 
    virtual bool GetFileSize (unsigned long &size) const;

    /// \brief
    /// Get the size of the file.
    /// 
    /// \param size 
    /// Output, the file size in bytes.
    /// 
    /// \return
    /// Returns true if the size was successfully obtained and false
    /// otherwise.
    /// 
    virtual bool GetFileSize64 (FdoInt64 &size) const;

    /// \brief
    /// Set the size of the file.
    /// 
    /// \remarks
    /// The file pointer is moved to the new end of file.
    /// 
    /// \param size 
    /// The new file size in bytes.
    /// 
    /// \return
    /// Returns true if the size was successfully set and false
    /// otherwise.
    /// 
    virtual bool SetFileSize(unsigned long size) const;

    /// \brief
    /// Set the size of the file.
    /// 
    /// \remarks
    /// The file pointer is moved to the new end of file.
    /// 
    /// \param size 
    /// The new file size in bytes.
    /// 
    /// \return
    /// Returns true if the size was successfully set and false
    /// otherwise.
    /// 
    virtual bool SetFileSize64 (FdoInt64 size) const;

    /// \brief
    /// Converts the last encountered error to a suitable exception.
    /// 
    /// \param context 
    /// The context in which the error occured.
    /// This is incorporated into the message.
    /// 
    /// \return
    /// Returns an exception with an appropriate error message,
    /// or NULL if the last operation completeted successfully.
    /// 
    virtual FdoException* LastErrorToException (wchar_t* context);

    /// file manipulation methods

    /// \brief
    /// Determine if the specified file exists.
    /// 
    /// \param path 
    /// The file to check existence for.
    /// 
    /// \return
    /// Returns true if the file (or directory) exists and false
    /// otherwise.
    /// 
    static bool FileExists (const wchar_t* path);

    /// \brief
    /// Determine if the specified name corresponds to a directory.
    /// 
    /// \param name 
    /// The name to verify as a directory.
    /// 
    /// \return
    /// Returns true if the specified name points to a valid directory;
    /// Returns false if the specified name points to a file or is invalid.
    /// The caller should call FileExists() beforehand to first
    /// determine that the name is valid in the current filesystem.
    /// 
    static bool IsDirectory (const wchar_t* name);

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
    static bool Delete (const wchar_t* fileName, bool force = false);

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
    static bool Move (const wchar_t* oldFileName, const wchar_t* newFileName);

    /// \brief
    /// Copy the specified file.
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
    /// Returns true if the file was copied and false
    /// otherwise.
    /// 
    static bool Copy (const wchar_t* oldFileName, const wchar_t* newFileName);

    /// \brief
    /// Get the name of a new (unique) temporary file.
    /// 
    /// \remarks
    /// The allocated name should be released with delete[].
    /// 
    /// \param name 
    /// Output, the address of a pointer to accept the name
    /// of the temporary file to.
    /// \param path 
    /// Input the path for the temporary file.
    /// 
    /// \return
    /// Returns true if the name was successfully generated and false
    /// otherwise.
    /// 
    static bool GetTempFile (wchar_t** name, const wchar_t* path = NULL);

    /// \brief
    /// Get the list of files in a directory.
    /// 
    /// \remarks
    /// The names returned in files are char* and don't have path
    /// as a prefix.
    /// 
    /// \param path 
    /// The directory to list.
    /// \param files 
    /// The list of files to fill with names.
    /// 
    static void GetAllFiles (const wchar_t* path, std::vector<std::wstring>& files);

    /// \brief
    /// Make the specified directory.
    /// 
    /// \remarks
    /// All paths up to the leaf are created if needed.
    /// 
    /// \param path 
    /// The path to create.
    /// 
    /// \return
    /// Returns true if the path was created and false
    /// otherwise.
    /// 
    static bool MkDir (const wchar_t* path);

    /// \brief
    /// Remove the specified directory.
    /// 
    /// \param path 
    /// The path to remove.
    /// 
    /// \return
    /// Returns true if the path was removed and false
    /// otherwise.
    /// 
    static bool RmDir (const wchar_t* path);

    /// \brief
    /// If the given pathname does not end in a path delimiter, concatenate the delimiter to the path .
    /// 
    /// \param path 
    /// The path to delimit.
    /// 
    /// \return
    /// N/A
    /// 
    static void DelimitPath(FdoStringP &path);

    /// \brief
    /// Transform a relative path in an absolute path.
    /// 
    /// \param path 
    /// The relative path.
    /// 
    /// \return
    /// Returns absolute path if can be transformed or passed parameter
    /// otherwise.
    /// 
	static const wchar_t* GetAbsolutePath(const wchar_t *pFilename);

    /// \brief
    /// Transform an absolute path in a relative path based on a folder.
    /// 
    /// \param path 
    /// The directory and the relative path.
    /// 
    /// \return
    /// Returns relative path if can be transformed or passed parameter
    /// otherwise.
    /// 
	static const wchar_t* GetRelativePath(const wchar_t *currentDirectory, const wchar_t *absoluteFilename);

    /// \brief
    /// Determine if the specified name corresponds to an absolute directory.
    /// 
    /// \param path 
    /// The path.
    /// 
    /// \return
    /// Returns true if the specified name points to an absolute directory and false
    /// otherwise.
    /// 
	static bool IsAbsolutePath(const wchar_t *pFilename);

    /// \brief
    /// Determines the directory and filename parts from the specified path.
    /// 
    /// \param path 
    /// The path.
    /// 
    /// \return
    /// Returns true if the specified loaction points to a directory and false
    /// otherwise.
    /// 
    static bool GetFileDirectoryAndName(const wchar_t *location, FdoStringP& directory, FdoStringP& name);

    /// \brief
    /// Changes the read-write access mode of a file.
    /// On Windows this sets/clears the read-only flag.
    /// On Linux this only sets/clears the file's owner write flag.
    /// 
    /// \param filePath 
    /// The path and filename of the file to modify.
    /// 
    /// \param bReadWrite 
    /// Set this to true for read-write access, false for read-only access.
    /// 
    static void Chmod(FdoString* filePath, bool bReadWrite);

};

#endif // FDO_COMMON_FILE_H


