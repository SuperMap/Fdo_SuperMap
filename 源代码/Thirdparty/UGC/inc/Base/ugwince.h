/* 
	\file ugwince.h
	\brief WinCE平台的头文件定义
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef _UGWINCE_H
#define _UGWINCE_H

//_WIN32_WCE
// UGC 2.0暂不支持WinCE, 待需要支持时,再进行代码的调整和移植

#define UGopen	fopen
#define UGwrite	fwrite
#define UGread	fread
#define UGseek	fseek
#define UGclose	fclose
// CE环境下，文件操作只有下面的接口
//打开文件：fopen()
//写文件：fwrite()
//读文件：fread()
//定位文件：fseek()
//关闭文件：fclose()


//CE环境下无以下宏定义：
//_MAX_DRIVE
//_MAX_DIR
//_MAX_FNAME
//_MAX_EXT


//CE环境下无以下内容：
//time_t
//clock_t
//clock()
//time()
//mktime()
//asctime()
//ctime()
//difftime()
//gmtime()
//localtime()
//strftime()

//①hypot()在CE下定义为_hypot()
//②CE环境下无getenv()接口


#endif
