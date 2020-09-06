#pragma once

#include "RaphEn/Core/Core.h"
#include <string>

namespace raphen {
	namespace debug {

		enum class RE_API channels {
			CORE = 0, RENDERING = 1, PHYSICS = 2
		};

		const char* const k_channels[] = { "CORE", "EVENT", "RENDERING", "PHYSICS" };

		std::stringstream getFormatedLocalTime();

		// API ver of log function
		void RE_API Log(const char* msg, const channels& channel = channels::CORE);

		// template for internal DLL logging purposes 
		// REQUIRES T TO IMPLEMENT << OPERATOR
		// NOT THREAD SAFE (T&)
		template<typename T>
		void log_internal(const T&, const channels& channel = channels::CORE);
	}
}