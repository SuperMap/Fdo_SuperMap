#if !defined(_UGCONFIGOPTIONMAP_H__)
#define _UGCONFIGOPTIONMAP_H__

#include "Scene/UGPrerequisites.h"

namespace UGC 
{
    typedef struct _UGConfigOption
    {
        UGString name;
        UGString currentValue;
        UGArray<UGString> possibleValues;
        UGbool immutable;
    } UGConfigOption;

    typedef UGDict<UGString, UGConfigOption*> UGConfigOptionMap;
}

#endif
