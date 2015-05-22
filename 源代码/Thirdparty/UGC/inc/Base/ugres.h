#ifndef UGRES_H
#define UGRES_H



// 基础信息: 从 10000 开始编号
#define	UGS_COMPANY                             10000	/*! 北京超图地理信息技术有限公司*/
#define	UGS_UGC_VERSION                         10001	/*! SuperMap UGC 2.0*/
#define	UGS_CLASSLIB_NAME                       10002	/*! SuperMap 跨平台核心类库 (UGC)*/
#define	UGS_COPYRIGHT                           10003	/*! 版权所有(C) 2005-2007 北京超图地理信息技术有限公司，保留所有权利\n"*/
#define	UGS_CURRENT_TIME                        10004	/*! %Y年%m月%d日  %H时%M分%S秒*/
#define	UGS_NEED_HIGHER_VERSION                 10005	/*! 需要更高的版本*/
#define	UGS_ERROR_CODE                          10006	/*! SuperMap UGC类库错误代码: %d。*/
#define	UGS_WORK_ENVIRONMENT_INFO               10007	/*! 用户: %s 计算机: %s 时间: %s 操作系统: %s 硬件环境: %s 语言环境: %s 可用物理内存: %dkb 可用页面文件或虚拟内存: %dkb */
#define	UGS_SM_REGISTER_RUNTIME_PLEASE          10008	/*! 警告：您的运行版本没有注册 请调用 %s注册运行版*/


// 一般性错误处理信息：从11000开始编码
#define	UGS_INVALID_DT                          11000	/*! 非法数据集*/
#define	UGS_PARAMETERS_HAVE_NULL_POINTER        11001	/*! 传进来的参数里有空指针*/
#define	UGS_DATASOURCE_POINTER_NULL             11002	/*! 数据源指针为空*/
#define	UGS_DATASET_POINTER_NULL                11003	/*! 数据集指针为空*/
#define	UGS_INVALID_STARTNODE_EQUAL_ENDNODE_ANALYSE_FAILED 11004	/*! 起始点与终止点是同一个点，传入ID(%d)非法，分析失败*/
#define	UGS_INVALID_NUMBER                      11005	/*! 非法的整型数据*/
#define	UGS_FILE_POINTER_NULL                   11006	/*! 文件指针为空！*/
#define	UGS_GRAVENESS_DATA_ERROR                11007	/*! 严重数据错误*/
#define	UGS_LINE_DATASET_POINTER_IS_NULL        11008	/*! 线数据集指针为空*/
#define	UGS_REGION_DATASET_POINTER_IS_NULL      11009	/*! 面数据集指针为空*/
#define	UGS_CURRENT_DS_NOT_EXIST                11010	/*! 当前数据源不存在*/
#define	UGS_LAYER_POINTER_NULL                  11011	/*! 层信息指针为空*/
#define	UGS_SYMBOL_INVALID_SYM                  11012	/*! 非法符号*/
#define	UGS_SYMBOL_INVALID_STROKE               11013	/*! 非法符号笔划*/
#define	UGS_SYMBOL_INVALID_RECT                 11014	/*! 非法矩形*/
#define	UGS_SYMBOL_INVALID_TEXT                 11015	/*! 非法字串*/
#define	UGS_SCALE_TYPE_INVALID                  11016	/*! 比例尺类型非法*/
#define	UGS_INVALID_SMOOTH_DEGREE               11017	/*! 非法的光滑度参数，光滑度值只能是0到5之间的数。*/
#define	UGS_INVALID_EXPRESSION                  11018	/*! 非法的表达式*/
#define	UGS_SLMSG_THEME_UNIQUE_KEYTYPE_INVALID  11019	/*! 非法的单值专题图键值*/
#define	UGS_SLMSG_THEME_RANGE_KEYTYPE_INVALID   11020	/*! 非法的范围分段专题图键值*/
#define	UGS_NULL_POINTER                        11021	/*! 指针为空*/
#define	UGS_INVALID_VALUE                       11022	/*! 非法值*/
#define	UGS_MEMMORY_NOT_ENOUGH                  11023	/*! 内存不足，请关闭程序，释放内存后再试*/
#define	UGS_MEMMORY_ALLOC_FAILED                11024	/*! 内存分配失败*/
#define	UGS_BUILDING_SPATIAL_INDEX              11025	/*! 正在建立索引......*/
#define	UGS_PREPARING                           11026	/*! 正在准备...*/


// 风格信息：从13000开始编码
#define	UGS_BIT_SYMBOL_DATA_IS_NULL             13000	/*! 位图符号的数据为空*/
#define	UGS_READ_BIT_INFO_ERROR                 13001	/*! 读取位图信息不正确*/
#define	UGS_READ_BIT_DATA_POINTER_IS_NULL       13002	/*! 读取位图数据指针为空*/
#define	UGS_READ_BIT_DIB_DATA_FAILED            13003	/*! 读取位图DIB数据失败*/
#define	UGS_BIT_IS_NULL_WHEN_SAVE               13004	/*! 保存时，位图数据为空*/
#define	UGS_BIT_IS_NULL_WHEN_GET_BIT_BYTE_COUNT 13005	/*! 获取保存位图字节数时位图数据为空*/
#define	UGS_BIT_IS_NULL_WHEN_IMPORT_BIT         13006	/*! 导入位图数据时位图数据为空*/
#define	UGS_BITMAP_BIT_IS_NULL                  13007	/*! 位图比特数据为空*/
#define	UGS_STREAMINFO_IS_NULL_WHEN_READ_BIT    13008	/*! 读取位图数据时流信息为空*/
#define	UGS_CANNOT_FIND_THE_VERSION_WHEN_READ_BIT 13009	/*! 读取位图数据时找不到对应的版本*/
#define	UGS_NOT_SUPPORT_LOW_VERSION_WHEN_SAVE_BIT 13010	/*! 保存位图数据时不支持其他低版本*/
#define	UGS_BIT_IS_NULL_WHEN_DRAW_BIT           13011	/*! 绘制位图时位图数据为空*/
#define	UGS_CREATE_BRUSH_FAILED                 13012	/*! 创建画刷失败*/
#define	UGS_GET_INFO_IS_NULL                    13013	/*! 获取信息为空*/
#define	UGS_GET_BACKGRAPHIC_FAILED              13014	/*! 创建背景画布失败*/
#define	UGS_CREATE_TRANSGRAPHIC_FAILED          13015	/*! 创建半透明画布失败*/
#define	UGS_BACK_IMAGE_DATA_INVALID             13016	/*! 背景Image数据不合法*/
#define	UGS_TRANSIMAGE_INVALID                  13017	/*! 透明Image数据不合法*/
#define	UGS_GRADIENT_RECTANGLE_IS_NULL          13018	/*! 渐变矩形为空*/
#define	UGS_TRANS_HEIGHT_OR_WIDTH_IS_ZERO       13019	/*! 半透明高度或宽度为零*/
#define	UGS_CREATE_BACKGRAPHICS_FAILED_WHEN_TRANS 13020	/*! 半透明效果时，创建背景画布失败*/
#define	UGS_CREATE_BACKIMAGE_FAILED_WHEN_TRANS  13021	/*! 半透明效果时创建背景Image失败*/
#define	UGS_BIT_DATA_INVLAID                    13022	/*! 位图数据不合法*/
#define	UGS_BACKIMAGE_INVLAID                   13023	/*! 背景Image不合法*/
#define	UGS_CLIP_REGION_IS_NULL                 13024	/*! 裁剪区域为空*/
#define	UGS_CREATE_CLIP_REGION_FAILED           13025	/*! 创建裁剪区域失败*/
#define	UGS_CLIP_RECTANGLE_IS_NULL              13026	/*! 裁剪区域矩形为空*/
#define	UGS_RECTANGLE_IS_NULL                   13027	/*! 矩形为空*/
#define	UGS_RECTANGLE_HEIGHT_OR_WIDTH_LESSTHAN_TWO 13028	/*! 矩形的宽度或者高度小于2*/
#define	UGS_CREATE_MEMGRAPHIC_FAILED            13029	/*! 创建内存画布失败*/
#define	UGS_CREATE_IMAGE_FAILED                 13030	/*! 创建Image失败*/
#define	UGS_FILLSYMPARAM_CREATE_IMAGE_FAILED    13031	/*! 绘制参数创建Image失败*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_READ_FILLSYMBOL 13032	/*! 读取填充符号时字节流为空*/
#define	UGS_READ_FILLSYMBOL_FAILED              13033	/*! 读取填充符号失败*/
#define	UGS_CANNOT_FIND_THE_FILLSYMBOL_VERSION  13034	/*! 找不到对应填充符号的版本*/
#define	UGS_FILLSYMBOL_SUBSYMBOL_COUNT_IS_ZERO  13035	/*! 填充符号子符号个数为零*/
#define	UGS_CANNOT_FIND_THE_FILLSYMBOL_VERSION_WHEN_SAVE 13036	/*! 保存填充符号时找不到对应的版本*/
#define	UGS_DRAW_POLYGON_BOUND_RECTANGLE_IS_NULL_WHEN_DRAW_FILLSYM 13037	/*! 填充符号时绘制的多边形外界矩形为空*/
#define	UGS_GET_FILLSYMPARAM_RECTANGLE_IS_NULL  13038	/*! 获取填充参数矩形为空*/
#define	UGS_GET_FILLSYMBOL_SUBLAYER_INDEX_INVLAID 13039	/*! 获取填充符号子层的索引不合法*/
#define	UGS_GET_FILLSYMBOL_SUBSYMBOL_INDEX_INVLAID 13040	/*! 获取填充符号的子符号索引不合法*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_FILLSYMBOL_READ_BIT_INFO 13041	/*! 填充符号读取位图信息时字节流为空*/
#define	UGS_READ_SUBRASTER_SYMBOL_FAILED        13042	/*! 读取子栅格符号失败*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_READ_FILLSYMBOL_POINT 13043	/*! 读取填充符号点符号时字节流为空*/
#define	UGS_READ_FILLSYM_SUBPOINT_FAILED        13044	/*! 读取填充符号子点符号失败*/
#define	UGS_BIT_IS_NULL_WHEN_GET_BIT_SIZE       13045	/*! 获取位图大小时位图数据为空*/
#define	UGS_BIT_IS_NULL_WHEN_FILLSYM_SAVE_BIT   13046	/*! 填充符号保存位图数据时位图数据为空*/
#define	UGS_CREATE_GRAPHICS_FAILED              13047	/*! 创建画布失败*/
#define	UGS_FILLSYMBOL_IS_NULL                  13048	/*! 填充位图数据为空*/
#define	UGS_FILLSYMBOL_REMOVE_SUBLAYER_FAILED   13049	/*! 填充符号移除子层失败*/
#define	UGS_READ_BIT_FAILED                     13050	/*! 读取位图数据失败*/
#define	UGS_BIT_IS_NULL                         13051	/*! 位图数据为空*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_READ_BIT   13052	/*! 读取位图数据时字节流为空*/
#define	UGS_READ_SUBFILLSYM_POINT_FAILED        13053	/*! 读取子填充符号的点符号时失败*/
#define	UGS_BIT_IS_NULL_WHEN_GET_SUBSYMBOL_BIT_SIZE 13054	/*! 获取子符号位图大小时数据为空*/
#define	UGS_BIT_IS_NULL_WHEN_SAVE_BIT           13055	/*! 保存位图数据时数据为空*/
#define	UGS_BIT_HEIGHT_OR_WIDTH_IS_ZERO         13056	/*! 位图数据高度或者宽度为零*/
#define	UGS_BIT_RECTANGLE_SIZE_INVALID          13057	/*! 位图矩形的大小不合法*/
#define	UGS_CREATE_GRAPHICS_INVALID             13058	/*! 创建内存画布不合法*/
#define	UGS_ROMANCE_POINT_SYMBOL_NOT_FIND_OPPOSITE_SYMBOL_TYPE 13059	/*! 渲染点符号时没有找到对应的符号类型*/
#define	UGS_BYTE_STREAM_INFO_IS_NULL_WHEN_READ_FILLLIB 13060	/*! 读取填充库时字节流信息为空*/
#define	UGS_BYTE_STREAM_IS_NULL_WHEN_FILLLIB_APPEND_INFO 13061	/*! 填充库中追加信息时字节流为空*/
#define	UGS_TEMPORARY_FILLLIB_APPEND_FAILED     13062	/*! 临时填充库追加失败*/
#define	UGS_FILLLIB_ADD_FAILED                  13063	/*! 填充库添加失败*/
#define	UGS_READ_ICON_CANNOT_FIND_FIT_VERSION   13064	/*! Icon符号读取找不到合适版本*/
#define	UGS_SAVE_ICON_CANNOT_FIND_FIT_VERSION   13065	/*! 保存Icon找不到对应版本*/
#define	UGS_READ_ICON_FAILED                    13066	/*! 读取Icon数据失败*/
#define	UGS_SAVE_ICON_FAILED                    13067	/*! 保存Icon数据失败*/
#define	UGS_SAVE_BYTE_LENGTH_LESSTHAN_ZERO      13068	/*! 保存的字节长度小于0*/
#define	UGS_ICON_IS_NULL                        13069	/*! Icon数据为空*/
#define	UGS_ICON_IDRESERVED_NOT_ZERO            13070	/*! 读取Icon中字段idReserved不为0*/
#define	UGS_ICON_IDTYPE_NOT_ONE                 13071	/*! 读取Icon中字段idType不为1*/
#define	UGS_ICON_IDCOUNT_LESSTHAN_ZERO          13072	/*! 读取Icon中的idCount小于0*/
#define	UGS_ICON_INFO_IS_NULL                   13073	/*! 读取Icon信息数据为空*/
#define	UGS_ICON_BYTE_IS_NULL                   13074	/*! 读取Icon比特数据为空*/
#define	UGS_SAVE_ICON_IS_NULL                   13075	/*! 保存Icon数据为空*/
#define	UGS_DRAW_ICON_IS_NULL                   13076	/*! 绘制Icon时数据为空*/
#define	UGS_READ_LINESYMBOL_SUBLINE_CANNOT_FIND_OPPOSITE_VERSION 13077	/*! 读取线符号子线时找不到对应的版本*/
#define	UGS_SAVE_LINESYMBOL_SUBLINE_CANNOT_FIND_OPPOSITE_VERSION 13078	/*! 保存线性符号子符号时找不到对应版本*/
#define	UGS_CANNOT_FIND_OPPOSITE_VERSION_WHEN_READ_LINESYMBOL 13079	/*! 线型符号读取找不到对应版本*/
#define	UGS_READ_LINE_SYMBOL_EXTEND_FAILED      13080	/*! 线型符号扩展读取失败*/
#define	UGS_READ_SUBLINE_SYMBOL_FAILED          13081	/*! 子线读取失败*/
#define	UGS_SAVE_EXTEND_SYMBOL_FAILED_WHEN_SAVE_SYMBOL 13082	/*! 线符号保存时扩展符号保存失败*/
#define	UGS_REMOVE_INDEX_INVALID_WHEN_REMOVE_SUB_LINE_SYMBOL 13083	/*! 移除子线时所要移除的索引不合法*/
#define	UGS_SAVE_D_SUBLINE_FAILED               13084	/*! 第%d个子线保存失败*/
#define	UGS_POINT_COUNT_LESSTHAN_TWO            13085	/*! 点个数小于2*/
#define	UGS_MOVING_INDEX_OR_MOVEING_TO_INDEX_INVALID_WHEN_MOVING_SUBLINE 13086	/*! 移动子线符号时，移动的索引或移动到的索引不合法*/
#define	UGS_MOVING_INDEX_INVALID_WHEN_SUBLINE_MOVE_TO_BOTTOM 13087	/*! 子线移动到底部时，要移动的子线索引不合法*/
#define	UGS_MOVING_SUBLINE_INVALID_WHEN_MOVING_SUBLINE_UP 13088	/*! 子线上移时，要移动的子线不合法*/
#define	UGS_MOVING_SUBLINE_INDEX_INVALID_WHEN_MOVING_TOP 13089	/*! 子线移到顶部时，要移动的子线索引不合法*/
#define	UGS_READ_SUBLINE_NOT_FIND_FIT_VERSION   13090	/*! 子线读取找不到合适的版本*/
#define	UGS_SAVE_SUBLINE_NOT_SUPPORT_LOW_VERSION 13091	/*! 子线保存不支持低版本*/
#define	UGS_SAVE_SUBLINE_FAILED                 13092	/*! 子线数据保存失败*/
#define	UGS_COMPUTE_PARALLEL_LINE_INTERVAL_FAILED_FOR_INTERVAL_IS_ZERO 13093	/*! 计算平行线间距时，间距为零失败*/
#define	UGS_POINT_COUNT_LESSTHAN_TWO_OR_POINTER_IS_NULL_WHEN_DRAW_POLYLINE 13094	/*! 绘制Polyline时，点个数小于2或者点指针为空*/
#define	UGS_JUST_FINISH_DRAWING_WHOLE_POLYLINE_ 13095	/*! 刚好结束整个折线的绘制*/
#define	UGS_ARRIVE_POLYLINE_END_WHOLE_POLYLINE_DRAWING_FINISH 13096	/*! 已经到达整条折线的最后了，整条折线绘制完毕了*/
#define	UGS_JUDEGE_FIRST_WHETHER_JUST_FINISH_DRAWING_WHOLE_POLYLINE 13097	/*! 先判断一下是否刚好结束整个折线的绘制*/
#define	UGS_DRWING_STARTPOINT_AND_ENDPOINT_IS_THE_SAME_POINT 13098	/*! 绘制线时起点和终点一致*/
#define	UGS_SOLID_PART_IS_ZERO                  13099	/*! 绘制线的实部分为零*/
#define	UGS_CALCULATE_GRADIENT_LINE_POINT_POINTER_IS_NULL_OR_COUNT_LESSTHAN_TWO 13100	/*! 计算渐变线时，点指针为空或者点个数小于2、起始终止点的宽度小于0*/
#define	UGS_GRADIENT_INTERVAL_IS_ZERO           13101	/*! 渐变线的间距为零*/
#define	UGS_DRAWING_GRADIENT_LINE_POINT_COUNT_IS_ZERO 13102	/*! 绘制渐变线时，绘制的点的个数为零*/
#define	UGS_LINE_EXTENT_COUNT_MORETHAN_FIVE     13103	/*! 线性扩展个数大于5*/
#define	UGS_READ_LINEEXTENT_NOT_FIND_OPPOSITE_VERSION 13104	/*! 扩展线型读取时找不到对应的版本*/
#define	UGS_SAVE_LINE_EXTENT_NOT_SUPPORT_LOW_VERSION 13105	/*! 线型扩展保存时不支持低版本*/
#define	UGS_NO_TOKEN_INFO                       13106	/*! 没有Token信息*/
#define	UGS_INDEX_OVERTOP_WHEN_GET_SYMBOLEXTENT_INDEX 13107	/*! 获取扩展符号的索引时，索引越界*/
#define	UGS_INDEX_OVERTOP_WHEN_REMOVE_EXTENTSYMBOL 13108	/*! 移除扩展符号时索引越界*/
#define	UGS_CREATING_PEN_SAMEAS_CURRENT_PEN_NEEDNOT_CREATE 13109	/*! 创建画笔时和当前的相同，不需要再创建了*/
#define	UGS_CREATING_BRUSH_COLOR_SAMEAS_CURRENT_BRUSH_NEEDNOT_CREATE 13110	/*! 创建画刷时，和当前的画刷颜色相同，不需要再创建*/
#define	UGS_NEEDNOT_CREATE_BRUSH                13111	/*! 不需要创建画刷*/
#define	UGS_POINT_INFO_INVALID_WHEN_DRAW_EXTENTLINE 13112	/*! 绘制扩展线型时，点信息不合法*/
#define	UGS_CANNOT_FIND_EXTERIOR_SYMBOL_WHEN_EXTENTLINE_USE_DEFINE_SYMBOL 13113	/*! 扩展线型使用自定义符号时，找不到外部符号库*/
#define	UGS_FILLSYMBOL_READ_BYTESTREAM_IS_NULL  13114	/*! 填充符号读取字节流为空*/
#define	UGS_IAMGE_SIZE_OVERTOP_WHEN_FILLSYMBOL_ROMANCE 13115	/*! 填充符号渲染时图像大小越界*/
#define	UGS_FILLSYMBOL_CANNOT_FIND_OPPOSITE_POINT_INFO 13116	/*! 填充符号找不到对应的点符号信息*/
#define	UGS_CREATE_MEMORY_GRAPHICS_FAILED_WHEN_FILLSYMBOL_ROMANCE 13117	/*! 填充符号渲染时创建内存画布失败*/
#define	UGS_CREATE_IMAGE_INVALID_WHEN_FILLSYMBOL_ROMANCE 13118	/*! 填充符号渲染时创建Image不合法*/
#define	UGS_POINT_READ_SYMSTROKE_CANNOT_FIND_THE_OPPOSITE_VERSION 13119	/*! 点符号笔划读取找不到对应的版本*/
#define	UGS_POINT_STROKE_SAVE_NOT_SUPPORT_LOW_VERSION 13120	/*! 点符号笔划保存不支持低版本*/
#define	UGS_NOT_FIND_POINT_STROKE_OPPOSITE_TYPE 13121	/*! 找不到点符号笔划的对应的类型*/
#define	UGS_SAVE_POINT_STROKE_FAILED            13122	/*! 保存点符号笔划失败*/
#define	UGS_READ_ICON_STROKE_FAILED             13123	/*! 读取Icon笔划失败*/
#define	UGS_CANNOT_FIND_OPPOSITE_STROKE_WHEN_READ_STROKE 13124	/*! 读取笔划时找不到对应的笔划类型*/
#define	UGS_POINT_COUNT_LESSTHAN_THREE_WHEN_READ_POLYGON_STROKE 13125	/*! 读取多边形类型笔划时点个数小于3*/
#define	UGS_READ_BIT_STROKE_FAILED              13126	/*! 读取位图笔划时失败*/
#define	UGS_SAVE_STROKE_NOT_SUPPORT_LOW_VERISON 13127	/*! 保存笔划不支持低版本*/
#define	UGS_CONSTRUCT_ARC_POINT_POINTER_IS_NULL 13128	/*! 构建弧段点指针为空*/
#define	UGS_TEXT_IS_NULL_WHEN_CONSTRUCT_POINT_STROKE 13129	/*! 点笔划构建时文本为空*/
#define	UGS_NOT_FIND_OPPOSITE_VERSION_WHEN_READ_POINT 13130	/*! 读取点符号时找不到对应的版本*/
#define	UGS_NOT_SUPPORT_LOW_VERSION_WHEN_SAVE_POINT 13131	/*! 保存点符号时不支持低版本*/
#define	UGS_POINT_SAVE_D_STROKE_FAILED          13132	/*! 点符号第%d个笔划保存失败*/
#define	UGS_DRAWING_PARAM_DISPLAY_BOUND_LESSTHAN_ZERO_WHEN_DRAWING_POINT 13133	/*! 点符号绘制时绘制参数显示范围小于0*/
#define	UGS_MERGE_FAILED_FOR_MERGE_SYMBOL_IS_NULL 13134	/*! 合并符号为空，合并失败*/
#define	UGS_INDEX_D_INVALID_WHEN_REMOVE_POINT   13135	/*! 点符号移除时,索引%d不合法*/
#define	UGS_READ_POINT_SYMLIB_FAILED_FOR_MARKER_ERROR 13136	/*! 点符号库读取时标志有错，读取失败*/
#define	UGS_READ_D_SYMBOL_FAILED                13137	/*! 第%d个符号读取失败*/
#define	UGS_POINT_LIB_SAVE_NOT_SUPPORT_THIS_VERSION 13138	/*! 点符号库保存不支持此版本*/
#define	UGS_POINT_LIB_D_SYMBOL_SAVE_FAILED      13139	/*! 点符号库中第%d个符号保存失败*/
#define	UGS_SYMBOL_LIB_NOT_FIND_OPPOSITE_NAME_SUBGROUP 13140	/*! 符号库没有找到对应名字的子组*/
#define	UGS_CREATE_FAILED_FOR_SAME_NAME_SUBGROUP_ALREADY_EXSIT 13141	/*! 已经存在此名字的子组，创建失败*/
#define	UGS_SET_OBJECT_ID_INDEX_OVERLOP         13142	/*! 设置对象ID的索引越界*/
#define	UGS_SET_ID_SAME_AS_SELF_ID              13143	/*! 设置的ID与自身ID相等，不用改了*/
#define	UGS_SET_ID_FAILED                       13144	/*! 设置ID失败*/
#define	UGS_NOT_FIND_THE_OPPOSITE_ID_INDEX      13145	/*! 没有找到对应ID的索引*/
#define	UGS_REMOVE_APPOINTED_ID_SYMBOL_FAILED   13146	/*! 移除指定ID的符号失败*/
#define	UGS_REMOVE_APPOINTED_INDEX_AND_DELETE_SYMBOL_FAILED 13147	/*! 移除指定索引ID并删除符号的操作失败*/
#define	UGS_REMOVE_GROUP_APPOINTED_INDEX_SUBGROUP_INDEX_OVERLOP 13148	/*! 移除本组指定索引的子组时，索引越界*/
#define	UGS_MOVE_FROM_TO_SELFGROUP_FAILED       13149	/*! 用户正在从本组中移动到本组中，操作失败*/
#define	UGS_NOT_EXIST_NEED_MOVE_SYMBOL_ID       13150	/*! 不存在此时要所要移动符号的ID*/
#define	UGS_IN_SELFGROUP_AND_SUBGROUP_THIS_ID_NOT_EXIST 13151	/*! 在本组及其子组中不存在此ID*/
#define	UGS_IN_SELFGROUP_AND_SUBGROUP_NOT_FIND_THE_OPPOSITE_NAME_GROUP 13152	/*! 在本组及其子组下面没有找到对应名称的组*/
#define	UGS_SYMBOL_WITH_THIS_ID_NOT_EXIST       13153	/*! 不存在此ID对应的符号*/
#define	UGS_CURRENT_GROUP_EXIST_SYMBOL_WITH_THIS_ID 13154	/*! 当前Group中存在此ID的符号*/
#define	UGS_INDEX_OVERLOP_WHEN_SEARCH_SYMBOL_NAME 13155	/*! 查找符号名称时其实索引越界*/
#define	UGS_SEARCHING_SYMLIB_NOT_HAVE_INDEX_WITH_OPPOSITE_NAME 13156	/*! 查找符号库中没有找到对应名称的索引*/
#define	UGS_SYMLIB_SYMBOL_COUNT_LESSTHAN_ZERO   13157	/*! 符号库中符号总数小于0*/
#define	UGS_NOT_FIND_SYMBOL_WITH_THE_NAME_WHEN_REVERSE_SEARCH 13158	/*! 反向查找时没有找到对应名称的符号*/
#define	UGS_OVERLOP_WHEN_REMOVE_THE_SYMBOL_INDEX 13159	/*! 移除指定符号的索引越界*/
#define	UGS_NOT_FIND_INDEX_WITH_THE_ID_WHEN_REMOVING 13160	/*! 移除符号时，指定索引的符号没有找到*/
#define	UGS_INDEX_OVERLOP_WHEN_GET_THE_SYMBOL   13161	/*! 获取符号库中符号时，索引越界*/
#define	UGS_APPOINT_ID_NOT_EXIST_IN_SYMLIB      13162	/*! 指定ID在符号库中不存在*/
#define	UGS_SYMBOL_WITH_APPOINT_ID_NOT_EXIST_IN_SYMLIB 13163	/*! 指定ID在符号库中找不到符号*/
#define	UGS_INDEX_OVERLOP_WHEN_SET_ID_IN_SYMLIB 13164	/*! 符号库中设置ID时，索引越界*/
#define	UGS_SET_ID_REPEAT                       13165	/*! 设置的新ID重复*/
#define	UGS_SYMBOL_FOUND_IN_SYMLIB_IS_NULL      13166	/*! 符号库中所找到的符号为空*/
#define	UGS_INDEX_OVERLOP_WHEN_SEARCH_NAME_IN_SYMLIB 13167	/*! 符号库中查找名称时，索引越界*/
#define	UGS_CANNOT_FIND_SYMBOL_WITH_OPPOSITE_INDEX 13168	/*! 找不到对应索引的符号*/
#define	UGS_INDEX_OVERLOP_WHEN_SYMLIB_SET_SYMBOL_NAME 13169	/*! 符号库中设置符号名称时，指定索引越界*/
#define	UGS_INDEX_OVERLOP_WHEN_SWAP             13170	/*! 符号库中符号交换时索引越界*/
#define	UGS_UNKNOWN_SYMBOL_VERSION              13171	/*! 不识别的符号版本*/
#define	UGS_SYMBOL_TRUETYPE                     13172	/*! 导入TrueType符号*/
#define	UGS_INPUT_METAFILE                      13173	/*! 从交换文件调入符号库*/
#define	UGS_LSL_MSG_LINE_NUMBER_NOTE            13174	/*! 线型的编号必须大于6！*/


// 地图单位信息：从14000开始编码
#define	UGS_SYMBOL_DEGREE                       14000	/*! °	*/
#define	UGS_SYMBOL_MINUTE                       14001	/*! ˊ*/
#define	UGS_MILIMETER                           14002	/*! 毫米*/
#define	UGS_CENTIMETER                          14003	/*! 厘米*/
#define	UGS_DECIMETER                           14004	/*! 分米*/
#define	UGS_METER                               14005	/*! 米*/
#define	UGS_KILOMETER                           14006	/*! 千米*/
#define	UGS_MILE                                14007	/*! 英里*/
#define	UGS_INCH                                14008	/*! 英寸*/
#define	UGS_YARD                                14009	/*! 码*/
#define	UGS_FOOT                                14010	/*! 英尺*/
#define	UGS_DEGREE                              14011	/*! 度*/
#define	UGS_MINUTE                              14012	/*! 分*/
#define	UGS_SECOND                              14013	/*! 秒*/
#define	UGS_SQ_MILIMETER                        14014	/*! 平方毫米*/
#define	UGS_SQ_CENTIMETER                       14015	/*! 平方厘米*/
#define	UGS_SQ_DECIMETER                        14016	/*! 平方分米*/
#define	UGS_SQ_METER                            14017	/*! 平方米*/
#define	UGS_SQ_KILOMETER                        14018	/*! 平方公里*/
#define	UGS_SQ_MILE                             14019	/*! 平方英里*/
#define	UGS_SQ_INCH                             14020	/*! 平方英寸*/
#define	UGS_SQ_YARD                             14021	/*! 平方码*/
#define	UGS_SQ_FOOT                             14022	/*! 平方英尺*/
#define	UGS_SM_STR_TIME_FORMAT                  14023	/*! %Y年%m月%d日 %H时%M分%S秒*/


// 地图处理信息：从15000开始编码
#define	UGS_CAN_NOT_CREATE_UNIQUE_THEMATIC_MAP_WITH_MORE_THAN_X_VALUES 15000	/*! 单值专题地图的单值个数不能超过%d个，创建单值专题图失败。*/
#define	UGS_CAN_NOT_CREATE_RANGE_THEMATIC_MAP_WITH_MORE_THAN_X_RANGES 15001	/*! 分段的数目不能超过%d,创建分段专题图失败!*/
#define	UGS_THEME_WIZARD                        15002	/*! 本向导将引导您轻松的创建专题图/n*/
#define	UGS_IMAGE_MSG_COLOR_HISTOGRAN_DLG_ERROE 15003	/*! 必须影像图层才能有直方图！*/
#define	UGS_LYT_ERR_LOAD_RULER_BMP              15004	/*! 调入标尺位图时错误*/
#define	UGS_LYT_ERROR_CREATE_SCALE              15005	/*! 矩形区域太小，无法正确生成比例尺!*/
#define	UGS_LYT_SCALE_NOT_APPROPRIATE           15006	/*! 您输入的小节长度太小！*/
#define	UGS_LYT_SCALE_EXISTED                   15007	/*! 此地图的比例尺已经存在！*/
#define	UGS_LYT_LEGEND_EXISTED                  15008	/*! 此地图的图例已经存在！*/
#define	UGS_LYT_BMP_OVERSIZE                    15009	/*! 选择的图像太大！*/
#define	UGS_SLMSG_INVALID_DRAG                  15010	/*! 不能拖到当前位置*/
#define	UGS_SLMSG_NOT_SUPPORT_LEGEND_ITEM_TYPE  15011	/*! 不支持的图标类型*/
#define	UGS_LYT_ERROR_MSG                       15012	/*! 矩形区域太小，无法正确生成比例尺!*/
#define	UGS_VIEW_MAP_BEGAIN                     15013	/*! 开始显示地图*/
#define	UGS_SLMSG_NO_LAYER                      15014	/*! 没有图层，无法完成初始化*/
#define	UGS_SET_INPUT_POLYGONLAYER              15015	/*! 请先设置输出面图层！*/
#define	UGS_SET_INPUT_REGIONLAYER               15016	/*! 请先设置输入区域图层！*/
#define	UGS_LYT_SEL_ONE_GROUP                   15017	/*! 请选择一个“组”对象!*/
#define	UGS_EDIT_ERR_GET_GEOMETRY               15018	/*! 取地图数据错误*/
#define	UGS_SL_MSG_TREEITEM_NOT_BELONG_TO_ANY_LAYER 15019	/*! 所给的节点不属于任何图层*/
#define	UGS_LAYER_LOCK                          15020	/*! 锁定当前图层*/
#define	UGS_SLMSG_CANNT_CHANGE_ITEM_TYPE        15021	/*! 图标的类型不同,不能修改图标的类型*/
#define	UGS_LYT_OUTPUT_MANAGING                 15022	/*! 正在处理输出影像，请稍后...*/


// 几何对象处理信息：从18000开始编码
#define	UGS_GET_GEOMETRY_DATA_FAILED            18000	/*! 获取对象空间数据失败*/
#define	UGS_MEMORY_ALLOTE_SHORTAGE              18001	/*! 内存分配不足*/
#define	UGS_GET_OBJECT_FAILED                   18002	/*! 获取对象失败*/
#define	UGS_OBJECTS_IDENTITY_QUERY_FAILED       18003	/*! 对象同一查询失败*/
#define	UGS_GET_OBJECT_SPATIAL_INFO_FAILED      18004	/*! 获取对象空间信息失败*/
#define	UGS_FAILED_TO_DRAW_REGION_FOR_REGION_IS_NULL 18005	/*! 面对象为空或者面对象的节点数小于等于0，绘制面对象失败*/
#define	UGS_FAILED_TO_DRAW_REGION_FOR_REGION_NODES_NUMBER_BIGGER_THAN_MAX 18006	/*! 面对象的节点数大于最大绘制节点数，绘制面对象失败*/
#define	UGS_SPATIAL_INDEX_NOT_SUPPORT_POITN_DATASET 18007	/*! 空间索引不支持点数据集*/
#define	UGS_INDEX_TABLE_IS_EXIST_PLEASE_CHECK_ITS_CORRECTNESS 18008	/*! 索引表已经存在，请检查其正确性*/
#define	UGS_IMPORT_MAYBE_GIRD_IS_NULL           18009	/*! 传入的maybe网格为空*/
#define	UGS_EMPTY_GEODATA                       18010	/*! 当前数据为空*/
#define	UGS_LESS_POINT_COUNT                    18011	/*! 输入的点数不能少于%d个*/
#define	UGS_OVERLAP_POINT                       18012	/*! 输入的点重叠*/
#define	UGS_NODE_ERROR                          18013	/*! 结点信息错误！*/
#define	UGS_GEODATA_ERROR                       18014	/*! 几何对象数据有错误！*/
#define	UGS_NO_GEO_FIGURE                       18015	/*! 非几何图形*/
#define	UGS_COMPUTE_AREA                        18016	/*! 计算多边形面积*/
#define	UGS_ERROR_COV_MOREPOINT                 18017	/*! 点的数目过多/n*/
#define	UGS_POINT_LACK                          18018	/*! 曲线控制点的个数不能少于6个*/
#define	UGS_MSG_OBJ_INVALID                     18019	/*! 对象无效*/
#define	UGS_MSG_INTERSECTOR_IS_NOT_TWO_POINT    18020	/*! 请确认折线与边界有两个交点!*/
#define	UGS_MSG_DATA_WAS_DAMAGED                18021	/*! 数据已被破坏*/
#define	UGS_XML_DATA_ERROR                      18022	/*! XML数据有错误！*/
#define	UGS_XML_POINTNUM_NOT_SAME               18023	/*! 点的个数不一致！*/
#define	UGS_STRING_AFC_EDIT_DELETE_OBJ          18024	/*! 你想删除这个对象吗？*/
#define	UGS_STRING_AFC_EDIT_ERROR               18025	/*! 有地方出问题了*/
#define	UGS_EDIT_ERR_NORECORD                   18026	/*! 当前编辑的对象不存在！*/
#define	UGS_ERROR_IDENTIAL_POINT                18027	/*! 输入的点全部重叠!*/
#define	UGS_SET_INPUT_LINE_LAYER                18028	/*! 请先设置输入线数据集！*/
#define	UGS_POLYGON_AREA_IS_ZERO                18029	/*! 多边形面积为零！*/
#define	UGS_POLYGON_CENTROID_CREATE_ERROR       18030	/*! 多边形中心点创建出错！*/
#define	UGS_STEP_1_BUILDING                     18031	/*! 创建多边形(%d/%d)...*/
#define	UGS_STEP_3_BUILDING                     18032	/*! 岛多边形处理(%d/%d)...*/
#define	UGS_STEP_4_BUILDING                     18033	/*! 整理多边形图层(%d/%d)...*/
#define	UGS_MSG_CLEARING_SMALL_POLYGON          18034	/*! 清除小多边形*/
#define	UGS_MSG_FIND_POLYPOLYLINE               18035	/*! 线数据集中有复杂线对象(SMID=%d)*/
#define	UGS_MSG_PICKUP_POLYGON                  18036	/*! 提取多边形*/
#define	UGS_MSG_POLYGON_PREPROCESS              18037	/*! 多边形预处理*/
#define	UGS_STEP_REGION_BUILD                   18038	/*! 提取多边形(%d/%d)...*/
#define	UGS_MSG_POLYGON_PREPROCESS_BUILD        18039	/*! 多边形预处理(%d/%d)...*/


