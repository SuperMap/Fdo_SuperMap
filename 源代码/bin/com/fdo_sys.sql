/*----------------------------------------------------------------------*/
/* Name                                                                 */
/*  g_sys.sql - create standard system tables schema                    */
/*                                                                      */
/* Description                                                          */
/*      Command file to create standard schema and system tables for    */
/*      a newly granted database.                                       */
/*                                                                      */
/* Remarks                                                              */
/*      This file is executed by a call to adb_exec_file().  Portions   */
/*      of this script are enabled or disabled via #ifdef variables.    */
/*      In particular defining VISION_noschema disables the creation of */
/*      the so called schema tables.                                    */
/*                                                                      */
/*----------------------------------------------------------------------*/


#ifndef VISION_noschema

/* Create tables                                                 */
/* IMPORTANT WARNING: if adding or removing system tables update src/adb/is_sys/tbl.c */

create table /* system */  f_schemainfo(
#ifdef Oracle
    schemaname          varchar(255) not null,
    description         varchar(255) null,
    owner               varchar(255) not null,
    creationdate        date null,
    schemaversionid     number not null,
    tableowner          varchar(30) null,
#else
    schemaname          varchar(200) not null,
    description         varchar(255) null,
    owner               varchar(200) not null,
    creationdate        datetime null,
    schemaversionid     decimal(5,3) not null,
#ifdef MySQL
    tableowner	   varchar(64) null,
#else
    tableowner          varchar(128) null,
#endif
#endif
    tablelinkname       varchar(128) null,
    tablemapping        varchar(30) null
    )
#ifdef MySQL
    engine=InnoDb
#else
#ifdef Oracle
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5)
#endif
#endif
    ;
      
/* SchemaType is set initially to NON_FDO type. It will be updated after the schema is created. */
#ifdef Oracle
insert into f_schemainfo (schemaname, description, creationdate, owner, schemaversionid )
values (sys_context('userenv', 'current_schema'), 'System Metaschema', SYSDATE, user, 3.000);
/* F_MetaClass is a special schema with a class for each FDO Feature schema class type */
insert into f_schemainfo  (schemaname, description, creationdate, owner, schemaversionid )
values ('F_MetaClass', 'Special classes for FDO Feature metaclasses', SYSDATE, user, 2.000);
#else
#ifdef SQLServer
insert into f_schemainfo (schemaname, description, creationdate, owner, schemaversionid )
values (DB_NAME(), 'System Metaschema', GETDATE(), SYSTEM_USER, 3.000);
/* F_MetaClass is a special schema with a class for each FDO Feature schema class type */
insert into f_schemainfo  (schemaname, description, creationdate, owner, schemaversionid )
values ('F_MetaClass', 'Special classes for FDO Feature metaclasses', GETDATE(), SYSTEM_USER, 2.000);
#else
insert into f_schemainfo (schemaname, description, creationdate, owner, schemaversionid )
values (database(), 'System Metaschema', current_date(), substring_index(current_user(), _utf8'@', 1), 3.000);
/* F_MetaClass is a special schema with a class for each FDO Feature schema class type */
insert into f_schemainfo  (schemaname, description, creationdate, owner, schemaversionid )
values ('F_MetaClass', 'Special classes for FDO Feature metaclasses', current_date(), substring_index(current_user(), _utf8'@', 1), 3.000);
#endif
#endif



/* Place to store different options used by the datastore like versioning method. */
create table f_options (
      name 	varchar(100) null,
      value             varchar(100) null
)
#ifdef MySQL
    engine=InnoDb
#else
#ifdef Oracle
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5)
#endif
#endif
;

/* Set versioning Oracle Workspace Manager versioning method */
#ifdef Oracle
insert into f_options values ('LT_MODE', '0');
insert into f_options values ('LOCKING_MODE', '0');
#else
insert into f_options values ('LT_MODE', '1');
insert into f_options values ('LOCKING_MODE', '1');
#endif

/*  Create the F_SCHEMAOPTIONS (Schema Options) table; it is based on the F_SAD table design           */

