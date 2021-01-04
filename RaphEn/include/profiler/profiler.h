
#pragma once

#include <string>
#include <fstream>
#include <mutex> 

#include "profiler/profile_result.h"
#include "profiler//profiler_timer.h"
#include "general/core.h"

namespace raphen::debug {
// Profiler Singleton accessed only through the macros at Profilercore.h
class Profiler {
 private:
	std::string _current_session;
	uint32_t _profile_count;
	std::ofstream _output_stream;
	std::mutex write_guard;

	Profiler() : _current_session(std::string()), _profile_count(0) {}

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
