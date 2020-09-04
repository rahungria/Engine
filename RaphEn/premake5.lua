project "RaphEn-Core"
    kind "SharedLib"
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
        "src"
    }

    filter "system:windows"

    systemversion "latest"

    defines {
        "RE_BUILD_DLL",
        "RE_PLATFORM_WINDOWS"
    }

    postbuildcommands {
        "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. out_dir .. "/Sandbox/"
    }
    postbuildmessage "Copying .dll dependencies"

    filter "configurations:Debug" 
        defines "HZ_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release" 
        defines "HZ_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist" 
        defines "HZ_DIST"
        runtime "Release"
        optimize "On"

    