#ifndef UGMARKUP_H
#define UGMARKUP_H

#include "ugdefs.h"
#include "ugplatform.h"

namespace UGC {

#ifdef DEBUG
#define _DS(i) (i?&(m_strDoc.c_str())[m_aPos[i].nStartL]:0)
#define MARKUP_SETDEBUGSTATE m_pMainDS=_DS(m_iPos); m_pChildDS=_DS(m_iPosChild)
#else
#define MARKUP_SETDEBUGSTATE
#endif

//! \brief XML解析类
//! \remarks 从网上下载的一个类, 原名为UGMarkup; 详细的功能使用说明请参考最后的注释说明. 
//! UGMarkup是基于“压缩”文档对象模型(EDOM ： "Encapsulated" Document Object Model,)，
//!	这是这个简单XML处理器的关键。它的一套XML处理方法和产生的效果与DOM(Document Object Model)
//!	是一样的。但是整个DOM有无数的对象类型，而EDOM只定义了一个对象：XML文档，EDOM回到了XML原始的吸引力—简单. 
//! Markup 封装了XML文档文本、结构和当前位置。它提供了增加元素、导航和得到元素属性和数据的所有方法。
//! 在文档中操作被执行的地方取决于当前位置和当前子位置。当前位置允许你增加一个元素到文档中的这个位置，
//! 而不需要明确指出增加对象到文档的这点上，在Markup的有效生命周期里，
//! 对象一直保持着一个用来描述文档的字符串，当你调用GetDoc.可以得到它.
class BASE_API UGMarkup
{
public:
	UGMarkup() { SetDoc( NULL ); m_nFlags=0; };
	UGMarkup( const char* szDoc ) { SetDoc( szDoc ); };
	UGMarkup( const UGMarkup& markup ) { *this = markup; };
	void operator=( const UGMarkup& markup );
	virtual ~UGMarkup() {};

	// Navigate
	UGbool Load( const char* szFileName );
	UGbool SetDoc( const char* szDoc );
	UGbool IsWellFormed();
	UGbool FindElem( const char* szName=NULL );
	UGbool FindChildElem( const char* szName=NULL );
	UGbool IntoElem();
	UGbool OutOfElem();
	void ResetChildPos() { x_SetPos(m_iPosParent,m_iPos,0); };
	void ResetMainPos() { x_SetPos(m_iPosParent,0,0); };
	void ResetPos() { x_SetPos(0,0,0); };
	std::string GetTagName() const;
	std::string GetChildTagName() const { return x_GetTagName(m_iPosChild); };
	std::string GetData() const { return x_GetData(m_iPos); };
	std::string GetChildData() const { return x_GetData(m_iPosChild); };
	std::string GetAttrib( const char* szAttrib ) const { return x_GetAttrib(m_iPos,szAttrib); };
	std::string GetChildAttrib( const char* szAttrib ) const { return x_GetAttrib(m_iPosChild,szAttrib); };
	std::string GetAttribName( int n ) const;
	UGbool SavePos( const char* szPosName="" );
	UGbool RestorePos( const char* szPosName="" );
	const std::string& GetError() const { return m_strError; };

	enum MarkupNodeType
	{
		MNT_ELEMENT					= 1,  // 0x01
		MNT_TEXT					= 2,  // 0x02
		MNT_WHITESPACE				= 4,  // 0x04
		MNT_CDATA_SECTION			= 8,  // 0x08
		MNT_PROCESSING_INSTRUCTION	= 16, // 0x10
		MNT_COMMENT					= 32, // 0x20
		MNT_DOCUMENT_TYPE			= 64, // 0x40
		MNT_EXCLUDE_WHITESPACE		= 123// 0x7b
	};

	// Create
	UGbool Save( const char* szFileName );
	const std::string& GetDoc() const { return m_strDoc; };
	UGbool AddElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,false,false); };
	UGbool InsertElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,true,false); };
	UGbool AddChildElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,false,true); };
	UGbool InsertChildElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,true,true); };
	UGbool AddAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPos,szAttrib,szValue); };
	UGbool AddChildAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPosChild,szAttrib,szValue); };
	UGbool AddAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPos,szAttrib,nValue); };
	UGbool AddChildAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPosChild,szAttrib,nValue); };
	UGbool AddSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,false,false); };
	UGbool InsertSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,true,false); };
	std::string GetSubDoc() const { return x_GetSubDoc(m_iPos); };
	UGbool AddChildSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,false,true); };
	UGbool InsertChildSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,true,true); };
	std::string GetChildSubDoc() const { return x_GetSubDoc(m_iPosChild); };

	// Modify
	UGbool RemoveElem();
	UGbool RemoveChildElem();
	UGbool SetAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPos,szAttrib,szValue); };
	UGbool SetChildAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPosChild,szAttrib,szValue); };
	UGbool SetAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPos,szAttrib,nValue); };
	UGbool SetChildAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPosChild,szAttrib,nValue); };
	UGbool SetData( const char* szData, int nCDATA=0 ) { return x_SetData(m_iPos,szData,nCDATA); };
	UGbool SetChildData( const char* szData, int nCDATA=0 ) { return x_SetData(m_iPosChild,szData,nCDATA); };


