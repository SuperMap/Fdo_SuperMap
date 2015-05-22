#ifndef FDO_SCHEMA_MERGECONTEXT_H
#define FDO_SCHEMA_MERGECONTEXT_H
// 

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#include <FdoStd.h>
#include <Fdo/Schema/FeatureSchemaCollection.h>
#include <Fdo/Schema/FeatureClass.h>
#include <Fdo/Schema/NetworkLinkFeatureClass.h>
#include <Fdo/Schema/NetworkClass.h>
#include <Fdo/Schema/NetworkNodeFeatureClass.h>
#include <Fdo/Schema/RasterPropertyDefinition.h>
#include <Fdo/Schema/UniqueConstraint.h>
#include <Fdo/Schema/ObjectPropertyDefinition.h>
#include <Fdo/Xml/Flags.h>

/// \cond DOXYGEN-IGNORE

/// \brief
/// FdoSchemaMergeContext provides support for updating a set of feature schemas
/// base on a second set of schemas. It's main purpose is to support the reading 
/// of feature schemas from XML and the IApplySchema command implementations of 
/// certain providers (e.g. SDF Provider). 
///
/// The schema updates can be done as an additive merge or based on the element states
/// in the second set of schemas.
///
/// \warning This class is not yet part of the FDO API and is subject to change in the 
/// future. It's functions are exported for use by the SDF Provider.
class FdoSchemaMergeContext : public FdoContext
{
public:
    /// \brief
    /// Constructs the Schema Merge Context
    /// 
    /// \param schemas 
    /// Input the features schemas to updated.
    ///
    /// \param defaultCapability
    /// Input if true, then all types of schema element modifications are allowed by default.
    /// If false then none are allowed by default.
    /// 
    /// 
    /// \return
    /// Returns FdoSchemaMergeContext
    /// 
    FDO_API static FdoSchemaMergeContext* Create( FdoFeatureSchemaCollection* schemas, bool defaultCapability = false  );

    /// \brief
    /// Gets the current IgnoreStates setting
    ///
    /// \return
    /// Returns true if element states on second set of schemas are ignored. Second set of schemas
    /// is additively merged into schemas to update.
    /// Returns false if element states determine how schemas are merged
    /// 
    FDO_API bool GetIgnoreStates();

    /// \brief
    /// Sets the IgnoreStates setting
    /// 
    /// \param ignoreStates 
    /// Input the new IgnoreStates setting.
    ///
    FDO_API void SetIgnoreStates( bool ignoreStates );

    /// \brief
    /// Gets the current ReplaceClass setting
    ///
    /// \return
    /// Returns true if properties, in the schemas to update, are deleted if not 
    /// present in the second set of schemas.
    /// Returns false if class properties are additively merged (Properties in scheams
    /// to update are kept, even if not present in second set of schemas).
    /// 
    FDO_API virtual bool GetReplaceClass();
    
    /// \brief
    /// Sets the ReplaceClass setting
    /// 
    /// \param replaceClass 
    /// Input the new ReplaceClass setting.
    ///
    FDO_API virtual void SetReplaceClass( bool replaceClass );

    /// \brief
    /// Gets the current CopyElement setting
    ///
    /// \return
    /// Returns true elements are always copied when the schemas are merged.
    /// Returns false if it is ok to simply move elements from the second set of 
    /// schems to the schemas to update. CopyElements should only be false when
    /// the second set of schemas will be discarded when the schema merge is complete
    /// 
    FDO_API virtual bool GetCopyElements();
    
    /// \brief
    /// Sets the CopyElements setting
    /// 
    /// \param copyElements 
    /// Input the new CopyElements setting.
    ///
    FDO_API virtual void SetCopyElements( bool copyElements );

    /// \brief
    /// Gets the current error level. Determines how strict the error checking is.
    ///
    /// \return
    /// Returns current error level.
    /// 
    FdoXmlFlags::ErrorLevel GetErrorLevel();

    /// \brief
    /// Sets the current error level
    /// 
    /// \param errorLevel 
    /// Input the new error level.
    ///
    void SetErrorLevel( FdoXmlFlags::ErrorLevel errorLevel );

