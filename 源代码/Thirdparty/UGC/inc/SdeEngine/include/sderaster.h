/* $Id: sderaster.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
/***********************************************************************
*
*N  {sderaster.h}  --  SDE Raster Data Types/Defines Header File
*
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*P  Purpose:
* 
*       SDE Raster Data Types/Defines Header File
*
*   COPYRIGHT 1992-2005 ESRI
*
*   TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
*   Unpublished material - all rights reserved under the
*   Copyright Laws of the United States.
*
*   For additional information, contact:
*   Environmental Systems Research Institute, Inc.
*   Attn: Contracts Dept
*   380 New York Street
*   Redlands, California, USA 92373
*
*   email: contracts@esri.com
*   
*E
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*H  History:
*
*E
***********************************************************************/

#ifndef SDE_RASTER
#define SDE_RASTER

#ifdef __cplusplus
extern "C" {
#endif


/************************************************************
*** SDE RASTER COLUMN HANDLE
************************************************************/

typedef struct _SE_RasterColumnRecord *SE_RASCOLINFO;


/************************************************************
*** SDE RASTER COLUMN HANDLE
************************************************************/

typedef struct _SE_RasterBandRecord *SE_RASBANDINFO;


/************************************************************
*** SDE RASTER COLUMN HANDLE
************************************************************/

typedef struct _SE_RasterRecord *SE_RASTERINFO;


/************************************/
/***  Time Modes for Raster Band  ***/
/************************************/

#define SE_RASTERBAND_CREATED     1
#define SE_RASTERBAND_MODIFIED    2

/************************************/
/***  Image Pyramid Auto Level   ****/
/************************************/

#define SE_PYRAMID_AUTO_LEVEL     -1

/************************************/
/***  Pixel Type in Raster Band   ***/
/************************************/

#define SE_PIXEL_TYPE_1BIT              0x008
#define SE_PIXEL_TYPE_4BIT              0x020
#define SE_PIXEL_TYPE_8BIT_U            0x040
#define SE_PIXEL_TYPE_8BIT_S            0x041
#define SE_PIXEL_TYPE_16BIT_U           0x080
#define SE_PIXEL_TYPE_16BIT_S           0x081
#define SE_PIXEL_TYPE_32BIT_U           0x100 
#define SE_PIXEL_TYPE_32BIT_S           0x101
#define SE_PIXEL_TYPE_32BIT_REAL        0x102
#define SE_PIXEL_TYPE_64BIT_REAL        0x200

/*****************************************************/
/***  Macro to obtain BitsPerPixel from Pixel Type ***/
/*****************************************************/

#define SE_PIXEL_TYPE_GET_DEPTH(type)    ((type) >> 3) 

/*****************************************/
/***  Compression Type in Raster Band  ***/
/*****************************************/

typedef enum 
{
  SE_COMPRESSION_NONE = 0,
  SE_COMPRESSION_LZ77,
  SE_COMPRESSION_JPEG,
  SE_COMPRESSION_JP2
} SE_COMPRESSION_TYPE;

#define SE_COMPRESSION_SET_PARAM_VALUE(type,value) \
  type = ((type) & 0x0000FFFF) | ((value) << 16)

/****************************************/
/***  Geodatabase Raster Layer Type   ***/
/****************************************/

#ifdef SE_GDBTYPE_NONE
#undef SE_GDBTYPE_NONE
#endif

#define SE_GDBTYPE_NONE       0
#define SE_GDBTYPE_RASTERMAP  1

/*******************************************************/
/*** SDE RASTER TILE HANDLE "SE_RASTILEINFO"         ***/
/*******************************************************/

typedef struct _SE_RasterTileRecord  *SE_RASTILEINFO;

/*******************************************************/
/*** SDE RASTER CONSTRAINT HANDLE "SE_RASCONSTRAINT" ***/
/*******************************************************/

typedef struct _SE_RasterConstraintRecord  *SE_RASCONSTRAINT;

/*******************************************************/
/*** SDE RASTER BUFFER HANDLE "SE_RASTERBUFFER"      ***/
/*******************************************************/

typedef struct _RasterBufferRecord  *SE_RASTERBUFFER;

/***************************************************/
/*** SDE RASTER ATTRIBUTE HANDLE "SE_RASTERATTR" ***/
/***************************************************/

typedef struct _SE_RasterAttrRecord  *SE_RASTERATTR;


/*
 * ==========================================================================
 *
 * THE FOLLOWING FUNCTIONS ARE FOR PUBLIC USE.
 *
 * ==========================================================================
 */

/* Raster column info object functions */

extern LONG SDEAPI SE_rascolinfo_create (SE_RASCOLINFO       *rastercolumn);
extern void SDEAPI SE_rascolinfo_free   (SE_RASCOLINFO       rastercolumn);

extern LONG SDEAPI SE_rascolinfo_get_id (const SE_RASCOLINFO rastercolumn,
                                         LONG                *rastercolumn_id);
extern LONG SDEAPI SE_rascolinfo_get_access 
                                        (const SE_RASCOLINFO rastercolumn,
                                         LONG                *privileges);
extern LONG SDEAPI SE_rascolinfo_get_creation_date 
                                        (const SE_RASCOLINFO rastercolumn,
                                         struct tm           *date);
extern LONG SDEAPI SE_rascolinfo_get_creation_keyword 
                                        (const SE_RASCOLINFO rastercolumn,
                                         CHAR                *config_keyword);
extern LONG SDEAPI SE_rascolinfo_set_creation_keyword 
                                        (SE_RASCOLINFO       rastercolumn,
                                         const CHAR          *config_keyword);
extern LONG SDEAPI SE_rascolinfo_get_description 
                                        (const SE_RASCOLINFO rastercolumn,
                                         CHAR                *description);
extern LONG SDEAPI SE_rascolinfo_set_description 
                                        (SE_RASCOLINFO       rastercolumn,
                                         const CHAR          *description);
extern LONG SDEAPI SE_rascolinfo_get_raster_column 
                                        (const SE_RASCOLINFO rastercolumn,
                                         CHAR                *table,
                                         CHAR                *raster_column);
extern LONG SDEAPI SE_rascolinfo_set_raster_column 
                                        (SE_RASCOLINFO       rastercolumn,
                                         const CHAR          *table,
                                         const CHAR          *raster_column);
extern LONG SDEAPI SE_rascolinfo_get_minimum_id 
                                        (const SE_RASCOLINFO rastercolumn,
                                         ULONG               *minimum_id);
extern LONG SDEAPI SE_rascolinfo_set_minimum_id 
                                        (SE_RASCOLINFO       rastercolumn,
                                         ULONG               minimum_id);
extern LONG SDEAPI SE_rascolinfo_get_coordref 
                                        (const SE_RASCOLINFO rastercolumn,
                                         SE_COORDREF         coordref);
extern LONG SDEAPI SE_rascolinfo_set_coordref 
                                        (SE_RASCOLINFO       rastercolumn,
                                         const SE_COORDREF   coordref);
extern BOOL SDEAPI SE_rascolinfo_has_gdbtype 
                                        (const SE_RASCOLINFO rastercolumn);
extern LONG SDEAPI SE_rascolinfo_get_gdbtype 
                                        (const SE_RASCOLINFO rastercolumn,
                                         UCHAR               *gdbtype);
extern LONG SDEAPI SE_rascolinfo_set_gdbtype 
                                        (SE_RASCOLINFO       rastercolumn,
                                         UCHAR               gdbtype);

/* Raster column object functions */

extern LONG SDEAPI SE_rastercolumn_alter 
                                        (SE_CONNECTION       handle,
                                         const SE_RASCOLINFO rastercolumn);
extern LONG SDEAPI SE_rastercolumn_create      
                                        (SE_CONNECTION       handle,
                                         const SE_RASCOLINFO rastercolumn);
extern LONG SDEAPI SE_rastercolumn_delete 
                                        (SE_CONNECTION       handle,
                                         const CHAR          *table_name,
                                         const CHAR          *raster_column);
extern LONG SDEAPI SE_rastercolumn_truncate 
                                        (SE_CONNECTION       handle,
                                         const CHAR          *table_name,
                                         const CHAR          *raster_column);
extern void SDEAPI SE_rastercolumn_free_info_list 
                                        (LONG                count,
                                         SE_RASCOLINFO       *rascol_list);
extern LONG SDEAPI SE_rastercolumn_get_info_by_name 
                                        (SE_CONNECTION       handle,
                                         const CHAR          *table_name,
                                         const CHAR          *raster_column,
                                         SE_RASCOLINFO       rastercolumn);
extern LONG SDEAPI SE_rastercolumn_get_info_by_id 
                                        (SE_CONNECTION       handle,
                                         LONG                rastercolumn_id,
                                         SE_RASCOLINFO       rastercolumn);
extern LONG SDEAPI SE_rastercolumn_get_info_list 
                                        (SE_CONNECTION       handle,
                                         SE_RASCOLINFO       **rascol_list,
                                         LONG                *count_addr);
extern LONG SDEAPI SE_rastercolumn_grant_access 
                                        (SE_CONNECTION       handle,
                                         const CHAR          *table_name,
                                         const CHAR          *raster_column,
                                         LONG                privilege,
                                         BOOL                grant,
                                         const CHAR          *user);
extern LONG SDEAPI SE_rastercolumn_revoke_access 
                                        (SE_CONNECTION       handle,
                                         const CHAR          *table_name,
                                         const CHAR          *raster_column,
                                         LONG                privilege,
                                         const CHAR          *user);

/* Raster band info object functions */

extern LONG SDEAPI SE_rasbandinfo_create 
                                        (SE_RASBANDINFO        *rasterband);
extern void SDEAPI SE_rasbandinfo_free  (SE_RASBANDINFO        rasterband);
extern LONG SDEAPI SE_rasbandinfo_duplicate 
                                        (const SE_RASBANDINFO  src_rasterband,
                                         SE_RASBANDINFO        tgt_rasterband);
extern LONG SDEAPI SE_rasbandinfo_get_id 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *rasterband_id);
extern LONG SDEAPI SE_rasbandinfo_get_pixel_type 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *pixel_type);
extern LONG SDEAPI SE_rasbandinfo_set_pixel_type 
                                        (SE_RASBANDINFO        rasterband,
                                         LONG                  pixel_type);
