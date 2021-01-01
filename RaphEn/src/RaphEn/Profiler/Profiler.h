// Copyright 2019-2020 Raphael Hungria
#pragma once

#include <string>
#include <fstream>
#include <mutex> //NOLINT (build/c++11)

#include "RaphEn/Profiler/ProfileResult.h"
#include "RaphEn/Profiler/ProfilerTimer.h"
#include "RaphEn/Core/Core.h"

namespace raphen::debug {
// Profiler Singleton accessed only through the macros at ProfilerCore.h
class Profiler {
 private:
    std::string m_current_session;
    uint32_t m_profile_count;
    std::ofstream m_output_stream;
    std::mutex write_guard;

    Profiler()
        : m_current_session(std::string()), m_profile_count(0) {}

    // Helper Function to write the json header
    void WriteHeader();
    // Helper Function to write the json footer
    void WriteFooter();

    friend class ProfilerTimer;
 public:
    // CALLED PRIVATELY ONLY / thread safe
    //  Writes the result of a ProfilerTimer instances in any scope as long
    // as there is an ongoin session
    void WriteProfile(const ProfileResult& result);

    // Open profile file stream and prepare json
    RE_API void BeginSession
    (const std::string& name, const std::string& filepath = "profile.json");

    // Close opened file stream and clean up json
    RE_API void EndSession();

    RE_API inline static Profiler& Get() {
        static Profiler instance;
        return instance;
    }
};
}  // namespace raphen::debug
