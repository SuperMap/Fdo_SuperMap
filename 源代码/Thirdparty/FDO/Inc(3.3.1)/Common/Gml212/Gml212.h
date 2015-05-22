#ifndef FDO_GML212_H
#define FDO_GML212_H
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
#endif

/// \brief
/// FdoGml212 is a utility class defining the constants that apply to GML 2.1.2
/// subsequent versions
class FdoGml212
{
public:
    /// Various GML types recognized by FDO

    /// Geometry Types
	FDO_API_COMMON static const FdoStringP mAbstractGeometry;
    FDO_API_COMMON static const FdoStringP mPoint;	
    FDO_API_COMMON static const FdoStringP mLineString;	
    FDO_API_COMMON static const FdoStringP mLinearRing;
    FDO_API_COMMON static const FdoStringP mBox;	
    FDO_API_COMMON static const FdoStringP mPolygon;	
    FDO_API_COMMON static const FdoStringP mMultiPoint;
	FDO_API_COMMON static const FdoStringP mMultiLineString;
	FDO_API_COMMON static const FdoStringP mMultiPolygon;	
	FDO_API_COMMON static const FdoStringP mGeometryProperty;	

    /// Geometry collections
    FDO_API_COMMON static const FdoStringP mAbstractGeometryCollection;

    /// Coordinate types
	FDO_API_COMMON static const FdoStringP mCoord;		
	FDO_API_COMMON static const FdoStringP mCoordinates;	

    /// Geometry Associations
   	FDO_API_COMMON static const FdoStringP mGeometryAssociation;
   	FDO_API_COMMON static const FdoStringP mPointMember;
   	FDO_API_COMMON static const FdoStringP mLineStringMember;	
   	FDO_API_COMMON static const FdoStringP mPolygonMember;	
   	FDO_API_COMMON static const FdoStringP mLinearRingMember;	

    /// Geometric Assocations (Properties)
	FDO_API_COMMON static const FdoStringP mPointProperty;		
	FDO_API_COMMON static const FdoStringP mPolygonProperty;	
	FDO_API_COMMON static const FdoStringP mLineStringProperty;
	FDO_API_COMMON static const FdoStringP mMultiPointProperty;	
	FDO_API_COMMON static const FdoStringP mMultiPolygonProperty;	
	FDO_API_COMMON static const FdoStringP mMultiLineStringProperty;	
	FDO_API_COMMON static const FdoStringP mMultiGeometryProperty;		

    /// Features, collections and associations
	FDO_API_COMMON static const FdoStringP mAbstractFeature;		
	FDO_API_COMMON static const FdoStringP mAbstractFeatureCollection;
	FDO_API_COMMON static const FdoStringP mFeatureAssociation;	
};

#endif


