##
## Copyright (C) 2004-2006  Autodesk, Inc.
## 
## This library is free software; you can redistribute it and/or
## modify it under the terms of version 2.1 of the GNU Lesser
## General Public License as published by the Free Software Foundation.
## 
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## Lesser General Public License for more details.
## 
## You should have received a copy of the GNU Lesser General Public
## License along with this library; if not, write to the Free Software
## Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
##

AUTOMAKE_OPTIONS = foreign

noinst_LTLIBRARIES = libProvidersCommon.la

EXTRA_DIST = \
  FdoCommon.sln \
  FdoCommon.vcproj \
  Docs/doc_src/FDOCommon_Provider_API.dox \
  Docs/doc_src/FDOCommon_Provider_API.doxdb \
  Docs/doc_src/overview_topics/FDOCommon_global_class_hierarchy.dtx \
  Docs/doc_src/overview_topics/index.dtx \
  Src/Parse/script3 \
  Src/Parse/script3_h \
  Src/Parse/script3_linux \
  Src/Parse/yyConstraint.y \
  Src/Parse/yyConstraintWin.cpp \
  Inc/Parse/yyConstraintWin.h

libProvidersCommon_la_SOURCES = \
  Src/FdoCommonNlsUtil.cpp \
  Src/FdoCommonOSUtil.cpp \
  Src/FdoCommonSchemaUtil.cpp \
  Src/FdoCommonStringUtil.cpp \
  Src/FdoCommonMiscUtil.cpp \
  Src/FdoCommonFile.cpp \
  Src/FdoCommonGeometryUtil.cpp \
  Src/FdoCommonConnPropDictionary.cpp \
  Src/FdoCommonConnStringParser.cpp \
  Src/FdoCommonBinaryReader.cpp \
  Src/FdoCommonBinaryWriter.cpp \
  Src/FdoCommonPropertyIndex.cpp \
  Src/FdoCommonThreadMutex.cpp \
  Src/FdoCommonThreadUtil.cpp \
  Src/stdafx.cpp \
  Src/Parse/Lex.cpp \
  Src/Parse/Parse.cpp \
  Src/Parse/yyConstraint.cpp

noinst_HEADERS = $(libProvidersCommon_la_SOURCES) \
  Inc/FdoCommonBinaryReader.h \
  Inc/FdoCommonBinaryWriter.h \
  Inc/FdoCommonCommand.h \
  Inc/FdoCommonConnPropDictionary.h \
  Inc/FdoCommonConnStringParser.h \
  Inc/FdoCommonFeatureCommand.h \
  Inc/FdoCommonFile.h \
  Inc/FdoCommonGeometryUtil.h \
  Inc/FdoCommonMiscUtil.h \
  Inc/FdoCommonNlsUtil.h \
  Inc/FdoCommonOSUtil.h \
  Inc/FdoCommonPropertyIndex.h \
  Inc/FdoCommonReader.h \
  Inc/FdoCommonSchemaUtil.h \
  Inc/FdoCommonStringUtil.h \
  Inc/FdoCommonThreadMutex.h \
  Inc/FdoCommonThreadUtil.h \
  Inc/stdafx.h \
  Inc/Parse/Lex.h \
  Inc/Parse/Parse.h \
  Inc/Parse/Types.h \
  Inc/Parse/yyConstraint.h

INCLUDES = \
  -I$(FDO)/Unmanaged/Inc \
  -I./Inc \
  -I$(FDO)/Unmanaged/Src/Common

libProvidersCommon_la_LDFLAGS = 

CXXFLAGS = @CXXFLAGS@ -D__USE_GNU -DLINUX -DLINUX_IA32 -pthread -DHAVE_GEOM_INFO_TYPE