// IO和文件处理信息：从19000开始编码
#define	UGS_DATAPUMP_UNKNOWN_FILETYPE           19000	/*! 不可识别的文件格式常量(%d)*/
#define	UGS_DATAPUMP_IMPORT_PARAMS_ERROR        19001	/*! 数据转换导入参数有误*/
#define	UGS_DATAPUMP_CREATE_PMP_FAILED          19002	/*! 创建格式常量为%d的数据转换类失败*/
#define	UGS_FILEPARSE_BASE_OPEN_FAILED          19003	/*! 用矢量解析基类打开文件(%s)失败*/
#define	UGS_FILEPARSE_READ_HEADER_FAILED        19004	/*! 读取文件头失败*/
#define	UGS_FILEPARSE_READ_FIELD_FAILED         19005	/*! 读取字段信息失败*/
#define	UGS_FILEPARSE_EOF                       19006	/*! 已到文件尾*/
#define	UGS_FILEPARSE_SHP_IMPORT                19007	/*! 导入Shape文件*/
#define	UGS_FILEPARSE_SHP_IMPORTTING            19008	/*! 正在导入Shape文件...*/
#define	UGS_FILEPARSE_SHP_HEADER_ERROR          19009	/*! 读取Shape文件中shp文件头时发生错误*/
#define	UGS_FILEPARSE_SHX_HEADER_ERROR          19010	/*! 读取Shape文件中shx文件头时发生错误*/
#define	UGS_FILEPARSE_SHP_FILECODE_ERROR        19011	/*! Shape文件头的FileCode为%d, 不等于9994(Shape文件标志)*/
#define	UGS_FILEPARSE_SHP_LENGTH_ERROR          19012	/*! Shape文件头中记录的文件长度(%d)和文件实际长度(%d)不相等*/
#define	UGS_FILEPARSE_SHX_LENGTH_ERROR          19013	/*! shx文件头中记录的文件长度(%d)和文件实际长度(%d)不相等*/
#define	UGS_FILEPARSE_SHP_VERSION               19014	/*! Shape文件头记录的版本号(%d)不等于1000(Shape格式版本号)*/
#define	UGS_FILEPARSE_SHP_GEOTYPE_PROBLEM       19015	/*! 这种Shape文件类型(%s)不能转为恰当的数据集类型*/
#define	UGS_FILEPARSE_SHX_INDEX_ERROR           19016	/*! shx文件索引可以已经损坏*/
#define	UGS_FILEPARSE_SHP_RECORDLENGTH          19017	/*! 在Shape文件(%s)编号为%d的记录在shp和shx文件中的长度描述不一致"}*/
#define	UGS_FILEPARSE_SHP_TYPE_ERROR            19018	/*! 不可识别的ShapeType(%d) */
#define	UGS_FILEPARSE_SHP_MULTIPATCH            19019	/*! 暂时不支持ShapeType为MultiPatch类型的Shape文件*/
#define	UGS_FILEPARSE_SHP_CREATE_FAILED         19020	/*! 创建Shape文件失败*/
#define	UGS_FILEPARSE_DBF_IMPORT                19021	/*! 导入DBF文件*/
#define	UGS_FILEPARSE_DBF_IMPORTING             19022	/*! 正在导入DBF文件...*/
#define	UGS_FILEPARSE_DBF_VER_NONSUPPORT        19023	/*! 不支持的DBF文件版本(0x%x)*/
#define	UGS_FILEPARSE_DBF_UNKNOWN_FIELDTYPE     19024	/*! 在DBF文件中, 遇到不认识的字段类型(%c)*/
#define	UGS_FILEPARSE_DBF_UNKNOWN_FLAG          19025	/*! 不可识别的记录开始或者结束标记(%d)*/
#define	UGS_FILE_OPEN_FAILED                    19026	/*! 文件（%s）打开失败*/
#define	UGS_FILE_CREATE_FAILED                  19027	/*! 文件（%s）创建失败*/
#define	UGS_FILE_WRITE_FAILED                   19028	/*! 文件（%s）写入失败*/
#define	UGS_FILE_READ_FAILED                    19029	/*! 文件（%s）读取失败*/
#define	UGS_FILE_NO_EXIST1                      19030	/*! 文件（%s）不存在*/
#define	UGS_FILE_NO_EXIST2                      19031	/*! 指定的文件不存在!*/
#define	UGS_FILE_DATA_TYPE_ERROR                19032	/*! 文件中数据类型错误*/
#define	UGS_FILE_IS_USING                       19033	/*! 文件正在使用中*/
#define	UGS_CANNOT_CREATE_TEMPFILE              19034	/*! 不能创建临时文件*/
#define	UGS_CREATE_TEMPORARY_FILE_ERROR         19035	/*! 生成缓存文件错误！*/
#define	UGS_EXPORT_SIT                          19036	/*! 数据集导出为SIT文件*/
#define	UGS_MSG_SDBPLUS_EXPORT_TO_TXT           19037	/*! 正在转化数据到数据库交换格式文件，请稍候...*/
#define	UGS_WRITING_DXF_FILE                    19038	/*! 正在输出 DXF 文件......*/
#define	UGS_WRITING_E00_FILE                    19039	/*! 正在输出 E00 文件......*/
#define	UGS_READING_DXF_FILE                    19040	/*! 正在输入 DXF 文件......*/
#define	UGS_READING_E00_FILE                    19041	/*! 正在输入 E00 文件......*/
#define	UGS_READING_DGN_FILE                    19042	/*! 正在输入DGN 文件......*/
#define	UGS_WRITING_DGN_FILE                    19043	/*! 正在输出 DGN 文件......*/
#define	UGS_READING_COV_FILE                    19044	/*! 正在输入 Coverage 文件......*/
#define	UGS_WRITING_COV_FILE                    19045	/*! 正在输出 Coverage 文件......*/
#define	UGS_READING_SHP_FILE                    19046	/*! 正在输入 Shape 文件......*/
#define	UGS_LAYER_INFO                          19047	/*! 原文件格式 : %s 由 %s 在 %s转入 开始 :%s 结束 :%s*/
#define	UGS_READING_MIF_FILE                    19048	/*! 正在输入 MIF 文件......*/
#define	UGS_WRITING_MIF_FILE                    19049	/*! 正在输出 MIF 文件......*/
#define	UGS_READING_VCT_FILE                    19050	/*! 正在输入 国家标准格式VCT 矢量文件......*/
#define	UGS_WRITING_VCT_FILE                    19051	/*! 正在输出 国家标准格式VCT 矢量文件......*/
#define	UGS_COMPACT                             19052	/*! 压缩:*/
#define	UGS_COMPACT_ECW                         19053	/*! ECW压缩:*/
#define	UGS_WRITING_SHP_FILE                    19054	/*! 正在输出 Shape 文件......*/
#define	UGS_FILE_X_TOO_SMALL                    19055	/*! 文件 %s 无效....*/
#define	UGS_FILE_FORMAT_INCORRECT               19056	/*! 文件格式不对*/
#define	UGS_MSG_IMPORT_TAB                      19057	/*! 转入MapInfo TAB文件*/
#define	UGS_READING_COV_FILE_PC_USERATT         19058	/*! 正在输入 Coverage(PC版) 文件用户自定义表......	*/
#define	UGS_READING_COV_FILE_PC_USERATT_ERROR   19059	/*! 输入 Coverage(PC版) 文件用户自定义表时，发生以下错误：*/
#define	UGS_ERROR_COV_WRITEFILE                 19060	/*! 写文件时发生错误/n*/
#define	UGS_ERROR_COV_WRITE_ONLY                19061	/*! 只写方式打开文件，不能读/n*/
#define	UGS_ERROR_COV_WRITESYSFIELDS            19062	/*! 写Coverage文件系统字段时发生错误/n*/
#define	UGS_ERROR_COV_DIRLENGTH                 19063	/*! info\arc.dir文件长度有错误/n*/
#define	UGS_ERROR_COV_MOREARC                   19064	/*! info目录下生成arc000x.dat文件错误/n*/
#define	UGS_ERROR_COV_FIELDINFO                 19065	/*! 生成字段信息文件错误/n*/
#define	UGS_ERROR_COV_FILEEXIST                 19066	/*! 试图生成一个已经存在的文件/n*/
#define	UGS_ERROR_COV_READ_ONLY                 19067	/*! 只读方式打开文件，不能写/n*/
#define	UGS_ERROR_COV_FILE_UNSPECIFIED          19068	/*! 不能确定的文件出错/n*/
#define	UGS_ERROR_COV_PRECISION                 19069	/*! Coverage 文件精度错误/n*/
#define	UGS_ERROR_COV_FILE_HARDIO               19070	/*! 打开文件时硬件错误/n*/
#define	UGS_ERROR_COV_FILE_ACCESSDENIED         19071	/*! 访问文件被拒绝/n*/
#define	UGS_ERROR_COV_FILE_INVALID              19072	/*! 处理文件时，文件无效/n*/
#define	UGS_ERROR_COV_FILE_TOOMANY              19073	/*! 处理文件时，文件数目太多/n*/
#define	UGS_ERROR_COV_FILE_NOTFOUND             19074	/*! 指定的文件没有找到/n*/
#define	UGS_ERROR_COV_FILE                      19075	/*! Coverage文件失效/n*/
#define	UGS_ERROR_COV_FILENOOPEN                19076	/*! 内部错误：对没有打开的文件进行操作/n*/
#define	UGS_ERROR_COV_FILE_SHARING              19077	/*! 文件共享错误/n*/
#define	UGS_READING_COV_FILE_SUN_USERATT_ERROR  19078	/*! 在转入Coverage(Sun版)文件用户属性表时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_SUN_USERATT        19079	/*! 正在转入Coverage(Sun版)文件用户属性表*/
#define	UGS_READING_COV_FILE_SUN_TEXT_ERROR     19080	/*! 在转入Coverage文件（Sun版文本图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_PC_POINT_ERROR     19081	/*! 在转成Coverage文件（Pc版点图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_SUN_POINT_ERROR    19082	/*! 在转成Coverage文件（Sun版点图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_PC_NETWORK_ERROR   19083	/*! 在转成Coverage文件（Pc版简单线图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_SUN_NETWORK_ERROR  19084	/*! 在转成Coverage文件（Sun版简单线图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_PC_LINE_ERROR      19085	/*! 在转成Coverage文件（Pc版复杂线图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_SUN_LINE_ERROR     19086	/*! 在转成Coverage文件（Sun版复杂线图层）时，出现以下错误：*/
#define	UGS_READING_COV_FILE_PC_REGION_ERROR    19087	/*! 在转成Coverage文件（Pc版面图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_SUN_REGION_ERROR   19088	/*! 在转成Coverage文件（Sun版面图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_PC_TEXT_ERROR      19089	/*! 在转成Coverage文件（Pc版注记图层）时，出现以下错误：/n*/
#define	UGS_READING_COV_FILE_SUN_TEXT_ERROR1    19090	/*! 在转成Coverage文件（Sun版注记图层）时，出现以下错误：/n*/
#define	UGS_BEGIN_WRITING_IN_DBF                19091	/*! 正在转出DBF文件*/
#define	UGS_BEGIN_READ_IN_DBF                   19092	/*! 正在转入DBF文件*/
#define	UGS_READING_WMF_FILE                    19093	/*! 正在转入WMF文件*/
#define	UGS_WRITING_WMF_FILE                    19094	/*! 正在转出WMF文件*/
#define	UGS_BEGIN_READING_IN_MDB                19095	/*! 正在转入Microsoft Access数据库文件MDB...*/
#define	UGS_READING_DWG_FILE                    19096	/*! 正在输入 DWG 文件...*/
#define	UGS_DXF_READING_ERROR                   19097	/*! 读取DXF文件时出错*/
#define	UGS_READING_DWG_LAYER                   19098	/*! 正在读取DWG图形的层信息......*/
#define	UGS_WRITING_JIF_FILE                    19099	/*! 转出JIF文件...*/
#define	UGS_WRITING_JIF25000_FILE               19100	/*! 转出JIF25000文件...*/
#define	UGS_MSG_NOT_SUPPORT_DXF_BINARY          19101	/*! %s 是dxf文件的二进制格式，系统暂不支持此格式的转入。*/
#define	UGS_ERROR_VEC_DVC_NOEXIST               19102	/*! Idrisi VEC文件的说明文件:%s 不能打开，请确认说明文件DVC文件在同一个文件夹下。*/
#define	UGS_VEC_EXPORT                          19103	/*! 正在转出Idrisi VEC文件...*/
#define	UGS_VEC_IMPORT                          19104	/*! 正在转入Idrisi VEC文件...*/
#define	UGS_SML_EXPORT                          19105	/*! 正在转出SML文档...*/
#define	UGS_SML_IMPORT                          19106	/*! 正在转入SML文档...*/
#define	UGS_AFC_DATAPMP_WRITE_CAD               19107	/*! 已输出 %ld 个复合对象*/
#define	UGS_GML_EXPORT                          19108	/*! 正在转出GML文档...*/
#define	UGS_GML_IMPORT                          19109	/*! 正在转入GML文档...*/
#define	UGS_GXML_EXPORT                         19110	/*! 正在转出GXML文档...*/
#define	UGS_GXML_IMPORT                         19111	/*! 正在转入GXML文档...*/
#define	UGS_IMPORT_AUTOCAD                      19112	/*! 正在转入AutoCAD的文件...*/
#define	UGS_IMPORT_JIF50_250_1000               19113	/*! 正在转入日本矢量格式文件...*/
#define	UGS_IMPORT_JIF2500                      19114	/*! 正在转入日本矢量2500格式文件...*/
#define	UGS_IMPORT_JIF10K                       19115	/*! 正在转入日本矢量10000格式文件...*/
#define	UGS_IMPORT_JIF25K                       19116	/*! 正在转入日本矢量25000格式文件...*/
#define	UGS_IMPORT_JRF10K                       19117	/*! 正在转入日本栅格10000格式文件...*/
#define	UGS_IMPORT_JRF10LANDUSE                 19118	/*! 正在转入日本栅格10LandUse格式文件...*/
#define	UGS_IMPORT_JRF10VOLCANO                 19119	/*! 正在转入日本栅格10Volcano格式文件...*/
#define	UGS_IMPORT_JRF50_250_1000               19120	/*! 正在转入日本栅格格式文件...*/
#define	UGS_READING_FILENAME                    19121	/*! 正在读取文件：%s ...*/
#define	UGS_PMP_ACAD_ERROR_EXT_NAME             19122	/*! 后缀名错误，必须为DWG或者DXF*/
#define	UGS_PMP_ACAD_ERROR_GET_HEADER           19123	/*! 获取文件头失败*/
#define	UGS_PMP_ACAD_ERROR_FILE_VERSION         19124	/*! AutoCAD文件版本错误*/
#define	UGS_PMP_ACAD_ERROR_INVALID_NAME         19125	/*! 名字不合法*/
#define	UGS_PMP_ACAD_ERROR_FILE_TYPE            19126	/*! AutoCAD文件类型错误*/
#define	UGS_PMP_ACAD_ERROR_INVALID_NUMBER       19127	/*! 序号不合法*/
#define	UGS_PMP_SELECT_SHX                      19128	/*! 请选择适当的shx文件*/
#define	UGS_PMP_SHX_FILTER                      19129	/*! AutoCAD SHX文件(*.shx)*/
#define	UGS_PMP_OPEN_AUTOCAD                    19130	/*! 正在打开AutoCAD文件*/
#define	UGS_PMP_SAVE_AUTOCAD                    19131	/*! 正在保存AutoCAD文件*/
#define	UGS_PMP_SCAN_AUTOCAD                    19132	/*! 正在扫描DXF文件...*/
#define	UGS_PMP_IMPORT_FST                      19133	/*! 正在转入FST文件*/
#define	UGS_PMP_IMPORT_ARCGRID                  19134	/*! 正在转入ArcInfo二进制Grid文件...*/
#define	UGS_IMPORT_MAPGIS                       19135	/*! 正在转入MapGIS明码交换格式...*/
#define	UGS_PMP_CREATE_LOGFILE_ERROR            19136	/*! 创建日志文件失败。*/
#define	UGS_PMP_GETLOGFILE_ERROR                19137	/*! 得到日志文件对象失败。*/
#define	UGS_IMG_IMPORT                          19138	/*! 正在转入Erdas Image文件...*/
#define	UGS_IMG_EXPORT                          19139	/*! 正在转出Erdas Image文件...*/
#define	UGS_PMP_VERSION_ERROR                   19140	/*! 目前还不支持此版本的文件!*/
#define	UGS_IMPORT_JIFDSF                       19141	/*! 正在转入日本数据地图25000格式文件...*/
#define	UGS_PMP_IMPORTING_RAW                   19142	/*! 正在导入RAW文件...*/
#define	UGS_PMP_IMPORT_BSQ                      19143	/*! 正在导入BSQ文件...*/
#define	UGS_PMP_IMPORTING_BIP                   19144	/*! 正在导入BIP文件...*/
#define	UGS_IMPORT_MRSID                        19145	/*! 正在转入MrSID 文件*/
#define	UGS_READING_ECW_FILE                    19146	/*! 正在转入 ECW 文件...*/
#define	UGS_FSL_EDITTOOL_IMAGEIMPORT            19147	/*! 导入图像文件*/
#define	UGS_FSL_EXPORT_BMP                      19148	/*! 输出为BMP文件*/
#define	UGS_OUTPUTEX_MSG_CREATE_TEMP_FILE       19149	/*! 正在生成临时文件......*/
#define	UGS_SM_NO_BITMAP_TO_SAVE                19150	/*! 没有位图可以保存。*/
#define	UGS_SM_FILE_OPEN_FAILED                 19151	/*! 打开文件错误。*/
#define	UGS_SM_BITMAP_NOT_CREATED               19152	/*! 创建位图错误。*/
#define	UGS_SM_MSG_FILE_X_NOT_EXISTS            19153	/*! 文件 "%s" 不存在!*/
#define	UGS_SM_MSG_FAILED_TO_OPEN_FILE_X        19154	/*! 打开文件 "%s" 失败!*/
#define	UGS_SM_MSG_FAILED_TO_CREATE_FILE_X      19155	/*! 创建文件 "%s" 失败!*/
#define	UGS_SM_MSG_FAILED_TO_WRITE_FILE_X       19156	/*! 写文件 "%s" 失败!	*/
#define	UGS_SM_MSG_FAILED_TO_READ_FILE_X        19157	/*! 读文件 "%s" 失败!*/
#define	UGS_SM_MSG_FILE_VERSION_NEWER_THAN_SOFTWARE 19158	/*! 该文件需要更高版本的软件才能打开。*/
#define	UGS_SM_FILE_TITLE_ERROR                 19159	/*! 文件头错误。*/
#define	UGS_SM_FILE_DATA_TYPE_ERROR             19160	/*! 文件中的数据类型错误。*/
#define	UGS_SM_FILE_COLUMNS_ERROR               19161	/*! 文件中列值错误。*/
#define	UGS_SM_DISKSPACE_NOT_ENOUGH             19162	/*! 磁盘空间不足！*/
#define	UGS_NO_ENOUGH_DISKSPACE                 19163	/*! 临时文件目录所在磁盘没有足够空间*/


// 坐标系投影处理信息：从20000开始编码
#define	UGS_MAP_LAMBERT_NAME                    20000	/*! 等角圆锥投影*/
#define	UGS_PJ_NONEARTH_2_EARTH_OR_PJ           20001	/*! 非地理坐标不能与地理坐标或投影坐标进行转换。*/
#define	UGS_PJ_THE_SAME_SYSTEM                  20002	/*! 同系，不用转换*/
#define	UGS_PJ_EARTH_2_EARTH                    20003	/*! 地理坐标系之间暂时不能转换*/
#define	UGS_PJ_UGS_INVALID                      20004	/*! 投影系无效*/
#define	UGS_PJ_SRC_IS_NOT_PJ                    20005	/*! 源不是投影系*/
#define	UGS_PJ_DES_IS_NOT_PJ                    20006	/*! 目的不是投影系*/
#define	UGS_PJ_SRC_IS_NOT_EARTH                 20007	/*! 源不是地理坐标系*/
#define	UGS_PJ_DES_IS_NOT_EARTH                 20008	/*! 目的不是地理坐标系*/
#define	UGS_PROJECT_INVLAID                     20009	/*! 投影信息不正确*/
#define	UGS_EARTH_COORD_SYSTEM                  20010	/*! 经纬坐标系*/
#define	UGS_PLANAR_COORD_SYSTEM                 20011	/*! 平面坐标系*/
#define	UGS_PJ_NAME                             20012	/*! 投影名称*/
#define	UGS_PJ_PARAMETER                        20013	/*! 参数*/


// 空间分析处理信息：从21000开始编码
#define	UGS_BUFFER_ANALYSIS_NOT_SUPPORT_DIFFERENT_RADIU 21000	/*! 缓冲区分析暂时不支持左右不等缓冲*/
#define	UGS_BUFFER_ANALYSIS_SEMICIRCLESEMENT_NOT_CORRET 21001	/*! 拟合弧段太小或太大*/
#define	UGS_BUFFER_ANALYSIS_FAILED              21002	/*! 缓冲区分析失败*/
#define	UGS_BUFFER_ANALYSIS_OBJECTS_COUNT_IS_0  21003	/*! 对象个数为0*/
#define	UGS_BUFFER_ANALYSIS_CREATE_UDB_DATASOURCE_FAIL 21004	/*! 创建UDB数据源失败*/
#define	UGS_BUFFER_ANALYSIS                     21005	/*! 缓冲区分析*/
#define	UGS_BUFFER_CREATING                     21006	/*! 正在生成缓冲区...*/
#define	UGS_CLIP_DT                             21007	/*! Clip数据集*/
#define	UGS_CLIPPING_DT                         21008	/*! 正在Clip数据集*/
#define	UGS_JUST_REGION_CLIP                    21009	/*! 只有多边形数据集才能作为Clip数据集*/
#define	UGS_IMAGE_CLIP_FAILED                   21010	/*! 影像剪裁操作失败！*/
#define	UGS_ERASE_DT                            21011	/*! Erase数据集*/
#define	UGS_ERASING_DT                          21012	/*! 正在Erase数据集...*/
#define	UGS_JUST_REGION_ERASE                   21013	/*! 只有面数据集才能作为Erase数据集*/
#define	UGS_INTERSECT_DT                        21014	/*! Intersect数据集*/
#define	UGS_INTERSECTING_DT                     21015	/*! 正在Intersect数据集...*/
#define	UGS_JUST_REGION_INTERSECT               21016	/*! 只有面数据集才能作为Intersect数据集*/
#define	UGS_IDENTITY_DAT                        21017	/*! Identity数据集*/
#define	UGS_IDENTITYING_DT                      21018	/*! 正在Identity数据集...*/
#define	UGS_JUST_REGION_IDENTITY                21019	/*! 只有面数据集才能作为Identity数据集*/
#define	UGS_UNION_DT                            21020	/*! Union数据集*/
#define	UGS_UNIONING_DT                         21021	/*! 正在Union数据集...*/
#define	UGS_JUST_REGION_UNION                   21022	/*! 只有面数据集才能作为Union数据集*/
#define	UGS_FAILED_IN_OVERLAY_COMPUTING         21023	/*! Overlay计算中出现问题*/
#define	UGS_OVERLAY_RESULT_DT_MUST_BE_EMPTY     21024	/*! 用来存放叠加操作结果的数据集必须为空*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_INTERSECTION 21025	/*! 只有多边形数据集才能作为求交运算的数据集。*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_ERASE_DT 21026	/*! 只有多边形数据集才能作为擦除数据集。*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_CLIP     21027	/*! 只有多边形数据集才能作为裁减数据集。*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_IDENTITY_DT 21028	/*! 只有多边形数据集才能作为同一运算的数据集。*/
#define	UGS_ONLY_REGION_CAN_BE_USED_AS_UNION    21029	/*! 只有多边形数据集才能作为合并运算的数据集。*/
#define	UGS_PROCESSING                          21030	/*! 正在处理...*/
#define	UGS_DT_INTERSECTING                     21031	/*! 数据集求交运算...*/
#define	UGS_DT_IDENTITYING                      21032	/*! 数据集同一运算...*/
#define	UGS_DT_UNIONNING                        21033	/*! 合并数据集...*/
#define	UGS_DT_CLIPPING                         21034	/*! 裁剪数据集...*/
#define	UGS_DT_ERASING                          21035	/*! 擦除数据集...*/
#define	UGS_NOT_SUPPORT_DT_TYPE                 21036	/*! 不能用这类数据集进行叠加操作*/
#define	UGS_FAILD_TO_QUERY_DT                   21037	/*! 查询数据集失败*/
#define	UGS_CLIP_NO_INTERSECTION                21038	/*! 剪裁边界和影像边界没有相交部分，剪裁操作失败！*/
#define	UGS_ONLY_DISSOLVE_REGION_AND_LINE       21039	/*! 消融只适用于面和线数据集！*/
#define	UGS_TOO_SMALL_BUFFER                    21040	/*! 开辟的缓冲区太小。*/
#define	UGS_SM_MSG_ONLY_DISSOLVE_TYPE           21041	/*! 消融数据集类型不合法*/
#define	UGS_SM_MSG_TOPO_DISSOLVING              21042	/*! 正在合并字段值相同的对象...*/
#define	UGS_MSG_MERGING_LINE_DISSOLVE           21043	/*! 线消融*/


// 拓扑处理信息：从22000开始编码
#define	UGS_TOPO_ERROR                          22000	/*! 源网络数据集拓扑关系错误*/
#define	UGS_NO_MATCHING_ARC                     22001	/*! 没有匹配弧段*/
#define	UGS_NO_DEMAND_NODE_OR_NO_CENTERS        22002	/*! 没有需求点或没有中心点*/
#define	UGS_FOUND_REPEATE_VERTEX                22003	/*! 发现重复顶点，请纠正后再试！*/
#define	UGS_ARC_DATA_READING_ERROR              22004	/*! 弧段数据读取错误！*/
#define	UGS_FOUND_A_ERROR_PESUDO_NODE           22005	/*! 发现一个错误的假结点：*/
#define	UGS_THIS_IS_A_TOPO_ERROR                22006	/*! 拓扑错误！*/
#define	UGS_FOUND_A_DANGLE_NODE                 22007	/*! 发现一个悬结点！*/
#define	UGS_ARCS_NUMBER_OF_POLYGON_IS_MROE_THAN_TOTAL_ARCS_NUMBER 22008	/*! 该多边形弧段数已经大于总弧段数！*/
#define	UGS_STEP_1_CLEANING_REDUDANCE_VERTEXES  22009	/*! 剔出冗余点(%d/%d)......*/
#define	UGS_DELETED_LINES_AND_VERTEXES          22010	/*! 共去除%d个线对象，%d个点对象。 */
#define	UGS_TOTAL_DELETED_REPEATE_LINES         22011	/*! 共删除%d个重复线图元。*/
#define	UGS_TOTAL_DELETED_DANGLE_LINES          22012	/*! 共去除%d条短悬线。*/
#define	UGS_TOTAL_DELETED_SMALL_POLYGON         22013	/*! 共删除%d个小多边形。*/
#define	UGS_TOTAL_MERGED_PSEUDO_NODES           22014	/*! 共合并%d个假结点。*/
#define	UGS_STEP_2_EXTENDING_LONG_DANGLE_LINE   22015	/*! 延伸长悬线(%d/%d)...*/
#define	UGS_THIS_IS_A_FATA_TOPO_ERROR           22016	/*! 严重拓扑错误！*/
#define	UGS_STEP_2_INTERSECT_ALL_LINES          22017	/*! 计算交点(%d/%d)...*/
#define	UGS_STEP_1_CLEAN_REPEATE_LINES          22018	/*! 去重复线预处理(%d/%d)...*/
#define	UGS_TOTAL_DELETED_SMALL_LINES           22019	/*! 在合并邻近结点的过程中，同时删除了%d个短线！*/
#define	UGS_ASK_EXTENDED_AERO_LENGTH            22020	/*! 悬结点延伸长度不能为零！*/
#define	UGS_STEP_3_LINE_NET_BUILD               22021	/*! 创建网络图层(%d/%d)...*/
#define	UGS_ERROR_SEARCHING_NEXT_ARC            22022	/*! 在查找当前多边形的下一条弧段时出错， 该弧段已经被其他多边形所使用。*/
#define	UGS_ERROR_SEARCHING_NEXT_NODE           22023	/*! 在搜索结点时出错。*/
#define	UGS_ASK_CONTINUE                        22024	/*! 继续吗？*/
#define	UGS_TOPO_ERROR_LINE_SID                 22025	/*! 拓扑错误线记录序号为：%d */
#define	UGS_MSG_BUILDING_POLYGONS               22026	/*! 正在创建拓扑多边形*/
#define	UGS_MSG_CLEARING_REPEATE_LINES          22027	/*! 清除重复线*/
#define	UGS_MSG_NODE_IDENTIFYING                22028	/*! 节点分类*/
#define	UGS_MSG_MERGING_PSEUDO_NODE             22029	/*! 合并假节点*/
#define	UGS_MSG_MERGING_CLOSE_NODE              22030	/*! 合并临近节点*/
#define	UGS_MSG_EXTENDING_DANGLE_LINES          22031	/*! 长悬线延伸*/
#define	UGS_MSG_INTERSECTING                    22032	/*! 弧段求交*/
#define	UGS_MSG_CREATING_TOPO_ERROR_INFO        22033	/*! 生成拓扑错误信息*/
#define	UGS_MSG_CLEARING_SMALL_DANGLE           22034	/*! 清除短悬线*/
#define	UGS_MSG_CLEAR_SHORT_LINE_IS_ZERO        22035	/*! 短悬线的距离等于或小于零*/
#define	UGS_MSG_CLEAR_REDUNDANCE_LINE_IS_ZERO   22036	/*! 冗余点的距离等于或小于零*/
#define	UGS_MSG_MERGE_CLOSE_NODE                22037	/*! 临近节点的距离等于或小于零*/
#define	UGS_MSG_POLYLINE_PREPROCESS             22038	/*! 线预处理*/
#define	UGS_MSG_MAKE_TOPO_POLYLINE              22039	/*! 提取拓扑线*/


// 数字地面模型（DEM）处理信息：从23000开始编码
#define	UGS_MAP_ALTIMETER                       23000	/*! 高度表(m)*/
#define	UGS_ERROR_SWITCH                        23001	/*! 创建精简TIN时不能使用 -I 参数*/
#define	UGS_DTM_MSG_TIN_TO_DEM                  23002	/*! 从不规则三角网生成数字高程模型*/
#define	UGS_DTM_MSG_CREATE_DEM                  23003	/*! 生成DEM*/
#define	UGS_DTM_MSG_READ_POINT                  23004	/*! 正在读取高程点*/


