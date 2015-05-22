#ifndef _FDO_H_
#define _FDO_H_
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

#ifdef _WIN32
#pragma once
#ifndef _WCHAR_T_DEFINED
#error wchar_t must be defined (/Zc:wchar or project~properties~C/C++~Language~"Treat wchar_t as built in type"="Yes")
#endif
#endif
#include <FdoStd.h>
#include <FdoGeometry.h>

////////////////////////////////////////////////////////////////
// Commands
//
#include <Fdo/Commands/BatchParameterValueCollection.h>
#include <Fdo/Commands/CommandException.h>
#include <Fdo/Commands/CommandType.h>
#include <Fdo/Commands/ICommand.h>
#include <Fdo/Commands/IdentifierCollection.h>
#include <Fdo/Commands/IFeatureCommand.h>
#include <Fdo/Commands/OrderingOption.h>
#include <Fdo/Commands/ParameterValue.h>
#include <Fdo/Commands/ParameterValueCollection.h>
#include <Fdo/Commands/PropertyValue.h>
#include <Fdo/Commands/PropertyValueCollection.h>

#include <Fdo/Commands/DataStore/IDataStorePropertyDictionary.h>
#include <Fdo/Commands/DataStore/ICreateDataStore.h>
#include <Fdo/Commands/DataStore/IDestroyDataStore.h>
#include <Fdo/Commands/DataStore/IDataStoreReader.h>
#include <Fdo/Commands/DataStore/IListDataStores.h>

#include <Fdo/Commands/Feature/IBaseSelect.h>
#include <Fdo/Commands/Feature/IDataReader.h>
#include <Fdo/Commands/Feature/IDelete.h>
#include <Fdo/Commands/Feature/IFeatureReader.h>
#include <Fdo/Commands/Feature/IInsert.h>
#include <Fdo/Commands/Feature/IReader.h>
#include <Fdo/Commands/Feature/ISelect.h>
#include <Fdo/Commands/Feature/ISelectAggregates.h>
#include <Fdo/Commands/Feature/IUpdate.h>

#include <Fdo/Commands/Locking/IAcquireLock.h>
#include <Fdo/Commands/Locking/IGetLockedObjects.h>
#include <Fdo/Commands/Locking/IGetLockInfo.h>
#include <Fdo/Commands/Locking/IGetLockOwners.h>
#include <Fdo/Commands/Locking/ILockConflictReader.h>
#include <Fdo/Commands/Locking/ILockedObjectReader.h>
#include <Fdo/Commands/Locking/ILockOwnersReader.h>
#include <Fdo/Commands/Locking/IReleaseLock.h>
#include <Fdo/Commands/Locking/LockStrategy.h>
#include <Fdo/Commands/Locking/LockType.h>
#include <Fdo/Commands/Locking/ConflictType.h>

#include <Fdo/Commands/LongTransaction/IActivateLongTransaction.h>
#include <Fdo/Commands/LongTransaction/IActivateLongTransactionCheckpoint.h>
#include <Fdo/Commands/LongTransaction/IChangeLongTransactionPrivileges.h>
#include <Fdo/Commands/LongTransaction/IChangeLongTransactionSet.h>
#include <Fdo/Commands/LongTransaction/ICommitLongTransaction.h>
#include <Fdo/Commands/LongTransaction/ICreateLongTransaction.h>
#include <Fdo/Commands/LongTransaction/ICreateLongTransactionCheckpoint.h>
#include <Fdo/Commands/LongTransaction/IDeactivateLongTransaction.h>
#include <Fdo/Commands/LongTransaction/IFreezeLongTransaction.h>
#include <Fdo/Commands/LongTransaction/IGetLongTransactionCheckpoints.h>
#include <Fdo/Commands/LongTransaction/IGetLongTransactionPrivileges.h>
#include <Fdo/Commands/LongTransaction/IGetLongTransactions.h>
#include <Fdo/Commands/LongTransaction/IGetLongTransactionsInSet.h>
#include <Fdo/Commands/LongTransaction/ILongTransactionCheckpointReader.h>
#include <Fdo/Commands/LongTransaction/ILTConflictDirectiveEnumerator.h>
#include <Fdo/Commands/LongTransaction/ILongTransactionPrivilegeReader.h>
#include <Fdo/Commands/LongTransaction/ILongTransactionReader.h>
#include <Fdo/Commands/LongTransaction/ILongTransactionSetReader.h>
#include <Fdo/Commands/LongTransaction/IRollbackLongTransaction.h>
#include <Fdo/Commands/LongTransaction/IRollbackLongTransactionCheckpoint.h>
#include <Fdo/Commands/LongTransaction/LongTransactionConflictResolution.h>
#include <Fdo/Commands/LongTransaction/LongTransactionConstants.h>
#include <Fdo/Commands/LongTransaction/LongTransactionFreezeOperations.h>
#include <Fdo/Commands/LongTransaction/LongTransactionPrivilegeOperations.h>
#include <Fdo/Commands/LongTransaction/LongTransactionPrivileges.h>
#include <Fdo/Commands/LongTransaction/LongTransactionSetOperations.h>

