#pragma once

#include <string>
namespace raphen {

	struct ProfileResult
	{
		std::string name;
		long long start, end;
		uint32_t thread_id;
	};
}