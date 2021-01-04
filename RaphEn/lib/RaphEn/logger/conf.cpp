// Copyright 2021 Raphael Hungria
#include <fstream>
#include <cstdint>
#include <sstream>

#include "repch.h"

#include "RaphEn/logger/conf.h"

namespace raphen::logger {
// Conf definitions

Conf::Conf(const char* logger_name, Priority minimum_priority)
    :   m_logger_name(logger_name),
        m_min_prio(minimum_priority),
        m_ofstream(std::ofstream()) {}

bool Conf::SetUp() {
    m_ofstream.open(m_logger_name + ".log", std::ios::out | std::ios::trunc);

    return m_ofstream.is_open();
}

bool Conf::CleanUp() {
    if (m_ofstream.is_open()) {
        m_ofstream.close();
    }

    return !m_ofstream.is_open();
}

bool Conf::AcceptPriority(const Priority& prio) const {
    return (int)prio >= (int)m_min_prio;
}

}  // namespace raphen::logger
