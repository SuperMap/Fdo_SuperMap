/** \file	 SuperMapExpressionCapabilities.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#ifndef __SUPERMAP_EXPRESSIONCAPABILITIES_H__
#define __SUPERMAP_EXPRESSIONCAPABILITIES_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapExpressionCapabilities : public FdoIExpressionCapabilities
{
public:
    SuperMapExpressionCapabilities ();

protected:
    virtual ~SuperMapExpressionCapabilities ();

protected:
    virtual void Dispose ();

public:
    /// <summary>Returns an array of FdoExpressionType objects the feature provider supports.</summary>
    /// <param name="length">Input the number of expression types</param> 
    /// <returns>Returns the list of expression types</returns> 
    virtual FdoExpressionType* GetExpressionTypes (FdoInt32& length);

    /// <summary>Returns a collection of FdoFunctionDefinition objects the feature provider supports within expressions.</summary>
    /// <returns>Returns the collection of function definitions</returns> 
    virtual FdoFunctionDefinitionCollection* GetFunctions ();

private:
    FdoPtr<FdoFunctionDefinitionCollection> m_supportedFunctions;
};

#endif // __SUPERMAP_EXPRESSIONCAPABILITIES_H__

