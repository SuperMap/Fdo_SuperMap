// UGHardwareBufferManager.h: interface for the UGHardwareBufferManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGHARDWAREBUFFERMANAGER_H__350A3FB9_0C41_49B8_A562_5D5D67873099__INCLUDED_)
#define AFX_UGHARDWAREBUFFERMANAGER_H__350A3FB9_0C41_49B8_A562_5D5D67873099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGSingleton.h"
#include "Scene/UGHardwareVertexBuffer.h"
#include "Scene/UGHardwareIndexBuffer.h"


namespace UGC
{
	
class SCENE_API UGHardwareBufferManager : public UGSingleton<UGHardwareBufferManager>  
{
public:
	UGHardwareBufferManager();
	virtual ~UGHardwareBufferManager();

protected:
	typedef UGList<UGHardwareVertexBuffer*> VertexBufferList;
    typedef UGList<UGHardwareIndexBuffer*> IndexBufferList;
    VertexBufferList m_VertexBuffers;
    IndexBufferList m_IndexBuffers;
	
	typedef UGList<UGVertexDeclaration*> VertexDeclarationList;
	typedef UGList<UGVertexBufferBinding*> VertexBufferBindingList;
    VertexDeclarationList m_VertexDeclarations;
	VertexBufferBindingList m_VertexBufferBindings;

public:	
    virtual void DestroyAllDeclarations(void);
    virtual void DestroyAllBindings(void);
    virtual UGVertexDeclaration* CreateVertexDeclarationImpl(void);
    virtual void DestroyVertexDeclarationImpl(UGVertexDeclaration* decl);
	virtual UGVertexBufferBinding* CreateVertexBufferBindingImpl(void);
	virtual void DestroyVertexBufferBindingImpl(UGVertexBufferBinding* binding);
	virtual UGHardwareVertexBuffer*  CreateVertexBuffer(UGuint vertexSize, UGuint numVerts, UGHardwareBuffer::Usage usage, 
			UGbool useShadowBuffer = false);
	virtual UGHardwareVertexBuffer* 
        CreateIndexBuffer(UGHardwareIndexBuffer::IndexType itype, UGuint numIndexes, 
		UGHardwareBuffer::Usage usage, UGbool useShadowBuffer = false);
    virtual UGVertexDeclaration* CreateVertexDeclaration(void);
    virtual void DestroyVertexDeclaration(UGVertexDeclaration* decl);
	virtual UGVertexBufferBinding* CreateVertexBufferBinding(void);
	virtual void DestroyVertexBufferBinding(UGVertexBufferBinding* binding);
	virtual void RegisterVertexBufferSourceAndCopy(
		const UGHardwareVertexBuffer* sourceBuffer,
		const UGHardwareVertexBuffer* copy);
    virtual void ReleaseVertexBufferCopy(
        const UGHardwareVertexBuffer* bufferCopy); 
    virtual void TouchVertexBufferCopy(
        const UGHardwareVertexBuffer* bufferCopy);
    virtual void FreeUnusedBufferCopies(void);
    virtual void ReleaseBufferCopies(UGbool forceFreeUnused = false);
    virtual void ForceReleaseBufferCopies(
        const UGHardwareVertexBuffer* sourceBuffer);
    virtual void ForceReleaseBufferCopies(UGHardwareVertexBuffer* sourceBuffer);
	void NotifyVertexBufferDestroyed(UGHardwareVertexBuffer* buf);
	void NotifyIndexBufferDestroyed(UGHardwareIndexBuffer* buf);
    static UGHardwareBufferManager& GetSingleton();

};

}
#endif // !defined(AFX_UGHARDWAREBUFFERMANAGER_H__350A3FB9_0C41_49B8_A562_5D5D67873099__INCLUDED_)
