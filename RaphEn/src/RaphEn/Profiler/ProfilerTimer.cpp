#include "RaphEn/Profiler/ProfilerTimer.h"
#include "RaphEn/Profiler/Profiler.h"

namespace raphen {
	namespace debug {

		ProfilerTimer::ProfilerTimer(const char* name) :
			m_name(name), 
			m_stopped(false)
		{
			m_start_timepoint = std::chrono::high_resolution_clock::now();
		}

		ProfilerTimer::~ProfilerTimer()
		{
			if (!m_stopped)
				Stop();
		}

		void ProfilerTimer::Stop()
		{
			auto endpoint = std::chrono::high_resolution_clock::now();

			long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_timepoint).time_since_epoch().count();
			long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endpoint).time_since_epoch().count();

			uint32_t thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
			Profiler::Get().WriteProfile({ m_name, start, end, thread_id });

			m_stopped = true;
		}
	}
}