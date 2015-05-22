/* $Id: sdeerno.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
/***********************************************************************
*
*N  {sdeerno.h}  --  SDE Error Numbers
*
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*P  Purpose:
* 
*
*   COPYRIGHT 1992-2005 ESRI
*
*   TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
*   Unpublished material - all rights reserved under the
*   Copyright Laws of the United States.
*
*   For additional information, contact:
*   Environmental Systems Research Institute, Inc.
*   Attn: Contracts Dept
*   380 New York Street
*   Redlands, California, USA 92373
*
*   email: contracts@esri.com
*   
*E
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*H  History:
*
*      ???                   9/91         Original coding.
*E
***********************************************************************/

#ifndef SDE_ERRNO
#define SDE_ERRNO

/******************************************************************************
****    FATAL SDE ERRORS
******************************************************************************/

#define SE_FAILURE              (-1)
#define SE_INVALID_LAYERINFO_OBJECT (-2)/* LAYERINFO pointer not initialized. */
#define SE_NO_ANNOTATION        (-3)    /* The given shape has no annotation */
#define SE_FINISHED             (-4)    /* STREAM LOADING OF SHAPES FINISHED */
#define SE_SDE_NOT_STARTED      (-5)    /* SDE NOT STARTED, CANNOT PERFORM FUNCTION */
#define SE_UNCHANGED            (-6)    /* THE SPECIFIED SHAPE WAS LEFT UNCHANGED */
#define SE_TASKS_EXCEEDED       (-7)    /* THE NUMBER OF SERVER TASKS IS @ MAXIMUM */
#define SE_CONNECTIONS_EXCEEDED (-7)    /* THE NUMBER OF SERVER CONNECTIONS IS @
                                           MAXIMUM */
#define SE_LOGIN_NOT_ALLOWED    (-8)    /* IOMGR NOT ACCEPTING CONNECTION REQUESTS */
#define SE_INVALID_USER         (-9)    /* CANNOT VALIDATE THE SPECIFIED USER AND
                                           PASSWORD */
#define SE_NET_FAILURE          (-10)   /* NETWORK I/O OPERATION FAILED */
#define SE_NET_TIMEOUT          (-11)   /* NETWORK I/O TIMEOUT */
#define SE_OUT_OF_SVMEM         (-12)   /* SERVER TASK CANNOT ALLOCATE NEEDED MEMORY */
#define SE_OUT_OF_CLMEM         (-13)   /* CLIENT TASK CANNOT ALLOCATE NEEDED MEMORY */
#define SE_OUT_OF_CONTEXT       (-14)   /* FUNCTION CALL IS OUT OF CONTEXT */
#define SE_NO_ACCESS            (-15)   /* NO ACCESS TO OBJECT */
#define SE_TOO_MANY_LAYERS      (-16)   /* Exceeded max_layers in giomgr.defs. */
#define SE_NO_LAYER_SPECIFIED   (-17)   /* MISSING LAYER SPECIFICATION */
#define SE_LAYER_LOCKED         (-18)   /* SPECIFIED LAYER IS LOCKED */
#define SE_LAYER_EXISTS         (-19)   /* SPECIFIED LAYER ALREADY EXISTS */
#define SE_LAYER_NOEXIST        (-20)   /* SPECIFIED LAYER DOES NOT EXIST */
#define SE_LAYER_INUSE          (-21)   /* SPECIFIED LAYER IS USE BY ANOTHER USER */
#define SE_FID_NOEXIST          (-22)   /* SPECIFIED SHAPE (LAYER:FID) DOESN'T EXIST */
#define SE_ROW_NOEXIST          (-22)   /* SPECIFIED ROW DOESN'T EXIST */
#define SE_FID_EXISTS           (-23)   /* SPECIFIED SHAPE (LAYER:FID) EXISTS */
#define SE_ROW_EXISTS           (-23)   /* SPECIFIED ROW EXISTS */
#define SE_LAYER_MISMATCH       (-24)   /* Both layers must be the same for this */
#define SE_NO_PERMISSIONS       (-25)   /* NO PERMISSION TO PERFORM OPERATION */
#define SE_INVALID_NOT_NULL     (-26)   /* COLUMN HAS NOT NULL CONSTRAINT. */
#define SE_INVALID_SHAPE        (-27)   /* INVALID SHAPE, CANNOT BE VERIFIED */
#define SE_INVALID_LAYER_NUMBER (-28)   /* MAP LAYER NUMBER OUT OF RANGE */
#define SE_INVALID_ENTITY_TYPE  (-29)   /* INVALID ENTITY TYPE */
#define SE_INVALID_SEARCH_METHOD (-30)  /* INVALID SEARCH METHOD */
#define SE_INVALID_ETYPE_MASK   (-31)   /* INVALID ENTITY TYPE MASK */
#define SE_BIND_CONFLICT        (-32)   /* BIND/SET/GET MIS-MATCH */
#define SE_INVALID_GRIDSIZE     (-33)   /* INVALID GRID SIZE */
#define SE_INVALID_LOCK_MODE    (-34)   /* INVALID LOCK MODE */
#define SE_ETYPE_NOT_ALLOWED    (-35)   /* ENTITY TYPE OF SHAPE IS NOT ALLOWED IN LAYER */
#define SE_TOO_MANY_POINTS      (-36)   /* Exceeded max points specified. */
#define SE_INVALID_NUM_OF_PTS   (-36)   /* Alternate name of above. */
#define SE_TABLE_NOEXIST        (-37)   /* DBMS TABLE DOES NOT EXIST */
#define SE_ATTR_NOEXIST         (-38)   /* SPECIFIED ATTRIBUTE COLUMN DOESN'T EXIST */
#define SE_LICENSE_FAILURE      (-39)   /* Underlying license manager problem. */
#define SE_OUT_OF_LICENSES      (-40)   /* No more SDE licenses available. */
#define SE_INVALID_COLUMN_VALUE (-41)   /* VALUE EXCEEDS VALID RANGE */
#define SE_INVALID_WHERE        (-42)   /* USER SPECIFIED WHERE CLAUSE IS INVALID */
#define SE_INVALID_SQL          (-42)   /* USER SPECIFIED SQL CLAUSE IS INVALID */
#define SE_LOG_NOEXIST          (-43)   /* SPECIFIED LOG FILE DOES NOT EXIST */
#define SE_LOG_NOACCESS         (-44)   /* UNABLE TO ACCESS SPECIFIED LOGFILE */
#define SE_LOG_NOTOPEN          (-45)   /* SPECIFIED LOGFILE IS NOT OPEN FOR I/O */
#define SE_LOG_IO_ERROR         (-46)   /* I/O ERROR USING LOGFILE */
#define SE_NO_SHAPES            (-47)   /* NO SHAPES SELECTED OR USED IN OPERATION */
#define SE_NO_LOCKS             (-48)   /* NO LOCKS DEFINED */
#define SE_LOCK_CONFLICT        (-49)   /* LOCK REQUEST CONFLICTS W/ ANOTHER
                                           ESTABLISHED LOCK */ 