create table f_schemaoptions(
#ifdef Oracle
    ownername    varchar(512) not null,
    elementname  varchar(255) not null,
    elementtype  varchar(30) not null,
    name         varchar(255) not null,
    value        varchar(4000) null)
 pctfree 5 pctused 90
    storage (initial     4K
             next        20K
             minextents  1
             maxextents  9999
             pctincrease 50)
#else
    ownername    varchar(400) not null,
    elementname  varchar(200) not null,
    elementtype  varchar(30) not null,
    name         varchar(200) not null,
    value        varchar(4000) null)
#ifdef MySQL
    engine=InnoDb
#endif
#endif
;



/*  Create the F_SAD (Schema Attribute Dictionary) table.                                        */

create table f_sad (
#ifdef Oracle
    ownername    varchar(512) not null,
    elementname  varchar(255) not null,
    elementtype  varchar(30) not null,
    name         varchar(255) not null,
    value        varchar(4000) null)
 pctfree 5 pctused 90
    storage (initial     4K
             next        20K
             minextents  1
             maxextents  9999
             pctincrease 50)
#else
    ownername    varchar(401) not null,
    elementname  varchar(200) not null,
    elementtype  varchar(30) not null,
    name         varchar(200) not null,
    value        varchar(4000) null)
#ifdef MySQL
    engine=InnoDb
#endif
#endif
;

create table f_dbopen (
#ifdef Oracle
    usernum             number not null,
    dbuser              varchar(30) not null,
    accessmode          varchar(1),
    activescid          number(20),
    opendate            date,
    sessionid           number,
    process             varchar(12)
    )
pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);
#else
    usernum 	  int not null,
#ifdef MySQL
    dbuser              varchar(16) not null,
#else
    dbuser              varchar(128) not null,
#endif
    accessmode          varchar(1) null,
    activescid	  bigint null,
    opendate	  datetime null,
    sessionid            smallint null,
    process             varchar(128) null
    )
#ifdef MySQL
    engine=InnoDb
#endif
;
#endif


#ifdef    FDO_FEATURE
create table f_feature(
    featid          number(20) not null,
    classid         number(20)
#ifdef   FDO_VERSIONS
    ,ltid            number(20),
    nextltid        number(20),
    ltgeneration    number(20)
#endif
#ifdef    FDO_LOCKS
    ,rowlockid       number(20),
    rowlocktype     varchar(1)
#endif
    )
      
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);
#ifndef FDO_VERSIONS 
#ifndef FDO_LOCKS
alter table F_FEATURE add ( constraint f_feature_pk primary key (FEATID));

#endif
#endif
#endif

#ifdef Oracle
/* create sequences */
create sequence F_FeatureSeq start with 2;
create sequence F_LockSeq start with 2;
create sequence F_PlanSeq start with 1;
#ifdef FDO_VERSIONS 
create sequence F_VersionSeq start with 1;
create sequence F_GenerationSeq start with 1;
#endif
create sequence F_ClassSeq start with 1;
create sequence F_PlangroupSeq start with 1;
create sequence F_UserSeq start with 1;
#endif

create table f_classdefinition (
#ifdef Oracle
    classid         number(20)  not null,
    classname       varchar(255) not null,
    schemaname      varchar(255) null,
    tablename       varchar(30) not null,
    roottablename   varchar(30),
    tableowner      varchar(30),
    tablelinkname   varchar(128),
    tablemapping    varchar(30),
    classtype       number(10)  not null,
    description     varchar(255),
    isabstract      number(1)   not null,
    parentclassname varchar(512),
    isfixedtable    number(1),
    istablecreator  number(1),
    hasversion      number(1) ,
    haslock         number(1),
    geometryproperty    varchar(4000)
    )     
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5)
#else
#ifdef MySQL
    classid         bigint not null AUTO_INCREMENT, /* starts 1, increment 1 */
#else
    classid         bigint not null IDENTITY(1,1),
#endif
    classname       varchar(200) not null,
    schemaname      varchar(200) null,
#ifdef MySQL
    tablename       varchar(64) null,
    roottablename   varchar(64),
    tableowner      varchar(64),
    tablelinkname   varchar(128),
    tablemapping    varchar(64),
#else
    tablename       varchar(128) null,
    roottablename   varchar(128) null,
    tableowner      varchar(128) null,
    tablelinkname   varchar(128) null,
    tablemapping    varchar(128) null,