protected:

#ifdef DEBUG
	const char* m_pMainDS;
	const char* m_pChildDS;
#endif

	std::string m_strDoc;
	std::string m_strError;
	int m_nFlags;

	struct ElemPos
	{
		ElemPos() { Clear(); };
		ElemPos( const ElemPos& pos ) { *this = pos; };
		UGbool IsEmptyElement() const { return (nStartR == nEndL + 1); };
		void Clear() { memset( this, 0, sizeof(ElemPos) ); };
		void AdjustStart( int n ) { nStartL+=n; nStartR+=n; };
		void AdjustEnd( int n ) { nEndL+=n; nEndR+=n; };
		int nStartL;
		int nStartR;
		int nEndL;
		int nEndR;
		int nReserved;
		int iElemParent;
		int iElemChild;
		int iElemNext;
	};

	int m_iPosParent;
	int m_iPos;
	int m_iPosChild;
	int m_iPosFree;
	int m_nNodeType;

	struct TokenPos
	{
		TokenPos( const char* sz ) { Clear(); szDoc = sz; };
		void Clear() { nL=0; nR=-1; nNext=0; bIsString=false; };
		UGbool Match( const char* szName )
		{
			int nLen = nR - nL + 1;
		// To ignore case, define MARKUP_IGNORECASE
		#ifdef MARKUP_IGNORECASE
			return ( (strnicmp( &szDoc[nL], szName, nLen ) == 0)
		#else
			return ( (strncmp( &szDoc[nL], szName, nLen ) == 0)
		#endif
				&& ( szName[nLen] == '\0' || strchr(" =/[",szName[nLen]) ) );
		};
		int nL;
		int nR;
		int nNext;
		const char* szDoc;
		UGbool bIsString;
	};

	struct SavedPos
	{
		int iPosParent;
		int iPos;
		int iPosChild;
	};
	typedef std::map<std::string,SavedPos> mapSavedPosT;
	mapSavedPosT m_mapSavedPos;

	void x_SetPos( int iPosParent, int iPos, int iPosChild )
	{
		m_iPosParent = iPosParent;
		m_iPos = iPos;
		m_iPosChild = iPosChild;
		m_nNodeType = iPos?MNT_ELEMENT:0;
		MARKUP_SETDEBUGSTATE;
	};

	struct PosArray
	{
		PosArray() { Clear(); };
		~PosArray() { Release(); };
		enum { PA_SEGBITS = 16, PA_SEGMASK = 0xffff };
		void RemoveAll() { Release(); Clear(); };
		void Release() { for (int n=0;n<SegsUsed();++n) delete[] (char*)pSegs[n]; if (pSegs) delete[] (char*)pSegs; };
		void Clear() { nSegs=0; nSize=0; pSegs=NULL; };
		int GetSize() const { return nSize; };
		int SegsUsed() const { return ((nSize-1)>>PA_SEGBITS) + 1; };
		ElemPos& operator[](int n) const { return pSegs[n>>PA_SEGBITS][n&PA_SEGMASK]; };
		ElemPos** pSegs;
		int nSize;
		int nSegs;
	};
	PosArray m_aPos;

	int x_GetFreePos() { if (m_iPosFree==m_aPos.GetSize()) x_AllocPosArray(); return m_iPosFree++; };
	int x_ReleasePos() { --m_iPosFree; return 0; };
	UGbool x_AllocPosArray( int nNewSize = 0 );
	UGbool x_ParseDoc();
	int x_ParseElem( int iPos );
	int x_ParseError( const char* szError, const char* szName = NULL );
	static UGbool x_FindChar( const char* szDoc, int& nChar, char c );
	static UGbool x_FindAny( const char* szDoc, int& nChar );
	static UGbool x_FindToken( TokenPos& token );
	std::string x_GetToken( const TokenPos& token ) const;
	int x_FindElem( int iPosParent, int iPos, const char* szPath );
	std::string x_GetTagName( int iPos ) const;
	std::string x_GetData( int iPos ) const;
	std::string x_GetAttrib( int iPos, const char* szAttrib ) const;
	UGbool x_AddElem( const char* szName, const char* szValue, UGbool bInsert, UGbool bAddChild );
	std::string x_GetSubDoc( int iPos ) const;
	UGbool x_AddSubDoc( const char* szSubDoc, UGbool bInsert, UGbool bAddChild );
	UGbool x_FindAttrib( TokenPos& token, const char* szAttrib=NULL ) const;
	UGbool x_SetAttrib( int iPos, const char* szAttrib, const char* szValue );
	UGbool x_SetAttrib( int iPos, const char* szAttrib, int nValue );
	UGbool x_CreateNode( std::string& strNode, int nNodeType, const char* szText );
	void x_LocateNew( int iPosParent, int& iPosRel, int& nOffset, int nLength, int nFlags );
	int x_ParseNode( TokenPos& token );
	UGbool x_SetData( int iPos, const char* szData, int nCDATA );
	int x_RemoveElem( int iPos );
	void x_DocChange( int nLeft, int nReplace, const std::string& strInsert );
	void x_PosInsert( int iPos, int nInsertLength );
	void x_Adjust( int iPos, int nShift, UGbool bAfterPos = false );
	std::string x_TextToDoc( const char* szText, UGbool bAttrib = false ) const;
	std::string x_TextFromDoc( int nLeft, int nRight ) const;
};

}

