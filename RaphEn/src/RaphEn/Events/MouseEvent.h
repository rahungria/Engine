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

	//Holds just the coordinates of the movement
	class RE_API MouseMovedEvent : MouseEvent
	{
	public:
		MouseMovedEvent(double x, double y) :
			MouseEvent(x,y) {}

		EVENT_CLASS_TYPE(MouseMoved)
	};

	class RE_API MouseScrolledEvent : MouseEvent
	{
	public:
		MouseScrolledEvent(double x, double y, double _x_offset, double _y_offset)
			:MouseEvent(x,y) , x_offset(_x_offset), y_offset(_y_offset) {}

		inline double GetXOffset() { return x_offset; }
		inline double GetYOffset() { return y_offset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: offset (" << x_offset << "," << y_offset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)

	private:
		double x_offset, y_offset;
	};
}