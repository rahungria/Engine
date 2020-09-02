#pragma once

#include <string>
#include <fstream>
#include <mutex>
#include "RaphEn/Profiler/ProfileResult.h"
#include "RaphEn/Core.h"

//template class RE_API std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
//template class RE_API std::basic_ofstream<char, std::char_traits<char>>;
//template class RE_API std::mutex;



namespace raphen {
	class Profiler
	{
	private:
		std::string m_current_session;
		uint32_t m_profile_count;
		std::ofstream m_output_stream;
		std::mutex write_guard;

		Profiler()
			: m_current_session(std::string()), m_profile_count(0) {}
		void WriteHeader();
		void WriteFooter();
	public:

		RE_API void BeginSession(const std::string& name, const std::string& filepath = "profile.json");
		RE_API void EndSession();
		void WriteProfile(const ProfileResult& result);
		RE_API inline static Profiler& Get()
		{
			static Profiler instance;
			return instance;
		}
	};
}