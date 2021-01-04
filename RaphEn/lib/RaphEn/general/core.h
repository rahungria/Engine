// Copyright 2019-2020 Raphael Hungria
// Author: username
#pragma once

#ifdef RE_PLATFORM_WINDOWS
    #ifdef RE_BUILD_DLL  // macros for linking dll functions
        #define RE_API __declspec(dllexport)
        // only export funcs for test if not on dist
        #ifndef RE_DIST
            #define RE_TEST_API __declspec(dllexport)
        #else
            #define RE_TEST_API
        #endif
    #else
    #define RE_API __declspec(dllimport)
    #ifdef RE_TEST
        #define RE_TEST_API __declspec(dllimport)
    #else
        #define RE_TEST_API
    #endif
    #endif
    #if defined(RE_TEST)
        #define RE_TEST_API __declspec(dllimport)
    #endif
#else
    #error RaphEn only supports Windows.
#endif  // RE_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
