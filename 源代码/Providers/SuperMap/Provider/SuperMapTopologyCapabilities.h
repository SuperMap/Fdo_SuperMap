/** \file	 SuperMapTopologyCapabilities.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#ifndef __SUPERMAP_TOPOLOGYCAPABILITIES_H__
#define __SUPERMAP_TOPOLOGYCAPABILITIES_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapTopologyCapabilities : public FdoITopologyCapabilities
{
public:
    SuperMapTopologyCapabilities ();

protected:
    virtual ~SuperMapTopologyCapabilities ();

protected:
    virtual void Dispose ();

public:
    // True if the provider supports topology; if this is false, attempts to
    // create topology-specific schema will fail.
    virtual bool SupportsTopology ();

    // True if the provider supports TopoGeometry properties that depend on
    // each other in a hierarchy; if this is false, attempting to set a
    // non-NULL for FdoTopoGeometryPropertyDefinition's "DependsOnTopoGeometry"
    // property will fail.
    virtual bool SupportsTopologicalHierarchy ();

    // True if the provider automatically (as a result of geometry assignment)
    // breaks curves and inserts nodes wherever curves cross or touch, or where
    // a node touches a curve.
    virtual bool BreaksCurveCrossingsAutomatically ();

    // True if the provider supports the activation of a topology using an area
    // (surface) restriction; this may involve the use of pessimistic locking.
    virtual bool ActivatesTopologyByArea ();

    // True if the provider constrains edits of TopoGeometry properties (by
    // geometry value) to those that do not change topological relationships.
    virtual bool ConstrainsFeatureMovements ();
};

#endif // __SUPERMAP_TOPOLOGYCAPABILITIES_H__

