/*******************************************************************/
/*                                                                 */
/*               Copyright (C) 2006 SafeNet, Inc.                  */
/*                      All Rights Reserved                        */
/*                                                                 */
/*     This Module contains Proprietary Information of SafeNet     */
/*          Inc., and should be treated as Confidential.           */
/*******************************************************************/

#ifndef _LSERV_H_
#define _LSERV_H_

/*H****************************************************************
* FILENAME    : lserv.h
*
* DESCRIPTION :
*           Contains public function prototypes, macros and defines
*           needed for licensing an app using Sentinel RMS Developer 
*           Kit library.
* USAGE       :
*           This file should be included by all users of Sentinel RMS 
*           Developer Kit client library.
* NOTES       :
*
*H*/

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>     /* For definition of FILE*  */
#include <time.h>

/*
 * Developer can compile with LSNOPROTO to force no prototyping.
 */

#if defined(_VWIN95_) || defined(_VWINNT_) || defined(_VWINCE_)
  /* 32-bit MS Windows application */
  /* This section is for internal use.  Do not define _VWIN95_ or _VWINNT_ */
# define VMSWINAPI
# define LSFAR
#ifdef _SLMSLIB_
#  define VDLL32
#else
#  define VDLL32    __declspec(dllexport)
#endif /* _SLMSLIB_ */
#else /* (_VWIN95_) || (_VWINNT_) || (_VWINCE_) */
# define VMSWINAPI
# define LSFAR
# define VDLL32
#endif /* MS Windows */

#if defined(_VMSWIN_) || defined (WIN32)
#pragma pack(push, 1)
#endif /*_VMSWIN_*/

/*------------------------------------------------------------------------*/
/* To inactivate licensing completely, use the following macro which      */
/* will make all Sentinel RMS Development Kit functions void:                        */
/*------------------------------------------------------------------------*/

/*
#define NO_LICENSE
*/

/*------------------------------------------------------------------------*/
/* LSAPI constants                                                        */
/*------------------------------------------------------------------------*/

#define  LS_DEFAULT_UNITS          (unsigned long)0xFFFFFFFF
#define  LS_ANY                    ((unsigned char LSFAR *)NULL)
#define  LS_USE_LAST               (unsigned long)0x0800FFFF

/*------------------------------------------------------------------------*/
/* Standalone mode constants                                              */
/*------------------------------------------------------------------------*/

#define VLS_STANDALONE             "no-net"
#define VLS_NETWORK_MODE              0
#define VLS_STANDALONE_MODE           1
#define VLS_PERPETUAL_MODE            2
#define VLS_INVALID_STANDALONE_FLAG  -1


/*------------------------------------------------------------------------*/
/* Trace level                                                            */
/*------------------------------------------------------------------------*/

#define VLS_NO_TRACE               1  /* This is the default value */
#define VLS_TRACE_KEYS             2
#define VLS_TRACE_FUNCTIONS        4
#define VLS_TRACE_ERRORS           8
#define VLS_TRACE_ALL              16

/*------------------------------------------------------------------------*/
/* Error handling                                                         */
/*------------------------------------------------------------------------*/

#define VLS_ON                     1  /* This is the default value */
#define VLS_OFF                    0

/*------------------------------------------------------------------------*/
/* Error handling                                                         */
/*------------------------------------------------------------------------*/
#define VLS_EH_SET_ALL             0

/*------------------------------------------------------------------------*/
/* True/False                                                             */
/*------------------------------------------------------------------------*/

#define VLS_TRUE                   0
#define VLS_FALSE                  1

/*------------------------------------------------------------------------*/
/*  Licnse Type flags                                                     */
/*------------------------------------------------------------------------*/
#define VLS_TRIAL_LIC                    1
#define VLS_NORMAL_LIC                   0
/*------------------------------------------------------------------------*/
/*  elan key flag                                                         */
/*------------------------------------------------------------------------*/
#define VLS_ELAN_CONVERTED_CODE          1
#define VLS_SLM_CODE                     0
/*------------------------------------------------------------------------*/
/*  Commuter lic                                                          */
/*------------------------------------------------------------------------*/
#define VLS_COMMUTED_CODE                 2
#define VLS_ISSUE_COMMUTER_CODES          1
#define VLS_NOT_ISSUE_COMMUTER_CODES      0
#define VLS_COMMUTERDAYS_UNRESTRICTED     0
/*------------------------------------------------------------------------*/
/*  Redundant flag                                                        */
/*------------------------------------------------------------------------*/
#define  VLS_REDUNDANT_CODE               1
#define  VLS_NON_REDUNDANT_CODE           0
/*------------------------------------------------------------------------*/
/*  Majority rule flag                                                    */
/*------------------------------------------------------------------------*/
 
#define VLS_MAJORITY_RULE_FOLLOWS         1
#define VLS_MAJORITY_RULE_NOT_FOLLOWS     0
/*------------------------------------------------------------------------*/
/* Sharing criteria                                                       */
/*------------------------------------------------------------------------*/

#define VLS_NO_SHARING                    0
#define VLS_USER_NAME_ID                  1
#define VLS_CLIENT_HOST_NAME_ID           2
#define VLS_X_DISPLAY_NAME_ID             3
#define VLS_VENDOR_SHARED_ID              4
#define VLS_NO_SHARING_STRING            "0"
#define VLS_USER_NAME_ID_STRING          "1"
#define VLS_CLIENT_HOST_NAME_ID_STRING   "2"
#define VLS_X_DISPLAY_NAME_ID_STRING     "3"
#define VLS_VENDOR_SHARED_ID_STRING      "4"
/*------------------------------------------------------------------------*/
/* Team creation criteria                                                 */
/*------------------------------------------------------------------------*/

#define VLS_NO_TEAM                       VLS_NO_SHARING
#define VLS_USER_NAME_BASED_TEAM          VLS_USER_NAME_ID
#define VLS_HOST_NAME_BASED_TEAM          VLS_CLIENT_HOST_NAME_ID
#define VLS_X_DISPLAY_BASED_TEAM          VLS_X_DISPLAY_NAME_ID
#define VLS_VENDOR_DEFINED_TEAM           VLS_VENDOR_SHARED_ID

#define VLS_NO_TEAM_STRING                VLS_NO_SHARING_STRING
#define VLS_USER_NAME_BASED_TEAM_STRING   VLS_USER_NAME_ID_STRING
#define VLS_HOST_NAME_BASED_TEAM_STRING   VLS_CLIENT_HOST_NAME_ID_STRING
#define VLS_X_DISPLAY_BASED_TEAM_STRING   VLS_X_DISPLAY_NAME_ID_STRING
#define VLS_VENDOR_DEFINED_TEAM_STRING    VLS_VENDOR_SHARED_ID_STRING

/*------------------------------------------------------------------------*/



/*------------------------------------------------------------------------*/
/* Holding criteria                                                       */
/*------------------------------------------------------------------------*/

#define VLS_HOLD_NONE              0
#define VLS_HOLD_VENDOR            1
#define VLS_HOLD_CODE              2
#define VLS_HOLD_NONE_STRING      "0"
#define VLS_HOLD_VENDOR_STRING    "1"
#define VLS_HOLD_CODE_STRING      "2"

/*------------------------------------------------------------------------*/
/* Client-server lock mode                                                */
/*------------------------------------------------------------------------*/

#define VLS_NODE_LOCKED            0
#define VLS_FLOATING               1
#define VLS_DEMO_MODE              2
#define VLS_CLIENT_NODE_LOCKED     3

/*------------------------------------------------------------------------*/
/* Locking criteria                                                       */
/*------------------------------------------------------------------------*/

/* Test whether a particular locking criterion is being used. */
#define VLS_LOCK_TO_ID_PROM(V)        (( (V) >> 0 ) & 0x1)
#define VLS_LOCK_TO_IP_ADDR(V)        (( (V) >> 1 ) & 0x1)
#define VLS_LOCK_TO_DISK_ID(V)        (( (V) >> 2 ) & 0x1)
#define VLS_LOCK_TO_HOSTNAME(V)       (( (V) >> 3 ) & 0x1)
#define VLS_LOCK_TO_ETHERNET(V)       (( (V) >> 4 ) & 0x1)
#define VLS_LOCK_TO_NW_IPX(V)         (( (V) >> 5 ) & 0x1)
#define VLS_LOCK_TO_NW_SERIAL(V)      (( (V) >> 6 ) & 0x1)
#define VLS_LOCK_TO_PORTABLE_SERV(V)  (( (V) >> 7 ) & 0x1)
#define VLS_LOCK_TO_CUSTOM(V)         (( (V) >> 8 ) & 0x1)
#define VLS_LOCK_TO_CPU(V)            (( (V) >> 9 ) & 0x1)

/* To set a particular locking criterion. */
#define VLS_LOCK_ID_PROM        0x1
#define VLS_LOCK_IP_ADDR        0x2
#define VLS_LOCK_DISK_ID        0x4
#define VLS_LOCK_HOSTNAME       0x8
#define VLS_LOCK_ETHERNET       0x10
#define VLS_LOCK_NW_IPX         0x20
#define VLS_LOCK_NW_SERIAL      0x40
#define VLS_LOCK_PORTABLE_SERV  0x80
#define VLS_LOCK_CUSTOM         0x100
#define VLS_LOCK_CPU            0x200
/* Highest bit currently in use : */
#define VLS_LOCK_HIGHEST_BIT    10    /* Starting from 1... */
/* Mask with all locking criteria set. */
#define VLS_LOCK_ALL            0x3FF
#define VLS_LOCK_NONET          VLS_LOCK_ALL^VLS_LOCK_IP_ADDR^VLS_LOCK_PORTABLE_SERV


/*------------------------------------------------------------------------*/
/* License does not have an expiration date                               */
/*------------------------------------------------------------------------*/

#define VLS_NO_EXPIRATION          -1

/*------------------------------------------------------------------------*/
/* This number represents infinite keys                                   */
/*------------------------------------------------------------------------*/

#define VLS_INFINITE_KEYS          0xffff
#define VLS_INFINITE_KEYS_STRING   ""

/*------------------------------------------------------------------------*/
/* Maximum size of machine finger print of remote machine                 */
/*------------------------------------------------------------------------*/

#define MAX_FINGER_PRINT (sizeof(VLSmachineID)+VLS_LOCK_HIGHEST_BIT)*2+4

/*------------------------------------------------------------------------*/
/* Type definitions                                                       */
/*------------------------------------------------------------------------*/
#if (defined _TRU64_ || defined _V_LP64_)
/* On 64 bit system, these must be 32 bit int */
typedef  unsigned int                     LS_STATUS_CODE;
typedef  unsigned int                     LS_HANDLE;
typedef  unsigned int                     QUEUE_HANDLE;
#else
typedef  unsigned long                     LS_STATUS_CODE;
typedef  unsigned long                     LS_HANDLE;
typedef  unsigned long                     QUEUE_HANDLE;
#endif

#define  VLS_MAX_NAME_LEN  128
#define  VLS_MAX_BUF_LEN   512
#define  VLS_MAX_ENCRYPTION_LEVEL     4
#define  VLS_MAX_CPU_ID_LEN 24


#if !defined(VLS_NOCOMPAT)
#define MAX_NAME_LEN VLS_MAX_NAME_LEN
#define MAX_BUF_LEN  VLS_MAX_BUF_LEN
#define MAX_ENCRYPTION_LEVEL VLS_MAX_ENCRYPTION_LEVEL
#define MAX_CPU_ID_LEN  VLS_MAX_CPU_ID_LEN 
#endif

#define VLS_DISC_NO_OPTIONS       0
#define VLS_DISC_RET_ON_FIRST     1
#define VLS_DISC_PRIORITIZED_LIST 2
#define VLS_DISC_NO_USERLIST      4
#define VLS_DISC_REDUNDANT_ONLY   8
#define VLS_DISC_DEFAULT_OPTIONS  VLS_DISC_NO_OPTIONS

#define NO_RET_ON_FIRST 0
#define RET_ON_FIRST 1

#define VLS_REQ_GET        01
#define VLS_REQ_QUEUE      02
#define VLS_COMMUTER_GET   04
#define VLS_GRACE_REQ      8
/* Don't use this value in your code*/
#define VLS_CAPACITY_GET   8

#define VLS_SERV_LOCALE_STR_LEN   35
#define VLS_SERV_VNDINFO_STR_LEN  50
#define VLS_SERV_PLATFORM_STR_LEN 20
#define VLS_SERV_UNUSED1_STR_LEN  20


#define VLS_GET_ETHERNET        01
#define VLS_GET_CID             02



typedef enum {VLS_LOCAL_UPD_ENABLE, VLS_LOCAL_UPD_DISABLE} VLS_LOC_UPD_STAT;

/* commuter */

#define HOSTID_ARRAY_SIZE           4
 
#define FAIL                        1

#define VLS_CAPACITY_NONE                 0
#define VLS_CAPACITY_NON_POOLED           1
#define VLS_CAPACITY_POOLED               2

#define VLS_INFINITE_CAPACITY             0xffffffff

/* Following is being used in lslic.
 * SLM 7.3.0
 */
#define VLS_NOLIMIT_STRING                  "NOLIMIT"
#define VLS_YES_NO_BUFFER_SIZE              2

/* Following is being used in upgradelockcode
 * SLM 7.3.0
 */


#define ULC_CODE_VERSION                        1
#define BASE_LOCK_CODE_LENGTH                   16
#define VENDOR_HASH_LENGTH                      7
#define VLScg_MAX_CODE_COMP_LEN               512

