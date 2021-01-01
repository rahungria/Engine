// Copyright 2019-2020 Raphael Hungria
#include "repch.h"

#include "RaphEn/Application.h"
#include "RaphEn/Core/ProfilerCore.h"


namespace raphen {
void Application::run(void) {
    PROFILE_FUNCTION();
    // TODO(rapha): propper Logging
    std::cout << "Starting Engine Up..." << std::endl;
    std::cin.get();
}

Application::~Application(void) {}
}  // namespace raphen