#endif
    classtype       smallint  not null,
    description     varchar(255) null,
    isabstract      tinyint   not null,
    parentclassname varchar(512) null,
    isfixedtable    tinyint null,
    istablecreator  tinyint null,
    hasversion      tinyint null,
    haslock         tinyint null,
    geometryproperty    varchar(4000) null
#ifdef MySQL
    , PRIMARY KEY (classid)
#endif
    )
#ifdef MySQL
    engine=InnoDb 
#endif
#endif
;

create table f_attributedefinition  (
#ifdef Oracle
    tablename       varchar(30) not null,
    classid         number(20)  not null,
    columnname      varchar(255) not null,
    attributename   varchar(4000)not null,
    idposition      number(5),
    columntype      varchar(30) not null,
    columnsize      number      not null,
    columnscale     number,
    attributetype   varchar(512) not null,
    geometrytype    varchar(64) null,
    isnullable      number(1)   not null,
    isfeatid        number(1)   not null,
    issystem        number(1)   not null,
    isreadonly      number(1)   not null,
    isautogenerated number(1) ,
    isrevisionnumber number(1) ,
    sequencename    varchar(30),
    owner           varchar(255),
    description     varchar(255),
    rootobjectname   varchar(30),
    isfixedcolumn   number(1),
    iscolumncreator  number(1),
    haselevation    number(1),
    hasmeasure      number(1)
    )
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);
#else
#ifdef MySQL
    tablename       varchar(64) not null,
#else
    tablename	varchar(128) not null,
#endif
    classid         bigint  not null,
    columnname      varchar(255) not null,
    attributename   varchar(4000) not null,
    idposition         smallint null,
    columntype      varchar(30) not null,
    columnsize       bigint      not null,
    columnscale     smallint null,
    attributetype   varchar(512) not null,
    geometrytype   varchar(64) null,
    isnullable         tinyint   not null,
    isfeatid           tinyint   not null,
    issystem         tinyint   not null,
    isreadonly       tinyint   not null,
    isautogenerated tinyint null ,
    isrevisionnumber tinyint null ,
    sequencename    varchar(30) null,
    owner           varchar(200) null,
    description     varchar(255) null,
#ifdef MySQL
	rootobjectname   varchar(64) null,
#else
	rootobjectname   varchar(128) null,
#endif
    isfixedcolumn   tinyint null,
    iscolumncreator  tinyint null,
    haselevation    tinyint null,
    hasmeasure     tinyint null
    )   
#ifdef MySQL
    engine=InnoDb
#endif
;
#endif

/* Add new meta-classes here and insert base properties */
/* Use F_ClassSeq.nextval for the classid inserting into the F_ClassDefinition table and F_ClassSeq.Currval for inserting */
/* properties into the F_AttributeDefinition table */

#ifdef SQLServer 
#ifdef FdoLt
insert into f_attributedefinition
(tablename, classid, columnname, attributename, columntype, columnsize, columnscale, attributetype, isnullable, 
isfeatid, issystem, isreadonly, isautogenerated, isrevisionnumber, owner, description, iscolumncreator, isfixedcolumn) values
('f_object', IDENT_CURRENT('f_classdefinition'), 'ltid', 'LtId', 'bigint', 0, 0, 'int64', 0, 0, 1, 1, 0, 0,
SYSTEM_USER,  'FDO base property: long transaction id', 0, 1);

insert into f_attributedefinition
(tablename, classid, columnname, attributename, columntype, columnsize, columnscale, attributetype, isnullable, 
isfeatid, issystem, isreadonly, isautogenerated, isrevisionnumber, owner, description, iscolumncreator, isfixedcolumn) values
('f_object', IDENT_CURRENT('f_classdefinition'), 'nextltid', 'NextLtId', 'varchar', 200, 0, 'string', 1, 0, 1, 1, 0, 0,
SYSTEM_USER,  'FDO base property: next long transaction id list', 0, 1);
#endif

