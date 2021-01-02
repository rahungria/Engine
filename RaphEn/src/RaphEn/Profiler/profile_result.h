// Copyright 2019-2020 Raphael Hungria
#pragma once

#include <string>
#include <cstdint>

#include "repch.h"

namespace raphen::debug {
// POD to hold the results of a profile run
struct ProfileResult {
    std::string name;
    int64_t start, end;
    uint32_t thread_id;
};
}  // namespace raphen::debug
