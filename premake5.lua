workspace "Tomato"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (Solution directory)
IncludeDir={}
IncludeDir["GLFW"]="Tomato/vendor/GLFW/include"

include "Tomato/vendor/GLFW"


project "Tomato"
	location "Tomato"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tmtpch.h"
	pchsource "Tomato/src/tmtpch.cpp"
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"TMT_PLATFORM_WINDOWS",
			"TMT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TMT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TMT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TMT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Tomato/vendor/spdlog/include",
		"Tomato/src"
	}

	links
	{
		"Tomato"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"TMT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TMT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TMT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TMT_DIST"
		optimize "On"