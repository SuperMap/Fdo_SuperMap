/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  *
 */

#ifndef FdoCommonSchemaUtil___H
#define FdoCommonSchemaUtil___H	1

#include <Fdo/Commands/IdentifierCollection.h>
#include <Fdo/Schema/AssociationPropertyDefinition.h>
#include <Fdo/Schema/FeatureSchemaCollection.h>
#include <Fdo/Schema/Class.h>
#include <Fdo/Schema/RasterPropertyDefinition.h>
#include <map>

// A Map that will allow copied schema elements to be tracked and will 
// prevent duplicate elements from being copied.
typedef std::map <FdoSchemaElement*, FdoSchemaElement*> FdoSchemaElementMap;
typedef std::pair <FdoSchemaElement*, FdoSchemaElement*> FdoSchemaElementPair;
typedef FdoSchemaElementMap::const_iterator FdoSchemaElementMapIterator;

// A context class used to assist in copying schema elemts. The contained map assists in avoiding duplicate objects being copied.
class FdoCommonSchemaCopyContext : public FdoDisposable
{
public:
    static FdoCommonSchemaCopyContext* Create(FdoIdentifierCollection* constraints = NULL, FdoBoolean useReadOnlyClassCapabilities = false);

public:
    /// return a const element map containing the copied elements
    const FdoSchemaElementMap * GetSchemaElementMap();

    /// insert a new source/copy pair into the element map
    void InsertSchemaElement(FdoSchemaElement* sourceElement, FdoSchemaElement *copyElement);

    /// find a copied element in the map based on it's source
    template <typename T> T* FindSchemaElement(T* elem)
    {
        if (m_schemaMap == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        T* retElem = NULL;

        FdoSchemaElementMapIterator elementIterator = m_schemaMap->find(elem);
        if (elementIterator != m_schemaMap->end()) {
            retElem = dynamic_cast<T*>(elementIterator->second);
            if (retElem == NULL) {
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(CLNT_3_NULLPOINTER)));
            }
        }

        return FDO_SAFE_ADDREF(retElem);
    }

    /// Set the identifier list that will constrain the list of copied properties
    void SetIdentifierConstraints(FdoIdentifierCollection *idCollection);

    /// Get the identifier list constrains the list of copied properties
    FdoIdentifierCollection* GetIdentifierConstraints();

    /// Enable/Disable the the constraint of copied properties
    void EnableIdentifierConstraints(FdoBoolean bEnableConstraints);

    /// Are identifier constraints Enabled/Disabled
    FdoBoolean IdentifierConstraintsEnabled();

    /// Override source schema capabilities with Read Only schema capabilities
    void ApplyReadOnlyClassCapabilities(FdoBoolean bReadOnly);

    /// Are overriden Read Only schema capabilities Enabled/Disabled
    FdoBoolean ReadOnlyClassCapabilitiesEnabled();

protected:
    FdoCommonSchemaCopyContext(FdoIdentifierCollection* constraints = NULL, FdoBoolean useReadOnlyClassCapabilities = false);
    FdoCommonSchemaCopyContext(const FdoCommonSchemaCopyContext &right);
    FdoCommonSchemaCopyContext & operator=(const FdoCommonSchemaCopyContext &right);
    virtual ~FdoCommonSchemaCopyContext();
    virtual void Dispose();

private:
    FdoSchemaElementMap * m_schemaMap;
    FdoBoolean m_readOnlyClassCapabilities;
    FdoBoolean m_identifierConstraintsEnabled;
    FdoPtr<FdoIdentifierCollection> m_identifierConstraints;
};

typedef FdoPtr<FdoCommonSchemaCopyContext> FdoCommonSchemaCopyContextP;

// A set of utility functionas that will assist in copying schema elements.
class FdoCommonSchemaUtil
{
public:

    /// Deep-copy an FDO schema collection.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoFeatureSchemaCollection * DeepCopyFdoFeatureSchemas(FdoFeatureSchemaCollection * schemas, FdoString * schemaName = NULL);