/*------------------------------------------------------------------------*/
/* Grace Period                                                           */
/*------------------------------------------------------------------------*/
#define VLS_NO_GRACE_PERIOD           0
#define VLS_STANDARD_GRACE_PERIOD     1

/*------------------------------------------------------------------------*/
/*  Grace license installation error handling                        	  */	
/*------------------------------------------------------------------------*/
#define VLS_IGNORE_GRACE_ERROR        0
#define VLS_NOTIFY_GRACE_ERROR        1

/*------------------------------------------------------------------------*/
/* Overdraft License -                                                    */
/*------------------------------------------------------------------------*/
#define VLS_NO_OVERDRAFT        0
#define VLS_STANDARD_OVERDRAFT  1
#define VLS_UNLIMITED_OVERDRAFT_HOURS 0

/*------------------------------------------------------------------------*/
/* Local request locking criteria flag -                                  */
/*------------------------------------------------------------------------*/
#define VLS_LOCAL_REQUEST_LOCKCRIT_USEDEFAULT   0
#define VLS_LOCAL_REQUEST_LOCKCRIT_DEFINED      1

/*------------------------------------------------------------------------*/
/* License revocation defines -                                           */
/*------------------------------------------------------------------------*/
/* This should always be greater than sizeof(VLSrevocationTicketT) */
#define VLS_MAX_LICENSE_REVOCATION_TICKET_SIZE         1024 

/*------------------------------------------------------------------------*/
/* License Versions                                                       */
/*------------------------------------------------------------------------*/
#define VLS_LICENSE_VERSION_NOT_DEFINED 0xffffffff 
#define VLS_LICENSE_VERSION_TOO_OLD    0x00000000 
#define VLS_LICENSE_VERSION_700        0x07000000
#define VLS_LICENSE_VERSION_730        0x07030000
#define VLS_LICENSE_VERSION_7301       0x07030001
#define VLS_LICENSE_VERSION_800        0x08000000
#define VLS_LICENSE_VERSION_LATEST     VLS_LICENSE_VERSION_800 


                                  
/*------------------------------------------------------------------------*/
/* Challenge, ChallengeResponse structs                                   */
/*------------------------------------------------------------------------*/

typedef struct {
  unsigned long   ulReserved;
  unsigned long   ulChallengedSecret;
  unsigned long   ulChallengeSize;
  unsigned char   ChallengeData[30];
} CHALLENGE, LS_CHALLENGE;

typedef struct {
  unsigned long ulResponseSize;
  unsigned char ResponseData[16];
} CHALLENGERESPONSE;

typedef struct { 
    long     wait_time;   /*max time, the client can be in queue */ 
    long     hold_time;   /*After allotement, the maximum time interval 
                            for which the server will keep the requested 
                            units reserved for this client */ 
    int      priority_num;/*Priority vis-a-vis other clients, as decided 
                             by the client application. For use in future. 
                             Not implemented in SLM7.0*/ 
    long     absPosition; /*The maximum position within the queue, 
                             before which the client can be queued. 
                             if the client doesn't care.*/ 
    long     grpPosition; /*The maximum position within the queue, 
                            considering only those queued clients that 
                            belong to the same group to which this client 
                            belongs to, before which the client can be 
                            queued -1 if the client doesn't care.*/ 
} VLSqueuePreference; 

/*------------------------------------------------------------------------*/
/* Client and feature information structures                              */
/* To be used in VLSgetClientInfo, VLSgetFeatureInfo and VLShandleInfo    */
/*------------------------------------------------------------------------*/

#define VLS_MAXFEALEN          64  // For Rainbows Internal use only.
#define VLS_MAXFEALEN_API_USER 25  // For SLM API user to specifying the length of feature name.
#define VLS_MAXLEN        VLS_MAXFEALEN
#define VLS_MAXVERLEN     12    /*11 chars, as allowed for long-codes, plus 1*/
#define VLS_SITEINFOLEN   150
#define VLS_VENINFOLEN    395
#define VLS_VENINFOLEN_OLD 98 /* prior to 7.3.0 version */
#define VLS_MAXCLLOCKLEN  200

#define VLS_MAXSRVLOCKLEN 250 /* To store server lock informations(both primary and secondary)11(servers)x2=22*/

#if !defined(VLS_NOCOMPAT)
#define MAXFEALEN    VLS_MAXFEALEN
#define MAXLEN       VLS_MAXFEALEN
#define MAXVERLEN    VLS_MAXVERLEN     
#define SITEINFOLEN  VLS_SITEINFOLEN
#define VENINFOLEN   VLS_VENINFOLEN
#define MAXCLLOCKLEN VLS_MAXCLLOCKLEN
#endif

/* Client Information structure */
struct client_info_struct {
  char          user_name[VLS_MAXLEN];
  unsigned long host_id;
  char          group[VLS_MAXLEN];
  long          start_time;
  long          hold_time;
  long          end_time;
  long          key_id;
  char          host_name[VLS_MAXLEN];
  char          x_display_name[VLS_MAXLEN];
  char          shared_id_name[VLS_MAXLEN];
  int           num_units;
  int           q_wait_time;
  int           is_holding;             /* VLS_TRUE/VLS_FALSE          */
  int           is_sharing;             /* # of clients using this key */
  int           is_commuted;

  /* Following fields are added to support capacity
   * licenses.
   * SLM 7.3.0
   */
  long          structSz;
  unsigned long team_capacity;      /* Total capacity */
  unsigned long total_resv_team_capacity; /* Total reserved capacity. */
  unsigned long reserved_team_capacity_in_use; /* Capacity given to clients from reserved capacity. */
  unsigned long unreserved_team_capacity_in_use; /* Capacity given to clients from unreserved capacity. */

  
  unsigned long user_capacity_from_reserved;
  unsigned long user_capacity_from_unreserved;

         /*Total units for this license*/ 
  int    total_team_tokens_resv;         /*Total reserved units*/ 
  int    reserved_team_tokens_in_use;      /*Units given from reserved pool to active*/
  int    unreserved_team_tokens_in_use;
  };
typedef  struct client_info_struct         VLSclientInfo;

/* Queued Client Information Struct */
typedef struct queued_client_info_struct { 
  char           user_name[VLS_MAXLEN]; 
  char           host_name[VLS_MAXLEN]; 
  char           x_display_name[VLS_MAXLEN]; 
  char           shared_id_name[VLS_MAXLEN]; 
  char           group_name[VLS_MAXLEN]; 
  unsigned long  host_id; 
  long           server_start_time; 
  long           server_end_time; 
  unsigned long  qkey_id; 
  int            num_units; 
  int            num_resvd_default;
  int            num_resvd_native;
  long           wait_time;   /*in secs*/ 
  long           hold_time;   /*in secs*/ 
  int            priority_num;
  long           absPosition; /*Current abs. position within the queue*/ 
  long           grpPosition; /*Current position within the queue, 
                                considering only those queued clients
                                that belong to the same group to which 
                                this client belongs to */ 
  long           availabilityTime; 
} VLSqueuedClientInfo; 


/* Feature Information structure */
typedef struct  feature_info_struct { 
  long   structSz; 
  char   feature_name[VLS_MAXFEALEN]; 
  char   version[VLS_MAXFEALEN]; 
  int    lic_type; 
  int    trial_days_count; 
  long   birth_day; 
  long   death_day;
  int    num_licenses;       /*Total units for this license*/ 
  int    total_resv;         /*Total reserved units*/ 
  int    lic_from_resv;      /*Units given from reserved pool to active
                               clients*/ 
  int    qlic_from_resv;      /*Units reserved from reserved-pool by 
                               aspirants and engaged clients. */ 
  int    lic_from_free_pool; /*Units given from free pool to active 
                               clients*/ 
  int    qlic_from_free_pool;/*Units reserved from free-pool by aspirants
                               and engaged clients.*/ 
  int    is_node_locked;     /*VLS_FLOATING/VLS_NODE_LOCKED/... */ 
  int    concurrency; 
  int    sharing_crit; 
  int    locking_crit; 
  int    holding_crit; 
  int    num_subnets; 
  char   site_license_info[VLS_SITEINFOLEN]; 
  long   hold_time; 
  int    meter_value; 
  char   vendor_info[VLS_VENINFOLEN + 1 ]; 
  char   cl_lock_info[VLS_MAXCLLOCKLEN]; 
  long   key_life_time; 
  int    sharing_limit; 
  int    soft_num_licenses; 
  int    is_standalone;      /*VLS_STANDALONE_MODE/VLS_NETWORK_MODE/VLS_PERPETUAL_MODE */ 
  int    check_time_tamper; 
  int    is_additive;        /*VLS_TRUE/VLS_FALSE */ 
  int    isRedundant;
  int    majority_rule;
  int    num_servers;
  int    isCommuter;
  int    log_encrypt_level;
  int    elan_key_flag;
  long   conversion_time;
  long   avg_queue_time;     /*whether for past clients or present??? */ 
  long   queue_length; 
  int    tot_lic_reqd;       /*By all queued Clients i.e. units required
                               by bachlores + aspirants -units reserved
                               by aspirants */ 
  int    isELMEnabled;
  int    commuted_keys;      /* number of commuted keys that have been
                                    checked out  */
  int    commuter_keys_left; /* number of commuter keys left */
  char   server_locking_info[VLS_MAXSRVLOCKLEN];    /*new field added for storing the server lock info*/
  int           capacity_flag; /* VLS_CAPACITY_NONE or VLS_CAPACITY_NON_POOLED or VLS_CAPACITY_POOLED */
  unsigned long capacity;      /* Total capacity */
  unsigned long total_resv_capacity; /* Total reserved capacity. */
  unsigned long in_use_capacity_from_reserved; /* Capacity given to clients from reserved capacity. */
  unsigned long in_use_capacity_from_unreserved; /* Capacity given to clients from unreserved capacity. */
  long  commuter_max_checkout_days; 
                           /*Max days license can be checked out. 0=no limit*/
  long  grace_period_flag;  /* Must be VLS_STANDARD_GRACE_PERIOD */
  long  grace_period_calendar_days;
                           /* Max days license can be used in grace period  */
  long  grace_period_elapsed_hours;
                           /* Max hours license can be used in grace period */
  long overdraft_flag;     /* VLS_NO_OVERDRAFT or VLS_STANDARD_OVERDRAFT */
  long overdraft_hours;    /* Max hours overdraft license can be used.       */
  long overdraft_users;    /* Simultaneous users allowed in overdraft      */
  long overdraft_users_in_use; /* Current number of users in overdraft */
  
  int  local_request_lockcrit_flag;
                         /* VLS_LOCAL_REQUEST_LOCKCRIT_DEFINED = use the specified 
                            lockcrit fields below. Otherwise use defaults. 
                            These values are to be used by commuter license, perpetual 
                            licenses and grace period licenses.              */
  int  local_request_lockcrit_required;
                         /* Required items for local request locking. */
  int  local_request_lockcrit_float;
                         /* Floating items for local request locking. */
  int  local_request_lockcrit_min_num;
                         /* Total number of items must for local request locking. */
  int  isGraceLicense; 
                         /* VLS_FALSE, when grace license is not in use, otherwise VLS_TRUE. */
  int  license_version;  /* License version(codegenversion) mapped to slm version. */

} VLSfeatureInfo; 

/* Commuter Information Structure */
typedef struct commuter_info_struct
{
 int        commuter_code_version;
 int        codegen_version;
 char       feature_name[VLS_MAXFEALEN]; /* Feature name */
 char       feature_version[VLS_MAXVERLEN]; /* Feature version */
 int        birth_day;
 int        birth_month;
 int        birth_year;
 int        death_day; /* 1 - 31 */
 int        death_month; /* 1 - 12 */
 int        death_year; /* 91 - ? -- This is basically year - 1900.*/
 int        num_of_licenses;
 int        locking_crit; /* locking criteria of client */
 char       lock_info[VLS_MAXCLLOCKLEN];/*lock info of client */
 char       vendor_info[VLS_VENINFOLEN + 1];
 char       issuing_server[MAX_NAME_LEN]; /* IP addresses if the protocol_type
                                                                is UDP.
                                             IPX addresses if the protocol_type
                                                                      is IPX */
 long        key_life_time;
 int         protocol_type;  /* VLScc_TCP(0)  / VLScc_IPX(1) */
 int         status; /* 1 - ACTIVE
                        0 - INACTIVE */
}VLScommuterInfo;
 

/*------------------------------------------------------------------------*/
/* Client version information structure                                   */
/* To be used in VLSgetLibInfo                                            */
/*------------------------------------------------------------------------*/

/* VLSgetLibInfo() should return the same version string in szVersion: */
/* The LS_VERSION format must be kept as X.YZ as this parameter is used
   in API versioning */
#define LS_VERSION   "8.0.4.0"
#define LS_MAJOR_VERSION "8.0"


#define FILE_VERSION_STRING "8, 0, 4, 0\0"
#define PRODUCT_VERSION_STRING "8, 0, 4, 0\0"
#define FILE_VERSION_MAJOR    8
#define FILE_VERSION_MINOR    0
#define FILE_VERSION_POINT    4
#define FILE_VERSION_BUILD    0
#define PRODUCT_VERSION_MAJOR 8
#define PRODUCT_VERSION_MINOR 0
#define PRODUCT_VERSION_POINT 4
#define PRODUCT_VERSION_BUILD 0

#define LS_PROD_NAME "Sentinel RMS Development Kit"

#define LS_COPYRIGHT \
"    Copyright (C) 2006 SafeNet, Inc.\n\n"

#define LIBINFOLEN  32

typedef struct {
  unsigned long ulInfoCode;
  char          szVersion  [LIBINFOLEN];
  char          szProtocol [LIBINFOLEN];
  char          szPlatform [LIBINFOLEN];
  char          szLocale   [LIBINFOLEN];
  char          szUnused2  [LIBINFOLEN];
} LS_LIBVERSION;