#define SE_OUT_OF_LOCKS         (-50)   /* MAXIMUM LOCKS ALLOWED BY SYSTEM ARE IN USE */
#define SE_DB_IO_ERROR          (-51)   /* DATABASE LEVEL I/O ERROR OCCURRED */
#define SE_STREAM_IN_PROGRESS   (-52)   /* SHAPE/FID STREAM NOT FINISHED, CAN'T
                                           EXECUTE */
#define SE_INVALID_COLUMN_TYPE  (-53)   /* INVALID COLUMN DATA TYPE */
#define SE_TOPO_ERROR           (-54)   /* TOPOLOGICAL INTEGRITY ERROR */
#define SE_ATTR_CONV_ERROR      (-55)   /* ATTRIBUTE CONVERSION ERROR */
#define SE_INVALID_COLUMN_DEF   (-56)   /* INVALID COLUMN DEFINITION */
#define SE_INVALID_SHAPE_BUF_SIZE (-57) /* INVALID SHAPE ARRAY BUFFER SIZE */
#define SE_INVALID_ENVELOPE     (-58)   /* ENVELOPE IS NULL, HAS NEGATIVE VALUES
                                           OR MIN > MAX */
#define SE_TEMP_IO_ERROR        (-59)   /* TEMP FILE I/O ERROR, CAN'T OPEN OR RAN
                                           OUT OF DISK */
#define SE_GSIZE_TOO_SMALL      (-60)   /* SPATIAL INDEX GRID SIZE IS TOO SMALL */
#define SE_LICENSE_EXPIRED      (-61)   /* SDE RUN-TIME LICENSE HAS EXPIRED, NO
                                           LOGINS ALLOWED */
#define SE_TABLE_EXISTS         (-62)   /* DBMS TABLE EXISTS */
#define SE_INDEX_EXISTS         (-63)   /* INDEX WITH THE SPECIFIED NAME ALREADY EXISTS */
#define SE_INDEX_NOEXIST        (-64)   /* INDEX WITH THE SPECIFIED NAME DOESN'T EXIST */
#define SE_INVALID_POINTER      (-65)   /* SPECIFIED POINTER VALUE IS NULL OR INVALID */
#define SE_INVALID_PARAM_VALUE  (-66)   /* SPECIFIED PARAMETER VALUE IS INVALID */
#define SE_ALL_SLIVERS          (-67)   /* SLIVER FACTOR CAUSED ALL RESULTS TO BE
                                           SLIVERS */
#define SE_TRANS_IN_PROGRESS    (-68)   /* USER SPECIFIED TRANSACTION IN PROGRESS */
#define SE_IOMGR_NO_DBMS_CONNECT (-69)  /* The iomgr has lost its connection
                                           to the underlying DBMS. */
#define SE_DUPLICATE_ARC        (-70)   /* AN ARC (startpt,midpt,endpt) ALREADY EXISTS */
#define SE_INVALID_ANNO_OBJECT  (-71)   /* SE_ANNO pointer not initialized. */
#define SE_PT_NO_EXIST          (-72)   /* SPECIFIED POINT DOESN'T EXIST IN FEAT */
#define SE_PTS_NOT_ADJACENT     (-73)   /* SPECIFIED POINTS MUST BE ADJACENT */
#define SE_INVALID_MID_PT       (-74)   /* SPECIFIED MID POINT IS INVALID */
#define SE_INVALID_END_PT       (-75)   /* SPECIFIED END POINT IS INVALID */
#define SE_INVALID_RADIUS       (-76)   /* SPECIFIED RADIUS IS INVALID */
#define SE_LOAD_ONLY_LAYER      (-77)   /* MAP LAYER IS LOAD ONLY MODE, OPERATION
                                           NOT ALLOWED */
#define SE_LAYERS_NOT_FOUND     (-78)   /* LAYERS TABLE DOES NOT EXIST. */
#define SE_FILE_IO_ERROR        (-79)   /* Error writing or creating an output
                                           text file. */
#define SE_BLOB_SIZE_TOO_LARGE  (-80)   /* Maximum BLOB size exceeded. */
#define SE_CORRIDOR_OUT_OF_BOUNDS (-81) /* Resulting corridor exceeds valid
                                           coordinate range 
*/
#define SE_SHAPE_INTEGRITY_ERROR (-82)  /* MODEL INTEGRITY ERROR */
#define SE_NOT_IMPLEMENTED_YET  (-83)   /* Function or option is not really
                                           written yet. */
#define SE_CAD_EXISTS           (-84)   /* This shape has a cad. */
#define SE_INVALID_TRANSID      (-85)   /* Invalid internal SDE Transaction ID. */
#define SE_INVALID_LAYER_NAME   (-86)   /* MAP LAYER NAME MUST NOT BE EMPTY */
#define SE_INVALID_LAYER_KEYWORD (-87)  /* Invalid Layer Configuration Keyword used. */
#define SE_INVALID_RELEASE      (-88)   /* Invalid Release/Version of SDE server. */
#define SE_VERSION_TBL_EXISTS	(-89)	/* VERSION table exists. */
#define SE_COLUMN_NOT_BOUND     (-90)    /* Column has not been bound */
#define SE_INVALID_INDICATOR_VALUE (-91) /* Indicator variable contains an 
                                            invalid value */
#define SE_INVALID_CONNECTION   (-92)    /* The connection handle is NULL,
                                            closed or the wrong object. */
#define SE_INVALID_DBA_PASSWORD (-93)    /* The DBA password is not correct. */
#define SE_PATH_NOT_FOUND       (-94)    /* Coord path not found in shape
                                            edit op. */
#define SE_SDEHOME_NOT_SET      (-95)    /* No SDEHOME environment var set, and we
                                            need one. */
#define SE_NOT_TABLE_OWNER      (-96)    /* User must be table owner. */
#define SE_PROCESS_NOT_FOUND    (-97)    /* The process ID specified does not
                                            correspond on an SDE server.  */
#define SE_INVALID_DBMS_LOGIN   (-98)    /* DBMS didn't accept user/password. */
#define SE_PASSWORD_TIMEOUT     (-99)    /* Password received was sent > 
                                            MAXTIMEDIFF seconds before. */
