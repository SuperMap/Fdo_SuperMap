//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//


function ExpandEnvironmentVar (EnvVarName)
{
    try
    {
        var fsh;
        fsh = new ActiveXObject('WScript.Shell');
        return fsh.ExpandEnvironmentStrings(EnvVarName);
    }
    catch(e)
    {
        return EnvVarName;
    }
}

function FindFdo (proj)
{
    try
    {
        fso = new ActiveXObject('Scripting.FileSystemObject');
        var project_path = proj.Object.ProjectDirectory;
        // count the slashes
        var count = -1;
        var index = -1;
        do
        {
            count++;
            index++;
            index = project_path.indexOf('\\', index);
        }
        while (index != -1);
        var relpath = '..\\';
        do
        {
            if (fso.FileExists(project_path + relpath + 'Fdo\\Unmanaged\\Inc\\Fdo.h'))
                return (relpath);
            else
                relpath += '..\\';
            count--;
        }
        while (count > 0);
    }
    catch(e)
    {
        throw e;
    }
    return (ExpandEnvironmentVar('%FDO%') + '\\');     
}

function FindFdoCommon (proj)
{
    try
    {
        fso = new ActiveXObject('Scripting.FileSystemObject');
        var project_path = proj.Object.ProjectDirectory;
        // count the slashes
        var count = -1;
        var index = -1;
        do
        {
            count++;
            index++;
            index = project_path.indexOf('\\', index);
        }
        while (index != -1);
        var relpath = '..\\';
        do
        {
            if (fso.FileExists(project_path + relpath + 'Utilities\\Common\\Inc\\stdafx.h'))
                return (project_path + relpath + 'Utilities\\');
            else
                relpath += '..\\';
            count--;
        }
        while (count > 0);
    }
    catch(e)
    {
        throw e;
    }
    return (ExpandEnvironmentVar('%FDOUTILITIES%') + '\\');     
}

function AddToLog (textVal)
{
    fso = new ActiveXObject('Scripting.FileSystemObject');
    var a = fso.CreateTextFile("c:\\testfile.txt", true);
    a.WriteLine(textVal);
    a.Close();
}

function OnFinish(selProj, selObj)
{
    try
    {
        var strProjectPath = wizard.FindSymbol('PROJECT_PATH');
        var strProjectName = wizard.FindSymbol('PROJECT_NAME');
        var prefix = wizard.FindSymbol('PREFIX');
        wizard.AddSymbol('UPPER_PREFIX', prefix.toUpperCase(), false);
        wizard.AddSymbol('LOWER_PREFIX', prefix.toLowerCase(), false);

        selProj = CreateCustomProject(strProjectName, strProjectPath);
        var fdo = FindFdo (selProj);
        var fdocommon = FindFdoCommon (selProj);
        AddConfig(selProj, strProjectName, fdo, fdocommon);

        var InfFile = CreateCustomInfFile();
        AddFilesToCustomProj(selProj, strProjectName, strProjectPath, InfFile);
        PchSettings(selProj);
        InfFile.Delete();

        selProj.Object.Save();
        
        var msgProj = CreateCustomMessageProject(strProjectName, strProjectPath);
        AddMessageConfig(msgProj, strProjectName, fdo, fdocommon);
        AddFilesToCustomMessageProj(msgProj, strProjectName, strProjectPath);

        msgProj.Object.Save();

        // establish the dependancy of the provider project on the message project
        var dependancies = DTE.Solution.SolutionBuild.BuildDependencies;
        var i;
        for (i = 1; i <= dependancies.Count; i++)
            if (strProjectName + 'Provider' == dependancies.Item(i).Project.Name)
                dependancies.Item(i).AddProject(msgProj.UniqueName);

        var tstProj = CreateCustomUnitTestProject(strProjectName, strProjectPath);
        AddUnitTestConfig(tstProj, strProjectName, fdo, fdocommon);
        AddFilesToCustomUnitTestProj(tstProj, strProjectName, strProjectPath, fdo);

        tstProj.Object.Save();
        
        // establish the dependancy of the unit test project on the provider project
        for (i = 1; i <= dependancies.Count; i++)
            if (tstProj.Name == dependancies.Item(i).Project.Name)
                dependancies.Item(i).AddProject(selProj.UniqueName);

        // add the ProvidersCommon project
        var commonProj = DTE.Solution.AddFromFile(ExpandEnvironmentVar('%FDOUTILITIES%') + '\\Common\\FdoCommon.vcproj');

        // establish the dependancy of the provider and unit test project on the FdoCommon project
        for (i = 1; i <= dependancies.Count; i++)
        {
            if (tstProj.Name == dependancies.Item(i).Project.Name)
                dependancies.Item(i).AddProject(commonProj.UniqueName);
            if (selProj.Name == dependancies.Item(i).Project.Name)
                dependancies.Item(i).AddProject(commonProj.UniqueName);
        }

        // set the UnitTest project as the startup project
        DTE.Solution.SolutionBuild.StartupProjects = tstProj;
    }
    catch(e)
    {
        if (e.description.length != 0)
            SetErrorInfo(e);
        return e.number
    }
}

