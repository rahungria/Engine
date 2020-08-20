#pragma once
#include "Core.h"

namespace raphen {

	class RE_API Application
	{
	public:
		virtual ~Application(void);
		
		void run(void);
	};

	//to be defined in Client application
	Application* CreateApplication(void);
}

