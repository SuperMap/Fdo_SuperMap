
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

#ifndef _FDOITOPOLOGYCAPABILITIES_H_
#define _FDOITOPOLOGYCAPABILITIES_H_

/// \brief
/// FDO supports properties that inform the client code about capabilities that
/// may vary between providers. 
/// /note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoITopologyCapabilities : public FdoIDisposable
{
    public:
    /// True if the provider supports topology; if this is false, attempts to
    /// create topology-specific schema will fail.
    FDO_API virtual bool SupportsTopology() = 0;

    /// True if the provider supports TopoGeometry properties that depend on
    /// each other in a hierarchy; if this is false, attempting to set a
    /// non-NULL for FdoTopoGeometryPropertyDefinition's "DependsOnTopoGeometry"
    /// property will fail.
    FDO_API virtual bool SupportsTopologicalHierarchy() = 0;

    /// True if the provider automatically (as a result of geometry assignment)
    /// breaks curves and inserts nodes wherever curves cross or touch, or where
    /// a node touches a curve.
    FDO_API virtual bool BreaksCurveCrossingsAutomatically() = 0;

    /// True if the provider supports the activation of a topology using an area
    /// (surface) restriction; this may involve the use of pessimistic locking.
    FDO_API virtual bool ActivatesTopologyByArea() = 0;

    /// True if the provider constrains edits of TopoGeometry properties (by
    /// geometry value) to those that do not change topological relationships.
    FDO_API virtual bool ConstrainsFeatureMovements() = 0;
};

#endif /* _FDOITOPOLOGYCAPABILITIES_H_ */


