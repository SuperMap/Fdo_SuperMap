//
//Copyright (C) 2004-2006  Autodesk, Inc.
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of version 2.1 of the GNU Lesser
//General Public License as published by the Free Software Foundation.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
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
// MessageId: FDO_1_INDEXOUTOFBOUNDS
//
// MessageText:
//
//  Item index out of bounds.
//
#define FDO_1_INDEXOUTOFBOUNDS           0x00000001L

//
// MessageId: FDO_1_BADPARAMETER
//
// MessageText:
//
//  Bad Parameter.
//
#define FDO_1_BADPARAMETER               0x00000002L

//
// MessageId: FDO_1_UNKNOWN_GEOMETRY_TYPE
//
// MessageText:
//
//  '%1$ls': Unknown geometry type '%2$d' discovered.
//
#define FDO_1_UNKNOWN_GEOMETRY_TYPE      0x00000003L

//
// MessageId: FDO_1_INVALID_NUM_OF_COORDINATE_POSITIONS
//
// MessageText:
//
//  '%1$ls': Invalid number of coordinate positions.
//
#define FDO_1_INVALID_NUM_OF_COORDINATE_POSITIONS 0x00000004L

//
// MessageId: FDO_1_UNKNOWN_GEOMETRY_COMPONENT_TYPE
//
// MessageText:
//
//  '%1$ls': Unknown geometry component type '%2$d' discovered.
//
#define FDO_1_UNKNOWN_GEOMETRY_COMPONENT_TYPE 0x00000005L

//
// MessageId: FDO_1_OPEN_RING
//
// MessageText:
//
//  '%1$ls': Identified an open ring when expecting a closed one.
//
#define FDO_1_OPEN_RING                  0x00000006L

//
// MessageId: FDO_1_RESOLUTION_TOO_FINE_FOR_EXTENT
//
// MessageText:
//
//  '%1$ls': The resolution is too fine for the extents.
//
#define FDO_1_RESOLUTION_TOO_FINE_FOR_EXTENT 0x00000007L

//
// MessageId: FDO_1_RESOLUTION_TOO_LARGE_FOR_EXTENT
//
// MessageText:
//
//  '%1$ls': The resolution is too large (> 0.1) for the extents.
//
#define FDO_1_RESOLUTION_TOO_LARGE_FOR_EXTENT 0x00000008L

//
// MessageId: FDO_1_COLLINEAR_POINTS
//
// MessageText:
//
//  '%1$ls': The points are collinear.
//
#define FDO_1_COLLINEAR_POINTS           0x00000009L

//
// MessageId: FDO_1_MEMORY_DEALLOCATION_ERROR
//
// MessageText:
//
//  '%1$ls': Failed to free memory for object '%2$ls'.
//
#define FDO_1_MEMORY_DEALLOCATION_ERROR  0x0000000AL

//
// MessageId: FDO_1_INVALID_INPUT_ON_CLASS_CREATION
//
// MessageText:
//
//  Cannot create instance of class '%1$ls' due to invalid value for the input parameter(s) '%2$ls'.
//
#define FDO_1_INVALID_INPUT_ON_CLASS_CREATION 0x0000000BL

//
// MessageId: FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION
//
// MessageText:
//
//  '%1$ls': Cannot execute function due to invalid value for the input parameter(s) '%2$ls'.
//
#define FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION 0x0000000CL

//
// MessageId: SCHEMA_1_BADATTRIBUTENAME
//
// MessageText:
//
//  Bad schema attribute name.
//
#define SCHEMA_1_BADATTRIBUTENAME        0x000003E9L

//
// MessageId: SCHEMA_2_BASEPROPERTIESALREADYSET
//
// MessageText:
//
//  Base properties already set.
//
#define SCHEMA_2_BASEPROPERTIESALREADYSET 0x000003EAL

//
// MessageId: SCHEMA_3_CLASSNOTADDED
//
// MessageText:
//
//  Class has not already been added to the FeatureSchema.
//
#define SCHEMA_3_CLASSNOTADDED           0x000003EBL

//
// MessageId: SCHEMA_4_IDENTITYPROPERTYNOTPROPERTY
//
// MessageText:
//
//  Identity Property must be member of Property collection.
//
#define SCHEMA_4_IDENTITYPROPERTYNOTPROPERTY 0x000003ECL

//
// MessageId: SCHEMA_5_INVALIDELEMENTNAME
//
// MessageText:
//
//  Invalid element name.
//
#define SCHEMA_5_INVALIDELEMENTNAME      0x000003EDL

//
// MessageId: SCHEMA_6_NAMENOTINATTRIBUTEDICTIONARY
//
// MessageText:
//
//  Name not in schema attribute dictionary.
//
#define SCHEMA_6_NAMENOTINATTRIBUTEDICTIONARY 0x000003EEL

//
// MessageId: SCHEMA_7_RELATIONENDNOTADDED
//
// MessageText:
//
//  RelationEnd has not been added to a FeatureSchema.
//
#define SCHEMA_7_RELATIONENDNOTADDED     0x000003EFL

//
// MessageId: SCHEMA_8_ATTRIBUTEALREADYINDICTIONARY
//
// MessageText:
//
//  Schema attribute already in dictionary.
//
#define SCHEMA_8_ATTRIBUTEALREADYINDICTIONARY 0x000003F0L

//
// MessageId: SCHEMA_9_ATTRIBUTENOTFOUND
//
// MessageText:
//
//  Schema attribute not found.
//
#define SCHEMA_9_ATTRIBUTENOTFOUND       0x000003F1L

//
// MessageId: SCHEMA_10_OBJECTHASPARENT
//
// MessageText:
//
//  Object already has parent.
//
#define SCHEMA_10_OBJECTHASPARENT        0x000003F2L

//
// MessageId: SCHEMA_11_OWNPARENT
//
// MessageText:
//
//  Element cannot be its own parent/grandparent.
//
#define SCHEMA_11_OWNPARENT              0x000003F3L

//
// MessageId: SCHEMA_12_OWNBASECLASS
//
// MessageText:
//
//  ClassDefinition cannot be its own base class.
//
#define SCHEMA_12_OWNBASECLASS           0x000003F4L

//
// MessageId: SCHEMA_13_IDENTITYPROPERTYONSUBCLASS
//
// MessageText:
//
//  A Class with a Base Class cannot have an Identity Property.
//
#define SCHEMA_13_IDENTITYPROPERTYONSUBCLASS 0x000003F5L

//
// MessageId: SCHEMA_14_SUBCLASSWITHIDENTITYPROPERTIES
//
// MessageText:
//
//  A Class with Identity Properties cannot have a Base Class.
//
#define SCHEMA_14_SUBCLASSWITHIDENTITYPROPERTIES 0x000003F6L

//
// MessageId: SCHEMA_15_NEGATIVELENGTHNOTALLOWED
//
// MessageText:
//
//  A Data Property cannot have a negative length.
//
#define SCHEMA_15_NEGATIVELENGTHNOTALLOWED 0x000003F7L

//
// MessageId: SCHEMA_16_NEGATIVEPRECISIONNOTALLOWED
//
// MessageText:
//
//  A Data Property cannot have a negative precision.
//
#define SCHEMA_16_NEGATIVEPRECISIONNOTALLOWED 0x000003F8L

//
// MessageId: SCHEMA_17_ASSOCIATIONMISSMATCHERROR
//
// MessageText:
//
//  Association Property '%1$ls' has type or number missmatch between the identity properties and the reverse identity properties. 
//
#define SCHEMA_17_ASSOCIATIONMISSMATCHERROR 0x000003F9L

//
// MessageId: SCHEMA_18_ASSOCIATIONIDENTITYERROR
//
// MessageText:
//
//  Identity properties not part of the associated class.
//
#define SCHEMA_18_ASSOCIATIONIDENTITYERROR 0x000003FAL

//
// MessageId: SCHEMA_19_UNSUPPORTEDXSDELEMENT
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, element '#2$ls' in #3$ls not supported by FDO.
//
#define SCHEMA_19_UNSUPPORTEDXSDELEMENT  0x000003FBL

//
// MessageId: SCHEMA_20_UNSUPPORTEDXSDATTRIBUTE
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, attribute '#2$ls' in #3$ls not supported by FDO.
//
#define SCHEMA_20_UNSUPPORTEDXSDATTRIBUTE 0x000003FCL

//
// MessageId: SCHEMA_21_UNSUPPORTEDXSDATTRIBUTEVALUE
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, #2$ls/@#3$ls value '#4$ls' not supported by FDO.
//
#define SCHEMA_21_UNSUPPORTEDXSDATTRIBUTEVALUE 0x000003FDL

//
// MessageId: SCHEMA_22_MISSINGOBJPROPCLASS
//
// MessageText:
//
//  Error reading schema from XML, class %1$ls for object property %2$ls not found in current feature schema collection.
//
#define SCHEMA_22_MISSINGOBJPROPCLASS    0x000003FEL

//
// MessageId: SCHEMA_23_UNSUPPORTEDXSDGBLELEM
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, global element #2$ls type must be '#3$ls' or '#4$ls'.
//
#define SCHEMA_23_UNSUPPORTEDXSDGBLELEM  0x000003FFL

//
// MessageId: SCHEMA_24_CLASSTYPECONFLICT
//
// MessageText:
//
//  Cannot change class type of class '%1$ls'. 
//
#define SCHEMA_24_CLASSTYPECONFLICT      0x00000400L

//
// MessageId: SCHEMA_25_PROPERTYTYPECONFLICT
//
// MessageText:
//
//  Cannot change property type of property '%1$ls'. 
//
#define SCHEMA_25_PROPERTYTYPECONFLICT   0x00000401L

//
// MessageId: SCHEMA_26_BASECLASSREF
//
// MessageText:
//
//  Error resolving Feature Schema references; base class '%1$ls:%2$ls' for class '%3$ls' not found. 
//
#define SCHEMA_26_BASECLASSREF           0x00000402L

//
// MessageId: SCHEMA_27_OBJPROPCLASSREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; class '%1$ls:%2$ls' for object property '%3$ls' not found. 
//
#define SCHEMA_27_OBJPROPCLASSREF        0x00000403L

//
// MessageId: SCHEMA_28_BASEIDPROPS
//
// MessageText:
//
//  Error reading Feature Schemas from XML; identity properties for class '%1$ls' differ from those of base class '%2$ls'.
//
#define SCHEMA_28_BASEIDPROPS            0x00000404L

//
// MessageId: SCHEMA_29_IDPROPREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; identity property '%1$ls' is not a property in class '%2$ls'.
//
#define SCHEMA_29_IDPROPREF              0x00000405L

//
// MessageId: SCHEMA_30_BASEIDPROPS
//
// MessageText:
//
//  Error reading Feature Schemas from XML; object property '%1$ls' has no class; cannot resolve its identity property.
//
#define SCHEMA_30_BASEIDPROPS            0x00000406L

//
// MessageId: SCHEMA_31_OBJPROPIDPROPREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; identity property '%1$ls' for object property '%2$ls' not found.
//
#define SCHEMA_31_OBJPROPIDPROPREF       0x00000407L

//
// MessageId: SCHEMA_32_GEOMPROPREF
//
// MessageText:
//
//  Error resolving Feature Schemas references; geometry property '%1$ls' for feature class '%2$ls' not found.
//
#define SCHEMA_32_GEOMPROPREF            0x00000408L

//
// MessageId: SCHEMA_33_BADDATAPROPSTRING
//
// MessageText:
//
//  Invalid property data type string %1$ls.
//
#define SCHEMA_33_BADDATAPROPSTRING      0x00000409L

//
// MessageId: SCHEMA_34_BADDATAPROPTYPE
//
// MessageText:
//
//  Invalid property data type %1$d.
//
#define SCHEMA_34_BADDATAPROPTYPE        0x0000040AL

//
// MessageId: SCHEMA_35_NOCLASSTYPE
//
// MessageText:
//
//  Cannot determine class type for class %1$ls.
//
#define SCHEMA_35_NOCLASSTYPE            0x0000040BL

//
// MessageId: SCHEMA_36_ABSTRACTCONFLICT
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, abstract setting for  '#2$ls' differs from that of its global element '#3$ls.
//
#define SCHEMA_36_ABSTRACTCONFLICT       0x0000040CL

//
// MessageId: SCHEMA_37_REQUIREDNODEFEATURE
//
// MessageText:
//
//  Start and end nodes of a network link feature can only be associated to a network node feature
//
#define SCHEMA_37_REQUIREDNODEFEATURE    0x0000040DL

//
// MessageId: SCHEMA_38_REQUIREDLAYERCLASS
//
// MessageText:
//
//  The layer property can only be associated to a network layer class
//
#define SCHEMA_38_REQUIREDLAYERCLASS     0x0000040EL

//
// MessageId: SCHEMA_39_REQUIREDNETWORKFCLASS
//
// MessageText:
//
//  The network property can only be associated to a network class
//
#define SCHEMA_39_REQUIREDNETWORKFCLASS  0x0000040FL

