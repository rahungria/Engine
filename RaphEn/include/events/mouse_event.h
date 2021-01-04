
#pragma once

#include <string>

#include "general/core.h"
#include "events/event_type.h"
#include "events/event.h"

namespace raphen::events {
// base class for any Mouse Events (mouse moved, click, scroll, etc)
class RE_API MouseEvent : public Event {
 public:
	std::string ToString() const;

	inline double GetX() const;
	inline double GetY() const;

	unsigned int GetCategoryFlags() const override;

 protected:
	MouseEvent(double x, double y);

	double _mouse_x, _mouse_y;
};

// Holds just the coordinates of the movement
class RE_API MouseMovedEvent : public MouseEvent {
 public:
	MouseMovedEvent(double x, double y);

	static EventType GetStaticType();
	EventType GetEventType() const override;
	const char* GetName() const override;
};


class RE_API MouseScrolledEvent : public MouseEvent {
 public:
	MouseScrolledEvent(double x, double y, double x_offset, double y_offset);

	inline double GetXOffset() const;
	inline double GetYOffset() const;

	std::string ToString() const override;

	static EventType GetStaticType();
	EventType GetEventType() const override;
	const char* GetName() const override;

 protected:
	double _x_offset, _y_offset;
};


class RE_API MouseButtonEvent : public MouseEvent {
 public:
	virtual inline unsigned int GetMouseButton() const;

	unsigned int GetCategoryFlags() const override;
 protected:
	MouseButtonEvent(double x, double y, unsigned int button);

 protected:
	unsigned int _mouse_button;
};


class RE_API MouseButtonDownEvent : public MouseButtonEvent {
 public:
	MouseButtonDownEvent(double x, double y, unsigned int button);

	std::string ToString() const override;

	static EventType GetStaticType();
	EventType GetEventType() const override;
	const char* GetName() const override;
};

class RE_API MouseButtonUpEvent : public MouseButtonEvent {
 public:
	MouseButtonUpEvent(double x, double y, unsigned int button);

	std::string ToString() const override;

	static EventType GetStaticType();
	EventType GetEventType() const override;
	const char* GetName() const override;
};
}  // namespace raphen::events
