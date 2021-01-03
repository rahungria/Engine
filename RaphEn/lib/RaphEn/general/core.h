// Copyright 2019-2020 Raphael Hungria
// Author: username
#pragma once

#ifdef RE_PLATFORM_WINDOWS
    #ifdef RE_BUILD_DLL  // macros for linking dll functions
        #define RE_API __declspec(dllexport)
    #else
        #define RE_API __declspec(dllimport)
    #endif  // RE_BUILD_DLL
#else
    #error RaphEn only supports Windows.
#endif  // RE_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
