/** \file	 SuperMapGetSpatialContextsCommand.h
*  \brief    实现FdoIGetSpatialIContexts接口，获取逻辑要素类的空间语义
*  \author	 周旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-25
*/

#ifndef __SUPERMAP_GETSPATIALCONTEXTSCOMMAND_H__
#define __SUPERMAP_GETSPATIALCONTEXTSCOMMAND_H__


class SuperMapGetSpatialContextsCommand :
    public FdoCommonCommand<FdoIGetSpatialContexts, SuperMapConnection>
{
protected:
    bool mActiveOnly;

public:
    // 0-argument constructor to please FdoPtr::operator->() :
    SuperMapGetSpatialContextsCommand ();

    SuperMapGetSpatialContextsCommand (FdoIConnection *connection);
    virtual ~SuperMapGetSpatialContextsCommand (void);

public:

    //
    // FdoIGetSpatialContexts interface
    //

    /// <summary> Gets a Boolean flag that indicates if the GetSpatialContexts command
    /// will return only the active spatial context or all spatial contexts. The
    /// default value of this flag is false, return all spatial contexts.</summary>
    /// <returns>Returns Boolean value</returns> 
    virtual const bool GetActiveOnly ();

    /// <summary> Sets a Boolean flag that indicates if the GetSpatialContexts command
    /// will return only the active spatial context or all spatial contexts. The
    /// default value of this flag is false, return all spatial contexts.</summary>
    /// <param name="value">Input the Boolean flag</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetActiveOnly (const bool value);

    /// <summary>Executes the GetSpatialContexts command returning an FdoISpatialContextReader.</summary>
    /// <returns>Returns nothing</returns> 
    virtual FdoISpatialContextReader* Execute ();
};

#endif // SUPERMAPGETSPATIALCONTEXTSCOMMAND_H