// Copyright 2019-2020 Raphael Hungria
#pragma once

namespace raphen::events {
// enum to differenciate and id different event types
enum class EventType {
    None = 0,
    // focus, lost focus and moved NOT IMPLEMENTED
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyDown, KeyUp,
    MouseButtonDown, MouseButtonUp, MouseMoved, MouseScrolled
};

// bit flag for event category
enum EventCategory {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryWindow = BIT(1),
    EventCategoryInput = BIT(2),
    EventCategoryKeyboard = BIT(3),
    EventCategoryMouse = BIT(4),
    EventCategoryMouseButton = BIT(5)
};
}  // namespace raphen::events
