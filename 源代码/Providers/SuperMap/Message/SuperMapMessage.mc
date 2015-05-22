;
;/** \file	 SuperMapMessage.h
; *  \brief	 信息ID
; *  \author	 郝玉江
; *  \attention 
; *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
; *  All Rights Reserved
; *  \version 1.0
; *  \date 2007-09-19
; */

;
;
;#ifdef __SUPERMAP_MESSAGE_DEFINE__
;// the default message catalog filename
;#	ifdef _WIN32
;		char *fdoshp_cat = "SuperMapMessage.dll";
;#	else
;		char *fdoshp_cat = "SuperMapMessage.cat";
;#	endif
;	FdoString* NlsMsgGet(int msg_num, char* default_msg, ...)
;	{
;		va_list varargs;
;		va_start(varargs, default_msg);
;		FdoString* ret = FdoException::NLSGetMessage(msg_num, default_msg, fdoshp_cat, varargs);
;		va_end(varargs);
;
;		return ret;
;	}
;#else // __SUPERMAP_MESSAGE_DEFINE__
;	extern char *fdoshp_cat;
;	extern FdoString* NlsMsgGet(int msg_num, char* default_msg, ...);
;#endif // __SUPERMAP_MESSAGE_DEFINE__
;

MessageIdTypedef=DWORD

;
;//LanguageNames=(English=0x409:MSG00409)
;//LanguageNames=(Chinese=0x804:MSG00804)
;
LanguageNames=(Chinese=0x804:MSG00804)

MessageId=1000
SymbolicName=SUPERMAP_UNEXPECTED_ERROR
Language=Chinese
在SuperMap数据访问接口中发生未预料到错误'%1$ls'。
.
MessageId=1002
SymbolicName=SUPERMAP_OPEN_FAILED
Language=Chinese
打开数据源失败。
.
MessageId=1003
SymbolicName=SUPERMAP_NULL_ARGUMENT
Language=Chinese
参数为NULL。
.
MessageId=1004
SymbolicName=SUPERMAP_INVALID_PROPERTY_NAME
Language=Chinese
属性名称错误。
.
MessageId=1005
SymbolicName=SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED
Language=Chinese
SuperMap提供者不支持配置文件。
.
;//************************************************************************************
;//************************************************************************************
;//** CONNECTION MESSAGES 
;//************************************************************************************
;//************************************************************************************
MessageId=1006
SymbolicName=SUPERMAP_CONNECTION_ALREADY_OPEN
Language=Chinese
已经建立连接。
.
MessageId=1007
SymbolicName=SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED
Language=Chinese
不支持连接超时。
.
MessageId=1008
SymbolicName=SUPERMAP_CONNECTION_LOCATION_NOT_EXIST
Language=Chinese
连接 '%1$ls' 文件不存在。
.
MessageId=1009
SymbolicName=SUPERMAP_INVALID_CONNECTION_STRING
Language=Chinese
无效连接字符串 '%1$ls' 。
.
MessageId=1010
SymbolicName=SUPERMAP_CONNECTION_INVALID
Language=Chinese
连接无效。
.
MessageId=1011
SymbolicName=SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME
Language=Chinese
无效连接属性名 '%1$ls'
.
MessageId=1012
SymbolicName=SUPERMAP_CONNECTION_PROPERTY_DATASTORE
Language=Chinese
数据集
.
MessageId=1013
SymbolicName=SUPERMAP_CONNECTION_NOT_ESTABLISHED
Language=Chinese
连接无效。
.

MessageId=1014
SymbolicName=SUPERMAP_CONNECTION_NOT_TYPE
Language=Chinese
缺少连接类型。
.

MessageId=1015
SymbolicName=SUPERMAP_CONNECTION_NOT_SERVER
Language=Chinese
缺少连接服务器。
.

MessageId=1016
SymbolicName=SUPERMAP_CONNECTION_NOT_DATABASE
Language=Chinese
缺少连接数据库。
.

MessageId=1017
SymbolicName=SUPERMAP_CONNECTION_NOT_USER
Language=Chinese
缺少连接数据库的用户。
.

MessageId=1018
SymbolicName=SUPERMAP_CONNECTION_NOT_PASSWORD
Language=Chinese
缺少连接数据库的密码。
.
MessageId=1019
SymbolicName=SUPERMAP_CONNECTION_FAIL
Language=Chinese
连接数据库失败。
.

MessageId=1020
SymbolicName=SUPERMAP_CONNECTION_STRING
Language=Chinese
连接字符串
.