//
// MessageId: SCHEMA_40_REQUIREDNUMERICTYPE
//
// MessageText:
//
//  The cost property type must be numeric.
//
#define SCHEMA_40_REQUIREDNUMERICTYPE    0x00000410L

//
// MessageId: SCHEMA_41_PARENTCHILDNOTSAMETYPE
//
// MessageText:
//
//  The network feature parent is not the same type as the child.
//
#define SCHEMA_41_PARENTCHILDNOTSAMETYPE 0x00000411L

//
// MessageId: SCHEMA_42_PARENTCHILDNETWORKNOTSAME
//
// MessageText:
//
//  The network feature parent network class is not the same as the child network class.
//
#define SCHEMA_42_PARENTCHILDNETWORKNOTSAME 0x00000412L

//
// MessageId: SCHEMA_43_COSTPROPERTYNOTFOUND
//
// MessageText:
//
//  The network feature cost property is not a feature property.
//
#define SCHEMA_43_COSTPROPERTYNOTFOUND   0x00000413L

//
// MessageId: SCHEMA_44_LINKSTARTORENDNODENETWORKERROR
//
// MessageText:
//
//  The start and end node network class must be the same as the link network class.
//
#define SCHEMA_44_LINKSTARTORENDNODENETWORKERROR 0x00000414L

//
// MessageId: SCHEMA_45_ASSOCPROPCLASSREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; class '%1$ls:%2$ls' for association property '%3$ls' not found.
//
#define SCHEMA_45_ASSOCPROPCLASSREF      0x00000415L

//
// MessageId: SCHEMA_46_ASSOCPROPS
//
// MessageText:
//
//  Error reading Feature Schemas from XML; association property '%1$ls' has no class; cannot resolve its identity property.
//
#define SCHEMA_46_ASSOCPROPS             0x00000416L

//
// MessageId: SCHEMA_47_ASSOCPROPIDPROPREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; identity property '%1$ls' for association property '%2$ls' not found.
//
#define SCHEMA_47_ASSOCPROPIDPROPREF     0x00000417L

//
// MessageId: SCHEMA_48_ASSOCREVERSEPROPCLASSREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; reverse association property '%1$ls' has no class; cannot resolve its identity property.
//
#define SCHEMA_48_ASSOCREVERSEPROPCLASSREF 0x00000418L

//
// MessageId: SCHEMA_49_ASSOCREVERSEPROPIDPROPREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; identity property '%1$ls' for reverse association property '%2$ls' not found.
//
#define SCHEMA_49_ASSOCREVERSEPROPIDPROPREF 0x00000419L

//
// MessageId: SCHEMA_50_NETWORKLAYERPROPREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; class '%1$ls:%2$ls' for network layer property '%3$ls' not found.
//
#define SCHEMA_50_NETWORKLAYERPROPREF    0x0000041AL

//
// MessageId: SCHEMA_51_CLASSNOSCHEMA
//
// MessageText:
//
//  Element '%1$ls' references class (%2$ls) which does not belong to a feature schema.
//
#define SCHEMA_51_CLASSNOSCHEMA          0x0000041BL

//
// MessageId: SCHEMA_52_BADELEMENTNAME
//
// MessageText:
//
//  Invalid Feature schema element name '%1$ls'; must not contain '%2$c'.
//
#define SCHEMA_52_BADELEMENTNAME         0x0000041CL

//
// MessageId: SCHEMA_53_BADASSOCREVERSEPROP
//
// MessageText:
//
//  Cannot use auto-generated or system properties as reverse identity properties for association property '%1$ls'
//
#define SCHEMA_53_BADASSOCREVERSEPROP    0x0000041DL

//
// MessageId: SCHEMA_54_AUTOGENREADONLY
//
// MessageText:
//
//  Cannot set autogenerated property '%1$ls' to be not read-only.
//
#define SCHEMA_54_AUTOGENREADONLY        0x0000041EL

//
// MessageId: SCHEMA_55_ASSOCIATEDCLASSREQUIRED
//
// MessageText:
//
//  Association property '%1$ls' is missing the associated class
//
#define SCHEMA_55_ASSOCIATEDCLASSREQUIRED 0x0000041FL

//
// MessageId: SCHEMA_56_UNSUPPORTEDXSDGBLELEM
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, global element #2$ls type must be '#3$ls' when error level is high.
//
#define SCHEMA_56_UNSUPPORTEDXSDGBLELEM  0x00000420L

//
// MessageId: SCHEMA_57_BADCOMPLEXTYPENAME
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, complexType #2$ls name must end with 'Type' when error level is high.
//
#define SCHEMA_57_BADCOMPLEXTYPENAME     0x00000421L

//
// MessageId: SCHEMA_58_UNSUPPORTEDXSDGBLELEM
//
// MessageText:
//
//  Error reading schema '#1$ls' from XML, global element #2$ls type is from a different schema: '#3$ls'.
//
#define SCHEMA_58_UNSUPPORTEDXSDGBLELEM  0x00000422L

//
// MessageId: SCHEMA_59_SCHEMAFROMPREFIX
//
// MessageText:
//
//  Schema names can only be generated from xmlns prefixes when ErrorLevel is VeryLow.
//
#define SCHEMA_59_SCHEMAFROMPREFIX       0x00000423L

//
// MessageId: SCHEMA_60_MULTIELEMMAPPING
//
// MessageText:
//
//  Multiple Schema Mappings found for element '%1$ls:%2$ls'.
//
#define SCHEMA_60_MULTIELEMMAPPING       0x00000424L

//
// MessageId: SCHEMA_61_MULTIELEMMAPPING
//
// MessageText:
//
//  Multiple Schema Mappings found for element '%1$ls:%2$ls.%3$ls'.
//
#define SCHEMA_61_MULTIELEMMAPPING       0x00000425L

//
// MessageId: SCHEMA_62_NOCLASSMAPPING
//
// MessageText:
//
//  Cannot add element '%1$ls', containing class mapping '%2$ls:%3$ls' not found.
//
#define SCHEMA_62_NOCLASSMAPPING         0x00000426L

//
// MessageId: SCHEMA_63_MULTICLASSMAPPING
//
// MessageText:
//
//  Multiple Schema Mappings found for class '%1$ls:%2$ls'.
//
#define SCHEMA_63_MULTICLASSMAPPING      0x00000427L

//
// MessageId: SCHEMA_64_MULTINAMESPACES
//
// MessageText:
//
//  Schema '%1$ls' has multiple targetNamespace values: '%2$ls', '%3$ls'.
//
#define SCHEMA_64_MULTINAMESPACES        0x00000428L

//
// MessageId: SCHEMA_65_UNICONSPROPREF
//
// MessageText:
//
//  Error reading Feature Schemas from XML; unique constraint property '%1$ls' for feature class '%2$ls' not found.
//
#define SCHEMA_65_UNICONSPROPREF         0x00000429L

//
// MessageId: SCHEMA_66_SCHEMARENAME
//
// MessageText:
//
//  Unsupported Schema modification; cannot rename feature schema '%1$ls' to '%2$ls'.
//
#define SCHEMA_66_SCHEMARENAME           0x0000042AL

//
// MessageId: SCHEMA_67_CLASSEXISTS
//
// MessageText:
//
//  Cannot add class '%1$ls'; it already exists
//
#define SCHEMA_67_CLASSEXISTS            0x0000042BL

//
// MessageId: SCHEMA_68_BADCLASSTYPE
//
// MessageText:
//
//  Cannot create class '%1$ls', unknown class type: %2$d
//
#define SCHEMA_68_BADCLASSTYPE           0x0000042CL

//
// MessageId: SCHEMA_69_CLASSNOTEXISTS
//
// MessageText:
//
//  Cannot modify class '%1$ls'; it does not exist
//
#define SCHEMA_69_CLASSNOTEXISTS         0x0000042DL

//
// MessageId: SCHEMA_70_MODDESCRIPTION
//
// MessageText:
//
//  Unsupported Schema modification; cannot modify description for element '%1$ls'.
//
#define SCHEMA_70_MODDESCRIPTION         0x0000042EL

//
// MessageId: SCHEMA_71_MODCLASSCONCRETE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot make abstract class '%1$ls' concrete
//
#define SCHEMA_71_MODCLASSCONCRETE       0x0000042FL

//
// MessageId: SCHEMA_72_MODCLASSABSTRACT
//
// MessageText:
//
//  Unsupported Schema modification; Cannot make class '%1$ls' abstract
//
#define SCHEMA_72_MODCLASSABSTRACT       0x00000430L

//
// MessageId: SCHEMA_73_MODBASECLASS
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change base class for '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_73_MODBASECLASS           0x00000431L

//
// MessageId: SCHEMA_74_MODCLASSIDENTITY
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change identity properties for class '%1$ls' from (%2$ls) to (%3$ls)
//
#define SCHEMA_74_MODCLASSIDENTITY       0x00000432L

//
// MessageId: SCHEMA_75_PROPEXISTS
//
// MessageText:
//
//  Cannot add property '%1$ls'; it already exists
//
#define SCHEMA_75_PROPEXISTS             0x00000433L

//
// MessageId: SCHEMA_76_BADPROPTYPE
//
// MessageText:
//
//  Cannot create property '%1$ls', unknown property type: %2$d
//
#define SCHEMA_76_BADPROPTYPE            0x00000434L

//
// MessageId: SCHEMA_77_PROPNOTEXISTS
//
// MessageText:
//
//  Cannot modify property '%1$ls'; it does not exist
//
#define SCHEMA_77_PROPNOTEXISTS          0x00000435L

//
// MessageId: SCHEMA_78_MODFEATGEOM
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify GeometryProperty for feature class '%1$ls'
//
#define SCHEMA_78_MODFEATGEOM            0x00000436L

//
// MessageId: SCHEMA_79_MODNETLAYER
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify layer class for network class '%1$ls'
//
#define SCHEMA_79_MODNETLAYER            0x00000437L

//
// MessageId: SCHEMA_80_MODNETCOST
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify cost property for network feature class '%1$ls'
//
#define SCHEMA_80_MODNETCOST             0x00000438L

//
// MessageId: SCHEMA_81_MODFEATNET
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify network class for network feature class '%1$ls'
//
#define SCHEMA_81_MODFEATNET             0x00000439L

//
// MessageId: SCHEMA_82_MODNETFEATREF
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify referenced feature class for network feature class '%1$ls'
//
#define SCHEMA_82_MODNETFEATREF          0x0000043AL

//
// MessageId: SCHEMA_83_MODPARENTNETFEAT
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify parent network feature class for network feature class '%1$ls'
//
#define SCHEMA_83_MODPARENTNETFEAT       0x0000043BL

//
// MessageId: SCHEMA_84_MODSTARTNODE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify start node for network link feature class '%1$ls'
//
#define SCHEMA_84_MODSTARTNODE           0x0000043CL

//
// MessageId: SCHEMA_85_MODENDNODE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify end node for network link feature class '%1$ls'
//
#define SCHEMA_85_MODENDNODE             0x0000043DL

//
// MessageId: SCHEMA_86_MODNODELAYER
//
// MessageText:
//
//  Unsupported Schema modification; Cannot modify layer for network node feature class '%1$ls'
//
#define SCHEMA_86_MODNODELAYER           0x0000043EL

//
// MessageId: SCHEMA_87_MODDATATYPE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change data type for property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_87_MODDATATYPE            0x0000043FL

//
// MessageId: SCHEMA_88_MODDEFAULTVALUE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change default value for data property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_88_MODDEFAULTVALUE        0x00000440L

//
// MessageId: SCHEMA_89_MODDATALENGTH
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change length for data property '%1$ls' from '%2$d' to '%3$d'
//
#define SCHEMA_89_MODDATALENGTH          0x00000441L

//
// MessageId: SCHEMA_90_MODPROPNULLABLE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change property '%1$ls' to be nullable
//
#define SCHEMA_90_MODPROPNULLABLE        0x00000442L

//
// MessageId: SCHEMA_91_MODPROPNNULLABLE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change property '%1$ls' to be not nullable
//
#define SCHEMA_91_MODPROPNNULLABLE       0x00000443L

//
// MessageId: SCHEMA_92_MODDATAPRECISION
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change precision for data property '%1$ls' from '%2$d' to '%3$d'
//
#define SCHEMA_92_MODDATAPRECISION       0x00000444L

//
// MessageId: SCHEMA_93_MODDATASCALE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change scale for data property '%1$ls' from '%2$d' to '%3$d'
//
#define SCHEMA_93_MODDATASCALE           0x00000445L

//
// MessageId: SCHEMA_94_MODDATAAUTOGEN
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change autogeneration setting for data property '%1$ls'
//
#define SCHEMA_94_MODDATAAUTOGEN         0x00000446L

//
// MessageId: SCHEMA_95_MODPROPRDONLY
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change property '%1$ls' to be read-only
//
#define SCHEMA_95_MODPROPRDONLY          0x00000447L

//
// MessageId: SCHEMA_96_MODPROPWRITABLE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change property '%1$ls' to be writable
//
#define SCHEMA_96_MODPROPWRITABLE        0x00000448L

