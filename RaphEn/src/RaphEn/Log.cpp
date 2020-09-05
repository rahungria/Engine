#include "RaphEn/Log.h"
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <ctime>

namespace raphen {
	namespace debug {

		std::stringstream* getFormatedLocalTime() {
			time_t now = time(0);

#			pragma warning (suppress : 4996)
			tm* ltm = localtime(&now);

			std::stringstream* ss = new std::stringstream;

			*ss << "["
				<< ltm->tm_year + 1900 << "-" << ltm->tm_mon + 1 << "-" << ltm->tm_mday << " " <<
				ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec <<
				"]";

			return ss;
		}

		template RE_API void Log<std::string>(const std::string&, const channels&);

		template<typename T>
		void RE_API Log(const T& msg, const channels& channel) {
			
			time_t now = time(0);

#			pragma warning (suppress : 4996)
			tm* ltm = localtime(&now);
			
			std::stringstream* s = getFormatedLocalTime();
			*s << " <" << (int)channel << ">" << kChannels[(int)channel];
			*s << "| " << msg << std::endl;
			
			std::cout << s->str();

			delete s;
		}
	}	
}