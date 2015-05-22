
#if !defined(AFX_UGHARDWAREBUFFER_H__D4007E6F_F7DF_4626_A250_D0D13EA3322E__INCLUDED_)
#define AFX_UGHARDWAREBUFFER_H__D4007E6F_F7DF_4626_A250_D0D13EA3322E__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC
{
class SCENE_API UGHardwareBuffer  
{

public:

	/// Enums describing buffer usage; not mutually exclusive
	enum Usage 
	{
        /** Static buffer which the application rarely modifies once created. Modifying 
        the contents of this buffer will involve a performance hit.
        */
        HBU_STATIC = 1,
		/** Indicates the application would like to modify this buffer with the CPU
		fairly often. 
		Buffers created with this flag will typically end up in AGP memory rather 
		than video memory.
		*/
		HBU_DYNAMIC = 2,
		/** Indicates the application will never read the contents of the buffer back, 
		it will only ever write data. Locking a buffer with this flag will ALWAYS 
		return a pointer to new, blank memory rather than the memory associated 
		with the contents of the buffer; this avoids DMA stalls because you can 
		write to a new memory area while the previous one is being used. 
		*/
		HBU_WRITE_ONLY = 4,
        /** Indicates that the application will be refilling the contents
        of the buffer regularly (not just updating, but generating the
        contents from scratch), and therefore does not mind if the contents 
        of the buffer are lost somehow and need to be recreated. This
        allows and additional level of optimisation on the buffer.
        This option only really makes sense when combined with 
        HBU_DYNAMIC_WRITE_ONLY.
        */
        HBU_DISCARDABLE = 8,
		/// Combination of HBU_STATIC and HBU_WRITE_ONLY
		HBU_STATIC_WRITE_ONLY = 5, 
		/** Combination of HBU_DYNAMIC and HBU_WRITE_ONLY. If you use 
        this, strongly consider using HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE
        instead if you update the entire contents of the buffer very 
        regularly. 
        */
		HBU_DYNAMIC_WRITE_ONLY = 6,
        /// Combination of HBU_DYNAMIC, HBU_WRITE_ONLY and HBU_DISCARDABLE
        HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE = 14


	};
	
	/// Locking options
	enum LockOptions
	{
        /** Normal mode, ie allows read/write and contents are preserved. */
        HBL_NORMAL,
		/** Discards the <em>entire</em> buffer while locking; this allows optimisation to be 
		performed because synchronisation issues are relaxed. Only allowed on buffers 
		created with the HBU_DYNAMIC flag. 
		*/
		HBL_DISCARD,
		/** Lock the buffer for reading only. Not allowed in buffers which are created with HBU_WRITE_ONLY. 
		Mandatory on statuc buffers, ie those created without the HBU_DYNAMIC flag. 
		*/ 
		HBL_READ_ONLY,
        /** As HBL_NORMAL, except the application guarantees not to overwrite any 
        region of the buffer which has already been used in this frame, can allow
        some optimisation on some APIs. */
        HBL_NO_OVERWRITE
    	
	};



public:

	/// Constructor, to be called by HardwareBufferManager only
	
    UGHardwareBuffer(Usage usage, UGbool systemMemory, UGbool useShadowBuffer);
	UGHardwareBuffer();
    virtual ~UGHardwareBuffer();

	/** Lock the buffer for (potentially) reading / writing.
	@param offset The byte offset from the start of the buffer to lock
	@param length The size of the area to lock, in bytes
	@param options Locking options
	@returns Pointer to the locked memory
	*/
	virtual void* Lock(UGint offset, UGint length, LockOptions options);
    
	/// Internal implementation of lock()
	virtual void* LockImpl(UGint offset, UGint length, LockOptions options) = 0;
    /// Internal implementation of unlock()
	virtual void UnlockImpl(void) = 0;
    /** Lock the entire buffer for (potentially) reading / writing.
	@param options Locking options
	@returns Pointer to the locked memory
    */
    void* Lock(LockOptions options);
    
	/** Releases the lock on this buffer. 
    @remarks 
        Locking and unlocking a buffer can, in some rare circumstances such as 
        switching video modes whilst the buffer is locked, corrupt the 
        contents of a buffer. This is pretty rare, but if it occurs, 
        this method will throw an exception, meaning you
        must re-upload the data.
    @par
        Note that using the 'read' and 'write' forms of updating the buffer does not
        suffer from this problem, so if you want to be 100% sure your
        data will not be lost, use the 'read' and 'write' forms instead.
    */
	virtual void Unlock(void);
    

    /** Reads data from the buffer and places it in the memory pointed to by pDest.
	@param offset The byte offset from the start of the buffer to read
	@param length The size of the area to read, in bytes
    @param pDest The area of memory in which to place the data, must be large enough to 
        accommodate the data!
    */
    virtual void ReadData(UGint offset, UGint length, void* pDest) = 0;
    /** Writes data to the buffer from an area of system memory; note that you must
        ensure that your buffer is big enough.
	@param offset The byte offset from the start of the buffer to start writing
	@param length The size of the data to write to, in bytes
    @param pSource The source of the data to be written
	@param discardWholeBuffer If true, this allows the driver to discard the entire buffer when writing,
		such that DMA stalls can be avoided; use if you can.
    */
    virtual void WriteData(UGint offset, UGint length, const void* pSource,
			UGbool discardWholeBuffer = false) = 0;

	/** Copy data from another buffer into this one.
	@remarks
		Note that the source buffer must not be created with the
        usage HBU_WRITE_ONLY otherwise this will fail. 
	@param srcBuffer The buffer from which to read the copied data
	@param srcOffset Offset in the source buffer at which to start reading
	@param dstOffset Offset in the destination buffer to start writing
	@param length Length of the data to copy, in bytes.
	@param discardWholeBuffer If true, will discard the entire contents of this buffer before copying
	*/
	virtual void CopyData(UGHardwareBuffer& srcBuffer, UGint srcOffset, 
		UGint dstOffset, UGint length, bool discardWholeBuffer = false);
	

    /// Updates the real buffer from the shadow buffer, if required
    virtual void UpdateFromShadow(void);
    

    /// Returns the size of this buffer in bytes
    UGint GetSizeInBytes(void) const;
	
    
	/// Returns the Usage flags with which this buffer was created
    Usage GetUsage(void) const
	{
		return m_Usage;
	}
	
	
	
	/// Returns whether this buffer is held in system memory
	UGbool IsSystemMemory(void) const;
	
	/// Returns whether this buffer has a system memory shadow for quicker reading
	UGbool HasShadowBuffer(void) const; 
	
    
	/// Returns whether or not this buffer is currently locked.
    UGbool IsLocked(void) const;
	

    /// Pass true to suppress hardware upload of shadow buffer changes
    void SuppressHardwareUpdate(UGbool suppress);
	

protected:
	UGint m_nSizeInBytes;
	Usage m_Usage;
	UGbool m_bIsLocked;
	UGint m_nLockStart;
	UGint m_nLockSize;
	UGbool m_bSystemMemory;
    UGbool m_bUseShadowBuffer;
    UGHardwareBuffer* m_pShadowBuffer;
    UGbool m_bShadowUpdated;
    UGbool m_bSuppressHardwareUpdate;
    
};

}
#endif // !defined(AFX_UGHARDWAREBUFFER_H__D4007E6F_F7DF_4626_A250_D0D13EA3322E__INCLUDED_)
