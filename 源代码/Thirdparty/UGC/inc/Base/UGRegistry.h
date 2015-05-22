#ifndef UGREGISTRY_H
#define UGREGISTRY_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGMarkup.h"
#include "UGHash.h"
#include "UGToolkit.h"
#include "UGMarkup.h"

namespace UGC{

class BASE_API UGRegistry : public UGHash<UGString>
{
private:
	enum ElemType 
	{ 
		Value = 0, 
		Object = 1, 
		Sequence = 2, 
		ObjectSequence = 3, 
		SubRegistry = 4, 
		ExternalFile = 5 
	};
	static ElemType Convert(const UGString &strType);
	
public:
	typedef UGHash<UGString> ObjType;
	typedef UGArray<UGString> SeqType;
	typedef UGArray<ObjType> ObjSeqType;
	typedef UGHash<void*> VHash;
	typedef VHash::POSITION VHash_Pos;

protected:
	UGRegistry();
	UGRegistry(const UGString& file);
	void LoadFile(const UGString& filename);
	virtual void LoadDoc(const UGString& content);

	void SaveDoc(UGMarkup& markup);
	
public:
	static UGString XmlPath();
	
	static UGRegistry& Root();
	
	virtual ~UGRegistry();
	
//	static ObjType ObjNull;
//	static SeqType SeqNull;
//	static ObjSeqType ObjSeqNull;
//	static UGRegistry RegNull;
	
	UGString Encoding() const;
	ObjType& Obj(const UGString& s) const;
	SeqType& Seq(const UGString& s) const;
	ObjSeqType& ObjSeq(const UGString& s) const;	
	UGRegistry& SubReg(const UGString& s) const;
	UGRegistry& SubFile(const UGString& s) const;	
	UGString Name() const;

	//! \brief 把修改在内存中的东西存储到ugc.xml文件中
	UGbool Save();

	//! \brief 得到SubFile中的文件名
	//! \param strTag ugc.xml文件中记录subfile的标签名，如"PrjConfig"
	//! \return 返回在ugc.xml文件中记录的外部文件名,如"PrjConfig.xml"
	//! \remarks 完整的标签为:<PrjConfig type="external">PrjConfig.xml</PrjConfig>
	UGString GetSubFileName(const UGString& strTag) const;

private: 
	VHash m_Objs;
	VHash m_Seqs;
	VHash m_ObjSeqs;
	VHash m_SubRegs;
	VHash m_SubExts;
	ObjType m_SubFiles;

	UGString m_strFileName;
	UGString m_strRootName;
};


//! 从resource.xml中读取字符串资源的类
//! \author zengzm
//! \remark resource.xml的内容进行了一些调整, 主要是不再用id作为tag name,而是id 自动增长
//! 故而原有Registry类不适用了. 这里从Registry中派生专门处理resource.xml的类
class UGRegistryResource : public UGRegistry
{
public:
	virtual void LoadDoc(const UGString& content);
};

//! 从epsfont.xml中读取字符串资源的类
class UGRegistryEpsFont: public UGRegistry
{
public:
	virtual void LoadDoc(const UGString& content);
};

}
#endif
