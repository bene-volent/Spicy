workspace "Spicy"
    architecture "x64"
    startproject "Sandbox"
    configurations
     { 
        "Debug", 
        "Release",
        "Dist" 
    } 

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Spicy/vendor/GLFW/include"
IncludeDir["Glad"] = "Spicy/vendor/Glad/include"
include "Spicy/vendor/GLFW"
include "Spicy/vendor/Glad"

project "Spicy"
    location "Spicy"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir    ("bin-int/"..outputdir.."/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    pchheader "spc_pch.h"
    pchsource "Spicy/src/spc_pch.cpp"

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SPC_PLATFORM_WINDOWS",
            "SPC_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath}  ../bin/" ..outputdir.. "/Sandbox")
        }
    

    filter "configurations:Debug"
        defines {"SPC_DEBUG","SPC_ENABLE_ASSERTS"}
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "SPC_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SPC_DIST"
        buildoptions "/MD"
        optimize "On"
            
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir    ("bin-int/"..outputdir.."/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Spicy/vendor/spdlog/include",
        "Spicy/src"
    }

    links
    {
        "Spicy"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SPC_PLATFORM_WINDOWS",
        }


    filter "configurations:Debug"
        defines "SPC_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "SPC_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SPC_DIST"
        buildoptions "/MD"
        optimize "On"