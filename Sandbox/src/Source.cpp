#include "Raphen.h"

class Sandbox : public raphen::Application {
public:
	Sandbox(void){}
	~Sandbox(void){}

};

//replaced by entry point header
//int main(void) {
//	Sandbox* sandbox = new Sandbox();
//	sandbox->run();
//
//	delete sandbox;
//}

raphen::Application* raphen::CreateApplication() {
	return new Sandbox;
}