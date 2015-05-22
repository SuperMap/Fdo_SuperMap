/** \file	 SuperMapInsertCommand.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#ifndef __SUPERMAP_INSERTCOMMAND_H__
#define __SUPERMAP_INSERTCOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapInsertCommand SuperMapInsertCommand.h
	\brief 用于执行要素插入要素源时的插入操作，在Map 3D中创建一个要素后执行检入操作时，自动执行该类中的Execute函数
    return Execute函数返回所插入的要素
*/

class SuperMapInsertCommand :
    public FdoCommonFeatureCommand<FdoIInsert, SuperMapConnection>
{
    friend class SuperMapConnection;

protected:
	FdoPtr<FdoBatchParameterValueCollection> m_BatchParameters;

private:
    SuperMapInsertCommand (FdoIConnection *connection);
    virtual ~SuperMapInsertCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapInsertCommand & operator= (const SuperMapInsertCommand &right);

    //
    // FdoIInsertCommand interface
    //

    /// <summary>Gets the FdoBatchParameterValueCollection that can be used for optimized
    /// batch inserts of multiple features with a single insert command. Batch
    /// inserts can be performed by using Parameters for each of the property
    /// values, then adding collections of parameter values to the
    /// FdoBatchParameterValueCollection. Each FdoParameterValueCollection in the
    /// FdoBatchParameterValueCollection should contain one FdoParameterValue for each
    /// of the parameters specified for property values.</summary>
    /// <returns>Returns FdoBatchParameterValueCollection</returns>
    virtual FdoBatchParameterValueCollection* GetBatchParameterValues ();

    /// <summary>Executes the insert command and returns a reference to an
    /// FdoIFeatureReader. Some feature providers can generate automatic identity
    /// values for features. This will happen automatically as the features are
    /// inserted. The returned FdoIFeatureReader allows the client to obtain the
    /// automatic identity property value(s) of newly inserted object(s). The
    /// returned feature reader at a minimum will read the unique identity
    /// properties of the objects just inserted. Multiple objects will be
    /// returned through the reader in the case of a batch insert.</summary>
    /// <returns>Returns an FdoIFeatureReader</returns> 
    virtual FdoIFeatureReader* Execute ();
};

#endif // __SUPERMAP_INSERTCOMMAND_H__