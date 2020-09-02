#include "RaphEn/Application.h"
#include <RaphEn/Profiler/ProfilerCore.h>
#include <iostream>

namespace raphen {

	void Application::run(void) {
		PROFILE_FUNCTION();
		std::cout << "Starting Engine Up..." << std::endl;
		//while (true);
		std::cin.get();
	}

	Application::~Application(void){

	}
}