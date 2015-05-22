/* $Id: pef.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
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

#ifndef PEF_INCLUDED
#define PEF_INCLUDED

#ifndef PE_INCLUDED
#include "pe.h"
#endif

#ifndef PEDEF_INCLUDED
#include "pedef.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pe_entry_t
{
   int  code;
   char name[PE_NAME_MAX];
} *PE_TABLE;

/* Return the predefined angular unit table:                                  */
PE_TABLE PEAPI pe_predefined_angular_unit(
                  int *n);

/* Return the predefined linear unit table:                                   */
PE_TABLE PEAPI pe_predefined_linear_unit(
                  int *n);

/* Return the predefined spheroid table:                                      */
PE_TABLE PEAPI pe_predefined_spheroid(
                  int *n);

/* Return the predefined datum table:                                         */
PE_TABLE PEAPI pe_predefined_datum(
                  int *n);

/* Return the predefined prime meridian table:                                */
PE_TABLE PEAPI pe_predefined_primem(
                  int *n);

/* Return the predefined parameter table:                                     */
PE_TABLE PEAPI pe_predefined_parameter(
                  int *n);

/* Return the predefined projection table:                                    */
PE_TABLE PEAPI pe_predefined_projection(
                  int *n);

/* Return the predefined method table:                                        */
PE_TABLE PEAPI pe_predefined_method(
                  int *n);

/* Return the predefined geographic CS table:                                 */
PE_TABLE PEAPI pe_predefined_geogcs(
                  int *n);

/* Return the predefined projected CS table:                                  */
PE_TABLE PEAPI pe_predefined_projcs(
                  int *n);

/* Return the predefined geographic transformation table:                     */
PE_TABLE PEAPI pe_predefined_geogtran(
                  int *n);

/* Release memory previously allocated by functions pe_predefined_...()       */
void PEAPI pe_table_del(
              PE_TABLE table);

/* Manufacture a new Projection Engine object:                                */
struct pe_struct_t * PEAPI pe_factory(
                              int code);

/* Return an object's factory code:                                           */
int PEAPI pe_factory_code(
             struct pe_struct_t *p);

/* Manufacture a new Projection Engine object of an exact type:               */
PE_UNIT       PEAPI pe_factory_unit(int code);
PE_SPHEROID   PEAPI pe_factory_spheroid(int code);
PE_DATUM      PEAPI pe_factory_datum(int code);
PE_PRIMEM     PEAPI pe_factory_primem(int code);
PE_GEOGCS     PEAPI pe_factory_geogcs(int code);
PE_PARAMETER  PEAPI pe_factory_parameter(int code);
PE_PROJECTION PEAPI pe_factory_projection(int code);
PE_PROJCS     PEAPI pe_factory_projcs(int code);
PE_METHOD     PEAPI pe_factory_method(int code);
PE_GEOGTRAN   PEAPI pe_factory_geogtran(int code);

/* Create an integer array of factory codes for specific object types         */
int * PEAPI pe_factory_datum_codelist(int *num_codes);
int * PEAPI pe_factory_geogcs_codelist(int *num_codes);
int * PEAPI pe_factory_geogtran_codelist(int *num_codes);
int * PEAPI pe_factory_method_codelist(int *num_codes);
int * PEAPI pe_factory_parameter_codelist(int *num_codes);
int * PEAPI pe_factory_projcs_codelist(int *num_codes);
int * PEAPI pe_factory_primem_codelist(int *num_codes);
int * PEAPI pe_factory_projection_codelist(int *num_codes);
int * PEAPI pe_factory_spheroid_codelist(int *num_codes);
int * PEAPI pe_factory_angular_unit_codelist(int *num_codes);
int * PEAPI pe_factory_linear_unit_codelist(int *num_codes);

/* Delete an integer array of factory codes                                   */
void PEAPI pe_factory_codelist_del(int *codelist);

#ifdef __cplusplus
};
#endif

#endif