function CreateCustomProject(strProjectName, strProjectPath)
{
    try
    {
        var strSolutionPath = strProjectPath.substr(0, strProjectPath.length - strProjectName.length);
        var strProjTemplatePath = wizard.FindSymbol('PROJECT_TEMPLATE_PATH');
        var strProjTemplate = '';
        strProjTemplate = strProjTemplatePath + '\\default.vcproj';

        var Solution = dte.Solution;
        var strSolutionName = "";
        if (wizard.FindSymbol("CLOSE_SOLUTION"))
        {
            Solution.Close();
            if (strSolutionName.length)
            {
                Solution.Create(strSolutionPath, strSolutionName);
                fso = new ActiveXObject('Scripting.FileSystemObject');
                fso.CreateFolder(strSolutionPath + strProjectName);
                fso.CreateFolder(strSolutionPath + strProjectName + '\\Src');
                fso.CreateFolder(strSolutionPath + strProjectName + '\\Src\\Provider');
            }
            else
            {
                fso = new ActiveXObject('Scripting.FileSystemObject');
                fso.CreateFolder(strSolutionPath);
                fso.CreateFolder(strSolutionPath + strProjectName);
                fso.CreateFolder(strSolutionPath + strProjectName + '\\Src');
                fso.CreateFolder(strSolutionPath + strProjectName + '\\Src\\Provider');
                Solution.Create(strSolutionPath + strProjectName + '\\Src\\', strProjectName);
            }
        }

        var strProjectNameWithExt = '';
        strProjectNameWithExt = 'Src\\Provider\\' + strProjectName + 'Provider.vcproj';

        var oTarget = wizard.FindSymbol("TARGET");
        var prj;
        if (wizard.FindSymbol("WIZARD_TYPE") == vsWizardAddSubProject)  // vsWizardAddSubProject
        {
            var prjItem = oTarget.AddFromTemplate(strProjTemplate, strProjectNameWithExt);
            prj = prjItem.SubProject;
        }
        else
        {
            prj = oTarget.AddFromTemplate(strProjTemplate, strProjectPath, strProjectNameWithExt);
        }
        prj.Name = strProjectName + 'Provider';
        return prj;
    }
    catch(e)
    {
        throw e;
    }
}

