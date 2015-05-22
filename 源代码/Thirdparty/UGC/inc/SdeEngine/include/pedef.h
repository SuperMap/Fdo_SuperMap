/* $Id: pedef.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
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
#ifndef PEDEF_INCLUDED
#define PEDEF_INCLUDED

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*                      U N I T S   O F   M E A S U R E                       */
/*----------------------------------------------------------------------------*/
#define PE_U_METER             9001 /* International meter                    */
#define PE_U_FOOT              9002 /* International foot                     */
#define PE_U_FOOT_US           9003 /* US survey foot                         */
#define PE_U_FOOT_CLARKE       9005 /* Clarke's foot                          */
#define PE_U_FATHOM            9014 /* Fathom                                 */
#define PE_U_NAUTICAL_MILE     9030 /* International nautical mile            */
#define PE_U_METER_GERMAN      9031 /* German legal meter                     */
#define PE_U_CHAIN_US          9033 /* US survey chain                        */
#define PE_U_LINK_US           9034 /* US survey link                         */
#define PE_U_MILE_US           9035 /* US survey mile                         */
#define PE_U_KILOMETER         9036 /* Kilometer                              */
#define PE_U_YARD_CLARKE       9037 /* Yard (Clarke)                          */
#define PE_U_CHAIN_CLARKE      9038 /* Chain (Clarke)                         */
#define PE_U_LINK_CLARKE       9039 /* Link (Clarke's ratio) (was PE_U_LINK 9007) */
#define PE_U_YARD_SEARS        9040 /* Yard (Sears)          (was 9012)       */
#define PE_U_FOOT_SEARS        9041 /* Sears' foot           (was 9032)       */
#define PE_U_CHAIN_SEARS       9042 /* Chain (Sears)         (was 9011)       */
#define PE_U_LINK_SEARS        9043 /* Link (Sears)          (was 9009)       */
#define PE_U_YARD_BENOIT_A     9050 /* Yard (Benoit 1895 A)                   */
#define PE_U_FOOT_BENOIT_A     9051 /* Foot (Benoit 1895 A)                   */
#define PE_U_CHAIN_BENOIT_A    9052 /* Chain (Benoit 1895 A)                  */
#define PE_U_LINK_BENOIT_A     9053 /* Link (Benoit 1895 A)                   */
#define PE_U_YARD_BENOIT_B     9060 /* Yard (Benoit 1895 B)                   */
#define PE_U_FOOT_BENOIT_B     9061 /* Foot (Benoit 1895 B)                   */
#define PE_U_CHAIN_BENOIT_B    9062 /* Chain (Benoit 1895 B) (was PE_U_CHAIN_BENOIT 9010)*/
#define PE_U_LINK_BENOIT_B     9063 /* Link (Benoit 1895 B) (was PE_U_LINK_BENOIT 9008)*/
#define PE_U_FOOT_1865         9070 /* Foot (1865)                            */
#define PE_U_FOOT_INDIAN       9080 /* Indian geodetic foot  (was 9006)       */
#define PE_U_FOOT_INDIAN_1937  9081 /* Indian foot (1937)                     */
#define PE_U_FOOT_INDIAN_1962  9082 /* Indian foot (1962)                     */
#define PE_U_FOOT_INDIAN_1975  9083 /* Indian foot (1975)                     */
#define PE_U_YARD_INDIAN       9084 /* Indian yard           (was 9013)       */
#define PE_U_YARD_INDIAN_1937  9085 /* Indian yard (1937)                     */
#define PE_U_YARD_INDIAN_1962  9086 /* Indian yard (1962)                     */
#define PE_U_YARD_INDIAN_1975  9087 /* Indian yard (1975)                     */
#define PE_U_MILE_STATUTE      9093 /* Statute mile                           */
#define PE_U_FOOT_GOLD_COAST   9094 /* Gold Coast Foot                        */
#define PE_U_FOOT_BRITISH_1936 9095 /* British Foot (1936)                    */
#define PE_U_YARD            109001 /* International Yard                     */
#define PE_U_YARD_US         109002 /* US survey yard                         */
#define PE_U_CHAIN           109003 /* International Chain                    */
#define PE_U_LINK            109004 /* International Link                     */
#define PE_U_KM50            109030 /*  50 kilometer length                   */
#define PE_U_KM150           109031 /* 150 kilometer length                   */

#define PE_U_RADIAN            9101 /* Radian                                 */
#define PE_U_DEGREE            9102 /* Degree                                 */
#define PE_U_MINUTE            9103 /* Arc-minute                             */
#define PE_U_SECOND            9104 /* Arc-second                             */
#define PE_U_GRAD              9105 /* Grad (angle subtended by 1/400 circle) */
#define PE_U_GON               9106 /* Gon  (angle subtended by 1/400 circle) */
#define PE_U_MICRORADIAN       9109 /* Microradian ( 1e-6 radian )            */
#define PE_U_MINUTE_CENTESIMAL 9112 /* Centesimal minute (1/100th Gon (Grad)) */
#define PE_U_SECOND_CENTESIMAL 9113 /* Centesimal second(1/10000th Gon (Grad))*/
#define PE_U_MIL_6400          9114 /* Mil (angle subtended by 1/6400 circle) */


/*----------------------------------------------------------------------------*/
/*                    G E O D E T I C   S P H E R O I D S                     */
/*----------------------------------------------------------------------------*/
#define PE_S_AIRY_1830           7001 /* Airy 1830                            */
#define PE_S_AIRY_MOD            7002 /* Airy modified                        */
#define PE_S_ATS_1977            7041 /* Average Terrestrial System 1977      */
#define PE_S_AUSTRALIAN          7003 /* Australian National                  */
#define PE_S_BESSEL_1841         7004 /* Bessel 1841                          */
#define PE_S_BESSEL_MOD          7005 /* Bessel modified                      */
#define PE_S_BESSEL_NAMIBIA      7006 /* Bessel Namibia                       */
#define PE_S_CLARKE_1858         7007 /* Clarke 1858                          */
#define PE_S_CLARKE_1866         7008 /* Clarke 1866                          */
#define PE_S_CLARKE_1866_MICH    7009 /* Clarke 1866 Michigan                 */
#define PE_S_CLARKE_1880         7034 /* Clarke 1880                          */
#define PE_S_CLARKE_1880_ARC     7013 /* Clarke 1880 (Arc)                    */
#define PE_S_CLARKE_1880_BENOIT  7010 /* Clarke 1880 (Benoit)                 */
#define PE_S_CLARKE_1880_IGN     7011 /* Clarke 1880 (IGN)                    */
#define PE_S_CLARKE_1880_RGS     7012 /* Clarke 1880 (RGS)                    */
#define PE_S_CLARKE_1880_SGA     7014 /* Clarke 1880 (SGA)                    */
#define PE_S_DANISH_1876         7051 /* Danish 1876                          */
#define PE_S_EVEREST_1830        7042 /* Everest 1830 (definition)            */
#define PE_S_EVEREST_MOD         7018 /* Everest 1830 (modified)              */
#define PE_S_EVEREST_ADJ_1937    7015 /* Everest (adjustment 1937)            */
#define PE_S_EVEREST_DEF_1962    7044 /* Everest (definition 1962)            */
#define PE_S_EVEREST_DEF_1967    7016 /* Everest (definition 1967)            */
#define PE_S_EVEREST_DEF_1975    7045 /* Everest (definition 1975) (was 7017) */
#define PE_S_GEM_10C             7031 /* GEM gravity potential model          */
#define PE_S_GRS_1967            7036 /* GRS 1967 = International 1967        */
#define PE_S_GRS_1980            7019 /* GRS 1980                             */
#define PE_S_HELMERT_1906        7020 /* Helmert 1906                         */
#define PE_S_INDONESIAN          7021 /* Indonesian National                  */
#define PE_S_INTERNATIONAL_1924  7022 /* International 1924                   */
#define PE_S_INTERNATIONAL_1967  7023 /* International 1967                   */
#define PE_S_KRASOVSKY_1940      7024 /* Krasovsky 1940                       */
#define PE_S_NWL_9D              7025 /* Transit precise ephemeris            */
#define PE_S_OSU_86F             7032 /* OSU 1986 geoidal model               */
#define PE_S_OSU_91A             7033 /* OSU 1991 geoidal model               */
#define PE_S_PLESSIS_1817        7027 /* Plessis 1817                         */
#define PE_S_SPHERE              7035 /* Authalic sphere                      */
#define PE_S_SPHERE_GRS_1980_AUTHALIC  7048 /* Authalic Sphere based on GRS80 */
#define PE_S_STRUVE_1860         7028 /* Struve 1860                          */
#define PE_S_WAR_OFFICE          7029 /* War Office                           */
#define PE_S_NWL_10D             7026 /* NWL-10D == WGS 1972                  */
#define PE_S_WGS_1972            7043 /* WGS 1972                             */
#define PE_S_WGS_1984            7030 /* WGS 1984                             */
#define PE_S_XIAN_1980           7049 /* Xian 1980                            */

#define PE_S_WGS_1966           107001 /* WGS 1966                            */
#define PE_S_FISCHER_1960       107002 /* Fischer 1960                        */
#define PE_S_FISCHER_1968       107003 /* Fischer 1968                        */
#define PE_S_FISCHER_MOD        107004 /* Fischer modified                    */
#define PE_S_HOUGH_1960         107005 /* Hough 1960                          */
#define PE_S_EVEREST_MOD_1969   107006 /* Everest modified 1969               */
#define PE_S_WALBECK            107007 /* Walbeck                             */
#define PE_S_SPHERE_AI          107008 /* Authalic sphere (ARC/INFO)          */
#define PE_S_SPHERE_EMEP        107009 /* EMEP Sphere of 6370000 m            */
#define PE_S_GRS_1967_TRUNC     107036 /* GRS 1967 Truncated                  */

#define PE_S_GRS_1980_ADJ_MN_ANOKA      107700 /* GRS 1980 Adj. Minnesota Anoka */
#define PE_S_GRS_1980_ADJ_MN_BECKER     107701 /* GRS 1980 Adj. Minnesota Becker */
#define PE_S_GRS_1980_ADJ_MN_BELTRAMI_N 107702 /* GRS 1980 Adj. Minnesota Beltrami_North */
#define PE_S_GRS_1980_ADJ_MN_BELTRAMI_S 107703 /* GRS 1980 Adj. Minnesota Beltrami_South */
#define PE_S_GRS_1980_ADJ_MN_BENTON     107704 /* GRS 1980 Adj. Minnesota Benton */
#define PE_S_GRS_1980_ADJ_MN_BIG_STONE  107705 /* GRS 1980 Adj. Minnesota Big_Stone */
#define PE_S_GRS_1980_ADJ_MN_BLUE_EARTH 107706 /* GRS 1980 Adj. Minnesota Blue_Earth */
#define PE_S_GRS_1980_ADJ_MN_BROWN      107707 /* GRS 1980 Adj. Minnesota Brown */
#define PE_S_GRS_1980_ADJ_MN_CARLTON    107708 /* GRS 1980 Adj. Minnesota Carlton */
#define PE_S_GRS_1980_ADJ_MN_CARVER     107709 /* GRS 1980 Adj. Minnesota Carver */
#define PE_S_GRS_1980_ADJ_MN_CASS_N     107710 /* GRS 1980 Adj. Minnesota Cass_North */
#define PE_S_GRS_1980_ADJ_MN_CASS_S     107711 /* GRS 1980 Adj. Minnesota Cass_South */
#define PE_S_GRS_1980_ADJ_MN_CHIPPEWA   107712 /* GRS 1980 Adj. Minnesota Chippewa */
#define PE_S_GRS_1980_ADJ_MN_CHISAGO    107713 /* GRS 1980 Adj. Minnesota Chisago */
#define PE_S_GRS_1980_ADJ_MN_COOK_N     107714 /* GRS 1980 Adj. Minnesota Cook_North */
#define PE_S_GRS_1980_ADJ_MN_COOK_S     107715 /* GRS 1980 Adj. Minnesota Cook_South */
#define PE_S_GRS_1980_ADJ_MN_COTTONWOOD 107716 /* GRS 1980 Adj. Minnesota Cottonwood */
#define PE_S_GRS_1980_ADJ_MN_CROW_WING  107717 /* GRS 1980 Adj. Minnesota Crow_Wing */
#define PE_S_GRS_1980_ADJ_MN_DAKOTA     107718 /* GRS 1980 Adj. Minnesota Dakota */
#define PE_S_GRS_1980_ADJ_MN_DODGE      107719 /* GRS 1980 Adj. Minnesota Dodge */
#define PE_S_GRS_1980_ADJ_MN_DOUGLAS    107720 /* GRS 1980 Adj. Minnesota Douglas */
#define PE_S_GRS_1980_ADJ_MN_FARIBAULT  107721 /* GRS 1980 Adj. Minnesota Faribault */
#define PE_S_GRS_1980_ADJ_MN_FILLMORE   107722 /* GRS 1980 Adj. Minnesota Fillmore */
#define PE_S_GRS_1980_ADJ_MN_FREEBORN   107723 /* GRS 1980 Adj. Minnesota Freeborn */
#define PE_S_GRS_1980_ADJ_MN_GOODHUE    107724 /* GRS 1980 Adj. Minnesota Goodhue */
#define PE_S_GRS_1980_ADJ_MN_GRANT      107725 /* GRS 1980 Adj. Minnesota Grant */
#define PE_S_GRS_1980_ADJ_MN_HENNEPIN   107726 /* GRS 1980 Adj. Minnesota Hennepin */
#define PE_S_GRS_1980_ADJ_MN_HOUSTON    107727 /* GRS 1980 Adj. Minnesota Houston */
#define PE_S_GRS_1980_ADJ_MN_ISANTI     107728 /* GRS 1980 Adj. Minnesota Isanti */
#define PE_S_GRS_1980_ADJ_MN_ITASCA_N   107729 /* GRS 1980 Adj. Minnesota Itasca_North */
#define PE_S_GRS_1980_ADJ_MN_ITASCA_S   107730 /* GRS 1980 Adj. Minnesota Itasca_South */
#define PE_S_GRS_1980_ADJ_MN_JACKSON    107731 /* GRS 1980 Adj. Minnesota Jackson */
#define PE_S_GRS_1980_ADJ_MN_KANABEC    107732 /* GRS 1980 Adj. Minnesota Kanabec */
#define PE_S_GRS_1980_ADJ_MN_KANDIYOHI  107733 /* GRS 1980 Adj. Minnesota Kandiyohi */
#define PE_S_GRS_1980_ADJ_MN_KITTSON    107734 /* GRS 1980 Adj. Minnesota Kittson */
#define PE_S_GRS_1980_ADJ_MN_KOOCHICHING   107735 /* GRS 1980 Adj. Minnesota Koochiching */
#define PE_S_GRS_1980_ADJ_MN_LAC_QUI_PARLE 107736 /* GRS 1980 Adj. Minnesota Lac_Qui_Parle */
#define PE_S_GRS_1980_ADJ_MN_LAKE_OF_THE_WOODS_N 107737 /* GRS 1980 Adj. Minnesota */
                                                        /* Lake_of_the_Woods_North */
#define PE_S_GRS_1980_ADJ_MN_LAKE_OF_THE_WOODS_S 107738 /* GRS 1980 Adj. Minnesota */
                                                        /* Lake_of_the_Woods_South */
#define PE_S_GRS_1980_ADJ_MN_LE_SUEUR   107739 /* GRS 1980 Adj. Minnesota Le_Sueur */
#define PE_S_GRS_1980_ADJ_MN_LINCOLN    107740 /* GRS 1980 Adj. Minnesota Lincoln */
#define PE_S_GRS_1980_ADJ_MN_LYON       107741 /* GRS 1980 Adj. Minnesota Lyon */
#define PE_S_GRS_1980_ADJ_MN_MCLEOD     107742 /* GRS 1980 Adj. Minnesota McLeod */
#define PE_S_GRS_1980_ADJ_MN_MAHNOMEN   107743 /* GRS 1980 Adj. Minnesota Mahnomen */
#define PE_S_GRS_1980_ADJ_MN_MARSHALL   107744 /* GRS 1980 Adj. Minnesota Marshall */
#define PE_S_GRS_1980_ADJ_MN_MARTIN     107745 /* GRS 1980 Adj. Minnesota Martin */
#define PE_S_GRS_1980_ADJ_MN_MEEKER     107746 /* GRS 1980 Adj. Minnesota Meeker */
#define PE_S_GRS_1980_ADJ_MN_MORRISON   107747 /* GRS 1980 Adj. Minnesota Morrison */
#define PE_S_GRS_1980_ADJ_MN_MOWER      107748 /* GRS 1980 Adj. Minnesota Mower */
#define PE_S_GRS_1980_ADJ_MN_MURRAY     107749 /* GRS 1980 Adj. Minnesota Murray */
#define PE_S_GRS_1980_ADJ_MN_NICOLLET   107750 /* GRS 1980 Adj. Minnesota Nicollet */
#define PE_S_GRS_1980_ADJ_MN_NOBLES     107751 /* GRS 1980 Adj. Minnesota Nobles */
#define PE_S_GRS_1980_ADJ_MN_NORMAN     107752 /* GRS 1980 Adj. Minnesota Norman */
#define PE_S_GRS_1980_ADJ_MN_OLMSTED    107753 /* GRS 1980 Adj. Minnesota Olmsted */
#define PE_S_GRS_1980_ADJ_MN_OTTERTAIL  107754 /* GRS 1980 Adj. Minnesota Ottertail */
#define PE_S_GRS_1980_ADJ_MN_PENNINGTON 107755 /* GRS 1980 Adj. Minnesota Pennington */
#define PE_S_GRS_1980_ADJ_MN_PINE       107756 /* GRS 1980 Adj. Minnesota Pine */
#define PE_S_GRS_1980_ADJ_MN_PIPESTONE  107757 /* GRS 1980 Adj. Minnesota Pipestone */
#define PE_S_GRS_1980_ADJ_MN_POLK       107758 /* GRS 1980 Adj. Minnesota Polk */
#define PE_S_GRS_1980_ADJ_MN_POPE       107759 /* GRS 1980 Adj. Minnesota Pope */
#define PE_S_GRS_1980_ADJ_MN_RAMSEY     107760 /* GRS 1980 Adj. Minnesota Ramsey */
#define PE_S_GRS_1980_ADJ_MN_RED_LAKE   107761 /* GRS 1980 Adj. Minnesota Red_Lake */
#define PE_S_GRS_1980_ADJ_MN_REDWOOD    107762 /* GRS 1980 Adj. Minnesota Redwood */
#define PE_S_GRS_1980_ADJ_MN_RENVILLE   107763 /* GRS 1980 Adj. Minnesota Renville */
#define PE_S_GRS_1980_ADJ_MN_RICE       107764 /* GRS 1980 Adj. Minnesota Rice */
#define PE_S_GRS_1980_ADJ_MN_ROCK       107765 /* GRS 1980 Adj. Minnesota Rock */
#define PE_S_GRS_1980_ADJ_MN_ROSEAU     107766 /* GRS 1980 Adj. Minnesota Roseau */
#define PE_S_GRS_1980_ADJ_MN_ST_LOUIS_N 107767 /* GRS 1980 Adj. Minnesota St_Louis_North */
#define PE_S_GRS_1980_ADJ_MN_ST_LOUIS_C 107768 /* GRS 1980 Adj. Minnesota St_Louis_Central */
#define PE_S_GRS_1980_ADJ_MN_ST_LOUIS_S 107769 /* GRS 1980 Adj. Minnesota St_Louis_South */
#define PE_S_GRS_1980_ADJ_MN_SCOTT      107770 /* GRS 1980 Adj. Minnesota Scott */
#define PE_S_GRS_1980_ADJ_MN_SHERBURNE  107771 /* GRS 1980 Adj. Minnesota Sherburne */
#define PE_S_GRS_1980_ADJ_MN_SIBLEY     107772 /* GRS 1980 Adj. Minnesota Sibley */
#define PE_S_GRS_1980_ADJ_MN_STEARNS    107773 /* GRS 1980 Adj. Minnesota Stearns */
#define PE_S_GRS_1980_ADJ_MN_STEELE     107774 /* GRS 1980 Adj. Minnesota Steele */
#define PE_S_GRS_1980_ADJ_MN_STEVENS    107775 /* GRS 1980 Adj. Minnesota Stevens */
#define PE_S_GRS_1980_ADJ_MN_SWIFT      107776 /* GRS 1980 Adj. Minnesota Swift */
#define PE_S_GRS_1980_ADJ_MN_TODD       107777 /* GRS 1980 Adj. Minnesota Todd */
#define PE_S_GRS_1980_ADJ_MN_TRAVERSE   107778 /* GRS 1980 Adj. Minnesota Traverse */
#define PE_S_GRS_1980_ADJ_MN_WABASHA    107779 /* GRS 1980 Adj. Minnesota Wabasha */
#define PE_S_GRS_1980_ADJ_MN_WADENA     107780 /* GRS 1980 Adj. Minnesota Wadena */
#define PE_S_GRS_1980_ADJ_MN_WASECA     107781 /* GRS 1980 Adj. Minnesota Waseca */
#define PE_S_GRS_1980_ADJ_MN_WATONWAN   107782 /* GRS 1980 Adj. Minnesota Watonwan */
#define PE_S_GRS_1980_ADJ_MN_WINONA     107783 /* GRS 1980 Adj. Minnesota Winona */
#define PE_S_GRS_1980_ADJ_MN_WRIGHT     107784 /* GRS 1980 Adj. Minnesota Wright */
#define PE_S_GRS_1980_ADJ_MN_YELLOW_MEDICINE 107785 /* GRS 1980 Adj. Minnesota */
                                                    /*  Yellow_Medicine        */

#define PE_S_GRS_1980_ADJ_WI_AL  107800 /* GRS 1980 Adj. Wisconsin Ashland    */
#define PE_S_GRS_1980_ADJ_WI_BA  107801 /* GRS 1980 Adj. Wisconsin Barron     */
#define PE_S_GRS_1980_ADJ_WI_BF  107802 /* GRS 1980 Adj. Wisconsin Bayfield   */
#define PE_S_GRS_1980_ADJ_WI_BR  107803 /* GRS 1980 Adj. Wisconsin Brown      */
#define PE_S_GRS_1980_ADJ_WI_BU  107804 /* GRS 1980 Adj. Wisconsin Buffalo    */
#define PE_S_GRS_1980_ADJ_WI_BN  107805 /* GRS 1980 Adj. Wisconsin Burnett    */
#define PE_S_GRS_1980_ADJ_WI_CP  107806 /* GRS 1980 Adj. Wisconsin Chippewa   */
#define PE_S_GRS_1980_ADJ_WI_CK  107807 /* GRS 1980 Adj. Wisconsin Clark      */
#define PE_S_GRS_1980_ADJ_WI_CO  107808 /* GRS 1980 Adj. Wisconsin Columbia   */
#define PE_S_GRS_1980_ADJ_WI_CR  107809 /* GRS 1980 Adj. Wisconsin Crawford   */
#define PE_S_GRS_1980_ADJ_WI_DN  107810 /* GRS 1980 Adj. Wisconsin Dane       */
#define PE_S_GRS_1980_ADJ_WI_DR  107811 /* GRS 1980 Adj. Wisconsin Door       */
#define PE_S_GRS_1980_ADJ_WI_DG  107812 /* GRS 1980 Adj. Wisconsin Douglas    */
#define PE_S_GRS_1980_ADJ_WI_DU  107813 /* GRS 1980 Adj. Wisconsin Dunn       */
#define PE_S_GRS_1980_ADJ_WI_EC  107814 /* GRS 1980 Adj. Wisconsin EauClaire  */
#define PE_S_GRS_1980_ADJ_WI_FN  107815 /* GRS 1980 Adj. Wisconsin Florence   */
#define PE_S_GRS_1980_ADJ_WI_FR  107816 /* GRS 1980 Adj. Wisconsin Forest     */
#define PE_S_GRS_1980_ADJ_WI_GT  107817 /* GRS 1980 Adj. Wisconsin Grant      */
#define PE_S_GRS_1980_ADJ_WI_IA  107818 /* GRS 1980 Adj. Wisconsin Iowa       */
#define PE_S_GRS_1980_ADJ_WI_IR  107819 /* GRS 1980 Adj. Wisconsin Iron       */
#define PE_S_GRS_1980_ADJ_WI_JA  107820 /* GRS 1980 Adj. Wisconsin Jackson    */
#define PE_S_GRS_1980_ADJ_WI_LC  107821 /* GRS 1980 Adj. Wisconsin LaCrosse   */
#define PE_S_GRS_1980_ADJ_WI_LG  107822 /* GRS 1980 Adj. Wisconsin Langlade   */
#define PE_S_GRS_1980_ADJ_WI_LN  107823 /* GRS 1980 Adj. Wisconsin Lincoln    */
#define PE_S_GRS_1980_ADJ_WI_MA  107824 /* GRS 1980 Adj. Wisconsin Marathon   */
#define PE_S_GRS_1980_ADJ_WI_MN  107825 /* GRS 1980 Adj. Wisconsin Marinette  */
#define PE_S_GRS_1980_ADJ_WI_ME  107826 /* GRS 1980 Adj. Wisconsin Menominee  */
#define PE_S_GRS_1980_ADJ_WI_MR  107827 /* GRS 1980 Adj. Wisconsin Monroe     */
#define PE_S_GRS_1980_ADJ_WI_OC  107828 /* GRS 1980 Adj. Wisconsin Oconto     */
#define PE_S_GRS_1980_ADJ_WI_ON  107829 /* GRS 1980 Adj. Wisconsin Oneida     */
#define PE_S_GRS_1980_ADJ_WI_PK  107830 /* GRS 1980 Adj. Wisconsin Polk       */
#define PE_S_GRS_1980_ADJ_WI_PT  107831 /* GRS 1980 Adj. Wisconsin Portage    */
#define PE_S_GRS_1980_ADJ_WI_PR  107832 /* GRS 1980 Adj. Wisconsin Price      */
#define PE_S_GRS_1980_ADJ_WI_RC  107833 /* GRS 1980 Adj. Wisconsin Richland   */
#define PE_S_GRS_1980_ADJ_WI_RK  107834 /* GRS 1980 Adj. Wisconsin Rock       */
#define PE_S_GRS_1980_ADJ_WI_RS  107835 /* GRS 1980 Adj. Wisconsin Rusk       */
#define PE_S_GRS_1980_ADJ_WI_SC  107836 /* GRS 1980 Adj. Wisconsin StCroix    */
#define PE_S_GRS_1980_ADJ_WI_SK  107837 /* GRS 1980 Adj. Wisconsin Sauk       */
#define PE_S_GRS_1980_ADJ_WI_SW  107838 /* GRS 1980 Adj. Wisconsin Sawyer     */
#define PE_S_GRS_1980_ADJ_WI_SH  107839 /* GRS 1980 Adj. Wisconsin Shawano    */
#define PE_S_GRS_1980_ADJ_WI_TA  107840 /* GRS 1980 Adj. Wisconsin Taylor     */
#define PE_S_GRS_1980_ADJ_WI_TR  107841 /* GRS 1980 Adj. Wisconsin Trempealeau*/
#define PE_S_GRS_1980_ADJ_WI_VR  107842 /* GRS 1980 Adj. Wisconsin Vernon     */
#define PE_S_GRS_1980_ADJ_WI_VI  107843 /* GRS 1980 Adj. Wisconsin Vilas      */
#define PE_S_GRS_1980_ADJ_WI_WW  107844 /* GRS 1980 Adj. Wisconsin Walworth   */
#define PE_S_GRS_1980_ADJ_WI_WB  107845 /* GRS 1980 Adj. Wisconsin Washburn   */
#define PE_S_GRS_1980_ADJ_WI_WA  107846 /* GRS 1980 Adj. Wisconsin Washington */
#define PE_S_GRS_1980_ADJ_WI_WK  107847 /* GRS 1980 Adj. Wisconsin Waukesha   */
#define PE_S_GRS_1980_ADJ_WI_WP  107848 /* GRS 1980 Adj. Wisconsin Waupaca    */
#define PE_S_GRS_1980_ADJ_WI_WS  107849 /* GRS 1980 Adj. Wisconsin Waushara   */
#define PE_S_GRS_1980_ADJ_WI_WD  107850 /* GRS 1980 Adj. Wisconsin Wood       */
#define PE_S_GRS_1980_ADJ_WI_AD_JN 107851 /* GRS 1980 Adj. Wisconsin Adams and Juneau */
#define PE_S_GRS_1980_ADJ_WI_GR_LF 107852 /* GRS 1980 Adj. Wisconsin Green and Lafayette */
#define PE_S_GRS_1980_ADJ_WI_GL_MQ 107853 /* GRS 1980 Adj. Wisconsin Green Lake and Marquette */
#define PE_S_GRS_1980_ADJ_WI_DD_JF 107854 /* GRS 1980 Adj. Wisconsin Dodge and Jefferson */
#define PE_S_GRS_1980_ADJ_WI_PP_PC 107855 /* GRS 1980 Adj. Wisconsin Pepin and Pierce */
#define PE_S_GRS_1980_ADJ_WI_CL_FL_OG_WN 107856 /* GRS 1980 Adj. Wisconsin    */
                            /* Calumet, Fond du Lac, Outagamie, and Winnebago */
#define PE_S_GRS_1980_ADJ_WI_KN_MW_OZ_RA 107857 /* GRS 1980 Adj. Wisconsin    */
                                   /* Kenosha, Milwaukee, Ozaukee, and Racine */
#define PE_S_GRS_1980_ADJ_WI_KW_MT_SG    107858 /* GRS 1980 Adj. Wisconsin    */
                                        /* Kewaunee, Manitowoc, and Sheboygan */

#define PE_S_XT_MERCURY_2000    107900 /* Mercury             */
#define PE_S_XT_VENUS_1985      107901 /* Venus 1985          */
#define PE_S_XT_VENUS_2000      107902 /* Venus 2000          */
#define PE_S_XT_MOON_2000       107903 /* The Moon            */
#define PE_S_XT_MARS_1979       107904 /* Mars 1979           */
#define PE_S_XT_MARS_2000       107905 /* Mars 2000           */
#define PE_S_XT_DEIMOS_2000     107906 /* Mars - Deimos       */
#define PE_S_XT_PHOBOS_2000     107907 /* Mars - Phobos       */
#define PE_S_XT_JUPITER_2000    107908 /* Jupiter             */
#define PE_S_XT_ADRASTEA_2000   107909 /* Jupiter - Adrastea  */
#define PE_S_XT_AMALTHEA_2000   107910 /* Jupiter - Amalthea  */
#define PE_S_XT_ANANKE_2000     107911 /* Jupiter - Ananke    */
#define PE_S_XT_CALLISTO_2000   107912 /* Jupiter - Callisto  */
#define PE_S_XT_CARME_2000      107913 /* Jupiter - Carme     */
#define PE_S_XT_ELARA_2000      107914 /* Jupiter - Elara     */
#define PE_S_XT_EUROPA_2000     107915 /* Jupiter - Europa    */
#define PE_S_XT_GANYMEDE_2000   107916 /* Jupiter - Ganymede  */
#define PE_S_XT_HIMALIA_2000    107917 /* Jupiter - Himalia   */
#define PE_S_XT_IO_2000         107918 /* Jupiter - Io        */
#define PE_S_XT_LEDA_2000       107919 /* Jupiter - Leda      */
#define PE_S_XT_LYSITHEA_2000   107920 /* Jupiter - Lysithea  */
#define PE_S_XT_METIS_2000      107921 /* Jupiter - Metis     */
#define PE_S_XT_PASIPHAE_2000   107922 /* Jupiter - Pasiphae  */
#define PE_S_XT_SINOPE_2000     107923 /* Jupiter - Sinope    */
#define PE_S_XT_THEBE_2000      107924 /* Jupiter - Thebe     */
#define PE_S_XT_SATURN_2000     107925 /* Saturn              */
#define PE_S_XT_ATLAS_2000      107926 /* Saturn - Atlas      */
#define PE_S_XT_CALYPSO_2000    107927 /* Saturn - Calypso    */
#define PE_S_XT_DIONE_2000      107928 /* Saturn - Dione      */
#define PE_S_XT_ENCELADUS_2000  107929 /* Saturn - Enceladus  */
#define PE_S_XT_EPIMETHEUS_2000 107930 /* Saturn - Epimetheus */
#define PE_S_XT_HELENE_2000     107931 /* Saturn - Helene     */
#define PE_S_XT_HYPERION_2000   107932 /* Saturn - Hyperion   */
#define PE_S_XT_IAPETUS_2000    107933 /* Saturn - Iapetus    */
#define PE_S_XT_JANUS_2000      107934 /* Saturn - Janus      */
#define PE_S_XT_MIMAS_2000      107935 /* Saturn - Mimas      */
#define PE_S_XT_PAN_2000        107936 /* Saturn - Pan        */
#define PE_S_XT_PANDORA_2000    107937 /* Saturn - Pandora    */
#define PE_S_XT_PHOEBE_2000     107938 /* Saturn - Phoebe     */
#define PE_S_XT_PROMETHEUS_2000 107939 /* Saturn - Prometheus */
#define PE_S_XT_RHEA_2000       107940 /* Saturn - Rhea       */
#define PE_S_XT_TELESTO_2000    107941 /* Saturn - Telesto    */
#define PE_S_XT_TETHYS_2000     107942 /* Saturn - Tethys     */
#define PE_S_XT_TITAN_2000      107943 /* Saturn - Titan      */
#define PE_S_XT_URANUS_2000     107944 /* Uranus              */
#define PE_S_XT_ARIEL_2000      107945 /* Uranus - Ariel      */
#define PE_S_XT_BELINDA_2000    107946 /* Uranus - Belinda    */
#define PE_S_XT_BIANCA_2000     107947 /* Uranus - Bianca     */
#define PE_S_XT_CORDELIA_2000   107948 /* Uranus - Cordelia   */
#define PE_S_XT_CRESSIDA_2000   107949 /* Uranus - Cressida   */
#define PE_S_XT_DESDEMONA_2000  107950 /* Uranus - Desdemona  */
#define PE_S_XT_JULIET_2000     107951 /* Uranus - Juliet     */
#define PE_S_XT_MIRANDA_2000    107952 /* Uranus - Miranda    */
#define PE_S_XT_OBERON_2000     107953 /* Uranus - Oberon     */
#define PE_S_XT_OPHELIA_2000    107954 /* Uranus - Ophelia    */
#define PE_S_XT_PORTIA_2000     107955 /* Uranus - Portia     */
#define PE_S_XT_PUCK_2000       107956 /* Uranus - Puck       */
#define PE_S_XT_ROSALIND_2000   107957 /* Uranus - Rosalind   */
#define PE_S_XT_TITANIA_2000    107958 /* Uranus - Titania    */
#define PE_S_XT_UMBRIEL_2000    107959 /* Uranus - Umbriel    */
#define PE_S_XT_NEPTUNE_2000    107960 /* Neptune             */
#define PE_S_XT_DESPINA_2000    107961 /* Neptune - Despina   */
#define PE_S_XT_GALATEA_2000    107962 /* Neptune - Galatea   */
#define PE_S_XT_LARISSA_2000    107963 /* Neptune - Larissa   */
#define PE_S_XT_NAIAD_2000      107964 /* Neptune - Naiad     */
#define PE_S_XT_NEREID_2000     107965 /* Neptune - Nereid    */
#define PE_S_XT_PROTEUS_2000    107966 /* Neptune - Proteus   */
#define PE_S_XT_THALASSA_2000   107967 /* Neptune - Thalassa  */
#define PE_S_XT_TRITON_2000     107968 /* Neptune - Triton    */
#define PE_S_XT_PLUTO_2000      107969 /* Pluto               */
#define PE_S_XT_CHARON_2000     107970 /* Pluto - Charon      */

/*----------------------------------------------------------------------------*/
/*                     H O R I Z O N T A L   D A T U M S                      */
/*----------------------------------------------------------------------------*/

/* NEW DATUMs at 9.0 ----------------------- */

#define PE_D_ALBANIAN_1987       6191 /* Albanian 1987                        */
#define PE_D_AMMASSALIK_1958     6196 /* Ammassalik 1958                      */
#define PE_D_AUSTRALIAN_ANTARCTIC_1998  6176 /* Autralian Antarctic 1998      */
#define PE_D_AZORES_CENTRAL_ISLANDS_1948   6183 /* Azores Central Islands 1948*/
#define PE_D_AZORES_CENTRAL_ISLANDS_1995   6665 /* Azores Central Islands 1995*/
#define PE_D_AZORES_OCCIDENTAL_ISLANDS_1939  6182 /* Azores Occidental Isls 1939 */
#define PE_D_AZORES_ORIENTAL_ISLANDS_1940  6184 /* Azores Oriental Isls 1940  */
#define PE_D_AZORES_ORIENTAL_ISLANDS_1995  6664 /* Azores Oriental Isls 1995  */
#define PE_D_COMBANI_1950        6632 /* Combani 1950                         */
#define PE_D_CSG_1967            6623 /* Centre Spatial Guyanais 1967         */
#define PE_D_DOUALA_1948         6192 /* Douala 1948                          */
#define PE_D_EGYPT_1930          6199 /* Egypt 1930                           */
#define PE_D_ESTONIA_1997        6180 /* Estonia 1997                         */
#define PE_D_FORT_DESAIX         6625 /* Fort Desaix                          */
#define PE_D_FORT_MARIGOT        6621 /* Fort Marigot                         */
#define PE_D_GRAND_COMOROS       6646 /* Grand Comoros                        */
#define PE_D_HELLE_1954          6660 /* Helle 1954                           */
#define PE_D_IGM_1995            6670 /* IGM 1995                             */
#define PE_D_IGN53_MARE          6641 /* IGN53 Mare                           */
#define PE_D_IGN56_LIFOU         6633 /* IGN56 Lifou                          */
#define PE_D_IGN72_GRANDE_TERRE  6634 /* IGN72 Grande Terre                   */
#define PE_D_IGN72_NUKU_HIVA     6630 /* IGN72 Nuku Hiva                      */
#define PE_D_IRAQ_KUWAIT_BOUNDARY_1992  6667 /*Iraq-Kuwait Boundary Datum 1992*/
#define PE_D_ISLANDS_NETWORK_1993 6659 /* Islands Network 1993                */
#define PE_D_ITRF_1988           6647 /* IERS Terrestrial Reference Frame 1988*/
#define PE_D_ITRF_1989           6648 /* IERS Terrestrial Reference Frame 1989*/
#define PE_D_ITRF_1990           6649 /* IERS Terrestrial Reference Frame 1990*/
#define PE_D_ITRF_1991           6650 /* IERS Terrestrial Reference Frame 1991*/
#define PE_D_ITRF_1992           6651 /* IERS Terrestrial Reference Frame 1992*/
#define PE_D_ITRF_1993           6652 /* IERS Terrestrial Reference Frame 1993*/
#define PE_D_ITRF_1994           6653 /* IERS Terrestrial Reference Frame 1994*/
#define PE_D_ITRF_1996           6654 /* IERS Terrestrial Reference Frame 1996*/
#define PE_D_ITRF_1997           6655 /* IERS Terrestrial Reference Frame 1997*/
#define PE_D_ITRF_2000           6656 /* IERS Terrestrial Reference Frame 2000*/
#define PE_D_K0_1949             6631 /* K0 1949                              */
#define PE_D_KOUSSERI            6198 /* Kousseri                             */
#define PE_D_LATVIA_1992         6661 /* Latvia 1992                          */
#define PE_D_LISBON_1890         6666 /* Lisbon 1890                          */
#define PE_D_LUXEMBOURG_1930     6181 /* Luxembourg 1930                      */
#define PE_D_MADEIRA_1936        6185 /* Madeira 1936                         */
#define PE_D_MANOCA_1962         6193 /* Manoca 1962                          */
#define PE_D_MOP78               6639 /* MOP78                                */
#define PE_D_NEA74_NOUMEA        6644 /* NEA74 Noumea                         */
#define PE_D_OSNI_1952           6188 /* OSNI 1952                            */
#define PE_D_PETRELS_1972        6636 /* Petrels 1972                         */
#define PE_D_PITON_DES_NEIGES    6626 /* Piton des Neiges                     */
#define PE_D_POINTE_GEOLOGIE_PERROUD_1950   6637 /* Pointe Geologie Perroud 1950 */
#define PE_D_PORTO_SANTO_1995    6663 /* Porto Santo 1995                     */
#define PE_D_POSGAR_1998         6190 /* POSGAR 1998                          */
#define PE_D_PULKOVO_1942_ADJ_1958  6179 /* Pulkovo 1942/58                   */
#define PE_D_PULKOVO_1942_ADJ_1983  6178 /* Pulkovo 1942/83                   */
#define PE_D_QND_1995            6614 /* Qatar National Datum 1995            */
#define PE_D_QORNOQ_1927         6194 /* Qornoq 1927                          */
#define PE_D_REYKJAVIK_1900      6657 /* Reykjavik 1900                       */
#define PE_D_RGFG_1995           6624 /* Reseau Geodesique Francais Guyane 1995 */
#define PE_D_RGNC_1991           6645 /* Reseau Geodesique Nouvelle Caledonie 1991 */
#define PE_D_RGR_1992            6627 /* Reseau Geodesique de la Reunion 1992 */
#define PE_D_RRAF_1991           6640 /* Reseau de Reference des Antilles Francaises 1991 */
#define PE_D_SAINTE_ANNE         6622 /* Sainte Anne                          */
#define PE_D_SAINT_PIERRE_ET_MIQUELON_1950  6638 /* Saint Pierre et Miquelon 1950 */
#define PE_D_SCORESBYSUND_1952   6195 /* Scoresbysund 1952                    */
#define PE_D_ST71_BELEP          6643 /* ST71 Belep                           */
#define PE_D_ST84_ILE_DES_PINS   6642 /* ST84 Ile des Pins                    */
#define PE_D_ST87_OUVEA          6635 /* ST87 Ouvea                           */
#define PE_D_SWEREF99            6619 /* SWEREF99                             */
#define PE_D_TAHAA               6629 /* Tahaa                                */
#define PE_D_TAHITI              6628 /* Tahiti                               */
#define PE_D_XIAN_1980           6610 /* Xian 1980                            */

#define PE_D_BERMUDA_2000          106271 /* Bermuda 2000                     */
#define PE_D_CHATHAM_ISLANDS_1979  106273 /* Chatham Islands 1979             */
#define PE_D_OBSERV_METEOR_1965    106274 /* Observatorio Meteorologico 1965  */
#define PE_D_ROMA_1940             106275 /* Roma 1940                        */
#define PE_D_SPHERE_EMEP           106276 /* EMEP                             */
#define PE_D_JORDAN                106277 /* Jordan                           */

#define PE_D_NAD_1983_HARN_ADJ_MN_ANOKA      106700 /* NAD 1983 HARN Adj. Minnesota Anoka */
#define PE_D_NAD_1983_HARN_ADJ_MN_BECKER     106701 /* NAD 1983 HARN Adj. Minnesota Becker */
#define PE_D_NAD_1983_HARN_ADJ_MN_BELTRAMI_N 106702 /* NAD 1983 HARN Adj. Minnesota Beltrami_North */
#define PE_D_NAD_1983_HARN_ADJ_MN_BELTRAMI_S 106703 /* NAD 1983 HARN Adj. Minnesota Beltrami_South */
#define PE_D_NAD_1983_HARN_ADJ_MN_BENTON     106704 /* NAD 1983 HARN Adj. Minnesota Benton */
#define PE_D_NAD_1983_HARN_ADJ_MN_BIG_STONE  106705 /* NAD 1983 HARN Adj. Minnesota Big_Stone */
#define PE_D_NAD_1983_HARN_ADJ_MN_BLUE_EARTH 106706 /* NAD 1983 HARN Adj. Minnesota Blue_Earth */
#define PE_D_NAD_1983_HARN_ADJ_MN_BROWN      106707 /* NAD 1983 HARN Adj. Minnesota Brown */
#define PE_D_NAD_1983_HARN_ADJ_MN_CARLTON    106708 /* NAD 1983 HARN Adj. Minnesota Carlton */
#define PE_D_NAD_1983_HARN_ADJ_MN_CARVER     106709 /* NAD 1983 HARN Adj. Minnesota Carver */
#define PE_D_NAD_1983_HARN_ADJ_MN_CASS_N     106710 /* NAD 1983 HARN Adj. Minnesota Cass_North */
#define PE_D_NAD_1983_HARN_ADJ_MN_CASS_S     106711 /* NAD 1983 HARN Adj. Minnesota Cass_South */
#define PE_D_NAD_1983_HARN_ADJ_MN_CHIPPEWA   106712 /* NAD 1983 HARN Adj. Minnesota Chippewa */
#define PE_D_NAD_1983_HARN_ADJ_MN_CHISAGO    106713 /* NAD 1983 HARN Adj. Minnesota Chisago */
#define PE_D_NAD_1983_HARN_ADJ_MN_COOK_N     106714 /* NAD 1983 HARN Adj. Minnesota Cook_North */
#define PE_D_NAD_1983_HARN_ADJ_MN_COOK_S     106715 /* NAD 1983 HARN Adj. Minnesota Cook_South */
#define PE_D_NAD_1983_HARN_ADJ_MN_COTTONWOOD 106716 /* NAD 1983 HARN Adj. Minnesota Cottonwood */
#define PE_D_NAD_1983_HARN_ADJ_MN_CROW_WING  106717 /* NAD 1983 HARN Adj. Minnesota Crow_Wing */
#define PE_D_NAD_1983_HARN_ADJ_MN_DAKOTA     106718 /* NAD 1983 HARN Adj. Minnesota Dakota */
#define PE_D_NAD_1983_HARN_ADJ_MN_DODGE      106719 /* NAD 1983 HARN Adj. Minnesota Dodge */
#define PE_D_NAD_1983_HARN_ADJ_MN_DOUGLAS    106720 /* NAD 1983 HARN Adj. Minnesota Douglas */
#define PE_D_NAD_1983_HARN_ADJ_MN_FARIBAULT  106721 /* NAD 1983 HARN Adj. Minnesota Faribault */
#define PE_D_NAD_1983_HARN_ADJ_MN_FILLMORE   106722 /* NAD 1983 HARN Adj. Minnesota Fillmore */
#define PE_D_NAD_1983_HARN_ADJ_MN_FREEBORN   106723 /* NAD 1983 HARN Adj. Minnesota Freeborn */
#define PE_D_NAD_1983_HARN_ADJ_MN_GOODHUE    106724 /* NAD 1983 HARN Adj. Minnesota Goodhue */
#define PE_D_NAD_1983_HARN_ADJ_MN_GRANT      106725 /* NAD 1983 HARN Adj. Minnesota Grant */
#define PE_D_NAD_1983_HARN_ADJ_MN_HENNEPIN   106726 /* NAD 1983 HARN Adj. Minnesota Hennepin */
#define PE_D_NAD_1983_HARN_ADJ_MN_HOUSTON    106727 /* NAD 1983 HARN Adj. Minnesota Houston */
#define PE_D_NAD_1983_HARN_ADJ_MN_ISANTI     106728 /* NAD 1983 HARN Adj. Minnesota Isanti */
#define PE_D_NAD_1983_HARN_ADJ_MN_ITASCA_N   106729 /* NAD 1983 HARN Adj. Minnesota Itasca_North */
#define PE_D_NAD_1983_HARN_ADJ_MN_ITASCA_S   106730 /* NAD 1983 HARN Adj. Minnesota Itasca_South */
#define PE_D_NAD_1983_HARN_ADJ_MN_JACKSON    106731 /* NAD 1983 HARN Adj. Minnesota Jackson */
#define PE_D_NAD_1983_HARN_ADJ_MN_KANABEC    106732 /* NAD 1983 HARN Adj. Minnesota Kanabec */
#define PE_D_NAD_1983_HARN_ADJ_MN_KANDIYOHI  106733 /* NAD 1983 HARN Adj. Minnesota Kandiyohi */
#define PE_D_NAD_1983_HARN_ADJ_MN_KITTSON    106734 /* NAD 1983 HARN Adj. Minnesota Kittson */
#define PE_D_NAD_1983_HARN_ADJ_MN_KOOCHICHING   106735 /* NAD 1983 HARN Adj. Minnesota Koochiching */
#define PE_D_NAD_1983_HARN_ADJ_MN_LAC_QUI_PARLE 106736 /* NAD 1983 HARN Adj. Minnesota Lac_Qui_Parle */
#define PE_D_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_N 106737 /* NAD 1983 HARN Adj. Minnesota */
                                                             /* Lake_of_the_Woods_North      */
#define PE_D_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_S 106738 /* NAD 1983 HARN Adj. Minnesota */
                                                             /* Lake_of_the_Woods_South      */
#define PE_D_NAD_1983_HARN_ADJ_MN_LE_SUEUR   106739 /* NAD 1983 HARN Adj. Minnesota Le_Sueur */
#define PE_D_NAD_1983_HARN_ADJ_MN_LINCOLN    106740 /* NAD 1983 HARN Adj. Minnesota Lincoln */
#define PE_D_NAD_1983_HARN_ADJ_MN_LYON       106741 /* NAD 1983 HARN Adj. Minnesota Lyon */
#define PE_D_NAD_1983_HARN_ADJ_MN_MCLEOD     106742 /* NAD 1983 HARN Adj. Minnesota McLeod */
#define PE_D_NAD_1983_HARN_ADJ_MN_MAHNOMEN   106743 /* NAD 1983 HARN Adj. Minnesota Mahnomen */
#define PE_D_NAD_1983_HARN_ADJ_MN_MARSHALL   106744 /* NAD 1983 HARN Adj. Minnesota Marshall */
#define PE_D_NAD_1983_HARN_ADJ_MN_MARTIN     106745 /* NAD 1983 HARN Adj. Minnesota Martin */
#define PE_D_NAD_1983_HARN_ADJ_MN_MEEKER     106746 /* NAD 1983 HARN Adj. Minnesota Meeker */
#define PE_D_NAD_1983_HARN_ADJ_MN_MORRISON   106747 /* NAD 1983 HARN Adj. Minnesota Morrison */
#define PE_D_NAD_1983_HARN_ADJ_MN_MOWER      106748 /* NAD 1983 HARN Adj. Minnesota Mower */
#define PE_D_NAD_1983_HARN_ADJ_MN_MURRAY     106749 /* NAD 1983 HARN Adj. Minnesota Murray */
#define PE_D_NAD_1983_HARN_ADJ_MN_NICOLLET   106750 /* NAD 1983 HARN Adj. Minnesota Nicollet */
#define PE_D_NAD_1983_HARN_ADJ_MN_NOBLES     106751 /* NAD 1983 HARN Adj. Minnesota Nobles */
#define PE_D_NAD_1983_HARN_ADJ_MN_NORMAN     106752 /* NAD 1983 HARN Adj. Minnesota Norman */
#define PE_D_NAD_1983_HARN_ADJ_MN_OLMSTED    106753 /* NAD 1983 HARN Adj. Minnesota Olmsted */
#define PE_D_NAD_1983_HARN_ADJ_MN_OTTERTAIL  106754 /* NAD 1983 HARN Adj. Minnesota Ottertail */
#define PE_D_NAD_1983_HARN_ADJ_MN_PENNINGTON 106755 /* NAD 1983 HARN Adj. Minnesota Pennington */
#define PE_D_NAD_1983_HARN_ADJ_MN_PINE       106756 /* NAD 1983 HARN Adj. Minnesota Pine */
#define PE_D_NAD_1983_HARN_ADJ_MN_PIPESTONE  106757 /* NAD 1983 HARN Adj. Minnesota Pipestone */
#define PE_D_NAD_1983_HARN_ADJ_MN_POLK       106758 /* NAD 1983 HARN Adj. Minnesota Polk */
#define PE_D_NAD_1983_HARN_ADJ_MN_POPE       106759 /* NAD 1983 HARN Adj. Minnesota Pope */
#define PE_D_NAD_1983_HARN_ADJ_MN_RAMSEY     106760 /* NAD 1983 HARN Adj. Minnesota Ramsey */
#define PE_D_NAD_1983_HARN_ADJ_MN_RED_LAKE   106761 /* NAD 1983 HARN Adj. Minnesota Red_Lake */
#define PE_D_NAD_1983_HARN_ADJ_MN_REDWOOD    106762 /* NAD 1983 HARN Adj. Minnesota Redwood */
#define PE_D_NAD_1983_HARN_ADJ_MN_RENVILLE   106763 /* NAD 1983 HARN Adj. Minnesota Renville */
#define PE_D_NAD_1983_HARN_ADJ_MN_RICE       106764 /* NAD 1983 HARN Adj. Minnesota Rice */
#define PE_D_NAD_1983_HARN_ADJ_MN_ROCK       106765 /* NAD 1983 HARN Adj. Minnesota Rock */
#define PE_D_NAD_1983_HARN_ADJ_MN_ROSEAU     106766 /* NAD 1983 HARN Adj. Minnesota Roseau */
#define PE_D_NAD_1983_HARN_ADJ_MN_ST_LOUIS_N 106767 /* NAD 1983 HARN Adj. Minnesota St_Louis_North */
#define PE_D_NAD_1983_HARN_ADJ_MN_ST_LOUIS_C 106768 /* NAD 1983 HARN Adj. Minnesota St_Louis_Central */
#define PE_D_NAD_1983_HARN_ADJ_MN_ST_LOUIS_S 106769 /* NAD 1983 HARN Adj. Minnesota St_Louis_South */
#define PE_D_NAD_1983_HARN_ADJ_MN_SCOTT      106770 /* NAD 1983 HARN Adj. Minnesota Scott */
#define PE_D_NAD_1983_HARN_ADJ_MN_SHERBURNE  106771 /* NAD 1983 HARN Adj. Minnesota Sherburne */
#define PE_D_NAD_1983_HARN_ADJ_MN_SIBLEY     106772 /* NAD 1983 HARN Adj. Minnesota Sibley */
#define PE_D_NAD_1983_HARN_ADJ_MN_STEARNS    106773 /* NAD 1983 HARN Adj. Minnesota Stearns */
#define PE_D_NAD_1983_HARN_ADJ_MN_STEELE     106774 /* NAD 1983 HARN Adj. Minnesota Steele */
#define PE_D_NAD_1983_HARN_ADJ_MN_STEVENS    106775 /* NAD 1983 HARN Adj. Minnesota Stevens */
#define PE_D_NAD_1983_HARN_ADJ_MN_SWIFT      106776 /* NAD 1983 HARN Adj. Minnesota Swift */
#define PE_D_NAD_1983_HARN_ADJ_MN_TODD       106777 /* NAD 1983 HARN Adj. Minnesota Todd */
#define PE_D_NAD_1983_HARN_ADJ_MN_TRAVERSE   106778 /* NAD 1983 HARN Adj. Minnesota Traverse */
#define PE_D_NAD_1983_HARN_ADJ_MN_WABASHA    106779 /* NAD 1983 HARN Adj. Minnesota Wabasha */
#define PE_D_NAD_1983_HARN_ADJ_MN_WADENA     106780 /* NAD 1983 HARN Adj. Minnesota Wadena */
#define PE_D_NAD_1983_HARN_ADJ_MN_WASECA     106781 /* NAD 1983 HARN Adj. Minnesota Waseca */
#define PE_D_NAD_1983_HARN_ADJ_MN_WATONWAN   106782 /* NAD 1983 HARN Adj. Minnesota Watonwan */
#define PE_D_NAD_1983_HARN_ADJ_MN_WINONA     106783 /* NAD 1983 HARN Adj. Minnesota Winona */
#define PE_D_NAD_1983_HARN_ADJ_MN_WRIGHT     106784 /* NAD 1983 HARN Adj. Minnesota Wright */
#define PE_D_NAD_1983_HARN_ADJ_MN_YELLOW_MEDICINE 106785 /* NAD 1983 HARN Adj. Minnesota */
                                                         /* Yellow_Medicine              */

#define PE_D_NAD_1983_HARN_ADJ_WI_AL  106800 /* NAD 1983 HARN Adj. Wisconsin Ashland */
#define PE_D_NAD_1983_HARN_ADJ_WI_BA  106801 /* NAD 1983 HARN Adj. Wisconsin Barron */
#define PE_D_NAD_1983_HARN_ADJ_WI_BF  106802 /* NAD 1983 HARN Adj. Wisconsin Bayfield */
#define PE_D_NAD_1983_HARN_ADJ_WI_BR  106803 /* NAD 1983 HARN Adj. Wisconsin Brown */
#define PE_D_NAD_1983_HARN_ADJ_WI_BU  106804 /* NAD 1983 HARN Adj. Wisconsin Buffalo */
#define PE_D_NAD_1983_HARN_ADJ_WI_BN  106805 /* NAD 1983 HARN Adj. Wisconsin Burnett */
#define PE_D_NAD_1983_HARN_ADJ_WI_CP  106806 /* NAD 1983 HARN Adj. Wisconsin Chippewa */
#define PE_D_NAD_1983_HARN_ADJ_WI_CK  106807 /* NAD 1983 HARN Adj. Wisconsin Clark */
#define PE_D_NAD_1983_HARN_ADJ_WI_CO  106808 /* NAD 1983 HARN Adj. Wisconsin Columbia */
#define PE_D_NAD_1983_HARN_ADJ_WI_CR  106809 /* NAD 1983 HARN Adj. Wisconsin Crawford */
#define PE_D_NAD_1983_HARN_ADJ_WI_DN  106810 /* NAD 1983 HARN Adj. Wisconsin Dane */
#define PE_D_NAD_1983_HARN_ADJ_WI_DR  106811 /* NAD 1983 HARN Adj. Wisconsin Door */
#define PE_D_NAD_1983_HARN_ADJ_WI_DG  106812 /* NAD 1983 HARN Adj. Wisconsin Douglas */
#define PE_D_NAD_1983_HARN_ADJ_WI_DU  106813 /* NAD 1983 HARN Adj. Wisconsin Dunn */
#define PE_D_NAD_1983_HARN_ADJ_WI_EC  106814 /* NAD 1983 HARN Adj. Wisconsin EauClaire */
#define PE_D_NAD_1983_HARN_ADJ_WI_FN  106815 /* NAD 1983 HARN Adj. Wisconsin Florence */
#define PE_D_NAD_1983_HARN_ADJ_WI_FR  106816 /* NAD 1983 HARN Adj. Wisconsin Forest */
#define PE_D_NAD_1983_HARN_ADJ_WI_GT  106817 /* NAD 1983 HARN Adj. Wisconsin Grant */
#define PE_D_NAD_1983_HARN_ADJ_WI_IA  106818 /* NAD 1983 HARN Adj. Wisconsin Iowa */
#define PE_D_NAD_1983_HARN_ADJ_WI_IR  106819 /* NAD 1983 HARN Adj. Wisconsin Iron */
#define PE_D_NAD_1983_HARN_ADJ_WI_JA  106820 /* NAD 1983 HARN Adj. Wisconsin Jackson */
#define PE_D_NAD_1983_HARN_ADJ_WI_LC  106821 /* NAD 1983 HARN Adj. Wisconsin LaCrosse */
#define PE_D_NAD_1983_HARN_ADJ_WI_LG  106822 /* NAD 1983 HARN Adj. Wisconsin Langlade */
#define PE_D_NAD_1983_HARN_ADJ_WI_LN  106823 /* NAD 1983 HARN Adj. Wisconsin Lincoln */
#define PE_D_NAD_1983_HARN_ADJ_WI_MA  106824 /* NAD 1983 HARN Adj. Wisconsin Marathon */
#define PE_D_NAD_1983_HARN_ADJ_WI_MN  106825 /* NAD 1983 HARN Adj. Wisconsin Marinette */
#define PE_D_NAD_1983_HARN_ADJ_WI_ME  106826 /* NAD 1983 HARN Adj. Wisconsin Menominee */
#define PE_D_NAD_1983_HARN_ADJ_WI_MR  106827 /* NAD 1983 HARN Adj. Wisconsin Monroe */
#define PE_D_NAD_1983_HARN_ADJ_WI_OC  106828 /* NAD 1983 HARN Adj. Wisconsin Oconto */
#define PE_D_NAD_1983_HARN_ADJ_WI_ON  106829 /* NAD 1983 HARN Adj. Wisconsin Oneida */
#define PE_D_NAD_1983_HARN_ADJ_WI_PK  106830 /* NAD 1983 HARN Adj. Wisconsin Polk */
#define PE_D_NAD_1983_HARN_ADJ_WI_PT  106831 /* NAD 1983 HARN Adj. Wisconsin Portage */
#define PE_D_NAD_1983_HARN_ADJ_WI_PR  106832 /* NAD 1983 HARN Adj. Wisconsin Price */
#define PE_D_NAD_1983_HARN_ADJ_WI_RC  106833 /* NAD 1983 HARN Adj. Wisconsin Richland */
#define PE_D_NAD_1983_HARN_ADJ_WI_RK  106834 /* NAD 1983 HARN Adj. Wisconsin Rock */
#define PE_D_NAD_1983_HARN_ADJ_WI_RS  106835 /* NAD 1983 HARN Adj. Wisconsin Rusk */
#define PE_D_NAD_1983_HARN_ADJ_WI_SC  106836 /* NAD 1983 HARN Adj. Wisconsin StCroix */
#define PE_D_NAD_1983_HARN_ADJ_WI_SK  106837 /* NAD 1983 HARN Adj. Wisconsin Sauk */
#define PE_D_NAD_1983_HARN_ADJ_WI_SW  106838 /* NAD 1983 HARN Adj. Wisconsin Sawyer */
#define PE_D_NAD_1983_HARN_ADJ_WI_SH  106839 /* NAD 1983 HARN Adj. Wisconsin Shawano */
#define PE_D_NAD_1983_HARN_ADJ_WI_TA  106840 /* NAD 1983 HARN Adj. Wisconsin Taylor */
#define PE_D_NAD_1983_HARN_ADJ_WI_TR  106841 /* NAD 1983 HARN Adj. Wisconsin Trempealeau */
#define PE_D_NAD_1983_HARN_ADJ_WI_VR  106842 /* NAD 1983 HARN Adj. Wisconsin Vernon */
#define PE_D_NAD_1983_HARN_ADJ_WI_VI  106843 /* NAD 1983 HARN Adj. Wisconsin Vilas */
#define PE_D_NAD_1983_HARN_ADJ_WI_WW  106844 /* NAD 1983 HARN Adj. Wisconsin Walworth */
#define PE_D_NAD_1983_HARN_ADJ_WI_WB  106845 /* NAD 1983 HARN Adj. Wisconsin Washburn */
#define PE_D_NAD_1983_HARN_ADJ_WI_WA  106846 /* NAD 1983 HARN Adj. Wisconsin Washington */
#define PE_D_NAD_1983_HARN_ADJ_WI_WK  106847 /* NAD 1983 HARN Adj. Wisconsin Waukesha */
#define PE_D_NAD_1983_HARN_ADJ_WI_WP  106848 /* NAD 1983 HARN Adj. Wisconsin Waupaca */
#define PE_D_NAD_1983_HARN_ADJ_WI_WS  106849 /* NAD 1983 HARN Adj. Wisconsin Waushara */
#define PE_D_NAD_1983_HARN_ADJ_WI_WD  106850 /* NAD 1983 HARN Adj. Wisconsin Wood */
#define PE_D_NAD_1983_HARN_ADJ_WI_AD_JN 106851 /* NAD 1983 HARN Adj. Wisconsin Adams and Juneau */
#define PE_D_NAD_1983_HARN_ADJ_WI_GR_LF 106852 /* NAD 1983 HARN Adj. Wisconsin Green and Lafayette */
#define PE_D_NAD_1983_HARN_ADJ_WI_GL_MQ 106853 /* NAD 1983 HARN Adj. Wisconsin Green Lake and Marquette */
#define PE_D_NAD_1983_HARN_ADJ_WI_DD_JF 106854 /* NAD 1983 HARN Adj. Wisconsin Dodge and Jefferson */
#define PE_D_NAD_1983_HARN_ADJ_WI_PP_PC 106855 /* NAD 1983 HARN Adj. Wisconsin Pepin and Pierce */
#define PE_D_NAD_1983_HARN_ADJ_WI_CL_FL_OG_WN 106856 /* NAD 1983 HARN Adj. Wisconsin */
                                   /* Calumet, Fond du Lac, Outagamie, and Winnebago */
#define PE_D_NAD_1983_HARN_ADJ_WI_KN_MW_OZ_RA 106857 /* NAD 1983 HARN Adj. Wisconsin */
                                          /* Kenosha, Milwaukee, Ozaukee, and Racine */
#define PE_D_NAD_1983_HARN_ADJ_WI_KW_MT_SG    106858 /* NAD 1983 HARN Adj. Wisconsin */
                                               /* Kewaunee, Manitowoc, and Sheboygan */

#define PE_D_XT_MERCURY_2000       106900 /* Mercury             */
#define PE_D_XT_VENUS_1985         106901 /* Venus 1985          */
#define PE_D_XT_VENUS_2000         106902 /* Venus 2000          */
#define PE_D_XT_MOON_2000          106903 /* The Moon            */
#define PE_D_XT_MARS_1979          106904 /* Mars 1979           */
#define PE_D_XT_MARS_2000          106905 /* Mars 2000           */
#define PE_D_XT_DEIMOS_2000        106906 /* Mars - Deimos       */
#define PE_D_XT_PHOBOS_2000        106907 /* Mars - Phobos       */
#define PE_D_XT_JUPITER_2000       106908 /* Jupiter             */
#define PE_D_XT_ADRASTEA_2000      106909 /* Jupiter - Adrastea  */
#define PE_D_XT_AMALTHEA_2000      106910 /* Jupiter - Amalthea  */
#define PE_D_XT_ANANKE_2000        106911 /* Jupiter - Ananke    */
#define PE_D_XT_CALLISTO_2000      106912 /* Jupiter - Callisto  */
#define PE_D_XT_CARME_2000         106913 /* Jupiter - Carme     */
#define PE_D_XT_ELARA_2000         106914 /* Jupiter - Elara     */
#define PE_D_XT_EUROPA_2000        106915 /* Jupiter - Europa    */
#define PE_D_XT_GANYMEDE_2000      106916 /* Jupiter - Ganymede  */
#define PE_D_XT_HIMALIA_2000       106917 /* Jupiter - Himalia   */
#define PE_D_XT_IO_2000            106918 /* Jupiter - Io        */
#define PE_D_XT_LEDA_2000          106919 /* Jupiter - Leda      */
#define PE_D_XT_LYSITHEA_2000      106920 /* Jupiter - Lysithea  */
#define PE_D_XT_METIS_2000         106921 /* Jupiter - Metis     */
#define PE_D_XT_PASIPHAE_2000      106922 /* Jupiter - Pasiphae  */
#define PE_D_XT_SINOPE_2000        106923 /* Jupiter - Sinope    */
#define PE_D_XT_THEBE_2000         106924 /* Jupiter - Thebe     */
#define PE_D_XT_SATURN_2000        106925 /* Saturn              */
#define PE_D_XT_ATLAS_2000         106926 /* Saturn - Atlas      */
#define PE_D_XT_CALYPSO_2000       106927 /* Saturn - Calypso    */
#define PE_D_XT_DIONE_2000         106928 /* Saturn - Dione      */
#define PE_D_XT_ENCELADUS_2000     106929 /* Saturn - Enceladus  */
#define PE_D_XT_EPIMETHEUS_2000    106930 /* Saturn - Epimetheus */
#define PE_D_XT_HELENE_2000        106931 /* Saturn - Helene     */
#define PE_D_XT_HYPERION_2000      106932 /* Saturn - Hyperion   */
#define PE_D_XT_IAPETUS_2000       106933 /* Saturn - Iapetus    */
#define PE_D_XT_JANUS_2000         107934 /* Saturn - Janus      */
#define PE_D_XT_MIMAS_2000         106935 /* Saturn - Mimas      */
#define PE_D_XT_PAN_2000           106936 /* Saturn - Pan        */
#define PE_D_XT_PANDORA_2000       106937 /* Saturn - Pandora    */
#define PE_D_XT_PHOEBE_2000        106938 /* Saturn - Phoebe     */
#define PE_D_XT_PROMETHEUS_2000    106939 /* Saturn - Prometheus */
#define PE_D_XT_RHEA_2000          106940 /* Saturn - Rhea       */
#define PE_D_XT_TELESTO_2000       106941 /* Saturn - Telesto    */
#define PE_D_XT_TETHYS_2000        106942 /* Saturn - Tethys     */
#define PE_D_XT_TITAN_2000         106943 /* Saturn - Titan      */
#define PE_D_XT_URANUS_2000        106944 /* Uranus              */
#define PE_D_XT_ARIEL_2000         106945 /* Uranus - Ariel      */
#define PE_D_XT_BELINDA_2000       106946 /* Uranus - Belinda    */
#define PE_D_XT_BIANCA_2000        106947 /* Uranus - Bianca     */
#define PE_D_XT_CORDELIA_2000      106948 /* Uranus - Cordelia   */
#define PE_D_XT_CRESSIDA_2000      106949 /* Uranus - Cressida   */
#define PE_D_XT_DESDEMONA_2000     106950 /* Uranus - Desdemona  */
#define PE_D_XT_JULIET_2000        106951 /* Uranus - Juliet     */
#define PE_D_XT_MIRANDA_2000       106952 /* Uranus - Miranda    */
#define PE_D_XT_OBERON_2000        106953 /* Uranus - Oberon     */
#define PE_D_XT_OPHELIA_2000       106954 /* Uranus - Ophelia    */
#define PE_D_XT_PORTIA_2000        106955 /* Uranus - Portia     */
#define PE_D_XT_PUCK_2000          106956 /* Uranus - Puck       */
#define PE_D_XT_ROSALIND_2000      106957 /* Uranus - Rosalind   */
#define PE_D_XT_TITANIA_2000       106958 /* Uranus - Titania    */
#define PE_D_XT_UMBRIEL_2000       106959 /* Uranus - Umbriel    */
#define PE_D_XT_NEPTUNE_2000       106960 /* Neptune             */
#define PE_D_XT_DESPINA_2000       106961 /* Neptune - Despina   */
#define PE_D_XT_GALATEA_2000       106962 /* Neptune - Galatea   */
#define PE_D_XT_LARISSA_2000       106963 /* Neptune - Larissa   */
#define PE_D_XT_NAIAD_2000         106964 /* Neptune - Naiad     */
#define PE_D_XT_NEREID_2000        106965 /* Neptune - Nereid    */
#define PE_D_XT_PROTEUS_2000       106966 /* Neptune - Proteus   */
#define PE_D_XT_THALASSA_2000      106967 /* Neptune - Thalassa  */
#define PE_D_XT_TRITON_2000        106968 /* Neptune - Triton    */
#define PE_D_XT_PLUTO_2000         106969 /* Pluto               */
#define PE_D_XT_CHARON_2000        106970 /* Pluto - Charon      */

/* END of NEW DATUM's at 9.0 ----------------------- */

#define PE_D_ABIDJAN_1987        6143 /* Abidjan 1987                         */
#define PE_D_ACCRA               6168 /* Accra                                */
#define PE_D_ADINDAN             6201 /* Adindan                              */
#define PE_D_AFGOOYE             6205 /* Afgooye                              */
#define PE_D_AGADEZ              6206 /* Agadez                               */
#define PE_D_AGD_1966            6202 /* Australian Geodetic Datum 1966       */
#define PE_D_AGD_1984            6203 /* Australian Geodetic Datum 1984       */
#define PE_D_AIN_EL_ABD_1970     6204 /* Ain el Abd 1970                      */
#define PE_D_AMERSFOORT          6289 /* Amersfoort                           */
#define PE_D_ANGUILLA_1957       6600 /* Anguilla 1957                        */
#define PE_D_ANTIGUA_1943        6601 /* Antigua Astro 1943                   */
#define PE_D_ARATU               6208 /* Aratu                                */
#define PE_D_ARC_1950            6209 /* Arc 1950                             */
#define PE_D_ARC_1960            6210 /* Arc 1960                             */
#define PE_D_ATF                 6901 /* Ancienne Triangulation Francaise     */
#define PE_D_ATS_1977            6122 /* Average Terrestrial System 1977      */
#define PE_D_BARBADOS_1938       6212 /* Barbados 1938                        */
#define PE_D_BATAVIA             6211 /* Batavia                              */
#define PE_D_BEDUARAM            6213 /* Beduaram                             */
#define PE_D_BEIJING_1954        6214 /* Beijing 1954                         */
#define PE_D_BELGE_1950          6215 /* Reseau National Belge 1950           */
#define PE_D_BELGE_1972          6313 /* Reseau National Belge 1972           */
#define PE_D_BERMUDA_1957        6216 /* Bermuda 1957                         */
#define PE_D_BERN_1898           6217 /* Bern 1898                            */
#define PE_D_BERN_1938           6306 /* Bern 1938                            */
#define PE_D_BISSAU              6165 /* Bissau                               */
#define PE_D_BOGOTA              6218 /* Bogota                               */
#define PE_D_BUKIT_RIMPAH        6219 /* Bukit Rimpah                         */
#define PE_D_CAMACUPA            6220 /* Camacupa                             */
#define PE_D_CAMPO_INCHAUSPE     6221 /* Campo Inchauspe                      */
#define PE_D_CAPE                6222 /* Cape                                 */
#define PE_D_CARTHAGE            6223 /* Carthage                             */
#define PE_D_CH1903              6149 /* CH 1903                              */
#define PE_D_CH1903_PLUS         6150 /* CH 1903+                             */
#define PE_D_CHOS_MALAL_1914     6160 /* Chos Malal 1914                      */
#define PE_D_CHTRF_1995          6151 /* Swiss Terrestrial Ref Frame 1995     */
#define PE_D_CHUA                6224 /* Chua                                 */
#define PE_D_CONAKRY_1905        6315 /* Conakry 1905                         */
#define PE_D_CORREGO_ALEGRE      6225 /* Corrego Alegre                       */
#define PE_D_COTE_D_IVOIRE       6226 /* Cote d'Ivoire                        */
#define PE_D_DABOLA              6155 /* Dabola 1981                          */
#define PE_D_DABOLA_1981         6155 /* Dabola 1981                          */
#define PE_D_DATUM_73            6274 /* Datum 73                             */
#define PE_D_DEALUL_PISCULUI_1933  6316 /* Dealul Piscului 1933               */
#define PE_D_DEALUL_PISCULUI_1970  6317 /* Dealul Piscului 1970               */
#define PE_D_DEIR_EZ_ZOR         6227 /* Deir ez Zor                          */
#define PE_D_DHDN                6314 /* Deutsches Hauptdreiecksnetz          */
#define PE_D_DOMINICA_1945       6602 /* Dominica 1945                        */
#define PE_D_DOUALA              6228 /* Douala                               */
#define PE_D_ED_1950             6230 /* European Datum 1950                  */
#define PE_D_ED_1950_ED77        6154 /* ED 1950 (ED77)                       */
#define PE_D_ED_1987             6231 /* European Datum 1987                  */
#define PE_D_EGYPT_1907          6229 /* Egypt 1907                           */
#define PE_D_ESTONIA_1992        6133 /* Estonia 1992                         */
#define PE_D_ETRS_1989           6258 /* European Terrestrial Ref. System 1989*/
#define PE_D_ETRF_1989         106258 /* European Terrestrial Ref. Frame 1989 */
#define PE_D_EUROPEAN_LIBYAN_1979  6159 /* European Libyan Datum 1979         */
#define PE_D_FAHUD               6232 /* Fahud                                */
#define PE_D_FD_1958             6132 /* Final Datum 1958                     */
#define PE_D_GANDAJIKA_1970      6233 /* Gandajika 1970                       */
#define PE_D_GAROUA              6234 /* Garoua                               */
#define PE_D_GDA_1994            6283 /* Geocentric Datum of Australia 1994   */
#define PE_D_GGRS_1987           6121 /* Greek Geodetic Reference System 1987 */
#define PE_D_GREEK               6120 /* Greek                                */
#define PE_D_GRENADA_1953        6603 /* Grenada 1953                         */
#define PE_D_GUYANE_FRANCAISE    6235 /* Guyane Francaise                     */
#define PE_D_HANOI_1972          6147 /* Hanoi 1972                           */
#define PE_D_HARTEBEESTHOEK94    6148 /* Hartebeesthoek 1994                  */
#define PE_D_HERAT_NORTH         6255 /* Herat North                          */
#define PE_D_HITO_XVIII_1963     6254 /* Hito XVIII 1963                      */
#define PE_D_HU_TZU_SHAN         6236 /* Hu Tzu Shan                          */
#define PE_D_HUNGARIAN_1972      6237 /* Hungarian Datum 1972                 */
#define PE_D_INDIAN_1954         6239 /* Indian 1954                          */
#define PE_D_INDIAN_1960         6131 /* Indian 1960                          */
#define PE_D_INDIAN_1975         6240 /* Indian 1975                          */
#define PE_D_INDONESIAN_1974     6238 /* Indonesian Datum 1974                */
#define PE_D_IRENET95            6173 /* IRENET95                             */
#define PE_D_ISRAEL              6141 /* Israel                               */
#define PE_D_JAMAICA_1875        6241 /* Jamaica 1875                         */
#define PE_D_JAMAICA_1969        6242 /* Jamaica 1969                         */
#define PE_D_KALIANPUR_1880      6243 /* Kalianpur (was PE_D_KALIANPUR)       */
#define PE_D_KALIANPUR_1937      6144 /* Kalianpur 1937                       */
#define PE_D_KALIANPUR_1962      6145 /* Kalianpur 1962                       */
#define PE_D_KALIANPUR_1975      6146 /* Kalianpur 1975                       */
#define PE_D_KANDAWALA           6244 /* Kandawala                            */
#define PE_D_KERTAU              6245 /* Kertau                               */
#define PE_D_KKJ                 6123 /* Kartastokoordinaattijarjestelma      */
#define PE_D_KOC                 6246 /* Kuwait Oil Company                   */
#define PE_D_KOREAN_1985         6162 /* Korean Datum 1985                    */
#define PE_D_KOREAN_1995         6166 /* Korean Datum 1995                    */
#define PE_D_KUDAMS              6319 /* Kuwait Utility                       */
#define PE_D_LAKE                6249 /* Lake                                 */
#define PE_D_LA_CANOA            6247 /* La Canoa                             */
#define PE_D_LEIGON              6250 /* Leigon                               */
#define PE_D_LIBERIA_1964        6251 /* Liberia 1964                         */
#define PE_D_LISBON              6207 /* Lisbon                               */
#define PE_D_LITHUANIA_1994      6126 /* Lithuania 1994                       */
#define PE_D_LOCODJO_1965        6142 /* Locodjo 1965                         */
#define PE_D_LOMA_QUINTANA       6288 /* Loma Quintana                        */
#define PE_D_LOME                6252 /* Lome                                 */
#define PE_D_LUZON_1911          6253 /* Luzon 1911                           */
#define PE_D_MADRID_1870         6903 /* Madrid 1870                          */
#define PE_D_MADZANSUA           6128 /* Madzansua - superseded by Tete       */
#define PE_D_MAHE_1971           6256 /* Mahe 1971                            */
#define PE_D_MAKASSAR            6257 /* Makassar                             */
#define PE_D_MALONGO_1987        6259 /* Malongo 1987                         */
#define PE_D_MANOCA              6260 /* Manoca                               */
#define PE_D_MASSAWA             6262 /* Massawa                              */
#define PE_D_MERCHICH            6261 /* Merchich                             */
#define PE_D_MGI                 6312 /* Militar-Geographische Institut       */
#define PE_D_MHAST               6264 /* Mhast                                */
#define PE_D_MINNA               6263 /* Minna                                */
#define PE_D_MONTE_MARIO         6265 /* Monte Mario                          */
#define PE_D_MONTSERRAT_1958     6604 /* Montserrat Astro 1958                */
#define PE_D_MOUNT_DILLON        6157 /* Mount Dillon                         */
#define PE_D_MOZNET              6130 /* Moznet                               */
#define PE_D_MPORALOKO           6266 /* M'poraloko                           */
#define PE_D_NAD_MICH            6268 /* NAD Michigan                         */
#define PE_D_NAD_1927            6267 /* North American Datum 1927            */
#define PE_D_NAD_1927_CGQ77      6609 /* NAD_1927 (CGQ77)                     */
#define PE_D_NAD_1927_DEF_1976   6608 /* NAD 1927 (1976)                      */
#define PE_D_NAD_1983            6269 /* North American Datum 1983            */
#define PE_D_NAD_1983_CSRS98     6140 /* NAD 1983(Canadian Spatial Ref System)*/
#define PE_D_NAD_1983_HARN       6152 /* NAD 1983 (HARN)                      */
#define PE_D_NAHRWAN_1967        6270 /* Nahrwan 1967                         */
#define PE_D_NAPARIMA_1955       6158 /* Naparima 1955                        */
#define PE_D_NAPARIMA_1972       6271 /* Naparima 1972                        */
#define PE_D_NDG                 6902 /* Nord de Guerre                       */
#define PE_D_NGN                 6318 /* National Geodetic Network (Kuwait)   */
#define PE_D_NGO_1948            6273 /* NGO 1948                             */
#define PE_D_NORD_SAHARA_1959    6307 /* Nord Sahara 1959                     */
#define PE_D_NSWC_9Z_2           6276 /* NSWC 9Z-2                            */
#define PE_D_NTF                 6275 /* Nouvelle Triangulation Francaise     */
#define PE_D_NZGD_1949           6272 /* New Zealand Geodetic Datum 1949      */
#define PE_D_OBSERVATARIO        6129 /* Observatario -  superseded by Tete   */
#define PE_D_OLD_HAWAIIAN        6135 /* Old Hawaiian                         */
#define PE_D_OSGB_1936           6277 /* OSGB 1936                            */
#define PE_D_OSGB_1970_SN        6278 /* OSGB 1970 (SN)                       */
#define PE_D_OS_SN_1980          6279 /* OS (SN) 1980                         */
#define PE_D_PADANG_1884         6280 /* Padang 1884                          */
#define PE_D_PALESTINE_1923      6281 /* Palestine 1923                       */
#define PE_D_PAMPA_DEL_CASTILLO  6161 /* Pampa del Castillo                   */
#define PE_D_PDO_1993            6134 /* PDO Survey Datum 1993                */
#define PE_D_POINTE_NOIRE        6282 /* Pointe Noire                         */
#define PE_D_POSGAR              6172 /* Posiciones Geodesicas Argentinas     */
#define PE_D_PSAD_1956           6248 /* Provisional South Amer. Datum 1956   */
#define PE_D_PUERTO_RICO         6139 /* Puerto Rico                          */
#define PE_D_PULKOVO_1942        6284 /* Pulkovo 1942                         */
#define PE_D_PULKOVO_1995        6200 /* Pulkovo 1995                         */
#define PE_D_QATAR               6285 /* Qatar                                */
#define PE_D_QATAR_1948          6286 /* Qatar 1948                           */
#define PE_D_QORNOQ              6287 /* Qornoq                               */
#define PE_D_RASSADIRAN          6153 /* Rassadiran                           */
#define PE_D_RT90                6124 /* RT 1990                              */
#define PE_D_SAD_1969            6291 /* South American Datum 1969            */
#define PE_D_SAMBOJA             6125 /* Samboja                              */
#define PE_D_SAPPER_HILL_1943    6292 /* Sapper Hill 1943                     */
#define PE_D_SCHWARZECK          6293 /* Schwarzeck                           */
#define PE_D_SEGORA              6294 /* Segora                               */
#define PE_D_SERINDUNG           6295 /* Serindung                            */
#define PE_D_SIERRA_LEONE_1924   6174 /* Sierra Leone 1924                    */
#define PE_D_SIERRA_LEONE_1968   6175 /* Sierra Leone 1968                    */
#define PE_D_SIRGAS              6170 /* Sistema de Referencia Geocentrico    */
                                      /*  para America del Sur                */
#define PE_D_SOUTH_YEMEN         6164 /* South Yemen                          */
#define PE_D_STOCKHOLM_1938      6308 /* Stockholm 1938                       */
#define PE_D_ST_GEORGE_ISLAND    6138 /* Alaska - St. George Island           */
#define PE_D_ST_KITTS_1955       6605 /* St. Kitts 1955                       */
#define PE_D_ST_LAWRENCE_ISLAND  6136 /* Alaska - St. Lawrence Island         */
#define PE_D_ST_LUCIA_1955       6606 /* St. Lucia 1955                       */
#define PE_D_ST_PAUL_ISLAND      6137 /* Alaska - St. Paul Island             */
#define PE_D_ST_VINCENT_1945     6607 /* St. Vincent 1945                     */
#define PE_D_SUDAN               6296 /* Sudan                                */
#define PE_D_S_JTSK              6156 /* S-JTSK                               */
#define PE_D_TANANARIVE_1925     6297 /* Tananarive 1925                      */
#define PE_D_TETE                6127 /* Tete                                 */
#define PE_D_TIMBALAI_1948       6298 /* Timbalai 1948                        */
#define PE_D_TM65                6299 /* TM65                                 */
#define PE_D_TM75                6300 /* TM75                                 */
#define PE_D_TOKYO               6301 /* Tokyo                                */
#define PE_D_TRINIDAD_1903       6302 /* Trinidad 1903                        */
#define PE_D_TRUCIAL_COAST_1948  6303 /* Trucial Coast 1948                   */
#define PE_D_VOIROL_1875         6304 /* Voirol 1875                          */
#define PE_D_VOIROL_UNIFIE_1960  6305 /* Voirol Unifie 1960                   */
#define PE_D_WGS_1972            6322 /* WGS 1972                             */
#define PE_D_WGS_1972_BE         6324 /* WGS 1972 Transit Broadcast Ephemeris */
#define PE_D_WGS_1984            6326 /* WGS 1984                             */
#define PE_D_YACARE              6309 /* Yacare                               */
#define PE_D_YEMEN_NGN_1996      6163 /* Yemen Nat'l Geodetic Network 1996    */
#define PE_D_YOFF                6310 /* Yoff                                 */
#define PE_D_ZANDERIJ            6311 /* Zanderij                             */

#define PE_D_ESTONIA_1937          106101 /* Estonia 1937                     */
#define PE_D_HERMANNSKOGEL         106102 /* Hermannskogel                    */
#define PE_D_SIERRA_LEONE_1960     106103 /* Sierra Leone 1960                */
#define PE_D_EUROPEAN_1979           6668 /* European 1979                    */
#define PE_D_EVEREST_BANGLADESH    106202 /* Everest - Bangladesh             */
#define PE_D_EVEREST_INDIA_NEPAL   106203 /* Everest - India and Nepal        */
#define PE_D_HJORSEY_1955            6658 /* Hjorsey 1955                     */
#define PE_D_HONG_KONG_1963        106205 /* Hong Kong 1963                   */
#define PE_D_OMAN                  106206 /* Oman                             */
#define PE_D_S_ASIA_SINGAPORE      106207 /* South Asia Singapore             */
#define PE_D_AYABELLE              106208 /* Ayabelle Lighthouse              */
#define PE_D_POINT58                 6620 /* Point 58                         */
#define PE_D_BEACON_E_1945         106212 /* Astro Beacon E 1945              */
#define PE_D_TERN_ISLAND_1961      106213 /* Tern Island Astro 1961           */
#define PE_D_ASTRO_1952            106214 /* Astronomical Station 1952        */
#define PE_D_BELLEVUE              106215 /* Bellevue IGN                     */
#define PE_D_CANTON_1966           106216 /* Canton Astro 1966                */
#define PE_D_CHATHAM_ISLAND_1971   106217 /* Chatham Island Astro 1971        */
#define PE_D_DOS_1968              106218 /* DOS 1968                         */
#define PE_D_EASTER_ISLAND_1967    106219 /* Easter Island 1967               */
#define PE_D_GUAM_1963             106220 /* Guam 1963                        */
#define PE_D_GUX_1                 106221 /* GUX 1 Astro                      */
#define PE_D_JOHNSTON_ISLAND_1961  106222 /* Johnston Island 1961             */
#define PE_D_KUSAIE_1951           106259 /* Kusaie Astro 1951                */
#define PE_D_MIDWAY_1961           106224 /* Midway Astro 1961                */
#define PE_D_PITCAIRN_1967         106226 /* Pitcairn Astro 1967              */
#define PE_D_SANTO_DOS_1965        106227 /* Santo DOS 1965                   */
#define PE_D_VITI_LEVU_1916        106228 /* Viti Levu 1916                   */
#define PE_D_WAKE_ENIWETOK_1960    106229 /* Wake-Eniwetok 1960               */
#define PE_D_WAKE_ISLAND_1952      106230 /* Wake Island Astro 1952           */
#define PE_D_ANNA_1_1965           106231 /* Anna 1 Astro 1965                */
#define PE_D_GAN_1970              106232 /* Gan 1970                         */
#define PE_D_ISTS_073_1969         106233 /* ISTS 073 Astro 1969              */
#define PE_D_KERGUELEN_ISLAND_1949 106234 /* Kerguelen Island 1949            */
#define PE_D_REUNION               106235 /* Reunion                          */
#define PE_D_ASCENSION_ISLAND_1958 106237 /* Ascension Island 1958            */
#define PE_D_DOS_71_4              106238 /* Astro DOS 71/4                   */
#define PE_D_CAPE_CANAVERAL        106239 /* Cape Canaveral                   */
#define PE_D_FORT_THOMAS_1955      106240 /* Fort Thomas 1955                 */
#define PE_D_GRACIOSA_1948         106241 /* Graciosa Base SW 1948            */
#define PE_D_ISTS_061_1968         106242 /* ISTS 061 Astro 1968              */
#define PE_D_LC5_1961              106243 /* L.C. 5 Astro 1961                */
#define PE_D_OBSERV_METEOR_1939    106245 /* Observ. Meteorologico 1939       */
#define PE_D_PICO_DE_LAS_NIEVES    106246 /* Pico de Las Nieves               */
#define PE_D_PORTO_SANTO_1936        6615 /* Porto Santo 1936                 */
#define PE_D_SAO_BRAZ              106249 /* Sao Braz                         */
#define PE_D_SELVAGEM_GRANDE_1938  106250 /* Selvagem Grande 1938             */
#define PE_D_TRISTAN_1968          106251 /* Tristan Astro 1968               */
#define PE_D_SAMOA_1962            106252 /* American Samoa 1962              */
#define PE_D_CAMP_AREA             106253 /* Camp Area Astro                  */
#define PE_D_DECEPTION_ISLAND      106254 /* Deception Island                 */
#define PE_D_GUNUNG_SEGARA           6613 /* Gunung Segara                    */
#define PE_D_S42_HUNGARY           106257 /* S-42 Hungary                     */
#define PE_D_ALASKAN_ISLANDS       106260 /* Alaskan Islands                  */
#define PE_D_HONG_KONG_1980          6611 /* Hong Kong 1980                   */
#define PE_D_LISBOA_BESSEL         106262 /* Datum Lisboa Bessel              */
#define PE_D_LISBOA_HAYFORD        106263 /* Datum Lisboa Hayford             */
#define PE_D_RGF_1993                6171 /* Reseau Geodesique Francais 1993  */
#define PE_D_NZGD_2000               6167 /* New Zealand Geodetic Datum 2000  */
#define PE_D_POHNPEI               106266 /* Pohnpei - Fed. States Micronesia */
#define PE_D_REGVEN                  6189 /* REGVEN                           */
#define PE_D_JGD_2000                6612 /* Japan Geodetic Datum 2000        */
#define PE_D_BAB_SOUTH             106269 /* Bab South Astro - Bablethuap Is -*/
                                          /*    Republic of Palau             */
#define PE_D_MAJURO                106270 /* Majuro - Republic of Marshall Is.*/

/*----------------------------------------------------------------------------*/
/*                     H O R I Z O N T A L   D A T U M S                      */
/*                        (S P H E R O I D   O N L Y)                         */
/*----------------------------------------------------------------------------*/
#define PE_D_AIRY_1830           6001 /* Airy 1830                            */
#define PE_D_AIRY_MOD            6002 /* Airy modified                        */
#define PE_D_AUSTRALIAN          6003 /* Australian National                  */
#define PE_D_BESSEL_1841         6004 /* Bessel 1841                          */
#define PE_D_BESSEL_MOD          6005 /* Bessel modified                      */
#define PE_D_BESSEL_NAMIBIA      6006 /* Bessel Namibia                       */
#define PE_D_CLARKE_1858         6007 /* Clarke 1858                          */
#define PE_D_CLARKE_1866         6008 /* Clarke 1866                          */
#define PE_D_CLARKE_1866_MICH    6009 /* Clarke 1866 Michigan                 */
#define PE_D_CLARKE_1880         6034 /* Clarke 1880                          */
#define PE_D_CLARKE_1880_ARC     6013 /* Clarke 1880 (Arc)                    */
#define PE_D_CLARKE_1880_BENOIT  6010 /* Clarke 1880 (Benoit)                 */
#define PE_D_CLARKE_1880_IGN     6011 /* Clarke 1880 (IGN)                    */
#define PE_D_CLARKE_1880_RGS     6012 /* Clarke 1880 (RGS)                    */
#define PE_D_CLARKE_1880_SGA     6014 /* Clarke 1880 (SGA)                    */
#define PE_D_EVEREST_1830        6042 /* Everest 1830  (was 106015)           */
#define PE_D_EVEREST_ADJ_1937    6015 /* Everest (adjustment 1937)            */
#define PE_D_EVEREST_DEF_1962    6044 /* Everest (definition 1962)            */
#define PE_D_EVEREST_DEF_1967    6016 /* Everest (definition 1967)            */
#define PE_D_EVEREST_DEF_1975    6045 /* Everest (definition 1975) (was 6017) */
#define PE_D_EVEREST_MOD         6018 /* Everest modified                     */
#define PE_D_GEM_10C             6031 /* GEM gravity potential model          */
#define PE_D_GRS_1967            6036 /* GRS 1967                             */
#define PE_D_GRS_1980            6019 /* GRS 1980                             */
#define PE_D_HELMERT_1906        6020 /* Helmert 1906                         */
#define PE_D_INDONESIAN          6021 /* Indonesian National                  */
#define PE_D_INTERNATIONAL_1924  6022 /* International 1924                   */
#define PE_D_INTERNATIONAL_1967  6023 /* International 1967                   */
#define PE_D_KRASOVSKY_1940      6024 /* Krasovsky 1940                       */
#define PE_D_NWL_9D              6025 /* Transit precise ephemeris            */
#define PE_D_OSU_86F             6032 /* OSU 1986 geoidal model               */
#define PE_D_OSU_91A             6033 /* OSU 1991 geoidal model               */
#define PE_D_PLESSIS_1817        6027 /* Plessis 1817                         */
#define PE_D_SPHERE              6035 /* Authalic sphere                      */
#define PE_D_STRUVE_1860         6028 /* Struve 1860                          */
#define PE_D_WAR_OFFICE          6029 /* War Office                           */

#define PE_D_WGS_1966          106001 /* WGS 1966                             */
#define PE_D_FISCHER_1960      106002 /* Fischer 1960                         */
#define PE_D_FISCHER_1968      106003 /* Fischer 1968                         */
#define PE_D_FISCHER_MOD       106004 /* Fischer modified                     */
#define PE_D_HOUGH_1960        106005 /* Hough 1960                           */
#define PE_D_EVEREST_MOD_1969  106006 /* Everest modified 1969                */
#define PE_D_WALBECK           106007 /* Walbeck                              */
#define PE_D_SPHERE_AI         106008 /* Authalic sphere (ARC/INFO)           */

/*----------------------------------------------------------------------------*/
/*                       P R I M E   M E R I D I A N S                        */
/*----------------------------------------------------------------------------*/
#define PE_PM_GREENWICH    8901 /*   0~00~00"     E                           */
#define PE_PM_ATHENS       8912 /*  23~42'58".815 E                           */
#define PE_PM_BERN         8907 /*   7~26'22".5   E                           */
#define PE_PM_BOGOTA       8904 /*  74~04'51".3   W                           */
#define PE_PM_BRUSSELS     8910 /*   4~22'04".71  E                           */
#define PE_PM_FERRO        8909 /*  17~40'00"     W                           */
#define PE_PM_JAKARTA      8908 /* 106~48'27".79  E                           */
#define PE_PM_LISBON       8902 /*   9~07'54".862 W                           */
#define PE_PM_MADRID       8905 /*   3~41'16".58  W                           */
#define PE_PM_OSLO         8913 /*  10~43'22".5   E                           */
#define PE_PM_PARIS        8903 /*   2~20'14".025 E                           */
#define PE_PM_ROME         8906 /*  12~27'08".4   E                           */
#define PE_PM_STOCKHOLM    8911 /*  18~03'29".8   E                           */

#define PE_PM_REFERENCE  108900 /* Generic meridian origin                    */

/*----------------------------------------------------------------------------*/
/*         G E O G R A P H I C   C O O R D I N A T E   S Y S T E M S          */
/*----------------------------------------------------------------------------*/

/* NEW GCS's at 9.0 ----------------------- */

#define PE_GCS_ALBANIAN_1987       4191 /* Albanian 1987                      */
#define PE_GCS_AMMASSALIK_1958     4196 /* Ammassalik 1958                    */
#define PE_GCS_AUSTRALIAN_ANTARCTIC_1998  4176 /* Autralian Antarctic Datum 1998 */
#define PE_GCS_AZORES_CENTRAL_1948     4183 /* Azores Central Isls 1948       */
#define PE_GCS_AZORES_CENTRAL_1995     4665 /* Azores Central Islands 1995    */
#define PE_GCS_AZORES_OCCIDENTAL_1939  4182 /* Azores Occidental Isls 1939    */
#define PE_GCS_AZORES_ORIENTAL_1940    4184 /* Azores Oriental Isls 1940      */
#define PE_GCS_AZORES_ORIENTAL_1995    4664 /* Azores Oriental Islands 1995   */
#define PE_GCS_COMBANI_1950        4632 /* Combani 1950                       */
#define PE_GCS_CSG_1967            4623 /* Centre Spatial Guyanais 1967       */
#define PE_GCS_DOUALA_1948         4192 /* Douala 1948                        */
#define PE_GCS_EGYPT_1930          4199 /* Egypt 1930                         */
#define PE_GCS_ESTONIA_1997        4180 /* Estonia 1997                       */
#define PE_GCS_FORT_DESAIX         4625 /* Fort Desaix                        */
#define PE_GCS_FORT_MARIGOT        4621 /* Fort Marigot                       */
#define PE_GCS_GRAND_COMOROS       4646 /* Grand Comoros                      */
#define PE_GCS_GUNUNG_SEGARA_JAKARTA  4820 /* Gunung Segara (Jakarta)         */
#define PE_GCS_HELLE_1954          4660 /* Helle 1954                         */
#define PE_GCS_IGM_1995            4670 /* IGM 1995                           */
#define PE_GCS_IGN53_MARE          4641 /* IGN53 Mare                         */
#define PE_GCS_IGN56_LIFOU         4633 /* IGN56 Lifou                        */
#define PE_GCS_IGN72_GRANDE_TERRE  4662 /* IGN72 Grande Terre                 */
#define PE_GCS_IGN72_NUKU_HIVA     4630 /* IGN72 Nuku Hiva                    */
#define PE_GCS_IKBD_1992           4667 /* Iraq-Kuwait Boundary Datum 1992    */
#define PE_GCS_ISN_1993            4659 /* Islands Network 1993               */
#define PE_GCS_K0_1949             4631 /* K0 1949                            */
#define PE_GCS_KOUSSERI            4198 /* Kousseri                           */
#define PE_GCS_LISBON_1890         4666 /* Lisbon 1890                        */
#define PE_GCS_LISBON_1890_LISBON  4904 /* Lisbon 1890 (Lisbon)               */
#define PE_GCS_LKS_1992            4661 /* Latvia 1992                        */
#define PE_GCS_LUXEMBOURG_1930     4181 /* Luxembourg 1930                    */
#define PE_GCS_MADEIRA_1936        4185 /* Madeira 1936                       */
#define PE_GCS_MANOCA_1962         4193 /* Manoca 1962                        */
#define PE_GCS_MOP78               4639 /* MOP78                              */
#define PE_GCS_NEA74_NOUMEA        4644 /* NEA74 Noumea                       */
#define PE_GCS_NORD_SAHARA_1959_PARIS  4819 /* Nord Sahara 1959 Paris         */
#define PE_GCS_OSNI_1952           4188 /* OSNI 1952                          */
#define PE_GCS_PETRELS_1972        4636 /* Petrels 1972                       */
#define PE_GCS_PITON_DES_NEIGES    4626 /* Piton des Neiges                   */
#define PE_GCS_POINTE_GEOLOGIE_PERROUD_1950  4637 /* Pointe Geologie Perroud 1950 */
#define PE_GCS_PORTO_SANTO_1995    4663 /* Porto Santo 1995                   */
#define PE_GCS_POSGAR_1998         4190 /* POSGAR 1998                        */
#define PE_GCS_PULKOVO_1942_ADJ_1958  4179 /* Pulkovo 1942/58                 */
#define PE_GCS_PULKOVO_1942_ADJ_1983  4178 /* Pulkovo 1942/83                 */
#define PE_GCS_QND_1995            4614 /* Qatar National Datum 1995          */
#define PE_GCS_QORNOQ_1927         4194 /* Qornoq 1927                        */
#define PE_GCS_REYKJAVIK_1900      4657 /* Reykjavik 1900                     */
#define PE_GCS_RGFG_1995           4624 /* Reseau Geodesique Francais Guyane 1995 */
#define PE_GCS_RGNC_1991           4645 /* Reseau Geodesique Nouvelle Caledonie 1991 */
#define PE_GCS_RGR_1992            4627 /* Reseau Geodesique de la Reunion 1992 */
#define PE_GCS_RRAF_1991           4640 /* Reseau de Reference des Antilles Francaises 1991 */
#define PE_GCS_SAINTE_ANNE         4622 /* Sainte Anne                        */
#define PE_GCS_SAINT_PIERRE_ET_MIQUELON_1950  4638 /* Saint Pierre et Miquelon 1950 */
#define PE_GCS_SCORESBYSUND_1952   4195 /* Scoresbysund 1952                  */
#define PE_GCS_ST71_BELEP          4643 /* ST71 Belep                         */
#define PE_GCS_ST84_ILE_DES_PINS   4642 /* ST84 Ile des Pins                  */
#define PE_GCS_ST87_OUVEA          4635 /* ST87 Ouvea                         */
#define PE_GCS_SWEREF99            4619 /* SWEREF99                           */
#define PE_GCS_TAHAA               4629 /* Tahaa                              */
#define PE_GCS_TAHITI              4628 /* Tahiti                             */
#define PE_GCS_XIAN_1980           4610 /* Xian 1980                          */

#define PE_GCS_BERMUDA_2000   104114 /* Bermuda 2000                          */
#define PE_GCS_ITRF_1988      104115 /* IERS Terrestrial Reference Frame 1988 */
#define PE_GCS_ITRF_1989      104116 /* IERS Terrestrial Reference Frame 1989 */
#define PE_GCS_ITRF_1990      104117 /* IERS Terrestrial Reference Frame 1990 */
#define PE_GCS_ITRF_1991      104118 /* IERS Terrestrial Reference Frame 1991 */
#define PE_GCS_ITRF_1992      104119 /* IERS Terrestrial Reference Frame 1992 */
#define PE_GCS_ITRF_1993      104120 /* IERS Terrestrial Reference Frame 1993 */
#define PE_GCS_ITRF_1994      104121 /* IERS Terrestrial Reference Frame 1994 */
#define PE_GCS_ITRF_1996      104122 /* IERS Terrestrial Reference Frame 1996 */
#define PE_GCS_ITRF_1997      104123 /* IERS Terrestrial Reference Frame 1997 */
#define PE_GCS_ITRF_2000      104124 /* IERS Terrestrial Reference Frame 2000 */

#define PE_GCS_CHATHAM_ISLANDS_1979  104125 /* Chatham Islands 1979           */
#define PE_GCS_OBSERV_METEOR_1965    104126 /* Observatorio Meteorologico 1965*/
#define PE_GCS_ROMA_1940             104127 /* Roma 1940                      */
#define PE_GCS_SPHERE_EMEP           104128 /* EMEP                           */
#define PE_GCS_EUREF_FIN             104129 /* EUREF - Finland                */
#define PE_GCS_JORDAN                104130 /* Jordan                         */

#define PE_GCS_NAD_1983_HARN_ADJ_MN_ANOKA      104700 /* NAD 1983 HARN Adj. Minnesota Anoka */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BECKER     104701 /* NAD 1983 HARN Adj. Minnesota Becker */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BELTRAMI_N 104702 /* NAD 1983 HARN Adj. Minnesota Beltrami_North */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BELTRAMI_S 104703 /* NAD 1983 HARN Adj. Minnesota Beltrami_South */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BENTON     104704 /* NAD 1983 HARN Adj. Minnesota Benton */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BIG_STONE  104705 /* NAD 1983 HARN Adj. Minnesota Big_Stone */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BLUE_EARTH 104706 /* NAD 1983 HARN Adj. Minnesota Blue_Earth */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_BROWN      104707 /* NAD 1983 HARN Adj. Minnesota Brown */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CARLTON    104708 /* NAD 1983 HARN Adj. Minnesota Carlton */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CARVER     104709 /* NAD 1983 HARN Adj. Minnesota Carver */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CASS_N     104710 /* NAD 1983 HARN Adj. Minnesota Cass_North */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CASS_S     104711 /* NAD 1983 HARN Adj. Minnesota Cass_South */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CHIPPEWA   104712 /* NAD 1983 HARN Adj. Minnesota Chippewa */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CHISAGO    104713 /* NAD 1983 HARN Adj. Minnesota Chisago */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_COOK_N     104714 /* NAD 1983 HARN Adj. Minnesota Cook_North */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_COOK_S     104715 /* NAD 1983 HARN Adj. Minnesota Cook_South */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_COTTONWOOD 104716 /* NAD 1983 HARN Adj. Minnesota Cottonwood */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_CROW_WING  104717 /* NAD 1983 HARN Adj. Minnesota Crow_Wing */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_DAKOTA     104718 /* NAD 1983 HARN Adj. Minnesota Dakota */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_DODGE      104719 /* NAD 1983 HARN Adj. Minnesota Dodge */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_DOUGLAS    104720 /* NAD 1983 HARN Adj. Minnesota Douglas */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_FARIBAULT  104721 /* NAD 1983 HARN Adj. Minnesota Faribault */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_FILLMORE   104722 /* NAD 1983 HARN Adj. Minnesota Fillmore */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_FREEBORN   104723 /* NAD 1983 HARN Adj. Minnesota Freeborn */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_GOODHUE    104724 /* NAD 1983 HARN Adj. Minnesota Goodhue */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_GRANT      104725 /* NAD 1983 HARN Adj. Minnesota Grant */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_HENNEPIN   104726 /* NAD 1983 HARN Adj. Minnesota Hennepin */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_HOUSTON    104727 /* NAD 1983 HARN Adj. Minnesota Houston */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ISANTI     104728 /* NAD 1983 HARN Adj. Minnesota Isanti */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ITASCA_N   104729 /* NAD 1983 HARN Adj. Minnesota Itasca_North */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ITASCA_S   104730 /* NAD 1983 HARN Adj. Minnesota Itasca_South */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_JACKSON    104731 /* NAD 1983 HARN Adj. Minnesota Jackson */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_KANABEC    104732 /* NAD 1983 HARN Adj. Minnesota Kanabec */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_KANDIYOHI  104733 /* NAD 1983 HARN Adj. Minnesota Kandiyohi */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_KITTSON    104734 /* NAD 1983 HARN Adj. Minnesota Kittson */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_KOOCHICHING   104735 /* NAD 1983 HARN Adj. Minnesota Koochiching */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_LAC_QUI_PARLE 104736 /* NAD 1983 HARN Adj. Minnesota Lac_Qui_Parle */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_N 104737 /* NAD 1983 HARN Adj. Minnesota */
                                                               /* Lake_of_the_Woods_North      */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_S 104738 /* NAD 1983 HARN Adj. Minnesota */
                                                               /* Lake_of_the_Woods_South      */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_LE_SUEUR   104739 /* NAD 1983 HARN Adj. Minnesota Le_Sueur */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_LINCOLN    104740 /* NAD 1983 HARN Adj. Minnesota Lincoln */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_LYON       104741 /* NAD 1983 HARN Adj. Minnesota Lyon */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MCLEOD     104742 /* NAD 1983 HARN Adj. Minnesota McLeod */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MAHNOMEN   104743 /* NAD 1983 HARN Adj. Minnesota Mahnomen */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MARSHALL   104744 /* NAD 1983 HARN Adj. Minnesota Marshall */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MARTIN     104745 /* NAD 1983 HARN Adj. Minnesota Martin */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MEEKER     104746 /* NAD 1983 HARN Adj. Minnesota Meeker */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MORRISON   104747 /* NAD 1983 HARN Adj. Minnesota Morrison */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MOWER      104748 /* NAD 1983 HARN Adj. Minnesota Mower */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_MURRAY     104749 /* NAD 1983 HARN Adj. Minnesota Murray */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_NICOLLET   104750 /* NAD 1983 HARN Adj. Minnesota Nicollet */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_NOBLES     104751 /* NAD 1983 HARN Adj. Minnesota Nobles */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_NORMAN     104752 /* NAD 1983 HARN Adj. Minnesota Norman */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_OLMSTED    104753 /* NAD 1983 HARN Adj. Minnesota Olmsted */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_OTTERTAIL  104754 /* NAD 1983 HARN Adj. Minnesota Ottertail */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_PENNINGTON 104755 /* NAD 1983 HARN Adj. Minnesota Pennington */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_PINE       104756 /* NAD 1983 HARN Adj. Minnesota Pine */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_PIPESTONE  104757 /* NAD 1983 HARN Adj. Minnesota Pipestone */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_POLK       104758 /* NAD 1983 HARN Adj. Minnesota Polk */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_POPE       104759 /* NAD 1983 HARN Adj. Minnesota Pope */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_RAMSEY     104760 /* NAD 1983 HARN Adj. Minnesota Ramsey */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_RED_LAKE   104761 /* NAD 1983 HARN Adj. Minnesota Red_Lake */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_REDWOOD    104762 /* NAD 1983 HARN Adj. Minnesota Redwood */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_RENVILLE   104763 /* NAD 1983 HARN Adj. Minnesota Renville */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_RICE       104764 /* NAD 1983 HARN Adj. Minnesota Rice */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ROCK       104765 /* NAD 1983 HARN Adj. Minnesota Rock */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ROSEAU     104766 /* NAD 1983 HARN Adj. Minnesota Roseau */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_N 104767 /* NAD 1983 HARN Adj. Minnesota St_Louis_North */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_C 104768 /* NAD 1983 HARN Adj. Minnesota St_Louis_Central */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_S 104769 /* NAD 1983 HARN Adj. Minnesota St_Louis_South */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_SCOTT      104770 /* NAD 1983 HARN Adj. Minnesota Scott */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_SHERBURNE  104771 /* NAD 1983 HARN Adj. Minnesota Sherburne */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_SIBLEY     104772 /* NAD 1983 HARN Adj. Minnesota Sibley */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_STEARNS    104773 /* NAD 1983 HARN Adj. Minnesota Stearns */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_STEELE     104774 /* NAD 1983 HARN Adj. Minnesota Steele */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_STEVENS    104775 /* NAD 1983 HARN Adj. Minnesota Stevens */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_SWIFT      104776 /* NAD 1983 HARN Adj. Minnesota Swift */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_TODD       104777 /* NAD 1983 HARN Adj. Minnesota Todd */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_TRAVERSE   104778 /* NAD 1983 HARN Adj. Minnesota Traverse */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_WABASHA    104779 /* NAD 1983 HARN Adj. Minnesota Wabasha */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_WADENA     104780 /* NAD 1983 HARN Adj. Minnesota Wadena */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_WASECA     104781 /* NAD 1983 HARN Adj. Minnesota Waseca */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_WATONWAN   104782 /* NAD 1983 HARN Adj. Minnesota Watonwan */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_WINONA     104783 /* NAD 1983 HARN Adj. Minnesota Winona */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_WRIGHT     104784 /* NAD 1983 HARN Adj. Minnesota Wright */
#define PE_GCS_NAD_1983_HARN_ADJ_MN_YELLOW_MEDICINE 104785 /* NAD 1983 HARN Adj. Minnesota */
                                                           /* Yellow_Medicine              */

#define PE_GCS_NAD_1983_HARN_ADJ_WI_AD  104800 /* NAD 1983 HARN Adj. Wisconsin Adams */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_AL  104801 /* NAD 1983 HARN Adj. Wisconsin Ashland */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_BA  104802 /* NAD 1983 HARN Adj. Wisconsin Barron */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_BF  104803 /* NAD 1983 HARN Adj. Wisconsin Bayfield */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_BR  104804 /* NAD 1983 HARN Adj. Wisconsin Brown */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_BU  104805 /* NAD 1983 HARN Adj. Wisconsin Buffalo */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_BN  104806 /* NAD 1983 HARN Adj. Wisconsin Burnett */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_CL  104807 /* NAD 1983 HARN Adj. Wisconsin Calumet */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_CP  104808 /* NAD 1983 HARN Adj. Wisconsin Chippewa */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_CK  104809 /* NAD 1983 HARN Adj. Wisconsin Clark */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_CO  104810 /* NAD 1983 HARN Adj. Wisconsin Columbia */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_CR  104811 /* NAD 1983 HARN Adj. Wisconsin Crawford */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_DN  104812 /* NAD 1983 HARN Adj. Wisconsin Dane */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_DD  104813 /* NAD 1983 HARN Adj. Wisconsin Dodge */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_DR  104814 /* NAD 1983 HARN Adj. Wisconsin Door */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_DG  104815 /* NAD 1983 HARN Adj. Wisconsin Douglas */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_DU  104816 /* NAD 1983 HARN Adj. Wisconsin Dunn */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_EC  104817 /* NAD 1983 HARN Adj. Wisconsin EauClaire */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_FN  104818 /* NAD 1983 HARN Adj. Wisconsin Florence */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_FL  104819 /* NAD 1983 HARN Adj. Wisconsin FondduLac */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_FR  104820 /* NAD 1983 HARN Adj. Wisconsin Forest */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_GT  104821 /* NAD 1983 HARN Adj. Wisconsin Grant */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_GR  104822 /* NAD 1983 HARN Adj. Wisconsin Green */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_GL  104823 /* NAD 1983 HARN Adj. Wisconsin GreenLake */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_IA  104824 /* NAD 1983 HARN Adj. Wisconsin Iowa */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_IR  104825 /* NAD 1983 HARN Adj. Wisconsin Iron */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_JA  104826 /* NAD 1983 HARN Adj. Wisconsin Jackson */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_JF  104827 /* NAD 1983 HARN Adj. Wisconsin Jefferson */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_JN  104828 /* NAD 1983 HARN Adj. Wisconsin Juneau */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_KN  104829 /* NAD 1983 HARN Adj. Wisconsin Kenosha */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_KW  104830 /* NAD 1983 HARN Adj. Wisconsin Kewaunee */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_LC  104831 /* NAD 1983 HARN Adj. Wisconsin LaCrosse */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_LF  104832 /* NAD 1983 HARN Adj. Wisconsin Lafayette */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_LG  104833 /* NAD 1983 HARN Adj. Wisconsin Langlade */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_LN  104834 /* NAD 1983 HARN Adj. Wisconsin Lincoln */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_MT  104835 /* NAD 1983 HARN Adj. Wisconsin Manitowoc */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_MA  104836 /* NAD 1983 HARN Adj. Wisconsin Marathon */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_MN  104837 /* NAD 1983 HARN Adj. Wisconsin Marinette */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_MQ  104838 /* NAD 1983 HARN Adj. Wisconsin Marquette */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_ME  104839 /* NAD 1983 HARN Adj. Wisconsin Menominee */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_MW  104840 /* NAD 1983 HARN Adj. Wisconsin Milwaukee */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_MR  104841 /* NAD 1983 HARN Adj. Wisconsin Monroe */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_OC  104842 /* NAD 1983 HARN Adj. Wisconsin Oconto */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_ON  104843 /* NAD 1983 HARN Adj. Wisconsin Oneida */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_OG  104844 /* NAD 1983 HARN Adj. Wisconsin Outagamie */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_OZ  104845 /* NAD 1983 HARN Adj. Wisconsin Ozaukee */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_PP  104846 /* NAD 1983 HARN Adj. Wisconsin Pepin */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_PC  104847 /* NAD 1983 HARN Adj. Wisconsin Pierce */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_PK  104848 /* NAD 1983 HARN Adj. Wisconsin Polk */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_PT  104849 /* NAD 1983 HARN Adj. Wisconsin Portage */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_PR  104850 /* NAD 1983 HARN Adj. Wisconsin Price */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_RA  104851 /* NAD 1983 HARN Adj. Wisconsin Racine */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_RC  104852 /* NAD 1983 HARN Adj. Wisconsin Richland */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_RK  104853 /* NAD 1983 HARN Adj. Wisconsin Rock */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_RS  104854 /* NAD 1983 HARN Adj. Wisconsin Rusk */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_SC  104855 /* NAD 1983 HARN Adj. Wisconsin StCroix */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_SK  104856 /* NAD 1983 HARN Adj. Wisconsin Sauk */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_SW  104857 /* NAD 1983 HARN Adj. Wisconsin Sawyer */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_SH  104858 /* NAD 1983 HARN Adj. Wisconsin Shawano */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_SG  104859 /* NAD 1983 HARN Adj. Wisconsin Sheboygan */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_TA  104860 /* NAD 1983 HARN Adj. Wisconsin Taylor */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_TR  104861 /* NAD 1983 HARN Adj. Wisconsin Trempealeau */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_VR  104862 /* NAD 1983 HARN Adj. Wisconsin Vernon */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_VI  104863 /* NAD 1983 HARN Adj. Wisconsin Vilas */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WW  104864 /* NAD 1983 HARN Adj. Wisconsin Walworth */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WB  104865 /* NAD 1983 HARN Adj. Wisconsin Washburn */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WA  104866 /* NAD 1983 HARN Adj. Wisconsin Washington */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WK  104867 /* NAD 1983 HARN Adj. Wisconsin Waukesha */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WP  104868 /* NAD 1983 HARN Adj. Wisconsin Waupaca */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WS  104869 /* NAD 1983 HARN Adj. Wisconsin Waushara */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WN  104870 /* NAD 1983 HARN Adj. Wisconsin Winnebago */
#define PE_GCS_NAD_1983_HARN_ADJ_WI_WD  104871 /* NAD 1983 HARN Adj. Wisconsin Wood */

#define PE_GCS_XT_MERCURY_2000    104900 /* Mercury             */
#define PE_GCS_XT_VENUS_1985      104901 /* Venus 1985          */
#define PE_GCS_XT_VENUS_2000      104902 /* Venus 2000          */
#define PE_GCS_XT_MOON_2000       104903 /* The Moon            */
#define PE_GCS_XT_MARS_1979       104904 /* Mars 1979           */
#define PE_GCS_XT_MARS_2000       104905 /* Mars 2000           */
#define PE_GCS_XT_DEIMOS_2000     104906 /* Mars - Deimos       */
#define PE_GCS_XT_PHOBOS_2000     104907 /* Mars - Phobos       */
#define PE_GCS_XT_JUPITER_2000    104908 /* Jupiter             */
#define PE_GCS_XT_ADRASTEA_2000   104909 /* Jupiter - Adrastea  */
#define PE_GCS_XT_AMALTHEA_2000   104910 /* Jupiter - Amalthea  */
#define PE_GCS_XT_ANANKE_2000     104911 /* Jupiter - Ananke    */
#define PE_GCS_XT_CALLISTO_2000   104912 /* Jupiter - Callisto  */
#define PE_GCS_XT_CARME_2000      104913 /* Jupiter - Carme     */
#define PE_GCS_XT_ELARA_2000      104914 /* Jupiter - Elara     */
#define PE_GCS_XT_EUROPA_2000     104915 /* Jupiter - Europa    */
#define PE_GCS_XT_GANYMEDE_2000   104916 /* Jupiter - Ganymede  */
#define PE_GCS_XT_HIMALIA_2000    104917 /* Jupiter - Himalia   */
#define PE_GCS_XT_IO_2000         104918 /* Jupiter - Io        */
#define PE_GCS_XT_LEDA_2000       104919 /* Jupiter - Leda      */
#define PE_GCS_XT_LYSITHEA_2000   104920 /* Jupiter - Lysithea  */
#define PE_GCS_XT_METIS_2000      104921 /* Jupiter - Metis     */
#define PE_GCS_XT_PASIPHAE_2000   104922 /* Jupiter - Pasiphae  */
#define PE_GCS_XT_SINOPE_2000     104923 /* Jupiter - Sinope    */
#define PE_GCS_XT_THEBE_2000      104924 /* Jupiter - Thebe     */
#define PE_GCS_XT_SATURN_2000     104925 /* Saturn              */
#define PE_GCS_XT_ATLAS_2000      104926 /* Saturn - Atlas      */
#define PE_GCS_XT_CALYPSO_2000    104927 /* Saturn - Calypso    */
#define PE_GCS_XT_DIONE_2000      104928 /* Saturn - Dione      */
#define PE_GCS_XT_ENCELADUS_2000  104929 /* Saturn - Enceladus  */
#define PE_GCS_XT_EPIMETHEUS_2000 104930 /* Saturn - Epimetheus */
#define PE_GCS_XT_HELENE_2000     104931 /* Saturn - Helene     */
#define PE_GCS_XT_HYPERION_2000   104932 /* Saturn - Hyperion   */
#define PE_GCS_XT_IAPETUS_2000    104933 /* Saturn - Iapetus    */
#define PE_GCS_XT_JANUS_2000      104934 /* Saturn - Janus      */
#define PE_GCS_XT_MIMAS_2000      104935 /* Saturn - Mimas      */
#define PE_GCS_XT_PAN_2000        104936 /* Saturn - Pan        */
#define PE_GCS_XT_PANDORA_2000    104937 /* Saturn - Pandora    */
#define PE_GCS_XT_PHOEBE_2000     104938 /* Saturn - Phoebe     */
#define PE_GCS_XT_PROMETHEUS_2000 104939 /* Saturn - Prometheus */
#define PE_GCS_XT_RHEA_2000       104940 /* Saturn - Rhea       */
#define PE_GCS_XT_TELESTO_2000    104941 /* Saturn - Telesto    */
#define PE_GCS_XT_TETHYS_2000     104942 /* Saturn - Tethys     */
#define PE_GCS_XT_TITAN_2000      104943 /* Saturn - Titan      */
#define PE_GCS_XT_URANUS_2000     104944 /* Uranus              */
#define PE_GCS_XT_ARIEL_2000      104945 /* Uranus - Ariel      */
#define PE_GCS_XT_BELINDA_2000    104946 /* Uranus - Belinda    */
#define PE_GCS_XT_BIANCA_2000     104947 /* Uranus - Bianca     */
#define PE_GCS_XT_CORDELIA_2000   104948 /* Uranus - Cordelia   */
#define PE_GCS_XT_CRESSIDA_2000   104949 /* Uranus - Cressida   */
#define PE_GCS_XT_DESDEMONA_2000  104950 /* Uranus - Desdemona  */
#define PE_GCS_XT_JULIET_2000     104951 /* Uranus - Juliet     */
#define PE_GCS_XT_MIRANDA_2000    104952 /* Uranus - Miranda    */
#define PE_GCS_XT_OBERON_2000     104953 /* Uranus - Oberon     */
#define PE_GCS_XT_OPHELIA_2000    104954 /* Uranus - Ophelia    */
#define PE_GCS_XT_PORTIA_2000     104955 /* Uranus - Portia     */
#define PE_GCS_XT_PUCK_2000       104956 /* Uranus - Puck       */
#define PE_GCS_XT_ROSALIND_2000   104957 /* Uranus - Rosalind   */
#define PE_GCS_XT_TITANIA_2000    104958 /* Uranus - Titania    */
#define PE_GCS_XT_UMBRIEL_2000    104959 /* Uranus - Umbriel    */
#define PE_GCS_XT_NEPTUNE_2000    104960 /* Neptune             */
#define PE_GCS_XT_DESPINA_2000    104961 /* Neptune - Despina   */
#define PE_GCS_XT_GALATEA_2000    104962 /* Neptune - Galatea   */
#define PE_GCS_XT_LARISSA_2000    104963 /* Neptune - Larissa   */
#define PE_GCS_XT_NAIAD_2000      104964 /* Neptune - Naiad     */
#define PE_GCS_XT_NEREID_2000     104965 /* Neptune - Nereid    */
#define PE_GCS_XT_PROTEUS_2000    104966 /* Neptune - Proteus   */
#define PE_GCS_XT_THALASSA_2000   104967 /* Neptune - Thalassa  */
#define PE_GCS_XT_TRITON_2000     104968 /* Neptune - Triton    */
#define PE_GCS_XT_PLUTO_2000      104969 /* Pluto               */
#define PE_GCS_XT_CHARON_2000     104970 /* Pluto - Charon      */

/* END of NEW GCS's at 9.0 ----------------------- */

#define PE_GCS_ABIDJAN_1987        4143 /* Abidjan 1987                       */
#define PE_GCS_ACCRA               4168 /* Accra                              */
#define PE_GCS_ADINDAN             4201 /* Adindan                            */
#define PE_GCS_AFGOOYE             4205 /* Afgooye                            */
#define PE_GCS_AGADEZ              4206 /* Agadez                             */
#define PE_GCS_AGD_1966            4202 /* Australian Geodetic Datum 1966     */
#define PE_GCS_AGD_1984            4203 /* Australian Geodetic Datum 1984     */
#define PE_GCS_AIN_EL_ABD_1970     4204 /* Ain el Abd 1970                    */
#define PE_GCS_AMERSFOORT          4289 /* Amersfoort                         */
#define PE_GCS_ANGUILLA_1957       4600 /* Anguilla 1957                      */
#define PE_GCS_ANTIGUA_1943        4601 /* Antigua Astro 1943                 */
#define PE_GCS_ARATU               4208 /* Aratu                              */
#define PE_GCS_ARC_1950            4209 /* Arc 1950                           */
#define PE_GCS_ARC_1960            4210 /* Arc 1960                           */
#define PE_GCS_ATF_PARIS           4901 /* ATF (Paris)                        */
#define PE_GCS_BARBADOS_1938       4212 /* Barbados 1938                      */
#define PE_GCS_BATAVIA             4211 /* Batavia                            */
#define PE_GCS_BATAVIA_JAKARTA     4813 /* Batavia (Jakarta)                  */
#define PE_GCS_BEDUARAM            4213 /* Beduaram                           */
#define PE_GCS_BEIJING_1954        4214 /* Beijing 1954                       */
#define PE_GCS_BELGE_1950          4215 /* Reseau National Belge 1950         */
#define PE_GCS_BELGE_1950_BRUSSELS 4809 /* Belge 1950 (Brussels)              */
#define PE_GCS_BELGE_1972          4313 /* Reseau National Belge 1972         */
#define PE_GCS_BERMUDA_1957        4216 /* Bermuda 1957                       */
#define PE_GCS_BERN_1898           4217 /* Bern 1898                          */
#define PE_GCS_BERN_1898_BERN      4801 /* Bern 1898 (Bern)                   */
#define PE_GCS_BERN_1938           4306 /* Bern 1938                          */
#define PE_GCS_BISSAU              4165 /* Bissau                             */
#define PE_GCS_BOGOTA              4218 /* Bogota                             */
#define PE_GCS_BOGOTA_BOGOTA       4802 /* Bogota (Bogota)                    */
#define PE_GCS_BUKIT_RIMPAH        4219 /* Bukit Rimpah                       */
#define PE_GCS_CAMACUPA            4220 /* Camacupa                           */
#define PE_GCS_CAMPO_INCHAUSPE     4221 /* Campo Inchauspe                    */
#define PE_GCS_CAPE                4222 /* Cape                               */
#define PE_GCS_CARTHAGE            4223 /* Carthage                           */
#define PE_GCS_CARTHAGE_PARIS      4816 /* Carthage (Paris) - superseded by   */
                                        /*             Carthage (Greenwich)   */
#define PE_GCS_CH1903              4149 /* CH 1903                            */
#define PE_GCS_CH1903_PLUS         4150 /* CH 1903+                           */
#define PE_GCS_CHOS_MALAL_1914     4160 /* Chos Malal 1914                    */
#define PE_GCS_CHTRF_1995          4151 /* Swiss Terrestrial Ref Frame 1995   */
#define PE_GCS_CHUA                4224 /* Chua                               */
#define PE_GCS_CONAKRY_1905        4315 /* Conakry 1905                       */
#define PE_GCS_CORREGO_ALEGRE      4225 /* Corrego Alegre                     */
#define PE_GCS_COTE_D_IVOIRE       4226 /* Cote d'Ivoire                      */
#define PE_GCS_DABOLA              4155 /* Dabola 1981                        */
#define PE_GCS_DABOLA_1981         4155 /* Dabola 1981                        */
#define PE_GCS_DATUM_73            4274 /* Datum 73                           */
#define PE_GCS_DEALUL_PISCULUI_1933  4316 /* Dealul Piscului 1933 (Romania)   */
#define PE_GCS_DEALUL_PISCULUI_1970  4317 /* Dealul Piscului 1970 (Romania)   */
#define PE_GCS_DEIR_EZ_ZOR         4227 /* Deir ez Zor                        */
#define PE_GCS_DHDN                4314 /* Deutsches Hauptdreiecksnetz        */
#define PE_GCS_DOMINICA_1945       4602 /* Dominica 1945                      */
#define PE_GCS_DOUALA              4228 /* Douala                             */
#define PE_GCS_ED_1950             4230 /* European Datum 1950                */
#define PE_GCS_ED_1950_ED77        4154 /* ED 1950 (ED77)                     */
#define PE_GCS_ED_1987             4231 /* European Datum 1987                */
#define PE_GCS_EGYPT_1907          4229 /* Egypt 1907                         */
#define PE_GCS_ESTONIA_1992        4133 /* Estonia 1992                       */
#define PE_GCS_ETRS_1989           4258 /* European Terrestrial Ref.System 1989*/
#define PE_GCS_ETRF_1989         104258 /* European Terrestrial Ref.Frame 1989*/
#define PE_GCS_EUROPEAN_LIBYAN_1979  4159 /* European Libyan Datum 1979       */
#define PE_GCS_FAHUD               4232 /* Fahud                              */
#define PE_GCS_FD_1958             4132 /* Final Datum 1958                   */
#define PE_GCS_GANDAJIKA_1970      4233 /* Gandajika 1970                     */
#define PE_GCS_GAROUA              4234 /* Garoua                             */
#define PE_GCS_GDA_1994            4283 /* Geocentric Datum of Australia 1994 */
#define PE_GCS_GGRS_1987           4121 /* Greek Geodetic Ref. System 1987    */
#define PE_GCS_GREEK               4120 /* Greek                              */
#define PE_GCS_GREEK_ATHENS        4815 /* Greek (Athens)                     */
#define PE_GCS_GRENADA_1953        4603 /* Grenada 1953                       */
#define PE_GCS_GUYANE_FRANCAISE    4235 /* Guyane Francaise                   */
#define PE_GCS_HANOI_1972          4147 /* Hanoi 1972                         */
#define PE_GCS_HARTEBEESTHOEK94    4148 /* Hartebeesthoek 1994                */
#define PE_GCS_HERAT_NORTH         4255 /* Herat North                        */
#define PE_GCS_HITO_XVIII_1963     4254 /* Hito XVIII 1963                    */
#define PE_GCS_HU_TZU_SHAN         4236 /* Hu Tzu Shan                        */
#define PE_GCS_HUNGARIAN_1972      4237 /* Hungarian Datum 1972               */
#define PE_GCS_INDIAN_1954         4239 /* Indian 1954                        */
#define PE_GCS_INDIAN_1960         4131 /* Indian 1960                        */
#define PE_GCS_INDIAN_1975         4240 /* Indian 1975                        */
#define PE_GCS_INDONESIAN_1974     4238 /* Indonesian Datum 1974              */
#define PE_GCS_IRENET95            4173 /* IRENET95                           */
#define PE_GCS_ISRAEL              4141 /* Israel                             */
#define PE_GCS_JAMAICA_1875        4241 /* Jamaica 1875                       */
#define PE_GCS_JAMAICA_1969        4242 /* Jamaica 1969                       */
#define PE_GCS_KALIANPUR_1880      4243 /* Kalianpur 1880                     */
#define PE_GCS_KALIANPUR_1937      4144 /* Kalianpur 1937                     */
#define PE_GCS_KALIANPUR_1962      4145 /* Kalianpur 1962                     */
#define PE_GCS_KALIANPUR_1975      4146 /* Kalianpur 1975                     */
#define PE_GCS_KANDAWALA           4244 /* Kandawala                          */
#define PE_GCS_KERTAU              4245 /* Kertau                             */
#define PE_GCS_KKJ                 4123 /* Kartastokoordinaattijarjestelma    */
#define PE_GCS_KOC                 4246 /* Kuwait Oil Company                 */
#define PE_GCS_KOREAN_1985         4162 /* Korean Datum 1985                  */
#define PE_GCS_KOREAN_1995         4166 /* Korean Datum 1995                  */
#define PE_GCS_KUDAMS              4319 /* Kuwait Utility                     */
#define PE_GCS_LA_CANOA            4247 /* La Canoa                           */
#define PE_GCS_LAKE                4249 /* Lake                               */
#define PE_GCS_LEIGON              4250 /* Leigon                             */
#define PE_GCS_LIBERIA_1964        4251 /* Liberia 1964                       */
#define PE_GCS_LISBON              4207 /* Lisbon                             */
#define PE_GCS_LISBON_LISBON       4803 /* Lisbon (Lisbon)                    */
#define PE_GCS_LKS_1994            4669 /* LKS 1994    (Lithuania)            */
#define PE_GCS_LOCODJO_1965        4142 /* Locodjo 1965                       */
#define PE_GCS_LOMA_QUINTANA       4288 /* Loma Quintana                      */
#define PE_GCS_LOME                4252 /* Lome                               */
#define PE_GCS_LUZON_1911          4253 /* Luzon 1911                         */
#define PE_GCS_MADRID_1870_MADRID  4903 /* Madrid 1870 - Madrid Prime M       */
#define PE_GCS_MADZANSUA           4128 /* Madzansua - superseded by Tete     */
#define PE_GCS_MAHE_1971           4256 /* Mahe 1971                          */
#define PE_GCS_MAKASSAR            4257 /* Makassar                           */
#define PE_GCS_MAKASSAR_JAKARTA    4804 /* Makassar (Jakarta)                 */
#define PE_GCS_MALONGO_1987        4259 /* Malongo 1987                       */
#define PE_GCS_MANOCA              4260 /* Manoca                             */
#define PE_GCS_MASSAWA             4262 /* Massawa                            */
#define PE_GCS_MERCHICH            4261 /* Merchich                           */
#define PE_GCS_MERCHICH_DEGREE   104261 /* Merchich (degrees)                 */
#define PE_GCS_MGI                 4312 /* Militar-Geographische Institut     */
#define PE_GCS_MGI_FERRO           4805 /* MGI (Ferro)                        */
#define PE_GCS_MHAST               4264 /* Mhast                              */
#define PE_GCS_MINNA               4263 /* Minna                              */
#define PE_GCS_MONTE_MARIO         4265 /* Monte Mario                        */
#define PE_GCS_MONTE_MARIO_ROME    4806 /* Monte Mario (Rome)                 */
#define PE_GCS_MONTSERRAT_1958     4404 /* Montserrat Astro 1958              */
#define PE_GCS_MOUNT_DILLON        4157 /* Mount Dillon                       */
#define PE_GCS_MOZNET              4130 /* Moznet                             */
#define PE_GCS_MPORALOKO           4266 /* M'poraloko                         */
#define PE_GCS_NAD_MICH            4268 /* NAD Michigan                       */
#define PE_GCS_NAD_1927            4267 /* North American Datum 1927          */
#define PE_GCS_NAD_1927_CGQ77      4609 /* NAD_1927 CGQ77                     */
#define PE_GCS_NAD_1927_DEF_1976   4608 /* NAD 1927 (1976)                    */
#define PE_GCS_NAD_1983            4269 /* North American Datum 1983          */
#define PE_GCS_NAD_1983_CSRS98     4140 /* NAD 1983(Canadian Spatial Ref System)*/
#define PE_GCS_NAD_1983_HARN       4152 /* North American Datum 1983 (HARN) (was 104269)*/
#define PE_GCS_NAHRWAN_1967        4270 /* Nahrwan 1967                       */
#define PE_GCS_NAPARIMA_1955       4158 /* Naparima 1955                      */
#define PE_GCS_NAPARIMA_1972       4271 /* Naparima 1972                      */
#define PE_GCS_NDG_PARIS           4902 /* Nord de Guerre (Paris)             */
#define PE_GCS_NGN                 4318 /* National Geodetic Network (Kuwait) */
#define PE_GCS_NGO_1948            4273 /* NGO 1948                           */
#define PE_GCS_NGO_1948_OSLO       4817 /* NGO 1948 (Oslo)                    */
#define PE_GCS_NORD_SAHARA_1959    4307 /* Nord Sahara 1959                   */
#define PE_GCS_NSWC_9Z_2           4276 /* NSWC 9Z-2                          */
#define PE_GCS_NTF                 4275 /* Nouvelle Triangulation Francaise (degrees) */
#define PE_GCS_NTF_PARIS           4807 /* NTF (Paris) (grads)                */
#define PE_GCS_NZGD_1949           4272 /* New Zealand Geodetic Datum 1949    */
#define PE_GCS_OBSERVATARIO        4129 /* Observatario - superseded by Tete  */
#define PE_GCS_OLD_HAWAIIAN        4135 /* Old Hawaiian                       */
#define PE_GCS_OS_SN_1980          4279 /* OS (SN) 1980                       */
#define PE_GCS_OSGB_1936           4277 /* OSGB 1936                          */
#define PE_GCS_OSGB_1970_SN        4278 /* OSGB 1970 (SN)                     */
#define PE_GCS_PADANG_1884         4280 /* Padang 1884                        */
#define PE_GCS_PADANG_1884_JAKARTA 4808 /* Padang 1884 (Jakarta)              */
#define PE_GCS_PALESTINE_1923      4281 /* Palestine 1923                     */
#define PE_GCS_PAMPA_DEL_CASTILLO  4161 /* Pampa del Castillo                 */
#define PE_GCS_PDO_1993            4134 /* PDO Survey Datum 1993              */
#define PE_GCS_POINTE_NOIRE        4282 /* Pointe Noire                       */
#define PE_GCS_POSGAR              4172 /* POSGAR                             */
#define PE_GCS_PSAD_1956           4248 /* Provisional South Amer. Datum 1956 */
#define PE_GCS_PUERTO_RICO         4139 /* Puerto Rico                        */
#define PE_GCS_PULKOVO_1942        4284 /* Pulkovo 1942                       */
#define PE_GCS_PULKOVO_1995        4200 /* Pulkovo 1995                       */
#define PE_GCS_QATAR               4285 /* Qatar 1974                         */
#define PE_GCS_QATAR_1974          4285 /* Qatar 1974                         */
#define PE_GCS_QATAR_1948          4286 /* Qatar 1948                         */
#define PE_GCS_QORNOQ              4287 /* Qornoq                             */
#define PE_GCS_RASSADIRAN          4153 /* Rassadiran                         */
#define PE_GCS_RT38                4308 /* RT38                               */
#define PE_GCS_RT38_STOCKHOLM      4814 /* RT38 (Stockholm)                   */
#define PE_GCS_RT90                4124 /* RT 1990                            */
#define PE_GCS_SAD_1969            4291 /* South American Datum 1969          */
#define PE_GCS_SAMBOJA             4125 /* Samboja                            */
#define PE_GCS_SAPPER_HILL_1943    4292 /* Sapper Hill 1943                   */
#define PE_GCS_SCHWARZECK          4293 /* Schwarzeck                         */
#define PE_GCS_SEGORA              4294 /* Segora                             */
#define PE_GCS_SERINDUNG           4295 /* Serindung                          */
#define PE_GCS_SIERRA_LEONE_1924   4174 /* Sierra Leone 1924                  */
#define PE_GCS_SIERRA_LEONE_1968   4175 /* Sierra Leone 1968                  */
#define PE_GCS_SIRGAS              4170 /* SIRGAS                             */
#define PE_GCS_SOUTH_YEMEN         4164 /* South Yemen                        */
#define PE_GCS_ST_GEORGE_ISLAND    4138 /* Alaska - St. George Island         */
#define PE_GCS_ST_KITTS_1955       4605 /* St. Kitts 1955                     */
#define PE_GCS_ST_LAWRENCE_ISLAND  4136 /* Alaska - St. Lawrence Island       */
#define PE_GCS_ST_LUCIA_1955       4606 /* St. Lucia 1955                     */
#define PE_GCS_ST_PAUL_ISLAND      4137 /* Alaska - St. Paul Island           */
#define PE_GCS_ST_VINCENT_1945     4607 /* St. Vincent 1945                   */
#define PE_GCS_SUDAN               4296 /* Sudan                              */
#define PE_GCS_S_JTSK              4156 /* S-JTSK                             */
#define PE_GCS_S_JTSK_FERRO        4818 /* S-JTSK (Ferro)                     */
#define PE_GCS_TANANARIVE_1925     4297 /* Tananarive 1925                    */
#define PE_GCS_TANANARIVE_1925_PARIS 4810 /* Tananarive 1925 (Paris)          */
#define PE_GCS_TETE                4127 /* Tete                               */
#define PE_GCS_TIMBALAI_1948       4298 /* Timbalai 1948                      */
#define PE_GCS_TM65                4299 /* TM65                               */
#define PE_GCS_TM75                4300 /* TM75                               */
#define PE_GCS_TOKYO               4301 /* Tokyo                              */
#define PE_GCS_TRINIDAD_1903       4302 /* Trinidad 1903                      */
#define PE_GCS_TRUCIAL_COAST_1948  4303 /* Trucial Coast 1948                 */
#define PE_GCS_VOIROL_1875         4304 /* Voirol 1875                        */
#define PE_GCS_VOIROL_1875_DEGREE 104304 /* Voirol 1875 (degrees)             */
#define PE_GCS_VOIROL_1875_PARIS   4811 /* Voirol 1875 (Paris)                */
#define PE_GCS_VOIROL_UNIFIE_1960  4305 /* Voirol Unifie 1960                 */
#define PE_GCS_VOIROL_UNIFIE_1960_DEGREE 104305 /*Voirol Unifie 1960 (degrees)*/
#define PE_GCS_VOIROL_UNIFIE_1960_PARIS 4812 /* Voirol Unifie 1960 (Paris)    */
#define PE_GCS_WGS_1972            4322 /* WGS 1972                           */
#define PE_GCS_WGS_1972_BE         4324 /* WGS 1972 Transit Broadcast Ephemer.*/
#define PE_GCS_WGS_1984            4326 /* WGS 1984                           */
#define PE_GCS_YACARE              4309 /* Yacare                             */
#define PE_GCS_YEMEN_NGN_1996      4163 /* Yemen Nat'l Geodetic Network 1996  */
#define PE_GCS_YOFF                4310 /* Yoff                               */
#define PE_GCS_ZANDERIJ            4311 /* Zanderij                           */

#define PE_GCS_EUROPEAN_1979        4668         /* European 1979             */
#define PE_GCS_EVEREST_BANGLADESH   (4202+33000) /* Everest - Bangladesh      */
#define PE_GCS_EVEREST_INDIA_NEPAL  (4203+33000) /* Everest - India and Nepal */
#define PE_GCS_HJORSEY_1955         4658         /* Hjorsey 1955              */
#define PE_GCS_HONG_KONG_1963       (4205+33000) /* Hong Kong 1963            */
#define PE_GCS_OMAN                 (4206+33000) /* Oman                      */
#define PE_GCS_S_ASIA_SINGAPORE     (4207+33000) /* South Asia Singapore      */
#define PE_GCS_AYABELLE             (4208+33000) /* Ayabelle Lighthouse       */
#define PE_GCS_POINT58              4620         /* Point 58                  */
#define PE_GCS_BEACON_E_1945        (4212+33000) /* Astro Beacon E 1945       */
#define PE_GCS_TERN_ISLAND_1961     (4213+33000) /* Tern Island Astro 1961    */
#define PE_GCS_ASTRO_1952           (4214+33000) /* Astronomical Station 1952 */
#define PE_GCS_BELLEVUE             (4215+33000) /* Bellevue IGN              */
#define PE_GCS_CANTON_1966          (4216+33000) /* Canton Astro 1966         */
#define PE_GCS_CHATHAM_ISLAND_1971  (4217+33000) /* Chatham Island Astro 1971 */
#define PE_GCS_DOS_1968             (4218+33000) /* DOS 1968                  */
#define PE_GCS_EASTER_ISLAND_1967   (4219+33000) /* Easter Island 1967        */
#define PE_GCS_GUAM_1963            (4220+33000) /* Guam 1963                 */
#define PE_GCS_GUX_1                (4221+33000) /* GUX 1 Astro               */
#define PE_GCS_JOHNSTON_ISLAND_1961 (4222+33000) /* Johnston Island 1961      */
#define PE_GCS_CARTHAGE_DEGREE      (4223+33000) /* Carthage (degrees)        */
#define PE_GCS_MIDWAY_1961          (4224+33000) /* Midway Astro 1961         */
#define PE_GCS_PITCAIRN_1967        (4226+33000) /* Pitcairn Astro 1967       */
#define PE_GCS_SANTO_DOS_1965       (4227+33000) /* Santo DOS 1965            */
#define PE_GCS_VITI_LEVU_1916       (4228+33000) /* Viti Levu 1916            */
#define PE_GCS_WAKE_ENIWETOK_1960   (4229+33000) /* Wake-Eniwetok 1960        */
#define PE_GCS_WAKE_ISLAND_1952     (4230+33000) /* Wake Island Astro 1952    */
#define PE_GCS_ANNA_1_1965          (4231+33000) /* Anna 1 Astro 1965         */
#define PE_GCS_GAN_1970             (4232+33000) /* Gan 1970                  */
#define PE_GCS_ISTS_073_1969        (4233+33000) /* ISTS 073 Astro 1969       */
#define PE_GCS_KERGUELEN_ISLAND_1949 (4234+33000) /* Kerguelen Island 1949    */
#define PE_GCS_REUNION               (4235+33000) /* Reunion                  */
#define PE_GCS_ASCENSION_ISLAND_1958 (4237+33000) /* Ascension Island 1958    */
#define PE_GCS_DOS_71_4             (4238+33000) /* Astro DOS 71/4            */
#define PE_GCS_CAPE_CANAVERAL       (4239+33000) /* Cape Canaveral            */
#define PE_GCS_FORT_THOMAS_1955     (4240+33000) /* Fort Thomas 1955          */
#define PE_GCS_GRACIOSA_1948        (4241+33000) /* Graciosa Base SW 1948     */
#define PE_GCS_ISTS_061_1968        (4242+33000) /* ISTS 061 Astro 1968       */
#define PE_GCS_LC5_1961             (4243+33000) /* L.C. 5 Astro 1961         */
#define PE_GCS_OBSERV_METEOR_1939   (4245+33000) /* Observ. Meteorologico 1939*/
#define PE_GCS_PICO_DE_LAS_NIEVES   (4246+33000) /* Pico de Las Nieves        */
#define PE_GCS_PORTO_SANTO_1936     4615         /* Porto Santo 1936          */
#define PE_GCS_SAO_BRAZ             (4249+33000) /* Sao Braz                  */
#define PE_GCS_SELVAGEM_GRANDE_1938 (4250+33000) /* Selvagem Grande 1938      */
#define PE_GCS_TRISTAN_1968         (4251+33000) /* Tristan Astro 1968        */
#define PE_GCS_SAMOA_1962           (4252+33000) /* American Samoa 1962       */
#define PE_GCS_CAMP_AREA            (4253+33000) /* Camp Area Astro           */
#define PE_GCS_DECEPTION_ISLAND     (4254+33000) /* Deception Island          */
#define PE_GCS_GUNUNG_SEGARA        4613         /* Gunung Segara             */
#define PE_GCS_S42_HUNGARY          (4257+33000) /* S-42 Hungary              */
#define PE_GCS_KUSAIE_1951          (4259+33000) /* Kusaie Astro 1951         */
#define PE_GCS_ALASKAN_ISLANDS      (4260+33000) /* Alaskan Islands           */

#define PE_GCS_ESTONIA_1937      104101 /* Estonia 1937                       */
#define PE_GCS_HERMANNSKOGEL     104102 /* Hermannskogel                      */
#define PE_GCS_SIERRA_LEONE_1960 104103 /* Sierra Leone 1960                  */
#define PE_GCS_HONG_KONG_1980      4611 /* Hong Kong 1980                     */
#define PE_GCS_LISBOA_BESSEL     104105 /* Datum Lisboa Bessel                */
#define PE_GCS_LISBOA_HAYFORD    104106 /* Datum Lisboa Hayford               */
#define PE_GCS_RGF_1993            4171 /* Reseau Geodesique Francais 1993    */
#define PE_GCS_NZGD_2000           4167 /* New Zealand Geodetic Datum 2000    */
#define PE_GCS_POHNPEI           104109 /* Pohnpei - Fed. States Micronesia   */
#define PE_GCS_REGVEN              4189 /* REGVEN                             */
#define PE_GCS_JGD_2000            4612 /* Japan Geodetic Datum 2000          */
#define PE_GCS_BAB_SOUTH         104112 /* Bab South Astro - Bablethuap Island*/
                                        /*    Republic of Palau               */
#define PE_GCS_MAJURO            104113 /* Majuro - Republic of Marshall Isls.*/

/*----------------------------------------------------------------------------*/
/*         G E O G R A P H I C   C O O R D I N A T E   S Y S T E M S          */
/*                        (S P H E R O I D   O N L Y)                         */
/*----------------------------------------------------------------------------*/

#define PE_GCS_AIRY_1830           4001 /* Airy 1830                          */
#define PE_GCS_AIRY_MOD            4002 /* Airy modified                      */
#define PE_GCS_ATS_1977            4122 /* Average Terrestrial System 1977    */
#define PE_GCS_AUSTRALIAN          4003 /* Australian National                */
#define PE_GCS_BESSEL_1841         4004 /* Bessel 1841                        */
#define PE_GCS_BESSEL_MOD          4005 /* Bessel modified                    */
#define PE_GCS_BESSEL_NAMIBIA      4006 /* Bessel Namibia                     */
#define PE_GCS_CLARKE_1858         4007 /* Clarke 1858                        */
#define PE_GCS_CLARKE_1866         4008 /* Clarke 1866                        */
#define PE_GCS_CLARKE_1866_MICH    4009 /* Clarke 1866 Michigan               */
#define PE_GCS_CLARKE_1880         4034 /* Clarke 1880                        */
#define PE_GCS_CLARKE_1880_ARC     4013 /* Clarke 1880 (Arc)                  */
#define PE_GCS_CLARKE_1880_BENOIT  4010 /* Clarke 1880 (Benoit)               */
#define PE_GCS_CLARKE_1880_IGN     4011 /* Clarke 1880 (IGN)                  */
#define PE_GCS_CLARKE_1880_RGS     4012 /* Clarke 1880 (RGS)                  */
#define PE_GCS_CLARKE_1880_SGA     4014 /* Clarke 1880 (SGA)                  */
#define PE_GCS_EVEREST_1830        4042 /* Everest 1830   (was 4015)          */
#define PE_GCS_EVEREST_DEF_1962    4044 /* Everest (definition 1962)          */
#define PE_GCS_EVEREST_DEF_1967    4016 /* Everest (definition 1967)          */
#define PE_GCS_EVEREST_DEF_1975    4045 /* Everest (definition 1975)(was 4017)*/
#define PE_GCS_EVEREST_MOD         4018 /* Everest modified                   */
#define PE_GCS_GEM_10C             4031 /* GEM gravity potential model        */
#define PE_GCS_GRS_1967            4036 /* GRS 1967                           */
#define PE_GCS_GRS_1980            4019 /* GRS 1980                           */
#define PE_GCS_HELMERT_1906        4020 /* Helmert 1906                       */
#define PE_GCS_INDONESIAN          4021 /* Indonesian National                */
#define PE_GCS_INTERNATIONAL_1924  4022 /* International 1927                 */
#define PE_GCS_INTERNATIONAL_1967  4023 /* International 1967                 */
#define PE_GCS_KRASOVSKY_1940      4024 /* Krasovsky 1940                     */
#define PE_GCS_NWL_9D              4025 /* Transit precise ephemeris          */
#define PE_GCS_OSU_86F             4032 /* OSU 1986 geoidal model             */
#define PE_GCS_OSU_91A             4033 /* OSU 1991 geoidal model             */
#define PE_GCS_PLESSIS_1817        4027 /* Plessis 1817                       */
#define PE_GCS_SPHERE              4035 /* Authalic sphere                    */
#define PE_GCS_STRUVE_1860         4028 /* Struve 1860                        */
#define PE_GCS_WAR_OFFICE          4029 /* War Office                         */
#define PE_GCS_WGS_1966            (4001+33000) /* WGS 1966                   */
#define PE_GCS_FISCHER_1960        (4002+33000) /* Fischer 1960               */
#define PE_GCS_FISCHER_1968        (4003+33000) /* Fischer 1968               */
#define PE_GCS_FISCHER_MOD         (4004+33000) /* Fischer modified           */
#define PE_GCS_HOUGH_1960          (4005+33000) /* Hough 1960                 */
#define PE_GCS_EVEREST_MOD_1969    (4006+33000) /* Everest modified 1969      */
#define PE_GCS_WALBECK             (4007+33000) /* Walbeck                    */
#define PE_GCS_SPHERE_AI           (4008+33000) /* Authalic sphere (ARC/INFO) */
#define PE_GCS_ASSUMED_GEOGRAPHIC_1 104000  /* NAD27 for shapefiles w/o a PRJ */

/*----------------------------------------------------------------------------*/
/*                            P A R A M E T E R S                             */
/*----------------------------------------------------------------------------*/
#define PE_PAR_FALSE_EASTING       100001 /* X0                               */
#define PE_PAR_FALSE_NORTHING      100002 /* Y0                               */
#define PE_PAR_SCALE_FACTOR        100003 /* K0                               */
#define PE_PAR_AZIMUTH             100004 /* ALPHA                            */
#define PE_PAR_HEIGHT              100005 /* HEIGHT                           */

#define PE_PAR_CENTRAL_MERIDIAN    100010 /* LAM0                             */
#define PE_PAR_LONGITUDE_OF_ORIGIN 100011 /* LAM0                             */
#define PE_PAR_LONGITUDE_OF_CENTER 100012 /* LAMC                             */
#define PE_PAR_LONGITUDE_OF_1ST    100013 /* LAM1                             */
#define PE_PAR_LONGITUDE_OF_2ND    100014 /* LAM2                             */

#define PE_PAR_CENTRAL_PARALLEL    100020 /* PHI0                             */
#define PE_PAR_LATITUDE_OF_ORIGIN  100021 /* PHI0                             */
#define PE_PAR_LATITUDE_OF_CENTER  100022 /* PHIC                             */
#define PE_PAR_LATITUDE_OF_1ST     100023 /* PHI1                             */
#define PE_PAR_LATITUDE_OF_2ND     100024 /* PHI2                             */
#define PE_PAR_STANDARD_PARALLEL_1 100025 /* PHI1                             */
#define PE_PAR_STANDARD_PARALLEL_2 100026 /* PHI2                             */
#define PE_PAR_PSEUDO_STANDARD_PARALLEL_1 100027 /* PHI1                      */

#define PE_PAR_OPTION              100036 /* OPTION                           */
#define PE_PAR_X_SCALE             100037 /* XS                               */
#define PE_PAR_Y_SCALE             100038 /* YS                               */
#define PE_PAR_XY_PLANE_ROTATION   100039 /* XYR                              */

#define PE_PAR_X_AXIS_TRANSLATION  100040 /* DX                               */
#define PE_PAR_Y_AXIS_TRANSLATION  100041 /* DY                               */
#define PE_PAR_Z_AXIS_TRANSLATION  100042 /* DZ                               */
#define PE_PAR_X_AXIS_ROTATION     100043 /* RX                               */
#define PE_PAR_Y_AXIS_ROTATION     100044 /* RY                               */
#define PE_PAR_Z_AXIS_ROTATION     100045 /* RZ                               */
#define PE_PAR_SCALE_DIFFERENCE    100046 /* DS                               */
#define PE_PAR_NAME_DATASET        100047 /* ND                               */
#define PE_PAR_X_COORD_OF_ROTATION_ORIGIN  100048 /* XCR                      */
#define PE_PAR_Y_COORD_OF_ROTATION_ORIGIN  100049 /* YCR                      */
#define PE_PAR_Z_COORD_OF_ROTATION_ORIGIN  100050 /* ZCR                      */

/*----------------------------------------------------------------------------*/
/*                       M A P   P R O J E C T I O N S                        */
/*----------------------------------------------------------------------------*/
#define PE_PRJ_PLATE_CARREE             43001 /* Plate Carree                 */
#define PE_PRJ_EQUIDISTANT_CYLINDRICAL  43002 /* Equidistant Cylindrical      */
#define PE_PRJ_MILLER_CYLINDRICAL       43003 /* Miller Cylindrical           */
#define PE_PRJ_MERCATOR                 43004 /* Mercator                     */
#define PE_PRJ_GAUSS_KRUGER             43005 /* Gauss-Kruger                 */
#define PE_PRJ_TRANSVERSE_MERCATOR      43006 /* Transverse Mercator = 43005  */
#define PE_PRJ_ALBERS                   43007 /* Albers                       */
#define PE_PRJ_SINUSOIDAL               43008 /* Sinusoidal                   */
#define PE_PRJ_MOLLWEIDE                43009 /* Mollweide                    */
#define PE_PRJ_ECKERT_VI                43010 /* Eckert VI                    */
#define PE_PRJ_ECKERT_V                 43011 /* Eckert V                     */
#define PE_PRJ_ECKERT_IV                43012 /* Eckert IV                    */
#define PE_PRJ_ECKERT_III               43013 /* Eckert III                   */
#define PE_PRJ_ECKERT_II                43014 /* Eckert II                    */
#define PE_PRJ_ECKERT_I                 43015 /* Eckert I                     */
#define PE_PRJ_GALL_STEREOGRAPHIC       43016 /* Gall Stereographic           */
#define PE_PRJ_BEHRMANN                 43017 /* Behrmann                     */
#define PE_PRJ_WINKEL_I                 43018 /* Winkel I                     */
#define PE_PRJ_WINKEL_II                43019 /* Winkel II                    */
#define PE_PRJ_LAMBERT_CONFORMAL_CONIC  43020 /* Lambert Conformal Conic      */
#define PE_PRJ_POLYCONIC                43021 /* Polyconic                    */
#define PE_PRJ_QUARTIC_AUTHALIC         43022 /* Quartic Authalic             */
#define PE_PRJ_LOXIMUTHAL               43023 /* Loximuthal                   */
#define PE_PRJ_BONNE                    43024 /* Bonne                        */
#define PE_PRJ_HOTINE_TWO_POINT_NATORIGIN 43025 /* Hotine 2 Pt Natural Origin */
#define PE_PRJ_STEREOGRAPHIC            43026 /* Stereographic                */
#define PE_PRJ_EQUIDISTANT_CONIC        43027 /* Equidistant Conic            */
#define PE_PRJ_CASSINI                  43028 /* Cassini                      */
#define PE_PRJ_VAN_DER_GRINTEN_I        43029 /* Van der Grinten I            */
#define PE_PRJ_ROBINSON                 43030 /* Robinson                     */
#define PE_PRJ_TWO_POINT_EQUIDISTANT    43031 /* Two-Point Equidistant        */
#define PE_PRJ_AZIMUTHAL_EQUIDISTANT    43032 /* Azimuthal Equidistant        */
#define PE_PRJ_LAMBERT_AZIMUTHAL_EQAREA 43033 /* Lambert Azimuthal Equal Area */
#define PE_PRJ_CYLINDRICAL_EQAREA       43034 /* Cylindrical Equal Area       */
#define PE_PRJ_HOTINE_TWO_POINT_CENTER  43035 /* Hotine 2 Point Center        */
#define PE_PRJ_HOTINE_AZIMUTH_NATORIGIN 43036 /* Hotine Azimuth Natural Origin*/
#define PE_PRJ_HOTINE_AZIMUTH_CENTER    43037 /* Hotine Azimuth Center        */
#define PE_PRJ_DOUBLE_STEREOGRAPHIC     43038 /* Double Stereographic         */
#define PE_PRJ_KROVAK                   43039 /* Krovak Oblique Lambert       */
                                              /*        Conformal Conic       */
#define PE_PRJ_NEW_ZEALAND_MAP_GRID     43040 /* New Zealand Map Grid         */
#define PE_PRJ_ORTHOGRAPHIC             43041 /* Orthographic                 */
#define PE_PRJ_WINKEL_TRIPEL            43042 /* Winkel Tripel                */
#define PE_PRJ_AITOFF                   43043 /* Aitoff                       */
#define PE_PRJ_HAMMER_AITOFF            43044 /* Hammer Aitoff                */
#define PE_PRJ_FLAT_POLAR_QUARTIC       43045 /* Flat Polar Quartic           */
#define PE_PRJ_CRASTER_PARABOLIC        43046 /* Craster Parabolic            */
#define PE_PRJ_GNOMONIC                 43047 /* Gnomonic                     */
#define PE_PRJ_TIMES                    43048 /* Bartholomew Times            */
#define PE_PRJ_VERTICAL_NEAR_SIDE_PERSPECTIVE 43049 /* Vertical Near-Side     */
                                                    /*          Perspective   */
#define PE_PRJ_STEREOGRAPHIC_NORTH_POLE 43050 /* Stereographic - North Pole   */
#define PE_PRJ_STEREOGRAPHIC_SOUTH_POLE 43051 /* Stereographic - South Pole   */
#define PE_PRJ_FULLER                   43052 /* Fuller                       */
#define PE_PRJ_RSO_NATORIGIN            43053 /* Rectified Skew Orthomorphic  */
                                              /*  - Natural Origin            */
#define PE_PRJ_RSO_CENTER               43054 /* Rectified Skew Orthomorphic  */
                                              /*  - Center                    */
#define PE_PRJ_CUBE                     43055 /* World on a Cube              */
#define PE_PRJ_TRANSVERSE_MERCATOR_COMPLEX 43056 /* Trans. Mercator Complex   */
#define PE_PRJ_ROBINSON_AI              43057 /* Robinson                     */
                                              /*   from Arc/INFO Workstation  */
#define PE_PRJ_LOCAL                    43058 /* Local                        */

/*----------------------------------------------------------------------------*/
/*          P R O J E C T E D   C O O R D I N A T E   S Y S T E M S           */
/*----------------------------------------------------------------------------*/

/* NEW PCS's at 9.0 ----------------------- */

#define PE_PCS_AIN_EL_ABD_ARAMCO_LAMBERT  2318 /* Ain el Abd Aramco Lambert   */
#define PE_PCS_ALBANIAN_1987_GK_4       2462 /* Albanian 1987 Gauss-K Zone 4  */
#define PE_PCS_AZORES_CENTRAL_1995_UTM_26N  3063 /* Azores Central 1995 UTM Zone 26N  */
#define PE_PCS_AZORES_ORIENTAL_1995_UTM_26N 3062 /* Azores Oriental 1995 UTM Zone 26N */

#define PE_PCS_BATAVIA_TM_109_SE        2308 /* Batavia TM 109 SE             */
#define PE_PCS_BATAVIA_NEIEZ            3001 /* Batavia NEIEZ                 */

/* Beijing 1954 3 Degree Gauss Kruger Zones */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_25 2401 /* Beijing 1954 3-degree GK zone 25 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_26 2402 /* Beijing 1954 3-degree GK zone 26 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_27 2403 /* Beijing 1954 3-degree GK zone 27 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_28 2404 /* Beijing 1954 3-degree GK zone 28 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_29 2405 /* Beijing 1954 3-degree GK zone 29 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_30 2406 /* Beijing 1954 3-degree GK zone 30 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_31 2407 /* Beijing 1954 3-degree GK zone 31 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_32 2408 /* Beijing 1954 3-degree GK zone 32 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_33 2409 /* Beijing 1954 3-degree GK zone 33 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_34 2410 /* Beijing 1954 3-degree GK zone 34 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_35 2411 /* Beijing 1954 3-degree GK zone 35 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_36 2412 /* Beijing 1954 3-degree GK zone 36 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_37 2413 /* Beijing 1954 3-degree GK zone 37 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_38 2414 /* Beijing 1954 3-degree GK zone 38 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_39 2415 /* Beijing 1954 3-degree GK zone 39 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_40 2416 /* Beijing 1954 3-degree GK zone 40 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_41 2417 /* Beijing 1954 3-degree GK zone 41 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_42 2418 /* Beijing 1954 3-degree GK zone 42 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_43 2419 /* Beijing 1954 3-degree GK zone 43 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_44 2420 /* Beijing 1954 3-degree GK zone 44 */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_45 2421 /* Beijing 1954 3-degree GK zone 45 */


/* Beijing 1954 3 Degree Gauss Kruger Central Meridian zones */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_75E  2422 /* Beijing 1954 3-degree GK CM 75E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_78E  2423 /* Beijing 1954 3-degree GK CM 78E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_81E  2424 /* Beijing 1954 3-degree GK CM 81E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_84E  2425 /* Beijing 1954 3-degree GK CM 84E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_87E  2426 /* Beijing 1954 3-degree GK CM 87E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_90E  2427 /* Beijing 1954 3-degree GK CM 90E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_93E  2428 /* Beijing 1954 3-degree GK CM 93E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_96E  2429 /* Beijing 1954 3-degree GK CM 96E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_99E  2430 /* Beijing 1954 3-degree GK CM 99E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_102E 2431 /* Beijing 1954 3-degree GK CM 102E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_105E 2432 /* Beijing 1954 3-degree GK CM 105E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_108E 2433 /* Beijing 1954 3-degree GK CM 108E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_111E 2434 /* Beijing 1954 3-degree GK CM 111E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_114E 2435 /* Beijing 1954 3-degree GK CM 114E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_117E 2436 /* Beijing 1954 3-degree GK CM 117E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_120E 2437 /* Beijing 1954 3-degree GK CM 120E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_123E 2438 /* Beijing 1954 3-degree GK CM 123E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_126E 2439 /* Beijing 1954 3-degree GK CM 126E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_129E 2440 /* Beijing 1954 3-degree GK CM 129E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_132E 2441 /* Beijing 1954 3-degree GK CM 132E */
#define PE_PCS_BEIJING_1954_3_DEGREE_GK_135E 2442 /* Beijing 1954 3-degree GK CM 135E */


#define PE_PCS_CAMPO_INCHAUSPE_UTM_19S  2315 /* Campo Inchauspe UTM zone 19S  */
#define PE_PCS_CAMPO_INCHAUSPE_UTM_20S  2316 /* Campo Inchauspe UTM zone 20S  */
#define PE_PCS_COMBANI_1950_UTM_38S     2980 /* Combani 1950 UTM zone 38S     */
#define PE_PCS_CSG_1967_UTM_22N         2971 /* CSG 1967 UTM zone 22N         */
#define PE_PCS_DOUALA_1948_AOF_WEST     2214 /* Douala 1948 AOF west          */

/*    European Datum 1950 3-degree Gauss-Kruger zones */
#define PE_PCS_ED_1950_3_DEGREE_GK_9    2206 /* ED 1950 3 Degree GK Zone  9   */
#define PE_PCS_ED_1950_3_DEGREE_GK_10   2207 /* ED 1950 3 Degree GK Zone 10   */
#define PE_PCS_ED_1950_3_DEGREE_GK_11   2208 /* ED 1950 3 Degree GK Zone 11   */
#define PE_PCS_ED_1950_3_DEGREE_GK_12   2209 /* ED 1950 3 Degree GK Zone 12   */
#define PE_PCS_ED_1950_3_DEGREE_GK_13   2210 /* ED 1950 3 Degree GK Zone 13   */
#define PE_PCS_ED_1950_3_DEGREE_GK_14   2211 /* ED 1950 3 Degree GK Zone 14   */
#define PE_PCS_ED_1950_3_DEGREE_GK_15   2212 /* ED 1950 3 Degree GK Zone 15   */

#define PE_PCS_ED_1950_FRANCE_EUROLAMBERT 2192 /* ED 1950 France EuroLambert  */

/*    European Datum 1950 Transverse Mercator Central Meridian zones */
#define PE_PCS_ED_1950_TM27             2319 /* ED50 TM27                     */
#define PE_PCS_ED_1950_TM30             2320 /* ED50 TM30                     */
#define PE_PCS_ED_1950_TM33             2321 /* ED50 TM33                     */
#define PE_PCS_ED_1950_TM36             2322 /* ED50 TM36                     */
#define PE_PCS_ED_1950_TM39             2323 /* ED50 TM39                     */
#define PE_PCS_ED_1950_TM42             2324 /* ED50 TM42                     */
#define PE_PCS_ED_1950_TM45             2325 /* ED50 TM45                     */

/*    European Datum 1950 Turkey zones */
#define PE_PCS_ED_1950_TURKEY_9         2181 /* ED 1950 Turkey Zone 9         */
#define PE_PCS_ED_1950_TURKEY_10        2182 /* ED 1950 Turkey Zone 10        */
#define PE_PCS_ED_1950_TURKEY_11        2183 /* ED 1950 Turkey Zone 11        */
#define PE_PCS_ED_1950_TURKEY_12        2184 /* ED 1950 Turkey Zone 12        */
#define PE_PCS_ED_1950_TURKEY_13        2185 /* ED 1950 Turkey Zone 13        */
#define PE_PCS_ED_1950_TURKEY_14        2186 /* ED 1950 Turkey Zone 14        */
#define PE_PCS_ED_1950_TURKEY_15        2187 /* ED 1950 Turkey Zone 15        */

#define PE_PCS_ESTONIA_1997_ESTONIA_GRID  3301 /* EST 1997 Estonia National Grid */

#define PE_PCS_ETRS_1989_KP2000_BORNHOLM 2198 /* ETRS 1989 Kp2000 Bornholm    */
#define PE_PCS_ETRS_1989_KP2000_JUTLAND  2196 /* ETRS 1989 Kp2000 Jutland     */
#define PE_PCS_ETRS_1989_KP2000_ZEALAND  2197 /* ETRS 1989 Kp2000 Zealand     */
#define PE_PCS_ETRS_1989_LAEA  3035 /* ETRS 1989 Lambert Azimuthal Equal Area Coord Ref Sys */
#define PE_PCS_ETRS_1989_LCC   3034 /* ETRS 1989 Lambert Conformal Conic Coord Ref Sys */
#define PE_PCS_ETRS_1989_POLAND_CS2000_5 2176 /* ETRS 1989 Poland CS2000 Zone 5 */
#define PE_PCS_ETRS_1989_POLAND_CS2000_6 2177 /* ETRS 1989 Poland CS2000 Zone 6 */
#define PE_PCS_ETRS_1989_POLAND_CS2000_7 2178 /* ETRS 1989 Poland CS2000 Zone 7 */
#define PE_PCS_ETRS_1989_POLAND_CS2000_8 2179 /* ETRS 1989 Poland CS2000 Zone 8 */
#define PE_PCS_ETRS_1989_POLAND_CS92     2180 /* ETRS 1989 Poland CS92        */
#define PE_PCS_ETRS_1989_TM_30_NE        2213 /* ETRS 1989 TM 30 NE           */

#define PE_PCS_FORT_DESAIX_UTM_20N       2973 /* Fort Desaix UTM zone 20N      */
#define PE_PCS_FORT_MARIGOT_UTM_20N      2969 /* Fort Marigot UTM zone 20N     */
#define PE_PCS_GRAND_COMOROS_UTM_38S     2999 /* Grand Comoros UTM zone 38S    */
#define PE_PCS_GUNUNG_SEGARA_NEIEZ       3000 /* Gunung Segara NEIEZ           */
#define PE_PCS_HELLE_1954_JAN_MAYEN_GRID 3058 /* Helle 1954 Jan Mayen Grid     */
#define PE_PCS_HJORSEY_1955_UTM_26N      3054 /* Hjorsey 1955 UTM Zone 26N     */
#define PE_PCS_HJORSEY_1955_UTM_27N      3055 /* Hjorsey 1955 UTM Zone 27N     */
#define PE_PCS_HJORSEY_1955_UTM_28N      3056 /* Hjorsey 1955 UTM Zone 28N     */
#define PE_PCS_IGM_1995_UTM_32N          3064 /* IGM 1995 UTM Zone 32N         */
#define PE_PCS_IGM_1995_UTM_33N          3065 /* IGM 1995 UTM Zone 33N         */
#define PE_PCS_IGN53_MARE_UTM_58S        2995 /* IGN53 Mare UTM zone 58S       */
#define PE_PCS_IGN56_LIFOU_UTM_58S       2981 /* IGN56 Lifou UTM zone 58S      */
#define PE_PCS_IGN72_GRANDE_TERRE_UTM_58S  2982 /* IGN72 Grande Terre UTM zone 58S */
#define PE_PCS_IGN72_NUKU_HIVA_UTM_7S    2978 /* IGN72 Nuku Hiva UTM zone 7S   */
#define PE_PCS_ISN_1993_LAMBERT_1993     3057 /* ISN 1993 Lambert 1993         */

/*    Japanese Geodetic Datum 2000 */
#define PE_PCS_JGD_2000_JAPAN_1         2443 /* JGD 2000 Japan Zone 1         */
#define PE_PCS_JGD_2000_JAPAN_2         2444 /* JGD 2000 Japan Zone 2         */
#define PE_PCS_JGD_2000_JAPAN_3         2445 /* JGD 2000 Japan Zone 3         */
#define PE_PCS_JGD_2000_JAPAN_4         2446 /* JGD 2000 Japan Zone 4         */
#define PE_PCS_JGD_2000_JAPAN_5         2447 /* JGD 2000 Japan Zone 5         */
#define PE_PCS_JGD_2000_JAPAN_6         2448 /* JGD 2000 Japan Zone 6         */
#define PE_PCS_JGD_2000_JAPAN_7         2449 /* JGD 2000 Japan Zone 7         */
#define PE_PCS_JGD_2000_JAPAN_8         2450 /* JGD 2000 Japan Zone 8         */
#define PE_PCS_JGD_2000_JAPAN_9         2451 /* JGD 2000 Japan Zone 9         */
#define PE_PCS_JGD_2000_JAPAN_10        2452 /* JGD 2000 Japan Zone 10        */
#define PE_PCS_JGD_2000_JAPAN_11        2453 /* JGD 2000 Japan Zone 11        */
#define PE_PCS_JGD_2000_JAPAN_12        2454 /* JGD 2000 Japan Zone 12        */
#define PE_PCS_JGD_2000_JAPAN_13        2455 /* JGD 2000 Japan Zone 13        */
#define PE_PCS_JGD_2000_JAPAN_14        2456 /* JGD 2000 Japan Zone 14        */
#define PE_PCS_JGD_2000_JAPAN_15        2457 /* JGD 2000 Japan Zone 15        */
#define PE_PCS_JGD_2000_JAPAN_16        2458 /* JGD 2000 Japan Zone 16        */
#define PE_PCS_JGD_2000_JAPAN_17        2459 /* JGD 2000 Japan Zone 17        */
#define PE_PCS_JGD_2000_JAPAN_18        2460 /* JGD 2000 Japan Zone 18        */
#define PE_PCS_JGD_2000_JAPAN_19        2461 /* JGD 2000 Japan Zone 19        */

#define PE_PCS_K0_1949_UTM_42S          2979 /* K0 1949 UTM zone 42S          */
#define PE_PCS_KERTAU_RSO_MALAYA_CH    24571 /* Kertau RSO Malaya             */
                                             /*  Chains (Benoit 1895 B)       */
#define PE_PCS_KOUSSERI_UTM_33N         2313 /* Kousseri UTM zone 33N         */
#define PE_PCS_LKS_1992_LATVIA_TM       3059 /* LKS 1992 Latvia TM            */
#define PE_PCS_LUXEMBOURG_1930_GAUSS    2169 /* Luxembourg 1930 Gauss         */
#define PE_PCS_MAKASSAR_NEIEZ           3002 /* Makassar NEIEZ                */
#define PE_PCS_MANOCA_1962_UTM_32N      2215 /* Manoca 1962 UTM Zone 32N      */
#define PE_PCS_MGI_SLOVENIA_GRID        2170 /* MGI Slovenia Grid             */
#define PE_PCS_MOP78_UTM_1S             2988 /* MOP78 UTM zone 1S             */

#define PE_PCS_NAD_1927_ALASKA_ALBERS_FT  2964 /* NAD 1927 Alaska Albers (US Feet) */
#define PE_PCS_NAD_1983_HARN_OREGON_LAMBERT         2993 /* NAD 1983 HARN Oregon Lambert */
#define PE_PCS_NAD_1983_HARN_OREGON_LAMBERT_FT_INTL 2994 /* NAD 1983 HARN Oregon Lambert (Intl Feet) */
#define PE_PCS_NAD_1983_OREGON_LAMBERT         2991 /* NAD 1983 Oregon Lambert */
#define PE_PCS_NAD_1983_OREGON_LAMBERT_FT_INTL 2992 /* NAD 1983 Oregon Lambert (Intl Feet) */

/*    NAD 1983 State Plane Coordinate System (in International Feet)          */
#define PE_PCS_NAD_1983_AZ_E_FT_INTL 2222 /* NAD 1983 SPCS Arizona East (Intl Feet)   */
#define PE_PCS_NAD_1983_AZ_C_FT_INTL 2223 /* NAD 1983 SPCS Arizona Central (Intl Feet)*/
#define PE_PCS_NAD_1983_AZ_W_FT_INTL 2224 /* NAD 1983 SPCS Arizona West (Intl Feet)   */
#define PE_PCS_NAD_1983_MI_N_FT_INTL 2251 /* NAD 1983 SPCS Michigan North (Intl Feet)  */
#define PE_PCS_NAD_1983_MI_C_FT_INTL 2252 /* NAD 1983 SPCS Michigan Central (Intl Feet)*/
#define PE_PCS_NAD_1983_MI_S_FT_INTL 2253 /* NAD 1983 SPCS Michigan South (Intl Feet)  */
#define PE_PCS_NAD_1983_MT_FT_INTL   2256 /* NAD 1983 SPCS Montana (Intl Feet) */
#define PE_PCS_NAD_1983_ND_N_FT_INTL 2265 /* NAD 1983 SPCS North Dakota North (Intl Feet) */
#define PE_PCS_NAD_1983_ND_S_FT_INTL 2266 /* NAD 1983 SPCS North Dakota South (Intl Feet) */
#define PE_PCS_NAD_1983_OR_N_FT_INTL 2269 /* NAD 1983 SPCS Oregon North (Intl Feet) */
#define PE_PCS_NAD_1983_OR_S_FT_INTL 2270 /* NAD 1983 SPCS Oregon South (Intl Feet) */
#define PE_PCS_NAD_1983_SC_FT_INTL   2273 /* NAD 1983 SPCS South Carolina (Intl Feet) */
#define PE_PCS_NAD_1983_UT_N_FT_INTL 2280 /* NAD 1983 SPCS Utah North (Intl Feet)  */
#define PE_PCS_NAD_1983_UT_C_FT_INTL 2281 /* NAD 1983 SPCS Utah Central (Intl Feet)*/
#define PE_PCS_NAD_1983_UT_S_FT_INTL 2282 /* NAD 1983 SPCS Utah South (Intl Feet)  */

/*    NAD 1983 HARN State Plane Coordinate System (in International Feet)     */
#define PE_PCS_NAD_1983_HARN_AZ_E_FT_INTL 2867 /* NAD 1983 HARN SPCS Arizona East (Intl Feet)   */
#define PE_PCS_NAD_1983_HARN_AZ_C_FT_INTL 2868 /* NAD 1983 HARN SPCS Arizona Central (Intl Feet)*/
#define PE_PCS_NAD_1983_HARN_AZ_W_FT_INTL 2869 /* NAD 1983 HARN SPCS Arizona West (Intl Feet)   */
#define PE_PCS_NAD_1983_HARN_MI_N_FT_INTL 2896 /* NAD 1983 HARN SPCS Michigan North (Intl Feet)  */
#define PE_PCS_NAD_1983_HARN_MI_C_FT_INTL 2897 /* NAD 1983 HARN SPCS Michigan Central (Intl Feet)*/
#define PE_PCS_NAD_1983_HARN_MI_S_FT_INTL 2898 /* NAD 1983 HARN SPCS Michigan South (Intl Feet)  */
#define PE_PCS_NAD_1983_HARN_MT_FT_INTL   2901 /* NAD 1983 HARN SPCS Montana (Intl Feet)         */
#define PE_PCS_NAD_1983_HARN_ND_N_FT_INTL 2909 /* NAD 1983 HARN SPCS North Dakota North (Intl Feet) */
#define PE_PCS_NAD_1983_HARN_ND_S_FT_INTL 2910 /* NAD 1983 HARN SPCS North Dakota South (Intl Feet) */
#define PE_PCS_NAD_1983_HARN_OR_N_FT_INTL 2913 /* NAD 1983 HARN SPCS Oregon North (Intl Feet) */
#define PE_PCS_NAD_1983_HARN_OR_S_FT_INTL 2914 /* NAD 1983 HARN SPCS Oregon South (Intl Feet) */
#define PE_PCS_NAD_1983_HARN_UT_N_FT_INTL 2921 /* NAD 1983 HARN SPCS Utah North (Intl Feet)  */
#define PE_PCS_NAD_1983_HARN_UT_C_FT_INTL 2922 /* NAD 1983 HARN SPCS Utah Central (Intl Feet)*/
#define PE_PCS_NAD_1983_HARN_UT_S_FT_INTL 2923 /* NAD 1983 HARN SPCS Utah South (Intl Feet)  */

/*    NAD 1983 HARN State Plane Coordinate System (in US Survey Feet)         */
#define PE_PCS_NAD_1983_HARN_CA_I_FT   2870 /* NAD 1983 HARN SPCS California I (US Feet)     */
#define PE_PCS_NAD_1983_HARN_CA_II_FT  2871 /* NAD 1983 HARN SPCS California II (US Feet)    */
#define PE_PCS_NAD_1983_HARN_CA_III_FT 2872 /* NAD 1983 HARN SPCS California III (US Feet)   */
#define PE_PCS_NAD_1983_HARN_CA_IV_FT  2873 /* NAD 1983 HARN SPCS California IV (US Feet)    */
#define PE_PCS_NAD_1983_HARN_CA_V_FT   2874 /* NAD 1983 HARN SPCS California V (US Feet)     */
#define PE_PCS_NAD_1983_HARN_CA_VI_FT  2875 /* NAD 1983 HARN SPCS California VI (US Feet)    */
#define PE_PCS_NAD_1983_HARN_CO_N_FT   2876 /* NAD 1983 HARN SPCS Colorado North (US Feet)   */
#define PE_PCS_NAD_1983_HARN_CO_C_FT   2877 /* NAD 1983 HARN SPCS Colorado Central (US Feet) */
#define PE_PCS_NAD_1983_HARN_CO_S_FT   2878 /* NAD 1983 HARN SPCS Colorado South (US Feet)   */
#define PE_PCS_NAD_1983_HARN_CT_FT     2879 /* NAD 1983 HARN SPCS Connecticut (US Feet)      */
#define PE_PCS_NAD_1983_HARN_DE_FT     2880 /* NAD 1983 HARN SPCS Delaware (US Feet)         */
#define PE_PCS_NAD_1983_HARN_FL_E_FT   2881 /* NAD 1983 HARN SPCS Florida East (US Feet)     */
#define PE_PCS_NAD_1983_HARN_FL_W_FT   2882 /* NAD 1983 HARN SPCS Florida West (US Feet)     */
#define PE_PCS_NAD_1983_HARN_FL_N_FT   2883 /* NAD 1983 HARN SPCS Florida North (US Feet)    */
#define PE_PCS_NAD_1983_HARN_GA_E_FT   2884 /* NAD 1983 HARN SPCS Georgia East (US Feet)     */
#define PE_PCS_NAD_1983_HARN_GA_W_FT   2885 /* NAD 1983 HARN SPCS Georgia West (US Feet)     */
#define PE_PCS_NAD_1983_HARN_ID_E_FT   2886 /* NAD 1983 HARN SPCS Idaho East (US Feet)       */
#define PE_PCS_NAD_1983_HARN_ID_C_FT   2887 /* NAD 1983 HARN SPCS Idaho Central (US Feet)    */
#define PE_PCS_NAD_1983_HARN_ID_W_FT   2888 /* NAD 1983 HARN SPCS Idaho West (US Feet)       */
#define PE_PCS_NAD_1983_HARN_IN_E_FT   2967 /* NAD 1983 HARN SPCS Indiana East (US Feet)     */
#define PE_PCS_NAD_1983_HARN_IN_W_FT   2968 /* NAD 1983 HARN SPCS Indiana West (US Feet)     */
#define PE_PCS_NAD_1983_HARN_KY_N_FT   2891 /* NAD 1983 HARN SPCS Kentucky North (US Feet)   */
#define PE_PCS_NAD_1983_HARN_KY_S_FT   2892 /* NAD 1983 HARN SPCS Kentucky South (US Feet)   */
#define PE_PCS_NAD_1983_HARN_MD_FT     2893 /* NAD 1983 HARN SPCS Maryland (US Feet)         */
#define PE_PCS_NAD_1983_HARN_MA_M_FT   2894 /* NAD 1983 HARN SPCS Mass. Mainland (US Feet)   */
#define PE_PCS_NAD_1983_HARN_MA_I_FT   2895 /* NAD 1983 HARN SPCS Mass. Island (US Feet)     */
#define PE_PCS_NAD_1983_HARN_MS_E_FT   2899 /* NAD 1983 HARN SPCS Mississippi East (US Feet) */
#define PE_PCS_NAD_1983_HARN_MS_W_FT   2900 /* NAD 1983 HARN SPCS Mississippi West (US Feet) */
#define PE_PCS_NAD_1983_HARN_NM_E_FT   2902 /* NAD 1983 HARN SPCS New Mexico East (US Feet)  */
#define PE_PCS_NAD_1983_HARN_NM_C_FT   2903 /* NAD 1983 HARN SPCS New Mexico Cent. (US Feet) */
#define PE_PCS_NAD_1983_HARN_NM_W_FT   2904 /* NAD 1983 HARN SPCS New Mexico West (US Feet)  */
#define PE_PCS_NAD_1983_HARN_NY_E_FT   2905 /* NAD 1983 HARN SPCS New York East (US Feet)    */
#define PE_PCS_NAD_1983_HARN_NY_C_FT   2906 /* NAD 1983 HARN SPCS New York Central (US Feet) */
#define PE_PCS_NAD_1983_HARN_NY_W_FT   2907 /* NAD 1983 HARN SPCS New York West (US Feet)    */
#define PE_PCS_NAD_1983_HARN_NY_LI_FT  2908 /* NAD 1983 HARN SPCS NY Long Island (US Feet)   */
#define PE_PCS_NAD_1983_HARN_OK_N_FT   2911 /* NAD 1983 HARN SPCS Oklahoma North (US Feet)   */
#define PE_PCS_NAD_1983_HARN_OK_S_FT   2912 /* NAD 1983 HARN SPCS Oklahoma South (US Feet)   */
#define PE_PCS_NAD_1983_HARN_TN_FT     2915 /* NAD 1983 HARN SPCS Tennessee (US Feet)        */
#define PE_PCS_NAD_1983_HARN_TX_N_FT   2916 /* NAD 1983 HARN SPCS Texas North (US Feet)      */
#define PE_PCS_NAD_1983_HARN_TX_NC_FT  2917 /* NAD 1983 HARN SPCS Texas North Cent.(US Feet) */
#define PE_PCS_NAD_1983_HARN_TX_C_FT   2918 /* NAD 1983 HARN SPCS Texas Central (US Feet)    */
#define PE_PCS_NAD_1983_HARN_TX_SC_FT  2919 /* NAD 1983 HARN SPCS Texas South Cent. (US Feet)*/
#define PE_PCS_NAD_1983_HARN_TX_S_FT   2920 /* NAD 1983 HARN SPCS Texas South (US Feet)      */
#define PE_PCS_NAD_1983_HARN_VA_N_FT   2924 /* NAD 1983 HARN SPCS Virginia North (US Feet)   */
#define PE_PCS_NAD_1983_HARN_VA_S_FT   2925 /* NAD 1983 HARN SPCS Virginia South (US Feet)   */
#define PE_PCS_NAD_1983_HARN_WA_N_FT   2926 /* NAD 1983 HARN SPCS Washington North (US Feet) */
#define PE_PCS_NAD_1983_HARN_WA_S_FT   2927 /* NAD 1983 HARN SPCS Washington South (US Feet) */
#define PE_PCS_NAD_1983_HARN_WI_N_FT   2928 /* NAD 1983 HARN SPCS Wisconsin North (US Feet)  */
#define PE_PCS_NAD_1983_HARN_WI_C_FT   2929 /* NAD 1983 HARN SPCS Wisconsin Central (US Feet)*/
#define PE_PCS_NAD_1983_HARN_WI_S_FT   2930 /* NAD 1983 HARN SPCS Wisconsin South (US Feet)  */

#define PE_PCS_NEA74_NOUMEA_UTM_58S     2998 /* NEA74 Noumea UTM zone 58S     */
#define PE_PCS_NZGD_2000_TRANSVERSE_MERCATOR   2193 /* NZGD 2000 Trans Merc   */
#define PE_PCS_OSNI_1952_IRISH_NATIONAL_GRID  29901 /* OSNI 1952 Irish Nat'nl Grid */
#define PE_PCS_PERROUD_1950_TERRE_ADELIE_POLAR_STEREOGRAPHIC  2986  
             /* Pointe Geologie Perroud 1950 Terre Adelie Polar Stereographic */
#define PE_PCS_PETRELS_1972_TERRE_ADELIE_POLAR_STEREOGRAPHIC  2985
                             /* Petrels 1972 Terre Adelie Polar Stereographic */
#define PE_PCS_PITON_DES_NEIGES_TM_REUNION 2990  /* Piton des Neiges TM Reunion */
#define PE_PCS_PORTO_SANTO_1995_UTM_28N 3061 /* Porto Santo 1995 UTM Zone 28N */
#define PE_PCS_PSAD_1956_ICN_REGIONAL   2317 /* PSAD56 ICN Regional           */

/*    Pulkovo 1942 3-Degree Gauss-Kruger Zones */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_7  2523 /* Pulkovo 1942 3-degree GK zone 7  */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_8  2524 /* Pulkovo 1942 3-degree GK zone 8  */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_9  2525 /* Pulkovo 1942 3-degree GK zone 9  */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_10 2526 /* Pulkovo 1942 3-degree GK zone 10 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_11 2527 /* Pulkovo 1942 3-degree GK zone 11 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_12 2528 /* Pulkovo 1942 3-degree GK zone 12 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_13 2529 /* Pulkovo 1942 3-degree GK zone 13 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_14 2530 /* Pulkovo 1942 3-degree GK zone 14 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_15 2531 /* Pulkovo 1942 3-degree GK zone 15 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_16 2532 /* Pulkovo 1942 3-degree GK zone 16 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_17 2533 /* Pulkovo 1942 3-degree GK zone 17 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_18 2534 /* Pulkovo 1942 3-degree GK zone 18 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_19 2535 /* Pulkovo 1942 3-degree GK zone 19 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_20 2536 /* Pulkovo 1942 3-degree GK zone 20 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_21 2537 /* Pulkovo 1942 3-degree GK zone 21 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_22 2538 /* Pulkovo 1942 3-degree GK zone 22 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_23 2539 /* Pulkovo 1942 3-degree GK zone 23 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_24 2540 /* Pulkovo 1942 3-degree GK zone 24 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_25 2541 /* Pulkovo 1942 3-degree GK zone 25 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_26 2542 /* Pulkovo 1942 3-degree GK zone 26 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_27 2543 /* Pulkovo 1942 3-degree GK zone 27 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_28 2544 /* Pulkovo 1942 3-degree GK zone 28 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_29 2545 /* Pulkovo 1942 3-degree GK zone 29 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_30 2546 /* Pulkovo 1942 3-degree GK zone 30 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_31 2547 /* Pulkovo 1942 3-degree GK zone 31 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_32 2548 /* Pulkovo 1942 3-degree GK zone 32 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_33 2549 /* Pulkovo 1942 3-degree GK zone 33 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_34 2551 /* Pulkovo 1942 3-degree GK zone 34 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_35 2552 /* Pulkovo 1942 3-degree GK zone 35 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_36 2553 /* Pulkovo 1942 3-degree GK zone 36 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_37 2554 /* Pulkovo 1942 3-degree GK zone 37 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_38 2555 /* Pulkovo 1942 3-degree GK zone 38 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_39 2556 /* Pulkovo 1942 3-degree GK zone 39 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_40 2557 /* Pulkovo 1942 3-degree GK zone 40 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_41 2558 /* Pulkovo 1942 3-degree GK zone 41 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_42 2559 /* Pulkovo 1942 3-degree GK zone 42 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_43 2560 /* Pulkovo 1942 3-degree GK zone 43 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_44 2561 /* Pulkovo 1942 3-degree GK zone 44 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_45 2562 /* Pulkovo 1942 3-degree GK zone 45 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_46 2563 /* Pulkovo 1942 3-degree GK zone 46 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_47 2564 /* Pulkovo 1942 3-degree GK zone 47 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_48 2565 /* Pulkovo 1942 3-degree GK zone 48 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_49 2566 /* Pulkovo 1942 3-degree GK zone 49 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_50 2567 /* Pulkovo 1942 3-degree GK zone 50 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_51 2568 /* Pulkovo 1942 3-degree GK zone 51 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_52 2569 /* Pulkovo 1942 3-degree GK zone 52 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_53 2570 /* Pulkovo 1942 3-degree GK zone 53 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_54 2571 /* Pulkovo 1942 3-degree GK zone 54 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_55 2572 /* Pulkovo 1942 3-degree GK zone 55 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_56 2573 /* Pulkovo 1942 3-degree GK zone 56 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_57 2574 /* Pulkovo 1942 3-degree GK zone 57 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_58 2575 /* Pulkovo 1942 3-degree GK zone 58 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_59 2576 /* Pulkovo 1942 3-degree GK zone 59 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_60 2577 /* Pulkovo 1942 3-degree GK zone 60 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_61 2578 /* Pulkovo 1942 3-degree GK zone 61 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_62 2579 /* Pulkovo 1942 3-degree GK zone 62 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_63 2580 /* Pulkovo 1942 3-degree GK zone 63 */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_64 2581 /* Pulkovo 1942 3-degree GK zone 64 */

/*    Pulkovo 1942 3-Degree Gauss-Kruger Central Meridian zones */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_21E  2582 /* Pulkovo 1942 3-degree GK CM 21E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_24E  2583 /* Pulkovo 1942 3-degree GK CM 24E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_27E  2584 /* Pulkovo 1942 3-degree GK CM 27E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_30E  2585 /* Pulkovo 1942 3-degree GK CM 30E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_33E  2586 /* Pulkovo 1942 3-degree GK CM 33E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_36E  2587 /* Pulkovo 1942 3-degree GK CM 36E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_39E  2588 /* Pulkovo 1942 3-degree GK CM 39E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_42E  2589 /* Pulkovo 1942 3-degree GK CM 42E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_45E  2590 /* Pulkovo 1942 3-degree GK CM 45E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_48E  2591 /* Pulkovo 1942 3-degree GK CM 48E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_51E  2592 /* Pulkovo 1942 3-degree GK CM 51E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_54E  2593 /* Pulkovo 1942 3-degree GK CM 54E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_57E  2594 /* Pulkovo 1942 3-degree GK CM 57E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_60E  2595 /* Pulkovo 1942 3-degree GK CM 60E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_63E  2596 /* Pulkovo 1942 3-degree GK CM 63E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_66E  2597 /* Pulkovo 1942 3-degree GK CM 66E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_69E  2598 /* Pulkovo 1942 3-degree GK CM 69E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_72E  2599 /* Pulkovo 1942 3-degree GK CM 72E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_75E  2601 /* Pulkovo 1942 3-degree GK CM 75E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_78E  2602 /* Pulkovo 1942 3-degree GK CM 78E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_81E  2603 /* Pulkovo 1942 3-degree GK CM 81E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_84E  2604 /* Pulkovo 1942 3-degree GK CM 84E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_87E  2605 /* Pulkovo 1942 3-degree GK CM 87E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_90E  2606 /* Pulkovo 1942 3-degree GK CM 90E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_93E  2607 /* Pulkovo 1942 3-degree GK CM 93E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_96E  2608 /* Pulkovo 1942 3-degree GK CM 96E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_99E  2609 /* Pulkovo 1942 3-degree GK CM 99E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_102E 2610 /* Pulkovo 1942 3-degree GK CM 102E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_105E 2611 /* Pulkovo 1942 3-degree GK CM 105E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_108E 2612 /* Pulkovo 1942 3-degree GK CM 108E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_111E 2613 /* Pulkovo 1942 3-degree GK CM 111E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_114E 2614 /* Pulkovo 1942 3-degree GK CM 114E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_117E 2615 /* Pulkovo 1942 3-degree GK CM 117E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_120E 2616 /* Pulkovo 1942 3-degree GK CM 120E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_123E 2617 /* Pulkovo 1942 3-degree GK CM 123E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_126E 2618 /* Pulkovo 1942 3-degree GK CM 126E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_129E 2619 /* Pulkovo 1942 3-degree GK CM 129E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_132E 2620 /* Pulkovo 1942 3-degree GK CM 132E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_135E 2621 /* Pulkovo 1942 3-degree GK CM 135E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_138E 2622 /* Pulkovo 1942 3-degree GK CM 138E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_141E 2623 /* Pulkovo 1942 3-degree GK CM 141E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_144E 2624 /* Pulkovo 1942 3-degree GK CM 144E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_147E 2625 /* Pulkovo 1942 3-degree GK CM 147E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_150E 2626 /* Pulkovo 1942 3-degree GK CM 150E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_153E 2627 /* Pulkovo 1942 3-degree GK CM 153E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_156E 2628 /* Pulkovo 1942 3-degree GK CM 156E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_159E 2629 /* Pulkovo 1942 3-degree GK CM 159E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_162E 2630 /* Pulkovo 1942 3-degree GK CM 162E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_165E 2631 /* Pulkovo 1942 3-degree GK CM 165E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_168E 2632 /* Pulkovo 1942 3-degree GK CM 168E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_171E 2633 /* Pulkovo 1942 3-degree GK CM 171E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_174E 2634 /* Pulkovo 1942 3-degree GK CM 174E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_177E 2635 /* Pulkovo 1942 3-degree GK CM 177E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_180E 2636 /* Pulkovo 1942 3-degree GK CM 180E */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_177W 2637 /* Pulkovo 1942 3-degree GK CM 177W */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_174W 2638 /* Pulkovo 1942 3-degree GK CM 174W */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_171W 2639 /* Pulkovo 1942 3-degree GK CM 171W */
#define PE_PCS_PULKOVO_1942_3_DEG_GK_168W 2640 /* Pulkovo 1942 3-degree GK CM 168W */

#define PE_PCS_PULKOVO_1942_ADJ_1983_3_DEG_GK_3 2166 /* Pulkovo 1942(83) 3-Degree GK zone 3 */
#define PE_PCS_PULKOVO_1942_ADJ_1983_3_DEG_GK_4 2167 /* Pulkovo 1942(83) 3-Degree GK zone 4 */
#define PE_PCS_PULKOVO_1942_ADJ_1983_3_DEG_GK_5 2168 /* Pulkovo 1942(83) 3-Degree GK zone 5 */

/*    Pulkovo 1995 3-Degree Gauss-Kruger zones */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_7  2641 /* Pulkovo 1995 3-degree GK zone 7 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_8  2642 /* Pulkovo 1995 3-degree GK zone 8 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_9  2643 /* Pulkovo 1995 3-degree GK zone 9 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_10 2644 /* Pulkovo 1995 3-degree GK zone 10 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_11 2645 /* Pulkovo 1995 3-degree GK zone 11 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_12 2646 /* Pulkovo 1995 3-degree GK zone 12 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_13 2647 /* Pulkovo 1995 3-degree GK zone 13 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_14 2648 /* Pulkovo 1995 3-degree GK zone 14 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_15 2649 /* Pulkovo 1995 3-degree GK zone 15 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_16 2650 /* Pulkovo 1995 3-degree GK zone 16 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_17 2651 /* Pulkovo 1995 3-degree GK zone 17 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_18 2652 /* Pulkovo 1995 3-degree GK zone 18 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_19 2653 /* Pulkovo 1995 3-degree GK zone 19 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_20 2654 /* Pulkovo 1995 3-degree GK zone 20 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_21 2655 /* Pulkovo 1995 3-degree GK zone 21 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_22 2656 /* Pulkovo 1995 3-degree GK zone 22 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_23 2657 /* Pulkovo 1995 3-degree GK zone 23 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_24 2658 /* Pulkovo 1995 3-degree GK zone 24 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_25 2659 /* Pulkovo 1995 3-degree GK zone 25 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_26 2660 /* Pulkovo 1995 3-degree GK zone 26 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_27 2661 /* Pulkovo 1995 3-degree GK zone 27 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_28 2662 /* Pulkovo 1995 3-degree GK zone 28 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_29 2663 /* Pulkovo 1995 3-degree GK zone 29 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_30 2664 /* Pulkovo 1995 3-degree GK zone 30 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_31 2665 /* Pulkovo 1995 3-degree GK zone 31 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_32 2666 /* Pulkovo 1995 3-degree GK zone 32 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_33 2667 /* Pulkovo 1995 3-degree GK zone 33 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_34 2668 /* Pulkovo 1995 3-degree GK zone 34 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_35 2669 /* Pulkovo 1995 3-degree GK zone 35 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_36 2670 /* Pulkovo 1995 3-degree GK zone 36 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_37 2671 /* Pulkovo 1995 3-degree GK zone 37 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_38 2672 /* Pulkovo 1995 3-degree GK zone 38 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_39 2673 /* Pulkovo 1995 3-degree GK zone 39 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_40 2674 /* Pulkovo 1995 3-degree GK zone 40 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_41 2675 /* Pulkovo 1995 3-degree GK zone 41 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_42 2676 /* Pulkovo 1995 3-degree GK zone 42 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_43 2677 /* Pulkovo 1995 3-degree GK zone 43 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_44 2678 /* Pulkovo 1995 3-degree GK zone 44 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_45 2679 /* Pulkovo 1995 3-degree GK zone 45 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_46 2680 /* Pulkovo 1995 3-degree GK zone 46 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_47 2681 /* Pulkovo 1995 3-degree GK zone 47 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_48 2682 /* Pulkovo 1995 3-degree GK zone 48 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_49 2683 /* Pulkovo 1995 3-degree GK zone 49 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_50 2684 /* Pulkovo 1995 3-degree GK zone 50 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_51 2685 /* Pulkovo 1995 3-degree GK zone 51 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_52 2686 /* Pulkovo 1995 3-degree GK zone 52 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_53 2687 /* Pulkovo 1995 3-degree GK zone 53 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_54 2688 /* Pulkovo 1995 3-degree GK zone 54 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_55 2689 /* Pulkovo 1995 3-degree GK zone 55 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_56 2690 /* Pulkovo 1995 3-degree GK zone 56 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_57 2691 /* Pulkovo 1995 3-degree GK zone 57 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_58 2692 /* Pulkovo 1995 3-degree GK zone 58 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_59 2693 /* Pulkovo 1995 3-degree GK zone 59 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_60 2694 /* Pulkovo 1995 3-degree GK zone 60 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_61 2695 /* Pulkovo 1995 3-degree GK zone 61 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_62 2696 /* Pulkovo 1995 3-degree GK zone 62 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_63 2697 /* Pulkovo 1995 3-degree GK zone 63 */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_64 2698 /* Pulkovo 1995 3-degree GK zone 64 */

/*    Pulkovo 1995 3-Degree Gauss-Kruger Central Meridian zones */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_21E  2699 /* Pulkovo 1995 3-degree GK CM 21E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_24E  2700 /* Pulkovo 1995 3-degree GK CM 24E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_27E  2701 /* Pulkovo 1995 3-degree GK CM 27E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_30E  2702 /* Pulkovo 1995 3-degree GK CM 30E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_33E  2703 /* Pulkovo 1995 3-degree GK CM 33E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_36E  2704 /* Pulkovo 1995 3-degree GK CM 36E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_39E  2705 /* Pulkovo 1995 3-degree GK CM 39E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_42E  2706 /* Pulkovo 1995 3-degree GK CM 42E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_45E  2707 /* Pulkovo 1995 3-degree GK CM 45E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_48E  2708 /* Pulkovo 1995 3-degree GK CM 48E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_51E  2709 /* Pulkovo 1995 3-degree GK CM 51E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_54E  2710 /* Pulkovo 1995 3-degree GK CM 54E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_57E  2711 /* Pulkovo 1995 3-degree GK CM 57E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_60E  2712 /* Pulkovo 1995 3-degree GK CM 60E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_63E  2713 /* Pulkovo 1995 3-degree GK CM 63E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_66E  2714 /* Pulkovo 1995 3-degree GK CM 66E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_69E  2715 /* Pulkovo 1995 3-degree GK CM 69E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_72E  2716 /* Pulkovo 1995 3-degree GK CM 72E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_75E  2717 /* Pulkovo 1995 3-degree GK CM 75E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_78E  2718 /* Pulkovo 1995 3-degree GK CM 78E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_81E  2719 /* Pulkovo 1995 3-degree GK CM 81E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_84E  2720 /* Pulkovo 1995 3-degree GK CM 84E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_87E  2721 /* Pulkovo 1995 3-degree GK CM 87E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_90E  2722 /* Pulkovo 1995 3-degree GK CM 90E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_93E  2723 /* Pulkovo 1995 3-degree GK CM 93E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_96E  2724 /* Pulkovo 1995 3-degree GK CM 96E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_99E  2725 /* Pulkovo 1995 3-degree GK CM 99E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_102E 2726 /* Pulkovo 1995 3-degree GK CM 102E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_105E 2727 /* Pulkovo 1995 3-degree GK CM 105E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_108E 2728 /* Pulkovo 1995 3-degree GK CM 108E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_111E 2729 /* Pulkovo 1995 3-degree GK CM 111E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_114E 2730 /* Pulkovo 1995 3-degree GK CM 114E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_117E 2731 /* Pulkovo 1995 3-degree GK CM 117E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_120E 2732 /* Pulkovo 1995 3-degree GK CM 120E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_123E 2733 /* Pulkovo 1995 3-degree GK CM 123E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_126E 2734 /* Pulkovo 1995 3-degree GK CM 126E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_129E 2735 /* Pulkovo 1995 3-degree GK CM 129E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_132E 2738 /* Pulkovo 1995 3-degree GK CM 132E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_135E 2739 /* Pulkovo 1995 3-degree GK CM 135E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_138E 2740 /* Pulkovo 1995 3-degree GK CM 138E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_141E 2741 /* Pulkovo 1995 3-degree GK CM 141E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_144E 2742 /* Pulkovo 1995 3-degree GK CM 144E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_147E 2743 /* Pulkovo 1995 3-degree GK CM 147E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_150E 2744 /* Pulkovo 1995 3-degree GK CM 150E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_153E 2745 /* Pulkovo 1995 3-degree GK CM 153E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_156E 2746 /* Pulkovo 1995 3-degree GK CM 156E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_159E 2747 /* Pulkovo 1995 3-degree GK CM 159E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_162E 2748 /* Pulkovo 1995 3-degree GK CM 162E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_165E 2749 /* Pulkovo 1995 3-degree GK CM 165E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_168E 2750 /* Pulkovo 1995 3-degree GK CM 168E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_168W 2758 /* Pulkovo 1995 3-degree GK CM 168W */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_171E 2751 /* Pulkovo 1995 3-degree GK CM 171E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_174E 2752 /* Pulkovo 1995 3-degree GK CM 174E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_177E 2753 /* Pulkovo 1995 3-degree GK CM 177E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_180E 2754 /* Pulkovo 1995 3-degree GK CM 180E */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_177W 2755 /* Pulkovo 1995 3-degree GK CM 177W */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_174W 2756 /* Pulkovo 1995 3-degree GK CM 174W */
#define PE_PCS_PULKOVO_1995_3_DEG_GK_171W 2757 /* Pulkovo 1995 3-degree GK CM 171W */

#define PE_PCS_QORNOQ_1927_UTM_22N      2216 /* Qornoq 1927 UTM Zone 22N      */
#define PE_PCS_QORNOQ_1927_UTM_23N      2217 /* Qornoq 1927 UTM Zone 23N      */
#define PE_PCS_RASSADIRAN_NAKHL_E_TAQI  2057 /* Rassadiran Nakhl e Taqi       */
#define PE_PCS_REGVEN_UTM_18N           2201 /* REGVEN UTM Zone 18N           */
#define PE_PCS_REGVEN_UTM_19N           2202 /* REGVEN UTM Zone 19N           */
#define PE_PCS_REGVEN_UTM_20N           2203 /* REGVEN UTM Zone 20N           */
#define PE_PCS_RGFG_1995_UTM_22N        2972 /* RGFG95 UTM zone 22N           */
#define PE_PCS_RGNC_1991_LAMBERT_NEW_CALEDONIA  2984 /* RGNC 1991 Lambert New Caledonia */
#define PE_PCS_RGR_1992_UTM_40S         2975 /* RGR92 UTM zone 40S            */
#define PE_PCS_RRAF_1991_UTM_20N        2989 /* RRAF 1991 UTM zone 20N        */

#define PE_PCS_RT90_75_GON_V            3019 /* RT90 7.5 gon V                */
#define PE_PCS_RT90_5_GON_V             3020 /* RT90 5   gon V                */
#define PE_PCS_RT90_25_GON_V            3021 /* RT90 2.5 gon V                */
#define PE_PCS_RT90_0_GON               3022 /* RT90 0   gon                  */
#define PE_PCS_RT90_25_GON_O            3023 /* RT90 2.5 gon O                */
#define PE_PCS_RT90_5_GON_O             3024 /* RT90 5   gon O                */
#define PE_PCS_RT38_75_GON_V            3025 /* RT90 7.5 gon V                */
#define PE_PCS_RT38_5_GON_V             3026 /* RT90 5   gon V                */
#define PE_PCS_RT38_25_GON_V            3027 /* RT90 2.5 gon V                */
#define PE_PCS_RT38_0_GON               3028 /* RT90 0   gon                  */
#define PE_PCS_RT38_25_GON_O            3029 /* RT90 2.5 gon O                */
#define PE_PCS_RT38_5_GON_O             3030 /* RT90 5   gon O                */

#define PE_PCS_SAINTE_ANNE_UTM_20N      2970 /* Sainte Anne UTM zone 20N      */
#define PE_PCS_SAINT_PIERRE_ET_MIQUELON_1950_UTM_21N  2987 /* Saint Pierre et */
                                                /* Miquelon 1950 UTM zone 21N */
#define PE_PCS_ST71_BELEP_UTM_58S       2997 /* ST71 Belep UTM zone 58S       */
#define PE_PCS_ST84_ILE_DES_PINS_UTM_58S  2996 /* ST84 Ile des Pins UTM zone 58S */
#define PE_PCS_ST87_OUVEA_UTM_58S       2983 /* ST87 Ouvea UTM zone 58S       */

#define PE_PCS_SWEREF99_TM              3006 /* SWEREF99 TM                   */
#define PE_PCS_SWEREF99_12_00           3007 /* SWEREF99 12 00                */
#define PE_PCS_SWEREF99_13_30           3008 /* SWEREF99 13 30                */
#define PE_PCS_SWEREF99_15_00           3009 /* SWEREF99 15 00                */
#define PE_PCS_SWEREF99_16_30           3010 /* SWEREF99 16 30                */
#define PE_PCS_SWEREF99_18_00           3011 /* SWEREF99 18 00                */
#define PE_PCS_SWEREF99_14_15           3012 /* SWEREF99 14 15                */
#define PE_PCS_SWEREF99_15_45           3013 /* SWEREF99 15 45                */
#define PE_PCS_SWEREF99_17_15           3014 /* SWEREF99 17 15                */
#define PE_PCS_SWEREF99_18_45           3015 /* SWEREF99 18 45                */
#define PE_PCS_SWEREF99_20_15           3016 /* SWEREF99 20 15                */
#define PE_PCS_SWEREF99_21_45           3017 /* SWEREF99 21 45                */
#define PE_PCS_SWEREF99_23_15           3018 /* SWEREF99 23 15                */

#define PE_PCS_TAHAA_UTM_5S             2977 /* Tahaa UTM zone 5S             */
#define PE_PCS_TAHITI_UTM_6S            2976 /* Tahiti UTM zone 6S            */
#define PE_PCS_TIMBALAI_1948_RSO_BORNEO_CH 29871 /* Timbalai 1948 RSO Borneo  */
                                                 /*  Chains (Sears)           */
#define PE_PCS_TIMBALAI_1948_RSO_BORNEO_FT 29872 /* Timbalai 1948 RSO Borneo  */
                                                 /*  Feet   (Sears)           */
#define PE_PCS_TIMBALAI_1948_RSO_BORNEO_M  29873 /* Timbalai 1948 RSO Borneo  */
                                                 /*  Meters                   */
#define PE_PCS_TM75_IRISH_GRID         29903 /* TM75 Irish Grid               */
#define PE_PCS_TRINIDAD_1903_TRINIDAD_GRID_FT_CLA  2314 /* Trinidad 1903 Trinidad Grid (ftCla) */
#define PE_PCS_WGS_1984_ANTARCTIC_P_STEREO            3031 /* WGS 1984 Antarctic Polar Stereographic */
#define PE_PCS_WGS_1984_AUSTRALIAN_ANTARCTIC_P_STEREO 3032 /* WGS 1984 Australian Antarctic Polar Stereo */
#define PE_PCS_WGS_1984_AUSTRALIAN_ANTARCTIC_LAMBERT  3033 /* WGS 1984 Australian Antarctic Lambert */
#define PE_PCS_WGS_1984_TM_116_SE       2309 /* WGS 84 TM 116 SE              */
#define PE_PCS_WGS_1984_TM_132_SE       2310 /* WGS 84 TM 132 SE              */
#define PE_PCS_WGS_1984_TM_6_NE         2311 /* WGS 84 TM 6 NE                */

/*    Xian 1980 Gauss-Kruger zones */
#define PE_PCS_XIAN_1980_GK_13         2327 /* Xian 1980 Gauss-Kruger zone 13 */
#define PE_PCS_XIAN_1980_GK_14         2328 /* Xian 1980 Gauss-Kruger zone 14 */
#define PE_PCS_XIAN_1980_GK_15         2329 /* Xian 1980 Gauss-Kruger zone 15 */
#define PE_PCS_XIAN_1980_GK_16         2330 /* Xian 1980 Gauss-Kruger zone 16 */
#define PE_PCS_XIAN_1980_GK_17         2331 /* Xian 1980 Gauss-Kruger zone 17 */
#define PE_PCS_XIAN_1980_GK_18         2332 /* Xian 1980 Gauss-Kruger zone 18 */
#define PE_PCS_XIAN_1980_GK_19         2333 /* Xian 1980 Gauss-Kruger zone 19 */
#define PE_PCS_XIAN_1980_GK_20         2334 /* Xian 1980 Gauss-Kruger zone 20 */
#define PE_PCS_XIAN_1980_GK_21         2335 /* Xian 1980 Gauss-Kruger zone 21 */
#define PE_PCS_XIAN_1980_GK_22         2336 /* Xian 1980 Gauss-Kruger zone 22 */
#define PE_PCS_XIAN_1980_GK_23         2337 /* Xian 1980 Gauss-Kruger zone 23 */

/*    Xian 1980 Gauss-Kruger Central Meridian zones */
#define PE_PCS_XIAN_1980_GK_75E        2338 /* Xian 1980 Gauss-Kruger CM  75E */
#define PE_PCS_XIAN_1980_GK_81E        2339 /* Xian 1980 Gauss-Kruger CM  81E */
#define PE_PCS_XIAN_1980_GK_87E        2340 /* Xian 1980 Gauss-Kruger CM  87E */
#define PE_PCS_XIAN_1980_GK_93E        2341 /* Xian 1980 Gauss-Kruger CM  93E */
#define PE_PCS_XIAN_1980_GK_99E        2342 /* Xian 1980 Gauss-Kruger CM  99E */
#define PE_PCS_XIAN_1980_GK_105E       2343 /* Xian 1980 Gauss-Kruger CM 105E */
#define PE_PCS_XIAN_1980_GK_111E       2344 /* Xian 1980 Gauss-Kruger CM 111E */
#define PE_PCS_XIAN_1980_GK_117E       2345 /* Xian 1980 Gauss-Kruger CM 117E */
#define PE_PCS_XIAN_1980_GK_123E       2346 /* Xian 1980 Gauss-Kruger CM 123E */
#define PE_PCS_XIAN_1980_GK_129E       2347 /* Xian 1980 Gauss-Kruger CM 129E */
#define PE_PCS_XIAN_1980_GK_135E       2348 /* Xian 1980 Gauss-Kruger CM 135E */

/*    Xian 1980 3-degree Gauss-Kruger zones */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_25 2349 /* Xian 1980 3-degree GK zone 25 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_26 2350 /* Xian 1980 3-degree GK zone 26 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_27 2351 /* Xian 1980 3-degree GK zone 27 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_28 2352 /* Xian 1980 3-degree GK zone 28 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_29 2353 /* Xian 1980 3-degree GK zone 29 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_30 2354 /* Xian 1980 3-degree GK zone 30 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_31 2355 /* Xian 1980 3-degree GK zone 31 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_32 2356 /* Xian 1980 3-degree GK zone 32 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_33 2357 /* Xian 1980 3-degree GK zone 33 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_34 2358 /* Xian 1980 3-degree GK zone 34 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_35 2359 /* Xian 1980 3-degree GK zone 35 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_36 2360 /* Xian 1980 3-degree GK zone 36 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_37 2361 /* Xian 1980 3-degree GK zone 37 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_38 2362 /* Xian 1980 3-degree GK zone 38 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_39 2363 /* Xian 1980 3-degree GK zone 39 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_40 2364 /* Xian 1980 3-degree GK zone 40 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_41 2365 /* Xian 1980 3-degree GK zone 41 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_42 2366 /* Xian 1980 3-degree GK zone 42 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_43 2367 /* Xian 1980 3-degree GK zone 43 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_44 2368 /* Xian 1980 3-degree GK zone 44 */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_45 2369 /* Xian 1980 3-degree GK zone 45 */

/*    Xian 1980 3-degree Gauss-Kruger Central Meridian zones */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_75E  2370 /* Xian 1980 3-degree GK CM  75E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_78E  2371 /* Xian 1980 3-degree GK CM  78E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_81E  2372 /* Xian 1980 3-degree GK CM  81E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_84E  2373 /* Xian 1980 3-degree GK CM  84E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_87E  2374 /* Xian 1980 3-degree GK CM  87E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_90E  2375 /* Xian 1980 3-degree GK CM  90E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_93E  2376 /* Xian 1980 3-degree GK CM  93E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_96E  2377 /* Xian 1980 3-degree GK CM  96E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_99E  2378 /* Xian 1980 3-degree GK CM  99E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_102E 2379 /* Xian 1980 3-degree GK CM 102E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_105E 2380 /* Xian 1980 3-degree GK CM 105E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_108E 2381 /* Xian 1980 3-degree GK CM 108E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_111E 2382 /* Xian 1980 3-degree GK CM 111E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_114E 2383 /* Xian 1980 3-degree GK CM 114E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_117E 2384 /* Xian 1980 3-degree GK CM 117E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_120E 2385 /* Xian 1980 3-degree GK CM 120E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_123E 2386 /* Xian 1980 3-degree GK CM 123E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_126E 2387 /* Xian 1980 3-degree GK CM 126E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_129E 2388 /* Xian 1980 3-degree GK CM 129E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_132E 2389 /* Xian 1980 3-degree GK CM 132E */
#define PE_PCS_XIAN_1980_3_DEGREE_GK_135E 2390 /* Xian 1980 3-degree GK CM 135E */

#define PE_PCS_AGD_1966_ACT_GRID_AGC  102071 /* AGD 1966 ACT Grid AGC Zone    */
#define PE_PCS_AGD_1966_ISG_54_2      102072 /* AGD 1966 NSW ISG Zone 54 / 2  */
#define PE_PCS_AGD_1966_ISG_54_3      102073 /* AGD 1966 NSW ISG Zone 54 / 3  */
#define PE_PCS_AGD_1966_ISG_55_1      102074 /* AGD 1966 NSW ISG Zone 55 / 1  */
#define PE_PCS_AGD_1966_ISG_55_2      102075 /* AGD 1966 NSW ISG Zone 55 / 2  */
#define PE_PCS_AGD_1966_ISG_55_3      102076 /* AGD 1966 NSW ISG Zone 55 / 3  */
#define PE_PCS_AGD_1966_ISG_56_1      102077 /* AGD 1966 NSW ISG Zone 56 / 1  */
#define PE_PCS_AGD_1966_ISG_56_2      102078 /* AGD 1966 NSW ISG Zone 56 / 2  */
#define PE_PCS_AGD_1966_ISG_56_3      102079 /* AGD 1966 NSW ISG Zone 56 / 3  */
#define PE_PCS_BERMUDA_2000_NATIONAL_GRID 102090 /* Bermuda 2000 National Grid*/

#define PE_PCS_CHATHAM_ISLANDS_1979_MAP_GRID   102111 /* Chatham Islands 1979 Map Grid */
#define PE_PCS_EMEP_50KM              102068 /* EMEP  50 Kilometer Grid       */
#define PE_PCS_EMEP_150KM             102069 /* EMEP 150 kilometer Grid       */
#define PE_PCS_ETRS_1989_UTM_26N      102097 /* ETRS 1989 UTM Zone 26N        */
#define PE_PCS_ETRS_1989_UTM_27N      102098 /* ETRS 1989 UTM Zone 27N        */
#define PE_PCS_ETRS_1989_UTM_39N      102099 /* ETRS 1989 UTM Zone 29N        */
#define PE_PCS_ETRS_1989_UWPP_1992        102173 /* ETRS 1989 Poland 1992     */
#define PE_PCS_ETRS_1989_UWPP_2000_PAS_5  102174 /* ETRS 1989 Poland zone 5   */
#define PE_PCS_ETRS_1989_UWPP_2000_PAS_6  102175 /* ETRS 1989 Poland zone 6   */
#define PE_PCS_ETRS_1989_UWPP_2000_PAS_7  102176 /* ETRS 1989 Poland zone 7   */
#define PE_PCS_ETRS_1989_UWPP_2000_PAS_8  102177 /* ETRS 1989 Poland zone 8   */
#define PE_PCS_EUREF_FIN_TM35FIN      102139 /* EUREF Finland UTM 35N         */
#define PE_PCS_EVEREST_MOD_1969_RSO_MALAYA_M  102061 /* Everest Modified 1969 */
#define PE_PCS_GUERNSEY_GRID          102070 /* Isle of Guernsey              */
#define PE_PCS_KANDAWALA_CEYLON_BELT_M  102063 /* Kandawala Ceylon Belt Meters*/
#define PE_PCS_KANDAWALA_CEYLON_BELT_YD1937  102064 /* Kandawala Ceylon Belt  */
                                                    /*  Indian Yards 1937     */
#define PE_PCS_KERTAU_RSO_MALAYA_M    102062 /* Kertau RSO Malaya Meters      */
#define PE_PCS_JGD_2000_UTM_51N       102145 /* JGD 2000 UTM Zone 51N         */
#define PE_PCS_JGD_2000_UTM_52N       102146 /* JGD 2000 UTM Zone 52N         */
#define PE_PCS_JGD_2000_UTM_53N       102147 /* JGD 2000 UTM Zone 53N         */
#define PE_PCS_JGD_2000_UTM_54N       102148 /* JGD 2000 UTM Zone 54N         */
#define PE_PCS_JGD_2000_UTM_55N       102149 /* JGD 2000 UTM Zone 55N         */
#define PE_PCS_JGD_2000_UTM_56N       102150 /* JGD 2000 UTM Zone 56N         */
#define PE_PCS_JORDAN_JTM             102158 /* Jordan Transverse Mercator    */

#define PE_PCS_NAD_1927_ALASKA_ALBERS_METERS  102117 /* NAD 1927 Alaska Albers (Meters) */
#define PE_PCS_NAD_1927_GEORGIA_ALBERS  102118 /* NAD 1927 Georgia Statewide Albers  */
#define PE_PCS_NAD_1927_TEXAS_STATEWIDE 102119 /* NAD 1927 Texas Statewide    */

#define PE_PCS_NAD_1927_UTM_1N        102124 /* NAD 1927 UTM Zone 1N          */
#define PE_PCS_NAD_1927_UTM_2N        102125 /* NAD 1927 UTM Zone 2N          */
#define PE_PCS_NAD_1927_UTM_59N       102126 /* NAD 1927 UTM Zone 59N         */
#define PE_PCS_NAD_1927_UTM_60N       102127 /* NAD 1927 UTM Zone 60N         */
#define PE_PCS_NAD_1983_GEORGIA_LAMBERT 102604 /* NAD 1983 Georgia Statewide Lambert */
#define PE_PCS_NAD_1983_HARN_HI_1_FT  102461 /* NAD 1983 HARN SPCS Hawaii Zone 1 (US Feet) */
#define PE_PCS_NAD_1983_HARN_HI_2_FT  102462 /* NAD 1983 HARN SPCS Hawaii Zone 2 (US Feet) */
#define PE_PCS_NAD_1983_HARN_HI_3_FT  102463 /* NAD 1983 HARN SPCS Hawaii Zone 3 (US Feet) */
#define PE_PCS_NAD_1983_HARN_HI_4_FT  102464 /* NAD 1983 HARN SPCS Hawaii Zone 4 (US Feet) */
#define PE_PCS_NAD_1983_HARN_HI_5_FT  102465 /* NAD 1983 HARN SPCS Hawaii Zone 5 (US Feet) */
#define PE_PCS_NAD_1983_HARN_MAINE_2000_EAST    102208 /* NAD 1983 HARN Maine 2000 East Zone    */
#define PE_PCS_NAD_1983_HARN_MAINE_2000_CENTRAL 102209 /* NAD 1983 HARN Maine 2000 Central Zone */
#define PE_PCS_NAD_1983_HARN_MAINE_2000_WEST    102210 /* NAD 1983 HARN Maine 2000 West Zone    */
#define PE_PCS_NAD_1983_HARN_UTM_4N   102202 /* NAD 1983 (HARN) UTM zone  4N  */
#define PE_PCS_NAD_1983_HARN_UTM_5N   102203 /* NAD 1983 (HARN) UTM zone  5N  */
#define PE_PCS_NAD_1983_HARN_UTM_11N  102205 /* NAD 1983 (HARN) UTM zone 11N  */
#define PE_PCS_NAD_1983_HARN_UTM_12N  102206 /* NAD 1983 (HARN) UTM zone 12N  */
#define PE_PCS_NAD_1983_HARN_UTM_13N  102207 /* NAD 1983 (HARN) UTM zone 13N  */
#define PE_PCS_NAD_1983_HARN_UTM_18N  102211 /* NAD 1983 (HARN) UTM zone 18N  */
#define PE_PCS_NAD_1983_IDAHO_TM  102605 /* NAD 1983 Idaho Transverse Mercator*/
#define PE_PCS_NAD_1983_MAINE_2000_EAST    102606 /* NAD 1983 Maine 2000 East Zone    */
#define PE_PCS_NAD_1983_MAINE_2000_CENTRAL 102607 /* NAD 1983 Maine 2000 Central Zone */
#define PE_PCS_NAD_1983_MAINE_2000_WEST    102608 /* NAD 1983 Maine 2000 West Zone    */
#define PE_PCS_NAD_1983_TEXAS_CENTRIC_ALBERS  102601 /* NAD 1983 Texas Centric*/
                                                     /* Mapping System Albers */
#define PE_PCS_NAD_1983_TEXAS_CENTRIC_LAMBERT 102602 /* NAD 1983 Texas Centric*/
                                                     /* Mapping System Lambert*/
#define PE_PCS_NAD_1983_TEXAS_STATEWIDE  102603 /* NAD 1983 Texas Statewide   */
                                                /* Mapping System             */
#define PE_PCS_NAD_1983_UTM_1N        102128 /* NAD 1983 UTM Zone 1N          */
#define PE_PCS_NAD_1983_UTM_2N        102129 /* NAD 1983 UTM Zone 2N          */
#define PE_PCS_NAD_1983_UTM_59N       102130 /* NAD 1983 UTM Zone 59N         */
#define PE_PCS_NAD_1983_UTM_60N       102131 /* NAD 1983 UTM Zone 60N         */
#define PE_PCS_NZGD_2000_CHATHAM_ISLAND_CIRCUIT 102112 /* NZGD2000 Chatham Island Circuit */
#define PE_PCS_OBSERV_METEOR_1965_MACAU_GRID 102159 /* Observ Meterologico 1965 Macau Grid */
#define PE_PCS_ROMA_1940_GAUSS_BOAGA_EST   102093 /* Roma 1940 Gauss Boaga Est*/
#define PE_PCS_ROMA_1940_GAUSS_BOAGA_OVEST 102094 /* Roma 1940 Gauss Boaga Ovest*/
#define PE_PCS_SAMOA_1962_UTM_2S    102116 /* American Samoa 1962 UTM zone 2S */

#define PE_PCS_WGS_1984_COMPLEX_UTM_20N 102570 /* WGS 1984 UTM Zone 20N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_21N 102571 /* WGS 1984 UTM Zone 21N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_22N 102572 /* WGS 1984 UTM Zone 22N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_23N 102573 /* WGS 1984 UTM Zone 23N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_24N 102574 /* WGS 1984 UTM Zone 24N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_25N 102575 /* WGS 1984 UTM Zone 25N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_26N 102576 /* WGS 1984 UTM Zone 26N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_27N 102577 /* WGS 1984 UTM Zone 27N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_28N 102578 /* WGS 1984 UTM Zone 28N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_29N 102579 /* WGS 1984 UTM Zone 29N using TM Complex */
#define PE_PCS_WGS_1984_COMPLEX_UTM_30N 102580 /* WGS 1984 UTM Zone 30N using TM Complex */

/* Minnesota County Coordinate Systems */

#define PE_PCS_NAD_1983_HARN_ADJ_MN_AITKIN_M     103600 /* NAD 1983 HARN Adj Minnesota Aitkin (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CLAY_M       103601 /* NAD 1983 HARN Adj Minnesota Clay (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CLEARWATER_M 103602 /* NAD 1983 HARN Adj Minnesota Clearwater (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_HUBBARD_M    103603 /* NAD 1983 HARN Adj Minnesota Hubbard (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAKE_M       103604 /* NAD 1983 HARN Adj Minnesota Lake (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MILLE_LACS_M 103605 /* NAD 1983 HARN Adj Minnesota Mille_Lacs (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WASHINGTON_M 103606 /* NAD 1983 HARN Adj Minnesota Washington (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WILKIN_M     103607 /* NAD 1983 HARN Adj Minnesota Wilkin (meter) */

#define PE_PCS_NAD_1983_HARN_ADJ_MN_ANOKA_M      103608 /* NAD 1983 HARN Adj. Minnesota Anoka (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BECKER_M     103609 /* NAD 1983 HARN Adj. Minnesota Becker (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BELTRAMI_N_M 103610 /* NAD 1983 HARN Adj. Minnesota Beltrami_North (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BELTRAMI_S_M 103611 /* NAD 1983 HARN Adj. Minnesota Beltrami_South (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BENTON_M     103612 /* NAD 1983 HARN Adj. Minnesota Benton (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BIG_STONE_M  103613 /* NAD 1983 HARN Adj. Minnesota Big_Stone (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BLUE_EARTH_M 103614 /* NAD 1983 HARN Adj. Minnesota Blue_Earth (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BROWN_M      103615 /* NAD 1983 HARN Adj. Minnesota Brown (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CARLTON_M    103616 /* NAD 1983 HARN Adj. Minnesota Carlton (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CARVER_M     103617 /* NAD 1983 HARN Adj. Minnesota Carver (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CASS_N_M     103618 /* NAD 1983 HARN Adj. Minnesota Cass_North (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CASS_S_M     103619 /* NAD 1983 HARN Adj. Minnesota Cass_South (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CHIPPEWA_M   103620 /* NAD 1983 HARN Adj. Minnesota Chippewa (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CHISAGO_M    103621 /* NAD 1983 HARN Adj. Minnesota Chisago (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_COOK_N_M     103622 /* NAD 1983 HARN Adj. Minnesota Cook_North (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_COOK_S_M     103623 /* NAD 1983 HARN Adj. Minnesota Cook_South (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_COTTONWOOD_M 103624 /* NAD 1983 HARN Adj. Minnesota Cottonwood (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CROW_WING_M  103625 /* NAD 1983 HARN Adj. Minnesota Crow_Wing (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_DAKOTA_M     103626 /* NAD 1983 HARN Adj. Minnesota Dakota (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_DODGE_M      103627 /* NAD 1983 HARN Adj. Minnesota Dodge (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_DOUGLAS_M    103628 /* NAD 1983 HARN Adj. Minnesota Douglas (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_FARIBAULT_M  103629 /* NAD 1983 HARN Adj. Minnesota Faribault (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_FILLMORE_M   103630 /* NAD 1983 HARN Adj. Minnesota Fillmore (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_FREEBORN_M   103631 /* NAD 1983 HARN Adj. Minnesota Freeborn (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_GOODHUE_M    103632 /* NAD 1983 HARN Adj. Minnesota Goodhue (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_GRANT_M      103633 /* NAD 1983 HARN Adj. Minnesota Grant (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_HENNEPIN_M   103634 /* NAD 1983 HARN Adj. Minnesota Hennepin (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_HOUSTON_M    103635 /* NAD 1983 HARN Adj. Minnesota Houston (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ISANTI_M     103636 /* NAD 1983 HARN Adj. Minnesota Isanti (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ITASCA_N_M   103637 /* NAD 1983 HARN Adj. Minnesota Itasca_North (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ITASCA_S_M   103638 /* NAD 1983 HARN Adj. Minnesota Itasca_South (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_JACKSON_M    103639 /* NAD 1983 HARN Adj. Minnesota Jackson (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KANABEC_M    103640 /* NAD 1983 HARN Adj. Minnesota Kanabec (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KANDIYOHI_M  103641 /* NAD 1983 HARN Adj. Minnesota Kandiyohi (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KITTSON_M    103642 /* NAD 1983 HARN Adj. Minnesota Kittson (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KOOCHICHING_M   103643 /* NAD 1983 HARN Adj. Minnesota Koochiching (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAC_QUI_PARLE_M 103644 /* NAD 1983 HARN Adj. Minnesota Lac_Qui_Parle (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_N_M 103645 /* NAD 1983 HARN Adj. Minnesota Lake_of_the_Woods_North (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_S_M 103646 /* NAD 1983 HARN Adj. Minnesota Lake_of_the_Woods_South (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LE_SUEUR_M   103647 /* NAD 1983 HARN Adj. Minnesota Le_Sueur (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LINCOLN_M    103648 /* NAD 1983 HARN Adj. Minnesota Lincoln (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LYON_M       103649 /* NAD 1983 HARN Adj. Minnesota Lyon (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MCLEOD_M     103650 /* NAD 1983 HARN Adj. Minnesota McLeod (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MAHNOMEN_M   103651 /* NAD 1983 HARN Adj. Minnesota Mahnomen (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MARSHALL_M   103652 /* NAD 1983 HARN Adj. Minnesota Marshall (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MARTIN_M     103653 /* NAD 1983 HARN Adj. Minnesota Martin (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MEEKER_M     103654 /* NAD 1983 HARN Adj. Minnesota Meeker (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MORRISON_M   103655 /* NAD 1983 HARN Adj. Minnesota Morrison (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MOWER_M      103656 /* NAD 1983 HARN Adj. Minnesota Mower (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MURRAY_M     103657 /* NAD 1983 HARN Adj. Minnesota Murray (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_NICOLLET_M   103658 /* NAD 1983 HARN Adj. Minnesota Nicollet (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_NOBLES_M     103659 /* NAD 1983 HARN Adj. Minnesota Nobles (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_NORMAN_M     103660 /* NAD 1983 HARN Adj. Minnesota Norman (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_OLMSTED_M    103661 /* NAD 1983 HARN Adj. Minnesota Olmsted (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_OTTERTAIL_M  103662 /* NAD 1983 HARN Adj. Minnesota Ottertail (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_PENNINGTON_M 103663 /* NAD 1983 HARN Adj. Minnesota Pennington (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_PINE_M       103664 /* NAD 1983 HARN Adj. Minnesota Pine (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_PIPESTONE_M  103665 /* NAD 1983 HARN Adj. Minnesota Pipestone (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_POLK_M       103666 /* NAD 1983 HARN Adj. Minnesota Polk (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_POPE_M       103667 /* NAD 1983 HARN Adj. Minnesota Pope (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RAMSEY_M     103668 /* NAD 1983 HARN Adj. Minnesota Ramsey (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RED_LAKE_M   103669 /* NAD 1983 HARN Adj. Minnesota Red_Lake (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_REDWOOD_M    103670 /* NAD 1983 HARN Adj. Minnesota Redwood (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RENVILLE_M   103671 /* NAD 1983 HARN Adj. Minnesota Renville (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RICE_M       103672 /* NAD 1983 HARN Adj. Minnesota Rice (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ROCK_M       103673 /* NAD 1983 HARN Adj. Minnesota Rock (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ROSEAU_M     103674 /* NAD 1983 HARN Adj. Minnesota Roseau (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_N_M 103675 /* NAD 1983 HARN Adj. Minnesota St_Louis_North (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_C_M 103676 /* NAD 1983 HARN Adj. Minnesota St_Louis_Central (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_S_M 103677 /* NAD 1983 HARN Adj. Minnesota St_Louis_South (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SCOTT_M      103678 /* NAD 1983 HARN Adj. Minnesota Scott (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SHERBURNE_M  103679 /* NAD 1983 HARN Adj. Minnesota Sherburne (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SIBLEY_M     103680 /* NAD 1983 HARN Adj. Minnesota Sibley (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_STEARNS_M    103681 /* NAD 1983 HARN Adj. Minnesota Stearns (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_STEELE_M     103682 /* NAD 1983 HARN Adj. Minnesota Steele (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_STEVENS_M    103683 /* NAD 1983 HARN Adj. Minnesota Stevens (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SWIFT_M      103684 /* NAD 1983 HARN Adj. Minnesota Swift (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_TODD_M       103685 /* NAD 1983 HARN Adj. Minnesota Todd (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_TRAVERSE_M   103686 /* NAD 1983 HARN Adj. Minnesota Traverse (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WABASHA_M    103687 /* NAD 1983 HARN Adj. Minnesota Wabasha (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WADENA_M     103688 /* NAD 1983 HARN Adj. Minnesota Wadena (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WASECA_M     103689 /* NAD 1983 HARN Adj. Minnesota Waseca (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WATONWAN_M   103690 /* NAD 1983 HARN Adj. Minnesota Watonwan (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WINONA_M     103691 /* NAD 1983 HARN Adj. Minnesota Winona (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WRIGHT_M     103692 /* NAD 1983 HARN Adj. Minnesota Wright (meter) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_YELLOW_MEDICINE_M 103693 /* NAD 1983 HARN Adj. Minnesota Yellow_Medicine (meter) */

#define PE_PCS_NAD_1983_HARN_ADJ_MN_AITKIN_FT     103700 /* NAD 1983 HARN Adj Minnesota Aitkin (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CLAY_FT       103701 /* NAD 1983 HARN Adj Minnesota Clay (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CLEARWATER_FT 103702 /* NAD 1983 HARN Adj Minnesota Clearwater (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_HUBBARD_FT    103703 /* NAD 1983 HARN Adj Minnesota Hubbard (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAKE_FT       103704 /* NAD 1983 HARN Adj Minnesota Lake (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MILLE_LACS_FT 103705 /* NAD 1983 HARN Adj Minnesota Mille_Lacs (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WASHINGTON_FT 103706 /* NAD 1983 HARN Adj Minnesota Washington (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WILKIN_FT     103707 /* NAD 1983 HARN Adj Minnesota Wilkin (US foot) */

#define PE_PCS_NAD_1983_HARN_ADJ_MN_ANOKA_FT      103708 /* NAD 1983 HARN Adj. Minnesota Anoka (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BECKER_FT     103709 /* NAD 1983 HARN Adj. Minnesota Becker (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BELTRAMI_N_FT 103710 /* NAD 1983 HARN Adj. Minnesota Beltrami_North (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BELTRAMI_S_FT 103711 /* NAD 1983 HARN Adj. Minnesota Beltrami_South (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BENTON_FT     103712 /* NAD 1983 HARN Adj. Minnesota Benton (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BIG_STONE_FT  103713 /* NAD 1983 HARN Adj. Minnesota Big_Stone (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BLUE_EARTH_FT 103714 /* NAD 1983 HARN Adj. Minnesota Blue_Earth (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_BROWN_FT      103715 /* NAD 1983 HARN Adj. Minnesota Brown (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CARLTON_FT    103716 /* NAD 1983 HARN Adj. Minnesota Carlton (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CARVER_FT     103717 /* NAD 1983 HARN Adj. Minnesota Carver (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CASS_N_FT     103718 /* NAD 1983 HARN Adj. Minnesota Cass_North (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CASS_S_FT     103719 /* NAD 1983 HARN Adj. Minnesota Cass_South (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CHIPPEWA_FT   103720 /* NAD 1983 HARN Adj. Minnesota Chippewa (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CHISAGO_FT    103721 /* NAD 1983 HARN Adj. Minnesota Chisago (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_COOK_N_FT     103722 /* NAD 1983 HARN Adj. Minnesota Cook_North (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_COOK_S_FT     103723 /* NAD 1983 HARN Adj. Minnesota Cook_South (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_COTTONWOOD_FT 103724 /* NAD 1983 HARN Adj. Minnesota Cottonwood (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_CROW_WING_FT  103725 /* NAD 1983 HARN Adj. Minnesota Crow_Wing (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_DAKOTA_FT     103726 /* NAD 1983 HARN Adj. Minnesota Dakota (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_DODGE_FT      103727 /* NAD 1983 HARN Adj. Minnesota Dodge (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_DOUGLAS_FT    103728 /* NAD 1983 HARN Adj. Minnesota Douglas (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_FARIBAULT_FT  103729 /* NAD 1983 HARN Adj. Minnesota Faribault (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_FILLMORE_FT   103730 /* NAD 1983 HARN Adj. Minnesota Fillmore (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_FREEBORN_FT   103731 /* NAD 1983 HARN Adj. Minnesota Freeborn (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_GOODHUE_FT    103732 /* NAD 1983 HARN Adj. Minnesota Goodhue (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_GRANT_FT      103733 /* NAD 1983 HARN Adj. Minnesota Grant (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_HENNEPIN_FT   103734 /* NAD 1983 HARN Adj. Minnesota Hennepin (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_HOUSTON_FT    103735 /* NAD 1983 HARN Adj. Minnesota Houston (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ISANTI_FT     103736 /* NAD 1983 HARN Adj. Minnesota Isanti (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ITASCA_N_FT   103737 /* NAD 1983 HARN Adj. Minnesota Itasca_North (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ITASCA_S_FT   103738 /* NAD 1983 HARN Adj. Minnesota Itasca_South (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_JACKSON_FT    103739 /* NAD 1983 HARN Adj. Minnesota Jackson (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KANABEC_FT    103740 /* NAD 1983 HARN Adj. Minnesota Kanabec (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KANDIYOHI_FT  103741 /* NAD 1983 HARN Adj. Minnesota Kandiyohi (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KITTSON_FT    103742 /* NAD 1983 HARN Adj. Minnesota Kittson (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_KOOCHICHING_FT   103743 /* NAD 1983 HARN Adj. Minnesota Koochiching (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAC_QUI_PARLE_FT 103744 /* NAD 1983 HARN Adj. Minnesota Lac_Qui_Parle (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_N_FT 103745 /* NAD 1983 HARN Adj. Minnesota Lake_of_the_Woods_North (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LAKE_OF_THE_WOODS_S_FT 103746 /* NAD 1983 HARN Adj. Minnesota Lake_of_the_Woods_South (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LE_SUEUR_FT   103747 /* NAD 1983 HARN Adj. Minnesota Le_Sueur (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LINCOLN_FT    103748 /* NAD 1983 HARN Adj. Minnesota Lincoln (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_LYON_FT       103749 /* NAD 1983 HARN Adj. Minnesota Lyon (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MCLEOD_FT     103750 /* NAD 1983 HARN Adj. Minnesota McLeod (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MAHNOMEN_FT   103751 /* NAD 1983 HARN Adj. Minnesota Mahnomen (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MARSHALL_FT   103752 /* NAD 1983 HARN Adj. Minnesota Marshall (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MARTIN_FT     103753 /* NAD 1983 HARN Adj. Minnesota Martin (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MEEKER_FT     103754 /* NAD 1983 HARN Adj. Minnesota Meeker (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MORRISON_FT   103755 /* NAD 1983 HARN Adj. Minnesota Morrison (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MOWER_FT      103756 /* NAD 1983 HARN Adj. Minnesota Mower (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_MURRAY_FT     103757 /* NAD 1983 HARN Adj. Minnesota Murray (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_NICOLLET_FT   103758 /* NAD 1983 HARN Adj. Minnesota Nicollet (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_NOBLES_FT     103759 /* NAD 1983 HARN Adj. Minnesota Nobles (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_NORMAN_FT     103760 /* NAD 1983 HARN Adj. Minnesota Norman (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_OLMSTED_FT    103761 /* NAD 1983 HARN Adj. Minnesota Olmsted (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_OTTERTAIL_FT  103762 /* NAD 1983 HARN Adj. Minnesota Ottertail (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_PENNINGTON_FT 103763 /* NAD 1983 HARN Adj. Minnesota Pennington (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_PINE_FT       103764 /* NAD 1983 HARN Adj. Minnesota Pine (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_PIPESTONE_FT  103765 /* NAD 1983 HARN Adj. Minnesota Pipestone (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_POLK_FT       103766 /* NAD 1983 HARN Adj. Minnesota Polk (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_POPE_FT       103767 /* NAD 1983 HARN Adj. Minnesota Pope (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RAMSEY_FT     103768 /* NAD 1983 HARN Adj. Minnesota Ramsey (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RED_LAKE_FT   103769 /* NAD 1983 HARN Adj. Minnesota Red_Lake (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_REDWOOD_FT    103770 /* NAD 1983 HARN Adj. Minnesota Redwood (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RENVILLE_FT   103771 /* NAD 1983 HARN Adj. Minnesota Renville (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_RICE_FT       103772 /* NAD 1983 HARN Adj. Minnesota Rice (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ROCK_FT       103773 /* NAD 1983 HARN Adj. Minnesota Rock (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ROSEAU_FT     103774 /* NAD 1983 HARN Adj. Minnesota Roseau (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_N_FT 103775 /* NAD 1983 HARN Adj. Minnesota St_Louis_North (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_C_FT 103776 /* NAD 1983 HARN Adj. Minnesota St_Louis_Central (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_ST_LOUIS_S_FT 103777 /* NAD 1983 HARN Adj. Minnesota St_Louis_South (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SCOTT_FT      103778 /* NAD 1983 HARN Adj. Minnesota Scott (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SHERBURNE_FT  103779 /* NAD 1983 HARN Adj. Minnesota Sherburne (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SIBLEY_FT     103780 /* NAD 1983 HARN Adj. Minnesota Sibley (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_STEARNS_FT    103781 /* NAD 1983 HARN Adj. Minnesota Stearns (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_STEELE_FT     103782 /* NAD 1983 HARN Adj. Minnesota Steele (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_STEVENS_FT    103783 /* NAD 1983 HARN Adj. Minnesota Stevens (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_SWIFT_FT      103784 /* NAD 1983 HARN Adj. Minnesota Swift (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_TODD_FT       103785 /* NAD 1983 HARN Adj. Minnesota Todd (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_TRAVERSE_FT   103786 /* NAD 1983 HARN Adj. Minnesota Traverse (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WABASHA_FT    103787 /* NAD 1983 HARN Adj. Minnesota Wabasha (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WADENA_FT     103788 /* NAD 1983 HARN Adj. Minnesota Wadena (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WASECA_FT     103789 /* NAD 1983 HARN Adj. Minnesota Waseca (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WATONWAN_FT   103790 /* NAD 1983 HARN Adj. Minnesota Watonwan (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WINONA_FT     103791 /* NAD 1983 HARN Adj. Minnesota Winona (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_WRIGHT_FT     103792 /* NAD 1983 HARN Adj. Minnesota Wright (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_MN_YELLOW_MEDICINE_FT 103793 /* NAD 1983 HARN Adj. Minnesota Yellow_Medicine (US foot) */


/* Wisconsin County Coordinate Systems */

#define PE_PCS_NAD_1983_HARN_ADJ_WI_AD_M  103800 /* NAD 1983 HARN Adj. Wisconsin Adams (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_AL_M  103801 /* NAD 1983 HARN Adj. Wisconsin Ashland (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BA_M  103802 /* NAD 1983 HARN Adj. Wisconsin Barron (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BR_M  103803 /* NAD 1983 HARN Adj. Wisconsin Brown (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BU_M  103804 /* NAD 1983 HARN Adj. Wisconsin Buffalo (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CL_M  103805 /* NAD 1983 HARN Adj. Wisconsin Calumet (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CK_M  103806 /* NAD 1983 HARN Adj. Wisconsin Clark (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DD_M  103807 /* NAD 1983 HARN Adj. Wisconsin Dodge (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DR_M  103808 /* NAD 1983 HARN Adj. Wisconsin Door (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DG_M  103809 /* NAD 1983 HARN Adj. Wisconsin Douglas (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DU_M  103810 /* NAD 1983 HARN Adj. Wisconsin Dunn (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_FN_M  103811 /* NAD 1983 HARN Adj. Wisconsin Florence (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_FL_M  103812 /* NAD 1983 HARN Adj. Wisconsin Fond_du_Lac (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_FR_M  103813 /* NAD 1983 HARN Adj. Wisconsin Forest (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_GT_M  103814 /* NAD 1983 HARN Adj. Wisconsin Grant (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_IA_M  103815 /* NAD 1983 HARN Adj. Wisconsin Iowa (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_IR_M  103816 /* NAD 1983 HARN Adj. Wisconsin Iron (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_JF_M  103817 /* NAD 1983 HARN Adj. Wisconsin Jefferson (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_JN_M  103818 /* NAD 1983 HARN Adj. Wisconsin Juneau (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_KN_M  103819 /* NAD 1983 HARN Adj. Wisconsin Kenosha (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_KW_M  103820 /* NAD 1983 HARN Adj. Wisconsin Kewaunee (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LC_M  103821 /* NAD 1983 HARN Adj. Wisconsin LaCrosse (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LN_M  103822 /* NAD 1983 HARN Adj. Wisconsin Lincoln (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MT_M  103823 /* NAD 1983 HARN Adj. Wisconsin Manitowoc (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MN_M  103824 /* NAD 1983 HARN Adj. Wisconsin Marinette (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_ME_M  103825 /* NAD 1983 HARN Adj. Wisconsin Menominee (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MW_M  103826 /* NAD 1983 HARN Adj. Wisconsin Milwaukee (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_OC_M  103827 /* NAD 1983 HARN Adj. Wisconsin Oconto (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_OG_M  103828 /* NAD 1983 HARN Adj. Wisconsin Outagamie (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_OZ_M  103829 /* NAD 1983 HARN Adj. Wisconsin Ozaukee (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PK_M  103830 /* NAD 1983 HARN Adj. Wisconsin Polk (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PR_M  103831 /* NAD 1983 HARN Adj. Wisconsin Price (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RA_M  103832 /* NAD 1983 HARN Adj. Wisconsin Racine (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RK_M  103833 /* NAD 1983 HARN Adj. Wisconsin Rock (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RS_M  103834 /* NAD 1983 HARN Adj. Wisconsin Rusk (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SC_M  103835 /* NAD 1983 HARN Adj. Wisconsin St_Croix (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SK_M  103836 /* NAD 1983 HARN Adj. Wisconsin Sauk (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SH_M  103837 /* NAD 1983 HARN Adj. Wisconsin Shawano (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SG_M  103838 /* NAD 1983 HARN Adj. Wisconsin Sheboygan (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_TR_M  103839 /* NAD 1983 HARN Adj. Wisconsin Trempealeau (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WA_M  103840 /* NAD 1983 HARN Adj. Wisconsin Washington (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WK_M  103841 /* NAD 1983 HARN Adj. Wisconsin Waukesha (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WP_M  103842 /* NAD 1983 HARN Adj. Wisconsin Waupaca (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WN_M  103843 /* NAD 1983 HARN Adj. Wisconsin Winnebago (meters) */

#define PE_PCS_NAD_1983_HARN_ADJ_WI_BF_M  103844 /* NAD 1983 HARN Adj. Wisconsin Bayfield (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BN_M  103845 /* NAD 1983 HARN Adj. Wisconsin Burnett (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CP_M  103846 /* NAD 1983 HARN Adj. Wisconsin Chippewa (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CO_M  103847 /* NAD 1983 HARN Adj. Wisconsin Columbia (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CR_M  103848 /* NAD 1983 HARN Adj. Wisconsin Crawford (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DN_M  103849 /* NAD 1983 HARN Adj. Wisconsin Dane (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_EC_M  103850 /* NAD 1983 HARN Adj. Wisconsin EauClaire (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_GR_M  103851 /* NAD 1983 HARN Adj. Wisconsin Green (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_GL_M  103852 /* NAD 1983 HARN Adj. Wisconsin GreenLake (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_JA_M  103853 /* NAD 1983 HARN Adj. Wisconsin Jackson (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LF_M  103854 /* NAD 1983 HARN Adj. Wisconsin Lafayette (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LG_M  103855 /* NAD 1983 HARN Adj. Wisconsin Langlade (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MA_M  103856 /* NAD 1983 HARN Adj. Wisconsin Marathon (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MQ_M  103857 /* NAD 1983 HARN Adj. Wisconsin Marquette (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MR_M  103858 /* NAD 1983 HARN Adj. Wisconsin Monroe (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_ON_M  103859 /* NAD 1983 HARN Adj. Wisconsin Oneida (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PP_M  103860 /* NAD 1983 HARN Adj. Wisconsin Pepin (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PC_M  103861 /* NAD 1983 HARN Adj. Wisconsin Pierce (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PT_M  103862 /* NAD 1983 HARN Adj. Wisconsin Portage (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RC_M  103863 /* NAD 1983 HARN Adj. Wisconsin Richland (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SW_M  103864 /* NAD 1983 HARN Adj. Wisconsin Sawyer (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_TA_M  103865 /* NAD 1983 HARN Adj. Wisconsin Taylor (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_VR_M  103866 /* NAD 1983 HARN Adj. Wisconsin Vernon (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_VI_M  103867 /* NAD 1983 HARN Adj. Wisconsin Vilas (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WW_M  103868 /* NAD 1983 HARN Adj. Wisconsin Walworth (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WB_M  103869 /* NAD 1983 HARN Adj. Wisconsin Washburn (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WS_M  103870 /* NAD 1983 HARN Adj. Wisconsin Waushara (meters) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WD_M  103871 /* NAD 1983 HARN Adj. Wisconsin Wood (meters) */

#define PE_PCS_NAD_1983_HARN_ADJ_WI_AD_FT  103900 /* NAD 1983 HARN Adj. Wisconsin Adams (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_AL_FT  103901 /* NAD 1983 HARN Adj. Wisconsin Ashland (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BA_FT  103902 /* NAD 1983 HARN Adj. Wisconsin Barron (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BR_FT  103903 /* NAD 1983 HARN Adj. Wisconsin Brown (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BU_FT  103904 /* NAD 1983 HARN Adj. Wisconsin Buffalo (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CL_FT  103905 /* NAD 1983 HARN Adj. Wisconsin Calumet (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CK_FT  103906 /* NAD 1983 HARN Adj. Wisconsin Clark (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DD_FT  103907 /* NAD 1983 HARN Adj. Wisconsin Dodge (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DR_FT  103908 /* NAD 1983 HARN Adj. Wisconsin Door (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DG_FT  103909 /* NAD 1983 HARN Adj. Wisconsin Douglas (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DU_FT  103910 /* NAD 1983 HARN Adj. Wisconsin Dunn (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_FN_FT  103911 /* NAD 1983 HARN Adj. Wisconsin Florence (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_FL_FT  103912 /* NAD 1983 HARN Adj. Wisconsin Fond_du_Lac (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_FR_FT  103913 /* NAD 1983 HARN Adj. Wisconsin Forest (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_GT_FT  103914 /* NAD 1983 HARN Adj. Wisconsin Grant (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_IA_FT  103915 /* NAD 1983 HARN Adj. Wisconsin Iowa (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_IR_FT  103916 /* NAD 1983 HARN Adj. Wisconsin Iron (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_JF_FT  103917 /* NAD 1983 HARN Adj. Wisconsin Jefferson (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_JN_FT  103918 /* NAD 1983 HARN Adj. Wisconsin Juneau (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_KN_FT  103919 /* NAD 1983 HARN Adj. Wisconsin Kenosha (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_KW_FT  103920 /* NAD 1983 HARN Adj. Wisconsin Kewaunee (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LC_FT  103921 /* NAD 1983 HARN Adj. Wisconsin LaCrosse (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LN_FT  103922 /* NAD 1983 HARN Adj. Wisconsin Lincoln (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MT_FT  103923 /* NAD 1983 HARN Adj. Wisconsin Manitowoc (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MN_FT  103924 /* NAD 1983 HARN Adj. Wisconsin Marinette (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_ME_FT  103925 /* NAD 1983 HARN Adj. Wisconsin Menominee (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MW_FT  103926 /* NAD 1983 HARN Adj. Wisconsin Milwaukee (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_OC_FT  103927 /* NAD 1983 HARN Adj. Wisconsin Oconto (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_OG_FT  103928 /* NAD 1983 HARN Adj. Wisconsin Outagamie (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_OZ_FT  103929 /* NAD 1983 HARN Adj. Wisconsin Ozaukee (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PK_FT  103930 /* NAD 1983 HARN Adj. Wisconsin Polk (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PR_FT  103931 /* NAD 1983 HARN Adj. Wisconsin Price (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RA_FT  103932 /* NAD 1983 HARN Adj. Wisconsin Racine (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RK_FT  103933 /* NAD 1983 HARN Adj. Wisconsin Rock (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RS_FT  103934 /* NAD 1983 HARN Adj. Wisconsin Rusk (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SC_FT  103935 /* NAD 1983 HARN Adj. Wisconsin St_Croix (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SK_FT  103936 /* NAD 1983 HARN Adj. Wisconsin Sauk (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SH_FT  103937 /* NAD 1983 HARN Adj. Wisconsin Shawano (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SG_FT  103938 /* NAD 1983 HARN Adj. Wisconsin Sheboygan (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_TR_FT  103939 /* NAD 1983 HARN Adj. Wisconsin Trempealeau (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WA_FT  103940 /* NAD 1983 HARN Adj. Wisconsin Washington (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WK_FT  103941 /* NAD 1983 HARN Adj. Wisconsin Waukesha (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WP_FT  103942 /* NAD 1983 HARN Adj. Wisconsin Waupaca (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WN_FT  103943 /* NAD 1983 HARN Adj. Wisconsin Winnebago (US foot) */

#define PE_PCS_NAD_1983_HARN_ADJ_WI_BF_FT  103944 /* NAD 1983 HARN Adj. Wisconsin Bayfield (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_BN_FT  103945 /* NAD 1983 HARN Adj. Wisconsin Burnett (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CP_FT  103946 /* NAD 1983 HARN Adj. Wisconsin Chippewa (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CO_FT  103947 /* NAD 1983 HARN Adj. Wisconsin Columbia (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_CR_FT  103948 /* NAD 1983 HARN Adj. Wisconsin Crawford (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_DN_FT  103949 /* NAD 1983 HARN Adj. Wisconsin Dane (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_EC_FT  103950 /* NAD 1983 HARN Adj. Wisconsin EauClaire (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_GR_FT  103951 /* NAD 1983 HARN Adj. Wisconsin Green (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_GL_FT  103952 /* NAD 1983 HARN Adj. Wisconsin GreenLake (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_JA_FT  103953 /* NAD 1983 HARN Adj. Wisconsin Jackson (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LF_FT  103954 /* NAD 1983 HARN Adj. Wisconsin Lafayette (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_LG_FT  103955 /* NAD 1983 HARN Adj. Wisconsin Langlade (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MA_FT  103956 /* NAD 1983 HARN Adj. Wisconsin Marathon (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MQ_FT  103957 /* NAD 1983 HARN Adj. Wisconsin Marquette (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_MR_FT  103958 /* NAD 1983 HARN Adj. Wisconsin Monroe (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_ON_FT  103959 /* NAD 1983 HARN Adj. Wisconsin Oneida (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PP_FT  103960 /* NAD 1983 HARN Adj. Wisconsin Pepin (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PC_FT  103961 /* NAD 1983 HARN Adj. Wisconsin Pierce (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_PT_FT  103962 /* NAD 1983 HARN Adj. Wisconsin Portage (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_RC_FT  103963 /* NAD 1983 HARN Adj. Wisconsin Richland (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_SW_FT  103964 /* NAD 1983 HARN Adj. Wisconsin Sawyer (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_TA_FT  103965 /* NAD 1983 HARN Adj. Wisconsin Taylor (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_VR_FT  103966 /* NAD 1983 HARN Adj. Wisconsin Vernon (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_VI_FT  103967 /* NAD 1983 HARN Adj. Wisconsin Vilas (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WW_FT  103968 /* NAD 1983 HARN Adj. Wisconsin Walworth (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WB_FT  103969 /* NAD 1983 HARN Adj. Wisconsin Washburn (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WS_FT  103970 /* NAD 1983 HARN Adj. Wisconsin Waushara (US foot) */
#define PE_PCS_NAD_1983_HARN_ADJ_WI_WD_FT  103971 /* NAD 1983 HARN Adj. Wisconsin Wood (US foot) */

#define PE_PCS_WORLD_FULLER                  54050 /* Fuller                  */
#define PE_PCS_WORLD_CUBE                    54051 /* Cube                    */

/* END of NEW PCS's at 9.0 ----------------------- */

#define PE_PCS_ABIDJAN_1987_TM_5_NW     2165 /* Abidjan 1987 TM 5 NW          */
#define PE_PCS_ABIDJAN_1987_UTM_29N     2043 /* Abidjan 1987 UTM 29N          */
#define PE_PCS_ABIDJAN_1987_UTM_30N     2041 /* Abidjan 1987 UTM 30N          */
#define PE_PCS_ACCRA_GHANA_GRID         2136 /* Accra Ghana Grid              */
#define PE_PCS_ACCRA_TM_1_NW            2137 /* Accra TM 1 NW                 */
#define PE_PCS_ADINDAN_UTM_37N         20137 /* Adindan UTM Zone 37N          */
#define PE_PCS_ADINDAN_UTM_38N         20138 /* Adindan UTM Zone 38N          */
#define PE_PCS_AFGOOYE_UTM_38N         20538 /* Afgooye UTM Zone 38N          */
#define PE_PCS_AFGOOYE_UTM_39N         20539 /* Afgooye UTM Zone 39N          */

/* Australia */
#define PE_PCS_AGD_1966_AMG_48         20248 /* AGD 1966 AMG Zone 48          */
#define PE_PCS_AGD_1966_AMG_49         20249 /* AGD 1966 AMG Zone 49          */
#define PE_PCS_AGD_1966_AMG_50         20250 /* AGD 1966 AMG Zone 50          */
#define PE_PCS_AGD_1966_AMG_51         20251 /* AGD 1966 AMG Zone 51          */
#define PE_PCS_AGD_1966_AMG_52         20252 /* AGD 1966 AMG Zone 52          */
#define PE_PCS_AGD_1966_AMG_53         20253 /* AGD 1966 AMG Zone 53          */
#define PE_PCS_AGD_1966_AMG_54         20254 /* AGD 1966 AMG Zone 54          */
#define PE_PCS_AGD_1966_AMG_55         20255 /* AGD 1966 AMG Zone 55          */
#define PE_PCS_AGD_1966_AMG_56         20256 /* AGD 1966 AMG Zone 56          */
#define PE_PCS_AGD_1966_AMG_57         20257 /* AGD 1966 AMG Zone 57          */
#define PE_PCS_AGD_1966_AMG_58         20258 /* AGD 1966 AMG Zone 58          */
#define PE_PCS_AGD_1984_AMG_48         20348 /* AGD 1984 AMG Zone 48          */
#define PE_PCS_AGD_1984_AMG_49         20349 /* AGD 1984 AMG Zone 49          */
#define PE_PCS_AGD_1984_AMG_50         20350 /* AGD 1984 AMG Zone 50          */
#define PE_PCS_AGD_1984_AMG_51         20351 /* AGD 1984 AMG Zone 51          */
#define PE_PCS_AGD_1984_AMG_52         20352 /* AGD 1984 AMG Zone 52          */
#define PE_PCS_AGD_1984_AMG_53         20353 /* AGD 1984 AMG Zone 53          */
#define PE_PCS_AGD_1984_AMG_54         20354 /* AGD 1984 AMG Zone 54          */
#define PE_PCS_AGD_1984_AMG_55         20355 /* AGD 1984 AMG Zone 55          */
#define PE_PCS_AGD_1984_AMG_56         20356 /* AGD 1984 AMG Zone 56          */
#define PE_PCS_AGD_1984_AMG_57         20357 /* AGD 1984 AMG Zone 57          */
#define PE_PCS_AGD_1984_AMG_58         20358 /* AGD 1984 AMG Zone 58          */


#define PE_PCS_AIN_EL_ABD_BAHRAIN_GRID 20499 /* Bahrain State Grid            */
#define PE_PCS_AIN_EL_ABD_UTM_37N      20437 /* Ain el Abd 1970 UTM Zone 37N  */
#define PE_PCS_AIN_EL_ABD_UTM_38N      20438 /* Ain el Abd 1970 UTM Zone 38N  */
#define PE_PCS_AIN_EL_ABD_UTM_39N      20439 /* Ain el Abd 1970 UTM Zone 39N  */
#define PE_PCS_AMERSFOORT_RD_NEW       28992 /* Amersfoort RD New,Netherlands */
#define PE_PCS_AMERSFOORT_RD_OLD       28991 /* Amersfoort RD Old,Netherlands */
#define PE_PCS_ANGUILLA_1957_BRITISH_W_INDIES  2000 /* Anguilla 1957 British W Indies Grid */
#define PE_PCS_ANTIGUA_1943_BRITISH_W_INDIES   2001 /* Antigua 1943 British W Indies Grid  */
#define PE_PCS_ARATU_UTM_22S           20822 /* Aratu UTM Zone 22S            */
#define PE_PCS_ARATU_UTM_23S           20823 /* Aratu UTM Zone 23S            */
#define PE_PCS_ARATU_UTM_24S           20824 /* Aratu UTM Zone 24S            */
#define PE_PCS_ARC_1950_UTM_34S        20934 /* Arc 1950 UTM zone 34S         */
#define PE_PCS_ARC_1950_UTM_35S        20935 /* Arc 1950 UTM zone 35S         */
#define PE_PCS_ARC_1950_UTM_36S        20936 /* Arc 1950 UTM zone 36S         */
#define PE_PCS_ARC_1960_UTM_35S        21035 /* Arc 1960 UTM zone 35S         */
#define PE_PCS_ARC_1960_UTM_36S        21036 /* Arc 1960 UTM zone 36S         */
#define PE_PCS_ARC_1960_UTM_37S        21037 /* Arc 1960 UTM zone 37S         */
#define PE_PCS_ARC_1960_UTM_35N        21095 /* Arc 1960 UTM zone 35N         */
#define PE_PCS_ARC_1960_UTM_36N        21096 /* Arc 1960 UTM zone 36N         */
#define PE_PCS_ARC_1960_UTM_37N        21097 /* Arc 1960 UTM zone 37N         */
#define PE_PCS_ATF_NORD_DE_GUERRE      27500 /* ATF Paris Nord de Guerre      */
#define PE_PCS_ATS_1977_MTM_4_NS      2294 /* ATS 1977 MTM zone 4 Nova Scotia */
#define PE_PCS_ATS_1977_MTM_5_NS      2295 /* ATS 1977 MTM zone 5 Nova Scotia */
#define PE_PCS_ATS_1977_NEW_BRUNSWICK 2200 /* ATS 1977 New Brunswick Stereographic */
#define PE_PCS_ATS_1977_PRINCE_EDWARD_ISLAND 2290 /* ATS 1977 Prince Edward   */
                                                  /*  Island Stereographic    */
#define PE_PCS_ATS_1977_UTM_19N       2219  /* ATS 1977 UTM Zone 19N          */
#define PE_PCS_ATS_1977_UTM_20N       2220  /* ATS 1977 UTM Zone 20N          */
#define PE_PCS_BARBADOS_1938_BRITISH_W_INDIES  21291 /* Barbados 1938 British W Indies Grid */
#define PE_PCS_BARBADOS_1938_BARBADOS_GRID     21292 /* Barbados 1938 Barbados Grid */
#define PE_PCS_BATAVIA_UTM_48S         21148 /* Batavia UTM Zone 48S          */
#define PE_PCS_BATAVIA_UTM_49S         21149 /* Batavia UTM Zone 49S          */
#define PE_PCS_BATAVIA_UTM_50S         21150 /* Batavia UTM Zone 50S          */

/* China */
#define PE_PCS_BEIJING_1954_GK_13      21413 /* Beijing 1954 GK Zone 13       */
#define PE_PCS_BEIJING_1954_GK_14      21414 /* Beijing 1954 GK Zone 14       */
#define PE_PCS_BEIJING_1954_GK_15      21415 /* Beijing 1954 GK Zone 15       */
#define PE_PCS_BEIJING_1954_GK_16      21416 /* Beijing 1954 GK Zone 16       */
#define PE_PCS_BEIJING_1954_GK_17      21417 /* Beijing 1954 GK Zone 17       */
#define PE_PCS_BEIJING_1954_GK_18      21418 /* Beijing 1954 GK Zone 18       */
#define PE_PCS_BEIJING_1954_GK_19      21419 /* Beijing 1954 GK Zone 19       */
#define PE_PCS_BEIJING_1954_GK_20      21420 /* Beijing 1954 GK Zone 20       */
#define PE_PCS_BEIJING_1954_GK_21      21421 /* Beijing 1954 GK Zone 21       */
#define PE_PCS_BEIJING_1954_GK_22      21422 /* Beijing 1954 GK Zone 22       */
#define PE_PCS_BEIJING_1954_GK_23      21423 /* Beijing 1954 GK Zone 23       */
#define PE_PCS_BEIJING_1954_GK_13N     21473 /* Beijing 1954 GK Zone 13N      */
#define PE_PCS_BEIJING_1954_GK_14N     21474 /* Beijing 1954 GK Zone 14N      */
#define PE_PCS_BEIJING_1954_GK_15N     21475 /* Beijing 1954 GK Zone 15N      */
#define PE_PCS_BEIJING_1954_GK_16N     21476 /* Beijing 1954 GK Zone 16N      */
#define PE_PCS_BEIJING_1954_GK_17N     21477 /* Beijing 1954 GK Zone 17N      */
#define PE_PCS_BEIJING_1954_GK_18N     21478 /* Beijing 1954 GK Zone 18N      */
#define PE_PCS_BEIJING_1954_GK_19N     21479 /* Beijing 1954 GK Zone 19N      */
#define PE_PCS_BEIJING_1954_GK_20N     21480 /* Beijing 1954 GK Zone 20N      */
#define PE_PCS_BEIJING_1954_GK_21N     21481 /* Beijing 1954 GK Zone 21N      */
#define PE_PCS_BEIJING_1954_GK_22N     21482 /* Beijing 1954 GK Zone 22N      */
#define PE_PCS_BEIJING_1954_GK_23N     21483 /* Beijing 1954 GK Zone 23N      */


#define PE_PCS_BELGE_LAMBERT_1950   21500 /* Belge Lambert 1950               */
#define PE_PCS_BELGE_LAMBERT_1972   31370 /* Belge Lambert 1972 (was 103300 at 8.3) */
#define PE_PCS_BERN_1898_BERN_LV03C    21780 /* Bern 1898 (Bern) LV03C        */
#define PE_PCS_BISSAU_UTM_28N           2095 /* Bissau UTM zone 28N           */
#define PE_PCS_BOGOTA_COLOMBIA_WEST       21891 /* Colombia West Zone         */
#define PE_PCS_BOGOTA_COLOMBIA_BOGOTA     21892 /* Colombia Bogota Zone       */
#define PE_PCS_BOGOTA_COLOMBIA_E_CENTRAL  21893 /* Colombia E Central Zone    */
#define PE_PCS_BOGOTA_COLOMBIA_EAST       21894 /* Colombia East Zone         */
#define PE_PCS_BOGOTA_UTM_17N             21817 /* Bogota UTM Zone 17N        */
#define PE_PCS_BOGOTA_UTM_18N             21818 /* Bogota UTM Zone 18N        */
#define PE_PCS_CAMACUPA_TM_11_30_SE    22091 /* Camacupa TM 11 30 SE          */
#define PE_PCS_CAMACUPA_TM_12_SE       22092 /* Camacupa TM 12 SE             */
#define PE_PCS_CAMACUPA_UTM_32S        22032 /* Camacupa UTM Zone 32S         */
#define PE_PCS_CAMACUPA_UTM_33S        22033 /* Camacupa UTM Zone 33S         */
#define PE_PCS_CAPE_UTM_34S            22234 /* Cape UTM zone 34S             */
#define PE_PCS_CAPE_UTM_35S            22235 /* Cape UTM zone 35S             */
#define PE_PCS_CAPE_UTM_36S            22236 /* Cape UTM zone 36S             */
#define PE_PCS_CARTHAGE_NORD_TUNISIE   22391 /* Nord Tunisie                  */
#define PE_PCS_CARTHAGE_TM_11_NE        2088 /* Carthage TM 11 NE             */
#define PE_PCS_CARTHAGE_SUD_TUNISIE    22392 /* Sud Tunisie                   */
#define PE_PCS_CARTHAGE_UTM_32N        22332 /* Carthage UTM Zone 32N         */
#define PE_PCS_CH1903_LV03             21781 /* CH1903 LV03  (Swiss, Liech)   */
#define PE_PCS_CH1903_PLUS_LV95         2056 /* CH1903+ LV95 (Swiss, Liech)   */
#define PE_PCS_CHOS_MALAL_1914_ARGENTINA_2  2081 /* Chos Malal 1914 Argentina zone 2 */
#define PE_PCS_CONAKRY_1905_UTM_28N    31528 /* Conakry 1905 UTM zone 28N     */
#define PE_PCS_CONAKRY_1905_UTM_29N    31529 /* Conakry 1905 UTM zone 29N     */
#define PE_PCS_CORREGO_ALEGRE_UTM_23S  22523 /* Corrego Alegre UTM Zone 23S   */
#define PE_PCS_CORREGO_ALEGRE_UTM_24S  22524 /* Corrego Alegre UTM Zone 24S   */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_1   22191 /* Argentina Zone 1            */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_2   22192 /* Argentina Zone 2            */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_3   22193 /* Argentina Zone 3            */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_4   22194 /* Argentina Zone 4            */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_5   22195 /* Argentina Zone 5            */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_6   22196 /* Argentina Zone 6            */
#define PE_PCS_C_INCHAUSPE_ARGENTINA_7   22197 /* Argentina Zone 7            */
#define PE_PCS_DABOLA_UTM_28N           2063 /* Dabola UTM zone 28N           */
#define PE_PCS_DABOLA_UTM_29N           2064 /* Dabola UTM zone 29N           */
#define PE_PCS_DATUM_73_UTM_ZONE_29N   27429 /* Datum 73 UTM Zone 29N         */
#define PE_PCS_DEALUL_PISCULUI_1933_STEREO_33  31600 /* Stereo 1933           */
#define PE_PCS_DEALUL_PISCULUI_1970_STEREO_70  31700 /* Stereo 1970           */
#define PE_PCS_DEIR_EZ_ZOR_LEVANT         22700 /* Deir ez Zor Levant Zone    */
#define PE_PCS_DEIR_EZ_ZOR_LEVANT_STEREO  22780 /* Deir es Zor Levant Stereographic */
#define PE_PCS_DEIR_EZ_ZOR_SYRIA          22770 /* Deir ez Zor Syria Lambert  */
#define PE_PCS_DHDN_3_DEGREE_GAUSS_1   31461 /* DHDN 3 degree Gauss zone 1    */
#define PE_PCS_DHDN_3_DEGREE_GAUSS_2   31466 /* DHDN 3 degree Gauss zone 2    */
#define PE_PCS_DHDN_3_DEGREE_GAUSS_3   31467 /* DHDN 3 degree Gauss zone 3    */
#define PE_PCS_DHDN_3_DEGREE_GAUSS_4   31468 /* DHDN 3 degree Gauss zone 4    */
#define PE_PCS_DHDN_3_DEGREE_GAUSS_5   31469 /* DHDN 3 degree Gauss zone 5    */
#define PE_PCS_DHDN_GERMANY_1          31491 /* Germany Zone 1                */
#define PE_PCS_DHDN_GERMANY_2          31492 /* Germany Zone 2                */
#define PE_PCS_DHDN_GERMANY_3          31493 /* Germany Zone 3                */
#define PE_PCS_DHDN_GERMANY_4          31494 /* Germany Zone 4                */
#define PE_PCS_DHDN_GERMANY_5          31495 /* Germany Zone 5                */
#define PE_PCS_DOMINICA_1945_BRITISH_W_INDIES  2002 /* Dominica 1945 British W Indies Grid */
#define PE_PCS_DOUALA_UTM_32N          22832 /* Douala UTM Zone 32N           */

/* Europe */
#define PE_PCS_ED_1950_ED77_UTM_38N     2058 /* ED 1950 (ED77) UTM 38N        */
#define PE_PCS_ED_1950_ED77_UTM_39N     2059 /* ED 1950 (ED77) UTM 39N        */
#define PE_PCS_ED_1950_ED77_UTM_40N     2060 /* ED 1950 (ED77) UTM 40N        */
#define PE_PCS_ED_1950_ED77_UTM_41N     2061 /* ED 1950 (ED77) UTM 41N        */
#define PE_PCS_ED_1950_TM_0_N          23090 /* ED 1950 TM 0 N                */
#define PE_PCS_ED_1950_TM_5_NE         23095 /* ED 1950 TM 5 NE               */
#define PE_PCS_ED_1950_UTM_28N      23028 /* European Datum 1950 UTM Zone 28N */
#define PE_PCS_ED_1950_UTM_29N      23029 /* European Datum 1950 UTM Zone 29N */
#define PE_PCS_ED_1950_UTM_30N      23030 /* European Datum 1950 UTM Zone 30N */
#define PE_PCS_ED_1950_UTM_31N      23031 /* European Datum 1950 UTM Zone 31N */
#define PE_PCS_ED_1950_UTM_32N      23032 /* European Datum 1950 UTM Zone 32N */
#define PE_PCS_ED_1950_UTM_33N      23033 /* European Datum 1950 UTM Zone 33N */
#define PE_PCS_ED_1950_UTM_34N      23034 /* European Datum 1950 UTM Zone 34N */
#define PE_PCS_ED_1950_UTM_35N      23035 /* European Datum 1950 UTM Zone 35N */
#define PE_PCS_ED_1950_UTM_36N      23036 /* European Datum 1950 UTM Zone 36N */
#define PE_PCS_ED_1950_UTM_37N      23037 /* European Datum 1950 UTM Zone 37N */
#define PE_PCS_ED_1950_UTM_38N      23038 /* European Datum 1950 UTM Zone 38N */


#define PE_PCS_EGYPT_BLUE_BELT         22991 /* Egypt 1907 Blue Belt          */
#define PE_PCS_EGYPT_RED_BELT          22992 /* Egypt Red Belt                */
#define PE_PCS_EGYPT_PURPLE_BELT       22993 /* Egypt Purple Belt             */
#define PE_PCS_EGYPT_EXT_PURPLE_BELT   22994 /* Egypt Extended Purple Belt    */
#define PE_PCS_ELD_1979_LIBYA_5         2068 /* ELD 1979 Libya zone 5         */
#define PE_PCS_ELD_1979_LIBYA_6         2069 /* ELD 1979 Libya zone 6         */
#define PE_PCS_ELD_1979_LIBYA_7         2070 /* ELD 1979 Libya zone 7         */
#define PE_PCS_ELD_1979_LIBYA_8         2071 /* ELD 1979 Libya zone 8         */
#define PE_PCS_ELD_1979_LIBYA_9         2072 /* ELD 1979 Libya zone 9         */
#define PE_PCS_ELD_1979_LIBYA_10        2073 /* ELD 1979 Libya zone 10        */
#define PE_PCS_ELD_1979_LIBYA_11        2074 /* ELD 1979 Libya zone 11        */
#define PE_PCS_ELD_1979_LIBYA_12        2075 /* ELD 1979 Libya zone 12        */
#define PE_PCS_ELD_1979_LIBYA_13        2076 /* ELD 1979 Libya zone 13        */
#define PE_PCS_ELD_1979_TM_12_NE        2087 /* ELD 1979 TM 12 NE             */
#define PE_PCS_ELD_1979_UTM_32N         2077 /* ELD 1979 UTM zone 32N         */
#define PE_PCS_ELD_1979_UTM_33N         2078 /* ELD 1979 UTM zone 33N         */
#define PE_PCS_ELD_1979_UTM_34N         2079 /* ELD 1979 UTM zone 34N         */
#define PE_PCS_ELD_1979_UTM_35N         2080 /* ELD 1979 UTM zone 35N         */
#define PE_PCS_ESTONIAN_COORDINATE_SYSTEM_1992 3300 /* Estonian Coord System 1992 */

/* European Terrestrial Reference Frame */
#define PE_PCS_ETRF_1989_TM_BALTIC_1993  103584 /* ETRF89 TM Baltic 1993      */
#define PE_PCS_ETRF_1989_UTM_28N      103528 /* ETRF 1989 UTM Zone 28N        */
#define PE_PCS_ETRF_1989_UTM_29N      103529 /* ETRF 1989 UTM Zone 29N        */
#define PE_PCS_ETRF_1989_UTM_30N      103530 /* ETRF 1989 UTM Zone 30N        */
#define PE_PCS_ETRF_1989_UTM_31N      103531 /* ETRF 1989 UTM Zone 31N        */
#define PE_PCS_ETRF_1989_UTM_32N      103532 /* ETRF 1989 UTM Zone 32N        */
#define PE_PCS_ETRF_1989_UTM_33N      103533 /* ETRF 1989 UTM Zone 33N        */
#define PE_PCS_ETRF_1989_UTM_34N      103534 /* ETRF 1989 UTM Zone 34N        */
#define PE_PCS_ETRF_1989_UTM_35N      103535 /* ETRF 1989 UTM Zone 35N        */
#define PE_PCS_ETRF_1989_UTM_36N      103536 /* ETRF 1989 UTM Zone 36N        */
#define PE_PCS_ETRF_1989_UTM_37N      103537 /* ETRF 1989 UTM Zone 37N        */
#define PE_PCS_ETRF_1989_UTM_38N      103538 /* ETRF 1989 UTM Zone 38N        */

/* European Terrestrial Reference System */
#define PE_PCS_ETRS_1989_TM_BALTIC_1993   25884 /* ETRS89 TM Baltic 1993      */
#define PE_PCS_ETRS_1989_UTM_28N       25828 /* ETRS 1989 UTM Zone 28N        */
#define PE_PCS_ETRS_1989_UTM_29N       25829 /* ETRS 1989 UTM Zone 29N        */
#define PE_PCS_ETRS_1989_UTM_30N       25830 /* ETRS 1989 UTM Zone 30N        */
#define PE_PCS_ETRS_1989_UTM_31N       25831 /* ETRS 1989 UTM Zone 31N        */
#define PE_PCS_ETRS_1989_UTM_32N       25832 /* ETRS 1989 UTM Zone 32N        */
#define PE_PCS_ETRS_1989_UTM_33N       25833 /* ETRS 1989 UTM Zone 33N        */
#define PE_PCS_ETRS_1989_UTM_34N       25834 /* ETRS 1989 UTM Zone 34N        */
#define PE_PCS_ETRS_1989_UTM_35N       25835 /* ETRS 1989 UTM Zone 35N        */
#define PE_PCS_ETRS_1989_UTM_36N       25836 /* ETRS 1989 UTM Zone 36N        */
#define PE_PCS_ETRS_1989_UTM_37N       25837 /* ETRS 1989 UTM Zone 37N        */
#define PE_PCS_ETRS_1989_UTM_38N       25838 /* ETRS 1989 UTM Zone 38N        */

#define PE_PCS_FAHUD_UTM_39N           23239 /* Fahud UTM Zone 39N            */
#define PE_PCS_FAHUD_UTM_40N           23240 /* Fahud UTM Zone 40N            */
#define PE_PCS_FD_1958_IRAQ             3200 /* Final Datum 1958 Iraq         */
#define PE_PCS_GAROUA_UTM_33N          23433 /* Garoua UTM Zone 33N           */
#define PE_PCS_GGRS_1987_GREEK_GRID     2100  /* Greek Grid                   */

/* Australia */
#define PE_PCS_GDA_1994_MGA_48         28348 /* GDA 1994 MGA Zone 48          */
#define PE_PCS_GDA_1994_MGA_49         28349 /* GDA 1994 MGA Zone 49          */
#define PE_PCS_GDA_1994_MGA_50         28350 /* GDA 1994 MGA Zone 50          */
#define PE_PCS_GDA_1994_MGA_51         28351 /* GDA 1994 MGA Zone 51          */
#define PE_PCS_GDA_1994_MGA_52         28352 /* GDA 1994 MGA Zone 52          */
#define PE_PCS_GDA_1994_MGA_53         28353 /* GDA 1994 MGA Zone 53          */
#define PE_PCS_GDA_1994_MGA_54         28354 /* GDA 1994 MGA Zone 54          */
#define PE_PCS_GDA_1994_MGA_55         28355 /* GDA 1994 MGA Zone 55          */
#define PE_PCS_GDA_1994_MGA_56         28356 /* GDA 1994 MGA Zone 56          */
#define PE_PCS_GDA_1994_MGA_57         28357 /* GDA 1994 MGA Zone 57          */
#define PE_PCS_GDA_1994_MGA_58         28358 /* GDA 1994 MGA Zone 58          */


#define PE_PCS_GRENADA_1953_BRITISH_W_INDIES  2003 /* Grenada 1953 British W Indies Grid */
#define PE_PCS_HANOI_1972_GK_106_NE     2093 /* Hanoi 1972 GK 106 NE          */
#define PE_PCS_HANOI_1972_GK_18         2044 /* Hanoi 1972 Gauss-Kruger zone 18 */
#define PE_PCS_HANOI_1972_GK_19         2045 /* Hanoi 1972 Gauss-Kruger zone 19 */
#define PE_PCS_HITO_XVIII_1963_ARGENTINA_2  2083 /* Hito XVIII Argentina zone 2 */
#define PE_PCS_HITO_XVIII_1963_UTM_19S      2084 /* Hito XVIII UTM zone 19S   */
#define PE_PCS_HUNGARIAN_1972_EOV  23700 /* Hungarian 1972 Egyseges Orszagos Vetuleti */
#define PE_PCS_INDIAN_1954_UTM_46N     23946 /* Indian 1954 UTM zone 46N      */
#define PE_PCS_INDIAN_1954_UTM_47N     23947 /* Indian 1954 UTM Zone 47N      */
#define PE_PCS_INDIAN_1954_UTM_48N     23948 /* Indian 1954 UTM Zone 48N      */
#define PE_PCS_INDIAN_1960_TM_106NE     3176 /* Indian 1960 TM 106NE          */
#define PE_PCS_INDIAN_1960_UTM_48N      3148 /* Indian 1960 UTM Zone 48N      */
#define PE_PCS_INDIAN_1960_UTM_49N      3149 /* Indian 1960 UTM Zone 49N      */
#define PE_PCS_INDIAN_1975_UTM_47N     24047 /* Indian 1975 UTM Zone 47N      */
#define PE_PCS_INDIAN_1975_UTM_48N     24048 /* Indian 1975 UTM Zone 48N      */
#define PE_PCS_ID_1974_UTM_46N          23846 /* Indonesian 1974 UTM Zone 46N */
#define PE_PCS_ID_1974_UTM_47N          23847 /* Indonesian 1974 UTM Zone 47N */
#define PE_PCS_ID_1974_UTM_48N          23848 /* Indonesian 1974 UTM Zone 48N */
#define PE_PCS_ID_1974_UTM_49N          23849 /* Indonesian 1974 UTM Zone 49N */
#define PE_PCS_ID_1974_UTM_50N          23850 /* Indonesian 1974 UTM Zone 50N */
#define PE_PCS_ID_1974_UTM_51N          23851 /* Indonesian 1974 UTM Zone 51N */
#define PE_PCS_ID_1974_UTM_52N          23852 /* Indonesian 1974 UTM Zone 52N */
#define PE_PCS_ID_1974_UTM_53N          23853 /* Indonesian 1974 UTM Zone 53N */
#define PE_PCS_ID_1974_UTM_46S          23886 /* Indonesian 1974 UTM Zone 46S */
#define PE_PCS_ID_1974_UTM_47S          23887 /* Indonesian 1974 UTM Zone 47S */
#define PE_PCS_ID_1974_UTM_48S          23888 /* Indonesian 1974 UTM Zone 48S */
#define PE_PCS_ID_1974_UTM_49S          23889 /* Indonesian 1974 UTM Zone 49S */
#define PE_PCS_ID_1974_UTM_50S          23890 /* Indonesian 1974 UTM Zone 50S */
#define PE_PCS_ID_1974_UTM_51S          23891 /* Indonesian 1974 UTM Zone 51S */
#define PE_PCS_ID_1974_UTM_52S          23892 /* Indonesian 1974 UTM Zone 52S */
#define PE_PCS_ID_1974_UTM_53S          23893 /* Indonesian 1974 UTM Zone 53S */
#define PE_PCS_ID_1974_UTM_54S          23894 /* Indonesian 1974 UTM Zone 54S */
#define PE_PCS_INDONESIAN_1974_UTM_46N  23846 /* Indonesian 1974 UTM Zone 46N */
#define PE_PCS_INDONESIAN_1974_UTM_47N  23847 /* Indonesian 1974 UTM Zone 47N */
#define PE_PCS_INDONESIAN_1974_UTM_48N  23848 /* Indonesian 1974 UTM Zone 48N */
#define PE_PCS_INDONESIAN_1974_UTM_49N  23849 /* Indonesian 1974 UTM Zone 49N */
#define PE_PCS_INDONESIAN_1974_UTM_50N  23850 /* Indonesian 1974 UTM Zone 50N */
#define PE_PCS_INDONESIAN_1974_UTM_51N  23851 /* Indonesian 1974 UTM Zone 51N */
#define PE_PCS_INDONESIAN_1974_UTM_52N  23852 /* Indonesian 1974 UTM Zone 52N */
#define PE_PCS_INDONESIAN_1974_UTM_53N  23853 /* Indonesian 1974 UTM Zone 53N */
#define PE_PCS_INDONESIAN_1974_UTM_46S  23886 /* Indonesian 1974 UTM Zone 46S */
#define PE_PCS_INDONESIAN_1974_UTM_47S  23887 /* Indonesian 1974 UTM Zone 47S */
#define PE_PCS_INDONESIAN_1974_UTM_48S  23888 /* Indonesian 1974 UTM Zone 48S */
#define PE_PCS_INDONESIAN_1974_UTM_49S  23889 /* Indonesian 1974 UTM Zone 49S */
#define PE_PCS_INDONESIAN_1974_UTM_50S  23890 /* Indonesian 1974 UTM Zone 50S */
#define PE_PCS_INDONESIAN_1974_UTM_51S  23891 /* Indonesian 1974 UTM Zone 51S */
#define PE_PCS_INDONESIAN_1974_UTM_52S  23892 /* Indonesian 1974 UTM Zone 52S */
#define PE_PCS_INDONESIAN_1974_UTM_53S  23893 /* Indonesian 1974 UTM Zone 53S */
#define PE_PCS_INDONESIAN_1974_UTM_54S  23894 /* Indonesian 1974 UTM Zone 54S */
#define PE_PCS_IRENET95_IRISH_TM        2157 /* IRENET95 Irish TM             */
#define PE_PCS_IRENET95_UTM_29N         2158 /* IRENET95 UTM zone 29N         */
#define PE_PCS_ISRAEL_ISRAEL_TM_GRID    2039 /* Israel Israel TM Grid         */
#define PE_PCS_JAD_1969_JAMAICA_GRID   24200 /* Jamaica Grid                  */
#define PE_PCS_JAMAICA_1875_OLD_GRID   24100 /* Jamaica 1875 Old Grid         */
#define PE_PCS_KALIANPUR_1880_INDIA_0     24370 /* Kalianpur 1880 India Zone 0   */
#define PE_PCS_KALIANPUR_1880_INDIA_I     24371 /* Kalianpur 1880 India Zone I   */
#define PE_PCS_KALIANPUR_1880_INDIA_IIA   24372 /* Kalianpur 1880 India Zone IIa */
#define PE_PCS_KALIANPUR_1880_INDIA_IIB   24382 /* Kalianpur 1880 India Zone IIb */
#define PE_PCS_KALIANPUR_1880_INDIA_III   24373 /* Kalianpur 1880 India Zone III */
#define PE_PCS_KALIANPUR_1880_INDIA_IV    24374 /* Kalianpur 1880 India Zone IV  */
#define PE_PCS_KALIANPUR_1937_INDIA_IIB   24375 /* Kalianpur 1937 India Zone IIb */
#define PE_PCS_KALIANPUR_1962_INDIA_I     24376 /* Kalianpur 1962 India Zone I   */
#define PE_PCS_KALIANPUR_1962_INDIA_IIA   24377 /* Kalianpur 1962 India Zone IIa */
#define PE_PCS_KALIANPUR_1975_INDIA_I     24378 /* Kalianpur 1975 India Zone I   */
#define PE_PCS_KALIANPUR_1975_INDIA_IIA   24379 /* Kalianpur 1975 India Zone IIa */
#define PE_PCS_KALIANPUR_1975_INDIA_IIB   24380 /* Kalianpur 1975 India Zone IIb */
#define PE_PCS_KALIANPUR_1975_INDIA_III   24381 /* Kalianpur 1975 India Zone III */
#define PE_PCS_KALIANPUR_1975_INDIA_IV    24383 /* Kalianpur 1975 India Zone IV  */
#define PE_PCS_KALIANPUR_1937_UTM_45N     24305 /* Kalianpur 1937 Zone 45N    */
#define PE_PCS_KALIANPUR_1937_UTM_46N     24306 /* Kalianpur 1937 Zone 46N    */
#define PE_PCS_KALIANPUR_1962_UTM_41N     24311 /* Kalianpur 1962 Zone 41N    */
#define PE_PCS_KALIANPUR_1962_UTM_42N     24312 /* Kalianpur 1962 Zone 42N    */
#define PE_PCS_KALIANPUR_1962_UTM_43N     24313 /* Kalianpur 1962 Zone 43N    */
#define PE_PCS_KALIANPUR_1975_UTM_42N     24342 /* Kalianpur 1975 Zone 42N    */
#define PE_PCS_KALIANPUR_1975_UTM_43N     24343 /* Kalianpur 1975 Zone 43N    */
#define PE_PCS_KALIANPUR_1975_UTM_44N     24344 /* Kalianpur 1975 Zone 44N    */
#define PE_PCS_KALIANPUR_1975_UTM_45N     24345 /* Kalianpur 1975 Zone 45N    */
#define PE_PCS_KALIANPUR_1975_UTM_46N     24346 /* Kalianpur 1975 Zone 46N    */
#define PE_PCS_KALIANPUR_1975_UTM_47N     24347 /* Kalianpur 1975 Zone 47N    */
#define PE_PCS_KERTAU_SINGAPORE_GRID   24500 /* Kertau Singapore grid         */
#define PE_PCS_KERTAU_UTM_47N          24547 /* Kertau UTM Zone 47N           */
#define PE_PCS_KERTAU_UTM_48N          24548 /* Kertau UTM Zone 48N           */
#define PE_PCS_KKJ_FINLAND_1            2391 /* Finland Zone 1                */
#define PE_PCS_KKJ_FINLAND_2            2392 /* Finland Zone 2                */
#define PE_PCS_KKJ_FINLAND_3            2393 /* Finland Zone 3                */
#define PE_PCS_KKJ_FINLAND_4            2394 /* Finland Zone 4                */
#define PE_PCS_KOC_LAMBERT             24600 /* Kuwait Oil Co - Lambert       */
#define PE_PCS_KOREAN_1985_EAST_BELT    2096 /* Korean 1985 Korea East Belt   */
#define PE_PCS_KOREAN_1985_CENTRAL_BELT 2097 /* Korean 1985 Korea Central Belt*/
#define PE_PCS_KOREAN_1985_WEST_BELT    2098 /* Korean 1985 Korea West Belt   */
#define PE_PCS_KUDAMS_KTM              31900 /* Kuwait Utility KTM            */
#define PE_PCS_LA_CANOA_UTM_18N        24718 /* La Canoa UTM Zone 18N         */
#define PE_PCS_LA_CANOA_UTM_19N        24719 /* La Canoa UTM Zone 19N         */
#define PE_PCS_LA_CANOA_UTM_20N        24720 /* La Canoa UTM Zone 20N         */
#define PE_PCS_LA_CANOA_UTM_21N        24721 /* La Canoa UTM Zone 21N         */
#define PE_PCS_LAKE_MARACAIBO           2102 /* Lake Maracaibo Grid           */
#define PE_PCS_LAKE_MARACAIBO_LA_ROSA_GRID  2104 /* Lake Maracaibo La Rosa Grid */
#define PE_PCS_LAKE_MARACAIBO_M1        2101 /* Lake Maracaibo Grid M1        */
#define PE_PCS_LAKE_MARACAIBO_M3        2103 /* Lake Maracaibo Grid M3        */
#define PE_PCS_LEIGON_GHANA_GRID       25000 /* Ghana Metre Grid              */
#define PE_PCS_LIETUVOS_KOORDINACIU_SISTEMA 2600 /* LKS1994                   */
#define PE_PCS_LISBON_PORTUGUESE_GRID  20790 /* Portuguese National Grid      */
#define PE_PCS_LOCODJO_1965_TM_5_NW     2164 /* Locodjo 1965 TM 5 NW          */
#define PE_PCS_LOCODJO_1965_UTM_29N     2042 /* Locodjo 1965 UTM 29N          */
#define PE_PCS_LOCODJO_1965_UTM_30N     2040 /* Locodjo 1965 UTM 30N          */
#define PE_PCS_LOME_UTM_31N            25231 /* Lome UTM Zone 31N             */
#define PE_PCS_LUZON_PHILIPPINES_I     25391 /* Philippines Zone I            */
#define PE_PCS_LUZON_PHILIPPINES_II    25392 /* Philippines Zone II           */
#define PE_PCS_LUZON_PHILIPPINES_III   25393 /* Philippines Zone III          */
#define PE_PCS_LUZON_PHILIPPINES_IV    25394 /* Philippines Zone IV           */
#define PE_PCS_LUZON_PHILIPPINES_V     25395 /* Philippines Zone V            */
#define PE_PCS_MADRID_1870_MADRID_SPAIN 2062 /* Madrid 1870 (Madrid) Spain    */
#define PE_PCS_MALONGO_1987_UTM_32S    25932 /* Malongo 1987 UTM Zone 32S     */
#define PE_PCS_MASSAWA_UTM_37N         26237 /* Massawa UTM Zone 37N          */
#define PE_PCS_MERCHICH_NORD_MAROC     26191 /* Nord Maroc                    */
#define PE_PCS_MERCHICH_SAHARA         26193 /* Sahara                        */
#define PE_PCS_MERCHICH_SUD_MAROC      26192 /* Sud Maroc                     */
#define PE_PCS_MGI_3_DEGREE_GAUSS_5    31265 /* MGI 3 degree Gauss zone 5     */
#define PE_PCS_MGI_3_DEGREE_GAUSS_6    31266 /* MGI 3 degree Gauss zone 6     */
#define PE_PCS_MGI_3_DEGREE_GAUSS_7    31267 /* MGI 3 degree Gauss zone 7     */
#define PE_PCS_MGI_3_DEGREE_GAUSS_8    31268 /* MGI 3 degree Gauss zone 8     */
#define PE_PCS_MGI_AUSTRIA_LAMBERT     31287 /* MGI Austria Lambert           */
#define PE_PCS_MGI_BALKANS_5           31275 /* MGI Balkans Zone 5            */
#define PE_PCS_MGI_BALKANS_6           31276 /* MGI Balkans Zone 6            */
#define PE_PCS_MGI_BALKANS_7           31277 /* MGI Balkans Zone 7            */
#define PE_PCS_MGI_BALKANS_8           31278 /* MGI Balkans Zone 8            */
#define PE_PCS_MGI_FERRO_AUSTRIA_WEST     31281 /* Austria (Ferro) West Zone  */
#define PE_PCS_MGI_FERRO_AUSTRIA_CENTRAL  31282 /* Austria (Ferro) Cent. Zone */
#define PE_PCS_MGI_FERRO_AUSTRIA_EAST     31283 /* Austria (Ferro) East Zone  */
#define PE_PCS_MGI_M28                 31284 /* MGI Austria M28 Zone          */
#define PE_PCS_MGI_M31                 31285 /* MGI Austria M31 Zone          */
#define PE_PCS_MGI_M34                 31286 /* MGI Austria M34 Zone          */
#define PE_PCS_MHAST_UTM_32S           26432 /* Mhast UTM Zone 32S            */
#define PE_PCS_MINNA_NIGERIA_EAST_BELT 26393 /* Nigeria East Belt             */
#define PE_PCS_MINNA_NIGERIA_MID_BELT  26392 /* Nigeria Mid Belt              */
#define PE_PCS_MINNA_NIGERIA_WEST_BELT 26391 /* Nigeria West Belt             */
#define PE_PCS_MINNA_UTM_31N           26331 /* Minna UTM Zone 31N            */
#define PE_PCS_MINNA_UTM_32N           26332 /* Minna UTM Zone 32N            */
#define PE_PCS_MONTE_MARIO_ROME_ITALY_1   26591 /* Monte Mario (Rome) Italy 1 */
#define PE_PCS_MONTE_MARIO_ROME_ITALY_2   26592 /* Monte Mario (Rome) Italy 2 */
#define PE_PCS_MONTSERRAT_1958_BRITISH_W_INDIES  2004 /* Montserrat 1958 British W Indies Grid */
#define PE_PCS_MOUNT_DILLON_TOBAGO_GRID 2066 /* Mount Dillon Tobago Grid      */
#define PE_PCS_MOZNET_UTM_36S           3036 /* Moznet UTM Zone 36S           */
#define PE_PCS_MOZNET_UTM_37S           3037 /* Moznet UTM Zone 37S           */
#define PE_PCS_MPORALOKO_UTM_32N       26632 /* M'poraloko UTM Zone 32N       */
#define PE_PCS_MPORALOKO_UTM_32S       26692 /* M'poraloko UTM Zone 32S       */

/* North America Datum 1927 */
#define PE_PCS_NAD_1927_BLM_14N        32074 /* NAD 1927 BLM Zone 14N         */
#define PE_PCS_NAD_1927_BLM_15N        32075 /* NAD 1927 BLM Zone 15N         */
#define PE_PCS_NAD_1927_BLM_16N        32076 /* NAD 1927 BLM Zone 16N         */
#define PE_PCS_NAD_1927_BLM_17N        32077 /* NAD 1927 BLM Zone 17N         */
#define PE_PCS_NAD_1927_CUBA_NORTE      2085 /* NAD 1927 Cuba Norte           */
#define PE_PCS_NAD_1927_CUBA_SUR        2086 /* NAD 1927 Cuba Sur             */
#define PE_PCS_NAD_1927_GUATEMALA_NORTE   32061 /* NAD 1927 Guatemala Norte   */
#define PE_PCS_NAD_1927_GUATEMALA_SUR     32062 /* NAD 1927 Guatemala Sur     */
#define PE_PCS_NAD_1927_UTM_3N         26703 /* NAD 1927 UTM Zone 3N          */
#define PE_PCS_NAD_1927_UTM_4N         26704 /* NAD 1927 UTM Zone 4N          */
#define PE_PCS_NAD_1927_UTM_5N         26705 /* NAD 1927 UTM Zone 5N          */
#define PE_PCS_NAD_1927_UTM_6N         26706 /* NAD 1927 UTM Zone 6N          */
#define PE_PCS_NAD_1927_UTM_7N         26707 /* NAD 1927 UTM Zone 7N          */
#define PE_PCS_NAD_1927_UTM_8N         26708 /* NAD 1927 UTM Zone 8N          */
#define PE_PCS_NAD_1927_UTM_9N         26709 /* NAD 1927 UTM Zone 9N          */
#define PE_PCS_NAD_1927_UTM_10N        26710 /* NAD 1927 UTM Zone 10N         */
#define PE_PCS_NAD_1927_UTM_11N        26711 /* NAD 1927 UTM Zone 11N         */
#define PE_PCS_NAD_1927_UTM_12N        26712 /* NAD 1927 UTM Zone 12N         */
#define PE_PCS_NAD_1927_UTM_13N        26713 /* NAD 1927 UTM Zone 13N         */
#define PE_PCS_NAD_1927_UTM_14N        26714 /* NAD 1927 UTM Zone 14N         */
#define PE_PCS_NAD_1927_UTM_15N        26715 /* NAD 1927 UTM Zone 15N         */
#define PE_PCS_NAD_1927_UTM_16N        26716 /* NAD 1927 UTM Zone 16N         */
#define PE_PCS_NAD_1927_UTM_17N        26717 /* NAD 1927 UTM Zone 17N         */
#define PE_PCS_NAD_1927_UTM_18N        26718 /* NAD 1927 UTM Zone 18N         */
#define PE_PCS_NAD_1927_UTM_19N        26719 /* NAD 1927 UTM Zone 19N         */
#define PE_PCS_NAD_1927_UTM_20N        26720 /* NAD 1927 UTM Zone 20N         */
#define PE_PCS_NAD_1927_UTM_21N        26721 /* NAD 1927 UTM Zone 21N         */
#define PE_PCS_NAD_1927_UTM_22N        26722 /* NAD 1927 UTM Zone 22N         */

/* -- Canada */
#define PE_PCS_NAD_1927_CGQ77_MTM_2_SCOPQ  2008 /* NAD 1927 SCoPQ Zone 2      */
#define PE_PCS_NAD_1927_CGQ77_MTM_3_SCOPQ  2009 /* NAD 1927 SCoPQ Zone 3      */
#define PE_PCS_NAD_1927_CGQ77_MTM_4_SCOPQ  2010 /* NAD 1927 SCoPQ Zone 4      */
#define PE_PCS_NAD_1927_CGQ77_MTM_5_SCOPQ  2011 /* NAD 1927 SCoPQ Zone 5      */
#define PE_PCS_NAD_1927_CGQ77_MTM_6_SCOPQ  2012 /* NAD 1927 SCoPQ Zone 6      */
#define PE_PCS_NAD_1927_CGQ77_MTM_7_SCOPQ  2013 /* NAD 1927 SCoPQ Zone 7      */
#define PE_PCS_NAD_1927_CGQ77_MTM_8_SCOPQ  2014 /* NAD 1927 SCoPQ Zone 8      */
#define PE_PCS_NAD_1927_CGQ77_MTM_9_SCOPQ  2015 /* NAD 1927 SCoPQ Zone 9      */
#define PE_PCS_NAD_1927_CGQ77_MTM_10_SCOPQ 2016 /* NAD 1927 SCoPQ Zone 10     */
#define PE_PCS_NAD_1927_CGQ77_QUEBEC_LAMBERT  2138 /* NAD 1927 CGQ77 Quebec Lambert */
#define PE_PCS_NAD_1927_CGQ77_UTM_17N     2031 /* NAD 1927 (CGQ77) UTM Zone 17*/
#define PE_PCS_NAD_1927_CGQ77_UTM_18N     2032 /* NAD 1927 (CGQ77) UTM Zone 18*/
#define PE_PCS_NAD_1927_CGQ77_UTM_19N     2033 /* NAD 1927 (CGQ77) UTM Zone 19*/
#define PE_PCS_NAD_1927_CGQ77_UTM_20N     2034 /* NAD 1927 (CGQ77) UTM Zone 20*/
#define PE_PCS_NAD_1927_CGQ77_UTM_21N     2035 /* NAD 1927 (CGQ77) UTM Zone 21*/
#define PE_PCS_NAD_1927_DEF_1976_MTM_8    2017 /* NAD 1927 (1976) MTM Zone 8  */
#define PE_PCS_NAD_1927_DEF_1976_MTM_9    2018 /* NAD 1927 (1976) MTM Zone 9  */
#define PE_PCS_NAD_1927_DEF_1976_MTM_10   2019 /* NAD 1927 (1976) MTM Zone 10 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_11   2020 /* NAD 1927 (1976) MTM Zone 11 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_12   2021 /* NAD 1927 (1976) MTM Zone 12 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_13   2022 /* NAD 1927 (1976) MTM Zone 13 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_14   2023 /* NAD 1927 (1976) MTM Zone 14 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_15   2024 /* NAD 1927 (1976) MTM Zone 15 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_16   2025 /* NAD 1927 (1976) MTM Zone 16 */
#define PE_PCS_NAD_1927_DEF_1976_MTM_17   2026 /* NAD 1927 (1976) MTM Zone 17 */
#define PE_PCS_NAD_1927_DEF_1976_UTM_15N  2027 /* NAD 1927 (1976) UTM Zone 15 */
#define PE_PCS_NAD_1927_DEF_1976_UTM_16N  2028 /* NAD 1927 (1976) UTM Zone 16 */
#define PE_PCS_NAD_1927_DEF_1976_UTM_17N  2029 /* NAD 1927 (1976) UTM Zone 17 */
#define PE_PCS_NAD_1927_DEF_1976_UTM_18N  2030 /* NAD 1927 (1976) UTM Zone 18 */
#define PE_PCS_NAD_1927_MTM_1   32081 /* NAD 1927 MTM Zone 1  - Newfoundland  */
#define PE_PCS_NAD_1927_MTM_2   32082 /* NAD 1927 MTM Zone 2  - Newfoundland  */
#define PE_PCS_NAD_1927_MTM_3   32083 /* NAD 1927 MTM Zone 3  - Newfoundland  */
#define PE_PCS_NAD_1927_MTM_4   32084 /* NAD 1927 MTM Zone 4  - Newfoundland  */
#define PE_PCS_NAD_1927_MTM_5   32085 /* NAD 1927 MTM Zone 5  - Newfoundland  */
#define PE_PCS_NAD_1927_MTM_6   32086 /* NAD 1927 MTM Zone 6  - Newfoundland  */
#define PE_PCS_NAD_1927_QUEBEC_LAMBERT 32098 /* NAD 1927 Quebec Lambert       */

/* -- United States of America */
/*       NAD 1927 State Plane Coordinate System (in US Survey Feet)           */
#define PE_PCS_NAD_1927_AL_E    26729 /* NAD 1927 SPCS Zone Alabama East      */
#define PE_PCS_NAD_1927_AL_W    26730 /* NAD 1927 SPCS Zone Alabama West      */
#define PE_PCS_NAD_1927_AK_1    26731 /* NAD 1927 SPCS Zone Alaska 1          */
#define PE_PCS_NAD_1927_AK_2    26732 /* NAD 1927 SPCS Zone Alaska 2          */
#define PE_PCS_NAD_1927_AK_3    26733 /* NAD 1927 SPCS Zone Alaska 3          */
#define PE_PCS_NAD_1927_AK_4    26734 /* NAD 1927 SPCS Zone Alaska 4          */
#define PE_PCS_NAD_1927_AK_5    26735 /* NAD 1927 SPCS Zone Alaska 5          */
#define PE_PCS_NAD_1927_AK_6    26736 /* NAD 1927 SPCS Zone Alaska 6          */
#define PE_PCS_NAD_1927_AK_7    26737 /* NAD 1927 SPCS Zone Alaska 7          */
#define PE_PCS_NAD_1927_AK_8    26738 /* NAD 1927 SPCS Zone Alaska 8          */
#define PE_PCS_NAD_1927_AK_9    26739 /* NAD 1927 SPCS Zone Alaska 9          */
#define PE_PCS_NAD_1927_AK_10   26740 /* NAD 1927 SPCS Zone Alaska 10         */
#define PE_PCS_NAD_1927_AZ_E    26748 /* NAD 1927 SPCS Zone Arizona East      */
#define PE_PCS_NAD_1927_AZ_C    26749 /* NAD 1927 SPCS Zone Arizona Central   */
#define PE_PCS_NAD_1927_AZ_W    26750 /* NAD 1927 SPCS Zone Arizona West      */
#define PE_PCS_NAD_1927_AR_N    26751 /* NAD 1927 SPCS Zone Arkansas North    */
#define PE_PCS_NAD_1927_AR_S    26752 /* NAD 1927 SPCS Zone Arkansas South    */
#define PE_PCS_NAD_1927_CA_I    26741 /* NAD 1927 SPCS Zone California I      */
#define PE_PCS_NAD_1927_CA_II   26742 /* NAD 1927 SPCS Zone California II     */
#define PE_PCS_NAD_1927_CA_III  26743 /* NAD 1927 SPCS Zone California III    */
#define PE_PCS_NAD_1927_CA_IV   26744 /* NAD 1927 SPCS Zone California IV     */
#define PE_PCS_NAD_1927_CA_V    26745 /* NAD 1927 SPCS Zone California V      */
#define PE_PCS_NAD_1927_CA_VI   26746 /* NAD 1927 SPCS Zone California VI     */
#define PE_PCS_NAD_1927_CA_VII  26747 /* NAD 1927 SPCS Zone California VII    */
#define PE_PCS_NAD_1927_CO_N    26753 /* NAD 1927 SPCS Zone Colorado North    */
#define PE_PCS_NAD_1927_CO_C    26754 /* NAD 1927 SPCS Zone Colorado Central  */
#define PE_PCS_NAD_1927_CO_S    26755 /* NAD 1927 SPCS Zone Colorado South    */
#define PE_PCS_NAD_1927_CT      26756 /* NAD 1927 SPCS Zone Connecticut       */
#define PE_PCS_NAD_1927_DE      26757 /* NAD 1927 SPCS Zone Delaware          */
#define PE_PCS_NAD_1927_FL_E    26758 /* NAD 1927 SPCS Zone Florida East      */
#define PE_PCS_NAD_1927_FL_W    26759 /* NAD 1927 SPCS Zone Florida West      */
#define PE_PCS_NAD_1927_FL_N    26760 /* NAD 1927 SPCS Zone Florida North     */
#define PE_PCS_NAD_1927_GA_E    26766 /* NAD 1927 SPCS Zone Georgia East      */
#define PE_PCS_NAD_1927_GA_W    26767 /* NAD 1927 SPCS Zone Georgia West      */
#define PE_PCS_NAD_1927_HI_1    26761 /* NAD 1927 SPCS Zone Hawaii 1          */
#define PE_PCS_NAD_1927_HI_2    26762 /* NAD 1927 SPCS Zone Hawaii 2          */
#define PE_PCS_NAD_1927_HI_3    26763 /* NAD 1927 SPCS Zone Hawaii 3          */
#define PE_PCS_NAD_1927_HI_4    26764 /* NAD 1927 SPCS Zone Hawaii 4          */
#define PE_PCS_NAD_1927_HI_5    26765 /* NAD 1927 SPCS Zone Hawaii 5          */
#define PE_PCS_NAD_1927_ID_E    26768 /* NAD 1927 SPCS Zone Idaho East        */
#define PE_PCS_NAD_1927_ID_C    26769 /* NAD 1927 SPCS Zone Idaho Central     */
#define PE_PCS_NAD_1927_ID_W    26770 /* NAD 1927 SPCS Zone Idaho West        */
#define PE_PCS_NAD_1927_IL_E    26771 /* NAD 1927 SPCS Zone Illinois East     */
#define PE_PCS_NAD_1927_IL_W    26772 /* NAD 1927 SPCS Zone Illinois West     */
#define PE_PCS_NAD_1927_IN_E    26773 /* NAD 1927 SPCS Zone Indiana East      */
#define PE_PCS_NAD_1927_IN_W    26774 /* NAD 1927 SPCS Zone Indiana West      */
#define PE_PCS_NAD_1927_IA_N    26775 /* NAD 1927 SPCS Zone Iowa North        */
#define PE_PCS_NAD_1927_IA_S    26776 /* NAD 1927 SPCS Zone Iowa South        */
#define PE_PCS_NAD_1927_KS_N    26777 /* NAD 1927 SPCS Zone Kansas North      */
#define PE_PCS_NAD_1927_KS_S    26778 /* NAD 1927 SPCS Zone Kansas South      */
#define PE_PCS_NAD_1927_KY_N    26779 /* NAD 1927 SPCS Zone Kentucky North    */
#define PE_PCS_NAD_1927_KY_S    26780 /* NAD 1927 SPCS Zone Kentucky South    */
#define PE_PCS_NAD_1927_LA_N    26781 /* NAD 1927 SPCS Zone Louisiana North   */
#define PE_PCS_NAD_1927_LA_S    26782 /* NAD 1927 SPCS Zone Louisiana South   */
#define PE_PCS_NAD_1927_ME_E    26783 /* NAD 1927 SPCS Zone Maine East        */
#define PE_PCS_NAD_1927_ME_W    26784 /* NAD 1927 SPCS Zone Maine West        */
#define PE_PCS_NAD_1927_MD      26785 /* NAD 1927 SPCS Zone Maryland          */
#define PE_PCS_NAD_1927_MA_M    26786 /* NAD 1927 SPCS Zone Mass. Mainland    */
#define PE_PCS_NAD_1927_MA_I    26787 /* NAD 1927 SPCS Zone Mass. Island      */
#define PE_PCS_NAD_1927_MI_N    26788 /* NAD 1927 SPCS Zone Michigan North    */
#define PE_PCS_NAD_1927_MI_C    26789 /* NAD 1927 SPCS Zone Michigan Central  */
#define PE_PCS_NAD_1927_MI_S    26790 /* NAD 1927 SPCS Zone Michigan South    */
#define PE_PCS_NAD_1927_MN_N    26791 /* NAD 1927 SPCS Zone Minnesota North   */
#define PE_PCS_NAD_1927_MN_C    26792 /* NAD 1927 SPCS Zone Minnesota Central */
#define PE_PCS_NAD_1927_MN_S    26793 /* NAD 1927 SPCS Zone Minnesota South   */
#define PE_PCS_NAD_1927_MS_E    26794 /* NAD 1927 SPCS Zone Mississippi East  */
#define PE_PCS_NAD_1927_MS_W    26795 /* NAD 1927 SPCS Zone Mississippi West  */
#define PE_PCS_NAD_1927_MO_E    26796 /* NAD 1927 SPCS Zone Missouri East     */
#define PE_PCS_NAD_1927_MO_C    26797 /* NAD 1927 SPCS Zone Missouri Central  */
#define PE_PCS_NAD_1927_MO_W    26798 /* NAD 1927 SPCS Zone Missouri West     */
#define PE_PCS_NAD_1927_MT_N    32001 /* NAD 1927 SPCS Zone Montana North     */
#define PE_PCS_NAD_1927_MT_C    32002 /* NAD 1927 SPCS Zone Montana Central   */
#define PE_PCS_NAD_1927_MT_S    32003 /* NAD 1927 SPCS Zone Montana South     */
#define PE_PCS_NAD_1927_NE_N    32005 /* NAD 1927 SPCS Zone Nebraska North    */
#define PE_PCS_NAD_1927_NE_S    32006 /* NAD 1927 SPCS Zone Nebraska South    */
#define PE_PCS_NAD_1927_NV_E    32007 /* NAD 1927 SPCS Zone Nevada East       */
#define PE_PCS_NAD_1927_NV_C    32008 /* NAD 1927 SPCS Zone Nevada Central    */
#define PE_PCS_NAD_1927_NV_W    32009 /* NAD 1927 SPCS Zone Nevada West       */
#define PE_PCS_NAD_1927_NH      32010 /* NAD 1927 SPCS Zone New Hampshire     */
#define PE_PCS_NAD_1927_NJ      32011 /* NAD 1927 SPCS Zone New Jersey        */
#define PE_PCS_NAD_1927_NM_E    32012 /* NAD 1927 SPCS Zone New Mexico East   */
#define PE_PCS_NAD_1927_NM_C    32013 /* NAD 1927 SPCS Zone New Mexico Cent.  */
#define PE_PCS_NAD_1927_NM_W    32014 /* NAD 1927 SPCS Zone New Mexico West   */
#define PE_PCS_NAD_1927_NY_E    32015 /* NAD 1927 SPCS Zone New York East     */
#define PE_PCS_NAD_1927_NY_C    32016 /* NAD 1927 SPCS Zone New York Central  */
#define PE_PCS_NAD_1927_NY_W    32017 /* NAD 1927 SPCS Zone New York West     */
#define PE_PCS_NAD_1927_NY_LI   32018 /* NAD 1927 SPCS Zone NY Long Island    */
#define PE_PCS_NAD_1927_NC      32019 /* NAD 1927 SPCS Zone North Carolina    */
#define PE_PCS_NAD_1927_ND_N    32020 /* NAD 1927 SPCS Zone North Dakota N    */
#define PE_PCS_NAD_1927_ND_S    32021 /* NAD 1927 SPCS Zone North Dakota S    */
#define PE_PCS_NAD_1927_OH_N    32022 /* NAD 1927 SPCS Zone Ohio North        */
#define PE_PCS_NAD_1927_OH_S    32023 /* NAD 1927 SPCS Zone Ohio South        */
#define PE_PCS_NAD_1927_OK_N    32024 /* NAD 1927 SPCS Zone Oklahoma North    */
#define PE_PCS_NAD_1927_OK_S    32025 /* NAD 1927 SPCS Zone Oklahoma South    */
#define PE_PCS_NAD_1927_OR_N    32026 /* NAD 1927 SPCS Zone Oregon North      */
#define PE_PCS_NAD_1927_OR_S    32027 /* NAD 1927 SPCS Zone Oregon South      */
#define PE_PCS_NAD_1927_PA_N    32028 /* NAD 1927 SPCS Zone Pennsylvania N    */
#define PE_PCS_NAD_1927_PA_S    32029 /* NAD 1927 SPCS Zone Pennsylvania S    */
#define PE_PCS_NAD_1927_RI      32030 /* NAD 1927 SPCS Zone Rhode Island      */
#define PE_PCS_NAD_1927_SC_N    32031 /* NAD 1927 SPCS Zone South Carolina N  */
#define PE_PCS_NAD_1927_SC_S    32033 /* NAD 1927 SPCS Zone South Carolina S  */
#define PE_PCS_NAD_1927_SD_N    32034 /* NAD 1927 SPCS Zone South Dakota N    */
#define PE_PCS_NAD_1927_SD_S    32035 /* NAD 1927 SPCS Zone South Dakota S    */
#define PE_PCS_NAD_1927_TN      32036 /* NAD 1927 SPCS Zone Tennessee         */
#define PE_PCS_NAD_1927_TX_N    32037 /* NAD 1927 SPCS Zone Texas North       */
#define PE_PCS_NAD_1927_TX_NC   32038 /* NAD 1927 SPCS Zone Texas North Cent. */
#define PE_PCS_NAD_1927_TX_C    32039 /* NAD 1927 SPCS Zone Texas Central     */
#define PE_PCS_NAD_1927_TX_SC   32040 /* NAD 1927 SPCS Zone Texas South Cent. */
#define PE_PCS_NAD_1927_TX_S    32041 /* NAD 1927 SPCS Zone Texas South       */
#define PE_PCS_NAD_1927_UT_N    32042 /* NAD 1927 SPCS Zone Utah North        */
#define PE_PCS_NAD_1927_UT_C    32043 /* NAD 1927 SPCS Zone Utah Central      */
#define PE_PCS_NAD_1927_UT_S    32044 /* NAD 1927 SPCS Zone Utah South        */
#define PE_PCS_NAD_1927_VT      32045 /* NAD 1927 SPCS Zone Vermont           */
#define PE_PCS_NAD_1927_VA_N    32046 /* NAD 1927 SPCS Zone Virginia North    */
#define PE_PCS_NAD_1927_VA_S    32047 /* NAD 1927 SPCS Zone Virginia South    */
#define PE_PCS_NAD_1927_WA_N    32048 /* NAD 1927 SPCS Zone Washington North  */
#define PE_PCS_NAD_1927_WA_S    32049 /* NAD 1927 SPCS Zone Washington South  */
#define PE_PCS_NAD_1927_WV_N    32050 /* NAD 1927 SPCS Zone West Virginia N   */
#define PE_PCS_NAD_1927_WV_S    32051 /* NAD 1927 SPCS Zone West Virginia S   */
#define PE_PCS_NAD_1927_WI_N    32052 /* NAD 1927 SPCS Zone Wisconsin North   */
#define PE_PCS_NAD_1927_WI_C    32053 /* NAD 1927 SPCS Zone Wisconsin Central */
#define PE_PCS_NAD_1927_WI_S    32054 /* NAD 1927 SPCS Zone Wisconsin South   */
#define PE_PCS_NAD_1927_WY_E    32055 /* NAD 1927 SPCS Zone Wyoming I East    */
#define PE_PCS_NAD_1927_WY_EC   32056 /* NAD 1927 SPCS Zone Wyoming II EC     */
#define PE_PCS_NAD_1927_WY_WC   32057 /* NAD 1927 SPCS Zone Wyoming III WC    */
#define PE_PCS_NAD_1927_WY_W    32058 /* NAD 1927 SPCS Zone Wyoming IV West   */
#define PE_PCS_NAD_1927_PR      32059 /* NAD 1927 SPCS Zone Puerto Rico       */
#define PE_PCS_NAD_1927_VI      32060 /* NAD 1927 SPCS Zone St. Croix         */
#define PE_PCS_NAD_1927_GU      (32061+33000) /* NAD 1927 SPCS Zone Guam      */
#define PE_PCS_NAD_MICH_MI_E_OLD  26801 /* NAD Michigan SPCS Zone Michigan East Old    */
#define PE_PCS_NAD_MICH_MI_C_OLD  26802 /* NAD Michigan SPCS Zone Michigan Central Old */
#define PE_PCS_NAD_MICH_MI_W_OLD  26803 /* NAD Michigan SPCS Zone Michigan West Old    */
#define PE_PCS_NAD_MICH_MI_N      26811 /* NAD Michigan SPCS Zone Michigan North       */
#define PE_PCS_NAD_MICH_MI_C      26812 /* NAD Michigan SPCS Zone Michigan Central     */
#define PE_PCS_NAD_MICH_MI_S      26813 /* NAD Michigan SPCS Zone Michigan South       */
#define PE_PCS_OLD_HAWAIIAN_HI_1    3561 /* Old Hawaiian State Plane Hawaii 1 */
#define PE_PCS_OLD_HAWAIIAN_HI_2    3562 /* Old Hawaiian State Plane Hawaii 2 */
#define PE_PCS_OLD_HAWAIIAN_HI_3    3563 /* Old Hawaiian State Plane Hawaii 3 */
#define PE_PCS_OLD_HAWAIIAN_HI_4    3564 /* Old Hawaiian State Plane Hawaii 4 */
#define PE_PCS_OLD_HAWAIIAN_HI_5    3565 /* Old Hawaiian State Plane Hawaii 5 */
#define PE_PCS_PUERTO_RICO_PR     3991 /* Puerto Rico State Plane Puerto Rico */
#define PE_PCS_PUERTO_RICO_VI     3992 /* Puerto Rico State Plane St. Croix   */
#define PE_PCS_SAMOA_1962_AS  (32062+33000) /* American Samoa 1962 SPCS American Samoa */


/* North American Datum 1983 */
#define PE_PCS_NAD_1983_UTM_3N         26903 /* NAD 1983 UTM Zone 3N          */
#define PE_PCS_NAD_1983_UTM_4N         26904 /* NAD 1983 UTM Zone 4N          */
#define PE_PCS_NAD_1983_UTM_5N         26905 /* NAD 1983 UTM Zone 5N          */
#define PE_PCS_NAD_1983_UTM_6N         26906 /* NAD 1983 UTM Zone 6N          */
#define PE_PCS_NAD_1983_UTM_7N         26907 /* NAD 1983 UTM Zone 7N          */
#define PE_PCS_NAD_1983_UTM_8N         26908 /* NAD 1983 UTM Zone 8N          */
#define PE_PCS_NAD_1983_UTM_9N         26909 /* NAD 1983 UTM Zone 9N          */
#define PE_PCS_NAD_1983_UTM_10N        26910 /* NAD 1983 UTM Zone 10N         */
#define PE_PCS_NAD_1983_UTM_11N        26911 /* NAD 1983 UTM Zone 11N         */
#define PE_PCS_NAD_1983_UTM_12N        26912 /* NAD 1983 UTM Zone 12N         */
#define PE_PCS_NAD_1983_UTM_13N        26913 /* NAD 1983 UTM Zone 13N         */
#define PE_PCS_NAD_1983_UTM_14N        26914 /* NAD 1983 UTM Zone 14N         */
#define PE_PCS_NAD_1983_UTM_15N        26915 /* NAD 1983 UTM Zone 15N         */
#define PE_PCS_NAD_1983_UTM_16N        26916 /* NAD 1983 UTM Zone 16N         */
#define PE_PCS_NAD_1983_UTM_17N        26917 /* NAD 1983 UTM Zone 17N         */
#define PE_PCS_NAD_1983_UTM_18N        26918 /* NAD 1983 UTM Zone 18N         */
#define PE_PCS_NAD_1983_UTM_19N        26919 /* NAD 1983 UTM Zone 19N         */
#define PE_PCS_NAD_1983_UTM_20N        26920 /* NAD 1983 UTM Zone 20N         */
#define PE_PCS_NAD_1983_UTM_21N        26921 /* NAD 1983 UTM Zone 21N         */
#define PE_PCS_NAD_1983_UTM_22N        26922 /* NAD 1983 UTM Zone 22N         */
#define PE_PCS_NAD_1983_UTM_23N        26923 /* NAD 1983 UTM Zone 23N         */

/* -- Canada */
#define PE_PCS_NAD_1983_CSRS98_MTM_2_SCOPQ 2139 /* NAD 1983 CSRS98 MTM SCoPQ Zone 2 */
#define PE_PCS_NAD_1983_CSRS98_MTM_3    2140 /* NAD 1983 CSRS98 MTM Zone 3    */
#define PE_PCS_NAD_1983_CSRS98_MTM_4    2141 /* NAD 1983 CSRS98 MTM Zone 4    */
#define PE_PCS_NAD_1983_CSRS98_MTM_5    2142 /* NAD 1983 CSRS98 MTM Zone 5    */
#define PE_PCS_NAD_1983_CSRS98_MTM_6    2143 /* NAD 1983 CSRS98 MTM Zone 6    */
#define PE_PCS_NAD_1983_CSRS98_MTM_7    2144 /* NAD 1983 CSRS98 MTM Zone 7    */
#define PE_PCS_NAD_1983_CSRS98_MTM_8    2145 /* NAD 1983 CSRS98 MTM Zone 8    */
#define PE_PCS_NAD_1983_CSRS98_MTM_9    2146 /* NAD 1983 CSRS98 MTM Zone 9    */
#define PE_PCS_NAD_1983_CSRS98_MTM_10   2147 /* NAD 1983 CSRS98 MTM Zone 10   */
#define PE_PCS_NAD_1983_CSRS98_NEW_BRUNSWICK  2036 /* NAD 1983 CSRS98 New     */
                                                   /*  Brunswick Stereographic*/
#define PE_PCS_NAD_1983_CSRS98_PEI  2291 /* NAD 1983 CSRS98 Prince Edward Isl */
#define PE_PCS_NAD_1983_CSRS98_UTM_11N  2153 /* NAD 1983 CSRS98 UTM Zone 11N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_12N  2152 /* NAD 1983 CSRS98 UTM Zone 12N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_13N  2151 /* NAD 1983 CSRS98 UTM Zone 13N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_17N  2150 /* NAD 1983 CSRS98 UTM Zone 17N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_18N  2149 /* NAD 1983 CSRS98 UTM Zone 18N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_19N  2037 /* NAD 1983 CSRS98 UTM Zone 19N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_20N  2038 /* NAD 1983 CSRS98 UTM Zone 20N  */
#define PE_PCS_NAD_1983_CSRS98_UTM_21N  2148 /* NAD 1983 CSRS98 UTM Zone 21N  */
#define PE_PCS_NAD_1983_MTM_1          32181 /* NAD 1983 MTM Zone 1    Canada */
#define PE_PCS_NAD_1983_MTM_2          32182 /* NAD 1983 MTM Zone 2    Canada */
#define PE_PCS_NAD_1983_MTM_2_SCOPQ    32180 /* NAD 1983 SCoPQ Zone 2  Quebec */
#define PE_PCS_NAD_1983_MTM_3          32183 /* NAD 1983 MTM Zone 3    Canada */
#define PE_PCS_NAD_1983_MTM_4          32184 /* NAD 1983 MTM Zone 4    Canada */
#define PE_PCS_NAD_1983_MTM_5          32185 /* NAD 1983 MTM Zone 5    Canada */
#define PE_PCS_NAD_1983_MTM_6          32186 /* NAD 1983 MTM Zone 6    Canada */
#define PE_PCS_NAD_1983_MTM_7          32187 /* NAD 1983 MTM Zone 7    Canada */
#define PE_PCS_NAD_1983_MTM_8          32188 /* NAD 1983 MTM Zone 8    Canada */
#define PE_PCS_NAD_1983_MTM_9          32189 /* NAD 1983 MTM Zone 9    Canada */
#define PE_PCS_NAD_1983_MTM_10         32190 /* NAD 1983 MTM Zone 10   Canada */
#define PE_PCS_NAD_1983_MTM_11         32191 /* NAD 1983 MTM Zone 11   Canada */
#define PE_PCS_NAD_1983_MTM_12         32192 /* NAD 1983 MTM Zone 12   Canada */
#define PE_PCS_NAD_1983_MTM_13         32193 /* NAD 1983 MTM Zone 13   Canada */
#define PE_PCS_NAD_1983_MTM_14         32194 /* NAD 1983 MTM Zone 14   Canada */
#define PE_PCS_NAD_1983_MTM_15         32195 /* NAD 1983 MTM Zone 15   Canada */
#define PE_PCS_NAD_1983_MTM_16         32196 /* NAD 1983 MTM Zone 16   Canada */
#define PE_PCS_NAD_1983_MTM_17         32197 /* NAD 1983 MTM Zone 17   Canada */
#define PE_PCS_NAD_1983_QUEBEC_LAMBERT 32198 /* NAD 1983 Quebec Lambert       */

/* -- United States of America */
/*       NAD 1983 State Plane Coordinate System (in Meters)                   */
#define PE_PCS_NAD_1983_AL_E    26929 /* NAD 1983 SPCS Zone Alabama East      */
#define PE_PCS_NAD_1983_AL_W    26930 /* NAD 1983 SPCS Zone Alabama West      */
#define PE_PCS_NAD_1983_AK_1    26931 /* NAD 1983 SPCS Zone Alaska 1          */
#define PE_PCS_NAD_1983_AK_2    26932 /* NAD 1983 SPCS Zone Alaska 2          */
#define PE_PCS_NAD_1983_AK_3    26933 /* NAD 1983 SPCS Zone Alaska 3          */
#define PE_PCS_NAD_1983_AK_4    26934 /* NAD 1983 SPCS Zone Alaska 4          */
#define PE_PCS_NAD_1983_AK_5    26935 /* NAD 1983 SPCS Zone Alaska 5          */
#define PE_PCS_NAD_1983_AK_6    26936 /* NAD 1983 SPCS Zone Alaska 6          */
#define PE_PCS_NAD_1983_AK_7    26937 /* NAD 1983 SPCS Zone Alaska 7          */
#define PE_PCS_NAD_1983_AK_8    26938 /* NAD 1983 SPCS Zone Alaska 8          */
#define PE_PCS_NAD_1983_AK_9    26939 /* NAD 1983 SPCS Zone Alaska 9          */
#define PE_PCS_NAD_1983_AK_10   26940 /* NAD 1983 SPCS Zone Alaska 10         */
#define PE_PCS_NAD_1983_AZ_E    26948 /* NAD 1983 SPCS Zone Arizona East      */
#define PE_PCS_NAD_1983_AZ_C    26949 /* NAD 1983 SPCS Zone Arizona Central   */
#define PE_PCS_NAD_1983_AZ_W    26950 /* NAD 1983 SPCS Zone Arizona West      */
#define PE_PCS_NAD_1983_AR_N    26951 /* NAD 1983 SPCS Zone Arkansas North    */
#define PE_PCS_NAD_1983_AR_S    26952 /* NAD 1983 SPCS Zone Arkansas South    */
#define PE_PCS_NAD_1983_CA_I    26941 /* NAD 1983 SPCS Zone California I      */
#define PE_PCS_NAD_1983_CA_II   26942 /* NAD 1983 SPCS Zone California II     */
#define PE_PCS_NAD_1983_CA_III  26943 /* NAD 1983 SPCS Zone California III    */
#define PE_PCS_NAD_1983_CA_IV   26944 /* NAD 1983 SPCS Zone California IV     */
#define PE_PCS_NAD_1983_CA_V    26945 /* NAD 1983 SPCS Zone California V      */
#define PE_PCS_NAD_1983_CA_VI   26946 /* NAD 1983 SPCS Zone California VI     */
#define PE_PCS_NAD_1983_CO_N    26953 /* NAD 1983 SPCS Zone Colorado North    */
#define PE_PCS_NAD_1983_CO_C    26954 /* NAD 1983 SPCS Zone Colorado Central  */
#define PE_PCS_NAD_1983_CO_S    26955 /* NAD 1983 SPCS Zone Colorado South    */
#define PE_PCS_NAD_1983_CT      26956 /* NAD 1983 SPCS Zone Connecticut       */
#define PE_PCS_NAD_1983_DE      26957 /* NAD 1983 SPCS Zone Delaware          */
#define PE_PCS_NAD_1983_FL_E    26958 /* NAD 1983 SPCS Zone Florida East      */
#define PE_PCS_NAD_1983_FL_W    26959 /* NAD 1983 SPCS Zone Florida West      */
#define PE_PCS_NAD_1983_FL_N    26960 /* NAD 1983 SPCS Zone Florida North     */
#define PE_PCS_NAD_1983_GA_E    26966 /* NAD 1983 SPCS Zone Georgia East      */
#define PE_PCS_NAD_1983_GA_W    26967 /* NAD 1983 SPCS Zone Georgia West      */
#define PE_PCS_NAD_1983_HI_1    26961 /* NAD 1983 SPCS Zone Hawaii Zone 1     */
#define PE_PCS_NAD_1983_HI_2    26962 /* NAD 1983 SPCS Zone Hawaii Zone 2     */
#define PE_PCS_NAD_1983_HI_3    26963 /* NAD 1983 SPCS Zone Hawaii Zone 3     */
#define PE_PCS_NAD_1983_HI_4    26964 /* NAD 1983 SPCS Zone Hawaii Zone 4     */
#define PE_PCS_NAD_1983_HI_5    26965 /* NAD 1983 SPCS Zone Hawaii Zone 5     */
#define PE_PCS_NAD_1983_ID_E    26968 /* NAD 1983 SPCS Zone Idaho East        */
#define PE_PCS_NAD_1983_ID_C    26969 /* NAD 1983 SPCS Zone Idaho Central     */
#define PE_PCS_NAD_1983_ID_W    26970 /* NAD 1983 SPCS Zone Idaho West        */
#define PE_PCS_NAD_1983_IL_E    26971 /* NAD 1983 SPCS Zone Illinois East     */
#define PE_PCS_NAD_1983_IL_W    26972 /* NAD 1983 SPCS Zone Illinois West     */
#define PE_PCS_NAD_1983_IN_E    26973 /* NAD 1983 SPCS Zone Indiana East      */
#define PE_PCS_NAD_1983_IN_W    26974 /* NAD 1983 SPCS Zone Indiana West      */
#define PE_PCS_NAD_1983_IA_N    26975 /* NAD 1983 SPCS Zone Iowa North        */
#define PE_PCS_NAD_1983_IA_S    26976 /* NAD 1983 SPCS Zone Iowa South        */
#define PE_PCS_NAD_1983_KS_N    26977 /* NAD 1983 SPCS Zone Kansas North      */
#define PE_PCS_NAD_1983_KS_S    26978 /* NAD 1983 SPCS Zone Kansas South      */
#define PE_PCS_NAD_1983_KY_N    26979 /* NAD 1983 SPCS Zone Kentucky North    */
#define PE_PCS_NAD_1983_KY_S    26980 /* NAD 1983 SPCS Zone Kentucky South    */
#define PE_PCS_NAD_1983_LA_N    26981 /* NAD 1983 SPCS Zone Louisiana North   */
#define PE_PCS_NAD_1983_LA_S    26982 /* NAD 1983 SPCS Zone Louisiana South   */
#define PE_PCS_NAD_1983_ME_E    26983 /* NAD 1983 SPCS Zone Maine East        */
#define PE_PCS_NAD_1983_ME_W    26984 /* NAD 1983 SPCS Zone Maine West        */
#define PE_PCS_NAD_1983_MD      26985 /* NAD 1983 SPCS Zone Maryland          */
#define PE_PCS_NAD_1983_MA_M    26986 /* NAD 1983 SPCS Zone Mass. Mainland    */
#define PE_PCS_NAD_1983_MA_I    26987 /* NAD 1983 SPCS Zone Mass. Island      */
#define PE_PCS_NAD_1983_MI_N    26988 /* NAD 1983 SPCS Zone Michigan North    */
#define PE_PCS_NAD_1983_MI_C    26989 /* NAD 1983 SPCS Zone Michigan Central  */
#define PE_PCS_NAD_1983_MI_S    26990 /* NAD 1983 SPCS Zone Michigan South    */
#define PE_PCS_NAD_1983_MN_N    26991 /* NAD 1983 SPCS Zone Minnesota North   */
#define PE_PCS_NAD_1983_MN_C    26992 /* NAD 1983 SPCS Zone Minnesota Central */
#define PE_PCS_NAD_1983_MN_S    26993 /* NAD 1983 SPCS Zone Minnesota South   */
#define PE_PCS_NAD_1983_MS_E    26994 /* NAD 1983 SPCS Zone Mississippi East  */
#define PE_PCS_NAD_1983_MS_W    26995 /* NAD 1983 SPCS Zone Mississippi West  */
#define PE_PCS_NAD_1983_MO_E    26996 /* NAD 1983 SPCS Zone Missouri East     */
#define PE_PCS_NAD_1983_MO_C    26997 /* NAD 1983 SPCS Zone Missouri Central  */
#define PE_PCS_NAD_1983_MO_W    26998 /* NAD 1983 SPCS Zone Missouri West     */
#define PE_PCS_NAD_1983_MT      32100 /* NAD 1983 SPCS Zone Montana           */
#define PE_PCS_NAD_1983_NE      32104 /* NAD 1983 SPCS Zone Nebraska          */
#define PE_PCS_NAD_1983_NV_E    32107 /* NAD 1983 SPCS Zone Nevada East       */
#define PE_PCS_NAD_1983_NV_C    32108 /* NAD 1983 SPCS Zone Nevada Central    */
#define PE_PCS_NAD_1983_NV_W    32109 /* NAD 1983 SPCS Zone Nevada West       */
#define PE_PCS_NAD_1983_NH      32110 /* NAD 1983 SPCS Zone New Hampshire     */
#define PE_PCS_NAD_1983_NJ      32111 /* NAD 1983 SPCS Zone New Jersey        */
#define PE_PCS_NAD_1983_NM_E    32112 /* NAD 1983 SPCS Zone New Mexico East   */
#define PE_PCS_NAD_1983_NM_C    32113 /* NAD 1983 SPCS Zone New Mexico Cent.  */
#define PE_PCS_NAD_1983_NM_W    32114 /* NAD 1983 SPCS Zone New Mexico West   */
#define PE_PCS_NAD_1983_NY_E    32115 /* NAD 1983 SPCS Zone New York East     */
#define PE_PCS_NAD_1983_NY_C    32116 /* NAD 1983 SPCS Zone New York Central  */
#define PE_PCS_NAD_1983_NY_W    32117 /* NAD 1983 SPCS Zone New York West     */
#define PE_PCS_NAD_1983_NY_LI   32118 /* NAD 1983 SPCS Zone NY Long Island    */
#define PE_PCS_NAD_1983_NC      32119 /* NAD 1983 SPCS Zone North Carolina    */
#define PE_PCS_NAD_1983_ND_N    32120 /* NAD 1983 SPCS Zone North Dakota N    */
#define PE_PCS_NAD_1983_ND_S    32121 /* NAD 1983 SPCS Zone North Dakota S    */
#define PE_PCS_NAD_1983_OH_N    32122 /* NAD 1983 SPCS Zone Ohio North        */
#define PE_PCS_NAD_1983_OH_S    32123 /* NAD 1983 SPCS Zone Ohio South        */
#define PE_PCS_NAD_1983_OK_N    32124 /* NAD 1983 SPCS Zone Oklahoma North    */
#define PE_PCS_NAD_1983_OK_S    32125 /* NAD 1983 SPCS Zone Oklahoma South    */
#define PE_PCS_NAD_1983_OR_N    32126 /* NAD 1983 SPCS Zone Oregon North      */
#define PE_PCS_NAD_1983_OR_S    32127 /* NAD 1983 SPCS Zone Oregon South      */
#define PE_PCS_NAD_1983_PA_N    32128 /* NAD 1983 SPCS Zone Pennsylvania N    */
#define PE_PCS_NAD_1983_PA_S    32129 /* NAD 1983 SPCS Zone Pennsylvania S    */
#define PE_PCS_NAD_1983_RI      32130 /* NAD 1983 SPCS Zone Rhode Island      */
#define PE_PCS_NAD_1983_SC      32133 /* NAD 1983 SPCS Zone South Carolina    */
#define PE_PCS_NAD_1983_SD_N    32134 /* NAD 1983 SPCS Zone South Dakota N    */
#define PE_PCS_NAD_1983_SD_S    32135 /* NAD 1983 SPCS Zone South Dakota S    */
#define PE_PCS_NAD_1983_TN      32136 /* NAD 1983 SPCS Zone Tennessee         */
#define PE_PCS_NAD_1983_TX_N    32137 /* NAD 1983 SPCS Zone Texas North       */
#define PE_PCS_NAD_1983_TX_NC   32138 /* NAD 1983 SPCS Zone Texas North Cent. */
#define PE_PCS_NAD_1983_TX_C    32139 /* NAD 1983 SPCS Zone Texas Central     */
#define PE_PCS_NAD_1983_TX_SC   32140 /* NAD 1983 SPCS Zone Texas South Cent. */
#define PE_PCS_NAD_1983_TX_S    32141 /* NAD 1983 SPCS Zone Texas South       */
#define PE_PCS_NAD_1983_UT_N    32142 /* NAD 1983 SPCS Zone Utah North        */
#define PE_PCS_NAD_1983_UT_C    32143 /* NAD 1983 SPCS Zone Utah Central      */
#define PE_PCS_NAD_1983_UT_S    32144 /* NAD 1983 SPCS Zone Utah South        */
#define PE_PCS_NAD_1983_VT      32145 /* NAD 1983 SPCS Zone Vermont           */
#define PE_PCS_NAD_1983_VA_N    32146 /* NAD 1983 SPCS Zone Virginia North    */
#define PE_PCS_NAD_1983_VA_S    32147 /* NAD 1983 SPCS Zone Virginia South    */
#define PE_PCS_NAD_1983_WA_N    32148 /* NAD 1983 SPCS Zone Washington North  */
#define PE_PCS_NAD_1983_WA_S    32149 /* NAD 1983 SPCS Zone Washington South  */
#define PE_PCS_NAD_1983_WV_N    32150 /* NAD 1983 SPCS Zone West Virginia N   */
#define PE_PCS_NAD_1983_WV_S    32151 /* NAD 1983 SPCS Zone West Virginia S   */
#define PE_PCS_NAD_1983_WI_N    32152 /* NAD 1983 SPCS Zone Wisconsin North   */
#define PE_PCS_NAD_1983_WI_C    32153 /* NAD 1983 SPCS Zone Wisconsin Central */
#define PE_PCS_NAD_1983_WI_S    32154 /* NAD 1983 SPCS Zone Wisconsin South   */
#define PE_PCS_NAD_1983_WY_E    32155 /* NAD 1983 SPCS Zone Wyoming I East    */
#define PE_PCS_NAD_1983_WY_EC   32156 /* NAD 1983 SPCS Zone Wyoming II EC     */
#define PE_PCS_NAD_1983_WY_WC   32157 /* NAD 1983 SPCS Zone Wyoming III WC    */
#define PE_PCS_NAD_1983_WY_W    32158 /* NAD 1983 SPCS Zone Wyoming IV West   */
#define PE_PCS_NAD_1983_PR_VI   32161 /* NAD 1983 SPCS Zone PR & St. Croix    */
#define PE_PCS_NAD_1983_GU     (32161+33000) /* NAD 1983 SPCS Zone Guam       */
#define PE_PCS_NAD_1983_KY     (32163+33000) /* NAD 1983 SPCS Kentucky(1 zone)*/


#define PE_PCS_NAHRWAN_1967_UTM_38N    27038 /* Nahrwan 1967 UTM Zone 38N     */
#define PE_PCS_NAHRWAN_1967_UTM_39N    27039 /* Nahrwan 1967 UTM Zone 39N     */
#define PE_PCS_NAHRWAN_1967_UTM_40N    27040 /* Nahrwan 1967 UTM Zone 40N     */
#define PE_PCS_NAPARIMA_1955_UTM_20N    2067 /* Naparima 1955 UTM zone 20N    */
#define PE_PCS_NAPARIMA_1972_UTM_20N   27120 /* Naparima 1972 UTM Zone 20N    */
#define PE_PCS_NGN_UTM_38N             31838 /* NGN UTM Zone 38N              */
#define PE_PCS_NGN_UTM_39N             31839 /* NGN UTM Zone 39N              */
#define PE_PCS_NGO_1948_OSLO_NORWAY_1  27391 /* NGO 1948 Oslo Norway zone 1   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_2  27392 /* NGO 1948 Oslo Norway zone 2   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_3  27393 /* NGO 1948 Oslo Norway zone 3   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_4  27394 /* NGO 1948 Oslo Norway zone 4   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_5  27395 /* NGO 1948 Oslo Norway zone 5   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_6  27396 /* NGO 1948 Oslo Norway zone 6   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_7  27397 /* NGO 1948 Oslo Norway zone 7   */
#define PE_PCS_NGO_1948_OSLO_NORWAY_8  27398 /* NGO 1948 Oslo Norway zone 8   */
#define PE_PCS_NORD_SAHARA_UTM_29N     30729 /* Nord Sahara 1959 UTM Zone 29N */
#define PE_PCS_NORD_SAHARA_UTM_30N     30730 /* Nord Sahara 1959 UTM Zone 30N */
#define PE_PCS_NORD_SAHARA_UTM_31N     30731 /* Nord Sahara 1959 UTM Zone 31N */
#define PE_PCS_NORD_SAHARA_UTM_32N     30732 /* Nord Sahara 1959 UTM Zone 32N */
#define PE_PCS_NTF_CENTRE_FRANCE       27592 /* NTF Paris Centre France (grads)*/
#define PE_PCS_NTF_CORSE               27594 /* NTF Paris Corse (grads)       */
#define PE_PCS_NTF_FRANCE_I            27581 /* NTF Paris France I (grads)    */
#define PE_PCS_NTF_FRANCE_II           27582 /* NTF Paris France II (grads)   */
#define PE_PCS_NTF_FRANCE_III          27583 /* NTF Paris France III (grads)  */
#define PE_PCS_NTF_FRANCE_IV           27584 /* NTF Paris France IV (grads)   */
#define PE_PCS_NTF_NORD_FRANCE         27591 /* NTF Paris Nord France (grads) */
#define PE_PCS_NTF_SUD_FRANCE          27593 /* NTF Paris Sud France (grads)  */

/* New Zealand */
#define PE_PCS_NZGD_1949_AMURI_CIRCUIT          27219 /* NZGD49 Amuri Circuit         */
#define PE_PCS_NZGD_1949_BAY_OF_PLENTY_CIRCUIT  27206 /* NZGD49 Bay of Plenty Circuit */
#define PE_PCS_NZGD_1949_BLUFF_CIRCUIT          27232 /* NZGD49 Bluff Circuit         */
#define PE_PCS_NZGD_1949_BULLER_CIRCUIT         27217 /* NZGD49 Buller Circuit        */
#define PE_PCS_NZGD_1949_COLLINGWOOD_CIRCUIT    27214 /* NZGD49 Collingwood Circuit   */
#define PE_PCS_NZGD_1949_GAWLER_CIRCUIT         27225 /* NZGD49 Gawler Circuit        */
#define PE_PCS_NZGD_1949_GREY_CIRCUIT           27218 /* NZGD49 Grey Circuit          */
#define PE_PCS_NZGD_1949_HAWKES_BAY_CIRCUIT     27208 /* NZGD49 Hawkes Bay Circuit    */
#define PE_PCS_NZGD_1949_HOKITIKA_CIRCUIT       27221 /* NZGD49 Hokitika Circuit      */
#define PE_PCS_NZGD_1949_JACKSONS_BAY_CIRCUIT   27223 /* NZGD49 Jacksons Bay Circuit  */
#define PE_PCS_NZGD_1949_KARAMEA_CIRCUIT        27216 /* NZGD49 Karamea Circuit       */
#define PE_PCS_NZGD_1949_LINDIS_PEAK_CIRCUIT    27227 /* NZGD49 Lindis Peak Circuit   */
#define PE_PCS_NZGD_1949_MARLBOROUGH_CIRCUIT    27220 /* NZGD49 Marlborough Circuit   */
#define PE_PCS_NZGD_1949_MOUNT_EDEN_CIRCUIT     27205 /* NZGD49 Mount Eden Circuit    */
#define PE_PCS_NZGD_1949_MOUNT_NICHOLAS_CIRCUIT 27228 /* NZGD49 Mount Nicholas Circuit*/
#define PE_PCS_NZGD_1949_MOUNT_PLEASANT_CIRCUIT 27224 /* NZGD49 Mount Pleasant Circuit*/
#define PE_PCS_NZGD_1949_MOUNT_YORK_CIRCUIT     27229 /* NZGD49 Mount York Circuit    */
#define PE_PCS_NZGD_1949_NELSON_CIRCUIT         27215 /* NZGD49 Nelson Circuit        */
#define PE_PCS_NZGD_1949_NORTH_TAIERI_CIRCUIT   27231 /* NZGD49 North Taieri Circuit  */
#define PE_PCS_NZGD_1949_OBSERVATION_PT_CIRCUIT 27230 /* NZGD49 Observation Point Circuit */
#define PE_PCS_NZGD_1949_OKARITO_CIRCUIT        27222 /* NZGD49 Okarito Circuit       */
#define PE_PCS_NZGD_1949_POVERTY_BAY_CIRCUIT    27207 /* NZGD49 Poverty Bay Circuit   */
#define PE_PCS_NZGD_1949_TARANAKI_CIRCUIT       27209 /* NZGD49 Taranaki Circuit      */
#define PE_PCS_NZGD_1949_TIMARU_CIRCUIT         27226 /* NZGD49 Timaru Circuit        */
#define PE_PCS_NZGD_1949_TUHIRANGI_CIRCUIT      27210 /* NZGD49 Tuhirangi Circuit     */
#define PE_PCS_NZGD_1949_WAIRARAPA_CIRCUIT      27212 /* NZGD49 Wairarapa Circuit     */
#define PE_PCS_NZGD_1949_WANGANUI_CIRCUIT       27211 /* NZGD49 Wanganui Circuit      */
#define PE_PCS_NZGD_1949_WELLINGTON_CIRCUIT     27213 /* NZGD49 Wellington Circuit    */

#define PE_PCS_NZGD_1949_NEW_ZEALAND_MAP_GRID  27200 /* New Zealand Map Grid  */
#define PE_PCS_NZGD_1949_NORTH_ISLAND  27291 /* New Zealand North Island      */
#define PE_PCS_NZGD_1949_SOUTH_ISLAND  27292 /* New Zealand South Island      */
#define PE_PCS_NZGD_1949_UTM_58S       27258 /* NZGD 1949 UTM zone 58S        */
#define PE_PCS_NZGD_1949_UTM_59S       27259 /* NZGD 1949 UTM zone 59S        */
#define PE_PCS_NZGD_1949_UTM_60S       27260 /* NZGD 1949 UTM zone 60S        */

#define PE_PCS_NZGD_2000_AMURI_CIRCUIT          2119 /* NZGD2000 Amuri Circuit         */
#define PE_PCS_NZGD_2000_BAY_OF_PLENTY_CIRCUIT  2106 /* NZGD2000 Bay of Plenty Circuit */
#define PE_PCS_NZGD_2000_BLUFF_CIRCUIT          2132 /* NZGD2000 Bluff Circuit         */
#define PE_PCS_NZGD_2000_BULLER_CIRCUIT         2117 /* NZGD2000 Buller Circuit        */
#define PE_PCS_NZGD_2000_COLLINGWOOD_CIRCUIT    2114 /* NZGD2000 Collingwood Circuit   */
#define PE_PCS_NZGD_2000_GAWLER_CIRCUIT         2125 /* NZGD2000 Gawler Circuit        */
#define PE_PCS_NZGD_2000_GREY_CIRCUIT           2118 /* NZGD2000 Grey Circuit          */
#define PE_PCS_NZGD_2000_HAWKES_BAY_CIRCUIT     2108 /* NZGD2000 Hawkes Bay Circuit    */
#define PE_PCS_NZGD_2000_HOKITIKA_CIRCUIT       2121 /* NZGD2000 Hokitika Circuit      */
#define PE_PCS_NZGD_2000_JACKSONS_BAY_CIRCUIT   2123 /* NZGD2000 Jacksons Bay Circuit  */
#define PE_PCS_NZGD_2000_KARAMEA_CIRCUIT        2116 /* NZGD2000 Karamea Circuit       */
#define PE_PCS_NZGD_2000_LINDIS_PEAK_CIRCUIT    2127 /* NZGD2000 Lindis Peak Circuit   */
#define PE_PCS_NZGD_2000_MARLBOROUGH_CIRCUIT    2120 /* NZGD2000 Marlborough Circuit   */
#define PE_PCS_NZGD_2000_MOUNT_EDEN_CIRCUIT     2105 /* NZGD2000 Mount Eden Circuit    */
#define PE_PCS_NZGD_2000_MOUNT_NICHOLAS_CIRCUIT 2128 /* NZGD2000 Mount Nicholas Circuit*/
#define PE_PCS_NZGD_2000_MOUNT_PLEASANT_CIRCUIT 2124 /* NZGD2000 Mount Pleasant Circuit*/
#define PE_PCS_NZGD_2000_MOUNT_YORK_CIRCUIT     2129 /* NZGD2000 Mount York Circuit    */
#define PE_PCS_NZGD_2000_NELSON_CIRCUIT         2115 /* NZGD2000 Nelson Circuit        */
#define PE_PCS_NZGD_2000_NORTH_TAIERI_CIRCUIT   2131 /* NZGD2000 North Taieri Circuit  */
#define PE_PCS_NZGD_2000_OBSERVATION_PT_CIRCUIT 2130 /* NZGD2000 Observation Point Circuit */
#define PE_PCS_NZGD_2000_OKARITO_CIRCUIT        2122 /* NZGD2000 Okarito Circuit       */
#define PE_PCS_NZGD_2000_POVERTY_BAY_CIRCUIT    2107 /* NZGD2000 Poverty Bay Circuit   */
#define PE_PCS_NZGD_2000_TARANAKI_CIRCUIT       2109 /* NZGD2000 Taranaki Circuit      */
#define PE_PCS_NZGD_2000_TIMARU_CIRCUIT         2126 /* NZGD2000 Timaru Circuit        */
#define PE_PCS_NZGD_2000_TUHIRANGI_CIRCUIT      2110 /* NZGD2000 Tuhirangi Circuit     */
#define PE_PCS_NZGD_2000_WANGANUI_CIRCUIT       2111 /* NZGD2000 Wanganui Circuit      */
#define PE_PCS_NZGD_2000_WAIRARAPA_CIRCUIT      2112 /* NZGD2000 Wairarapa Circuit     */
#define PE_PCS_NZGD_2000_WELLINGTON_CIRCUIT     2113 /* NZGD2000 Wellington Circuit    */

#define PE_PCS_NZGD_2000_UTM_58S        2133 /* NZGD 2000 UTM zone 58S        */
#define PE_PCS_NZGD_2000_UTM_59S        2134 /* NZGD 2000 UTM zone 59S        */
#define PE_PCS_NZGD_2000_UTM_60S        2135 /* NZGD 2000 UTM zone 60S        */


#define PE_PCS_OSGB_1936_BRITISH_GRID  27700 /* British National Grid         */
#define PE_PCS_PALESTINE_1923_ISRAEL_CS_GRID  28193 /* Palestine 1923 Israel CS Grid */
#define PE_PCS_PALESTINE_1923_PALESTINE_BELT  28192 /* Palestine 1923 Palestine Belt */
#define PE_PCS_PALESTINE_1923_PALESTINE_GRID  28191 /* Palestine 1923 Palestine Grid */
#define PE_PCS_PAMPA_DEL_CASTILLO_ARGENTINA_2  2082 /* Pampa del Castillo Argentina zone 2 */
#define PE_PCS_PDO_1993_UTM_39N         3439 /* PDO 1993 UTM zone 39N         */
#define PE_PCS_PDO_1993_UTM_40N         3440 /* PDO 1993 UTM zone 40N         */
#define PE_PCS_POINTE_NOIRE_UTM_32S    28232 /* Pointe Noire UTM Zone 32S     */
#define PE_PCS_PSAD_1956_PERU_WEST     24891 /* Peru West Zone                */
#define PE_PCS_PSAD_1956_PERU_CENTRAL  24892 /* Peru Central Zone             */
#define PE_PCS_PSAD_1956_PERU_EAST     24893 /* Peru East Zone                */
#define PE_PCS_PSAD_1956_UTM_18N   24818 /* Prov. S. Amer. Datum UTM Zone 18N */
#define PE_PCS_PSAD_1956_UTM_19N   24819 /* Prov. S. Amer. Datum UTM Zone 19N */
#define PE_PCS_PSAD_1956_UTM_20N   24820 /* Prov. S. Amer. Datum UTM Zone 20N */
#define PE_PCS_PSAD_1956_UTM_21N   24821 /* Prov. S. Amer. Datum UTM Zone 21N */
#define PE_PCS_PSAD_1956_UTM_17S   24877 /* Prov. S. Amer. Datum UTM Zone 17S */
#define PE_PCS_PSAD_1956_UTM_18S   24878 /* Prov. S. Amer. Datum UTM Zone 18S */
#define PE_PCS_PSAD_1956_UTM_19S   24879 /* Prov. S. Amer. Datum UTM Zone 19S */
#define PE_PCS_PSAD_1956_UTM_20S   24880 /* Prov. S. Amer. Datum UTM Zone 20S */
#define PE_PCS_PSAD_1956_UTM_22S   24882 /* Prov. S. Amer. Datum UTM zone 22S */
#define PE_PCS_PUERTO_RICO_UTM_20N      3920 /* Puerto Rico UTM zone 20N      */

/* Russia (former states of USSR) */
#define PE_PCS_PULKOVO_1942_GK_2       28402 /* Pulkovo 1942 GK Zone 2        */
#define PE_PCS_PULKOVO_1942_GK_3       28403 /* Pulkovo 1942 GK Zone 3        */
#define PE_PCS_PULKOVO_1942_GK_4       28404 /* Pulkovo 1942 GK Zone 4        */
#define PE_PCS_PULKOVO_1942_GK_5       28405 /* Pulkovo 1942 GK Zone 5        */
#define PE_PCS_PULKOVO_1942_GK_6       28406 /* Pulkovo 1942 GK Zone 6        */
#define PE_PCS_PULKOVO_1942_GK_7       28407 /* Pulkovo 1942 GK Zone 7        */
#define PE_PCS_PULKOVO_1942_GK_8       28408 /* Pulkovo 1942 GK Zone 8        */
#define PE_PCS_PULKOVO_1942_GK_9       28409 /* Pulkovo 1942 GK Zone 9        */
#define PE_PCS_PULKOVO_1942_GK_10      28410 /* Pulkovo 1942 GK Zone 10       */
#define PE_PCS_PULKOVO_1942_GK_11      28411 /* Pulkovo 1942 GK Zone 11       */
#define PE_PCS_PULKOVO_1942_GK_12      28412 /* Pulkovo 1942 GK Zone 12       */
#define PE_PCS_PULKOVO_1942_GK_13      28413 /* Pulkovo 1942 GK Zone 13       */
#define PE_PCS_PULKOVO_1942_GK_14      28414 /* Pulkovo 1942 GK Zone 14       */
#define PE_PCS_PULKOVO_1942_GK_15      28415 /* Pulkovo 1942 GK Zone 15       */
#define PE_PCS_PULKOVO_1942_GK_16      28416 /* Pulkovo 1942 GK Zone 16       */
#define PE_PCS_PULKOVO_1942_GK_17      28417 /* Pulkovo 1942 GK Zone 17       */
#define PE_PCS_PULKOVO_1942_GK_18      28418 /* Pulkovo 1942 GK Zone 18       */
#define PE_PCS_PULKOVO_1942_GK_19      28419 /* Pulkovo 1942 GK Zone 19       */
#define PE_PCS_PULKOVO_1942_GK_20      28420 /* Pulkovo 1942 GK Zone 20       */
#define PE_PCS_PULKOVO_1942_GK_21      28421 /* Pulkovo 1942 GK Zone 21       */
#define PE_PCS_PULKOVO_1942_GK_22      28422 /* Pulkovo 1942 GK Zone 22       */
#define PE_PCS_PULKOVO_1942_GK_23      28423 /* Pulkovo 1942 GK Zone 23       */
#define PE_PCS_PULKOVO_1942_GK_24      28424 /* Pulkovo 1942 GK Zone 24       */
#define PE_PCS_PULKOVO_1942_GK_25      28425 /* Pulkovo 1942 GK Zone 25       */
#define PE_PCS_PULKOVO_1942_GK_26      28426 /* Pulkovo 1942 GK Zone 26       */
#define PE_PCS_PULKOVO_1942_GK_27      28427 /* Pulkovo 1942 GK Zone 27       */
#define PE_PCS_PULKOVO_1942_GK_28      28428 /* Pulkovo 1942 GK Zone 28       */
#define PE_PCS_PULKOVO_1942_GK_29      28429 /* Pulkovo 1942 GK Zone 29       */
#define PE_PCS_PULKOVO_1942_GK_30      28430 /* Pulkovo 1942 GK Zone 30       */
#define PE_PCS_PULKOVO_1942_GK_31      28431 /* Pulkovo 1942 GK Zone 31       */
#define PE_PCS_PULKOVO_1942_GK_32      28432 /* Pulkovo 1942 GK Zone 32       */

#define PE_PCS_PULKOVO_1942_GK_2N      28462 /* Pulkovo 1942 GK Zone 2N       */
#define PE_PCS_PULKOVO_1942_GK_3N      28463 /* Pulkovo 1942 GK Zone 3N       */
#define PE_PCS_PULKOVO_1942_GK_4N      28464 /* Pulkovo 1942 GK Zone 4N       */
#define PE_PCS_PULKOVO_1942_GK_5N      28465 /* Pulkovo 1942 GK Zone 5N       */
#define PE_PCS_PULKOVO_1942_GK_6N      28466 /* Pulkovo 1942 GK Zone 6N       */
#define PE_PCS_PULKOVO_1942_GK_7N      28467 /* Pulkovo 1942 GK Zone 7N       */
#define PE_PCS_PULKOVO_1942_GK_8N      28468 /* Pulkovo 1942 GK Zone 8N       */
#define PE_PCS_PULKOVO_1942_GK_9N      28469 /* Pulkovo 1942 GK Zone 9N       */
#define PE_PCS_PULKOVO_1942_GK_10N     28470 /* Pulkovo 1942 GK Zone 10N      */
#define PE_PCS_PULKOVO_1942_GK_11N     28471 /* Pulkovo 1942 GK Zone 11N      */
#define PE_PCS_PULKOVO_1942_GK_12N     28472 /* Pulkovo 1942 GK Zone 12N      */
#define PE_PCS_PULKOVO_1942_GK_13N     28473 /* Pulkovo 1942 GK Zone 13N      */
#define PE_PCS_PULKOVO_1942_GK_14N     28474 /* Pulkovo 1942 GK Zone 14N      */
#define PE_PCS_PULKOVO_1942_GK_15N     28475 /* Pulkovo 1942 GK Zone 15N      */
#define PE_PCS_PULKOVO_1942_GK_16N     28476 /* Pulkovo 1942 GK Zone 16N      */
#define PE_PCS_PULKOVO_1942_GK_17N     28477 /* Pulkovo 1942 GK Zone 17N      */
#define PE_PCS_PULKOVO_1942_GK_18N     28478 /* Pulkovo 1942 GK Zone 18N      */
#define PE_PCS_PULKOVO_1942_GK_19N     28479 /* Pulkovo 1942 GK Zone 19N      */
#define PE_PCS_PULKOVO_1942_GK_20N     28480 /* Pulkovo 1942 GK Zone 20N      */
#define PE_PCS_PULKOVO_1942_GK_21N     28481 /* Pulkovo 1942 GK Zone 21N      */
#define PE_PCS_PULKOVO_1942_GK_22N     28482 /* Pulkovo 1942 GK Zone 22N      */
#define PE_PCS_PULKOVO_1942_GK_23N     28483 /* Pulkovo 1942 GK Zone 23N      */
#define PE_PCS_PULKOVO_1942_GK_24N     28484 /* Pulkovo 1942 GK Zone 24N      */
#define PE_PCS_PULKOVO_1942_GK_25N     28485 /* Pulkovo 1942 GK Zone 25N      */
#define PE_PCS_PULKOVO_1942_GK_26N     28486 /* Pulkovo 1942 GK Zone 26N      */
#define PE_PCS_PULKOVO_1942_GK_27N     28487 /* Pulkovo 1942 GK Zone 27N      */
#define PE_PCS_PULKOVO_1942_GK_28N     28488 /* Pulkovo 1942 GK Zone 28N      */
#define PE_PCS_PULKOVO_1942_GK_29N     28489 /* Pulkovo 1942 GK Zone 29N      */
#define PE_PCS_PULKOVO_1942_GK_30N     28490 /* Pulkovo 1942 GK Zone 30N      */
#define PE_PCS_PULKOVO_1942_GK_31N     28491 /* Pulkovo 1942 GK Zone 31N      */
#define PE_PCS_PULKOVO_1942_GK_32N     28492 /* Pulkovo 1942 GK Zone 32N      */

#define PE_PCS_PULKOVO_1995_GK_2       20002 /* Pulkovo 1995 GK Zone 2        */
#define PE_PCS_PULKOVO_1995_GK_3       20003 /* Pulkovo 1995 GK Zone 3        */
#define PE_PCS_PULKOVO_1995_GK_4       20004 /* Pulkovo 1995 GK Zone 4        */
#define PE_PCS_PULKOVO_1995_GK_5       20005 /* Pulkovo 1995 GK Zone 5        */
#define PE_PCS_PULKOVO_1995_GK_6       20006 /* Pulkovo 1995 GK Zone 6        */
#define PE_PCS_PULKOVO_1995_GK_7       20007 /* Pulkovo 1995 GK Zone 7        */
#define PE_PCS_PULKOVO_1995_GK_8       20008 /* Pulkovo 1995 GK Zone 8        */
#define PE_PCS_PULKOVO_1995_GK_9       20009 /* Pulkovo 1995 GK Zone 9        */
#define PE_PCS_PULKOVO_1995_GK_10      20010 /* Pulkovo 1995 GK Zone 10       */
#define PE_PCS_PULKOVO_1995_GK_11      20011 /* Pulkovo 1995 GK Zone 11       */
#define PE_PCS_PULKOVO_1995_GK_12      20012 /* Pulkovo 1995 GK Zone 12       */
#define PE_PCS_PULKOVO_1995_GK_13      20013 /* Pulkovo 1995 GK Zone 13       */
#define PE_PCS_PULKOVO_1995_GK_14      20014 /* Pulkovo 1995 GK Zone 14       */
#define PE_PCS_PULKOVO_1995_GK_15      20015 /* Pulkovo 1995 GK Zone 15       */
#define PE_PCS_PULKOVO_1995_GK_16      20016 /* Pulkovo 1995 GK Zone 16       */
#define PE_PCS_PULKOVO_1995_GK_17      20017 /* Pulkovo 1995 GK Zone 17       */
#define PE_PCS_PULKOVO_1995_GK_18      20018 /* Pulkovo 1995 GK Zone 18       */
#define PE_PCS_PULKOVO_1995_GK_19      20019 /* Pulkovo 1995 GK Zone 19       */
#define PE_PCS_PULKOVO_1995_GK_20      20020 /* Pulkovo 1995 GK Zone 20       */
#define PE_PCS_PULKOVO_1995_GK_21      20021 /* Pulkovo 1995 GK Zone 21       */
#define PE_PCS_PULKOVO_1995_GK_22      20022 /* Pulkovo 1995 GK Zone 22       */
#define PE_PCS_PULKOVO_1995_GK_23      20023 /* Pulkovo 1995 GK Zone 23       */
#define PE_PCS_PULKOVO_1995_GK_24      20024 /* Pulkovo 1995 GK Zone 24       */
#define PE_PCS_PULKOVO_1995_GK_25      20025 /* Pulkovo 1995 GK Zone 25       */
#define PE_PCS_PULKOVO_1995_GK_26      20026 /* Pulkovo 1995 GK Zone 26       */
#define PE_PCS_PULKOVO_1995_GK_27      20027 /* Pulkovo 1995 GK Zone 27       */
#define PE_PCS_PULKOVO_1995_GK_28      20028 /* Pulkovo 1995 GK Zone 28       */
#define PE_PCS_PULKOVO_1995_GK_29      20029 /* Pulkovo 1995 GK Zone 29       */
#define PE_PCS_PULKOVO_1995_GK_30      20030 /* Pulkovo 1995 GK Zone 30       */
#define PE_PCS_PULKOVO_1995_GK_31      20031 /* Pulkovo 1995 GK Zone 31       */
#define PE_PCS_PULKOVO_1995_GK_32      20032 /* Pulkovo 1995 GK Zone 32       */

#define PE_PCS_PULKOVO_1995_GK_2N      20062 /* Pulkovo 1995 GK Zone 2N       */
#define PE_PCS_PULKOVO_1995_GK_3N      20063 /* Pulkovo 1995 GK Zone 3N       */
#define PE_PCS_PULKOVO_1995_GK_4N      20064 /* Pulkovo 1995 GK Zone 4N       */
#define PE_PCS_PULKOVO_1995_GK_5N      20065 /* Pulkovo 1995 GK Zone 5N       */
#define PE_PCS_PULKOVO_1995_GK_6N      20066 /* Pulkovo 1995 GK Zone 6N       */
#define PE_PCS_PULKOVO_1995_GK_7N      20067 /* Pulkovo 1995 GK Zone 7N       */
#define PE_PCS_PULKOVO_1995_GK_8N      20068 /* Pulkovo 1995 GK Zone 8N       */
#define PE_PCS_PULKOVO_1995_GK_9N      20069 /* Pulkovo 1995 GK Zone 9N       */
#define PE_PCS_PULKOVO_1995_GK_10N     20070 /* Pulkovo 1995 GK Zone 10N      */
#define PE_PCS_PULKOVO_1995_GK_11N     20071 /* Pulkovo 1995 GK Zone 11N      */
#define PE_PCS_PULKOVO_1995_GK_12N     20072 /* Pulkovo 1995 GK Zone 12N      */
#define PE_PCS_PULKOVO_1995_GK_13N     20073 /* Pulkovo 1995 GK Zone 13N      */
#define PE_PCS_PULKOVO_1995_GK_14N     20074 /* Pulkovo 1995 GK Zone 14N      */
#define PE_PCS_PULKOVO_1995_GK_15N     20075 /* Pulkovo 1995 GK Zone 15N      */
#define PE_PCS_PULKOVO_1995_GK_16N     20076 /* Pulkovo 1995 GK Zone 16N      */
#define PE_PCS_PULKOVO_1995_GK_17N     20077 /* Pulkovo 1995 GK Zone 17N      */
#define PE_PCS_PULKOVO_1995_GK_18N     20078 /* Pulkovo 1995 GK Zone 18N      */
#define PE_PCS_PULKOVO_1995_GK_19N     20079 /* Pulkovo 1995 GK Zone 19N      */
#define PE_PCS_PULKOVO_1995_GK_20N     20080 /* Pulkovo 1995 GK Zone 20N      */
#define PE_PCS_PULKOVO_1995_GK_21N     20081 /* Pulkovo 1995 GK Zone 21N      */
#define PE_PCS_PULKOVO_1995_GK_22N     20082 /* Pulkovo 1995 GK Zone 22N      */
#define PE_PCS_PULKOVO_1995_GK_23N     20083 /* Pulkovo 1995 GK Zone 23N      */
#define PE_PCS_PULKOVO_1995_GK_24N     20084 /* Pulkovo 1995 GK Zone 24N      */
#define PE_PCS_PULKOVO_1995_GK_25N     20085 /* Pulkovo 1995 GK Zone 25N      */
#define PE_PCS_PULKOVO_1995_GK_26N     20086 /* Pulkovo 1995 GK Zone 26N      */
#define PE_PCS_PULKOVO_1995_GK_27N     20087 /* Pulkovo 1995 GK Zone 27N      */
#define PE_PCS_PULKOVO_1995_GK_28N     20088 /* Pulkovo 1995 GK Zone 28N      */
#define PE_PCS_PULKOVO_1995_GK_29N     20089 /* Pulkovo 1995 GK Zone 29N      */
#define PE_PCS_PULKOVO_1995_GK_30N     20090 /* Pulkovo 1995 GK Zone 30N      */
#define PE_PCS_PULKOVO_1995_GK_31N     20091 /* Pulkovo 1995 GK Zone 31N      */
#define PE_PCS_PULKOVO_1995_GK_32N     20092 /* Pulkovo 1995 GK Zone 32N      */


#define PE_PCS_QATAR_1948_QATAR_GRID    2099 /* Qatar 1948 Qatar Grid         */
#define PE_PCS_QATAR_GRID              28600 /* Qatar National Grid           */
#define PE_PCS_RT38_STOCKHOLM_SWEDISH_GRID 30800 /* Swedish National Grid     */
#define PE_PCS_RT90_25_GON_W                2400 /* RT 1990 2.5 gon W Sweden  */

/* South America */
#define PE_PCS_SAD_1969_BRAZIL_POLYCONIC   29100 /* SAD 1969 Brazil Polyconic */
#define PE_PCS_SAD_1969_UTM_18N     29118 /* South American 1969 UTM Zone 18N */
#define PE_PCS_SAD_1969_UTM_19N     29119 /* South American 1969 UTM Zone 19N */
#define PE_PCS_SAD_1969_UTM_20N     29120 /* South American 1969 UTM Zone 20N */
#define PE_PCS_SAD_1969_UTM_21N     29121 /* South American 1969 UTM Zone 21N */
#define PE_PCS_SAD_1969_UTM_22N     29122 /* South American 1969 UTM Zone 22N */
#define PE_PCS_SAD_1969_UTM_17S     29177 /* South American 1969 UTM Zone 17S */
#define PE_PCS_SAD_1969_UTM_18S     29178 /* South American 1969 UTM Zone 18S */
#define PE_PCS_SAD_1969_UTM_19S     29179 /* South American 1969 UTM Zone 19S */
#define PE_PCS_SAD_1969_UTM_20S     29180 /* South American 1969 UTM Zone 20S */
#define PE_PCS_SAD_1969_UTM_21S     29181 /* South American 1969 UTM Zone 21S */
#define PE_PCS_SAD_1969_UTM_22S     29182 /* South American 1969 UTM Zone 22S */
#define PE_PCS_SAD_1969_UTM_23S     29183 /* South American 1969 UTM Zone 23S */
#define PE_PCS_SAD_1969_UTM_24S     29184 /* South American 1969 UTM Zone 24S */
#define PE_PCS_SAD_1969_UTM_25S     29185 /* South American 1969 UTM Zone 25S */


#define PE_PCS_SAMBOJA_UTM_50S          2550 /* Samboja UTM zone 50S          */
#define PE_PCS_SAMOA_1962_SAMOA_LAMBERT 2155 /* Samoa 1962 American Samoa Lambert */
#define PE_PCS_SAPPER_HILL_UTM_20S     29220 /* Sapper Hill 1943 UTM Zone 20S */
#define PE_PCS_SAPPER_HILL_UTM_21S     29221 /* Sapper Hill 1943 UTM Zone 21S */
#define PE_PCS_SCHWARZECK_UTM_33S      29333 /* Schwarzeck UTM Zone 33S       */
#define PE_PCS_SIERRA_LEONE_1924_NEW_COLONY_GRID 2159 /* Sierra Leone 1924 New Colony Grid */
#define PE_PCS_SIERRA_LEONE_1924_NEW_WAR_OFFICE_GRID 2160 /* Sierra Leone 1924 New War Office Grid */
#define PE_PCS_SIERRA_LEONE_1968_UTM_28N   2161 /* Sierra Leone 1968 UTM zone 28N */
#define PE_PCS_SIERRA_LEONE_1968_UTM_29N   2162 /* Sierra Leone 1968 UTM zone 29N */
#define PE_PCS_SIRGAS_UTM_17N          31917 /* SIRGAS UTM zone 17N           */
#define PE_PCS_SIRGAS_UTM_18N          31918 /* SIRGAS UTM zone 18N           */
#define PE_PCS_SIRGAS_UTM_19N          31919 /* SIRGAS UTM zone 19N           */
#define PE_PCS_SIRGAS_UTM_20N          31920 /* SIRGAS UTM zone 20N           */
#define PE_PCS_SIRGAS_UTM_21N          31921 /* SIRGAS UTM zone 21N           */
#define PE_PCS_SIRGAS_UTM_22N          31922 /* SIRGAS UTM zone 22N           */
#define PE_PCS_SIRGAS_UTM_17S          31977 /* SIRGAS UTM zone 17S           */
#define PE_PCS_SIRGAS_UTM_18S          31978 /* SIRGAS UTM zone 18S           */
#define PE_PCS_SIRGAS_UTM_19S          31979 /* SIRGAS UTM zone 19S           */
#define PE_PCS_SIRGAS_UTM_20S          31980 /* SIRGAS UTM zone 20S           */
#define PE_PCS_SIRGAS_UTM_21S          31981 /* SIRGAS UTM zone 21S           */
#define PE_PCS_SIRGAS_UTM_22S          31982 /* SIRGAS UTM zone 22S           */
#define PE_PCS_SIRGAS_UTM_23S          31983 /* SIRGAS UTM zone 23S           */
#define PE_PCS_SIRGAS_UTM_24S          31984 /* SIRGAS UTM zone 24S           */
#define PE_PCS_SIRGAS_UTM_25S          31985 /* SIRGAS UTM zone 25S           */
#define PE_PCS_ST_KITTS_1955_BRITISH_W_INDIES   2005 /* St Kitts 1955 British W Indies Grid */
#define PE_PCS_ST_LUCIA_1955_BRITISH_W_INDIES   2006 /* St Lucia 1955 British W Indies Grid */
#define PE_PCS_ST_VINCENT_1945_BRITISH_W_INDIES 2007 /* St Vincent 1945 British W Indies Grid */
#define PE_PCS_SOUTH_YEMEN_GK_8         2091 /* South Yemen Gauss-Kruger zone 8 */
#define PE_PCS_SOUTH_YEMEN_GK_9         2092 /* South Yemen Gauss-Kruger zone 9 */
#define PE_PCS_SUDAN_UTM_35N           29635 /* Sudan UTM Zone 35N            */
#define PE_PCS_SUDAN_UTM_36N           29636 /* Sudan UTM Zone 36N            */
#define PE_PCS_S_JTSK_FERRO_KROVAK      2065 /* S-JTSK (Ferro) Krovak         */
#define PE_PCS_TANANARIVE_UTM_38S      29738 /* Tananarive 1925 UTM Zone 38S  */
#define PE_PCS_TANANARIVE_UTM_39S      29739 /* Tananarive 1925 UTM Zone 39S  */
#define PE_PCS_TC_1948_UTM_39N       30339 /* Trucial Coast 1948 UTM Zone 39N */
#define PE_PCS_TC_1948_UTM_40N       30340 /* Trucial Coast 1948 UTM Zone 40N */
#define PE_PCS_TETE_UTM_36S             2736 /* Tete UTM Zone 36S             */
#define PE_PCS_TETE_UTM_37S             2737 /* Tete UTM Zone 37S             */
#define PE_PCS_TIMBALAI_1948_UTM_49N   29849 /* Timbalai 1948 UTM Zone 49N    */
#define PE_PCS_TIMBALAI_1948_UTM_50N   29850 /* Timbalai 1948 UTM Zone 50N    */
#define PE_PCS_TM65_IRISH_GRID         29900 /* Irish National Grid           */
#define PE_PCS_TOKYO_JAPAN_1           30161 /* Tokyo Japan Zone 1            */
#define PE_PCS_TOKYO_JAPAN_2           30162 /* Tokyo Japan Zone 2            */
#define PE_PCS_TOKYO_JAPAN_3           30163 /* Tokyo Japan Zone 3            */
#define PE_PCS_TOKYO_JAPAN_4           30164 /* Tokyo Japan Zone 4            */
#define PE_PCS_TOKYO_JAPAN_5           30165 /* Tokyo Japan Zone 5            */
#define PE_PCS_TOKYO_JAPAN_6           30166 /* Tokyo Japan Zone 6            */
#define PE_PCS_TOKYO_JAPAN_7           30167 /* Tokyo Japan Zone 7            */
#define PE_PCS_TOKYO_JAPAN_8           30168 /* Tokyo Japan Zone 8            */
#define PE_PCS_TOKYO_JAPAN_9           30169 /* Tokyo Japan Zone 9            */
#define PE_PCS_TOKYO_JAPAN_10          30170 /* Tokyo Japan Zone 10           */
#define PE_PCS_TOKYO_JAPAN_11          30171 /* Tokyo Japan Zone 11           */
#define PE_PCS_TOKYO_JAPAN_12          30172 /* Tokyo Japan Zone 12           */
#define PE_PCS_TOKYO_JAPAN_13          30173 /* Tokyo Japan Zone 13           */
#define PE_PCS_TOKYO_JAPAN_14          30174 /* Tokyo Japan Zone 14           */
#define PE_PCS_TOKYO_JAPAN_15          30175 /* Tokyo Japan Zone 15           */
#define PE_PCS_TOKYO_JAPAN_16          30176 /* Tokyo Japan Zone 16           */
#define PE_PCS_TOKYO_JAPAN_17          30177 /* Tokyo Japan Zone 17           */
#define PE_PCS_TOKYO_JAPAN_18          30178 /* Tokyo Japan Zone 18           */
#define PE_PCS_TOKYO_JAPAN_19          30179 /* Tokyo Japan Zone 19           */
#define PE_PCS_TRINIDAD_1903_TRINIDAD_GRID  30200 /* Trinidad 1903 Trinidad Grid */
#define PE_PCS_VOIROL_N_ALGERIE_ANCIENNE  30491 /* Nord Algerie ancienne      */
#define PE_PCS_VOIROL_S_ALGERIE_ANCIENNE  30492 /* Sud Algerie ancienne       */
#define PE_PCS_VOIROL_UNIFIE_N_ALGERIE    30591 /* Nord Algerie               */
#define PE_PCS_VOIROL_UNIFIE_S_ALGERIE    30592 /* Sud Algerie                */

/* World Geodetic System 1972 */
#define PE_PCS_WGS_1972_BE_TM_106_NE    2094 /* WGS 1972 BE TM 106 NE         */
#define PE_PCS_WGS_1972_UTM_1N         32201 /* WGS 1972 UTM Zone 1N          */
#define PE_PCS_WGS_1972_UTM_2N         32202 /* WGS 1972 UTM Zone 2N          */
#define PE_PCS_WGS_1972_UTM_3N         32203 /* WGS 1972 UTM Zone 3N          */
#define PE_PCS_WGS_1972_UTM_4N         32204 /* WGS 1972 UTM Zone 4N          */
#define PE_PCS_WGS_1972_UTM_5N         32205 /* WGS 1972 UTM Zone 5N          */
#define PE_PCS_WGS_1972_UTM_6N         32206 /* WGS 1972 UTM Zone 6N          */
#define PE_PCS_WGS_1972_UTM_7N         32207 /* WGS 1972 UTM Zone 7N          */
#define PE_PCS_WGS_1972_UTM_8N         32208 /* WGS 1972 UTM Zone 8N          */
#define PE_PCS_WGS_1972_UTM_9N         32209 /* WGS 1972 UTM Zone 9N          */
#define PE_PCS_WGS_1972_UTM_10N        32210 /* WGS 1972 UTM Zone 10N         */
#define PE_PCS_WGS_1972_UTM_11N        32211 /* WGS 1972 UTM Zone 11N         */
#define PE_PCS_WGS_1972_UTM_12N        32212 /* WGS 1972 UTM Zone 12N         */
#define PE_PCS_WGS_1972_UTM_13N        32213 /* WGS 1972 UTM Zone 13N         */
#define PE_PCS_WGS_1972_UTM_14N        32214 /* WGS 1972 UTM Zone 14N         */
#define PE_PCS_WGS_1972_UTM_15N        32215 /* WGS 1972 UTM Zone 15N         */
#define PE_PCS_WGS_1972_UTM_16N        32216 /* WGS 1972 UTM Zone 16N         */
#define PE_PCS_WGS_1972_UTM_17N        32217 /* WGS 1972 UTM Zone 17N         */
#define PE_PCS_WGS_1972_UTM_18N        32218 /* WGS 1972 UTM Zone 18N         */
#define PE_PCS_WGS_1972_UTM_19N        32219 /* WGS 1972 UTM Zone 19N         */
#define PE_PCS_WGS_1972_UTM_20N        32220 /* WGS 1972 UTM Zone 20N         */
#define PE_PCS_WGS_1972_UTM_21N        32221 /* WGS 1972 UTM Zone 21N         */
#define PE_PCS_WGS_1972_UTM_22N        32222 /* WGS 1972 UTM Zone 22N         */
#define PE_PCS_WGS_1972_UTM_23N        32223 /* WGS 1972 UTM Zone 23N         */
#define PE_PCS_WGS_1972_UTM_24N        32224 /* WGS 1972 UTM Zone 24N         */
#define PE_PCS_WGS_1972_UTM_25N        32225 /* WGS 1972 UTM Zone 25N         */
#define PE_PCS_WGS_1972_UTM_26N        32226 /* WGS 1972 UTM Zone 26N         */
#define PE_PCS_WGS_1972_UTM_27N        32227 /* WGS 1972 UTM Zone 27N         */
#define PE_PCS_WGS_1972_UTM_28N        32228 /* WGS 1972 UTM Zone 28N         */
#define PE_PCS_WGS_1972_UTM_29N        32229 /* WGS 1972 UTM Zone 29N         */
#define PE_PCS_WGS_1972_UTM_30N        32230 /* WGS 1972 UTM Zone 30N         */
#define PE_PCS_WGS_1972_UTM_31N        32231 /* WGS 1972 UTM Zone 31N         */
#define PE_PCS_WGS_1972_UTM_32N        32232 /* WGS 1972 UTM Zone 32N         */
#define PE_PCS_WGS_1972_UTM_33N        32233 /* WGS 1972 UTM Zone 33N         */
#define PE_PCS_WGS_1972_UTM_34N        32234 /* WGS 1972 UTM Zone 34N         */
#define PE_PCS_WGS_1972_UTM_35N        32235 /* WGS 1972 UTM Zone 35N         */
#define PE_PCS_WGS_1972_UTM_36N        32236 /* WGS 1972 UTM Zone 36N         */
#define PE_PCS_WGS_1972_UTM_37N        32237 /* WGS 1972 UTM Zone 37N         */
#define PE_PCS_WGS_1972_UTM_38N        32238 /* WGS 1972 UTM Zone 38N         */
#define PE_PCS_WGS_1972_UTM_39N        32239 /* WGS 1972 UTM Zone 39N         */
#define PE_PCS_WGS_1972_UTM_40N        32240 /* WGS 1972 UTM Zone 40N         */
#define PE_PCS_WGS_1972_UTM_41N        32241 /* WGS 1972 UTM Zone 41N         */
#define PE_PCS_WGS_1972_UTM_42N        32242 /* WGS 1972 UTM Zone 42N         */
#define PE_PCS_WGS_1972_UTM_43N        32243 /* WGS 1972 UTM Zone 43N         */
#define PE_PCS_WGS_1972_UTM_44N        32244 /* WGS 1972 UTM Zone 44N         */
#define PE_PCS_WGS_1972_UTM_45N        32245 /* WGS 1972 UTM Zone 45N         */
#define PE_PCS_WGS_1972_UTM_46N        32246 /* WGS 1972 UTM Zone 46N         */
#define PE_PCS_WGS_1972_UTM_47N        32247 /* WGS 1972 UTM Zone 47N         */
#define PE_PCS_WGS_1972_UTM_48N        32248 /* WGS 1972 UTM Zone 48N         */
#define PE_PCS_WGS_1972_UTM_49N        32249 /* WGS 1972 UTM Zone 49N         */
#define PE_PCS_WGS_1972_UTM_50N        32250 /* WGS 1972 UTM Zone 50N         */
#define PE_PCS_WGS_1972_UTM_51N        32251 /* WGS 1972 UTM Zone 51N         */
#define PE_PCS_WGS_1972_UTM_52N        32252 /* WGS 1972 UTM Zone 52N         */
#define PE_PCS_WGS_1972_UTM_53N        32253 /* WGS 1972 UTM Zone 53N         */
#define PE_PCS_WGS_1972_UTM_54N        32254 /* WGS 1972 UTM Zone 54N         */
#define PE_PCS_WGS_1972_UTM_55N        32255 /* WGS 1972 UTM Zone 55N         */
#define PE_PCS_WGS_1972_UTM_56N        32256 /* WGS 1972 UTM Zone 56N         */
#define PE_PCS_WGS_1972_UTM_57N        32257 /* WGS 1972 UTM Zone 57N         */
#define PE_PCS_WGS_1972_UTM_58N        32258 /* WGS 1972 UTM Zone 58N         */
#define PE_PCS_WGS_1972_UTM_59N        32259 /* WGS 1972 UTM Zone 59N         */
#define PE_PCS_WGS_1972_UTM_60N        32260 /* WGS 1972 UTM Zone 60N         */

#define PE_PCS_WGS_1972_UTM_1S         32301 /* WGS 1972 UTM Zone 1S          */
#define PE_PCS_WGS_1972_UTM_2S         32302 /* WGS 1972 UTM Zone 2S          */
#define PE_PCS_WGS_1972_UTM_3S         32303 /* WGS 1972 UTM Zone 3S          */
#define PE_PCS_WGS_1972_UTM_4S         32304 /* WGS 1972 UTM Zone 4S          */
#define PE_PCS_WGS_1972_UTM_5S         32305 /* WGS 1972 UTM Zone 5S          */
#define PE_PCS_WGS_1972_UTM_6S         32306 /* WGS 1972 UTM Zone 6S          */
#define PE_PCS_WGS_1972_UTM_7S         32307 /* WGS 1972 UTM Zone 7S          */
#define PE_PCS_WGS_1972_UTM_8S         32308 /* WGS 1972 UTM Zone 8S          */
#define PE_PCS_WGS_1972_UTM_9S         32309 /* WGS 1972 UTM Zone 9S          */
#define PE_PCS_WGS_1972_UTM_10S        32310 /* WGS 1972 UTM Zone 10S         */
#define PE_PCS_WGS_1972_UTM_11S        32311 /* WGS 1972 UTM Zone 11S         */
#define PE_PCS_WGS_1972_UTM_12S        32312 /* WGS 1972 UTM Zone 12S         */
#define PE_PCS_WGS_1972_UTM_13S        32313 /* WGS 1972 UTM Zone 13S         */
#define PE_PCS_WGS_1972_UTM_14S        32314 /* WGS 1972 UTM Zone 14S         */
#define PE_PCS_WGS_1972_UTM_15S        32315 /* WGS 1972 UTM Zone 15S         */
#define PE_PCS_WGS_1972_UTM_16S        32316 /* WGS 1972 UTM Zone 16S         */
#define PE_PCS_WGS_1972_UTM_17S        32317 /* WGS 1972 UTM Zone 17S         */
#define PE_PCS_WGS_1972_UTM_18S        32318 /* WGS 1972 UTM Zone 18S         */
#define PE_PCS_WGS_1972_UTM_19S        32319 /* WGS 1972 UTM Zone 19S         */
#define PE_PCS_WGS_1972_UTM_20S        32320 /* WGS 1972 UTM Zone 20S         */
#define PE_PCS_WGS_1972_UTM_21S        32321 /* WGS 1972 UTM Zone 21S         */
#define PE_PCS_WGS_1972_UTM_22S        32322 /* WGS 1972 UTM Zone 22S         */
#define PE_PCS_WGS_1972_UTM_23S        32323 /* WGS 1972 UTM Zone 23S         */
#define PE_PCS_WGS_1972_UTM_24S        32324 /* WGS 1972 UTM Zone 24S         */
#define PE_PCS_WGS_1972_UTM_25S        32325 /* WGS 1972 UTM Zone 25S         */
#define PE_PCS_WGS_1972_UTM_26S        32326 /* WGS 1972 UTM Zone 26S         */
#define PE_PCS_WGS_1972_UTM_27S        32327 /* WGS 1972 UTM Zone 27S         */
#define PE_PCS_WGS_1972_UTM_28S        32328 /* WGS 1972 UTM Zone 28S         */
#define PE_PCS_WGS_1972_UTM_29S        32329 /* WGS 1972 UTM Zone 29S         */
#define PE_PCS_WGS_1972_UTM_30S        32330 /* WGS 1972 UTM Zone 30S         */
#define PE_PCS_WGS_1972_UTM_31S        32331 /* WGS 1972 UTM Zone 31S         */
#define PE_PCS_WGS_1972_UTM_32S        32332 /* WGS 1972 UTM Zone 32S         */
#define PE_PCS_WGS_1972_UTM_33S        32333 /* WGS 1972 UTM Zone 33S         */
#define PE_PCS_WGS_1972_UTM_34S        32334 /* WGS 1972 UTM Zone 34S         */
#define PE_PCS_WGS_1972_UTM_35S        32335 /* WGS 1972 UTM Zone 35S         */
#define PE_PCS_WGS_1972_UTM_36S        32336 /* WGS 1972 UTM Zone 36S         */
#define PE_PCS_WGS_1972_UTM_37S        32337 /* WGS 1972 UTM Zone 37S         */
#define PE_PCS_WGS_1972_UTM_38S        32338 /* WGS 1972 UTM Zone 38S         */
#define PE_PCS_WGS_1972_UTM_39S        32339 /* WGS 1972 UTM Zone 39S         */
#define PE_PCS_WGS_1972_UTM_40S        32340 /* WGS 1972 UTM Zone 40S         */
#define PE_PCS_WGS_1972_UTM_41S        32341 /* WGS 1972 UTM Zone 41S         */
#define PE_PCS_WGS_1972_UTM_42S        32342 /* WGS 1972 UTM Zone 42S         */
#define PE_PCS_WGS_1972_UTM_43S        32343 /* WGS 1972 UTM Zone 43S         */
#define PE_PCS_WGS_1972_UTM_44S        32344 /* WGS 1972 UTM Zone 44S         */
#define PE_PCS_WGS_1972_UTM_45S        32345 /* WGS 1972 UTM Zone 45S         */
#define PE_PCS_WGS_1972_UTM_46S        32346 /* WGS 1972 UTM Zone 46S         */
#define PE_PCS_WGS_1972_UTM_47S        32347 /* WGS 1972 UTM Zone 47S         */
#define PE_PCS_WGS_1972_UTM_48S        32348 /* WGS 1972 UTM Zone 48S         */
#define PE_PCS_WGS_1972_UTM_49S        32349 /* WGS 1972 UTM Zone 49S         */
#define PE_PCS_WGS_1972_UTM_50S        32350 /* WGS 1972 UTM Zone 50S         */
#define PE_PCS_WGS_1972_UTM_51S        32351 /* WGS 1972 UTM Zone 51S         */
#define PE_PCS_WGS_1972_UTM_52S        32352 /* WGS 1972 UTM Zone 52S         */
#define PE_PCS_WGS_1972_UTM_53S        32353 /* WGS 1972 UTM Zone 53S         */
#define PE_PCS_WGS_1972_UTM_54S        32354 /* WGS 1972 UTM Zone 54S         */
#define PE_PCS_WGS_1972_UTM_55S        32355 /* WGS 1972 UTM Zone 55S         */
#define PE_PCS_WGS_1972_UTM_56S        32356 /* WGS 1972 UTM Zone 56S         */
#define PE_PCS_WGS_1972_UTM_57S        32357 /* WGS 1972 UTM Zone 57S         */
#define PE_PCS_WGS_1972_UTM_58S        32358 /* WGS 1972 UTM Zone 58S         */
#define PE_PCS_WGS_1972_UTM_59S        32359 /* WGS 1972 UTM Zone 59S         */
#define PE_PCS_WGS_1972_UTM_60S        32360 /* WGS 1972 UTM Zone 60S         */


/* World Geodetic System 1984 */
#define PE_PCS_WGS_1984_TM_36_SE    32766 /* WGS 84 TM 36 SE - Mozambique     */
#define PE_PCS_WGS_1984_UPS_NORTH   32661 /* Universal Polar Stereographic NP */
#define PE_PCS_WGS_1984_UPS_SOUTH   32761 /* Universal Polar Stereographic SP */ 
#define PE_PCS_WGS_1984_UTM_1N         32601 /* WGS 1984 UTM Zone 1N          */
#define PE_PCS_WGS_1984_UTM_2N         32602 /* WGS 1984 UTM Zone 2N          */
#define PE_PCS_WGS_1984_UTM_3N         32603 /* WGS 1984 UTM Zone 3N          */
#define PE_PCS_WGS_1984_UTM_4N         32604 /* WGS 1984 UTM Zone 4N          */
#define PE_PCS_WGS_1984_UTM_5N         32605 /* WGS 1984 UTM Zone 5N          */
#define PE_PCS_WGS_1984_UTM_6N         32606 /* WGS 1984 UTM Zone 6N          */
#define PE_PCS_WGS_1984_UTM_7N         32607 /* WGS 1984 UTM Zone 7N          */
#define PE_PCS_WGS_1984_UTM_8N         32608 /* WGS 1984 UTM Zone 8N          */
#define PE_PCS_WGS_1984_UTM_9N         32609 /* WGS 1984 UTM Zone 9N          */
#define PE_PCS_WGS_1984_UTM_10N        32610 /* WGS 1984 UTM Zone 10N         */
#define PE_PCS_WGS_1984_UTM_11N        32611 /* WGS 1984 UTM Zone 11N         */
#define PE_PCS_WGS_1984_UTM_12N        32612 /* WGS 1984 UTM Zone 12N         */
#define PE_PCS_WGS_1984_UTM_13N        32613 /* WGS 1984 UTM Zone 13N         */
#define PE_PCS_WGS_1984_UTM_14N        32614 /* WGS 1984 UTM Zone 14N         */
#define PE_PCS_WGS_1984_UTM_15N        32615 /* WGS 1984 UTM Zone 15N         */
#define PE_PCS_WGS_1984_UTM_16N        32616 /* WGS 1984 UTM Zone 16N         */
#define PE_PCS_WGS_1984_UTM_17N        32617 /* WGS 1984 UTM Zone 17N         */
#define PE_PCS_WGS_1984_UTM_18N        32618 /* WGS 1984 UTM Zone 18N         */
#define PE_PCS_WGS_1984_UTM_19N        32619 /* WGS 1984 UTM Zone 19N         */
#define PE_PCS_WGS_1984_UTM_20N        32620 /* WGS 1984 UTM Zone 20N         */
#define PE_PCS_WGS_1984_UTM_21N        32621 /* WGS 1984 UTM Zone 21N         */
#define PE_PCS_WGS_1984_UTM_22N        32622 /* WGS 1984 UTM Zone 22N         */
#define PE_PCS_WGS_1984_UTM_23N        32623 /* WGS 1984 UTM Zone 23N         */
#define PE_PCS_WGS_1984_UTM_24N        32624 /* WGS 1984 UTM Zone 24N         */
#define PE_PCS_WGS_1984_UTM_25N        32625 /* WGS 1984 UTM Zone 25N         */
#define PE_PCS_WGS_1984_UTM_26N        32626 /* WGS 1984 UTM Zone 26N         */
#define PE_PCS_WGS_1984_UTM_27N        32627 /* WGS 1984 UTM Zone 27N         */
#define PE_PCS_WGS_1984_UTM_28N        32628 /* WGS 1984 UTM Zone 28N         */
#define PE_PCS_WGS_1984_UTM_29N        32629 /* WGS 1984 UTM Zone 29N         */
#define PE_PCS_WGS_1984_UTM_30N        32630 /* WGS 1984 UTM Zone 30N         */
#define PE_PCS_WGS_1984_UTM_31N        32631 /* WGS 1984 UTM Zone 31N         */
#define PE_PCS_WGS_1984_UTM_32N        32632 /* WGS 1984 UTM Zone 32N         */
#define PE_PCS_WGS_1984_UTM_33N        32633 /* WGS 1984 UTM Zone 33N         */
#define PE_PCS_WGS_1984_UTM_34N        32634 /* WGS 1984 UTM Zone 34N         */
#define PE_PCS_WGS_1984_UTM_35N        32635 /* WGS 1984 UTM Zone 35N         */
#define PE_PCS_WGS_1984_UTM_36N        32636 /* WGS 1984 UTM Zone 36N         */
#define PE_PCS_WGS_1984_UTM_37N        32637 /* WGS 1984 UTM Zone 37N         */
#define PE_PCS_WGS_1984_UTM_38N        32638 /* WGS 1984 UTM Zone 38N         */
#define PE_PCS_WGS_1984_UTM_39N        32639 /* WGS 1984 UTM Zone 39N         */
#define PE_PCS_WGS_1984_UTM_40N        32640 /* WGS 1984 UTM Zone 40N         */
#define PE_PCS_WGS_1984_UTM_41N        32641 /* WGS 1984 UTM Zone 41N         */
#define PE_PCS_WGS_1984_UTM_42N        32642 /* WGS 1984 UTM Zone 42N         */
#define PE_PCS_WGS_1984_UTM_43N        32643 /* WGS 1984 UTM Zone 43N         */
#define PE_PCS_WGS_1984_UTM_44N        32644 /* WGS 1984 UTM Zone 44N         */
#define PE_PCS_WGS_1984_UTM_45N        32645 /* WGS 1984 UTM Zone 45N         */
#define PE_PCS_WGS_1984_UTM_46N        32646 /* WGS 1984 UTM Zone 46N         */
#define PE_PCS_WGS_1984_UTM_47N        32647 /* WGS 1984 UTM Zone 47N         */
#define PE_PCS_WGS_1984_UTM_48N        32648 /* WGS 1984 UTM Zone 48N         */
#define PE_PCS_WGS_1984_UTM_49N        32649 /* WGS 1984 UTM Zone 49N         */
#define PE_PCS_WGS_1984_UTM_50N        32650 /* WGS 1984 UTM Zone 50N         */
#define PE_PCS_WGS_1984_UTM_51N        32651 /* WGS 1984 UTM Zone 51N         */
#define PE_PCS_WGS_1984_UTM_52N        32652 /* WGS 1984 UTM Zone 52N         */
#define PE_PCS_WGS_1984_UTM_53N        32653 /* WGS 1984 UTM Zone 53N         */
#define PE_PCS_WGS_1984_UTM_54N        32654 /* WGS 1984 UTM Zone 54N         */
#define PE_PCS_WGS_1984_UTM_55N        32655 /* WGS 1984 UTM Zone 55N         */
#define PE_PCS_WGS_1984_UTM_56N        32656 /* WGS 1984 UTM Zone 56N         */
#define PE_PCS_WGS_1984_UTM_57N        32657 /* WGS 1984 UTM Zone 57N         */
#define PE_PCS_WGS_1984_UTM_58N        32658 /* WGS 1984 UTM Zone 58N         */
#define PE_PCS_WGS_1984_UTM_59N        32659 /* WGS 1984 UTM Zone 59N         */
#define PE_PCS_WGS_1984_UTM_60N        32660 /* WGS 1984 UTM Zone 60N         */

#define PE_PCS_WGS_1984_UTM_1S         32701 /* WGS 1984 UTM Zone 1S          */
#define PE_PCS_WGS_1984_UTM_2S         32702 /* WGS 1984 UTM Zone 2S          */
#define PE_PCS_WGS_1984_UTM_3S         32703 /* WGS 1984 UTM Zone 3S          */
#define PE_PCS_WGS_1984_UTM_4S         32704 /* WGS 1984 UTM Zone 4S          */
#define PE_PCS_WGS_1984_UTM_5S         32705 /* WGS 1984 UTM Zone 5S          */
#define PE_PCS_WGS_1984_UTM_6S         32706 /* WGS 1984 UTM Zone 6S          */
#define PE_PCS_WGS_1984_UTM_7S         32707 /* WGS 1984 UTM Zone 7S          */
#define PE_PCS_WGS_1984_UTM_8S         32708 /* WGS 1984 UTM Zone 8S          */
#define PE_PCS_WGS_1984_UTM_9S         32709 /* WGS 1984 UTM Zone 9S          */
#define PE_PCS_WGS_1984_UTM_10S        32710 /* WGS 1984 UTM Zone 10S         */
#define PE_PCS_WGS_1984_UTM_11S        32711 /* WGS 1984 UTM Zone 11S         */
#define PE_PCS_WGS_1984_UTM_12S        32712 /* WGS 1984 UTM Zone 12S         */
#define PE_PCS_WGS_1984_UTM_13S        32713 /* WGS 1984 UTM Zone 13S         */
#define PE_PCS_WGS_1984_UTM_14S        32714 /* WGS 1984 UTM Zone 14S         */
#define PE_PCS_WGS_1984_UTM_15S        32715 /* WGS 1984 UTM Zone 15S         */
#define PE_PCS_WGS_1984_UTM_16S        32716 /* WGS 1984 UTM Zone 16S         */
#define PE_PCS_WGS_1984_UTM_17S        32717 /* WGS 1984 UTM Zone 17S         */
#define PE_PCS_WGS_1984_UTM_18S        32718 /* WGS 1984 UTM Zone 18S         */
#define PE_PCS_WGS_1984_UTM_19S        32719 /* WGS 1984 UTM Zone 19S         */
#define PE_PCS_WGS_1984_UTM_20S        32720 /* WGS 1984 UTM Zone 20S         */
#define PE_PCS_WGS_1984_UTM_21S        32721 /* WGS 1984 UTM Zone 21S         */
#define PE_PCS_WGS_1984_UTM_22S        32722 /* WGS 1984 UTM Zone 22S         */
#define PE_PCS_WGS_1984_UTM_23S        32723 /* WGS 1984 UTM Zone 23S         */
#define PE_PCS_WGS_1984_UTM_24S        32724 /* WGS 1984 UTM Zone 24S         */
#define PE_PCS_WGS_1984_UTM_25S        32725 /* WGS 1984 UTM Zone 25S         */
#define PE_PCS_WGS_1984_UTM_26S        32726 /* WGS 1984 UTM Zone 26S         */
#define PE_PCS_WGS_1984_UTM_27S        32727 /* WGS 1984 UTM Zone 27S         */
#define PE_PCS_WGS_1984_UTM_28S        32728 /* WGS 1984 UTM Zone 28S         */
#define PE_PCS_WGS_1984_UTM_29S        32729 /* WGS 1984 UTM Zone 29S         */
#define PE_PCS_WGS_1984_UTM_30S        32730 /* WGS 1984 UTM Zone 30S         */
#define PE_PCS_WGS_1984_UTM_31S        32731 /* WGS 1984 UTM Zone 31S         */
#define PE_PCS_WGS_1984_UTM_32S        32732 /* WGS 1984 UTM Zone 32S         */
#define PE_PCS_WGS_1984_UTM_33S        32733 /* WGS 1984 UTM Zone 33S         */
#define PE_PCS_WGS_1984_UTM_34S        32734 /* WGS 1984 UTM Zone 34S         */
#define PE_PCS_WGS_1984_UTM_35S        32735 /* WGS 1984 UTM Zone 35S         */
#define PE_PCS_WGS_1984_UTM_36S        32736 /* WGS 1984 UTM Zone 36S         */
#define PE_PCS_WGS_1984_UTM_37S        32737 /* WGS 1984 UTM Zone 37S         */
#define PE_PCS_WGS_1984_UTM_38S        32738 /* WGS 1984 UTM Zone 38S         */
#define PE_PCS_WGS_1984_UTM_39S        32739 /* WGS 1984 UTM Zone 39S         */
#define PE_PCS_WGS_1984_UTM_40S        32740 /* WGS 1984 UTM Zone 40S         */
#define PE_PCS_WGS_1984_UTM_41S        32741 /* WGS 1984 UTM Zone 41S         */
#define PE_PCS_WGS_1984_UTM_42S        32742 /* WGS 1984 UTM Zone 42S         */
#define PE_PCS_WGS_1984_UTM_43S        32743 /* WGS 1984 UTM Zone 43S         */
#define PE_PCS_WGS_1984_UTM_44S        32744 /* WGS 1984 UTM Zone 44S         */
#define PE_PCS_WGS_1984_UTM_45S        32745 /* WGS 1984 UTM Zone 45S         */
#define PE_PCS_WGS_1984_UTM_46S        32746 /* WGS 1984 UTM Zone 46S         */
#define PE_PCS_WGS_1984_UTM_47S        32747 /* WGS 1984 UTM Zone 47S         */
#define PE_PCS_WGS_1984_UTM_48S        32748 /* WGS 1984 UTM Zone 48S         */
#define PE_PCS_WGS_1984_UTM_49S        32749 /* WGS 1984 UTM Zone 49S         */
#define PE_PCS_WGS_1984_UTM_50S        32750 /* WGS 1984 UTM Zone 50S         */
#define PE_PCS_WGS_1984_UTM_51S        32751 /* WGS 1984 UTM Zone 51S         */
#define PE_PCS_WGS_1984_UTM_52S        32752 /* WGS 1984 UTM Zone 52S         */
#define PE_PCS_WGS_1984_UTM_53S        32753 /* WGS 1984 UTM Zone 53S         */
#define PE_PCS_WGS_1984_UTM_54S        32754 /* WGS 1984 UTM Zone 54S         */
#define PE_PCS_WGS_1984_UTM_55S        32755 /* WGS 1984 UTM Zone 55S         */
#define PE_PCS_WGS_1984_UTM_56S        32756 /* WGS 1984 UTM Zone 56S         */
#define PE_PCS_WGS_1984_UTM_57S        32757 /* WGS 1984 UTM Zone 57S         */
#define PE_PCS_WGS_1984_UTM_58S        32758 /* WGS 1984 UTM Zone 58S         */
#define PE_PCS_WGS_1984_UTM_59S        32759 /* WGS 1984 UTM Zone 59S         */
#define PE_PCS_WGS_1984_UTM_60S        32760 /* WGS 1984 UTM Zone 60S         */


#define PE_PCS_YEMEN_NGN_1996_UTM_38N   2089 /* Yemen NGN 1996 UTM zone 38N   */
#define PE_PCS_YEMEN_NGN_1996_UTM_39N   2090 /* Yemen NGN 1996 UTM zone 39N   */
#define PE_PCS_YOFF_1972_UTM_28N       31028 /* Yoff 1972 UTM Zone 28N        */
#define PE_PCS_ZANDERIJ_1972_UTM_21N     31121 /* Zanderij 1972 UTM Zone 21N  */
#define PE_PCS_ZANDERIJ_SURINAME_OLD_TM  31170 /* Zanderij Old TM             */
#define PE_PCS_ZANDERIJ_SURINAME_TM      31171 /* Zanderij TM                 */
#define PE_PCS_ZANDERIJ_TM_54_NW         31154 /* Zanderij TM 54 NW           */

/* ---------------------------------------- */


#define PE_PCS_NAD_1983_CANADA_ALBERS        102001 /* NAD 1983 Albers Canada */
#define PE_PCS_NAD_1983_CANADA_LAMBERT       102002 /* NAD 1983 Lambert Canada */
#define PE_PCS_NAD_1983_USA_ALBERS           102003 /* NAD 1983 Albers contiguous USA */
#define PE_PCS_NAD_1983_USA_LAMBERT          102004 /* NAD 1983 Lambert contiguous USA */
#define PE_PCS_NAD_1983_USA_EQUI_CONIC       102005 /* NAD 1983 Equidistant Conic contiguous USA */
#define PE_PCS_NAD_1983_ALASKA_ALBERS        102006 /* NAD 1983 Albers Alaska */
#define PE_PCS_NAD_1983_HAWAII_ALBERS        102007 /* NAD 1983 Albers Hawaii */
#define PE_PCS_NAD_1983_N_AMERICA_ALBERS     102008 /* NAD 1983 Albers North America */
#define PE_PCS_NAD_1983_N_AMERICA_LAMBERT    102009 /* NAD 1983 Lambert North America */
#define PE_PCS_NAD_1983_N_AMERICA_EQUI_CONIC 102010 /* NAD 1983 Equidistant Conic North America */
#define PE_PCS_WGS_1984_AFRICA_SINUSOIDAL    102011 /* WGS 1984 Sinusoidal Africa */
#define PE_PCS_WGS_1984_ASIA_LAMBERT         102012 /* WGS 1984 Lambert Asia  */
#define PE_PCS_ED_1950_EUROPE_ALBERS         102013 /* ED 1950 Albers Europe  */
#define PE_PCS_ED_1950_EUROPE_LAMBERT        102014 /* ED 1950 Lambert Europe */
#define PE_PCS_SAD_1969_S_AMERICA_LAMBERT    102015 /* SAD 1969 Lambert South America */
#define PE_PCS_WGS_1984_N_POLE_AZI_EQUI      102016 /* WGS 1984 Azimuthal Equidistant North Pole */
#define PE_PCS_WGS_1984_N_POLE_LAMBERT_AZI_EQAREA 102017 
                                                    /* WGS 1984 Lambert Azimuthal EqArea North Pole */
#define PE_PCS_WGS_1984_N_POLE_STEREOGRAPHIC 102018 /* WGS 1984 Stereographic North Pole */
#define PE_PCS_WGS_1984_S_POLE_AZI_EQUI      102019 /* WGS 1984 Azimuthal Equidistant South Pole */
#define PE_PCS_WGS_1984_S_POLE_LAMBERT_AZI_EQAREA 102020 
                                                    /* WGS 1984 Lambert Azimuthal EqArea South Pole */
#define PE_PCS_WGS_1984_S_POLE_STEREOGRAPHIC 102021 /* WGS 1984 Stereographic South Pole */

#define PE_PCS_WGS_1984_AFRICA_ALBERS        102022 /* WGS 1984 Albers for Africa */
#define PE_PCS_WGS_1984_AFRICA_EQUI_CONIC    102023 /* WGS 1984 Equidistant Conic for Africa */
#define PE_PCS_WGS_1984_AFRICA_LAMBERT       102024 /* WGS 1984 Lambert for Africa */
#define PE_PCS_WGS_1984_ASIA_NORTH_ALBERS    102025 /* WGS 1984 Albers for Northern Asia */
#define PE_PCS_WGS_1984_ASIA_NORTH_EQUI_CONIC 102026 /* WGS 1984 Equidistant Conic for Northern Asia */
#define PE_PCS_WGS_1984_ASIA_NORTH_LAMBERT   102027 /* WGS 1984 Lambert for Northern Asia */
#define PE_PCS_WGS_1984_ASIA_SOUTH_ALBERS    102028 /* WGS 1984 Albers for Southern Asia */
#define PE_PCS_WGS_1984_ASIA_SOUTH_EQUI_CONIC 102029 /* WGS 1984 Equidistant Conic for Southern Asia */
#define PE_PCS_WGS_1984_ASIA_SOUTH_LAMBERT   102030 /* WGS 1984 Lambert for Southern Asia */

#define PE_PCS_ED_1950_EUROPE_EQUI_CONIC     102031 /* ED 1950 Equidistant Conic for Europe */
#define PE_PCS_SAD_1969_S_AMERICA_EQUI_CONIC 102032 /* SAD 1969 Equidistant Conic for South America */
#define PE_PCS_SAD_1969_S_AMERICA_ALBERS     102033 /* SAD 1969 Albers for South America */

#define PE_PCS_WGS_1984_N_POLE_GNOMONIC      102034 /* WGS 1984 Gnomonic North Pole */
#define PE_PCS_WGS_1984_N_POLE_ORTHOGRAPHIC  102035 /* WGS 1984 Orthographic North Pole */
#define PE_PCS_WGS_1984_S_POLE_GNOMONIC      102036 /* WGS 1984 Gnomonic South Pole */
#define PE_PCS_WGS_1984_S_POLE_ORTHOGRAPHIC  102037 /* WGS 1984 Orthographic South Pole */
#define PE_PCS_THE_WORLD_FROM_SPACE          102038 /* The World from Space (center in MA) */
#define PE_PCS_NAD_1983_USGS_USA_ALBERS      102039 /* NAD 1983 USGS Contiguous USA Albers */

#define PE_PCS_S_JTSK_KROVAK          102065 /* S-JTSK Krovak                 */
#define PE_PCS_S_JTSK_FERRO_KROVAK_EN 102066 /* S-JTSK (Ferro) Krovak EastNorth XY */
#define PE_PCS_S_JTSK_KROVAK_EN       102067 /* S-JTSK Krovak EastNorth XY    */

#define PE_PCS_MONTE_MARIO_ITALY_1    3003 /* Monte Mario (Greenwich) Italy 1 */
#define PE_PCS_MONTE_MARIO_ITALY_2    3004 /* Monte Mario (Greenwich) Italy 2 */

#define PE_PCS_NGO_1948_NORWAY_1   102101 /* NGO 1948 Norway zone 1           */
#define PE_PCS_NGO_1948_NORWAY_2   102102 /* NGO 1948 Norway zone 2           */
#define PE_PCS_NGO_1948_NORWAY_3   102103 /* NGO 1948 Norway zone 3           */
#define PE_PCS_NGO_1948_NORWAY_4   102104 /* NGO 1948 Norway zone 4           */
#define PE_PCS_NGO_1948_NORWAY_5   102105 /* NGO 1948 Norway zone 5           */
#define PE_PCS_NGO_1948_NORWAY_6   102106 /* NGO 1948 Norway zone 6           */
#define PE_PCS_NGO_1948_NORWAY_7   102107 /* NGO 1948 Norway zone 7           */
#define PE_PCS_NGO_1948_NORWAY_8   102108 /* NGO 1948 Norway zone 8           */

#define PE_PCS_RGF_1993_LAMBERT_93   2154 /* RGF Lambert-93                   */

#define PE_PCS_OLD_HAWAIIAN_UTM_4N 102114 /* Old Hawaiian UTM zone 4N         */
#define PE_PCS_OLD_HAWAIIAN_UTM_5N 102115 /* Old Hawaiian UTM zone 5N         */

#define PE_PCS_NAD_1927_MICHIGAN_GEOREF   102120 /* NAD 1927 Michigan GeoRef (US Survey Feet) */
#define PE_PCS_NAD_1983_MICHIGAN_GEOREF   102121 /* NAD 1983 Michigan GeoRef (US Survey Feet) */
#define PE_PCS_NAD_1927_MICHIGAN_GEOREF_M 102122 /* NAD 1927 Michigan GeoRef (Meters) */
#define PE_PCS_NAD_1983_MICHIGAN_GEOREF_M 102123 /* NAD 1983 Michigan GeoRef (Meters) */

#define PE_PCS_NGO_1948_UTM_32N    102132 /* NGO 1948 UTM zone 32N            */
#define PE_PCS_NGO_1948_UTM_33N    102133 /* NGO 1948 UTM zone 33N            */
#define PE_PCS_NGO_1948_UTM_34N    102134 /* NGO 1948 UTM zone 34N            */
#define PE_PCS_NGO_1948_UTM_35N    102135 /* NGO 1948 UTM zone 35N            */

#define PE_PCS_NGO_1948_BAERUM_KOMMUNE  102136 /* NGO 1948 Baerum Kommune     */
#define PE_PCS_NGO_1948_BERGENHALVOEN   102137 /* NGO 1948 Bergenhalvoen      */
#define PE_PCS_NGO_1948_OSLO_KOMMUNE    102138 /* NGO 1948 Oslo Kommune       */

#define PE_PCS_HONG_KONG_1980_GRID       2326 /* Hong Kong 1980 Grid          */
#define PE_PCS_HONG_KONG_1980_UTM_49N  102141 /* Hong Kong 1980 UTM 49N       */
#define PE_PCS_HONG_KONG_1980_UTM_50N  102142 /* Hong Kong 1980 UTM 50N       */

#define PE_PCS_TOKYO_UTM_51N       102151 /* Tokyo UTM Zone 51N               */
#define PE_PCS_TOKYO_UTM_52N       102152 /* Tokyo UTM Zone 52N               */
#define PE_PCS_TOKYO_UTM_53N       102153 /* Tokyo UTM Zone 53N               */
#define PE_PCS_TOKYO_UTM_54N       102154 /* Tokyo UTM Zone 54N               */
#define PE_PCS_TOKYO_UTM_55N       102155 /* Tokyo UTM Zone 55N               */
#define PE_PCS_TOKYO_UTM_56N       102156 /* Tokyo UTM Zone 56N               */

#define PE_PCS_DATUM_73_HAYFORD_GAUSS_IGEOE 102160 /* Datum 73 Hayford Gauss IGeoE  */
#define PE_PCS_DATUM_73_HAYFORD_GAUSS_IPCC  102161 /* Datum 73 Hayford Gauss IPCC   */
#define PE_PCS_GRACIOSA_1948_UTM_26N        102162 /* Graciosa Base SW 1948 UTM Zone 26N */
#define PE_PCS_LISBOA_BESSEL_BONNE          102163 /* Lisboa Bessel Bonne           */
#define PE_PCS_LISBOA_HAYFORD_GAUSS_IGEOE   102164 /* Lisboa Hayford Gauss IGeoE    */
#define PE_PCS_LISBOA_HAYFORD_GAUSS_IPCC    102165 /* Lisboa Hayford Gauss IPCC     */
#define PE_PCS_OBSERV_METEOR_1939_UTM_25N   102166 /* Observ Meteorologico 1939 UTM Zone 25N */
#define PE_PCS_PORTO_SANTO_1936_UTM_28N       2942 /* Porto Santo 1936 UTM Zone 28N */
#define PE_PCS_SAO_BRAZ_UTM_26N             102168 /* Sao Braz UTM Zone 26N         */
#define PE_PCS_SELVAGEM_GRANDE_1938_UTM_28N 102169 /* Selvagem Grande 1938 UTM Zone 28N */

#define PE_PCS_AGD_1966_VICGRID          102170 /* Victoria Grid              */
#define PE_PCS_GDA_1994_VICGRID94        102171 /* Victoria Grid 1994         */
#define PE_PCS_GDA_1994_SOUTH_AUSTRALIA  102172 /* South Australia Lambert    */

#define PE_PCS_NAD_1927_10TM_AEP_FOREST   102178 /* NAD 1927 10TM AEP Forest  */
#define PE_PCS_NAD_1927_10TM_AEP_RESOURCE 102179 /* NAD 1927 10TM AEP Resource*/
#define PE_PCS_NAD_1927_3TM_111           102180 /* NAD 1927 3TM (cm 111)     */
#define PE_PCS_NAD_1927_3TM_114           102181 /* NAD 1927 3TM (cm 114)     */
#define PE_PCS_NAD_1927_3TM_117           102182 /* NAD 1927 3TM (cm 117)     */
#define PE_PCS_NAD_1927_3TM_120           102183 /* NAD 1927 3TM (cm 120)     */
#define PE_PCS_NAD_1983_10TM_AEP_FOREST   102184 /* NAD 1983 10TM AEP Forest  */
#define PE_PCS_NAD_1983_10TM_AEP_RESOURCE 102185 /* NAD 1983 10TM AEP Resource*/
#define PE_PCS_NAD_1983_3TM_111           102186 /* NAD 1983 3TM (cm 111)     */
#define PE_PCS_NAD_1983_3TM_114           102187 /* NAD 1983 3TM (cm 114)     */
#define PE_PCS_NAD_1983_3TM_117           102188 /* NAD 1983 3TM (cm 117)     */
#define PE_PCS_NAD_1983_3TM_120           102189 /* NAD 1983 3TM (cm 120)     */
#define PE_PCS_NAD_1983_BC_ENVIRONMENT_ALBERS   3005 /* BC Environment Albers */

#define PE_PCS_MERCHICH_DEGREE_NORD_MAROC 102191 /*Merchich(degrees) Nord Maroc*/
#define PE_PCS_MERCHICH_DEGREE_SUD_MAROC  102192 /*Merchich(degrees) Sud Maroc*/
#define PE_PCS_MERCHICH_DEGREE_SAHARA     102193 /* Merchich(degrees) Sahara  */

#define PE_PCS_UWPP_1992                  102194 /* ETRF 1989 Poland 1992     */
#define PE_PCS_UWPP_2000_PAS_5            102195 /* ETRF 1989 Poland zone 5   */
#define PE_PCS_UWPP_2000_PAS_6            102196 /* ETRF 1989 Poland zone 6   */
#define PE_PCS_UWPP_2000_PAS_7            102197 /* ETRF 1989 Poland zone 7   */
#define PE_PCS_UWPP_2000_PAS_8            102198 /* ETRF 1989 Poland zone 8   */

#define PE_PCS_NAD_1983_HARN_UTM_2S     2195 /* NAD 1983 (HARN) UTM zone 2S   */

#define PE_PCS_NAD_1983_HARN_GUAM_MAP_GRID 102201 /* NAD 1983 (HARN) Guam Map Grid */

/*       NAD 1983 HARN State Plane Coordinate System (in Meters)                   */
#define PE_PCS_NAD_1983_HARN_AL_E     2759 /* NAD 1983 HARN SPCS Alabama East      */
#define PE_PCS_NAD_1983_HARN_AL_W     2760 /* NAD 1983 HARN SPCS Alabama West      */
#define PE_PCS_NAD_1983_HARN_AZ_E     2761 /* NAD 1983 HARN SPCS Arizona East      */
#define PE_PCS_NAD_1983_HARN_AZ_C     2762 /* NAD 1983 HARN SPCS Arizona Central   */
#define PE_PCS_NAD_1983_HARN_AZ_W     2763 /* NAD 1983 HARN SPCS Arizona West      */
#define PE_PCS_NAD_1983_HARN_AR_N     2764 /* NAD 1983 HARN Zone Arkansas North    */
#define PE_PCS_NAD_1983_HARN_AR_S     2765 /* NAD 1983 HARN Zone Arkansas South    */
#define PE_PCS_NAD_1983_HARN_CA_I     2766 /* NAD 1983 HARN SPCS California I      */
#define PE_PCS_NAD_1983_HARN_CA_II    2767 /* NAD 1983 HARN SPCS California II     */
#define PE_PCS_NAD_1983_HARN_CA_III   2768 /* NAD 1983 HARN SPCS California III    */
#define PE_PCS_NAD_1983_HARN_CA_IV    2769 /* NAD 1983 HARN SPCS California IV     */
#define PE_PCS_NAD_1983_HARN_CA_V     2770 /* NAD 1983 HARN SPCS California V      */
#define PE_PCS_NAD_1983_HARN_CA_VI    2771 /* NAD 1983 HARN SPCS California VI     */
#define PE_PCS_NAD_1983_HARN_CO_N     2772 /* NAD 1983 HARN SPCS Colorado North    */
#define PE_PCS_NAD_1983_HARN_CO_C     2773 /* NAD 1983 HARN SPCS Colorado Central  */
#define PE_PCS_NAD_1983_HARN_CO_S     2774 /* NAD 1983 HARN SPCS Colorado South    */
#define PE_PCS_NAD_1983_HARN_CT       2775 /* NAD 1983 HARN SPCS Connecticut       */
#define PE_PCS_NAD_1983_HARN_DE       2776 /* NAD 1983 HARN SPCS Delaware          */
#define PE_PCS_NAD_1983_HARN_FL_E     2777 /* NAD 1983 HARN SPCS Florida East      */
#define PE_PCS_NAD_1983_HARN_FL_W     2778 /* NAD 1983 HARN SPCS Florida West      */
#define PE_PCS_NAD_1983_HARN_FL_N     2779 /* NAD 1983 HARN SPCS Florida North     */
#define PE_PCS_NAD_1983_HARN_GA_E     2780 /* NAD 1983 HARN SPCS Georgia East      */
#define PE_PCS_NAD_1983_HARN_GA_W     2781 /* NAD 1983 HARN SPCS Georgia West      */
#define PE_PCS_NAD_1983_HARN_HI_1     2782 /* NAD 1983 HARN SPCS Hawaii Zone 1     */
#define PE_PCS_NAD_1983_HARN_HI_2     2783 /* NAD 1983 HARN SPCS Hawaii Zone 2     */
#define PE_PCS_NAD_1983_HARN_HI_3     2784 /* NAD 1983 HARN SPCS Hawaii Zone 3     */
#define PE_PCS_NAD_1983_HARN_HI_4     2785 /* NAD 1983 HARN SPCS Hawaii Zone 4     */
#define PE_PCS_NAD_1983_HARN_HI_5     2786 /* NAD 1983 HARN SPCS Hawaii Zone 5     */
#define PE_PCS_NAD_1983_HARN_ID_E     2787 /* NAD 1983 HARN SPCS Idaho East        */
#define PE_PCS_NAD_1983_HARN_ID_C     2788 /* NAD 1983 HARN SPCS Idaho Central     */
#define PE_PCS_NAD_1983_HARN_ID_W     2789 /* NAD 1983 HARN SPCS Idaho West        */
#define PE_PCS_NAD_1983_HARN_IL_E     2790 /* NAD 1983 HARN SPCS Illinois East     */
#define PE_PCS_NAD_1983_HARN_IL_W     2791 /* NAD 1983 HARN SPCS Illinois West     */
#define PE_PCS_NAD_1983_HARN_IN_E     2792 /* NAD 1983 HARN SPCS Indiana East      */
#define PE_PCS_NAD_1983_HARN_IN_W     2793 /* NAD 1983 HARN SPCS Indiana West      */
#define PE_PCS_NAD_1983_HARN_IA_N     2794 /* NAD 1983 HARN SPCS Iowa North        */
#define PE_PCS_NAD_1983_HARN_IA_S     2795 /* NAD 1983 HARN SPCS Iowa South        */
#define PE_PCS_NAD_1983_HARN_KS_N     2796 /* NAD 1983 HARN SPCS Kansas North      */
#define PE_PCS_NAD_1983_HARN_KS_S     2797 /* NAD 1983 HARN SPCS Kansas South      */
#define PE_PCS_NAD_1983_HARN_KY_N     2798 /* NAD 1983 HARN SPCS Kentucky North    */
#define PE_PCS_NAD_1983_HARN_KY_S     2799 /* NAD 1983 HARN SPCS Kentucky South    */
#define PE_PCS_NAD_1983_HARN_LA_N     2800 /* NAD 1983 HARN SPCS Louisiana North   */
#define PE_PCS_NAD_1983_HARN_LA_S     2801 /* NAD 1983 HARN SPCS Louisiana South   */
#define PE_PCS_NAD_1983_HARN_ME_E     2802 /* NAD 1983 HARN SPCS Maine East        */
#define PE_PCS_NAD_1983_HARN_ME_W     2803 /* NAD 1983 HARN SPCS Maine West        */
#define PE_PCS_NAD_1983_HARN_MD       2804 /* NAD 1983 HARN SPCS Maryland          */
#define PE_PCS_NAD_1983_HARN_MA_M     2805 /* NAD 1983 HARN SPCS Mass. Mainland    */
#define PE_PCS_NAD_1983_HARN_MA_I     2806 /* NAD 1983 HARN SPCS Mass. Island      */
#define PE_PCS_NAD_1983_HARN_MI_N     2807 /* NAD 1983 HARN SPCS Michigan North    */
#define PE_PCS_NAD_1983_HARN_MI_C     2808 /* NAD 1983 HARN SPCS Michigan Central  */
#define PE_PCS_NAD_1983_HARN_MI_S     2809 /* NAD 1983 HARN SPCS Michigan South    */
#define PE_PCS_NAD_1983_HARN_MN_N     2810 /* NAD 1983 HARN SPCS Minnesota North   */
#define PE_PCS_NAD_1983_HARN_MN_C     2811 /* NAD 1983 HARN SPCS Minnesota Central */
#define PE_PCS_NAD_1983_HARN_MN_S     2812 /* NAD 1983 HARN SPCS Minnesota South   */
#define PE_PCS_NAD_1983_HARN_MS_E     2813 /* NAD 1983 HARN SPCS Mississippi East  */
#define PE_PCS_NAD_1983_HARN_MS_W     2814 /* NAD 1983 HARN SPCS Mississippi West  */
#define PE_PCS_NAD_1983_HARN_MO_E     2815 /* NAD 1983 HARN SPCS Missouri East     */
#define PE_PCS_NAD_1983_HARN_MO_C     2816 /* NAD 1983 HARN SPCS Missouri Central  */
#define PE_PCS_NAD_1983_HARN_MO_W     2817 /* NAD 1983 HARN SPCS Missouri West     */
#define PE_PCS_NAD_1983_HARN_MT       2818 /* NAD 1983 HARN SPCS Montana           */
#define PE_PCS_NAD_1983_HARN_NE       2819 /* NAD 1983 HARN SPCS Nebraska          */
#define PE_PCS_NAD_1983_HARN_NV_E     2820 /* NAD 1983 HARN SPCS Nevada East       */
#define PE_PCS_NAD_1983_HARN_NV_C     2821 /* NAD 1983 HARN SPCS Nevada Central    */
#define PE_PCS_NAD_1983_HARN_NV_W     2822 /* NAD 1983 HARN SPCS Nevada West       */
#define PE_PCS_NAD_1983_HARN_NH       2823 /* NAD 1983 HARN SPCS New Hampshire     */
#define PE_PCS_NAD_1983_HARN_NJ       2824 /* NAD 1983 HARN SPCS New Jersey        */
#define PE_PCS_NAD_1983_HARN_NM_E     2825 /* NAD 1983 HARN SPCS New Mexico East   */
#define PE_PCS_NAD_1983_HARN_NM_C     2826 /* NAD 1983 HARN SPCS New Mexico Cent.  */
#define PE_PCS_NAD_1983_HARN_NM_W     2827 /* NAD 1983 HARN SPCS New Mexico West   */
#define PE_PCS_NAD_1983_HARN_NY_E     2828 /* NAD 1983 HARN SPCS New York East     */
#define PE_PCS_NAD_1983_HARN_NY_C     2829 /* NAD 1983 HARN SPCS New York Central  */
#define PE_PCS_NAD_1983_HARN_NY_W     2830 /* NAD 1983 HARN SPCS New York West     */
#define PE_PCS_NAD_1983_HARN_NY_LI    2831 /* NAD 1983 HARN SPCS NY Long Island    */
#define PE_PCS_NAD_1983_HARN_ND_N     2832 /* NAD 1983 HARN SPCS North Dakota N    */
#define PE_PCS_NAD_1983_HARN_ND_S     2833 /* NAD 1983 HARN SPCS North Dakota S    */
#define PE_PCS_NAD_1983_HARN_OH_N     2834 /* NAD 1983 HARN SPCS Ohio North        */
#define PE_PCS_NAD_1983_HARN_OH_S     2835 /* NAD 1983 HARN SPCS Ohio South        */
#define PE_PCS_NAD_1983_HARN_OK_N     2836 /* NAD 1983 HARN SPCS Oklahoma North    */
#define PE_PCS_NAD_1983_HARN_OK_S     2837 /* NAD 1983 HARN SPCS Oklahoma South    */
#define PE_PCS_NAD_1983_HARN_OR_N     2838 /* NAD 1983 HARN SPCS Oregon North      */
#define PE_PCS_NAD_1983_HARN_OR_S     2839 /* NAD 1983 HARN SPCS Oregon South      */
#define PE_PCS_NAD_1983_HARN_RI       2840 /* NAD 1983 HARN SPCS Rhode Island      */
#define PE_PCS_NAD_1983_HARN_SD_N     2841 /* NAD 1983 HARN SPCS South Dakota N    */
#define PE_PCS_NAD_1983_HARN_SD_S     2842 /* NAD 1983 HARN SPCS South Dakota S    */
#define PE_PCS_NAD_1983_HARN_TN       2843 /* NAD 1983 HARN SPCS Tennessee         */
#define PE_PCS_NAD_1983_HARN_TX_N     2844 /* NAD 1983 HARN SPCS Texas North       */
#define PE_PCS_NAD_1983_HARN_TX_NC    2845 /* NAD 1983 HARN SPCS Texas North Cent. */
#define PE_PCS_NAD_1983_HARN_TX_C     2846 /* NAD 1983 HARN SPCS Texas Central     */
#define PE_PCS_NAD_1983_HARN_TX_SC    2847 /* NAD 1983 HARN SPCS Texas South Cent. */
#define PE_PCS_NAD_1983_HARN_TX_S     2848 /* NAD 1983 HARN SPCS Texas South       */
#define PE_PCS_NAD_1983_HARN_UT_N     2849 /* NAD 1983 HARN SPCS Utah North        */
#define PE_PCS_NAD_1983_HARN_UT_C     2850 /* NAD 1983 HARN SPCS Utah Central      */
#define PE_PCS_NAD_1983_HARN_UT_S     2851 /* NAD 1983 HARN SPCS Utah South        */
#define PE_PCS_NAD_1983_HARN_VT       2852 /* NAD 1983 HARN SPCS Vermont           */
#define PE_PCS_NAD_1983_HARN_VA_N     2853 /* NAD 1983 HARN SPCS Virginia North    */
#define PE_PCS_NAD_1983_HARN_VA_S     2854 /* NAD 1983 HARN SPCS Virginia South    */
#define PE_PCS_NAD_1983_HARN_WA_N     2855 /* NAD 1983 HARN SPCS Washington North  */
#define PE_PCS_NAD_1983_HARN_WA_S     2856 /* NAD 1983 HARN SPCS Washington South  */
#define PE_PCS_NAD_1983_HARN_WV_N     2857 /* NAD 1983 HARN SPCS West Virginia N   */
#define PE_PCS_NAD_1983_HARN_WV_S     2858 /* NAD 1983 HARN SPCS West Virginia S   */
#define PE_PCS_NAD_1983_HARN_WI_N     2859 /* NAD 1983 HARN SPCS Wisconsin North   */
#define PE_PCS_NAD_1983_HARN_WI_C     2860 /* NAD 1983 HARN SPCS Wisconsin Central */
#define PE_PCS_NAD_1983_HARN_WI_S     2861 /* NAD 1983 HARN SPCS Wisconsin South   */
#define PE_PCS_NAD_1983_HARN_WY_E     2862 /* NAD 1983 HARN SPCS Wyoming I East    */
#define PE_PCS_NAD_1983_HARN_WY_EC    2863 /* NAD 1983 HARN SPCS Wyoming II EC     */
#define PE_PCS_NAD_1983_HARN_WY_WC    2864 /* NAD 1983 HARN SPCS Wyoming III WC    */
#define PE_PCS_NAD_1983_HARN_WY_W     2865 /* NAD 1983 HARN SPCS Wyoming IV West   */
#define PE_PCS_NAD_1983_HARN_PR_VI    2866 /* NAD 1983 HARN SPCS PR & St. Croix    */
#define PE_PCS_NAD_1983_HARN_KY     102363 /* NAD 1983 HARN SPCS Kentucky (one zone)*/

#define PE_PCS_VOIROL_DEGREE_N_ALGERIE_ANCIENNE 102491 /* Voirol 1875 (degrees)   */
                                                       /* Nord Algerie Ancienne   */
#define PE_PCS_VOIROL_DEGREE_S_ALGERIE_ANCIENNE 102492 /* Voirol 1875 (degrees)   */
                                                       /* Sud Algerie Ancienne    */

#define PE_PCS_NTF_FRANCE_I_DEG          102581 /* NTF France I   (degrees)   */
#define PE_PCS_NTF_FRANCE_II_DEG         102582 /* NTF France II  (degrees)   */
#define PE_PCS_NTF_FRANCE_III_DEG        102583 /* NTF France III (degrees)   */
#define PE_PCS_NTF_FRANCE_IV_DEG         102584 /* NTF France IV  (degrees)   */

#define PE_PCS_VOIROL_UNIFIE_DEGREE_N_ALGERIE   102591 /* Voirol Unifie (degrees) */
                                                       /* Nord Algerie            */
#define PE_PCS_VOIROL_UNIFIE_DEGREE_S_ALGERIE   102592 /* Voirol Unifie (degrees) */
                                                       /* Sud Algerie             */

/*       NAD 1983 State Plane Coordinate System (in US Survey Feet)               */
#define PE_PCS_NAD_1983_AL_E_FT   102629 /* NAD 1983 SPCS Alabama East (Feet)     */
#define PE_PCS_NAD_1983_AL_W_FT   102630 /* NAD 1983 SPCS Alabama West (Feet)     */
#define PE_PCS_NAD_1983_AK_1_FT   102631 /* NAD 1983 SPCS Alaska 1 (Feet)         */
#define PE_PCS_NAD_1983_AK_2_FT   102632 /* NAD 1983 SPCS Alaska 2 (Feet)         */
#define PE_PCS_NAD_1983_AK_3_FT   102633 /* NAD 1983 SPCS Alaska 3 (Feet)         */
#define PE_PCS_NAD_1983_AK_4_FT   102634 /* NAD 1983 SPCS Alaska 4 (Feet)         */
#define PE_PCS_NAD_1983_AK_5_FT   102635 /* NAD 1983 SPCS Alaska 5 (Feet)         */
#define PE_PCS_NAD_1983_AK_6_FT   102636 /* NAD 1983 SPCS Alaska 6 (Feet)         */
#define PE_PCS_NAD_1983_AK_7_FT   102637 /* NAD 1983 SPCS Alaska 7 (Feet)         */
#define PE_PCS_NAD_1983_AK_8_FT   102638 /* NAD 1983 SPCS Alaska 8 (Feet)         */
#define PE_PCS_NAD_1983_AK_9_FT   102639 /* NAD 1983 SPCS Alaska 9 (Feet)         */
#define PE_PCS_NAD_1983_AK_10_FT  102640 /* NAD 1983 SPCS Alaska 10 (Feet)        */
#define PE_PCS_NAD_1983_AZ_E_FT   102648 /* NAD 1983 SPCS Arizona East (Feet)     */
#define PE_PCS_NAD_1983_AZ_C_FT   102649 /* NAD 1983 SPCS Arizona Central (Feet)  */
#define PE_PCS_NAD_1983_AZ_W_FT   102650 /* NAD 1983 SPCS Arizona West (Feet)     */
#define PE_PCS_NAD_1983_AR_N_FT   102651 /* NAD 1983 SPCS Arkansas North (Feet)   */
#define PE_PCS_NAD_1983_AR_S_FT   102652 /* NAD 1983 SPCS Arkansas South (Feet)   */
#define PE_PCS_NAD_1983_CA_I_FT     2225 /* NAD 1983 SPCS California I (Feet)     */
#define PE_PCS_NAD_1983_CA_II_FT    2226 /* NAD 1983 SPCS California II (Feet)    */
#define PE_PCS_NAD_1983_CA_III_FT   2227 /* NAD 1983 SPCS California III (Feet)   */
#define PE_PCS_NAD_1983_CA_IV_FT    2228 /* NAD 1983 SPCS California IV (Feet)    */
#define PE_PCS_NAD_1983_CA_V_FT     2229 /* NAD 1983 SPCS California V (Feet)     */
#define PE_PCS_NAD_1983_CA_VI_FT    2230 /* NAD 1983 SPCS California VI (Feet)    */
#define PE_PCS_NAD_1983_CO_N_FT     2231 /* NAD 1983 SPCS Colorado North (Feet)   */
#define PE_PCS_NAD_1983_CO_C_FT     2232 /* NAD 1983 SPCS Colorado Central (Feet) */
#define PE_PCS_NAD_1983_CO_S_FT     2233 /* NAD 1983 SPCS Colorado South (Feet)   */
#define PE_PCS_NAD_1983_CT_FT       2234 /* NAD 1983 SPCS Connecticut (Feet)      */
#define PE_PCS_NAD_1983_DE_FT       2235 /* NAD 1983 SPCS Delaware (Feet)         */
#define PE_PCS_NAD_1983_FL_E_FT     2236 /* NAD 1983 SPCS Florida East (Feet)     */
#define PE_PCS_NAD_1983_FL_W_FT     2237 /* NAD 1983 SPCS Florida West (Feet)     */
#define PE_PCS_NAD_1983_FL_N_FT     2238 /* NAD 1983 SPCS Florida North (Feet)    */
#define PE_PCS_NAD_1983_GA_E_FT     2239 /* NAD 1983 SPCS Georgia East (Feet)     */
#define PE_PCS_NAD_1983_GA_W_FT     2240 /* NAD 1983 SPCS Georgia West (Feet)     */
#define PE_PCS_NAD_1983_HI_1_FT   102661 /* NAD 1983 SPCS Hawaii Zone 1 (Feet)    */
#define PE_PCS_NAD_1983_HI_2_FT   102662 /* NAD 1983 SPCS Hawaii Zone 2 (Feet)    */
#define PE_PCS_NAD_1983_HI_3_FT   102663 /* NAD 1983 SPCS Hawaii Zone 3 (Feet)    */
#define PE_PCS_NAD_1983_HI_4_FT   102664 /* NAD 1983 SPCS Hawaii Zone 4 (Feet)    */
#define PE_PCS_NAD_1983_HI_5_FT   102665 /* NAD 1983 SPCS Hawaii Zone 5 (Feet)    */
#define PE_PCS_NAD_1983_ID_E_FT     2241 /* NAD 1983 SPCS Idaho East (Feet)       */
#define PE_PCS_NAD_1983_ID_C_FT     2242 /* NAD 1983 SPCS Idaho Central (Feet)    */
#define PE_PCS_NAD_1983_ID_W_FT     2243 /* NAD 1983 SPCS Idaho West (Feet)       */
#define PE_PCS_NAD_1983_IL_E_FT   102671 /* NAD 1983 SPCS Illinois East (Feet)    */
#define PE_PCS_NAD_1983_IL_W_FT   102672 /* NAD 1983 SPCS Illinois West (Feet)    */
#define PE_PCS_NAD_1983_IN_E_FT     2965 /* NAD 1983 SPCS Indiana East (Feet)     */
#define PE_PCS_NAD_1983_IN_W_FT     2966 /* NAD 1983 SPCS Indiana West (Feet)     */
#define PE_PCS_NAD_1983_IA_N_FT   102675 /* NAD 1983 SPCS Iowa North (Feet)       */
#define PE_PCS_NAD_1983_IA_S_FT   102676 /* NAD 1983 SPCS Iowa South (Feet)       */
#define PE_PCS_NAD_1983_KS_N_FT   102677 /* NAD 1983 SPCS Kansas North (Feet)     */
#define PE_PCS_NAD_1983_KS_S_FT   102678 /* NAD 1983 SPCS Kansas South (Feet)     */
#define PE_PCS_NAD_1983_KY_N_FT     2246 /* NAD 1983 SPCS Kentucky North (Feet)   */
#define PE_PCS_NAD_1983_KY_S_FT     2247 /* NAD 1983 SPCS Kentucky South (Feet)   */
#define PE_PCS_NAD_1983_LA_N_FT   102681 /* NAD 1983 SPCS Louisiana North (Feet)  */
#define PE_PCS_NAD_1983_LA_S_FT   102682 /* NAD 1983 SPCS Louisiana South (Feet)  */
#define PE_PCS_NAD_1983_ME_E_FT   102683 /* NAD 1983 SPCS Maine East (Feet)       */
#define PE_PCS_NAD_1983_ME_W_FT   102684 /* NAD 1983 SPCS Maine West (Feet)       */
#define PE_PCS_NAD_1983_MD_FT       2248 /* NAD 1983 SPCS Maryland (Feet)         */
#define PE_PCS_NAD_1983_MA_M_FT     2249 /* NAD 1983 SPCS Mass. Mainland (Feet)   */
#define PE_PCS_NAD_1983_MA_I_FT     2250 /* NAD 1983 SPCS Mass. Island (Feet)     */
#define PE_PCS_NAD_1983_MI_N_FT   102688 /* NAD 1983 SPCS Michigan North (Feet)   */
#define PE_PCS_NAD_1983_MI_C_FT   102689 /* NAD 1983 SPCS Michigan Central (Feet) */
#define PE_PCS_NAD_1983_MI_S_FT   102690 /* NAD 1983 SPCS Michigan South (Feet)   */
#define PE_PCS_NAD_1983_MN_N_FT   102691 /* NAD 1983 SPCS Minnesota North (Feet)  */
#define PE_PCS_NAD_1983_MN_C_FT   102692 /* NAD 1983 SPCS Minnesota Central (Feet)*/
#define PE_PCS_NAD_1983_MN_S_FT   102693 /* NAD 1983 SPCS Minnesota South (Feet)  */
#define PE_PCS_NAD_1983_MS_E_FT     2254 /* NAD 1983 SPCS Mississippi East (Feet) */
#define PE_PCS_NAD_1983_MS_W_FT     2255 /* NAD 1983 SPCS Mississippi West (Feet) */
#define PE_PCS_NAD_1983_MO_E_FT   102696 /* NAD 1983 SPCS Missouri East (Feet)    */
#define PE_PCS_NAD_1983_MO_C_FT   102697 /* NAD 1983 SPCS Missouri Central (Feet) */
#define PE_PCS_NAD_1983_MO_W_FT   102698 /* NAD 1983 SPCS Missouri West (Feet)    */
#define PE_PCS_NAD_1983_MT_FT     102700 /* NAD 1983 SPCS Montana (Feet)          */
#define PE_PCS_NAD_1983_NE_FT     102704 /* NAD 1983 SPCS Nebraska (Feet)         */
#define PE_PCS_NAD_1983_NV_E_FT   102707 /* NAD 1983 SPCS Nevada East (Feet)      */
#define PE_PCS_NAD_1983_NV_C_FT   102708 /* NAD 1983 SPCS Nevada Central (Feet)   */
#define PE_PCS_NAD_1983_NV_W_FT   102709 /* NAD 1983 SPCS Nevada West (Feet)      */
#define PE_PCS_NAD_1983_NH_FT     102710 /* NAD 1983 SPCS New Hampshire (Feet)    */
#define PE_PCS_NAD_1983_NJ_FT     102711 /* NAD 1983 SPCS New Jersey (Feet)       */
#define PE_PCS_NAD_1983_NM_E_FT     2257 /* NAD 1983 SPCS New Mexico East (Feet)  */
#define PE_PCS_NAD_1983_NM_C_FT     2258 /* NAD 1983 SPCS New Mexico Cent. (Feet) */
#define PE_PCS_NAD_1983_NM_W_FT     2259 /* NAD 1983 SPCS New Mexico West (Feet)  */
#define PE_PCS_NAD_1983_NY_E_FT     2260 /* NAD 1983 SPCS New York East (Feet)    */
#define PE_PCS_NAD_1983_NY_C_FT     2261 /* NAD 1983 SPCS New York Central (Feet) */
#define PE_PCS_NAD_1983_NY_W_FT     2262 /* NAD 1983 SPCS New York West (Feet)    */
#define PE_PCS_NAD_1983_NY_LI_FT    2263 /* NAD 1983 SPCS NY Long Island (Feet)   */
#define PE_PCS_NAD_1983_NC_FT       2264 /* NAD 1983 SPCS North Carolina (Feet)   */
#define PE_PCS_NAD_1983_ND_N_FT   102720 /* NAD 1983 SPCS North Dakota N (Feet)   */
#define PE_PCS_NAD_1983_ND_S_FT   102721 /* NAD 1983 SPCS North Dakota S (Feet)   */
#define PE_PCS_NAD_1983_OH_N_FT   102722 /* NAD 1983 SPCS Ohio North (Feet)       */
#define PE_PCS_NAD_1983_OH_S_FT   102723 /* NAD 1983 SPCS Ohio South (Feet)       */
#define PE_PCS_NAD_1983_OK_N_FT     2267 /* NAD 1983 SPCS Oklahoma North (Feet)   */
#define PE_PCS_NAD_1983_OK_S_FT     2268 /* NAD 1983 SPCS Oklahoma South (Feet)   */
#define PE_PCS_NAD_1983_OR_N_FT   102726 /* NAD 1983 SPCS Oregon North (Feet)     */
#define PE_PCS_NAD_1983_OR_S_FT   102727 /* NAD 1983 SPCS Oregon South (Feet)     */
#define PE_PCS_NAD_1983_PA_N_FT     2271 /* NAD 1983 SPCS Pennsylvania N (Feet)   */
#define PE_PCS_NAD_1983_PA_S_FT     2272 /* NAD 1983 SPCS Pennsylvania S (Feet)   */
#define PE_PCS_NAD_1983_RI_FT     102730 /* NAD 1983 SPCS Rhode Island (Feet)     */
#define PE_PCS_NAD_1983_SC_FT     102733 /* NAD 1983 SPCS South Carolina (Feet)   */
#define PE_PCS_NAD_1983_SD_N_FT   102734 /* NAD 1983 SPCS South Dakota N (Feet)   */
#define PE_PCS_NAD_1983_SD_S_FT   102735 /* NAD 1983 SPCS South Dakota S (Feet)   */
#define PE_PCS_NAD_1983_TN_FT       2274 /* NAD 1983 SPCS Tennessee (Feet)        */
#define PE_PCS_NAD_1983_TX_N_FT     2275 /* NAD 1983 SPCS Texas North (Feet)      */
#define PE_PCS_NAD_1983_TX_NC_FT    2276 /* NAD 1983 SPCS Texas North Cent. (Feet)*/
#define PE_PCS_NAD_1983_TX_C_FT     2277 /* NAD 1983 SPCS Texas Central (Feet)    */
#define PE_PCS_NAD_1983_TX_SC_FT    2278 /* NAD 1983 SPCS Texas South Cent. (Feet)*/
#define PE_PCS_NAD_1983_TX_S_FT     2279 /* NAD 1983 SPCS Texas South (Feet)      */
#define PE_PCS_NAD_1983_UT_N_FT   102742 /* NAD 1983 SPCS Utah North (Feet)       */
#define PE_PCS_NAD_1983_UT_C_FT   102743 /* NAD 1983 SPCS Utah Central (Feet)     */
#define PE_PCS_NAD_1983_UT_S_FT   102744 /* NAD 1983 SPCS Utah South (Feet)       */
#define PE_PCS_NAD_1983_VT_FT     102745 /* NAD 1983 SPCS Vermont (Feet)          */
#define PE_PCS_NAD_1983_VA_N_FT     2283 /* NAD 1983 SPCS Virginia North (Feet)   */
#define PE_PCS_NAD_1983_VA_S_FT     2284 /* NAD 1983 SPCS Virginia South (Feet)   */
#define PE_PCS_NAD_1983_WA_N_FT     2285 /* NAD 1983 SPCS Washington North (Feet) */
#define PE_PCS_NAD_1983_WA_S_FT     2286 /* NAD 1983 SPCS Washington South (Feet) */
#define PE_PCS_NAD_1983_WV_N_FT   102750 /* NAD 1983 SPCS West Virginia N (Feet)  */
#define PE_PCS_NAD_1983_WV_S_FT   102751 /* NAD 1983 SPCS West Virginia S (Feet)  */
#define PE_PCS_NAD_1983_WI_N_FT     2287 /* NAD 1983 SPCS Wisconsin North (Feet)  */
#define PE_PCS_NAD_1983_WI_C_FT     2288 /* NAD 1983 SPCS Wisconsin Central (Feet)*/
#define PE_PCS_NAD_1983_WI_S_FT     2289 /* NAD 1983 SPCS Wisconsin South (Feet)  */
#define PE_PCS_NAD_1983_WY_E_FT   102755 /* NAD 1983 SPCS Wyoming I East (Feet)   */
#define PE_PCS_NAD_1983_WY_EC_FT  102756 /* NAD 1983 SPCS Wyoming II EC (Feet)    */
#define PE_PCS_NAD_1983_WY_WC_FT  102757 /* NAD 1983 SPCS Wyoming III WC (Feet)   */
#define PE_PCS_NAD_1983_WY_W_FT   102758 /* NAD 1983 SPCS Wyoming IV West (Feet)  */
#define PE_PCS_NAD_1983_PR_VI_FT  102761 /* NAD 1983 SPCS PR & St. Croix (Feet)   */
#define PE_PCS_NAD_1983_GU_FT     102766 /* NAD 1983 SPCS Guam (Feet)             */
#define PE_PCS_NAD_1983_KY_FT     102763 /* NAD 1983 SPCS Kentucky (Feet) (one zone)*/


/*----------------------------------------------------------------------------*/
/*          P R O J E C T E D   C O O R D I N A T E   S Y S T E M S           */
/*                           (W O R L D   W I D E)                            */
/*----------------------------------------------------------------------------*/
#define PE_PCS_WORLD_PLATE_CARREE            54001 /* Plate Carree            */
#define PE_PCS_WORLD_EQUIDISTANT_CYLINDRICAL 54002 /* Equidistant Cyl.        */
#define PE_PCS_WORLD_MILLER_CYLINDRICAL      54003 /* Miller Cylindrical      */
#define PE_PCS_WORLD_MERCATOR                54004 /* Mercator                */
#define PE_PCS_WORLD_SINUSOIDAL              54008 /* Sinusoidal              */
#define PE_PCS_WORLD_MOLLWEIDE               54009 /* Mollweide               */
#define PE_PCS_WORLD_ECKERT_VI               54010 /* Eckert VI               */
#define PE_PCS_WORLD_ECKERT_V                54011 /* Eckert V                */
#define PE_PCS_WORLD_ECKERT_IV               54012 /* Eckert IV               */
#define PE_PCS_WORLD_ECKERT_III              54013 /* Eckert III              */
#define PE_PCS_WORLD_ECKERT_II               54014 /* Eckert II               */
#define PE_PCS_WORLD_ECKERT_I                54015 /* Eckert I                */
#define PE_PCS_WORLD_GALL_STEREOGRAPHIC      54016 /* Gall Stereographic      */
#define PE_PCS_WORLD_BEHRMANN                54017 /* Behrmann                */
#define PE_PCS_WORLD_WINKEL_I                54018 /* Winkel I                */
#define PE_PCS_WORLD_WINKEL_II               54019 /* Winkel II               */
#define PE_PCS_WORLD_POLYCONIC               54021 /* Polyconic               */
#define PE_PCS_WORLD_QUARTIC_AUTHALIC        54022 /* Quartic Authalic        */
#define PE_PCS_WORLD_LOXIMUTHAL              54023 /* Loximuthal              */
#define PE_PCS_WORLD_BONNE                   54024 /* Bonne                   */
#define PE_PCS_WORLD_HOTINE                  54025 /* Hotine                  */
#define PE_PCS_WORLD_STEREOGRAPHIC           54026 /* Stereographic           */
#define PE_PCS_WORLD_EQUIDISTANT_CONIC       54027 /* Equidistant Conic       */
#define PE_PCS_WORLD_CASSINI                 54028 /* Cassini                 */
#define PE_PCS_WORLD_VAN_DER_GRINTEN_I       54029 /* Van der Grinten I       */
#define PE_PCS_WORLD_ROBINSON                54030 /* Robinson                */
#define PE_PCS_WORLD_TWO_POINT_EQUIDISTANT   54031 /* Two-Point Equidistant   */
#define PE_PCS_WORLD_AZIMUTHAL_EQUIDISTANT   54032 /* Azimuthal Equidistant   */
#define PE_PCS_WORLD_CYLINDRICAL_EQAREA      54034 /* Cylindrical Equal Area  */
#define PE_PCS_WORLD_WINKEL_TRIPEL_NGS       54042 /* Winkel Tripel (NGS version) */
#define PE_PCS_WORLD_AITOFF                  54043 /* Aitoff                  */
#define PE_PCS_WORLD_HAMMER_AITOFF           54044 /* Hammer-Aitoff           */
#define PE_PCS_WORLD_FLAT_POLAR_QUARTIC      54045 /* Flat Polar Quartic      */
#define PE_PCS_WORLD_CRASTER_PARABOLIC       54046 /* Craster Parabolic       */
#define PE_PCS_WORLD_TIMES                   54048 /* Times                   */
#define PE_PCS_WORLD_VERTICAL_PERSPECTIVE    54049 /* Vertical Near-Side Perspective */
                                                   /* (Geosynchronous Orbit)  */

/*----------------------------------------------------------------------------*/
/*          P R O J E C T E D   C O O R D I N A T E   S Y S T E M S           */
/*                          (S P H E R E   O N L Y)                           */
/*----------------------------------------------------------------------------*/
#define PE_PCS_SPHERE_PLATE_CARREE            53001 /* Plate Carree           */
#define PE_PCS_SPHERE_EQUIDISTANT_CYLINDRICAL 53002 /* Equidistant Cyl.       */
#define PE_PCS_SPHERE_MILLER_CYLINDRICAL      53003 /* Miller Cylindrical     */
#define PE_PCS_SPHERE_MERCATOR                53004 /* Mercator               */
#define PE_PCS_SPHERE_SINUSOIDAL              53008 /* Sinusoidal             */
#define PE_PCS_SPHERE_MOLLWEIDE               53009 /* Mollweide              */
#define PE_PCS_SPHERE_ECKERT_VI               53010 /* Eckert VI              */
#define PE_PCS_SPHERE_ECKERT_V                53011 /* Eckert V               */
#define PE_PCS_SPHERE_ECKERT_IV               53012 /* Eckert IV              */
#define PE_PCS_SPHERE_ECKERT_III              53013 /* Eckert III             */
#define PE_PCS_SPHERE_ECKERT_II               53014 /* Eckert II              */
#define PE_PCS_SPHERE_ECKERT_I                53015 /* Eckert I               */
#define PE_PCS_SPHERE_GALL_STEREOGRAPHIC      53016 /* Gall Stereographic     */
#define PE_PCS_SPHERE_BEHRMANN                53017 /* Behrmann               */
#define PE_PCS_SPHERE_WINKEL_I                53018 /* Winkel I               */
#define PE_PCS_SPHERE_WINKEL_II               53019 /* Winkel II              */
#define PE_PCS_SPHERE_POLYCONIC               53021 /* Polyconic              */
#define PE_PCS_SPHERE_QUARTIC_AUTHALIC        53022 /* Quartic Authalic       */
#define PE_PCS_SPHERE_LOXIMUTHAL              53023 /* Loximuthal             */
#define PE_PCS_SPHERE_BONNE                   53024 /* Bonne                  */
#define PE_PCS_SPHERE_HOTINE                  53025 /* Hotine                 */
#define PE_PCS_SPHERE_STEREOGRAPHIC           53026 /* Stereographic          */
#define PE_PCS_SPHERE_EQUIDISTANT_CONIC       53027 /* Equidistant Conic      */
#define PE_PCS_SPHERE_CASSINI                 53028 /* Cassini                */
#define PE_PCS_SPHERE_VAN_DER_GRINTEN_I       53029 /* Van der Grinten I      */
#define PE_PCS_SPHERE_ROBINSON                53030 /* Robinson               */
#define PE_PCS_SPHERE_TWO_POINT_EQUIDISTANT   53031 /* Two-Point Equidistant  */
#define PE_PCS_SPHERE_AZIMUTHAL_EQUIDISTANT   53032 /* Azimuthal Equidistant  */
#define PE_PCS_SPHERE_CYLINDRICAL_EQAREA      53034 /* Cylindrical Equal Area */
#define PE_PCS_SPHERE_WINKEL_TRIPEL_NGS       53042 /* Winkel Tripel (NGS version) */
#define PE_PCS_SPHERE_AITOFF                  53043 /* Aitoff                 */
#define PE_PCS_SPHERE_HAMMER_AITOFF           53044 /* Hammer-Aitoff          */
#define PE_PCS_SPHERE_FLAT_POLAR_QUARTIC      53045 /* Flat Polar Quartic     */
#define PE_PCS_SPHERE_CRASTER_PARABOLIC       53046 /* Craster Parabolic      */
#define PE_PCS_SPHERE_TIMES                   53048 /* Times                  */
#define PE_PCS_SPHERE_VERTICAL_PERSPECTIVE    53049 /* Vertical Near-Side Perspective */
                                                    /* (Geosynchronous Orbit) */

/*----------------------------------------------------------------------------*/
/*                               M E T H O D S                                */
/*----------------------------------------------------------------------------*/
#define PE_MTH_LONGITUDE_ROTATION      9601 /* Longitude Rotation             */
#define PE_MTH_GEOCENTRIC_TRANSLATION  9603 /* Geocentric Translation (3-par.)*/
#define PE_MTH_MOLODENSKY              9604 /* Molodensky                     */
#define PE_MTH_MOLODENSKY_ABRIDGED     9605 /* Abridged Molodensky            */
#define PE_MTH_POSITION_VECTOR         9606 /* Position Vector (7-par.)       */
#define PE_MTH_COORDINATE_FRAME        9607 /* Coordinate Frame (7-par.)      */
#define PE_MTH_BURSA_WOLF            109607 /* Bursa-Wolf                     */
#define PE_MTH_NADCON                  9613 /* NADCON                         */
#define PE_MTH_NTV2                    9615 /* NTv2                           */
#define PE_MTH_HARN                  109613 /* HARN (HPGN)                    */
#define PE_MTH_MOLODENSKY_BADEKAS      9636 /* Molodensky-Badekas             */

/*----------------------------------------------------------------------------*/
/*            G E O G R A P H I C   T R A N S F O R M A T I O N S             */
/*----------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------- */
/*                  Transforms by Geocentric Translation,                     */
/*                  Coordinate Frame, Position Vector and                     */
/*                       Molodensky-Badekas Methods                           */
/* -------------------------------------------------------------------------- */


/* NEW GT's at 9.0 (Geocen Trans, Coord Frame, Pos Vector, MB) ----- */
/* (Geocentric Translation, Coordinate Frame, Position Vector, Molodenksy-Badekas) */

#define PE_GT_AGD_1966_TO_WGS_1984_12       1665 /* Australia - ACT           */
#define PE_GT_AGD_1966_TO_WGS_1984_13       1666 /* Australia - NSW & Victoria*/
#define PE_GT_AGD_1966_TO_WGS_1984_14       1667 /* Australia - Tasmania      */
#define PE_GT_AGD_1966_TO_WGS_1984_15       1668 /* Australia - Northern Territory */
#define PE_GT_AGD_1984_TO_WGS_1984_7        1669 /* Australia                 */
#define PE_GT_AMERSFOORT_TO_WGS_1984_2      1672 /* Netherlands               */
#define PE_GT_AMMASSALIK_1958_TO_WGS_1984_1 1800 /* Greenland - Ammassalik area */
#define PE_GT_AUSTRALIAN_ANTARCTIC_1998_TO_WGS_1984_1  1890 /* Antarctica     */
#define PE_GT_AZORES_CENTRAL_1948_TO_WGS_1984_1    1886 /* Portugal - Graciosa, */
                                                        /* Terceira, Sao Jorge, */
                                                        /* Pico, Faial          */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_10   1980 /* Azores - Faial, Graciosa, */
                                                        /* Pico, Sao Jorge, and */
                                                        /* Terceira islands     */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_11   1981 /* Azores - Faial, Graciosa, */
                                                        /* Pico, Sao Jorge, and */
                                                        /* Terceira islands     */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_2    1972 /* Azores - central, Terceira island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_3    1973 /* Azores - central, Terceira island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_4    1974 /* Azores - central, Faial island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_5    1975 /* Azores - central, Terceira island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_6    1976 /* Azores - central, Pico island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_7    1977 /* Azores - central, Pico island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_8    1978 /* Azores - central, Sao Jorge island */
#define PE_GT_AZORES_CENTRAL_1995_TO_WGS_1984_9    1979 /* Azores - central, Sao Jorge island */
#define PE_GT_AZORES_OCCIDENTAL_1939_TO_WGS_1984_1 1887 /* Portugal - Flores, Corvo */
#define PE_GT_AZORES_OCCIDENTAL_1939_TO_WGS_1984_2 1982 /* Azores - Flores, Corvo islands */
#define PE_GT_AZORES_ORIENTAL_1940_TO_WGS_1984_1   1885 /* Portugal - Sao Miguel*/
                                                        /*  and Santa Maria     */
#define PE_GT_AZORES_ORIENTAL_1995_TO_WGS_1984_2   1968 /* Azores - Sao Miguel island */
#define PE_GT_AZORES_ORIENTAL_1995_TO_WGS_1984_3   1969 /* Azores - Sao Miguel island */
#define PE_GT_AZORES_ORIENTAL_1995_TO_WGS_1984_4   1970 /* Azores - Santa Maria and Sao Miguel islands */
#define PE_GT_AZORES_ORIENTAL_1995_TO_WGS_1984_5   1971 /* Azores - Santa Maria and Sao Miguel islands */
#define PE_GT_BATAVIA_TO_WGS_1984_2         1813 /* Indonesia - Java Sea -    */
                                                 /*  offshore northwest Java  */
#define PE_GT_BATAVIA_TO_WGS_1984_3         1814 /* Indonesia - eastern Java Sea */
#define PE_GT_BEDUARAM_TO_WGS_1972_BE_1     1839 /* Nigeria - southeast       */
#define PE_GT_BELGE_1972_TO_ETRS_1989_1     1652 /* Belgium                   */
#define PE_GT_CH1903_PLUS_TO_ETRS_1989_1    1647 /* Switzerland               */
#define PE_GT_CH1903_PLUS_TO_WGS_1984_1     1676 /* Switzerland               */
#define PE_GT_CH1903_TO_ETRS_1989_1         1646 /* Switzerland               */
#define PE_GT_COMBANI_1950_TO_WGS_1984_1    1916 /* Mayotte                   */
#define PE_GT_CSG_1967_TO_RGFG_1995_1       1908 /* French Guiana             */
#define PE_GT_CSG_1967_TO_WGS_1984_1        1906 /* French Guiana             */
#define PE_GT_DATUM_73_TO_ETRS_1989_1       1657 /* Portugal                  */
#define PE_GT_DATUM_73_TO_ETRS_1989_3       1992 /* Portugal                  */
#define PE_GT_DATUM_73_TO_WGS_1984_3        1983 /* Portugal                  */
#define PE_GT_DATUM_73_TO_WGS_1984_4        1987 /* Portugal                  */
#define PE_GT_DEALUL_PISCULUI_1933_TO_WGS_1984_1  1995 /* Romania             */
#define PE_GT_DEALUL_PISCULUI_1970_TO_WGS_1984_1  1996 /* Romania             */
#define PE_GT_DEALUL_PISCULUI_1970_TO_WGS_1984_2  1097 /* Romania             */
#define PE_GT_DHDN_TO_ETRS_1989_2           1776 /* Germany - West            */
#define PE_GT_DHDN_TO_ETRS_1989_3           1778 /* Germany - S of 50 20 N    */
#define PE_GT_DHDN_TO_ETRS_1989_4           1779 /* Germany - between 50 20 N and 52 20 N */
#define PE_GT_DHDN_TO_ETRS_1989_5           1780 /* Germany - N of 52 20 N    */
#define PE_GT_DHDN_TO_ETRS_1989_6           1781 /* Germany - Thuringen       */
#define PE_GT_DHDN_TO_ETRS_1989_7           1782 /* Germany - Sachsen         */
#define PE_GT_DHDN_TO_WGS_1984_1            1673 /* Germany - West            */
#define PE_GT_DHDN_TO_WGS_1984_2            1777 /* Germany - West            */
#define PE_GT_ED_1950_ED77_TO_WGS_1984_3    1856 /* Iran - South Pars field blocks 2 & 3 */
#define PE_GT_ED_1950_ED77_TO_WGS_1984_4    1857 /* Iran - Lavan Island & Balal field */
#define PE_GT_ED_1950_ED77_TO_WGS_1984_5    1858 /* Iran - Kharg Island       */
#define PE_GT_ED_1950_TO_ETRS_1989_10       1650 /* France                    */
#define PE_GT_ED_1950_TO_ETRS_1989_4        1626 /* Denmark                   */
#define PE_GT_ED_1950_TO_ETRS_1989_5        1628 /* Gibraltar                 */
#define PE_GT_ED_1950_TO_ETRS_1989_6        1630 /* Spain - Balearic Islands  */
#define PE_GT_ED_1950_TO_ETRS_1989_7        1632 /* Spain - mainland except   */
                                                 /* NW (N of 41.5N, W of 4.5W)*/
#define PE_GT_ED_1950_TO_ETRS_1989_8        1634 /* Spain - Northwest         */
                                                 /* (N of 41.5N, W of 4.5W)   */
#define PE_GT_ED_1950_TO_ETRS_1989_9        1783 /* Turkey                    */
#define PE_GT_ED_1950_TO_WGS_1984_25        1627 /* Denmark                   */
#define PE_GT_ED_1950_TO_WGS_1984_26        1629 /* Gibraltar                 */
#define PE_GT_ED_1950_TO_WGS_1984_27        1631 /* Spain - Balearic Islands  */
#define PE_GT_ED_1950_TO_WGS_1984_28        1633 /* Spain - mainland except   */
                                                 /* NW (N of 41.5N, W of 4.5W)*/
#define PE_GT_ED_1950_TO_WGS_1984_29        1635 /* Spain - Northwest         */
                                                 /* (N of 41.5N, W of 4.5W)   */
#define PE_GT_ED_1950_TO_WGS_1984_30        1784 /* Turkey                    */
#define PE_GT_ED_1950_TO_WGS_1984_31        1810 /* Egypt - western desert    */
#define PE_GT_ED_1950_TO_WGS_1984_32        1999 /* Netherlands - offshore, North Sea */
#define PE_GT_ED_1950_TO_WGS_1984_33        1985 /* Portugal                  */
#define PE_GT_ED_1950_TO_WGS_1984_34        1989 /* Portugal                  */
#define PE_GT_ED_1950_TO_WGS_1984_36        1998 /* Germany - offshore, North Sea */
#define PE_GT_ED_1987_TO_WGS_1984_2         1960 /* Europe - west             */
#define PE_GT_ELD_1979_TO_WGS_1984_1        1859 /* Libya - Murzuq field      */
#define PE_GT_ELD_1979_TO_WGS_1984_2        1860 /* Libya - Murzuq field      */
#define PE_GT_ELD_1979_TO_WGS_1984_3        1861 /* Libya - Mabruk field      */
#define PE_GT_ELD_1979_TO_WGS_1984_4        1862 /* Libya - Mabruk field      */
#define PE_GT_ELD_1979_TO_WGS_1984_5        1863 /* Libya - Mabruk field      */
#define PE_GT_ESTONIA_1997_TO_ETRS_1989_1   1648 /* Estonia                   */
#define PE_GT_ESTONIA_1997_TO_WGS_1984_1    1649 /* Estonia                   */
#define PE_GT_FD_1958_TO_WGS_1984_2         1854 /* Lavan Island & Balal field*/
#define PE_GT_FD_1958_TO_WGS_1984_3         1855 /* Kharg Island              */
#define PE_GT_FORT_DESAIX_TO_WGS_1984_1     1909 /* Martinique                */
#define PE_GT_FORT_DESAIX_TO_WGS_1984_2     1910 /* Martinique                */
#define PE_GT_FORT_MARIGOT_TO_WGS_1984_1    1903 /* Guadeloupe - St. Martin & */
                                                 /* St. Barthelemy islands    */
#define PE_GT_GANDAJIKA_1970_TO_WGS_1984_1  1894 /* Maldives                  */
#define PE_GT_GAROUA_TO_WGS_1972_BE_1       1805 /* Cameroon - Garoua area    */
#define PE_GT_GUNUNG_SEGARA_TO_WGS_1984_1   1897 /* Indonesia - Kalimantan    */
#define PE_GT_GUNUNG_SEGARA_TO_WGS_1984_2   1898 /* Indonesia - east Kalimantan */
#define PE_GT_GUNUNG_SEGARA_TO_WGS_1984_3   1899 /* Indonesia - northeast Kalimantan */
#define PE_GT_GUNUNG_SEGARA_TO_WGS_1984_4   1838 /* Indonesia - east Kalimantan */
                                                 /*   - Mahakam delta area    */
#define PE_GT_HELLE_1954_TO_WGS_1984_1      1957 /* Jan Mayen (Norway)        */
#define PE_GT_HITO_XVIII_1963_TO_WGS_1984_2 1892 /* Chile - Tierra del Fuego  */
#define PE_GT_HONG_KONG_1980_TO_WGS_1984_1  1825  /* China - Hong Kong        */
#define PE_GT_HUNGARIAN_1972_TO_WGS_1984_1  1830 /* Hungary                   */
#define PE_GT_HUNGARIAN_1972_TO_WGS_1984_2  1831 /* Hungary                   */
#define PE_GT_IGM_1995_TO_ETRS_1989_1       1098 /* Italy                     */
#define PE_GT_IGM_1995_TO_WGS_1984_1        1099 /* Italy                     */
#define PE_GT_IGN53_MARE_TO_WGS_1984_1      1928 /* New Caledonia - Mare      */
#define PE_GT_IGN56_LIFOU_TO_WGS_1984_1     1917 /* New Caledonia - Lifou     */
#define PE_GT_IGN56_LIFOU_TO_WGS_1984_2     1927 /* New Caledonia - Lifou     */
#define PE_GT_IGN72_GRANDE_TERRE_TO_WGS_1984_1  1962 /* New Caledonia - Grande Terre */
#define PE_GT_IGN72_GRANDE_TERRE_TO_WGS_1984_2  1963 /* New Caledonia - Grande Terre */
#define PE_GT_IGN72_NUKU_HIVA_TO_WGS_1984_1 1914 /* French Polynesia -        */
                                                 /* Marquises - Nuku Hiva     */
#define PE_GT_IKBD_1992_TO_WGS_1984_1       1993 /* Iraq-Kuwait Boundary      */
#define PE_GT_INDIAN_1975_TO_WGS_1984_4     1812 /* Thailand                  */
#define PE_GT_INDONESIAN_1974_TO_WGS_1984_2 1832 /* Indonesia                 */
#define PE_GT_INDONESIAN_1974_TO_WGS_1984_3 1833 /* Indonesia                 */
#define PE_GT_IRENET95_TO_WGS_1984_1        1678 /* Ireland                   */
#define PE_GT_ISN_1993_TO_WGS_1984_1        1952 /* Iceland                   */
#define PE_GT_ITRF_1988_TO_ITRF_2000_1      1943 /* World                     */
#define PE_GT_ITRF_1989_TO_ITRF_2000_1      1942 /* World                     */
#define PE_GT_ITRF_1990_TO_ITRF_2000_1      1941 /* World                     */
#define PE_GT_ITRF_1991_TO_ITRF_2000_1      1940 /* World                     */
#define PE_GT_ITRF_1992_TO_ITRF_2000_1      1939 /* World                     */
#define PE_GT_ITRF_1993_TO_ITRF_2000_1      1938 /* World                     */
#define PE_GT_ITRF_1994_TO_ITRF_2000_1      1937 /* World                     */
#define PE_GT_ITRF_1996_TO_ITRF_2000_1      1936 /* World                     */
#define PE_GT_ITRF_1997_TO_ITRF_2000_1      1935 /* World                     */
#define PE_GT_JGD_2000_TO_WGS_1984_1        1826 /* Japan                     */
#define PE_GT_K0_1949_TO_WGS_1984_1         1915 /* Kerguelen Island          */
#define PE_GT_KKJ_TO_ETRS_1989_1            1638 /* Finland                   */
#define PE_GT_KKJ_TO_WGS_1984_1             1639 /* Finland                   */
#define PE_GT_KOUSSERI_TO_WGS_1972_BE_1     1806 /* Cameroon - N'Djamena area */
#define PE_GT_LA_CANOA_TO_REGVEN_1          1771 /* Venezuela                 */
#define PE_GT_LA_CANOA_TO_WGS_1984_2        1096 /* Venezuela                 */
#define PE_GT_LISBON_1890_TO_WGS_1984_1     1986 /* Portugal                  */
#define PE_GT_LISBON_1890_TO_WGS_1984_2     1990 /* Portugal                  */
#define PE_GT_LISBON_TO_ETRS_1989_1         1655 /* Portugal                  */
#define PE_GT_LISBON_TO_ETRS_1989_2         1997 /* Portugal                  */
#define PE_GT_LISBON_TO_WGS_1984_2          1944 /* Portugal - onshore        */
#define PE_GT_LISBON_TO_WGS_1984_3          1984 /* Portugal                  */
#define PE_GT_LISBON_TO_WGS_1984_4          1988 /* Portugal                  */
#define PE_GT_LKS_1992_TO_WGS_1984_1        1958 /* Latvia                    */
#define PE_GT_LUXEMBOURG_1930_TO_ETRS_1989_1  1642 /* Luxembourg              */
#define PE_GT_LUXEMBOURG_1930_TO_WGS_1984_1   1643 /* Luxembourg              */
#define PE_GT_MAKASSAR_TO_WGS_1984_1        1837 /* Indonesia - southwest Sulawesi */
#define PE_GT_MANOCA_1962_TO_WGS_1972_BE_1  1902 /* Cameroon                  */
#define PE_GT_MANOCA_1962_TO_WGS_1984_1     1796 /* Cameroon - coastal area   */
#define PE_GT_MGI_TO_ETRS_1989_1            1619 /* Austria                   */
#define PE_GT_MGI_TO_ETRS_1989_2            1620 /* Croatia                   */
#define PE_GT_MGI_TO_ETRS_1989_3            1785 /* Slovenia                  */
#define PE_GT_MGI_TO_WGS_1984_4             1621 /* Croatia                   */
#define PE_GT_MGI_TO_WGS_1984_5             1786 /* Bosnia & Herzegovina,     */
                                                 /* Croatia, Serbia, Slovenia */
#define PE_GT_MGI_TO_WGS_1984_6             1794 /* Austria                   */
#define PE_GT_MGI_TO_WGS_1984_7             1795 /* Yugoslavia - Montenegro   */
#define PE_GT_MINNA_TO_WGS_1984_10          1824 /* Nigeria - south           */
#define PE_GT_MINNA_TO_WGS_1984_4           1818 /* Nigeria - offshore beyond continental shelf */
#define PE_GT_MINNA_TO_WGS_1984_6           1820 /* Nigeria - offshore beyond continental shelf */
#define PE_GT_MINNA_TO_WGS_1984_7           1821 /* Nigeria - offshore beyond continental shelf */
#define PE_GT_MINNA_TO_WGS_1984_8           1822 /* Nigeria - offshore beyond continental shelf */
#define PE_GT_MINNA_TO_WGS_1984_9           1823 /* Nigeria - offshore beyond continental shelf */
#define PE_GT_MONTE_MARIO_TO_ETRS_1989_1    1659 /* Italy - mainland          */
#define PE_GT_MONTE_MARIO_TO_ETRS_1989_2    1661 /* Italy - Sardinia          */
#define PE_GT_MONTE_MARIO_TO_ETRS_1989_3    1663 /* Italy - Sicily            */
#define PE_GT_MONTE_MARIO_TO_WGS_1984_2     1662 /* Italy - Sardinia          */
#define PE_GT_MONTE_MARIO_TO_WGS_1984_3     1664 /* Italy - Sicily            */
#define PE_GT_MONTE_MARIO_TO_WGS_1984_4     1660 /* Italy - mainland          */
#define PE_GT_MOP78_TO_WGS_1984_1           1925 /* Wallis and Futuna - Wallis*/
#define PE_GT_NAD_1983_CSRS98_TO_WGS_1984_1 1842 /* Canada                    */
#define PE_GT_NAD_1983_CSRS98_TO_WGS_1984_2 1946 /* Canada                    */
#define PE_GT_NAD_1983_HARN_TO_WGS_1984_2   1900 /* Contiguous United States  */
#define PE_GT_NAD_1983_HARN_TO_WGS_1984_3   1901 /* Contiguous United States  */
#define PE_GT_NAD_1983_TO_NAD_1983_CSRS98_4 1950 /* Canada - Newfoundland,    */
                                                 /* New Brunswick, & Nova     */
                                                 /* Scotia offshore           */
#define PE_GT_NEA74_NOUMEA_TO_WGS_1984_1    1932 /* New Caledonia - Noumea    */
                                                 /*  district on Grande Terre */
#define PE_GT_NGO_1948_TO_ETRS_1989_1       1653 /* Norway - onshore          */
#define PE_GT_NORD_SAHARA_1959_TO_WGS_1984_4  1815 /* Algeria - District 3 (In Salah) */
#define PE_GT_NORD_SAHARA_1959_TO_WGS_1984_5  1816 /* Algeria - In Amenas block */
#define PE_GT_NORD_SAHARA_1959_TO_WGS_1984_6  1817 /* Algeria - Hassi Bir Reikaz */
#define PE_GT_NTF_TO_ETRS_1989_1            1651 /* France                    */
#define PE_GT_OSNI_1952_TO_WGS_1984_1       1955 /* Ireland, Northern Ireland */
#define PE_GT_PETRELS_1972_TO_WGS_1984_1    1921 /* Antarctica - Terre Adelie */
#define PE_GT_PITON_DES_NEIGES_TO_RGR_1992_1  1926 /* Reunion                 */
#define PE_GT_PITON_DES_NEIGES_TO_WGS_1984_1  1911 /* Reunion                 */
#define PE_GT_POINT58_TO_WGS_1984_1         1880 /* Burkina Faso - central,   */
                                                 /* Niger - SW, near 12N      */
#define PE_GT_POINTE_GEOLOGIE_PERROUD_1950_TO_WGS_1984_1 1922 /* Antarctica - */
                                                              /* Terre Adelie */
#define PE_GT_POINTE_NOIRE_TO_WGS_1984_2    1801 /* Congo - coastal area & offshore */
#define PE_GT_POINTE_NOIRE_TO_WGS_1984_3    1802 /* Congo - coastal area and offshore */
#define PE_GT_PORTO_SANTO_1995_TO_WGS_1984_2 1966 /* Madeira and Porto Santo islands */
#define PE_GT_PORTO_SANTO_1995_TO_WGS_1984_3 1967 /* Madeira and Porto Santo islands */
#define PE_GT_POSGAR_1998_TO_SIRGAS_1       1774 /* Argentina                 */
#define PE_GT_POSGAR_1998_TO_WGS_1984_1     1773 /* Argentina                 */
#define PE_GT_PSAD_1956_TO_REGVEN_1         1769 /* Venezuela                 */
#define PE_GT_PSAD_1956_TO_WGS_1984_12      1811 /* Brazil - offshore Amazon cone */
#define PE_GT_PSAD_1956_TO_WGS_1984_13      1095 /* Venezuela                 */
#define PE_GT_PUERTO_RICO_TO_WGS_1984_3     1893 /* Puerto Rico and Virgin Islands */
#define PE_GT_PULKOVO_1942_ADJ_1958_TO_ETRS_1989_1 1644 /* Poland             */
#define PE_GT_PULKOVO_1942_ADJ_1958_TO_WGS_1984_1  1645 /* Poland             */
#define PE_GT_PULKOVO_1942_ADJ_1983_TO_ETRS_1989_1 1674 /* Germany - Brandenburg,  */
                                                        /* Mecklenburg-Vorpommern, */
                                                        /* Sachsen, Sachsen-Anhalt,*/
                                                        /* Thuringen               */
#define PE_GT_PULKOVO_1942_ADJ_1983_TO_ETRS_1989_2 1775 /* Germany - Brandenburg,  */
                                                        /* Mecklenburg-Vorpommern, */
                                                        /* Sachsen, Sachsen-Anhalt,*/
                                                        /* Thuringen               */
#define PE_GT_PULKOVO_1942_ADJ_1983_TO_WGS_1984_1  1675 /* Germany - Brandenburg,  */
                                                        /* Mecklenburg-Vorpommern, */
                                                        /* Sachsen, Sachsen-Anhalt,*/
                                                        /* Thuringen               */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_13   1807 /* Azerbaijan                */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_14   1808 /* Azerbaijan and Georgia    */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_15   1809 /* Azerbaijan - coastal area */
                                                 /* Baku to Astara            */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_2    1679 /* Lithuania                 */
#define PE_GT_QND_1995_TO_WGS_1984_1        1840 /* Qatar                     */
#define PE_GT_QORNOQ_1927_TO_WGS_1984_1     1797 /* Greenland - south         */
#define PE_GT_QORNOQ_1927_TO_WGS_1984_2     1798 /* Greenland                 */
#define PE_GT_REGVEN_TO_WGS_1984_1          1768 /* Venezuela                 */
#define PE_GT_REYKJAVIK_1900_TO_WGS_1984_1  1994 /* Iceland                   */
#define PE_GT_RGFG_1995_TO_WGS_1984_1       1907 /* French Guiana             */
#define PE_GT_RGF_1993_TO_WGS_1984_1        1671 /* France                    */
#define PE_GT_RGNC_1991_TO_WGS_1984_1       1920 /* New Caledonia             */
#define PE_GT_RGR_1992_TO_PITON_DES_NEIGES_1  1964 /* Reunion                 */
#define PE_GT_RGR_1992_TO_WGS_1984_1        1912 /* Reunion                   */
#define PE_GT_RRAF_1991_TO_WGS_1984_1       1934 /* Antilles - Guadeloupe and Martinique */
#define PE_GT_RT90_TO_ETRS_1989_2           1787 /* Sweden                    */
#define PE_GT_RT90_TO_WGS_1984_2            1896 /* Sweden                    */
#define PE_GT_SAINTE_ANNE_TO_WGS_1984_1     1904 /* Guadeloupe - Basse-Terre, */
                                                 /* Grande-Terre, Desiride,   */
                                                 /* Marie-Galante, Les Saintes*/
#define PE_GT_SAINTE_ANNE_TO_WGS_1984_2     1905 /* Gaudeloupe - Basse-Terre, */
                                                 /* Grande-Terre, Desiride,   */
                                                 /* Marie-Galante, Les Saintes*/
#define PE_GT_SAINT_PIERRE_ET_MIQUELON_1950_TO_WGS_1984_1  1923 /* Saint Pierre */
                                                                /* and Miquelon */
#define PE_GT_SCORESBYSUND_1952_TO_WGS_1984_1     1799 /* Greenland - Scoresbysund area */
#define PE_GT_SELVAGEM_GRANDE_1938_TO_WGS_1984_1  1965 /* Portugal - Selvagens islands */
#define PE_GT_SOUTH_YEMEN_TO_WGS_1984_1     1682 /* South Yemen               */
#define PE_GT_ST71_BELEP_TO_WGS_1984_1      1931 /* New Caledonia - Belep     */
#define PE_GT_ST84_ILE_DES_PINS_TO_WGS_1984_1  1930 /* New Caledonia - Ile des Pins */
#define PE_GT_ST87_OUVEA_TO_WGS_1984_1      1919 /* New Caledonia - Ouvea     */
#define PE_GT_ST_VINCENT_1945_TO_WGS_1984_1 1959 /* St. Vincent and the Grenadines */
#define PE_GT_SWEREF99_TO_ETRS_1989_1       1878 /* Sweden                    */
#define PE_GT_SWEREF99_TO_WGS_1984_1        1879 /* Sweden                    */
#define PE_GT_S_JTSK_TO_ETRS_1989_1         1622 /* Czech Republic            */
#define PE_GT_S_JTSK_TO_ETRS_1989_2         1624 /* Slovak Republic           */
#define PE_GT_S_JTSK_TO_WGS_1984_1          1623 /* Czech Republic            */
#define PE_GT_S_JTSK_TO_WGS_1984_2          1625 /* Slovak Republic           */
#define PE_GT_TAHAA_TO_WGS_1984_1           1913 /* Society Islands - Bora Bora,*/
                                                 /* Huahin, Raiatea, Tahaa    */
#define PE_GT_TAHITI_TO_WGS_1984_1          1924 /* Society Islands - Moorea and Tahiti */
#define PE_GT_TETE_TO_WGS_1984_1            1683 /* Mozambique                */
#define PE_GT_TETE_TO_WGS_1984_2            1684 /* Mozambique - Maputo and   */
                                                 /* southern part of Gaza (S of 24S) */
#define PE_GT_TETE_TO_WGS_1984_3            1685 /* Mozambique - Gaza, Inhambane, */
                                                 /* and southern parts of Sofala &*/
                                                 /* Manhica (between 24S and 20S) */
#define PE_GT_TETE_TO_WGS_1984_4            1686 /* Mozambique - Sofala N of  */
                                                 /* Beira corridor, Manhica,  */
                                                 /* Tete & Zambezia (between  */
                                                 /* 20S and 16S)              */
#define PE_GT_TETE_TO_WGS_1984_5            1687 /* Mozambique - Nampula, Niassa,*/
                                                 /* and Cabo Delgado (N of 16S)  */
#define PE_GT_TIMBALAI_1948_TO_WGS_1984_4   1852 /* Malaysia - East Malaysia  */
                                                 /* (Sabah, Sarawak) offshore */
#define PE_GT_TM65_TO_ETRS_1989_1           1640 /* Republic of Ireland and   */
                                                 /* Northern Ireland          */
#define PE_GT_TM65_TO_WGS_1984_2            1641 /* Republic of Ireland and   */
                                                 /* Northern Ireland          */
#define PE_GT_TM75_TO_ETRS_1989_2           1953 /* Ireland, Northern Ireland */
#define PE_GT_TM75_TO_WGS_1984_2            1954 /* Ireland, Northern Ireland */
#define PE_GT_TM75_TO_WGS_1984_3            1956 /* Ireland, Northern Ireland */
#define PE_GT_YOFF_TO_WGS_1972_1            1828 /* Senegal                   */

#define PE_GT_AMERSFOORT_TO_ETRS_1989_MB  108231 /* Netherlands               */
#define PE_GT_CHATHAM_ISLANDS_1979_TO_NZGD_2000_1  108203 /* Chatham Islands  */
#define PE_GT_CHATHAM_ISLANDS_1979_TO_WGS_1984_1   108204 /* Chatham Islands  */
#define PE_GT_CHATHAM_ISLAND_1971_TO_WGS_1984      108205 /* Chatham Island   */
#define PE_GT_DHDN_TO_WGS_1984_3X         108206 /* Germany - S of 50 20 N    */
#define PE_GT_DHDN_TO_WGS_1984_4X         108207 /* Germany - between 50 20 N and 52 20 N */
#define PE_GT_DHDN_TO_WGS_1984_5X         108208 /* Germany - N of 52 20 N    */
#define PE_GT_DHDN_TO_WGS_1984_6X         108209 /* Germany - Thuringen       */
#define PE_GT_DHDN_TO_WGS_1984_7X         108210 /* Germany - Sachsen         */
#define PE_GT_EUREF_FIN_TO_ETRS_1989      108226 /* Finland                   */
#define PE_GT_EUREF_FIN_TO_WGS_1984       108227 /* Finland                   */
#define PE_GT_ISRAEL_TO_WGS_1984          108215 /* Israel                    */
#define PE_GT_JGD_2000_TO_WGS_1984        108107 /* Japan                     */
#define PE_GT_KKJ_TO_ETRS_1989_2          108228 /* Finland                   */
#define PE_GT_KKJ_TO_EUREF_FIN            108229 /* Finland                   */
#define PE_GT_KKJ_TO_WGS_1984_2           108230 /* Finland                   */
#define PE_GT_JORDAN_TO_WGS_1984          108233 /* Jordan                    */
#define PE_GT_LA_CANOA_TO_SIRGAS          108217 /* Venezuela                 */
#define PE_GT_LISBOA_HAYFORD_TO_DATUM_73_1       108222 /* Portugal  3 Param  */
#define PE_GT_LISBOA_HAYFORD_TO_DATUM_73_2       108223 /* Portugal  7 Param  */
#define PE_GT_LISBOA_HAYFORD_TO_LISBOA_BESSEL_1  108224 /* Portugal  3 Param  */
#define PE_GT_LISBOA_HAYFORD_TO_LISBOA_BESSEL_2  108225 /* Portugal  7 Param  */
#define PE_GT_MIDWAY_1961_TO_WGS_1984     108218 /* Midway Is.                */
#define PE_GT_MIDWAY_1961_TO_WGS_1984_OLD 108219 /* Midway Is.                */
#define PE_GT_OBSERV_METEOR_1965_TO_WGS_1984_2   108234 /* Macau              */
#define PE_GT_PALESTINE_1923_TO_WGS_1984_1X      108220 /* Palestine          */
#define PE_GT_PALESTINE_1923_TO_WGS_1984_2X      108232 /* Palestine          */
#define PE_GT_SWEREF99_TO_RT90            108212 /* Sweden                    */
#define PE_GT_S_JTSK_TO_PULKOVO_1942      108202 /* Czech Republic            */
#define PE_GT_WGS_1984_TO_OBSERV_METEOR_1965_1   108211 /* Macau              */
#define PE_GT_WGS_1984_TO_OBSERV_METEOR_1965_2   108235 /* Macau              */
#define PE_GT_WGS_1984_TO_RT90            108213 /* Sweden                    */

/* END of NEW GT's at 9.0 (Geocen, Coord, Pos, MB ) ------------------------- */

#define PE_GT_ABIDJAN_1987_TO_WGS_1984      1470 /* Cote d'Ivoire             */
#define PE_GT_ACCRA_TO_WGS_1972_BE          1570 /* Ghana - offshore          */
#define PE_GT_ACCRA_TO_WGS_1984             1569 /* Ghana                     */
#define PE_GT_ADINDAN_TO_WGS_1984_1         1100 /* Mean for Ethiopia and     */
#define PE_GT_ADINDAN_TO_WGS_1984_2         1101 /* Burkina Faso              */
#define PE_GT_ADINDAN_TO_WGS_1984_3         1102 /* Cameroon                  */
#define PE_GT_ADINDAN_TO_WGS_1984_4         1103 /* Ethiopia                  */
#define PE_GT_ADINDAN_TO_WGS_1984_5         1104 /* Mali                      */
#define PE_GT_ADINDAN_TO_WGS_1984_6         1105 /* Senegal                   */
#define PE_GT_ADINDAN_TO_WGS_1984_7         1106 /* Sudan                     */
#define PE_GT_AFGOOYE_TO_WGS_1984           1107 /* Somalia                   */
#define PE_GT_AGD_1966_TO_GDA_1994          1278 /* Australia                 */
#define PE_GT_AGD_1966_TO_GDA_1994_2        1458 /* Australia - ACT           */
#define PE_GT_AGD_1966_TO_GDA_1994_3        1459 /* Australia - Tasmania      */
#define PE_GT_AGD_1966_TO_GDA_1994_4        1460 /* Australia - New South Wales & Victoria */
#define PE_GT_AGD_1966_TO_GDA_1994_8        1594 /* Australia - Tasmania      */
#define PE_GT_AGD_1966_TO_GDA_1994_9        1595 /* Australia - Northern Terr */
#define PE_GT_AGD_1966_TO_WGS_1984          1108 /* Australia                 */
#define PE_GT_AGD_1984_TO_GDA_1994          1279 /* Australia                 */
#define PE_GT_AGD_1984_TO_GDA_1994_2        1280 /* Australia                 */
#define PE_GT_AGD_1984_TO_WGS_1984_1        1109 /* Australia                 */
#define PE_GT_AGD_1984_TO_WGS_1984_2        1236 /* Australia                 */
#define PE_GT_AIN_EL_ABD_TO_WGS_1984_1      1110 /* Bahrain                   */
#define PE_GT_AIN_EL_ABD_TO_WGS_1984_2      1111 /* Saudi Arabia              */
#define PE_GT_AMERSFOORT_TO_ETRF_1989     108191 /* Netherlands               */
#define PE_GT_AMERSFOORT_TO_ETRS_1989       1751 /* Netherlands               */
#define PE_GT_ARC_1950_TO_WGS_1984_1        1113 /* Mean for Botswana, Malawi,*/
                                                 /* Swaziland, Zaire, Zambia, */
                                                 /* and Zimbabwe              */
#define PE_GT_AMERSFOORT_TO_WGS_1984        1112 /* Netherlands               */
#define PE_GT_ANTIGUA_1943_TO_WGS_1984      1441 /* Antigua                   */
#define PE_GT_ARATU_TO_WGS_1984_1           1549 /* Brazil - Campos; Espiritu */
                                                 /*       Santo, Santos basin */
#define PE_GT_ARATU_TO_WGS_1984_2           1550 /* Brazil - Tucano basin north */
#define PE_GT_ARATU_TO_WGS_1984_3           1551 /* Brazil - Tucano basin central */
#define PE_GT_ARATU_TO_WGS_1984_4           1552 /* Brazil - Tucano basin south */
#define PE_GT_ARC_1950_TO_WGS_1984_2        1114 /* Botswana                  */
#define PE_GT_ARC_1950_TO_WGS_1984_3        1115 /* Burundi                   */
#define PE_GT_ARC_1950_TO_WGS_1984_4        1116 /* Lesotho                   */
#define PE_GT_ARC_1950_TO_WGS_1984_5        1117 /* Malawi                    */
#define PE_GT_ARC_1950_TO_WGS_1984_6        1118 /* Swaziland                 */
#define PE_GT_ARC_1950_TO_WGS_1984_7        1119 /* Zaire                     */
#define PE_GT_ARC_1950_TO_WGS_1984_8        1120 /* Zambia                    */
#define PE_GT_ARC_1950_TO_WGS_1984_9        1121 /* Zimbabwe                  */
#define PE_GT_ARC_1960_TO_WGS_1984          1122 /* Mean for Kenya and        */
                                                 /* Tanzania                  */
#define PE_GT_ARC_1960_TO_WGS_1984_2        1284 /* Kenya                     */
#define PE_GT_ARC_1960_TO_WGS_1984_3        1285 /* Tanzania                  */
#define PE_GT_BATAVIA_JAKARTA_TO_WGS_1984   8178 /* Batavia(Jakarta) to WGS84 */
#define PE_GT_BATAVIA_TO_WGS_1984           1123 /* Indonesia (Sumatra)       */
#define PE_GT_BELGE_1972_TO_WGS_1984_1      1609 /* Belgium                   */
#define PE_GT_BELGE_1972_TO_WGS_1984_2      1610 /* Belgium                   */
#define PE_GT_BERMUDA_1957_TO_WGS_1984      1124 /* Bermuda                   */
#define PE_GT_BISSAU_TO_WGS_1984            1547 /* Guinea-Bissau             */
#define PE_GT_BOGOTA_BOGOTA_TO_WGS_1984     8174 /* Bogota(Bogota) to WGS84   */
#define PE_GT_BOGOTA_TO_WGS_1984            1125 /* Columbia                  */
#define PE_GT_BOGOTA_TO_WGS_1984_2          1597 /* Colombia - Casanare, BP   */
                                                 /* Cusiana/Cupiagua field areas */
#define PE_GT_BUKIT_RIMPAH_TO_WGS_1984      1126 /* Indonesia (Bangka and     */
                                                 /* Belitung Islands          */
#define PE_GT_CAMACUPA_TO_WGS_1972_BE_1     1317 /* Angola - offshore         */
#define PE_GT_CAMACUPA_TO_WGS_1984_1        1318 /* Angola - offshore block 5 */
#define PE_GT_CAMACUPA_TO_WGS_1984_2        1319 /* Angola - offshore block 2 */
#define PE_GT_CAMACUPA_TO_WGS_1984_3        1320 /* Angola - offshore block 1 & 16 */
#define PE_GT_CAMACUPA_TO_WGS_1984_4        1321 /* Angola - offshore block 7 & 8 */
#define PE_GT_CAMACUPA_TO_WGS_1984_5        1322 /* Angola - offshore block 3 */
#define PE_GT_CAMACUPA_TO_WGS_1984_6        1323 /* Angola - offshore block 7 */
#define PE_GT_CAMACUPA_TO_WGS_1984_7        1324 /* Angola - offshore block 3, 7, 15, & 17 */
#define PE_GT_CAMACUPA_TO_WGS_1984_8        1325 /* Angola - offshore block 2 */
#define PE_GT_CAMACUPA_TO_WGS_1984_9        1326 /* Angola - offshore block 1 & 16 */
#define PE_GT_CAMACUPA_TO_WGS_1984_10       1327 /* Angola - offshore block 2, 3, & 17 */
#define PE_GT_CAMPO_INCHAUSPE_TO_WGS_1984   1127 /* Argentina                 */
#define PE_GT_CAMPO_INCHAUSPE_TO_WGS_1984_2 1527 /* Argentina - Neuquen       */
                                                 /* province, Chos Malal area */
#define PE_GT_CAPE_TO_HARTEBEESTHOEK94      1504 /* South Africa              */
#define PE_GT_CAPE_TO_WGS_1984_1            1128 /* South Africa              */
#define PE_GT_CAPE_TO_WGS_1984_2            1129 /* South Africa              */
#define PE_GT_CARTHAGE_TO_WGS_1984          1130 /* Tunisia                   */
#define PE_GT_CARTHAGE_TO_WGS_1984_2        1538 /* Tunisia - offshore        */
#define PE_GT_CH1903_PLUS_TO_CHTRF_1995     1509 /* Liechtenstein, Switzerland*/
#define PE_GT_CH1903_TO_WGS_1984_1          1508 /* Liechtenstein, Switzerland*/
#define PE_GT_CH1903_TO_WGS_1984_2          1510 /* Liechtenstein, Switzerland*/
#define PE_GT_CHOS_MALAL_1914_TO_CAMPO_INCHAUSPE  1528 /* Argentina - Neuquen */
                                                 /* province, Chos Malal area */
#define PE_GT_CHOS_MALAL_1914_TO_WGS_1984   8517 /* Argentina - Neuquen       */
                                                 /* province, Chos Malal area */
#define PE_GT_CHTRF_1995_TO_WGS_1984        1511 /* Liechtenstein, Switzerland*/
#define PE_GT_CHUA_TO_WGS_1984              1131 /* Paraguay                  */
#define PE_GT_CONAKRY_1905_TO_WGS_1984      1517 /* Guinea                    */
#define PE_GT_CORREGO_ALEGRE_TO_WGS_1984    1132 /* Brazil                    */
#define PE_GT_DABOLA_1981_TO_WGS_1984       1518 /* Guinea                    */
#define PE_GT_DEIR_EZ_ZOR_TO_WGS_1972_BE    1584 /* Syrian Arab Republic -    */
                                                 /* Deir area (35 22 N, 40 06 E) */
#define PE_GT_DEIR_EZ_ZOR_TO_WGS_1984_2     1585 /* Syrian Arab Republic      */
#define PE_GT_DEIR_EZ_ZOR_TO_WGS_1984_3     1586 /* Syrian Arab Republic -    */
                                                 /*   Al Whaleed area         */
#define PE_GT_DEIR_EZ_ZOR_TO_WGS_1984_4     1587 /* Syrian Arab Republic -    */
                                                 /* Shaddadeh area (36 N, 41 E) */
#define PE_GT_DHDN_TO_ETRF_1989           108192 /* Germany - former W Germany*/
#define PE_GT_DHDN_TO_ETRS_1989             1309 /* Germany - former W Germany*/
#define PE_GT_DOMINICA_1945_TO_WGS_1984     1442 /* Dominica                  */
#define PE_GT_ED_1950_ED77_TO_WGS_1984      1514 /* Iran                      */
#define PE_GT_ED_1950_TO_ED_1987_2          1147 /* Norway (offshore north of */
                                                 /* 65 deg N)                 */
#define PE_GT_ED_1950_TO_ETRF_1989_1      108193 /* Norway -offshore N of 65N */
                                                 /* Svalbard and Jan Mayen Islands */
#define PE_GT_ED_1950_TO_ETRS_1989_1        1588 /* Norway -offshore N of 65N */
                                                 /* Svalbard and Jan Mayen Islands */
#define PE_GT_ED_1950_TO_WGS_1984_1         1133 /* Mean for Austria, Belgium,*/
                                                 /* Denmark, Finland, France, */
                                                 /* Germany (West), Gibraltar,*/
                                                 /* Greece, Italy, Luxembourg,*/
                                                 /* Netherlands, Norway,      */
                                                 /* Spain, Sweden,            */
                                                 /* Switzerland, and Portugal */
#define PE_GT_ED_1950_TO_WGS_1984_2         1134 /* Mean for Austria, Denmark,*/
                                                 /* France, Germany (West),   */
                                                 /* Netherlands,              */
                                                 /* and Switzerland           */
#define PE_GT_ED_1950_TO_WGS_1984_3         1135 /* Mean for Iraq, Israel,    */
                                                 /* Jordan, Kuwait, Lebanon,  */
                                                 /* Saudi Arabia, and Syria   */
#define PE_GT_ED_1950_TO_WGS_1984_4         1136 /* Cyprus                    */
#define PE_GT_ED_1950_TO_WGS_1984_5         1137 /* Egypt                     */
#define PE_GT_ED_1950_TO_WGS_1984_6         1138 /* Ireland, United Kingdom   */
#define PE_GT_ED_1950_TO_WGS_1984_7         1139 /* Finland, Norway           */
#define PE_GT_ED_1950_TO_WGS_1984_8         1140 /* Greece                    */
#define PE_GT_ED_1950_TO_WGS_1984_9         1141 /* Iran                      */
#define PE_GT_ED_1950_TO_WGS_1984_10        1142 /* Italy (Sardinia)          */
#define PE_GT_ED_1950_TO_WGS_1984_11        1143 /* Italy (Sicily)            */
#define PE_GT_ED_1950_TO_WGS_1984_12        1144 /* Malta                     */
#define PE_GT_ED_1950_TO_WGS_1984_13        1145 /* Portugal, Spain           */
#define PE_GT_ED_1950_TO_WGS_1984_16        1245 /* Tunisia                   */
#define PE_GT_ED_1950_TO_WGS_1984_17        1275 /* France                    */
#define PE_GT_ED_1950_TO_WGS_1984_18        1311 /* UK - offshore E of 6W     */
#define PE_GT_ED_1950_TO_WGS_1984_19        1440 /* Greece                    */
#define PE_GT_ED_1950_TO_WGS_1984_23        1612 /* Norway -offshore N of 62N */
                                                 /* Svalbard and Jan Mayen Islands */
#define PE_GT_ED_1950_TO_WGS_1984_24        1613 /* Norway -offshore S of 62N */
#define PE_GT_ED_1987_TO_WGS_1984_1         1146 /* North Sea south of 62     */
                                                 /* deg N (UK,Denmark,Germany,*/
                                                 /* Norway) and Netherlands   */
                                                 /* (offshore)                */
#define PE_GT_EGYPT_1907_TO_WGS_1972        1545 /* Egypt                     */
#define PE_GT_EGYPT_1907_TO_WGS_1984        1148 /* Egypt                     */
#define PE_GT_EGYPT_1907_TO_WGS_1984_3      1546 /* Egypt - Gulf of Suez      */
#define PE_GT_ESTONIA_1992_TO_ETRF_1989   108194 /* Estonia                   */
#define PE_GT_ESTONIA_1992_TO_ETRS_1989     1331 /* Estonia                   */
#define PE_GT_ESTONIA_1992_TO_WGS_1984      1333 /* Estonia                   */
#define PE_GT_ETRF_1989_TO_WGS_1984       108195 /* Europe                    */
#define PE_GT_ETRS_1989_TO_WGS_1984         1149 /* Europe                    */
#define PE_GT_FAHUD_TO_WGS_1984             1256 /* Oman                      */
#define PE_GT_FAHUD_TO_WGS_1984_2           1438 /* Oman                      */
#define PE_GT_FD_1958_TO_WGS_1984           1513 /* Iran - Kangan District    */
#define PE_GT_GGRS_1987_TO_WGS_1984         1272 /* Greek GRS                 */
#define PE_GT_GDA_1994_TO_WGS_1984          1150 /* Australia                 */
#define PE_GT_GRENADA_1953_TO_WGS_1984      1443 /* Grenada                   */
#define PE_GT_HANOI_1972_TO_WGS_1984        1544 /* Vietnam - Meekong delta   */
#define PE_GT_HARTEBEESTHOEK94_TO_WGS_1984  1505 /* South Africa              */
#define PE_GT_HERAT_NORTH_TO_WGS_1984       1246 /* Afghanistan               */
#define PE_GT_HITO_XVIII_1963_TO_WGS_1984   1529 /* Argentina - Tierra del Fuego */
#define PE_GT_HUNGARIAN_1972_TO_ETRF_1989_1 108196 /* Hungarian to ETRF 1989  */
#define PE_GT_HUNGARIAN_1972_TO_ETRS_1989_1 1829 /* Hungarian to ETRF 1989    */
#define PE_GT_HU_TZU_SHAN_TO_WGS_1984       1152 /* Taiwan                    */
#define PE_GT_INDIAN_1954_TO_WGS_1984       1153 /* Thailand, Vietnam         */
#define PE_GT_INDIAN_1960_TO_WGS_1972_BE    1541 /* Vietnam - offshore        */
#define PE_GT_INDIAN_1960_TO_WGS_1984_1     8532 /* Vietnam - offshore        */
#define PE_GT_INDIAN_1960_TO_WGS_1984_2     1542 /* Vietnam near 16N          */
#define PE_GT_INDIAN_1960_TO_WGS_1984_3     1543 /* Vietnam - Con Son island  */
#define PE_GT_INDIAN_1975_TO_WGS_1984       1154 /* Thailand                  */
#define PE_GT_INDIAN_1975_TO_WGS_1984_2     1304 /* Thailand                  */
#define PE_GT_INDIAN_1975_TO_WGS_1984_3     1537 /* Thailand - Bongkot field  */
#define PE_GT_INDONESIAN_1974_TO_WGS_1984   1248 /* Indonesia                 */
#define PE_GT_IRENET95_TO_ETRF_1989       108197 /* Northern Ireland          */
#define PE_GT_IRENET95_TO_ETRS_1989         1611 /* Northern Ireland          */
#define PE_GT_KALIANPUR_1937_TO_WGS_1984_1  1155 /* Bangladesh                */
#define PE_GT_KALIANPUR_1937_TO_WGS_1984_2  1533 /* Myanmar - Moattama area   */
#define PE_GT_KALIANPUR_1962_TO_WGS_1984_1  1247 /* Pakistan                  */
#define PE_GT_KALIANPUR_1975_TO_WGS_1984_1  1156 /* India, Nepal              */
#define PE_GT_KANDAWALA_TO_WGS_1984         1157 /* Sri Lanka                 */
#define PE_GT_KERTAU_TO_WGS_1984            1158 /* West Malaysia, Singapore  */
#define PE_GT_KOREAN_1995_TO_WGS_1984_1     1558 /* Republic of Korea         */
#define PE_GT_LA_CANOA_TO_WGS_1984          1516 /* Venezuela - Delta Amacuro,*/
                                                 /*   Anzoategui, Bolivar,    */
                                                 /*   Monagas, Sucre States   */
#define PE_GT_LEIGON_TO_WGS_1984            1159 /* Ghana                     */
#define PE_GT_LIBERIA_1964_TO_WGS_1984      1160 /* Liberia                   */
#define PE_GT_LKS_1994_TO_WGS_1984          1283 /* Lithuania                 */
#define PE_GT_LOCODJO_1965_TO_WGS_1984      1469 /* Cote d'Ivoire             */
#define PE_GT_LUZON_1911_TO_WGS_1984_1      1161 /* Philippines (excluding    */
                                                 /* Mindanao)                 */
#define PE_GT_LUZON_1911_TO_WGS_1984_2      1162 /* Philippines (Mindanao)    */
#define PE_GT_MAHE_1971_TO_WGS_1984         1164 /* Mahe Island               */
#define PE_GT_MALONGO_1987_TO_MHAST_1       1328 /* Angola - Cabinda offshore */
#define PE_GT_MALONGO_1987_TO_WGS_1984_1    1330 /* Angola - Cabinda offshore */
#define PE_GT_MALONGO_1987_TO_WGS_1984_2    1557 /* Angola - Cabinda offshore */
#define PE_GT_MANOCA_TO_WGS_1984_1          1316 /* Cameroon                  */
#define PE_GT_MASSAWA_TO_WGS_1984           1165 /* Ethiopia (Eritrea)        */
#define PE_GT_MERCHICH_TO_WGS_1984          1166 /* Morocco                   */
#define PE_GT_MGI_FERRO_TO_WGS_1984         8263 /* Mean for Croatia, Slovenia, */
                                                 /* Bosnia and Herzegovina, & Serbia */
#define PE_GT_MGI_TO_WGS_1984               1306 /* Boznia and Herzegovina,   */
                                                 /* Croatia, Serbia, Slovenia */
#define PE_GT_MGI_TO_WGS_1984_2             8415 /* Austria                   */
#define PE_GT_MGI_TO_WGS_1984_3             1618 /* Austria                   */
#define PE_GT_MHAST_TO_WGS_1984_1           1329 /* Angola - Cabinda offshore */
#define PE_GT_MINNA_TO_WGS_1984_1           1167 /* Cameroon                  */
#define PE_GT_MINNA_TO_WGS_1984_2           1168 /* Nigeria                   */
#define PE_GT_MINNA_TO_WGS_1984_3           1754 /* Nigeria - south           */
#define PE_GT_MONTE_MARIO_ROME_TO_WGS_1984  8175 /* Monte Mario(Rome) to WGS84*/
#define PE_GT_MONTE_MARIO_TO_WGS_1984       1169 /* Italy (Sardinia)          */
#define PE_GT_MONTSERRAT_1958_TO_WGS_1984   1444 /* Montserrat                */
#define PE_GT_MOZNET_TO_WGS_1984            1302 /* Mozambique                */
#define PE_GT_MPORALOKO_TO_WGS_1984         1163 /* Gabon                     */
#define PE_GT_MPORALOKO_TO_WGS_1984_2       1532 /* Gabon                     */

#define PE_GT_NAD_1927_TO_WGS_1984_1        1170 /* Mean for Antigua, Barbados*/
                                                 /* Barbuda, Caicos Islands,  */
                                                 /* Cuba, Dominican Republic, */
                                                 /* Grand Cayman, Jamaica,    */
                                                 /* and Turks Islands         */
#define PE_GT_NAD_1927_TO_WGS_1984_2        1171 /* Mean for Belize,          */
                                                 /* Costa Rica, El Salvador,  */
                                                 /* Guatemala, Honduras,      */
                                                 /* and Nicaragua             */
#define PE_GT_NAD_1927_TO_WGS_1984_3        1172 /* Mean for Canada           */
#define PE_GT_NAD_1927_TO_WGS_1984_4        1173 /* Mean for United States    */
                                                 /* (CONUS)                   */
#define PE_GT_NAD_1927_TO_WGS_1984_5        1174 /* Mean for United States    */
                                                 /* (CONUS East of Mississippi*/
                                                 /* River including MN, MO,   */
                                                 /* and LA)                   */
#define PE_GT_NAD_1927_TO_WGS_1984_6        1175 /* Mean for United States    */
                                                 /* (CONUS West of Mississippi*/
                                                 /* River)                    */
#define PE_GT_NAD_1927_TO_WGS_1984_7        1176 /* United States (Alaska)    */
#define PE_GT_NAD_1927_TO_WGS_1984_8        1177 /* Bahamas (except San       */
                                                 /* Salvador Island)          */
#define PE_GT_NAD_1927_TO_WGS_1984_9        1178 /* Bahamas (San Salvador     */
                                                 /* Island)                   */
#define PE_GT_NAD_1927_TO_WGS_1984_10       1179 /* Canada (Alberta, British  */
                                                 /* Columbia)                 */
#define PE_GT_NAD_1927_TO_WGS_1984_11       1180 /* Canada (Manitoba, Ontario)*/
#define PE_GT_NAD_1927_TO_WGS_1984_12       1181 /* Canada (New Brunswick,    */
                                                 /* Newfoundland, Nova Scotia,*/
                                                 /* and Quebec)               */
#define PE_GT_NAD_1927_TO_WGS_1984_13       1182 /* Canada (Northwest         */
                                                 /* Territories, Saskatchewan)*/
#define PE_GT_NAD_1927_TO_WGS_1984_14       1183 /* Canada (Yukon)            */
#define PE_GT_NAD_1927_TO_WGS_1984_15       1184 /* Panama (Canal Zone)       */
#define PE_GT_NAD_1927_TO_WGS_1984_16       1185 /* Cuba                      */
#define PE_GT_NAD_1927_TO_WGS_1984_17       1186 /* Greenland (Hayes          */
                                                 /* Peninsula)                */
#define PE_GT_NAD_1927_TO_WGS_1984_18       1187 /* Mexico                    */

#define PE_GT_NAD_1927_TO_WGS_1984_21       1249 /* United States (Alaska -   */
                                                 /* Aleutians East of 180E)   */
#define PE_GT_NAD_1927_TO_WGS_1984_22       1250 /* United States (Alaska -   */
                                                 /* Aleutians West of 180E)   */
#define PE_GT_NAD_1927_TO_WGS_1984_30       1530 /* Cuba                      */

#define PE_GT_NAD_1983_CSRS98_TO_WGS_1984   1473 /* Canada - New Brunswick    */
#define PE_GT_NAD_1983_HARN_TO_WGS_1984     1580 /* United States             */
#define PE_GT_NAD_1983_TO_WGS_1984_1        1188 /* Canada, Central America,  */
                                                 /* Mexico, and United States */
                                                 /* (Alaska, CONUS)           */
#define PE_GT_NAD_1983_TO_WGS_1984_2        1251 /* United States (Alaska -   */
                                                 /* Aleutians)                */
#define PE_GT_NAD_1983_TO_WGS_1984_3        1252 /* United States (Hawaii)    */
#define PE_GT_NAD_1983_TO_WGS_1984_4        1308 /* United States- CORS ITRF96*/
#define PE_GT_NAD_1983_TO_WGS_1984_5        1515 /* United States             */
#define PE_GT_NAHRWAN_1967_TO_WGS_1984_1    1189 /* Oman (Nasirah Island)     */
#define PE_GT_NAHRWAN_1967_TO_WGS_1984_2    1190 /* Saudi Arabia              */
#define PE_GT_NAHRWAN_1967_TO_WGS_1984_3    1191 /* United Arab Emirates      */
#define PE_GT_NAHRWAN_1967_TO_WGS_1984_4    1531 /* UAE - Abu al Bu Koosh     */
#define PE_GT_NAHRWAN_1967_TO_WGS_1984_5    1536 /* Qatar                     */
#define PE_GT_NAPARIMA_1955_TO_WGS_1984_2   1555 /* Trinidad                  */
#define PE_GT_NAPARIMA_1955_TO_WGS_1984_3   1556 /* Trinidad                  */
#define PE_GT_NAPARIMA_1972_TO_WGS_1984     1192 /* Trinidad & Tobago         */
#define PE_GT_NAPARIMA_1972_TO_WGS_1984_2   8212 /* Trinidad and Tobago       */
#define PE_GT_NAPARIMA_1972_TO_WGS_1984_3   1307 /* Trinidad and Tobago       */
#define PE_GT_NORD_SAHARA_1959_TO_WGS_1972_BE 1560 /* Algeria - Hassi Messaoud area */
#define PE_GT_NORD_SAHARA_1959_TO_WGS_1984  1253 /* Algeria                   */
#define PE_GT_NORD_SAHARA_1959_TO_WGS_1984_3  8562 /* Algeria - Hassi Messaoud */
#define PE_GT_NTF_PARIS_TO_ED_1950          8186 /* NTF(Paris) to ED 1950     */
#define PE_GT_NTF_PARIS_TO_WGS_1972         8188 /* NTF(Paris) to WGS 1972    */
#define PE_GT_NTF_PARIS_TO_WGS_1984         8094 /* NTF(Paris) to WGS 1984    */
#define PE_GT_NTF_TO_ED_1950                1276 /* France                    */
#define PE_GT_NTF_TO_WGS_1972               1277 /* France                    */
#define PE_GT_NTF_TO_WGS_1984               1193 /* France                    */
#define PE_GT_NZGD_1949_TO_WGS_1984         1151 /* New Zealand               */
#define PE_GT_NZGD_1949_TO_WGS_1984_2       1564 /* New Zealand               */
#define PE_GT_NZGD_2000_TO_WGS_1984_1       1565 /* New Zealand               */
#define PE_GT_OSGB_1936_TO_ED_1950_UKOOA    1315 /* UK - England, Scotland, Wales, N Sea */
#define PE_GT_OSGB_1936_TO_WGS_1984_1       1195 /* Mean for UK (England,     */
                                                 /* Scotland, Wales, and      */
                                                 /* Isle of Man)              */
#define PE_GT_OSGB_1936_TO_WGS_1984_2       1196 /* UK (England)              */
#define PE_GT_OSGB_1936_TO_WGS_1984_3       1197 /* UK (England, Wales, and   */
                                                 /* Isle of Man)              */
#define PE_GT_OSGB_1936_TO_WGS_1984_4       1198 /* UK (Scotland, including   */
                                                 /* Shetland Islands)         */
#define PE_GT_OSGB_1936_TO_WGS_1984_5       1199 /* UK (Wales)                */
#define PE_GT_OSGB_1936_TO_WGS_1984_PETROL  1314 /* UK - England, Scotland, Wales, N Sea */
#define PE_GT_PDO_1993_TO_WGS_1972          1616 /* Oman                      */
#define PE_GT_PDO_1993_TO_WGS_1984          1439 /* Oman                      */
#define PE_GT_PDO_1993_TO_WGS_1984_3        1617 /* Oman - Block 4            */
#define PE_GT_POINTE_NOIRE_TO_WGS_1984      1200 /* Congo                     */
#define PE_GT_POSGAR_TO_WGS_1984_1          1598 /* South America             */
#define PE_GT_PSAD_1956_TO_WGS_1984_1       1201 /* Mean for Bolivia, Chile,  */
                                                 /* Colombia, Ecuador, Guyana,*/
                                                 /* Peru, and Venezuela       */
#define PE_GT_PSAD_1956_TO_WGS_1984_2       1202 /* Bolivia                   */
#define PE_GT_PSAD_1956_TO_WGS_1984_3       1203 /* Chile (Northern, near     */
                                                 /* 19 deg S                  */
#define PE_GT_PSAD_1956_TO_WGS_1984_4       1204 /* Chile (Southern, near     */
                                                 /* 43 deg S                  */
#define PE_GT_PSAD_1956_TO_WGS_1984_5       1205 /* Colombia                  */
#define PE_GT_PSAD_1956_TO_WGS_1984_6       1206 /* Ecuador                   */
#define PE_GT_PSAD_1956_TO_WGS_1984_7       1207 /* Guyana                    */
#define PE_GT_PSAD_1956_TO_WGS_1984_8       1208 /* Peru                      */
#define PE_GT_PSAD_1956_TO_WGS_1984_9       1209 /* Venezuela                 */
#define PE_GT_PSAD_1956_TO_WGS_1984_10      1582 /* Bolivia - Madidi          */
#define PE_GT_PSAD_1956_TO_WGS_1984_11      1583 /* Bolivia - Block 20        */
#define PE_GT_PULKOVO_1942_TO_ESTONIA_1992  1332 /* Estonia                   */
#define PE_GT_PULKOVO_1942_TO_ETRF_1989   108198 /* Germany - former E Germany*/
#define PE_GT_PULKOVO_1942_TO_ETRS_1989     1310 /* Germany - former E Germany*/
#define PE_GT_PULKOVO_1942_TO_LKS_1994      1274 /* Lithuania                 */
#define PE_GT_PULKOVO_1942_TO_WGS_1984      1254 /* Russia                    */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_3    1287 /* Hungary                   */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_4    1288 /* Poland                    */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_5    1289 /* Czech Republic            */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_6    1290 /* Latvia                    */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_7    1291 /* Kazakhstan                */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_8    1292 /* Albania                   */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_9    1293 /* Romania                   */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_10   1303 /* Kazakhstan - Caspian      */
#define PE_GT_PULKOVO_1942_TO_WGS_1984_12   1334 /* Estonia                   */
#define PE_GT_QATAR_TO_WGS_1984             1561 /* Qatar                     */
#define PE_GT_QATAR_1974_TO_WGS_1984_1      1561 /* Qatar                     */
#define PE_GT_QATAR_1974_TO_WGS_1984_2      1562 /* Qatar - offshore          */
#define PE_GT_QATAR_1974_TO_WGS_1984_3      1563 /* Qatar - onshore           */
#define PE_GT_QORNOQ_TO_WGS_1984            8111 /* Greenland (South)         */
#define PE_GT_RASSADIRAN_TO_WGS_1984        1512 /* Iran - Tehari Refinery    */
#define PE_GT_RGF_1993_TO_ETRF_1989_1     108199 /* France                    */
#define PE_GT_RGF_1993_TO_ETRS_1989_1       1591 /* France                    */
#define PE_GT_RT90_TO_WGS_1984              1437 /* Sweden                    */
#define PE_GT_SAD_1969_TO_WGS_1984_1        1864 /* Mean for Argentina,       */
                                                 /* Bolivia, Brazil, Chile,   */
                                                 /* Colombia, Ecuador, Guyana,*/
                                                 /* Paraguay, Peru, Trinidad &*/
                                                 /* Tobago, and Venezuela     */
#define PE_GT_SAD_1969_TO_WGS_1984_2        1865 /* Argentina                 */
#define PE_GT_SAD_1969_TO_WGS_1984_3        1866 /* Bolivia                   */
#define PE_GT_SAD_1969_TO_WGS_1984_4        1867 /* Brazil                    */
#define PE_GT_SAD_1969_TO_WGS_1984_5        1868 /* Chile                     */
#define PE_GT_SAD_1969_TO_WGS_1984_6        1869 /* Colombia                  */
#define PE_GT_SAD_1969_TO_WGS_1984_7        1870 /* Ecuador                   */
#define PE_GT_SAD_1969_TO_WGS_1984_8        1871 /* Ecuador (Baltra,          */
                                                 /* Galapagos)                */
#define PE_GT_SAD_1969_TO_WGS_1984_9        1872 /* Guyana                    */
#define PE_GT_SAD_1969_TO_WGS_1984_10       1873 /* Paraguay                  */
#define PE_GT_SAD_1969_TO_WGS_1984_11       1874 /* Peru                      */
#define PE_GT_SAD_1969_TO_WGS_1984_12       1875 /* Trinidad & Tobago         */
#define PE_GT_SAD_1969_TO_WGS_1984_13       1876 /* Venezuela                 */
#define PE_GT_SAD_1969_TO_WGS_1984_14       1877 /* Brazil                    */
#define PE_GT_SAMBOJA_TO_WGS_1984           1282 /* Indonesia - E Kalimantan  */
                                                 /*   Mahakam delta area      */
#define PE_GT_SAMOA_1962_TO_WGS_1984        1577 /* American Samoa            */
#define PE_GT_SAPPER_HILL_1943_TO_WGS_1984  1225 /* Falkland Islands (East    */
                                                 /* Falkland Island)          */
#define PE_GT_SCHWARZECK_TO_WGS_1984        1226 /* Namibia                   */
#define PE_GT_SCHWARZECK_TO_WGS_1984_2      1271 /* Namibia                   */
#define PE_GT_SEGORA_TO_WGS_1984            1286 /* Indonesia - Kalimantan    */
#define PE_GT_SIERRA_LEONE_1968_TO_WGS_1984 1614 /* Sierra Leone              */
#define PE_GT_SIRGAS_TO_WGS_1984_1          1581 /* South America             */
#define PE_GT_SOUTH_YEMEN_TO_YEMEN_NGN_1996 1539 /* South Yemen               */
#define PE_GT_ST_LUCIA_1955_TO_WGS_1984     1446 /* St. Lucia                 */
#define PE_GT_ST_KITTS_1955_TO_WGS_1984     1445 /* St. Kitts and Nevis       */
#define PE_GT_TANANARIVE_1925_PARIS_TO_WGS_1984  8176 
                                                 /* Tananarive (Paris) to     */
                                                 /* WGS84                     */
#define PE_GT_TANANARIVE_1925_TO_WGS_1984   1227 /* Madagascar                */
#define PE_GT_TETE_TO_MOZNET_1              1297 /* Mozambique                */
#define PE_GT_TETE_TO_MOZNET_2              1298 /* Mozambique - Maputo &     */
                                                 /*   S Gaza  province,       */
                                                 /*   S of approx. 24S        */
#define PE_GT_TETE_TO_MOZNET_3              1299 /* Mozambique - Gaza,        */
                                                 /*  Inhambane, S Sofala and  */
                                                 /*  S Manhica, betwn 20S-24S */
#define PE_GT_TETE_TO_MOZNET_4              1300 /* Mozambique - Sofala N of  */
                                                 /*  Beira corridor, Manhica, */
                                                 /*  Tete & Zambezia, 16S-20S */
#define PE_GT_TETE_TO_MOZNET_5              1301 /* Mozambique  - Nampula,    */
                                                 /*  Niassa and Cabo Delgado, */
                                                 /*  N of 16S                 */
#define PE_GT_TIMBALAI_1948_TO_WGS_1984     1228 /* Brunei, Malaysia (Sabah,  */
                                                 /* Sarawak)                  */
#define PE_GT_TIMBALAI_1948_TO_WGS_1984_2   1592 /* Brunei Darussalam offshore*/
#define PE_GT_TIMBALAI_1948_TO_WGS_1984_3   1615 /* Brunei Darussalam onshore */
#define PE_GT_TM65_TO_WGS_1984              1229 /* Ireland                   */
#define PE_GT_TOKYO_TO_WGS_1984_1           1230 /* Mean for Japan, Korea,    */
                                                 /* and Okinawa               */
#define PE_GT_TOKYO_TO_WGS_1984_2           1231 /* Japan                     */
#define PE_GT_TOKYO_TO_WGS_1984_3           1232 /* Korea                     */
#define PE_GT_TOKYO_TO_WGS_1984_4           1233 /* Okinawa                   */
#define PE_GT_TOKYO_TO_WGS_1984_5           1305 /* South Korea               */
#define PE_GT_TRINIDAD_1903_TO_WGS_1984     1296 /* Trinidad and Tobago       */
#define PE_GT_VOIROL_1875_PARIS_TO_WGS_1984 8211 /* Voirol 1875 (Paris) to    */
                                                 /* WGS84                     */
#define PE_GT_VOIROL_1875_TO_WGS_1984       1294 /* Algeria - N of 35g (31 30') N */
#define PE_GT_VOIROL_UNIFIE_1960_PARIS_TO_WGS_1984  8177
                                                 /* Voirol Unifie (Paris) to  */
                                                 /* WGS84                     */
#define PE_GT_VOIROL_UNIFIE_1960_TO_WGS_1984  8158 /* Algeria                 */
#define PE_GT_WGS_1972_TO_WGS_1984_1        1237 /* World                     */
#define PE_GT_WGS_1972_TO_WGS_1984_2        1238 /* World                     */
#define PE_GT_YACARE_TO_WGS_1984            1234 /* Uruguay                   */
#define PE_GT_YEMEN_NGN_1996_TO_WGS_1984    1540 /* Yemen                     */
#define PE_GT_ZANDERIJ_TO_WGS_1984          1235 /* Suriname                  */


#define PE_GT_OLD_HAWAIIAN_TO_WGS_1984_1  108008 /* Old Hawaiian to WGS 1984 (1 - OHA_M) */
#define PE_GT_OLD_HAWAIIAN_TO_WGS_1984_2  108009 /* Old Hawaiian to WGS 1984 (2 - OHA_A) */
#define PE_GT_OLD_HAWAIIAN_TO_WGS_1984_3  108010 /* Old Hawaiian to WGS 1984 (3 - OHA_B) */
#define PE_GT_OLD_HAWAIIAN_TO_WGS_1984_4  108011 /* Old Hawaiian to WGS 1984 (4 - OHA_C) */
#define PE_GT_OLD_HAWAIIAN_TO_WGS_1984_5  108012 /* Old Hawaiian to WGS 1984 (5 - OHA_D) */

#define PE_GT_JAMAICA_1969_TO_WGS_1984_1  108101 /* Jamaica 1969 to WGS 1984_1*/
#define PE_GT_NTF_PARIS_TO_RGF_1993_1     108102 /* France                    */
#define PE_GT_TOKYO_TO_JGD_2000_1         108103 /* Japan                     */
#define PE_GT_REGVEN_TO_SIRGAS_1            1767 /* Venezuela                 */
#define PE_GT_HJORSEY_1955_TO_WGS_1984      1951 /* Iceland                   */
#define PE_GT_TOKYO_TO_WGS_1984_2001      108106 /* Japan                     */

#define PE_GT_DATUM_73_TO_WGS_1984_1      108110 /* Portugal                  */
#define PE_GT_DATUM_73_TO_WGS_1984_2      108120 /* Portugal                  */
#define PE_GT_ED_1950_TO_WGS_1984_PT3     108111 /* Portugal                  */
#define PE_GT_ED_1950_TO_WGS_1984_PT7     108121 /* Portugal                  */
#define PE_GT_GRACIOSA_1948_TO_WGS_1984_1 108112 /* Faial, Graciosa, Pico,    */
                                                 /*  Sao Jorge, & Terceira    */
                                                 /*  Islands (Azores)         */
#define PE_GT_GRACIOSA_1948_TO_WGS_1984_2 108122 /* Faial, Graciosa, Pico,    */
                                                 /*  Sao Jorge, & Terceira    */
                                                 /*  Islands (Azores)         */

#define PE_GT_LISBOA_BESSEL_TO_WGS_1984_1      108113 /* Portugal             */
#define PE_GT_LISBOA_BESSEL_TO_WGS_1984_2      108123 /* Portugal             */
#define PE_GT_LISBOA_HAYFORD_TO_WGS_1984_1     108114 /* Portugal             */
#define PE_GT_LISBOA_HAYFORD_TO_WGS_1984_2     108124 /* Portugal             */
#define PE_GT_PORTO_SANTO_1936_TO_WGS_1984_1   108115 /* Porto Santo & Madeira Islands */
#define PE_GT_PORTO_SANTO_1936_TO_WGS_1984_2   108125 /* Porto Santo & Madeira Islands */
#define PE_GT_OBSERV_METEOR_1939_TO_WGS_1984_1 108116 /* Corvo & Flores Islands (Azores) */
#define PE_GT_SAO_BRAZ_TO_WGS_1984_1      108117 /* Sao Miguel and Santa      */
                                                 /*  Maria Islands (Azores)   */
#define PE_GT_SAO_BRAZ_TO_WGS_1984_2      108127 /* Sao Miguel and Santa      */
                                                 /*  Maria Islands (Azores)   */

#define PE_GT_NTF_TO_RGF_1993_1           108130 /* France                    */

#define PE_GT_NZGD_1949_TO_NZGD_2000_1      1566 /* New Zealand               */
#define PE_GT_NZGD_1949_TO_NZGD_2000_3PAR   1566 /* New Zealand               */
#define PE_GT_NZGD_1949_TO_NZGD_2000_2      1701 /* New Zealand               */
#define PE_GT_NZGD_1949_TO_NZGD_2000_7PAR   1701 /* New Zealand               */

#define PE_GT_POHNPEI_TO_NAD_1983         108133 /* Pohnpei - Fed. States of Micronesia   */
#define PE_GT_BAB_SOUTH_TO_NAD_1983       108134 /* Bablethuap Island - Republic of Palau */
#define PE_GT_MAJURO_TO_NAD_1983          108135 /* Majuro - Republic of Marshall Islands */

#define PE_GT_GUAM_1963_TO_HARN_MP_ROTA   108137 /* Rota Island  -            */
                                                 /*  Northern Mariana Islands */
#define PE_GT_GUAM_1963_TO_HARN_MP_SAIPAN 108138 /* Saipan Island -           */
                                                 /*  Northern Mariana Islands */
#define PE_GT_GUAM_1963_TO_HARN_MP_TINIAN_AGUIJAN  108139 
                                                 /* Tinian and Aguijan Island */
                                                 /*  Northern Mariana Islands */

#define PE_GT_NGO_1948_TO_WGS_1984          1654 /* Norway                    */

/* -------------------------------------------------------------------------- */
/*                  Transforms by Longitude Rotation Method                   */
/*              Prime Meridians of (non-Greenwich) to Greenwich               */
/* -------------------------------------------------------------------------- */

/* NEW Longitude Rotation based GT's at 9.0 ----------------------- */

#define PE_GT_CARTHAGE_PARIS_TO_CARTHAGE       1881 /* Carthage (Paris) to Carthage */
#define PE_GT_GUNUNG_SEGARA_JAKARTA_TO_GUNUNG_SEGARA  1883 
                                                /* Gunung Segara (Jakarta) to */
                                                /* Gunung Segara              */
#define PE_GT_LISBON_1890_LISBON_TO_LISBON_1890 1991
                                         /* Lisbon 1890 Lisbon to Lisbon 1890 */
#define PE_GT_NORD_SAHARA_1959_PARIS_TO_NORD_SAHARA_1959  1882 
                                               /* Nord Sahara 1959 (Paris) to */
                                               /* Nord Sahara 1959            */
#define PE_GT_S_JTSK_FERRO_TO_S_JTSK           1884 /* S-JTSK (Ferro) to      */
                                                    /* S-JTSK                 */

/* END of NEW Longitude Rotation based GT's at 9.0 ----------------------- */

#define PE_GT_BATAVIA_JAKARTA_TO_BATAVIA       1759 /* Batavia (Jakarta) to   */
                                                    /* Batavia                */
#define PE_GT_BELGE_1950_BRUSSELS_TO_BELGE_1950  1264
                                                    /* Belge 1950(Brussels) to*/
                                                    /* to Belge 1950          */
#define PE_GT_BERN_1898_BERN_TO_BERN_1898      8161 /* Bern 1898 (Bern) to    */
                                                    /* Bern 1898              */
#define PE_GT_BERN_1898_BERN_TO_CH1903         1765 /* Bern 1898 (Bern) to    */
                                                    /* CH1903 (Greenwich)     */
#define PE_GT_BOGOTA_BOGOTA_TO_BOGOTA          1755 /* Bogota (Bogota) to     */
                                                    /* Bogota                 */
#define PE_GT_GREEK_ATHENS_TO_GREEK            1761 /* Greek(Athens) to Greek */
#define PE_GT_LISBON_LISBON_TO_LISBON          1756 /* Lisbon (Lisbon) to     */
                                                    /* Lisbon                 */
#define PE_GT_MAKASSAR_JAKARTA_TO_MAKASSAR     1260 /* Makassar (Jakarta) to  */
                                                    /* Makassar               */
#define PE_GT_MGI_FERRO_TO_MGI                 1757 /* MGI (Ferro) to MGI     */
#define PE_GT_MONTE_MARIO_ROME_TO_MONTE_MARIO  1262 /* Monte Mario (Rome) to  */
                                                    /* Monte Mario            */
#define PE_GT_NGO_1948_OSLO_TO_NGO_1948        1762 /* NGO 1948 (Oslo) to     */
                                                    /* NGO 1948               */
#define PE_GT_NTF_PARIS_TO_NTF                 1764 /* NTF (Paris) to NTF     */
#define PE_GT_PADANG_1884_JAKARTA_TO_PADANG_1884  1758 
                                                    /* Padang 1884(Jakarta) to*/
                                                    /* to Padang 1884         */
#define PE_GT_RT38_STOCKHOLM_TO_RT38           1760 /* RT38 (Stockholm) to    */
                                                    /* RT38                   */
#define PE_GT_TANANARIVE_1925_PARIS_TO_TANANARIVE_1925  1265 
                                                /* Tananarive 1925 (Paris) to */
                                                /* Tananarive 1925            */
#define PE_GT_VOIROL_1875_PARIS_TO_VOIROL_1875 1266 /* Voirol 1875 (Paris) to */
                                                    /* Voirol 1875            */
#define PE_GT_VOIROL_UNIFIE_1960_PARIS_TO_VOIROL_UNIFIE_1960  8171 
                                             /* Voirol Unifie 1960 (Paris) to */
                                             /* Voirol Unifie 1960            */

/* -------------------------------------------------------------------------- */
/*                  Transforms by NADCON/HARN Grid Method                     */
/* -------------------------------------------------------------------------- */

/* NEW NADCON based GT's at 9.0 ----------------------- */

#define PE_GT_PUERTO_RICO_TO_NAD_1983 1461 /* Puerto Rico and US Virgin Islands */

/* END of NEW NADCON based GT's at 9.0 ----------------------- */

/* NAD27 - NAD83 grid-based transformations */

#define PE_GT_NAD_1927_TO_NAD_1983_NADCON   1241 /* NAD27 to NAD83 - CONUS    */
#define PE_GT_NAD_1927_TO_NAD_1983_AK       1243 /* NAD27 to NAD83 - Alaska   */
#define PE_GT_NAD_1927_TO_NAD_1983_PRVI   108003 /* NAD27 to NAD83 -          */
                                                 /*   Puerto Rico-Virgin I.   */
/* Old non-NAD27 - NAD83 grid-based transformations */
#define PE_GT_OLD_HAWAIIAN_TO_NAD_1983      1454 /* Old Hawaiian to NAD83     */
#define PE_GT_ST_GEORGE_TO_NAD_1983         1457 /* St. George I. to NAD83    */
#define PE_GT_ST_LAWRENCE_TO_NAD_1983       1455 /* St. Lawrence I. to NAD83  */
#define PE_GT_ST_PAUL_TO_NAD_1983           1456 /* St. Paul I. to NAD83      */

/* HARN - HPGN grid-based transformations */
#define PE_GT_NAD_1983_TO_HARN_AL    1474 /* Alabama HARN                     */
#define PE_GT_NAD_1983_TO_HARN_AZ    1475 /* Arizona HARN                     */
#define PE_GT_NAD_1983_TO_HARN_AR    1704 /* Arkansas HARN                    */
#define PE_GT_NAD_1983_TO_HARN_CN    1476 /* California North HARN -above 36N */
#define PE_GT_NAD_1983_TO_HARN_CS    1477 /* California South HARN -below 37N */
#define PE_GT_NAD_1983_TO_HARN_CO    1478 /* Colorado HARN                    */
#define PE_GT_NAD_1983_TO_HARN_FL    1480 /* Florida HARN                     */
#define PE_GT_NAD_1983_TO_HARN_GA    1479 /* Georgia HARN                     */
#define PE_GT_NAD_1983_TO_HARN_HI    1520 /* Hawaii HARN                      */
#define PE_GT_NAD_1983_TO_HARN_IA    1705 /* Iowa HARN                        */
#define PE_GT_NAD_1983_TO_HARN_IL    1553 /* Illinois HARN                    */
#define PE_GT_NAD_1983_TO_HARN_IN    1521 /* Indiana HARN                     */
#define PE_GT_NAD_1983_TO_HARN_KS    1522 /* Kansas HARN                      */
#define PE_GT_NAD_1983_TO_HARN_KY    1483 /* Kentucky HARN                    */
#define PE_GT_NAD_1983_TO_HARN_LA    1484 /* Louisiana HARN                   */
#define PE_GT_NAD_1983_TO_HARN_MD    1485 /* Maryland & Delaware HARN         */
#define PE_GT_NAD_1983_TO_HARN_ME    1486 /* Maine HARN                       */
#define PE_GT_NAD_1983_TO_HARN_MI    1487 /* Michigan HARN                    */
#define PE_GT_NAD_1983_TO_HARN_MN    1706 /* Minnesota HARN                   */
#define PE_GT_NAD_1983_TO_HARN_MS    1488 /* Mississippi HARN                 */
#define PE_GT_NAD_1983_TO_HARN_MO    1707 /* Missouri HARN                    */
#define PE_GT_NAD_1983_TO_HARN_EM    1481 /* Montana & Idaho HARN - E of 113W */
#define PE_GT_NAD_1983_TO_HARN_WM    1482 /* Montana & Idaho HARN - W of 113W */
#define PE_GT_NAD_1983_TO_HARN_NB    1489 /* Nebraska HARN                    */
#define PE_GT_NAD_1983_TO_HARN_NV    1523 /* Nevada HARN                      */
#define PE_GT_NAD_1983_TO_HARN_NE    1490 /* New England -CT,MA,NH,RI,VT HARN */
#define PE_GT_NAD_1983_TO_HARN_NJ    1554 /* New Jersey HARN                  */
#define PE_GT_NAD_1983_TO_HARN_NM    1491 /* New Mexico HARN                  */
#define PE_GT_NAD_1983_TO_HARN_NY    1492 /* New York HARN                    */
#define PE_GT_NAD_1983_TO_HARN_ND    1493 /* North Dakota HARN                */
#define PE_GT_NAD_1983_TO_HARN_OH    1524 /* Ohio HARN                        */
#define PE_GT_NAD_1983_TO_HARN_OK    1494 /* Oklahoma HARN                    */
#define PE_GT_NAD_1983_TO_HARN_PV    1495 /* Puerto Rico & Virgin Islnds HARN */
#define PE_GT_NAD_1983_TO_HARN_SD    1496 /* South Dakota HARN                */
#define PE_GT_NAD_1983_TO_HARN_TN    1497 /* Tennessee HARN                   */
#define PE_GT_NAD_1983_TO_HARN_ET    1498 /* Texas HARN - E of 100W           */
#define PE_GT_NAD_1983_TO_HARN_WT    1499 /* Texas HARN - W of 100W           */
#define PE_GT_NAD_1983_TO_HARN_UT    1525 /* Utah HARN                        */
#define PE_GT_NAD_1983_TO_HARN_VA    1500 /* Virginia HARN                    */
#define PE_GT_NAD_1983_TO_HARN_WO    1501 /* Washington & Oregon HARN         */
#define PE_GT_NAD_1983_TO_HARN_WV    1526 /* West Virginia HARN               */
#define PE_GT_NAD_1983_TO_HARN_WI    1502 /* Wisconsin HARN                   */
#define PE_GT_NAD_1983_TO_HARN_WY    1503 /* Wyoming HARN                     */

#define PE_GT_SAMOA_1962_TO_HARN_ES  1579 /* American Samoa 1962 to NAD 1983  */
                                          /*   HARN American Samoa East -     */
                                          /*     Ofu, Olosega, & Ta'u islands */
#define PE_GT_SAMOA_1962_TO_HARN_WS  1578 /* American Samoa 1962 to NAD 1983  */
                                          /*   HARN American Samoa West -     */
                                          /*     Tutuila & Aunu'u islands     */

#define PE_GT_GUAM_1963_TO_HARN_GU 108143 /* Guam 1963 to NAD 1983 HARN Guam  */


/* -------------------------------------------------------------------------- */
/*                       Transforms by NTv2 Grid Method                       */
/* -------------------------------------------------------------------------- */
/* NTv2 method grid-based transformations - various countries and GCS's       */

/* NEW Ntv2 based GT's at 9.0 ----------------------- */

/* Australia */
#define PE_GT_AGD_1966_TO_GDA_1994_11_NTV2           1803 /* Australia nationl*/
#define PE_GT_AGD_1984_TO_GDA_1994_5_NTV2            1804 /* Australia nationl*/

/* New Zealand */
#define PE_GT_NZGD_1949_TO_WGS_1984_3_NTV2           1670 /* New Zealand      */

/* France */
#define PE_GT_RGF_1993_TO_NTF_NTV2                 108470 /* France           */
/* France (New Caledonia) */
#define PE_GT_RGNC_1991_TO_IGN72_GRANDE_TERRE_NTV2 108471 /* New Caledonia    */
#define PE_GT_RGNC_1991_TO_NEA74_NOUMEA_NTV2       108472 /* New Caledonia    */ 

/* END of NEW Ntv2 based GT's at 9.0 ----------------------- */

/* Canada */
#define PE_GT_ATS_1977_TO_NAD_1983_CSRS98_NTV2_NB    1841 /* New Brunswick    */
#define PE_GT_ATS_1977_TO_NAD_1983_CSRS98_2          1846 /* Canada - PEI     */
#define PE_GT_ATS_1977_TO_NAD_1983_CSRS98_NTV2_PEI   1846 /* Prince Edward Is.*/
#define PE_GT_ATS_1977_TO_NAD_1983_CSRS98_NTV2_NS          1850 /* Nova Scotia*/
#define PE_GT_ATS_1977_TO_NAD_1983_CSRS98_NTV2_MARITIMES 108302 /* Maritimes  */

#define PE_GT_NAD_1927_CGQ77_TO_NAD_1983_2           1575 /* Canada - Quebec  */
#define PE_GT_NAD_1927_CGQ77_TO_NAD_1983_CSRS98      1845 /* Canada - Quebec  */
#define PE_GT_NAD_1927_DEF_1976_TO_NAD_1983_NTV2_ONTARIO  1463 /* NAD27 Def76 */
                                                          /* to NAD83 Ontario */
#define PE_GT_NAD_1927_TO_NAD_1983_6                 1573 /* Canada - Quebec  */
#define PE_GT_NAD_1927_TO_NAD_1983_CSRS98_1          1844 /* Canada - Quebec  */
#define PE_GT_NAD_1927_TO_NAD_1983_CSRS98_2          1847 /* Canada - Saskatchewan */
#define PE_GT_NAD_1927_TO_NAD_1983_NTV2_CANADA  1313 /* NAD27 to NAD83 Canada */

#define PE_GT_NAD_1983_TO_NAD_1983_CSRS98_1          1843 /* Canada - Quebec  */
#define PE_GT_NAD_1983_TO_NAD_1983_CSRS98_2          1848 /* Canada - Saskatchewan */
#define PE_GT_NAD_1983_TO_NAD_1983_CSRS98_3          1849 /* Canada - Alberta */


/* Australia AGD66 or AGD84 to GDA94 */
#define PE_GT_AGD_1966_TO_GDA_1994_NTV2_VICTORIA     1464 /* Victoria         */
#define PE_GT_AGD_1966_TO_GDA_1994_NTV2_TASMANIA     1506 /* Tasmania         */
#define PE_GT_AGD_1966_TO_GDA_1994_NTV2_NORTH_TERR   1507 /* Northern Territory */
#define PE_GT_AGD_1984_TO_GDA_1994_NTV2_QUEENSLAND 108453 /* Queensland       */
#define PE_GT_AGD_1984_TO_GDA_1994_3                 1559 /* Western Australia*/
#define PE_GT_AGD_1984_TO_GDA_1994_4                 1593 /* Western Australia*/
#define PE_GT_AGD_1984_TO_GDA_1994_NTV2_WESTERN      1593 /* Western Australia*/
#define PE_GT_AGD_1966_TO_GDA_1994_10                1596 /* New South Wales, */
                                                          /*  Victoria, & ACT */
#define PE_GT_AGD_1966_TO_GDA_1994_NTV2_SOUTHEAST    1596 /* New South Wales, */
                                                          /*  Victoria, & ACT */

/* New Zealand */
#define PE_GT_NZGD_1949_TO_NZGD_2000_3               1568 /* New Zealand      */
#define PE_GT_NZGD_1949_TO_NZGD_2000_NTV2            1568 /* New Zealand      */


/*----------------------------------------------------------------------------*/
/* Symbolic names for array sph[] indexes:                                    */
/*----------------------------------------------------------------------------*/
#define PE_SPH_A   0 /* Semimajor axis                                        */
#define PE_SPH_E2  1 /* Eccentricity squared                                  */

/*----------------------------------------------------------------------------*/
/* Symbolic names for array parm[] indexes:                                   */
/*    Projections                                                             */
/*----------------------------------------------------------------------------*/
#define PE_PARM_X0      0 /* False easting                                    */
#define PE_PARM_Y0      1 /* False northing                                   */

#define PE_PARM_LAM0    2 /* Central meridian, Longitude of origin            */
#define PE_PARM_LON0    2 /* = PE_PARM_LAM0                                   */
#define PE_PARM_PHI0    6 /* Central parallel, Latitude of origin             */
#define PE_PARM_LAT0    6 /* = PE_PARM_PHI0                                   */

#define PE_PARM_PHI1    3 /* Standard parallel 1, Latitude of 1st point       */
#define PE_PARM_LAT1    3 /* = PE_PARM_PHI1                                   */
#define PE_PARM_LAM1    8 /* Longitude of 1st point                           */
#define PE_PARM_LON1    8 /* = PE_PARM_LAM1                                   */

#define PE_PARM_PHI2    4 /* Standard parallel 2, Latitude of 2nd point       */
#define PE_PARM_LAT2    4 /* = PE_PARM_PHI2                                   */
#define PE_PARM_LAM2    9 /* Longitude of 2nd point                           */
#define PE_PARM_LON2    9 /* = PE_PARM_LAM2                                   */

#define PE_PARM_LAMC   10 /* Longitude of Center                              */
#define PE_PARM_LONC   10 /*  == PE_PARM_LAMC                                 */
#define PE_PARM_PHIC   11 /* Latitude of Center                               */
#define PE_PARM_LATC   11 /*  == PE_PARM_PHIC                                 */

#define PE_PARM_K0      5 /* Scale factor                                     */
#define PE_PARM_ALPHA   7 /* Azimuth                                          */
#define PE_PARM_HEIGHT 15 /* Height                                           */

#define PE_PARM_XS     12 /* X Scale                                          */
#define PE_PARM_YS     13 /* Y Scale                                          */
#define PE_PARM_XYR    14 /* XY Plane Rotation                                */

#define PE_PARM_OPTION 15 /* Option                                           */

/*----------------------------------------------------------------------------*/
/* Symbolic names for array coord[] indexes:                                  */
/*----------------------------------------------------------------------------*/
#define PE_COORD_LAM   0 /* Longitude                                         */
#define PE_COORD_LON   0 /* = PE_COORD_LAM                                    */

#define PE_COORD_PHI   1 /* Latitude                                          */
#define PE_COORD_LAT   1 /* = PE_COORD_PHI                                    */

#define PE_COORD_X     0 /* X-coordinate                                      */
#define PE_COORD_Y     1 /* Y-coordinate                                      */

#define PE_COORD_H     2 /* Height                                            */

/*----------------------------------------------------------------------------*/
/* Symbolic names for array parm[] indexes:                                   */
/*   Geographic Transforms                                                    */
/*----------------------------------------------------------------------------*/
#define PE_PARM_DX  0 /* X-axis translation                                   */
#define PE_PARM_DY  1 /* Y-axis translation                                   */
#define PE_PARM_DZ  2 /* Z-axis translation                                   */
#define PE_PARM_RX  3 /* X-axis rotation                                      */
#define PE_PARM_RY  4 /* Y-axis rotation                                      */
#define PE_PARM_RZ  5 /* Z-axis rotation                                      */
#define PE_PARM_DS  6 /* Scale difference                                     */
#define PE_PARM_XCR 7 /* X coord of Rotation Origin                           */
#define PE_PARM_YCR 8 /* Y coord of Rotation Origin                           */
#define PE_PARM_ZCR 9 /* Z coord of Rotation Origin                           */
#define PE_PARM_ND 15 /* Name of Dataset for Grid based Geog transforms       */

/*----------------------------------------------------------------------------*/

#define PE_EPS   3.55271367880050092935562E-15  /* 2^(-48) */
#define PE_EPSS  0.000000059604644775390625     /* 2^(-24) */
#define PE_PI    3.14159265358979323846264
#define PE_PI2   1.57079632679489661923132
#define PE_PI4   0.785398163397448309615661

#define PE_SPHERE(e2) ((e2) < PE_EPS)
#define PE_ABS(a)     (((a) < 0) ? -(a) : (a))
#define PE_SGN(a,b)   (((b) >= 0) ? PE_ABS(a) : -PE_ABS(a))
#define PE_EQ(a,b)    (PE_ABS((a)-(b)) <= PE_EPS*(1+(PE_ABS(a)+PE_ABS(b))/2))
#define PE_ZERO(a)    (PE_ABS(a) <= PE_EPS)

/*----------------------------------------------------------------------------*/
/* Symbolic names for kinds of a horizon:                                     */
/*----------------------------------------------------------------------------*/
#define PE_HORIZON_RECT  0
#define PE_HORIZON_POLY  1
#define PE_HORIZON_LINE  2
#define PE_HORIZON_POINT 3

#define PE_HORIZON_DELTA  0.0000002  /* radians - about 1.2 meters along      */
                                     /*           the equator                 */

#endif
