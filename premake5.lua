-- -- lua premake --
-- workspace "RaphEn"
-- 	architecture "x64"
-- 	startproject "Sandbox"

-- 	configurations {
-- 		"Debug",
-- 		"Release",
-- 		"Dist"
-- 	}
-- outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- project "RaphaEn" 
-- 	location "RaphEn"
-- 	kind "SharedLib"
-- 	language "C++"

-- 	targetdir ("bin\\" .. outputdir .. "\\%{prj.name}")
-- 	objdir ("bin-int\\" .. outputdir .. "\\%{prj.name}")

-- 	files {
-- 		".\\RaphEn\\src\\**.h",
-- 		".\\RaphEn\\src\\**.cpp"
-- 	}

-- 	includedirs {
-- 		".\\RaphEn\\src"
-- 	}

-- 	filter "system:windows"
-- 		cppdialect "C++17"
-- 		staticruntime "On"
-- 		systemversion "latest"

-- 		defines {
-- 			"RE_BUILD_DLL",
-- 			"RE_PLATFORM_WINDOWS"
-- 		}

-- 		postbuildcommands {
-- 			("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox")
-- 		}

-- 		filter "configurations:Debug"
-- 			defines "RE_DEBUG"
-- 			symbols "On"

-- 		filter "configurations:Release"
-- 			defines "RE_RELEASE"
-- 			optimize "On"

-- 		filter "configurations:Dist" 
-- 			defines "RE_DIST"
-- 			optimize "On"

-- project "Sandbox" 
-- 	location "Sandbox"
-- 	kind "ConsoleApp"
-- 	language "C++"

-- 	targetdir ("bin\\" .. outputdir .. "\\%{prj.name}")
-- 	objdir ("bin-int\\" .. outputdir .. "\\%{prj.name}")

-- 	files {
-- 		".\\%{prj.name}\\src\\**.h",
-- 		".\\%{prj.name}\\src\\**.cpp"
-- 	}

-- 	includedirs {
-- 		".\\%{prj.name}\\src",
-- 		".\\RaphaEn\\src"
-- 	}

-- 	links {
-- 		"RaphaEn"
-- 	}

-- 	filter "system:windows"
-- 		cppdialect "C++17"
-- 		staticruntime "On"
-- 		systemversion "latest"

-- 		defines {
-- 			"RE_BUILD_DLL",
-- 			"RE_PLATFORM_WINDOWS"
-- 		}

-- 		-- postbuildcommands {
-- 		-- 	("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox")
-- 		-- }
-- 		postbuildcommands {
-- 			"{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox"
-- 		}

-- 		filter "configurations:Debug"
-- 			defines "RE_DEBUG"
-- 			symbols "On"

-- 		filter "configurations:Release"
-- 			defines "RE_RELEASE"
-- 			optimize "On"

-- 		filter "configurations:Dist"
-- 			defines "RE_DIST"
-- 			optimize "On"

workspace "RaphEn"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

out_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group ""

include ("RaphEn/premake5.lua")
include ("Sandbox/premake5.lua")