#define SE_INVALID_SERVER       (-100)   /* Server machine was not found */
#define SE_IOMGR_NOT_AVAILABLE  (-101)   /* IO Mgr task not started on server */
#define SE_SERVICE_NOT_FOUND    (-102)   /* No SDE entry in the /etc/services file */
#define SE_INVALID_STATS_TYPE   (-103)   /* Tried statisitics on non-numeric */
#define SE_INVALID_DISTINCT_TYPE (-104)  /* Distinct stats on invalid type */
#define SE_INVALID_GRANT_REVOKE (-105)   /* Invalid use of grant/revoke function */
#define SE_INVALID_SDEHOME      (-106)   /* The supplied SDEHOME path is
                                            invalid or NULL.  */
#define SE_INVALID_STREAM       (-107)   /* Stream does not exist */
#define SE_TOO_MANY_STREAMS     (-108)   /* Max number of streams exceeded */
#define SE_OUT_OF_MUTEXES       (-109)   /* Exceeded system's max number of mutexs. */
#define SE_CONNECTION_LOCKED    (-110)   /* This connection is locked to a 
                                            different thread. */
#define SE_CONNECTION_IN_USE    (-111)   /* This connection is being used at the
                                            moment by another thread. */
#define SE_NOT_A_SELECT_STATEMENT (-112) /* The SQL statement was not a select */
#define SE_FUNCTION_SEQUENCE_ERROR (-113)/* Function called out of sequence */
#define SE_WRONG_COLUMN_TYPE    (-114)   /* Get request on wrong column type */
#define SE_PTABLE_LOCKED        (-115)   /* This ptable is locked to a different
                                            thread. */
#define SE_PTABLE_IN_USE        (-116)   /* This ptable is being used at the
                                             moment by another thread. */
#define SE_STABLE_LOCKED        (-117)   /* This stable is locked to a different
                                            thread. */
#define SE_STABLE_IN_USE        (-118)   /* This stable is being used at the
                                            moment by another thread. */
#define SE_INVALID_FILTER_TYPE  (-119)   /* Unrecognized spatial filter type. */
#define SE_NO_CAD               (-120)   /* The given shape has no CAD. */
#define SE_INSTANCE_NOT_AVAILABLE (-121) /* No instance running on server. */
#define SE_INSTANCE_TOO_EARLY   (-122)   /* Instance is a version previous to 2.0. */
#define SE_INVALID_SYSTEM_UNITS (-123)   /* Systems units < 1 or > 2147483647. */
#define SE_INVALID_UNITS        (-124)   /* FEET, METERS, DECIMAL_DEGREES or OTHER. */
#define SE_INVALID_CAD_OBJECT   (-125)   /* SE_CAD pointer not initialized. */
#define SE_VERSION_NOEXIST      (-126)   /* Version not found. */
#define SE_INVALID_SPATIAL_CONSTRAINT (-127) /* Spatial filters invalid for search */
#define SE_INVALID_STREAM_TYPE  (-128)   /* Invalid operation for the given stream */
#define SE_INVALID_SPATIAL_COLUMN  (-129) /* Column contains NOT NULL values during 
                                             SE_layer_create() */
#define SE_NO_SPATIAL_MASKS     (-130)   /* No spatial masks available.  */
#define SE_IOMGR_NOT_FOUND      (-131)   /* Iomgr program not found. */
#define SE_SYSTEM_IS_CLIENT_ONLY (-132)  /* Operation can not possibly be run on
                                            this system -- it needs a server. */
#define SE_MULTIPLE_SPATIAL_COLS (-133)  /* Only one spatial column allowed */
#define SE_INVALID_SHAPE_OBJECT (-134)   /* The given shape object handle is invalid */
#define SE_INVALID_PARTNUM      (-135)   /* The specified shape part number does
                                            not exist */
#define SE_INCOMPATIBLE_SHAPES  (-136)   /* The given shapes are of incompatible
                                            types */
#define SE_INVALID_PART_OFFSET  (-137)   /* The specified part offset is invalid */
#define SE_INCOMPATIBLE_COORDREFS (-138) /* The given coordinate references are
                                            incompatible */
#define SE_COORD_OUT_OF_BOUNDS  (-139)   /* The specified coordinate exceeds the
                                            valid coordinate range */
#define SE_LAYER_CACHE_FULL     (-140)   /* Max. Layers exceeded in cache */
#define SE_INVALID_COORDREF_OBJECT (-141) /* The given coordinate reference 
                                             object handle is invalid */
#define SE_INVALID_COORDSYS_ID  (-142)   /* The coordinate system identifier is
                                            invalid */
#define SE_INVALID_COORDSYS_DESC (-143)  /* The coordinate system description is
                                            invalid */
#define SE_INVALID_ROW_ID_LAYER (-144)   /* SE_ROW_ID is not a valid ArcSDE row_id
                                            column for this table or layer */
#define SE_PROJECTION_ERROR     (-145)   /* Error projecting shape points */
#define SE_ARRAY_BYTES_EXCEEDED (-146)   /* Max array bytes exceeded */
#define SE_POLY_SHELLS_OVERLAP      (-147)  /* 2 donuts or 2 outer shells overlap */
#define SE_TOO_FEW_POINTS           (-148)  /* Numofpts is less than required for
                                               feature */
#define SE_INVALID_PART_SEPARATOR   (-149)  /* part separator in the wrong position */
#define SE_INVALID_POLYGON_CLOSURE  (-150)  /* polygon does not close properly */
#define SE_INVALID_OUTER_SHELL      (-151)  /* A polygon outer shell does not
                                               completely enclose all donuts for
                                               the part */
#define SE_ZERO_AREA_POLYGON        (-152)  /* Polygon shell has no area */
#define SE_POLYGON_HAS_VERTICAL_LINE (-153) /* Polygon shell contains a vertical line */
#define SE_OUTER_SHELLS_OVERLAP     (-154)  /* Multipart area has overlapping parts */
#define SE_SELF_INTERSECTING        (-155)  /* Linestring or poly boundary is
                                               self-intersecting */
#define SE_INVALID_EXPORT_FILE      (-156)  /* Export file is invalid */
#define SE_READ_ONLY_SHAPE          (-157)  /* Attempted to modify or free a
                                               read-only shape from an
                                               stable. */
#define SE_INVALID_DATA_SOURCE      (-158)  /* Invalid data source */
#define SE_INVALID_STREAM_SPEC      (-159)  /* Stream Spec parameter exceeds
                                               giomgr default */
