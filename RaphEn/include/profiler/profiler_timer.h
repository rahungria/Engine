
#pragma once
#include <string>
#include <chrono> 

#include "repch.h"

#include "general/core.h"

namespace raphen::debug {
// Class instantiated by debug macros
// Counts the time since instantiation until it goes out of scope, accesses
// an ongoing profiler session and writes to it
class ProfilerTimer {
 private:
	const std::string _name;
	bool _stopped;
	std::chrono::time_point<std::chrono::high_resolution_clock>
		_start_timepoint;

 public:
	// Gets current time in constructor
	explicit ProfilerTimer(const char* name);

	// Stops timer on deconstructor
	~ProfilerTimer();

	// Gets end time and duration, and outputs to running profiler session
	void Stop();
};
}  // namespace raphen::debug
