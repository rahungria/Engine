
#include "repch.h"

#include "application.h"
#include "general/profiler_core.h"


namespace raphen {
void Application::Run(void) {
	PROFILE_FUNCTION();
	// TODO(rapha): propper Logging
	std::cout << "Starting Engine Up..." << std::endl;
	std::cin.get();
}

Application::~Application(void) {}
}  // namespace raphen
