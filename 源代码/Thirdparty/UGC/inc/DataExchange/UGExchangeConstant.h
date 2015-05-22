 
#ifndef UG_EXCHANGE_FILE_STRUCTS_PUBLIC
#define UG_EXCHANGE_FILE_STRUCTS_PUBLIC




//1。外部数据文件类型
typedef enum//外部数据文件类型
{
	//fileNone = 0, 表示现在没有指定转入或者转出的文件类型是什么；
		// 在检查转入或者转出参数设置时，碰到这种情况，要报错，并return false。
		TypeNone = 0, 
	
		// SuperMap预留的矢量格式常量 [1, 100]
		// 其中通用矢量格式[1, 50]	XML格式[51, 60]	数据库文件[60, 70]
		// SuperMap开放给用户自行开发的矢量格式常量: [101, 200]

		// AutoCAD File		[1, 5]
		TypeAutoCAD		= 1,	//AutoCAD 文件：DWG 或者 DXF 文件，均可
		TypeDWG			= 2,	//AutoCAD DWG 交换文件
		TypeDXF			= 3,	//AutoCAD DXF 交换文件
		// ERSI File			[6, 10]
		TypeCoverage	= 6,	//Arc/Info Coverage
		TypeE00			= 7,	//Arc/Info E00交换文件
		TypeShape		= 8,	//ArcView Shape文件
		// MapInfo File		[11, 15]
		TypeTAB			= 11,	//MapInfo TAB
		TypeMIF			= 12,	//MapInfo MIF 交换文件
		// MicroStation File [16, 20]
		TypeDGN			= 16,	//Microstation DGN文件
		// other GIS/CAD software File [21, 50]
		TypeVEC			= 21,	//Idrisi 矢量文件
		TypeVCT			= 22,	//国家标准矢量文件 *.VCT
		TypeMapGis		= 23,	//MapGIS明码交换文件  
		// other vector file 
		TypeWMF			= 31,	//wmf文件(windows metaFile:元文件)

		//XML document		[51, 60]
		TypeGML			= 51,	//OpenGIS 定义的XML 文档
		TypeSML			= 52,	//SuperMap 定义的XML文档
		
		//database file		[61, 70]
		TypeDBF			= 61,	//dbf 数据库文件
		TypeMDB			= 62,	//Microsoft Access 数据库文件

		// SuperMap预留的栅格格式常量 [101, 200]
		// 其中影像类[101, 120] 图片类[121, 140] DEM/Grid类[141-160] 
		// 其他[161, 180] 预留格式[181, 200]

		// 影像类[101, 120]
		TypeIMG			= 101,	//Erdas Image文件
		TypeSID			= 102,	//sid文件
		TypeTIF			= 103,	//tif文件
		TypeECW			= 106,	//Er-Mapper ECW文件
		TypeIDR			= 107,	//Idrisi 栅格文件
		TypeFST			= 108,	//Landsat－7 FST文件，后缀名(*.fst)

		// 图片类[121, 140]
		TypeBMP			= 121,	//bitmap文件
		TypeJPG			= 122,	//jpg文件
		TypePNG			= 123,	//portal network graphic(PNG)

		// DEM/Grid类[141-160]
		TypeBIL		= 141,	// BIL格式的grd文件
		TypeArcGrid		= 142,	//Arc/Info 交换文件grd文件
		TypeDEM			= 143,	//国标格网数据文件
		TypeUSGSGrid	= 144,	//USGS格网数据文件 美国标准
		TypeArcBinaryGrid = 145,	//Arc/Info binary grid文件，可以在arcinfo中用GridAscii和AsciiGrid命令与 fileGRD 格式进行互换

		// 其他[161, 180]
		TypeRAW			= 161,	//raw文件

		// 预留格式[181, 200]
		TypeGIF			= 181,	//gif文件
		TypeTGA			= 182,	//tga文件
		
		
		//Japanese File (vector[200, 250] and rastor[251, 300])
		//Japanese File vector [200, 250]
		TypeGXML		= 200, //日本定义的 XML文档
		TypeJIF50		= 201, //*.mem,日本国土信息院的50矢量图文件格式
		TypeJIF250		= 202, //*.sem,日本国土信息院的250矢量图文件格式
		TypeJIF1000		= 203, //*.tem,日本国土信息院的1000矢量图文件格式
		TypeJIF2500		= 204, //*.txt,日本国土信息院的2500矢量图文件格式
		TypeJIF10000	= 205, //*.lge,日本国土信息院的10000矢量图文件格式
		TypeJIF25000	= 206, //*.mby,日本国土信息院的25000矢量图文件格式

		TypeENC			= 210, //日本海图ENC格式（*.000文件）

		//Japanese File rastor [251, 300]
		TypeJRF10Landuse = 251, //*.tdu,日本国土信息院的10LANDUSE栅格文件格式
		//*.tdg,日本国土信息院的10m栅格文件格式
		//以前认为日本国土信息院的10m栅格文件格式只有一种是*.tdu,是土地利用数据
		//现在知道还有一种是*.tdg，描述行政区域数据，名称没有办法改了，里面的格式完全一样

		TypeJRF10Volcano= 252, //*.dat,日本国土信息院的10VOLCANO栅格文件格式
		TypeJRF50		= 253, //*.mem,日本国土信息院的50栅格文件格式
		TypeJRF250		= 254, //*.sem,日本国土信息院的250栅格文件格式
		TypeJRF1000		= 255, //*.tem,日本国土信息院的1000栅格文件格式
		TypeJRF10000	= 256, //*.lbi,日本国土信息院的10000栅格文件格式
		TypeJIFSDF		= 257, //*.xml,日本国土地理院的数值地图25000空间基盘(Spatial Data Framework)

		// 这里再预留 100个编号 给可能的使用 [301, 400]

		// SuperMap为用户自行开发数据转换预留的文件格式常量 [401, 500]
		// 矢量: [401, 450]
		TypeUserVectorBegin	= 401, 
		TypeUserVectorEnd	= 450, 
		// 栅格: [451, 500]
		TypeUserRasterBegin	= 451, 
		TypeUserRasterEnd	= 500

} FileType;




enum
{
	GeoRefFile_NONE= 0, //用户没有指定影像坐标参考文件的类型
	GeoRefFile_DOM = 1, //类型为 dom, 国标地理坐标文件
	GeoRefFile_TFW = 2, //类型为 tfw, TIFF地理坐标文件
	GeoRefFile_SMC = 3, //类型为 smc（supermap自定义，xml文档）
	GeoRefFile_GB = 4//真正的国标地理坐标文件，上面的dom是以前错误的理解，文件后缀是img
};


//mif version or mapinfo version???
typedef enum
{
	VersUnkown = 0 
	
}UGVersion; //mif? mapinfo?




#endif
