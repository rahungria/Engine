
#pragma once

#include "general/core.h"
#include "general/profiler_core.h"


#ifdef RE_PLATFORM_WINDOWS

	// Expect definition in application (instead of defining main)
	extern raphen::Application* raphen::CreateApplication(void);

	int main(int argc, char** argv) {
		RE_PROFILE_BEGIN_SESSION("Startup", "Profile-Startup.json");
		raphen::Application* app = raphen::CreateApplication();
		RE_PROFILE_END_SESSION();

		// TODO(rapha): profile in more depth when possible
		RE_PROFILE_BEGIN_SESSION("App_Loop", "Profile-AppLoop.json");
		app->Run();
		RE_PROFILE_END_SESSION();

		delete app;

		return 0;
	}
#endif  // RE_PLATFORM_WINDOWS
