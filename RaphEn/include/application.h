
#pragma once
#include "general/core.h"


namespace raphen {
class RE_API Application {
 public:
	virtual ~Application(void);

	void Run(void);
};

// To be defined in Client application (project), see entry point
Application* CreateApplication(void);
}  // namespace raphen
