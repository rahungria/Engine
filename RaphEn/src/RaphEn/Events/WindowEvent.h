#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Core/EventCore.h"
#include "RaphEn/Events/Event.h"
#include <sstream>

namespace raphen::events
{

	class RE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int height, unsigned int width) :
			m_height(height), m_width(width) {}

		inline unsigned int GetHeight() const { return m_height; }
		inline unsigned int GetWidth() const { return m_width; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: [h,w](" << m_height << "," << m_width << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryWindow)
		EVENT_CLASS_TYPE(WindowResize)
	protected:
		unsigned int m_height, m_width;
	};

	class RE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		std::string ToString() const override
		{
			return "WindowCloseEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryWindow)
		EVENT_CLASS_TYPE(WindowClose)
	};
}
