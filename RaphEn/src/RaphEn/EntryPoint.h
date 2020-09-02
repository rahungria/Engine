#pragma once

#include "RaphEn/Core.h"
#include "RaphEn/Profiler/ProfilerCore.h"

#ifdef RE_PLATFORM_WINDOWS
	//#include "RaphEn/Application.h"
	//#include "RaphEn/Profiler/ProfilerCore.h"

	//Expect definition in application (instead of defining main)
	extern raphen::Application* raphen::CreateApplication(void);

	int main(int argc, char** argv) 
	{
		RE_PROFILE_BEGIN_SESSION("Startup", "Startup-Profile.json");
		raphen::Application* app = raphen::CreateApplication();
		RE_PROFILE_END_SESSION();

		RE_PROFILE_BEGIN_SESSION("App Loop", "App-Loop-Profile.json");
		app->run();
		RE_PROFILE_END_SESSION();
		
		delete app;

		return 0;
	}

#endif //RE_PLATFORM_WINDOWS