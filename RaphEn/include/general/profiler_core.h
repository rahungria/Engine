

// Header with necessary includes and preprocessor macros for the use of
// profiling system

// Usage:
// Begin a Session 'RE_PROFILE_BEGIN_SESSION(name, filepath)'
// End the Session 'RE_PROFILE_END_SESSION()'
// wrapping all the code to be profiled

// There CANNOT be overlapping Profiling Sessions and inside each function to be
// profiled inside the session block

// Each individual function to be profiled inside a profiler block should have
// a PROFILE_FUNCTION() definition for full function signature name
// or a PROFILE_SCOPE(name) to profile a single scope with a custom name
#pragma once
#include "profiler/profiler.h"
#include "profiler//profiler_timer.h"


#if RE_DEBUG
	#define RE_PROFILE_BEGIN_SESSION(name, filepath) \
		::raphen::debug::Profiler::Get().BeginSession(name, filepath)
	#define RE_PROFILE_END_SESSION() \
		::raphen::debug::Profiler::Get().EndSession()
	#define PROFILE_SCOPE(name) \
		::raphen::debug::ProfilerTimer timer##__LINE__(name)
	#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
	#define RE_PROFILE_BEGIN_SESSION(name, filepath)
	#define RE_PROFILE_END_SESSION()
	#define PROFILE_SCOPE(name)
	#define PROFILE_FUNCTION()
#endif