#define SE_INVALID_ALTER_OPERATION  (-160)  /* Tried to remove cad or anno */
#define SE_INVALID_SPATIAL_COL_NAME (-161)  /* Spat col name same as table name */
#define SE_INVALID_DATABASE         (-162)  /* Invalid database name */
#define SE_SPATIAL_SQL_NOT_INSTALLED (-163) /* Spatial SQL extension not
                                               present in underlying DBMS */
#define SE_NORM_DIM_INFO_NOT_FOUND  (-164)  /* Obsolete SDE 3.0.2 error */
#define SE_NORM_DIM_TAB_VALUE_NOT_FOUND (-165)  /* Obsolete SDE 3.0.2 error */
#define SE_UNSUPPORTED_NORMALIZED_OPERATION (-166)  /* " SDE 3.0.2 error */
#define SE_INVALID_REGISTERED_LAYER_OPTION (-167) /* Obsolete SDE 3.0.2 error*/
#define SE_READ_ONLY                (-168)  /* Has R/O access to SE_ROW_ID */
#define SE_NO_SDE_ROWID_COLUMN      (-169)  /* The current table doesn't have a
                                               SDE-maintained rowid column. */
#define SE_READ_ONLY_COLUMN         (-170)  /* Column is not user-modifiable */
#define SE_INVALID_VERSION_NAME     (-171)  /* Illegal or blank version name */
#define SE_STATE_NOEXIST            (-172)  /* A specified state is not in
                                               the VERSION_STATES table. */
#define SE_INVALID_STATEINFO_OBJECT (-173)  /* STATEINFO object not
                                               initialized. */
#define SE_VERSION_HAS_MOVED        (-174)  /* Attempted to change version
                                               state, but already changed. */
#define SE_STATE_HAS_CHILDREN       (-175)  /* Tried to open a state which
                                               has children. */
#define SE_PARENT_NOT_CLOSED        (-176)  /* To create a state, the parent
                                               state must be closed. */
#define SE_VERSION_EXISTS           (-177)  /* Version already exists. */
#define SE_TABLE_NOT_MULTIVERSION   (-178)  /* Table must be multiversion for
                                               this operation. */
#define SE_STATE_USED_BY_VERSION    (-179)  /* Can't delete state being used by
                                               a version. */
#define SE_INVALID_VERSIONINFO_OBJECT (-180) /* VERSIONINFO object not
                                                initialized. */
#define SE_INVALID_STATE_ID         (-181)  /* State ID out of range or not
                                               found. */
#define SE_SDETRACELOC_NOT_SET      (-182)  /* Environment var SDETRACELOC not
                                               set to a value   */
#define SE_ERROR_LOADING_SSA        (-183)  /* Error loading the SSA  */

#define SE_TOO_MANY_STATES          (-184)  /* This operation has more
                                               states than can fit in SQL. */
#define SE_STATES_ARE_SAME          (-185)  /* Function takes 2 <> states,
                                               but same one was given twice. */
#define SE_NO_ROWID_COLUMN          (-186)  /* Table has no usable row ID
                                               column. */
#define SE_NO_STATE_SET             (-187)  /* Call needs state to be set. */
#define SE_SSA_FUNCTION_ERROR       (-188)  /* Error executing SSA function */
#define SE_INVALID_REGINFO_OBJECT   (-189)  /* REGINFO object !initialized. */
#define SE_NO_COMMON_LINEAGE        (-190)  /* Attempting to trim between
                                               states on diff. branches */
#define SE_STATE_INUSE              (-191)  /* State is being modified. */
#define SE_STATE_TREE_INUSE         (-192)  /* Try to lock tree, and some
                                               state in tree already locked. */
#define SE_INVALID_RASTER_COLUMN    (-193)  /* Raster column has non-NULL values
                                               or used as row_id column */
#define SE_RASTERCOLUMN_EXISTS      (-194)  /* Raster column already exists */
#define SE_INVALID_MVTABLE_INDEX    (-195)  /* Unique indexes are not allowed
                                               on multiversion tables. */
#define SE_INVALID_STORAGE_TYPE     (-196)  /* Invalid layer storage type. */
#define SE_AMBIGUOUS_NIL_SHAPE      (-197)  /* No SQL type provided when 
                                               converting NIL shape to text */
#define SE_INVALID_BYTE_ORDER       (-198)  /* Invalid byte order for 
                                               Well-Known Binary shape */
#define SE_INVALID_GEOMETRY_TYPE    (-199)  /* Shape type in the given shape
                                               is not a valid geometry type */
#define SE_INVALID_NUM_MEASURES     (-200)  /* Number of measures in shape must
                                               be zero or equal to number 
                                               of points */
#define SE_INVALID_NUM_PARTS        (-201)  /* Number of parts in shape
                                               is incorrect for its
                                               geometry type */
#define SE_BINARY_TOO_SMALL         (-202)  /* Memory allocated for ESRI
                                               binary shape is too small */
#define SE_SHAPE_TEXT_TOO_LONG      (-203)  /* Shape text exceeds the 
                                               supplied maximum string length */
#define SE_SHAPE_TEXT_ERROR         (-204)  /* Found syntax error in the 
                                               supplied shape text */
#define SE_TOO_MANY_PARTS           (-205)  /* Number of parts in shape is more
                                               than expected for the given
                                               shape text */
#define SE_TYPE_MISMATCH            (-206)  /* Shape's SQL type is not as 
                                               expected when constructing 
                                               shape from text */
#define SE_SQL_PARENTHESIS_MISMATCH (-207)  /* Found parentheses mismatch 
                                               when parsing shape text */
#define SE_NIL_SHAPE_NOT_ALLOWED    (-208)  /* NIL shape is not allowed for
                                               Well-Known Binary 
                                               represenation */
#define SE_INSTANCE_ALREADY_RUNNING (-209)  /* Tried to start already running
                                               SDE instance. */
#define SE_UNSUPPORTED_OPERATION    (-210)  /* The operation requested is 
                                               unsupported. */
#define SE_INVALID_EXTERNAL_LAYER_OPTION (-211)  /* Invalid External layer
                                                    option. */ 
#define SE_NORMALIZE_VALUE_NOT_FOUND (-212) /* Normalized layer dimension 
                                               table value not found. */
#define SE_INVALID_QUERY_TYPE       (-213)  /* Invalid query type. */
#define SE_NO_TRACE_LIBRARY         (-214)  /* No trace functions in this
                                               library */
#define SE_TRACE_ON                 (-215)  /* Tried to enable tracing that
                                               was already on */ 