    /// Deep-copy an FDO schema.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoFeatureSchema * DeepCopyFdoFeatureSchema(FdoFeatureSchema * schema, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO class Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoClassDefinition * DeepCopyFdoClassDefinition(FdoClassDefinition * sourceClass, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO class (Non-Feature).
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoClass * DeepCopyFdoClass(FdoClass * sourceClass, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Feature class.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoFeatureClass * DeepCopyFdoFeatureClass(FdoFeatureClass * sourceClass, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Property Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoPropertyDefinition * DeepCopyFdoPropertyDefinition(FdoPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Data Property Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoDataPropertyDefinition * DeepCopyFdoDataPropertyDefinition(FdoDataPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Geometric Property Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoGeometricPropertyDefinition * DeepCopyFdoGeometricPropertyDefinition(FdoGeometricPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Raster Property Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoRasterPropertyDefinition * DeepCopyFdoRasterPropertyDefinition(FdoRasterPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Object Property Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoObjectPropertyDefinition * DeepCopyFdoObjectPropertyDefinition(FdoObjectPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy an FDO Association Property Definition.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static FdoAssociationPropertyDefinition * DeepCopyFdoAssociationPropertyDefinition(FdoAssociationPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy FDO Class capabilities and constraints.
    /// This is guaranteed to never return NULL (will throw a FdoException on error).
    static void DeepCopyFdoClassCapabilitiesAndConstraints(FdoClassDefinition* sourceClass, FdoClassDefinition* copyClass, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy the computed properties of an FDO class Definition.
    static void DeepCopyFdoComputedClassProperties(FdoClassDefinition * sourceClass, FdoClassDefinition * copyClass, FdoCommonSchemaCopyContext * schemaContext = NULL);


    /// Returns the requested logical class definition, paring it down to the given property list
    static FdoClassDefinition* GetLogicalClassDefinition (FdoIConnection* connection, FdoString* logicalClassName, FdoIdentifierCollection* selectedProperties);

    /// Returns true if the given property name corresponds to an identity property of the given class definition:
    static bool IsIdentityProperty(FdoClassDefinition* pClassDef, FdoString *propertyName);

    /// Deep-copy the common elements of an FDO schema element:
    static void DeepCopyFdoSchemaElementDetails(FdoSchemaElement* copyElement, FdoSchemaElement* sourceElement);

    /// Copy an FdoDataValue (more accurate than doing destDataValue = FdoDataValue::Parse(sourceDataValue->ToString())):
    static FdoDataValue* CopyDataValue(FdoDataValue* sourceDataValue);

    /// Adds all the FdoComputedIdentifiers found in selectedIds to destClass as property definitions :
    static void AddComputedIdentifiersAsProperties(FdoIConnection* connection, FdoClassDefinition* destClass, FdoClassDefinition* originalClass, FdoIdentifierCollection* selectedIds);


protected:

    /// Determine if the given property should be copied.
    static FdoBoolean ClassPropertyShouldBeCopied(FdoPropertyDefinition* classProperty, FdoCommonSchemaCopyContext * schemaContext);

    /// Deep-copy the common elements of an FDO class Definition.
    static void DeepCopyFdoClassDefinitionDetails(FdoClassDefinition * sourceClass, FdoClassDefinition * copyClass, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy a single type of FDO property in a collection.
    static void DeepCopyFdoPropertyType(FdoPropertyDefinitionCollection *properties, FdoPropertyDefinitionCollection *newProperties, FdoPropertyType propertyType, FdoCommonSchemaCopyContext * schemaContext = NULL);

    /// Deep-copy FDO Data Property Definitions.
    static void DeepCopyFdoPropertyType(FdoDataPropertyDefinitionCollection *properties, FdoPropertyDefinitionCollection *newProperties, FdoCommonSchemaCopyContext * schemaContext);

    /// Copy references to FDO named Data property identified by name in sourceProperties and contained in newProperties into the destionation collection.
    static void CopyFdoNamedDataProperties(FdoDataPropertyDefinitionCollection *sourceProperties, FdoPropertyDefinitionCollection *newProperties, FdoReadOnlyPropertyDefinitionCollection *newBaseProperties, FdoDataPropertyDefinitionCollection *destProperties, FdoCommonSchemaCopyContext * schemaContext = NULL);

};

#endif // FdoCommonSchemaUtil___H


