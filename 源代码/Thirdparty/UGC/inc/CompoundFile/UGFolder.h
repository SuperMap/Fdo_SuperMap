// SeFolder.h: interface for the UGFolder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMSSFOLDER_H__978F73C8_E4FB_43D4_BED1_056CE71977B8__INCLUDED_)
#define AFX_SMSSFOLDER_H__978F73C8_E4FB_43D4_BED1_056CE71977B8__INCLUDED_

#include "UGFileLogical.h"

namespace UGC{

class COMPOUNDFILE_API UGFolder
{
public:
	UGFolder();
	~UGFolder();

private:
	UGFolder(const UGFolder& src);
	UGFolder& operator=(const UGFolder& src);

public:		
	UGString GetName() const;
	void SetName(UGString lpNewName);

	UGint GetSize() const;
	
	UGbool IsValid() const;	

	UGint GetFileCount() const;
	
	UGint GetSubFolderCount() const;

	UGFolder* GetSubFolder(const UGString& strFolderName) const;
	//UGString GetSubFolderName(UGint nIndex) const;
	UGFolder* GetSubFolder(UGint nIndex) const;
	
	UGString GetFileName(UGint nIndex) const;

	UGFileLogical * GetFileAt(UGint nIndex) const ;

	UGint FindFile(const UGString& strFileName) const;
	
	UGint FindSubFolder(const UGString& strFolderName) const;
	
	UGbool RemoveElement(const UGString& strName);		
	
	UGbool RenameElement(const UGString& strOldName,const UGString& strNewName);
	
	UGbool OpenFile(const UGString& strName, UGFileLogical* &pFile) const ;
	
	UGbool CreateNewFile(const UGString& strName, UGFileLogical* &pFileNew);
	
	UGbool CreateFolder(const UGString& strName, UGFolder* &pFolderNew);

	UGbool CopyTo(UGFolder &folder) const ;
	
	void Release();
	
	void Destroy();

	void ReadInfo(UGFileLogical *pInfoFile,UGint nVersion);
	
	void WriteInfo(UGFileLogical *pInfoFile,UGint nVersion);


public:
	
//inline functions
	void SetBlockManager(UGBlockManager* pBlockManager);

	UGBlockManager *GetBlockManager() const;

protected:
	UGbool AddFile(UGFileLogical* pFile);
	
	UGbool RemoveFile(UGint nIndex);
	
	UGbool AddFolder(UGFolder* pFolder);
	
	UGbool RemoveFolder(UGint nIndex);

protected:
	UGBlockManager* m_pBlockManager;
	
	UGString m_strName;
	
	UGushort m_nFileCount;
	UGushort m_nSubFolderCount;
	UGFileLogical **m_ppFiles;
	UGFolder **m_ppSubFolders;
};

inline void UGFolder::SetBlockManager(UGBlockManager* pBlockManager)
{
	m_pBlockManager=pBlockManager;
}

inline UGBlockManager * UGFolder::GetBlockManager() const
{
	return m_pBlockManager;
}

}

#endif // !defined(AFX_SEFOLDER_H__978F73C8_E4FB_43D4_BED1_056CE71977B8__INCLUDED_)
