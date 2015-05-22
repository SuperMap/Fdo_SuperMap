// UGPrimitiveSet.h: interface for the UGPrimitiveSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGPRIMITIVESET_H)
#define UGPRIMITIVESET_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGArray.h"

namespace UGC{

class GRAPHICS3D_API UGPrimitiveSet  
{
public:
	enum Type
	{
		PrimitiveType,
		DrawArraysPrimitiveType, //glDrawArrays
		DrawElementsPrimitiveUByteType,//glDrawElements
		DrawElementsPrimitiveUShorteType,
		DrawElementsPrimitiveUIntType
	};
	enum Mode
	{
		POINTS,// = GL_POINTS,
		LINES,// = GL_LINES,
		LINE_STRIP,// = GL_LINE_STRIP,
		LINE_LOOP,// = GL_LINE_LOOP,
		TRIANGLES,// = GL_TRIANGLES,
		TRIANGLE_STRIP,// = GL_TRIANGLE_STRIP,
		TRIANGLE_FAN,// = GL_TRIANGLE_FAN,
		QUADS,// = GL_QUADS,
		QUAD_STRIP,// = GL_QUAD_STRIP,
		POLYGON// = GL_POLYGON
	};
	
public:
	UGPrimitiveSet(Type primitivetype = PrimitiveType,Mode mode = POINTS):
	  m_enPrimitiveType(primitivetype),m_enPrimitiveMode(mode)
	  {}
	  virtual ~UGPrimitiveSet(){};
public:
	void SetPrimitiveMode(Mode mode);
	Mode GetPrimitiveMode();

	void SetPrimitiveType(Type type);
	Type GetPrimitiveType();

	virtual UGint GetIndex(UGint  pos) const = 0;
	virtual UGint GetNumIndices() const = 0;
	virtual void OffsetIndices(UGint offset) = 0;
	virtual unsigned int GetNumPrimitives() const 
	{
		switch(m_enPrimitiveMode)
		{
		case(POINTS): return GetNumIndices();
		case(LINES): return GetNumIndices()/2;
		case(TRIANGLES): return GetNumIndices()/3;
		case(QUADS): return GetNumIndices()/4;
		case(LINE_STRIP):
		case(LINE_LOOP):
		case(TRIANGLE_STRIP):
		case(TRIANGLE_FAN):
		case(QUAD_STRIP):
		case(POLYGON): return 1;
		}
		return 0;
	}

protected:
	Type m_enPrimitiveType;
	Mode m_enPrimitiveMode;
};
//!\brief
class GRAPHICS3D_API UGDrawArrays:public UGPrimitiveSet
{
public:
	UGDrawArrays(UGPrimitiveSet::Mode mode = POINTS):UGPrimitiveSet(UGPrimitiveSet::DrawArraysPrimitiveType,mode),
		m_nFirst(0),m_nCount(0){}
	UGDrawArrays(UGPrimitiveSet::Mode mode,UGint nFirst,UGint nCount):
	UGPrimitiveSet(UGPrimitiveSet::DrawArraysPrimitiveType,mode),
		m_nFirst(nFirst),
		m_nCount(nCount){}
	~UGDrawArrays(){};

	void SetFirst(UGint nFirst);
	UGint GetFirst();
	void SetCount(UGint nCount);
	UGint GetCount();

	UGint GetIndex(UGint  pos) const{return m_nFirst + pos;};
	UGint GetNumIndices() const{return m_nCount;};
	void OffsetIndices(UGint offset){m_nFirst += offset;};

protected:
	UGint m_nFirst;
	UGint m_nCount;
};
//glDrawElements
class GRAPHICS3D_API UGDrawElementsUByte:public UGPrimitiveSet
{
public:
	UGDrawElementsUByte(UGPrimitiveSet::Mode mode):
		UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUByteType,mode)
		{}
	UGDrawElementsUByte(UGPrimitiveSet::Mode mode,UGuint nCount):
		UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUByteType,mode)
	{
			m_IndexArray.SetSize(nCount);
	}
	UGDrawElementsUByte(UGPrimitiveSet::Mode mode,UGuint nCount,UGuchar* pIndexData):
		UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUByteType,mode)
	{
		m_IndexArray.SetSize(nCount);
		UGuchar* pData = m_IndexArray.GetData();
		memmove(pData,pIndexData,nCount);			
	}
	~UGDrawElementsUByte()
	{
	
	}

	//operation on every value
	void SetIndex(UGint nIndex,UGuchar nValue);
	UGuchar GetIndex(UGint  pos);
	//get the interal pointer to the index buffer
	void* GetIndexPointer()const;

protected:
	UGArray<UGuchar> m_IndexArray;

};

class GRAPHICS3D_API UGDrawElementsUShort:public UGPrimitiveSet
{
public:
	UGDrawElementsUShort(UGPrimitiveSet::Mode mode):
	  UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUShorteType,mode)
	  {}
	  UGDrawElementsUShort(UGPrimitiveSet::Mode mode,UGuint nCount):
	  UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUShorteType,mode)
	  {
		  m_IndexArray.SetSize(nCount);
	  }
	  UGDrawElementsUShort(UGPrimitiveSet::Mode mode,UGuint nCount,UGuchar* pIndexData):
	  UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUShorteType,mode)
	  {
		  m_IndexArray.SetSize(nCount);
		  UGushort* pData = m_IndexArray.GetData();
		  memmove(pData,pIndexData,nCount);			
	  }
	  ~UGDrawElementsUShort()
	  {
		  
	  }
	  
	  //operation on every value
	  void SetIndex(UGint nIndex,UGushort nValue);
	  UGushort GetIndex(UGint  pos);
	  //get the interal pointer to the index buffer
	  void* GetIndexPointer()const;
	  
protected:
	UGArray<UGushort> m_IndexArray;
	
};

class GRAPHICS3D_API UGDrawElementsUInt:public UGPrimitiveSet
{
public:
	UGDrawElementsUInt(UGPrimitiveSet::Mode mode):
	  UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUIntType,mode)
	  {}
	  UGDrawElementsUInt(UGPrimitiveSet::Mode mode,UGuint nCount):
	  UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUIntType,mode)
	  {
		  m_IndexArray.SetSize(nCount);
	  }
	  UGDrawElementsUInt(UGPrimitiveSet::Mode mode,UGuint nCount,UGuchar* pIndexData):
	  UGPrimitiveSet(UGPrimitiveSet::DrawElementsPrimitiveUIntType,mode)
	  {
		  m_IndexArray.SetSize(nCount);
		  UGuint* pData = m_IndexArray.GetData();
		  memmove(pData,pIndexData,nCount);			
	  }
	  ~UGDrawElementsUInt()
	  {
		  
	  }
	  
	  //operation on every value
	  void SetIndex(UGint nIndex,UGuint nValue);
	  UGint GetIndex(UGint  pos);
	  //get the interal pointer to the index buffer
	  void* GetIndexPointer()const;
	  
protected:
	UGArray<UGuint> m_IndexArray;
	
};

}

#endif // !defined(UGPRIMITIVESET_H)