#include <Fdo/Commands/Schema/IApplySchema.h>
#include <Fdo/Commands/Schema/IDescribeSchema.h>
#include <Fdo/Commands/Schema/IDescribeSchemaMapping.h>
#include <Fdo/Commands/Schema/IDestroySchema.h>
#include <Fdo/Commands/Schema/PhysicalClassMapping.h>
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>
#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>
#include <Fdo/Commands/Schema/PhysicalPropertyMapping.h>
#include <Fdo/Commands/Schema/PhysicalSchemaMapping.h>
#include <Fdo/Commands/Schema/PhysicalSchemaMappingCollection.h>

#include <Fdo/Commands/SpatialContext/SpatialContextMismatchException.h>
#include <Fdo/Commands/SpatialContext/IActivateSpatialContext.h>
#include <Fdo/Commands/SpatialContext/ICreateSpatialContext.h>
#include <Fdo/Commands/SpatialContext/IDestroySpatialContext.h>
#include <Fdo/Commands/SpatialContext/IGetSpatialContexts.h>
#include <Fdo/Commands/SpatialContext/ISpatialContextReader.h>
#include <Fdo/Commands/SpatialContext/SpatialContextExtentType.h>

#include <Fdo/Commands/Sql/ISQLCommand.h>
#include <Fdo/Commands/Sql/ISQLDataReader.h>

#include <Fdo/Commands/UnitOfMeasure/BaseUnit.h>
#include <Fdo/Commands/UnitOfMeasure/ICreateMeasureUnit.h>
#include <Fdo/Commands/UnitOfMeasure/IDestroyMeasureUnit.h>
#include <Fdo/Commands/UnitOfMeasure/IGetMeasureUnits.h>
#include <Fdo/Commands/UnitOfMeasure/IMeasureUnitReader.h>

////////////////////////////////////////////////////////////////
// Connections
//
#include <Fdo/Connections/ConnectionException.h>
#include <Fdo/Connections/ConnectionState.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Connections/IConnectionInfo.h>
#include <Fdo/Connections/IConnectionPropertyDictionary.h>
#include <Fdo/Connections/IPropertyDictionary.h>
#include <Fdo/Connections/ITransaction.h>

#include <Fdo/Connections/Capabilities/ArgumentDefinition.h>
#include <Fdo/Connections/Capabilities/ArgumentDefinitionCollection.h>
#include <Fdo/Connections/Capabilities/FunctionDefinition.h>
#include <Fdo/Connections/Capabilities/FunctionDefinitionCollection.h>
#include <Fdo/Connections/Capabilities/ThreadCapability.h>
#include <Fdo/Connections/Capabilities/ICommandCapabilities.h>
#include <Fdo/Connections/Capabilities/IConnectionCapabilities.h>
#include <Fdo/Connections/Capabilities/IExpressionCapabilities.h>
#include <Fdo/Connections/Capabilities/IFilterCapabilities.h>
#include <Fdo/Connections/Capabilities/IGeometryCapabilities.h>
#include <Fdo/Connections/Capabilities/ISchemaCapabilities.h>
#include <Fdo/Connections/Capabilities/IRasterCapabilities.h>
#include <Fdo/Connections/Capabilities/ITopologyCapabilities.h>
#include <Fdo/Connections/Capabilities/ReadOnlyArgumentDefinitionCollection.h>
#include <Fdo/Connections/Capabilities/SignatureDefinition.h>

