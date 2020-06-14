workspace "Anubis-Engine"

	startproject "Sandbox"

	configurations 
	{ 
		"Debug", 
		"Release" 
	}
	
	architecture "x86_64"
	language "C++"
	cppdialect "C++14"
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

    filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
	
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Anubis-Engine"
	location "Anubis-Engine"
	kind "StaticLib"

	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/include/**.hpp",
		"%{prj.name}/include/**.inl"
	}
	
	includedirs
	{
		"Anubis-Engine/include",
		"vendor/glfw/include"
	}
	
	
project "Sandbox"
	location "%{prj.name}"
	kind "ConsoleApp"
	dependson { "Anubis-Engine" } 
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.inl"
	}
	
	includedirs
	{
		"Anubis-Engine/include",
		"vendor/glfw/include"
	}
	
	libdirs
	{
		"vendor/glfw/bin/%{cfg.architecture}/%{cfg.name}",
		("bin/" .. outputdir .. "/Anubis-Engine")
	}
	
	links
	{
		"glfw3",
		"Anubis-Engine"
	}
	
	