function AddConfig(proj, strProjectName, fdo_path, fdocommon_path)
{
    try
    {
        var prefix = wizard.FindSymbol('PREFIX');
        var upper_prefix = prefix.toUpperCase();

        // VCConfiguration
        var config = proj.Object.Configurations('Debug');
        config.OutputDirectory = '..\\..\\Bin\\Win32\\Debug';
        config.IntermediateDirectory = 'Debug';
        config.ConfigurationType = ConfigurationTypes.typeDynamicLibrary;
        config.CharacterSet = charSet.charSetUnicode;

        // VCCLCompilerTool
        var CLTool = config.Tools('VCCLCompilerTool');
        CLTool.AdditionalIncludeDirectories = '.\\;$(FDO)\\Unmanaged\\Inc;..\\..\\..\\Inc;$(FDOUTILITIES)\\Common\\Inc'
        CLTool.DebugInformationFormat = debugOption.debugEditAndContinue;
        CLTool.Detect64BitPortabilityProblems = true;
        CLTool.WarningLevel = 3;
        CLTool.Optimization = optimizeOption.optimizeDisabled;
        CLTool.PreprocessorDefinitions = 'WIN32;_DEBUG;_WINDOWS;_USRDLL;_CRT_SECURE_NO_DEPRECATE;' + upper_prefix + '_EXPORTS';
        CLTool.TreatWChar_tAsBuiltInType = true;
        CLTool.UsePrecompiledHeader = pchOption.pchUseUsingSpecific;
        CLTool.RuntimeLibrary = rtMultiThreadedDebugDLL;
        CLTool.RuntimeTypeInfo = true;

        // VCLinkerTool
        var LinkTool = config.Tools('VCLinkerTool');
        LinkTool.AdditionalLibraryDirectories = '$(FDO)\\Unmanaged\\Lib\\Win32\\Debug;$(FDOUTILITIES)\\Common\\Lib\\Win32\\Debug';
        LinkTool.AdditionalDependencies = 'FDO.lib ProvidersCommon.lib FDOGeometry.lib FDONLS.lib FdoCommon.lib FDOSpatial.lib';
        LinkTool.GenerateDebugInformation = true;
        LinkTool.ProgramDatabaseFile = '$(OutDir)/'+ upper_prefix + 'Provider.pdb';
        LinkTool.OutputFile = '$(OutDir)/'+ upper_prefix + 'Provider.dll';
        LinkTool.ImportLibrary = '..\\..\\Lib\\Win32\\Debug\\' + upper_prefix + 'Provider.lib';

        var CLPostBuildEvent = config.Tools('VCPostBuildEventTool');
		CLPostBuildEvent.Description = 'Versioning ' + upper_prefix + 'Provider.dll';
    	CLPostBuildEvent.CommandLine = '$(FDOTHIRDPARTY)\\util\\stampver\\StampVer.exe -v\"..\\..\\SubDoc\\Providers.version\" -f\"3.2.0.0%PROVIDERS_VERSION%\" $(OutDir)\\' + upper_prefix + 'Provider.dll';

    	var CLPreLinkEvent = config.Tools('VCPreLinkEventTool');
		CLPreLinkEvent.CommandLine = 'if not exist ..\\..\\Lib\\Win32\\Debug mkdir ..\\..\\Lib\\Win32\\Debug';

        config = proj.Object.Configurations('Release');
        config.OutputDirectory = '..\\..\\Bin\\Win32\\Release';
        config.IntermediateDirectory = 'Release';
        config.ConfigurationType = ConfigurationTypes.typeDynamicLibrary;
        config.CharacterSet = charSet.charSetUnicode;

        CLTool = config.Tools('VCCLCompilerTool');
        CLTool.AdditionalIncludeDirectories = '.\\;$(FDO)\\Unmanaged\\Inc;..\\..\\..\\Inc;$(FDOUTILITIES)\\Common\\Inc'
        CLTool.PreprocessorDefinitions = 'WIN32;NDEBUG;_WINDOWS;_USRDLL;_CRT_SECURE_NO_DEPRECATE;' + upper_prefix + '_EXPORTS';
        CLTool.TreatWChar_tAsBuiltInType = true;
        CLTool.UsePrecompiledHeader = pchOption.pchUseUsingSpecific;
        CLTool.RuntimeLibrary = rtMultiThreadedDLL;
        CLTool.RuntimeTypeInfo = true;

        LinkTool = config.Tools('VCLinkerTool');
        LinkTool.AdditionalLibraryDirectories = '$(FDO)\\Unmanaged\\Lib\\Win32\\Release;$(FDOUTILITIES)\\Common\\Lib\\Win32\\Release';
        LinkTool.AdditionalDependencies = 'FDO.lib ProvidersCommon.lib FDOGeometry.lib FDONLS.lib FdoCommon.lib FDOSpatial.lib';
        LinkTool.GenerateDebugInformation = true;
        LinkTool.ProgramDatabaseFile = '$(OutDir)/'+ upper_prefix + 'Provider.pdb';
        LinkTool.OutputFile = '$(OutDir)/'+ upper_prefix + 'Provider.dll';
        LinkTool.ImportLibrary = '..\\..\\Lib\\Win32\\Release\\' + upper_prefix + 'Provider.lib';
        
        CLPostBuildEvent = config.Tools('VCPostBuildEventTool');
		CLPostBuildEvent.Description = 'Versioning ' + upper_prefix + 'Provider.dll';
    	CLPostBuildEvent.CommandLine = '$(FDOTHIRDPARTY)\\util\\stampver\\StampVer.exe -v\"..\\..\\SubDoc\\Providers.version\" -f\"3.2.0.0%PROVIDERS_VERSION%\" $(OutDir)\\' + upper_prefix + 'Provider.dll';
    	
    	CLPreLinkEvent = config.Tools('VCPreLinkEventTool');
		CLPreLinkEvent.CommandLine = 'if not exist ..\\..\\Lib\\Win32\\Release mkdir ..\\..\\Lib\\Win32\\Release';
    }
    catch(e)
    {
        throw e;
    }
}

function PchSettings(proj)
{
    // TODO: specify pch settings
}

function DelFile(fso, strWizTempFile)
{
    try
    {
        if (fso.FileExists(strWizTempFile))
        {
            var tmpFile = fso.GetFile(strWizTempFile);
            tmpFile.Delete();
        }
    }
    catch(e)
    {
        throw e;
    }
}

function CreateCustomInfFile()
{
    try
    {
        var fso, TemplatesFolder, TemplateFiles, strTemplate;
        fso = new ActiveXObject('Scripting.FileSystemObject');

        var TemporaryFolder = 2;
        var tfolder = fso.GetSpecialFolder(TemporaryFolder);
        var strTempFolder = tfolder.Drive + '\\' + tfolder.Name;

        var strWizTempFile = strTempFolder + "\\" + fso.GetTempName();

        var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');
        var strInfFile = strTemplatePath + '\\Templates.inf';
        wizard.RenderTemplate(strInfFile, strWizTempFile);

        var WizTempFile = fso.GetFile(strWizTempFile);
        return WizTempFile;
    }
    catch(e)
    {
        throw e;
    }
}