////////////////////////////////////////////////////////////////
// Expression
//
#include <Fdo/Expression/BinaryExpression.h>
#include <Fdo/Expression/BinaryOperations.h>
#include <Fdo/Expression/BooleanValue.h>
#include <Fdo/Expression/ByteValue.h>
#include <Fdo/Expression/LOBValue.h>
#include <Fdo/Expression/BLOBValue.h>
#include <Fdo/Expression/CLOBValue.h>
#include <Fdo/Expression/BLOBStreamReader.h>
#include <Fdo/Expression/ComputedIdentifier.h>
#include <Fdo/Expression/DataValue.h>
#include <Fdo/Expression/DataValueCollection.h>
#include <Fdo/Expression/DateTimeValue.h>
#include <Fdo/Expression/DecimalValue.h>
#include <Fdo/Expression/DoubleValue.h>
#include <Fdo/Expression/Expression.h>
#include <Fdo/Expression/ExpressionCollection.h>
#include <Fdo/Expression/ExpressionException.h>
#include <Fdo/Expression/ExpressionType.h>
#include <Fdo/Expression/Function.h>
#include <Fdo/Expression/GeometryValue.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Expression/Int16Value.h>
#include <Fdo/Expression/Int32Value.h>
#include <Fdo/Expression/Int64Value.h>
#include <Fdo/Expression/IExpressionProcessor.h>
#include <Fdo/Expression/LiteralValue.h>
#include <Fdo/Expression/LiteralValueCollection.h>
#include <Fdo/Expression/LiteralValueType.h>
#include <Fdo/Expression/Parameter.h>
#include <Fdo/Expression/SingleValue.h>
#include <Fdo/Expression/StringValue.h>
#include <Fdo/Expression/UnaryExpression.h>
#include <Fdo/Expression/UnaryOperations.h>
#include <Fdo/Expression/ValueExpression.h>

////////////////////////////////////////////////////////////////
// Filter
//
#include <Fdo/Filter/BinaryLogicalOperations.h>
#include <Fdo/Filter/BinaryLogicalOperator.h>
#include <Fdo/Filter/ComparisonCondition.h>
#include <Fdo/Filter/ComparisonOperations.h>
#include <Fdo/Filter/ConditionType.h>
#include <Fdo/Filter/DistanceCondition.h>
#include <Fdo/Filter/DistanceOperations.h>
#include <Fdo/Filter/Filter.h>
#include <Fdo/Filter/FilterException.h>
#include <Fdo/Filter/GeometricCondition.h>
#include <Fdo/Filter/IFilterProcessor.h>
#include <Fdo/Filter/InCondition.h>
#include <Fdo/Filter/LogicalOperator.h>
#include <Fdo/Filter/NullCondition.h>
#include <Fdo/Filter/SearchCondition.h>
#include <Fdo/Filter/SpatialCondition.h>
#include <Fdo/Filter/SpatialOperations.h>
#include <Fdo/Filter/UnaryLogicalOperations.h>
#include <Fdo/Filter/UnaryLogicalOperator.h>
#include <Fdo/Filter/ValueExpressionCollection.h>