// 数据引擎处理信息：从24000开始编码
#define	UGS_UDB_NOT_SUPPORT_RELEASEPYRAMIDDATASETS 24000	/*! UDB 引擎不支持如下操作:ReleasePyramidDatasets()*/
#define	UGS_UDB_NOT_SUPPORT_TIER                24001	/*! UDB 引擎不支持如下操作:Tier()*/
#define	UGS_UDB_NOT_SUPPORT_BULIDPYRAMID        24002	/*! UDB 引擎不支持如下操作:BuildPyramid()*/
#define	UGS_UDB_NOT_SUPPORT_REMOVEPYRAMIDS      24003	/*! UDB 引擎不支持如下操作:RemovePyramids()*/
#define	UGS_UDB_NOT_SUPPORT_CALCAVGVALUE        24004	/*! UDB 引擎不支持如下操作:CalcAvgValue()*/
#define	UGS_DATASET_NOT_OPEN_OR_DATASOURCE_READ_ONLY 24005	/*! 数据集没有打开或数据源为只读*/
#define	UGS_DATASET_NOT_OPEN_OR_CANNOT_OPEN     24006	/*! 数据集没有打开或无法打开*/
#define	UGS_IMAGE_BLOCK_SIZE_IS_ZERO            24007	/*! 影像块尺寸为0*/
#define	UGS_UDB_NOT_SUPPORT_GETLOCKEDUSERID     24008	/*! UDB 引擎不支持如下操作:GetLockedUserID()*/
#define	UGS_UDB_NOT_SUPPORT_CREATE              24009	/*! UDB 引擎不支持如下操作:Create()*/
#define	UGS_UDB_NOT_SUPPORT_COMPUTERECCOUNT     24010	/*! UDB 引擎不支持如下操作:ComputeRecCount()*/
#define	UGS_UDB_NOT_SUPPORT_RESAMPLE            24011	/*! UDB 引擎不支持如下操作:Resample()*/
#define	UGS_UDB_NOT_SUPPORT_REGISTEROPTION      24012	/*! UDB 引擎不支持如下操作:RegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_UNREGISTEROPTION    24013	/*! UDB 引擎不支持如下操作:UnRegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_GETCACHEFILE        24014	/*! UDB 引擎不支持如下操作:GetCacheFile()*/
#define	UGS_UDB_NOT_SUPPORT_COPYFIELD           24015	/*! UDB 引擎不支持如下操作:CopyField()*/
#define	UGS_NOT_FIND_FILED_WITH_THIS_ID         24016	/*! 找不到此ID字段*/
#define	UGS_CURRENT_CURSOR_POS_ILLEGAL          24017	/*! 当前的游标位置非法*/
#define	UGS_UDB_NOT_SUPPORT_GETGEOMETRYDIRECT   24018	/*! UDB 引擎不支持如下操作:GetGeometryDirect()*/
#define	UGS_UDB_NOT_SUPPORT_FINDFIRST           24019	/*! UDB 引擎不支持如下操作:FindFirst()*/
#define	UGS_UDB_NOT_SUPPORT_FINDLAST            24020	/*! UDB 引擎不支持如下操作:FindLast()*/
#define	UGS_UDB_NOT_SUPPORT_FINDNEXT            24021	/*! UDB 引擎不支持如下操作:FindNext()*/
#define	UGS_UDB_NOT_SUPPORT_FINDPREV            24022	/*! UDB 引擎不支持如下操作:FindPrev()*/
#define	UGS_UDB_NOT_SUPPORT_SETGEOMETRY         24023	/*! UDB 引擎不支持如下操作:SetGeometry*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUE       24024	/*! UDB 引擎不支持如下操作:SetFieldValue*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUENULL   24025	/*! UDB 引擎不支持如下操作:SetFieldValueNull*/
#define	UGS_NO_GEOMETRY_ELEMENT_OR_CANNOT_OPEN_DATASET 24026	/*! 没有几何元素或无法打开数据集*/
#define	UGS_UDB_NOT_SUPPORT_LOCK                24027	/*! UDB 引擎不支持如下操作:Lock()*/
#define	UGS_UDB_NOT_SUPPORT_UNLOCK              24028	/*! UDB 引擎不支持如下操作:UnLock()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUT        24029	/*! UDB 引擎不支持如下操作:UndoCheckOut()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUTCURRENT 24030	/*! UDB 引擎不支持如下操作:UndoCheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKINCURRENT      24031	/*! UDB 引擎不支持如下操作:CheckInCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUTCURRENT     24032	/*! UDB 引擎不支持如下操作:CheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKIN             24033	/*! UDB 引擎不支持如下操作:CheckIn()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUT            24034	/*! UDB 引擎不支持如下操作:CheckOut()*/
#define	UGS_ENG_INVALID_DEST_DS                 24035	/*! 目的数据源非法*/
#define	UGS_ENG_GET_POINT_FROM_DT               24036	/*! 正在从数据库中取点...*/
#define	UGS_ENG_CANNOT_CHANGE_PWD_SHAREMODE     24037	/*! 共享打开方式不能修改密码！*/
#define	UGS_ENG_INVALID_DATA_FORMAT             24038	/*! 非SuperMap格式的文件或文件系统已破坏*/
#define	UGS_ENG_READONLY                        24039	/*! 只读，不能进行修改操作。*/
#define	UGS_ENG_CANNOT_WATCH_DS                 24040	/*! 数据源已经被别的用户以独占方式打开，或没有查看数据的权限。*/
#define	UGS_ENG_CANNOT_OPEN_READONLY_3001       24041	/*! 3001版本不能只读打开*/
#define	UGS_ENG_CONNECT_STRING_ERROR            24042	/*! 连接数据源字串非法。*/
#define	UGS_ENG_OPEN_DATASOURCE_FAILED          24043	/*! 数据源打开失败*/
#define	UGS_ENG_DATASOURCE_CONNECT_FAILED       24044	/*! 数据库连接失败，请检查数据源连接参数*/
#define	UGS_ENG_INVALID_DT                      24045	/*! 数据集无效*/
#define	UGS_ENG_SAMENAME_DT_EXIST               24046	/*! 同名数据集已经存在！*/
#define	UGS_ENG_CANNOT_COPY_BETWEEN_ENGINE      24047	/*! 不能在不同的引擎间克隆ECW或MrSID数据集*/
#define	UGS_ENG_REPLACE_DATASET_NAME            24048	/*! 要创建的数据集的名字从(%s)更换为(%s)*/
#define	UGS_ENG_CREATE_DATASET_FAILED2          24049	/*! 创建数据集(名称:%s;类型:%d)失败*/
#define	UGS_ENG_EMPTY_RS                        24050	/*! 当前记录集为空*/
#define	UGS_ENG_CANNOT_UPDATE                   24051	/*! 在没有AddNew或Edit的状态下不能Update！*/
#define	UGS_ENG_TOO_SMALL_POLYGON               24052	/*! 周长为0或者面积为0的多边形对象不能添加到记录集中。*/
#define	UGS_ENG_TOO_SHORT_LINE                  24053	/*! 长度为0的线对象不能添加到记录集中。*/
#define	UGS_ENG_ADD_TO_RECORDSET                24054	/*! 正往记录集里加记录\"%s\"...*/
#define	UGS_ENG_REPLACE_FIELD_NAME              24055	/*! 要创建的字段的名字从(%s)更换为(%s)*/
#define	UGS_ENG_CLOSE_ALL_RECORDSET             24056	/*! 建空间索引前请关闭所有的记录集！*/
#define	UGS_ENG_ERROR_SQL_STATEMENT             24057	/*! 错误的SQL查询语句！*/
#define	UGS_ENG_SPATIAL_QUERY_NO_GEODATA        24058	/*! 空间查询没有几何对象*/
#define	UGS_ENG_LONG_TRANS_NOT_LOGIN            24059	/*! 长事务用户没有登录！*/
#define	UGS_ORAPLUS_NOSUPPORT_DATATYPE          24060	/*! 这种数据类型Oracle引擎目前不支持。*/
#define	UGS_PREPARE_CREATE_DS                   24061	/*! 准备创建数据源...*/
#define	UGS_CREATE_DS_SUCCESS                   24062	/*! 创建数据源成功!*/
#define	UGS_PREPARE_OPEN_DS                     24063	/*! 准备打开数据源...*/
#define	UGS_OPEN_DS_SUCCESS                     24064	/*! 打开数据源成功!*/
#define	UGS_PREPARE_CLOSE_DS                    24065	/*! 关闭数据源...*/
#define	UGS_CREATE_TABLE_SUCCESS                24066	/*! 创建&lt;%s&gt;表成功...*/
#define	UGS_ROLLBACK_TRANS                      24067	/*! 回滚事务*/
#define	UGS_READING_INFO_OF_VDT                 24068	/*! 正在读取矢量数据集&lt;%s&gt;的相关信息...	*/
#define	UGS_READING_INFO_OF_RDT                 24069	/*! 正在读取栅格数据集&lt;%s&gt;的相关信息...*/
#define	UGS_LOGIN_LONGTRANS                     24070	/*! 登录数据源(%s)的长事务环境*/
#define	UGS_LOGOUT_LONGTRANS                    24071	/*! 退出数据源(%s)的长事务环境*/
#define	UGS_LONGTRANS_LOCK_DATA                 24072	/*! {%s}按长事务方式锁定数据*/
#define	UGS_LONGTRANS_UNLOCK_DATA               24073	/*! {%s}按长事务方式解锁数据*/
#define	UGS_LONGTRANS_ROLLBACK                  24074	/*! {%s}按长事务方式回滚操作	*/
#define	UGS_CREATE_VDT                          24075	/*! 创建矢量数据集：%s*/
#define	UGS_CREATE_RASTER                       24076	/*! 创建栅格数据集：%s*/
#define	UGS_DELETE_DT                           24077	/*! 删除数据集：%s*/
#define	UGS_VDT_APPEND                          24078	/*! 向矢量数据集 (%s) 中追加记录*/
#define	UGS_VDT_BUILD_SPATIAL_INDEX             24079	/*! 为矢量数据集 (%s) 建立空间索引 ... ...	*/
#define	UGS_VDT_COMPUTE_BOUNDS                  24080	/*! 为矢量数据集 ( %s ) 计算范围...*/
#define	UGS_VDT_CREATE_FIELD                    24081	/*! 为矢量数据集 ( %s ) 创建字段 ( %s ) ...*/
#define	UGS_VDT_DELETE_FIELD                    24082	/*! 为矢量数据集( %s ) 删除字段 ( %s )*/
#define	UGS_VDT_CREATE_INDEX                    24083	/*! 为矢量数据集 (%s) 创建字段索引 ( %s )*/
#define	UGS_VDT_REMOVE_INDEX                    24084	/*! 为矢量数据集 ( %s ) 移除索引 ( %s ) */
#define	UGS_VDT_RENAME                          24085	/*! 将矢量数据集 ( %s ) 重命名为：( %s )*/
#define	UGS_VDT_RESET_BOUNDS                    24086	/*! 矢量数据集( %s )重设Bounds。*/
#define	UGS_VDT_MODIFY_FIELD_INFO               24087	/*! 矢量数据集 ( %s ) : 修改字段 ( %s ) 的相关信息*/
#define	UGS_RS_ADD_RECORDSET                    24088	/*! 数据集(%s)的记录集添加了一条记录*/
#define	UGS_RS_DELETE_A_RECORDSET               24089	/*! 数据集(%s)的记录集删除了一条记录*/
#define	UGS_RS_MODIFY_RECORDSET                 24090	/*! 数据集(%s)的记录集修改了一条记录*/
#define	UGS_COMPUTE_EXTREMUM                    24091	/*! 计算字段 %s 的极值*/
#define	UGS_OPEN_VDT                            24092	/*! 打开矢量数据集 (%s)成功！*/
#define	UGS_CLOSE_VDT                           24093	/*! 关闭矢量数据集(%s)*/
#define	UGS_CONNECT_DS                          24094	/*! 数据源{%s}连接到数据库*/
#define	UGS_COPY_DT                             24095	/*! 数据源{%s}复制数据集{%s}*/
#define	UGS_VDT_ADD_METADATADESC                24096	/*! 矢量数据集(%s)添加元数据*/
#define	UGS_VDT_LONGTRAN_CHECKIN                24097	/*! 矢量数据集(%s)按长事务方式提交修改	*/
#define	UGS_VDT_LONGTRAN_LOCK                   24098	/*! 矢量数据集(%s)按长事务方式锁定记录*/
#define	UGS_VDT_CLEAR_METADATA                  24099	/*! 矢量数据集(%s)清除元数据*/
#define	UGS_VDT_COPYFIELD                       24100	/*! 矢量数据集(%s)复制字段(%s)*/
#define	UGS_VDT_DELETE_METADATA_NODE            24101	/*! 矢量数据集(%s)删除元数据节点*/
#define	UGS_OPEN_RDT                            24102	/*! 打开栅格数据集(%s)成功*/
#define	UGS_CLOSE_RDT                           24103	/*! 关闭栅格数据集(%s)*/
#define	UGS_RDT_CREATEECW                       24104	/*! 创建ECW文件(%s)的外部连接*/
#define	UGS_RDT_CREATE_MRSID                    24105	/*! 创建MrSID文件(%s)的外部连接*/
#define	UGS_RDT_RESET                           24106	/*! 栅格数据集(%s)图层清空*/
#define	UGS_VDT_TRUNCATE                        24107	/*! 矢量数据集(%s)清空数据*/
#define	UGS_RDT_RELEASE_PYRAMID                 24108	/*! 栅格数据集(%s)释放影像金字塔数据集*/
#define	UGS_RDT_ADD_METADATA                    24109	/*! 栅格数据集(%s)添加元数据*/
#define	UGS_RDT_CLEAR_METADATA                  24110	/*! 栅格数据集(%s)清除元数据*/
#define	UGS_RDT_DELETE_METADATA                 24111	/*! 栅格数据集(%s)删除元数据描述的节点*/
#define	UGS_RDT_REMOVE_PYRAMUGS                 24112	/*! 栅格数据集(%s)删除影像金字塔*/
#define	UGS_RDT_BUILD_PYRAMID                   24113	/*! 栅格数据集(%s)建立影像金字塔*/
#define	UGS_RS_DELETE_ALL                       24114	/*! 记录集删除所有记录*/
#define	UGS_VDT_LONGTRAN_UNDO_LOCK              24115	/*! 矢量数据集(%s) 按长事务方式取消锁定*/
#define	UGS_VDT_SET_FIELD_PROPTY                24116	/*! 矢量数据集(%s) 设置字段(%s) 属性	*/
#define	UGS_VDT_UPDATE_FIELD                    24117	/*! 矢量数据集(%s) 更新字段(%s) 属性*/
#define	UGS_LOG_RS_LOCK                         24118	/*! 将记录集查询出来的且没有被别人锁定的记录锁定*/
#define	UGS_RS_UNDO_MODIFY                      24119	/*! 放弃对当前记录集所做的修改*/
#define	UGS_LOG_RS_MODIFY_CURRENT               24120	/*! 提交对当前记录所做的修改*/
#define	UGS_RS_LOCK_CURRENT                     24121	/*! 锁定当前记录*/
#define	UGS_RS_UNDO_MODIFY_CURRENT              24122	/*! 撤消对当前记录所做的修改*/
#define	UGS_RS_COPY_FIELD                       24123	/*! 记录集复制字段(%s)*/
#define	UGS_RS_MODIFY_FIELD_VALUE               24124	/*! 记录集修改当前属性字段值*/
#define	UGS_RS_MODIFY_GEOMETRY                  24125	/*! 记录集修改当前空间数据*/
#define	UGS_VDT_QUERY_FIELD_INFOS               24126	/*! 矢量数据集(%s) 查询字段集合*/
#define	UGS_VDT_STATISTIC                       24127	/*! 矢量数据集(%s)执行统计操作*/
#define	UGS_VDT_COMPUTE_EXTREMUM                24128	/*! 矢量数据集(%s) 计算极值*/
#define	UGS_VDT_COMPUTE_BOUNDARY                24129	/*! 矢量数据集(%s) 计算边界*/
#define	UGS_RDT_SAVE_TO_BLOCK                   24130	/*! 栅格数据集(%s) 保存影像数据到存储设备*/
#define	UGS_RDT_LOAD_IMAGE                      24131	/*! 栅格数据集(%s) 读取影像数据*/
#define	UGS_RS_FIND_FIRST                       24132	/*! 记录集光标移到第一个位置*/
#define	UGS_RS_FIND_LAST                        24133	/*! 记录集光标移到最后一个位置*/
#define	UGS_RS_FIND_NEXT                        24134	/*! 记录集光标移到下一个位置*/
#define	UGS_RS_FIND_PREV                        24135	/*! 记录集光标移到前一个位置*/
#define	UGS_RS_SEEK_BY_ID                       24136	/*! 根据ID移动记录集光标*/
#define	UGS_RS_STATISTIC                        24137	/*! 记录集执行统计操作*/
#define	UGS_RS_QUERY_WITH_BOUNDS                24138	/*! 记录集执行Bounds查询*/
#define	UGS_RS_QUERY_WITH_GENERAL               24139	/*! 记录集执行普通查询*/
#define	UGS_RS_QUERY_WITH_IDS                   24140	/*! 记录集执行IDS查询*/
#define	UGS_RS_QUERY_WITH_SPATIAL               24141	/*! 记录集执行空间查询*/
#define	UGS_RS_COMPUTE_BOUNDS                   24142	/*! 记录集计算边界*/
#define	UGS_RS_FLUSH_CURRENT_RECORDSET          24143	/*! 记录集提交当前记录到存储设备*/
#define	UGS_RS_UPDATING                         24144	/*! 记录集正在执行更新操作...*/
#define	UGS_RS_UPDATE                           24145	/*! 记录集更新成功*/
#define	UGS_CREATE_DT                           24146	/*! 数据源(%s)创建数据集(%s)*/
#define	UGS_DS_CONNECT                          24147	/*! 数据源(%s)建立连接*/
#define	UGS_RDT_RENAME                          24148	/*! 将栅格数据集 (%s) 重命名为 (%s)	*/
#define	UGS_FIELD_NAME                          24149	/*! 字段名*/
#define	UGS_FIELD_TYPE                          24150	/*! 字段类型*/
#define	UGS_FIELD_SIZE                          24151	/*! 字段大小*/
#define	UGS_ERROR_TOO_SMALL_REGION              24152	/*! 周长为0或者面积为0的多边形对象不能添加到数据集中。*/
#define	UGS_ERROR_TOO_SHORT_LINE                24153	/*! 长度为0的线对象不能添加到数据集中。*/
#define	UGS_INVALID_ROW_OR_COLUMN               24154	/*! 无效的行列数*/
#define	UGS_FAILED_TO_OPEN_DT                   24155	/*! 打开数据集失败*/
#define	UGS_INVALID_DS_PATH                     24156	/*! 数据源路径非法*/
#define	UGS_RS_NOT_EXIST                        24157	/*! 记录集不存在*/
#define	UGS_RS_IS_EMPTY                         24158	/*! 空记录集*/
#define	UGS_DT_IS_EMPTY                         24159	/*! 空数据集*/
#define	UGS_TYPE_MISMATCH_BETWEEN_RS_AND_DT     24160	/*! 数据集和记录集的类型不匹配*/
#define	UGS_FAILED_TO_CREATE_FIELDS             24161	/*! 创建字段失败*/
#define	UGS_DT_NAME_ALREADY_EXIST               24162	/*! 同名的数据集已存在*/
#define	UGS_DT_WITH_SPECIFIED_NAME_NOT_EXIST    24163	/*! 指定名字的数据集不存在*/
#define	UGS_DUPLICATED_PARAMETERS_FOUND         24164	/*! 各个参数不能相同*/
#define	UGS_FAILED_TO_SEARCH_FIELD_INFO         24165	/*! 查找字段信息失败*/
#define	UGS_MISMATCH_SOURCE_DT_AND_TARGET_DT    24166	/*! 源数据集和目标数据集的类型必须相同*/
#define	UGS_CREATE_DT_ERROR                     24167	/*! 生成新数据集失败！*/
#define	UGS_INVALID_PASSWORD                    24168	/*! 口令错误！*/
#define	UGS_DISSOLVING                          24169	/*! 正在合并字段值相同的邻接对象...*/
#define	UGS_JOINTING_TABLE                      24170	/*! 正在连接属性数据表...*/
#define	UGS_ALL_FIELD_IN_CURRENT_DT             24171	/*! 当前数据集包含了要连接的数据表的所有字段，不需要再连接。*/
#define	UGS_NAME_NULL                           24172	/*! 名称不能为空!*/
#define	UGS_NAME_BEYOND_LIMIT                   24173	/*! 名称超过了规定字符长度!*/
#define	UGS_NAME_AGAIN_SYSTEMNAME               24174	/*! 名称不能与系统保留字段相同!*/
#define	UGS_NAME_PREFIX_ERROR                   24175	/*! 名称不能以数字或下划线开头!*/
#define	UGS_FIELD_NAME_ALREADY_EXISTS           24176	/*! 同名的字段已存在*/
#define	UGS_IS_BOF                              24177	/*! 已到记录头，不能执行相关操作。*/
#define	UGS_IS_EOF                              24178	/*! 已到记录尾，不能执行相关操作。*/
#define	UGS_HAS_NO_GEOMETRY                     24179	/*! 当前记录集不包含空间数据，不能执行空间数据相关操作。*/
#define	UGS_DT_NOT_OPEN                         24180	/*! 当前数据集没有打开。*/
#define	UGS_QUERY_GEOMETRY_ON_TABULAR           24181	/*! 试图在Tabular表中查询空间数据时出错。*/
#define	UGS_DS_IS_NOT_OPEN                      24182	/*! 数据源没有打开，不能执行相关操作。*/
#define	UGS_DS_INFO_IS_NOT_INTEGRATED           24183	/*! 连接数据源字符串非法。*/
#define	UGS_OUT_OF_SEMICOLON                    24184	/*! 缺失分号(;)*/
#define	UGS_OUT_OF_EQUAL                        24185	/*! 缺失等号(=)*/
#define	UGS_RS_IS_NOT_OPEN                      24186	/*! 记录集没有打开。*/
#define	UGS_QUERY_OPTION_IS_NONE                24187	/*! 查询选项错误。*/
#define	UGS_CANT_COPY_DT_FROM_IMGPLUGINS        24188	/*! 不能从外挂影像引擎中复制数据集*/
#define	UGS_DELETE_TABLE_FAILED                 24189	/*! 删除表失败*/
#define	UGS_DELETE_DT_REGISTER_INFO_FAILED      24190	/*! 删除注册表信息失败*/
#define	UGS_DELETE_DT_METADATA_FAILED           24191	/*! 删除元数据失败*/
#define	UGS_DELETE_SEQUENCE_FAILED              24192	/*! 删除序列失败*/
#define	UGS_DELETE_SPATIAL_INDEX_FAILED         24193	/*! 删除空间索引表失败*/
#define	UGS_DELETE_PYRAMUGS_TABLE_FAILED        24194	/*! 删除金字塔表失败*/
#define	UGS_DELETE_PYRAMUGS_DT_REGISTER_INFO_FAILED 24195	/*! 删除注册表中金字塔信息失败*/
#define	UGS_DELETE_PYRAMUGS_DT_MetaData_FAILED  24196	/*! 删除金字塔元数据失败*/
#define	UGS_CANNT_CREATE_ECW_OR_MRSID_BY_TEMPLATE 24197	/*! ECW和MRSID数据集不能由模板创建*/
#define	UGS_CANNT_COPY_NETWORK_OR_LINEZ_OR_LINEM_OR_POINTZ_BETWEEN_SDB_AND_SQLSERVER 24198	/*! 不能从SDB向SQLSERVER数据源复制LineZ，LineM，PointZ，Network数据集*/
#define	UGS_INVALID_FIELD_NAME_LENGTH           24199	/*! 字段(%s)长度大于30,创建失败*/
#define	UGS_DT_APPEND_FAILED_WITH_EXCEPTION     24200	/*! 数据集追加异常而终止*/
#define	UGS_SMETAB_ENGINE_NAME                  24201	/*! SuperMap MicroStation 引擎.*/
#define	UGS_SMETAB_MSG_INVALID_SQL_SENTENCE     24202	/*! 错误的SQL查询语句!*/
#define	UGS_AUTOCAD_ENGINE_NAME                 24203	/*! SuperMap AutoCAD数据引擎*/
#define	UGS_ORCPLUS_ENGINE_NAME                 24204	/*! SDX+ for Oracle	*/
#define	UGS_ORCPLUS_NOT_SUPPORT_TYPE            24205	/*! SDX+ for Oracle 引擎目前还不支持这种类型的数据集。*/
#define	UGS_ORCPLUS_DB_VERSION_ERROR            24206	/*! 当前的SDX Plus for ORACLE不支持版本号%ld的数据源，请和SuperMap技术支持联系(support@supermap.com)。*/
#define	UGS_ORCPLUS_SYSTEMUSER_NOT_CREATE_DATASOURCE 24207	/*! 系统默认用户不可创建SUPERMAP数据源*/
#define	UGS_ORACLEPLUS_NOT_LOG_IN               24208	/*! 长事务用户没有登陆！*/
#define	UGS_ORAPLUS_RECORD_IS_CHECKED_BY_OTHERS 24209	/*! 当前记录被他人锁定！*/
#define	UGS_PREPARE_CREATE_DB                   24210	/*! 准备创建数据集...	*/
#define	UGS_CONNECT_TO_SERVER                   24211	/*! 连接到服务器...*/
#define	UGS_CREATING_SYSTEM_TABLE               24212	/*! 创建系统表 %s ...*/
#define	UGS_CREATING_TEMP_TABLE                 24213	/*! 创建临时表 %s ...*/
#define	UGS_SETING_DB_INFO                      24214	/*! 保存数据源信息...*/
#define	UGS_ORACLE_SPATIAL_ENGINE_NAME          24215	/*! Oracle Spatial 引擎	*/
#define	UGS_SPATIAL_DB_ENGINE                   24216	/*! SuperMap 空间数据引擎(SDB)*/
#define	UGS_MSG_SDB_DATA_CONVERT                24217	/*! 转化了 %d条记录*/
#define	UGS_MSG_CLOSE_OPENED_RS                 24218	/*! 请先关闭所有已经打开的记录集(recordset)!*/
#define	UGS_COMPACTING_DATASET                  24219	/*! 正在紧缩数据集*/
#define	UGS_SDBPLUS_ENGINE                      24220	/*! SuperMap 空间数据库引擎(SDB 5)*/
#define	UGS_MSG_SDBPLUS_INVALID_DATASET         24221	/*! 发现数据集的属性数据与空间数据不一致！数据集已坏。*/
#define	UGS_MSG_SDBPLUS_DATA_CONVERT            24222	/*! 转化了 %d条记录*/
#define	UGS_SQL_ENGINE_NAME                     24223	/*! SDX for SQL Server*/
#define	UGS_SQL_NOT_SUPPORT_TYPE                24224	/*! SDX for SQL Server 引擎目前还不支持这种类型的数据集。*/
#define	UGS_SQL_DATABASE_VERSION_ERROR          24225	/*! 当前的SDX for SQL SERVER不支持版本号为%s的数据源，请和SuperMap联系.*/
#define	UGS_SQL_RECORD_IS_CHECKED_BY_OTHERS     24226	/*! 当前记录正被其他用户锁定，不能执行编辑操作。*/
#define	UGS_SQL_NOT_LOG_IN                      24227	/*! 没有登录长事务环境，不能执行相关的操作。*/
#define	UGS_SQL_SOME_RECORDS_LOCKED_BY_OTHERS   24228	/*! 一些记录被其他用户锁定，所以不能执行针对全表的操作。*/
#define	UGS_MSG_SQL_BUILD_QD_TREE               24229	/*! 已处理了%ld条记录*/
#define	UGS_MSG_SQL_BUILDING_PYRAMID            24230	/*! 建立影像金字塔...*/
#define	UGS_IMAGE_PLUGINS_ENGINE                24231	/*! SuperMap 影像插件引擎。*/
#define	UGS_OSQLPLUS_ENGINE_NAME                24232	/*! SDX+ for SQL Server(ODBC)*/
#define	UGS_DATA_VERSION_ERROR                  24233	/*! SDX+ for SQL Server引擎版本不支持打开这个版本的数据源.*/
#define	UGS_ODBC_NONSUPPORT_PYRAMID             24234	/*! 不支持建立金字塔*/
#define	UGS_ODBC_CAN_NOT_UNRIGISTER             24235	/*! 还有记录被其他人锁定，不能锁定、取消锁定。*/
#define	UGS_ODBC_NOT_LOG_IN                     24236	/*! 长事务用户没有登陆*/
#define	UGS_ODBC_CANNT_LOCK_TABLE               24237	/*! 有其他用户锁定记录不能进行全表操作,例如:锁定,解锁等.*/
#define	UGS_ODBC_NOT_AUTOLOCK                   24238	/*! 不是自动锁定状态，不能编辑或添加，请设置自动锁定状态或把要修改的记录锁定*/
#define	UGS_ODBC_RECORD_IS_CHECKED_BY_OTHERS    24239	/*! 记录被他人锁定，不能编辑*/
#define	UGS_ODBC_BE_TABLE_LOCK                  24240	/*! 当前数据已经被全表锁定,不能进行其他相关操作.	*/
#define	UGS_ODBC_DS_CONNECT_FAILED              24241	/*! 数据源建立连接失败！*/
#define	UGS_MSG_DATASOURCE_ALIAS_X_ALREADY_EXISTED 24242	/*! 数据源别名"%S"已经存在!*/
#define	UGS_MSG_MISSING_ENGINE                  24243	/*! 找不到类型为%d的SDX引擎*/
#define	UGS_MSG_DB_WORKSPACE_REQUIRE_CAPTION    24244	/*! 数据库版本的工作空间需要工作空间名字，或者工作空间重名。*/
#define	UGS_FIELD_COUNT_TOO_SMALL               24245	/*! 没有属性字段！*/
#define	UGS_RECORD_NO_IS_TOO_LARGE              24246	/*! 记录号太大*/
#define	UGS_DMRS_LINK_NOT_SUPPORT_SET_X2        24247	/*! DMRS不能被设置成（%s）*/
#define	UGS_ERROR_COV_MKDIR                     24248	/*! 生成目录错误/n*/
#define	UGS_ERROR_COV_NOSUPPORT_TYPE            24249	/*! 属性表有暂不支持的字段类型/n*/
#define	UGS_ERROR_COV_USERFIELDCOUNT            24250	/*! 用户字段出现错误/n*/
#define	UGS_ERROR_COV_MORE_USER_FIELD           24251	/*! 用户字段数目太多/n*/
#define	UGS_ERROR_COV_CREATE_USER_FIELD         24252	/*! 生成用户字段时错误/n*/
#define	UGS_ERROR_COV_FIELDTYPE                 24253	/*! 字段类型错误/n*/
#define	UGS_MSG_PMP_SQL_NO_ENOUGH_DISKSPACE     24254	/*! 现在是用快速方法导入数据到SQL引擎中，但磁盘空间可能不足！是否继续用快速方法导入数据？点击“YES”，则继续用快速方法导入数据；点击“NO”， 则使用传统方法导入数据。*/
#define	UGS_OUTPUTEX_MSG_CREATE_DATASET         24255	/*! 正在生成新的数据集......*/
#define	UGS_LYT_FIELD_NAME                      24256	/*! 字段名 : %s*/
#define	UGS_MISMATCH_DATASET_TYPE               24257	/*! 数据集类型不匹配*/
#define	UGS_MSG_FAILED_TO_BUILD_SPATIAL_INDEX   24258	/*! 创建空间索引失败！*/
#define	UGS_DTM_MSG_NO_REGION_OVERLAY           24259	/*! 数据集没有范围重叠*/
#define	UGS_SET_INPUT_POLYGON_TMPLAYER          24260	/*! 请先创建临时面数据集！*/
#define	UGS_IMAGE_MSG_SEARCH_ITEM               24261	/*! 搜索图斑*/
#define	UGS_IMAGE_MSG_FAILED_TO_ADD_NEW_RECORD  24262	/*! 添加新记录失败*/
#define	UGS_NOUN_EXPRESSION_CMB                 24263	/*! 表达式...*/
#define	UGS_FILED_OR_TABLE_NAME_IS_NULL         24264	/*! 判断传入的字段名或表名是否可用时，传入的名称为空*/
#define	UGS_NAME_LENGTH_OVERRUN                 24265	/*! 名称长度大于30个字符*/
#define	UGS_WMS_VERSION_INVALID                 24266	/*! 没有发现可用的WMS版本,或输入的URL不可用*/
#define	UGS_WFS_VERSION_INVALID                 24267	/*! 没有发现可用的WFS版本,或输入的URL不可用*/
#define	UGS_WCS_VERSION_INVALID                 24268	/*! 没有发现可用的WCS版本,或输入的URL不可用*/
#define	UGS_CREATING_WEBENGINE_IS_NONSUPPORT    24269	/*! 网络数据引擎不支持创建操作*/
#define	UGS_DELETE_NONE                         24270	/*! 没有删除任何数据集*/
#define	UGS_NOT_SUPPORT_THIS_WEB_DATASOURCE     24271	/*! 不支持的此种类型的网络数据源*/
#define	UGS_FAILED_TO_PARSE_WEB_DATASOURCE      24272	/*! 解析网络数据源能力失败*/
#define	UGS_COORDINATE_REFERENCE_IS_EMPTY       24273	/*! 坐标参考系为空*/
#define	UGS_FAILED_TO_PARSE_URL                 24274	/*! URL解析失败*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_RASTER 24275	/*! 网络数据引擎不支持创建栅格数据集*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_TOPO 24276	/*! 网络数据引擎不支持创建拓扑数据集*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_VECTOR 24277	/*! 网络数据引擎不支持创建矢量数据集*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_ROLLBACK   24278	/*! 网络数据引擎不支持回滚操作*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_COMMIT     24279	/*! 网络数据引擎不支持提交操作*/
#define	UGS_NOT_SPECIFY_ANY_LAYERS              24280	/*! 尚未指定任何图层,请尝试运行SetAllLayers函数。*/
#define	UGS_WMS_SERVER_REPORT_AN_EXCEPTION      24281	/*! WMS服务器报告了一个异常*/
#define	UGS_MARKUP_NOT_FIND_CAPABILITY_TAG      24282	/*! Makup 没有发现Capability标签*/
#define	UGS_CAPABILITY_XML_FILE_PATH_IS_EMPTY   24283	/*! Capabilities XML文件路径为空*/
#define	UGS_LAYER_ARRAY_IS_EMPTY                24284	/*! 图层数组为空*/
#define	UGS_SIZE_OF_GETMAP_IAMEGE_IS_ZERO       24285	/*! GetMap 影像文件大小为0*/
#define	UGS_WMS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED 24286	/*! WMS GetMap请求未生成内存数据源*/
#define	UGS_NONE_VISIBLE_LAYERS                 24287	/*! 没有任何可视图层显示*/
#define	UGS_WFS_SERVER_REPORT_AN_EXCEPTION      24288	/*! WFS服务器报告了一个异常*/
#define	UGS_GETFEATURE_XML_FILE_PATH_IS_EMPTY   24289	/*! GetFeature XML文件路径为空*/
#define	UGS_MARKUP_NOT_FIND_XS_COMPLEXCONTENT_TAG 24290	/*! Makup 没有发现xs:complexContent标签*/
#define	UGS_MARKUP_NOT_FIND_XS_SCHEMA_TAG       24291	/*! Makup 没有发现xs:schema标签*/
#define	UGS_DESCRIBE_XML_FILE_PATH_IS_EMPTY     24292	/*! Describe XML文件路径为空*/
#define	UGS_WFS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED 24293	/*! WFS GetFeature请求未生成内存数据源*/
#define	UGS_SIZE_OF_DESCRIBE_XML_IS_ZERO        24294	/*! Describe XML文件大小为0*/
#define	UGS_SIZE_OF_GETFEATURE_XML_IS_ZERO      24295	/*! GetFeature XML文件大小为0*/
#define	UGS_GENERAL_QUERY_RESULT_IS_NULL        24296	/*! General查询没有得到任何记录*/
#define	UGS_IDS_QUERY_RESULT_IS_NULL            24297	/*! IDs查询没有得到任何记录*/
#define	UGS_IDS_ARRAY_COUNT_IS_MISMATCH         24298	/*! IDs 数组个数不匹配*/
#define	UGS_ILLEGAL_QUERY_BOUNDS                24299	/*! 查询边界错误*/
#define	UGS_WEB_ENGINE_NOT_SUPPORT_THIS_WFS_VERSION 24300	/*! 网络数据引擎不支持该WFS版本*/
#define	UGS_MARKUP_NOT_FIND_FEATURETYPELIST_TAG 24301	/*! Makup 没有发现FeatureTypeList标签*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WFS_VERSION 24302	/*! 网络数据引擎只支持WFS1.0.0版本*/
#define	UGS_CAPABILITIES_XML_DO_NOT_EXIST       24303	/*! Capabilities XML文件不存在*/
#define	UGS_WCS_SERVER_REPORT_AN_EXCEPTION      24304	/*! WCS服务器报告了一个异常*/
#define	UGS_DESCRIBE_XML_DO_NOT_EXIST           24305	/*! Describe XML文件不存在*/
#define	UGS_FAILED_TO_TRANSFER_IMAGE_TO_RASTER  24306	/*! 从影像到栅格的数据转换失败*/
#define	UGS_WEBENGINE_NOT_SUPPORT_BEGINTRANS    24307	/*! 网络数据引擎不支持开始事务操作*/
#define	UGS_MARKUP_NOT_FIND_XS_COMPLEXTYPE_TAG  24308	/*! Makup 没有发现xs:complexType标签*/
#define	UGS_WCS_NOT_SUPPORT_SETVISIBLE_LAYER    24309	/*! 网络数据引擎的WCS数据集不支持设置可见图层的操作*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERINDEXES 24310	/*! 网络数据引擎的WCS数据集不支持获取可见图层索引*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERTILES 24311	/*! 网络数据引擎的WCS数据集不支持获取可见图层标题*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERNEMES 24312	/*! 网络数据引擎的WCS数据集不支持获取可见图层名称*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERINDEXS   24313	/*! 网络数据引擎的WCS数据集不支持获取所有图层的索引*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERTITLES   24314	/*! 网络数据引擎的WCS数据集不支持获取所有图层的标题*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERNAMES    24315	/*! 网络数据引擎的WCS数据集不支持获取所有图层的名称*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WCS_VERSION 24316	/*! 网络数据引擎只支持WCS1.0.0版本*/
#define	UGS_PARSE_FILE_NOT_EXIST                24317	/*! 解析文件不存在*/
#define	UGS_HTTP_ERROR_NUMBER_OVERRUN           24318	/*! HTTP 错误号大于300*/
#define	UGS_FILE_GOT_FROM_WEB_IS_EMPTY          24319	/*! 从网络上得到的文件为空*/
#define	UGS_NOT_GET_FILE_FROM_WEB_CORRECTLY     24320	/*! 没有正确地从网络上得到文件*/
#define	UGS_OGC_SERVER_REPORT_AN_EXCEPTION      24321	/*! OGC 网络服务器报告了一个异常*/
#define	UGS_INVALID_OGC_FILE                    24322	/*! 这不是一个正确的OGC网络数据文件*/
#define	UGS_FAILED_TO_CONNECT_DB                24323	/*! 连接数据库失败*/
#define	UGS_DATASET_INDEX_TYPE_IS_EMPTY         24324	/*! 数据集索引类型为空*/
#define	UGS_DATASET_IS_NULL_OR_VERSION_NUM_INVALID 24325	/*! 数据集为空或版本号非法*/
#define	UGS_THIS_DATASET_NOT_HAVE_VERSION_OPTION 24326	/*! 该数据集不存在版本选项*/
#define	UGS_FAILED_TO_GET_DEFAULT_INDEX_PARAMETER 24327	/*! 获取默认索引参数失败*/
#define	UGS_TILEINDEX_FAILED_TO_UNREGISTER_     24328	/*! 图幅索引反注册失败*/
#define	UGS_FAILED_TO_REGISTER_LIBRARY          24329	/*! 注册Library失败*/
#define	UGS_FAILED_TO_GET_TILE_SUBDATASET       24330	/*! 获取图幅索引子数据集失败*/
#define	UGS_FAILED_TO_QUERY_TITLE_DATASET       24331	/*! 查询图幅索引数据集失败*/
#define	UGS_FAILED_TO_GET_TILE_DATASET          24332	/*! 获取图幅索引数据集失败*/
#define	UGS_FAILED_TO_CREATE_TILE_DATASET       24333	/*! 创建图幅数索引据集失败*/
#define	UGS_THIS_DATASET_CANNOT_CREATE_DYNAMIC_INDEX 24334	/*! 不支持该类型的数据集创建动态索引*/
#define	UGS_THE_QUALITY_PARAMETER_TO_CREATE_RTREE_INDEX 24335	/*! 创建R树索引的Quality参数无效*/
#define	UGS_NOT_SUPPORT_THE_INDEX               24336	/*! 不支持的索引类型*/
#define	UGS_DATASET_OR_RTREE_POINTER_IS_NULL    24337	/*! 数据集指针或者R树指针为空*/
#define	UGS_INCORRECT_EDIT_MODE                 24338	/*! 编辑模式错误*/
#define	UGS_CANNOT_UPDATE_INDEX_FOR_LIBID_NOT_EXIST 24339	/*! LibID不存在，无法更新索引*/
#define	UGS_FAILED_TO_QUERY_FOR_NOT_TILE_INDEX  24340	/*! 该数据集不是图幅索引，查询失败*/
#define	UGS_INDEX_TYPE_MISMATCH                 24341	/*! 索引的类型不符*/
#define	UGS_FAILED_TO_GET_THE_GRID_CORRELATIVE_WITH_QUERY_OBJECTS 24342	/*! 提取与查询对象相关的格子失败*/
#define	UGS_FAILED_TO_FILETER_OBJECT_FROM_THE_GIRD 24343	/*! 从相关格子中过滤对象失败*/
#define	UGS_SCANLINE_ROW_OVERRUN                24344	/*! 扫描线行超过数据集边界*/
#define	UGS_SCANLINE_BEGINING_COLUMN_OVERRUN    24345	/*! 扫描线开始列超过数据集边界*/
#define	UGS_ECW_NOT_SUPPORT_TO_GET_SCANLINE     24346	/*! ECW数据集不支持得到扫描线*/
#define	UGS_QUERY_CURSOR_HANDLE_IS_NULL         24347	/*! 查询游标的语句句柄为空*/
#define	UGS_FAILED_TO_TRANSCOMMIT_DATA          24348	/*! 提交数据失败*/
#define	UGS_FILED_INDEX_NOT_EXIST               24349	/*! 字段索引不存在*/
#define	UGS_ECW_AND_MRSID_NOT_SUPPORT_BULIDPYRAMID 24350	/*! 不支持对ECW和MrSID建立金字塔*/
#define	UGS_IMAGEBLOCK_LINE_LESS_THAN_ONE       24351	/*! 影像块的行数小于1非法*/
#define	UGS_HEIGHT_AND_WIDTH_ILLEGAL            24352	/*! 高度和宽度不合法*/
#define	UGS_RASTER_FAILED_TO_REGISTER_OPTION    24353	/*! 栅格数据集注册选项信息失败*/
#define	UGS_RASTER_FAILED_TO_UNREGISTER_OPTION  24354	/*! 栅格数据集注销选项信息失败*/
#define	UGS_DATASET_NOT_MODIFIED                24355	/*! 数据集没有修改*/
#define	UGS_INDEX_TABLE_EXIST                   24356	/*! 该索引表已经存在*/
#define	UGS_FILED_NAME_CANNOT_BE_EMPTY          24357	/*! 字段名称不能为空*/
#define	UGS_FILED_NAME_AND_FORMAT_CANNOT_BE_EMPTY 24358	/*! 字段别名及格式不能为空*/
#define	UGS_NOT_SUPPORT_THIS_STATISTIC_MODE     24359	/*! 不支持此统计模式*/
#define	UGS_RECORD_AT_THIS_INDEX_NOT_EXIST      24360	/*! 该索引的记录不存在*/
#define	UGS_RECORDSET_AT_THIS_INDEX_NOT_EXIST   24361	/*! 索引的记录集不存在*/
#define	UGS_TILE_INDEX_TABLE_NOT_EXIST          24362	/*! 图幅索引表不存在*/
#define	UGS_DATASET_NOT_HAVE_THIS_REGISTER_OPTION 24363	/*! 数据集不存在该注册选项*/
#define	UGS_FAILED_TO_SAVE_DATASOURCE_INFO      24364	/*! 保存数据源信息失败*/
#define	UGS_LOADING_WORKSPACE_NAME_IS_EMPTY     24365	/*! 传入的工作空间名为空*/
#define	UGS_DATASOURCE_NOT_OPEN                 24366	/*! 数据源未打开*/
#define	UGS_FAILED_TO_START_TRANSACTION         24367	/*! 开始事务失败*/
#define	UGS_NOT_START_TRANSACTION               24368	/*! 未开始事务*/
#define	UGS_RECORD_NOT_EDITABLE                 24369	/*! 该记录处于非编辑模式*/
#define	UGS_CURSOR_IS_FORWARD_ONLY              24370	/*! 该游标是前向滑动游标*/
#define	UGS_GEOMETRY_ADDED_IS_NULL              24371	/*! 添加的对象为空*/
#define	UGS_LINE_IS_ILLEGAL                     24372	/*! 该线对象非法*/
#define	UGS_FILED_NOT_EXIST                     24373	/*! 该字段不存在*/
#define	UGS_NOT_SUPPORT_THIS_TYPE_GEOMETRY      24374	/*! 不支持该类型对象*/
#define	UGS_FILED_AT_THE_INDEX_NOT_EXIST        24375	/*! 该索引的字段不存在*/
#define	UGS_RECORD_EDIT_MODE_ILLEGAL            24376	/*! 该记录的编辑模式不合法*/
#define	UGS_THE_RECORD_INDEX_OVERRUN            24377	/*! 当前记录索引超过记录数*/
#define	UGS_THE_RECORD_INDEX_ILLEGAL            24378	/*! 当前记录索引非法*/
#define	UGS_NOT_SUPPORT_THE_QUERY_TYPE          24379	/*! 不支持该查询类型*/
#define	UGS_CURSOR_HANDLE_IS_NULL               24380	/*! 游标句柄为空*/
#define	UGS_FAILED_TO_CREATE_DATASOURCE_VERSION 24381	/*! 创建数据源版本失败*/
#define	UGS_FAILED_TO_DELETE_DATASOURCE_VERSION 24382	/*! 删除数据源版本失败*/
#define	UGS_RECORD_COUNT_IS_ZERO                24383	/*! 记录集的记录数为0*/
#define	UGS_FAILED_TO_FETCH_DATA                24384	/*! 取数据失败*/
#define	UGS_FAILED_TO_SCAN_FIELD_INFO           24385	/*! 扫描字段信息失败*/
#define	UGS_ID_ARRAY_COUNT_IS_ZERO              24386	/*! ID数组个数为0*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY_FILED     24387	/*! 记录集中没有几何字段*/
#define	UGS_THE_RECORD_ID_IS_ZERO               24388	/*! 当前记录的ID为0*/
#define	UGS_ILLEGAL_DATA_FOR_GEOMETY_SIZE_LESSTHAN_EIGHT_BYTE 24389	/*! 几何对象的存储长度小于8字节，非法数据*/
#define	UGS_OVERRUN_RECORDSET_BOUND             24390	/*! 超出记录集范围*/
#define	UGS_MOVE_TO_EOF                         24391	/*! 到达文件末尾*/
#define	UGS_RECORDSET_NOT_OPEN                  24392	/*! 记录集未打开*/
#define	UGS_MOVE_TO_BOF                         24393	/*! 已到达记录集头*/
#define	UGS_NOT_FIND_FILED                      24394	/*! 未找到字段*/
#define	UGS_FAILED_TO_GET_TEMPTABLE             24395	/*! 获取临时关联表失败*/
#define	UGS_TILE_GEOMETRY_ERROR                 24396	/*! 图幅索引数据集的图幅几何对象错误*/
#define	UGS_TEMPLATE_NAME_IS_EMPTY              24397	/*! 模板名为空*/
#define	UGS_TEMPLATE_FILE_NOT_EXIST             24398	/*! 模板文件不存在*/
#define	UGS_TEMPLATE_NAME_ALREADY_EXISTED       24399	/*! 模板名已存在*/
#define	UGS_TEMPLATE_FILE_IS_EMPTY              24400	/*! 模板文件内容为空*/
#define	UGS_MAPPING_ALREADY_EXIST               24401	/*! 映射已存在*/
#define	UGS_FAILED_TO_GET_DATASET_INITIAL_INFO  24402	/*! 数据集初始信息获取失败*/
#define	UGS_ORIGINAL_COORDINATES_SYSTEM_IS_NULL 24403	/*! 源坐标系为空*/
#define	UGS_ORGINAL_COORDINATES_NOT_PROJECTION_AND_TARGET_COORDINATES_IS_NULL 24404	/*! 源坐标系不是投影坐标系，目标坐标系为空*/
#define	UGS_ORGINAL_OR_TARGET_COORDINATES_IS_PLANE_COORDINATE 24405	/*! 源坐标系或目标坐标系有一个是平面坐标系*/
#define	UGS_LONGITUDE_LATITUDE_SAME_COORDINATE_SYSTEM 24406	/*! 经纬度 ==> 经纬度,坐标系相同*/
#define	UGS_PROJECTION_SAME_COORDINATE_SYSTEM   24407	/*! 投影==>投影，坐标系相同*/
#define	UGS_APPENDING_DATASET_TYPE_MISMATCH     24408	/*! 追加的数据集类型不匹配*/
#define	UGS_CANNOT_DELETE_FOR_HAVING_UNCOMMITTABLE_DATA 24409	/*! 删除记录之前有未提交的数据，且自动提交这些数据失败，无法进行删除操作*/
#define	UGS_ID_IS_ZERO_CANNOT_DELETE            24410	/*! 当前ID值为0，无法删除*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY           24411	/*! 记录集中没有几何对象记录*/
#define	UGS_ID_IS_ZERO                          24412	/*! 当前记录的ID为0*/
#define	UGS_NOT_FIND_MATCHING_FILED             24413	/*! 未找到匹配的字段*/
#define	UGS_HAVE_UNCOMMITTABLE_DATA_AND_FAILED_TO_AUTOCOMMIT 24414	/*! 存在未提交的编辑，自动提交，但提交失败*/
#define	UGS_ALREADY_UNEDITABLE                  24415	/*! 已经是非编辑状态*/
#define	UGS_DATASET_POINTER_IS_NULL_CANNOT_REGISTER_VERSION 24416	/*! 数据集指针为空，无法注册版本*/
#define	UGS_FAILED_TO_CREATE_A_TABLE            24417	/*! 创建A表失败*/
#define	UGS_DATASET_POINTER_IS_NULL_CANNOT_COMMIT_VERSION 24418	/*! 数据集指针为空，无法提交版本*/
#define	UGS_FAILED_TO_COMMIT_FOR_VERSION_NOT_EXIST 24419	/*! SmVersions中不存在该版本，提交失败*/
#define	UGS_FAILED_TO_COMMIT_FOR_DATASET_POINTER_IS_NULL 24420	/*! 数据集指针为空，提交失败*/
#define	UGS_FAILED_TO_ROLLBACK_FOR_NOT_REGISTER_VERSION 24421	/*! 数据集没有注册版本数据集，回滚失败*/
#define	UGS_FAILED_TO_COMMIT_VERSION_FOR_FAILED_TO_UPDATE_INDEX 24422	/*! 索引更新失败，版本提交失败*/
#define	UGS_FAILED_TO_UPDATE_INDEX_FOR_FAILED_TO_OPEN_DATASET 24423	/*! 数据集打开失败，索引更新失败*/
#define	UGS_CANNOT_ADD_DATASET_FOR_FAILED_TO_OPEN_DATASET 24424	/*! 数据集打开失败，无法添加数据集*/
#define	UGS_CANNOT_GET_FILELD_INFO_FOR_FAILED_TO_OPEN_DATASET 24425	/*! 获取字段信息失败，数据集打开失败*/
#define	UGS_CANNOT_MODIFY_INFO_FOR_DATASET_IS_READ_ONLY 24426	/*! 数据集为只读状态，无法修改信息*/
#define	UGS_FAILED_TO_CREATE_DATASET_FOR_ALREADY_EXIST_IN_REGEDIT 24427	/*! 注册表中已经存在相关记录，创建数据集失败*/
#define	UGS_FAILED_TO_CREATE_NETWORK_SUBDATASET 24428	/*! 创建网络数据集的子数据集失败*/
#define	UGS_SUBDATASET_IS_NULL                  24429	/*! 子数据集为空*/
#define	UGS_NOT_TILE_INDEX_CANNOT_GET_TITLE_ID  24430	/*! 当前索引非图幅索引，不能获取图幅ID*/
#define	UGS_FIELD_TYPE_ILLEGAL                  24431	/*! 字段类型非法*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_DATASET_NOT_OPEN 24432	/*! 数据集未打开，无法创建字段*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_FILED_NAME_ILLEGAL 24433	/*! 字段名称非法，创建字段失败*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_FILED_NAME_LENGTH_OVERRUN 24434	/*! 字段名称长度超过30，创建字段失败*/
#define	UGS_FAILED_TO_DELETE_FIELD_FOR_NO_MATCHING_FIELD_NAME 24435	/*! 没有匹配的字段名称，删除字段失败*/
#define	UGS_LOADING_PARAM_ILLEGAL               24436	/*! 传入参数非法，请检查*/
#define	UGS_CANNOT_DELETE_SYSTEM_FIELD          24437	/*! 系统字段，无法删除*/
#define	UGS_FAILED_TO_GET_FIELD_FOR_NO_MATCHING_FIELD_NAME 24438	/*! 未找到匹配字段名称,获取字段信息失败*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY_CANNOT_APPEND_RECORD 24439	/*! 记录集中没有几何对象，无法向非纯属性表数据集中追加记录*/
#define	UGS_FIELD_NAME_ALREADY_EXIST            24440	/*! 字段名已存在*/
#define	UGS_NAME_ILLEGAL                        24441	/*! 非法名称*/
#define	UGS_NOT_SUPPORT_THIS_ORACLE_DATA_TYPE   24442	/*! 不支持的Oracle数据类型*/
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_TILE_INDEX 24443	/*! 该类型数据集不支持图幅索引*/
#define	UGS_FAILED_TO_CREATE_TILE_SUBDATASET    24444	/*! 创建图幅子数据集失败*/
#define	UGS_CANNOT_UNREGISTER_FOR_HAVE_NOT_REGISTERED 24445	/*! 未注册的选项，无法进行反注册*/
#define	UGS_FAILED_TO_DELETE_FOR_NOT_FIND_SUBDATASET 24446	/*! 未找到子数据集，删除失败*/
#define	UGS_PJCONVERT_POINTER_IS_NULL_OR_DATASOURCE_COORDINATES_IS_PLANE_COORDINATES 24447	/*! 坐标系转换计算器指针为空，或数据源为平面坐标系。*/
#define	UGS_PJCONVERT_TARGET_PJSYSTEM_IS_PLANE_COORDINATES 24448	/*! 坐标系转换计算器目标投影坐标系为平面坐标系。*/
#define	UGS_PJCOORDSYS_POINTER_IS_NULL_OR_DATASOURCE_COORDSYS_IS_PLANE_COORDSYS 24449	/*! 投影坐标系定义指针为空,或数据源为投影坐标系*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_LONGITUDE_LATITUDE 24450	/*! 投影坐标系定义的空间坐标系不是经纬度坐标系。*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_PJCOORDSYS  24451	/*! 投影坐标系定义的空间坐标系不是投影坐标系。*/
#define	UGS_NOT_FIND_ENGINE_DYNAMIC_LIB_DEFINE  24452	/*! 没有找到相关引擎的动态库定义*/
#define	UGS_FAILED_TO_SET_THE_VERSION_BY_VERSION_NAME 24453	/*! 以版本名设置当前版本失败*/
#define	UGS_FAILED_TO_SET_THE_VERSION_BY_VERSION_ID 24454	/*! 以版本号设置当前版本失败*/
#define	UGS_FAILED_TO_GET_VERSION_INFO          24455	/*! 得到版本信息失败*/
#define	UGS_DATASET_FAILED_TO_REGISTER_VERSION  24456	/*! 注册数据集为版本失败*/
#define	UGS_DATASET_FAILED_TO_UNREGISTER_VERSION 24457	/*! 反注册数据集版本失败*/
#define	UGS_FAILED_TO_COMMIT_TO_DEFAULT_VERSION 24458	/*! 提交到主版本失败*/
#define	UGS_FAILED_ROLLBACK_VERSION             24459	/*! 清除一个版本的编辑失败*/
#define	UGS_IMGBLOCK_INDEX_ID_LESSTHAN_ZERO     24460	/*! 指定影像块索引号小于0*/
#define	UGS_RASTER_FAILED_TO_CALCULATE_EXTREMUM_BY_REGION 24461	/*! CalculateExtremumByRegion栅格计算极值失败*/
#define	UGS_FAILED_TO_SET_IMGBLOCK              24462	/*! 设置影像块失败*/
#define	UGS_FAILED_TO_APPEND_RECORDSET          24463	/*! 追加记录集失败*/
#define	UGS_SPATIALQUERY_OPTION_ILLEGAL         24464	/*! 空间查询选项非法*/
#define	UGS_VALUE_IMPORTED_ILLEGAL              24465	/*! 传入的值非法*/
#define	UGS_GRID_IMPORTED_IS_NULL               24466	/*! 传入的网格为空*/
#define	UGS_CANNOT_GET_CONNECTION_INFO_FOR_XML_IS_EMPTY 24467	/*! XML文件为空,不能得到连接信息*/
#define	UGS_CANNOT_GET_CONNECTION_INFO_FOR_XML_STRING_FORMAT_MISMATCH 24468	/*! XML字符串格式不对,不能得到连接信息*/
#define	UGS_IMAGE_POINTER_IS_NULL               24469	/*! 影像数据集指针为空*/
#define	UGS_GET_DATA_STORING_METADATA           24470	/*! 得到存储元数据的数据*/
#define	UGS_FAILED_TO_INITIALIZE_DATASET        24471	/*! 初始化数据集失败*/
#define	UGS_THE_METADATA_NOT_EXIST              24472	/*! 当前数据集的元数据不存在*/
#define	UGS_FAILED_TO_GET_METADATA_FOR_METADATA_COUNT_IS_ZERO 24473	/*! 元数据元素个数为0,获取元数据失败*/
#define	UGS_FAILED_TO_GET_METADATA_FOR_NOT_FIND_METADATA_ELEMENT 24474	/*! 元数据元素没有找到,获取元数据失败*/
#define	UGS_FAILED_TO_QUERY_BY_SUBBOUNDS        24475	/*! 以子边框查询失败*/
#define	UGS_FAILED_TO_GET_QUERY_DEFINE_FROM_XML 24476	/*! 没有找到QueryDef标签，从XML文件中得到查询定义失败*/
#define	UGS_THE_DATASET_NOT_SUPPORT_INDEX       24477	/*! 当前数据集不支持索引*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX     24478	/*! 当前数据集不需要创建索引*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX_FOR_NOT_DIRTY 24479	/*! 当前数据集索引不脏不需要创建索引*/
#define	UGS_POINT_CANNOT_BUILDINDEX             24480	/*! 点数据集不能创建索引*/
#define	UGS_MEMORY_DATASOURCE_COUNT_IS_ZERO     24481	/*! 内存数据源的个数为0*/
#define	UGS_INDEX_BOUNDS_ERROR                  24482	/*! 建立索引需要的范围有误*/
#define	UGS_NOT_SUPPORT_THE_EDIT_MODE           24483	/*! 不支持该编辑模式*/
#define	UGS_GEOMETRY_UNKNOWN                    24484	/*! 无法识别的几何对象类型*/
#define	UGS_FAILED_TO_GET_FILED_VALUE_FOR_NO_MATCHING_FILED_NAME 24485	/*! 没有匹配的字段名，获取字段值失败*/
#define	UGS_NO_MATCHING_ID                      24486	/*! 没有匹配的ID*/
#define	UGS_INVALID_RECORD_POINTED_BY_THE_RECORDSET 24487	/*! 记录集当前指向的记录无效*/
#define	UGS_CANNOT_CHANGE_PASSWORD_FOR_DATASOURCE_NOT_OPEN 24488	/*! 数据源未打开，不能修改密码*/
#define	UGS_USERNAME_IS_EMPTY                   24489	/*! 用户名为空，非法*/
#define	UGS_CANNOT_STARTTRANS_FOR_DATASOURCE_NOT_OPEN 24490	/*! 数据源未打开，无法开始事务*/
#define	UGS_CANNOT_STARTTRANS_FOR_NOT_OPEN_BY_TRANS 24491	/*! 不是以事务方式打开，无法开始事务*/
#define	UGS_CANNOT_LOGIN_FOR_DATASOURCE_VERSION_MISMATCH 24492	/*! 数据源版本不对，无法登录*/
#define	UGS_CANNOT_LOGIN_FOR_DATASOURCE_NOT_OPEN 24493	/*! 数据源未打开，无法登录*/
#define	UGS_CANNOT_DELETE_DATASET_FOR_DATASOURCE_NOT_OPEN 24494	/*! 数据源未打开，无法删除数据集*/
#define	UGS_PBYTE_POINTER_IS_NULL               24495	/*! pByte 传入空指针*/
#define	UGS_CANNOT_SAVE_WORKSPACE_FOR_FAILED_TO_CONNECT_DATABASE 24496	/*! 数据库连接失败，无法保存工作空间*/
#define	UGS_WORKSPACE_NAME_IS_EMPTY             24497	/*! 传入参数：“工作空间名称”为空*/
#define	UGS_CANNOT_GET_WORKSPACE_FOR_FAILED_TO_CONNECT_DATABASE 24498	/*! 数据库连接失败,无法获取工作空间*/
#define	UGS_CANNOT_GET_WORKSPACE_INFO_FOR_FAILED_TO_CONNECT_DATABASE 24499	/*! 数据库连接失败,无法获取工作空间信息*/
#define	UGS_CANNOT_DELETE_WORKSPACE_INFO_FOR_FAILED_TO_CONNECT_DATABASE 24500	/*! 数据库连接失败,无法删除工作空间信息*/
#define	UGS_CANNOT_CREATE_VERSION_FOR_DATASOURCE_NOT_OPEN 24501	/*! 数据源未打开,无法创建新版本*/
#define	UGS_IMPORTING_VERSION_NAME_IS_NULL      24502	/*! 传入空的版本名称,请检查*/
#define	UGS_VERSION_ID_ERROR                    24503	/*! 版本号错误,请检查*/
#define	UGS_DATASOURCE_NOT_CREATE_VERSION       24504	/*! 该数据源没有创建版本*/
#define	UGS_CANNOT_CREATE_RASTER_FOR_WIDTH_OR_HEIGHT_IS_ZERO 24505	/*! 栅格数据集的宽或高为0, 无法创建*/
#define	UGS_CANNOT_CREATE_FOR_NOT_SUPPORT_THE_DATASET_TYPE 24506	/*! 不支持的数据集类型,无法创建*/
#define	UGS_FAILED_TO_CREATE_RASTER_FOR_INVALID_PIXEL_FORMAT 24507	/*! 不支持的像素格式,创建栅格数据集失败*/
#define	UGS_CANNOT_BULID_PYRAMID_FOR_FAILED_TO_OPEN_DATASET 24508	/*! 数据集打开失败,无法创建金字塔*/
#define	UGS_FAILED_TO_CREATE_PYRAMID_SUBDATASET 24509	/*! 创建金字塔子数据集失败*/
#define	UGS_IMGBLOCK_SIZE_LESSTHAN_ONE          24510	/*! 影像块大小小于1,非法数据*/
#define	UGS_DATASET_READONLY_CANNOT_SET_OPTION  24511	/*! 数据集为只读状态,无法设置选项*/
#define	UGS_TEMPTABLE_FAILED_TO_RELATE_QUERY    24512	/*! 临时表关联查询失败*/
#define	UGS_FAILED_TO_RELATE_QUERY              24513	/*! 关联查询失败*/
#define	UGS_FAILED_TO_COPY_FILED_VALUE          24514	/*! 拷贝字段值失败*/
#define	UGS_FAILED_TO_DELETE_RECORD             24515	/*! 删除记录失败*/
#define	UGS_CREATE_WORKSPACE_SMTABLE_FAILED     24516	/*! 创建工作空间的系统表失败*/
#define	UGS_NOT_SUPPORT_THIS_WEBENGINE          24517	/*! 不支持的网络引擎类型*/


