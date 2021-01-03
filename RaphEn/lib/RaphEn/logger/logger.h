// Copyright 2021 Raphael Hungria
#pragma once
#include <fstream>
#include "RaphEn/general/core.h"


namespace raphen::logger {

enum class Priority {
    DEBUG, INFO, WARN, ERROR, FATAL
};

int return2() {
    return 2;
}
}  // namespace raphen::logger
