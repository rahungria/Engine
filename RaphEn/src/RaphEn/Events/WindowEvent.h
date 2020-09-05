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
		WindowResizeEvent(unsigned int height, unsigned int width);

		inline unsigned int GetHeight() const;
		inline unsigned int GetWidth() const;

		std::string ToString() const override;

		EVENT_CLASS_CATEGORY(EventCategoryWindow)
		EVENT_CLASS_TYPE(WindowResize)
	protected:
		unsigned int m_height, m_width;
	};

	class RE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent();

		std::string ToString() const override;

		EVENT_CLASS_CATEGORY(EventCategoryWindow)
		EVENT_CLASS_TYPE(WindowClose)
	};
}