#ifdef FdoLock
insert into f_attributedefinition
(tablename, classid, columnname, attributename, columntype, columnsize, columnscale, attributetype, isnullable, 
isfeatid, issystem, isreadonly, isautogenerated, isrevisionnumber, owner, description, iscolumncreator, isfixedcolumn) values
('f_object', IDENT_CURRENT('f_classdefinition'), 'lockid', 'LockId', 'bigint', 0, 0, 'int64', 1, 0, 1, 1, 0, 0,
SYSTEM_USER,  'FDO base property: persistent lock id', 0, 1);

insert into f_attributedefinition
(tablename, classid, columnname, attributename, columntype, columnsize, columnscale, attributetype, isnullable, 
isfeatid, issystem, isreadonly, isautogenerated, isrevisionnumber, owner, description, iscolumncreator, isfixedcolumn) values
('f_object', IDENT_CURRENT('f_classdefinition'), 'locktype', 'LockType', 'char', 1, 0, 'string', 1, 0, 1, 1, 0, 0,
SYSTEM_USER,  'FDO base property: persistent lock type', 0, 1);
#endif

#endif


create table f_spatialcontextgroup (
#ifdef Oracle
    scgid           number(20) not null,
#else
#ifdef MySQL
    scgid	        bigint not null AUTO_INCREMENT,
#else
	scgid	        bigint not null IDENTITY(0,1),
#endif
#endif
    crsname         varchar(255) null,			/* 68 in MDSYS.CS_SRS */
    crswkt			varchar(2048) null,
#ifdef Oracle
    srid			number(38),				/* same as in MDSYS.CS_SRS */
#else
    srid	          bigint null,
#endif
    areaunit        varchar(30) null,
    lengthunit      varchar(30) null,
    positionxyunit  varchar(30) null, 
    positionzunit   varchar(30) null,
    volumeunit      varchar(30) null,
    measureunit     varchar(30) null,
#ifdef Oracle
    xtolerance      number not null,
    ztolerance      number,
    xmin            number not null,
    ymin            number not null,
    zmin            number,
    xmax            number not null,
    ymax            number not null,
    zmax            number,
#else
    xtolerance      double precision not null,
    ztolerance      double precision null,
    xmin            double precision not null,
    ymin            double precision not null,
    zmin            double precision null,
    xmax            double precision not null,
    ymax            double precision not null,
    zmax            double precision null,
#endif
    extenttype		varchar(1) not null
#ifdef MySQL
    , PRIMARY KEY (scgid)
#endif
    )
#ifdef MySQL
    engine=InnoDb
#else
#ifdef Oracle
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5)
#endif
#endif
;

 create table f_spatialcontextgeom (
#ifdef Oracle
    scid           		number(20) not null,
    geomtablename   	varchar(30) not null,
    geomcolumnname   	varchar(30) not null,	
    dimensionality		number  not null              
    )
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);   
#else
	scid           		bigint not null,
#ifdef MySQL
    geomtablename   	varchar(64) not null,
    geomcolumnname   	varchar(64) not null,
#else	
    geomtablename   	varchar(128) not null,
    geomcolumnname   	varchar(128) not null,
#endif	
    dimensionality		smallint  not null              
    )
#ifdef MySQL
    engine=InnoDb
#endif
;
#endif

#ifndef SQLServer
	insert into f_spatialcontextgroup (scgid, crsname, xtolerance, ztolerance, xmin, ymin, xmax, ymax, extenttype) values (0, '', 0.001, 0.001, -2000000, -2000000, 2000000, 2000000, 'S');
#else
	insert into f_spatialcontextgroup (crsname, xtolerance, ztolerance, xmin, ymin, xmax, ymax, extenttype) values ('', 0.001, 0.001, -2000000, -2000000, 2000000, 2000000, 'S');
#endif


create table f_attributedependencies    (
#ifdef Oracle
    pktablename     varchar(30) not null,
    pkcolumnnames   varchar(1000),
    fktablename     varchar(30) not null,
    fkcolumnnames   varchar(1000),
    fkcardinality   number(10) not null,
    identitycolumn   varchar(30),
    ordertype       char(1)
    )
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);
#else
#ifdef MySQL
    pktablename     varchar(64) not null,
    pkcolumnnames   varchar(1056),
    fktablename     varchar(64) not null,
    fkcolumnnames   varchar(1056),
    fkcardinality   int not null,
    identitycolumn   varchar(64),