//
// MessageId: SCHEMA_97_BADCONSTRAINTTYPE
//
// MessageText:
//
//  Cannot modify constraint for data property '%1$ls'; unknown constraint type: %2$d
//
#define SCHEMA_97_BADCONSTRAINTTYPE      0x00000449L

//
// MessageId: SCHEMA_98_MODDATACONSTRAINT
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change constraint for data property '%1$ls'
//
#define SCHEMA_98_MODDATACONSTRAINT      0x0000044AL

//
// MessageId: SCHEMA_99_MODGEOMTYPES
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change geometry types for geometric property '%1$ls'
//
#define SCHEMA_99_MODGEOMTYPES           0x0000044BL

//
// MessageId: SCHEMA_100_MODGEOMELEVATION
//
// MessageText:
//
//  Unsupported Schema modification; Cannot add/remove elevation dimension to/from geometric property '%1$ls'
//
#define SCHEMA_100_MODGEOMELEVATION      0x0000044CL

//
// MessageId: SCHEMA_101_MODGEOMMEASURE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot add/remove measure dimension to/from geometric property '%1$ls'
//
#define SCHEMA_101_MODGEOMMEASURE        0x0000044DL

//
// MessageId: SCHEMA_102_MODPROPSC
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change spatial context for property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_102_MODPROPSC             0x0000044EL

//
// MessageId: SCHEMA_103_MODASSOCCLASS
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change associated class for association property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_103_MODASSOCCLASS         0x0000044FL

//
// MessageId: SCHEMA_104_MODASSOCREVNAME
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change reverse name for association property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_104_MODASSOCREVNAME       0x00000450L

//
// MessageId: SCHEMA_105_MODASSOCDELRULE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change delete rule for association property '%1$ls'
//
#define SCHEMA_105_MODASSOCDELRULE       0x00000451L

//
// MessageId: SCHEMA_106_MODASSOCCASCLOCK
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change cascade lock setting for association property '%1$ls'
//
#define SCHEMA_106_MODASSOCCASCLOCK      0x00000452L

//
// MessageId: SCHEMA_107_MODASSOCMULT
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change multiplicity for association property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_107_MODASSOCMULT          0x00000453L

//
// MessageId: SCHEMA_108_MODASSOCREVMULT
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change reverse multiplicity for association property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_108_MODASSOCREVMULT       0x00000454L

//
// MessageId: SCHEMA_109_MODASSOCID
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change identity properties for association property '%1$ls' from (%2$ls) to (%3$ls)
//
#define SCHEMA_109_MODASSOCID            0x00000455L

//
// MessageId: SCHEMA_110_MODREVASSOCID
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change reverse identity properties for association property '%1$ls' from (%2$ls) to (%3$ls)
//
#define SCHEMA_110_MODREVASSOCID         0x00000456L

//
// MessageId: SCHEMA_111_MODOBJCLASS
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change class for object property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_111_MODOBJCLASS           0x00000457L

//
// MessageId: SCHEMA_112_MODOBJID
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change identity property for object property '%1$ls' from '%2$ls' to '%3$ls'
//
#define SCHEMA_112_MODOBJID              0x00000458L

//
// MessageId: SCHEMA_113_MODOBJTYPE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change object type for object property '%1$ls'
//
#define SCHEMA_113_MODOBJTYPE            0x00000459L

//
// MessageId: SCHEMA_114_MODOBJORDERTYPE
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change order type for object property '%1$ls'
//
#define SCHEMA_114_MODOBJORDERTYPE       0x0000045AL

//
// MessageId: SCHEMA_115_MODRASTERMODEL
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change default data model for raster property '%1$ls'
//
#define SCHEMA_115_MODRASTERMODEL        0x0000045BL

//
// MessageId: SCHEMA_116_MODRASTERX
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change default image X size for raster property '%1$ls' from '%2$d' to '%3$d'
//
#define SCHEMA_116_MODRASTERX            0x0000045CL

//
// MessageId: SCHEMA_117_MODRASTERY
//
// MessageText:
//
//  Unsupported Schema modification; Cannot change default image Y size for raster property '%1$ls' from '%2$d' to '%3$d'
//
#define SCHEMA_117_MODRASTERY            0x0000045DL

//
// MessageId: SCHEMA_118_SCHEMAEXISTS
//
// MessageText:
//
//  Cannot add feature schema '%1$ls'; it already exists
//
#define SCHEMA_118_SCHEMAEXISTS          0x0000045EL

//
// MessageId: SCHEMA_119_SCHEMANOTEXISTS
//
// MessageText:
//
//  Cannot modify feature schema '%1$ls'; it does not exist
//
#define SCHEMA_119_SCHEMANOTEXISTS       0x0000045FL

//
// MessageId: SCHEMA_120_ADDSCHEMA
//
// MessageText:
//
//  Cannot add feature schema '%1$ls'; multiple schemas not supported
//
#define SCHEMA_120_ADDSCHEMA             0x00000460L

//
// MessageId: SCHEMA_121_DELSCHEMA
//
// MessageText:
//
//  Unsupport Schema modification; Cannot delete feature schema '%1$ls'
//
#define SCHEMA_121_DELSCHEMA             0x00000461L

//
// MessageId: SCHEMA_122_ADDCLASS
//
// MessageText:
//
//  Unsupport Schema modification; Cannot add class definition '%1$ls'
//
#define SCHEMA_122_ADDCLASS              0x00000462L

//
// MessageId: SCHEMA_123_DELCLASS
//
// MessageText:
//
//  Unsupport Schema modification; Cannot delete class definition '%1$ls'
//
#define SCHEMA_123_DELCLASS              0x00000463L

//
// MessageId: SCHEMA_124_ADDPROP
//
// MessageText:
//
//  Unsupport Schema modification; Cannot add property '%1$ls'
//
#define SCHEMA_124_ADDPROP               0x00000464L

//
// MessageId: SCHEMA_125_DELPROP
//
// MessageText:
//
//  Unsupport Schema modification; Cannot delete property '%1$ls'
//
#define SCHEMA_125_DELPROP               0x00000465L

//
// MessageId: SCHEMA_126_DELBASECLASS
//
// MessageText:
//
//  Cannot delete class '%1$ls'; it is the base class for '%2$ls'
//
#define SCHEMA_126_DELBASECLASS          0x00000466L

//
// MessageId: SCHEMA_127_DELOBJCLASS
//
// MessageText:
//
//  Cannot delete class '%1$ls'; it is the class for object property '%2$ls'
//
#define SCHEMA_127_DELOBJCLASS           0x00000467L

//
// MessageId: SCHEMA_128_DELCLASSID
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is an identity property for class '%2$ls'
//
#define SCHEMA_128_DELCLASSID            0x00000468L

//
// MessageId: SCHEMA_129_DELOBJID
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is an identity property for object property '%2$ls'
//
#define SCHEMA_129_DELOBJID              0x00000469L

//
// MessageId: SCHEMA_130_DELASSOCCLASS
//
// MessageText:
//
//  Cannot delete class '%1$ls'; it is the associated class for association property '%2$ls'
//
#define SCHEMA_130_DELASSOCCLASS         0x0000046AL

//
// MessageId: SCHEMA_131_DELASSOCID
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is an identity property for association property '%2$ls'
//
#define SCHEMA_131_DELASSOCID            0x0000046BL

//
// MessageId: SCHEMA_132_DELASSOCREVID
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is a reverse identity property for association property '%2$ls'
//
#define SCHEMA_132_DELASSOCREVID         0x0000046CL

//
// MessageId: SCHEMA_133_DELLAYERCLASS
//
// MessageText:
//
//  Cannot delete class '%1$ls'; it is the network layer class for network class '%2$ls'
//
#define SCHEMA_133_DELLAYERCLASS         0x0000046DL

//
// MessageId: SCHEMA_134_DELNETCOST
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the cost property for network feature class '%2$ls'
//
#define SCHEMA_134_DELNETCOST            0x0000046EL

//
// MessageId: SCHEMA_135_DELFEATNET
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the network class property for network feature class '%2$ls'
//
#define SCHEMA_135_DELFEATNET            0x0000046FL

//
// MessageId: SCHEMA_136_DELREFFEAT
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the referenced feature property for network feature class '%2$ls'
//
#define SCHEMA_136_DELREFFEAT            0x00000470L

//
// MessageId: SCHEMA_137_DELNETPARENT
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the parent network feature property for network feature class '%2$ls'
//
#define SCHEMA_137_DELNETPARENT          0x00000471L

//
// MessageId: SCHEMA_138_DELSTARTNODE
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the start node property for network link feature class '%2$ls'
//
#define SCHEMA_138_DELSTARTNODE          0x00000472L

//
// MessageId: SCHEMA_139_DELENDNODE
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the end node property for network link feature class '%2$ls'
//
#define SCHEMA_139_DELENDNODE            0x00000473L

//
// MessageId: SCHEMA_140_DELNODELAYER
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the layer property for network node feature class '%2$ls'
//
#define SCHEMA_140_DELNODELAYER          0x00000474L

//
// MessageId: SCHEMA_141_BASETYPECONFLICT
//
// MessageText:
//
//  Cannot set base class for '%1$ls' to '%2$ls'; they have different class types
//
#define SCHEMA_141_BASETYPECONFLICT      0x00000475L

//
// MessageId: SCHEMA_142_DELFEATGEOM
//
// MessageText:
//
//  Cannot delete property '%1$ls'; it is the geometry property for feature class '%2$ls'
//
#define SCHEMA_142_DELFEATGEOM           0x00000476L

//
// MessageId: SCHEMA_143_DELCLASSOBJECTS
//
// MessageText:
//
//  Cannot delete class definition '%1$ls'; it has objects
//
#define SCHEMA_143_DELCLASSOBJECTS       0x00000477L

//
// MessageId: SCHEMA_144_ADDPROPOBJECTS
//
// MessageText:
//
//  Cannot add not-nullable property '%1$ls'; its class has objects
//
#define SCHEMA_144_ADDPROPOBJECTS        0x00000478L

//
// MessageId: SCHEMA_145_DELPROPOBJECTS
//
// MessageText:
//
//  Cannot delete a property '%1$ls'; its class has objects
//
#define SCHEMA_145_DELPROPOBJECTS        0x00000479L

//
// MessageId: SCHEMA_146_DELSCHEMAOBJECTS
//
// MessageText:
//
//  Cannot delete schema definition '%1$ls'; it has objects
//
#define SCHEMA_146_DELSCHEMAOBJECTS      0x0000047AL

//
// MessageId: SCHEMA_148_MODCONSTRAINTTYPE
//
// MessageText:
//
//  Cannot modify constraint type for property '%1$ls'; property has values
//
#define SCHEMA_148_MODCONSTRAINTTYPE     0x0000047CL

//
// MessageId: SCHEMA_147_MODCONSTRAINT
//
// MessageText:
//
//  Cannot modify constraint for property '%1$ls'; property has values and new constraint is more restrictive
//
#define SCHEMA_147_MODCONSTRAINT         0x0000047BL

//
// MessageId: EXPRESSION_1_BLOBVALUENULL
//
// MessageText:
//
//  BLOBValue is null.
//
#define EXPRESSION_1_BLOBVALUENULL       0x000007D1L

//
// MessageId: EXPRESSION_2_BOOLEANVALUENULL
//
// MessageText:
//
//  BooleanValue is null.
//
#define EXPRESSION_2_BOOLEANVALUENULL    0x000007D2L

//
// MessageId: EXPRESSION_3_BYTEVALUENULL
//
// MessageText:
//
//  ByteValue is null.
//
#define EXPRESSION_3_BYTEVALUENULL       0x000007D3L

//
// MessageId: EXPRESSION_4_CLOBVALUENULL
//
// MessageText:
//
//  CLOBValue is null.
//
#define EXPRESSION_4_CLOBVALUENULL       0x000007D4L

//
// MessageId: EXPRESSION_5_DATETIMEVALUENULL
//
// MessageText:
//
//  DateTimeValue is null.
//
#define EXPRESSION_5_DATETIMEVALUENULL   0x000007D5L

//
// MessageId: EXPRESSION_6_DECIMALVALUENULL
//
// MessageText:
//
//  DecimalValue is null.
//
#define EXPRESSION_6_DECIMALVALUENULL    0x000007D6L

//
// MessageId: EXPRESSION_7_DOUBLEVALUENULL
//
// MessageText:
//
//  DoubleValue is null.
//
#define EXPRESSION_7_DOUBLEVALUENULL     0x000007D7L

//
// MessageId: EXPRESSION_8_INCOMPLETEBINARYEXPRESSION
//
// MessageText:
//
//  Incomplete binary expression.
//
#define EXPRESSION_8_INCOMPLETEBINARYEXPRESSION 0x000007D8L

//
// MessageId: EXPRESSION_9_INCOMPLETEFUNCTION
//
// MessageText:
//
//  Incomplete function.
//
#define EXPRESSION_9_INCOMPLETEFUNCTION  0x000007D9L

//
// MessageId: EXPRESSION_10_INCOMPLETEPARAMETER
//
// MessageText:
//
//  Incomplete parameter.
//
#define EXPRESSION_10_INCOMPLETEPARAMETER 0x000007DAL

