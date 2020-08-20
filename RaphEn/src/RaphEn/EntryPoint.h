#pragma once
#ifdef RE_PLATFORM_WINDOWS
	
	#include "Application.h"
	extern raphen::Application* raphen::CreateApplication(void);
			
	int main(int argc, char** argv) {
		raphen::Application* app = raphen::CreateApplication();
		app->run();

		delete app;
	}

#endif //RE_PLATFORM_WINDOWS