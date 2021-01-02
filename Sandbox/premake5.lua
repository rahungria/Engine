project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("../bin/" .. out_dir ..  "/%{prj.name}")
    objdir ("../bin-int/" .. out_dir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src",
        "../RaphEn/src"
    }

    links {
        "RaphEn-Core"
    }

    filter "system:windows"

    systemversion "latest"

    defines {
        "RE_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug" 
        defines "RE_DEBUG"
        symbols "On"

    filter "configurations:Release" 
        defines "RE_RELEASE"
        optimize "On"

    filter "configurations:Dist" 
        defines "RE_DIST"
        optimize "On"