/*------------------------------------------------------------------------*/
/* VLSDiscover info structure to be passed as array in VLSDiscoverExt     */
/* to get the server charateristics information                           */
/*------------------------------------------------------------------------*/

typedef struct {
    short     protocol;      /* bit 1 - IPX, bit 2 - TCP/IP */
    short     isRedundant;   /* server is token sharing type or not */
    int       num_clients;   /* Clients connected to server */
    char      ip_address[VLS_MAXLEN];
    int       num_units_available;
    int       is_served;     /* V_TRUE if already served by this  server,  
                                V_FALSE otherwise */  
    char      pool_name[8];
    long      reserved1;
    long      reserved2;
} discover_info_type, VLSdiscoverInfo;


/* SLM 7.3.0
 * Prototype Code for upgrade code 
 */

typedef struct {
    int version_num;
    char hash_vendor_string[VENDOR_HASH_LENGTH];
    int capacity_flag;
    int standalone_flag;
    unsigned num_keys;
    int birth_day;
    int birth_month;
    int birth_year;
    int death_day;
    int death_month;
    int death_year;
    int client_server_lock_mode;   
    unsigned char base_lock_code[BASE_LOCK_CODE_LENGTH + 1];

    /* For internal use */
    char base_feature_name[VLScg_MAX_CODE_COMP_LEN + 1];
    char base_feature_version[VLScg_MAX_CODE_COMP_LEN + 1];
    unsigned long capacity;

} ulcCode;

/*------------------------------------------------------------------------*/
/* Macros for status codes                                                */
/* prefix LS  :  LSAPI status codes                                       */
/* prefix VLS :  Our own status codes                                     */
/*------------------------------------------------------------------------*/

/* The function completed successfully                                    */
#define LS_SUCCESS                   0x0

/* Handle used on call did not describe a valid licensing system context  */
#define LS_BADHANDLE                 (LS_STATUS_CODE)0xC8001001

/* Licensing system could not locate enough available licensing resources */
/* to satisfy the request                                                 */
#define LS_INSUFFICIENTUNITS         (LS_STATUS_CODE)0xC8001002

/* No licensing system could be found with which to perform the function  */
/* invoked                                                                */
#define LS_LICENSESYSNOTAVAILABLE    (LS_STATUS_CODE)0xC8001003

/* The licensing system has determined that the resources used to satisfy */
/* a previous request are no longer granted to the calling software       */
#define LS_LICENSETERMINATED         (LS_STATUS_CODE)0xC8001004

/* The licensing system has no licensing resources that could satisfy the */
/* request.                                                               */
#define LS_NOAUTHORIZATIONAVAILABLE  (LS_STATUS_CODE)0xC8001005

/* The licensing system has licensing resources that could satisfy the    */
/* request, but they are not available at the time of the request         */
#define LS_NOLICENSESAVAILABLE       (LS_STATUS_CODE)0xC8001006

/* Insufficient resources (such as memory) are available to complete the  */
/* request                                                                */
#define LS_NORESOURCES               (LS_STATUS_CODE)0xC8001007

/* The network is unavailable                                             */
#define LS_NO_NETWORK                (LS_STATUS_CODE)0xC8001008

/* A warning occured while looking up an error messge string for the      */
/* LSGetMessage() function                                                */
#define LS_NO_MSG_TEXT               (LS_STATUS_CODE)0xC8001009

/* An unrecognized status code was passed into the LSGetMessage() function*/
#define LS_UNKNOWN_STATUS            (LS_STATUS_CODE)0xC800100A

/* An invalid index was specified in LSEnumProviders() or LSQuery License */
#define LS_BAD_INDEX                 (LS_STATUS_CODE)0xC800100B

/* No additional units are available                                      */
#define LS_NO_MORE_UNITS             (LS_STATUS_CODE)0xC800100C

/* The license associated with the current context has expired. This may  */
/* be due to a time-restriction on the license                            */
#define LS_LICENSE_EXPIRED           (LS_STATUS_CODE)0xC800100D

/* Input buffer is too small, need a bigger buffer                        */
#define LS_BUFFER_TOO_SMALL          (LS_STATUS_CODE)0xC800100E

/* No success in achieving the target                                     */
#define LS_NO_SUCCESS                (LS_STATUS_CODE)0xC800100F

/* Grace Days have been used up                                           */
#define LS_GRACE_EXPIRED             (LS_STATUS_CODE)0xC8001010

/* Unexpected state of Grace License                                      */
#define LS_GRACE_INVALID_STATE       (LS_STATUS_CODE)0xC8001011

/* Grace Hours have been used up                                          */
#define LS_GRACE_HOURS_EXHAUSTED     (LS_STATUS_CODE)0xC8001012


/* 1. Generic error when a license is denied by a server.
 * If reasons are known, more specific errors are given */
#define VLS_NO_LICENSE_GIVEN         1

/* 2. Application has not been given a name. */
#define VLS_APP_UNNAMED              2

/* 3. Unkown host (Application is given a server name but that
 * server name doesnt seem to exist) */
#define VLS_HOST_UNKNOWN             3

/* 4. No FILE giving license server name (Application cannot figure
 * out the license server. */
#define VLS_NO_SERVER_FILE           4

/* 5. On the specified machine, license server is not RUNNING. */
#define VLS_NO_SERVER_RUNNING        5

/* 6. This /feature is node locked but the request for a key came
 * from a machine other than the host running the Sentinel RMS Development Kit server. */
#define VLS_APP_NODE_LOCKED          6

/* 7. LSrelease called when this copy of the application had not
 * received a valid key from the Sentinel RMS Development Kit server. */
#define VLS_NO_KEY_TO_RETURN         7

/* 8. Failed to return the key issued to this copy of the application */
#define VLS_RETURN_FAILED            8

/* 9. End of clients on calling VLSgetClientInfo */
#define VLS_NO_MORE_CLIENTS          9

/* 10. End of features on calling VLSgetFeatureInfo */
#define VLS_NO_MORE_FEATURES         10

/* 11. General error by vendor in calling function etc.  */
#define VLS_CALLING_ERROR            11

/* 12. Internal error in Sentinel RMS Development Kit */
#define VLS_INTERNAL_ERROR           12

/* 13. Irrecoverable Internal error in Sentinel RMS Development Kit */
#define VLS_SEVERE_INTERNAL_ERROR    13

/* 14. On the specified machine, license server is not responding.
 * (Probable cause - network down, wrong port number, some other
 * application on that port etc.) */
#define VLS_NO_SERVER_RESPONSE       14

/* 15. User/machine excluded */
#define VLS_USER_EXCLUDED            15

/* 16. Unknown shared id */
#define VLS_UNKNOWN_SHARED_ID        16

/* 17. No servers responded to client broadcast */
#define VLS_NO_RESPONSE_TO_BROADCAST 17

/* 18. No such feature recognized by server */
#define VLS_NO_SUCH_FEATURE          18

/* 19. Failed to add license */
#define VLS_ADD_LIC_FAILED           19

/* 20. Failed to delete license */
#define VLS_DELETE_LIC_FAILED        20

/* 21. Last update was done locally */
#define VLS_LOCAL_UPDATE             21

/* 22. Last update was done by the Sentinel RMS Development Kit server */
#define VLS_REMOTE_UPDATE            22

/* 23. The vendor identification of requesting application does not
 * match with that of the application licensed by this system. */
#define VLS_VENDORIDMISMATCH         23

/* 24. The server has licenses for the same feature,version from multiple
 * vendors, and it is not clear from the requested operation which license
 * the requestor is interested in.  */
#define VLS_MULTIPLE_VENDORID_FOUND  24

/* 25. An error has occured in decrypting (or decoding) a network message.
 * Probably an incompatible or unknown server, or a version mismatch. */
#define VLS_BAD_SERVER_MESSAGE       25

/* 26. The server has found evidence of tampering of the system clock,
 * and it cannot service the request since the license for this feature
 * has been set to be time tamper proof.  */
#define VLS_CLK_TAMP_FOUND           26

/* 27. The specified operation is not permitted - authorization failed. */
#define VLS_NOT_AUTHORIZED           27

/* 28. The domain of server is different from that of client. */
#define VLS_INVALID_DOMAIN           28

/* 29. The server does not know of this tag type. */
#define VLS_UNKNOWN_TAG_TYPE         29
 
/* 30. A tag's type is invalid for the operation requested. */
#define VLS_INVALID_TAG_TYPE         30
 
/* 31. The server doesn't know this tag. */
#define VLS_UNKNOWN_TAG              31
 
/* 32. Attempt to update a tagged key. */
#define VLS_UPDATE_TAGGED_KEY_ERROR  32
 
/* 33. Server does not support tags. */
#define VLS_TAGS_NOT_SUPPORTED       33

/* 34. */
#define VLS_LOG_FILE_NAME_NOT_FOUND  34

/*35. */
#define VLS_LOG_FILE_NAME_NOT_CHANGED 35

/* 36. */
#define VLS_FINGERPRINT_MISMATCH     36

/* 37. Trial License Usage Exhauseted or Trial License Expired */
#define VLS_TRIAL_LIC_EXHAUSTED          37

/* 38. No Updates have been made so far */
#define VLS_NO_UPDATES_SO_FAR        38

/* 39. Eventhough the client asked VLSreleaseExt API to return a specific
number of units, it returned all the issued units */
#define VLS_ALL_UNITS_RELEASED       39
   
/* 40. The LS_HANDLE is a queued handle */
#define VLS_QUEUED_HANDLE            40

/* 41. The LS_HANDLE is an active handle */
#define VLS_ACTIVE_HANDLE            41

/* 42. The status of LS_HANDLE is ambiguous */
#define VLS_AMBIGUOUS_HANDLE         42

/* 43. Could not queue the client because the queue is full*/
#define VLS_NOMORE_QUEUE_RESOURCES   43

/* 44. No client as specified, found with the server*/
#define VLS_NO_SUCH_CLIENT           44

/* 45. Client not authorized to make the specified request*/
#define VLS_CLIENT_NOT_AUTHORIZED    45

/* 46. Distribution Criterion given is not correct */
#define VLS_BAD_DISTB_CRIT           46

/* 47. Processing not done because current leader is not known */
#define VLS_LEADER_NOT_PRESENT       47

/* 48. Tried to add a server to pool which is already there */
#define VLS_SERVER_ALREADY_PRESENT   48

/* 49. Tried to delete a server who is not in pool currently */
#define VLS_SERVER_NOT_PRESENT       49

/* 50. File can not be open. */
#define VLS_FILE_OPEN_ERROR          50

/* 51. Host name is not valid or can not be resolved */
#define VLS_BAD_HOSTNAME             51

/* 52. Different API version. Client server version mismatch */
#define VLS_DIFF_LIB_VER              52

/* 53. A non-redundant server contacted for redundant server related information */
#define VLS_NON_REDUNDANT_SRVR       53

/* 54. Message forwarded to leader. It is not an error */
#define VLS_MSG_TO_LEADER            54

/* 55. Update fail. may be Contact server died or modified */
#define VLS_CONTACT_FAILOVER_SERVER  55

/* 56.IP address given can not be resolved */
#define VLS_UNRESOLVED_IP_ADDRESS    56

/* 57. Hostname given is unresoled */
#define VLS_UNRESOLVED_HOSTNAME      57

/* 58. Invalid IP address Format */
#define VLS_INVALID_IP_ADDRESS       58

/* 59. Server is synchronizing dist table. Not an Error */
#define VLS_SERVER_FILE_SYNC         59

/* 60. Pool is already having max. no. of servers it can handle */
#define VLS_POOL_FULL                60

/* 61. Pool will not exist if this only server is removed */
#define VLS_ONLY_SERVER              61
/* 62. The feature is inactive on the requested server. */
#define VLS_FEATURE_INACTIVE         62

/* 63. The token cannot be issued because of majority rule failure. */
#define VLS_MAJORITY_RULE_FAILURE    63

/* 64.  Error related to configuration file operation. */
#define VLS_CONF_FILE_ERROR          64

/* 65. A non-redundant feature given for redundant feature related operation */
#define VLS_NON_REDUNDANT_FEATURE    65

/* 66. No Trial usage info  */
#define VLS_NO_TRIAL_INFO              66

/* 67. Trial usage query failed */
#define VLS_TRIAL_INFO_FAILED           67

/* 68. elan License not enabled */
#define VLS_ELM_LIC_NOT_ENABLE         68

/* commuter related error code */

/*69. not linked to integrated library*/
#define VLS_NOT_LINKED_TO_INTEGRATED_LIBRARY   69 

/* 70 client commuter code does not exist */
#define VLS_CLIENT_COMMUTER_CODE_DOES_NOT_EXIST    70

/*71. client already exist */
#define VLS_CLIENT_ALREADY_EXISTS                            71 

/*72 End of features on calling VLSgetCommuterInfo API*/
#define VLS_NO_MORE_COMMUTER_CODE                            72 

/*73 Failed to get client commuter info */
#define VLS_GET_COMMUTER_INFO_FAILED                         73

/* 74 VLSuninstallAndReturnCommuterCode() API failed */
#define VLS_UNABLE_TO_UNINSTALL_CLIENT_COMMUTER_CODE         74 

/* 75 VLSgetAndInstallCommuterCode()  failed */
#define VLS_ISSUE_COMMUTER_CODE_FAILED                       75


/* 76. server is not allowed to issue commuter code for the requested feature
   and version */
#define VLS_UNABLE_TO_ISSUE_COMMUTER_CODE                    76

