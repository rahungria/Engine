
#include "repch.h"

#include "profiler/profiler.h"
#include "logger/log.h"
#include "profiler/profile_result.h"

namespace raphen::debug {
	void Profiler::BeginSession
	(const std::string& name, const std::string& filepath) {
		// raphen::debug::Log<std::string>
		// ("Begining profile session", raphen::debug::channels::CORE);
		_output_stream.open(filepath);
		Profiler::WriteHeader();
		_current_session = name;
	}
	void Profiler::EndSession() {
		// raphen::debug::Log<std::string>("Ending profile session");
		WriteFooter();
		_output_stream.close();
		_profile_count = 0;
	}

	void Profiler::WriteHeader() {
		_output_stream << "{\"otherData\": {},\"traceEvents\":[";
		_output_stream.flush();
	}

	void Profiler::WriteFooter() {
		_output_stream << "]}";
		_output_stream.flush();
	}

	void Profiler::WriteProfile(const ProfileResult& result) {
		std::lock_guard<std::mutex> lock(write_guard);
		if (_profile_count++ > 0)
			_output_stream << ",";

		std::string name = result.name;
		std::replace(name.begin(), name.end(), '"', '\'');

		_output_stream 
			<< "{"
			<< R"("cat":"function",)"
			<< R"("dur":)" << (result.end - result.start) << ','
			<< R"("name":")" << name << R"(",)"
			<< R"("ph":"X",)"
			<< R"("pid":0,)"
			<< R"("tid":)" << result.thread_id << ","
			<< R"("ts":)" << result.start
			<< R"(})";

		_output_stream.flush();
	}
}  // namespace raphen::debug
