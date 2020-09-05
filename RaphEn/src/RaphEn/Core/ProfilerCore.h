//Header with necessary includes and preprocessor macros for the use of profiling system
//Usage:	Define a Profiler Session Block by: Begin a Session ( RE_PROFILE_BEGIN_SESSION(name, filepath) ) before all the code to the outputed 
//			to the same json profile file and end it ( RE_PROFILE_END_SESSION() ) after all the execution.
//
//			There CANNOT be overlapping Profiling Sessions and inside each function to be profiled inside the session block
//
//			Each individual function to be profiled inside a profiler block should have a PROFILE_FUNCTION() definition for full function signature name
//			or a PROFILE_SCOPE(name) to profile a single scope with a custom name 
#pragma once
#include "RaphEn/Profiler/Profiler.h"
#include "RaphEn/Profiler/ProfilerTimer.h"

//#define PROFILING 1

#if HZ_DEBUG
	#define RE_PROFILE_BEGIN_SESSION(name, filepath) ::raphen::debug::Profiler::Get().BeginSession(name, filepath)
	#define RE_PROFILE_END_SESSION() ::raphen::debug::Profiler::Get().EndSession()
	#define PROFILE_SCOPE(name) ::raphen::debug::ProfilerTimer timer##__LINE__(name)
	#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
	#define RE_PROFILE_BEGIN_SESSION(name, filepath)
	#define RE_PROFILE_END_SESSION()
	#define PROFILE_SCOPE(name)  
	#define PROFILE_FUNCTION()  
#endif