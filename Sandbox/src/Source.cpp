
#include "raphen.h"

class Sandbox : public raphen::Application {
 public:
	Sandbox(void) {}
	~Sandbox(void) {}
};


raphen::Application* raphen::CreateApplication() {
	// raphen::events::WindowResizeEvent evnt(400, 500);
	// raphen::logger::Log("debug log", raphen::logger::channels::RENDERING);
	return new Sandbox;
}