//
// MessageId: EXPRESSION_11_INCOMPLETEUNARYEXPRESSION
//
// MessageText:
//
//  Incomplete unary expression.
//
#define EXPRESSION_11_INCOMPLETEUNARYEXPRESSION 0x000007DBL

//
// MessageId: EXPRESSION_12_INT16VALUENULL
//
// MessageText:
//
//  Int16Value is null.
//
#define EXPRESSION_12_INT16VALUENULL     0x000007DCL

//
// MessageId: EXPRESSION_13_INT32VALUENULL
//
// MessageText:
//
//  Int32Value is null.
//
#define EXPRESSION_13_INT32VALUENULL     0x000007DDL

//
// MessageId: EXPRESSION_14_INT64VALUENULL
//
// MessageText:
//
//  Int64Value is null.
//
#define EXPRESSION_14_INT64VALUENULL     0x000007DEL

//
// MessageId: EXPRESSION_15_INVALIDDATAVALUE
//
// MessageText:
//
//  Invalid data type.
//
#define EXPRESSION_15_INVALIDDATAVALUE   0x000007DFL

//
// MessageId: EXPRESSION_16_NULLIDENTIFIER
//
// MessageText:
//
//  Null identifier.
//
#define EXPRESSION_16_NULLIDENTIFIER     0x000007E0L

//
// MessageId: EXPRESSION_17_STRINGNOTEXPRESSION
//
// MessageText:
//
//  String does not represent a valid expression.
//
#define EXPRESSION_17_STRINGNOTEXPRESSION 0x000007E1L

//
// MessageId: EXPRESSION_18_SINGLEVALUENULL
//
// MessageText:
//
//  SingleValue is null.
//
#define EXPRESSION_18_SINGLEVALUENULL    0x000007E2L

//
// MessageId: EXPRESSION_19_STRINGVALUENULL
//
// MessageText:
//
//  StringValue is null.
//
#define EXPRESSION_19_STRINGVALUENULL    0x000007E3L

//
// MessageId: EXPRESSION_20_STRINGNOTVALUEEXPRESSION
//
// MessageText:
//
//  String does not represent a valid value expression.
//
#define EXPRESSION_20_STRINGNOTVALUEEXPRESSION 0x000007E4L

//
// MessageId: FILTER_1_INCOMPLETEBINARYOPERATOR
//
// MessageText:
//
//  Incomplete binary logical operator.
//
#define FILTER_1_INCOMPLETEBINARYOPERATOR 0x00000BB9L

//
// MessageId: FILTER_2_INCOMPLETECOMPARISONCONDITION
//
// MessageText:
//
//  Incomplete comparison condition.
//
#define FILTER_2_INCOMPLETECOMPARISONCONDITION 0x00000BBAL

//
// MessageId: FILTER_3_INCOMPLETEDISTANCECONDITION
//
// MessageText:
//
//  Incomplete distance condition.
//
#define FILTER_3_INCOMPLETEDISTANCECONDITION 0x00000BBBL

//
// MessageId: FILTER_4_INCOMPLETEINCONDITION
//
// MessageText:
//
//  Incomplete in condition.
//
#define FILTER_4_INCOMPLETEINCONDITION   0x00000BBCL

//
// MessageId: FILTER_5_INCOMPLETENULLCONDITION
//
// MessageText:
//
//  Incomplete null condition.
//
#define FILTER_5_INCOMPLETENULLCONDITION 0x00000BBDL

//
// MessageId: FILTER_6_INCOMPLETESPATIALCONDITION
//
// MessageText:
//
//  Incomplete spatial condition.
//
#define FILTER_6_INCOMPLETESPATIALCONDITION 0x00000BBEL

//
// MessageId: FILTER_7_INCOMPLETEUNARYOPERATOR
//
// MessageText:
//
//  Incomplete unary logical operator.
//
#define FILTER_7_INCOMPLETEUNARYOPERATOR 0x00000BBFL

//
// MessageId: FILTER_8_INVALIDFILTERSTRING
//
// MessageText:
//
//  Invalid filter string.
//
#define FILTER_8_INVALIDFILTERSTRING     0x00000BC0L

//
// MessageId: FILTER_9_STRINGNOTFILTER
//
// MessageText:
//
//  String does not represent a valid filter.
//
#define FILTER_9_STRINGNOTFILTER         0x00000BC1L

//
// MessageId: COMMANDS_1_INVALIDIDENTIFIERNAME
//
// MessageText:
//
//  Invalid identifier name '%1$ls'.
//
#define COMMANDS_1_INVALIDIDENTIFIERNAME 0x00000FA1L

//
// MessageId: COMMANDS_2_INVALIDPARAMETERVALUENAME
//
// MessageText:
//
//  Invalid parameter value name '%1$ls'.
//
#define COMMANDS_2_INVALIDPARAMETERVALUENAME 0x00000FA2L

//
// MessageId: COMMANDS_3_INVALIDPROPERTYVALUENAME
//
// MessageText:
//
//  Invalid property value name '%1$ls'.
//
#define COMMANDS_3_INVALIDPROPERTYVALUENAME 0x00000FA3L

//
// MessageId: COMMANDS_4_INVALIDPROVIDERNAME
//
// MessageText:
//
//  Schema Override set for schema '%1$ls' has invalid provider name '%2$ls'; must be of the form: Company.Provider.Version.
//
#define COMMANDS_4_INVALIDPROVIDERNAME   0x00000FA4L

//
// MessageId: COMMANDS_5_OVERRIDEPROVIDERMISMATCH
//
// MessageText:
//
//  Registered provider '%1$ls' is registered with library for provider '%2$ls'.
//
#define COMMANDS_5_OVERRIDEPROVIDERMISMATCH 0x00000FA5L

//
// MessageId: COMMANDS_6_MISSINGPROVIDERNAME
//
// MessageText:
//
//  Schema Override set for schema '%1$ls' has no provider name.
//
#define COMMANDS_6_MISSINGPROVIDERNAME   0x00000FA6L

//
// MessageId: COMMANDS_7_OBJECTHASPARENT
//
// MessageText:
//
//  Schema Override '%1$ls' already has parent.
//
#define COMMANDS_7_OBJECTHASPARENT       0x00000FA7L

//
// MessageId: COMMANDS_8_BADMAPPINGSUBELEMENT
//
// MessageText:
//
//  Element '%1$ls' not allowed inside %2$ls Schema Mapping element %3$ls[@name='%4$ls'].
//
#define COMMANDS_8_BADMAPPINGSUBELEMENT  0x00000FA8L

//
// MessageId: COMMANDS_9_MULTIMAPPINGSUBELEMENT
//
// MessageText:
//
//  Multiple instances of Element '%1$ls' not allowed inside %2$ls Schema Mapping element %3$ls[@name='%4$ls'].
//
#define COMMANDS_9_MULTIMAPPINGSUBELEMENT 0x00000FA9L

//
// MessageId: COMMANDS_10_CHOICESUBELEMENT
//
// MessageText:
//
//  Only one of '%1$ls' allowed inside %2$ls Schema Mapping element %3$ls[@name='%4$ls'].
//
#define COMMANDS_10_CHOICESUBELEMENT     0x00000FAAL

//
// MessageId: COMMANDS_11_OWNPARENT
//
// MessageText:
//
//  Element '%1$ls' cannot be its own parent/grandparent.
//
#define COMMANDS_11_OWNPARENT            0x00000FABL

//
// MessageId: COMMANDS_12_DUPLICATESUBELEMENT
//
// MessageText:
//
//  Only one of '%1$ls[@name=%2$ls]' allowed inside %3$ls Schema Mapping element %4$ls[@name='%5$ls'].
//
#define COMMANDS_12_DUPLICATESUBELEMENT  0x00000FACL

//
// MessageId: PARSE_1_INVALIDDIGIT
//
// MessageText:
//
//  Invalid digit in number.
//
#define PARSE_1_INVALIDDIGIT             0x00001389L

//
// MessageId: PARSE_2_INVALIDDATETIME
//
// MessageText:
//
//  Invalid DateTime value.
//
#define PARSE_2_INVALIDDATETIME          0x0000138AL

//
// MessageId: PARSE_3_DATETIMEOUTOFRANGE
//
// MessageText:
//
//  DateTime value out of range.
//
#define PARSE_3_DATETIMEOUTOFRANGE       0x0000138BL

//
// MessageId: PARSE_4_STRINGINCORRECTLYFORMATTED
//
// MessageText:
//
//  String incorrectly formatted.
//
#define PARSE_4_STRINGINCORRECTLYFORMATTED 0x0000138CL

//
// MessageId: PARSE_5_STRINGTOOLONG
//
// MessageText:
//
//  String too long.
//
#define PARSE_5_STRINGTOOLONG            0x0000138DL

//
// MessageId: PARSE_6_MISSINGQUOTE_d
//
// MessageText:
//
//  Unmatched quote following quotation mark at column %1$d.
//
#define PARSE_6_MISSINGQUOTE_d           0x0000138EL

//
// MessageId: PARSE_7_INVALIDHEXDIGIT
//
// MessageText:
//
//  Invalid hex digit.
//
#define PARSE_7_INVALIDHEXDIGIT          0x0000138FL

//
// MessageId: PARSE_8_INVALIDBITDIGIT
//
// MessageText:
//
//  Invalid bit digit.
//
#define PARSE_8_INVALIDBITDIGIT          0x00001390L

//
// MessageId: PARSE_9_WRONGTOKEN
//
// MessageText:
//
//  Wrong token.
//
#define PARSE_9_WRONGTOKEN               0x00001391L

//
// MessageId: SC_1_XMLNONAME
//
// MessageText:
//
//  Current spatial context has no name; cannot write to XML.
//
#define SC_1_XMLNONAME                   0x00001771L

//
// MessageId: SC_2_NOSTATETRANSITION
//
// MessageText:
//
//  Error in SCReadHandler state transition table, no transition after element '%1$ls'.
//
#define SC_2_NOSTATETRANSITION           0x00001772L

//
// MessageId: SC_3_XMLNOEXTENTS
//
// MessageText:
//
//  Current spatial context '%1$ls' has no extents; cannot write to XML.
//
#define SC_3_XMLNOEXTENTS                0x00001773L

//
// MessageId: SC_4_XMLNOREAD
//
// MessageText:
//
//  %1$ls failed: no spatial context has been read from XML.
//
#define SC_4_XMLNOREAD                   0x00001774L

//
// MessageId: SC_5_MISSINGATTRIBUTE
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, required attribute %2$ls/@%3$ls is missing.
//
#define SC_5_MISSINGATTRIBUTE            0x00001775L

//
// MessageId: SC_6_BADATTRIBUTE
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, invalid attribute %2$ls/@%3$ls value '%4$ls'.
//
#define SC_6_BADATTRIBUTE                0x00001776L

//
// MessageId: SC_7_NAMEIDDIFF
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, gml:id '%2$ls' differs from srsName.
//
#define SC_7_NAMEIDDIFF                  0x00001777L

//
// MessageId: SC_8_BADELEMENT
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, invalid %2$ls value '%3$ls'.
//
#define SC_8_BADELEMENT                  0x00001778L

//
// MessageId: SC_9_BADSUBELEMENT
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, unexpected first element %2$ls inside '%3$ls'.
//
#define SC_9_BADSUBELEMENT               0x00001779L

//
// MessageId: SC_10_BADNEXTELEMENT
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, unexpected element %2$ls after '%3$ls'.
//
#define SC_10_BADNEXTELEMENT             0x0000177AL

//
// MessageId: SC_11_MISSINGNEXTELEMENT
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, expected element %2$ls after '%3$ls'.
//
#define SC_11_MISSINGNEXTELEMENT         0x0000177BL

//
// MessageId: SC_12_EMPTYELEMENT
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, element %2$ls has no sub-elements.
//
#define SC_12_EMPTYELEMENT               0x0000177CL

//
// MessageId: SC_13_NAMEIDDIFF
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, gml:baseCRS/fdo:WKTCRS/gml:id '%2$ls' differs from gml:baseCRS/fdo:WKTCRS/srsName.
//
#define SC_13_NAMEIDDIFF                 0x0000EA6DL

//
// MessageId: SC_14_EMPTYBASECRS
//
// MessageText:
//
//  Error reading spatial context %1$ls from XML, gml:baseCRS subelement must have an xlink:href attribute or fdo:WKTCRS subelement.
//
#define SC_14_EMPTYBASECRS               0x0000177EL

//
// MessageId: SC_15_NEEDCALLREADNEXT
//
// MessageText:
//
//  Error reading from feature reader, need to call ReadNext before getting property.
//
#define SC_15_NEEDCALLREADNEXT           0x0000177FL

//
// MessageId: SC_16_INDEXOUTOFBOUND
//
// MessageText:
//
//  Error reading from feature reader, reach end in the feature collection.
//
#define SC_16_INDEXOUTOFBOUND            0x00001780L

//
// MessageId: CLNT_1_NULLINPUTPOINTER
//
// MessageText:
//
//  NULL Input Pointer
//
#define CLNT_1_NULLINPUTPOINTER          0x00001B59L