extern LONG SDEAPI SE_rasbandinfo_get_compression_type 
                                        (const SE_RASBANDINFO  rasterband,
                                         SE_COMPRESSION_TYPE   *type);
extern LONG SDEAPI SE_rasbandinfo_set_compression_type 
                                        (SE_RASBANDINFO        rasterband,
                                         SE_COMPRESSION_TYPE   compression);
extern LONG SDEAPI SE_rasbandinfo_get_tile_size 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *block_width,
                                         LONG                  *block_height);
extern LONG SDEAPI SE_rasbandinfo_set_tile_size 
                                        (SE_RASBANDINFO        rasterband,
                                         LONG                  block_width,
                                         LONG                  block_height);
extern LONG SDEAPI SE_rasbandinfo_get_rascol_id 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *rascol_id);
extern LONG SDEAPI SE_rasbandinfo_set_rascol_id 
                                        (SE_RASBANDINFO        rasterband,
                                         LONG                  rascol_id);
extern LONG SDEAPI SE_rasbandinfo_get_band_number 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *sequence_nbr);
extern LONG SDEAPI SE_rasbandinfo_set_band_number 
                                        (SE_RASBANDINFO        rasterband,
                                         LONG                  sequence_nbr);
extern LONG SDEAPI SE_rasbandinfo_get_raster_id 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *raster_id);
extern LONG SDEAPI SE_rasbandinfo_get_time 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  which_time,
                                         struct tm             *time);
