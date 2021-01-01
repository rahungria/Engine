// Copyright 2019-2020 Raphael Hungria
#include <string>

#include "repch.h"

#include "RaphEn/Events/MouseEvent.h"
#include "RaphEn/Events/EventType.h"

namespace raphen::events {
// --------------- MOUSE EVENT -----------------------

MouseEvent::MouseEvent(double x, double y)
    : m_mouse_x(x), m_mouse_y(y) {}

inline double MouseEvent::GetX() const { return m_mouse_x; }
inline double MouseEvent::GetY() const { return m_mouse_y; }

unsigned int MouseEvent::GetCategoryFlags() const {
    return EventCategoryMouse | EventCategoryInput;
}

std::string MouseEvent::ToString() const {
    std::stringstream ss;
    ss << "MouseEvent: (" << m_mouse_x << "," << m_mouse_y << ")";
    return ss.str();
}

// --------------- MOUSE MOVED EVENT -----------------------

MouseMovedEvent::MouseMovedEvent(double x, double y) :
    MouseEvent(x, y) {}

EventType MouseMovedEvent::GetStaticType() { return EventType::MouseMoved; }
EventType MouseMovedEvent::GetEventType() const { return GetStaticType(); }
const char* MouseMovedEvent::GetName() const { return "MouseMovedEvent"; }

// --------------- MOUSE SCROLLED EVENT -----------------------

MouseScrolledEvent::MouseScrolledEvent
    (double x, double y, double _x_offset, double _y_offset)
    : MouseEvent(x, y), m_x_offset(_x_offset), m_y_offset(_y_offset) {}

inline double MouseScrolledEvent::GetXOffset() const { return m_x_offset; }
inline double MouseScrolledEvent::GetYOffset() const { return m_y_offset; }

EventType MouseScrolledEvent::GetStaticType() {
    return EventType::MouseScrolled;
}
EventType MouseScrolledEvent::GetEventType() const { return GetStaticType(); }
const char* MouseScrolledEvent::GetName() const { return "MouseMovedEvent"; }

std::string MouseScrolledEvent::ToString() const {
    std::stringstream ss;
    ss  << "MouseScrolledEvent: offset (" << m_x_offset << "," << m_y_offset
        << ")";
    return ss.str();
}

// --------------- MOUSE BUTTON EVENT -----------------------

MouseButtonEvent::MouseButtonEvent(double x, double y, unsigned int button) :
    MouseEvent(x, y), m_mouse_button(button) {}

inline unsigned int MouseButtonEvent::GetMouseButton() const {
    return m_mouse_button;
}

unsigned int MouseButtonEvent::GetCategoryFlags() const {
    return EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton;
}

// --------------- MOUSE BUTTON DOWN EVENT -----------------------

MouseButtonDownEvent::MouseButtonDownEvent(
    double x, double y, unsigned int button)
    : MouseButtonEvent(x, y, button) {}

EventType MouseButtonDownEvent::GetStaticType() {
    return EventType::MouseButtonDown;
}
EventType MouseButtonDownEvent::GetEventType() const {
    return GetStaticType();
}
const char* MouseButtonDownEvent::GetName() const {
    return "MouseButtonDownEvent";
}

std::string MouseButtonDownEvent::ToString() const {
    std::stringstream ss;
    ss  << "MouseButtonDownEvent: (" << m_mouse_x << "," << m_mouse_y
        << "), button: " << m_mouse_button;
    return ss.str();
}

// --------------- MOUSE BUTTON UP EVENT -----------------------

MouseButtonUpEvent::MouseButtonUpEvent(double x, double y, unsigned int button)
    : MouseButtonEvent(x, y, button) {}

EventType MouseButtonUpEvent::GetStaticType() {
    return EventType::MouseButtonUp;
}
EventType MouseButtonUpEvent::GetEventType() const { return GetStaticType(); }
const char* MouseButtonUpEvent::GetName() const { return "MouseButtonUpEvent"; }

std::string MouseButtonUpEvent::ToString() const {
    std::stringstream ss;
    ss  << "MouseButtonUpEvent: (" << m_mouse_x << "," << m_mouse_y
        << "), button: " << m_mouse_button;
    return ss.str();
}
}  // namespace raphen::events
