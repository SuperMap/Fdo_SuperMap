
/** \file	 FdoSuperMapProvider.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#ifndef __FDO_SUPERMAP_PROVIDER_H__
#define __FDO_SUPERMAP_PROVIDER_H__


#ifdef _WIN32

#pragma once

#ifdef FDO_SUPERMAP_EXPORTS
#define FDO_SUPERMAP_API __declspec(dllexport)
#else
#define FDO_SUPERMAP_API __declspec(dllimport)
#endif


#else //_WIN32

#define FDO_SUPERMAP_API

#endif //_WIN32

#endif // __FDO_SUPERMAP_PROVIDER_H__


