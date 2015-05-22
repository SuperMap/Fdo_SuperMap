/* $Id: pe.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
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

#ifndef PE_INCLUDED
#define PE_INCLUDED

#ifndef PEDEF_INCLUDED
#include "pedef.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define PEAPI __stdcall
#else
#define PEAPI
#endif

/* Maximum length of a text buffer:                                           */
#define PE_BUFFER_MAX 1024

/* Maximum length of a name character array:                                  */
#define PE_NAME_MAX 64

/* Maximum number of parameters:                                              */
#define PE_PARM_MAX 16

/* Return Projection Engine version information:                              */
char * PEAPI pe_version(void);

/* Allocate memory                                                            */
void * PEAPI pe_memalloc(int size);

/* Deallocate memory                                                          */
void PEAPI pe_memdealloc(void *pointer);

/* Function to load pointer to function which supplies pedatahome location    */
typedef char *(*PE_DHOMEFUNC)();
void PEAPI pe_datahome_setfunc(PE_DHOMEFUNC getdatahome);

/* Function to load pointer to function which supplies peobjedithome location */
typedef char *(*PE_OEHOMEFUNC)();
void PEAPI pe_objedithome_setfunc(PE_OEHOMEFUNC getdatahome);

/*----------------------------------------------------------------------------*/
/*                      U N I T S   O F   M E A S U R E                       */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_UNIT;

/* Create a new unit of measure:                                              */
PE_UNIT PEAPI pe_unit_new(
                 const char *name,
                 double factor);

/* Release memory previously allocated by function pe_unit_new():             */
void PEAPI pe_unit_del(
              PE_UNIT unit);

/* Retrieve a unit's name into array name[]:                                  */
void PEAPI pe_unit_name(
              PE_UNIT unit,
              char name[PE_NAME_MAX]);

/* Retrieve a unit's conversion factor and return it:                         */
double PEAPI pe_unit_factor(
                PE_UNIT unit);

/* Retrieve unit build status code and return it:                             */
unsigned char PEAPI pe_unit_status(
                       PE_UNIT unit);