#define SE_TRACE_OFF                (-216)  /* Tried to disable tracing that
                                               was already off */ 
#define SE_SCL_SYNTAX_ERROR         (-217)  /* SCL Compiler doesn't like the
                                               SCL stmt */
#define SE_TABLE_REGISTERED         (-218)  /* Table already registered. */
#define SE_INVALID_REGISTRATION_ID  (-219)  /* Registration ID out of range */
#define SE_TABLE_NOREGISTERED       (-220)  /* Table not registered. */
#define SE_TOO_MANY_REGISTRATIONS   (-221)  /* Exceeded max_registrations. */
#define SE_DELETE_NOT_ALLOWED       (-222)  /* This object can not be deleted,
                                               other objects depend on it. */
#define SE_ROWLOCKING_ENABLED       (-223)  /* Row locking enabled      */
#define SE_ROWLOCKING_NOT_ENABLED   (-224)  /* Row locking not enabled  */
#define SE_RASTERCOLUMN_INUSE       (-225)  /* Specified raster column is used
                                               by another user */
#define SE_RASTERCOLUMN_NOEXIST     (-226)  /* The specified raster column 
                                               does not exist */
#define SE_INVALID_RASTERCOLUMN_NUMBER (-227) /* Raster column number 
                                                 out of range */
#define SE_TOO_MANY_RASTERCOLUMNS   (-228)  /* Maximum raster column 
                                               number exceeded */
#define SE_INVALID_RASTER_NUMBER    (-229)  /* Raster number out of range */
#define SE_NO_REQUEST_STATUS        (-230)  /* cannot determine 
                                               request status */
#define SE_NO_REQUEST_RESULTS       (-231)  /* cannot open request results */ 
#define SE_RASTERBAND_EXISTS        (-232)  /* Raster band already exists */
#define SE_RASTERBAND_NOEXIST       (-233)  /* The specified raster band 
                                               does not exist */
#define SE_RASTER_EXISTS            (-234)  /* Raster already exists */
#define SE_RASTER_NOEXIST           (-235)  /* The specified raster 
                                               does not exist */
#define SE_TOO_MANY_RASTERBANDS     (-236)  /* Maximum raster band 
                                               number exceeded */ 
#define SE_TOO_MANY_RASTERS         (-237)  /* Maximum raster number 
                                               exceeded */ 
#define SE_VIEW_EXISTS              (-238)   /* DBMS VIEW EXISTS */
#define SE_VIEW_NOEXIST             (-239)   /* DBMS VIEW NOT EXISTS */
#define SE_LOCK_EXISTS              (-240)   /* Lock record exist */
#define SE_ROWLOCK_MASK_CONFLICT    (-241)   /* Rowlocking mask conflict */
#define SE_NOT_IN_RASTER            (-242)   /* Raster band specified 
                                                not in a raster */
#define SE_INVALID_RASBANDINFO_OBJECT (-243) /* RASBANDINFO object
                                                not initialized */
#define SE_INVALID_RASCOLINFO_OBJECT (-244) /* RASCOLINFO object
                                               not initialized */
#define SE_INVALID_RASTERINFO_OBJECT (-245) /* RASTERINFO object 
                                               not initialized */
#define SE_INVALID_RASTERBAND_NUMBER (-246) /* Raster band number
                                               out of range */
#define SE_MULTIPLE_RASTER_COLS      (-247) /* Only one raster column allowed */
#define SE_TABLE_SCHEMA_IS_LOCKED    (-248) /* Table is being locked already */
#define SE_INVALID_LOGINFO_OBJECT    (-249) /* SE_LOGINFO pointer not initialized. */
#define SE_SQL_TOO_LONG              (-250) /* Operation generated a SQL
                                               statement too big to process.*/
#define SE_UNSUPPORTED_ON_VIEW       (-251) /* Not supported on a View.*/
#define SE_LOG_EXISTS                (-252) /* Specified log file exists already. */
#define SE_LOG_IS_OPEN               (-253) /* Specified log file is open. */
#define SE_SPATIALREF_EXISTS         (-254) /* Spatial reference entry exists. */
#define SE_SPATIALREF_NOEXIST        (-255) /* Spatial reference entry does not
                                               exist. */
#define SE_SPATIALREF_IN_USE         (-256) /* Spatial reference entry is
                                               in use by one or more layers. */
#define SE_INVALID_SPATIALREFINFO_OBJECT (-257) /* The SE_SPATIALREFINFO object
                                                   is not initialized. */
#define SE_SEQUENCENBR_EXISTS        (-258) /* Raster band sequence number 
                                               already exits. */
#define SE_INVALID_QUERYINFO_OBJECT  (-259) /* SE_QUERYINFO pointer not initialized. */
#define SE_QUERYINFO_NOT_PREPARED    (-260) /* SE_QUERYINFO pointer is not
                                               prepared for query. */
#define SE_INVALID_RASTILEINFO_OBJECT   (-261) /* RASTILEINFO object not 
                                                  initialized */
#define SE_INVALID_RASCONSTRAINT_OBJECT (-262) /* SE_RASCONSTRAINT object not 
                                                  initialized */
#define SE_INVALID_METADATA_RECORD_ID (-263)  /* invalid record id number */
#define SE_INVALID_METADATA_OBJECT (-264)   /* SE_METADATAINFO pointer not 
                                               initialized */
#define SE_INVALID_METADATA_OBJECT_TYPE (-265) /* unsupported object type */
#define SE_SDEMETADATA_NOT_FOUND        (-266) /* SDEMETADATA table does not exist */
#define SE_METADATA_RECORD_NOEXIST      (-267) /* Metadata record does not exist. */
#define SE_GEOMETRYCOL_NOEXIST          (-268) /* Geometry entry does not exist */
#define SE_INVALID_FILE_PATH            (-269) /* File path too long or invalid */
#define SE_INVALID_LOCATOR_OBJECT_TYPE  (-270) /* Locator object not initialized */
#define SE_INVALID_LOCATOR              (-271) /* Locator cannot be validated */
#define SE_TABLE_HAS_NO_LOCATOR         (-272) /* Table has no associated locator */
#define SE_INVALID_LOCATOR_CATEGORY     (-273) /* Locator cateogry is not specified */
#define SE_INVALID_LOCATOR_NAME         (-274) /* Invalid locator name */
#define SE_LOCATOR_NOEXIST              (-275) /* Locator does not exist */
#define SE_LOCATOR_EXISTS               (-276) /* A locator with that name exists */
#define SE_INVALID_LOCATOR_TYPE         (-277) /* Unsupported Locator type */
#define SE_NO_COORDREF                  (-278) /* No coordref defined */
#define SE_CANT_TRIM_RECONCILED_STATE   (-279) /* Can't trim past a reconciled
                                                  state. */