    /// \brief
    /// Gets the schemas to update
    ///
    /// \return
    /// Returns FdoFeatureSchemaCollection
    /// 
	FDO_API FdoFeatureSchemaCollection* GetSchemas() const;

    /// \brief
    /// Gets the second set of schemas.
    ///
    /// \return
    /// Returns FdoFeatureSchemaCollection
    /// 
	FdoPtr<FdoFeatureSchemaCollection> GetUpdSchemas() const;

    /// \brief
    /// Sets the second set of schemas. This function must only be used
    /// when the current IgnoreStates setting is true.
    /// 
    /// \param schemas 
    /// Input the schemas.
    ///
    FDO_API void SetUpdSchemas( FdoFeatureSchemaCollection* schemas );

    /// \brief
    /// Sets the second set of schemas to be a single feature schema.
    /// This gets around a problem where a feature schema's element
    /// state is always changed to "Added" when it is added to a collection.
    /// 
    /// \param schemas 
    /// Input the schema.
    ///
    FDO_API void SetUpdSchema( FdoFeatureSchema* schema );

    /// \brief
    /// Gets the FDO connection used by this context. 
    ///
    /// \return
    /// Returns FdoIConnection. NULL if there is no current connection
    /// 
    FDO_API FdoIConnection* GetConnection();

    /// \brief
    /// Sets the FDO connection used by this context. If a connection is
    /// provided then this context can do extra error checking based on
    /// the connection's provider capabilities and datastore contents.
    /// 
    /// \param connection 
    /// Input the FDO connection.
    ///
    FDO_API void SetConnection( FdoIConnection* connection );

    /// \brief
    /// Merges the second set of schemas into the schemas to update.
    /// Resolves all references. If there
    /// are any errors these are thrown. 
    ///
    FDO_API void CommitSchemas();

    // The following functions check whether certain schema element modifications
    // can be carried out. Each calls the corresponding Can* function to see if the
    // modification is supported at all. If it is then the element is examined 
    // further to see if the modification can be done. If this context is provided
    // a connection, the connection is also check to see if the modification is
    // allowed (for example class delete is disallowed if the connected datastore
    // has any objects of that class definition.
    //
    // Each function returns true of the modification can be performed and false if not.
    // An error is logged if the modification cannot be performed.

    FDO_API virtual bool CheckDeleteClass( FdoClassDefinition* classDef );

    FDO_API virtual bool CheckAddProperty( FdoPropertyDefinition* prop );

	FDO_API virtual bool CheckDeleteProperty( FdoPropertyDefinition* prop );

    FDO_API virtual bool CheckDeleteSchema( FdoFeatureSchema* schema );

    // The following functions represent each type of schema element modification.
    // Each returns true if the modification is allowed.
    //
    // The return value is the defaultCapability passed to the Create() function. 
    // Sub-classes can override any of these functions if their return value needs
    // to differ from the default capability. 
    //
    // For example, if only 3 modifications are supported then set default capability
    // to false and override the 3 functions, for these modifications, to return true.


    FDO_API virtual bool CanModElementDescription( FdoSchemaElement* element );


    FDO_API virtual bool CanAddSchema( FdoFeatureSchema* schema );
    FDO_API virtual bool CanDeleteSchema( FdoFeatureSchema* schema );
    FDO_API virtual bool CanModSchemaName( FdoFeatureSchema* schema );

    FDO_API virtual bool CanAddClass( FdoClassDefinition* classDef );
    FDO_API virtual bool CanDeleteClass( FdoClassDefinition* classDef );
    FDO_API virtual bool CanModClassName( FdoClassDefinition* classDef );
    FDO_API virtual bool CanModBaseClass( FdoClassDefinition* classDef );
    FDO_API virtual bool CanModClassAbstract( FdoClassDefinition* classDef );
    FDO_API virtual bool CanModIdProps( FdoClassDefinition* classDef );

    FDO_API virtual bool CanModFeatGeometry( FdoFeatureClass* classDef );

    FDO_API virtual bool CanModNetLayer( FdoNetworkClass* classDef );

