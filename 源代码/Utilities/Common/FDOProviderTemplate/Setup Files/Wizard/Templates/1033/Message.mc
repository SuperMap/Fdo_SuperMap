;//
;//Copyright (C) 2004-2006  Autodesk, Inc.
;//
;//This library is free software; you can redistribute it and/or
;//modify it under the terms of version 2.1 of the GNU Lesser
;//General Public License as published by the Free Software Foundation.
;//
;//This library is distributed in the hope that it will be useful,
;//but WITHOUT ANY WARRANTY; without even the implied warranty of
;//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;//Lesser General Public License for more details.
;//
;//You should have received a copy of the GNU Lesser General Public
;//License along with this library; if not, write to the Free Software
;//Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
;//


;//************************************************************************************
;//************************************************************************************
;//** GENERIC MESSAGES 
;//************************************************************************************
;//************************************************************************************

MessageId=1001
SymbolicName=[!output UPPER_PREFIX]_SET_TRANSACTION_NOT_SUPPORTED
Language=English
Setting the transaction is not supported.
.

;//************************************************************************************
;//************************************************************************************
;//** CONNECTION MESSAGES 
;//************************************************************************************
;//************************************************************************************


MessageId=2001
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_TIMEOUT_UNSUPPORTED
Language=English
Connection timeout is not supported.
.
MessageId=2002
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_COMMAND_NOT_SUPPORTED
Language=English
The command %1$d is not supported.
.
MessageId=2003
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_CONFIGURATION_FILE_NOT_SUPPORTED
Language=English
[!output PREFIX] Provider does not support configuration files.
.
MessageId=2004
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_INVALID
Language=English
Connection is invalid.
.
MessageId=2005
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_REQUIRED_PROPERTY_NULL
Language=English
The required property '%1$ls' cannot be set to NULL.
.
MessageId=2006
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_ENUM_PROPERTY_WRONG_VALUE
Language=English
The given value '%1$ls' for enumerable property '%2$ls' is not in the enumeration value collection.
.
MessageId=2007
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_PROPERTY_NOT_FOUND
Language=English
The connection property '%1$ls' was not found.
.
MessageId=2008
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_NOT_ESTABLISHED
Language=English
Connection not established.
.


;//************************************************************************************
;//************************************************************************************
;//** CONNECTION PROPERTIES 
;//************************************************************************************
;//************************************************************************************

MessageId=3001
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_PROPERTY_DATASTORE
Language=English
DataStore
.


;//************************************************************************************
;//************************************************************************************
;//** SCHEMA-RELATED MESSAGES 
;//************************************************************************************
;//************************************************************************************

MessageId=4001
SymbolicName=[!output UPPER_PREFIX]_OBJECT_PROPERTIES_NOT_SUPPORTED
Language=English
Object properties are not supported.
.
MessageId=4002
SymbolicName=[!output UPPER_PREFIX]_UNSUPPORTED_DATATYPE
Language=English
The '%1$ls' data type is not supported by [!output PREFIX].
.


;//************************************************************************************
;//************************************************************************************
;//** VERSION-RELATED MESSAGES 
;//************************************************************************************
;//************************************************************************************


;//************************************************************************************
;//************************************************************************************
;//** FILTERS & EXPRESSIONS MESSAGES 
;//************************************************************************************
;//************************************************************************************


;//************************************************************************************
;//************************************************************************************
;//** FEATURE COMMAND MESSAGES 
;//************************************************************************************
;//************************************************************************************

MessageId=7001
SymbolicName=[!output UPPER_PREFIX]_COMMAND_PARAMETERS_NOT_SUPPORTED
Language=English
Command parameters are not supported.
.
MessageId=7002
SymbolicName=[!output UPPER_PREFIX]_COMMAND_TIMEOUT_NOT_SUPPORTED
Language=English
Command timeout is not supported.
.
MessageId=7003
SymbolicName=[!output UPPER_PREFIX]_COMMAND_TRANSACTIONS_NOT_SUPPORTED
Language=English
Command get/set transaction is not supported.
.
MessageId=7004
SymbolicName=[!output UPPER_PREFIX]_CANCEL_NOT_SUPPORTED
Language=English
Cannot cancel command.
.
MessageId=7005
SymbolicName=[!output UPPER_PREFIX]_OPERATION_UNSUPPORTED
Language=English
This operation is not supported.
.

;//************************************************************************************
;//************************************************************************************
;//** LOCK-RELATED MESSAGES
;//************************************************************************************
;//************************************************************************************

[!if !LOCKING]
MessageId=8001
SymbolicName=[!output UPPER_PREFIX]_LOCKING_NOT_SUPPORTED
Language=English
Locking not supported.
.
[!endif]

;//************************************************************************************
;//************************************************************************************
;//** SPATIAL CONTEXT MESSAGES 
;//************************************************************************************
;//************************************************************************************



;//************************************************************************************
;//************************************************************************************
;//** TRANSACTION MESSAGES 
;//************************************************************************************
;//************************************************************************************

[!if !TRANSACTIONS]
MessageId=10001
SymbolicName=[!output UPPER_PREFIX]_CONNECTION_TRANSACTIONS_NOT_SUPPORTED
Language=English
[!output PREFIX] Provider does not support transactions.
.
[!endif]
