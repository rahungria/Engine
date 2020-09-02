#pragma once
#include "RaphEn/Profiler/Profiler.h"
#include "RaphEn/Profiler/ProfilerTimer.h"

#define PROFILING 1

#if PROFILING
	#define RE_PROFILE_BEGIN_SESSION(name, filepath) ::raphen::Profiler::Get().BeginSession(name, filepath)
	#define RE_PROFILE_END_SESSION() ::raphen::Profiler::Get().EndSession()
	#define PROFILE_SCOPE(name) ProfilerTimer timer##__LINE__(name)
	#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
	#define RE_PROFILE_BEGIN_SESSION(name, filepath)
	#define RE_PROFILE_END_SESSION()
	#define PROFILE_SCOPE(name)  
	#define PROFILE_FUNCTION()  

#endif