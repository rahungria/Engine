
#pragma once
#include <fstream>
#include <string>

#include "general/core.h"
#include "logger/log.h"


namespace raphen::logger {
// TODO: add support for multiple formats
// TODO: create abstract interface for Conf

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
	std::string _logger_name;
	std::ofstream _ofstream;
	const Priority _min_prio;

	friend class Logger;
};
}  // namespace raphen::logger