#else
    pktablename     varchar(128) not null,
    pkcolumnnames   varchar(2080) null,
    fktablename     varchar(128) not null,
    fkcolumnnames   varchar(2080) null,
    fkcardinality        int not null,
    identitycolumn   varchar(128) null,
#endif
    ordertype       char(1)
    )
#ifdef MySQL
    engine=InnoDb
#endif
;
#endif

#ifdef FDO_FEATURE
/* Add dependency for navigating from a feature to its class and schema name */
insert into f_attributedependencies ( pktablename, pkcolumnnames, fktablename, fkcolumnnames, fkcardinality )
values ( 'F_FEATURE', 'CLASSID', 'F_CLASSDEFINITION', 'CLASSID', 1 );
#endif

create table f_associationdefinition    (
#ifdef Oracle
     pseudocolname          varchar(30) not null, /* used to uniquely identify an association definition */
     pktablename            varchar(30) not null,
     pkcolumnnames          varchar(1000),
     fktablename            varchar(30) not null,
     fkcolumnnames          varchar(1000),
     multiplicity           varchar(5),
     reversemultiplicity    varchar(5),
     cascadelock            char(1),
     deleterule             number(5),
     reversename            varchar(4000)
   )
    pctfree 5 pctused 90
    storage (initial     4K
              next        4K
              minextents  1
              maxextents  9999
	 pctincrease 5);
#else
#ifdef MySQL
     pseudocolname          varchar(64) not null, /* used to uniquely identify an association definition */
     pktablename            varchar(64) not null,
     pkcolumnnames          varchar(1056),
     fktablename            varchar(64) not null,
     fkcolumnnames          varchar(1056),
#else
     pseudocolname          varchar(128) not null, /* used to uniquely identify an association definition */
     pktablename            varchar(128) not null,
     pkcolumnnames          varchar(2080) null,
     fktablename            varchar(128) not null,
     fkcolumnnames          varchar(2080) null,
#endif
     multiplicity           varchar(5) null,
     reversemultiplicity    varchar(5) null,
     cascadelock            char(1) null,
     deleterule                int null,
     reversename            varchar(200) null
   )
#ifdef MySQL
    engine=InnoDb
#endif
;
#endif

create table f_spatialcontext   (
#ifdef Oracle
    scid            number(20) not null,
    scname          varchar(255) not null,
    description     varchar(255),
    scgid           number(20)
#ifdef FDO_LOCKS
    ,rowlockid       number(10),
    rowlocktype     varchar(1)
#endif
    )  
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);
#else
#ifdef MySQL
    scid	        bigint not null AUTO_INCREMENT,
#else
	scid	        bigint not null IDENTITY(0,1),
#endif
    scname          varchar(255) not null,
    description     varchar(255) null,
    scgid          bigint null
#ifdef FDO_LOCKS
    ,rowlockid       bigint null,
    rowlocktype     varchar(1) null
#endif
#ifdef MySQL
    , PRIMARY KEY (scid)
#endif
    )
#ifdef MySQL
    engine=InnoDb
#endif
;
#endif

#ifdef MySQL
	insert into f_spatialcontext (scname, description, scgid) 
		values ('Default', 'Default Database Spatial Context', 1);
#else
#ifndef SQLServer         
	insert into f_spatialcontext (scid, scname, description, scgid) 
		values (0, 'Default', 'Default Database Spatial Context', 0);
#else
	insert into f_spatialcontext (scname, description, scgid) 
		values ('Default', 'Default Database Spatial Context', 0);
#endif
#endif

create table f_classtype (
#ifdef Oracle
    classtype       number(10)  not null,
    classtypename   varchar(255) not null
    )
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);
#else
    classtype          int  not null,
    classtypename   varchar(255) not null
    )
#endif
#ifdef MySQL
    engine=InnoDb
#endif
;


/* Lookups for class type enums-string pairs */
insert into f_classtype (classtype, classtypename) values (1, 'Class');
insert into f_classtype (classtype, classtypename) values (2, 'Feature');

#ifdef Oracle
/* New Lock Table. */
create table f_lockname (
        lockid      number(20,0)  not null,
        name        varchar(30)   not null,
        description varchar(255),
        createdate  date,
        owner       varchar(30)   not null)
      
    pctfree 5 pctused 90
    storage (initial     4K
             next        20K
             minextents  1
             maxextents  9999
             pctincrease 50);

