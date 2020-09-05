#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Core/EventCore.h"
#include "RaphEn/Events/Event.h"
#include <sstream>

namespace raphen::events
{
	// base class for any Mouse Events (mouse moved, click, scroll, etc)
	class MouseEvent : Event
	{
	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseEvent: (" << m_mouse_x << "," << m_mouse_y << ")";
			return ss.str();
		}

		inline double GetX() { return m_mouse_x; }
		inline double GetY() { return m_mouse_y; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseEvent (double x, double y)
			: m_mouse_x(x) , m_mouse_y (y) {}
	private:
		double m_mouse_x, m_mouse_y;
	};

	class RE_API MouseMovedEvent : MouseEvent
	{

	};
}