;//************************************************************************************
;//************************************************************************************
;//** SCHEMA-RELATED MESSAGES 
;//************************************************************************************
;//************************************************************************************
MessageId=2001
SymbolicName=SUPERMAP_SCHEMA_FAIL_READ_FEATURE_SCHEMAS
Language=Chinese
从配置中加载模式出错。
.
MessageId=2002
SymbolicName=SUPERMAP_SCHEMA_FAIL_READ_SCHEMA_MAPPINGS
Language=Chinese
从配置中加载模式映射出错。
.
MessageId=2003
SymbolicName=SUPERMAP_INVALID_PHYSICAL_SCHEMA_PROVIDER_NAME
Language=Chinese
无效实体模式映射提供名。
.
;//************************************************************************************
;//************************************************************************************
;//** CONNECTION PROPERTIES 
;//************************************************************************************
;//************************************************************************************

MessageId=3000
SymbolicName=SUPERMAP_CONNECTION_PROPERTY_DATASOURCE
Language=Chinese
数据源
.
MessageId=3001
SymbolicName=SUPERMAP_CONNECTIONPROPERTY_TEMPORARY_FILE
Language=Chinese
临时目录
.
MessageId=3002
SymbolicName=SUPERMAP_CONNECTIONPROPERTY_CONN_TYPE
Language=Chinese
连接类型
.


;//************************************************************************************
;//************************************************************************************
;//** TRANSACTION MESSAGES 
;//************************************************************************************
;//************************************************************************************

MessageId=4001
SymbolicName=SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED
Language=Chinese
SuperMap SDB/SDX+ 数据访问不支持事务处理。
.

MessageId=4002
SymbolicName=SUPERMAP_TRANSACTIONS_NOT_START
Language=Chinese
数据访问不能启动事务。
.

MessageId=4003
SymbolicName=SUPERMAP_TRANSACTION_SPENT
Language=Chinese
这个事务已经执行过提交或回滚。
.

MessageId=4004
SymbolicName=SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED
Language=Chinese
不支持事务嵌套。
.

;//************************************************************************************
;//************************************************************************************
;//** CONNECTION INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=5001
SymbolicName=SUPERMAP_PROVIDER_DISPLAY_NAME
Language=Chinese
适用于 SuperMap SDB/SDX+ 的 FDO 提供程序
.
MessageId=5002
SymbolicName=SUPERMAP_PROVIDER_DESCRIPTION
Language=Chinese
对基于 SuperMap SDB/SDX+ 的数据存储具有读和写权限。
.

;//************************************************************************************
;//************************************************************************************
;//** SELECT INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=6001
SymbolicName=SUPERMAP_UNEXPECTED_DATATYPE
Language=Chinese
要素源中无对应的数据类型'%1$ls'
.

;//************************************************************************************
;//************************************************************************************
;//** SCHEMA INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=7001
SymbolicName=SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION
Language=Chinese
缺省模式
.

MessageId=7002
SymbolicName=SUPERMAP_DEFAULT_SCHEMA_NAME
Language=Chinese
缺省模式
.

MessageId=7003
SymbolicName=SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED
Language=Chinese
不支持物理模式映射
.

MessageId=7004
SymbolicName=SUPERMAP_SCHEMA_NOT_SPECIFIED
Language=Chinese
不支持物理模式映射
.

MessageId=7005
SymbolicName=SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE
Language=Chinese
不支持的模式元素状态
.

MessageId=7006
SymbolicName=SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA
Language=Chinese
模式元素状态冲突，在待添加的模式中有已删除的类
.

MessageId=7007
SymbolicName=SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA
Language=Chinese
模式元素状态冲突，在待添加的模式中有已修改的类
.

MessageId=7008
SymbolicName=SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA
Language=Chinese
模式元素状态冲突，在待添加的模式中有未变化的类
.

MessageId=7009
SymbolicName=SUPERMAP_CLASS_NAME_INVALID
Language=Chinese
'%l$s'无效的要素类名
.

MessageId=7010
SymbolicName=SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY
Language=Chinese
要素类 '%l$ls' 包含超过一个几何属性
.

MessageId=7011
SymbolicName=SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z
Language=Chinese
暂时不支持Z维的对象
.

MessageId=7012
SymbolicName=SUPERMAP_GEOMETRY_NOT_SUPPORTED_M
Language=Chinese
暂时不支持M维的对象
.

MessageId=7013
SymbolicName=SUPERMAP_DATASET_CREATED_FAILED
Language=Chinese
'%l$ls' 矢量数据集创建失败
.

MessageId=7014
SymbolicName=SUPERMAP_CREATED_FAILED
Language=Chinese
模式创建失败
.

MessageId=7015
SymbolicName=SUPERMAP_DATA_TYPE_NOT_SUPPORTED
Language=Chinese
此Fdo数据类型'%l$d'本provider暂不支持
.

MessageId=7016
SymbolicName=SUPERMAP_FIELD_CREATED_FAILED
Language=Chinese
物理数据集的字段创建失败
.

MessageId=7017
SymbolicName=SUPERMAP_DATASET_EXIST
Language=Chinese
该物理数据集名已经存在
.

