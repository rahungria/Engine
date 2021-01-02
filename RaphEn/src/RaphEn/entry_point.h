// Copyright 2019-2020 Raphael Hungria
#pragma once

#include "RaphEn/general/core.h"
#include "RaphEn/general/profiler_core.h"


#ifdef RE_PLATFORM_WINDOWS

    // Expect definition in application (instead of defining main)
    extern raphen::Application* raphen::CreateApplication(void);

    int main(int argc, char** argv) {
        RE_PROFILE_BEGIN_SESSION("Startup", "Profile-Startup.json");
        raphen::Application* app = raphen::CreateApplication();
        RE_PROFILE_END_SESSION();

        // TODO(rapha): profile in more depth when possible
        RE_PROFILE_BEGIN_SESSION("App Loop", "Profile-AppLoop.json");
        app->run();
        RE_PROFILE_END_SESSION();

        delete app;

        return 0;
    }
#endif  // RE_PLATFORM_WINDOWS
