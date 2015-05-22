/** \file	 SuperMapApplySchemaCommand.h
*  \brief    该类主要为实现FDO的FdoIApplySchema接口，完成修改模式的功能
*  \author	 周旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-22
*/  

#ifndef __SUPERMAP_APPLYSCHEMACOMMAND_H__
#define __SUPERMAP_APPLYSCHEMACOMMAND_H__

#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapApplySchemaCommand : public FdoCommonCommand<FdoIApplySchema, SuperMapConnection>
{
    friend class SuperMapConnection;

private:
    FdoPtr<FdoFeatureSchema> m_Schema;
    FdoBoolean m_IgnoreStates;

private:
    //
    // Prevent the use of the copy constructor by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapApplySchemaCommand (const  SuperMapApplySchemaCommand &right);

    // Constructs an instance of a DescribeSchema command using the given connection.
    SuperMapApplySchemaCommand (FdoIConnection* connection);

protected:
    // Default destructor for DescribeSchema command.
    virtual ~SuperMapApplySchemaCommand (void);
/*
    void CheckName (FdoPropertyDefinition* property);
    void SetInfo (ColumnInfo* info, int n, FdoPropertyDefinition* property);
*/
    // 内部使用的三个函数
    void AddSchema ();
    void DeleteSchema ();
    void ModifySchema ();

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapApplySchemaCommand & operator= (const SuperMapApplySchemaCommand &right);

    ///<summary>Gets the schema to create.</summary>
    /// <returns>Returns the schema that would be created.</returns> 
    virtual FdoFeatureSchema* GetFeatureSchema ();

    ///<summary>Sets the schema to create.</summary>
    /// <param name="value">Input the definition of the schema to create.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetFeatureSchema (FdoFeatureSchema* value);

    /// <summary> Gets the FdoPhysicalSchemaMapping used to specify how the schema definition
    /// gets mapped into physical storage.</summary>
    /// <returns>Returns FdoPhysicalSchemaMapping</returns> 
	/// note: Physical Schema mapping not supported by SuperMap Provider. 
    virtual FdoPhysicalSchemaMapping* GetPhysicalMapping ();

    ///<summary>Sets the FdoPhysicalSchemaMapping used to specify how the schema definition
    ///gets mapped into physical storage.</summary>
    /// <param name="value">Input the FdoPhysicalSchemaMapping</param> 
    /// <returns>Returns nothing</returns> 
	/// note: Physical Schema mapping not supported by SuperMap Provider.
   virtual void SetPhysicalMapping (FdoPhysicalSchemaMapping* value);

    /// <summary> Indicates whether Execute() will ignore element states 
    /// when applying the feature schema.</summary>
    /// <returns>Returns true if elements states will be ignored, false otherwise. 
    /// </returns> 
    virtual FdoBoolean GetIgnoreStates();

    ///<summary>Changes the handling of element states by Execute().</summary>
    /// <param name="ignoreStates">Input True: Execute() will ignore the 
    /// element states on the Feature Schema elements. Instead, it 
    /// will additively merge the Feature Schema into the current DataStore.
    /// False: Execute() will use the element states to determine whether
    /// each element is inserted, modified or deleted.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetIgnoreStates( FdoBoolean ignoreStates );

    ///<summary>Executes the ApplySchema command that creates metadata and physical
    ///storage for the schema. An exception is thrown if the schema already
    ///exists or if a schema already exists and the feature provider only
    ///supports a single schema. If schema changes include deletion of classes
    ///or the schema itself, then those classes (or the schema, if it is marked
    ///as deleted) must not contain any instance data. If they do, an exception
    ///will be thrown.</summary>
    /// <returns>Returns nothing</returns> 
    virtual void Execute ();
};

#endif // __SUPERMAP_APPLYSCHEMACOMMAND_H__