//
// MessageId: CLNT_2_EMPTYINPUTPARAMETER
//
// MessageText:
//
//  Empty Input Parameter
//
#define CLNT_2_EMPTYINPUTPARAMETER       0x00001B5AL

//
// MessageId: CLNT_3_NULLPOINTER
//
// MessageText:
//
//  NULL Pointer
//
#define CLNT_3_NULLPOINTER               0x00001B5BL

//
// MessageId: CLNT_4_PROVIDERNOTREGISTERED
//
// MessageText:
//
//  FDO Provider Not Registered
//
#define CLNT_4_PROVIDERNOTREGISTERED     0x00001B5CL

//
// MessageId: CLNT_5_OUTOFMEMORY
//
// MessageText:
//
//  Out Of Memory
//
#define CLNT_5_OUTOFMEMORY               0x00001B5DL

//
// MessageId: CLNT_6_INVALIDINPUTPARAMETER
//
// MessageText:
//
//  Invalid Input Parameter
//
#define CLNT_6_INVALIDINPUTPARAMETER     0x00001B5EL

//
// MessageId: CLNT_7_FAILURE
//
// MessageText:
//
//  Action Failed
//
#define CLNT_7_FAILURE                   0x00001B5FL

//
// MessageId: CLNT_8_UNABLE_TO_LOAD_LIBRARY
//
// MessageText:
//
//  Unable to load the FDO Provider: %1$s
//
#define CLNT_8_UNABLE_TO_LOAD_LIBRARY    0x00001B60L

//
// MessageId: CLNT_9_INVALID_PROVIDER_ENTRY_POINT
//
// MessageText:
//
//  FDO Provider entry point function 'CreateConnection' was not found.
//
#define CLNT_9_INVALID_PROVIDER_ENTRY_POINT 0x00001B61L

//
// MessageId: CLNT_10_NULL_CONNECTION_FROM_PROVIDER
//
// MessageText:
//
//  FDO Provider entry point function 'CreateConnection' returned NULL.
//
#define CLNT_10_NULL_CONNECTION_FROM_PROVIDER 0x00001B62L

//
// MessageId: CLNT_11_PARSER_ERROR
//
// MessageText:
//
//  Parser Error
//
#define CLNT_11_PARSER_ERROR             0x00001B63L

//
// MessageId: CLNT_12_FILE_NOT_EXISTS
//
// MessageText:
//
//  File '%1$ls' does not exist
//
#define CLNT_12_FILE_NOT_EXISTS          0x00001B64L

//
// MessageId: CLNT_13_UNKNOWN_MESSAGE
//
// MessageText:
//
//  Unknown message id: %1$d
//
#define CLNT_13_UNKNOWN_MESSAGE          0x00001B65L

//
// MessageId: CLNT_14_XML_ERROR
//
// MessageText:
//
//  Error in registry file '%1$ls', line %2$d: %3$s
//
#define CLNT_14_XML_ERROR                0x00001B66L

//
// MessageId: CLNT_15_XML_WRITE_ERROR
//
// MessageText:
//
//  Error writing to registry file '%1$ls', %2$s
//
#define CLNT_15_XML_WRITE_ERROR          0x00001B67L

//
// MessageId: FUNCTION_CEIL
//
// MessageText:
//
//  Returns the smallest integer greater than or equal to the expression value
//
#define FUNCTION_CEIL                    0x00001F41L

//
// MessageId: FUNCTION_FLOOR
//
// MessageText:
//
//  Returns the largest integer equal to or less than the expression value
//
#define FUNCTION_FLOOR                   0x00001F42L

//
// MessageId: FUNCTION_AVG
//
// MessageText:
//
//  Returns the average value of an expression
//
#define FUNCTION_AVG                     0x00001F43L

//
// MessageId: FUNCTION_COUNT
//
// MessageText:
//
//  Returns the number of objects in the query
//
#define FUNCTION_COUNT                   0x00001F44L

//
// MessageId: FUNCTION_MAX
//
// MessageText:
//
//  Returns the maximum value of an expression
//
#define FUNCTION_MAX                     0x00001F45L

//
// MessageId: FUNCTION_MIN
//
// MessageText:
//
//  Returns the minimum value of an expression
//
#define FUNCTION_MIN                     0x00001F46L

//
// MessageId: FUNCTION_SUM
//
// MessageText:
//
//  Returns the sum of values of an expression
//
#define FUNCTION_SUM                     0x00001F47L

//
// MessageId: FUNCTION_LOWER
//
// MessageText:
//
//  Returns strings with all lowercase letters
//
#define FUNCTION_LOWER                   0x00001F48L

//
// MessageId: FUNCTION_UPPER
//
// MessageText:
//
//  Returns strings with all letters uppercase
//
#define FUNCTION_UPPER                   0x00001F49L

//
// MessageId: FUNCTION_CONCAT
//
// MessageText:
//
//  Returns the string concatenation of 2 expressions
//
#define FUNCTION_CONCAT                  0x00001F4AL

//
// MessageId: FUNCTION_DBL_ARG
//
// MessageText:
//
//  Argument that represents a double
//
#define FUNCTION_DBL_ARG                 0x00001F4BL

//
// MessageId: FUNCTION_INT_ARG
//
// MessageText:
//
//  Argument that represents an integer
//
#define FUNCTION_INT_ARG                 0x00001F4CL

//
// MessageId: FUNCTION_STR_ARG
//
// MessageText:
//
//  Argument that represents a string
//
#define FUNCTION_STR_ARG                 0x00001F4DL

//
// MessageId: FUNCTION_SPATIALEXTENTS
//
// MessageText:
//
//  Returns the spatial extents of values of a geometric expression
//
#define FUNCTION_SPATIALEXTENTS          0x00001F4EL

//
// MessageId: FUNCTION_GEOM_ARG
//
// MessageText:
//
//  Argument that represents a geometry
//
#define FUNCTION_GEOM_ARG                0x00001F4FL

//
// MessageId: FUNCTION_BOOL_ARG
//
// MessageText:
//
//  Argument that represents a boolean
//
#define FUNCTION_BOOL_ARG                0x00001F50L

//
// MessageId: FUNCTION_BYTE_ARG
//
// MessageText:
//
//  Argument that represents a byte
//
#define FUNCTION_BYTE_ARG                0x00001F51L

//
// MessageId: FUNCTION_DT_ARG
//
// MessageText:
//
//  Argument that represents a date-time value
//
#define FUNCTION_DT_ARG                  0x00001F52L

//
// MessageId: FUNCTION_DEC_ARG
//
// MessageText:
//
//  Argument that represents a decimal
//
#define FUNCTION_DEC_ARG                 0x00001F53L

//
// MessageId: FUNCTION_INT16_ARG
//
// MessageText:
//
//  Argument that represents a 16-bit integer
//
#define FUNCTION_INT16_ARG               0x00001F54L

//
// MessageId: FUNCTION_INT32_ARG
//
// MessageText:
//
//  Argument that represents a 32-bit integer
//
#define FUNCTION_INT32_ARG               0x00001F55L

//
// MessageId: FUNCTION_INT64_ARG
//
// MessageText:
//
//  Argument that represents a 64-bit integer
//
#define FUNCTION_INT64_ARG               0x00001F56L

//
// MessageId: FUNCTION_SINGLE_ARG
//
// MessageText:
//
//  Argument that represents a single value
//
#define FUNCTION_SINGLE_ARG              0x00001F57L

//
// MessageId: FUNCTION_BLOB_ARG
//
// MessageText:
//
//  Argument that represents a BLOB value
//
#define FUNCTION_BLOB_ARG                0x00001F58L

//
// MessageId: FUNCTION_CLOB_ARG
//
// MessageText:
//
//  Argument that represents a CLOB value
//
#define FUNCTION_CLOB_ARG                0x00001F59L

//
// MessageId: FUNCTION_ASSOCIATION_ARG
//
// MessageText:
//
//  Argument that represents an association
//
#define FUNCTION_ASSOCIATION_ARG         0x00001F5AL

//
// MessageId: FUNCTION_OBJECT_ARG
//
// MessageText:
//
//  Argument that represents an object
//
#define FUNCTION_OBJECT_ARG              0x00001F5BL

//
// MessageId: FUNCTION_RASTER_ARG
//
// MessageText:
//
//  Argument that represents a raster
//
#define FUNCTION_RASTER_ARG              0x00001F5CL

//
// MessageId: FDO_1_BADALLOC
//
// MessageText:
//
//  Memory allocation failed.
//
#define FDO_1_BADALLOC                   0x00002329L

//
// MessageId: FDO_2_BADPARAMETER
//
// MessageText:
//
//  Bad parameter to method.
//
#define FDO_2_BADPARAMETER               0x0000232AL

//
// MessageId: FDO_3_NOTIMPLEMENTED
//
// MessageText:
//
//  Method is not implemented.
//
#define FDO_3_NOTIMPLEMENTED             0x0000232BL

//
// MessageId: FDO_4_UNREADY
//
// MessageText:
//
//  Data is not in a state to respond to the request.
//
#define FDO_4_UNREADY                    0x0000232CL

//
// MessageId: FDO_5_INDEXOUTOFBOUNDS
//
// MessageText:
//
//  Item index out of bounds.
//
#define FDO_5_INDEXOUTOFBOUNDS           0x0000232DL

//
// MessageId: FDO_6_OBJECTNOTFOUND
//
// MessageText:
//
//  Invalid delete; object not present.
//
#define FDO_6_OBJECTNOTFOUND             0x0000232EL

//
// MessageId: FDO_7_INVALIDFGF
//
// MessageText:
//
//  String is not a valid FGF string.
//
#define FDO_7_INVALIDFGF                 0x0000232FL

//
// MessageId: FDO_8_INCORRECTSTRINGFORMAT
//
// MessageText:
//
//  Parse string is incorrectly formatted.
//
#define FDO_8_INCORRECTSTRINGFORMAT      0x00002330L

//
// MessageId: FDO_9_INVALIDDIGIT
//
// MessageText:
//
//  Invalid digit in number.
//
#define FDO_9_INVALIDDIGIT               0x00002331L

//
// MessageId: FDO_10_UNSUPPORTEDGEOMETRYTYPE
//
// MessageText:
//
//  Unsupported geometry type.
//
#define FDO_10_UNSUPPORTEDGEOMETRYTYPE   0x00002332L

//
// MessageId: FDO_11_INVALIDPOINT
//
// MessageText:
//
//  Invalid point.
//
#define FDO_11_INVALIDPOINT              0x00002333L

//
// MessageId: FDO_12_SHAREDARRAY
//
// MessageText:
//
//  Cannot resize a shared array.
//
#define FDO_12_SHAREDARRAY               0x00002334L

//
// MessageId: FDO_13_INVALIDRESIZE
//
// MessageText:
//
//  Invalid array resize.
//
#define FDO_13_INVALIDRESIZE             0x00002335L

//
// MessageId: FDO_14_NULLSTRING
//
// MessageText:
//
//  Null String.
//
#define FDO_14_NULLSTRING                0x00002336L

//
// MessageId: FDO_15_UNSUPPORTEDGEOMETRYDATA
//
// MessageText:
//
//  Invalid Geometry.
//
#define FDO_15_UNSUPPORTEDGEOMETRYDATA   0x00002337L

//
// MessageId: FDO_17_UNSUPPORTEDDIMENSIONALITY
//
// MessageText:
//
//  Invalid dimensionality.
//
#define FDO_17_UNSUPPORTEDDIMENSIONALITY 0x00002338L

//
// MessageId: FDO_18_DATAPROVIDERFAILURE
//
// MessageText:
//
//  OCI failure.
//
#define FDO_18_DATAPROVIDERFAILURE       0x00002339L

//
// MessageId: FDO_18_FILEOPENFAILURE
//
// MessageText:
//
//  Failed to open file '%1$ls' with access modes: '%2$ls'.
//
#define FDO_18_FILEOPENFAILURE           0x0000233AL

//
// MessageId: FDO_19_STREAMREADERROR
//
// MessageText:
//
//  Cannot read %1$d bytes from unreadable stream.
//
#define FDO_19_STREAMREADERROR           0x0000233BL

//
// MessageId: FDO_20_STREAMWRITEERROR
//
// MessageText:
//
//  Cannot write %1$d bytes to unwritable stream.
//
#define FDO_20_STREAMWRITEERROR          0x0000233CL

//
// MessageId: FDO_21_STREAMWRITEERROR
//
// MessageText:
//
//  Cannot write %1$d bytes to writable stream, only %2$d bytes were written.
//
#define FDO_21_STREAMWRITEERROR          0x0000233DL

//
// MessageId: FDO_22_STREAMSEEKERROR
//
// MessageText:
//
//  Cannot seek on non-seekable stream.
//
#define FDO_22_STREAMSEEKERROR           0x0000233EL

//
// MessageId: FDO_23_STREAMSEEKFAILURE
//
// MessageText:
//
//  Seek on stream failed.
//
#define FDO_23_STREAMSEEKFAILURE         0x0000233FL

