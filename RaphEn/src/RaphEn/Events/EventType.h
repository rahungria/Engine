#pragma once

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
		EventCategoryApplication = BIT(0),
		EventCategoryWindow = BIT(1),
		EventCategoryInput = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryMouseButton = BIT(5)
	};
}