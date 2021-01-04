// Copyright 2021 Raphael Hungria
#pragma once
#include <fstream>
#include <string>

#include "RaphEn/general/core.h"
#include "RaphEn/logger/log.h"


namespace raphen::logger {
// TODO: add support for multiple formats

// Configuration class used to initialize a Logger
class RE_TEST_API Conf {
 public:
    // @param _ofstream: the stream to output the Logger messages
    // @param minimum_priority: the minimum priority that a logger should write
    explicit Conf(const char* logger_name, Priority minimum_priority);
    virtual ~Conf() {}

    virtual bool SetUp();
    virtual bool CleanUp();
    bool AcceptPriority(const Priority& prio) const;

    Conf(const Conf&) = delete;
    Conf(Conf&&) = delete;
    Conf& operator=(const Conf&) = delete;
    Conf& operator=(Conf&&) = delete;
 private:
    std::string m_logger_name;
    std::ofstream m_ofstream;
    const Priority m_min_prio;

    friend class Logger;
};
}  // namespace raphen::logger