extern LONG SDEAPI SE_rasbandinfo_get_band_size 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *band_width,
                                         LONG                  *band_height);
extern LONG SDEAPI SE_rasbandinfo_set_band_size 
                                        (SE_RASBANDINFO        rasterband,
                                         LONG                  band_width,
                                         LONG                  band_height);
extern LONG SDEAPI SE_rasbandinfo_get_extent 
                                        (const SE_RASBANDINFO  rasterband,
                                         SE_ENVELOPE           *envelope);
extern LONG SDEAPI SE_rasbandinfo_set_extent 
                                        (SE_RASBANDINFO        rasterband,
                                         const SE_ENVELOPE     *envelope);
extern LONG SDEAPI SE_rasbandinfo_get_max_level 
                                        (const SE_RASBANDINFO  rasterband,
                                         LONG                  *max_level,
                                         BOOL                  *skip_level1);
extern LONG SDEAPI SE_rasbandinfo_set_max_level 
                                        (SE_RASBANDINFO        rasterband,
                                         LONG                  max_level,
                                         BOOL                  skip_level1);
extern LONG SDEAPI SE_rasbandinfo_get_band_name 
                                        (const SE_RASBANDINFO  rasterband,
                                         CHAR                  *band_name);
extern LONG SDEAPI SE_rasbandinfo_set_band_name 
                                        (SE_RASBANDINFO        rasterband,
                                         const CHAR            *band_name);
