#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Events/EventType.h"

namespace raphen::events 
{
	//Base Abstract class for every system event
	class RE_API Event
	{
		//friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual unsigned int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		//for logging
		inline std::ostream& operator << (std::ostream& os)
		{
			return os << this->ToString();
			return os;
		}

#		pragma warning(suppress : 26812)
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_handled = false;
	};
}