    FDO_API virtual bool CanModNetCost( FdoNetworkFeatureClass* classDef );
    FDO_API virtual bool CanModNetProp( FdoNetworkFeatureClass* classDef );
    FDO_API virtual bool CanModNetFeat( FdoNetworkFeatureClass* classDef );
    FDO_API virtual bool CanModNetParent( FdoNetworkFeatureClass* classDef );

    FDO_API virtual bool CanModLinkStartNode( FdoNetworkLinkFeatureClass* classDef );
    FDO_API virtual bool CanModLinkEndNode( FdoNetworkLinkFeatureClass* classDef );

    FDO_API virtual bool CanModNodeLayer( FdoNetworkNodeFeatureClass* classDef );

    FDO_API virtual bool CanAddProperty( FdoPropertyDefinition* prop );
    FDO_API virtual bool CanDeleteProperty( FdoPropertyDefinition* prop );
    FDO_API virtual bool CanModPropertyName( FdoPropertyDefinition* prop );

    FDO_API virtual bool CanModDataType( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDefaultValue( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataNullable( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataLength( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataPrecision( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataScale( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataAutoGenerated( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataReadOnly( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanModDataConstraint( FdoDataPropertyDefinition* prop );
    FDO_API virtual bool CanRestrictDataConstraint( FdoDataPropertyDefinition* prop );

    FDO_API virtual bool CanModGeomTypes( FdoGeometricPropertyDefinition* prop );
    FDO_API virtual bool CanModGeomElevation( FdoGeometricPropertyDefinition* prop );
    FDO_API virtual bool CanModGeomMeasure( FdoGeometricPropertyDefinition* prop );
    FDO_API virtual bool CanModGeomSC( FdoGeometricPropertyDefinition* prop );
    FDO_API virtual bool CanModGeomReadOnly( FdoGeometricPropertyDefinition* prop );

    FDO_API virtual bool CanModAssocClass( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocReverseName( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocDeleteRule( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocLockCascade( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocMultiplicity( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocReverseMultiplicity( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocIdentity( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocReverseIdentity( FdoAssociationPropertyDefinition* prop );
    FDO_API virtual bool CanModAssocReadOnly( FdoAssociationPropertyDefinition* prop );

    FDO_API virtual bool CanModObjClass( FdoObjectPropertyDefinition* prop );
    FDO_API virtual bool CanModObjId( FdoObjectPropertyDefinition* prop );
    FDO_API virtual bool CanModObjType( FdoObjectPropertyDefinition* prop );
    FDO_API virtual bool CanModObjOrder( FdoObjectPropertyDefinition* prop );

    FDO_API virtual bool CanModRasterReadOnly( FdoRasterPropertyDefinition* prop );
    FDO_API virtual bool CanModRasterNullable( FdoRasterPropertyDefinition* prop );
    FDO_API virtual bool CanModRasterModel( FdoRasterPropertyDefinition* prop );
    FDO_API virtual bool CanModRasterXSize( FdoRasterPropertyDefinition* prop );
    FDO_API virtual bool CanModRasterYSize( FdoRasterPropertyDefinition* prop );
    FDO_API virtual bool CanModRasterSC( FdoRasterPropertyDefinition* prop );

    /// \brief
    /// Checks if a class has objects.
    ///
    /// \warning This function is used as a pre-check to see if a class definition can 
    /// be deleted. However, there is a chance that the class has no objects when this
    /// check is done, but an object is created by someone else before the class is 
    /// deleted. Providers that need to prevent this race condition can do so by 
    /// extending this function.
    /// 
    /// \param classDef
    /// Input the class to check
    ///
    /// \return
    /// Returns true if the class has objects ( the datastore for the current connection
    /// is checked for objects).
    /// Returns false if the class does not have objects or this context does not have
    /// a connection.
    FDO_API virtual bool ClassHasObjects( FdoClassDefinition* classDef );

    // When the schemas are merged. references between schema elements cannot be resolved
    // right away, since the referenced element might not yet have been copied to the 
    // schemas to update. Therefore, the merge process simply builds lists of these
    // references and then resolves them after the merge is complete. 

    // The following functions support building the lists of referneces

    // Add reference between qualified name of schema element and actual object.
    // This may start as an element in the second set of schemas, but then changes
    // to the corresponding element in the schemas to update, after the element
    // has been copied to the schemas to update
    void AddElementMap( FdoSchemaElement* pElement );

    // Adds a reference between a class and its base class.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the class.
    //      schemaName - base class schema name.
    //      className - base class name.
    void AddBaseClassRef( FdoClassDefinition* pReferencer, FdoString* schemaName, FdoString* className );

    // Adds a reference between an object property and its class.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the object property.
    //      schemaName - class schema name.
    //      className - class name.
    void AddObjPropRef( FdoObjectPropertyDefinition* pReferencer, FdoString* schemaName, FdoString* className );


    // Adds a reference between a network node feature class and the layer association proeprty.
    //
    // Parameters:
    //      pReferencer - the network node feature class.
    //      assoc - the layer association property name
    //      
    void AddNetworkNodeAssocPropRef( FdoNetworkNodeFeatureClass* pReferencer, FdoString* assoc );

    // Adds a reference between a network link feature class and the start association property.
    //
    // Parameters:
    //      pReferencer - the network link feature class.
    //      assoc - the start association property name
    void AddNetworkLinkStartAssocPropRef( FdoNetworkLinkFeatureClass* pReferencer, FdoString* assoc );

    // Adds a reference between a network link feature class and the end association property.
    //
    // Parameters:
    //      pReferencer - the network link feature class.
    //      assoc - the end association property name
    void AddNetworkLinkEndAssocPropRef( FdoNetworkLinkFeatureClass* pReferencer, FdoString* assoc );

    // Adds a reference between a network feature class and the cost association property.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the network feature class
    //      cost - the cost association property name
    void AddNetworkFeatureCostPropRef( FdoNetworkFeatureClass* pReferencer, FdoString* cost );


    // Adds a reference between a network feature and the network property association property.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the network feature class
    //      networkProp - the association network property name
    void AddNetworkFeatureNetworkPropRef( FdoNetworkFeatureClass* pReferencer, FdoString* networkProp );

    // Adds a reference between a network feature class and the reference feature association property.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the network feature class
    //      refFeatProp - the reference feature property association name
    void AddNetworkFeatureRefFeatPropRef( FdoNetworkFeatureClass* pReferencer, FdoString* refFeatProp );

    // Adds a reference between a network feature class and the parent network feature assocaition property.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the network feature class
    //      parentNetworkFeatProp - the parent network feature association property name
    void AddNetworkFeatureParentNetworkFeatPropRef( FdoNetworkFeatureClass* pReferencer, FdoString* parentNetworkFeatProp );

    // Adds a reference between a network class and its layer class.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the network class.
    //      schemaName - class schema name.
    //      className - class name.
    void AddNetworkClassRef( FdoNetworkClass* pReferencer, FdoString* schemaName, FdoString* className );


    // Adds a reference between a associate property and its associated class.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the associate property.
    //      schemaName - associate class schema name.
    //      className - associate class name.
    void AddAssocPropRef( FdoAssociationPropertyDefinition* pReferencer, FdoString* schemaName, FdoString* className );

    // Adds a reference between a class and its identity properties.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the class
    //      idProps - the identity property names.
    void AddIdPropRef( FdoClassDefinition* pReferencer, FdoStringsP idProps );

    // Adds a reference between a class' unique constraint and its properties.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the class
	//		pUniConsRef - this class's unique constraint
    //      props - the property names.
    void AddUniqueConstraintRef( FdoClassDefinition* pClsRef, FdoUniqueConstraint* pUniConsRef, FdoStringsP props );

    // Adds a reference between an object property and its identity property.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the object property
    //      idProp - the identity property name.
    void AddObjIdPropRef( FdoObjectPropertyDefinition* pReferencer, FdoString* idProp );
    
    // Adds a reference between an association property and its identity properties.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the association property
    //      idProps - the identity property names.
    void AddAssocIdPropRef( FdoAssociationPropertyDefinition* pReferencer, FdoStringsP idProps );

    void AddAssocIdReversePropRef( FdoAssociationPropertyDefinition* pReferencer, FdoStringsP idProps );

    // Adds a reference between a feature class and its geometry property.
    // These references are resolved after all the classes have been read.
    //
    // Parameters:
    //      pReferencer - the feature class
    //      geomProp - the geometry property name.
    void AddGeomPropRef( FdoFeatureClass* pReferencer, FdoString* geomProp );

    // Adds a property value constraint to the list of constraints to validate
    // against existing property values.
    //
    // Parameters:
    //      pDataProp - the data property to which the constraint applies.
    void AddDataRestrictToCheck( FdoDataPropertyDefinition* pDataProp );

    FdoClassDefinition* FindClass( FdoFeatureSchemaCollection* pSchemas, FdoClassDefinition* pClass );
    // Find a class in the given schema collection.
    FdoClassDefinition* FindClass( FdoFeatureSchemaCollection* pSchemas, FdoString* schemaName, FdoString* className );
    
    // Checks if the given constraint modification is allowed
    //
    // Parameters:
    //      oldProp - property containing previous constraint
    //      newProp - property containing new constraint
    bool CheckModDataConstraint( FdoDataPropertyDefinition* oldProp, FdoDataPropertyDefinition* newProp );

protected:
    FDO_API FdoSchemaMergeContext() {}
    FDO_API FdoSchemaMergeContext( FdoFeatureSchemaCollection* schemas, bool defaultCapability = false );
    FDO_API virtual ~FdoSchemaMergeContext();

private:
    // Merge the schemas that were read, into the schema collection.
    void MergeSchemas();
    void MergeSchema( FdoFeatureSchema* newSchema );

    void CheckReferences();

    // Checks if the given constraint modification is allowed. The modification
    // passed in must be one that makes the constraint more restrictive.
    //
    // Parameters:
    //      oldProp - property containing previous constraint
    //      newProp - property containing new constraint
    bool CheckRestrictDataConstraint( FdoDataPropertyDefinition* oldProp, FdoDataPropertyDefinition* newProp );

    // Checks the merged schemas against their objects and features and logs errors
    // for inconsistencies. Currently, the only checks are to see if any data constraints,
    // that were made more restrictive, cause any existing property values to become
    // invalid.
    void CheckSchemasWData();

    // Various functions for resolving references.
    void ResolveBaseClasses();
    void ResolveObjPropClasses();
    void ResolveAssociatedPropClasses();
    void ResolveNetworkLinkProps();
    void ResolveNetworkProps();
    void ResolveNetworkNodeProps();
    void ResolveNetworkFeatureProps();
    void ResolveIdProps();
    void ResolveObjIdProps();
    void ResolveAssocIdProps();
    void ResolveAssocIdReverseProps();
    void ResolveGeomProps();
	void ResolveUniqueConstraints();
    // For each referencing class, without geometryProperty, pick a geometryProperty
    // for it. One is pick only if there is only geometric property on the class and
    // all of its ancestors.
    void ResolveDefaultGeomProps();

    FdoSchemaElement* MapElement( FdoSchemaElement* pElement );

    // Various functions for finding FDO elements. 

    // Find a class property. Walks up the base classes until the property is found.
    FdoPropertyDefinition* FindProperty( FdoClassDefinition* pClass, FdoString* propName, FdoBoolean checkUpdSchemas = true );
    // Find an identity property. Checks the topmost base class.
    FdoDataPropertyDefinition* GetIdProperty( FdoClassDefinition* pClass, const FdoInt32 idx, FdoBoolean checkUpdSchemas = true );

    // Gets the topmost base class for a class.
    FdoClassDefinition* GetTopClass( FdoClassDefinition* pClass );
    // Gets the base class for a class. Gets the most recent object. Returns the
    // object read from XML. If the base class was not read from XML then its
    // original object is returned.
    FdoClassDefinition* GetBaseClass( FdoClassDefinition* pClass );

    // Definition for a reference to a class.
    class ElementMap : public FdoIDisposable 
    {
    public:
        static ElementMap* Create( FdoSchemaElement* pElement );

        // Get the referencing element.
        FdoSchemaElement* GetElement();
        void SetElement( FdoSchemaElement* pElement );
        FdoStringP GetName(); 

        // Indicates that this object does not allow its name
        // to change. Not allowing name change allows more efficient 
        // random access to FdoDictionary.
        virtual FdoBoolean CanSetName()
        {
            return false;
        }

    protected:
        ElementMap() {}
        ElementMap( FdoSchemaElement* pReferencer );
        virtual ~ElementMap() {}

        virtual void Dispose();

    private:
        FdoSchemaElementP mElement;
        FdoStringP mElementName;
    };
    
    // Collection of references to classes.
    class ElementMaps : public FdoNamedCollection<ElementMap,FdoException>
    {
    protected:
        virtual void Dispose();

        ElementMaps() {}

    public:
        /// <summary>Gets the number of items in the collection.</summary>
        /// <returns>Returns number of items in the collection</returns> 
        static ElementMaps* Create()
        {
            return new  ElementMaps();
        }
    };

    // Definition for a reference to a class.
    class ClassRef : public FdoIDisposable 
    {
    public:
        static ClassRef* Create( FdoSchemaElement* pReferencer, FdoStringP schemaName, FdoStringP className );

        // Get the referencing element.
        FdoSchemaElement* GetReferencer();
        void SetReferencer( FdoSchemaElement* referencer );
        FdoSchemaElement* GetNewReferenced();
        void SetNewReferenced( FdoSchemaElement* pNewReferenced );
        FdoStringP GetSchemaName();
        FdoStringP GetClassName();
        FdoStringP GetName(); 

        // Indicates that this object does not allow its name
        // to change. Not allowing name change allows more efficient 
        // random access to FdoDictionary.
        virtual FdoBoolean CanSetName()
        {
            return false;
        }

    protected:
        ClassRef() {}
        ClassRef( FdoSchemaElement* pReferencer, FdoStringP schemaName, FdoStringP className );
        virtual ~ClassRef() {}

        virtual void Dispose();

    private:
        FdoSchemaElementP mReferencer;
        FdoSchemaElementP mNewReferenced;
        FdoStringP mReferencerName;
        FdoStringP mSchemaName;
        FdoStringP mClassName;
    };
    
    // Collection of references to classes.
    class ClassRefs : public FdoNamedCollection<ClassRef,FdoException>
    {
    protected:
        virtual void Dispose();

        ClassRefs() {}

    public:
        /// <summary>Gets the number of items in the collection.</summary>
        /// <returns>Returns number of items in the collection</returns> 
        static ClassRefs* Create()
        {
            return new  ClassRefs();
        }
    };

    // Definition of a reference to a collection of strings.
    class StringsRef : public FdoIDisposable 
    {
    public:
        static StringsRef* Create( FdoSchemaElement* pReferencer, FdoStringsP strings );

        FdoSchemaElement* GetReferencer();
        void SetReferencer( FdoSchemaElement* referencer );
        FdoStringsP GetStrings();
        FdoStringP GetName(); 

        // Indicates that this object does not allow its name
        // to change. Not allowing name change allows more efficient 
        // random access to FdoDictionary.
        virtual FdoBoolean CanSetName()
        {
            return false;
        }

    protected:
        StringsRef() {}
        StringsRef( FdoSchemaElement* pReferencer, FdoStringsP strings );
        virtual ~StringsRef() {}

        virtual void Dispose();

    private:
        FdoPtr<FdoSchemaElement> mReferencer;
        FdoStringsP mStrings;
        FdoStringP mQName;
    };
    
    // Collection of references to string collections
    class StringsRefs : public FdoNamedCollection<StringsRef,FdoException>
    {
    protected:
        virtual void Dispose();

        StringsRefs() {}

    public:
        /// <summary>Gets the number of items in the collection.</summary>
        /// <returns>Returns number of items in the collection</returns> 
        static StringsRefs* Create()
        {
            return new  StringsRefs();
        }
    };

	// Definition of a reference to unique constraint
	class UniqueConstraintRef : public FdoDisposable
	{
    public:
        static UniqueConstraintRef* Create( FdoClassDefinition* pClsRef, FdoUniqueConstraint* pUniConsRef, FdoStringsP strings );

        FdoClassDefinition* GetRefClass();
        void SetRefClass( FdoClassDefinition* referencer );
		FdoUniqueConstraint* GetRefUniqueConstraint();
        FdoStringsP GetStrings();
        FdoStringP GetName(); 

        // Indicates that this object does not allow its name
        // to change. Not allowing name change allows more efficient 
        // random access to FdoDictionary.
        virtual FdoBoolean CanSetName()
        {
            return false;
        }

    protected:
        UniqueConstraintRef() {}
        UniqueConstraintRef( FdoClassDefinition* pClsRef, FdoUniqueConstraint* pUniConsRef, FdoStringsP strings );
        virtual ~UniqueConstraintRef() {}

    private:
        FdoPtr<FdoClassDefinition> mClsRef;
		FdoPtr<FdoUniqueConstraint> mUniConsRef;
        FdoStringsP mStrings;
        FdoStringP mQName;
	};

	// Collection of references to unique constraint references
    class UniqueConstraintRefs : public FdoNamedCollection<UniqueConstraintRef,FdoException>
    {
    protected:
        virtual void Dispose();

        UniqueConstraintRefs() {}

    public:
        /// <summary>Gets the number of items in the collection.</summary>
        /// <returns>Returns number of items in the collection</returns> 
        static UniqueConstraintRefs* Create()
        {
            return new  UniqueConstraintRefs();
        }
    };

    void CopyNetworkAssocProp( FdoPtr<StringsRef> ref );

    // The current Feature Schemas
    FdoPtr<FdoFeatureSchemaCollection> mSchemas;
    // The Feature Schemas being read from the XML document.
    FdoPtr<FdoFeatureSchemaCollection> mUpdSchemas;
    FdoFeatureSchema* mUpdSchema;

    FdoPtr<FdoIConnection> mConnection;

    bool mIgnoreStates;
    bool mDefaultCapability;
    bool mReplaceClass;
    bool mCopyElements;

    // Element name to object maps.
    FdoPtr<ElementMaps> mElementMaps;
    // Base class references
    FdoPtr<ClassRefs> mBaseClassRefs;
    // Object Property class references
    FdoPtr<ClassRefs> mObjPropRefs;
    // Associate class reference
    FdoPtr<ClassRefs> mAssocPropRefs;
    // Identity property references
    FdoPtr<StringsRefs> mIdPropRefs;
	// Unique constraint references
    FdoPtr<UniqueConstraintRefs> mUniConsRefs;
    // Object Property identity property references
    FdoPtr<StringsRefs> mObjIdPropRefs;

    // Network Node association property references
    FdoPtr<StringsRefs> mNetworkNodeAssocPropRefs;
    // Network Link Start association property reference
    FdoPtr<StringsRefs> mNetworkLinkStartAssocPropRefs;
    // Network Link End association property reference
    FdoPtr<StringsRefs> mNetworkLinkEndAssocPropRefs;
    // Network Feature Cost property reference
    FdoPtr<StringsRefs> mNetworkFeatureCostPropRefs;
    // Network Feature network property reference
    FdoPtr<StringsRefs> mNetworkFeatureNetworkPropRefs;
    // Network Feature reference feature property reference
    FdoPtr<StringsRefs> mNetworkFeatureRefFeatPropRef;
    // Network Feature parent network feature property reference
    FdoPtr<StringsRefs> mNetworkFeatureParentNetworkFeatPropRef;
    // Network reference 
    FdoPtr<ClassRefs> mNetworkRefs;

    // Association Property identity property references
    FdoPtr<StringsRefs> mAssocIdPropRefs;
    // Association Property identity reverse property references
    FdoPtr<StringsRefs> mAssocIdReversePropRefs;

    // Geometry property references.
    FdoPtr<StringsRefs> mGeomPropRefs;

    FdoPtr<StringsRefs> mDataRestrictToCheck;

    FdoXmlFlags::ErrorLevel mErrorLevel;

    FdoDictionaryP mClassHasObjects;
};

/// \brief
/// FdoSchemaMergeContextP is a FdoPtr on FdoSchemaMergeContext, provided for convenience.
typedef FdoPtr<FdoSchemaMergeContext> FdoSchemaMergeContextP;
/// \endcond

#endif


