#include "repch.h"

#include "RaphEn/Application.h"
#include "RaphEn/Core/ProfilerCore.h"

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