extern LONG SDEAPI SE_rasbandinfo_get_tile_origin 
                                        (const SE_RASBANDINFO  rasterband,
                                         LFLOAT                *x,
                                         LFLOAT                *y);
extern LONG SDEAPI SE_rasbandinfo_set_bin_function 
                                        (SE_RASBANDINFO        rasterband,
                                         SE_BIN_FUNCTION_TYPE  type,
                                         LONG                  num_bins,
                                         LFLOAT                *bin_table);
extern BOOL SDEAPI SE_rasbandinfo_has_colormap 
                                        (const SE_RASBANDINFO  rasterband);
extern LONG SDEAPI SE_rasbandinfo_set_colormap 
                                        (SE_RASBANDINFO        rasterband,
                                         SE_COLORMAP_TYPE      colormap_type,
                                         SE_COLORMAP_DATA_TYPE data_type,
                                         LONG                  num_entries,
                                         void                  *data);
extern LONG SDEAPI SE_rasbandinfo_get_colormap 
                                        (const SE_RASBANDINFO  rasterband,
                                         SE_COLORMAP_TYPE      *colormap_type,
                                         SE_COLORMAP_DATA_TYPE *data_type,
                                         LONG                  *num_entries,
                                         void                  **data);
extern void SDEAPI SE_rasbandinfo_free_colormap 
                                        (void                  *data);
extern void SDEAPI SE_rasbandinfo_free_stats_histogram 
                                        (LFLOAT                *bin_table,
                                         LFLOAT                *histogram);
extern LONG SDEAPI SE_rasbandinfo_get_stats_min 
                                        (const SE_RASBANDINFO  rasterband,
                                         LFLOAT                *min);
extern LONG SDEAPI SE_rasbandinfo_get_stats_max 
                                        (const SE_RASBANDINFO  rasterband,
                                         LFLOAT                *max);
extern LONG SDEAPI SE_rasbandinfo_get_stats_mean 
                                        (const SE_RASBANDINFO  rasterband,
                                         LFLOAT                *mean);
extern LONG SDEAPI SE_rasbandinfo_get_stats_stddev 
                                        (const SE_RASBANDINFO  rasterband,
                                         LFLOAT                *stddev);
extern LONG SDEAPI SE_rasbandinfo_get_stats_histogram 
                                        (const SE_RASBANDINFO  rasterband,
                                         SE_BIN_FUNCTION_TYPE  *type,
                                         LONG                  *num_bins,
                                         LFLOAT                **bin_table,
                                         LFLOAT                **histogram);
extern BOOL SDEAPI SE_rasbandinfo_has_stats
                                        (const SE_RASBANDINFO  rasterband);
extern void SDEAPI SE_rasbandinfo_free_transform_list 
                                        (SE_TRANSFORMINFO      *transform_list,
                                         LONG                  count);
extern LONG SDEAPI SE_rasbandinfo_set_transform_list 
                                        (SE_RASBANDINFO        rasterband,
                                         const 
                                         SE_TRANSFORMINFO      *transform_list,
                                         LONG                  count); 
extern LONG SDEAPI SE_rasbandinfo_get_transform_list 
                                        (const SE_RASBANDINFO  rasterband,
                                         SE_TRANSFORMINFO      **transform_list,
                                         LONG                  *count);
extern BOOL SDEAPI SE_rasbandinfo_has_transform_list 
                                        (const SE_RASBANDINFO  rasterband);
                                        
/* Raster band object functions */

extern LONG SDEAPI SE_rasterband_alter  (SE_CONNECTION         handle,
                                         const SE_RASBANDINFO  rasterband);
