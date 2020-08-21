#include "Log.h"
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <ctime>

namespace raphen {
	namespace debug {

		std::stringstream* getFormatedLocalTime() {
			time_t now = time(0);
			tm* ltm = localtime(&now);

			std::stringstream* ss = new std::stringstream;

			*ss << "["
				<< ltm->tm_year + 1900 << "-" << ltm->tm_mon + 1 << "-" << ltm->tm_mday << " " <<
				ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec <<
				"]";

			return ss;
		}

		void RE_API Log(const std::string& msg, const channels& channel) {
			
			time_t now = time(0);
			tm* ltm = localtime(&now);
			
			std::stringstream* s = getFormatedLocalTime();
			*s << " <" << (int)channel << ">" << kChannels[(int)channel];
			*s << "| " << msg << std::endl;
			
			std::cout << s->str();

			delete s;
		}
	}	
}