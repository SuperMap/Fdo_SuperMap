/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef [!output UPPER_PREFIX]CREATESPATIALCONTEXT_H
#define [!output UPPER_PREFIX]CREATESPATIALCONTEXT_H

class [!output PREFIX]CreateSpatialContext :
    public FdoCommonCommand<FdoICreateSpatialContext, [!output PREFIX]Connection>
{
public:
    [!output PREFIX]CreateSpatialContext([!output PREFIX]Connection *connection);
    virtual ~[!output PREFIX]CreateSpatialContext(void);

    // methods inherited from FdoICreateSpatialContext:
public:
    virtual FdoString* GetName();
    virtual void SetName(FdoString* value);
    virtual FdoString* GetDescription();
    virtual void SetDescription(FdoString* value);
    virtual FdoString* GetCoordinateSystem();
    virtual void SetCoordinateSystem(FdoString* value);
    virtual FdoSpatialContextExtentType GetExtentType();
    virtual void SetExtentType(FdoSpatialContextExtentType value);
    virtual FdoByteArray* GetExtent();
    virtual void SetExtent(FdoByteArray* value);
    virtual const double GetXYTolerance();
    virtual void SetXYTolerance(const double value);
    virtual const double GetZTolerance();
    virtual void SetZTolerance(const double value);
    virtual const bool GetUpdateExisting();
    virtual void SetUpdateExisting(const bool value);
    virtual void Execute();
    virtual FdoString* GetCoordinateSystemWkt();
	virtual void SetCoordinateSystemWkt(FdoString* value);

protected:
    bool m_bUpdateExisting;
    FdoStringP m_wcsName;
    FdoStringP m_wcsDescription;
    FdoStringP m_wcsCoordSys;
    FdoStringP m_wcsCoordSysWkt;
    FdoPtr<FdoByteArray> m_Extent;
    FdoSpatialContextExtentType m_eExtentType;
    double m_dXYTolerance;
    double m_dZTolerance;

    // flags to track what's been set (useful when updating spatial contexts):
    bool m_bDescriptionSet;
    bool m_bCoordinateSystemSet;
    bool m_bCoordinateSystemWktSet;
    bool m_bExtentTypeSet;
    bool m_bExtentSet;
    bool m_bXYToleranceSet;
    bool m_bZToleranceSet;
};

#endif // [!output UPPER_PREFIX]CREATESPATIALCONTEXT_H

