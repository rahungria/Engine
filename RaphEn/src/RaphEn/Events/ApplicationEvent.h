#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Core/EventCore.h"
#include "RaphEn/Events/Event.h"
#include <string>


namespace raphen::events
{

	class RE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		std::string ToString() const override
		{
			return "AppTickEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};

	class RE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		std::string ToString() const override
		{
			return "AppUpdateEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class RE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		std::string ToString() const override
		{
			return "AppRenderEvent";
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};
}