extern LONG SDEAPI SE_rasterband_create (SE_CONNECTION         handle,
                                         const SE_RASBANDINFO  rasterband,
                                         LONG                  *band_id);
extern LONG SDEAPI SE_rasterband_delete (SE_CONNECTION         handle,
                                         const SE_RASBANDINFO  rasterband);
extern void SDEAPI SE_rasterband_free_info_list 
                                        (LONG                  count,
                                         SE_RASBANDINFO        *rasband_list);
extern LONG SDEAPI SE_rasterband_get_info_by_id 
                                        (SE_CONNECTION         handle,
                                         LONG                  rastercolumn_id,
                                         LONG                  rasterband_id,
                                         SE_RASBANDINFO        rasterband);
extern LONG SDEAPI SE_rasterband_get_info_list 
                                        (SE_CONNECTION         handle,
                                         LONG                  rastercolumn_id,
                                         SE_RASBANDINFO        **rasband_list,
                                         LONG                  *count_addr);

/* Raster info object functions */

extern LONG SDEAPI SE_rasterinfo_create (SE_RASTERINFO         *raster);
extern void SDEAPI SE_rasterinfo_free   (SE_RASTERINFO         raster);
extern LONG SDEAPI SE_rasterinfo_duplicate 
                                        (const SE_RASTERINFO   src_raster,
                                         SE_RASTERINFO         tgt_raster);
extern LONG SDEAPI SE_rasterinfo_get_description 
                                        (const SE_RASTERINFO   raster,
                                         CHAR                  *description);
extern LONG SDEAPI SE_rasterinfo_set_description 
                                        (SE_RASTERINFO         raster,
                                         const CHAR            *description);
extern LONG SDEAPI SE_rasterinfo_get_rascol_id 
                                        (const SE_RASTERINFO   raster,
                                         LONG                  *rascol_id);
extern LONG SDEAPI SE_rasterinfo_set_rascol_id 
                                        (SE_RASTERINFO         raster,
                                         LONG                  rascol_id);
extern LONG SDEAPI SE_rasterinfo_get_raster_id 
                                        (const SE_RASTERINFO   raster,
                                         LONG                  *raster_id);

/* Raster object functions */

extern LONG SDEAPI SE_raster_create     (SE_CONNECTION         handle,
                                         const SE_RASTERINFO   raster,
                                         LONG                  *raster_id);
extern LONG SDEAPI SE_raster_delete     (SE_CONNECTION         handle,
                                         const SE_RASTERINFO   raster);

extern LONG SDEAPI SE_raster_get_bands  (SE_CONNECTION         handle,
                                         const SE_RASTERINFO   raster,
                                         SE_RASBANDINFO        **rasband_list,
                                         LONG                  *count_addr);

extern LONG SDEAPI SE_raster_add_band   (SE_CONNECTION         handle,
                                         SE_RASTERINFO         raster,
                                         const SE_RASBANDINFO  rasterband);
extern LONG SDEAPI SE_raster_drop_band  (SE_CONNECTION         handle,
                                         SE_RASTERINFO         raster,
                                         const SE_RASBANDINFO  rasterband);

extern LONG SDEAPI SE_raster_get_info_by_id 
                                        (SE_CONNECTION         handle,
                                         LONG                  rastercolumn_id,
                                         LONG                  raster_id,
                                         SE_RASTERINFO         raster);

/* Raster stream functions */

extern LONG SDEAPI SE_stream_set_raster_constraint
                                        (SE_STREAM              stream,
                                         const SE_RASCONSTRAINT constraint);
extern LONG SDEAPI SE_stream_query_raster_tile 
                                        (SE_STREAM              stream,
                                         const SE_RASCONSTRAINT constraint);
extern LONG SDEAPI SE_stream_get_raster_tile   
                                        (SE_STREAM              stream,
                                         SE_RASTILEINFO         tile_ptr);
extern LONG SDEAPI SE_stream_get_raster (SE_STREAM              stream, 
                                         SHORT                  column, 
                                         SE_RASTERATTR          raster);
extern LONG SDEAPI SE_stream_last_inserted_raster_id
                                        (SE_STREAM              stream,
                                         LONG                   *raster_id);


/* Raster tile info object functions */

extern LONG SDEAPI SE_rastileinfo_create 
                                        (SE_RASTILEINFO         *tile);
