
#include <cstdint>

#include "repch.h"

#include "profiler//profiler_timer.h"
#include "profiler/profiler.h"

namespace raphen::debug {
ProfilerTimer::ProfilerTimer(const char* name) :
	_name(name),
	_stopped(false) {
	_start_timepoint = std::chrono::high_resolution_clock::now();
}

ProfilerTimer::~ProfilerTimer() {
	if (!_stopped)
		Stop();
}

void ProfilerTimer::Stop() {
	auto endpoint = std::chrono::high_resolution_clock::now();

	int64_t start = std::chrono::time_point_cast<std::chrono::microseconds>
		(_start_timepoint).time_since_epoch().count();
	int64_t end = std::chrono::time_point_cast<std::chrono::microseconds>
		(endpoint).time_since_epoch().count();

	uint32_t thread_id = (uint32_t)std::hash<std::thread::id>{}
		(std::this_thread::get_id());
	Profiler::Get().WriteProfile({ _name, start, end, thread_id });

	_stopped = true;
}
}  // namespace raphen::debug
