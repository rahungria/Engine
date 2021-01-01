// Copyright 2019-2020 Raphael Hungria
#include <sstream>

#include "repch.h"

#include "RaphEn/Log.h"


namespace raphen::debug {
// TODO(rapha): TEST THE NEW SAFE LOCALTIME
std::stringstream getFormatedLocalTime() {
    time_t now = time(0);
    tm ltm;

    localtime_s(&ltm, &now);

    std::stringstream ss;
    ss << "["
        << ltm.tm_year + 1900 << "-" << ltm.tm_mon + 1 << "-" << ltm.tm_mday
        << " " << ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec <<
        "]";

    return ss;
}

void RE_API Log(const char* msg, const channels& channel) {
    time_t now = time(0);
    tm ltm;

    localtime_s(&ltm, &now);

    std::stringstream s = getFormatedLocalTime();
    s   << " <" << static_cast<int>(channel) << ">"
        << k_channels[static_cast<int>(channel)]
        << "| " << msg << std::endl;

    std::cout << s.str();
}

template<typename T>
void log_internal(const T& msg, const channels& channel) {
    time_t now = time(0);
    tm ltm;

    localtime_s(&ltm, &now);

    std::stringstream s = getFormatedLocalTime();
    s   << " <" << static_cast<int>(channel) << ">"
        << k_channels[static_cast<int>(channel)]
        << "| " << msg << std::endl;

    std::cout << s.str();
}
}  // namespace raphen::debug
