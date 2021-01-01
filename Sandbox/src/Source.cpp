// Copyright 2019-2020 Raphael Hungria
#include "Raphen.h"

class Sandbox : public raphen::Application {
 public:
    Sandbox(void) {}
    ~Sandbox(void) {}
};

// replaced by entry point header
// int main(void) {
//    Sandbox* sandbox = new Sandbox();
//    sandbox->run();
//
//    delete sandbox;
//}

raphen::Application* raphen::CreateApplication() {
    // raphen::events::WindowResizeEvent evnt(400, 500);
    raphen::debug::Log("debug log", raphen::debug::channels::RENDERING);
    return new Sandbox;
}