MessageId=7018
SymbolicName=SUPERMAP_SCHEMA_NAME_SHOULD_BE_CHANGED
Language=Chinese
该模式名已经存在，请修改模式名。
.

MessageId=7019
SymbolicName=SUPERMAP_NOT_SUPPORT_DATASET_TYPE
Language=Chinese
对不起，暂时不支持点、线、面、文本、复合数据集以外的数据集类型。
.

MessageId=7020
SymbolicName=SUPERMAP_IMAGE_SCHEMA_NAME
Language=Chinese
影像模式
.

MessageId=7021
SymbolicName=SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS
Language=Chinese
不能删除类'%1$ls'，因为它包含数据
.

MessageId=7022
SymbolicName=SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS
Language=Chinese
不能修改类'%1$ls'，因为它包含数据
.

MessageId=7023
SymbolicName=SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA
Language=Chinese
不能删除模式'%1$ls'，因为其中的类 '%2$ls'包含数据
.

MessageId=7024
SymbolicName=SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND
Language=Chinese
不能删除类'%1$ls'，因为找不到该类
.


;//************************************************************************************
;//************************************************************************************
;//** GEOMETRY INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=8001
SymbolicName=SUPERMAP_UNKNOWN_SHAPE_TYPE
Language=Chinese
暂不支持的数据集（几何）类型'%1$d'
.

;//************************************************************************************
;//************************************************************************************
;//** FEATURE SOURCE INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=9001
SymbolicName=SUPERMAP_FEATURE_SOURCE_NOT_OPEN
Language=Chinese
无法打开要素源 '%1$ls'
.


MessageId=9002
SymbolicName=SUPERMAP_COMPLICATED_FEATURE_OBJECT_NOT_SUPPORTED
Language=Chinese
要素源中暂不支持复杂几何对象 '%1$ls'
.

MessageId=9003
SymbolicName=SUPERMAP_LOCKING_NOT_SUPPORTED
Language=Chinese
不支持锁定 '%1$ls'
.

MessageId=9004
SymbolicName=SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT
Language=Chinese
点图层不支持创建多点
.

MessageId=9005
SymbolicName=SUPERMAP_FEATURE_NOT_EXIST
Language=Chinese
该要素已经不存在，请取消要素检出
.

;//************************************************************************************
;//************************************************************************************
;//** SPATIAL CONTEXT INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=10001
SymbolicName=SUPERMAP_READER_NOT_READY
Language=Chinese
'%1$ls'空间语义读取器未准备好
.

MessageId=10002
SymbolicName=SUPERMAP_SPATIALCONTEXT_EMPTYWKT
Language=Chinese
WKT串不能为空
.

MessageId=10003
SymbolicName=SUPERMAP_SPATIALCONTEXT_INVALIDWKT
Language=Chinese
非法的WKT串，解析不出坐标系名称
.

MessageId=10004
SymbolicName=SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT
Language=Chinese
空间语义名与WKT串冲突
.

;//************************************************************************************
;//************************************************************************************
;//** FILTER INFORMATION
;//************************************************************************************
;//************************************************************************************

MessageId=11001
SymbolicName=SUPERMAP_OUT_OF_MEMORY_ERROR
Language=Chinese
内存分配失败
.

MessageId=11002
SymbolicName=SUPERMAP_FILTER_MISSING_OPERAND
Language=Chinese
过滤中丢失逻辑运算符
.

MessageId=11003
SymbolicName=SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT
Language=Chinese
一元逻辑运算仅支持NOT运算
.

MessageId=11004
SymbolicName=SUPERMAP_FILTER_MISSING_EXPRESSION
Language=Chinese
丢失左或者右表达式
.

MessageId=11005
SymbolicName=SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION
Language=Chinese
未知比较运算符
.

MessageId=11006
SymbolicName=SUPERMAP_FILTER_MISSING_PROPERTY
Language=Chinese
运算符丢失属性名
.
MessageId=11007
SymbolicName=SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE
Language=Chinese
IN运算符丢失属性值
.

MessageId=11008
SymbolicName=SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED
Language=Chinese
不支持的二元表达式
.

MessageId=11009
SymbolicName=SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE
Language=Chinese
一元表达式仅支持负操作
.

MessageId=11010
SymbolicName=SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION
Language=Chinese
目前不支持该表达式
.

;//************************************************************************************
;//************************************************************************************
;//** RASTER INFORMATION
;//************************************************************************************
;//************************************************************************************

MessageId=12001
SymbolicName=SUPERMAP_UNEXPECTED_PARAMETER
Language=Chinese
无效参数
.

MessageId=12002
SymbolicName=SUPERMAP_PALLETTE_NOT_SUPPORTED
Language=Chinese
目前还不支持带有调色板的图像读取
.