//
// MessageId: FDO_24_STREAMBADFP
//
// MessageText:
//
//  Cannot create FdoIoFileStream, bad file pointer.
//
#define FDO_24_STREAMBADFP               0x00002340L

//
// MessageId: FDO_25_STREAMSIZEFAILURE
//
// MessageText:
//
//  Setting length of stream to %1$d bytes failed.
//
#define FDO_25_STREAMSIZEFAILURE         0x00002341L

//
// MessageId: FDO_26_BUFFEROVERWRITEERROR
//
// MessageText:
//
//  Cannot write %1$lld bytes to buffer with %2$lld bytes remaining.
//
#define FDO_26_BUFFEROVERWRITEERROR      0x00002342L

//
// MessageId: FDO_27_BUFFERLENGTHERROR
//
// MessageText:
//
//  Cannot change length of fixed buffer stream.
//
#define FDO_27_BUFFERLENGTHERROR         0x00002343L

//
// MessageId: FDO_28_UTF8FAILURE
//
// MessageText:
//
//  Unicode to UTF8 conversion failed for string '%1$ls'.
//
#define FDO_28_UTF8FAILURE               0x00002344L

//
// MessageId: FDO_29_UNICODEFAILURE
//
// MessageText:
//
//  UTF8 to Unicode conversion failed for string '%1$s'.
//
#define FDO_29_UNICODEFAILURE            0x00002345L

//
// MessageId: FDO_30_BADPARAM
//
// MessageText:
//
//  Bad %1$ls value '%2$ls' passed to %3$ls.
//
#define FDO_30_BADPARAM                  0x00002346L

//
// MessageId: FDO_31_ENDELEMENTERROR
//
// MessageText:
//
//  FdoXmlWriter::EndElement: there is no current element to end.
//
#define FDO_31_ENDELEMENTERROR           0x00002347L

//
// MessageId: FDO_32_XMLATTRIBUTEERROR
//
// MessageText:
//
//  Cannot add attribute %1$ls; tag for element %2$ls is no longer open.
//
#define FDO_32_XMLATTRIBUTEERROR         0x00002348L

//
// MessageId: FDO_33_XMLPARSEERROR
//
// MessageText:
//
//  XML Document parse error at line %1$d column %2$d: %3$ls
//
#define FDO_33_XMLPARSEERROR             0x00002349L

//
// MessageId: FDO_34_MEMORYSTREAMOVERFLOW
//
// MessageText:
//
//  %1$ls: Maximum length for a %2$ls exceeded, please increase buffer size (currently %3$d)
//
#define FDO_34_MEMORYSTREAMOVERFLOW      0x0000234AL

//
// MessageId: FDO_35_FILENOCONTEXT
//
// MessageText:
//
//  Stream is not contextual (has no absolute position); %1$ls::%2$ls cannot be called
//
#define FDO_35_FILENOCONTEXT             0x0000234BL

//
// MessageId: FDO_36_STREAMINDEXALIGN
//
// MessageText:
//
//  %1$ls::%2$ls cannot be called when file size exceeds %3$d bytes (current size: %4$d bytes)
//
#define FDO_36_STREAMINDEXALIGN          0x0000234CL

//
// MessageId: FDO_37_FILEFLUSH
//
// MessageText:
//
//  %1$ls: failed to flush file
//
#define FDO_37_FILEFLUSH                 0x0000234DL

//
// MessageId: FDO_38_ITEMNOTFOUND
//
// MessageText:
//
//  Item '%1$ls' not found in collection
//
#define FDO_38_ITEMNOTFOUND              0x0000234EL

//
// MessageId: FDO_39_STACKPOP
//
// MessageText:
//
//  Stack is empty, cannot pop.
//
#define FDO_39_STACKPOP                  0x0000234FL

//
// MessageId: FDO_40_BADXMLELEMENT
//
// MessageText:
//
//  Element '%1$ls' is not a valid XML 1.0 element name.
//
#define FDO_40_BADXMLELEMENT             0x00002350L

//
// MessageId: FDO_41_BADXMLATTRIBUTE
//
// MessageText:
//
//  Attribute '%1$ls' is not a valid XML 1.0 attribute name.
//
#define FDO_41_BADXMLATTRIBUTE           0x00002351L

//
// MessageId: FDO_42_GENERICCHAR
//
// MessageText:
//
//  %1$ls
//
#define FDO_42_GENERICCHAR               0x00002352L

//
// MessageId: FDO_43_XSLERROR
//
// MessageText:
//
//  XSL Error at line %1$d column %2$d: %3$ls.
//
#define FDO_43_XSLERROR                  0x00002353L

//
// MessageId: FDO_44_BADDEFAULTROOT
//
// MessageText:
//
//  Cannot change default root setting for FdoXmlWriter; root element has already been written.
//
#define FDO_44_BADDEFAULTROOT            0x00002354L

//
// MessageId: FDO_45_ITEMINCOLLECTION
//
// MessageText:
//
//  Item %1$ls is already in this named collection.
//
#define FDO_45_ITEMINCOLLECTION          0x00002355L

//
// MessageId: FDO_46_REMAININGSTREAMSIZE
//
// MessageText:
//
//  %1$ls: Cannot read remainder of stream, there are more than %$2d items remaining.
//
#define FDO_46_REMAININGSTREAMSIZE       0x00002356L

//
// MessageId: FDO_47_READARRAYSIZE
//
// MessageText:
//
//  %1$ls: FdoArray is too small to read %2$d items from stream.
//
#define FDO_47_READARRAYSIZE             0x00002357L

//
// MessageId: FDO_48_NOCONTENTELEMENT
//
// MessageText:
//
//  %1$ls called when there is no open element; content is '%2$ls'.
//
#define FDO_48_NOCONTENTELEMENT          0x00002358L

//
// MessageId: FDO_49_MULTIROOTELEMENT
//
// MessageText:
//
//  %1$ls: cannot write second root element '%2$ls' to XML document.
//
#define FDO_49_MULTIROOTELEMENT          0x00002359L

//
// MessageId: FDO_50_XMLTRANSCODEFAILED
//
// MessageText:
//
//  %1$ls: %2$ls failed.
//
#define FDO_50_XMLTRANSCODEFAILED        0x0000235AL

//
// MessageId: FDO_51_SETFILESIZE
//
// MessageText:
//
//  Cannot change file size to %1$d Windows; maximum is %2$d
//
#define FDO_51_SETFILESIZE               0x0000235BL

//
// MessageId: FDO_52_BADSUBELEMENT
//
// MessageText:
//
//  Error reading from XML, unexpected element %1$ls inside '%2$ls'.
//
#define FDO_52_BADSUBELEMENT             0x0000235CL

//
// MessageId: FDO_53_NESTEDXMLPARSEERROR
//
// MessageText:
//
//  Nested call to FdoXmlReader::Parse() attempted.
//
#define FDO_53_NESTEDXMLPARSEERROR       0x0000235DL

//
// MessageId: FDO_54_XMLINPUTEOF
//
// MessageText:
//
//  Cannot parse XML document whose stream is at end-of-file.
//
#define FDO_54_XMLINPUTEOF               0x0000235EL

//
// MessageId: FDO_55_XSLINPUTEOF
//
// MessageText:
//
//  Cannot XSL Transform XML document whose stream is at end-of-file.
//
#define FDO_55_XSLINPUTEOF               0x0000235FL

//
// MessageId: FDO_56_XSLSTYLESHEETEOF
//
// MessageText:
//
//  Cannot read XSL stylesheet whose stream is at end-of-file.
//
#define FDO_56_XSLSTYLESHEETEOF          0x00002360L

//
// MessageId: FDO_57_UNEXPECTEDERROR
//
// MessageText:
//
//  Unexpected error encountered.
//
#define FDO_57_UNEXPECTEDERROR           0x00002361L

//
// MessageId: FDO_58_READERHASNODATA
//
// MessageText:
//
//  End of reader data or ReadNext not called.
//
#define FDO_58_READERHASNODATA           0x00002362L

//
// MessageId: FDO_59_CANNOTFETCHNULLVALUE
//
// MessageText:
//
//  Cannot fetch NULL value.
//
#define FDO_59_CANNOTFETCHNULLVALUE      0x00002363L

//
// MessageId: FDO_60_NULL_POINTER
//
// MessageText:
//
//  Unexpected NULL pointer.
//
#define FDO_60_NULL_POINTER              0x00002364L

//
// MessageId: FDO_61_NULL_ARGUMENT
//
// MessageText:
//
//  A required argument was set to NULL.
//
#define FDO_61_NULL_ARGUMENT             0x00002365L

//
// MessageId: FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH
//
// MessageText:
//
//  Fetching a property value did not match the property type.
//
#define FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH 0x00002366L

//
// MessageId: FDO_63_CONNECTION_INVALID
//
// MessageText:
//
//  Connection is invalid.
//
#define FDO_63_CONNECTION_INVALID        0x00002367L

//
// MessageId: FDO_64_CONNECTION_REQUIRED_PROPERTY_NULL
//
// MessageText:
//
//  The required property '%1$ls' cannot be set to NULL.
//
#define FDO_64_CONNECTION_REQUIRED_PROPERTY_NULL 0x00002368L

//
// MessageId: FDO_65_CONNECTION_ENUM_PROPERTY_WRONG_VALUE
//
// MessageText:
//
//  The given value '%1$ls' for enumerable property '%2$ls' is not in the enumeration value collection.
//
#define FDO_65_CONNECTION_ENUM_PROPERTY_WRONG_VALUE 0x00002369L

//
// MessageId: FDO_66_CONNECTION_PROPERTY_NOT_FOUND
//
// MessageText:
//
//  The connection property '%1$ls' was not found.
//
#define FDO_66_CONNECTION_PROPERTY_NOT_FOUND 0x0000236AL

//
// MessageId: FDO_67_CONNECTION_TIMEOUT_NOT_SUPPORTED
//
// MessageText:
//
//  Connection timeout is not supported.
//
#define FDO_67_CONNECTION_TIMEOUT_NOT_SUPPORTED 0x0000236BL

//
// MessageId: FDO_68_COMMAND_PARAMETERS_NOT_SUPPORTED
//
// MessageText:
//
//  Command parameters are not supported.
//
#define FDO_68_COMMAND_PARAMETERS_NOT_SUPPORTED 0x0000236CL

//
// MessageId: FDO_69_PROPERTY_NOT_AVAILABLE
//
// MessageText:
//
//  The requested property is not available.
//
#define FDO_69_PROPERTY_NOT_AVAILABLE    0x0000236DL

//
// MessageId: FDO_70_PROPERTY_TYPE_NOT_SUPPORTED
//
// MessageText:
//
//  The property type '%1$ls' is not supported by this provider.
//
#define FDO_70_PROPERTY_TYPE_NOT_SUPPORTED 0x0000236EL

//
// MessageId: FDO_71_DATA_TYPE_NOT_SUPPORTED
//
// MessageText:
//
//  The data type '%1$ls' is not supported by this provider.
//
#define FDO_71_DATA_TYPE_NOT_SUPPORTED   0x0000236FL

//
// MessageId: FDO_72_LOB_DATA_TYPE_NOT_SUPPORTED
//
// MessageText:
//
//  The BLOB and CLOB data types are not supported by this provider.
//
#define FDO_72_LOB_DATA_TYPE_NOT_SUPPORTED 0x00002370L

//
// MessageId: FDO_73_PROPERTY_INDEXOUTOFBOUNDS
//
// MessageText:
//
//  Property index '%1$d' is out of bounds.
//
#define FDO_73_PROPERTY_INDEXOUTOFBOUNDS 0x00002371L

//
// MessageId: FDO_74_PROPERTY_NAME_NOT_FOUND
//
// MessageText:
//
//  The property '%1$ls' was not found.
//
#define FDO_74_PROPERTY_NAME_NOT_FOUND   0x00002372L

//
// MessageId: FDO_75_INVALID_NUM_ARGUMENTS
//
// MessageText:
//
//  Invalid number of arguments to function '%1$ls'; expected %2$d argument(s), got %3$d instead.
//
#define FDO_75_INVALID_NUM_ARGUMENTS     0x00002373L

//
// MessageId: FDO_76_CLASS_NAME_NOT_FOUND
//
// MessageText:
//
//  The class '%1$ls' was not found.
//
#define FDO_76_CLASS_NAME_NOT_FOUND      0x00002374L

//
// MessageId: FDO_77_ORDERBY_INVALID_TYPE
//
// MessageText:
//
//  The data type '%1$ls' cannot be used with Order By.
//
#define FDO_77_ORDERBY_INVALID_TYPE      0x00002375L

//
// MessageId: FDO_78_AGGREGATE_IN_AGGREGATE_FUNCTION
//
// MessageText:
//
//  Aggregate functions cannot contain aggregate functions as their arguments.
//
#define FDO_78_AGGREGATE_IN_AGGREGATE_FUNCTION 0x00002376L

//
// MessageId: FDO_79_AGGREGATE_INVALID_MIX
//
// MessageText:
//
//  Invalid combination of aggregate functions and non-aggregate expressions.
//
#define FDO_79_AGGREGATE_INVALID_MIX     0x00002377L

