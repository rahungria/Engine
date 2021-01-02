project "RETests"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("../bin/" .. out_dir ..  "/%{prj.name}")
    objdir ("../bin-int/" .. out_dir .. "/%{prj.name}")

    files {
        "tests/**.h",
        "tests/**.cpp"
    }

    includedirs {
        "tests",
        "../RaphEn/src"
    }

    libdirs {
        "../bin/" .. out_dir .. "/RaphEn-Core"
    }

    filter "system:windows"

    -- buildoptions {
    --     "//DYNAMICBASE RaphEn-Core.lib"
    -- }

    systemversion "latest"

    defines {
        "RE_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug" 
        defines "RE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release" 
        defines "RE_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist" 
        defines "RE_DIST"
        runtime "Release"
        optimize "On"
