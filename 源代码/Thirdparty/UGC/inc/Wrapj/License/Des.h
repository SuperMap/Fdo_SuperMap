// Des.h: interface for the CDes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DES_H__438F0382_F171_4B39_B595_FB0BD8F195FD__INCLUDED_)
#define AFX_DES_H__438F0382_F171_4B39_B595_FB0BD8F195FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define EN0	0	/* MODE == encrypt */
#define DE1	1	/* MODE == decrypt */

class CDes  
{	
public:
	CDes();
	virtual ~CDes();
	
public:
	void encrypt(unsigned char *key, unsigned char *from, unsigned char *to, int nWay);
	void decrypt(unsigned char *key, unsigned char *from, unsigned char *to, int nWay);

	void encryptex(unsigned char *key, unsigned char *from, unsigned char *to, int nSize);
	void decryptex(unsigned char *key, unsigned char *from, unsigned char *to, int nSize);
private:
	void deskey(unsigned char *, short);
	void usekey(unsigned long *);
	void cpkey(unsigned long *);
	void des(unsigned char *, unsigned char *);
	
private:
	void des2key(unsigned char *, short);
	void Ddes(unsigned char *, unsigned char *);
	void D2des(unsigned char *, unsigned char *);
	
private:
	void des3key(unsigned char *, short);
	void D3des(unsigned char *, unsigned char *);
	
private:
	void scrunch(unsigned char *, unsigned long *);
	void unscrun(unsigned long *, unsigned char *);
	void desfunc(unsigned long *, unsigned long *);
	void cookey(unsigned long *);
	
private:
	unsigned long KnL[32];
	unsigned long KnR[32];
	unsigned long Kn3[32];	
	
private: 
	static unsigned char Df_Key[24]; 
	static unsigned short bytebit[8]; 
	static unsigned long bigbyte[24]; 
	static unsigned char pc1[56]; 
	static unsigned char totrot[16]; 
	static unsigned char pc2[48]; 
	static unsigned long SP1[64]; 
	static unsigned long SP2[64]; 
	static unsigned long SP3[64]; 
	static unsigned long SP4[64]; 
	static unsigned long SP5[64]; 
	static unsigned long SP6[64]; 
	static unsigned long SP7[64]; 
	static unsigned long SP8[64]; 
};

#endif // !defined(AFX_DES_H__438F0382_F171_4B39_B595_FB0BD8F195FD__INCLUDED_)
