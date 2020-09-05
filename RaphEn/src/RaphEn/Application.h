#pragma once
#include "RaphEn/Core/Core.h"

namespace raphen {

	class RE_API Application
	{
	public:
		virtual ~Application(void);
		
		void run(void);
	};

	//to be defined in Client application (see entry point)
	Application* CreateApplication(void);
}

