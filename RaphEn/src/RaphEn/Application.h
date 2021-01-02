// Copyright 2019-2020 Raphael Hungria
#pragma once
#include "RaphEn/general/core.h"


namespace raphen {
class RE_API Application {
 public:
    virtual ~Application(void);

    void run(void);
};

// To be defined in Client application (project), see entry point
Application* CreateApplication(void);
}  // namespace raphen