////////////////////////////////////////////////////////////////
// Schema
//
#include <Fdo/Schema/AssociationPropertyDefinition.h>
#include <Fdo/Schema/AutogenerationException.h>
#include <Fdo/Schema/Class.h>
#include <Fdo/Schema/ClassCapabilities.h>
#include <Fdo/Schema/ClassCollection.h>
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/ClassType.h>
#include <Fdo/Schema/DataPropertyDefinition.h>
#include <Fdo/Schema/DataPropertyDefinitionCollection.h>
#include <Fdo/Schema/DataType.h>
#include <Fdo/Schema/DeleteRule.h>
#include <Fdo/Schema/FeatureClass.h>
#include <Fdo/Schema/FeatureClassCollection.h>
#include <Fdo/Schema/FeatureSchema.h>
#include <Fdo/Schema/FeatureSchemaCollection.h>
#include <Fdo/Schema/GeometricPropertyDefinition.h>
#include <Fdo/Schema/GeometricType.h>
#include <Fdo/Schema/MergeContext.h>
#include <Fdo/Schema/ObjectPropertyDefinition.h>
#include <Fdo/Schema/ObjectType.h>
#include <Fdo/Schema/OrderType.h>
#include <Fdo/Schema/PropertyDefinition.h>
#include <Fdo/Schema/PropertyDefinitionCollection.h>
#include <Fdo/Schema/PropertyType.h>
#include <Fdo/Schema/PropertyValueConstraintRange.h>
#include <Fdo/Schema/PropertyValueConstraintType.h>
#include <Fdo/Schema/PropertyValueConstraint.h>
#include <Fdo/Schema/PropertyValueConstraintList.h>
#include <Fdo/Schema/ReadOnlyPropertyDefinitionCollection.h>
#include <Fdo/Schema/SchemaAttributeDictionary.h>
#include <Fdo/Schema/SchemaCollection.h>
#include <Fdo/Schema/SchemaElement.h>
#include <Fdo/Schema/SchemaElementState.h>
#include <Fdo/Schema/SchemaException.h>
#include <Fdo/Schema/RasterPropertyDefinition.h>
#include <Fdo/Schema/ReadOnlyDataPropertyDefinitionCollection.h>
#include <Fdo/Schema/NetworkFeatureClass.h>
#include <Fdo/Schema/NetworkLayerClass.h>
#include <Fdo/Schema/NetworkNodeFeatureClass.h>
#include <Fdo/Schema/NetworkLinkFeatureClass.h>
#include <Fdo/Schema/NetworkClass.h>
#include <Fdo/Schema/TopoFeaturePropertyDefinition.h>
#include <Fdo/Schema/TopoGeometryPropertyDefinition.h>
#include <Fdo/Schema/Topology.h>
#include <Fdo/Schema/UniqueConstraint.h>
#include <Fdo/Schema/UniqueConstraintCollection.h>
#include <Fdo/Schema/PropertyValueConstraint.h>
#include <Fdo/Schema/PropertyValueConstraintList.h>
#include <Fdo/Schema/PropertyValueConstraintRange.h>
#include <Fdo/Schema/PropertyValueConstraintList.h>


////////////////////////////////////////////////////////////////
// Raster
//
#include <Fdo/Raster/IRaster.h>
#include <Fdo/Raster/IRasterPropertyDictionary.h>
#include <Fdo/Raster/RasterDataOrganization.h>
#include <Fdo/Raster/RasterDataModelType.h>
#include <Fdo/Raster/RasterDataModel.h>
#include <Fdo/Raster/RasterDataType.h>

////////////////////////////////////////////////////////////////
// Client Services
//
#include <Fdo/ClientServices/ClientServiceException.h>
#include <Fdo/ClientServices/ConnectionManager.h>
#include <Fdo/ClientServices/FeatureAccessManager.h>
#include <Fdo/ClientServices/Provider.h>
#include <Fdo/ClientServices/ProviderNameTokens.h>
#include <Fdo/ClientServices/ProviderRegistry.h>
#include <Fdo/ClientServices/ClientServices.h>
#include <Fdo/ClientServices/ProviderCollection.h>

////////////////////////////////////////////////////////////////
// XML Services
//

#include <Fdo/Xml/ClassMapping.h>
#include <Fdo/Xml/ClassMappingCollection.h>
#include <Fdo/Xml/Context.h>
#include <Fdo/Xml/Deserializable.h>
#include <Fdo/Xml/ElementMapping.h>
#include <Fdo/Xml/ElementMappingCollection.h>
#include <Fdo/Xml/FeatureContext.h>
#include <Fdo/Xml/FeatureFlags.h>
#include <Fdo/Xml/FeatureHandler.h>
#include <Fdo/Xml/FeaturePropertyReader.h>
#include <Fdo/Xml/FeaturePropertyWriter.h>
#include <Fdo/Xml/FeatureReader.h>
#include <Fdo/Xml/FeatureSerializer.h>
#include <Fdo/Xml/FeatureWriter.h>
#include <Fdo/Xml/Flags.h>
#include <Fdo/Xml/NameCollectionHandler.h>
#include <Fdo/Xml/SchemaMapping.h>
#include <Fdo/Xml/Serializable.h>
#include <Fdo/Xml/SpatialContextFlags.h>
#include <Fdo/Xml/SpatialContextReader.h>
#include <Fdo/Xml/SpatialContextSerializer.h>
#include <Fdo/Xml/SpatialContextWriter.h>

#endif


