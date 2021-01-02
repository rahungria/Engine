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