// UGVertexData.h: interface for the UGVertexData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVERTEXDATA_H__A4AA5DD0_1CD4_4A85_9806_C228E86416AE__INCLUDED_)
#define AFX_UGVERTEXDATA_H__A4AA5DD0_1CD4_4A85_9806_C228E86416AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGHardwareBuffer.h"
#include "Scene/UGHardwareVertexBuffer.h"

namespace UGC
{

typedef UGList<UGHardwareBuffer::Usage> BufferUsageList;

class SCENE_API UGVertexData  
{

public:

	UGVertexData();
	virtual ~UGVertexData();
	UGVertexData* Clone(UGbool copyData = true) const;
    void PrepareForShadowVolume(void);
    UGHardwareVertexBuffer* m_phardwareShadowVolWBuffer;
	void ReorganiseBuffers(UGVertexDeclaration* newDeclaration, const BufferUsageList& bufferUsage);
	void ReorganiseBuffers(UGVertexDeclaration* newDeclaration);
	void ConvertPackedColour(VertexElementType srcType, VertexElementType destType);
	void AllocateHardwareAnimationElements(UGushort count);

public:
	UGVertexDeclaration* vertexDeclaration;
	UGVertexBufferBinding* vertexBufferBinding;
	UGuint vertexStart;
	UGuint vertexCount;

private:
   
    UGVertexData(const UGVertexData& rhs);   
    UGVertexData& operator=(const UGVertexData& rhs); 

};

}
#endif // !defined(AFX_UGVERTEXDATA_H__A4AA5DD0_1CD4_4A85_9806_C228E86416AE__INCLUDED_)
