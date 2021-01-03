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
        "../RaphEn/lib"
    }

    libdirs {
        "../bin/" .. out_dir .. "/RaphEn"
    }

    filter "system:windows"

    linkoptions {
        "/DYNAMICBASE RaphEn.lib"
    }

    systemversion "latest"

    defines {
        "RE_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug"
        -- not 'RE_DEBUG' to not crash normally profiled functions
        defines "RE_TEST"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release" 
        defines "RE_RELEASE"
        runtime "Release"
        optimize "On"
    
    -- not supported in dist
    -- filter "configurations:Dist" 
    --     defines "RE_DIST"
    --     runtime "Release"
    --     optimize "On"
