#pragma once

#include "RaphEn/Core/Core.h"
#include <chrono>
#include <string>
#include <thread>

namespace raphen::debug {

	//Class instantiated by debug macros
	//Counts the time since instantiation until it goes out of scope, accesses an ongoing profiler session and writes to it
	class ProfilerTimer
	{
	private:
		const std::string m_name;
		bool m_stopped;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timepoint;

	public:
		//Gets current time in constructor
		ProfilerTimer(const char* name);

		//Stops timer on deconstructor
		~ProfilerTimer();

		//Gets end time and duration, and outputs to running profiler session
		void Stop();
	};
}