function GetTargetName(strName, strProjectName)
{
    try
    {
        var prefix;
        var ProjectPrefix = wizard.FindSymbol('PREFIX');
        var strTarget = strName;
        var strExt = strTarget.substr(strTarget.lastIndexOf("."));
        if(strExt==".cpp" || strExt==".h" || strExt==".mc" || strExt==".rc" )
            prefix = ProjectPrefix;
        else
            prefix = '';

        if (strName == 'ReadMe.txt')
            strTarget = 'ReadMe.txt';
        else if (strName == 'stdafx.h')
            strTarget = 'stdafx.h';
        else if (strName == 'stdafx.cpp')
            strTarget = 'stdafx.cpp';
        else if (strName == 'Fdo.h')
            strTarget = 'Fdo' + prefix + '.h';
        else if (strName == 'resourcep.h')
            strTarget = 'resource.h';
        else
            strTarget = prefix + strTarget;

        return strTarget; 
    }
    catch(e)
    {
        throw e;
    }
}

function AddFilesToCustomProj(proj, strProjectName, strProjectPath, InfFile)
{
    try
    {
        var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');

        var strTpl = '';
        var strName = '';
        var group;
        var i;

        var strTextStream = InfFile.OpenAsTextStream(1, -2);
        while (!strTextStream.AtEndOfStream)
        {
            strTpl = strTextStream.ReadLine();
            if (strTpl != '')
            {
                strName = strTpl;
                if (strName.substr(0, 1) == '#')
                {
                    group = proj.Object.AddFilter(strName.substr(1));
                    continue;
                }
                var strTarget = GetTargetName(strName, strProjectName);
                var strTemplate = strTemplatePath + '\\' + strTpl;
                var strFile = strProjectPath + '\\Src\\Provider\\' + strTarget;

                var bCopyOnly = false;  //"true" will only copy the file from strTemplate to strTarget without rendering/adding to the project
                var strExt = strName.substr(strName.lastIndexOf("."));
                if(strExt==".bmp" || strExt==".ico" || strExt==".gif" || strExt==".rtf" || strExt==".css")
                    bCopyOnly = true;
                wizard.RenderTemplate(strTemplate, strFile, bCopyOnly);
                var file = group.AddFile (strFile);
                if (strTarget == 'stdafx.cpp')
                {
                    var tool = file.FileConfigurations.Item("Debug|Win32").Tool;
                    tool.UsePrecompiledHeader = pchOption.pchCreateUsingSpecific;
                    tool = file.FileConfigurations.Item("Release|Win32").Tool;
                    tool.UsePrecompiledHeader = pchOption.pchCreateUsingSpecific;
                }
            }
        }
        strTextStream.Close();
    }
    catch(e)
    {
        throw e;
    }
}

function CreateCustomMessageProject(strProjectName, strProjectPath)
{
    try
    {
        var strSolutionPath = strProjectPath.substr(0, strProjectPath.length - strProjectName.length);
        var strProjTemplatePath = wizard.FindSymbol('PROJECT_TEMPLATE_PATH');
        var strProjTemplate = '';
        strProjTemplate = strProjTemplatePath + '\\default.vcproj';

        var strProjectNameWithExt = '';
        strProjectNameWithExt = 'Src\\Message\\' + strProjectName + 'Message.vcproj';
        fso = new ActiveXObject('Scripting.FileSystemObject');
        fso.CreateFolder(strSolutionPath + strProjectName + '\\Src\\Message');

        var oTarget = wizard.FindSymbol("TARGET");
        var prj;
        if (wizard.FindSymbol("WIZARD_TYPE") == vsWizardAddSubProject)  // vsWizardAddSubProject
        {
            var prjItem = oTarget.AddFromTemplate(strProjTemplate, strProjectNameWithExt);
            prj = prjItem.SubProject;
        }
        else
        {
            prj = oTarget.AddFromTemplate(strProjTemplate, strProjectPath, strProjectNameWithExt, false);
        }
        prj.Name = strProjectName + 'Message';
        return prj;
    }
    catch(e)
    {
        throw e;
    }
}

function AddMessageConfig(proj, strProjectName, fdo_path, fdocommon_path)
{
    try
    {
        var prefix = wizard.FindSymbol('PREFIX');
        var upper_prefix = prefix.toUpperCase();

        // VCConfiguration
        var config = proj.Object.Configurations('Debug');
        config.OutputDirectory = '..\\..\\Bin\\Win32\\Debug';
        config.IntermediateDirectory = 'Debug';
        config.ConfigurationType = ConfigurationTypes.typeDynamicLibrary;
        config.CharacterSet = charSet.charSetUnicode;

        // VCCLCompilerTool
        var CLTool = config.Tools('VCCLCompilerTool');
        CLTool.DebugInformationFormat = debugOption.debugEnabled;
        CLTool.PreprocessorDefinitions = 'WIN32;_DEBUG;_WINDOWS';

        // VCLinkerTool
        var LinkTool = config.Tools('VCLinkerTool');
        LinkTool.IgnoreImportLibrary = true;
        LinkTool.ResourceOnlyDLL = true;

        config = proj.Object.Configurations('Release');
        config.OutputDirectory = '..\\..\\Bin\\Win32\\Release';
        config.IntermediateDirectory = 'Release';
        config.ConfigurationType = ConfigurationTypes.typeDynamicLibrary;
        config.CharacterSet = charSet.charSetUnicode;

        var CLTool = config.Tools('VCCLCompilerTool');
        CLTool.PreprocessorDefinitions = 'WIN32;NDEBUG;_WINDOWS';

        var LinkTool = config.Tools('VCLinkerTool');
        LinkTool.IgnoreImportLibrary = true;
        LinkTool.ResourceOnlyDLL = true;
    }
    catch(e)
    {
        throw e;
    }
}

