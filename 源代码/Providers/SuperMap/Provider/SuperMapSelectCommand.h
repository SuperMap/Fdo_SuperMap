
/** \file	 SuperMapSelectCommand.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#ifndef __SUPERMAP_SELECTCOMMAND_H__
#define __SUPERMAP_SELECTCOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapSelectCommand SuperMapSelectCommand.h
	\brief 用于执行图层加载时的查询操作，在Map 3D中选择某一个要素类加载到地图时，自动执行该类中的Execute函数
    return Execute函数返回所查询到的要素
*/

class SuperMapSelectCommand :
    public FdoCommonFeatureCommand<FdoISelect, SuperMapConnection>
{
    friend class SuperMapConnection;

protected:
    FdoPtr<FdoIdentifierCollection> m_PropertiesToSelect;

public:
    SuperMapSelectCommand (SuperMapConnection* connection);
    virtual ~SuperMapSelectCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapSelectCommand & operator= (const SuperMapSelectCommand &right);

    void Dispose ();

    /// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
    /// return with the result. If empty all properties of the specified class
    /// are returned.</summary>
    /// <returns>Returns the list of property names.</returns> 
    virtual FdoIdentifierCollection* GetPropertyNames ();

    /// <summary>Gets the FdoLockType value (see "Locking Commands").</summary>
    /// <returns>Returns the lock type.</returns> 
    virtual FdoLockType GetLockType ();

    /// <summary>Sets the FdoLockType value (see "Locking Commands").</summary>
    /// <param name="value">Input the lock type.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetLockType (FdoLockType value);

    /// <summary>Gets the FdoLockStrategy value (see "Locking Commands").</summary>
    /// <returns>Returns the lock strategy.</returns> 
    virtual FdoLockStrategy GetLockStrategy ();

    /// <summary>Sets the FdoLockStrategy value (see "Locking Commands").</summary>
    /// <param name="value">Input the lock strategy.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetLockStrategy (FdoLockStrategy value);

    /// <summary>Executes the select command and returns a reference to an FdoIFeatureReader.</summary>
    /// <returns>Returns the feature reader.</returns> 
    virtual FdoIFeatureReader* Execute ();

    /// <summary>Executes the select command and returns a reference to an
    /// IFeatureReader.</summary> 
    /// <returns>Returns the feature reader.</returns> 
    virtual FdoIFeatureReader* ExecuteWithLock ();

    /// <summary> When executing the operation ExecuteWithLock lock 
    /// conflicts may occur. Those lock conflicts are reported. The 
    /// function GetLockConflicts returns a lock conflict reader 
    /// providing access to the list of lock conflicts that occurred 
    /// during the execution of the operation.</summary>
    /// <returns>Returns a lock conflict reader.</returns> 
    virtual FdoILockConflictReader* GetLockConflicts ();

    /// <summary>Gets the FdoIdentifierCollection that holds the list of order by property names. If empty no ordering is used. This list is initially
    /// empty and the caller need to add the property that the command should use as a order by criteria.</summary>
    /// <returns>Returns the list of group by property names.</returns> 
    virtual FdoIdentifierCollection* GetOrdering(){ return NULL; }

    /// <summary>Set the ordering option of the selection. This is only used if the ordering collection is not empty.</summary>
    /// <param name="option">Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
    /// FdoOrderingOption_Ascending is the default value.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetOrderingOption( FdoOrderingOption  option ) {}

    /// <summary>Gets the ordering option.</summary>
    /// <returns>Returns the ordering option.</returns> 
    virtual FdoOrderingOption GetOrderingOption( ){ return (FdoOrderingOption)0; }
};

#endif // __SuperMap_SELECTCOMMAND_H__