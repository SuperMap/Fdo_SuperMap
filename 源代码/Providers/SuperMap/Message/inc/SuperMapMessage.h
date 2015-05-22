
/** \file	 SuperMapMessage.h
 *  \brief	 信息ID
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#ifdef __SUPERMAP_MESSAGE_DEFINE__
// the default message catalog filename
#	ifdef _WIN32
		char *fdoshp_cat = "SuperMapMessage.dll";
#	else
		char *fdoshp_cat = "SuperMapMessage.cat";
#	endif
	FdoString* NlsMsgGet(int msg_num, char* default_msg, ...)
	{
		va_list varargs;
		va_start(varargs, default_msg);
		FdoString* ret = FdoException::NLSGetMessage(msg_num, default_msg, fdoshp_cat, varargs);
		va_end(varargs);

		return ret;
	}
#else // __SUPERMAP_MESSAGE_DEFINE__
	extern char *fdoshp_cat;
	extern FdoString* NlsMsgGet(int msg_num, char* default_msg, ...);
#endif // __SUPERMAP_MESSAGE_DEFINE__


//LanguageNames=(English=0x409:MSG00409)
//LanguageNames=(Chinese=0x804:MSG00804)

//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: SUPERMAP_UNEXPECTED_ERROR
//
// MessageText:
//
//  在SuperMap数据访问接口中发生未预料到错误'%1$ls'。
//
#define SUPERMAP_UNEXPECTED_ERROR        ((DWORD)0x000003E8L)

//
// MessageId: SUPERMAP_OPEN_FAILED
//
// MessageText:
//
//  打开数据源失败。
//
#define SUPERMAP_OPEN_FAILED             ((DWORD)0x000003EAL)

//
// MessageId: SUPERMAP_NULL_ARGUMENT
//
// MessageText:
//
//  参数为NULL。
//
#define SUPERMAP_NULL_ARGUMENT           ((DWORD)0x000003EBL)

//
// MessageId: SUPERMAP_INVALID_PROPERTY_NAME
//
// MessageText:
//
//  属性名称错误。
//
#define SUPERMAP_INVALID_PROPERTY_NAME   ((DWORD)0x000003ECL)

//
// MessageId: SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED
//
// MessageText:
//
//  SuperMap提供者不支持配置文件。
//
#define SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED ((DWORD)0x000003EDL)

//************************************************************************************
//************************************************************************************
//** CONNECTION MESSAGES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_CONNECTION_ALREADY_OPEN
//
// MessageText:
//
//  已经建立连接。
//
#define SUPERMAP_CONNECTION_ALREADY_OPEN ((DWORD)0x000003EEL)

//
// MessageId: SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED
//
// MessageText:
//
//  不支持连接超时。
//
#define SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED ((DWORD)0x000003EFL)

//
// MessageId: SUPERMAP_CONNECTION_LOCATION_NOT_EXIST
//
// MessageText:
//
//  连接 '%1$ls' 文件不存在。
//
#define SUPERMAP_CONNECTION_LOCATION_NOT_EXIST ((DWORD)0x000003F0L)

//
// MessageId: SUPERMAP_INVALID_CONNECTION_STRING
//
// MessageText:
//
//  无效连接字符串 '%1$ls' 。
//
#define SUPERMAP_INVALID_CONNECTION_STRING ((DWORD)0x000003F1L)

//
// MessageId: SUPERMAP_CONNECTION_INVALID
//
// MessageText:
//
//  连接无效。
//
#define SUPERMAP_CONNECTION_INVALID      ((DWORD)0x000003F2L)

//
// MessageId: SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME
//
// MessageText:
//
//  无效连接属性名 '%1$ls'
//
#define SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME ((DWORD)0x000003F3L)

//
// MessageId: SUPERMAP_CONNECTION_PROPERTY_DATASTORE
//
// MessageText:
//
//  数据集
//
#define SUPERMAP_CONNECTION_PROPERTY_DATASTORE ((DWORD)0x000003F4L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_ESTABLISHED
//
// MessageText:
//
//  连接无效。
//
#define SUPERMAP_CONNECTION_NOT_ESTABLISHED ((DWORD)0x000003F5L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_TYPE
//
// MessageText:
//
//  缺少连接类型。
//
#define SUPERMAP_CONNECTION_NOT_TYPE     ((DWORD)0x000003F6L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_SERVER
//
// MessageText:
//
//  缺少连接服务器。
//
#define SUPERMAP_CONNECTION_NOT_SERVER   ((DWORD)0x000003F7L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_DATABASE
//
// MessageText:
//
//  缺少连接数据库。
//
#define SUPERMAP_CONNECTION_NOT_DATABASE ((DWORD)0x000003F8L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_USER
//
// MessageText:
//
//  缺少连接数据库的用户。
//
#define SUPERMAP_CONNECTION_NOT_USER     ((DWORD)0x000003F9L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_PASSWORD
//
// MessageText:
//
//  缺少连接数据库的密码。
//
#define SUPERMAP_CONNECTION_NOT_PASSWORD ((DWORD)0x000003FAL)

//
// MessageId: SUPERMAP_CONNECTION_FAIL
//
// MessageText:
//
//  连接数据库失败。
//
#define SUPERMAP_CONNECTION_FAIL         ((DWORD)0x000003FBL)

//
// MessageId: SUPERMAP_CONNECTION_STRING
//
// MessageText:
//
//  连接字符串
//
#define SUPERMAP_CONNECTION_STRING       ((DWORD)0x000003FCL)

//************************************************************************************
//************************************************************************************
//** SCHEMA-RELATED MESSAGES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_SCHEMA_FAIL_READ_FEATURE_SCHEMAS
//
// MessageText:
//
//  从配置中加载模式出错。
//
#define SUPERMAP_SCHEMA_FAIL_READ_FEATURE_SCHEMAS ((DWORD)0x000007D1L)

//
// MessageId: SUPERMAP_SCHEMA_FAIL_READ_SCHEMA_MAPPINGS
//
// MessageText:
//
//  从配置中加载模式映射出错。
//
#define SUPERMAP_SCHEMA_FAIL_READ_SCHEMA_MAPPINGS ((DWORD)0x000007D2L)

//
// MessageId: SUPERMAP_INVALID_PHYSICAL_SCHEMA_PROVIDER_NAME
//
// MessageText:
//
//  无效实体模式映射提供名。
//
#define SUPERMAP_INVALID_PHYSICAL_SCHEMA_PROVIDER_NAME ((DWORD)0x000007D3L)

//************************************************************************************
//************************************************************************************
//** CONNECTION PROPERTIES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_CONNECTION_PROPERTY_DATASOURCE
//
// MessageText:
//
//  数据源
//
#define SUPERMAP_CONNECTION_PROPERTY_DATASOURCE ((DWORD)0x00000BB8L)

//
// MessageId: SUPERMAP_CONNECTIONPROPERTY_TEMPORARY_FILE
//
// MessageText:
//
//  临时目录
//
#define SUPERMAP_CONNECTIONPROPERTY_TEMPORARY_FILE ((DWORD)0x00000BB9L)

//
// MessageId: SUPERMAP_CONNECTIONPROPERTY_CONN_TYPE
//
// MessageText:
//
//  连接类型
//
#define SUPERMAP_CONNECTIONPROPERTY_CONN_TYPE ((DWORD)0x00000BBAL)

//************************************************************************************
//************************************************************************************
//** TRANSACTION MESSAGES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED
//
// MessageText:
//
//  SuperMap SDB/SDX+ 数据访问不支持事务处理。
//
#define SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED ((DWORD)0x00000FA1L)

//
// MessageId: SUPERMAP_TRANSACTIONS_NOT_START
//
// MessageText:
//
//  数据访问不能启动事务。
//
#define SUPERMAP_TRANSACTIONS_NOT_START  ((DWORD)0x00000FA2L)

//
// MessageId: SUPERMAP_TRANSACTION_SPENT
//
// MessageText:
//
//  这个事务已经执行过提交或回滚。
//
#define SUPERMAP_TRANSACTION_SPENT       ((DWORD)0x00000FA3L)

//
// MessageId: SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED
//
// MessageText:
//
//  不支持事务嵌套。
//
#define SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED ((DWORD)0x00000FA4L)

//************************************************************************************
//************************************************************************************
//** CONNECTION INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_PROVIDER_DISPLAY_NAME
//
// MessageText:
//
//  适用于 SuperMap SDB/SDX+ 的 FDO 提供程序
//
#define SUPERMAP_PROVIDER_DISPLAY_NAME   ((DWORD)0x00001389L)

//
// MessageId: SUPERMAP_PROVIDER_DESCRIPTION
//
// MessageText:
//
//  对基于 SuperMap SDB/SDX+ 的数据存储具有读和写权限。
//
#define SUPERMAP_PROVIDER_DESCRIPTION    ((DWORD)0x0000138AL)

//************************************************************************************
//************************************************************************************
//** SELECT INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_UNEXPECTED_DATATYPE
//
// MessageText:
//
//  要素源中无对应的数据类型'%1$ls'
//
#define SUPERMAP_UNEXPECTED_DATATYPE     ((DWORD)0x00001771L)

//************************************************************************************
//************************************************************************************
//** SCHEMA INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION
//
// MessageText:
//
//  缺省模式
//
#define SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION ((DWORD)0x00001B59L)

//
// MessageId: SUPERMAP_DEFAULT_SCHEMA_NAME
//
// MessageText:
//
//  缺省模式
//
#define SUPERMAP_DEFAULT_SCHEMA_NAME     ((DWORD)0x00001B5AL)

//
// MessageId: SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED
//
// MessageText:
//
//  不支持物理模式映射
//
#define SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED ((DWORD)0x00001B5BL)

//
// MessageId: SUPERMAP_SCHEMA_NOT_SPECIFIED
//
// MessageText:
//
//  不支持物理模式映射
//
#define SUPERMAP_SCHEMA_NOT_SPECIFIED    ((DWORD)0x00001B5CL)

//
// MessageId: SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE
//
// MessageText:
//
//  不支持的模式元素状态
//
#define SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE ((DWORD)0x00001B5DL)

//
// MessageId: SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA
//
// MessageText:
//
//  模式元素状态冲突，在待添加的模式中有已删除的类
//
#define SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA ((DWORD)0x00001B5EL)

//
// MessageId: SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA
//
// MessageText:
//
//  模式元素状态冲突，在待添加的模式中有已修改的类
//
#define SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA ((DWORD)0x00001B5FL)

//
// MessageId: SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA
//
// MessageText:
//
//  模式元素状态冲突，在待添加的模式中有未变化的类
//
#define SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA ((DWORD)0x00001B60L)

//
// MessageId: SUPERMAP_CLASS_NAME_INVALID
//
// MessageText:
//
//  '%l$s'无效的要素类名
//
#define SUPERMAP_CLASS_NAME_INVALID      ((DWORD)0x00001B61L)

//
// MessageId: SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY
//
// MessageText:
//
//  要素类 '%l$ls' 包含超过一个几何属性
//
#define SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY ((DWORD)0x00001B62L)

//
// MessageId: SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z
//
// MessageText:
//
//  暂时不支持Z维的对象
//
#define SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z ((DWORD)0x00001B63L)

//
// MessageId: SUPERMAP_GEOMETRY_NOT_SUPPORTED_M
//
// MessageText:
//
//  暂时不支持M维的对象
//
#define SUPERMAP_GEOMETRY_NOT_SUPPORTED_M ((DWORD)0x00001B64L)

//
// MessageId: SUPERMAP_DATASET_CREATED_FAILED
//
// MessageText:
//
//  '%l$ls' 矢量数据集创建失败
//
#define SUPERMAP_DATASET_CREATED_FAILED  ((DWORD)0x00001B65L)

//
// MessageId: SUPERMAP_CREATED_FAILED
//
// MessageText:
//
//  模式创建失败
//
#define SUPERMAP_CREATED_FAILED          ((DWORD)0x00001B66L)

//
// MessageId: SUPERMAP_DATA_TYPE_NOT_SUPPORTED
//
// MessageText:
//
//  此Fdo数据类型'%l$d'本provider暂不支持
//
#define SUPERMAP_DATA_TYPE_NOT_SUPPORTED ((DWORD)0x00001B67L)

//
// MessageId: SUPERMAP_FIELD_CREATED_FAILED
//
// MessageText:
//
//  物理数据集的字段创建失败
//
#define SUPERMAP_FIELD_CREATED_FAILED    ((DWORD)0x00001B68L)

//
// MessageId: SUPERMAP_DATASET_EXIST
//
// MessageText:
//
//  该物理数据集名已经存在
//
#define SUPERMAP_DATASET_EXIST           ((DWORD)0x00001B69L)

//
// MessageId: SUPERMAP_SCHEMA_NAME_SHOULD_BE_CHANGED
//
// MessageText:
//
//  该模式名已经存在，请修改模式名。
//
#define SUPERMAP_SCHEMA_NAME_SHOULD_BE_CHANGED ((DWORD)0x00001B6AL)

//
// MessageId: SUPERMAP_NOT_SUPPORT_DATASET_TYPE
//
// MessageText:
//
//  对不起，暂时不支持点、线、面、文本、复合数据集以外的数据集类型。
//
#define SUPERMAP_NOT_SUPPORT_DATASET_TYPE ((DWORD)0x00001B6BL)

//
// MessageId: SUPERMAP_IMAGE_SCHEMA_NAME
//
// MessageText:
//
//  影像模式
//
#define SUPERMAP_IMAGE_SCHEMA_NAME       ((DWORD)0x00001B6CL)

//
// MessageId: SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS
//
// MessageText:
//
//  不能删除类'%1$ls'，因为它包含数据
//
#define SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS ((DWORD)0x00001B6DL)

//
// MessageId: SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS
//
// MessageText:
//
//  不能修改类'%1$ls'，因为它包含数据
//
#define SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS ((DWORD)0x00001B6EL)

//
// MessageId: SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA
//
// MessageText:
//
//  不能删除模式'%1$ls'，因为其中的类 '%2$ls'包含数据
//
#define SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA ((DWORD)0x00001B6FL)

//
// MessageId: SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND
//
// MessageText:
//
//  不能删除类'%1$ls'，因为找不到该类
//
#define SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND ((DWORD)0x00001B70L)

//************************************************************************************
//************************************************************************************
//** GEOMETRY INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_UNKNOWN_SHAPE_TYPE
//
// MessageText:
//
//  暂不支持的数据集（几何）类型'%1$d'
//
#define SUPERMAP_UNKNOWN_SHAPE_TYPE      ((DWORD)0x00001F41L)

//************************************************************************************
//************************************************************************************
//** FEATURE SOURCE INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_FEATURE_SOURCE_NOT_OPEN
//
// MessageText:
//
//  无法打开要素源 '%1$ls'
//
#define SUPERMAP_FEATURE_SOURCE_NOT_OPEN ((DWORD)0x00002329L)

//
// MessageId: SUPERMAP_COMPLICATED_FEATURE_OBJECT_NOT_SUPPORTED
//
// MessageText:
//
//  要素源中暂不支持复杂几何对象 '%1$ls'
//
#define SUPERMAP_COMPLICATED_FEATURE_OBJECT_NOT_SUPPORTED ((DWORD)0x0000232AL)

//
// MessageId: SUPERMAP_LOCKING_NOT_SUPPORTED
//
// MessageText:
//
//  不支持锁定 '%1$ls'
//
#define SUPERMAP_LOCKING_NOT_SUPPORTED   ((DWORD)0x0000232BL)

//
// MessageId: SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT
//
// MessageText:
//
//  点图层不支持创建多点
//
#define SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT ((DWORD)0x0000232CL)

//
// MessageId: SUPERMAP_FEATURE_NOT_EXIST
//
// MessageText:
//
//  该要素已经不存在，请取消要素检出
//
#define SUPERMAP_FEATURE_NOT_EXIST       ((DWORD)0x0000232DL)

//************************************************************************************
//************************************************************************************
//** SPATIAL CONTEXT INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_READER_NOT_READY
//
// MessageText:
//
//  '%1$ls'空间语义读取器未准备好
//
#define SUPERMAP_READER_NOT_READY        ((DWORD)0x00002711L)

//
// MessageId: SUPERMAP_SPATIALCONTEXT_EMPTYWKT
//
// MessageText:
//
//  WKT串不能为空
//
#define SUPERMAP_SPATIALCONTEXT_EMPTYWKT ((DWORD)0x00002712L)

//
// MessageId: SUPERMAP_SPATIALCONTEXT_INVALIDWKT
//
// MessageText:
//
//  非法的WKT串，解析不出坐标系名称
//
#define SUPERMAP_SPATIALCONTEXT_INVALIDWKT ((DWORD)0x00002713L)

//
// MessageId: SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT
//
// MessageText:
//
//  空间语义名与WKT串冲突
//
#define SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT ((DWORD)0x00002714L)

//************************************************************************************
//************************************************************************************
//** FILTER INFORMATION
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_OUT_OF_MEMORY_ERROR
//
// MessageText:
//
//  内存分配失败
//
#define SUPERMAP_OUT_OF_MEMORY_ERROR     ((DWORD)0x00002AF9L)

//
// MessageId: SUPERMAP_FILTER_MISSING_OPERAND
//
// MessageText:
//
//  过滤中丢失逻辑运算符
//
#define SUPERMAP_FILTER_MISSING_OPERAND  ((DWORD)0x00002AFAL)

//
// MessageId: SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT
//
// MessageText:
//
//  一元逻辑运算仅支持NOT运算
//
#define SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT ((DWORD)0x00002AFBL)

//
// MessageId: SUPERMAP_FILTER_MISSING_EXPRESSION
//
// MessageText:
//
//  丢失左或者右表达式
//
#define SUPERMAP_FILTER_MISSING_EXPRESSION ((DWORD)0x00002AFCL)

//
// MessageId: SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION
//
// MessageText:
//
//  未知比较运算符
//
#define SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION ((DWORD)0x00002AFDL)

//
// MessageId: SUPERMAP_FILTER_MISSING_PROPERTY
//
// MessageText:
//
//  运算符丢失属性名
//
#define SUPERMAP_FILTER_MISSING_PROPERTY ((DWORD)0x00002AFEL)

//
// MessageId: SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE
//
// MessageText:
//
//  IN运算符丢失属性值
//
#define SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE ((DWORD)0x00002AFFL)

//
// MessageId: SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED
//
// MessageText:
//
//  不支持的二元表达式
//
#define SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED ((DWORD)0x00002B00L)

//
// MessageId: SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE
//
// MessageText:
//
//  一元表达式仅支持负操作
//
#define SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE ((DWORD)0x00002B01L)

//
// MessageId: SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION
//
// MessageText:
//
//  目前不支持该表达式
//
#define SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION ((DWORD)0x00002B02L)

//************************************************************************************
//************************************************************************************
//** RASTER INFORMATION
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_UNEXPECTED_PARAMETER
//
// MessageText:
//
//  无效参数
//
#define SUPERMAP_UNEXPECTED_PARAMETER    ((DWORD)0x00002EE1L)

//
// MessageId: SUPERMAP_PALLETTE_NOT_SUPPORTED
//
// MessageText:
//
//  目前还不支持带有调色板的图像读取
//
#define SUPERMAP_PALLETTE_NOT_SUPPORTED  ((DWORD)0x00002EE2L)