function AddFilesToCustomMessageProj(proj, strProjectName, strProjectPath)
{
    try
    {
        var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');
        var strName = '';

        strName = 'Message.mc';
        var strTarget = GetTargetName(strName, strProjectName);
        var strTemplate = strTemplatePath + '\\' + strName;
        var strFile = strProjectPath + '\\Src\\Message\\' + strTarget;
        wizard.RenderTemplate(strTemplate, strFile, false);
        var file = proj.Object.AddFile(strFile);

        // configure the custom command
        var tool = proj.Object.Configurations.Item(1).Tools("VCCustomBuildTool");
        file.FileConfigurations.Item("Debug|Win32").Tool = tool;
        tool = file.FileConfigurations.Item("Debug|Win32").Tool; // need to refetch it for some reason
        var generated = GetTargetName('Message.rc', strProjectName);
        var dynamic = GetTargetName('MessageDynamic.rc', strProjectName);
        var staticrc = GetTargetName('MessageStatic.rc', strProjectName);
        var h = GetTargetName('Message.h', strProjectName);
        var dynamich = GetTargetName('MessageDynamic.h', strProjectName);
        var statich = GetTargetName('MessageStatic.h', strProjectName);
        tool.CommandLine =
          "mc -U -h Inc\\ -r .\\ ./" + strTarget + 
          "\nren .\\" + generated + " " + dynamic +
          "\ncopy .\\" + staticrc + "+.\\" + dynamic + " .\\" + generated +
          "\ndel .\\" + dynamic +
          "\nren Inc\\" + h + " " + dynamich +
          "\ncopy " + statich + "+Inc\\" + dynamich + " Inc\\" + h +
          "\ndel Inc\\" + dynamich;
        tool.Description = "Performing Custom Build Step:  Creating " + h + " and " + generated + " from " + strTarget;
        tool.Outputs = "Inc\\" + h + ";.\\" + generated;
        var tool2 = file.FileConfigurations.Item("Release|Win32").Tool;
        tool2.CommandLine = tool.CommandLine;
        tool2.Description = tool.Description;
        tool2.Outputs = tool.Outputs;

        strName = 'MessageStatic.rc';
        var strTarget = GetTargetName(strName, strProjectName);
        var strTemplate = strTemplatePath + '\\' + strName;
        var strFile = strProjectPath + '\\Src\\Message\\' + strTarget;
        wizard.RenderTemplate(strTemplate, strFile, false);

        strName = 'resource.h';
        var strTemplate = strTemplatePath + '\\' + strName;
        var strFile = strProjectPath + '\\Src\\Message\\' + strName;
        wizard.RenderTemplate(strTemplate, strFile, false);
        proj.Object.AddFile(strFile);

        strName = 'MessageStatic.h';
        var strTarget = GetTargetName(strName, strProjectName);
        var strTemplate = strTemplatePath + '\\' + strName;
        var strFile = strProjectPath + '\\Src\\Message\\' + strTarget;
        wizard.RenderTemplate(strTemplate, strFile, false);
        proj.Object.AddFile(strFile);

        // add the created file without rendering from a template
        strName = 'Message.rc';
        var strTarget = GetTargetName(strName, strProjectName);
        var strFile = strProjectPath + '\\Src\\Message\\' + strTarget;
        proj.Object.AddFile(strFile);
    }
    catch(e)
    {
        throw e;
    }
}

function CreateCustomUnitTestProject(strProjectName, strProjectPath)
{
    try
    {
        var strSolutionPath = strProjectPath.substr(0, strProjectPath.length - strProjectName.length);
        var strProjTemplatePath = wizard.FindSymbol('PROJECT_TEMPLATE_PATH');
        var strProjTemplate = '';
        strProjTemplate = strProjTemplatePath + '\\default.vcproj';

        var strProjectNameWithExt = '';
        strProjectNameWithExt = 'Src\\UnitTest\\' + 'UnitTest.vcproj';
        fso = new ActiveXObject('Scripting.FileSystemObject');
        fso.CreateFolder(strSolutionPath + strProjectName + '\\Src\\UnitTest');

        var oTarget = wizard.FindSymbol("TARGET");
        var prj;
        if (wizard.FindSymbol("WIZARD_TYPE") == vsWizardAddSubProject)  // vsWizardAddSubProject
        {
            var prjItem = oTarget.AddFromTemplate(strProjTemplate, strProjectNameWithExt);
            prj = prjItem.SubProject;
        }
        else
        {
            prj = oTarget.AddFromTemplate(strProjTemplate, strProjectPath, strProjectNameWithExt, false);
        }
        prj.Name = 'UnitTest';
        return prj;
    }
    catch(e)
    {
        throw e;
    }
}

