@ECHO OFF

REM
REM SuperMap FDO Provider ±‡“Î≈˙¥¶¿Ì
REM
REM Copyright (C)  1996-2007 SuperMap GIS Technologies,Inc.
REM All Rights Reserved
REM YuJiang(Leo)
REM

SVN up
CALL Buildall Rebuild

IF EXIST setup GOTO setup
MKDIR setup
:setup

IF EXIST setup\lang GOTO copying
MKDIR setup\lang
:copying

COPY /Y /V bin\lang\en_US.dll setup\lang\en_US.dll
COPY /Y /V bin\EPSFont.xml setup\EPSFont.xml
COPY /Y /V bin\resource.xml setup\resource.xml
COPY /Y /V bin\ugc.xml setup\ugc.xml
COPY /Y /V bin\PrjConfig.xml setup\PrjConfig.xml
COPY /Y /V bin\Install.exe setup\Install.exe
COPY /Y /V bin\filelist.lst setup\filelist.lst
COPY /Y /V bin\gdal132.dll setup\gdal132.dll
COPY /Y /V bin\libiconv-2.dll setup\libiconv-2.dll
COPY /Y /V bin\libpng12.dll setup\libpng12.dll
COPY /Y /V bin\sqlite.dll setup\sqlite.dll
COPY /Y /V bin\zlib1.dll setup\zlib1.dll
COPY /Y /V bin\libcurl.dll setup\libcurl.dll
COPY /Y /V bin\SuAlgorithm200.dll setup\SuAlgorithm200.dll
COPY /Y /V bin\SuBase200.dll setup\SuBase200.dll
COPY /Y /V bin\SuCompoundFile200.dll setup\SuCompoundFile200.dll
COPY /Y /V bin\SuDataExchange200.dll setup\SuDataExchange200.dll
REM COPY /Y /V bin\SuDB2Engine200.sdx setup\SuDB2Engine200.sdx
COPY /Y /V bin\SuEngine200.dll setup\SuEngine200.dll
REM COPY /Y /V bin\SuFileEngine200.sdx setup\SuFileEngine200.sdx
COPY /Y /V bin\SuFileParser200.dll setup\SuFileParser200.dll
COPY /Y /V bin\SuGeometry200.dll setup\SuGeometry200.dll
COPY /Y /V bin\SuGraphics200.dll setup\SuGraphics200.dll
COPY /Y /V bin\SuODBCEngine200.dll setup\SuODBCEngine200.dll
COPY /Y /V bin\SuOperation200.dll setup\SuOperation200.dll
COPY /Y /V bin\SuOrcEngine200.sdx setup\SuOrcEngine200.sdx
COPY /Y /V bin\SuProject200.dll setup\SuProject200.dll
COPY /Y /V bin\SuPSGraphics200.uge setup\SuPSGraphics200.uge
COPY /Y /V bin\SuSdbPlusEngine200.sdx setup\SuSdbPlusEngine200.sdx
COPY /Y /V bin\SuSITEngine200.sdx setup\SuSITEngine200.sdx
COPY /Y /V bin\SuSqlPlusEngine200.sdx setup\SuSqlPlusEngine200.sdx
COPY /Y /V bin\SuTopology200.dll setup\SuTopology200.dll
REM COPY /Y /V bin\SuUdbEngine200.sdx setup\SuUdbEngine200.sdx
COPY /Y /V bin\SuWGraphics200.uge setup\SuWGraphics200.uge
REM COPY /Y /V bin\SuWebEngine200.sdx setup\SuWebEngine200.sdx

COPY /Y /V bin\SuperMapMessage.dll setup\SuperMapMessage.dll
COPY /Y /V bin\SuperMapMessage.dll setup\SuperMapMessageCN.dll
COPY /Y /V bin\SuperMapProvider.dll setup\SuperMapProvider.dll
COPY /Y /V bin\SuperMapConnectionPlugin.dll setup\SuperMapConnectionPlugin.dll
COPY /Y /V bin\SuperMapConnectionPluginEN.dll setup\SuperMapConnectionPluginEN.dll
COPY /Y /V bin\SuperMapConnectionPluginCN.dll setup\SuperMapConnectionPluginCN.dll




