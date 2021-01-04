// Copyright 2019-2020 Raphael Hungria
#pragma once
#include <string>

#include "RaphEn/general/core.h"


// TODO(rapha): implement log levels (debug, info, warn, etc)
namespace raphen::logger {
enum class RE_API Channels {
    Core, Event, Test
};
enum class RE_API Priority {
    Debug, Info, Warn, Error, Fatal
};

const char* const k_channels[] = {
    "CORE", "EVENT", "RENDERING", "PHYSICS", "TESTS"
};

std::string getFormatedLocalTime();

// API ver of log function
void RE_API Log(const char* msg, const Channels& channel=Channels::Core);

// templated method for internal DLL logging purposes
// REQUIRES T TO IMPLEMENT << OPERATOR
// NOT THREAD SAFE (T&)
template<typename T>
void log_internal(const T&, const Channels& channel=Channels::Core);
}  // namespace raphen::logger