//
// MessageId: FDO_80_INVALID_EXPRESSION
//
// MessageText:
//
//  Invalid expression; expression types incompatible.
//
#define FDO_80_INVALID_EXPRESSION        0x00002378L

//
// MessageId: FDO_81_IDENTIFIER_NOT_FOUND
//
// MessageText:
//
//  The identifier '%1$ls' was not recognized.
//
#define FDO_81_IDENTIFIER_NOT_FOUND      0x00002379L

//
// MessageId: FDO_82_UNSUPPORTED_LOGICAL_OPERATION
//
// MessageText:
//
//  Unsupported FDO logical operation.
//
#define FDO_82_UNSUPPORTED_LOGICAL_OPERATION 0x0000237AL

//
// MessageId: FDO_83_UNSUPPORTED_COMPARISON_OPERATION
//
// MessageText:
//
//  Unsupported FDO comparison operation.
//
#define FDO_83_UNSUPPORTED_COMPARISON_OPERATION 0x0000237BL

//
// MessageId: FDO_84_SPATIAL_CONDITION_NOT_LITERAL_GEOMETRY
//
// MessageText:
//
//  Only literal geometric values are allowed in spatial conditions.
//
#define FDO_84_SPATIAL_CONDITION_NOT_LITERAL_GEOMETRY 0x0000237CL

//
// MessageId: FDO_85_DISTANCE_SPATIAL_CONDITION_NOT_SUPPORTED
//
// MessageText:
//
//  The Distance spatial condition is not supported by this provider.
//
#define FDO_85_DISTANCE_SPATIAL_CONDITION_NOT_SUPPORTED 0x0000237DL

//
// MessageId: FDO_86_UNSUPPORTED_BINARY_OPERATION
//
// MessageText:
//
//  Unsupported FDO binary operation.
//
#define FDO_86_UNSUPPORTED_BINARY_OPERATION 0x0000237EL

//
// MessageId: FDO_87_UNSUPPORTED_UNARY_OPERATION
//
// MessageText:
//
//  Unsupported FDO unary operation.
//
#define FDO_87_UNSUPPORTED_UNARY_OPERATION 0x0000237FL

//
// MessageId: FDO_88_INVALID_FUNCTION_ARG_TYPE
//
// MessageText:
//
//  Argument number %1$d to function '%2$ls' was of type '%3$ls', expected type '%4$ls'.
//
#define FDO_88_INVALID_FUNCTION_ARG_TYPE 0x00002380L

//
// MessageId: FDO_89_UNSUPPORTED_FUNCTION
//
// MessageText:
//
//  The function '%1$ls' is not supported by this provider.
//
#define FDO_89_UNSUPPORTED_FUNCTION      0x00002381L

//
// MessageId: FDO_90_GEOMETRY_VALUES_IN_FILTER_UNSUPPORTED
//
// MessageText:
//
//  Geometry values in filters are not supported by this provider.
//
#define FDO_90_GEOMETRY_VALUES_IN_FILTER_UNSUPPORTED 0x00002382L

//
// MessageId: FDO_91_FILE_NOT_FOUND
//
// MessageText:
//
//  The file '%1$ls' was not found.
//
#define FDO_91_FILE_NOT_FOUND            0x00002383L

//
// MessageId: FDO_92_PATH_NOT_FOUND
//
// MessageText:
//
//  The path to file '%1$ls' was not found.
//
#define FDO_92_PATH_NOT_FOUND            0x00002384L

//
// MessageId: FDO_93_TOO_MANY_OPEN_FILES
//
// MessageText:
//
//  Already too many open files when opening file '%1$ls'.
//
#define FDO_93_TOO_MANY_OPEN_FILES       0x00002385L

//
// MessageId: FDO_94_ACCESS_DENIED
//
// MessageText:
//
//  Access to file '%1$ls' was denied.
//
#define FDO_94_ACCESS_DENIED             0x00002386L

//
// MessageId: FDO_95_FILE_IO_ERROR
//
// MessageText:
//
//  File '%1$ls' I/O error in context '%2$ls': %3$ls
//
#define FDO_95_FILE_IO_ERROR             0x00002387L

//
// MessageId: FDO_96_READ_ONLY
//
// MessageText:
//
//  Location for file '%1$ls' is read-only.
//
#define FDO_96_READ_ONLY                 0x00002388L

//
// MessageId: FDO_97_CANNOT_SET_READONLY_PROPERTY
//
// MessageText:
//
//  Property '%1$ls' cannot be set because it is read-only.
//
#define FDO_97_CANNOT_SET_READONLY_PROPERTY 0x00002389L

//
// MessageId: FDO_98_MISSING_DEFAULT_VALUE
//
// MessageText:
//
//  Read-only property '%1$ls' requires a default value.
//
#define FDO_98_MISSING_DEFAULT_VALUE     0x0000238AL

//
// MessageId: FDO_99_CANNOT_DEFAULT_READONLY_PROPERTY
//
// MessageText:
//
//  Read-only identity property '%1$ls' cannot have a default value.
//
#define FDO_99_CANNOT_DEFAULT_READONLY_PROPERTY 0x0000238BL

//
// MessageId: FDO_100_COMMAND_TIMEOUT_NOT_SUPPORTED
//
// MessageText:
//
//  Command timeout is not supported.
//
#define FDO_100_COMMAND_TIMEOUT_NOT_SUPPORTED 0x0000238CL

//
// MessageId: FDO_101_TRANSACTIONS_NOT_SUPPORTED
//
// MessageText:
//
//  Transactions are not supported.
//
#define FDO_101_TRANSACTIONS_NOT_SUPPORTED 0x0000238DL

//
// MessageId: FDO_102_COMMAND_NOT_SUPPORTED
//
// MessageText:
//
//  The command '%1$ls' is not supported.
//
#define FDO_102_COMMAND_NOT_SUPPORTED    0x0000238EL

//
// MessageId: FDO_103_CONNECTION_ALREADY_OPEN
//
// MessageText:
//
//  The connection is already open.
//
#define FDO_103_CONNECTION_ALREADY_OPEN  0x0000238FL

//
// MessageId: FDO_104_READER_PROPERTY_NOT_SELECTED
//
// MessageText:
//
//  The property '%1$ls' is not in the reader's selected property set.
//
#define FDO_104_READER_PROPERTY_NOT_SELECTED 0x00002390L

//
// MessageId: FDO_105_UNSUPPORTED_SPATIAL_OPERATION
//
// MessageText:
//
//  Unsupported FDO spatial operation.
//
#define FDO_105_UNSUPPORTED_SPATIAL_OPERATION 0x00002391L

//
// MessageId: FDO_106_LOB_NOT_SUPPORTED_IN_FILTER
//
// MessageText:
//
//  LOB objects not supported in the FDO Filter.
//
#define FDO_106_LOB_NOT_SUPPORTED_IN_FILTER 0x00002392L

//
// MessageId: FDO_107_PARAEMETRS_NOT_SUPPORTED_IN_FILTER
//
// MessageText:
//
//  Parameters not supported in the FDO Filter.
//
#define FDO_107_PARAEMETRS_NOT_SUPPORTED_IN_FILTER 0x00002393L

//
// MessageId: FDO_108_INVALID_FDO_IN_CONDITION
//
// MessageText:
//
//  Invalid FDO In condition.
//
#define FDO_108_INVALID_FDO_IN_CONDITION 0x00002394L

//
// MessageId: FDO_109_INVALID_FDO_COMPARISON_CONDITION
//
// MessageText:
//
//  Invalid FDO In condition.
//
#define FDO_109_INVALID_FDO_COMPARISON_CONDITION 0x00002395L

//
// MessageId: FDO_110_PROPERTY_NOT_NULLABLE
//
// MessageText:
//
//  The property '%1$ls' cannot be set to NULL.
//
#define FDO_110_PROPERTY_NOT_NULLABLE    0x00002396L

//
// MessageId: FDO_111_PROPERTY_RANGE_CONSTRAINT_VIOLATED
//
// MessageText:
//
//  The property '%1$ls' range constraint (%2$ls) is violated by value %3$ls.
//
#define FDO_111_PROPERTY_RANGE_CONSTRAINT_VIOLATED 0x00002397L

//
// MessageId: FDO_112_PROPERTY_LIST_CONSTRAINT_VIOLATED
//
// MessageText:
//
//  The property '%1$ls' list constraint (%2$ls) is violated by value %3$ls.
//
#define FDO_112_PROPERTY_LIST_CONSTRAINT_VIOLATED 0x00002398L

//
// MessageId: FDO_113_PROPERTY_UNKNOWN_CONSTRAINT_VIOLATED
//
// MessageText:
//
//  The property '%1$ls' unknown constraint is violated by value %2$ls.
//
#define FDO_113_PROPERTY_UNKNOWN_CONSTRAINT_VIOLATED 0x00002399L

//
// MessageId: FDO_114_XSL_LOG_ERROR
//
// MessageText:
//
//  ERROR
//
#define FDO_114_XSL_LOG_ERROR            0x0000239AL

//
// MessageId: FDO_115_XSL_LOG_WARNING
//
// MessageText:
//
//  WARNING
//
#define FDO_115_XSL_LOG_WARNING          0x0000239BL

//
// MessageId: FDO_116_XSL_LOG_MESSAGE
//
// MessageText:
//
//  MESSAGE
//
#define FDO_116_XSL_LOG_MESSAGE          0x0000239CL

//
// MessageId: FDO_117_XSL_LOG_ORIGINATOR_XMLPARSER
//
// MessageText:
//
//  XML Parser
//
#define FDO_117_XSL_LOG_ORIGINATOR_XMLPARSER 0x0000239DL

//
// MessageId: FDO_118_XSL_LOG_ORIGINATOR_XSLPROCESSOR
//
// MessageText:
//
//  XSL Processor
//
#define FDO_118_XSL_LOG_ORIGINATOR_XSLPROCESSOR 0x0000239EL

//
// MessageId: FDO_119_XSL_LOG_ORIGINATOR_XPATH
//
// MessageText:
//
//  XPath
//
#define FDO_119_XSL_LOG_ORIGINATOR_XPATH 0x0000239FL

//
// MessageId: FDO_120_XSL_LOG_ORIGINATOR_UNKNOWN
//
// MessageText:
//
//  Unknown originator
//
#define FDO_120_XSL_LOG_ORIGINATOR_UNKNOWN 0x000023A0L

//
// MessageId: FDO_121_XSL_ATSOURCENODE
//
// MessageText:
//
//  At source node '%1$ls'
//
#define FDO_121_XSL_ATSOURCENODE         0x000023A1L

//
// MessageId: FDO_122_XSL_ATURI
//
// MessageText:
//
//  at URI '%1$ls' (line %2$d, column %3$d)
//
#define FDO_122_XSL_ATURI                0x000023A2L

//
// MessageId: FDO_123_NOATTRIBUTEELEMENT
//
// MessageText:
//
//  %1$ls called when there is no open element; cannot write attribute '%2$ls'.
//
#define FDO_123_NOATTRIBUTEELEMENT       0x000023A3L

//
// MessageId: FDO_124_BYTESAFTERCLOSE
//
// MessageText:
//
//  %1$ls called after document closed; cannot write bytes.
//
#define FDO_124_BYTESAFTERCLOSE          0x000023A4L

//
// MessageId: FDO_125_SCHEMA_ALREADY_EXISTS
//
// MessageText:
//
//  The schema '%1$ls' already exists.
//
#define FDO_125_SCHEMA_ALREADY_EXISTS    0x000023A5L

//
// MessageId: FDO_126_CLASS_ALREADY_EXISTS
//
// MessageText:
//
//  The class '%1$ls' already exists.
//
#define FDO_126_CLASS_ALREADY_EXISTS     0x000023A6L

//
// MessageId: FDO_127_PROPERTY_ALREADY_EXISTS
//
// MessageText:
//
//  The property '%1$ls' already exists.
//
#define FDO_127_PROPERTY_ALREADY_EXISTS  0x000023A7L

//
// MessageId: FDO_128_GEOMETRY_MAPPING_ERROR
//
// MessageText:
//
//  The provided input is invalid for the current mapping process.
//
#define FDO_128_GEOMETRY_MAPPING_ERROR   0x000023A8L

//
// MessageId: FDO_129_PROPERTY_TYPE_NOT_SUPPORTED_BY_OPERATION
//
// MessageText:
//
//  The property type '%1$ls' is not supported by this operation.
//
#define FDO_129_PROPERTY_TYPE_NOT_SUPPORTED_BY_OPERATION 0x000023A9L

//
// MessageId: FDO_130_DATA_TYPE_NOT_SUPPORTED_BY_OPERATION
//
// MessageText:
//
//  The data type '%1$ls' is not supported by this operation.
//
#define FDO_130_DATA_TYPE_NOT_SUPPORTED_BY_OPERATION 0x000023AAL

//
// MessageId: FDO_131_UNSUPPORTED_GEOMETRY_TYPE
//
// MessageText:
//
//  The '%1$ls' geometry type (or combination of types) is not supported.
//
#define FDO_131_UNSUPPORTED_GEOMETRY_TYPE 0x000023ABL