// 数据格式转换处理信息：从25000开始编码
#define	UGS_CANNT_COPY_ECW_OR_MRSUGS_BETWEEN_DIFFERENT_ENGINES 25000	/*! MrSID和ECW数据只能在本地数据源之间拷贝*/
#define	UGS_AFC_DATAPMP_WRITE_LINE              25001	/*! 已输出 %ld 个线对象*/
#define	UGS_AFC_DATAPMP_WRITE_POLYGON           25002	/*! 已输出 %ld 个多边形对象*/
#define	UGS_AFC_DATAPMP_WRITE_POINT             25003	/*! 已输出 %ld 个点对象*/
#define	UGS_AFC_DATAPMP_WRITE_TEXT              25004	/*! 已输出 %ld 个文本对象*/
#define	UGS_AFC_DATAPMP_READ_LINE               25005	/*! 已输入 %ld 个线对象*/
#define	UGS_AFC_DATAPMP_READ_POLYGON            25006	/*! 已输入 %ld 个多边形对象*/
#define	UGS_AFC_DATAPMP_READ_POINT              25007	/*! 已输入 %ld 个点对象*/
#define	UGS_AFC_DATAPMP_READ_TEXT               25008	/*! 已输入 %ld 个文本对象*/
#define	UGS_BEGIN_READ_IN_LINE                  25009	/*! 开始转入线对象......*/
#define	UGS_BEGIN_READ_IN_POINT                 25010	/*! 开始转入点对象......*/
#define	UGS_BEGIN_READ_IN_POLYGON               25011	/*! 开始转入多边形对象......*/
#define	UGS_BEGIN_READ_IN_LINE_ATTRIBUTE        25012	/*! 开始转入线对象的属性......*/
#define	UGS_BEGIN_READ_IN_POLYGON_ATTRIBUTE     25013	/*! 开始转入多边形对象的属性......*/
#define	UGS_READED_IN_LINE_ATTRIBUTE            25014	/*! 已经转入 %ld 个线对象的属性......*/
#define	UGS_READED_IN_POLYGON_ATTRIBUTE         25015	/*! 已经转入 %ld 个多边形对象的属性......*/
#define	UGS_AFC_DATAPMP_READED_OBJ              25016	/*! 已输入%ld 个对象*/
#define	UGS_BEGIN_READ_IN_TEXT                  25017	/*! 开始转入注记对象......*/
#define	UGS_BEGIN_READ_IN_NODE_ATTRIBUTE        25018	/*! 读入节点属性表......*/
#define	UGS_BEGIN_READ_IN_LAB_ATTRIBUTE         25019	/*! 开始转入标识点属性...*/
#define	UGS_IMAGE_FORMAT_NOT_SUPPORTED          25020	/*! 对不起，本系统目前不支持该格式*/
#define	UGS_READ_BMP_FILE                       25021	/*! 正在转入BMP图像*/
#define	UGS_WRITE_BMP_FILE                      25022	/*! 正在转出BMP图像*/
#define	UGS_READ_TIFF_FILE                      25023	/*! 正在转入TIFF图像*/
#define	UGS_WRITE_TIFF_FILE                     25024	/*! 正在转出TIFF图像*/
#define	UGS_READ_JEPG_FILE                      25025	/*! 正在转入JPEG图像*/
#define	UGS_WRITE_JEPG_FILE                     25026	/*! 正在转出JPEG图像*/
#define	UGS_BEGIN_WRITE_IN_POINT                25027	/*! 开始转出点对象......*/
#define	UGS_BEGIN_WRITING_IN_NETWORK            25028	/*! 开始转出简单线对象......*/
#define	UGS_BEGIN_WRITE_IN_LINE                 25029	/*! 开始转出复杂线对象......*/
#define	UGS_BEGIN_WRITING_IN_REGION             25030	/*! 开始转出面对象......*/
#define	UGS_BEGIN_WRITE_IN_TEXT                 25031	/*! 开始转出注记对象......*/
#define	UGS_WRITE_GRID_FILE                     25032	/*! 正在转出 Grid 数据！*/
#define	UGS_READ_GRID_FILE                      25033	/*! 正在转入 Grid 数据！*/
#define	UGS_IMPORT_TILE                         25034	/*! 已经转入%ld/%ld 个影像块...	*/
#define	UGS_PMP_CREATING_TEMP_DATA              25035	/*! 正在准备临时数据，这可能需要几分钟,请稍候......*/
#define	UGS_AFC_DATAPMP_READ_CAD                25036	/*! 已输入 %ld 个复合对象*/
#define	UGS_GXML_FEATURE_IMPORT                 25037	/*! 已输入 %ld 个对象*/
#define	UGS_GXML_EXPORT_RECORD                  25038	/*! 已输出 %ld 个对象*/
#define	UGS_AFC_DATAPMP_READED_ATTRITUBE        25039	/*! 已输入%d条属性数据*/
#define	UGS_VCT_VARCHAR_FIND                    25040	/*! 正在搜索文件%s的变长字符，准备导入属性数据...*/


// 栅格分析处理信息：从26000开始编码
#define	UGS_IMGREG_ERR_INTERRECTIFY             26000	/*! 解方程错误,无法求出系数! 请增加或修改控制点!*/
#define	UGS_IMGREG_NEW_LAYER_NAME               26001	/*! 请输入新建栅格图层名称：*/
#define	UGS_IMGREG_TRANSFORM                    26002	/*! 影像转换……*/
#define	UGS_OUTPUTEX_TOO_LARGE_RESOLUTION       26003	/*! 输入分辨率太大！*/
#define	UGS_OUTPUTEX_MANAGEMENT_ERROR           26004	/*! 处理过程中出错！*/
#define	UGS_OUTPUTEX_MSG_TITLE                  26005	/*! 地图栅格化*/
#define	UGS_RECTIFY_TITLE                       26006	/*! 正在进行影像配准*/
#define	UGS_CONJOINT_AND_NORMALS                26007	/*! 计算法向量和邻接关系*/
#define	UGS_MSG_INVALID_ISOLIEN_DISTANCE        26008	/*! 非法的等高距*/
#define	UGS_MSG_FAILED_TO_TRACE_CLOSED_ISOLINE  26009	/*! 追踪闭合的等值线失败, 等值线高度是 %f。*/
#define	UGS_MSG_ASPECT                          26010	/*! 坡向*/
#define	UGS_MSG_SLOPE                           26011	/*! 坡度*/
#define	UGS_MSG_RECLASS                         26012	/*! 重分级*/
#define	UGS_DTM_MSG_CUTFILL                     26013	/*! 格网数据填挖方计算*/
#define	UGS_ERROR_INVERSIBLE_MATRIX             26014	/*! 区间重叠*/
#define	UGS_MSG_HILLSHADE                       26015	/*! 三维晕渲*/
#define	UGS_DTM_MSG_ANALYSIS                    26016	/*! 栅格分析*/
#define	UGS_DTM_MSG_HYD_DIR                     26017	/*! 流向计算*/
#define	UGS_DTM_MSG_HYD_ACC                     26018	/*! 累积汇水量*/
#define	UGS_DTM_MSG_HYD_LENGTH                  26019	/*! 流长*/
#define	UGS_DTM_MSG_INVALID_CELLSIZE            26020	/*! 指定的结果栅格大小无效*/
#define	UGS_DTM_MSG_NOT_RASTER                  26021	/*! 试图用非栅格数据进行栅格运算*/
#define	UGS_DTM_MSG_NO_STATISTIC_TYPE_MATCHING  26022	/*! 没有匹配的统计类型*/
#define	UGS_DTM_MSG_CREATE_LAKE                 26023	/*! 创建湖泊*/
#define	UGS_DTM_MSG_CLIP_RASTER                 26024	/*! 正在裁剪栅格数据*/
#define	UGS_DTM_MSG_VALUETABLE                  26025	/*! 统计栅格单值数据表*/
#define	UGS_DTM_MSG_TRANSLATE_RASTER_PROJECTION_TITLE 26026	/*! 正在进行栅格投影转换...*/
#define	UGS_MSG_TRANSLATING_PROJECTION          26027	/*! 栅格投影转换...*/
#define	UGS_IMAGE_MSG_NO_IMAGE                  26028	/*! 没有影像数据*/
#define	UGS_IMAGE_MSG_ERROR_DATA                26029	/*! 影像长度或宽度小于零*/
#define	UGS_IMAGE_MSG_NO_SUCH_DIRECTION         26030	/*! 没有那个方向的搜索*/
#define	UGS_IMAGE_MSG_CREATING_ORTHO            26031	/*! 创建正射三维影像*/
#define	UGS_IMAE_MSG_COMPUTING_COLOR            26032	/*! 计算三维影像颜色...*/
#define	UGS_IMAGE_MSG_SMOOTHING                 26033	/*! 影像平滑处理....*/
#define	UGS_IMAGE_MSG_INTERP                    26034	/*! 数据内插计算*/
#define	UGS_IMAGE_MSG_INTERP_IDW                26035	/*! 距离反比权重(IDW)内插*/
#define	UGS_IMAGE_MSG_INTERP_KRIG1              26036	/*! 普通克吕金内插*/
#define	UGS_IMAGE_MSG_INTERP_RBF                26037	/*! 径向基函数(RBF)插值*/
#define	UGS_CHOOSE_PIXELFORMAT_FAILED           26038	/*! 选择像素格式失败*/
#define	UGS_SET_PIXELFORMAT_FAILED              26039	/*! 设置像素格式失败*/
#define	UGS_CREATE_OGLCONTEXT_FAILED            26040	/*! 不能创建OpenGL渲染场景*/
#define	UGS_MAKE_CURRENTCONTEXT_FAILED          26041	/*! 不能选择当前场景*/
#define	UGS_DISPLAYSETTINGS_NOT_SUPPORTED       26042	/*! 不支持当前显示参数设置*/
#define	UGS_PLS_CHOOSE_DEEPERDEPTH_OR_LESSSCALE 26043	/*! 请加深树的层次或者选择较小的拉伸比例*/
#define	UGS_IMGBLOCK_GET_FAILED                 26044	/*! 获取影像块出错*/


// 网络分析处理信息：从27000开始编码
#define	UGS_TOO_SMALL_TOLERANCE                 27000	/*! 容限不能小于或等于0*/
#define	UGS_INVALID_NODE_SELECT_TOLERANCE       27001	/*! 节点选择容限错误！*/
#define	UGS_INVALID_END_NODE                    27002	/*! 指定的终点无效！*/
#define	UGS_NOT_SUPPORT_ALLOCATE_TYPE           27003	/*! 资源分配类型不匹配*/
#define	UGS_NUMBER_OF_CENTERS_IS_INCORRECT      27004	/*! 指定的中心个数不合法！*/
#define	UGS_CANDIDATE_CENTERS_CANNOT_BE_ZERO    27005	/*! 候选中心个数不能为零！*/
#define	UGS_NOT_ENOUGH_CANDIDATE_CENTERS        27006	/*! 没有足够的候选中心点！*/
#define	UGS_NOT_ALLOW_ALLOCATE_FOR_NULL_CENTER  27007	/*! 不能分配非中心点！*/
#define	UGS_INVALID_DEMAND_NODE                 27008	/*! 需求节点未能被正确分配*/
#define	UGS_ALLOCATING                          27009	/*! 资源分配*/
#define	UGS_FIND_TSP_PATH                       27010	/*! 旅行商分析*/
#define	UGS_FIND_SHORTEST_PATH                  27011	/*! 最佳路径分析*/
#define	UGS_GET_RESULT                          27012	/*! 正在生成结果*/
#define	UGS_FIND_SERVICEAREAING                 27013	/*! 服务区分析*/
#define	UGS_FIND_CLOSEST_FACILITYING            27014	/*! 最近设施查找*/
#define	UGS_LOCATEALLOCATING                    27015	/*! 选址分区分析*/
#define	UGS_NODE_CONNECTED_ANYLAZED             27016	/*! 节点连通性分析*/
#define	UGS_FIND_CONNECTED_NODES                27017	/*! 通达点分析*/
#define	UGS_FIND_CONNECTED_EDGES                27018	/*! 通达边分析*/
#define	UGS_FIND_CRITIAL_EDGES                  27019	/*! 关键边分析*/
#define	UGS_FIND_CRITIAL_NODES                  27020	/*! 关键点分析*/
#define	UGS_NOT_SET_TRN_FIELD                   27021	/*! 没有设置转向表相关字段*/
#define	UGS_NOT_SET_ARCID_OR_NODEID_FIELD       27022	/*! 没有设置弧段ID或结点ID字段*/
#define	UGS_NOT_SET_COST_FIELD                  27023	/*! 没有设置阻力字段*/
#define	UGS_STEP_2_LINE_NET_BUILD               27024	/*! 弧段结点编码(%d/%d)...*/
#define	UGS_MSG_BUILDING_TRN                    27025	/*! 正在创建转向表*/
#define	UGS_MSG_CANNOT_FIND_NODE                27026	/*! 在指定的位置容限内无法找到节点!*/
#define	UGS_SL_MSG_MISMATCH_BETWEEN_IMAGELIST_AND_TREEITEM 27027	/*! 树的节点与图标列表不匹配*/


// 字段类型定义：从28000开始编码
#define	UGS_NOUM_BOOLEAN                        28000	/*! 布尔*/
#define	UGS_NOUM_SHORT                          28001	/*! 短整型*/
#define	UGS_NOUM_LONG                           28002	/*! 长整型*/
#define	UGS_NOUM_SINGLE                         28003	/*! 单精度*/
#define	UGS_NOUM_DOUBLE                         28004	/*! 双精度*/
#define	UGS_NOUM_NUMERIC                        28005	/*! 数值*/
#define	UGS_NOUM_FLOAT                          28006	/*! 浮点型*/
#define	UGS_NOUM_DBTEXT                         28007	/*! 文本*/
#define	UGS_NOUM_CHAR                           28008	/*! 字符*/
#define	UGS_NOUM_BYTE                           28009	/*! 字节*/
#define	UGS_NOUM_BINARY                         28010	/*! 二进制*/
#define	UGS_NOUM_DATE                           28011	/*! 日期*/
#define	UGS_NOUM_CURRENCY                       28012	/*! 货币*/
#define	UGS_NOUM_MEMO                           28013	/*! 备注*/
#define	UGS_NOUM_LONGBINARY                     28014	/*! 长二进制*/
#define	UGS_NOUM_TIME                           28015	/*! 时间*/


