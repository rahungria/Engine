#pragma once

#include "RaphEn/Core/Core.h"
#include "RaphEn/Events/EventType.h"
#include "RaphEn/Events/Event.h"
#include <string>


namespace raphen::events
{

	class RE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent();

		std::string ToString() const override;

		static EventType GetStaticType();
		virtual EventType GetEventType() const override;
		virtual const char* GetName() const override;

		virtual unsigned int GetCategoryFlags() const override;
	};

	class RE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent();

		std::string ToString() const override;

		static EventType GetStaticType();
		virtual EventType GetEventType() const override;
		virtual const char* GetName() const override;

		virtual unsigned int GetCategoryFlags() const override;
	};

	class RE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent();

		std::string ToString() const override;

		static EventType GetStaticType();
		virtual EventType GetEventType() const override;
		virtual const char* GetName() const override;

		virtual unsigned int GetCategoryFlags() const override;
	};
}