/* Put an external representation of a unit into array buffer[]:              */
void PEAPI pe_unit_to_string(
              PE_UNIT unit,
              char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a unit:            */
PE_UNIT PEAPI pe_unit_from_string(
                 const char *buffer);

/* Test if argument p points to a unit:                                       */
int PEAPI pe_unit_p(
             struct pe_struct_t *p);

/* Test if two units are identical:                                           */
int PEAPI pe_unit_eq(
             PE_UNIT unit1,
             PE_UNIT unit2);

/* Clone a unit:                                                              */
PE_UNIT PEAPI pe_unit_clone(
                 PE_UNIT unit);

/*----------------------------------------------------------------------------*/
/*                    G E O D E T I C   S P H E R O I D S                     */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_SPHEROID;

/* Create a new geodetic spheroid:                                            */
PE_SPHEROID PEAPI pe_spheroid_new(
                     const char *name,
                     double axis,
                     double flattening);

/* Relese memory previously allocated by function pe_spheroid_new():          */
void PEAPI pe_spheroid_del(
              PE_SPHEROID spheroid);

/* Retrieve a spheroid's name into array name[]:                              */
void PEAPI pe_spheroid_name(
              PE_SPHEROID spheroid,
              char name[PE_NAME_MAX]);

/* Retrieve a spheroid's semi-major axis and return it:                       */
double PEAPI pe_spheroid_axis(
                PE_SPHEROID spheroid);

/* Retrieve a spheroid's flattening and return it:                            */
double PEAPI pe_spheroid_flattening(
                PE_SPHEROID spheroid);

/* Retrieve spheroid build status code and return it:                         */
unsigned char PEAPI pe_spheroid_status(
                       PE_SPHEROID spheroid);

/* Put an external representation of a spheroid into array buffer[]:          */
void PEAPI pe_spheroid_to_string(
              PE_SPHEROID spheroid,
              char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a spheroid:        */
PE_SPHEROID PEAPI pe_spheroid_from_string(
                     const char *buffer);

/* Test if argument p points to a spheroid:                                   */
int PEAPI pe_spheroid_p(
             struct pe_struct_t *p);

/* Test if two spheroids are identical:                                       */
int PEAPI pe_spheroid_eq(
             PE_SPHEROID spheroid1,
             PE_SPHEROID spheroid2);

/* Clone a spheroid:                                                          */
PE_SPHEROID PEAPI pe_spheroid_clone(
                     PE_SPHEROID spheroid);

/*----------------------------------------------------------------------------*/
/*                     H O R I Z O N T A L   D A T U M S                      */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_DATUM;

/* Create a new horizontal datum:                                             */
PE_DATUM PEAPI pe_datum_new(
                  const char *name,
                  PE_SPHEROID spheroid);

/* Release memory previously allocated by function pe_datum_new():            */
void PEAPI pe_datum_del(
              PE_DATUM datum);

/* Retrieve a datum's name into array name[]:                                 */
void PEAPI pe_datum_name(
              PE_DATUM datum,
              char name[PE_NAME_MAX]);

/* Retrieve a datum's spheroid and return it:                                 */
PE_SPHEROID PEAPI pe_datum_spheroid(
                     PE_DATUM datum);

/* Retrieve datum build status code and return it:                            */
unsigned char PEAPI pe_datum_status(
                       PE_DATUM datum);

/* Put an external representation of a datum into array buffer[]:             */
void PEAPI pe_datum_to_string(
              PE_DATUM datum,
              char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a datum:           */
PE_DATUM PEAPI pe_datum_from_string(
                  const char *buffer);

/* Test if argument p points to a datum:                                      */
int PEAPI pe_datum_p(
             struct pe_struct_t *p);

/* Test if two datums are identical:                                          */
int PEAPI pe_datum_eq(
             PE_DATUM datum1,
             PE_DATUM datum2);

/* Clone a datum:                                                             */
PE_DATUM PEAPI pe_datum_clone(
                  PE_DATUM datum);

/*----------------------------------------------------------------------------*/
/*                       P R I M E   M E R I D I A N S                        */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_PRIMEM;

/* Create a new prime meridian:                                               */
PE_PRIMEM PEAPI pe_primem_new(
                   const char *name,
                   double longitude);

/* Release memory previously allocated by function pe_primem_new():           */
void PEAPI pe_primem_del(
              PE_PRIMEM primem);

/* Retrieve a prime meridian's name into array name[]:                        */
void PEAPI pe_primem_name(
              PE_PRIMEM primem,
              char name[PE_NAME_MAX]);

/* Retrieve a prime meridian's longitude and return it:                       */
double PEAPI pe_primem_longitude(
                PE_PRIMEM primem);

/* Retrieve primem build status code and return it:                           */
unsigned char PEAPI pe_primem_status(
                       PE_PRIMEM primem);

/* Put an external representation of a prime meridian into array buffer[]:    */
void PEAPI pe_primem_to_string(
              PE_PRIMEM primem,
              char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a prime meridian:  */
PE_PRIMEM PEAPI pe_primem_from_string(
                   const char *buffer);

/* Test if argument p points to a prime meridian:                             */
int PEAPI pe_primem_p(
             struct pe_struct_t *p);

/* Test if two prime meridians are identical:                                 */
int PEAPI pe_primem_eq(
             PE_PRIMEM primem1,
             PE_PRIMEM primem2);

/* Clone a prime meridian:                                                    */
PE_PRIMEM PEAPI pe_primem_clone(
                   PE_PRIMEM primem);

/*----------------------------------------------------------------------------*/
/*         G E O G R A P H I C   C O O R D I N A T E   S Y S T E M S          */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_GEOGCS;

/* Create a new geographic coordinate system (GCS):                           */
PE_GEOGCS PEAPI pe_geogcs_new(
                   const char *name,
                   PE_DATUM datum,
                   PE_PRIMEM primem,
                   PE_UNIT unit);

/* Release memory previously allocated by function pe_geogcs_new():           */
void PEAPI pe_geogcs_del(
              PE_GEOGCS geogcs);

/* Retrieve a GCS's name into array name[]:                                   */
void PEAPI pe_geogcs_name(
              PE_GEOGCS geogcs,
              char name[PE_NAME_MAX]);

/* Retrieve a GCS's datum and return it:                                      */
PE_DATUM PEAPI pe_geogcs_datum(
                  PE_GEOGCS geogcs);

/* Retrieve a GCS's prime meridian and return it:                             */
PE_PRIMEM PEAPI pe_geogcs_primem(
                   PE_GEOGCS geogcs);

/* Retrieve a GCS's unit (angular) and return it:                             */
PE_UNIT PEAPI pe_geogcs_unit(
                 PE_GEOGCS geogcs);

/* Retrieve GCS build status code and return it:                              */
unsigned char PEAPI pe_geogcs_status(
                       PE_GEOGCS geogcs);

/* Put an external representation of a GCS into array buffer[]:               */
void PEAPI pe_geogcs_to_string(
              PE_GEOGCS geogcs,
              char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a GCS:             */
PE_GEOGCS PEAPI pe_geogcs_from_string(
                   const char *buffer);

/* Test if argument p points to a GCS:                                        */
int PEAPI pe_geogcs_p(
             struct pe_struct_t *p);

/* Test if two GCSs are identical:                                            */
int PEAPI pe_geogcs_eq(
             PE_GEOGCS geogcs1,
             PE_GEOGCS geogcs2);

/* Clone a GCS:                                                               */
PE_GEOGCS PEAPI pe_geogcs_clone(
                   PE_GEOGCS geogcs);

/*----------------------------------------------------------------------------*/
/*         G E O C E N T R I C   C O O R D I N A T E   S Y S T E M S          */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_GEOXYZCS;

/* Create a new geocentric coordinate system (GXYZCS):                        */
PE_GEOXYZCS PEAPI pe_geoxyzcs_new(
                     const char *name,
                     PE_GEOGCS geogcs,
                     PE_UNIT unit);

/* Release memory previously allocated by function pe_geoxyzcs_new():         */
void PEAPI pe_geoxyzcs_del(
              PE_GEOXYZCS geoxyzcs);

/* Retrieve a GXYZCS's name into array name[]:                                */
void PEAPI pe_geoxyzcs_name(
              PE_GEOXYZCS geoxyzcs,
              char name[PE_NAME_MAX]);

/* Retrieve a GXYZCS's geogcs and return it:                                  */
PE_GEOGCS PEAPI pe_geoxyzcs_geogcs(
                   PE_GEOXYZCS geoxyzcs);

/* Retrieve a GXYZCS's unit (linear) and return it:                           */
PE_UNIT PEAPI pe_geoxyzcs_unit(
                 PE_GEOXYZCS geoxyzcs);

/* Retrieve GXYZCS build status code and return it:                           */
unsigned char PEAPI pe_geoxyzcs_status(
                       PE_GEOXYZCS geoxyzcs);

/* Put an external representation of a GXYZCS into array buffer[]:            */
void PEAPI pe_geoxyzcs_to_string(
              PE_GEOXYZCS geoxyzcs,
              char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a GXYZCS:          */
PE_GEOXYZCS PEAPI pe_geoxyzcs_from_string(
                     const char *buffer);

/* Test if argument p points to a GXYZCS:                                     */
int PEAPI pe_geoxyzcs_p(
             struct pe_struct_t *p);

/* Test if two GXYZCSs are identical:                                         */
int PEAPI pe_geoxyzcs_eq(
             PE_GEOXYZCS geoxyzcs1,
             PE_GEOXYZCS geoxyzcs2);

/* Clone a GXYZCS:                                                            */
PE_GEOXYZCS PEAPI pe_geoxyzcs_clone(
                     PE_GEOXYZCS geoxyzcs);

/*----------------------------------------------------------------------------*/
/*                       M A P   P R O J E C T I O N S                        */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_PROJECTION;

/* Projection transformation function type:                                   */
typedef int (*PE_PROJFUNC)(
                 double sph[2],
                 double parm[PE_PARM_MAX],
                 int    n,
                 double coord[][2],
                 int    iconst[],
                 double dconst[]);

/* Projection horizon type:                                                   */
typedef struct pe_horizon_t
{
   int      nump;
   int      kind;
   int      inclusive;
   int      replicate;
   int      size;
   double (*coord)[2];
} *PE_HORIZON;

/* Enum of replication directions for a horizon                               */
enum replicate_enum {PE_HORIZON_REPLICATE_NONE,  PE_HORIZON_REPLICATE_LEFT,
                     PE_HORIZON_REPLICATE_RIGHT, PE_HORIZON_REPLICATE_BOTH};

/* Projection horizon function type:                                          */
typedef PE_HORIZON (*PE_HORFUNC)(
			double sph[2],
			double parm[PE_PARM_MAX]);

/* Create a new map projection:                                               */
PE_PROJECTION PEAPI pe_projection_new(
		       const char *name,
		       PE_PROJFUNC forward,
		       PE_PROJFUNC inverse,
		       PE_HORFUNC  horizon);

/* Release memory previously allocated by function pe_projection_new():       */
void PEAPI pe_projection_del(
	      PE_PROJECTION projection);

/* Retrieve a projection's name into array name[]:                            */
void PEAPI pe_projection_name(
	      PE_PROJECTION projection,
	      char name[PE_NAME_MAX]);

/* Retrieve a projection's forward transformation and return it:              */
PE_PROJFUNC PEAPI pe_projection_forward(
		     PE_PROJECTION projection);

/* Retrieve a projection's inverse transformation and return it:              */
PE_PROJFUNC PEAPI pe_projection_inverse(
		     PE_PROJECTION projection);

/* Retrieve a projection's gcs horizon function and return it:                */
PE_HORFUNC PEAPI pe_projection_horizon(
		    PE_PROJECTION projection);

/* Retrieve a projection's pcs horizon function and return it:                */
PE_HORFUNC PEAPI pe_projection_horizon_pcs(
		    PE_PROJECTION projection);

/* Retrieve a projection's gcs raster horizon function and return it:         */
PE_HORFUNC PEAPI pe_projection_horizon_gcs_raster(
		    PE_PROJECTION projection);

/* Retrieve a projection's pcs raster horizon function and return it:         */
PE_HORFUNC PEAPI pe_projection_horizon_pcs_raster(
		    PE_PROJECTION projection);

/* Retrieve projection build status code and return it:                       */
unsigned char PEAPI pe_projection_status(
                       PE_PROJECTION projection);

/* Put an external representation of a projection into array buffer[]:        */
void PEAPI pe_projection_to_string(
	      PE_PROJECTION projection,
	      char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a projection:      */
PE_PROJECTION PEAPI pe_projection_from_string(
		       const char *buffer);

/* Test if argument p points to a projection:                                 */
int PEAPI pe_projection_p(
	     struct pe_struct_t *p);

/* Test if two projections are identical:                                     */
int PEAPI pe_projection_eq(
	     PE_PROJECTION projection1,
	     PE_PROJECTION projection2);

/* Clone a projection:                                                        */
PE_PROJECTION PEAPI pe_projection_clone(
		       PE_PROJECTION projection);

/*----------------------------------------------------------------------------*/
/*                               M E T H O D S                                */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_METHOD;

/* Method transformation function type:                                       */
typedef int (*PE_METHFUNC)(
		 double sph1[2],
		 double sph2[2],
		 double parm[PE_PARM_MAX],
		 char   *chrstr,
		 int    n,
		 double coord[][2],
		 double h[],
		 int    iconst[],
		 float  fconst[],
		 double dconst[]);

/* Create a new transformation method:                                        */
PE_METHOD PEAPI pe_method_new(
		   const char *name,
		   PE_METHFUNC forward,
		   PE_METHFUNC inverse);

/* Release memory previously allocated by function pe_method_new():           */
void PEAPI pe_method_del(
	      PE_METHOD method);

/* Retrieve a methods's name into array name[]:                               */
void PEAPI pe_method_name(
	      PE_METHOD method,
	      char name[PE_NAME_MAX]);

/* Retrieve a method's forward function and return it:                        */
PE_METHFUNC PEAPI pe_method_forward(
		     PE_METHOD method);

/* Retrieve a method's inverse function and return it:                        */
PE_METHFUNC PEAPI pe_method_inverse(
		     PE_METHOD method);

/* Retrieve method build status code and return it:                           */
unsigned char PEAPI pe_method_status(
                       PE_METHOD method);

/* Put an external representation of a method into array buffer[]:            */
void PEAPI pe_method_to_string(
	      PE_METHOD method,
	      char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a method:          */
PE_METHOD PEAPI pe_method_from_string(
		   const char *buffer);

/* Test if argument p points to a method:                                     */
int PEAPI pe_method_p(
	     struct pe_struct_t *p);

/* Test if two methods are identical:                                         */
int PEAPI pe_method_eq(
	     PE_METHOD method1,
	     PE_METHOD method2);

/* Clone a method:                                                            */
PE_METHOD PEAPI pe_method_clone(
		   PE_METHOD method);

/*----------------------------------------------------------------------------*/
/*                            P A R A M E T E R S                             */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_PARAMETER;

/* Create a new parameter:                                                    */
PE_PARAMETER PEAPI pe_parameter_new(
		      const char *name,
		      double value);

/* Release memory previously allocated by function pe_parameter_new():        */
void PEAPI pe_parameter_del(
	      PE_PARAMETER parameter);

/* Retrieve a parameter's name into array name[]:                             */
void PEAPI pe_parameter_name(
	      PE_PARAMETER parameter,
	      char name[PE_NAME_MAX]);

/* Retrieve a parameter's value and return it:                                */
double PEAPI pe_parameter_value(
		PE_PARAMETER parameter);

/* Return the parameter array index number a parameter object would occupy    */
int PEAPI pe_parameter_index(
		PE_PARAMETER parameter);

/* Set a parameter's value:                                                   */
int PEAPI pe_parameter_value_set(
	     PE_PARAMETER parameter,
	     double value);

/* Set a parameter's name:                                                    */
int PEAPI pe_parameter_name_set(
	     PE_PARAMETER parameter,
	     char name[PE_NAME_MAX]);

/* Retrieve parameter build status code and return it:                        */
unsigned char PEAPI pe_parameter_status(
                       PE_PARAMETER parameter);

/* Put an external representation of a parameter into array buffer[]:         */
void PEAPI pe_parameter_to_string(
	      PE_PARAMETER parameter,
	      char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a parameter:       */
PE_PARAMETER PEAPI pe_parameter_from_string(
		      const char *buffer);

/* Test if argument p points to a parameter:                                  */
int PEAPI pe_parameter_p(
	     struct pe_struct_t *p);

/* Test if two parameters are identical:                                      */
int PEAPI pe_parameter_eq(
	     PE_PARAMETER parameter1,
	     PE_PARAMETER parameter2);

/* Clone a parameter:                                                         */
PE_PARAMETER PEAPI pe_parameter_clone(
		      PE_PARAMETER parameter);

/* Create default parameters in array parameters[] for a method object:       */
int PEAPI pe_parameter_method_defaults(
	     PE_METHOD    method,
	     PE_PARAMETER parameters[PE_PARM_MAX]);

/* Create default parameters in array parameters[] for a projection object:   */
int PEAPI pe_parameter_projection_defaults(
	     PE_PROJECTION projection,
	     PE_PARAMETER  parameters[PE_PARM_MAX]);

/*----------------------------------------------------------------------------*/
/*          P R O J E C T E D   C O O R D I N A T E   S Y S T E M S           */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_PROJCS;

/* Create a new projected coordinate system (PCS):                            */
PE_PROJCS PEAPI pe_projcs_new(
		   const char *name,
		   PE_GEOGCS geogcs,
		   PE_PROJECTION projection,
		   PE_PARAMETER parameters[PE_PARM_MAX],
		   PE_UNIT unit);

/* Release memory previously allocated by function pe_projcs_new():           */
void PEAPI pe_projcs_del(
	      PE_PROJCS projcs);

/* Retrieve a PCS's name into array name[]:                                   */
void PEAPI pe_projcs_name(
	      PE_PROJCS projcs,
	      char name[PE_NAME_MAX]);

/* Retrieve a PCS's GCS and return it:                                        */
PE_GEOGCS PEAPI pe_projcs_geogcs(
		   PE_PROJCS projcs);

/* Retrieve a PCS's projection and return it:                                 */
PE_PROJECTION PEAPI pe_projcs_projection(
		       PE_PROJCS projcs);

/* Retrieve a PCS's parameters into array parameters[]:                       */
void PEAPI pe_projcs_parameters(
	      PE_PROJCS projcs,
	      PE_PARAMETER parameters[PE_PARM_MAX]);

/* Retrieve a PCS's unit (linear) and return it:                              */
PE_UNIT PEAPI pe_projcs_unit(
		 PE_PROJCS projcs);

/* Retrieve PCS build status code and return it:                              */
unsigned char PEAPI pe_projcs_status(
                       PE_PROJCS projcs);

/* Put an external representation of a PCS into array buffer[]:               */
void PEAPI pe_projcs_to_string(
	      PE_PROJCS projcs,
	      char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a PCS:             */
PE_PROJCS PEAPI pe_projcs_from_string(
		   const char *buffer);

/* Test if argument p points to a PCS:                                        */
int PEAPI pe_projcs_p(
	     struct pe_struct_t *p);

/* Test if two PCSs are identical:                                            */
int PEAPI pe_projcs_eq(
	     PE_PROJCS projcs1,
	     PE_PROJCS projcs2);

/* Test if two PCSs are identical except for the name (no-name comparison)    */
int PEAPI pe_projcs_eqnn(
	     PE_PROJCS projcs1,
	     PE_PROJCS projcs2);

/* Clone a PCS:                                                               */
PE_PROJCS PEAPI pe_projcs_clone(
		   PE_PROJCS projcs);

/* Clone a PCS, change the clone's unit objects to the arguments,             */
/*   and convert values in appropriate parameter objects:                     */
PE_PROJCS PEAPI pe_projcs_clone_alterunits(
		   PE_PROJCS projcs,
		   PE_UNIT   linear_unit,
		   PE_UNIT   angular_unit);

/* Load projection constants for a PCS                                        */
int PEAPI pe_projcs_load_constants(
	     PE_PROJCS projcs);

/* Unload projection constants for a PCS                                      */
void PEAPI pe_projcs_unload_constants(
	      PE_PROJCS projcs);

/* Are projection constants for a PCS loaded?                                 */
int PEAPI pe_projcs_isconstloaded(
	     PE_PROJCS projcs);


/*----------------------------------------------------------------------------*/
/*                      P C S   I N F O R M A T I O N                         */
/*----------------------------------------------------------------------------*/

/* PCS (PROJCS) information structure type */
typedef struct pe_pcsinfo_t
{
   double   central_meridian;
   unsigned north_pole_location : 2;
   unsigned north_pole_geometry : 2;
   unsigned south_pole_location : 2;
   unsigned south_pole_geometry : 2;
   unsigned is_horizon_edge_duplicated : 1;
   unsigned is_horizon_convex_hull : 1;
   unsigned is_entire_world : 1;
   unsigned is_densification_needed : 1;
} *PE_PCSINFO;

/* Enums of pole locations and geometries for a pcsinfo structure */
enum pole_location_enum {PE_POLE_OUTSIDE_BOUNDARY, PE_POLE_ON_BOUNDARY,
                         PE_POLE_INSIDE_BOUNDARY};
enum pole_geometry_enum {PE_POLE_NONE, PE_POLE_POINT,
                         PE_POLE_LINE_STRAIGHT, PE_POLE_LINE_CURVED};

PE_PCSINFO PEAPI pe_pcsinfo_generate(
                    PE_PROJCS projcs);

void PEAPI pe_pcsinfo_del(
              PE_PCSINFO pcsinfo);


/*----------------------------------------------------------------------------*/
/*                    C O O R D I N A T E   S Y S T E M S                     */
/*----------------------------------------------------------------------------*/

/* Abstract supertype for PE_GEOGCS and PE_PROJCS:                            */
typedef struct pe_struct_t *PE_COORDSYS;

/* Release memory previously allocated by function pe_{geogcs|projcs}_new():  */
void PEAPI pe_coordsys_del(
	      PE_COORDSYS coordsys);

/* Put an external representation of a coordinate system into array buffer[]: */
void PEAPI pe_coordsys_to_string(
	      PE_COORDSYS coordsys,
	      char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a coord. system:   */
PE_COORDSYS PEAPI pe_coordsys_from_string(
		     const char *buffer);

/* Test if argument p points to a coordinate system:                          */
int PEAPI pe_coordsys_p(
	     struct pe_struct_t *p);

/* Test if two coordinate systems are identical:                              */
int PEAPI pe_coordsys_eq(
	     PE_COORDSYS coordsys1,
	     PE_COORDSYS coordsys2);

/* Clone a coordinate system:                                                 */
PE_COORDSYS PEAPI pe_coordsys_clone(
		     PE_COORDSYS coordsys);

/*----------------------------------------------------------------------------*/
/*            G E O G R A P H I C   T R A N S F O R M A T I O N S             */
/*----------------------------------------------------------------------------*/
typedef struct pe_struct_t *PE_GEOGTRAN;

/* Create a new geographic transformation (GT):                               */
PE_GEOGTRAN PEAPI pe_geogtran_new(
		     const char *name,
		     PE_GEOGCS geogcs1,
		     PE_GEOGCS geogcs2,
		     PE_METHOD method,
		     PE_PARAMETER parameters[PE_PARM_MAX]);

/* Release memory previously allocated by function pe_geogtran_new():         */
void PEAPI pe_geogtran_del(
	      PE_GEOGTRAN geogtran);

/* Retrieve a GT's name into array name[]:                                    */
void PEAPI pe_geogtran_name(
	      PE_GEOGTRAN geogtran,
	      char name[PE_NAME_MAX]);

/* Retrieve a GT's 1st GCS and return it:                                     */
PE_GEOGCS PEAPI pe_geogtran_geogcs1(
		   PE_GEOGTRAN geogtran);

/* Retrieve a GT's 2nd GCS and return it:                                     */
PE_GEOGCS PEAPI pe_geogtran_geogcs2(
		   PE_GEOGTRAN geogtran);

/* Retrieve a GT's method and return it:                                      */
PE_METHOD PEAPI pe_geogtran_method(
		   PE_GEOGTRAN geogtran);

/* Retrieve a GT's parameters into array parameters[]:                        */
void PEAPI pe_geogtran_parameters(
	      PE_GEOGTRAN geogtran,
	      PE_PARAMETER parameters[PE_PARM_MAX]);

/* Retrieve GT build status code and return it:                               */
unsigned char PEAPI pe_geogtran_status(
                       PE_GEOGTRAN geogtran);

/* Put an external representation of a GT into array buffer[]:                */
void PEAPI pe_geogtran_to_string(
	      PE_GEOGTRAN geogtran,
	      char buffer[PE_BUFFER_MAX]);

/* Convert an external representation found in buffer into a GT:              */
PE_GEOGTRAN PEAPI pe_geogtran_from_string(
		     const char *buffer);

/* Test if argument p points to a GT:                                         */
int PEAPI pe_geogtran_p(
	     struct pe_struct_t *p);

/* Test if two GTs are identical:                                             */
int PEAPI pe_geogtran_eq(
	     PE_GEOGTRAN geogtran1,
	     PE_GEOGTRAN geogtran2);

/* Clone a GT:                                                                */
PE_GEOGTRAN PEAPI pe_geogtran_clone(
		     PE_GEOGTRAN geogtran);

/* Load constants for a geographic transform                                  */
int PEAPI pe_geogtran_load_constants(
	     PE_GEOGTRAN geogtran);

/* Unload constants for a geographic transform                                */
void PEAPI pe_geogtran_unload_constants(
	      PE_GEOGTRAN geogtran);

/* Are constants for a geographic transform loaded?                           */
int PEAPI pe_geogtran_isconstloaded(
	     PE_GEOGTRAN geogtran);

/*----------------------------------------------------------------------------*/
/*                               A C T I O N S                                */
/*----------------------------------------------------------------------------*/

/* Transform coordinates from a geographic to projected coordinate system:    */
int PEAPI pe_geog_to_proj(
	     PE_PROJCS projcs,
	     int n,
	     double coord[][2]);

/* Transform coordinates from a projected to geographic coordinate system:    */
int PEAPI pe_proj_to_geog(
	     PE_PROJCS projcs,
	     int n,
	     double coord[][2]);

/* Transform coordinates from a geographic to geographic coordinate system:   */
int PEAPI pe_geog1_to_geog2(
	     PE_GEOGTRAN geogtran,
	     int n,
	     double coord[][2],
	     double h[]);

int PEAPI pe_geog2_to_geog1(
	     PE_GEOGTRAN geogtran,
	     int n,
	     double coord[][2],
	     double h[]);

/* Transform geographic coordinates to an MGRS designation:                   */
int PEAPI pe_geog_to_mgrs(
	     PE_GEOGCS geogcs,
	     int       n,
	     double    coord[][2],
	     int       num_digits,
	     int       numeric_rounding,
	     char      *mgrs_str[]);

int PEAPI pe_geog_to_mgrs_extended(
	     PE_GEOGCS geogcs,
	     int       n,
	     double    coord[][2],
	     int       num_digits,
	     int       numeric_rounding,
	     int       mode,
	     char      *mgrs_str[]);

/* Transform MGRS designations to geographic coordinates:                     */
int PEAPI pe_mgrs_to_geog(
	     PE_GEOGCS geogcs,
	     int       n,
	     char      *mgrs_str[],
	     double    coord[][2]);

int PEAPI pe_mgrs_to_geog_extended(
	     PE_GEOGCS geogcs,
	     int       n,
	     char      *mgrs_str[],
	     int       mode,
	     double    coord[][2]);

/* Generate a geogcs horizon for a projected coordinate system and return it: */
PE_HORIZON PEAPI pe_generate_horizon(
                   PE_PROJCS projcs);

/* Generate a projcs horizon for a projected coordinate system and return it: */
PE_HORIZON PEAPI pe_horizon_pcs_generate(
                    PE_PROJCS projcs);

/* Generate a raster geogcs horizon for a projected coordinate system and return it: */
PE_HORIZON PEAPI pe_horizon_gcs_raster_generate(
                    PE_PROJCS projcs);

/* Generate a raster projcs horizon for a projected coordinate system and return it: */
PE_HORIZON PEAPI pe_horizon_pcs_raster_generate(
                    PE_PROJCS projcs);

/* Release memory previously allocated by function pe_generate_horizon():     */
void PEAPI pe_horizon_del(
              PE_HORIZON horizon);

/*----------------------------------------------------------------------------*/
/*                          M A T H E M A T I C S                             */
/*----------------------------------------------------------------------------*/

/* Longitude adjustment:                                                      */
double PEAPI pe_delta(double lam);

/* Comparison with tolerance:                                                 */
int PEAPI pe_eq(double u, double v);

/* Auxiliary function:                                                        */
double PEAPI pe_w(double e2, double phi);

/* Meridional radius of curvature:                                            */
double PEAPI pe_m(double a, double e2, double phi);

/* Transverse radius of curvature:                                            */
double PEAPI pe_n(double a, double e2, double phi);

/* Conformal latitude:                                                        */
double PEAPI pe_phi_to_chi(double e2, double phi);

/* Inverse conformal latitude:                                                */
double PEAPI pe_chi_to_phi(double e2, double chi);

/* Authalic latitude:                                                         */
double PEAPI pe_phi_to_beta(double e2, double phi);

/* Inverse authalic latitude:                                                 */
double PEAPI pe_beta_to_phi(double e2, double beta);

/* Rectifying latitude:                                                       */
double PEAPI pe_phi_to_mu(double e2, double phi);

/* Inverse rectifying latitude:                                               */
double PEAPI pe_mu_to_phi(double e2, double mu);

/* Parametric (reduced) latitude:                                             */
double PEAPI pe_phi_to_eta(double e2, double phi);

/* Inverse parametric (reduced) latitude:                                     */
double PEAPI pe_eta_to_phi(double e2, double eta);

/* Geocentric latitude:                                                       */
double PEAPI pe_phi_to_phig(double e2, double phi);

/* Inverse geocentric latitude:                                               */
double PEAPI pe_phig_to_phi(double e2, double phig);

/* Authalic radius:                                                           */
double PEAPI pe_auth_r(double a, double e2);

/* Meridional distance:                                                       */
double PEAPI pe_q(double a, double e2, double phi);

/* Meridional quadrant:                                                       */
double PEAPI pe_q90(double a, double e2);

/* Transformation from curvilinear to cartesian coordinates:                  */
void PEAPI pe_curv_to_cart(double a, double e2,
                           double phi, double lam, double h,
                           double *x, double *y, double *z );

/* Transformation from cartesian to curvilinear coordinates:                  */
void PEAPI pe_cart_to_curv(double a, double e2,
                           double x, double y, double z,
                           double *phi, double *lam, double *h);

/* Find geodesic distance and azimuth given two geodetic coordinates:         */
void PEAPI pe_geodesic_distance(double a,     double e2,
                                double lam1,  double phi1,
                                double lam2,  double phi2,
                                double *distance,
                                double *az12, double *az21);

/* Find destination geodetic coordinate given origin coordinate, 
                                              geodesic distance, and azimuth: */
void PEAPI pe_geodesic_coordinate(double a,        double e2,
                                  double lam1,     double phi1,
                                  double distance, double az12,
                                  double *lam2,    double *phi2);

#ifdef __cplusplus
};
#endif

#endif