//
// MessageId: FDO_132_CONNECTION_BROKEN
//
// MessageText:
//
//  Network connection is broken, or the server stopped responding.
//
#define FDO_132_CONNECTION_BROKEN        0x000023ACL

//
// MessageId: FDO_133_UNEXPECTEDERROR_PERFORMING
//
// MessageText:
//
//  Unexpected error encountered while accessing the server.
//
#define FDO_133_UNEXPECTEDERROR_PERFORMING 0x000023ADL

//
// MessageId: FDO_134_SPATIAL_CONTEXT_ERROR_DEFAULT_EXISTS
//
// MessageText:
//
//  '%1$ls': Default spatial context exists; Cannot create spatial context info.
//
#define FDO_134_SPATIAL_CONTEXT_ERROR_DEFAULT_EXISTS 0x000023AEL

//
// MessageId: FDO_135_SPATIAL_CONTEXT_ERROR_ID_MISSMATCH
//
// MessageText:
//
//  '%1$ls': The spatial context ids don't match.
//
#define FDO_135_SPATIAL_CONTEXT_ERROR_ID_MISSMATCH 0x000023AFL

//
// MessageId: FDO_136_SPATIAL_CONTEXT_ERROR_UNKNOWN_EXTENT_TYPE
//
// MessageText:
//
//  '%1$ls': Unknown extent type.
//
#define FDO_136_SPATIAL_CONTEXT_ERROR_UNKNOWN_EXTENT_TYPE 0x000023B0L

//
// MessageId: FDO_137_NAMED_COLLECTION_INDEX_NAME_ERROR
//
// MessageText:
//
//  '%1$ls': Cannot find index in Named Collection for unspecified name (NULL).
//
#define FDO_137_NAMED_COLLECTION_INDEX_NAME_ERROR 0x000023B1L

//
// MessageId: FDO_138_MBC_ERROR_ROOT_CELL
//
// MessageText:
//
//  '%1$ls': Invalid MBC format: missing root cell.
//
#define FDO_138_MBC_ERROR_ROOT_CELL      0x000023B2L

//
// MessageId: FDO_139_MBC_ERROR_ILLEGAL_CHAR
//
// MessageText:
//
//  '%1$ls': Invalid MBC format: illegal character.
//
#define FDO_139_MBC_ERROR_ILLEGAL_CHAR   0x000023B3L

//
// MessageId: FDO_140_MBC_ERROR_SKIP
//
// MessageText:
//
//  '%1$ls': MBC error: too many skip characters specified.
//
#define FDO_140_MBC_ERROR_SKIP           0x000023B4L

//
// MessageId: FDO_141_MBC_ERROR_MAX_DEPTH
//
// MessageText:
//
//  '%1$ls': MBC error: depth exceeds maximum depth.
//
#define FDO_141_MBC_ERROR_MAX_DEPTH      0x000023B5L

//
// MessageId: FDO_142_MBC_ERROR_EXTENTS
//
// MessageText:
//
//  '%1$ls': MBC error: extents outside spatial index extents.
//
#define FDO_142_MBC_ERROR_EXTENTS        0x000023B6L

//
// MessageId: FDO_143_URL_ERROR
//
// MessageText:
//
//  The requested URL returned error: '%1$ls'.
//
#define FDO_143_URL_ERROR                0x000023B7L

//
// MessageId: FDO_144_URL_SERVICE_UNAVAILABLE
//
// MessageText:
//
//  The HTTP service is unavailable.
//
#define FDO_144_URL_SERVICE_UNAVAILABLE  0x000023B8L

//
// MessageId: FDO_145_URL_BAD_REQUEST
//
// MessageText:
//
//  The HTTP request could not be understood by the server due to malformed syntax.
//
#define FDO_145_URL_BAD_REQUEST          0x000023B9L

//
// MessageId: FDO_146_URL_NOT_AUTHORIZED
//
// MessageText:
//
//  The HTTP request is missing user authentication or the user authorization has been refused by the server. 
//
#define FDO_146_URL_NOT_AUTHORIZED       0x000023BAL

//
// MessageId: FDO_147_URL_ACCESS_DENIED
//
// MessageText:
//
//  The HTTP request was denied (forbidden) by the server. 
//
#define FDO_147_URL_ACCESS_DENIED        0x000023BBL

//
// MessageId: FDO_148_URI_NOT_FOUND
//
// MessageText:
//
//  The HTTP request URI was not found by the server.
//
#define FDO_148_URI_NOT_FOUND            0x000023BCL

//
// MessageId: FDO_149_URL_REQUEST_NOT_ALLOWED
//
// MessageText:
//
//  The method specified in the HTTP request is not allowed for the resource identified by the URI.
//
#define FDO_149_URL_REQUEST_NOT_ALLOWED  0x000023BDL

//
// MessageId: FDO_150_URL_REQUEST_NOT_ACCEPTABLE
//
// MessageText:
//
//  The HTTP request generated an unaceptable response by the server.
//
#define FDO_150_URL_REQUEST_NOT_ACCEPTABLE 0x000023BEL

//
// MessageId: FDO_151_URL_PROXY_AUTHENTICATION_REQUIRED
//
// MessageText:
//
//  The client is not authorized to access the HTTP Proxy Server.
//
#define FDO_151_URL_PROXY_AUTHENTICATION_REQUIRED 0x000023BFL

//
// MessageId: FDO_152_URL_REQUEST_TIMEOUT
//
// MessageText:
//
//  HTTP server timeout. The client did not produce a request within the time that the server allowed.
//
#define FDO_152_URL_REQUEST_TIMEOUT      0x000023C0L

//
// MessageId: FDO_153_URL_NOT_AVAILABLE
//
// MessageText:
//
//  The requested HTTP resource is no longer available at the server.
//
#define FDO_153_URL_NOT_AVAILABLE        0x000023C1L

//
// MessageId: FDO_154_URL_REQUEST_TOO_LONG
//
// MessageText:
//
//  The HTTP server is refusing to service the request because the Request-URI is longer than the server is willing to interpret.
//
#define FDO_154_URL_REQUEST_TOO_LONG     0x000023C2L

//
// MessageId: FDO_155_URL_INTERNAL_SERVER_ERROR
//
// MessageText:
//
//  The HTTP server encountered an unexpected internal condition which prevented it from fulfilling the request.
//
#define FDO_155_URL_INTERNAL_SERVER_ERROR 0x000023C3L

//
// MessageId: FDO_156_URL_REQUEST_NOT_IMPLEMENTED
//
// MessageText:
//
//  The HTTP server does not support the functionality required to fulfill the request.
//
#define FDO_156_URL_REQUEST_NOT_IMPLEMENTED 0x000023C4L

//
// MessageId: FDO_157_URL_OVERLOADED
//
// MessageText:
//
//  The HTTP server, while acting as a gateway or proxy, received an invalid response from the upstream server it accessed in attempting to fulfill the request. 
//
#define FDO_157_URL_OVERLOADED           0x000023C5L

//
// MessageId: FDO_158_URL_SERVICE_UNAVAILABLE
//
// MessageText:
//
//  The HTTP server is currently unable to handle the request due to a temporary overloading or maintenance of the server. 
//
#define FDO_158_URL_SERVICE_UNAVAILABLE  0x000023C6L

//
// MessageId: FDO_159_URL_GATEWAY_TIMEOUT
//
// MessageText:
//
//  The HTTP server, while acting as a gateway or proxy, did not receive a timely response from the upstream server specified by the URI. 
//
#define FDO_159_URL_GATEWAY_TIMEOUT      0x000023C7L

//
// MessageId: FDO_160_HTTP_UNSUPPORTED_VERION
//
// MessageText:
//
//  The server does not support, or refuses to support, the HTTP protocol version that was used in the request message.
//
#define FDO_160_HTTP_UNSUPPORTED_VERION  0x000023C8L

//
// MessageId: FDO_161_UNABLE_CONNECT_HOST
//
// MessageText:
//
//  Unable to connect to the host.
//
#define FDO_161_UNABLE_CONNECT_HOST      0x000023C9L

//
// MessageId: FDO_162_CONNECT_HOST_TIMEOUT
//
// MessageText:
//
//  The connection to the host has timed out.
//
#define FDO_162_CONNECT_HOST_TIMEOUT     0x000023CAL

//
// MessageId: FDO_163_UNABLE_RESOLVE_HOST
//
// MessageText:
//
//  Unable to resolve the host. Host not found.
//
#define FDO_163_UNABLE_RESOLVE_HOST      0x000023CBL

//
// MessageId: FDO_164_UNSUPPORTED_HTTP_PROTOCOL
//
// MessageText:
//
//  Unsupported HTTP Protocol.
//
#define FDO_164_UNSUPPORTED_HTTP_PROTOCOL 0x000023CCL

//
// MessageId: FDO_165_MALFORMED_URL
//
// MessageText:
//
//  Malformed URL.
//
#define FDO_165_MALFORMED_URL            0x000023CDL

//
// MessageId: FDO_166_UNABLE_RESOLVE_PROXY
//
// MessageText:
//
//  Couldn't resolve proxy name.
//
#define FDO_166_UNABLE_RESOLVE_PROXY     0x000023CEL

//
// MessageId: FDO_167_DOWNLOAD_PARTIAL_FILE
//
// MessageText:
//
//  Downloaded a partial file.
//
#define FDO_167_DOWNLOAD_PARTIAL_FILE    0x000023CFL

//
// MessageId: FDO_168_FAILURE_OPEN_FILE
//
// MessageText:
//
//  Could not open/read from file.
//
#define FDO_168_FAILURE_OPEN_FILE        0x000023D0L

//
// MessageId: FDO_169_FAILURE_POST
//
// MessageText:
//
//  Failure to HTTP POST data.
//
#define FDO_169_FAILURE_POST             0x000023D1L

//
// MessageId: FDO_170_FAILURE_SSL_CONNECT
//
// MessageText:
//
//  Server SSL connect error.
//
#define FDO_170_FAILURE_SSL_CONNECT      0x000023D2L

//
// MessageId: FDO_171_UNABLE_RESUME_DOWNLOAD
//
// MessageText:
//
//  Could not resume data download.
//
#define FDO_171_UNABLE_RESUME_DOWNLOAD   0x000023D3L

//
// MessageId: FDO_172_ABORTED_BY_CALLBACK
//
// MessageText:
//
//  The operation was aborted by an application callback.
//
#define FDO_172_ABORTED_BY_CALLBACK      0x000023D4L

//
// MessageId: FDO_173_ENDLESS_URL_REDIRECT
//
// MessageText:
//
//  The number of URL redirects hit the maximum amount.
//
#define FDO_173_ENDLESS_URL_REDIRECT     0x000023D5L

//
// MessageId: FDO_174_SSL_PEER_CERTIFICATE
//
// MessageText:
//
//  The SSL peer certificate was not ok.
//
#define FDO_174_SSL_PEER_CERTIFICATE     0x000023D6L

//
// MessageId: FDO_175_SERVER_RETURNED_NOTHING
//
// MessageText:
//
//  The server returned no data.
//
#define FDO_175_SERVER_RETURNED_NOTHING  0x000023D7L

//
// MessageId: FDO_176_FAILURE_SENDING_NETWORK_DATA
//
// MessageText:
//
//  Failure sending Network data.
//
#define FDO_176_FAILURE_SENDING_NETWORK_DATA 0x000023D8L

//
// MessageId: FDO_177_FAILURE_RECIEVING_NETWORK_DATA
//
// MessageText:
//
//  Failure receiving Network data.
//
#define FDO_177_FAILURE_RECIEVING_NETWORK_DATA 0x000023D9L

//
// MessageId: FDO_178_SSL_CERTIFICATE_ERROR
//
// MessageText:
//
//  Error using the the local SSL certificate.
//
#define FDO_178_SSL_CERTIFICATE_ERROR    0x000023DAL

//
// MessageId: FDO_179_SSL_CIPHER_ERROR
//
// MessageText:
//
//  Couldn't use the specified SSL cipher.
//
#define FDO_179_SSL_CIPHER_ERROR         0x000023DBL

//
// MessageId: FDO_180_CACERT_CIPHER_ERROR
//
// MessageText:
//
//  Server SSL certificate verification failed. Verify path and access rights.
//
#define FDO_180_CACERT_CIPHER_ERROR      0x000023DCL

//
// MessageId: FDO_181_LDAP_INVALID_URL
//
// MessageText:
//
//  Invalid LDAP URL.
//
#define FDO_181_LDAP_INVALID_URL         0x000023DDL

//
// MessageId: FDO_182_AGGREGATE_IN_SELECT
//
// MessageText:
//
//  Aggregate functions are not supported by the Select command; use the SelectAggregates command instead.
//
#define FDO_182_AGGREGATE_IN_SELECT      0x000023DEL

//
// MessageId: FDO_183_INVALID_FUNCTION_ARG
//
// MessageText:
//
//  One or more arguments for function '%1$ls' did not match the expected argument types.
//
#define FDO_183_INVALID_FUNCTION_ARG     0x000023DFL

