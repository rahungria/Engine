#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Core/ProfilerCore.h"

#ifdef RE_PLATFORM_WINDOWS

	//Expect definition in application (instead of defining main)
	extern raphen::Application* raphen::CreateApplication(void);

	struct test
	{
		int a, b;
		test(int a1, int b1) : a(a1), b(b1) {}
	};

	int main(int argc, char** argv) 
	{
		RE_PROFILE_BEGIN_SESSION("Startup", "Profile-Startup.json");
		raphen::Application* app = raphen::CreateApplication();
		RE_PROFILE_END_SESSION();

		RE_PROFILE_BEGIN_SESSION("App Loop", "Profile-AppLoop.json");
		app->run();
		RE_PROFILE_END_SESSION();
		
		delete app;

		return 0;
	}

#endif //RE_PLATFORM_WINDOWS