#endif

/** Markup 的主要功能使用说明:
1, 创建一个XML文档
对于创建一个XML文档，需要实例化一个UGMarkup对象，并调用AddElem创建根元素。
在这个位置，如果你调用 AddElem("ORDER") ，你的文档会简单的装一个空ORDER元素<ORDER/>. 
然后调用AddChildElem 在根元素的下面创建元素 (例如：“进入”根元素内部，层次表示).
下面的示例代码创建一个XML文档并返回它（的内容）到一个字符串中。
UGMarkup xml;
xml.AddElem( "ORDER" );
xml.AddChildElem( "ITEM" );
xml.IntoElem();
xml.AddChildElem( "SN", "132487A-J" );
xml.AddChildElem( "NAME", "crank casing" );
xml.AddChildElem( "QTY", "1" );
CString csXML = xml.GetDoc();
这些代码产生了下面的XML，这个根结点是ORDER元素；注意它的开始标签<ORDER> 在开头，结束标签</ORDER>在结尾。
当一个元素是在一个父下面（深入或被包含），这个父元素的开始标签要在它之前，结束标签要在它之后。
ORDER元素包含一个ITEM元素，而ITEM元素包含了三个字子元素：SN、NAME和QTY；
<ORDER>
	<ITEM>
		<SN>132487A-J</SN>
		<NAME>crank casing</NAME>
		<QTY>1</QTY>
	</ITEM>
</ORDER>
如例子中所显示的，你也能够在一个子元素下创建新元素，这需要调用IntoElem 移动你的当前主位置到当前子元素位置，
然后你就可以在这下面增加一个子元素了。UGMarkup在索引中保持了一个当前位置指针，以保证你的源码更加短和更简单，
当导航文件时，相同的逻辑位置也会被使用。

2,导航XML文档
上面的例子所创建的XML字符串，用SetDoc方法加入到UGMarkup对象中能够被解析，
你也可以引导它正确的进入被创建的同一个UGMarkup对象中，如果你要设置当前位置到文档的开始时，需要调用ResetPos.
在下面的例子中，从csXML字符串生成UGMarkup对象后，我们循环ORDER元素下的所有ITEM元素，并得到每个项目的序号和数量。
UGMarkup xml;
xml.SetDoc( csXML );
while ( xml.FindChildElem("ITEM") )
{
    xml.IntoElem();
    xml.FindChildElem( "SN" );
    CString csSN = xml.GetChildData();
    xml.FindChildElem( "QTY" );
    int nQty = atoi( xml.GetChildData() );
    xml.OutOfElem();
}
对于我们发现的每个元素，在查询它了子元素之前要调用IntoElem，查询完之后再调用OutOfElem ，
当你习惯于这种导航类型时，你将知道，检查你的循环时，要确定每个IntoElem 调用都有一个与之对应的OutOfElem 调用 。

3,增加元素和属性
上面创建文档的例子中仅创建了一个ITEM元素，现在这个例子是创建多个项目，从前一个内容加裁后，再增加数据源，
加上SHIPMENT信息元素中有一个属性，这段代码也演示了你能调用调用IntoElem和AddElem来代替AddChildElem,函数调用。
虽然这意味着更多的调用，但许多人认为这样更直观。
UGMarkup xml;
xml.AddElem( "ORDER" );
xml.IntoElem(); // inside ORDER
for ( int nItem=0; nItem<aItems.GetSize(); ++nItem )
{
    xml.AddElem( "ITEM" );
    xml.IntoElem(); // inside ITEM
    xml.AddElem( "SN", aItems[nItem].csSN );
    xml.AddElem( "NAME", aItems[nItem].csName );
    xml.AddElem( "QTY", aItems[nItem].nQty );
    xml.OutOfElem(); // back out to ITEM level
}
xml.AddElem( "SHIPMENT" );
xml.IntoElem(); // inside SHIPMENT
xml.AddElem( "POC" );
xml.SetAttrib( "type", csPOCType );
xml.IntoElem(); // inside POC
xml.AddElem( "NAME", csPOCName );
xml.AddElem( "TEL", csPOCTel );
这段代码产生了下面的XML，根元素ORDER包含两个ITEM元素和一个SHIPMENT元素，
ITEM元素全都包含SN、NAME、和QTY元素，
SHIPMENT元素包含一个带有属性类型的POC元素，和NAME及TEL子元素。
<ORDER>
	<ITEM>
		<SN>132487A-J</SN>
		<NAME>crank casing</NAME>
		<QTY>1</QTY>
	</ITEM>
	<ITEM>
		<SN>4238764-A</SN>
		<NAME>bearing</NAME>
		<QTY>15</QTY>
	</ITEM>
	<SHIPMENT>
		<POC type="non-emergency">
			<NAME>John Smith</NAME>
			<TEL>555-1234</TEL>
		</POC>
	</SHIPMENT>
</ORDER>

4, 查找元素
FindElem 和 FindChildElem方法用于到下一个兄弟元素。如果可选的标签名被指定，
那么它们将到下一个与标签名相匹配的元素，被发现的元素是当前元素，
并且下次调用Find将会到当前位置后的下一个兄弟或下一个匹配兄弟。
当你无法判断元素的索引时，在调用两个Find方法之间，一定要复位当前位置。
看上面的例子中ITEM元素，如果是别的人创建的XML文件，你不能确定SN元素在QTY元素之前，
那么在查找QTY元素之前就要调用ResetChildPos();
对于用一个特定的序号去查找元素，你需要完全循环ITEM元素，并比较SN元素的数据和你正在搜索的序号。
这个例子不同于先前导航的例子，它调用IntoElem 进入到ORDER元素，
并且用FindElem("ITEM")替换FindChildElem("ITEM");其实两种方式都挺好。
需要注意的是，在Find方法中指定ITEM元素的标签名，我们会忽略所有其它的兄弟元素，例如SHIPMENT元素。
UGMarkup xml;
xml.SetDoc( csXML );
xml.FindElem(); // ORDER element is root
xml.IntoElem(); // inside ORDER
while ( xml.FindElem("ITEM") )
{
    xml.FindChildElem( "SN" );
    if ( xml.GetChildData() == csFindSN )
        break; // found
}

5,编码
ASCII编码引用了我们所依靠的字符码128以下的字符，如用英语编程。
如果你只使用ASCII码，很方便，UTF-8编程与你拉公共ASCII集相同。
如果你所使用的字符集不在Unicode编码集(UTF-8，UTF-16，UCS-2)中，
那么出于交互性以及在IE中很好的显示，你真的需要在XML声明中进行描述。
像ISO-8859-1(西欧)字符集指定字符值在一个比特且在128到255之间。
以便每个字符仍然使用一个比特。Windows双字节字符集像GB2312，Shift_JIS和EUC-KR，
每个字符都是用一个或两个字节，对于这些Windows字符集，在你的预处理中需要定义 _MBCS ，
并要确定用户的操作系统设置到合适的编码页。
关于用一个XML描述的XML文档前缀，像<?xml version="1.0" encoding="ISO-8859-1"?>，
需要通过用SetDoc或UGMarkup的构造函数来传递。在结尾要包括回车符，这样根结点会显示在下一行。
xml.SetDoc( "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\r\n" );
xml.AddElem( "island", "Cura?ao" );

*/

