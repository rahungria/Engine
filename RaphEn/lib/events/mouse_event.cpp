
#include <string>

#include "repch.h"

#include "events/mouse_event.h"
#include "events/event_type.h"

namespace raphen::events {
// --------------- MOUSE EVENT -----------------------

MouseEvent::MouseEvent(double x, double y)
	: _mouse_x(x), _mouse_y(y) {}

inline double MouseEvent::GetX() const { return _mouse_x; }
inline double MouseEvent::GetY() const { return _mouse_y; }

unsigned int MouseEvent::GetCategoryFlags() const {
	return EventCategoryMouse | EventCategoryInput;
}

std::string MouseEvent::ToString() const {
	std::stringstream ss;
	ss << "MouseEvent: (" << _mouse_x << "," << _mouse_y << ")";
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
	(double x, double y, double x_offset, double y_offset)
	: MouseEvent(x, y), _x_offset(x_offset), _y_offset(y_offset) {}

inline double MouseScrolledEvent::GetXOffset() const { return _x_offset; }
inline double MouseScrolledEvent::GetYOffset() const { return _y_offset; }

EventType MouseScrolledEvent::GetStaticType() {
	return EventType::MouseScrolled;
}
EventType MouseScrolledEvent::GetEventType() const { return GetStaticType(); }
const char* MouseScrolledEvent::GetName() const { return "MouseMovedEvent"; }

std::string MouseScrolledEvent::ToString() const {
	std::stringstream ss;
	ss  << "MouseScrolledEvent: offset (" << _x_offset << "," << _y_offset
		<< ")";
	return ss.str();
}

// --------------- MOUSE BUTTON EVENT -----------------------

MouseButtonEvent::MouseButtonEvent(double x, double y, unsigned int button) :
	MouseEvent(x, y), _mouse_button(button) {}

inline unsigned int MouseButtonEvent::GetMouseButton() const {
	return _mouse_button;
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
	ss  << "MouseButtonDownEvent: (" << _mouse_x << "," << _mouse_y
		<< "), button: " << _mouse_button;
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
	ss  << "MouseButtonUpEvent: (" << _mouse_x << "," << _mouse_y
		<< "), button: " << _mouse_button;
	return ss.str();
}
}  // namespace raphen::events
