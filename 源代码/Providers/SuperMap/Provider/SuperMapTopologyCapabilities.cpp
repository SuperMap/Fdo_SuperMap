
/** \file	 SuperMapTopologyCapabilities.cpp
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#include <SuperMap.h>

SuperMapTopologyCapabilities::SuperMapTopologyCapabilities ()
{
}

SuperMapTopologyCapabilities::~SuperMapTopologyCapabilities ()
{
}

void SuperMapTopologyCapabilities::Dispose()
{
    delete this;
}

// True if the provider supports topology; if this is false, attempts to
// create topology-specific schema will fail.
bool SuperMapTopologyCapabilities::SupportsTopology ()
{
    return (false);
}

// True if the provider supports TopoGeometry properties that depend on
// each other in a hierarchy; if this is false, attempting to set a
// non-NULL for FdoTopoGeometryPropertyDefinition's "DependsOnTopoGeometry"
// property will fail.
bool SuperMapTopologyCapabilities::SupportsTopologicalHierarchy ()
{
    return (false);
}

// True if the provider automatically (as a result of geometry assignment)
// breaks curves and inserts nodes wherever curves cross or touch, or where
// a node touches a curve.
bool SuperMapTopologyCapabilities::BreaksCurveCrossingsAutomatically ()
{
    return (false);
}

// True if the provider supports the activation of a topology using an area
// (surface) restriction; this may involve the use of pessimistic locking.
bool SuperMapTopologyCapabilities::ActivatesTopologyByArea ()
{
    return (false);
}

// True if the provider constrains edits of TopoGeometry properties (by
// geometry value) to those that do not change topological relationships.
bool SuperMapTopologyCapabilities::ConstrainsFeatureMovements ()
{
    return (false);
}


