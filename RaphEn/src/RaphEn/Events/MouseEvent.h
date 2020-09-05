#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Core/EventCore.h"
#include "RaphEn/Events/Event.h"
#include <sstream>

namespace raphen::events
{
	// base class for any Mouse Events (mouse moved, click, scroll, etc)
	class MouseEvent : public Event
	{
	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseEvent: (" << m_mouse_x << "," << m_mouse_y << ")";
			return ss.str();
		}

		inline double GetX() const { return m_mouse_x; }
		inline double GetY() const { return m_mouse_y; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseEvent (double x, double y)
			: m_mouse_x(x) , m_mouse_y (y) {}

		double m_mouse_x, m_mouse_y;
	};

	//Holds just the coordinates of the movement
	class RE_API MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(double x, double y) :
			MouseEvent(x,y) {}

		EVENT_CLASS_TYPE(MouseMoved)
	};


	class RE_API MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(double x, double y, double _x_offset, double _y_offset)
			:MouseEvent(x,y) , x_offset(_x_offset), y_offset(_y_offset) {}

		inline double GetXOffset() const { return x_offset; }
		inline double GetYOffset() const { return y_offset; }

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


	class RE_API MouseButtonEvent : public MouseEvent
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

		inline unsigned int GetMouseButton() const { return m_mouse_button; }

	protected:
		MouseButtonEvent (double x, double y, unsigned int button) :
			MouseEvent(x,y), m_mouse_button(button) {}

	protected:
		unsigned int m_mouse_button;
	};


	class RE_API MouseButtonDownEvent : public MouseButtonEvent
	{
	public:
		MouseButtonDownEvent(double x, double y, unsigned int button) :
			MouseButtonEvent(x,y,button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonDownEvent: (" << m_mouse_x << "," << m_mouse_y << "), button: " << m_mouse_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonDown)
	};

	class RE_API MouseButtonUpEvent : public MouseButtonEvent
	{
	public:
		MouseButtonUpEvent(double x, double y, unsigned int button) :
			MouseButtonEvent(x, y, button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonUpEvent: (" << m_mouse_x << "," << m_mouse_y << "), button: " << m_mouse_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonUp)
	};
}