function AddUnitTestConfig(proj, strProjectName, fdo_path, fdocommon_path)
{
    try
    {
        var prefix = wizard.FindSymbol('PREFIX');
        var upper_prefix = prefix.toUpperCase();

        // VCConfiguration
        var config = proj.Object.Configurations('Debug');
        config.OutputDirectory = '..\\..\\Bin\\Win32\\Debug';
        config.IntermediateDirectory = 'Debug';
        config.ConfigurationType = ConfigurationTypes.typeApplication;
        config.UseOfMfc = useOfMfc.useMfcDynamic;
        config.CharacterSet = charSet.charSetMBCS;

        // VCCLCompilerTool
        var CLTool = config.Tools('VCCLCompilerTool');
        CLTool.AdditionalIncludeDirectories = '.\\;$(FDO)\\Unmanaged\\Inc;..\\..\\..\\Inc;$(FDOUTILITIES)\\Common\\Inc;$(FDOTHIRDPARTY)\\cppunit\\include';
        CLTool.DebugInformationFormat = debugOption.debugEditAndContinue;
        CLTool.Detect64BitPortabilityProblems = true;
        CLTool.WarningLevel = 3;
        CLTool.Optimization = optimizeOption.optimizeDisabled;
        CLTool.PreprocessorDefinitions = 'WIN32;_DEBUG;_WINDOWS;_CRT_SECURE_NO_DEPRECATE';
        CLTool.TreatWChar_tAsBuiltInType = true;
        CLTool.UsePrecompiledHeader = pchOption.pchUseUsingSpecific;
        CLTool.RuntimeLibrary = rtMultiThreadedDebugDLL;

        // VCLinkerTool
        var LinkTool = config.Tools('VCLinkerTool');
        LinkTool.AdditionalLibraryDirectories = '$(FDO)\\Unmanaged\\Lib\\Win32\\Debug;$(FDOUTILITIES)\\Common\\Lib\\Win32\\Debug;$(FDOTHIRDPARTY)\\cppunit\\lib';
        LinkTool.AdditionalDependencies = 'FDO.lib ProvidersCommon.lib FDOGeometry.lib FDONLS.lib FdoCommon.lib testrunnerd.lib cppunitd.lib';
        LinkTool.IgnoreDefaultLibraryNames = 'libcmtd.lib';
        LinkTool.GenerateDebugInformation = true;
        LinkTool.ProgramDatabaseFile = '$(OutDir)/$(ProjectName).pdb';

        config = proj.Object.Configurations('Release');
        config.OutputDirectory = '..\\..\\Bin\\Win32\\Release';
        config.IntermediateDirectory = 'Release';
        config.ConfigurationType = ConfigurationTypes.typeApplication;
        config.UseOfMfc = useOfMfc.useMfcDynamic;
        config.CharacterSet = charSet.charSetMBCS;

        var CLTool = config.Tools('VCCLCompilerTool');
        CLTool.AdditionalIncludeDirectories = '.\\;$(FDO)\\Unmanaged\\Inc;..\\..\\..\\Inc;$(FDOUTILITIES)\\Common\\Inc;$(FDOTHIRDPARTY)\\cppunit\\include';
        CLTool.PreprocessorDefinitions = 'WIN32;NDEBUG;_WINDOWS;_CRT_SECURE_NO_DEPRECATE';
        CLTool.TreatWChar_tAsBuiltInType = true;
        CLTool.UsePrecompiledHeader = pchOption.pchUseUsingSpecific;
        CLTool.RuntimeLibrary = rtMultiThreadedDLL;

        var LinkTool = config.Tools('VCLinkerTool');
        LinkTool.AdditionalLibraryDirectories = '$(FDO)\\Unmanaged\\Lib\\Win32\\Release;$(FDOUTILITIES)\\Common\\Lib\\Win32\\Release;$(FDOTHIRDPARTY)\\cppunit\\lib';
        LinkTool.AdditionalDependencies = 'FDO.lib ProvidersCommon.lib FDOGeometry.lib FDONLS.lib FdoCommon.lib testrunnerd.lib cppunitd.lib';
    }
    catch(e)
    {
        throw e;
    }
}

