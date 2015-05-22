// UGDesEncrypt.h: interface for the UGDesEncrypt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDESENCRYPT_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_)
#define AFX_UGDESENCRYPT_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_

#include "Base/ugdefs.h"

namespace UGC {	
const static char Des_key[17] = "~@!#(*&)_OP%#_*!";	
const static int Des_key_length = 16;
class BASE_API UGDesEncrypt  
{
	
	
public:
	enum WorkMode
	{
		ENCRYPT,
		DECRYPT,
	};
	
	UGDesEncrypt();
	virtual ~UGDesEncrypt();
	static UGbool Work(	UGchar *szOut, 
				UGchar *szIn, 
				UGint datalen, 
				const UGchar *Key, 
				UGint keylen, 
				WorkMode emMode);
	
};

}

#endif // !defined(AFX_UGDESENCRYPT_H__C364698C_5E89_4C16_8850_63871A01DC07__INCLUDED_)
