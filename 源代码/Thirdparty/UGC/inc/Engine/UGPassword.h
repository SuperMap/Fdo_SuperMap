
#if !defined(AFX_SMPASSWORD_H__36C41F28_FE6E_43D2_A872_539AC1D3B32B__INCLUDED_)
#define AFX_SMPASSWORD_H__36C41F28_FE6E_43D2_A872_539AC1D3B32B__INCLUDED_

#include "Base/ugdefs.h"

namespace UGC{

class ENGINE_API UGPassword  
{
public:
	UGPassword();
	virtual ~UGPassword();

public:
	UGuint GenerateKey(const UGchar *pw);// generate a 32 bit key according to the password(capital) 
	void GenerateStream(UGuchar *stream,UGuint key);//generate a 255 length byte array according to the key,stream must be a 255 length array.
	void GenerateXorString(UGuchar *src,UGuchar *dest);//generate a string that every char is xor of source sting. src and dest must be a 255 length array. so src's xor is dest, dext's xor is still src.
protected:
	inline void SwapByte(UGuchar& c1,UGuchar& c2);		//swap byte c1<-->c2
};

}

#endif // !defined(AFX_SMPASSWORD_H__36C41F28_FE6E_43D2_A872_539AC1D3B32B__INCLUDED_)