/* new sequence table */
create table f_sequence(
    seqid           varchar(30) not null,
    startnum      number  
    )
    pctfree 5 pctused 90
    storage (initial     4K
             next        4K
             minextents  1
             maxextents  9999
             pctincrease 5);

insert into f_sequence select sequence_name, min_value from all_sequences where sequence_owner=sys_context('userenv', 'current_schema');

/* insert 12 "dummy" rows to have 20 rows in the F_Sequence table. */

insert into f_sequence values( 'F_Seq_1',1);
insert into f_sequence values( 'F_Seq_2',1);
insert into f_sequence values( 'F_Seq_3',1);
insert into f_sequence values( 'F_Seq_4',1);
insert into f_sequence values( 'F_Seq_5',1);
insert into f_sequence values( 'F_Seq_6',1);
insert into f_sequence values( 'F_Seq_7',1);
insert into f_sequence values( 'F_Seq_8',1);
insert into f_sequence values( 'F_Seq_9',1);
insert into f_sequence values( 'F_Seq_10',1);
insert into f_sequence values( 'F_Seq_11',1);
insert into f_sequence values( 'F_Seq_12',1);
#ifndef FDO_VERSIONS
insert into f_sequence values( 'F_Seq_13',1);
insert into f_sequence values( 'F_Seq_14',1);
#endif
#endif
#endif  VISION_noschema

#ifdef Oracle
/*********************************************************/
/*                     STORED PROCEDURES				 */
/* For debugging use:									 */
/* 
set arraysize 1		
set serveroutput on size 100000
dbms_output.put_line('var=' || var);
*/
/*********************************************************/
create or replace procedure f_update_spatial_metadata
  (owner        varchar2,
   table_name   varchar2,
   column_name  VARCHAR2,
   diminfo      mdsys.sdo_dim_array,
   srid         number) authid definer as
   PRAGMA AUTONOMOUS_TRANSACTION;
   sql_stmt varchar2(250);
   sq VARCHAR2(1) := CHR(39);
begin
  sql_stmt := 'delete from  mdsys.sdo_geom_metadata_table where SDO_OWNER=UPPER('||sq||owner||sq||')'||' and SDO_TABLE_NAME=UPPER('||sq||table_name||sq||')'||' and SDO_COLUMN_NAME=UPPER('||sq||column_name||sq||')';
  execute immediate sql_stmt;

  if srid <> 0 THEN
  	MDSYS.SDO_META.CHANGE_ALL_SDO_GEOM_METADATA(owner,
                                             	table_name,
                                              	column_name,
                                              	diminfo, 
                                              	srid);
  ELSE
  	MDSYS.SDO_META.CHANGE_ALL_SDO_GEOM_METADATA(owner,
                                              	table_name,
                                              	column_name,
                                              	diminfo, 
                                              	NULL);
  END IF;
  commit;
end f_update_spatial_metadata;


create or replace procedure f_create_spatial_index_rtree
  (table_name   varchar2,
   column_name  varchar2,
   index_name	varchar2,
   num_dims	NUMBER,
   space_def varchar2) authid definer as
   PRAGMA AUTONOMOUS_TRANSACTION;
   sql_stmt varchar2(2000);
 begin
  sql_stmt := 'create index '||index_name||' on '||table_name||'('||column_name||') indextype is mdsys.spatial_index'||
             ' parameters (''sdo_indx_dims='|| num_dims || ' '|| space_def ||''')';

  execute immediate sql_stmt;
  commit;
end f_create_spatial_index_rtree;

create or replace procedure f_create_spatial_index_qtree
  (table_name   	varchar2,
   column_name  	varchar2,
   index_name	varchar2,
   space_def 	varchar2) authid definer as
   PRAGMA AUTONOMOUS_TRANSACTION;
   sql_stmt varchar2(2000);
begin
  sql_stmt := 'create index '||index_name||' on '||table_name||'('||column_name||') indextype is mdsys.spatial_index'||
              ' parameters (''sdo_level=1 ' || space_def ||''')';

  execute immediate sql_stmt;
  commit;
end f_create_spatial_index_qtree;


#endif

/* End */
