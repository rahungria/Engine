#pragma once

#include "RaphEn/Core/Core.h"

namespace raphen::events {

	//enum to differenciate and id different event types
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, //focus, lost focus, moved NOT IMPLEMENTED
		AppTick, AppUpdate, AppRender,
		KeyDown, KeyUp,
		MouseButtonDown, MouseButtonUp, MouseMoved, MouseScrolled
	};

	//bit flag for event category
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication =	BIT(0),
		EventCategoryWindow =		BIT(1),
		EventCategoryInput =		BIT(2),
		EventCategoryKeyboard =		BIT(3),
		EventCategoryMouse =		BIT(4),
		EventCategoryMouseButton =	BIT(5)
	};
}

	//Macros to make writing child classes of events easier
#	define EVENT_CLASS_TYPE(type)			static EventType GetStaticType() { return EventType::##type; }\
											virtual EventType GetEventType() const override { return GetStaticType(); }\
											virtual const char* GetName() const override { return #type; }

#	define EVENT_CLASS_CATEGORY(category)	virtual int GetCategoryFlags() const override { return category; }