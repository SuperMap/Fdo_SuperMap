/* $Id: pe_coordsys_from_prj.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
/* -------------------------------------------------------------------------- */
/* Projection Engine Version 9.1                                              */
/*   COPYRIGHT 1992-2005 ESRI                                                 */
/*                                                                            */
/*   TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL                         */
/*   Unpublished material - all rights reserved under the                     */
/*   Copyright Laws of the United States.                                     */
/*                                                                            */
/*   For additional information, contact:                                     */
/*   Environmental Systems Research Institute, Inc.                           */
/*   Attn: Contracts Dept                                                     */
/*   380 New York Street                                                      */
/*   Redlands, California, USA 92373                                          */
/*                                                                            */
/*   email: contracts@esri.com                                                */
/* -------------------------------------------------------------------------- */

#ifndef PE_FROM_PRJ_INCLUDED
#define PE_FROM_PRJ_INCLUDED

#define PE_PRJ_ILLEGAL_ARGUMENT   (-100)
#define PE_PRJ_CANNOT_OPEN_FILE   (-101)
#define PE_PRJ_ILLEGAL_KEYWORD    (-102)
#define PE_PRJ_TOO_MANY_PARAMS    (-103)
#define PE_PRJ_ILLEGAL_UNIT       (-104)
#define PE_PRJ_ILLEGAL_SPHEROID   (-105)
#define PE_PRJ_ILLEGAL_DATUM      (-106)
#define PE_PRJ_ILLEGAL_PROJECTION (-107)
#define PE_PRJ_ILLEGAL_PARAMETER  (-108)
#define PE_PRJ_ILLEGAL_ZONE       (-109)
#define PE_PRJ_NO_ZUNIT           (-110)

#define PE_TOPRJ_ILLEGAL_UNIT         (-121)
#define PE_TOPRJ_ILLEGAL_PRIMEM       (-122)
#define PE_TOPRJ_ILLEGAL_PROJECTION   (-123)
#define PE_TOPRJ_ILLEGAL_SPHEROID     (-124)
#define PE_TOPRJ_ILLEGAL_SCALE_FACTOR (-125)
#define PE_TOPRJ_ILLEGAL_PARAMETER    (-126)
#define PE_TOPRJ_ILLEGAL_AZIMUTH      (-127)

#define PE_PRJ_OUT_OF_MEMORY      (-200)

#ifdef __cplusplus
extern "C" {
#endif

PE_COORDSYS PEAPI pe_coordsys_from_prjfile(
                     const char *path,
                     int        *error);

PE_COORDSYS PEAPI pe_coordsys_from_prjstring(
                     const char *string,
                     int        *error);

PE_UNIT     PEAPI pe_zunit_from_prjfile(
                     const char *path,
                     int        *error);

PE_UNIT     PEAPI pe_zunit_from_prjstring(
                     const char *string,
                     int        *error);

void        PEAPI pe_coordsys_to_prjfile(
                     PE_COORDSYS coordsys,
                     PE_UNIT     zunit,
                     const char  *path,
                     int         *error);

void        PEAPI pe_coordsys_to_prjstring(
                     PE_COORDSYS coordsys,
                     PE_UNIT     zunit,
                     char        *string,
                     int         *error);

#ifdef __cplusplus
};
#endif

#endif