#define SE_FILE_OBJECT_NOEXIST          (-280) /* Fileinfo object does not 
                                                  exist. */
#define SE_FILE_OBJECT_EXISTS           (-281) /* Fileinfo object already 
                                                  exists. */
#define SE_INVALID_FILEINFO_OBJECT      (-282) /* Fileinfo object not 
                                                  initialized. */
#define SE_INVALID_FILEINFO_OBJECT_TYPE (-283) /* Unsupported Fileinfo object 
                                                  type. */
#define SE_RASTERBAND_NO_STATS          (-284) /* No statistics available for
                                                  this raster band. */
#define SE_VERSION_HAS_CHILDREN         (-285) /* Can't delete a version with
                                                  children. */
#define SE_SQLTYPE_UNSUPPORTED_ETYPE    (-286) /* SQL type does not support ANNO
                                                  or CAD at current release */
#define SE_NO_DBTUNE_FILE               (-287) /* The DBTUNE file is missing 
                                                  or unreadable. */
#define SE_LOG_SYSTABLES_CREATE_FAILED  (-288) /* Logfile system tables do not
                                                  exist. */
#define SE_OBJECT_RESTRICTED            (-289) /* This app can't perform this
                                                  operation on this object. */
#define SE_INVALID_GEOGTRAN_OBJECT      (-290) /* The given geographic 
                                                  transformation object 
                                                  handle is invalid */
#define SE_COLUMN_EXISTS                (-291) /* Column already exists */
#define SE_SQL_KEYWORD                  (-292) /* SQL keyword violation. */
#define SE_INVALID_OBJECTLOCKINFO_OBJECT (-293) /* The supplied objectlock
                                                   handle is bad. */
#define SE_RASTERBUFFER_TOO_SMALL       (-294) /* The raster buffer size 
                                                  is too small. */
#define SE_INVALID_RASTER_DATA          (-295) /* Invalid raster data */
#define SE_OPERATION_NOT_ALLOWED        (-296) /* This operation is not 
                                                  allowed */
#define SE_INVALID_RASTERATTR_OBJECT    (-297) /* SE_RASTERATTR object not 
                                                  initialized */
#define SE_INVALID_VERSION_ID           (-298) /* Version ID out of range. */
#define SE_MVTABLE_CANT_BE_LOAD_ONLY    (-299) /* Attempting to make an MV
                                                  table load-only */
#define SE_INVALID_SDO_GEOM_METADATA_OBJ (-300) /* The user-supplied table/
                                                   column is invalid. */
#define SE_ROW_OUT_OF_SEQUENCE          (-301) /* The next row was not the row
                                                  expected. */
#define SE_INSTANCE_IS_READ_ONLY        (-302) /* The ArcSDE instance is 
                                                  read-only */
#define SE_MOSAIC_NOT_ALLOWED           (-303) /* Image mosaicking is not
                                                  allowed */
#define SE_INVALID_RASTER_BITMAP        (-304) /* Invalid raster bitmap 
                                                  object */
#define SE_SEQUENCENBR_NOEXIST          (-305) /* The specified band sequence 
                                                  number does not exist. */
#define SE_SQLTYPE_INVALID_FEATURE_TYPE (-306) /* Invalid SQLTYPE feature type
                                                  (i.e. Rect, Arc, Circle) */ 
#define SE_DBMS_OBJECTS_NOT_SUPPORTED   (-307) /* DBMS Objects (Spatial, ADT's
                                                  not supported */ 
#define SE_BINARY_CONV_NO_COLUMNS_FOUND (-308) /* No columns found for binary
                                                  conversion (LOB/LONGRAW) */
#define SE_RASTERBAND_NO_COLORMAP       (-309) /* The raster band has no
                                                  colormap. */
#define SE_INVALID_BIN_FUNCTION         (-310) /* Invalid raster band bin 
                                                  function. */
#define SE_INVALID_RASTERBAND_STATS     (-311) /* Invalid raster band
                                                  statistics. */
#define SE_INVALID_RASTERBAND_COLORMAP  (-312) /* Invalid raster band 
                                                  colormap */
#define SE_INVALID_RASTER_KEYWORD       (-313) /* Invalid raster layer
                                                  configuration keyword */
#define SE_INCOMPATIBLE_INSTANCE        (-314) /* This sort of iomgr can't run
                                                  on this sort of instance. */
#define SE_INVALID_VOLUME_INFO          (-315) /* Export file's volume info is
                                                  invalid */
#define SE_INVALID_COMPRESSION_TYPE     (-316) /* Invalid compression type */
#define SE_INVALID_INDEX_PARAM          (-317) /* Invalid index parameter */
#define SE_INVALID_INDEX_TYPE           (-318) /* Invalid index type */
#define SE_SET_VALUE_CONFLICT           (-319) /* Try to set conflicting value 
                                                  in object */
#define SE_ADT_DATATYPE_NOT_SUPPORTED   (-320) /* Abstract Data types not
                                                  supported */ 
#define SE_NO_SPATIAL_INDEX             (-321) /* No spatial index */
#define SE_INVALID_IDENTIFIER           (-322) /* Name not valid for DBMS */
#define SE_REGISTERED_TABLE_ROWID_EXIST (-323) /* ROWID for Oracle Spatial
                                                  table already exists. */
#define SE_SERVER_LIB_LOAD_ERROR        (-324) /* gsrvr dll for direct could
                                                  not be loaded. */
#define SE_REGISTRATION_NOT_ALLOWED     (-325) /* The table can not be
                                                  registered. */
#define SE_UNSUPPORTED_ON_MVTABLE       (-326) /* Operation not supported on
                                                  multiversion table. */
#define SE_NO_ARCSDE_LICENSE            (-327) /* No ArcSDE server license found */
#define SE_UNSUPPORTED_EXPORT_FILE      (-328) /* Exportfile is not supported */
#define SE_TABLE_INUSE                  (-329) /* Specified table is in use  */
#define SE_INVALID_XMLINDEX_OBJECT      (-330) /* SE_XMLINDEXINFO object not 
                                                  initialized */
#define SE_XML_COLUMN_EXISTS            (-331) /* Specified XML column exists */
#define SE_XML_TAG_CONFLICT             (-332) /* Tag's data type or alias 
                                                  doesn't match.*/
#define SE_XML_INDEX_EXISTS             (-333) /* XML index already exists. */
#define SE_XML_INDEX_NOEXIST            (-334) /* Specified XML index 
                                                  does not exist. */
