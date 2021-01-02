// Copyright 2019-2020 Raphael Hungria
#pragma once
#include <string>

#include "RaphEn/general/core.h"


// TODO(rapha): implement log levels (debug, info, warn, etc)
namespace raphen::logger {
enum class RE_API channels {
    CORE = 0, EVENT=1, RENDERING = 2, PHYSICS = 3, TESTS=4
};

const char* const k_channels[] = {
    "CORE", "EVENT", "RENDERING", "PHYSICS", "TESTS"
};

std::string getFormatedLocalTime();

// API ver of log function
void RE_API Log(const char* msg, const channels& channel = channels::CORE);

// templated method for internal DLL logging purposes
// REQUIRES T TO IMPLEMENT << OPERATOR
// NOT THREAD SAFE (T&)
template<typename T>
void log_internal(const T&, const channels& channel = channels::CORE);
}  // namespace raphen::logger
