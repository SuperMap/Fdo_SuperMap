#ifndef UGFREETYPELIB_H_
#define UGFREETYPELIB_H_
#include "Base/ugdefs.h"
#include "ft2build.h"
#include "freetype/freetype.h"
#include "freetype/ftglyph.h"

#include "Base/UGString.h"
#include "Base/UGDict.h"
#include "Base/ugplatform.h"

namespace UGC {

class BASE_API UGFreeTypeLib { 
public:
	enum FaceStyle
	{
		Regular = 0,
			Bold = 1,
			Italic = 2,
			BoldItalic = 3
	};		
	typedef UGArray<FT_Face> FaceVec;
	typedef UGDict<UGString,FaceVec> FaceMap;	
private:
	UGFreeTypeLib();	
	FT_Face NewFace(const UGString& file,UGint index);
	UGString GetFontsPath();  //»ñÈ¡×Ö¿âÂ·¾¶
public:	
	static UGFreeTypeLib& GetInstance() {
		static UGFreeTypeLib x;
		return x;
	}
	~UGFreeTypeLib();			
	FT_Face GetFace(const UGString& family,const FaceStyle& style);	
private:
	UGFreeTypeLib(const UGFreeTypeLib&);
	UGFreeTypeLib& operator=(const UGFreeTypeLib&);
private:
	FT_Library m_library;
	FaceMap m_faces;
	FT_Face m_defaultFace;
};

}

#endif 
