#include "repch.h"

#include "RaphEn/Log.h"


namespace raphen {
	namespace debug {

		std::stringstream getFormatedLocalTime() {
			time_t now = time(0);

#			pragma warning (suppress : 4996)
			tm* ltm = localtime(&now);

			std::stringstream ss;

			ss << "["
				<< ltm->tm_year + 1900 << "-" << ltm->tm_mon + 1 << "-" << ltm->tm_mday << " " <<
				ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec <<
				"]";

			return ss;
		}

		void RE_API Log(const char* msg, const channels& channel)
		{	
			time_t now = time(0);

#			pragma warning (suppress : 4996)
			tm* ltm = localtime(&now);
			
			std::stringstream s = getFormatedLocalTime();
			s << " <" << (int)channel << ">" << k_channels[(int)channel];
			s << "| " << msg << std::endl;
			
			std::cout << s.str();
		}

		template<typename T>
		void log_internal(const T& msg, const channels& channel)
		{
			time_t now = time(0);

#			pragma warning (suppress : 4996)
			tm* ltm = localtime(&now);

			std::stringstream s = getFormatedLocalTime();
			s << " <" << (int)channel << ">" << k_channels[(int)channel];
			s << "| " << msg << std::endl;

			std::cout << s.str();
		}
	}	
}