// Copyright 2019-2020 Raphael Hungria
#pragma once

#include <string>

#include "RaphEn/Core/Core.h"
#include "RaphEn/Events/EventType.h"
#include "RaphEn/Events/Event.h"

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

    double m_mouse_x, m_mouse_y;
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
    MouseScrolledEvent(double x, double y, double _x_offset, double _y_offset);

    inline double GetXOffset() const;
    inline double GetYOffset() const;

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

 protected:
    double m_x_offset, m_y_offset;
};


class RE_API MouseButtonEvent : public MouseEvent {
 public:
    virtual inline unsigned int GetMouseButton() const;

    unsigned int GetCategoryFlags() const override;
 protected:
    MouseButtonEvent(double x, double y, unsigned int button);

 protected:
    unsigned int m_mouse_button;
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