#define SE_INVALID_XML_INDEX_ALTER      (-335) /* Tried to alter non-modifiable
                                                  field. */
#define SE_XML_TEMPLATE_IN_USE          (-336) /* Cannot alter/delete template
                                                  that's referenced by column. */
#define SE_NOT_XML_INDEX_OWNER          (-337) /* Must be owner to del/alter. */
#define SE_INVALID_XMLDOC_OBJECT        (-338) /* SE_XMLDOC object not 
                                                  initialized */
#define SE_XML_TAG_NOEXIST              (-339) /* Named tag not found. */ 
#define SE_XML_PARSE_ERROR              (-340) /* Illegal XML document syntax */
#define SE_ZM_NOEXISTS                  (-341) /* the ZM column does not exists
                                                  in the layers table */
#define SE_INVALID_DATE                 (-342) /* Invalid date value */
#define SE_XML_COLUMN_NOEXIST           (-343) /* Given XML column not found */
#define SE_XML_COLUMN_MISMATCH          (-344) /* Both XML columns must be the 
                                                  same for this operation. */
#define SE_INVALID_XPATH                (-345) /* Incorrect xpath syntax. */
#define SE_XPATH_NOT_SUPPORTED          (-346) /* Input xpath tag not supported 
                                                  in current release. */
#define SE_INVALID_COLUMNINFO_OBJECT    (-347) /* SE_COLUMNINFO object not 
                                                  initialized */
#define SE_INVALID_XMLTAG_OBJECT        (-348) /* SE_XMLTAGINFO object not 
                                                  initialized */
#define SE_INVALID_XMLINDEX_TYPE        (-349) /* Wrong type of XML index */
#define SE_INSTANCEDB_UNSUPPORTED_OPERATION  (-350) /* The requested operation is
                                                    unsupported by instance db.*/
#define SE_XPATH_INVALID_LOCATION_ALIAS  (-351) /* Incorrect xpath location 
                                                   alias syntax. */
#define SE_XPATH_PREDICATE_INVALID_TOKEN (-352) /* Incorrect xpath predicate 
                                                   token.*/
#define SE_XPATH_PREDICATE_INVALID_OPERATOR       (-353) /* Incorrect xpath  
                                                       predicate operator. */
#define SE_XPATH_PREDICATE_INVALID_CONTAIN_SYNTAX (-354) /* Incorrect xpath 
                                           predicate contain function syntax.*/
#define SE_XPATH_EMPTY_ELEMENT  (-355) /* Empty xpath element is not allowed.*/
#define SE_XPATH_INVALID_TOKEN  (-356) /* Incorrect xpath token. */
#define SE_SDETMP_NOT_SET               (-357)  /* Environment var SDETMP not
                                                   set to a value   */
#define SE_INVALID_SERVERINFO_OBJECT    (-358)  /* SERVERINFO object not
                                                   initialized. */
#define SE_USER_GROUP_CONFLICT          (-359)  /* Ambiguity between a user
                                                   name and group name when
                                                   working with permissions */
#define SE_GCDRULE_FILE_EXISTS          (-360)  /* Geocoding rule file already
                                                   exists and force_overwrite
                                                   is not specified */
#define SE_GCDRULE_FILE_NOT_FOUND       (-361)  /* Geocoding rule file
                                                   is not found */
#define SE_GCDRULE_NOT_FOUND            (-362)  /* Geocoding rule is not found
                                                   in geocoding rule table */
#define SE_GCDRULE_EXISTS               (-363)  /* Geocoding rule already
                                                   exist in the geocoding rule
                                                   table and force_overwrite
                                                   is not specified */
#define SE_INVALID_XMLCOLUMN_OBJECT     (-364)  /* SE_XMLCOLUMNINFO object not 
                                                   initialized */
#define SE_INVALID_GROUP                (-365)  /* Invalid system group name */
#define SE_INVALID_XML_COLUMN           (-366)  /* Column contains NOT NULL 
                                                   values during 
                                                   SE_xmlcolumn_create() */
#define SE_INVALID_LOCATOR_PROPERTY     (-367)  /* Locator property is too long
                                                   or invalid */
#define SE_LOCATOR_PROPERTY_MULTIPLE    (-368)  /* Locator property has multiple
                                                   values */
#define SE_DB_SRCH_OUTGEOD_EXTENT       (-369)  /* Search window completely 
						   outside  oracle spatial 
                                                   geodetic extent */
#define SE_XML_COLUMN_NOT_INDEXED       (-370)  /* Cannot use xpath searches on 
                                                   non-indexed columns. */
#define SE_NO_SDE_UUID_COLUMN           (-371)  /* The current table doesn't have
                                                   SDE-maintained UUID column. */
#define SE_INVALID_UUID_COLUMN          (-372)  /* Invalid UUID column. */
#define SE_64BIT_LAYER_NOT_SUPPORTED    (-373)  /* Underlying RDBMS doesn't 
                                                   support 64-bit layer. */
#define SE_INVALID_INDEX_MASK           (-374)  /* Invalid (rebuild) index mask*/
#define SE_INVALID_PRECISION            (-375)  /* Coordref/Layer precision not
                                                   OK for requested operation. */
#define SE_INVALID_TRANSFORMINFO_OBJECT  (-376) /* The SE_TRANSFORMINFO object 
                                                   is not initialized */      
#define SE_INVALID_RASTERBAND_XFORM_LIST (-377) /* Invalid raster band 
                                                   transform list */
#define SE_RASTERBAND_NO_XFORM_LIST      (-378) /* The raster band has no
                                                   transform list */
#define SE_INVALID_QUERYCOLUMN_OBJECT         (-379)  /* SE_QUERYCOLUMN object
                                                         not initialized */
#define SE_MULTIPLE_SHAPESOURCE_SHAPES        (-380)  /* Multiple shapes set to
                                                         SE_SHAPESOURCE shape */
#define SE_INVALID_QUERYSELECT_OBJECT         (-381)  /* SE_QUERYSELECT object
                                                         not initialized */
#define SE_INVALID_SHAPESOURCE_OBJECT         (-382)  /* SE_SHAPESOURCE object
                                                         not initialized */
#define SE_INVALID_SPATIALCONSTRAINT_OBJECT   (-383)  /* SE_SPATIALCONSTRAINT
                                                         object not init'ized */
#define SE_MISSING_JOIN_CONSTRAINT            (-384)  /* QUERYFROM join
                                                         constraint missing */
#define SE_ANSI_JOIN_CONFLICT                 (-385)  /* QUERYFROM join
                                                         conflict */
