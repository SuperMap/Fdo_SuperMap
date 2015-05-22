// UGHardwareIndexBuffer.h: interface for the UGHardwareIndexBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGHARDWAREINDEXBUFFER_H__886F6A8A_AB29_48D5_9B82_90931E519577__INCLUDED_)
#define AFX_UGHARDWAREINDEXBUFFER_H__886F6A8A_AB29_48D5_9B82_90931E519577__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGHardwareBuffer.h"

namespace UGC
{
class SCENE_API UGHardwareIndexBuffer : public UGHardwareBuffer
{

public:
	enum IndexType {
		IT_16BIT,
		IT_32BIT
	};

protected:
	IndexType m_IndexType;
	UGuint m_unNumIndexes;
    UGuint m_unIndexSize;

public:
	
	UGHardwareIndexBuffer(IndexType idxType, UGuint numIndexes, UGHardwareBuffer::Usage usage,
        UGbool useSystemMemory, UGbool useShadowBuffer);
    ~UGHardwareIndexBuffer();	
    IndexType GetType(void) const { return m_IndexType; }
    UGuint GetNumIndexes(void) const { return m_unNumIndexes; }
    UGuint GetIndexSize(void) const { return m_unIndexSize; }
};	
}
#endif // !defined(AFX_UGHARDWAREINDEXBUFFER_H__886F6A8A_AB29_48D5_9B82_90931E519577__INCLUDED_)
