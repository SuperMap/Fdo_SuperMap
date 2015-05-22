// UGHardwareVertexBuffer.h: interface for the UGHardwareVertexBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGHARDWAREVERTEXBUFFER_H__2788CD42_E5F2_4B40_83B8_F01A5E631222__INCLUDED_)
#define AFX_UGHARDWAREVERTEXBUFFER_H__2788CD42_E5F2_4B40_83B8_F01A5E631222__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGHardwareBuffer.h"

namespace UGC 
{

class SCENE_API UGHardwareVertexBuffer : public UGHardwareBuffer
{
	
public:
	UGHardwareVertexBuffer();
	UGHardwareVertexBuffer(UGuint vertexSize, UGuint numVertices,
                UGHardwareBuffer::Usage usage, UGbool useSystemMemory, UGbool useShadowBuffer);
            
	virtual ~UGHardwareVertexBuffer();

	UGuint GetVertexSize(void) const;
	UGuint GetNumVertices(void) const;

protected:
	UGuint m_unVertexSize;
	UGuint m_nNumVertices;

};

enum VertexElementSemantic {
	/// Position, 3 reals per vertex
	VES_POSITION = 1,
	/// Blending weights
	VES_BLEND_WEIGHTS = 2,
    /// Blending indices
    VES_BLEND_INDICES = 3,
	/// Normal, 3 reals per vertex
	VES_NORMAL = 4,
	/// Diffuse colours
	VES_DIFFUSE = 5,
	/// Specular colours
	VES_SPECULAR = 6,
	/// Texture coordinates
	VES_TEXTURE_COORDINATES = 7,
    /// Binormal (Y axis if normal is Z)
    VES_BINORMAL = 8,
    /// Tangent (X axis if normal is Z)
    VES_TANGENT = 9

};

enum VertexElementType
{
    VET_FLOAT1 = 0,
    VET_FLOAT2 = 1,
    VET_FLOAT3 = 2,
    VET_FLOAT4 = 3,
    /// alias to more specific colour type - use the current rendersystem's colour packing
	VET_COLOUR = 4,
	VET_SHORT1 = 5,
	VET_SHORT2 = 6,
	VET_SHORT3 = 7,
	VET_SHORT4 = 8,
    VET_UBYTE4 = 9,
    /// D3D style compact colour
    VET_COLOUR_ARGB = 10,
    /// GL style compact colour
    VET_COLOUR_ABGR = 11
};

class SCENE_API UGVertexElement
{
public:
	UGVertexElement();
	UGVertexElement::UGVertexElement(UGushort source, UGuint offset, 
        VertexElementType theType, VertexElementSemantic semantic, UGushort index);
	~UGVertexElement();

public:
	UGushort GetSource(void) const { return m_unSource; }
	UGuint GetOffset(void) const { return m_unOffset; }
	VertexElementType GetType(void) const { return m_Type; }
	VertexElementSemantic GetSemantic(void) const { return m_Semantic; }
	UGushort GetIndex(void) const { return m_unIndex; }
	static UGuint ConvertColourValue(const UGColorValue& src, VertexElementType dst);
	
	UGuint GetSize(void) const;
	static UGuint GetTypeSize(VertexElementType etype);
	static UGushort GetTypeCount(VertexElementType etype);
	static VertexElementType MultiplyTypeCount(VertexElementType baseType, UGushort count);
	static VertexElementType GetBaseType(VertexElementType multiType);
	static void ConvertColourValue(VertexElementType srcType,
		                           VertexElementType dstType, UGuint* ptr);
	static VertexElementType GetBestColourVertexElementType(void);

protected:
	UGuint m_unOffset;	
	UGushort m_unSource;
	VertexElementType m_Type;
	VertexElementSemantic m_Semantic;
	UGushort m_unIndex;
};


class SCENE_API UGVertexDeclaration
{
public:
	UGVertexDeclaration();
	~UGVertexDeclaration();
	typedef UGList<UGVertexElement> UGVertexElementList;

    UGuint GetElementCount(void) 
	{ 
		return m_ElementList.GetCount(); 
	}
    const UGVertexElementList& GetElements(void) const;
    const UGVertexElement* GetElement(UGushort index);
    void Sort(void);
    void CloseGapsInSource(void);
    UGVertexDeclaration* GetAutoOrganisedDeclaration(UGbool skeletalAnimation,
													 UGbool vertexAnimation);
    UGushort GetMaxSource(void) const;
    virtual const UGVertexElement& AddElement(UGushort source, UGuint offset, VertexElementType theType,
									          VertexElementSemantic semantic, UGushort index = 0);
    virtual const UGVertexElement& InsertElement(UGushort atPosition,
												 UGushort source, UGuint offset, VertexElementType theType,
												 VertexElementSemantic semantic, UGushort index = 0);
    virtual void RemoveElement(UGushort elem_index);
    virtual void RemoveElement(VertexElementSemantic semantic, UGushort index = 0);
	virtual void RemoveAllElements(void);
    virtual void ModifyElement(UGushort elem_index, UGushort source, UGuint offset, VertexElementType theType,
							   VertexElementSemantic semantic, UGushort index = 0);
    virtual const UGVertexElement* FindElementBySemantic(VertexElementSemantic sem, UGushort index = 0);
		virtual UGVertexElementList FindElementsBySource(UGushort source);
    virtual UGuint GetVertexSize(UGushort source);
    virtual UGVertexDeclaration* Clone(void);

    inline UGbool operator== (const UGVertexDeclaration& rhs) const
    {
        if (m_ElementList.GetCount() != rhs.m_ElementList.GetCount())
		{
            return false;
		}
		else
		{   
			// 补充比较内容，参考OGRE		
			return true;
		}
        
    }
    inline bool operator!= (const UGVertexDeclaration& rhs) const
    {
        return !(*this == rhs);
    }

protected:
	UGVertexElementList m_ElementList;

};


class SCENE_API UGVertexBufferBinding
{
public:
	typedef UGDict<UGushort, UGHardwareVertexBuffer*> UGVertexBufferBindingMap;
public:
	UGVertexBufferBinding();
	~UGVertexBufferBinding();

	virtual const UGVertexBufferBindingMap& GetBindings(void) const;
	virtual void SetBinding(UGushort index, UGHardwareVertexBuffer* buffer);
	virtual void UnsetBinding(UGushort index);
    virtual void UnsetAllBindings(void);
	virtual UGHardwareVertexBuffer* GetBuffer(UGushort index);
	virtual UGbool IsBufferBound(UGushort index);
    virtual UGuint GetBufferCount(void) const { return m_BindingMap.GetCount(); }
	virtual UGushort GetNextIndex(void) const { return m_nHighIndex++; }

protected:
	UGVertexBufferBindingMap m_BindingMap;
	mutable UGushort m_nHighIndex;
};
}
#endif // !defined(AFX_UGHARDWAREVERTEXBUFFER_H__2788CD42_E5F2_4B40_83B8_F01A5E631222__INCLUDED_)
