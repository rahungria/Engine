
#include <string>

#include "repch.h"

#include "events/window_event.h"
#include "events/event_type.h"

namespace raphen::events {
// --------------- WINDOW RESIZE VENT -----------------------

WindowResizeEvent::WindowResizeEvent(unsigned int height, unsigned int width)
	: _height(height), _width(width) {}

inline unsigned int WindowResizeEvent::GetHeight() const { return _height; }
inline unsigned int WindowResizeEvent::GetWidth() const { return _width; }

std::string WindowResizeEvent::ToString() const {
	std::stringstream ss;
	ss << "WindowResizeEvent: [h,w](" << _height << "," << _width << ")";
	return ss.str();
}

EventType WindowResizeEvent::GetStaticType() { return EventType::WindowResize; }
EventType WindowResizeEvent::GetEventType() const  { return GetStaticType(); }
const char* WindowResizeEvent::GetName() const { return "WindowResizeEvent"; }

unsigned int WindowResizeEvent::GetCategoryFlags() const {
	return EventCategoryWindow;
}

// --------------- WINDOW CLOSE VENT -----------------------

WindowCloseEvent::WindowCloseEvent() {}

std::string WindowCloseEvent::ToString() const {
	return "WindowCloseEvent";
}

EventType WindowCloseEvent::GetStaticType() { return EventType::WindowClose; }
EventType WindowCloseEvent::GetEventType() const { return GetStaticType(); }
const char* WindowCloseEvent::GetName() const { return "WindowCloseEvent"; }

unsigned int WindowCloseEvent::GetCategoryFlags() const {
	return EventCategoryWindow;
}
}  // namespace raphen::events
