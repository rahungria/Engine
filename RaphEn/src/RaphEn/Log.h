#pragma once

#include "RaphEn/Core.h"
#include <string>

namespace raphen {
	namespace debug {

		enum class RE_API channels {
			CORE = 0, RENDERING = 1, PHYSICS = 2
		};

		const char* const kChannels[] = { "CORE", "RENDERING", "PHYSICS" };

		std::stringstream* getFormatedLocalTime();
		void RE_API Log(const std::string& msg, const channels& channel = channels::CORE);
	}
}