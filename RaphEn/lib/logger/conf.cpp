
#include <fstream>
#include <cstdint>
#include <sstream>

#include "repch.h"

#include "logger/conf.h"

namespace raphen::logger {
// Conf definitions

Conf::Conf(const char* logger_name, Priority minimum_priority)
	:   _logger_name(logger_name),
		_min_prio(minimum_priority),
		_ofstream(std::ofstream()) {}

bool Conf::SetUp() {
	_ofstream.open(_logger_name + ".log", std::ios::out | std::ios::trunc);

	return _ofstream.is_open();
}

bool Conf::CleanUp() {
	if (_ofstream.is_open()) {
		_ofstream.close();
	}

	return !_ofstream.is_open();
}

bool Conf::AcceptPriority(const Priority& prio) const {
	return (int)prio >= (int)_min_prio;
}

}  // namespace raphen::logger
