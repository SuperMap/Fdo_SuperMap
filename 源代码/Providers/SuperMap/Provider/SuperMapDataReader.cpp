
/** \file	 SuperMapDataReader.cpp
*  \author	 Âí¿¡
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-10
*/

#include "SuperMap.h"

SuperMapDataReader::SuperMapDataReader(SuperMapFeatureReader  *reader)
{
	m_FeatureReader = FDO_SAFE_ADDREF( reader );
}

SuperMapDataReader::~SuperMapDataReader(void)
{

}
