// SmUnit.h: interface for the UGUnit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGC_SMUNIT_H__6F3A3977_6B26_4FA5_8847_357F48923186__INCLUDED_)
#define UGC_SMUNIT_H__6F3A3977_6B26_4FA5_8847_357F48923186__INCLUDED_



#include "UGString.h"




namespace UGC{


class BASE_API UGUnit  
{
	
public:
	UGUnit();
	
	~UGUnit();

	
static UGString GetUnitName(UGlong nUnit) ;

// 返回nUnit是长度还是角度
// 长度返回 UNIT_DISTANCE 
// 角度返回 UNIT_ANGLE
// 无法识别的单位返回 0 
static UGlong   GetUnitType(UGlong nUnit) ; 
		
static UGString UnitConvert(UGlong lUnits);
static UGint UnitConvert(UGString strUnits);

static UGString GetUnitsNameExt(UGlong lUnits);
static UGString GetUnitsName(UGlong lUnits);	
};


}//namespace UGC


#endif // !defined(UGC_SMUNIT_H__6F3A3977_6B26_4FA5_8847_357F48923186__INCLUDED_)
