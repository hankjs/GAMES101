workspace "GAMES101"
	architecture "x64"
	startproject "Main"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = ""

IncludeDir = {}

project "Eigen"
	location "Eigen"

project "Hw0"
	location "Hw0"

project "*"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetname ("Main")
	targetdir ("%{wks.location}/%{prj.name}/bin/" .. outputdir)
	objdir    ("%{wks.location}/%{prj.name}/bin-int/" .. outputdir)

	files {
		"%{wks.location}/%{prj.name}/src/**.h",
		"%{wks.location}/%{prj.name}/src/**.cpp",
	}

	defines {
		"_WIN32"
	}

	includedirs {
		"%{wks.location}/%{prj.name}/src",
		"%{wks.location}/vendor"
	}

	links { 
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"

		