// 补充信息，补充结束后进行分类：从29000开始编码
#define	UGS_FAILED_TO_PREPAREEDITBOARD_FOR_PICTURE_INBUFFER_IS_NULL 29000	/*! 内存图片为空，UGEditToolPack::PrepareEditBoard失败*/
#define	UGS_NAME_NOT_EXIST_UGMAPSTORAGE_CLONE_FAILED 29001	/*! 名字为%s的UGMapStorage不存在，克隆UGMapStorage失败*/
#define	UGS_SOURCE_FILE_FULLNAME_S              29002	/*! 源文件全名: %s*/
#define	UGS_ADJUSTXMLFILE_UNFULFILMENT          29003	/*! AdjustXMLFile接口未实现*/
#define	UGS_FAILED_TO_MAKE_BLOCK_SEQUENCE       29004	/*! 序列化块失败*/
#define	UGS_CANNOT_COMPRESS_FOR_BLOCK_SIZE_IS_OVERRUN 29005	/*! 块的尺寸不合要求，无法进行SGL编码*/
#define	UGS_FAILED_TO_GETSNAPADDPOINT_FOR_THERE_IS_NO_SANPPOINT_IN_BUFFER 29006	/*! Buffer中没有捕捉点对象，UGEditSnapBuffer::GetSnapAddPoint失败*/
#define	UGS_FAILED_TO_GETLINEINDEX_FOR_THERE_IS_NO_SANPLINE_IN_BUFFER 29007	/*! Buffer中没有捕捉线对象，UGEditSnapBuffer::GetLineIndex失败*/
#define	UGS_CACHEMASTERFILE_S_CREATE_SUCCESS    29008	/*! CacheMasterFile： %s 创建成功*/
#define	UGS_CACHEMASTERFILE_S_EXIST             29009	/*! CacheMasterFile： %s 已存在*/
#define	UGS_FAILED_TO_CREATE_CAD_DATASET        29010	/*! CAD数据集创建失败*/
#define	UGS_CURSORTYPE_IS_OPENFORWARD_ONLY      29011	/*! 当前游标处于向前滑动状态*/
#define	UGS_CURSORTYPE_IS_OPENFORWARDONLY       29012	/*! 当前游标处于向前滑动状态*/
#define	UGS_EDITMODE_ISNOT_EDITNONE_AND_CANNOT_UPDATE  29013	/*! EditeMode is not EditNone and Can't Update*/
#define	UGS_EDITMODE_ARENOT_EDITINPROGRESS_EDITADD 29014	/*! 对象编辑模式不匹配*/
#define	UGS_THE_LAYER_NAME_IS_NULL_IN_FINDAVAILABLENAME 29015	/*! 在返回一个与其他图层名称不同的名字时，传入的图层名称为空*/
#define	UGS_GEOARC_RADIUS_IS_NULL               29016	/*! GeoArc半径为0*/
#define	UGS_GEOARC_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE 29017	/*! GeoArc参数非法：三点一线*/
#define	UGS_GEOCIRCLE_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE 29018	/*! GeoCircle参数非法：三点一线*/
#define	UGS_FAILED_TO_TRANSFER_GEOCURVE_TO_LINE 29019	/*! GeoCurve转化为Line失败*/
#define	UGS_GEOMETRY_IS_INVALID                 29020	/*! 几何对象无效*/
#define	UGS_GEOPIE_MAJOR_OR_MINOR_AXIS_SHOULD_MORETHAN_ZERO 29021	/*! 扇形的正负轴均应大于0*/
#define	UGS_GETINFO_UNFULFILMENT                29022	/*! 获得数据库版本工作空间信息的接口未实现*/
#define	UGS_GETTABADJUST_UNFULFILMENT           29023	/*! 获取xml标签应在位置的接口未实现*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_GRAPHICS_IS_NULL 29024	/*! Graphics为空，判断文本对象是否被选中失败*/
#define	UGS_HASGEOMETRY                         29025	/*! 判断是否有几何数据*/
#define	UGS_ARRAY_IS_NULL                       29026	/*! IDS数组为空*/
#define	UGS_INVALID_ID                          29027	/*! ID非法*/
#define	UGS_THE_LAYER_NAME_IS_NULL_IN_ISVALIDNAME 29028	/*! 在判断图层名称是否合法时，指定的图层名称为空*/
#define	UGS_LOADINFO_UNFULFILMENT               29029	/*! 加载SUW文件版本号和信息的接口未实现*/
#define	UGS_FAILED_TO_SET_EDITING_ENVIRONMENT_FOR_MAPWND_DONOT_LINK_WORKSPACE 29030	/*! 地图模拟窗口没有关联工作空间，设置编辑环境失败*/
#define	UGS_FAILED_TO_SAVE_SXW_FILE             29031	/*! 存储工作空间的xml文件失败*/
#define	UGS_MSTERFILE_FULLNAME_S                29032	/*! MasterFile文件全名: %s"*/
#define	UGS_OGRDIVER_IS_S                       29033	/*! OGRDriver 为 %s*/
#define	UGS_OGRDRIVER_POINTER_IS_NULL           29034	/*! OGRDriver指针为空*/
#define	UGS_FAILED_TO_CHECKMARGINPANMODE_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29035	/*! 绘制参数为空或者绘制缓存为空，撞墙漫游失败*/
#define	UGS_FAILED_TO_ONLBUTTONDOWN_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29036	/*! 绘制参数为空或者绘制缓存为空，鼠标左键点击失败*/
#define	UGS_FAILED_TO_ONMOUSEMOVE_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29037	/*! 绘制参数为空或者绘制缓存为空，鼠标移动失败*/
#define	UGS_FAILED_TO_ONRBUTTONDBCLK_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29038	/*! 绘制参数为空或者绘制缓存为空，鼠标右键双击失败*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29039	/*! 绘制参数为空或者绘制缓存为空，鼠标右键点击失败*/
#define	UGS_FAILED_TO_ONRBUTTONUP_FOR_PDRAWPARAM_OR_PDRAWCACHE_IS_NULL 29040	/*! 绘制参数为空或者绘制缓存为空，鼠标右键弹起失败*/
#define	UGS_FAILED_TO_ONSIZE_FOR_PDRAWPARAM_IS_NULL 29041	/*! 绘制参数为空，地图窗口改变大小失败*/
#define	UGS_FAILED_TO_SELECTWITHREGION_FOR_PDRAWPARAM_IS_NULL 29042	/*! 绘制参数为空，框选失败*/
#define	UGS_FAILED_TO_BREAK_FOR_PRSBREAKLINES_OR_PRSNEWOBJS_IS_NULL 29043	/*! 需要被打断的线对象所在的记录集或者用来保存打断后线对象的记录集为空
，打断失败*/
#define	UGS_FAILED_TO_BREAK_FOR_PRSBREAKLINES_IS_NULL 29044	/*! 需要被打断的线对象所在的记录集的记录数为0，打断失败*/
#define	UGS_QUERYDEF_M_IOS_IS_NULL              29045	/*! QueryDef::m_IDs is null*/
#define	UGS_READCONTENT_UNFULFILMENT            29046	/*! 从文件中读取字节数的接口未实现*/
#define	UGS_ODBC_RTREEINDEX_GET_NODES_FAILED    29047	/*! R树索引获取叶子结点失败*/
#define	UGS_SAVEINFO_UNFULFILMENT               29048	/*! 加载SUW文件版本号和信息的接口未实现*/
#define	UGS_SDB_NOT_SUPPORT_TOPO                29049	/*! SDB引擎暂时不支持Topo数据集*/
#define	UGS_SDX_CREATEDATASOURCE_FAILED         29050	/*! SDX CreateDataSource失败！*/
#define	UGS_SDX_CREATEDATASOURCE_SUCCESS        29051	/*! SDX CreateDataSource成功！*/
#define	UGS_SMID_VALUE_IS_ZERO                  29052	/*! SMID 的值为0*/
#define	UGS_SQLPLUS_DELETEMETADATA_FAILED       29053	/*! SQL+引擎删除元数据失败*/
#define	UGS_DATASETRASTER_NAME_INVALID          29054	/*! SQLPLUS栅格数据集名字无效*/
#define	UGS_DATASETVECTOR_VERSION_REGISTEROPTION_FAILED 29055	/*! SQLPLUS矢量数据集版本注册失败*/
#define	UGS_IDS_COUNT_INVALID                   29056	/*! ID个数非法*/
#define	UGS_TOPO_RULE_ALREADY_EXIST             29057	/*! Topo规则已经存在了*/
#define	UGS_UDB_NOT_SUPPORT_DELETEALL           29058	/*! UDB 引擎不支持全部删除操作*/
#define	UGS_UDB_NOT_SUPPORT_GETREACORDCHECKEDBY 29059	/*! UDB 引擎不支持查询当前记录的锁定用户（长事务）*/
#define	UGS_UDB_NOT_SUPPORT_THIS_VECTOR_TYPE    29060	/*! UDB 引擎不支持这种矢量数据集类型*/
#define	UGS_UDB_NOT_SUPPORT_DELETE_FIELD        29061	/*! UDB引擎不支持删除字段*/
#define	UGS_FAILED_TO_MAKEFIXANGLE              29062	/*! 根据两个点、角度、容限生成另外一个点失败*/
#define	UGS_FAILED_TO_MAKEFIXLENGTH             29063	/*! 在线上根据长度生成另外一个点失败*/
#define	UGS_FAILED_TO_MAKEPARALLELLINE          29064	/*! 生成平行线失败*/
#define	UGS_FAILED_TO_MAKESAMELINE              29065	/*! UGEditOperater::MakeSameLine失败*/
#define	UGS_FAILED_TO_MAKEVERTICALLINE          29066	/*! 生成垂直线失败*/
#define	UGS_FAILED_TO_GETPOINT                  29067	/*! 从捕捉元素中捕捉点失败*/
#define	UGS_FAILED_TO_SETPOINT                  29068	/*! 将捕捉到的点加到捕捉元素中失败*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_FAILED_TO_CREATE_UGFONT 29069	/*! 字体类型创建失败，选中文本失败*/
#define	UGS_UGIMAGE_IS_NULL                     29070	/*! UGImage为空*/
#define	UGS_UGLAYOUTSTORAGE_LOAD_FAILED         29071	/*! 导入布局失败*/
#define	UGS_UGLAYOUTSTORAGE_SAVE_FAILED         29072	/*! 保存布局失败*/
#define	UGS_UGLAYOUTSTORAGES_FROMXML_FAILED     29073	/*! 解析包含布局文件路径信息的XML字符串，构造并打开布局集合失败*/
#define	UGS_FAILED_TO_REDO                      29074	/*! 重做失败*/
#define	UGS_FAILED_TO_UNDO                      29075	/*! 撤销失败*/
#define	UGS_UNEXPECTED_VALUE                    29076	/*! 异常值*/
#define	UGS_UNZIP_FAILED_OPEN_SUW_FAILED        29077	/*! 解压缩失败，打开SUW工作空间失败*/
#define	UGS_WCS_ERROR                           29078	/*! WCS发生错误*/
#define	UGS_XML_CHAR_IS_NULL_THAT_CANNOT_FORMAT_GEO 29079	/*! XML字符串为空，无法构造几何对象*/
#define	UGS_XML_WRONG_FOR_CARDINAL_PARAM_POINTS_SHOULD_MORE_THAN_ZERO 29080	/*! XML错误：Cardinal 参数点应大于0*/
#define	UGS_XML_WRONG_FOR_GEOARC_PARAM_POINTS_LESS_THAN_THREE 29081	/*! XML错误：GeoArc的参数点少于3个*/
#define	UGS_XML_WRONG_FOR_GEOARC_PARAM_POINTS_SHOULD_MORE_THAN_ZERO 29082	/*! XML错误：GeoArc的参数点应大于0*/
#define	UGS_XML_WRONG_FOR_GEOCIRCLE_PARAM_POINTS_LESS_THAN_THREE 29083	/*! XML错误：GeoCircle的参数点少于3个*/
#define	UGS_XML_WRONG_FOR_GEOPOINT_COORDINATE_LESSTHAN_TWO 29084	/*! XML错误：GeoPoint的坐标少于2个*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_CARDINAL_TAB 29085	/*! XML错误：未找到Cardinal标签*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_ELLIPTICARC_TAB 29086	/*! XML错误：未找到EllipticArc标签*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_GEOCURVE_TAB 29087	/*! XML错误：未找到GeoCurve标签*/
#define	UGS_XML_WRONG_FOR_CANNOT_FIND_TAB       29088	/*! XML错误：未找到标签*/
#define	UGS_CANNOT_FORMAT_GEOPIE_FOR_THREE_POINT_IN_ONE_LINE 29089	/*! 三点共线，无法构造GeoPie*/
#define	UGS_TRIANGLE_TOPO_ERROR                 29090	/*! 三角形拓扑关系错误*/
#define	UGS_FORBID_CUT                          29091	/*! 不允许剪切操作，剪切失败*/
#define	UGS_FORBID_DELETE                       29092	/*! 不允许删除操作，删除失败*/
#define	UGS_FAILED_TO_INSERTPOINTTOGEOMETRY_FOR_FORBID_BREAKING_LINE 29093	/*! 不允许捕捉点打断线，添加控制点到当前对象中失败*/
#define	UGS_CANNOT_EXPORT_VECTOR_DATASET_TO_VECTOR_FILE 29094	/*! 不可导出矢量数据集为矢量格式文件*/
#define	UGS_NOT_IN_EDTING_OR_NEVER_EDITED       29095	/*! 不在编辑状态，或没有进行过编辑*/
#define	UGS_LAYER_IS_NOT_EXIST                  29096	/*! 不存在此名字的图层*/
#define	UGS_CANNOT_SUPPORT_APPEND_DIFFERNT_RESOLUTION_IAMGE 29097	/*! 不支持不同分辨率的影像数据集追加*/
#define	UGS_UNSUPPORT_PIXELFORMAT               29098	/*! 不支持的像素格式*/
#define	UGS_NOT_SUPPORT_THIS_GEOMETRY_FORMAT    29099	/*! 不支持的几何对象类型*/
#define	UGS_UNSUPPORT_DATA_TYPE                 29100	/*! 不支持的数据类型*/
#define	UGS_NOT_SUPPORT_FILE_TYPE               29101	/*! 不支持的文件类型*/
#define	UGS_UNSUPPORT_CODE_TYPE                 29102	/*! 不支持的编码类型*/
#define	UGS_NOT_SUPPORT_THIS_DATASET_TYPE       29103	/*! 不支持的数据集类型*/
#define	UGS_NOT_SUPPORT_THIS_TYPE               29104	/*! 不支持该类型*/
#define	UGS_CANNOT_UPDATE                       29105	/*! 不能更新*/
#define	UGS_LAYERS_NEED_NOT_MOVE                29106	/*! 不需要进行移动*/
#define	UGS_FAILED_TO_CONVERT_THEME_VARIABLE_TO_DOUBLE 29107	/*! 专题图变量转双精度类型失败*/
#define	UGS_THEME_BASICCLASS_XML_IS_NULL        29108	/*! 专题图基类读取XML信息字符串为空*/
#define	UGS_THEME_BASICCLASS_CANNOT_FIND_THEMELABEL_WHEN_READ_XML 29109	/*! 专题图基类读取XML信息时找不到Theme标签*/
#define	UGS_THEME_POINTER_IS_NULL_WHEN_CONVERT_THEME_TO_DATASET 29110	/*! 专题图转数据集时专题图指针为空*/
#define	UGS_THEMES_REMOVE_COUNT_LESSTHAN_ONE    29111	/*! 专题图集合删除个数小于1*/
#define	UGS_THEMES_NOT_FIND_THE_THEME_POINTER   29112	/*! 专题图集合没有找到对应指针的专题图*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEGRID 29113	/*! 专题图集合获取可见Grid专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMELABEL 29114	/*! 专题图集合获取可见标签专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEDOTDENSITY 29115	/*! 专题图集合获取可见点密度专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESYMBOL 29116	/*! 专题图集合获取可见符号专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESTYLE 29117	/*! 专题图集合获取可见风格专题图失败*/
#define	UGS_THEMES_READING_XML_STRING_IS_NULL   29118	/*! 专题图集合读取XML信息时字符串为空*/
#define	UGS_THEMES_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29119	/*! 专题图集合读取XML信息时找不到Themes标签*/
#define	UGS_THEMES_CANNOT_FIND_THE_VERSION_WHEN_READ_XML 29120	/*! 专题图集合读取XML信息时找不到对应的版本*/
#define	UGS_CANNOT_MERGE_TWO_GEOMETRY_WITH_DIFFERNT_DIM 29121	/*! 两个Geometry的维度不一致，无法合并*/
#define	UGS_TWO_NODES_SAME_ID                   29122	/*! 两个节点ID相同*/
#define	UGS_TWO_ARRAY_HAVE_DIFFERNT_SIZE        29123	/*! 两数组大小不同*/
#define	UGS_FAILED_TO_ANALYSE_TWO_NODES         29124	/*! 两点之间分析失败*/
#define	UGS_FIND_SHORTPATH                      29125	/*! 两点查询的最短路径*/
#define	UGS_TWO_POINTS_CANNOT_MIRROR            29126	/*! 两点相同,无法镜像*/
#define	UGS_COUNT_IS_NULL                       29127	/*! 个数为空*/
#define	UGS_COUNT_LESSTHAN_ONE                  29128	/*! 个数少于一个*/
#define	UGS_CENTERPOINT_LESSTHAN_SERVICE_COUNT  29129	/*! 中心点个数小于服务区分析个数*/
#define	UGS_CENTERPOINT_COUNT_LESSTHAN_ZERO     29130	/*! 中心点个数少于0*/
#define	UGS_CENTERPOINT_SIZE_LESSTHAN_ZERO      29131	/*! 中心点大小小于0*/
#define	UGS_CENTERPOINTS_DT_IS_NULL             29132	/*! 中心点数据集为空*/
#define	UGS_CENTERPOINT_TYPE_IS_NULL            29133	/*! 中心点类型为空*/
#define	UGS_CENTER_INDEX_IS_NULL                29134	/*! 中心点索引为空*/
#define	UGS_CENTERPOINT_INVALID                 29135	/*! 中心点索引非法*/
#define	UGS_CENTER_POINTER_DEMANDE_LESSTHAN_ZERO 29136	/*! 中心需求点大小小于0*/
#define	UGS_THE_FIRST_CHAR_OF_WORD_IS_NULL      29137	/*! 串首位置为空*/
#define	UGS_READ_XML_INFO_FROM_FILE_FAILED_OPEN_SXW_FAILED_S 29138	/*! 从文件%s中读取XML信息失败,打开SXW工作空间失败*/
#define	UGS_READ_XML_INFO_FAILED_OPEN_DB_WORKSPACE_FAILED 29139	/*! 从文件%s中读取XML信息失败,打开数据库工作空间失败*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE          29140	/*! 从文件中获取对象个数...*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE_D        29141	/*! 从文件中获取对象个数为：%d*/
#define	UGS_GEOMETRY_POINTER_IS_NULL            29142	/*! 传入几何对象指针为空*/
#define	UGS_IMPORT_POINT3D_IS_NULL              29143	/*! 传入三维坐标点为空*/
#define	UGS_IMPORT_HANDLE_IS_OUT_EXTENT         29144	/*! 传入的句柄为%d,不在可移动的句柄范围内*/
#define	UGS_IMPORT_ID_IS_NULL                   29145	/*! 传入的ID为空*/
#define	UGS_FAILED_TO_ONDRAW_FOR_PGRAPHICS_IS_NULL 29146	/*! 传入的pGraphics为空，绘制对象失败*/
#define	UGS_FAILED_TO_INVALIDOBJ_FOR_IMPORT_UGGRAPHICS_IS_NULL 29147	/*! 传入的UGGraphics为空，刷新几何对象失败*/
#define	UGS_FAILED_TO_INVALIDSELECT_FOR_IMPORT_UGGRAPHIC_IS_NULL 29148	/*! 传入的UGGraphics为空，刷新选择对象失败*/
#define	UGS_UGWORKSPACECONNECTION_M_STRSERVE_IS_NULL_DELETE_WORKSPACE_FAILED 29149	/*! 传入的工作空间连接的m_strServer为空，删除工作空间失败*/
#define	UGS_UGWORKSPACECONNECTION_M_STRSERVE_IS_NULL_OPEN_WORKSPACE_FAILED 29150	/*! 传入的工作空间连接的m_strServer为空，打开工作空间失败*/
#define	UGS_IMPORT_XML_NOT_FIND_MAP_NODE_INFO_UGMAPSTORAGES_FROMXML_FAILED 29151	/*! 传入的XML字符串中没有找到地图的节点信息，通过解析xml文件构造地图集合失败*/
#define	UGS_IMPORT_XML_NOT_FIND_LAYOUT_NODE_INFO_UGLAYOUTSTORAGES_FROMXML_FAILED 29152	/*! 传入的XML字符串中没有找到布局的节点信息，通过解析xml文件构造布局集合失败*/
#define	UGS_IMPORT_XML_NOT_FIND_NODE_INFO_UGDATASOURCE_FROMXML_FAILED 29153	/*! 传入的XML字符串中没有找到数据源的节点信息，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_IMPORT_XML_NOT_FIND_RESOURCE_NODE_INFO_UGLAYOUTSTORAGES_FROMXML_FAILED 29154	/*! 传入的XML字符串中没有找到资源的节点信息，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_IMPORT_XML_STRING_OR_WORKSPACE_NAME_IS_NULL_UGRESOURCES_FROMXML_FAILED 29155	/*! 传入的XML字符串为空或者传入的工作空间名字为空，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_IMPORT_XML_STRING_OR_WORKSPACE_NAME_IS_NULL_UGLAYOUTSTORAGES_FROMXML_FAILED 29156	/*! 传入的XML字符串为空或者工作空间名字为空，通过解析xml文件构造布局集合失败*/
#define	UGS_IMPORT_XML_IS_NULL_UGDATASOURCE_FROMXML_FAILED 29157	/*! 传入的XML字符串为空，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_IMPORT_XML_IS_NULL_UGMAPSTORAGE_FROMXML_FAILED 29158	/*! 传入的XML字符串为空，通过解析xml文件构造地图集合失败*/
#define	UGS_INVALID_GEODATA                     29159	/*! 传入的几何对象无效,绘制几何对象失败*/
#define	UGS_FAILED_TO_INVALIDRECT_FOR_IMPORT_FLASHBOUND_IS_OVERRUN 29160	/*! 传入的刷新范围不在可视范围内，刷新矩形区域失败*/
#define	UGS_FAILED_TO_INVALIDRECT_FOR_IMPORT_FLASHBOUND_IS_NULL 29161	/*! 传入的刷新范围为空，刷新矩形区域失败*/
#define	UGS_IMPORT_TILE_IS_NULL                 29162	/*! 传入的图幅为空*/
#define	UGS_IMPORT_MAP_NAME_IS_NULL_GET_MAP_FAILED 29163	/*! 传入的地图名字为空，获取地图失败*/
#define	UGS_FAILED_TO_DRAW_TXT_FOR_THE_STRING_IS_NULL 29164	/*! 传入的字符串为空，绘制文本失败*/
#define	UGS_IMPORT_NAME_IS_NULL_UGLAYOUTSTORAGES_FROMXML_FAILED 29165	/*! 传入的工作空间名字为空，通过解析xml文件构造布局集合失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_UGRESOURCES_FROMXML_FAILED 29166	/*! 传入的工作空间名字为空，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_FAILED_TO_BREAK_FOR_IMPORT_DATASET_OR_BREAKOBJECT_IS_NULL 29167	/*! 传入的数据集为空或者用来打断的对象为空，UGEditToolPack::Break失败*/
#define	UGS_FAILED_TO_BREAK_FOR_IMPORT_DATASET_IS_OVERRUN 29168	/*! 传入的数据集类型不为线数据集、网络数据集、路由数据集或者CAD数据集，打断失败*/
#define	UGS_IMPORT_VERSION_ID_NOT_EXIST_UGRESOURCE_FROMXML_FAILED 29169	/*! 传入的版本号不存在，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_IMPORT_VERSION_ID_NOT_EXIST_UGRESOURCE_TOXML_FAILED 29170	/*! 传入的版本号不存在，数据源信息保存为xml文件失败*/
#define	UGS_IMPORT_INDEX_PACKAGE_IS_NULL        29171	/*! 传入的索引包为空*/
#define	UGS_NOT_MATCH                           29172	/*! 位置大小无关，没有匹配*/
#define	UGS_POS_IS_INVALID                      29173	/*! 位置非法*/
#define	UGS_NOT_SUPPORT_OPEN_LOW_VERSION_DATA   29174	/*! 低版本的数据不支持打开*/
#define	UGS_WORKSPACE_SAVEAS_SXW_FAILED_SAVEAS_DB_WORKSPACE_FAILED 29175	/*! 保存工作空间为临时的sxw文件失败，另存数据库工作空间失败*/
#define	UGS_WORKSPACE_SAVEAS_BINARY_FILE_TO_DB_FAILED 29176	/*! 保存工作空间二进制文件到数据库失败*/
#define	UGS_ODBC_SAVEWORKSPACE_FAILED           29177	/*! 保存工作空间失败，原因%s*/
#define	UGS_SAVE_DATASOURCE_INFO_ERROR          29178	/*! 保存数据源信息错误*/
#define	UGS_LAYERS_SAVED_COUNT_LESSTHAN_ONE     29179	/*! 保存的图层个数小于1*/
#define	UGS_ODBC_SAVEINDEXINFO_FAILED           29180	/*! 保存索引信息失败*/
#define	UGS_CANNOT_APPEND_FOR_PIXEL_IS_DIFFERENT 29181	/*! 像素格式不一致，不能追加*/
#define	UGS_SQLPLUS_METADATA_GET_DATASOURCE_FAILED 29182	/*! 元数据获取数据源失败*/
#define	UGS_SQLPLUS_METADATA_GET_DATASET_NAMES_FAILED 29183	/*! 元数据获取数据集名称失败*/
#define	UGS_NO_BUSLINE_IN_BUSSTOP               29184	/*! 公交站点范围内无线路*/
#define	UGS_NO_BUSSTOP_IN_BUSLINE               29185	/*! 公交线路范围内无站点*/
#define	UGS_INVALID_BUSNETWORK                  29186	/*! 公交网络*/
#define	UGS_FIND_D_SDX                          29187	/*! 共找到%d个 SDX*/
#define	UGS_LINKDATA_NOT_SUPPORT_QUERY          29188	/*! 关联数据不支持查询*/
#define	UGS_GET_TEMPORARY_TABLE_FAILED_WHEN_RELATE_QUERY 29189	/*! 关联查询时，获取临时表失败...*/
#define	UGS_ODBC_RASTER_CLOSE_FAILED            29190	/*! 关闭栅格数据集失败*/
#define	UGS_OTHER_INVALID                       29191	/*! 其它无效信息*/
#define	UGS_INTERNAL_PARAM_NOT_INITIALIZE       29192	/*! 内部参量还未初始化*/
#define	UGS_MAP_FAILED_TO_PREPARE_BUFFER        29193	/*! 准备地图缓存失败*/
#define	UGS_READY_IMPORT_DATA_FILE_S            29194	/*! 准备导入数据文件：%s*/
#define	UGS_CANNOT_WORK_FOR_GEOBOUNDS_AREA_IS_NULL 29195	/*! 几何对象的Bounds面积为0，操作无法进行*/
#define	UGS_GEOMETRY_TYPE_INVALID               29196	/*! 几何对象类型无效*/
#define	UGS_GEOMETRY_INVALID                    29197	/*! 几何对象非法*/
#define	UGS_BLOCKCOUNT_ERROR                    29198	/*! 分块数目不对*/
#define	UGS_FAILED_TO_ANALYSE                   29199	/*! 分析失败*/
#define	UGS_NOT_ENOUGH_SEGMENTS                 29200	/*! 分段数不足*/
#define	UGS_FAILED_TO_WORDSEGMENT               29201	/*! 分词失败*/
#define	UGS_FAILED_TO_ALLOT_MEMORY              29202	/*! 分配内存失败*/
#define	UGS_FAILED_INITIALIZE                   29203	/*! 分配环境信息失败*/
#define	UGS_FAILED_ALLOT_HANDLE                 29204	/*! 分配环境句柄失败*/
#define	UGS_FAILED_ALLOT_COST_MEMORY            29205	/*! 分配花费内存失败*/
#define	UGS_CREATE_GRAPHICS_FAILED_AND_UGDRAWCACHE_PREPARE_FAILED 29206	/*! 创建Graphics失败,准备绘制缓冲失败*/
#define	UGS_CREATE_FROMAT_D_UGBRUSH_FAILED      29207	/*! 创建类型为%d的画刷失败*/
#define	UGS_CREATE_FROMAT_D_UGFONT_FAILED       29208	/*! 创建类型为%d的字体失败*/
#define	UGS_CREATE_FROMAT_D_UGIMAGE_FAILED      29209	/*! 创建类型为%d的UGImage失败*/
#define	UGS_CREATE_FROMAT_D_UGPEN_FAILED        29210	/*! 创建类型为%d的画笔失败*/
#define	UGS_CREATE_FORMAT_D_UGRGN_FAILED        29211	/*! 创建类型为%d的UGRgn失败*/
#define	UGS_CREATE_IMAGE_FAILED_AND_UGDRAWCACHE_PREPARE_FAILED 29212	/*! 创建Image失败,准备绘制缓冲失败*/
#define	UGS_ODBC_BULID_RETREEINDEX_GET_RTREE_NODEID_FAILED 29213	/*! 创建R树索引时，获取叶子结点ID失败*/
#define	UGS_BULID_RTREEINDEX_RECORDSETS_IS_NULL 29214	/*! 创建R树索引，记录集为空*/
#define	UGS_FAILED_TO_CREATE_SMID_SERIAL        29215	/*! 创建SmID的序列失败*/
#define	UGS_FAILED_TO_CREATE_TOPO_ERROR_POINTDT 29216	/*! 创建Topo点错误数据集%s失败*/
#define	UGS_FAILED_TO_CREATE_TOPO_ERROR_LINEDT  29217	/*! 创建Topo线错误数据集失败*/
#define	UGS_FAILED_TO_CREATE_TOPO_DIRTY_DT      29218	/*! 创建Topo脏区数据集%s失败*/
#define	UGS_FAILED_TO_CREATE_TOPO_ERROR_REGIONDT 29219	/*! 创建Topo面错误数据集%s失败*/
#define	UGS_UGLAYOUTSTORAGE_CREATE_FAILED       29220	/*! 创建布局失败*/
#define	UGS_UGMAPSTORAGE_CREATE_FAILED          29221	/*! 创建地图失败*/
#define	UGS_UGSCENESTORAGE_CREATE_FAILED        29222	/*! 创建三维场景失败*/
#define	UGS_ODBC_BULIDDYNAMIC_FAILED            29223	/*! 创建动态索引失败*/
#define	UGS_ODBC_BULID_DYNAMICINDEX_FAILED      29224	/*! 创建动态索引失败，原因%s*/
#define	UGS_ODBC_BULID_QTREE_INDEX_FAILED       29225	/*! 创建四叉树索引失败，原因%s*/
#define	UGS_ODBC_BULIDTILE_FAILED               29226	/*! 创建图幅索引失败，原因%s*/
#define	UGS_ODBC_BUILD_TILE_DATASET_FAILED      29227	/*! 创建图幅索引失败*/
#define	UGS_ODBC_BULID_TILE_DATASET_FAILED      29228	/*! 创建图幅索引失败*/
#define	UGS_ODBC_BULIDTILE_GETFIELDINFO_IS_EMPTY 29229	/*! 创建图幅索引时，获取字段信息失败*/
#define	UGS_CREATE_FIELD_S_FAILED               29230	/*! 创建字段[%s]失败*/
#define	UGS_ODBC_BUILD_PYRAMID_DADASET_FAILED   29231	/*! 创建影像金字塔失败*/
#define	UGS_ODBC_BUILDPYRAMID_FAILED            29232	/*! 创建影像金字塔失败*/
#define	UGS_CANNOT_CREATE_DATASOURCE_UGDATASOURCES_FROMXML_FAILED 29233	/*! 创建数据源返回为空，通过解析xml文件构造数据源集合，并且连接或打开数据源失败*/
#define	UGS_CREATE_DATASET_S_FAILED             29234	/*! 创建数据集%s失败*/
#define	UGS_SQLPLUS_CREATE_DATASET_VERSION_FAILED 29235	/*! 创建数据集版本失败*/
#define	UGS_FAILED_TO_CREATE_FILE_TYPE_PARSER   29236	/*! 创建文件格式解析器失败*/
#define	UGS_CREATE_FILE_FORMAT_PARSER_SUCCESS   29237	/*! 创建文件格式解析器成功*/
#define	UGS_ODBC_RASTER_CREATE_FAILED           29238	/*! 创建栅格数据集失败*/
#define	UGS_FAILED_TO_CREATE_RASTER_DATASET     29239	/*! 创建栅格数据集：%s失败*/
#define	UGS_CREATE_FORMAT_D_GRAPHICS_FAILED     29240	/*! 创建类型为%d的Graphics失败*/
#define	UGS_ODBC_CREATEINDEX_FAILED             29241	/*! 创建索引失败*/
#define	UGS_FAILED_TO_CREATE_INDEX_TABLE        29242	/*! 创建索引表失败*/
#define	UGS_CREATE_RECORDSET_FAILED             29243	/*! 创建记录集失败*/
#define	UGS_FAILED_TO_CREATE_TRACEADJMATRIX     29244	/*! 创建追踪矩阵失败*/
#define	UGS_FAILED_TO_CREAT_ADJMATRIX           29245	/*! 创建邻接矩阵失败*/
#define	UGS_FAILED_TO_CREATE_DEMAND_POINTS_FILE 29246	/*! 创建需求点文件失败*/
#define	UGS_INITIALIZATION_FAILED               29247	/*! 初始化失败*/
#define	UGS_FAILED_TO_INITIALIZE_TXT_STYLE_FOR_FAILED_TO_ADD_TXTBOUND_TO_BUFFER 29248	/*! 初始化文本风格失败，添加文本范围到缓存中失败*/
#define	UGS_FAILED_TO_DRAW_TXT_FOR_FAILED_TO_INITIALIZE_TXT_STYLE 29249	/*! 初始化文本风格失败，绘制文本失败*/
#define	UGS_DELETEMETADATA_INITDATASET_FAILED   29250	/*! 删除中间数据失败，初始化数据集失败*/
#define	UGS_FAILED_DELETE_POSTFIX               29251	/*! 删除后缀失败*/
#define	UGS_DELETE_FAILED                       29252	/*! 删除失败*/
#define	UGS_SQLPLUS_DELETE_SUBDATASET_FAILED    29253	/*! 删除子数据集失败*/
#define	UGS_ODBC_DELETEFILED_FAILED             29254	/*! 删除字段失败*/
#define	UGS_ODBC_DELETEWORKSPACEINFO_FAILED     29255	/*! 删除工作空间信息失败*/
#define	UGS_SQLPLUS_DELETE_DATASET_FAILED       29256	/*! 删除数据集失败*/
#define	UGS_DROPSPATIALINDEX_FAILED             29257	/*! 删除空间索引失败*/
#define	UGS_ODBC_TRUNCATE_TABLE_FAILED          29258	/*! 删除表中记录失败*/
#define	UGS_ODBC_REMOVEPYRAMIDS_FAILED          29259	/*! 删除金字塔失败*/
#define	UGS_RECORDSET_IS_BOF                    29260	/*! 到达记录集头*/
#define	UGS_RECORDSET_IS_EOF                    29261	/*! 到达记录集尾*/
#define	UGS_SQLPLUS_REFRESH_RASTER_REGISTER_FAILED 29262	/*! 刷新数据集注册信息失败*/
#define	UGS_SQLPLUS_REFRESH_VECTOR_REGISTER_FAILED 29263	/*! 刷新数据集注册信息失败*/
#define	UGS_ODBC_FLUSHCURRENTRECORDSET_FAILED   29264	/*! 刷新记录失败*/
#define	UGS_ODBC_REFRESHPOS_FAILED              29265	/*! 刷新记录集失败*/
#define	UGS_ODBC_REFRESHOPTION_FAILED           29266	/*! 刷新选项信息失败*/
#define	UGS_LAST_EDIT_NOT_FINISH                29267	/*! 前一次编辑还没有结束*/
#define	UGS_HAVE_MODIFIED_AND_UPDATE_FAILED     29268	/*! 前面已经做过修改且更新失败*/
#define	UGS_LOAD_S_FAILED                       29269	/*! 加载%s失败*/
#define	UGS_LOAD_S_SUCCESS                      29270	/*! 加载%s成功*/
#define	UGS_FAILED_TO_LOAD_BLOCK                29271	/*! 加载Block失败*/
#define	UGS_ODBC_LOADRTREELEAF_FAILED           29272	/*! 加载R树索引叶子节点失败*/
#define	UGS_LOAD_SDX_DYNAMIC_LIB_D_SUCCESS_D_FAILED 29273	/*! 加载SDX动态库完毕: %d 个成功，%d个失败"*/
#define	UGS_LOAD_SDX_S_SUCCESS                  29274	/*! 加载SDX（s%）成功*/
#define	UGS_ODBC_LOADWORKSPACE_FAILED           29275	/*! 加载工作空间失败*/
#define	UGS_LOAD_PROJECT_CONFIG_FILE_ERROR      29276	/*! 加载工程配置文件：%s错误*/
#define	UGS_ODBC_RASTER_LOAD_BLOCK_FAILED       29277	/*! 加载影像块数据失败*/
#define	UGS_LOAD_PRJCONFIG_XML_FAILED           29278	/*! 加载投影配置文件%s失败*/
#define	UGS_NODE_FAILED_CREATE_DIRECTION        29279	/*! 单个节点创建流向失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_SWAP          29280	/*! 单值专题图交换失败*/
#define	UGS_THEMEUNIQUE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29281	/*! 单值专题图保存XML信息时找不到Theme标签*/
#define	UGS_THEMEUNIQUE_FIELD_INVALID           29282	/*! 单值专题图字段不合法*/
#define	UGS_THEMEUNIQUE_FAILED_TO_INSERT_VALUE  29283	/*! 单值专题图插入值存在，插入失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_FIND_THE_VALUE 29284	/*! 单值专题图查找值的对应值失败*/
#define	UGS_THEMEUNIQUE_FAILED_FINDSTYLE        29285	/*! 单值专题图查找风格失败*/
#define	UGS_THEMEUNIQUE_SEGEMENT_COUNT_LESSTHAN_ONE 29286	/*! 单值专题图段个数小于1*/
#define	UGS_THEMEUNIQUE_NOT_FIND_THE_VALUE_CAPTION 29287	/*! 单值专题图没有找到对应值的标题*/
#define	UGS_THEMEUNIQUE_FAILED_TO_ADD_VALUE     29288	/*! 单值专题图添加值存在，添加失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_REMOVE        29289	/*! 单值专题图移除失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_GET_RECORDSET_FIELD 29290	/*! 单值专题图获取记录集字段信息失败*/
#define	UGS_THEMEUNIQUE_RECORDSET_COUNT_IS_ZERO 29291	/*! 单值专题图记录集个数为零*/
#define	UGS_THEMEUNIQUE_RECORDSET_IS_NULL       29292	/*! 单值专题图记录集为空*/
#define	UGS_THEMEUNIQUE_RECORDSET_FAILED_TO_GET_FIELDVALUE 29293	/*! 单值专题图记录集获取字段值失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_READ_XML      29294	/*! 单值专题图读取XML信息基类读取失败*/
#define	UGS_THEMEUNIQUE_READING_XML_STRING_IS_NULL 29295	/*! 单值专题图读取XML信息字符串为空*/
#define	UGS_UNINSTALL_S_SUCCESS                 29296	/*! 卸载s%成功*/
#define	UGS_FINISH_UNINSTALL_SDX                29297	/*! 卸载SDX成功*/
#define	UGS_ORIGINAL_CACHEMASTERFILE_S_NOT_EXIST_OR_INVALID_BEGIN_CREATING_NEW_FILE 29298	/*! 原CacheMasterFile： %s 不存在或者不合法,开始创建新文件...*/
#define	UGS_ORIGINAL_FILE_NAME_IS_NULL          29299	/*! 原始文件名为空,请检查*/
#define	UGS_ORIGINAL_RECORDSET_IS_NULL          29300	/*! 原记录集为空*/
#define	UGS_PARAM_IS_NULL                       29301	/*! 参数为空*/
#define	UGS_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE 29302	/*! 参数错误：三点一线*/
#define	UGS_INVALID_PARAM_FOR_IMPORT_GEOMETRY_MUST_BE_REGION_AND_NOT_NULL 29303	/*! 参数错误：传入Geometry指针必须非空且必须是面对象*/
#define	UGS_INVALID_PARAM_FOR_IMPORT_GEOMETRY_NOT_NULL_AND_THE_SECOND_GEOMETRY_MUSTBE_REGION 29304	/*! 参数错误：传入Geometry指针必须非空，且第二个Geometry必须为面对像*/
#define	UGS_INVALID_PARAM_FOR_ROUNDRECT_ANGLE_SHOULD_MORETHAN_ZERO 29305	/*! 参数错误：圆角矩形的圆角弧度必须非负*/
#define	UGS_INVALID_PARAM_FOR_ROUNDRECT_WIDTH_MUST_MORETHAN_ZERO 29306	/*! 参数错误：圆角矩形的宽度必须大于0*/
#define	UGS_INVALID_PARAM_FOR_ROUNDRECT_HEIGHT_MUST_MORETHAN_ZERO 29307	/*! 参数错误：圆角矩形的高度必须大于0*/
#define	UGS_INVALID_PARAM_FOR_INVALID_M         29308	/*! 参数错误：无效的M值计算枚举变量*/
#define	UGS_PARAM_INVALID_FOR_ELLIPSE_MAJORANDMINOR_AXIS_SHOULD_MORETHAN_ZERO 29309	/*! 参数错误：椭圆的长短轴都必须大于0*/
#define	UGS_PARAM_INVALID_FOR_POINTS_POINTER_IS_NULL 29310	/*! 参数错误：点串指针为空*/
#define	UGS_INVALID_PARAM_FOR_INVALID_SHILD_OBJECT 29311	/*! 参数错误：非法的子对象*/
#define	UGS_INVALID_PARAM                       29312	/*! 参数非法*/
#define	UGS_INVALID_PARAM_FOR_GEOMETRY_POINTER_IS_NULL 29313	/*! 参数非法：Geometry指针为空*/
#define	UGS_PARAM_INVALID_FOR_NO_OVERLAPING_POINTS_SHOULD_MORETHAN_SIX 29314	/*! 参数非法：不重合的点数应大于6*/
#define	UGS_INVALID_PARAM_FOR_CHILD_OBJECT_NEED_MORETHAN_TWO_POINTS 29315	/*! 参数非法：子对象至少需要2个点*/
#define	UGS_PARAM_INVALID_FOR_POINTS_SHOULD_MORETHAN_ZERO 29316	/*! 参数非法：点串应非空且点数大于0*/
#define	UGS_INVALID_PARAM_FOR_AT_LEAST_TWO_POINTS 29317	/*! 参数非法：至少需要2个点*/
#define	UGS_INVALID_PARAM_FOR_AT_LEAST_FOUR_POINTS 29318	/*! 参数非法：至少需要四个点*/
#define	UGS_FAILED_TO_UNREGISTER_VERSION        29319	/*! 反注册版本失败！*/
#define	UGS_OVERLAP_FAILED_TO_TOPO              29320	/*! 叠加分析拓扑处理失败*/
#define	UGS_OVERLAYANALYSIS_DATASET_TYPE_NOT_MATCH 29321	/*! 叠加分析数据集类型不匹配*/
#define	UGS_OVERLAP_TYPE_NOT_MATCH              29322	/*! 叠加分析类型不匹配*/
#define	UGS_TRANSEFER_ANOTHER_SAVEAS_METHOD_SAVEAS_DB_WORKSPACE_FAILED 29323	/*! 另存工作空间为数据库工作空间失败，请调用SaveAs的另外一个接口*/
#define	UGS_WORKSPACE_SAVEAS_FILE_CANNOT_DELETE_FILE_EXIST 29324	/*! 另存工作空间为文件型工作空间，文件已经存在并且无法删除*/
#define	UGS_WORKSPACE_SAVEAS_FILE_SET_FILE_NOT_COVER_FILE_EXIST 29325	/*! 另存工作空间为文件型工作空间，设置了文件存在就不覆盖，而文件已经存在*/
#define	UGS_ONLY_ONE_ARC                        29326	/*! 只有一个ARC*/
#define	UGS_READONLY_CANNOT_MODIFY              29327	/*! 只读属性，不能修改*/
#define	UGS_READONLY_DATASOURCE_CANNOT_CREATE_DATASET 29328	/*! 只读数据不能创建数据集*/
#define	UGS_DATASOURCE_READONLY_CANNOT_CREATE_DATASET 29329	/*! 只读数据源，不能创建数据集*/
#define	UGS_DATASOURCE_READONLY_CANNOT_OPERATE  29330	/*! 只读数据源，不能进行操作*/
#define	UGS_ODBC_VECTOR_READONLY                29331	/*! 只读数据集*/
#define	UGS_FAILED_TO_ONDELETE_FOR_THE_LAYER_OR_DATASET_IS_NULL 29332	/*! 可编辑图层为空或者可编辑图层对应的数据集为空，UGMapWnd::OnDelete失败*/
#define	UGS_FAILED_TO_CUT_FOR_LAYER_IS_NULL     29333	/*! 可编辑图层数为0，UGMapWnd::Cut失败*/
#define	UGS_EDITING_RECORDSET_NOT_SUPPORT_STATISTIC_QUERY 29334	/*! 可编辑记录集不支持统计查询*/
#define	UGS_HOMONYMY_DATASET_EXIST              29335	/*! 同名数据集已经存在*/
#define	UGS_NAME_NOT_EXIST_UGLAYOUTSTORAGE_CLONE_FAILED 29336	/*! 名字为%s的布局不存在，克隆失败*/
#define	UGS_NAME_NOT_EXIST_UGLAYOUTSTORAGE_REMOVE_FAILED 29337	/*! 名字为%s的布局不存在，移除失败*/
#define	UGS_NAME_IS_EXIST_UGLAYOUTSTORAGE_CLONE_FAILED 29338	/*! 名字为%s的布局已经存在，克隆失败*/
#define	UGS_UGMAPSTORAGE_NAME_NOT_EXIST_REMOVE_FAILED 29339	/*! 名字为%s的地图不存在，移除失败*/
#define	UGS_NAME_NOT_EXIST_UGMAPSTORAGE_RENAME_FAILED 29340	/*! 名字为%s的地图不存在，重命名失败*/
#define	UGS_NAME_IS_EXIST_UGMAPSTORAGE_CLONE_FAILED 29341	/*! 名字为%s的地图已经存在，克隆失败*/
#define	UGS_NAME_IS_EXIST_UGMAPSTORAGE_ADD_FAILED 29342	/*! 名字为%s的地图已经存在，添加失败*/
#define	UGS_NAME_IS_EXIST_UGMAPSTORAGE_RENAME_FAILED 29343	/*! 名字为%s的地图已经存在，重命名失败*/
#define	UGS_UGSCENESTORAGE_NAME_NOT_EXIST_CLONE_FAILED 29344	/*! 名字为%s的三维场景不存在，克隆失败*/
#define	UGS_UGSCENESTORAGE_NAME_NOT_EXIST_REMOVE_FAILED 29345	/*! 名字为%s的三维场景不存在，移除失败*/
#define	UGS_UGSCENESTORAGE_NAME_IS_EXIST_CLONE_FAILED 29346	/*! 名字为%s的三维场景已经存在，克隆失败*/
#define	UGS_NAME_NOT_EXIST_MODIFY_LAYOUT_NAME_FAILED 29347	/*! 名字为%s的布局不存在，修改布局名字失败*/
#define	UGS_NAME_IS_EXIST_FAILED_TO_ADD_LAYOUT  29348	/*! 名字为%s的布局已经存在，添加布局失败*/
#define	UGS_FAILED_LINE_FIX_LENGTH_FOR_FIXED_LENGTH_IS_TOO_SHORT 29349	/*! 固定长度太短，固定长度失败*/
#define	UGS_INVALID_DATASET_WHEN_PREPARE_SEARCHING 29350	/*! 图层准备查询条件时数据集不合法*/
#define	UGS_LAYER_DATASET_IS_INVALID            29351	/*! 图层对应的数据集不合法*/
#define	UGS_FAILED_TO_ONKEYDOWN_FOR_LAYER_IS_NULL 29352	/*! 图层数为0，单击失败*/
#define	UGS_FAILED_TO_ONLBUTTONDBCLK_FOR_LAYER_IS_NULL 29353	/*! 图层数为0，鼠标左键双击失败*/
#define	UGS_HITTEST_INVALID_DATASET             29354	/*! 图层点击时数据集不合法*/
#define	UGS_LAYER_TYPE_INVLAID                  29355	/*! 图层类型无效*/
#define	UGS_INVALID_LAYER_INDEX                 29356	/*! 图层索引非法*/
#define	UGS_DATASET_IS_NULL_OR_ATTRIBUTE_WHEN_DRAWING 29357	/*! 图层绘制时数据集为空或者为属性表数据集*/
#define	UGS_DATASET_IS_NULL_OR_TABLE_WHEN_SETTING_LAYER 29358	/*! 图层设置数据集时数据集为空或者为表格数据集*/
#define	UGS_MAPBREADTH_CACHEFILE_ERROR          29359	/*! 图幅 %d 的缓存文件出错*/
#define	UGS_MAP_BREADTH_QUERY_GET_ID_FAILED     29360	/*! 图幅空间查询获取图幅ID失败!*/
#define	UGS_IDXTILE_DOESNOT_SUPPORT_REBUILD     29361	/*! 图幅索引不支持重建*/
#define	UGS_ODBC_LIBTILE_BOUNDS_DONOT_FIT       29362	/*! 图幅范围不符*/
#define	UGS_ODBC_LIBTILE_COUNT_OVERLIMIT        29363	/*! 图幅记录超过限制*/
#define	UGS_FAILED_TO_SAVE_FOR_QUERY_RECORDSET_IS_NULL 29364	/*! 在编辑图层对应的数据集中查询记录集返回空，保存编辑对象失败*/
#define	UGS_FAILED_TO_SAVE_FOR_FAILED_TO_SEARCH_OBJECT_ID 29365	/*! 在编辑对象所在的记录集中查找编辑对象的ID失败，保存编辑对象失败*/
#define	UGS_MAP_AVISIBLE_BOUNDS_TOO_SMALL_TO_DRAW 29366	/*! 地图显示范围太小，绘制失败*/
#define	UGS_MAP_SCALE_IS_ZERO                   29367	/*! 地图比例尺为零*/
#define	UGS_FAILED_TO_ONMOUSEMOVE_FOR_NOT_RESPOND_THE_MOUSE_EVENT 29368	/*! 地图第一次还没有绘制出来，不响应鼠标事件，鼠标移动失败*/
#define	UGS_ADDRESS_IS_NULL                     29369	/*! 地址串为空*/
#define	UGS_COORDINATE_OVERRUN                  29370	/*! 坐标值超出图幅范围*/
#define	UGS_INVALID_COORDINATE_BOUND            29371	/*! 坐标范围不合法*/
#define	UGS_COORDINATE_CONVER_TO_NODE_FAILED    29372	/*! 坐标转化为节点失败*/
#define	UGS_FAILED_TO_SEARCHLOOP_BASEON_ARC     29373	/*! 基于弧段查询网络连通回路失败*/
#define	UGS_DEAL_WITH_DATAFILE_S_FAILED         29374	/*! 处理数据文件:%s 失败*/
#define	UGS_DEAL_WITH_DATAFILE_S_SUCCESS        29375	/*! 处理数据文件:%s 成功*/
#define	UGS_ODBC_DS_DISPOSE_VERSION_FAILED      29376	/*! 处理版本失败*/
#define	UGS_ODBC_DISPOSE_INDEX_FAILED           29377	/*! 处理索引失败*/
#define	UGS_ODBC_COPYFIELD_FAILED               29378	/*! 复制字段失败*/
#define	UGS_FAILED_TO_SPLITGEOCOMPOUND_FOR_CHILD_OBJECT_IS_NULL 29379	/*! 复合对象子对象个数为0，拆分复合对象失败*/
#define	UGS_FAILED_TO_MTSP                      29380	/*! 多旅行商分析失败*/
#define	UGS_REGION_COUNT_LESSTHAN_ZERO          29381	/*! 多边形的个数小于0*/
#define	UGS_COUNT_DIFFERNT_WITH_WORD            29382	/*! 大小和词的的个数不一致*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_WIDTH_OVERRUN 29383	/*! 字体宽度大于最大可视大小或者字体高度小于最小可视大小，选中文本失败*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_HEIGHT_IS_ZERO 29384	/*! 字体高度为0，选中文本失败*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT_FOR_HEIGHT_OVERRUN 29385	/*! 字体高度大于最大可视大小或者字体高度小于最小可视大小，选中文本失败*/
#define	UGS_FIELD_IS_EMPTY                      29386	/*! 字段为空*/
#define	UGS_FIELD_INFO_INVALID                  29387	/*! 字段信息无效*/
#define	UGS_FIELD_NAME_INVALID                  29388	/*! 字段名非法*/
#define	UGS_INVALID_FIELD_NAME_CREATE_FAILED    29389	/*! 字段名非法，创建字段失败*/
#define	UGS_FIELD_INDEX_INVALID                 29390	/*! 字段索引非法*/
#define	UGS_INDEX_OF_FIELD_OUTOF_BOUNDS         29391	/*! 字段越界*/
#define	UGS_STRING_IS_NULL                      29392	/*! 字符串为空*/
#define	UGS_ODBC_RASTER_SAVEINFO_FAILED         29393	/*! 存储栅格信息失败*/
#define	UGS_FINISH_IMPORT_THE_SINGLE_BAND       29394	/*! 完成单波段数据导入*/
#define	UGS_FINISH_IMPORT_THE_D_BAND            29395	/*! 完成第 %d 个波段导入*/
#define	UGS_TOLERANCE_TOO_SMALL                 29396	/*! 容限太小*/
#define	UGS_PASSWORD_ERROR_OPEN_SUW_FAILED      29397	/*! 密码错误，打开SUW工作空间失败*/
#define	UGS_FAILED_TO_DCTCODE_FOR_BLOCK         29398	/*! 对Block进行DCT编码失败*/
#define	UGS_SPATIALQUERY_GEOMETRY               29399	/*! 对非空间数据集进行空间查询*/
#define	UGS_FINISH_IMPROT_RASTER                29400	/*! 导入栅格数据完成*/
#define	UGS_ODBC_VERSION_DATASET_COPY_DATA_BY_VERSION_FAILED 29401	/*! 将A表数据追加到主表失败*/
#define	UGS_RECORDSET_ISNOT_MOVEFIRST           29402	/*! 尚未移动到第一条记录*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_MODIFY_FAILED 29403	/*! 工作空间中没有别名为%s的数据源，修改别名失败*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_SEARCH_FAILED 29404	/*! 工作空间中没有别名为%s的数据源，查找别名失败*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_GET_ALIAS_FAILED 29405	/*! 工作空间中没有别名为%s的数据源，获取别名失败*/
#define	UGS_NO_ALIAS_IN_WORKSPACE_RELEASE_FAILED 29406	/*! 工作空间中没有别名为%s的数据源，释放失败*/
#define	UGS_NO_INDEX_IN_WORKSPACE_RELEASE_FAILED 29407	/*! 工作空间中没有索引为%d的数据源，释放失败*/
#define	UGS_WORKSPACE_IS_NULL                   29408	/*! 工作空间为空*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVE_WORKSPACE_FAILED 29409	/*! 工作空间名字为空，保存工作空间失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_SUW_FAILED 29410	/*! 工作空间名字为空，另存SUW工作空间失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_SXW_FAILED 29411	/*! 工作空间名字为空，另存SXW工作空间失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_DB_WORKSPACE_FAILED 29412	/*! 工作空间名字为空，另存数据库工作空间失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_SAVEAS_FILE_WORKSPACE_FAILED 29413	/*! 工作空间名字为空，另存文件型工作空间失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_OPEN_SUW_FAILED 29414	/*! 工作空间名字为空，打开SUW工作空间失败*/
#define	UGS_WORKSPACE_NAME_IS_NULL_OPEN_WORKSPACE_FAILED 29415	/*! 工作空间名字为空，打开工作空间失败*/
#define	UGS_MAP_FAILED_TO_SAVE_FOR_WORKSPACE_POINTER_IS_NULL 29416	/*! 工作空间指针为空，保存地图失败*/
#define	UGS_MAP_FAILED_TO_SAVEAS_FOR_WORKSPACE_POINTER_IS_NULL 29417	/*! 工作空间指针为空，另存地图失败*/
#define	UGS_WORKSPACE_NOT_EXIST_DELETE_WORKSPACE_FAILED 29418	/*! 工作空间文件不存在，删除文件型工作空间失败*/
#define	UGS_WORKSPACE_NOT_EXIST_OPEN_FILE_WORKSPACE_FAILED 29419	/*! 工作空间文件不存在，打开文件型工作空间失败*/
#define	UGS_WORKSPACE_FILE_OPEN_FAILED_SAVEAS_SUW_FAILED 29420	/*! 工作空间文件打开失败，另存SUW工作空间失败*/
#define	UGS_FAILED_TO_OPEN_SUW_FOR_FAILED_TO_OPEN_WORKSPACE_FILE 29421	/*! 工作空间文件打开失败，打开SUW工作空间失败*/
#define	UGS_UNKOWN_VERSION_ID_SAVE_WORKSPACE_FAILED 29422	/*! 工作空间版本未知，保存工作空间失败*/
#define	UGS_UNKNOWN_WORKSPACE_VERSION_SAVEAS_SXW_FAILED 29423	/*! 工作空间版本未知，另存SXW工作空间失败*/
#define	UGS_UNKOWN_VERSION_ID_SAVEAS_WORKSPACE_FAILED 29424	/*! 工作空间版本未知，另存工作空间失败*/
#define	UGS_UNKNOWN_WORKSPACE_VERSION_OPEN_SUW_FAILED 29425	/*! 工作空间版本未知，打开SUW工作空间失败*/
#define	UGS_ALREADY_IN_EDITING                  29426	/*! 已经在编辑状态了*/
#define	UGS_EXIST                               29427	/*! 已经存在*/
#define	UGS_ALREADY_IMPORT_D_OBJECT             29428	/*! 已经导入%ld个对象*/
#define	UGS_HAS_BULIDPYRAMID                    29429	/*! 已经建立金字塔*/
#define	UGS_ALREADY_FULL_EXTENT                 29430	/*! 已经是全幅显示了，全幅显示失败*/
#define	UGS_FAILED_TO_PUSH_FOR_BUFFER_OVERRUN   29431	/*! 已经超过最大的缓冲区数了，UGEditSnapBuffer::Push失败*/
#define	UGS_FAILED_BUILD_SINGLE_GRADE           29432	/*! 建立单个河流等级失败*/
#define	UGS_BULIDPYRAMID_FAILED                 29433	/*! 建立金字塔失败*/
#define	UGS_BEGIN_LOADING_SDX_DYNAMAIC_LIB      29434	/*! 开始加载SDX动态库*/
#define	UGS_BEGIN_LOADING_SDX                   29435	/*! 开始加载SDX：*/
#define	UGS_BEGIN_UNINSTALL_SDX                 29436	/*! 开始卸载SDX*/
#define	UGS_BEGIN_IMPORTING_DATA                29437	/*! 开始导入数据..*/
#define	UGS_BEGIN_IMPORTING_RASTER              29438	/*! 开始导入栅格数据...*/
#define	UGS_ENGINE_NOT_HAVE_THE_ABILITY         29439	/*! null*/
#define	UGS_ODBCCONNECTION_INITALIZE_FAILED     29440	/*! 引擎没有这种能力*/
#define	UGS_ARC_SELECTIONCOUNT_IS_NULL          29441	/*! null*/
#define	UGS_EDGEFIELD_IS_NULL                   29442	/*! 弧段个数为空*/
#define	UGS_ARC_LENGTH_LESSTHAN_ZERO            29443	/*! 弧段的大小小于0*/
#define	UGS_FAILED_CONVERT_ARC_TO_NODE          29444	/*! 弧段转化为节点失败*/
#define	UGS_INVALID_MERGE_BUSSTOP_ID            29445	/*! 归并站点ID非法*/
#define	UGS_DIVMATRIX_POINTER_NULL              29446	/*! 归约矩阵指针为空*/
#define	UGS_EDITING_NOW_PLEASE_EDIT_AFTER       29447	/*! 当前正在编辑中，请更新或取消更新之后再编辑*/
#define	UGS_SQLPLUS_VESION_DATASET_POSTTOMAINVERSION_FAILED 29448	/*! 当前版本提交到主版本失败*/
#define	UGS_CURRENT_VERSION_DATASOURCE_NOT_SUPPORT_THIS_TYPE_DATASET 29449	/*! 当前版本的数据源不支持此类型的数据集*/
#define	UGS_FAILED_TO_ONCUT_FOR_CURRENT_STATE_IS_UNEDITABLE 29450	/*! 当前状态不可编辑，剪切失败*/
#define	UGS_FAILED_TO_ONDELETE_FOR_CURRENT_STATE_IS_UNEDITABLE 29451	/*! 当前状态不可编辑，删除失败*/
#define	UGS_FAILED_TO_ONREDO_FOR_CURRENT_STATE_IS_UNEDITABLE 29452	/*! 当前状态不可编辑，重做失败*/
#define	UGS_FAILED_TO_ONUNDO_FOR_CURRENT_STATE_IS_UNEDITABLE 29453	/*! 当前状态不可编辑，撤销失败*/
#define	UGS_FAILED_LINE_FIX_ANGLE_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29454	/*! 当前绘制对象不是折线，多边形，同一线段成固定角度失败*/
#define	UGS_FAILED_LINE_FIX_LENGTH_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29455	/*! 当前绘制对象不是折线，多边形，固定长度失败*/
#define	UGS_FAILED_LINE_PARALLEL_LINE_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29456	/*! 当前绘制对象不是折线，多边形，绘制平行线失败*/
#define	UGS_FAILED_LINE_VERTICAL_LINE_FOR_CURRENT_OBJECTS_ISNOT_POLYLINE_OR_POLYGON 29457	/*! 当前绘制对象不是折线，多边形，绘制垂直线失败*/
#define	UGS_FAILED_LINE_FIX_ANGLE_FOR_CURRENT_OBJECT_IS_NULL 29458	/*! 当前绘制对象为空，同一线段成固定角度失败*/
#define	UGS_FAILED_LINE_FIX_LENGTH_FOR_CURRENT_OBJECT_IS_NULL 29459	/*! 当前绘制对象为空，固定长度失败*/
#define	UGS_FAILED_LINE_IS_HORV_FOR_CURRENT_OBJECT_IS_NULL 29460	/*! 当前绘制对象为空，绘制平行或者垂直线失败*/
#define	UGS_FAILED_LINE_PARALLEL_LINE_FOR_CURRENT_OBJECT_IS_NULL 29461	/*! 当前绘制对象为空，绘制平行线失败*/
#define	UGS_FAILED_LINE_ON_POINT_FOR_CURRENT_BOUND_IS_NULL 29462	/*! 当前绘制范围为空，线经过点失败*/
#define	UGS_FAILED_LINE_PARALLEL_LINE_FOR_CURRENT_BOUND_IS_NULL 29463	/*! 当前绘制范围为空，绘制平行线失败*/
#define	UGS_FAILED_LINE_VERTICAL_LINE_FOR_CURRENT_BOUND_IS_NULL 29464	/*! 当前绘制范围为空，绘制垂直线失败*/
#define	UGS_FAILED_POINT_AT_LINE_EXTEND_FOR_CURRENT_BOUND_IS_NULL 29465	/*! 当前绘制范围为空，点在延长线上失败*/
#define	UGS_FAILED_POINT_EXTEND_ON_POINT_FOR_CURRENT_BOUND_IS_NULL 29466	/*! 当前绘制范围为空，和其他图素点水平、垂直失败*/
#define	UGS_FAILED_POINT_IN_LINE_MIDDLE_FOR_CURRENT_BOUND_IS_NULL 29467	/*! 当前绘制范围为空，点在线中点失败*/
#define	UGS_FAILED_POINT_ON_LINESTARTOREND_FOR_CURRENT_BOUND_IS_NULL 29468	/*! 当前绘制范围为空，点在线的端点失败*/
#define	UGS_FAILED_POINT_ON_LINE_FOR_CURRENT_BOUND_IS_NULL 29469	/*! 当前绘制范围为空，点在线上失败*/
#define	UGS_FAILED_POINT_ON_POINT_FOR_CURRENT_BOUND_IS_NULL 29470	/*! 当前绘制范围为空，点重合失败*/
#define	UGS_FAILED_TO_SNAP_FOR_CURRENT_BOUND_IS_NULL 29471	/*! 当前绘制范围为空，捕捉失败*/
#define	UGS_FAILED_TO_DRAW_RASTER_FOR_EQUIPMENT_COORDINATE_IS_NULL 29472	/*! 当前绘制范围转换成设备坐标为空，绘制栅格数据集失败*/
#define	UGS_FAILED_TO_COMMIT_EDIT_FOR_THE_CURRENT_DATASET_OR_LAYER_IS_NULL 29473	/*! 当前编辑图层为空或者当前编辑图层对应的数据集为空，提交编辑失败*/
#define	UGS_FAILED_TO_ISREDOTOOLENABLE_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29474	/*! 当前编辑子对象为空，判断是否可以恢复上一步操作失败*/
#define	UGS_FAILED_TO_ISUNDOTOOLENABLE_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29475	/*! 当前编辑子对象为空，判断是否可以撤销上一步操作失败*/
#define	UGS_FAILED_TO_ONLBUTTONDBLCLK_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29476	/*! 当前编辑子对象为空，鼠标左键双击失败*/
#define	UGS_FAILED_TO_ONLBUTTONDOWN_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29477	/*! 当前编辑子对象为空，鼠标左键单击失败*/
#define	UGS_FAILED_TO_ONLBUTTONUP_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29478	/*! 当前编辑子对象为空，鼠标左键弹起失败*/
#define	UGS_FAILED_TO_ONMOUSEMOVE_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29479	/*! 当前编辑子对象为空，鼠标移动失败*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29480	/*! 当前编辑子对象为空，鼠标右键单击失败*/
#define	UGS_FAILED_TO_ONRBUTTONUP_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29481	/*! 当前编辑子对象为空，鼠标右键弹起失败*/
#define	UGS_FAILED_TO_ONREDO_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29482	/*! 当前编辑子对象为空，重做失败*/
#define	UGS_FAILED_TO_ONSETCURSOR_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29483	/*! 当前编辑子对象为空，设置光标失败*/
#define	UGS_FAILED_TO_ONUNDO_FOR_CURRENT_CHILD_OBJECT_IS_NULL 29484	/*! 当前编辑子对象为空，撤销失败*/
#define	UGS_FAILED_TO_COMPLETE_EDITING_FOR_CURRENT_COMPOUND_OBJECT_IS_NULL 29485	/*! 当前编辑对象为复合对象，并且为空，完成编辑动作失败*/
#define	UGS_FAILED_TO_MERGE_FOR_CURRENT_OBJECT_IS_NULL 29486	/*! 当前编辑对象为空，合并失败*/
#define	UGS_CURRENT_EDITING_OBJECT_IS_NULL_ONDRAW_NOT_DRAW 29487	/*! 当前编辑对象为空，绘制未绘制对象*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN_FOR_CURRENT_OBJECT_IS_NULL 29488	/*! 当前编辑对象为空，鼠标右键点击失败*/
#define	UGS_FAILED_TO_SAVE_FOR_CURRENT_OBJECT_IS_NULL 29489	/*! 当前编辑对象为空，保存编辑对象失败*/
#define	UGS_FAILED_TO_COMPLETE_EDITING_FOR_CURRENT_OBJECT_IS_NULL 29490	/*! 当前编辑对象为空，完成编辑动作失败*/
#define	UGS_FAILED_TO_CALCULATE_FOR_CURRENT_OBJECT_IS_NULL 29491	/*! 当前编辑对象为空，计算辅助线辅助点失败*/
#define	UGS_CURRENT_RECORD_IS_NULL              29492	/*! 当前记录为空*/
#define	UGS_CURRENT_RECOR_POINT_TO_BOF_OR_EOF   29493	/*! 当前记录指向文件头或者文件尾*/
#define	UGS_CURRENT_DATASET_CANNOT_EDIT         29494	/*! 当前记录集不能编辑*/
#define	UGS_CURRENT_RECORSET_POINT_TO_BOF_OR_EOF 29495	/*! 当前记录集指向文件头或者文件尾*/
#define	UGS_CURRENT_DATASET_IS_LOCKED_CANNOT_EDIT 29496	/*! 当前记录集被其他用户锁定，不能编辑*/
#define	UGS_FAILED_TO_CALCULATE_BOUND_FOR_SELECTED_OBJETS_IS_NULL 29497	/*! 当前选中对象个数为0，计算选中对象总范围失败*/
#define	UGS_FAILED_TO_SETACCESSIBILITYACTIONPOINTMODE_FOR_SELECTED_OBJETS_ISNOT_ONE 29498	/*! 当前选中对象的个数不为1，设置结点编辑模式失败*/
#define	UGS_CURRENT_HEIGHT_OR_WIDTH_IS_ZERO_ADJUST_SCALE_COEFFICIENT_FAILED 29499	/*! 当前逻辑范围高度或者宽度为0，调整比例系数失败*/
#define	UGS_IMAGE_BLOCK_POINTER_IS_NULL         29500	/*! 影像块指针为空*/
#define	UGS_FAILED_TO_DRAW_IMAGE_FOR_IMAGE_BOUNDS_IS_NULL 29501	/*! 影像块的范围为空，绘制影像块失败*/
#define	UGS_FAILED_TO_GET_CENTERPOINT_SERVICE_DATASET 29502	/*! 得到中心点服务数据集失败*/
#define	UGS_FAILED_TO_GET_CENTERPOINT           29503	/*! 得到中间点失败*/
#define	UGS_GEOMETRY_GETTED_IS_NULL             29504	/*! 得到几何对象为空*/
#define	UGS_GET_GEOMETRY_OBJECTS_FAILED         29505	/*! 得到几何对象失败*/
#define	UGS_SQLPLUS_GETSEQVALUE_FAILED          29506	/*! 得到序列化的值失败*/
#define	UGS_INSERTPOS_INVALID                   29507	/*! 得到插入位置非法*/
#define	UGS_FAILED_TO_GET_DATASET_POINTER       29508	/*! 得到数据集指针失败*/
#define	UGS_FAILED_TO_GET_NETWORK_FIELD         29509	/*! 得到网络数据集字段失败*/
#define	UGS_NETWORK_FAILED_TO_GET_NODEDT        29510	/*! 得到网络点数据集失败*/
#define	UGS_FAILED_TO_GET_COST_PARAM            29511	/*! 得到花费参数失败*/
#define	UGS_FAILED_TO_GET_COST                  29512	/*! 得到花费失败*/
#define	UGS_FAILED_TO_GET_COST_FILED            29513	/*! 得到花费字段失败*/
#define	UGS_FAILED_TO_GET_WORD_FREQUENCY        29514	/*! 得到词串频率失败*/
#define	UGS_LAYERS_CANNOT_ADD_FOR_CANNOT_OPEN_DATASET 29515	/*! 打不开数据集，无法加入*/
#define	UGS_PRINT_SCALE_IS_ZERO                 29516	/*! 打印比例尺为零*/
#define	UGS_FAILED_TO_PRINT_FOR_HEIGHT_OR_WIDTH_LESS_THAN_TEN 29517	/*! 打印的高度或者宽度小于10，打印失败*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_ZERO 29518	/*! 打开5.0版本数据源失败*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_THREE 29519	/*! 打开5.3版本数据源失败*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTY_AND_AGO 29520	/*! 打开50以前版本的数据失败*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTYONE     29521	/*! 打开51版本的数据失败*/
#define	UGS_FAILED_TO_OPEN_UGPJFILE             29522	/*! 打开坐标参考文件失败*/
#define	UGS_SQLPLUS_DS_OPEN_EXPANDTABLE_FAILED  29523	/*! 打开外挂属性表失败*/
#define	UGS_ODBC_TOPODATASET_OPEN_FAILED        29524	/*! 打开拓扑数据集失败*/
#define	UGS_TRANSEFER_ANOTHER_OPEN_METHOD_OPEN_DB_WORKSPACE_FAILED 29525	/*! 打开数据库工作空间请调用另外一个打开方法，打开数据库工作空间失败*/
#define	UGS_FAILED_TO_OPEN_FILE                 29526	/*! 打开数据文件: %s 失败*/
#define	UGS_FAILED_TO_OPEN_DATASOURCE_S         29527	/*! 打开数据源%s失败*/
#define	UGS_FAILED_TO_GET_FIELD_INFO_WHEN_OPEN_DATASET 29528	/*! 打开数据集时获取字段信息失败*/
#define	UGS_UGWORKSPACE_BOXINGSXW_FAILED_OPEN_FILE_S_FAILED 29529	/*! 打开文件%s失败，将SXW文件包装成字节失败*/
#define	UGS_FAILED_TO_OPEN_FILE_AND_CANNOT_WRITE 29530	/*! 打开文件失败，不能写入*/
#define	UGS_FAILED_TO_OPEN_TEXT                 29531	/*! 打开文本文件失败!*/
#define	UGS_ODBC_VECTOR_OPEN_FAILED             29532	/*! 打开矢量数据集失败*/
#define	UGS_FAILED_TO_OPEN_DICTIONARY           29533	/*! 打开词典文件失败!*/
#define	UGS_FAILED_TO_DRAW_COMPOUND_FOR_FAILED_TO_UNGROUP_THE_COMPOUND 29534	/*! 打散复合对象失败，绘制复合对象失败*/
#define	UGS_ODBC_SQL_EXECUTE_FAILED             29535	/*! 执行SQL语句失败*/
#define	UGS_ODBC_EXECUPDATE_FAILED              29536	/*! 执行更新失败*/
#define	UGS_CANNOT_FIND_PRJCONFIG_XML           29537	/*! 找不到投影配置文件*/
#define	UGS_CANNOT_FIND_THE_CONNECTING_ENDNODE  29538	/*! 找不到连通的那个终点*/
#define	UGS_TOPO_DATASET_POINTER_IS_NULL        29539	/*! 拓扑数据集指针为空*/
#define	UGS_TOPO_FAILED_TO_ADD_RULES            29540	/*! 拓扑数据集添加规则失败*/
#define	UGS_FAILED_TO_CUT_FOR_FAILED_TO_COPY_TO_REGEDIT 29541	/*! 拷贝到注册表失败，剪切失败*/
#define	UGS_THE_DELETING_BUSLINE_NONENTITY      29542	/*! 指定要删除的公交线路不存在*/
#define	UGS_FAILED_TO_PUSH_FOR_SNAPELEMENT_IS_NONENTITY 29543	/*! 捕捉要素不存在，入栈失败*/
#define	UGS_FAILED_TO_PUSH_FOR_SNAPELEMENT_IS_NOT_USED 29544	/*! 捕捉要素已经不用了，入栈失败*/
#define	UGS_PICKUP_COMMON_BOUNDARY_FAILED       29545	/*! 提取公共边界失败*/
#define	UGS_SQLPLUS_EXTRACT_CONFLICTS_FAILED    29546	/*! 提取冲突数据失败*/
#define	UGS_INSERT_DATASOURCE_ALIAS_FAILED_S    29547	/*! 插入别名为%s的数据源失败*/
#define	UGS_INSERT_LAYER_COUNT_IS_OVERRUN       29548	/*! 插入层数超过允许最大层数*/
#define	UGS_OPERATE_TEMPORARY_TABLE_FAILED      29549	/*! 操作临时表失败*/
#define	UGS_IMPORT_DATA_FAILED                  29550	/*! 数据导入失败*/
#define	UGS_IMPORT_DATA_SUCCESS                 29551	/*! 数据导入成功*/
#define	UGS_DATA_ATTRIBUTE_READONLY             29552	/*! 数据属性为只读*/
#define	UGS_DATA_UNEXPECTED                     29553	/*! 数据异常*/
#define	UGS_DATA_OR_PASSWORD_ERROR              29554	/*! 数据或者密码错误。*/
#define	UGS_DATASOURCE_IS_NULL                  29555	/*! 数据源为空*/
#define	UGS_DATASOURCE_READONLY                 29556	/*! 数据源只读*/
#define	UGS_DATASOURCE_OPEN_SUCCESS             29557	/*! 数据源打开成功*/
#define	UGS_DATASOURCE_IS_READONLY              29558	/*! 数据源是只读模式*/
#define	UGS_DATASOURCE_ISNOT_OPEN_OR_READONLY   29559	/*! 数据源没有打开或数据源为只读*/
#define	UGS_SAME_DATASOURCE                     29560	/*! 数据源相同*/
#define	UGS_DATA_TYPE_NOT_MATCH                 29561	/*! 数据类型不匹配*/
#define	UGS_DATA_SIZE_IS_TOO_SMALL_TO_COMPRESS  29562	/*! 数据量太小，压缩不进行*/
#define	UGS_INVALID_DATASET_COUNT               29563	/*! 数据集个数非法*/
#define	UGS_DATASET_READONLY                    29564	/*! 数据集为只读状态*/
#define	UGS_DATASET_IS_NULL                     29565	/*! 数据集为空*/
#define	UGS_DATASET_IS_NULL_OR_NOT_IN_SAME_DATASOURCE 29566	/*! 数据集为空或者不是同一个数据源的数据集*/
#define	UGS_DATASET_IS_NULL_OR_INVALID_THEMEEXPRESSION 29567	/*! 数据集为空或者专题图表达式不合法*/
#define	UGS_DATASET_IS_NULL_OR_DATASET_ISNOT_VECTOR 29568	/*! 数据集为空或者数据集不是矢量数据集*/
#define	UGS_FAILED_TO_CREATE_DATASET            29569	/*! 数据集创建失败*/
#define	UGS_DATASET_ALIAS_UPDATE_FAILED         29570	/*! 数据集别名更新失败*/
#define	UGS_DATASET_NAME_INVALID                29571	/*! 数据集名称不合法*/
#define	UGS_SAME_DATASET_NAME                   29572	/*! 数据集名称相同*/
#define	UGS_DATASET_AND_FIELD_SIZE_UNLIKENESS   29573	/*! 数据集和字段数组大小不相等*/
#define	UGS_INVALID_DATASET_SIZE                29574	/*! 数据集大小非法*/
#define	UGS_DATASET_ALREADY_ADDED_TO_TOPO       29575	/*! 数据集已经加入了Topo*/
#define	UGS_DATASET_FAILED_TO_GET_FIELD_INFO    29576	/*! 数据集得到字段信息失败*/
#define	UGS_OPEN_DATASET_FAILED                 29577	/*! 数据集打开失败*/
#define	UGS_DATASET_POINTER_OR_FIELD_NAME_IS_NULL 29578	/*! 数据集指针为空或者字段名称为空*/
#define	UGS_NOT_OPEN_CANNOT_QUERY               29579	/*! 数据集没有打开,不能进行查询*/
#define	UGS_DATASET_NOT_OPEN_OR_READONLY_CANNOT_COPY 29580	/*! 数据集没有打开或者只读,不能复制*/
#define	UGS_INVALID_DATASET_INDEX               29581	/*! 数据集的索引非法*/
#define	UGS_DATASET_TYPE_INVLAID                29582	/*! 数据集类型不合法*/
#define	UGS_DATASET_IS_NOT_IMAGE                29583	/*! 数据集类型不是Image(DEM,Grid)*/
#define	UGS_DATA_INVALID                        29584	/*! 数据非法*/
#define	UGS_ARRAY_SIZE_IS_ONE                   29585	/*! 数组大小为1*/
#define	UGS_ARRAY_SIZE_IS_NULL                  29586	/*! 数组大小为空*/
#define	UGS_INVALID_ARRAY_SIZE                  29587	/*! 数组大小非法!*/
#define	UGS_FILE_NOT_EXIST                      29588	/*! 文件不存在*/
#define	UGS_FILE_IS_EXIST                       29589	/*! 文件已经存在，请确认*/
#define	UGS_NEW_ALIAS_IS_EXIST_MODIFY_DATASOURCE_ALIAS_FAILED 29590	/*! 新别名%s已经存在，修改数据源别名失败*/
#define	UGS_NEWNAME_IS_EXIST_MODIFY_LAYOUT_NAME_FAILED 29591	/*! 新名字%s已经存在，修改布局名字失败*/
#define	UGS_SQLPLUS_DATASOURCE_CREATE_FAILED    29592	/*! 新建数据源失败*/
#define	UGS_SQLPLUS_CREATE_DATASOURCE_FAILED    29593	/*! 新建数据源失败*/
#define	UGS_ODBC_VECTOR_CREATE_FAILED           29594	/*! 新建矢量数据集失败*/
#define	UGS_INVALID_DATASET_OPEN_FAILED         29595	/*! 无效数据集，打开失败*/
#define	UGS_INVALID_ENUM                        29596	/*! 无效的枚举变量*/
#define	UGS_CANNOT_MOVE_FORWARD                 29597	/*! 无法向前移动游标*/
#define	UGS_CANNOT_OPEN_MAP                     29598	/*! 无法打开地图*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE             29599	/*! 无法进行空间参考变换*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE_PLANAR_COORD_SYSTEM_TO_EARTH_COORD_SYSTEM 29600	/*! 无法进行空间参考变换：-->地理坐标系或者投影坐标系*/
#define	UGS_BUSLINE_HAS_NO_BUSSTOP              29601	/*! 无站点通过该线路*/
#define	UGS_NO_BUSLINE_THROUGH_BUSSTOP          29602	/*! 无线路通过该站点*/
#define	UGS_ONLY_SUPPORT_SIMPLE_OBJECT          29603	/*! 暂时只支持简单对象*/
#define	UGS_ODBC_UPDATE_RTREE_ITEM_ADD_FAILED   29604	/*! 更新R树索引叶结点失败*/
#define	UGS_UPTATE_FAILED                       29605	/*! 更新不成功*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_FAILED     29606	/*! 更新动态索引失败*/
#define	UGS_ODBC_UPDATE_QTREEINDEX_FAILED       29607	/*! 更新四叉树索引失败*/
#define	UGS_ODBC_UPDATE_LIBTILE_VERSION_FAILED  29608	/*! 更新图幅索引失败*/
#define	UGS_SQLPLUS_UPDATE_VECTOR_REGISTER_FAILED 29609	/*! 更新数据集注册信息失败*/
#define	UGS_SQLPLUS_UPDATE_RASTER_REGISTER_FAILED 29610	/*! 更新数据集注册信息失败*/
#define	UGS_NO_BUSSTOP_IN_UPDATE_BUSLINE        29611	/*! 更新线路范围内无站点*/
#define	UGS_ODBC_RECORDSET_UPDATE_FAILED        29612	/*! 更新记录集失败*/
#define	UGS_FAILED_TO_SHORTPATH                 29613	/*! 最短路径分析失败*/
#define	UGS_CANNOT_FORMAT_GEOPIE_FOR_TWO_SAME_POINT 29614	/*! 有两点相同，无法够造GeoPie*/
#define	UGS_AVAILIABLE_POINTS_COUNT             29615	/*! 有效点的个数*/
#define	UGS_SERVICE_RADIUS_TOO_SMALL            29616	/*! 服务区半径太小*/
#define	UGS_CANNOT_FIND_MATCHED_END_POINT       29617	/*! 未找到匹配的终止点*/
#define	UGS_CANNOT_FIND_MATCHED_START_POINT     29618	/*! 未找到匹配的起始点*/
#define	UGS_NOT_FIND_UGSTRING                   29619	/*! 未找到字符串*/
#define	UGS_FAILED_TO_DRAW_UGPIE                29620	/*! 构建Arc失败,绘制UGPie对象失败*/
#define	UGS_FAILED_TO_DRAW_POINT_OF_ARC         29621	/*! 构建Arc失败,获取绘制Arc的点失败*/
#define	UGS_CONSTRUCT_DATASET_FAILED            29622	/*! 构造数据集失败*/
#define	UGS_SEARCH_GRAPHICS_D_UGGRAPHICSMANAGER_FAILED 29623	/*! 查找Graphics类型为%d的UGGraphicsManager失败*/
#define	UGS_FAILED_TO_SEARCH                    29624	/*! 查找失败*/
#define	UGS_LAYER_SEARCHING_IS_NULL             29625	/*! 查找指定数据集为空*/
#define	UGS_SEARCH_RECORDSET                    29626	/*! 查找记录集*/
#define	UGS_SEARCH_RECORDSET_IS_NULL            29627	/*! 查找记录集为空*/
#define	UGS_QUERY_IDS_EMPTY                     29628	/*! 查询ID为空*/
#define	UGS_SEARCH_RECORDSET_NULL               29629	/*! 查询到记录集为空*/
#define	UGS_SQLPLUS_FILLMAPPING_FAILED          29630	/*! 查询失败*/
#define	UGS_SQLPLUS_QUERYMETADATAWITHFILTER_FAILED 29631	/*! 查询失败*/
#define	UGS_ODBC_EXECSTATCOUNT_FAILED           29632	/*! 查询失败*/
#define	UGS_SQLPLUS_QUERYDTSWITHFIELTER_FAILED  29633	/*! 查询失败*/
#define	UGS_ODBC_GETIDSBYQUERYDEF_FAILED        29634	/*! 查询失败*/
#define	UGS_FAILED_TO_QUERY                     29635	/*! 查询失败*/
#define	UGS_SQLPLUS_QUERY_DT_WITH_BOUNDSSUB_FAILED 29636	/*! 查询失败*/
#define	UGS_ODBC_QUERY_FIELD_INFO_FAILED        29637	/*! 查询字段信息失败*/
#define	UGS_QUERY_FIELD_INFO_FAILED             29638	/*! 查询字段信息失败*/
#define	UGS_QUERIED_OBJECT_POINTER_NULL         29639	/*! 查询对象指针为空*/
#define	UGS_QUERY_OBJECT_TYPE_INVALID           29640	/*! 查询对象类型不合法*/
#define	UGS_QUERY_DATASET_POINTER_IS_NULL       29641	/*! 查询数据集指针为空*/
#define	UGS_THE_SEARCH_RECORDSET_IS_NULL        29642	/*! 查询的记录集为空*/
#define	UGS_QUERY_OPERATER_INVALID              29643	/*! 查询算子不合法*/
#define	UGS_QUERY_RESULT_IS_NULL                29644	/*! 查询结果为空*/
#define	UGS_NETWORK_SEARCH_RECORDSET_IS_NULL    29645	/*! 查询网络数据集记录集为空,查询对象个数小于等于0*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_NODEDT     29646	/*! 查询网络点数据集失败*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_LINEDT     29647	/*! 查询网络线数据集失败*/
#define	UGS_NOEDS_SEARCH_RT_IS_NULL             29648	/*! 查询网络节点记录集为空*/
#define	UGS_QUERY_RECORDSET_COUNT_IS_NULL       29649	/*! 查询记录集个数为空*/
#define	UGS_SEARCH_RT_IS_NULL                   29650	/*! 查询记录集为空*/
#define	UGS_QUERING_RECORDSET_OBJECTS_COUNT_IS_ZERO 29651	/*! 查询记录集对象数为零*/
#define	UGS_QUERY_RECORDSET_POINTER_IS_NULL     29652	/*! 查询记录集指针为空*/
#define	UGS_QUERY_RECORDSET_TYPE_INVALID        29653	/*! 查询记录集类型不合法*/
#define	UGS_SEARCH_RECORDSET_INVALID            29654	/*! 查询记录非法*/
#define	UGS_QUERY_OPTION_INVALID                29655	/*! 查询选项为空*/
#define	UGS_QUERY_OPTION_WRONG                  29656	/*! 查询选项错*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_SWAP_STYLE 29657	/*! 栅格单值专题图交换风格失败*/
#define	UGS_THEMEGRIDUNIQUE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29658	/*! 栅格单值专题图保存XML信息时专题图标签找不到*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_INSERT_VALUE 29659	/*! 栅格单值专题图插入值已经存在，插入失败*/
#define	UGS_THEMEGRIDRUNIQUE_NOT_FOUND_THE_INDEX 29660	/*! 栅格单值专题图没有找到对应值的索引*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_ADD_VALUE 29661	/*! 栅格单值专题图添加值已经存在，增加失败*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_READ_XML 29662	/*! 栅格单值专题图读取XML信息时基类读取失败*/
#define	UGS_THEMEGRIDUNIQUE_XML_IS_NULL         29663	/*! 栅格单值专题图读取XML信息时字符串为空*/
#define	UGS_ODBC_RASTER_CACHEBYBLOCK_FAILED     29664	/*! 栅格块缓存失败*/
#define	UGS_ODBC_RASTER_FAVEBLOCK_FAILED        29665	/*! 栅格存储块失败*/
#define	UGS_ODBC_RASTER_SAVEBLOCK_FAILED        29666	/*! 栅格存储块失败*/
#define	UGS_FAILED_TO_DRAW_RASTER_FOR_FAILED_TO_OPEN_RASTER_DATASET 29667	/*! 栅格数据集打开失败，绘制栅格数据集失败*/
#define	UGS_FAILED_TO_DRAW_RASTER_FOR_NO_INTERSECTION 29668	/*! 栅格数据集的范围和当前绘制范围没有交集，绘制栅格数据集失败*/
#define	UGS_THEMEGRIDRANGE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29669	/*! 栅格范围专题图保存成XML信息时找不到专题图标签*/
#define	UGS_THEMEGRIDRANGE_SEGMENT_LESSTHAN_TWO 29670	/*! 栅格范围专题图分段个数小于2*/
#define	UGS_THEMEGRIDRANGE_NOT_FOUND_THE_INDEX  29671	/*! 栅格范围专题图没有找到对应值的索引*/
#define	UGS_THEMEGRIDRANGE_REMOVEAT_COUNT_LESSTHAN_ONE 29672	/*! 栅格范围专题图移除时移除个数小于1*/
#define	UGS_THEMEGRIDRANGE_BOUNDS_VALUE_COUNT_IS_ZERO 29673	/*! 栅格范围专题图范围值个数为零*/
#define	UGS_THEMEGRIDRANGE_INVALID_SEGMENT      29674	/*! 栅格范围专题图设置分段时分段个数无效*/
#define	UGS_THEMEGRIDRANGE_FAILED_TO_READ_XML   29675	/*! 栅格范围专题图读取XML信息时基类读取失败*/
#define	UGS_THEMEGRIDRANGE_XML_IS_NULL          29676	/*! 栅格范围专题图读取XML信息时字符串为空*/
#define	UGS_THEMELABEL_CANNOT_FIND_LABEL_WHEN_SAVEAS_XML 29677	/*! 标签专题图保存XML信息时找不到标签*/
#define	UGS_THEMELABEL_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29678	/*! 标签专题图保存时找不到专题图标签*/
#define	UGS_THEMELABEL_FAILED_TO_CONVERT_VARIANT_TO_DOUBLE 29679	/*! 标签专题图变量转成双精度值失败*/
#define	UGS_THEMELABEL_FIELD_INVALID            29680	/*! 标签专题图字段不合法*/
#define	UGS_THEMELABEL_FINDTEXTSTYLE_INVALID_INDEX 29681	/*! 标签专题图所找风格的索引不合法*/
#define	UGS_THEMELABEL_NOT_FOUND_THE_INDEX      29682	/*! 标签专题图找不到对应值的索引*/
#define	UGS_THEMELABEL_TEXT_HEIGHT_IS_NULL      29683	/*! 标签专题图文本风格高度为零*/
#define	UGS_THEMELABEL_FINDTEXTSTYLE_FAILED_TO_FIND_FIELDVALUE 29684	/*! 标签专题图查找记录集对应字段值失败*/
#define	UGS_THEMELABEL_MAKEALONGLINETEXT_TOO_SHORT_TO_DRAW 29685	/*! 标签专题图沿线标记时太短不绘制*/
#define	UGS_THEMELABEL_HITTEST_INVALID_DATASET  29686	/*! 标签专题图点击时数据集不合法*/
#define	UGS_THEMELABEL_HITTEST_TEXT_HEIGHT_IS_NULL 29687	/*! 标签专题图点击时文本风格高度为零*/
#define	UGS_THEMELABEL_HITTEST_SERACH_FIELD_COUNT_IS_ZERO 29688	/*! 标签专题图点击时查询字段个数为零*/
#define	UGS_THEMELABEL_HITTEST_SCALE_IS_ZERO    29689	/*! 标签专题图点击时绘制参数比例尺为零*/
#define	UGS_THEMELABEL_REMOVEAT_COUNT_LESSTHAN_ONE 29690	/*! 标签专题图移除个数小于1*/
#define	UGS_THEMELABEL_FAILED_TO_GET_RECORDSET_WHEN_EXTREMUM 29691	/*! 标签专题图计算极值时获取记录集信息失败*/
#define	UGS_THEMELABEL_RECORDSET_IS_NULL        29692	/*! 标签专题图记录集为空*/
#define	UGS_THEMELABEL_RECORDSET_IS_NULL_WHEN_EXTREMUM 29693	/*! 标签专题图设置多个分段时计算极值时记录集为空*/
#define	UGS_THEMELABEL_SEGMENT_LESSTHAN_TWO     29694	/*! 标签专题图设置多个风格时分段个数小于2*/
#define	UGS_THEMELABEL_MAKEDEFAULTSTYLE_SEGEMENT_VALUE_IS_ZERO 29695	/*! 标签专题图设置多个风格时段值为零*/
#define	UGS_THEMELABEL_MAKEDEFAULT_STYLE_BOUNDS_LESSTHAN_ZERO 29696	/*! 标签专题图设置多个风格时范围值小于0*/
#define	UGS_THEMELABEL_CLASSIFY_RECORDSET_IS_NULL 29697	/*! 标签专题图设置多个风格时计算分段时记录集为空*/
#define	UGS_THEMELABEL_MAKEDEFAULTSTYLE_STYLE_COUNT_INVALID 29698	/*! 标签专题图设置多个风格时风格个数不合法*/
#define	UGS_THEMELABEL_MAKEDEFAULTSTYLE_STYLE_COUNT_IS_ZERO 29699	/*! 标签专题图设置多个风格时风格个数为零*/
#define	UGS_THEMELABEL_SET_DISPLAY_FORMAT_EXCEPTION 29700	/*! 标签专题图设置显示格式时出现异常*/
#define	UGS_THEMELABEL_FAILED_TO_READ_XML       29701	/*! 标签专题图读取XML时基类读取失败*/
#define	UGS_THEMELABEL_FAILED_TO_READ_UNIQUE_TEXT_STYLE 29702	/*! 标签专题图读取单个文本风格时失败*/
#define	UGS_THEMELABEL_FAILED_TO_CREATE_GRAPHICS_WHEN_CONVERT_TO_GEO 29703	/*! 标签专题图转几何对象时创建Graphics失败*/
#define	UGS_THEMELABEL_TEXT_FONT_IS_NULL_WHEN_CONVERT_TO_GEO 29704	/*! 标签专题图转几何对象时创建字体为空*/
#define	UGS_THEMELABEL_TEXT_WIDTH_OVERRUN_WHEN_CONVERT_TO_GEO 29705	/*! 标签专题图转几何对象时字体宽度不在最大最小范围内*/
#define	UGS_THEMELABEL_DEFAULT_SIZE_IS_ZERO_WHEN_CONVERT_TO_GEO 29706	/*! 标签专题图转几何对象时默认大小为零*/
#define	UGS_FAILED_TO_MARK                      29707	/*! 标识失败*/
#define	UGS_WRONG_MARK                          29708	/*! 标识错误*/
#define	UGS_FAILED_TO_CHECK_GRAPHIC_DYNAMIC_LIB 29709	/*! 检查Graphics动态库失败*/
#define	UGS_CHECKING_AND_CHECKED_DATASET_CANNOT_BE_SAME_DATASET 29710	/*! 检查数据集和被检查数据集不能为同一数据集*/
#define	UGS_FAILED_TO_CHECK_DEMAND_POINTS       29711	/*! 检查需求点失败*/
#define	UGS_FAILED_TO_CHECK_DEMAND_POINTS_FILE  29712	/*! 检查需求点文件失败*/
#define	UGS_CANNOT_OPEN_TEMPLATE_DATASET        29713	/*! 模版数据集不能打开*/
#define	UGS_TFWEIGHT_AND_FTWEIGHT_ARE_NULL      29714	/*! 正向和反向字段为空*/
#define	UGS_IMORTING_THE_SINGLE_BAND_D          29715	/*! 正在导入单波段数据(%d)...*/
#define	UGS_IMPROTING_DATAFILE_S                29716	/*! 正在导入数据文件：%s ...*/
#define	UGS_IMPORTING_DATAFILE_S                29717	/*! 正在导入数据文件：%s ... */
#define	UGS_IMPORTING_THE_D_BAND                29718	/*! 正在导入第 %d 个波段...*/
#define	UGS_EXPORTING_DATAFILE_S                29719	/*! 正在导出数据文件：%s*/
#define	UGS_OPENING_DATASOURCE                  29720	/*! 正在打开数据源...*/
#define	UGS_IS_EDITING_AND_ALREADY_ADDED        29721	/*! 正在编辑且已经执行过添加操作*/
#define	UGS_MAYBE_SUPERMAPDS_ALREADY            29722	/*! 此前可能已经是SuperMap的数据源，请确认*/
#define	UGS_THIS_MAPBREADTH_HAS_NODATA          29723	/*! 此图幅范围内没有数据*/
#define	UGS_THE_ENGINE_NOT_SUPPORT_CREATE_THS_TYPE_DATASET 29724	/*! 此引擎暂时不支持这种数据集的创建*/
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_UNION 29725	/*! 此数据集类型不支持Union操作*/
#define	UGS_THE_FILE_NAME_IS_NONENTITY          29726	/*! 此文件名不存在*/
#define	UGS_THE_BARRIER_EDGE                    29727	/*! 此边为障碍边*/
#define	UGS_SCALE_LESSTHAN_ZERO_SET_SCALE_FAILED 29728	/*! 比例尺小于等于0，设置比例尺失败*/
#define	UGS_NO_CHANGED                          29729	/*! 没有做任何修改*/
#define	UGS_NO_GEOMETRY_ELEMENT                 29730	/*! 没有几何元素*/
#define	UGS_NOT_MATCH_THE_NODE                  29731	/*! 没有匹配到相关节点*/
#define	UGS_NEEDNOT_UPDATE_FOR_NO_CHANGE        29732	/*! 没有发生改变，不需要更新*/
#define	UGS_NONE_LEGAL_CHILD_OBJECT             29733	/*! 没有合法的子对象*/
#define	UGS_NOT_FIND_THE_ID_IN_SELECTION        29734	/*! 没有在选择集中找到对应的ID*/
#define	UGS_NOT_GET_NODE_INFO                   29735	/*! 没有得到节点信息*/
#define	UGS_NOT_FIND_INDEX_OPPOSITE_THE_FILED_NAME 29736	/*! 没有找到与这个字段名对应的索引*/
#define	UGS_LAYERS_NOT_FIND_USEFUL_LAYER_NAME   29737	/*! 没有找到可用的图层名字*/
#define	UGS_DONOT_FIND_UGPJFILE                 29738	/*! 没有找到坐标参考文件*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_NAME 29739	/*! 没有找到指定名称的图层*/
#define	UGS_NOT_FIND_THE_TOPO_LAYER             29740	/*! 没有找到指定的拓扑数据集图层*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_INDEX 29741	/*! 没有找到指定索引的图层*/
#define	UGS_NOT_FIND_DATA                       29742	/*! 没有找到数据*/
#define	UGS_NOT_APPOINT_DATASOURCE_TYPE_OR_CANNOT_PARSE_DATASOURCE_TYPE_FROM_URL 29743	/*! 没有指定数据源类型或者无法从URL中解析出数据源类型*/
#define	UGS_NONE_TIP_OR_TIP_ERROR               29744	/*! 没有提示信息或提示信息不正确*/
#define	UGS_NO_ROW_CHANGED                      29745	/*! 没有数据行被改变*/
#define	UGS_THE_CORRELATIVE_FIELD_IS_NONENTITY  29746	/*! 没有相关的字段名称*/
#define	UGS_NO_CORRELATIVE_ARC                  29747	/*! 没有相关的弧段*/
#define	UGS_NO_SPATIALDATA_CANNOT_COMPUTE_BOUND 29748	/*! 没有空间数据，不能统计范围*/
#define	UGS_NO_SM_AND_NOT_EXPANDOPEN            29749	/*! 没有系统表，且非扩展打开*/
#define	UGS_NO_DIRTY_RECORD                     29750	/*! 没有脏区记录*/
#define	UGS_HAVENOT_READ_ANY_DATA               29751	/*! 没有读取到任何数据*/
#define	UGS_DONOT_HAVE_PYRAMIDS                 29752	/*! 没有金字塔*/
#define	UGS_BAND_COUNT_IS_ZERO                  29753	/*! 波段数为0*/
#define	UGS_BULID_SPATIALINDEXTILE_FAILED       29754	/*! 注册失败*/
#define	UGS_FAILED_TO_PASTE_FOR_THE_REGEDIT_IS_NONENTITY 29755	/*! 注册文件不存在，粘贴失败*/
#define	UGS_FAILED_TO_REGISTER_VERSION          29756	/*! 注册版本失败！*/
#define	UGS_REGISTER_TABLE_NOT_EXIST            29757	/*! 注册表不存在*/
#define	UGS_DIRECTION_IS_NULL                   29758	/*! 流向字段为空*/
#define	UGS_DIRECTION_TYPE_IS_NOT_LONG          29759	/*! 流向字段类型不是长整型类型*/
#define	UGS_TEST_DEBUG                          29760	/*! 测试Debug*/
#define	UGS_SQLPLUS_ADDMETADATADESC_FAILED      29761	/*! 添加元数据失败*/
#define	UGS_FAILED_TO_ADD_GEO                   29762	/*! 添加几何对象失败*/
#define	UGS_ODBC_CREATEFILED_FAILED             29763	/*! 添加字段失败*/
#define	UGS_FAILED_TO_ADD_TOPO                  29764	/*! 添加拓扑数据集失败*/
#define	UGS_LAYERS_UNSUPPORT_ADDING_DATASET_AS_ATTRIBUTE 29765	/*! 添加数据集为属性表类型，暂不支持*/
#define	UGS_SQLPLUS_ADDTEMPLATEFILE_FAILED      29766	/*! 添加模板文件失败*/
#define	UGS_ODBC_FILL_TABLE_EXTINFO_FAILED      29767	/*! 添加记录失败*/
#define	UGS_CANNOT_APPEND_FOR_ORIGINALDATASET_ISNOT_OVERLAP_WITH_TARGETDATASET 29768	/*! 源数据集与目标数据集没有叠合，无法追加*/
#define	UGS_SOURCE_RECORDSET_HASNO_RECORD       29769	/*! 源记录集没有记录*/
#define	UGS_POINTS_POINTER_IS_NULL              29770	/*! 点串指针为空*/
#define	UGS_NODE_COUNT_NOT_EQUAL_ARC_COUNT      29771	/*! 点和弧段个数不一致*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_BOUNDS_IS_NULL 29772	/*! 点密度专题图专为几何对象时范围为空*/
#define	UGS_THEMEDOTDENSITY_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29773	/*! 点密度专题图保存XML信息找不到Theme对应标签*/
#define	UGS_THEMEDOTDENSITY_BASICCLASS_IS_NULL_WEHN_SAVE_XML 29774	/*! 点密度专题图保存XML信息时基类信息为空*/
#define	UGS_THEMEDOTDENSITY_DOTFILLRANDOM_BOUNDS_IS_NULL 29775	/*! 点密度专题图填充范围为空*/
#define	UGS_THEMEDOTDENSITY_FIELD_INVALID       29776	/*! 点密度专题图字段不合法*/
#define	UGS_THEMEDOTDENSITY_INVALID_FIELD       29777	/*! 点密度专题图字段不合法*/
#define	UGS_THEMEDOTDENSITY_DOTFILLRANDOM_POINTER_IS_NULL 29778	/*! 点密度专题图点填充时点指针为空*/
#define	UGS_THEMEDOTDENSITY_DRAW_POINT_VALUE_IS_ZERO 29779	/*! 点密度专题图绘制点代表的值为零*/
#define	UGS_THEMEDOTDENSITY_RECORDSET_IS_NULL   29780	/*! 点密度专题图记录集为空*/
#define	UGS_THEMEDOTDENSITY_XML_BASICCLASS_IS_NULL 29781	/*! 点密度专题图读取XML信息基类信息为空*/
#define	UGS_THEMEDOTDENSITY_XML_IS_NULL         29782	/*! 点密度专题图读取XML信息字符串为空*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_POINT_COUNT_IS_ZERO 29783	/*! 点密度专题图转为几何对象点个数为零*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_POINT_VALUE_IS_ZERO 29784	/*! 点密度专题图转为几何对象点代表的值为零*/
#define	UGS_THEMEDOTDENSITY_TO_GEOMETRY_POINT_POINTER_IS_NULL 29785	/*! 点密度专题图转为几何对象点指针为空*/
#define	UGS_NOT_REGION_WHEN_CONVERT_THEMEDOTDENSITY_TO_DATASET 29786	/*! 点密度专题图转数据集时不是面数据集类型*/
#define	UGS_POINT_COUNT_LESSTHAN_ZERO           29787	/*! 点的个数小于0*/
#define	UGS_NODE_COUNT_LESSTHAN_TWO             29788	/*! 点的个数少于2个*/
#define	UGS_FAILED_CONVERT_POINT                29789	/*! 点的转化失败*/
#define	UGS_VERSION_NAME_IS_NULL                29790	/*! 版本名称为空*/
#define	UGS_ODBC_VERSIONDATASET_REFRESH_VERSION_FAILED 29791	/*! 版本数据集更新版本失败*/
#define	UGS_VERSIONDT_NOT_SET_VERSION_CANNOT_EDIT 29792	/*! 版本数据集没有设置版本，不能编辑*/
#define	UGS_ODBC_UPDATE_VERSION_FAILED          29793	/*! 版本更新失败*/
#define	UGS_FAILED_TO_GENERATE_FILE             29794	/*! 生成数据文件: %s 失败*/
#define	UGS_SQLPLUS_UNION_CONFLICS_FAILED       29795	/*! 用合并的方法解决冲突失败*/
#define	UGS_FAILED_TO_DRAW_IMAGE_FOR_USER_CANCLE 29796	/*! 用户取消绘制，绘制影像失败*/
#define	UGS_SELECTED_COSTFIELD_INVALID          29797	/*! 用户选择的耗费字段非法*/
#define	UGS_FAILED_TO_FORMAT_ARC                29798	/*! 由参数构造弧段失败*/
#define	UGS_FAILED_TO_APPLY_MEMORY              29799	/*! 申请内存失败*/
#define	UGS_AIM_DATASET_IS_NULL                 29800	/*! 目标数据集为空*/
#define	UGS_ODBC_GETBOUNDSDIRECTLY_FAILED       29801	/*! 直接获取外界矩形失败*/
#define	UGS_FAILED_TO_INTERSECTLINE_FOR_PARALLEL_LINE_HAS_NO_INTERSECTION_POINT 29802	/*! 直线平行，无交点，相交运算失败*/
#define	UGS_ODBC_VECTOR_CREATERTREEINDEX_FAILED 29803	/*! 矢量数据集创建R树索引失败*/
#define	UGS_ODBC_VECTOR_REGISTEROPTION_FAILED   29804	/*! 矢量数据集注册失败*/
#define	UGS_ODBC_VECTOR_UNREGISTEROPTION_FAILED 29805	/*! 矢量数据集注销失败*/
#define	UGS_ODBC_VECTOR_GETNEWID_FAILED         29806	/*! 矢量数据集获取新的ID失败*/
#define	UGS_ODBC_VECTOR_COMPUTEBOUNDS_FAILED    29807	/*! 矢量数据集计算范围失败*/
#define	UGS_ODBC_VECTOR_APPEND_FAILED           29808	/*! 矢量数据集追加失败*/
#define	UGS_CANNOT_FORMAT_REGION_FOR_RECTANGLE_IS_NULL 29809	/*! 矩形为空，无法构面*/
#define	UGS_RECTANGLE_WIDTH_MUST_MORETHAN_ZERO  29810	/*! 矩形的宽必须大于0*/
#define	UGS_RECTANGLE_HEIGHT_MUST_MORETHAN_ZERO 29811	/*! 矩形的高必须大于0*/
#define	UGS_CANNOT_WORK_FOR_RECTANGLE_AREA_IS_NULL 29812	/*! 矩形面积为0，操作无法进行*/
#define	UGS_GEOMETRY_ELEMENT_IS_NULL            29813	/*! 空几何元素*/
#define	UGS_CHAR_IS_NULL                        29814	/*! 空字符!*/
#define	UGS_EMPTY_OBJECT_CANNOT_ADD_TO_DATASET  29815	/*! 空对象不能添加到数据集里*/
#define	UGS_INVALID_BUSSTOP_ID                  29816	/*! 站点ID非法*/
#define	UGS_BUSSTOP_RECORDSET_IS_NULL           29817	/*! 站点记录集为空*/
#define	UGS_THEMESYMBOL_FIELD_INVLAID           29818	/*! 符号专题图字段不合法*/
#define	UGS_DATASET_ISNOT_CAD_OR_SCALE_IS_ZERO_WHEN_CONVERT_THEME_TO_DATASET 29819	/*! 符号转为数据集时指定数据集不是CAD数据集或者绘制参数比例尺为零*/
#define	UGS_PATH_NO_MATCH_POINTS                29820	/*! 第i+1路由点无匹配的道路*/
#define	UGS_ROUTE_NODE_NO_MATCH_ROAD            29821	/*! 第i+1路由点无匹配的道路*/
#define	UGS_FIRST_LEVEL_GIRD_MUST_MORETHAN_ZERO_AND_GEOMETRY_MUST_NOT_NULL 29822	/*! 第一层网格大小不能为0且几何对象不能为空*/
#define	UGS_THEMEGRADUATE_NOT_SUPPORT_NEGATIVE  29823	/*! 等级符号专题图不支持负值时出现负值*/
#define	UGS_THEMEGRADUATE_BASICCLASS_IS_NULL_WEHN_SAVE_XML 29824	/*! 等级符号专题图保存XML信息时基类信息为空*/
#define	UGS_THEMEGRADUATE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29825	/*! 等级符号专题图保存XML信息时找不到Theme标签*/
#define	UGS_THEMEGRADUATE_CANNOT_FIND_THE_LABEL_WHEN_SAVE_XML 29826	/*! 等级符号专题图保存XML信息时找不到标签*/
#define	UGS_THEMEGRADUATE_VALUE_IS_ZERO         29827	/*! 等级符号专题图值为零*/
#define	UGS_THEMEGRADUATE_FIELD_INVALID         29828	/*! 等级符号专题图字段不合法*/
#define	UGS_THEMEGRADUATE_FIELD_EXPRESSION_IS_NULL 29829	/*! 等级符号专题图字段表达式为空*/
#define	UGS_THEMEGRADUATE_DEFINE_VALUE_IS_ZERO  29830	/*! 等级符号专题图定义值为零*/
#define	UGS_THEMEGRADUATE_INVALID_GRADUATEMODE  29831	/*! 等级符号专题图等级符号模式不合法*/
#define	UGS_THEMEGRADUATE_IMPORT_PARAM_VALUE_IS_ZERO 29832	/*! 等级符号专题图计算符号大小时输入参数值为零*/
#define	UGS_THEMEGRADUATESYMBOL_RECORDSET_IS_NULL 29833	/*! 等级符号专题图记录集为空*/
#define	UGS_THEMEGRADUATE_FAILED_TO_READ_XML    29834	/*! 等级符号专题图读取XML信息时基类读取失败*/
#define	UGS_THEMEGRADUATE_XML_IS_NULL           29835	/*! 等级符号专题图读取XML信息时字符串为空*/
#define	UGS_THEMEGRADUATE_DEFINE_MAX_VALUE_IS_ZERO 29836	/*! 等级符号专题图默认设置中最大值为零*/
#define	UGS_SMID_LESSTHAN_ZERO                  29837	/*! 系统ID小于零*/
#define	UGS_SYSTEMUSER_FORBID_CREATING_DATASOURCE 29838	/*! 系统用户不允许创建数据源*/
#define	UGS_INVALID_INDEX_LOCATION              29839	/*! 索引位置非法*/
#define	UGS_INDEX_ANALYZE_FAILED                29840	/*! 索引分析失败*/
#define	UGS_INDEX_OVERLOP                       29841	/*! 索引号越界*/
#define	UGS_WRONG_INDEX                         29842	/*! 索引错误*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_EDITDELETED_FAILED 29843	/*! 索引已被删除，更新动态索引失败*/
#define	UGS_FAILED_TO_SEARCH_INDEX              29844	/*! 索引查找失败*/
#define	UGS_INDEXTYPE_INVALID                   29845	/*! 索引的类型不符*/
#define	UGS_INDEX_ISNOT_IDXRTREE                29846	/*! 索引类型不是R树索引*/
#define	UGS_INDEX_TYPE_ISNOT_IDXDYNAMIC         29847	/*! 索引类型不是动态索引*/
#define	UGS_INDEX_ISNOT_IDXQTREE                29848	/*! 索引类型不是四叉树索引*/
#define	UGS_INDEX_TYPE_IS_NOT_IDXTILE           29849	/*! 索引类型不是图幅索引*/
#define	UGS_INVALID_INDEX                       29850	/*! 索引非法*/
#define	UGS_CANNOT_ADD_ATTRIBUTE_TO_TOPO        29851	/*! 纯属性表不能添加到Topo里*/
#define	UGS_HAS_GAP_BETWEEN_LINE                29852	/*! 线段之间有间隔*/
#define	UGS_LINE_INTERSECT_FAILED               29853	/*! 线段求交失败*/
#define	UGS_INVALID_BUSLINE_ID                  29854	/*! 线路ID非法*/
#define	UGS_BUSLINE_RECORDSET_IS_NULL           29855	/*! 线路记录集为空*/
#define	UGS_ENDPOINT_IS_BARRIERNODE             29856	/*! 终止节点是障碍点*/
#define	UGS_INVALID_ENDPOINT_M                  29857	/*! 终点M值无效*/
#define	UGS_FAILED_TO_CREATE_RESULTDT_FIELD     29858	/*! 结果数据集字段创建失败*/
#define	UGS_NODE_POINTER_IS_NULL                29859	/*! 结点指针为空*/
#define	UGS_DRAW_PARAM_SCALE_IS_ZERO            29860	/*! 绘制参数比例尺为零*/
#define	UGS_MAP_FAILED_TO_DRAW                  29861	/*! 绘制地图失败*/
#define	UGS_DATASET_OR_RECORDSET_IS_NULL_WHEN_DRAW_THEMENONE 29862	/*! 绘制无专题图图层时，数据集为空或者记录集为空*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMELABEL  29863	/*! 绘制标签专题图时绘制参数比例尺为零*/
#define	UGS_TEXT_HEIGHT_IS_ZERO_WHEN_DRAW_THEMELABEL 29864	/*! 绘制标签专题图时绘制文字风格高度为零*/
#define	UGS_IS_NOT_REGION_OR_RECORDSET_IS_NULL_WHEN_DRAW_THEMEDOTDENSITY 29865	/*! 绘制点密度专题图时不是面数据集或者记录集为空*/
#define	UGS_INVALID_FIELD_TYPE_WHEN_DRAW_THEMEDOTDENSITY 29866	/*! 绘制点密度专题图时字段类型不合法*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMEDOTDENSITY 29867	/*! 绘制点密度专题图时绘制参数比例尺为零*/
#define	UGS_FAILED_TO_DRAW_FOR_HEIGHT_OR_WIDTH_LESS_THAN_ONE 29868	/*! 绘制的高度或者宽度小于1，绘制失败*/
#define	UGS_THEMEGRADUATEDSYMBOL_UNSUPPORTED_CAD 29869	/*! 绘制等级符号专题图时数据据为CAD数据集，暂不支持*/
#define	UGS_DATASET_OR_RECORDSET_IS_NULL_WHEN_DRAW_THEMEGRADUATEDSYMBOL 29870	/*! 绘制等级符号专题图时数据集不是矢量的或者记录集为空*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMEGRADUATEDSYMBOL 29871	/*! 绘制等级符号专题图时绘制参数比例尺为零*/
#define	UGS_DATASET_IS_NULL_OR_DATASET_ISNOT_VECTOR_WHEN_DRAW_THEMESTYLE 29872	/*! 绘制风格专题图时数据集不是矢量的或者记录集为空*/
#define	UGS_SCALE_IS_ZERO_WHEN_DRAW_THEMESTYLE  29873	/*! 绘制风格专题图时绘制参数的比例尺为零*/
#define	UGS_THEMEGRAPH_FORBID_ADDING_LEADERLINE 29874	/*! 统计专题图不允许添加牵引线*/
#define	UGS_THEMEGRAPH_FAILED_TO_SWAP           29875	/*! 统计专题图交换失败*/
#define	UGS_THEMEGRAPH_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29876	/*! 统计专题图保存成XML信息时找不到Theme标签*/
#define	UGS_THEMEGRAPH_FAILED_TO_SAVEAS_XML     29877	/*! 统计专题图保存成XML时基类保存失败*/
#define	UGS_THEMEGRAPH_CANNOT_FIND_THE_LABEL_WHEN_SAVE_XML 29878	/*! 统计专题图吧保存XML信息时找不到标签*/
#define	UGS_THEMEGRAPH_NOT_SUPPORT_NEGATIVE     29879	/*! 统计专题图在不支持负值的选择下出现负值字段，不进行绘制*/
#define	UGS_THEMEGRAPH_FIELD_INVALID            29880	/*! 统计专题图字段不合法*/
#define	UGS_THEMEGRAPH_CANNOT_FIND_GRAPHITEM_WHEN_READING_XML 29881	/*! 统计专题图字段读取XML时找不到GraphItem标签*/
#define	UGS_THEMEGRAPH_TEXT_HEIGHT_IS_ZERO      29882	/*! 统计专题图文本风格高度为零*/
#define	UGS_THEMEGRAPH_HITTEST_DRAWING_POINTER_IS_NULL 29883	/*! 统计专题图点击中绘制参数指针为空"*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_BIG 29884	/*! 统计专题图点击事件中图像太大*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_SMALL 29885	/*! 统计专题图点击事件中图像太小*/
#define	UGS_THEMEGRAPH_HITTEST_FIELD_COUNT_IS_ZERO 29886	/*! 统计专题图点击事件中字段个数为零*/
#define	UGS_THEMEGRAPH_HITTEST_DATASET_IS_NOT_RASTER 29887	/*! 统计专题图点击事件中数据集不是矢量的*/
#define	UGS_THEMEGRAPH_HITTEST_MAX_IS_ZERO      29888	/*! 统计专题图点击事件中最大值为零*/
#define	UGS_THEMEGRAPH_HITTEST_SCALE_IS_ZERO    29889	/*! 统计专题图点击事件中比例尺为零*/
#define	UGS_THEMEGRAPH_HITTEST_RECORDSET_IS_NULL 29890	/*! 统计专题图点击事件中记录集为空*/
#define	UGS_THEMEGRAPH_FAILED_TO_REMOVE         29891	/*! 统计专题图移除失败*/
#define	UGS_THEMEGRAPH_FIELD_LESSTHAN_TWO_WHEN_DRAW_3DROSE 29892	/*! 统计专题图绘制三维玫瑰时字段个数小于2*/
#define	UGS_THEMEGRAPH_TOO_BIG_TO_DRAW          29893	/*! 统计专题图绘制时图像过大*/
#define	UGS_THEMEGRAPH_TOO_SMALL_TO_DRAW        29894	/*! 统计专题图绘制时图像过小*/
#define	UGS_THEMEGRAPH_FIELD_MAXVALUE_IS_ZERO_WHEN_DRAW 29895	/*! 统计专题图绘制时字段最大值为零*/
#define	UGS_THEMEGRAPH_FEILD_COUNT_IS_ZERO_WHEN_EXTREMUM 29896	/*! 统计专题图计算极值时字段个数为零*/
#define	UGS_THEMEGRAPH_RECORDSET_IS_NULL        29897	/*! 统计专题图记录集为空*/
#define	UGS_THEMEGRAPH_DEFINE_STYLE_FIELD_COUNT_IS_ZERO 29898	/*! 统计专题图设置默认风格时字段个数为零*/
#define	UGS_THEMEGRAPH_READING_XML_STRING_IS_NULL 29899	/*! 统计专题图读取XML信息字符串为空*/
#define	UGS_THEMEGRAPH_FAILED_TO_READ_XML       29900	/*! 统计专题图读取XML时基类读取失败*/
#define	UGS_THEMEGRAPH_XML_IS_NULL              29901	/*! 统计专题图读取XML时字符串为空*/
#define	UGS_GRAPH_LESSTHAN_SMALLEST_BOUNDS_WHEN_CONVERTTOGEO 29902	/*! 统计专题图转为几何对象时图像小于最小允许范围*/
#define	UGS_GRAPH_OVERRUN_WHEN_CONVERTTOGEO     29903	/*! 统计专题图转为几何对象时图像超过最大允许范围*/
#define	UGS_MAX_IS_ZERO_WHEN_CONVERTTOGEO       29904	/*! 统计专题图转为几何对象时最大值为零*/
#define	UGS_DRAW_PARAM_POINTER_IS_NULL_WHEN_CONVERTTOGEO 29905	/*! 统计专题图转为几何对象时绘制参数指针为空*/
#define	UGS_THEMEGRAPH_TO_GEOMETRY_HAVE_NEGAITIVE_VALUE 29906	/*! 统计专题图转几何对象时出现负值*/
#define	UGS_THEMEGRAPH_TO_GEOMETRY_FIELD_MAXVALUE_IS_NULL 29907	/*! 统计专题图转几何对象时字段最大值为零*/
#define	UGS_THEMEGRAPH_PYRAMIDBAR_FIELD_IS_NULL_OR_ISNOT_EVEN 29908	/*! 统计专题图金字塔条形子段个数为零或者不是偶数*/
#define	UGS_THEMEGRAPH_PYRAMIDPOLY_FIELD_IS_NULL_OR_ISNOT_EVEN 29909	/*! 统计专题图金字塔面型子段个数为零或者不是偶数*/
#define	UGS_ODBC_STATISTIC_FAILED               29910	/*! 统计失败*/
#define	UGS_FAILED_TO_INVALIDOBJ_FOR_UGGRAPHICS_BUFFER_IS_NULL 29911	/*! 缓存UGGraphics为空，刷新对象失败*/
#define	UGS_MEMORY_FILE_S_CREATE_FAILED         29912	/*! 缓存文件 %s 创建失败*/
#define	UGS_MEMORY_FILE_S_CREATE_SUCCESS        29913	/*! 缓存文件全 %s 创建成功*/
#define	UGS_MEMORY_FILE_FULLNAME_S              29914	/*! 缓存文件全名: %s*/
#define	UGS_FAILED_TO_CODE                      29915	/*! 编码失败*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_SETGEOMETRY_FAILED 29916	/*! 编辑对象后，索引管理失败*/
#define	UGS_FAILED_TO_SAVE_FOR_FAILED_TO_GET_ORIGINAL_OBJECT 29917	/*! 编辑对象所在的记录集无法取出原始编辑对象，保存编辑对象失败*/
#define	UGS_GRID_TYPE_UNCONFORMITY              29918	/*! 网格化类型不符*/
#define	UGS_STRARCID_IS_NULL                    29919	/*! 网络弧段大小为空*/
#define	UGS_INVALID_ARC_INDEX                   29920	/*! 网络弧段索引非法*/
#define	UGS_NETWORK_ARCDEMAND_IS_NULL           29921	/*! 网络弧段需求字段为空*/
#define	UGS_INVLIAD_ARC                         29922	/*! 网络弧段非法*/
#define	UGS_NETWORK_IS_NULL                     29923	/*! 网络数据集为空*/
#define	UGS_INVLAID_INDEX_FOR_NETWORK_IS_NULL   29924	/*! 网络数据集为空,索引非法*/
#define	UGS_NETWORK_IS_NULL_OR_DTTRN_IS_NULL    29925	/*! 网络数据集为空或者转向表数据集为空*/
#define	UGS_FAILED_TO_OPEN_NETWORK              29926	/*! 网络数据集打开失败*/
#define	UGS_NETWORK_NOT_OPEN                    29927	/*! 网络数据集没有打开*/
#define	UGS_NETWORK_NODEDT_TYPE_ERROR           29928	/*! 网络点数据集类型不对*/
#define	UGS_NODE_IS_NULL                        29929	/*! 网络节点为空*/
#define	UGS_NETWORK_NODE_INDEX_INVALID          29930	/*! 网络节点索引非法*/
#define	UGS_NETWORK_NODEDEMAND_IS_NULL          29931	/*! 网络节点需求字段为空*/
#define	UGS_NETWORK_RECORDSET_IS_NULL           29932	/*! 网络记录集为空*/
#define	UGS_DIRTY_DATASET_IS_NULL               29933	/*! 脏区数据集为空*/
#define	UGS_FAILED_TO_UNDO_FOR_TRACkING_NOT_SUPPORT_UNDO 29934	/*! 自动跟踪目前不支持回退，撤销失败*/
#define	UGS_FAILED_TO_REDO_FOR_TRACkING_NOT_SUPPORT_REDO 29935	/*! 自动跟踪目前不支持重做，重做失败*/
#define	UGS_CANNOT_USE_THEMECUSTOM              29936	/*! 自定义专题图不可用*/
#define	UGS_THEMECUSTOM_DATASET_DIMENSION_INVALID 29937	/*! 自定义专题图不可用数据集维数不合法*/
#define	UGS_THEMECUSTOM_CANNOT_FIND_THE_LABEL_WHEN_SAVE_XML 29938	/*! 自定义专题图保存XML时找不到对应的标签*/
#define	UGS_THEMECUSTOM_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29939	/*! 自定义专题图保存成XML时找不到Theme标签*/
#define	UGS_THEMECUSTOM_FAILED_TO_READ_XML      29940	/*! 自定义专题图基类读取XML信息失败*/
#define	UGS_THEMECUSTOM_FIELD_TYPE_INVALID      29941	/*! 自定义专题图字段类型不合法*/
#define	UGS_THEMECUSTOM_FAILED_TO_GET_FIELD_VALUE 29942	/*! 自定义专题图获取字段值失败*/
#define	UGS_THEMECUSTOM_XML_IS_NULL             29943	/*! 自定义专题图读取XML信息时字符串为空*/
#define	UGS_DEFINE_OPERATER_STRING_IS_NULL_OR_LENGTH_LESSTHAN_EIGHT 29944	/*! 自定义算子字符串为空或长度小于八个字符*/
#define	UGS_REGION_NEED_AT_LEAST_THREE_POINTS   29945	/*! 至少三点才能够面*/
#define	UGS_GEOLINE_NEED_MORETHAN_TWO_POINTS    29946	/*! 至少需要两点才能够成GeoLine*/
#define	UGS_INVALID_NODE_ID                     29947	/*! 节点ID非法*/
#define	UGS_WRONG_NODE_COUNT                    29948	/*! 节点个数不对*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE_DISTANCE 29949	/*! 节点个数和服务距离个数不一致*/
#define	UGS_NODE_COUNT_LESSTHAN_ONE             29950	/*! 节点个数少于1*/
#define	UGS_NODE_COUNT_INFO_NOT_MATCH           29951	/*! 节点信息个数不一致*/
#define	UGS_NODE_TOLERANCE_LESSTHAN_MIN         29952	/*! 节点容限小于最小值*/
#define	UGS_NODE_POINTER                        29953	/*! 节点指针*/
#define	UGS_NODE_POINTER_INVALID                29954	/*! 节点指针非法*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE   29955	/*! 节点的个数和服务分析个数不一致*/
#define	UGS_NODE_TYPE_IS_NULL                   29956	/*! 节点类型为空*/
#define	UGS_NODE_INDEX_NEGATIVE                 29957	/*! 节点索引为负*/
#define	UGS_NODE_INDEX_TOO_SMALL                29958	/*! 节点索引太小*/
#define	UGS_INVALID_NODE_INDEX                  29959	/*! 节点索引非法*/
#define	UGS_INVLID_NODE                         29960	/*! 节点非法*/
#define	UGS_COSTFIELD_IS_NULL                   29961	/*! 花费字段为空*/
#define	UGS_NOT_SET_COST                        29962	/*! 花费字段没有设置*/
#define	UGS_COST_MARK_NULL                      29963	/*! 花费标记为空*/
#define	UGS_THEMERANGE_CANNOT_FIND_THEME_LABEL_WHEN_SAVEAS_XML 29964	/*! 范围专题图保存XML信息时找不到专题图标签*/
#define	UGS_THEMERANGE_SEGEMENT_COUNT_INVALID   29965	/*! 范围专题图分段个数不合法*/
#define	UGS_THEMERANGE_CLASSIFY_RECORDSET_IS_NULL 29966	/*! 范围专题图分段时记录集为空*/
#define	UGS_THEMERANGE_SEGMENT_BOUNDS_LESSTHAN_ZERO 29967	/*! 范围专题图分段范围小于0*/
#define	UGS_THEMERANGE_FAILED_TO_CONVERT_VARIANT_TO_DOUBLE 29968	/*! 范围专题图变量转换为双精度类型失败*/
#define	UGS_THEMERANGE_FIELD_INVALID            29969	/*! 范围专题图字段不合法*/
#define	UGS_THEMERANGE_NOT_FOUND_THE_INDEX      29970	/*! 范围专题图找不到对应值的索引*/
#define	UGS_THEMERANGE_FINDFIELD_INVALID_INDEX  29971	/*! 范围专题图查找字段时索引不合法*/
#define	UGS_THEMERANGE_FINDTEXTSTYLE_FAILED_TO_GET_FIELDVALUE 29972	/*! 范围专题图查找风格时获取字段值失败*/
#define	UGS_THEMERANGE_REMOVEAT_COUNT_LESSTHAN_ONE 29973	/*! 范围专题图移除个数小于1*/
#define	UGS_THEMERANGE_FAILED_TO_GET_RECORDSET_WHEN_EXTREMUM 29974	/*! 范围专题图计算极值时获取记录集信息失败*/
#define	UGS_THEMERANGE_RECORDSET_IS_NULL_WHEN_EXTREMUM 29975	/*! 范围专题图计算极值时记录集为空*/
#define	UGS_THEMERANGE_MAKEDEFAULTCAPTION_BOUNDS_COUNT_IS_ZERO 29976	/*! 范围专题图设置默认标题时范围个数为零*/
#define	UGS_THEMERANGE_MAKEDEFAULTSTYLE_FIELD_COUNT_IS_ZERO 29977	/*! 范围专题图设置默认风格时字段个数为零*/
#define	UGS_THEMERANGE_MAKEDEFAULTSTYLE_FIELD_COUNT_IS_ZERO_BAK 29978	/*! 范围专题图设置默认风格时字段个数为零_BAK*/
#define	UGS_THEMERANGE_FAILED_TO_READ_XML       29979	/*! 范围专题图读取XML信息时基类读取失败*/
#define	UGS_THEMERANGE_READING_XML_STRING_IS_NULL 29980	/*! 范围专题图读取XML信息时字符串为空*/
#define	UGS_THEMERANGE_MAKEDEFAULT_SEGMENT_COUNT_LESSTHAN_ZERO 29981	/*! 范围专题图默认分段时分段数目小于2*/
#define	UGS_FAILED_TO_GET_GEOMETRY_POINTS       29982	/*! 获取Geometry点串失败*/
#define	UGS_ODBC_FETCH_ID_FAILED                29983	/*! 获取ID失败*/
#define	UGS_GET_OGRLAYER_POINTER_IS_NULL        29984	/*! 获取OGRLayer指针为空*/
#define	UGS_FAILED_TO_GET_CREATEDATASOURCE_ADDRESS 29985	/*! 获取SDX 新建数据源函数地址失败*/
#define	UGS_COUNT_NOT_MATCH                     29986	/*! 获取个数不匹配*/
#define	UGS_SQLPLUS_GETMAPPING_FAILED           29987	/*! 获取元数据影射信息失败*/
#define	UGS_ODBC_GETLIBTILE_ID_FAILED           29988	/*! 获取图幅ID失败*/
#define	UGS_ODBC_FETCH_FOREIGHNTABLE_VALUE_FAILED 29989	/*! 获取外接表值失败*/
#define	UGS_ODBC_GETIFILEDINFO_FAILED           29990	/*! 获取字段信息失败*/
#define	UGS_FAILED_TO_GET_FIELD_INFO            29991	/*! 获取字段信息失败了*/
#define	UGS_ODBC_GETOBJECTCOUNT_FAILED          29992	/*! 获取对象数失败*/
#define	UGS_FAILED_TO_ONLAYERSMODIFIED_FOR_THE_WORKSPACE_IS_NULL 29993	/*! 获取工作空间为空，修改图层失败*/
#define	UGS_ODBC_GETWORKSPACEINFO_FAILED        29994	/*! 获取工作空间信息失败*/
#define	UGS_FETCH_DATA_FAILED                   29995	/*! 获取数据失败*/
#define	UGS_ODBC_GETALLDBINFO_FAILED            29996	/*! 获取数据库服务中所有数据库用户信息失败*/
#define	UGS_ODBC_GET_DATAVERSION_INFOS_FAILED   29997	/*! 获取数据版本信息失败*/
#define	UGS_ODBC_GET_DATASET_UPDATETIME_FAILED  29998	/*! 获取数据集更新时间失败*/
#define	UGS_FAILED_TO_GET_DATASET_TYPE          29999	/*! 获取数据集类型失败*/
#define	UGS_ODBC_REFRESHMAXGEOSIZE_FAILED       30000	/*! 获取最大对象的大小*/
#define	UGS_ODBC_GETSYSTABLESELVALUE_FAILED     30001	/*! 获取某些系统表中特定字段的最大值*/
#define	UGS_SQLPLUS_GETTEMPLATENAMES_FAILED     30002	/*! 获取模板名称失败*/
#define	UGS_FAILED_TO_GET_POINTS                30003	/*! 获取点串失败*/
#define	UGS_ODBC_REFINE_VERSION_TABLE_IDS_FAILED 30004	/*! 获取版本表中的记录ID失败*/
#define	UGS_GOAL_DATASOURCE_POINTER_IS_NULL     30005	/*! 获取的GDAL数据源指针为空*/
#define	UGS_OGR_DATASOURCE_POINTER_IS_NULL      30006	/*! 获取的OGR数据源指针为空*/
#define	UGS_FAILED_TO_GET_SPATIAL_DATA          30007	/*! 获取空间数据失败*/
#define	UGS_FAILED_TO_GET_SPATIAL_POINTS        30008	/*! 获取空间点串失败*/
#define	UGS_FAILED_GET_GRADE_FIELD              30009	/*! 获取等级字段失败*/
#define	UGS_UGSCENESTORAGE_GET_INDEX_FAILED_D   30010	/*! 获取索引为%d的三维场景失败*/
#define	UGS_GET_INDEX_LAYOUT_FAILED_D           30011	/*! 获取索引为%d的布局失败*/
#define	UGS_GET_INDEX_PACKAGE_OBJECT_ID_FAILED  30012	/*! 获取索引包内对象ID失败*/
#define	UGS_GET_INDEX_PACKAGE_DATA_FAILED       30013	/*! 获取索引包内数据失败*/
#define	UGS_GET_INDEX_PACKAGE_MAX_FAILED        30014	/*! 获取索引包最大值失败*/
#define	UGS_GET_INDEX_PACKAGE_BOUNDS_FAILED     30015	/*! 获取索引包的范围失败*/
#define	UGS_FAILED_TO_GET_NODE_ALLOT            30016	/*! 获取节点分配失败*/
#define	UGS_COST_IS_NULL                        30017	/*! 获取花费为空*/
#define	UGS_FAILED_TO_GET_COST_FIELD            30018	/*! 获取花费字段失败*/
#define	UGS_ODBC_GETRECORDCOUNT_FAILED          30019	/*! 获取记录数失败*/
#define	UGS_GET_RECORDSET_IS_NULL               30020	/*! 获取记录集为空*/
#define	UGS_FAILED_TO_GET_TRNCOST               30021	/*! 获取转向花费失败*/
#define	UGS_FAILED_TO_GET_TRACE_COST            30022	/*! 获取追踪花费失败*/
#define	UGS_ODBC_FETCH_LINKTABLE_DATA_FAILED    30023	/*! 获取链接表数据失败*/
#define	UGS_ODBC_GETKEY_FAILED                  30024	/*! 获取键值失败*/
#define	UGS_FAILED_TO_GET_DMNODE_INFO           30025	/*! 获取需要点数据信息失败*/
#define	UGS_TABLE_SMMETA_TEMPLATE_IS_EXIST      30026	/*! 表中间数据模板已经存在*/
#define	UGS_COPIED_GEO_TYPE_DIFFER_WITH_TARGET_GEO 30027	/*! 被拷贝的几何对象与目标对象类型不一致*/
#define	UGS_QUERIED_DATASET_POINTER_NULL        30028	/*! 被查询数据集指针为空*/
#define	UGS_QUERIED_RECORDSET_OBJECTS_COUNT_IS_ZERO 30029	/*! 被查询记录集对象数为零*/
#define	UGS_QUERIED_RECORDSET_POINTER_NULL      30030	/*! 被查询记录集指针为空*/
#define	UGS_QUERIED_RECORDSET_TYPE_INVALID      30031	/*! 被查询记录集类型不合法*/
#define	UGS_FAILED_TO_OPEN_APPENDED_DATASET     30032	/*! 被追加的数据集打开失败*/
#define	UGS_IMPORT_FILE_NAME_IS_NULL            30033	/*! 要导入的数据文件名为空！*/
#define	UGS_ERROR_WHEN_SOLVE_ATABLE_VERSION_CONFILCT 30034	/*! 解决A表版本冲突时遇到问题*/
#define	UGS_ERROR_WHEN_SOLVE_DTABLE_VERSION_CONFILCT 30035	/*! 解决D表版本冲突时遇到问题*/
#define	UGS_ODBC_CALCULATE_UNIQUEVALUES_FAILED  30036	/*! 计算单值失败*/
#define	UGS_ODBC_COMPUTE_BOUNDS_FAILED          30037	/*! 计算外接矩形失败*/
#define	UGS_ODBC_COMPUTERECCOUNT_FAILED         30038	/*! 计算记录数失败*/
#define	UGS_RECORDSET_COUNT_IS_ZERO             30039	/*! 记录集个数为0*/
#define	UGS_RECORDSET_IS_EMPTY                  30040	/*! 记录集为空*/
#define	UGS_RECORDSET_IS_NULL                   30041	/*! 记录集为空*/
#define	UGS_RECORDSET_POINTER_IS_NULL           30042	/*! 记录集指针为空*/
#define	UGS_RECORDSET_POINT_TO_BOF              30043	/*! 记录集游标在开头*/
#define	UGS_RECORDSET_POINT_TO_EOF              30044	/*! 记录集游标在结尾*/
#define	UGS_RECORDSET_INDEX_INVALID             30045	/*! 记录集索引无效*/
#define	UGS_RECORDSET_OUTOF_BOUNDS              30046	/*! 记录集越界*/
#define	UGS_MAP_OR_EQUIPMENT_BOUNDS_IS_NULL     30047	/*! 设备范围或者地图范围为空*/
#define	UGS_SET_LAYER_EDIT_INDEX_MORETHAN_TOTAL_COUNT 30048	/*! 设置图层可编辑时，指定图层索引大于图层总数*/
#define	UGS_ODBC_SETIFILEDINFO_FAILED           30049	/*! 设置字段信息失败*/
#define	UGS_ODBC_SETFILEDNAME_BY_SIGN_FAILED    30050	/*! 设置字段类别失败*/
#define	UGS_SET_IMPORT_PARAM                    30051	/*! 设置导入参数*/
#define	UGS_INVALID_DATASET_WHEN_SET_SORTING_FIELD 30052	/*! 设置排序字段显示顺序时数据集不合法*/
#define	UGS_ODBC_SET_DATAOURCEINFO_FAILED       30053	/*! 设置数据源信息失败*/
#define	UGS_ODBC_SETBOUNDS_FAILED               30054	/*! 设置数据集范围失败*/
#define	UGS_ODBC_SETMAXGEOSIZE_FAILED           30055	/*! 设置最大几何对象的大小*/
#define	UGS_FAILED_TO_SET_SUBACTION_FOR_NOT_SUPPORT_THIS_SUBACTION 30056	/*! 设置的SubAction:%d不支持,设置SubAction失败*/
#define	UGS_GEOMETRY_SETTED_IS_NULL             30057	/*! 设置的几何对象为空*/
#define	UGS_GEOMETRY_SETTED_ORIGINAL_SMID_ISNOT_NEGATIVE_ONE 30058	/*! 设置的几何对象初始化的SmID不为-1*/
#define	UGS_D_GRAPHICS_NOT_EXIST_SET_FAILED     30059	/*! 设置类型为%d的Graphics不存在，设置失败*/
#define	UGS_OUTPUT_DATASOURCE_IS_NULL           30060	/*! 设置输出数据源为空*/
#define	UGS_WORD_POINTER_IS_NULL                30061	/*! 词串指针为空*/
#define	UGS_WORD_NUM_IS_NULL                    30062	/*! 词语个数为空*/
#define	UGS_INVALID_WORD_SIZE                   30063	/*! 词语串大小非法*/
#define	UGS_WORD_IS_NULL                        30064	/*! 词语为空*/
#define	UGS_FAILED_TO_DRAW_FOR_LAYER_IS_UNVISIBLE 30065	/*! 该图层不可见，绘制失败*/
#define	UGS_READ_DATASETS_FAILED                30066	/*! 读取数据集失败*/
#define	UGS_READ_INFO_FAILED                    30067	/*! 读取信息失败*/
#define	UGS_READ_SDBINFO_FAILED                 30068	/*! 读取文件型数据源信息失败*/
#define	UGS_READING_XML_STRING_IS_NULL          30069	/*! 读取XML信息时字符串为空*/
#define	UGS_LAYERS_CANNOT_FIND_LABEL_WHEN_READING_XML 30070	/*! 读取XML时图层标签找不到*/
#define	UGS_NOT_FIND_LAYER_TAB_WHEN_READ_XML    30071	/*! 读取XML时，图层标签没有找到*/
#define	UGS_NOT_FIND_MAP_LABEL_WHEN_READ_XML    30072	/*! 读取XML时，没有找到地图标签*/
#define	UGS_NOT_FIND_NAME_LABEL_WHEN_READ_XML   30073	/*! 读取XML时，没有找到名称标签*/
#define	UGS_FAILED_TO_READ_ONE_GEOMETRY         30074	/*! 读取一个几何对象失败*/
#define	UGS_CANNOT_FIND_THE_VERSION_WHEN_READ_BASICCLASS 30075	/*! 读取专题图基类信息时找不到对应的版本*/
#define	UGS_FAILED_TO_READ_DATA                 30076	/*! 读取数据失败*/
#define	UGS_FAILED_TO_READ_DATASOURCE_INFO      30077	/*! 读取数据源信息失败！*/
#define	UGS_FAILED_TO_READ_FIELD_INFO           30078	/*! 读取数据表字段信息错误*/
#define	UGS_READ_COLOR_TABLE_FAILED             30079	/*! 读取颜色表数据失败*/
#define	UGS_INVLAID_STARTPOINT_AND_ENDPOINT     30080	/*! 起始点和终止点非法*/
#define	UGS_STARTPOINT_IS_BARRIERNODE           30081	/*! 起始点是障碍点*/
#define	UGS_INVALID_STARTNODE                   30082	/*! 起始点非法*/
#define	UGS_INVALID_STARTPOINT_M                30083	/*! 起点M值无效*/
#define	UGS_STARTPOINT_AND_ENDPOINT_NOT_CONNECTED 30084	/*! 起点和终点不连通*/
#define	UGS_STARTPOINT_AND_ENDPOINT_IS_SAME     30085	/*! 起点和终点相同*/
#define	UGS_START_POINT_MUST_BE_ZERO            30086	/*! 起点必须为0*/
#define	UGS_DISTANCE_POINTER_IS_NULL            30087	/*! 距离指针为空*/
#define	UGS_TRACKINGLAYER_FAILED_TO_CREATE_DATASOURCE 30088	/*! 跟踪层创建数据源失败*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DELETE_THE_LABEL_OBJECT 30089	/*! 跟踪层删除对应标签的对象失败*/
#define	UGS_TRACKINGLAYER_FAILED_TO_SEARCH_THE_GEO 30090	/*! 跟踪层查找对应几何对象失败*/
#define	UGS_TRACKINGLAYER_FAILED_FIND_THE_LABEL_INDEX 30091	/*! 跟踪层查找对应标签的索引失败*/
#define	UGS_TRACKINGLAYER_CANNOT_USE_THE_ADDING_GEO 30092	/*! 跟踪层添加几何对象不可用*/
#define	UGS_TRACKINGLAYER_FAILED_TO_ADD         30093	/*! 跟踪层添加对象失败*/
#define	UGS_TRACKINGLAYER_REMOVE_COUNT_LESSTHAN_ONE 30094	/*! 跟踪层移除个数小于1*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DRAW        30095	/*! 跟踪层绘制失败*/
#define	UGS_TRACKINGLAYER_RECORDSET_IS_NULL_WHEN_DRAW 30096	/*! 跟踪层绘制时记录集为空*/
#define	UGS_TRACKINGLAYER_GETTING_THE_INDEX_INVALID 30097	/*! 跟踪层获取对应对象的索引不合法*/
#define	UGS_TRACKlAYER_RECORDSET_IS_NULL        30098	/*! 跟踪层记录集为空*/
#define	UGS_PATH_COUNT_LESSTHAN_ZERO            30099	/*! 路径个数小于0*/
#define	UGS_FAILED_TO_PATH                      30100	/*! 路径分析失败*/
#define	UGS_ROUTE_COUNT_LESSTHAN_ZERO           30101	/*! 路由个数小于0*/
#define	UGS_TRN_FIELD_ERROR                     30102	/*! 转向表字段设置错误*/
#define	UGS_DTTRN_IS_NULL                       30103	/*! 转向表数据集为空*/
#define	UGS_OUTPUT_MAP_NAME_IS_NULL             30104	/*! 输出地图名字为空*/
#define	UGS_TOO_LARGE_RESOLUTION_WHEN_OUTPUT_MAP 30105	/*! 输出地图时，分辨率太大*/
#define	UGS_FAILED_TO_CREATE_FEAT_DISPLAY_ENGINE_OR_ENGINE_IS_NULL 30106	/*! 输出地图时，创建内存显示引擎为空或者创建合适显示引擎失败*/
#define	UGS_FAILED_TO_CREATE_MEMORY_ENGINE      30107	/*! 创建内存引擎失败*/
#define	UGS_FAILED_TO_CREATE_ALLOT_POINTS_FILE  30108	/*! 创建分配点文件失败*/
#define	UGS_FAILED_TO_CREATE_MEMORY_DISPLAY_ENGINE_WHEN_OUTPUT_MAP 30109	/*! 输出地图时，创建内存显示引擎失败*/
#define	UGS_FAILED_TO_CREATE_FEAT_IAMGE_WHEN_OUTPUT_MAP 30110	/*! 输出地图时，创建合适的图像失败*/
#define	UGS_RASTER_IS_NULL_WHEN_OUTPUT_MAP      30111	/*! 输出地图时，创建栅格数据集为空*/
#define	UGS_IAMGE_OVERRUN_WHEN_OUTPUT_MAP       30112	/*! 输出地图时，图像数据为空或者图像格式小于16位*/
#define	UGS_WIDTH_OVERRUN_WHEN_OUTPUT_MAP       30113	/*! 输出地图时，宽度大于32767*/
#define	UGS_INVALID_DATASET_NAME_WHEN_OUTPUT_MAP 30114	/*! 输出地图时，数据集名称非法*/
#define	UGS_FAILED_TO_OPEN_FILE_WHEN_OUTPUT_MAP 30115	/*! 输出地图时，文件打开失败*/
#define	UGS_HEIGHT_OR_WIDTH_LESSTHAN_TEN_WHEN_OUTPUT_MAP 30116	/*! 输出地图时，高度或者宽度小于10*/
#define	UGS_OUTPUT_MAP_BOUND_IS_NULL            30117	/*! 输出地图范围为空*/
#define	UGS_OUTPUT_BUFFER_HAS_NO_ENOUGH_ROOM    30118	/*! 输出缓存没有足够的空间*/
#define	UGS_OUTPUT_TRN                          30119	/*! 输出转向表*/
#define	UGS_ODBC_ENHANCE_IDS_FAILED             30120	/*! 过滤ID失败*/
#define	UGS_RETURN_FALSE                        30121	/*! 返回false*/
#define	UGS_INVALID_LEVEL_PARAMETER             30122	/*! 这一级别的参数错误。*/
#define	UGS_DATASET_ATTACH_TOPO                 30123	/*! 这个数据集已经参与了Topo*/
#define	UGS_NODE_IS_BARRIER_NODE                30124	/*! 这个是一个障碍点*/
#define	UGS_VIRTUAL_NODES                       30125	/*! 这个是虚节点*/
#define	UGS_NODE_IS_BARRIERNODE                 30126	/*! 这个节点是障碍点*/
#define	UGS_THE_NODE_ANALYSIS_FAILED            30127	/*! 这个节点的分析失败*/
#define	UGS_FAILED_TO_OPEN_APPENDING_DATASET    30128	/*! 追加的数据集打开失败*/
#define	UGS_APPENDING_DATASET_POINTER_IS_NULL   30129	/*! 追加的数据集指针为空*/
#define	UGS_DYNAMICINDEX_WILL_FAIL_IN_SQLPLUS   30130	/*! 追加记录后，动态索引脏*/
#define	UGS_TRACE_INVALID_STARTNODE_AND_ENDNODE 30131	/*! 追踪前后节点非法*/
#define	UGS_FAILED_TO_TRACE                     30132	/*! 追踪失败*/
#define	UGS_TRACE_NODE_LESSTHAN_TWO             30133	/*! 追踪点个数少于两个*/
#define	UGS_INVALID_TRACEPOINT_INDEX            30134	/*! 追踪点索引非法*/
#define	UGS_TRACE_COST_FAILED_TO_ALLOT_MEMORY   30135	/*! 追踪花费内存分配失败*/
#define	UGS_LOCATION_COUNT_LESSTHAN_ZERO        30136	/*! 选址分区个数小于0*/
#define	UGS_SELECT_IMAGE_FAILED_AND_UGDRAWCACHE_PREPARE_FAILED 30137	/*! 选择Image失败，准备绘制缓冲失败*/
#define	UGS_FAILED_TO_INVALIDOBJ_FOR_FAILED_TO_SELECT_IMAGE 30138	/*! 选择Image失败，刷新对象失败*/
#define	UGS_DATASET_OR_SELECT_COUNT_IS_MULL     30139	/*! 选择个数为零或者数据集为空*/
#define	UGS_SELECT_WRONG_ANALYSIS_TYPE          30140	/*! 选择分析类型不正确*/
#define	UGS_SELECT_WRONG_NODE                   30141	/*! 选择模式错误*/
#define	UGS_SELECTION_DELETE_NONE               30142	/*! 选择集中删除个数为零*/
#define	UGS_SELECTION_RECORDSET_POINTER_IS_NULL 30143	/*! 选择集中记录集指针为空*/
#define	UGS_OPTION_INVALID                      30144	/*! 选项非法*/
#define	UGS_SQLPLUS_GET_TEMPLATE_BY_NAME_FAILED 30145	/*! 通过名称获模板失败*/
#define	UGS_ODBC_GETFILEDNAME_BY_SIGN_FAILED    30146	/*! 通过字段类别获取字段名称失败*/
#define	UGS_RESMAPLE_INTERVAL_MUST_MORETHAN_ZERO 30147	/*! 重采样间隔必须大于0*/
#define	UGS_ODBCDATASETRASTER_TIER_ISAVAILABLEDATASETNAME_FAILED 30148	/*! 金字塔数据集名称非法*/
#define	UGS_MAP_HEIGHT_OR_WIDTH_IS_ZERO_LOCKMAPDRAWBOUNDS_FAILED 30149	/*! 锁定地图范围高度或者宽度为0，锁定地图绘制范围失败*/
#define	UG_ERROROBJ_OUTPUT_FORMAT_DEBUG         30150	/*! 错误编号: %ERRORCODE\t 错误信息: %ERRORMSG\t 代码文件: %CODEFILE\t 代码行: %CODELINE\t 线程ID: %THREADID*/
#define	UG_ERROROBJ_OUTPUT_FORMAT               30151	/*! 错误编号: %ERRORCODE\t 错误信息: %ERRORMSG\t 线程ID: %THREADID*/
#define	UGS_ODBCCONNECTION_SQLENDTRAN_FAILED    30152	/*! 长事务回滚失败*/
#define	UGS_DTDMARC_IS_NULL                     30153	/*! 需求弧段数据集为空*/
#define	UGS_DTDMNODES_IS_NULL                   30154	/*! 需求点数据集为空*/
#define	UGS_LAYER_NEEDED_MOVING_OVERRUN         30155	/*! 需要移动的图层不在范围之内*/
#define	UGS_ONLY_TIN_SUPPORT_THIS_METHOD        30156	/*! 只有Tin数据集支持此方法*/
#define	UGS_INVALID_DYNAMIC_LIB_S               30157	/*! 动态库非法：*/
#define	UGS_INVALID_PARAM_FOR_RADIUS_SHOULID_MORETHAN_ZERO 30158	/*! 参数非法：半径不应小于0*/
#define	UGS_INVALID_PARAM_FOR_POINTS_POINTER_AND_POINTS_NOT_NULL 30159	/*! 参数非法：点串指针应非空且传入点串大小应大于0*/
#define	UGS_FAILED_TO_MERGE_FOR_INVALID_DIM     30160	/*! 合并运算的两个几何对象维度不一致，合并失败*/
#define	UGS_INVALID_GML_VERSION                 30161	/*! GML版本信息非法*/
#define	UGS_INVLAID_TOPO_RULES                  30162	/*! Topo规则非法*/
#define	UGS_INVALID_PIXELFORMAT                 30163	/*! 像素格式非法*/
#define	UGS_INVALID_GEO                         30164	/*! 几何对象非法*/
#define	UGS_INVALID_GEO_FOR_SUBCOUNT_EQUAL_ZERO 30165	/*! 几何对象非法：子对象个数为零*/
#define	UGS_FAILED_TO_PREPROCESS                30166	/*! 预处理失败*/
#define	UGS_RECORDSET_POINTER_IS_NULL_WHEN_CONVERT_THEMESTYLE_TO_DATASET 30167	/*! 风格专题图转数据集时记录集指针为空*/
#define	UGS_ODBC_SUPPORT_FUNCTIONS_FAILED       30168	/*! 驱动程序不支持该ODBC函数*/
#define	UGS_FAILED_TO_ONREDO_FOR_MOUSE_CLICK_IS_NULL 30169	/*! 鼠标点击数为0，重做失败*/
#define	UGS_FAILED_TO_ONUNDO_FOR_MOUSE_CLICK_IS_NULL 30170	/*! 鼠标点击数为0，撤销失败*/
#define	UGS_BUFFER_ANALYSIS_RADIUS_IS_ZERO      30171	/*! 缓冲半径为零*/
#define	UGS_OBJECT_IS_NULL                      30172	/*! 对象为空*/
#define	UGS_UGBUSNETWORK_ATTRIBUTE_TABLE_FIELD_ILLEGAL 30173	/*! 加载的属性表字段不符合公交网络属性表字段标准*/

#endif
