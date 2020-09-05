#pragma once

#include "RaphEn/Core.h"

namespace raphen::events {

	//enum to differenciate and id different event types
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyDown, KeyUp,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//bit flag for event category
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication =	BIT(0),
		EventCategoryInput =		BIT(1),
		EventCategoryKeyboard =		BIT(2),
		EventCategoryMouse =		BIT(3),
		EventCategoryMouseButton =	BIT(4)
	};
}

	//Macros to make writing child classes of events easier
#	define EVENT_CLASS_TYPE(type)			static EventType GetStaticType() { return EventType::##type; }\
											virtual EventType GetEventType() const override { return GetStaticType(); }\
											virtual const char* GetName() const override { return #type; }

#	define EVENT_CLASS_CATEGORY(category)	virtual int GetCategoryFlags() const override { return category; }