/* 77. Not enough key available to check out commuter code */
#define VLS_NOT_ENOUGH_COMMUTER_KEYS_AVAILABLE         77

/*78. Invalid lock Info provided by client */
#define VLS_INVALID_INFO_FROM_CLIENT                   78

/* 79. Server has already check out one commuter code for this client */
#define VLS_CLIENT_ALREADY_EXIST                       79

/* 80. No commuter code exit with this feature / version */ 
#define VLS_COMMUTER_CODE_DOES_NOT_EXIST               80

/* 81. Client has already had commuter code with this feature version */
#define VLS_COMMUTER_CODE_ALREADY_EXIST                81

/* 82. Server synchronization in progress. Please wait...  */
#define VLS_SERVER_SYNC_IN_PROGRESS                82

/* 83. it is remotely checked out license */ 
#define VLS_REMOTE_CHECKOUT                        83

/* 84. Unable to install remote commuter code  */ 
#define VLS_UNABLE_TO_INSTALL_COMMUTER_CODE        84

/* 85 Failed to get remote locking code string   */
#define VLS_UNABLE_TO_GET_MACHINE_ID_STRING          85

/* 86 Invalid machine id string sent            */
#define VLS_INVALID_MACHINEID_STR                    86

/* 87. Commuter code expiration is greater than license itself */
#define  VLS_EXCEEDS_LICENSE_LIFE                   87

/* 88. Terminal server found. Cannot run Standalone application on it*/
#define VLS_TERMINAL_SERVER_FOUND                  88

/* 89. Application is not linked to either Intgr lib or standalone lib*/
#define VLS_NOT_APPROPRIATE_LIBRARY                89
 
/* 90. Not specified valid filetype*/
#define VLS_INVALID_FILETYPE                       90

/* 91. Application is communicating with old server that does not support this feature */
#define VLS_NOT_SUPPORTED                          91

/* 92. License string is invalid */
#define VLS_INVALID_LICENSE                        92

/* 93. License string is duplicate */
#define VLS_DUPLICATE_LICENSE                      93

/* For capacity licensing */
#define VLS_INSUFFICIENT_USER_CAPACITY             94

#define VLS_TEAM_LIMIT_EXHAUSTED                   95

#define VLS_INSUFFICIENT_TEAM_CAPACITY             96

#define VLS_CANNOT_DELETE_UPGRADED_LIC             97

/* For upgrade lock code */
#define VLS_UPGRADE_NOT_ALLOWED                    98

/* This feature is already marked for check-in */
#define VLS_FEATURE_MARKED_FOR_DELETION            99

#define VLS_MORE_CAPACITY_INFO_AVAILABLE           100

#define VLS_TEAM_EXCLUDED                          101

/* A network server contacted for standalone server related information */
#define VLS_NETWORK_SRVR                           102

/* The contacted feature is a Perpetual License */
#define VLS_PERPETUAL_LICENSE                      103

/* The commuter code has been checked out */
#define VLS_COMMUTER_CHECKOUT                      104

/* Error Codes For Revoke License */

/* License With Given Feature/Version does not exist on the server. */
#define VLS_REVOKE_ERR_NO_FEATURE                     105

/* The Message Received By The Server Was Corrupted. */
#define VLS_REVOKE_ERR_CORRUPT_MESSAGE                106

/* The Received Capacity/Number Of Licenses To Revoke Out Of Range. */
#define VLS_REVOKE_ERR_OUT_VALID_RANGE                107

/* Error Loading the MD5 plugin dll at the server. */
#define VLS_REVOKE_ERR_MD5_PLUGIN_LOAD_FAIL           108

/* Error In Executing The Authentication Plugin. */
#define VLS_REVOKE_ERR_MD5_PLUGIN_EXEC_FAIL           109

/* This feature has less number of total licenses. */
#define VLS_REVOKE_ERR_INSUFFICIENT_FEATURE_LICENSES  110

/* Default group does not has sufficient licenses, reconfigure your user resevation file */
#define VLS_REVOKE_ERR_INSUFFICIENT_DEFAULT_GROUP     111

/* Currently required number of licenses are not free for revoke in the default group */
#define VLS_REVOKE_ERR_INSUFFICIENT_FREE_IN_DEFAULT   112

/* Invalid SessionID sent by the client In Packet */
#define VLS_REVOKE_ERR_INVALID_SESSION_ID             113

/* Invalid Password For Revocation. */
#define VLS_REVOKE_ERR_INVALID_PASSWORD               114

/* Revocation Failed Internal Server Error. */
#define VLS_REVOKE_ERR_INTERNAL_SERVER                115

/* Infinite Revoke Not Possible With Enabled Group Distribution. */
#define VLS_REVOKE_ERR_INFINITE_GRP_DIST              116

/* All licenses must be free for infinite revocation. */
#define VLS_REVOKE_ERR_INFINITE_LIC_IN_USE            117

/* License has infinite keys only infinite revoke request allowed. */
#define VLS_REVOKE_ERR_INFINITE_LIC_FINITE_REQ        118

/* Ticket Generation For Revoke Failed. */
#define VLS_REVOKE_ERR_TICKET_GENERATION              119

/* Revocation Not Supported On Old License Code Generator Versions. */
#define VLS_REVOKE_ERR_CODGEN_VERSION_UNSUPPORTED     120

/* Revocation Not Supported For Redundant Licenses. */
#define VLS_REVOKE_ERR_RDNT_LIC_UNSUPPORED            121

/* Revocation Not Supported For Capacity Licenses. */
#define VLS_REVOKE_ERR_CAPACITY_LIC_UNSUPPORED        122

/* Error Unexpected Challenge Packet Received From Server. */
#define VLS_REVOKE_ERR_UNEXPECTED_AUTH_CHLG_PKT       123

/* Revocation Not Supported For Trial Licenses. */
#define VLS_REVOKE_ERR_TRIAL_LIC_UNSUPPORED           124

/*  Local Request Locking criteria */
/* Not all required lock selectors are available */
#define VLS_REQUIRED_LOCK_FIELDS_NOT_FOUND            125

/* Total lock selectors available is less than min. number */
#define VLS_NOT_ENOUGH_LOCK_FIELDS                    126

/* Remote checkout is not allowed for perpetual licenses */
#define VLS_REMOTE_CHECKOUT_NOT_ALLOWED_FOR_PERPETUAL 127

/* Installation of Grace License on client machine failed */ 
#define VLS_GRACE_LIC_INSTALL_FAIL                    128 

/* The API Is Not Supported In The No-Net Mode Of The Server. */
#define VLS_NOT_SUPPORTED_IN_NONET_LIBRARY            129

/* Grace code length overflow error generated at Server end. */
#define VLS_GRACE_CODE_LENGTH_OVERFLOW_ERROR  	      130

/*------------------------------------------------------------------------*/ 
/* Type of file read by server at startup                                 */
/*------------------------------------------------------------------------*/
typedef enum {VLS_LSERVRC,VLS_LSERVRCCNF,VLS_ULSERVRC}VLS_FILE_TYPE;


/*------------------------------------------------------------------------*/
/* Function Prototypes                                                    */
/*------------------------------------------------------------------------*/

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetFileName (
#ifndef LSNOPROTO
  VLS_FILE_TYPE filetype, /*IN*/
  unsigned char* fileName,/*IN*/
  unsigned char* unused1,
  unsigned long* unused2
#endif /* LSNOPROTO */
);



/*------------------------------------------------------------------------*/
/* Function Prototypes                                                    */
/*------------------------------------------------------------------------*/


