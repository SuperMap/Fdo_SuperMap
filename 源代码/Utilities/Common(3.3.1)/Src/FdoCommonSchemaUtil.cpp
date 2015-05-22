/*
 * 
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

#include "stdafx.h"
#include <FdoCommonSchemaUtil.h>
#include <FdoCommonMiscUtil.h>


/////////////////////////////
/////////////////////////////

FdoCommonSchemaCopyContext* FdoCommonSchemaCopyContext::Create(FdoIdentifierCollection* constraints, FdoBoolean useReadOnlyClassCapabilities)
{
    FdoCommonSchemaCopyContext* pObject = new FdoCommonSchemaCopyContext(constraints, useReadOnlyClassCapabilities);
    if (pObject == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }
    return pObject;
}

FdoCommonSchemaCopyContext::FdoCommonSchemaCopyContext(FdoIdentifierCollection* constraints, FdoBoolean useReadOnlyClassCapabilities) :
    m_identifierConstraints(constraints),
    m_readOnlyClassCapabilities(useReadOnlyClassCapabilities)
{
    m_schemaMap = new FdoSchemaElementMap;
    if (m_schemaMap == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FDO_SAFE_ADDREF(m_identifierConstraints.p);
    m_identifierConstraintsEnabled = (m_identifierConstraints == NULL) ? (false) : (true);
}

FdoCommonSchemaCopyContext::~FdoCommonSchemaCopyContext()
{
    if (m_schemaMap != NULL) {
        FdoSchemaElementMapIterator elementIterator = m_schemaMap->begin();
        while (elementIterator != m_schemaMap->end()) {
            FdoSchemaElement* fisrtElement = elementIterator->first;
            FDO_SAFE_RELEASE(fisrtElement);

            FdoSchemaElement* secondElement = elementIterator->second;
            FDO_SAFE_RELEASE(secondElement);

            elementIterator++;
        }

        delete m_schemaMap;
        m_schemaMap = NULL;
    }
}

void FdoCommonSchemaCopyContext::Dispose()
{
    delete this;
}

const FdoSchemaElementMap * FdoCommonSchemaCopyContext::GetSchemaElementMap()
{
    return m_schemaMap;
}

void FdoCommonSchemaCopyContext::InsertSchemaElement(FdoSchemaElement* sourceElement, FdoSchemaElement *copyElement)
{
    if (sourceElement == NULL || copyElement == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::InsertSchemaElement",
                                                               L"sourceElement/copyElement"));
    }

    if (m_schemaMap == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    m_schemaMap->insert(FdoSchemaElementPair(FDO_SAFE_ADDREF(sourceElement), FDO_SAFE_ADDREF(copyElement)));
}

// Set the identifier list that will constrain the list of copied properties
void FdoCommonSchemaCopyContext::SetIdentifierConstraints(FdoIdentifierCollection *idCollection)
{
    FDO_SAFE_RELEASE(m_identifierConstraints.p);
    FDO_SAFE_ADDREF(idCollection);
    m_identifierConstraints = idCollection;
}

// Get the identifier list that will constrain the list of copied properties
FdoIdentifierCollection* FdoCommonSchemaCopyContext::GetIdentifierConstraints()
{
   return FDO_SAFE_ADDREF(m_identifierConstraints.p);
}

// Enable/Disable the identifier list that will constrain the list of copied properties
void FdoCommonSchemaCopyContext::EnableIdentifierConstraints(FdoBoolean bEnableConstraints)
{
    m_identifierConstraintsEnabled = bEnableConstraints;
}

// Are identifier list constraints Enabled/Disabled
FdoBoolean FdoCommonSchemaCopyContext::IdentifierConstraintsEnabled()
{
    return m_identifierConstraintsEnabled;
}

// Enable/Disable the identifier list that will constrain the list of copied properties
void FdoCommonSchemaCopyContext::ApplyReadOnlyClassCapabilities(FdoBoolean bReadOnly)
{
    m_readOnlyClassCapabilities = bReadOnly;
}

// Are identifier list constraints Enabled/Disabled
FdoBoolean FdoCommonSchemaCopyContext::ReadOnlyClassCapabilitiesEnabled()
{
    return m_readOnlyClassCapabilities;
}

/////////////////////////////
/////////////////////////////


void FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(FdoSchemaElement* copyElement, FdoSchemaElement* sourceElement)
{
    if (( copyElement == NULL ) || (sourceElement == NULL)) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoSchemaElementDetails",
                                                               L"sourceElement/copyElement"));
    }

    // NOTE: copying name and description is already done during Create() calls

    // NOTE: setting the parent is already done when adding the child to it's parent's collection

    // copy the schema attribute dictionary:
    FdoPtr<FdoSchemaAttributeDictionary> sourceAttributes = sourceElement->GetAttributes ();
    FdoPtr<FdoSchemaAttributeDictionary> copyAttributes = copyElement->GetAttributes ();
    FdoInt32 length;
    FdoString** sourceAttrNames = sourceAttributes->GetAttributeNames (length);
    for (int i = 0; i < length; i++)
    {
        FdoString* sourceAttrName = sourceAttrNames[i];
        copyAttributes->Add (sourceAttrName, sourceAttributes->GetAttributeValue (sourceAttrName));
    }
}

FdoFeatureSchemaCollection * FdoCommonSchemaUtil::DeepCopyFdoFeatureSchemas(FdoFeatureSchemaCollection * schemas, FdoString * schemaName)
{
    if ( schemas == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoFeatureSchemas",
                                                               L"schemas"));
    }

    FdoCommonSchemaCopyContextP copyContext = FdoCommonSchemaCopyContext::Create(NULL);
    if (copyContext == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoPtr<FdoFeatureSchemaCollection> newSchemas = FdoFeatureSchemaCollection::Create(NULL);
    if ( newSchemas == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    if ( schemaName != NULL && wcscmp(schemaName, L"") != 0 ) {
        FdoPtr<FdoFeatureSchema> pSchema = schemas->GetItem(schemaName);
        if (pSchema == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        FdoPtr<FdoFeatureSchema> newSchema = DeepCopyFdoFeatureSchema(pSchema.p, copyContext);
        newSchemas->Add(newSchema);
    }
    else {
        for (FdoInt32 i=0;  i<schemas->GetCount(); i++) {
            FdoPtr<FdoFeatureSchema> pSchema = schemas->GetItem(i);
            if (pSchema == NULL) {
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
            }

            FdoPtr<FdoFeatureSchema> newSchema = DeepCopyFdoFeatureSchema(pSchema.p, copyContext);
            newSchemas->Add(newSchema);
        }
    }

    // Mark all schema elements as "unchanged":
    for (FdoInt32 k=0;  k<newSchemas->GetCount(); k++) {
        FdoPtr<FdoFeatureSchema> pNewSchema = newSchemas->GetItem(k);
        if (pNewSchema == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        pNewSchema->AcceptChanges();
    }

    FDO_SAFE_ADDREF(newSchemas.p);
    return newSchemas;
}

FdoFeatureSchema * FdoCommonSchemaUtil::DeepCopyFdoFeatureSchema(FdoFeatureSchema * schema, FdoCommonSchemaCopyContext * schemaContext)
{
    if (schema == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoFeatureSchema",
                                                               L"schema"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoFeatureSchemaP retSchema = localSchemaContext->FindSchemaElement(schema);
    if (retSchema != NULL) {
        return FDO_SAFE_ADDREF(retSchema.p);
    }

    FdoPtr<FdoFeatureSchema> newSchema = FdoFeatureSchema::Create(schema->GetName(), schema->GetDescription());
    if ( newSchema == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newSchema, schema);

    FdoPtr<FdoClassCollection> classes = schema->GetClasses();
    if (classes == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoClassCollection> newClasses = newSchema->GetClasses();
    if (newClasses == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    for (FdoInt32 i=0; i<classes->GetCount(); i++) {
        FdoPtr<FdoClassDefinition> pClass = classes->GetItem(i);
        if (pClass == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }
        FdoPtr<FdoClassDefinition> newClass = DeepCopyFdoClassDefinition(pClass, localSchemaContext);
        newClasses->Add(newClass);
    }

    newSchema->AcceptChanges();
    localSchemaContext->InsertSchemaElement(schema, newSchema);

    FDO_SAFE_ADDREF(newSchema.p);
    return newSchema;
}

FdoClassDefinition * FdoCommonSchemaUtil::DeepCopyFdoClassDefinition(FdoClassDefinition * sourceClass, FdoCommonSchemaCopyContext * schemaContext)
{
    if (sourceClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoClassDefinition",
                                                               L"sourceClass"));
    }

    FdoClassDefinitionP newClass;

#pragma message ("TODO: Support the deep copy of Network Classes.")

    switch (sourceClass->GetClassType())
    {
    case FdoClassType_Class:
        newClass = DeepCopyFdoClass(static_cast<FdoClass*>(sourceClass), schemaContext);
        break;
    case FdoClassType_FeatureClass:
        newClass = DeepCopyFdoFeatureClass(static_cast<FdoFeatureClass*>(sourceClass), schemaContext);
        break;
    case FdoClassType_NetworkClass:
    case FdoClassType_NetworkLayerClass:
    case FdoClassType_NetworkNodeClass:
    case FdoClassType_NetworkLinkClass:
    default:
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
    }

    FDO_SAFE_ADDREF(newClass.p);
    return newClass;
}

FdoClass * FdoCommonSchemaUtil::DeepCopyFdoClass(FdoClass * sourceClass, FdoCommonSchemaCopyContext * schemaContext)
{
    if (sourceClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoClass",
                                                               L"sourceClass"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoClassP retClass = localSchemaContext->FindSchemaElement(sourceClass);
    if (retClass != NULL) {
        return FDO_SAFE_ADDREF(retClass.p);
    }

    FdoPtr<FdoClass> newClass = FdoClass::Create(sourceClass->GetName(), sourceClass->GetDescription());
    if (newClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }
	
	// Add the copied class to the schema context map before copying the properties as
	// some property may depend on the new class. For example the association property 
	// need to find the associated class.
	localSchemaContext->InsertSchemaElement(sourceClass, newClass);

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newClass, sourceClass);

    FdoCommonSchemaUtil::DeepCopyFdoClassDefinitionDetails(sourceClass, newClass, localSchemaContext);


    FDO_SAFE_ADDREF(newClass.p);
    return newClass;
}

FdoFeatureClass * FdoCommonSchemaUtil::DeepCopyFdoFeatureClass(FdoFeatureClass * sourceClass, FdoCommonSchemaCopyContext * schemaContext)
{
    if (sourceClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoFeatureClass",
                                                               L"sourceClass"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoFeatureClassP retClass = localSchemaContext->FindSchemaElement(sourceClass);
    if (retClass != NULL) {
        return FDO_SAFE_ADDREF(retClass.p);
    }

    FdoPtr<FdoFeatureClass> newClass = FdoFeatureClass::Create(sourceClass->GetName(), sourceClass->GetDescription());
    if (newClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

	// Add the copied class to the schema context map before copying the properties as
	// some property may depend on the new class. For example the association property 
	// need to find the associated class.
	localSchemaContext->InsertSchemaElement(sourceClass, newClass);

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newClass, sourceClass);

    FdoCommonSchemaUtil::DeepCopyFdoClassDefinitionDetails(sourceClass, newClass, localSchemaContext);

    FdoGeometricPropertyP geometricProperty = sourceClass->GetGeometryProperty();
    if (geometricProperty != NULL) {
        FdoPtr<FdoPropertyDefinitionCollection> properties = newClass->GetProperties();
        if (properties == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        for (int k=0; k<properties->GetCount(); k++) {
            FdoPtr<FdoPropertyDefinition> property = properties->GetItem(k);
            if (property == NULL) {
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
            }

            if (property->GetPropertyType() == FdoPropertyType_GeometricProperty) {
                if (FdoStringP(property->GetName()) == FdoStringP(geometricProperty->GetName())) {
                    if (FdoCommonSchemaUtil::ClassPropertyShouldBeCopied(property, schemaContext)) {
                        newClass->SetGeometryProperty(static_cast<FdoGeometricPropertyDefinition*>(property.p));
                    }
                    break;
                }
            }
        }
    }


    FDO_SAFE_ADDREF(newClass.p);
    return newClass;
}

void FdoCommonSchemaUtil::DeepCopyFdoClassDefinitionDetails(FdoClassDefinition * sourceClass, FdoClassDefinition * copyClass, FdoCommonSchemaCopyContext * schemaContext)
{
    if (sourceClass == NULL || copyClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoClassDefinitionDetails",
                                                               L"sourceClass/copyClass"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    copyClass->SetIsAbstract(sourceClass->GetIsAbstract());
    copyClass->SetIsComputed(sourceClass->GetIsComputed());

    // Retrieve the classes and collection objects from the source and destination classes 
    // that will be used to hold the properties being queried and maniplulated 

    FdoClassDefinitionP baseClass = sourceClass->GetBaseClass();
    if (baseClass != NULL) {
        FdoClassDefinitionP newBaseClass = FdoCommonSchemaUtil::DeepCopyFdoClassDefinition(baseClass, localSchemaContext);
        copyClass->SetBaseClass(newBaseClass);
    }

    FdoPtr<FdoReadOnlyPropertyDefinitionCollection> baseProperties = sourceClass->GetBaseProperties();
    if (baseProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoPropertyDefinitionCollection> newBaseProperties = FdoPropertyDefinitionCollection::Create(NULL);
    if (newBaseProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoDataPropertyDefinitionCollection> identityProperties = sourceClass->GetIdentityProperties();
    if (identityProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoDataPropertyDefinitionCollection> newIdentityProperties = copyClass->GetIdentityProperties();
    if (newIdentityProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoPropertyDefinitionCollection> properties = sourceClass->GetProperties();
    if (properties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoPropertyDefinitionCollection> newProperties = copyClass->GetProperties();
    if (newProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    // Copy all of the base properties first. NOTE: There still is an open question on 
    // whether the properties should be copied in a certain order to allow reference matching...
    for (FdoInt32 i=0;  i<baseProperties->GetCount(); i++) {
        FdoPtr<FdoSchemaElement> schemaElement = baseProperties->GetItem(i);
        if (schemaElement == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        FdoPropertyDefinition* property = dynamic_cast<FdoPropertyDefinition *>(schemaElement.p);
        if (property == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        if (FdoCommonSchemaUtil::ClassPropertyShouldBeCopied(property, localSchemaContext)) {
            FdoPtr<FdoPropertyDefinition> newBaseProperty = DeepCopyFdoPropertyDefinition(property, localSchemaContext);
            newBaseProperties->Add(newBaseProperty);
        }
    }

    // Set the base properties on the new class.
    copyClass->SetBaseProperties(newBaseProperties);

    // Copy the class identity 'Data' Properties from the source to destination property collection.
    FdoCommonSchemaUtil::DeepCopyFdoPropertyType(identityProperties, newProperties, localSchemaContext);

    // Copy the rest of the data properties from the source class to the destination class
    FdoCommonSchemaUtil::DeepCopyFdoPropertyType(properties, newProperties, FdoPropertyType_DataProperty, localSchemaContext);

    // Copy the source identifier properties to the copy identifier property collection
    FdoCommonSchemaUtil::CopyFdoNamedDataProperties(identityProperties, newProperties, NULL, newIdentityProperties,localSchemaContext);

    // Copy the rest of the class properties. NOTE: Object an Association properties depend on data properties so we have to copy
    // these after the data and identity properties have been copied.
    FdoCommonSchemaUtil::DeepCopyFdoPropertyType(properties, newProperties, FdoPropertyType_GeometricProperty, localSchemaContext);
    FdoCommonSchemaUtil::DeepCopyFdoPropertyType(properties, newProperties, FdoPropertyType_RasterProperty, localSchemaContext);
    FdoCommonSchemaUtil::DeepCopyFdoPropertyType(properties, newProperties, FdoPropertyType_ObjectProperty, localSchemaContext);
    FdoCommonSchemaUtil::DeepCopyFdoPropertyType(properties, newProperties, FdoPropertyType_AssociationProperty, localSchemaContext);

    // Copy the class capabilities and constraints
    FdoCommonSchemaUtil::DeepCopyFdoClassCapabilitiesAndConstraints(sourceClass, copyClass, localSchemaContext);
}

FdoBoolean FdoCommonSchemaUtil::ClassPropertyShouldBeCopied(FdoPropertyDefinition* classProperty, FdoCommonSchemaCopyContext * schemaContext) 
{
    if (classProperty == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::ClassPropertyShouldBeCopied",
                                                               L"classProperty"));
    }

    FdoBoolean bCopyProperty = true;
    if (schemaContext == NULL) {
        return bCopyProperty;
    }

    FdoBoolean bIdentifierConstraintsEnabled = schemaContext->IdentifierConstraintsEnabled();
    if (bIdentifierConstraintsEnabled) {
        FdoPtr<FdoIdentifierCollection> identifierConstraints = schemaContext->GetIdentifierConstraints();
        if (identifierConstraints != NULL && identifierConstraints->GetCount() > 0) {
            FdoBoolean bPropertyFound = false;

            for (FdoInt32 x=0; x<identifierConstraints->GetCount(); x++) {
                FdoPtr<FdoIdentifier> identifier = identifierConstraints->GetItem(x);
                if (identifier == NULL) {
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                }

                FdoStringsP identifierStrings = FdoStringCollection::Create(identifier->GetText(), L".");
                
                FdoString * identifierName = identifierStrings->GetString(0);
                if (identifierName == NULL) {
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                }

                FdoString * classPropertyName = classProperty->GetName();
                if (classPropertyName == NULL) {
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                }

                if (wcscmp(identifierName, classPropertyName) == 0) {
                    bPropertyFound = true;
                    break;
                }
            }

            bCopyProperty = bPropertyFound;
        }
    }

    return bCopyProperty;
}

void FdoCommonSchemaUtil::DeepCopyFdoClassCapabilitiesAndConstraints(FdoClassDefinition* sourceClass, FdoClassDefinition* copyClass, FdoCommonSchemaCopyContext * schemaContext)
{
    if (sourceClass == NULL || copyClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoClassCapabilitiesAndConstraints",
                                                               L"sourceClass/copyClass"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoPtr<FdoClassCapabilities> sourceCapabilities = sourceClass->GetCapabilities();
    if (sourceCapabilities != NULL) {
        FdoPtr<FdoClassCapabilities> newCapabilities = FdoClassCapabilities::Create(*copyClass);
        if ( newCapabilities == NULL ) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }

        FdoBoolean readOnlyClassCapabilitiesEnabled = localSchemaContext->ReadOnlyClassCapabilitiesEnabled();
        if (readOnlyClassCapabilitiesEnabled) {
            newCapabilities->SetSupportsLocking(false);
            newCapabilities->SetLockTypes(NULL, 0);
            newCapabilities->SetSupportsLongTransactions(false);
            newCapabilities->SetSupportsWrite(false);
        }
        else {
            newCapabilities->SetSupportsLocking(sourceCapabilities->SupportsLocking());
            FdoInt32 lockTypeCount = 0;
            FdoLockType *lockTypes = sourceCapabilities->GetLockTypes(lockTypeCount);
            newCapabilities->SetLockTypes(lockTypes, lockTypeCount);
            newCapabilities->SetSupportsLongTransactions(sourceCapabilities->SupportsLongTransactions());
            newCapabilities->SetSupportsWrite(sourceCapabilities->SupportsWrite());
        }

        copyClass->SetCapabilities(newCapabilities);
    }

    // Copy unique constraints:
    FdoPtr<FdoUniqueConstraintCollection> sourceUniqueConstraints = sourceClass->GetUniqueConstraints();
    FdoPtr<FdoUniqueConstraintCollection> copyUniqueConstraints = copyClass->GetUniqueConstraints();
    for (int i=0; i<sourceUniqueConstraints->GetCount(); i++)
    {
        FdoPtr<FdoUniqueConstraint> sourceUniqueConstraint = sourceUniqueConstraints->GetItem(i);
        FdoPtr<FdoUniqueConstraint> copyUniqueConstraint = FdoUniqueConstraint::Create();

        FdoPtr<FdoDataPropertyDefinitionCollection> sourceDataProps = sourceUniqueConstraint->GetProperties();
        FdoPtr<FdoDataPropertyDefinitionCollection> copyDataProps = copyUniqueConstraint->GetProperties();

        // NOTE: some properties in the unique constraint may be missing from copyClass if the user is only
        // copying a subset of the properties; in this case, we don't copy the unique constraint:
        bool bSomeConstraintPropertiesMissing = false;
        for (int j=0; j<sourceDataProps->GetCount() && !bSomeConstraintPropertiesMissing; j++)
        {
            FdoPtr<FdoDataPropertyDefinition> sourceDataProp = sourceDataProps->GetItem(j);
            FdoPtr<FdoDataPropertyDefinition> copyDataProp = schemaContext->FindSchemaElement(sourceDataProp.p);
            if (copyDataProp == NULL)
                bSomeConstraintPropertiesMissing = true;
            else
                copyDataProps->Add(copyDataProp);
        }

        if (!bSomeConstraintPropertiesMissing)
            copyUniqueConstraints->Add(copyUniqueConstraint);
    }
}

void FdoCommonSchemaUtil::DeepCopyFdoPropertyType(FdoPropertyDefinitionCollection *properties, FdoPropertyDefinitionCollection *newProperties, FdoPropertyType propertyType, FdoCommonSchemaCopyContext * schemaContext)
{
    if (properties == NULL || newProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoPropertyType",
                                                               L"properties/newProperties"));
    }

    for (FdoInt32 j=0; j<properties->GetCount(); j++) {
        FdoPtr<FdoPropertyDefinition> property = properties->GetItem(j);
        if (property == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        if (property->GetPropertyType() == propertyType) {
            FdoString* propertyName = property->GetName();
            if (propertyName == NULL) {
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
            }

            FdoPtr<FdoPropertyDefinition> existingProperty = newProperties->FindItem(propertyName);
            if (existingProperty == NULL) {
                if (FdoCommonSchemaUtil::ClassPropertyShouldBeCopied(property, schemaContext)) {
                    FdoPtr<FdoPropertyDefinition> newProperty = DeepCopyFdoPropertyDefinition(property.p, schemaContext);
                    newProperties->Add(newProperty);
                }
            }
        }
    }
}

void FdoCommonSchemaUtil::DeepCopyFdoPropertyType(FdoDataPropertyDefinitionCollection *properties, FdoPropertyDefinitionCollection *newProperties, FdoCommonSchemaCopyContext * schemaContext)
{
    if (properties == NULL || newProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoPropertyType",
                                                               L"properties/newProperties"));
    }

    for (FdoInt32 j=0; j<properties->GetCount(); j++) {
        FdoPtr<FdoPropertyDefinition> property = properties->GetItem(j);
        if (property == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        FdoString* propertyName = property->GetName();
        if (propertyName == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        FdoPtr<FdoPropertyDefinition> existingProperty = newProperties->FindItem(propertyName);
        if (existingProperty == NULL) {
            if (FdoCommonSchemaUtil::ClassPropertyShouldBeCopied(property, schemaContext)) {
                FdoPtr<FdoPropertyDefinition> newProperty = DeepCopyFdoPropertyDefinition(property.p, schemaContext);
                newProperties->Add(newProperty);
            }
        }
    }
}

void FdoCommonSchemaUtil::CopyFdoNamedDataProperties(FdoDataPropertyDefinitionCollection *sourceProperties, FdoPropertyDefinitionCollection *newProperties, FdoReadOnlyPropertyDefinitionCollection *newBaseProperties, FdoDataPropertyDefinitionCollection *destProperties, FdoCommonSchemaCopyContext * schemaContext)
{
    if (sourceProperties == NULL || newProperties == NULL || destProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::CopyFdoNamedDataProperties",
                                                               L"sourceProperties/newProperties/destProperties"));
    }

    for (FdoInt32 k=0; k<sourceProperties->GetCount(); k++) {
        FdoPtr<FdoDataPropertyDefinition> sourceProperty = sourceProperties->GetItem(k);
        if (sourceProperty == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }

        if (FdoCommonSchemaUtil::ClassPropertyShouldBeCopied(sourceProperty, schemaContext)) {
            FdoBoolean bPropertyFound = false;

            for (FdoInt32 x=0; x<newProperties->GetCount(); x++) {
                FdoPtr<FdoPropertyDefinition> newProperty = newProperties->GetItem(x);
                if (newProperty == NULL) {
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                }

                if (newProperty->GetPropertyType() == FdoPropertyType_DataProperty) {
                    if (FdoStringP(newProperty->GetName()) == FdoStringP(sourceProperty->GetName())) {
                        destProperties->Add(static_cast<FdoDataPropertyDefinition*>(newProperty.p));
                        bPropertyFound = true;
                        break;
                    }
                }
            }

            for (FdoInt32 x=0; newBaseProperties!=NULL && x<newBaseProperties->GetCount() && !bPropertyFound; x++) {
                FdoPtr<FdoPropertyDefinition> newProperty = newBaseProperties->GetItem(x);
                if (newProperty == NULL) {
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                }

                if (newProperty->GetPropertyType() == FdoPropertyType_DataProperty) {
                    if (FdoStringP(newProperty->GetName()) == FdoStringP(sourceProperty->GetName())) {
                        destProperties->Add(static_cast<FdoDataPropertyDefinition*>(newProperty.p));
                        bPropertyFound = true;
                        break;
                    }
                }
            }

            if (bPropertyFound == false) {
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
            }
        }
    }
}

FdoPropertyDefinition * FdoCommonSchemaUtil::DeepCopyFdoPropertyDefinition(FdoPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext)
{
    if (property == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoPropertyDefinition",
                                                               L"property"));
    }

    FdoPropertyP newProperty;

    switch (property->GetPropertyType())
    {
    case FdoPropertyType_DataProperty:
        newProperty = DeepCopyFdoDataPropertyDefinition(static_cast<FdoDataPropertyDefinition*>(property), schemaContext);
        break;
    case FdoPropertyType_RasterProperty:
        newProperty = DeepCopyFdoRasterPropertyDefinition(static_cast<FdoRasterPropertyDefinition*>(property), schemaContext);
        break;
    case FdoPropertyType_GeometricProperty:
        newProperty = DeepCopyFdoGeometricPropertyDefinition(static_cast<FdoGeometricPropertyDefinition*>(property), schemaContext);
        break;
    case FdoPropertyType_AssociationProperty:
        newProperty = DeepCopyFdoAssociationPropertyDefinition(static_cast<FdoAssociationPropertyDefinition*>(property), schemaContext);
        break;
    case FdoPropertyType_ObjectProperty:
        newProperty = DeepCopyFdoObjectPropertyDefinition(static_cast<FdoObjectPropertyDefinition*>(property), schemaContext);
        break;
    default:
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
    }

    FDO_SAFE_ADDREF(newProperty.p);
    return newProperty;
}

FdoDataPropertyDefinition * FdoCommonSchemaUtil::DeepCopyFdoDataPropertyDefinition(FdoDataPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext)
{
    if (property == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoDataPropertyDefinition",
                                                               L"property"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoDataPropertyP retProperty = localSchemaContext->FindSchemaElement(property);
    if (retProperty != NULL) {
        return FDO_SAFE_ADDREF(retProperty.p);
    }

    FdoPtr<FdoDataPropertyDefinition> newProperty = FdoDataPropertyDefinition::Create(property->GetName(), property->GetDescription(), property->GetIsSystem());
    if ( newProperty == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newProperty, property);

    newProperty->SetDataType(property->GetDataType());
    newProperty->SetReadOnly(property->GetReadOnly());
    newProperty->SetLength(property->GetLength());
    newProperty->SetPrecision(property->GetPrecision());
    newProperty->SetScale(property->GetScale());
    newProperty->SetNullable(property->GetNullable());
    newProperty->SetIsAutoGenerated(property->GetIsAutoGenerated());
    newProperty->SetDefaultValue(property->GetDefaultValue());

    // Copy property value constraint (if any):
    FdoPtr<FdoPropertyValueConstraint> sourcePropValConstraint = property->GetValueConstraint();
    if (sourcePropValConstraint != NULL)
    {
        switch (sourcePropValConstraint->GetConstraintType())
        {
            case FdoPropertyValueConstraintType_Range:
            {
                FdoPropertyValueConstraintRange* sourcePropValConstraintRange = static_cast<FdoPropertyValueConstraintRange*>(sourcePropValConstraint.p);
                FdoPtr<FdoPropertyValueConstraintRange> newPropValConstraintRange;
                newPropValConstraintRange = FdoPropertyValueConstraintRange::Create();
                newPropValConstraintRange->SetMaxInclusive(sourcePropValConstraintRange->GetMaxInclusive());
                FdoPtr<FdoDataValue> maxValue = sourcePropValConstraintRange->GetMaxValue();
                if (maxValue)
                {
                    FdoPtr<FdoDataValue> copiedMaxValue = FdoCommonSchemaUtil::CopyDataValue(FdoPtr<FdoDataValue>(maxValue));
                    newPropValConstraintRange->SetMaxValue(copiedMaxValue);
                }
                newPropValConstraintRange->SetMinInclusive(sourcePropValConstraintRange->GetMinInclusive());
                FdoPtr<FdoDataValue> minValue = sourcePropValConstraintRange->GetMinValue();
                if (minValue)
                {
                    FdoPtr<FdoDataValue> copiedMinValue = FdoCommonSchemaUtil::CopyDataValue(minValue);
                    newPropValConstraintRange->SetMinValue(copiedMinValue);
                }
                newProperty->SetValueConstraint(newPropValConstraintRange);
            }
            break;

            case FdoPropertyValueConstraintType_List:
            {
                FdoPropertyValueConstraintList* sourcePropValConstraintList = static_cast<FdoPropertyValueConstraintList*>(sourcePropValConstraint.p);
                FdoPtr<FdoPropertyValueConstraintList> newPropValConstraintList;
                newPropValConstraintList = FdoPropertyValueConstraintList::Create();

                FdoPtr<FdoDataValueCollection> sourceDataValues = sourcePropValConstraintList->GetConstraintList();
                FdoPtr<FdoDataValueCollection> newDataValues = newPropValConstraintList->GetConstraintList();

                for (int i=0; i<sourceDataValues->GetCount(); i++)
                {
                    FdoPtr<FdoDataValue> sourceDataValue = sourceDataValues->GetItem(i);
                    FdoPtr<FdoDataValue> newDataValue = FdoCommonSchemaUtil::CopyDataValue(sourceDataValue);
                    newDataValues->Add(newDataValue);
                }

                newProperty->SetValueConstraint(newPropValConstraintList);
            }
            break;

            default:
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
        }
    }

    localSchemaContext->InsertSchemaElement(property, newProperty);

    FDO_SAFE_ADDREF(newProperty.p);
    return newProperty;
}

FdoGeometricPropertyDefinition * FdoCommonSchemaUtil::DeepCopyFdoGeometricPropertyDefinition(FdoGeometricPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext)
{
    if (property == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoGeometricPropertyDefinition",
                                                               L"property"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoGeometricPropertyP retProperty = localSchemaContext->FindSchemaElement(property);
    if (retProperty != NULL) {
        return FDO_SAFE_ADDREF(retProperty.p);
    }

    FdoPtr<FdoGeometricPropertyDefinition> newProperty = FdoGeometricPropertyDefinition::Create(property->GetName(), property->GetDescription(), property->GetIsSystem());
    if ( newProperty == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newProperty, property);

    FdoInt32 geomTypesLength;
    FdoGeometryType *geomTypes = property->GetSpecificGeometryTypes(geomTypesLength);
    newProperty->SetSpecificGeometryTypes(geomTypes, geomTypesLength);
    newProperty->SetReadOnly(property->GetReadOnly());
    newProperty->SetHasElevation(property->GetHasElevation());
    newProperty->SetHasMeasure(property->GetHasMeasure());
    newProperty->SetSpatialContextAssociation(property->GetSpatialContextAssociation());

    localSchemaContext->InsertSchemaElement(property, newProperty);

    FDO_SAFE_ADDREF(newProperty.p);
    return newProperty;
}

FdoRasterPropertyDefinition * FdoCommonSchemaUtil::DeepCopyFdoRasterPropertyDefinition(FdoRasterPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext)
{
    if (property == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoRasterPropertyDefinition",
                                                               L"property"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoRasterPropertyP retProperty = localSchemaContext->FindSchemaElement(property);
    if (retProperty != NULL) {
        return FDO_SAFE_ADDREF(retProperty.p);
    }

    FdoPtr<FdoRasterPropertyDefinition> newProperty = FdoRasterPropertyDefinition::Create(property->GetName(), property->GetDescription(), property->GetIsSystem());
    if ( newProperty == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newProperty, property);

    newProperty->SetReadOnly(property->GetReadOnly());
    newProperty->SetNullable(property->GetNullable());
    newProperty->SetDefaultImageXSize(property->GetDefaultImageXSize());
    newProperty->SetDefaultImageYSize(property->GetDefaultImageYSize());
    newProperty->SetSpatialContextAssociation(property->GetSpatialContextAssociation());

    FdoPtr<FdoRasterDataModel> newRasterDataModel = FdoRasterDataModel::Create();
    if ( newRasterDataModel == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoPtr<FdoRasterDataModel> rasterDataModel = property->GetDefaultDataModel();
    
    if (rasterDataModel != NULL) {
        newRasterDataModel->SetBitsPerPixel(rasterDataModel->GetBitsPerPixel());
        newRasterDataModel->SetDataModelType(rasterDataModel->GetDataModelType());
        newRasterDataModel->SetDataType(rasterDataModel->GetDataType());
        newRasterDataModel->SetOrganization(rasterDataModel->GetOrganization());
        newRasterDataModel->SetTileSizeX(rasterDataModel->GetTileSizeX());
        newRasterDataModel->SetTileSizeY(rasterDataModel->GetTileSizeY());
    }

    newProperty->SetDefaultDataModel(newRasterDataModel);

    localSchemaContext->InsertSchemaElement(property, newProperty);

    FDO_SAFE_ADDREF(newProperty.p);
    return newProperty;
}

FdoObjectPropertyDefinition * FdoCommonSchemaUtil::DeepCopyFdoObjectPropertyDefinition(FdoObjectPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext)
{
    if (property == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoObjectPropertyDefinition",
                                                               L"property"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoObjectPropertyP retProperty = localSchemaContext->FindSchemaElement(property);
    if (retProperty != NULL) {
        return FDO_SAFE_ADDREF(retProperty.p);
    }

    FdoPtr<FdoObjectPropertyDefinition> newProperty = FdoObjectPropertyDefinition::Create(property->GetName(), property->GetDescription(), property->GetIsSystem());
    if ( newProperty == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newProperty, property);

    FdoBoolean bConstraintsEnabled = localSchemaContext->IdentifierConstraintsEnabled();
    localSchemaContext->EnableIdentifierConstraints(false);

    FdoClassDefinitionP sourceClass = property->GetClass();
    FdoClassDefinitionP copyClass = FdoCommonSchemaUtil::DeepCopyFdoClassDefinition(sourceClass, localSchemaContext);
    newProperty->SetClass(copyClass);

    localSchemaContext->EnableIdentifierConstraints(bConstraintsEnabled);

    FdoDataPropertyP identityProperty = property->GetIdentityProperty();
    if (identityProperty != NULL) {
        FdoDataPropertyP copiedIdentityProperty = FdoCommonSchemaUtil::DeepCopyFdoDataPropertyDefinition(identityProperty);
        if (copiedIdentityProperty == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
        }
        newProperty->SetIdentityProperty(copiedIdentityProperty.p);
    }

    newProperty->SetObjectType(property->GetObjectType());
    newProperty->SetOrderType(property->GetOrderType());

    localSchemaContext->InsertSchemaElement(property, newProperty);

    FDO_SAFE_ADDREF(newProperty.p);
    return newProperty;
}

FdoAssociationPropertyDefinition * FdoCommonSchemaUtil::DeepCopyFdoAssociationPropertyDefinition(FdoAssociationPropertyDefinition * property, FdoCommonSchemaCopyContext * schemaContext)
{
    if (property == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoAssociationPropertyDefinition",
                                                               L"property"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoAssociationPropertyP retProperty = localSchemaContext->FindSchemaElement(property);
    if (retProperty != NULL) {
        return FDO_SAFE_ADDREF(retProperty.p);
    }

    FdoPtr<FdoAssociationPropertyDefinition> newProperty = FdoAssociationPropertyDefinition::Create(property->GetName(), property->GetDescription(), property->GetIsSystem());
    if ( newProperty == NULL ) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
    }

    FdoCommonSchemaUtil::DeepCopyFdoSchemaElementDetails(newProperty, property);

	newProperty->SetReverseName(property->GetReverseName());
    newProperty->SetDeleteRule(property->GetDeleteRule());
    newProperty->SetLockCascade(property->GetLockCascade());
    newProperty->SetIsReadOnly(property->GetIsReadOnly());
    newProperty->SetMultiplicity(property->GetMultiplicity());
    newProperty->SetReverseMultiplicity(property->GetReverseMultiplicity());

    FdoBoolean bConstraintsEnabled = localSchemaContext->IdentifierConstraintsEnabled();
    localSchemaContext->EnableIdentifierConstraints(false);

    FdoClassDefinitionP sourceAssociationClass = property->GetAssociatedClass();
	
    FdoClassDefinitionP copyAssociationClass = localSchemaContext->FindSchemaElement(sourceAssociationClass.p);
	
	if( copyAssociationClass == NULL )
		copyAssociationClass = FdoCommonSchemaUtil::DeepCopyFdoClassDefinition(sourceAssociationClass, localSchemaContext);
	
	newProperty->SetAssociatedClass(copyAssociationClass);
	

    localSchemaContext->EnableIdentifierConstraints(bConstraintsEnabled);

    FdoDataPropertiesP identityProps = property->GetIdentityProperties();
    FdoDataPropertiesP newIdentityProps = newProperty->GetIdentityProperties();

    FdoClassDefinitionP parentClass = dynamic_cast<FdoClassDefinition*>(property->GetParent());
    if (parentClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoPropertyDefinitionCollection> parentClassProperties = copyAssociationClass->GetProperties();
    if (parentClassProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoReadOnlyPropertyDefinitionCollection> parentClassBaseProperties = copyAssociationClass->GetBaseProperties();
    if (parentClassBaseProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoCommonSchemaUtil::CopyFdoNamedDataProperties(identityProps, parentClassProperties, parentClassBaseProperties, newIdentityProps);

    FdoDataPropertiesP reverseIdentityProps = property->GetReverseIdentityProperties();
    FdoDataPropertiesP newReverseIdentityProps = newProperty->GetReverseIdentityProperties();

	FdoClassDefinitionP copyParentClass = localSchemaContext->FindSchemaElement(parentClass.p);
	if( copyParentClass == NULL )
		throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));

    FdoPtr<FdoPropertyDefinitionCollection> associationClassProperties = copyParentClass->GetProperties();
    if (associationClassProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPtr<FdoReadOnlyPropertyDefinitionCollection> associationClassBaseProperties = copyParentClass->GetBaseProperties();
    if (associationClassBaseProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoCommonSchemaUtil::CopyFdoNamedDataProperties(reverseIdentityProps, associationClassProperties, associationClassBaseProperties, newReverseIdentityProps);

	
	//If this association property is already added by following the associated classes, then we need to undo that addition and 
	//wait until it's added by calling method. This situation happens when we have 2 classes that have associations to each other.
	FdoPtr<FdoPropertyDefinition> prop = associationClassProperties->FindItem( newProperty->GetName() );
	if( prop != NULL )
		associationClassProperties->Remove( prop );
	
    localSchemaContext->InsertSchemaElement(property, newProperty);

    FDO_SAFE_ADDREF(newProperty.p);
    return newProperty;
}

void FdoCommonSchemaUtil::DeepCopyFdoComputedClassProperties(FdoClassDefinition * sourceClass, FdoClassDefinition* copyClass, FdoCommonSchemaCopyContext * schemaContext)
{
    if (copyClass == NULL || sourceClass == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonSchemaCopyContext::DeepCopyFdoComputedClassProperties",
                                                               L"copyClass/sourceClass"));
    }

    FdoCommonSchemaCopyContextP localSchemaContext = FDO_SAFE_ADDREF(schemaContext);
    if (localSchemaContext == NULL) {
        localSchemaContext = FdoCommonSchemaCopyContext::Create(NULL);
        if (localSchemaContext == NULL) {
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));
        }
    }

    FdoPropertiesP sourceProperties = sourceClass->GetProperties();
    if (sourceProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoPropertiesP copyProperties = copyClass->GetProperties();
    if (copyProperties == NULL) {
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
    }

    FdoBoolean bClassIsComputed = false;

    FdoBoolean bIdentifierConstraintsEnabled = schemaContext->IdentifierConstraintsEnabled();
    if (bIdentifierConstraintsEnabled) {
        FdoPtr<FdoIdentifierCollection> identifierConstraints = schemaContext->GetIdentifierConstraints();
        if (identifierConstraints != NULL && identifierConstraints->GetCount() > 0) {
            for (FdoInt32 x=0; x<identifierConstraints->GetCount(); x++) {
                FdoPtr<FdoIdentifier> identifier = identifierConstraints->GetItem(x);
                if (identifier == NULL) {
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                }

                FdoComputedIdentifier * computedIdentifier = dynamic_cast<FdoComputedIdentifier*>(identifier.p);
                if (computedIdentifier != NULL) {
                    FdoString* identifierText = computedIdentifier->GetText();
                    if (identifierText == NULL) {
                        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                    }

#pragma message ("TODO: Should we throw an error if the item is not found?")

                    FdoPropertyP computedProperty = sourceProperties->FindItem(identifierText);
                    if (computedProperty != NULL) {
                        FdoPropertyP copiedComputedProperty = FdoCommonSchemaUtil::DeepCopyFdoPropertyDefinition(computedProperty, schemaContext);
                        if (copiedComputedProperty == NULL) {
                            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_4_UNREADY)));
                        }

                        copyProperties->Add(copiedComputedProperty);
                        bClassIsComputed = true;
                    }
                }
            }
        }
    }

    copyClass->SetIsComputed(bClassIsComputed);
}




// Returns the requested logical class definition, paring it down to the given property list
FdoClassDefinition* FdoCommonSchemaUtil::GetLogicalClassDefinition (FdoIConnection* connection, FdoString* logicalClassName, FdoIdentifierCollection* propertySubset)
{
    VALIDATE_ARGUMENT(logicalClassName);

    FdoPtr<FdoIdentifier> logicalClassId = FdoIdentifier::Create(logicalClassName);
    FdoPtr<FdoClassDefinition> retClassDef;
    

    // Get logical class:
    FdoPtr<FdoIDescribeSchema> describeSchema = (FdoIDescribeSchema*)connection->CreateCommand(FdoCommandType_DescribeSchema);
    if ((logicalClassId->GetSchemaName() != NULL) && (wcslen(logicalClassId->GetSchemaName())>0))
        describeSchema->SetSchemaName(logicalClassId->GetSchemaName());
    FdoPtr<FdoFeatureSchemaCollection> schemas = describeSchema->Execute();
    for (FdoInt32 i=0; i<schemas->GetCount(); i++)
    {
        FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(i);

        if ((logicalClassId->GetSchemaName() != NULL) && (wcslen(logicalClassId->GetSchemaName())>0) && (0!=wcscmp(logicalClassId->GetSchemaName(), schema->GetName())))
            continue;

        FdoPtr<FdoClassCollection> classes = schema->GetClasses();
        retClassDef = classes->FindItem(logicalClassId->GetName());
        if (retClassDef != NULL)
            break;
    }
    if (retClassDef == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_76_CLASS_NAME_NOT_FOUND), logicalClassName));

    // Create copy of logical class, using given propertySubset:
    FdoPtr<FdoCommonSchemaCopyContext> copyContext = FdoCommonSchemaCopyContext::Create(propertySubset);
    FdoPtr<FdoClassDefinition> logicalClassCopy = FdoCommonSchemaUtil::DeepCopyFdoClassDefinition(retClassDef, copyContext);
    return FDO_SAFE_ADDREF(logicalClassCopy.p);
}



bool FdoCommonSchemaUtil::IsIdentityProperty(FdoClassDefinition* pClassDef, FdoString *propertyName)
{
	bool   bRetVal = false;
	FdoPtr<FdoClassDefinition> pBaseClass;
	FdoPtr<FdoClassDefinition> pBaseParentClass;

	// IMPORTANT: the schema design states that for subclasses, only the root parent class stores
	// the identity properties; this means we need to first find the root parent class (if any):
	FDO_SAFE_ADDREF(pClassDef);
	pBaseClass = pClassDef;
	pBaseParentClass = pClassDef->GetBaseClass();
	while (pBaseParentClass != NULL)
	{
		pBaseClass = pBaseParentClass;  //NOTE: automatic addref here, due to "smart ptr to smart ptr" assignment
		pBaseParentClass = (FdoClassDefinition*)pBaseClass->GetBaseClass();
	}

	// Now look for the identity property in the identity collection of the "absolute" base class:
	FdoPtr<FdoDataPropertyDefinitionCollection> pIdProperties = pBaseClass->GetIdentityProperties();
    bRetVal = (pIdProperties != NULL) && (pIdProperties->GetCount()>0) && pIdProperties->Contains(propertyName);

	return bRetVal;
}



FdoDataValue* FdoCommonSchemaUtil::CopyDataValue(FdoDataValue* sourceDataValue)
{
    FdoDataValue *retDataValue = NULL;

    switch (sourceDataValue->GetDataType())
    {
        case FdoDataType_Boolean:
        {
            FdoBooleanValue* sourceDataValue2 = static_cast<FdoBooleanValue*>(sourceDataValue);
            FdoPtr<FdoBooleanValue> newDataValue = FdoBooleanValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetBoolean(sourceDataValue2->GetBoolean());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Byte:
        {
            FdoByteValue* sourceDataValue2 = static_cast<FdoByteValue*>(sourceDataValue);
            FdoPtr<FdoByteValue> newDataValue = FdoByteValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetByte(sourceDataValue2->GetByte());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_DateTime:
        {
            FdoDateTimeValue* sourceDataValue2 = static_cast<FdoDateTimeValue*>(sourceDataValue);
            FdoPtr<FdoDateTimeValue> newDataValue = FdoDateTimeValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetDateTime(sourceDataValue2->GetDateTime());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Decimal:
        {
            FdoDecimalValue* sourceDataValue2 = static_cast<FdoDecimalValue*>(sourceDataValue);
            FdoPtr<FdoDecimalValue> newDataValue = FdoDecimalValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetDecimal(sourceDataValue2->GetDecimal());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Double:
        {
            FdoDoubleValue* sourceDataValue2 = static_cast<FdoDoubleValue*>(sourceDataValue);
            FdoPtr<FdoDoubleValue> newDataValue = FdoDoubleValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetDouble(sourceDataValue2->GetDouble());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Int16:
        {
            FdoInt16Value* sourceDataValue2 = static_cast<FdoInt16Value*>(sourceDataValue);
            FdoPtr<FdoInt16Value> newDataValue = FdoInt16Value::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetInt16(sourceDataValue2->GetInt16());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Int32:
        {
            FdoInt32Value* sourceDataValue2 = static_cast<FdoInt32Value*>(sourceDataValue);
            FdoPtr<FdoInt32Value> newDataValue = FdoInt32Value::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetInt32(sourceDataValue2->GetInt32());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Int64:
        {
            FdoInt64Value* sourceDataValue2 = static_cast<FdoInt64Value*>(sourceDataValue);
            FdoPtr<FdoInt64Value> newDataValue = FdoInt64Value::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetInt64(sourceDataValue2->GetInt64());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_Single:
        {
            FdoSingleValue* sourceDataValue2 = static_cast<FdoSingleValue*>(sourceDataValue);
            FdoPtr<FdoSingleValue> newDataValue = FdoSingleValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetSingle(sourceDataValue2->GetSingle());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_String:
        {
            FdoStringValue* sourceDataValue2 = static_cast<FdoStringValue*>(sourceDataValue);
            FdoPtr<FdoStringValue> newDataValue = FdoStringValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
                newDataValue->SetString(sourceDataValue2->GetString());
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_BLOB:
        {
            FdoBLOBValue* sourceDataValue2 = static_cast<FdoBLOBValue*>(sourceDataValue);
            FdoPtr<FdoBLOBValue> newDataValue = FdoBLOBValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
            {
                FdoPtr<FdoByteArray> sourceData = sourceDataValue2->GetData();
                FdoPtr<FdoByteArray> newData = FdoByteArray::Create(sourceData->GetData(), sourceData->GetCount());
                newDataValue->SetData(newData);
            }
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        case FdoDataType_CLOB:
        {
            FdoCLOBValue* sourceDataValue2 = static_cast<FdoCLOBValue*>(sourceDataValue);
            FdoPtr<FdoCLOBValue> newDataValue = FdoCLOBValue::Create();
            if (sourceDataValue2->IsNull())
                newDataValue->SetNull();
            else
            {
                FdoPtr<FdoByteArray> sourceData = sourceDataValue2->GetData();
                FdoPtr<FdoByteArray> newData = FdoByteArray::Create(sourceData->GetData(), sourceData->GetCount());
                newDataValue->SetData(newData);
            }
            retDataValue = FDO_SAFE_ADDREF(newDataValue.p);
        }
        break;

        default:
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
    }

    return retDataValue;
}


void FdoCommonSchemaUtil::AddComputedIdentifiersAsProperties(FdoIConnection* connection, FdoClassDefinition* destClass, FdoClassDefinition* originalClass, FdoIdentifierCollection* selectedIds)
{
    FdoPtr<FdoPropertyDefinitionCollection> destProps = destClass->GetProperties();
    FdoStringP genericDescription = L"";
    for (int i=0; selectedIds && i<selectedIds->GetCount(); i++)
    {
        FdoPtr<FdoIdentifier> selectedId = selectedIds->GetItem(i);
        FdoComputedIdentifier* computedId = dynamic_cast<FdoComputedIdentifier*>(selectedId.p);
        if (computedId)
        {
            FdoPropertyType propType;
            FdoDataType     dataType;
            FdoPtr<FdoExpression> expr = computedId->GetExpression();
            FdoPtr<FdoIExpressionCapabilities> expressionCaps = connection->GetExpressionCapabilities();
            FdoPtr<FdoFunctionDefinitionCollection> functions = expressionCaps->GetFunctions();
			FdoCommonMiscUtil::GetExpressionType(functions, originalClass, expr, propType, dataType);
            if (propType == FdoPropertyType_DataProperty)
            {
                FdoPtr<FdoDataPropertyDefinition> dataProp = FdoDataPropertyDefinition::Create(computedId->GetName(), genericDescription);
                dataProp->SetDataType(dataType);
                destProps->Add(dataProp);
            }
            else if (propType == FdoPropertyType_GeometricProperty)
            {
                FdoPtr<FdoGeometricPropertyDefinition> geomProp = FdoGeometricPropertyDefinition::Create(computedId->GetName(), genericDescription);
                destProps->Add(geomProp);
            }
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_70_PROPERTY_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoPropertyTypeToString(propType)));
        }
    }
}