extern void SDEAPI SE_rastileinfo_free  (SE_RASTILEINFO         tile);
extern LONG SDEAPI SE_rastileinfo_get_band_id 
                                        (const SE_RASTILEINFO   tile,
                                         LONG                   *band_id);
extern LONG SDEAPI SE_rastileinfo_set_band_id 
                                        (SE_RASTILEINFO         tile,
                                         LONG                   band_id);
extern LONG SDEAPI SE_rastileinfo_get_rowcol
                                        (const SE_RASTILEINFO   tile,
                                         LONG                   *row,
                                         LONG                   *column);
extern LONG SDEAPI SE_rastileinfo_set_rowcol
                                        (SE_RASTILEINFO         tile,
                                         LONG                   row,
                                         LONG                   column);
extern LONG SDEAPI SE_rastileinfo_get_level 
                                        (const SE_RASTILEINFO   tile,
                                         LONG                   *level);
extern LONG SDEAPI SE_rastileinfo_set_level 
                                        (SE_RASTILEINFO         tile,
                                         LONG                   level);
extern LONG SDEAPI SE_rastileinfo_get_pixel_data 
                                        (SE_RASTILEINFO         tile,
                                         void                   **pixels,
                                         LONG                   *length);
extern LONG SDEAPI SE_rastileinfo_set_pixel_data 
                                        (SE_RASTILEINFO         tile,
                                         void                   *pixels,
                                         LONG                   length);

/* Raster constraint object functions */

extern LONG SDEAPI SE_rasconstraint_create 
                                        (SE_RASCONSTRAINT  *handle);
extern void SDEAPI SE_rasconstraint_free 
                                        (SE_RASCONSTRAINT  handle);
extern LONG SDEAPI SE_rasconstraint_reset 
                                        (SE_RASCONSTRAINT  handle);
extern LONG SDEAPI SE_rasconstraint_set_bands 
                                        (SE_RASCONSTRAINT  handle,
                                         LONG              num_bands,
                                         LONG              *band_nbr);
extern LONG SDEAPI SE_rasconstraint_set_envelope 
                                        (SE_RASCONSTRAINT  handle,
                                         LONG              minx,
                                         LONG              miny,
                                         LONG              maxx,
                                         LONG              maxy);
extern LONG SDEAPI SE_rasconstraint_set_level 
                                        (SE_RASCONSTRAINT  handle,
                                         LONG              level);
extern LONG SDEAPI SE_rasconstraint_set_interleave 
                                        (SE_RASCONSTRAINT  handle,
                                         SE_RASTER_INTERLEAVE_TYPE interleave);

/* Raster attribute object functions */

extern LONG SDEAPI SE_rasterattr_create (SE_RASTERATTR         *handle,
                                         BOOL                  input_mode);
extern void SDEAPI SE_rasterattr_free   (SE_RASTERATTR         handle);

extern LONG SDEAPI SE_rasterattr_set_image_size 
                                        (SE_RASTERATTR         handle,
                                         LONG                  band_width,
                                         LONG                  band_height,
                                         LONG                  num_bands);
extern LONG SDEAPI SE_rasterattr_set_tile_size 
                                        (SE_RASTERATTR         handle,
                                         LONG                  tile_width,
                                         LONG                  tile_height);
extern LONG SDEAPI SE_rasterattr_set_pixel_type 
                                        (SE_RASTERATTR         handle,
                                         LONG                  pixel_type);
extern LONG SDEAPI SE_rasterattr_set_callback 
                                        (SE_RASTERATTR         handle,
                                         SE_RASTER_PROC        callback,
                                         void                  *context);
extern LONG SDEAPI SE_rasterattr_get_raster_info 
                                        (SE_RASTERATTR         handle,
                                         SE_RASTERINFO         *raster);
extern LONG SDEAPI SE_rasterattr_get_image_size 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *band_width,
                                         LONG                  *band_height,
                                         LONG                  *num_bands);
extern LONG SDEAPI SE_rasterattr_get_tile_size 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *tile_width,
                                         LONG                  *tile_height);
extern LONG SDEAPI SE_rasterattr_get_pixel_type 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *pixel_type);
extern LONG SDEAPI SE_rasterattr_get_max_level 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *max_level,
                                         BOOL                  *skip_level1);
