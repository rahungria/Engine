#include "RaphEn/Profiler/Profiler.h"
#include "RaphEn/Log.h"
#include "ProfileResult.h"
#include <algorithm>
#include <mutex>

namespace raphen {

    void Profiler::BeginSession(const std::string& name, const std::string& filepath)
    {
        raphen::debug::Log("Begining profile session", raphen::debug::channels::CORE);
        m_output_stream.open(filepath);
        Profiler::WriteHeader();
        m_current_session = name;
    }
    void Profiler::EndSession()
    {
        raphen::debug::Log("Ending profile session");
        WriteFooter();
        m_output_stream.close();
        m_profile_count = 0;
    }

    void Profiler::WriteHeader()
    {
        m_output_stream << "{\"otherData\": {},\"traceEvents\":[";
        m_output_stream.flush();
    }

    void Profiler::WriteFooter()
    {
        m_output_stream << "]}";
        m_output_stream.flush();
    }

    void Profiler::WriteProfile(const ProfileResult& result)
    {
        std::lock_guard<std::mutex> lock(write_guard);
        if (m_profile_count++ > 0)
            m_output_stream << ",";

        std::string name = result.name;
        std::replace(name.begin(), name.end(), '"', '\'');

        m_output_stream << "{";
        m_output_stream << "\"cat\":\"function\",";
        m_output_stream << "\"dur\":" << (result.end - result.start) << ',';
        m_output_stream << "\"name\":\"" << name << "\",";
        m_output_stream << "\"ph\":\"X\",";
        m_output_stream << "\"pid\":0,";
        m_output_stream << "\"tid\":" << result.thread_id << ",";
        m_output_stream << "\"ts\":" << result.start;
        m_output_stream << "}";

        m_output_stream.flush();
    }
}