function AddUnitTestFile (group, filename)
{
    var file;
    var tool;

    file = group.AddFile(filename);
    tool = file.FileConfigurations.Item("Debug|Win32").Tool;
    tool.UsePrecompiledHeader = pchOption.pchUseUsingSpecific;
    tool.PrecompiledHeaderThrough = 'StdAfx.h'
    tool.PrecompiledHeaderFile = '$(IntDir)/StdAfx.pch';
    tool = file.FileConfigurations.Item("Release|Win32").Tool;
    tool.UsePrecompiledHeader = pchOption.pchUseUsingSpecific;
    tool.PrecompiledHeaderThrough = 'StdAfx.h'
    tool.PrecompiledHeaderFile = '$(IntDir)/StdAfx.pch';
    
    return (file);
}

function AddFilesToCustomUnitTestProj(proj, strProjectName, strProjectPath, fdo_path)
{
    var group;
    var file;
    var prototool;
    var tool;
    var tool2;
    var strTemplatePath;
    var strName;
    var strTemplate;
    var strFile;
    var strThird;
    
    strThird = ExpandEnvironmentVar('%FDOTHIRDPARTY%');
    try
    {
        strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');
        group = proj.Object.AddFilter ('Framework')
        AddUnitTestFile (group, strThird + '\\cppunit\\HostApp\\HostApp.cpp');
        group.AddFile (strThird + '\\cppunit\\HostApp\\HostApp.h');
        AddUnitTestFile (group, strThird + '\\cppunit\\HostApp\\HostAppDoc.cpp');
        group.AddFile (strThird + '\\cppunit\\HostApp\\HostAppDoc.h');
        AddUnitTestFile (group, strThird + '\\cppunit\\HostApp\\HostAppView.cpp');
        group.AddFile (strThird + '\\cppunit\\HostApp\\HostAppView.h');
        AddUnitTestFile (group, strThird + '\\cppunit\\HostApp\\MainFrm.cpp');
        group.AddFile (strThird + '\\cppunit\\HostApp\\MainFrm.h');
        group.AddFile (strThird + '\\cppunit\\HostApp\\Resource.h');
        file = AddUnitTestFile (group, strThird + '\\cppunit\\HostApp\\StdAfx.cpp');
        tool = file.FileConfigurations.Item("Debug|Win32").Tool;
        tool.UsePrecompiledHeader = pchOption.pchCreateUsingSpecific;
        tool = file.FileConfigurations.Item("Release|Win32").Tool;
        tool.UsePrecompiledHeader = pchOption.pchCreateUsingSpecific;
        group.AddFile (strThird + '\\cppunit\\HostApp\\StdAfx.h');
        file = AddUnitTestFile (group, strThird + '\\cppunit\\HostApp\\TestMain.cpp');

        strName = 'Pch.cpp';
        strTemplate = strTemplatePath + '\\' + strName;
        strFile = strProjectPath + '\\Src\\UnitTest\\' + strName;
        wizard.RenderTemplate (strTemplate, strFile, false);
        file = group.AddFile (strFile);
        tool = file.FileConfigurations.Item("Debug|Win32").Tool;
        tool.UsePrecompiledHeader = pchOption.pchCreateUsingSpecific;
        tool.PrecompiledHeaderFile = '$(IntDir)/$(TargetName).pch';
        tool.PrecompiledHeaderThrough = 'Pch.h'
        tool = file.FileConfigurations.Item("Release|Win32").Tool;
        tool.UsePrecompiledHeader = pchOption.pchCreateUsingSpecific;
        tool.PrecompiledHeaderFile = '$(IntDir)/$(TargetName).pch';
        tool.PrecompiledHeaderThrough = 'Pch.h'

        strName = 'Pch.h';
        strTemplate = strTemplatePath + '\\' + strName;
        strFile = strProjectPath + '\\Src\\UnitTest\\' + strName;
        wizard.RenderTemplate (strTemplate, strFile, false);
        file = group.AddFile (strFile);

        strName = 'providers.xml';
        strTemplate = strTemplatePath + '\\' + strName;
        strFile = strProjectPath + '\\Src\\UnitTest\\' + strName;
        wizard.RenderTemplate (strTemplate, strFile, false);

        group = proj.Object.AddFilter ('Resource Files')
        file = group.AddFile (strThird + '\\cppunit\\HostApp\\HostApp.rc');

        prototool = proj.Object.Configurations.Item(1).Tools ("VCCustomBuildTool");
        group = proj.Object.AddFilter ('Symbolic Targets')
        
        // copy FDO files
        file = group.AddFile ('CopyFdo');
        file.FileConfigurations.Item("Debug|Win32").Tool = prototool;
        tool = file.FileConfigurations.Item("Debug|Win32").Tool;
        tool.CommandLine =
            'copy $(FDO)\\Unmanaged\\Bin\\Win32\\Debug\\FDO.dll $(OutDir)\n' +
            'copy $(FDO)\\Unmanaged\\Bin\\Win32\\Debug\\FDOCommon.dll $(OutDir)\n' +
            'copy $(FDO)\\Unmanaged\\Bin\\Win32\\Debug\\FDOGeometry.dll $(OutDir)\n' +
            'echo "delete me please">$(OutDir)\\CopyFdo.ilk';
        tool.Description = 'Copying FDO files';
        tool.Outputs = '$(OutDir)\\CopyFdo.ilk';
        tool.AdditionalDependencies = '$(FDO)\\Unmanaged\\Bin\\Win32\\Debug\\FDO.dll;$(FDO)\\Unmanaged\\Bin\\Win32\\Debug\\FDOCommon.dll;$(FDO)\\Unmanaged\\Bin\\Win32\\Debug\\FDOGeometry.dll';
        tool2 = file.FileConfigurations.Item("Release|Win32").Tool;
        tool2.CommandLine = 
            'copy $(FDO)\\Unmanaged\\Bin\\Win32\\Release\\FDO.dll $(OutDir)\n' +
            'copy $(FDO)\\Unmanaged\\Bin\\Win32\\Release\\FDOCommon.dll $(OutDir)\n' +
            'copy $(FDO)\\Unmanaged\\Bin\\Win32\\Release\\FDOGeometry.dll $(OutDir)\n' +
            'echo "delete me please">$(OutDir)\\CopyFdo.ilk';
        tool2.Description = tool.Description;
        tool2.Outputs = tool.Outputs;
        tool2.AdditionalDependencies = '$(FDO)\\Unmanaged\\Bin\\Win32\\Release\\FDO.dll;$(FDO)\\Unmanaged\\Bin\\Win32\\Release\\FDOCommon.dll;$(FDO)\\Unmanaged\\Bin\\Win32\\Release\\FDOGeometry.dll';

        // copy thirdparty files
        file = group.AddFile ('CopyThirdparty');
        file.FileConfigurations.Item("Debug|Win32").Tool = prototool;
        tool = file.FileConfigurations.Item("Debug|Win32").Tool;
        tool.CommandLine =
            'copy $(FDOTHIRDPARTY)\\cppunit\\lib\\testrunnerd.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\cppunit\\lib\\cppunitd_dll.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Debug\\Xalan-C_1_7_0D.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Debug\\XalanMessages_1_7_0D.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\apache\\xml-xerces\\c\\Build\\Win32\\VC8\\Debug\\xerces-c_2_5_0D.dll $(OutDir)\n' +
            'echo "delete me please">$(OutDir)\\CopyThirdparty.ilk';
        tool.Description = 'Copying thirdparty dlls';
        tool.Outputs = '$(OutDir)\\CopyThirdparty.ilk';
        tool.AdditionalDependencies = '$(FDOTHIRDPARTY)\\cppunit\\lib\\testrunnerd.dll;$(FDOTHIRDPARTY)\\cppunit\\lib\\cppunitd_dll.dll;$(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Debug\\Xalan-C_1_7_0D.dll;$(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Debug\\XalanMessages_1_7_0D.dll;$(FDOTHIRDPARTY)\\apache\\xml-xerces\\c\\Build\\Win32\\VC8\\Debug\\xerces-c_2_5_0D.dll';
        tool2 = file.FileConfigurations.Item("Release|Win32").Tool;
        tool2.CommandLine =
            'copy $(FDOTHIRDPARTY)\\cppunit\\lib\\testrunner.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\cppunit\\lib\\cppunit_dll.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Release\\Xalan-C_1_7_0.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Release\\XalanMessages_1_7_0.dll $(OutDir)\n' +
            'copy $(FDOTHIRDPARTY)\\apache\\xml-xerces\\c\\Build\\Win32\\VC8\\Release\\xerces-c_2_5_0.dll $(OutDir)\n' +
            'echo "delete me please">$(OutDir)\\CopyThirdparty.ilk';
        tool2.Description = tool.Description;
        tool2.Outputs = tool.Outputs;
        tool2.AdditionalDependencies = '$(FDOTHIRDPARTY)\\cppunit\\lib\\testrunnerd.dll;$(FDOTHIRDPARTY)\\cppunit\\lib\\cppunitd_dll.dll;$(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Release\\Xalan-C_1_7_0.dll;$(FDOTHIRDPARTY)\\apache\\xml-xalan\\c\\Build\\Win32\\VC8\\Release\\XalanMessages_1_7_0.dll;$(FDOTHIRDPARTY)\\apache\\xml-xerces\\c\\Build\\Win32\\VC8\\Release\\xerces-c_2_5_0.dll';

        // fake install
        file = group.AddFile ('FakeInstall');
        file.FileConfigurations.Item("Debug|Win32").Tool = prototool;
        tool = file.FileConfigurations.Item("Debug|Win32").Tool;
        tool.CommandLine = 'copy providers.xml $(OutDir)';
        tool.Description = 'Performing fake install';
        tool.Outputs = '$(OutDir)\\providers.xml';
        tool2 = file.FileConfigurations.Item("Release|Win32").Tool;
        tool2.CommandLine = 'copy providers.xml $(OutDir)';
        tool2.Description = tool.Description;
        tool2.Outputs = tool.Outputs;
    }
    catch(e)
    {
        throw e;
    }
}