VDLL32 LS_STATUS_CODE VMSWINAPI LSRequest (
#ifndef LSNOPROTO
  unsigned char  LSFAR *license_system,
  unsigned char  LSFAR *publisher_name,
  unsigned char  LSFAR *product_name,
  unsigned char  LSFAR *version,
  unsigned long  LSFAR *units_reqd,
  unsigned char  LSFAR *log_comment,
  LS_CHALLENGE   LSFAR *challenge,
  LS_HANDLE      LSFAR *lshandle
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI LSRelease (
#ifndef LSNOPROTO
  LS_HANDLE             lshandle,
  unsigned long         units_consumed,
  unsigned char  LSFAR *log_comment
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetAndInstallCommuterCode (
#ifndef LSNOPROTO
    unsigned char * feature_name,      /* IN */
    unsigned char * feature_version,   /* IN */
    long          * units_reqd,        /* IN */
    int           * duration,          /* IN/OUT */ /*No of days */
#if (defined _HP_UX11_ && _V_LP64_)
    unsigned long *lock_mask,
#else
    int           * lock_mask,         /* IN/OUT */
#endif
    unsigned char * log_comment,       /* IN */
    LS_CHALLENGE  * challenge         /* IN/OUT */

#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSuninstallAndReturnCommuterCode(
#ifndef LSNOPROTO
  unsigned char              *feature_name,   /*  IN  */
  unsigned char              *feature_version,        /*  IN  */
  unsigned char              *log_comment    /*  IN  */
#endif /* LSNOPROTO */
);

                    
VDLL32 LS_STATUS_CODE VMSWINAPI VLScleanExpiredCommuterCode(
#ifndef LSNOPROTO
  unsigned char              *feature_name,    /*  IN  */
  unsigned char              *feature_version, /*  IN  */
  unsigned char              *log_comment,     /*  IN  */
  unsigned long              *unused           /*  IN  */
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetCommuterInfo(
#ifndef LSNOPROTO
  unsigned char *feature_name,     /* IN */
  unsigned char *version,          /* IN */
  int index,                       /* IN */
  VLScommuterInfo *commuter_info  /* OUT */
#endif /* LSNOPROTO */
);


VDLL32 LS_STATUS_CODE VMSWINAPI LSUpdate (
#ifndef LSNOPROTO
  LS_HANDLE             lshandle,
  unsigned long         unused1,
  long           LSFAR *unused2,
  unsigned char  LSFAR *unused3,
  LS_CHALLENGE   LSFAR *challenge
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSbatchUpdate (
#ifndef LSNOPROTO
  int                    numHandles,     /* IN                          */
  LS_HANDLE      LSFAR * lshandle,       /* INOUT - numHandles elements */
  unsigned long  LSFAR * unused1,        /* IN    - should be NULL      */
  long           LSFAR * unused2,        /* IN    - should be NULL      */
  unsigned char  LSFAR * unused3,        /* IN    - should be NULL      */
  LS_CHALLENGE   LSFAR * unused4,        /* IN    - should be NULL      */
  LS_STATUS_CODE LSFAR * status          /* OUT   - numHandles elements */
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSchangeUsageLogFileName (
#ifndef LSNOPROTO
  char  LSFAR * hostName,       /* IN   */
  char  LSFAR * newFileName    /* IN    */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetUsageLogFileName (
#ifndef LSNOPROTO
  char    LSFAR   *hostName,            /* IN   */
  char    LSFAR   *fileName             /* OUT  */
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSshutDown (
#ifndef LSNOPROTO
  char    LSFAR   *hostName
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI LSGetMessage (
#ifndef LSNOPROTO
  LS_HANDLE             lshandle,
  LS_STATUS_CODE        Value,
  unsigned char  LSFAR *Buffer,
  unsigned long         BufferSize
#endif
);

/* Single-call licensing. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSlicense(
#ifndef LSNOPROTO
  unsigned char  LSFAR *feature_name,
  unsigned char  LSFAR *version,
  LS_HANDLE      LSFAR *handle
#endif  /* LSNOPROTO */
);

/* Disables single-call licensing; returns license key. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSdisableLicense(
#ifndef LSNOPROTO
  LS_HANDLE      LSFAR *handle
#endif  /* LSNOPROTO */
);

/*------------------------------------------------------------------------*/
/* Disables automatic renewal of license                                  */
/* call with handle to disable automatic renewal of one feature           */
/* call with (LS_HANDLE) 0 to disable auto renewal of all features        */
/* on UNIX, call VLSdisableAutoTimer before using sleep                   */
/* on Win32, call VLSdisableAutoTimer when thread has no message loop     */
/*------------------------------------------------------------------------*/
VDLL32 LS_STATUS_CODE VMSWINAPI VLSdisableAutoTimer(
#ifndef LSNOPROTO
  LS_HANDLE handle,
  int       state        /* VLS_ON or VLS_OFF */
#endif  /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetTraceLevel(
#ifndef LSNOPROTO
  int trace_level
#endif /* LSNOPROTO*/
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetContactServer(
#ifndef LSNOPROTO
  char LSFAR *server_name
#endif /* LSNOPROTO */
);

/* THIS FUNCTION IS OBSOLETE.  Use VLSsetContactServer() instead. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetServerName(
#ifndef LSNOPROTO
  char LSFAR *server_name
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetServerList (
#ifndef LSNOPROTO
  char LSFAR *outBuf,
  int        outBufSz
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSinitServerList(
#ifndef LSNOPROTO

  char LSFAR *ServerList,
  int        option_flag
#endif /* LSNOPROTO */
);

/* Get the name of license server. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetContactServer(
#ifndef LSNOPROTO
  char   LSFAR     *outBuf,
  int    outBufSz
#endif
);

/* Get the name of license server. */
/* THIS FUNCTION IS OBSOLETE.  Use VLSgetContactServer() instead. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetServerName (
#ifndef LSNOPROTO
  char   LSFAR     *outBuf,
  int    outBufSz
#endif
);

/* Get the name of license server from Handle. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetServerNameFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE        handle_id,
  char   LSFAR     *outBuf,
  int    outBufSz
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSerrorHandle (
#ifndef LSNOPROTO
  int errorHandle
#endif
);

/*
 * Replaces the default error handler for the specified error.
 * Error Handlers are automatically called on error, unless disabled.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetErrorHandler(
#ifndef LSNOPROTO
  LS_STATUS_CODE (VMSWINAPI * myErrorHandler)(LS_STATUS_CODE, char LSFAR *),
  LS_STATUS_CODE LS_ErrorType
#endif /* LSNOPROTO */
);

/*
 * Configures displaying of error msgs to the user through the default
 * error handlers.  If you disable the default error handlers you do not
 * need to use this function.
 * Default behavior:
 *   Windows - Pop up a Message Box.
 *   Unix    - Write to stderr.
 * You can alter this behavior by providing either a FILE* or a file path.
 * The other parameter should be NULL.
 * If you provide both, preference will be given to the FILE*.
 */
typedef enum {
  VLS_NULL, VLS_STDOUT, VLS_STDERR
} VLS_ERR_FILE;

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetUserErrorFile(
#ifndef LSNOPROTO
  VLS_ERR_FILE msgFile,  /* IN - Desired error file */
  char LSFAR * filePath  /* IN - Full path of desired error file */
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetRemoteRenewalTime(
#ifndef LSNOPROTO
  unsigned char LSFAR *feature_name,
  unsigned char LSFAR *version,
  int renewal_time     /* renewal time in secs */
#endif /* LSNOPROTO */
);


/* The following API is an extension of VLSDiscover, It now returns 
 * Server Characteristics Information in discoverInfo Array
 *
 * NOTE: num_servers is an IN-OUT parameter. 
 * As INPUT it passes the array size of discoverInfo
 * and as OUT it tells how many servers responded
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSdiscoverExt (
#ifndef LSNOPROTO
unsigned char   LSFAR *feature_name,           /* IN */
unsigned char   LSFAR *version,                /* IN */
unsigned char   LSFAR *unused1,                /* IN */
int                   *num_servers,            /* IN-OUT */
VLSdiscoverInfo       *discoverInfo,          /* IN-OUT*/
int                   optionFlag,              /* IN */ 
int                   sharing_crit,            /* IN */
char            LSFAR *vendor_list
#endif /* LSNOPROTO */
);


VDLL32 LS_STATUS_CODE VMSWINAPI VLSdiscover (
#ifndef LSNOPROTO
  unsigned char LSFAR *feature_name,
  unsigned char LSFAR *version,
  unsigned char LSFAR *unused1,
  int                  bufferSize,
  char          LSFAR *server_names,
  int                  broadcastFlag,
  char          LSFAR *vendor_list
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSwhere (
#ifndef LSNOPROTO
  unsigned char LSFAR *feature_name,
  unsigned char LSFAR *version,
  unsigned char LSFAR *unused1,
  int                  bufferSize,
  char          LSFAR *server_names,
  int                  broadcastFlag
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddFeature (
#ifndef LSNOPROTO
  unsigned char LSFAR *license_string,
  unsigned char LSFAR *unused1,
  LS_CHALLENGE  LSFAR *unused2
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddFeatureExt(
#ifndef LSNOPROTO
  unsigned char *licenseString, /* IN */
  unsigned char *DistCritString,/* IN */
  unsigned char *unused1,       /* IN */
  LS_CHALLENGE  *unused2        /* INOUT */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddFeatureToFile (
#ifndef LSNOPROTO
  unsigned char LSFAR *license_string,
  unsigned char LSFAR *unused1,
  unsigned char LSFAR *unused2,
  LS_CHALLENGE  LSFAR *unused3
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddFeatureToFileExt(
#ifndef LSNOPROTO
  unsigned char *licenseString,     /* IN */
  unsigned char *unused1,           /* IN */
  unsigned char *DistCritString,    /* IN */
  unsigned char *unused2,           /* IN */
  LS_CHALLENGE  *unused3            /* INOUT */
#endif
);


VDLL32 LS_STATUS_CODE VMSWINAPI VLSdeleteFeature (
#ifndef LSNOPROTO
  unsigned char LSFAR *feature_name,
  unsigned char LSFAR *version,
  unsigned char LSFAR *unused1,
  LS_CHALLENGE  LSFAR *unused2
#endif
);

/* Capacity licensing.
 * SLM 7.3.0
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSdeleteFeatureExt (
#ifndef LSNOPROTO
  unsigned char LSFAR *feature_name,
  unsigned char LSFAR *version,
  unsigned long LSFAR *capacity,
  unsigned char LSFAR *log_comment,
  LS_CHALLENGE  LSFAR *challenge,
  unsigned char LSFAR *unused1,
  unsigned long LSFAR *unused2
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetVersions (
#ifndef LSNOPROTO
  char          LSFAR *feature_name,
  int                  bufferSize,
  char          LSFAR *versionList,
  char          LSFAR *unused1
#endif
);

/* Capacity licensing.
 * SLM 7.3.0
 */
/**************************************************************************
* DESCRIPTION:
*           This function will get capacities of all the licenses having 
*           specified feature & version but different capacity. 
*           It returns list of capacities as one string, each capacity 
*           separated by a space character.
*           If capacityList is passed as NULL, the API returns the
*           bufferSize required. The index field returns the index of the
*           license upto which the capacity has been retrieved based on the
*           buffersize. 
************************************************************************/
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetCapacityList (
#ifndef LSNOPROTO
  unsigned char LSFAR *feature_name,  /*IN*/
  unsigned char LSFAR *feature_version, /*IN*/
  int           LSFAR *index,          /*INOUT*/
  unsigned long LSFAR *bufferSize,    /*INOUT*/
  char          LSFAR *capacityList,  /*OUT*/
  char          LSFAR *log_comment, /* currently unused */
  unsigned long LSFAR *unused2      /* currently unused */
#endif
);


VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetHandleInfo (
#ifndef LSNOPROTO
  LS_HANDLE            lshandle,
  VLSclientInfo LSFAR *client_info
#endif
);

/* Get information about client */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetClientInfo (
#ifndef LSNOPROTO
  unsigned char   LSFAR *feature_name,
  unsigned char   LSFAR *version,
  int                    index,
  char            LSFAR *unused1,
  VLSclientInfo   LSFAR *client_info
#endif /* LSNOPROTO */
);

/* Extended the functionality of VLSgetClientInfo API to support
 * capacity licenses also.
 * Added in SLM 7.3.0
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetClientInfoExt (
#ifndef LSNOPROTO
  unsigned char   LSFAR *feature_name,
  unsigned char   LSFAR *version,
  unsigned long   LSFAR *capacity,
  int                    index,
  char            LSFAR *log_comment,
  unsigned long   LSFAR *unused1,
  VLSclientInfo   LSFAR *client_info
#endif /* LSNOPROTO */
);


/* Get information about queued client */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetQueuedClientInfo (
#ifndef LSNOPROTO
  unsigned char   LSFAR *feature_name,
  unsigned char   LSFAR *version,
  int                    index,
  char            LSFAR *unused1,
  VLSqueuedClientInfo   LSFAR *client_info
#endif /* LSNOPROTO */
);

/* Get information about feature */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetFeatureInfo(
#ifndef LSNOPROTO
  unsigned char   LSFAR *feature_name,
  unsigned char   LSFAR *version,
  int                    index,
  char            LSFAR *unused1,
  VLSfeatureInfo  LSFAR *feature_info
#endif /* LSNOPROTO */
);

/* Extended the functionality of VLSgetFeatureInfo API to support
 * capacity licenses also.
 * Added in SLM 7.3.0
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetFeatureInfoExt (
#ifndef LSNOPROTO
  unsigned char   LSFAR *feature_name,
  unsigned char   LSFAR *version,
  unsigned long   LSFAR *capacity,
  int                    index,
  char            LSFAR *unused1,
  unsigned long   LSFAR *unused2,
  VLSfeatureInfo  LSFAR *feature_info
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetFeatureFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE              lshandle,
  char            LSFAR *Buffer,
  unsigned long          BufferSize
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetVersionFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE              lshandle,
  char            LSFAR *Buffer,
  unsigned long          BufferSize
#endif
);

/* Extracts allocated team capacity and user capacity 
 * from the handle.
 * SLM 7.3.0
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetCapacityFromHandle (
#ifndef LSNOPROTO
    LS_HANDLE       lshandle,
  unsigned long LSFAR *user_capacity,   /* OUT - user capacity issued by by server */
  unsigned long LSFAR *team_capacity,    /* OUT - team capacity issued by by server */
  unsigned long LSFAR *license_capacity  /* OUT - license capacity */
#endif
);
/*
 * Note that the information returned by this function will be correct
 * only immediately after acquiring the handle.  The information in the
 * handle is NOT updated subsequently.
 *
 * The function is used when the clocks may not be in sync. It
 * returns the difference in seconds between the estimated current
 * time on the server and the estimated time on the client.
 * The estimation error is usually the network latency time.
 *
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetTimeDriftFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE            lshandle,                    /* IN  */
  long          LSFAR *secondsServerAheadOfClient   /* OUT */
#endif
);


/*
 * Note that the information returned by this function will be correct
 * only immediately after acquiring the handle.  The information in the
 * handle is NOT updated subsequently.
 *
 * The function is used when the clocks may not be in sync. It
 * returns the difference in seconds between the estimated current
 * time on the server and the estimated feature expiration time
 * on the server.
 *
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetFeatureTimeLeftFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE              lshandle,                       /* IN */
  unsigned long   LSFAR *secondsUntilTheFeatureExpires   /* OUT */
#endif
);

/*
 * Note that the information returned by this function will be correct
 * only immediately after acquiring the handle.  The information in the
 * handle is NOT updated subsequently.
 *
 * The function is used when the clocks may not be in sync. It
 * returns the difference in seconds between the estimated current
 * time on the server and the estimated key expiration time on
 * on the server.
 *
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetKeyTimeLeftFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE              lshandle,                   /* IN */
  unsigned long   LSFAR *secondsUntilTheKeyExpires   /* OUT */
#endif
);

/*
 * Note that the information returned by this function will be correct
 * only immediately after acquiring the handle.  The information in the
 * handle is NOT updated subsequently.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetLicInUseFromHandle (
#ifndef LSNOPROTO
  LS_HANDLE              lshandle,
  int             LSFAR *totalKeysIssued   /* OUT - keys issued by server */
#endif
);

/*
 * Returns the value VLS_LOCAL_UPDATE or VLS_REMOTE_UPDATE
 * depending on whether the last SUCCESSFUL update was locally done or
 * done by the Sentinel RMS Development Kit server.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetRenewalStatus (
#ifndef LSNOPROTO
  void
#endif
);

/*
 * Calling this function makes all future update calls
 * go directly to the Sentinel RMS Development Kit server.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSdisableLocalRenewal(
#ifndef LSNOPROTO
  void
#endif
);

/*
 * Calling this function allows the client libraries to process each
 * future update and send only those updates which are necessary
 * to the server. This is the default behaviour and please read the
 * user manual for further description on the default behaviour.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSenableLocalRenewal(
#ifndef LSNOPROTO
  void
#endif
);

/*
 * This function tells us whether local renewal of keys is enabled,
 * or if all LSUpdate calls go straight to the server (disabled).
 */
VDLL32 VLS_LOC_UPD_STAT VMSWINAPI VLSisLocalRenewalDisabled(
#ifndef LSNOPROTO
  void
#endif
);

/* Function to retrieve (possibly customized) hostid of the machine */
/* THIS FUNCTION IS OBSOLETE.  Use VLSgetMachineID() instead. */
VDLL32 long VMSWINAPI VLSgetHostId(
#ifndef LSNOPROTO
void
#endif
);

/* Call this function to get a description of the client library version */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetLibInfo(
#ifndef LSNOPROTO
LS_LIBVERSION LSFAR * pInfo
#endif
);


VDLL32 long VMSWINAPI VLSgetNWerrno(
#ifndef LSNOPROTO
  void
#endif
);

VDLL32 int VMSWINAPI VLSgetServerPort(
#ifndef LSNOPROTO
  void
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSinitialize(
#ifndef LSNOPROTO
  void
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI  VLScleanup(
#ifndef LSNOPROTO
  void
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetTimeoutInterval (
#ifndef LSNOPROTO
long interval
#endif
);

VDLL32 long VMSWINAPI VLSgetTimeoutInterval(
#ifndef LSNOPROTO
void
#endif
);


VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetBroadcastInterval (
#ifndef LSNOPROTO
long interval
#endif
);

VDLL32 long VMSWINAPI VLSgetBroadcastInterval(
#ifndef LSNOPROTO
void
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSqueuedRequest (
#ifndef LSNOPROTO
  unsigned char  LSFAR *license_system,
  unsigned char  LSFAR *publisher_name,
  unsigned char  LSFAR *product_name,
  unsigned char  LSFAR *version,
  unsigned long  LSFAR *units_reqd,
  unsigned char  LSFAR *log_comment,
  LS_CHALLENGE   LSFAR *challenge,
  LS_HANDLE      LSFAR *lshandle,
  VLSqueuePreference LSFAR *qPreference,
  int            LSFAR *requestFlag
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSupdateQueuedClient (
#ifndef LSNOPROTO
  LS_HANDLE             lshandle,
  long           LSFAR *absExpiryTime,
  unsigned char  LSFAR *unused3,
  LS_CHALLENGE   LSFAR *unused4
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetQueuedLicense (
#ifndef LSNOPROTO
  LS_HANDLE             lshandle,
  unsigned char  LSFAR *log_comment,
  LS_CHALLENGE   LSFAR *challenge
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetHandleStatus (
#ifndef LSNOPROTO
  LS_HANDLE             lshandle
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSinitQueuePreference (
#ifndef LSNOPROTO
  VLSqueuePreference  *qPreference
#endif /* LSNOPROTO */
  );

VDLL32 LS_STATUS_CODE VMSWINAPI VLSremoveQueuedClient (
#ifndef LSNOPROTO
   unsigned char         *feature_name,  /* IN */
   unsigned char         *version,       /* IN */
   long                  qkey_id,        /*IN */
   char                  *log_comment    /* IN */
#endif /* LSNOPROTO */
    );
    
VDLL32 LS_STATUS_CODE VMSWINAPI VLSremoveQueue (
#ifndef LSNOPROTO
   unsigned char         *feature_name,  /* IN */
   unsigned char         *version,       /* IN */
   char                  *log_comment    /* IN */
#endif /* LSNOPROTO */
    );

/*------------------------------------------------------------------------*/
/* Fingerprinting-related types and functions:                            */
/*------------------------------------------------------------------------*/

typedef struct _vlsmachineID {
  unsigned long id_prom;               /* VLS_LOCK_ID_PROM */
  char          ip_addr[VLS_MAXLEN];       /* VLS_LOCK_IP_ADDR */
  unsigned long disk_id;               /* VLS_LOCK_DISK_ID */
  char          host_name[VLS_MAXLEN];     /* VLS_LOCK_HOSTNAME */
  char          ethernet[VLS_MAXLEN];      /* VLS_LOCK_ETHERNET */
  unsigned long nw_ipx;                /* VLS_LOCK_NW_IPX */
  unsigned long nw_serial;             /* VLS_LOCK_NW_SERIAL */
  char          portserv_addr[VLS_MAXLEN]; /* VLS_LOCK_PORTABLE_SERV */
  unsigned long custom;                /* VLS_LOCK_CUSTOM */

  unsigned long reserved;              /* For internal use */
  char          cpu_id[VLS_MAX_CPU_ID_LEN + 1];   /* VLS_LOCK_CPU */
  unsigned long unused2;               /* Reserved for future use. */
} VLSmachineID;

/* Initializes a machine id struct to blank/default values. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSinitMachineID(
#ifndef LSNOPROTO
  VLSmachineID LSFAR *machineID       /* OUT - should be pre-allocated */
#endif
);

/*
 * Sets the values of the machine id struct for the current host.
 * The input machine ID struct is initialized and then only those items
 * indicated by the lock_selector_in will (try to) be obtained and set.
 * If lock_selector_out is not NULL, *lock_selector_out is set to a bitmask
 * specifying which items could actually be obtained.
 * To try to obtain all possible machine id struct items, set
 * lock_selector_in to VLS_LOCK_ALL.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetMachineID(
#ifndef LSNOPROTO
  unsigned long        lock_selector_in, /* IN */
  VLSmachineID  LSFAR *machineID,        /* OUT - should be pre-allocated */
  unsigned long LSFAR *lock_selector_out /* OUT - may be NULL */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetNumberedMachineID(
#ifndef LSNOPROTO
  unsigned long        lock_selector_in,  /* IN */
  VLSmachineID  LSFAR *machineID,         /* OUT - should be pre-allocated */
  unsigned long LSFAR *lock_selector_out, /* OUT - may be NULL */
  int                  flag,              /* IN  - VLS_GET_CID/VLS_GET_ETHERNET */
  int                  index,             /* IN */
  int                  reserved           /* IN */   
#endif
);

/* Computes locking code of machineID struct based on lock selector. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSmachineIDtoLockCode(
#ifndef LSNOPROTO
  VLSmachineID  LSFAR *machineID,     /* IN */
  unsigned long        lock_selector, /* IN */
  unsigned long LSFAR *lockCode       /* OUT - effective locking code */
#endif
);


/*------------------------------------------------------------------------*/
/* Function Prototypes of General-Purpose Utility Functions:              */
/*------------------------------------------------------------------------*/

/*
 * This function is called for scheduling eventhandler to be awakened after
 * so many seconds. It handles only SIGALRM signal. No. of events that can be
 * scheduled is 100. A particular eventhandler can be executed more
 * than once by specifying it in repeat_event argument. This function is
 * available only on UNIX platforms.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSscheduleEvent(
#ifndef LSNOPROTO
unsigned long   seconds,              /* IN -- Time Interval in seconds */
void            (*eventHandler) (void),   /* IN -- Signal Handler Fn. */
long            repeat_event          /* IN -- No of event repetitions :
                                               -1 for infinite */
#endif
);

/*
 * This function is called for disabling the events scheduled using
 * VLSscheduleEvent function. To disable a particular event pass the event
 * handler function name as the argument. To disable all the events pass
 * NULL as argument. Returns LS_SUCCESS on success. This function is available
 * only on UNIX platforms.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSdisableEvents(
#ifndef LSNOPROTO
void        (*eventHandler) (void)  /* IN -- Signal Handler Fn.: NULL for All */
#endif
);

/*------------------------------------------------------------------------*/
/* Function Prototypes of Redundant server related client APIs            */
/*------------------------------------------------------------------------*/
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetHostAddress(
#ifndef LSNOPROTO
    char   * hostname,    /* IN */
    char   * IP_AddressBuf,  /* OUT */
    int      IPAddrBufLen /* IN */
#endif
);

/* 
 * This utility function resolves the give IP Address into fully qualified
 * host name. Since this API may call to DNS to resolve IP address, hence
 * it is blocking one.
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetHostName (
#ifndef LSNOPROTO
char            LSFAR  *IP_address,    /* IN  IP Address in AA.BB.CC.DD format*/
char            LSFAR  *HostName,      /* OUT HostName Buffer */
int                     HostNameBufLen /* IN  HostName Buffer Size*/
#endif
);


VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetDistbCrit(
#ifndef LSNOPROTO
        char   * feature_name,   /* IN */
        char   * feature_version,   /* IN */
        char   * dist_crit,      /* OUT - pre-malloced */
        int       distcrit_buflen   /* IN */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetDistbCritToFile(
#ifndef LSNOPROTO
        char   * feature_name,   /* IN */
        char   * feature_version,   /* IN */ 
     char   *file_name     /* IN */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSchangeDistbCrit(
#ifndef LSNOPROTO
char   * feature_name,
char   * version,
char   * dist_crit
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetLeaderServerName(
#ifndef LSNOPROTO
        char   * leader_name, /* OUT */
        int       leader_name_len   /* IN */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddServerToPool(
#ifndef LSNOPROTO
 char *server_name,
 char *server_addr 
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSdelServerFromPool(
#ifndef LSNOPROTO
 char *server_name,
 char *server_addr 
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddFeatureExt(
#ifndef LSNOPROTO
unsigned char *licenseString,    /* IN */
unsigned char *DistCritString,   /* IN */
unsigned char *log_comment,   /* IN */
LS_CHALLENGE  *challenge   /* INOUT */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSaddFeatureToFileExt(
#ifndef LSNOPROTO
unsigned char *    licenseString,      /* IN */
unsigned char *    DistCritString,      /* IN */
unsigned char *    license_file_name,  /* IN */
unsigned char *    log_comment,        /* IN */
LS_CHALLENGE  *    challenge           /* INOUT */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetFeatureInfoToFile(
#ifndef LSNOPROTO
unsigned char *    feature_name,    /* IN */ 
unsigned char *    version,   /* IN */ 
char        *    file_name /* IN */
#endif
);

/* The API VLS_FillFeaInfoStruct reads the string dumped by the
 * VLSgetFeatureInfoToFile API and fills up the VLSFeatureInfo struct
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSFillFeaInfoStruct( 
#ifndef LSNOPROTO
char*            lineStr,          /* IN */
VLSfeatureInfo*  finfo             /* IN-OUT */
#endif
);
    


VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetLicSharingServerList
(
#ifndef LSNOPROTO
unsigned char *  feature_name,       /* IN */
unsigned char *  feature_version,    /* IN */
int              server_list_len,    /* IN */
char          *  server_list,        /* OUT */
int           *  num_servers         /* OUT */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetTrialPeriodLeft (
#ifndef LSNOPROTO
   unsigned char       * feature_name,     /* IN */
   unsigned char       * version ,         /* IN */
   unsigned long       * trialperiod,      /* OUT */
   unsigned char LSFAR * unused1

#endif /* LSNOPROTO */
);



/*------------------------------------------------------------------------*/
/* Macros with default licensing values.                                  */
/* There should be no space(s) between macro name and open parenthesis.   */
/* Most of these are for backward compatibility.                          */
/*------------------------------------------------------------------------*/

#define VLS_REQUEST(feature_name, version, handle_addr)  \
        LSRequest(LS_ANY,(unsigned char LSFAR *) "Sentinel RMS Development Kit User", \
                     (unsigned char LSFAR *)feature_name, \
                     (unsigned char LSFAR *)version, \
                     (unsigned long LSFAR *)NULL, (unsigned char LSFAR *)NULL, \
                     (LS_CHALLENGE LSFAR *)NULL, handle_addr)

#define VLS_RELEASE(handle)     \
        LSRelease(handle, LS_DEFAULT_UNITS, (unsigned char LSFAR *)NULL)

#define VLS_UPDATE(handle)                                     \
        LSUpdate     (handle, LS_DEFAULT_UNITS, (long LSFAR *)NULL, \
                     (unsigned char LSFAR *)NULL, (LS_CHALLENGE LSFAR *)NULL)

#define VLS_INITIALIZE() VLSinitialize()

#define VLS_CLEANUP()    VLScleanup()

/*-----------------------------------------------------------------------*/
/* Macros over sharing APIs                                              */
/*-----------------------------------------------------------------------*/
#define VLSsetTeamId(team_id, func_ptr) \
                VLSsetSharedId(team_id,func_ptr)
#define VLSsetTeamIdValue(team_id,team_id_value) \
                VLSsetSharedIdValue(team_id,team_id_value)

#define VLS_UNKNOWN_TEAM_ID VLS_UNKNOWN_SHARED_ID

/*------------------------------------------------------------------------*/
/* Macros which will make all Sentinel RMS Development Kit functions void:  */
/*------------------------------------------------------------------------*/

#ifdef NO_LICENSE
#define LSGetMessage(a1,a2,a3,a4)                 (LS_SUCCESS)
#define LSRelease(a1,a2,a3)                       (LS_SUCCESS)
#define LSRequest(a1,a2,a3,a4,a5,a6,a7,a8)        (LS_SUCCESS)
#define LSUpdate(a1,a2,a3,a4,a5)                  (LS_SUCCESS)
#define VLSaddFeature(a1,a2,a3)                   (LS_SUCCESS)
#define VLSaddFeatureToFile(a1,a2,a3,a4)          (LS_SUCCESS)
#define VLSbatchUpdate(a1,a2,a3,a4,a5,a6,a7)      (LS_SUCCESS)
#define VLScleanup()                              (LS_SUCCESS)
#define VLSdeleteFeature(a1,a2,a3,a4)             (LS_SUCCESS)
#define VLSdisableAutoTimer(a1,a2)                (LS_SUCCESS)
#define VLSdisableLicense(a1)                     (LS_SUCCESS)
#define VLSdisableLocalRenewal()                  (LS_SUCCESS)
#define VLSdiscover(a1,a2,a3,a4,a5,a6,a7)         (LS_SUCCESS)
#define VLSenableLocalRenewal()                   (LS_SUCCESS)
#define VLSerrorHandle(a1)                        (LS_SUCCESS)
#define VLSgetBroadcastInterval()                 (9)
#define VLSgetClientInfo(a1,a2,a3,a4,a5)          (VLS_NO_MORE_CLIENTS)
#define VLSgetQueuedClientInfo(a1,a2,a3,a4,a5)    (VLS_NO_MORE_CLIENTS)
#define VLSgetContactServer(a1,a2)                (LS_SUCCESS)
#define VLSgetFeatureFromHandle(a1,a2,a3)         (LS_BADHANDLE)
#define VLSgetFeatureInfo(a1,a2,a3,a4,a5)         (VLS_NO_MORE_FEATURES)
#define VLSgetFeatureTimeLeftFromHandle(a1,a2)    (LS_BADHANDLE)
#define VLSgetHandleInfo(a1,a2)                   (LS_BADHANDLE)
#define VLSgetHostId()                            (0)
#define VLSgetKeyTimeLeftFromHandle(a1,a2)        (LS_BADHANDLE)
#define VLSgetLibInfo(a1)                         (LS_SUCCESS)
#define VLSgetLicInUseFromHandle(a1,a2)           (LS_BADHANDLE)
#define VLSgetMachineID(a1,a2,a3)                 (LS_SUCCESS)
#define VLSgetNWerrno()                           (0)
#define VLSgetRenewalStatus()                     (VLS_LOCAL_UPDATE)
#define VLSgetServerList(a1,a2)                   (LS_SUCCESS)
#define VLSgetServerName(a1,a2)                   (LS_SUCCESS)
#define VLSgetServerNameFromHandle(a1,a2,a3)      (LS_SUCCESS)
#define VLSgetServerPort()                        (5093)
#define VLSgetTimeDriftFromHandle(a1,a2)          (LS_BADHANDLE)
#define VLSgetTimeoutInterval()                   (30)
#define VLSgetVersionFromHandle(a1,a2,a3)         (LS_BADHANDLE)
#define VLSgetVersions(a1,a2,a3,a4)               (VLS_NO_SUCH_FEATURE)
#define VLSinitMachineID(a1)                      (LS_SUCCESS)
#define VLSinitServerList(a1,a2)                  (LS_SUCCESS)
#define VLSinitialize()                           (LS_SUCCESS)
#define VLSisLocalRenewalDisabled()               (VLS_LOCAL_UPD_ENABLE)
#define VLSlicense(a1,a2,a3)                      (LS_SUCCESS)
#define VLSmachineIDtoLockCode(a1,a2,a3)          (LS_SUCCESS)
#define VLSsetBroadcastInterval(a1)               (LS_SUCCESS)
#define VLSsetContactServer(a1)                   (LS_SUCCESS)
#define VLSsetErrorHandler(a1,a2)                 (LS_SUCCESS)
#define VLSsetRemoteRenewalTime(a1,a2,a3)         (LS_SUCCESS)
#define VLSsetServerName(a1)                      (LS_SUCCESS)
#define VLSsetTimeoutInterval(a1)                 (LS_SUCCESS)
#define VLSsetTraceLevel(a1)                      (LS_SUCCESS)
#define VLSsetUserErrorFile(a1,a2)                (LS_SUCCESS)
#define VLSshutDown(a1)                           (LS_SUCCESS)
#define VLSwhere(a1,a2,a3,a4,a5,a6)               (LS_SUCCESS)
#define VLSdiscoverExt(a1,a2,a3,a4,a5,a6,a7,a8)   (LS_SUCCESS)
#define VLSgetHostName(a1,a2,a3)                  (LS_UNRESOLVED_IP_ADDRESS)
#define VLSgetHostAddress(a1,a2,a3)               (LS_UNRESOLVED_HOSTNAME)
#define VLSgetDistbCrit(a1,a2,a3,a4)        (LS_SUCCESS)
#define VLSgetDistbCritToFile(a1,a2,a3)        (LS_SUCCESS)
#define VLSchangeDistbCrit(a1,a2,a3)              (LS_SUCCESS)
#define VLSgetLeaderServerName(a1,a2)            (LS_SUCCESS)
#define VLSaddServerToPool(a1, a2)           (LS_SUCCESS)
#define VLSdelServerFromPool(a1, a2)                  (LS_SUCCESS)
#define VLSaddFeatureExt(a1,a2,a3,a4)             (LS_SUCCESS)
#define VLSaddFeatureToFileExt(a1,a2,a3,a4,a5)    (LS_SUCCESS)
#define VLSgetFeatureInfoToFile(a1,a2,a3)         (LS_SUCCESS)
#endif /* NO_LICENSE */

typedef enum {LOG_SRVR_UP = 1, \
              LOG_LDR_ELECT, \
              LOG_HRT_BT, \
              LOG_BORROW_REQ_RESP, \
              LOG_USG_NOTIFY, \
              LOG_CHNG_DIST_CRIT, \
              LOG_DIST_CRIT_SYNC, \
              LOG_CFG_FILE, \
              LOG_SRVR_DOWN, \
              LOG_MOD_SERVER, \
              LOG_ADD_DEL_LIC} srvrLogState;

#if defined(_VMSWIN_) || defined (WIN32)
#pragma pack(pop)
#endif /*_VMSWIN_*/

/*********************************************************************j
*
* DESCRIPTION :
*       This section contains prototypes and header declarations for 
*       customizing the client/server.  There are various aspects of the
*       client/server that can be customized to suit a vendor's needs.
*       This file lists all the aspects.
*
* USAGE       :
*       All files related to customization must include this section.
*       IMPORTANT-  If a vendor customizes his/her server in any way,
*       he/she must also change the port number of his/her server via
*       the API call VLSchangePortNumber(), so that the customized
*       server does not interfere with other vendors' applications that
*       rely on a default (uncustomized) server.  Of course, the clients
*       must also be modified to contact the server on the new port
*       number, using the client API call VLSsetServerPort().
*
* NOTES       :
*       All functions in this section that are marked OVERRIDE, when present 
*       in vendor's object files, will override default function bodies 
*       present in static libraries of Sentinel RMS Development Kit.  For this to work
*       correctly, vendor must specify his/her overriding object files 
*       BEFORE Sentinel RMS Development Kit libraries in the linker command.  These
*       functions are called by the client/server as and when needed.
*
*       All functions in this section that are marked BUILT-IN, are
*       functions that can be called from any vendor functions.  Vendor
*       should NOT override these functions (i.e., provide his/her own 
*       functions by the same names).
*
*H*/


/*------------------------------------------------------------------------*/
/* Prototypes for client-side customization:                              */
/*------------------------------------------------------------------------*/

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetHoldTime (  /* BUILT-IN */
#ifndef LSNOPROTO
  unsigned char   LSFAR *feature_name, /* IN */
  unsigned char   LSFAR *version,      /* IN */
  int                    hold_time     /* IN */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetSharedId (  /* BUILT-IN */
#ifndef LSNOPROTO
  int shared_id,                                              /* IN */
  LS_STATUS_CODE (VMSWINAPI * mySharedIdFunc) (char LSFAR *)  /* IN */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetSharedIdValue(  /* BUILT-IN */
#ifndef LSNOPROTO
  int                  shared_id,     /* IN */
  char          LSFAR *sharedIdValue  /* IN */
#endif
);

VDLL32 void VMSWINAPI VLSsetServerPort(  /* BUILT-IN */
#ifndef LSNOPROTO
  int port_number                    /* IN */
#endif
);

/*------------------------------------------------------------------------*/
/* Struct containing time tampering Info.                                 */
/*------------------------------------------------------------------------*/

typedef struct  timetampering_info_struct
{
 long   structSz;
 time_t lastTime; 
 time_t currTime; /* current time */
 long   grace_period; /* grace-period allowed */
 int    percentViolationAllowed; /* percentage of violations allowed. in case of UNIX*/
 int    numViolationForError; /* number of violations allowed. in case of UNIX */
 int    numViolationFound; /*Actual number of violations found in case of UNIX*/
 int    percentViolationFound; /*Actual  percent violation found in case of UNIX*/
 unsigned long clkSetBackTime; /*Actual period  by which clock id found back*/
 } VLStimeTamperInfo;

/*------------------------------------------------------------------------*/
/* structure contains server information                                   */
/*------------------------------------------------------------------------*/

typedef struct{
        long              structSz;
        int               major_no;
        int               minor_no;
        int               revision_no;
        int               build_no;
        unsigned char     locale[VLS_SERV_LOCALE_STR_LEN];
        unsigned char     vendor_info[VLS_SERV_VNDINFO_STR_LEN];
        unsigned char     platform[VLS_SERV_PLATFORM_STR_LEN];
        unsigned long     lock_mask;
        unsigned char     unused1[VLS_SERV_UNUSED1_STR_LEN];
        long              unused2;
        VLStimeTamperInfo tmtmpr_info;
        VLSmachineID      machine_id;
} VLSservInfo;

/*------------------------------------------------------------------------*/
/* Prototypes for API retrieve information about server                   */
/*------------------------------------------------------------------------*/

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetServInfo( 
#ifndef LSNOPROTO
 unsigned char LSFAR *server_name, /*  IN */
 VLSservInfo   LSFAR *srv_info,  /* out */
 unsigned char LSFAR *unused1,   /*reserved*/
 unsigned long LSFAR *unused2    /*reserved*/
#endif
);
/*------------------------------------------------------------------------*/
/* Prototypes for client-and-server-side customization:                   */
/*------------------------------------------------------------------------*/

/* Supply custom hostid function/mechanism */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetHostIdFunc(  /* BUILT-IN */
#ifndef LSNOPROTO
  unsigned long (VMSWINAPI * customGetHostIdFunc)(void)  /* IN */
#endif
);

 
/* Network messages encryption/decryption customization: */
VDLL32 int VMSWINAPI VLSencryptMsg(                         /* OVERRIDE */
#ifndef LSNOPROTO
  char *decrypted_mesg,          /* IN */
  char *encrypted_mesg,          /* OUT - allocated by caller */
  int   size                     /* IN */
#endif
);
 
VDLL32 int VMSWINAPI VLSdecryptMsg(                         /* OVERRIDE */
#ifndef LSNOPROTO
  char *encrypted_mesg,          /* IN */
  char *decrypted_mesg,          /* OUT - allocated by caller */
  int   size                     /* IN */
#endif
);
 

/*------------------------------------------------------------------------*/
/* Types and prototypes for server hook functions customization:          */
/*------------------------------------------------------------------------*/

#define HOOK_LS_MAX_PATHLEN           128   /* Path Length */
#define HOOK_CLIENT_IDENTIFIER_SIZE   100   /* Client identifier size */

/* ***** Event types ***** */
#define LS_REQ_PRE               0 /* EVENT : Before processing lsreq() */
#define LS_REQ_POST              1 /* EVENT : After  processing lsreq() */
#define LS_REL_PRE               2 /* EVENT : Before processing lsrel() */
#define LS_REL_POST              3 /* EVENT : After  processing lsrel() */

/* ***** Error codes on server side ***** */
#define LSERV_STATUS_SUCCESS        LS_SUCCESS    /* Success status */
#define LSERV_STATUS_DENY           101  /* Denial by vendor event handler */

typedef int LSERV_STATUS;

/* Structure for File Location Info passed to vendor event handlers. */ 
typedef struct {
  char       lservrcFile    [HOOK_LS_MAX_PATHLEN];   /* lservrc file path */
  char       lservrcCnfFile [HOOK_LS_MAX_PATHLEN];   /* lserv cnf file path */
  char       lservStaFile   [HOOK_LS_MAX_PATHLEN];   /* lserv usage file path */
  char       lservLogFile   [HOOK_LS_MAX_PATHLEN];   /* lserv error message file path */
  char       lsGrResvFile   [HOOK_LS_MAX_PATHLEN];   /* lserv group file path */
  char       reserved       [HOOK_LS_MAX_PATHLEN];   /* reserved */
} VLSfileLocInfo;

/* Structure for Misc. Info passed to vendor event handlers. */
typedef struct {
  char            ipAddress     [VLS_MAX_NAME_LEN];    /* of client */
                  /* Flags indicate status of tests for this request: */
  int             nodeLockPass;       /* 1 => Node locking tests pass */
  int             siteLicensePass;    /* 1 => Site licensing tests pass */
  int             licExpirationPass;  /* 1 => License expiration tests pass */
  int             clockTamperPass;    /* 1 => Clock tampering tests pass */
  char            reserved      [VLS_MAX_NAME_LEN];
} VLSmiscInfo;

/* The complete structure passed to vendor event handlers. */
typedef struct {
  VLSclientInfo   clientInfoStruct;  /* Same as client API struct */
  VLSfeatureInfo  featureInfoStruct; /* Same as client API struct */
  VLSfileLocInfo  fileLocInfoStruct;
  VLSmiscInfo     miscInfoStruct;
} VLShandlerStruct;


/*
 * Called by server during server initialization.  This is where
 * calls to VLSeventAddHook() should be placed, to configure the server
 * to consult vendor event handler functions.
 */
VDLL32 LSERV_STATUS VMSWINAPI VLSserverVendorInitialize(    /* OVERRIDE */
#ifndef LSNOPROTO
  void
#endif
);
/*API to set vendor specific information */
VDLL32 LSERV_STATUS VMSWINAPI VLSsetServerInfo(
#ifndef LSNOPROTO
     char  LSFAR **vendorInfo
#endif
);

/* Call to register an event handler with the server. */
VDLL32 LSERV_STATUS VMSWINAPI VLSeventAddHook(              /* BUILT-IN */
#ifndef LSNOPROTO
  int       eventName,  /* IN - event type , LS_REQ / LS_REL */
                                             /* _PRE / _POST */
  int       (*handlerFuncPtr)(VLShandlerStruct *, char *, char *, int), 
                        /* IN - function pointer */
  char   *  identifier  /* IN - client identifier to match */
#endif
);


/*------------------------------------------------------------------------*/
/* Client-side calls to use Server Hooks:                                 */
/*------------------------------------------------------------------------*/

/* Struct passed to server from client while using server hooks: */
typedef  struct {
   char   identifier[VLS_MAX_NAME_LEN];
   char   inBuf[VLS_MAX_BUF_LEN];   /* String passed to the server */
   char   outBuf[VLS_MAX_BUF_LEN];  /* String returned by the server */
} VLSserverInfo;


VDLL32 LS_STATUS_CODE VMSWINAPI VLSinitServerInfo (  /* BUILT-IN */
#ifndef LSNOPROTO
  VLSserverInfo    LSFAR    *serverInfo  /* OUT - allocated by caller */
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSrequestExt (  /* BUILT-IN */
#ifndef LSNOPROTO
  unsigned char  LSFAR *license_system,  /* IN */
  unsigned char  LSFAR *publisher_name,  /* IN */
  unsigned char  LSFAR *product_name,    /* IN */
  unsigned char  LSFAR *version,         /* IN */
  unsigned long  LSFAR *units_reqd,      /* IN */
  unsigned char  LSFAR *log_comment,     /* IN */
  LS_CHALLENGE   LSFAR *challenge,       /* INOUT - allocated by caller */
  LS_HANDLE      LSFAR *lshandle,        /* OUT - allocated by caller */
  VLSserverInfo  LSFAR *serverInfo       /* INOUT - allocated by caller */
#endif /* LSNOPROTO */
);

/* New Client API for requesting Capacity licenses.
 * Added in SLM 7.3.0
 */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSrequestExt2 (  /* BUILT-IN */
#ifndef LSNOPROTO
  unsigned char  LSFAR *license_system,  /* IN */
  unsigned char  LSFAR *publisher_name,  /* IN */
  unsigned char  LSFAR *product_name,    /* IN */
  unsigned char  LSFAR *version,         /* IN */
  unsigned long  LSFAR *units_reqd,      /* IN */
  unsigned char  LSFAR *log_comment,     /* IN */
  LS_CHALLENGE   LSFAR *challenge,       /* INOUT - allocated by caller */
  LS_HANDLE      LSFAR *lshandle,        /* OUT - allocated by caller */
  VLSserverInfo  LSFAR *serverInfo,      /* INOUT - allocated by caller */
  unsigned long  LSFAR *team_capacity_reqd,
  unsigned long  LSFAR *user_capacity_reqd,
  unsigned char  LSFAR *unused1,
  unsigned long  LSFAR *special_flag     /* INOUT - general purpose flag.
                                            Used for grace installation error 
                                            handling in SLM 800 */ 
#endif /* LSNOPROTO */
);


VDLL32 LS_STATUS_CODE VMSWINAPI VLSqueuedRequestExt (  /* BUILT-IN */
#ifndef LSNOPROTO
  unsigned char      LSFAR *license_system,  /* IN */
  unsigned char      LSFAR *publisher_name,  /* IN */
  unsigned char      LSFAR *product_name,    /* IN */
  unsigned char      LSFAR *version,         /* IN */
  unsigned long      LSFAR *units_reqd,      /* IN */
  unsigned char      LSFAR *log_comment,     /* IN */
  LS_CHALLENGE       LSFAR *challenge,       /* INOUT - allocated by caller */
  LS_HANDLE          LSFAR *lshandle,        /* OUT - allocated by caller */
  VLSqueuePreference LSFAR *qPreference,     /* INOUT - allocated by caller*/
  int                LSFAR *requestFlag,     /* INOUT - allocated by caller*/
  VLSserverInfo      LSFAR *serverInfo       /* INOUT - allocated by caller */
#endif /* LSNOPROTO */
);

/* Returns LS_SUCCESS if the number of units actually returned is same as the
   value of "units_consumed" paramter passed to this API.
   Returns VLS_ALL_UNITS_RELEASED, if it returnes all the units evenif asked for
   some specific number of units to be returned.
 */

VDLL32 LS_STATUS_CODE VMSWINAPI VLSreleaseExt (  /* BUILT-IN */
#ifndef LSNOPROTO
  LS_HANDLE             lshandle,        /* IN */
  unsigned long         units_consumed,  /* IN */
  unsigned char  LSFAR *log_comment,     /* IN */
  VLSserverInfo  LSFAR *serverInfo       /* INOUT - allocated by caller */
#endif /* LSNOPROTO */
);


/*------------------------------------------------------------------------*/
/* Time tamper customization (for server and standalone mode):            */
/*------------------------------------------------------------------------*/
 
typedef enum {VLS_CONT_AFTER_TM_TAMPER, VLS_EXIT_AFTER_TM_TAMPER}
        VLSactionOnTmTamper;
 
typedef enum {VLS_ENABLE_DEFAULT_TM_TAMPER, VLS_DISABLE_DEFAULT_TM_TAMPER}
        VLStmTamperMethod;
 

/*
 * Called by server each time server needs to verify whether the system
 * clock has been set back.  Default behavior of the server can be
 * customized here.  Note this is called BEFORE any checks are performed
 * by the server.
 */
VDLL32 void VMSWINAPI VLSconfigureTimeTamper (              /* OVERRIDE */
#ifndef LSNOPROTO
  VLSactionOnTmTamper *   actionOnTmTamper,       /* OUT */
  VLStmTamperMethod   *   tmTamperMethod,         /* OUT */
#ifdef _V_LP64_
  int                *   gracePeriod,            /* OUT */
#else
  long                *   gracePeriod,            /* OUT */
#endif
  int                 *   percentViolations,      /* OUT */
  int                 *   numViolationsForError   /* OUT */
#endif
);
 
/*
 * Vendor's function to tell the server if clock has been set back.
 * Called only in case vendor's VLSconfigureTimeTamper() function returns 
 * tmTamperMethod to be VLS_DISABLE_DEFAULT_TM_TAMPER, not otherwise.
 * Should return 0 if clock is not set back.
 */
VDLL32 int VMSWINAPI VLSisClockSetBack(
#ifndef LSNOPROTO
void
#endif
);                   /* OVERRIDE */



/*------------------------------------------------------------------------*/
/* License encryption/decryption customization (server and standalone)    */
/*------------------------------------------------------------------------*/
 
VDLL32 int VMSWINAPI VLSencryptLicense(                     /* OVERRIDE */
#ifndef LSNOPROTO
  char *decrypted_mesg,          /* IN */
  char *encrypted_mesg,          /* OUT - allocated by caller */
  int   size                     /* IN */
#endif
);
 
VDLL32 int VMSWINAPI VLSdecryptLicense(                     /* OVERRIDE */
#ifndef LSNOPROTO
  char *encrypted_mesg,          /* IN */
  char *decrypted_mesg,          /* OUT - allocated by caller */
  int   size                     /* IN */
#endif
);
 
/*------------------------------------------------------------------------*/
/* Upgrade License encryption/decryption customization (server and standalone)    */
/*------------------------------------------------------------------------*/
 
VDLL32 int VMSWINAPI VLSencryptUpgradeLicense(                     /* OVERRIDE */
#ifndef LSNOPROTO
  char *decrypted_mesg,          /* IN */
  char *encrypted_mesg,          /* OUT - allocated by caller */
  int   size                     /* IN */
#endif
);
 
VDLL32 int VMSWINAPI VLSdecryptUpgradeLicense(                     /* OVERRIDE */
#ifndef LSNOPROTO
  char *encrypted_mesg,          /* IN */
  char *decrypted_mesg,          /* OUT - allocated by caller */
  int   size                     /* IN */
#endif
);
 

/*------------------------------------------------------------------------*/
/* Server UDP port number customization:                                  */
/*------------------------------------------------------------------------*/
 
/* Should return the desired UDP port number of server */
VDLL32 int VMSWINAPI VLSchangePortNumber(                   /* OVERRIDE */
#ifndef LSNOPROTO
  int  currentPort      /* IN  - Currently configured port number */
#endif
);

/*------------------------------------------------------------------------*/
/* Server TFTP port number customization:                                  */
/*------------------------------------------------------------------------*/
 
/* Should return the desired UDP port number of server */
VDLL32 int VMSWINAPI VLSchangeTFTPPortNumber(                   /* OVERRIDE */
#ifndef LSNOPROTO
  int  current_port      /* IN  - Currently configured TFTP port number */
#endif
);

/*------------------------------------------------------------------------*/
/* Types and prototypes for tag-related functions.                        */
/*------------------------------------------------------------------------*/
typedef enum {
  VLS_TAG_TYPE_INVALID, VLS_TAG_TYPE_KEY
} VLStagType;

typedef struct {
  VLStagType    type;
  long          lifetime;                /* Tag's Time-To-Live. */
  char          signature[VLS_MAXLEN];       /* `Seed' for tag generation. */
  char          lservHost[VLS_MAXLEN];
  short         lservPort;
  char          id[VLS_MAXLEN];              /* The tag. */

  /* Validity period of tag as seen by client. */
  long          clientStartTime;
  long          clientEndTime;
  /* Validity period of tag as seen by server. */
  long          serverStartTime;
  long          serverEndTime;

  /* Server identification. Useful for validation. */
  char          serverID[VLS_MAXLEN];
  
  char          unused1[VLS_MAXLEN];
  char          unused2[VLS_MAXLEN];
} VLStagHandle;
 
VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetPoolServerList (
#ifndef LSNOPROTO
  char * outBuf,
  int    outBufSz
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSsetBorrowingStatus (
#ifndef LSNOPROTO
char   *   feature_name,
char   *   version,
int        state
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI  VLSsetServerLogState (
#ifndef LSNOPROTO
  int  event,
  int  state 
#endif
);

#ifdef _VMSWIN_ 
VDLL32 LS_STATUS_CODE VMSWINAPI  VLSsetOutputCP(
#ifndef LSNOPROTO
  int  cp /*in*/
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI  VLSgetOutputCP(
#ifndef LSNOPROTO
  int  *cp    /*out*/ 
#endif
);
#endif  /*_VMSWIN_*/

/* Available only on UNIX */
/* Function to be used instead of sleep */
void  VLSeventSleep (
#ifndef LSNOPROTO
unsigned long seconds
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetMachineIDString(
#ifndef LSNOPROTO
      unsigned long *lock_selector, /* INOUT   */
      unsigned char *machineIDString,  /* OUT - preallocated*/
      unsigned long *bufSz /* INOUT - returns buffer size if
                              machineIDString is NULL */
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSgetCommuterCode (
#ifndef LSNOPROTO
      unsigned char  *feature_name,    /* IN */
      unsigned char  *feature_version, /* IN */
      unsigned long  *units_reqd,      /* IN */
#if (defined _HP_UX11_ && _V_LP64_)
      int *duration,        /* IN/OUT */    
#else
      unsigned long *duration,
#endif
      unsigned long  *lock_mask,       /* IN */
      unsigned char  *log_comment,     /* IN */
      unsigned char  *machineIDString, /* IN */
      unsigned char  *commuter_code,   /* OUT */
      LS_CHALLENGE   *challenge,       /* IN/OUT */
      VLSserverInfo  *requestInfo,     /* IN/OUT */
      VLSserverInfo  *commuterInfo,    /* IN/OUT - to be used in future for hooks */
      unsigned long  *reserved1        /* IN/OUT */
#endif /* LSNOPROTO */
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLSinstallCommuterCode ( 
#ifndef LSNOPROTO
      unsigned char  *commuter_code, /* IN */ 
      unsigned char  *reserved1,     /* IN */ 
      unsigned long   reserved2      /* IN */
#endif /* LSNOPROTO */
);

LS_STATUS_CODE VLSgenerateUpgradeLockCode (
#ifndef LSNOPROTO
  unsigned char *lic_string,
  unsigned char *upgrade_lock_code,
  unsigned long *szUpgradecode
#endif
);

VDLL32 LS_STATUS_CODE VMSWINAPI VLScontrolRemoteSession (
#ifndef LSNOPROTO
  int toCheckRemoteSession
#endif
);

/**********************************************************************************
 * DESCRIPTION :
 *  It decodes the upgarde lock code  string "UpgradeLockCodeString" and puts the  
 *  corresponding ulcCode struct in the last argument.Address of a pointer to 
 *  ulcCode struct is to be passed as the last argument.
 *  This pointer will contain the ulcCode of the input upgardelock code string.
 *  This function takes care of all memory allocations it uses.
 *    
 * RETURN VALUES:
 *  returns LS_SUCCESS on successful return. 
 *  returns LS_NORESOURCES on malloc failure.
 *  else returns VLS_INTERNAL_ERROR
 * NOTE :
 */

int VLSdecodeUpgradelockCode(
#ifndef LSNOPROTO
  char *           upgrade_lock_code,         /* IN  upgrade lock code string*/
  char *           compacted_upd_lock_code,   /* OUT upgrade lock code string after removing
                                               *     comment chars and white spaces 
                                               *     NOTE:if this parameter "compacted_upd_lock_code"
                                               *          is set as NULL then set third parameter "length"
                                               *          as 0 else set third parameter length  as 
                                               *         " (sizeof(compacted_upd_lock_code)+1)"
                                               */
  int              length,                    /* IN  length of compacted_upd_lock_code */
  ulcCode **       ulcCodePP                  /* OUT */
#endif /* LSNOPROTO */
);

/* License revocation API. */
VDLL32 LS_STATUS_CODE VMSWINAPI VLSrevokeLicense
(
#ifndef LSNOPROTO
  unsigned char   *server_name,     /* IN */
  unsigned char   *feature_name,    /* IN */
  unsigned char   *feature_version, /* IN */
  unsigned long   capacity,  /* IN */
  unsigned char   *password,        /* IN */
  int             *units_to_revoke, /* IN/OUT */
  unsigned long   *capacity_to_revoke,/* IN/OUT */
  unsigned char   *rvk_ticket, /* OUT */
  int             *length_of_rvk_ticket, /* IN/OUT */
  unsigned char   *log_comment,      /* IN */
  unsigned long   *reserved1,       /* IN */
  unsigned char   *reserved2        /* IN */
#endif /* LSNOPROTO */
);

/*------------------------------------------------------------------------*/
/* Macros which will make all Sentinel RMS Development Kit functions void:  */
/*------------------------------------------------------------------------*/

#ifdef NO_LICENSE
#define VLSinitServerInfo(a1)                               (LS_SUCCESS)
#define VLSeventAddHook(a1,a2,a3)                           (LS_SUCCESS)
#define VLSreleaseExt(a1,a2,a3,a4)                          (LS_SUCCESS)
#define VLSrequestExt(a1,a2,a3,a4,a5,a6,a7,a8,a9)           (LS_SUCCESS)
#define VLSsetHoldTime(a1,a2)                               (LS_SUCCESS)
#define VLSsetHostIdFunc(a1)                                (LS_SUCCESS)
#define VLSsetServerPort(a1)                                /* void return */
#define VLSsetSharedId(a1,a2)                               (LS_SUCCESS)
#define VLSsetSharedIdValue(a1,a2)                          (LS_SUCCESS)
#define VLSrequestExt2(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13)  (LS_SUCCESS)
#define VLSgetFeatureInfoExt(a1,a2,a3,a4,a5,a6,a7)          (VLS_NO_MORE_FEATURE)
#define VLSgetClientInfoExt(a1,a2,a3,a4,a5,a6,a7)           (VLS_NO_MORE_CLIENTS)
#define VLSgetCapacityList(a1,a2,a3,a4,a5,a6,a7)            (VLS_NO_MORE_FEATURE)
#define VLSgetCapacityFromHandle(a1,a2,a3,a4)               (LS_BADHANDLE)
#define VLSdeleteFeatureExt(a1,a2,a3,a4,a5,a6,a7)           (LS_SUCCESS)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _LSERV_H_ */