#define SE_MISSING_JOIN_TABLE                 (-386)  /* QUERYFROM join table
                                                         missing */
#define SE_INVALID_QUERYTABLE_OBJECT          (-387)  /* SE_QUERYTABLE object
                                                         not initialized */
#define SE_INVALID_QUERYFROM_OBJECT           (-388)  /* SE_QUERYFROM object not
                                                         initialized */
#define SE_INVALID_XMLCONSTRAINT_OBJECT       (-389)  /* SE_XMLCONSTRAINT object
                                                         not initialized */
#define SE_INVALID_ATTRIBUTECONSTRAINT_OBJECT (-390)  /* SE_ATTRIBUTECONSTRAINT
                                                         object not init'ized */
#define SE_INVALID_QUERYWHERE_OBJECT          (-391)  /* SE_QUERYWHERE object
                                                         not initialized */
#define SE_CPG_OPEN_ERROR               (-392)  /* Error opening codepage
                                                   converter */
#define SE_CPG_CONVERSION_OVERFLOW      (-393)  /* The destination string buffer
                                                   is too small */
#define SE_CPG_CONVERSION_ERROR         (-394)  /* Codepage conversion error */
#define SE_STATE_CLOSED                 (-395)  /* Operation invalid on a closed
                                                   state. */
#define SE_INVALID_ON_BASE_STATE        (-396)  /* The requested operation is
                                                   invalid on the base state. */
#define SE_DC_LICENSE_SERVER_NOT_REGISTERED    (-397) /* The direct connect is
                                                         not registered with an
                                                         ArcSde server for
                                                         license. */
#define SE_INVALID_ID_RANGE             (-398)  /* The given range of ids is
                                                   invalid */
#define SE_STATEOBJECT_HAS_NO_LINEAGE   (-399)  /* This state object doesn't
                                                   contain lineage info. */
#define SE_OGCWKB_UNSUPPORTED_EYTPE     (-400)  /* OGCWKB type does not support
                                                   ANNO, CAD, 3D, Measures or
                                                   Curves. */
#define SE_SET_ORIGIN_NOT_ALLOWED       (-401)  /* Not allowed to set image
                                                   origin. */
#define SE_INVALID_IMAGE_ORIGIN         (-402)  /* Not a valid image origin. */
#define SE_RASTERBAND_NO_GDB_METADATA      (-403) /* The raster band has no 
                                                     GDB metadata. */
#define SE_INVALID_RASTERBAND_GDB_METADATA (-404) /* Invalid raster band GDB 
                                                     metadata. */
#define SE_COMPLEX_COL_INDX_NOT_ALLOWED (-405)  /* Not allowed to create index
                                                   on complex column. */
#define SE_COMPRESS_ALREADY_RUNNING     (-406)  /* Can't start compress if
                                                   compress is already running */
#define SE_SCHEMA_OUT_OF_DATE           (-407)  /* Schema is out of date. */ 
#define SE_MVTABLE_HAS_DELTA_ROWS       (-408)  /* Has rows in delta tables. */
#define SE_LOST_DBMS_CONNECTION         (-409)  /* Lost connection to underlying
                                                   DBMS. */
#define SE_INVALID_XMLCOLUMN_ALTER      (-410)  /* XMLCOLUMN alter tried to modify
                                                   a column property that cannot change */ 

/******************************************************************************
****    NON-FATAL SDE WARNINGS
******************************************************************************/

#define SE_SUCCESS               0
#define SE_SDE_WARNING           (-1000)  /* BASE NUMBER FOR WARNING CODES */
#define SE_ETYPE_CHANGED         (-1001)  /* FUNCTION CHANGED ENTITY TYPE OF 
                                             FEAT */
#define SE_NO_ROWS_DELETED       (-1002)  /* No rows were deleted. */
#define SE_TOO_MANY_DISTINCTS    (-1003)  /* Too many distinct values 
                                             in stats */
#define SE_NULL_VALUE            (-1004)  /* Request column value is NULL */
#define SE_NO_ROWS_UPDATED       (-1005)  /* No rows were updated */
#define SE_NO_CPGCVT             (-1006)  /* No codepage conversion  */
#define SE_NO_CPGHOME            (-1007)  /* Cannot find codepage directory */
#define SE_DBMS_DOES_NOT_SUPPORT (-1008)  /* DBMS does NOT support 
                                             this function */
#define SE_INVALID_FUNCTION_ID   (-1009)  /* Invalid DBMS function id */
#define SE_LAYERS_UPDATE_FAILED  (-1010)  /* Update layer extent failed */
#define SE_NO_LOCALIZED_MESSAGE  (-1011)  /* No localized error messages */
#define SE_SPATIAL_INDEX_NOT_CREATED (-1012) /* Spatial index not created,
                                              server inability to support
                                              SPIDX_PARAM specified */
#define SE_FUNC_UNSUPPORTED_ON_DBMS (-1013) /* SDE does NOT support this function                                                                           on this DBMS */
#define SE_SQL_NOT_CACHED        (-1014)  /* SQL statement that is being re-executed
                                             was not found in the cache */


/******************************************************************************
****    SDE Exit Codes
****
****      These are the status codes found in giomgr.log when a connection's
****    gsrvr exits (as opposed to going down on a signal or with an exception
****    code -- those are documented in the operating system's documentation).
******************************************************************************/

#define SE_EXIT_SUCCESS                 0
#define SE_EXIT_INVALID_COMMAND_LINE    1
#define SE_EXIT_IOMGR_IO_ERROR          2
#define SE_EXIT_DBMS_CONNECT_REJECTED   3
#define SE_EXIT_SHARED_MEMORY_ERROR     4
#define SE_EXIT_MALLOC_ERROR            5
#define SE_EXIT_CLIENT_IO_ERROR         6
#define SE_EXIT_LOGFILE_INIT_FAILED     7
#define SE_EXIT_LOST_CLIENT             8
#define SE_EXIT_BAD_COMMAND_CODE        9
#define SE_EXIT_REGISTRY_INIT_FAILED   10
#define SE_EXIT_LAYERS_INIT_FAILED     11
#define SE_EXIT_METADATA_INIT_FAILED   12
#define SE_EXIT_RASTER_INIT_FAILED     13
#define SE_EXIT_VERSION_INIT_FAILED    14
#define SE_EXIT_LOCATOR_INIT_FAILED    15
#define SE_EXIT_NO_LOCALIZED_MESSAGE   16
#define SE_EXIT_MUTEX_ERROR            17

#endif /* SDE_ERRNO */