extern LONG SDEAPI SE_rasterattr_get_rasterband_info 
                                        (SE_RASTERATTR         handle,
                                         SE_RASBANDINFO        *rasterband,
                                         LONG                  index);
extern LONG SDEAPI SE_rasterattr_get_num_bands 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *num_bands);
extern LONG SDEAPI SE_rasterattr_get_rasterband_info_list 
                                        (SE_RASTERATTR         handle,
                                         SE_RASBANDINFO        **rasbnd_list,
                                         LONG                  *count);
extern LONG SDEAPI SE_rasterattr_get_rascol_id 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *rascol_id);
extern LONG SDEAPI SE_rasterattr_get_raster_id 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *raster_id);
extern LONG SDEAPI SE_rasterattr_set_extent 
                                        (SE_RASTERATTR         handle,
                                         const SE_ENVELOPE     *envelope);
extern LONG SDEAPI SE_rasterattr_get_extent 
                                        (SE_RASTERATTR         handle,
                                         SE_ENVELOPE           *envelope);
extern LONG SDEAPI SE_rasterattr_set_mosaic_mode 
                                        (SE_RASTERATTR         handle,
                                         LONG                  mode);
extern LONG SDEAPI SE_rasterattr_set_mask_mode 
                                        (SE_RASTERATTR         handle,
                                         BOOL                  mode);
extern LONG SDEAPI SE_rasterattr_get_tile_origin 
                                        (SE_RASTERATTR         handle,
                                         LFLOAT                *x,
                                         LFLOAT                *y);
extern LONG SDEAPI SE_rasterattr_get_image_size_by_level 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *width,
                                         LONG                  *height,
                                         LONG                  *offset_x,
                                         LONG                  *offset_y,
                                         LONG                  *num_bands,
                                         LONG                  level);
extern LONG SDEAPI SE_rasterattr_get_extent_by_level 
                                        (SE_RASTERATTR         handle,
                                         SE_ENVELOPE           *envelope,
                                         LFLOAT                *offset_x,
                                         LFLOAT                *offset_y,
                                         LONG                  level);
extern LONG SDEAPI SE_rasterattr_set_pyramid_info 
                                        (SE_RASTERATTR         handle,
                                         LONG                  max_level,
                                         BOOL                  skip_level1,
                                         SE_INTERPOLATION_TYPE interpolation);
extern LONG SDEAPI SE_rasterattr_get_pyramid_info 
                                        (SE_RASTERATTR         handle,
                                         LONG                  *max_level,
                                         BOOL                  *skip_level1,
                                         SE_INTERPOLATION_TYPE *interpolation);
extern LONG SDEAPI SE_rasterattr_set_colormap 
                                        (SE_RASTERATTR         handle,
                                         SE_COLORMAP_TYPE      colormap_type,
                                         SE_COLORMAP_DATA_TYPE data_type,
                                         LONG                  num_entries,
                                         const void            *data);
extern LONG SDEAPI SE_rasterattr_set_compression_type 
                                        (SE_RASTERATTR         handle,
                                         SE_COMPRESSION_TYPE   compression);
extern LONG SDEAPI SE_rasterattr_get_compression_type 
                                        (SE_RASTERATTR         handle,
                                         SE_COMPRESSION_TYPE   *type);
extern LONG SDEAPI SE_rasterattr_set_compression_property 
                                        (SE_RASTERATTR         handle,
                                         const CHAR            *name,
                                         void                  *value);
extern LONG SDEAPI SE_rasterattr_get_compression_property 
                                        (SE_RASTERATTR         handle,
                                         const CHAR            *name,
                                         void                  *value);
extern LONG SDEAPI SE_rasterattr_set_pyramid_property
                                        (SE_RASTERATTR         handle,
                                         const CHAR            *name,
                                         void                  *value);
extern LONG SDEAPI SE_rasterattr_get_pyramid_property
                                        (SE_RASTERATTR         handle,
                                         const CHAR            *name,
                                         void                  *value);
extern LONG SDEAPI SE_rasterattr_set_image_origin
                                        (SE_RASTERATTR         handle,
                                         LFLOAT                x,
                                         LFLOAT                y);

#ifdef __cplusplus
};
#endif

#endif

