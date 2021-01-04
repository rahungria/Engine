// Copyright 2019-2020 Raphael Hungria
#include <string>
#include <chrono>
#include <iostream>

#include "repch.h"

#include "RaphEn/logger/log.h"


namespace raphen::logger {

constexpr int LOCALTIME_BUFFERSIZE = 23;
// TODO(rapha): TEST THE NEW SAFE LOCALTIME
std::string getFormatedLocalTime() {
    char buffer[LOCALTIME_BUFFERSIZE];
    auto now = std::chrono::system_clock::now();
    auto millis = static_cast<int>
        ((now.time_since_epoch().count() / 1000000) % 1000);

    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm localt;
    localtime_s(&localt, &tt);

    strftime(buffer, LOCALTIME_BUFFERSIZE, "%F %X", &localt);
    sprintf_s(buffer, "%s %03d", buffer, millis);

    return std::string(buffer);
}

void RE_API Log(const char* msg, const Channels& channel) {
    time_t now = time(0);
    tm ltm;

    localtime_s(&ltm, &now);

    std::string time = getFormatedLocalTime();
    std::stringstream ss;
    ss  << "<" << static_cast<int>(channel) << ">"
        << k_channels[static_cast<int>(channel)]
        << "| " << msg << std::endl;

    std::cout << time << " " << ss.str();
}

template<typename T>
void log_internal(const T& msg, const Channels& channel) {
    time_t now = time(0);
    tm ltm;

    localtime_s(&ltm, &now);

    std::stringstream s = getFormatedLocalTime();
    s   << " <" << static_cast<int>(channel) << ">"
        << k_channels[static_cast<int>(channel)]
        << "| " << msg << std::endl;

    std::cout << s.str();
}
}  // namespace raphen::logger
