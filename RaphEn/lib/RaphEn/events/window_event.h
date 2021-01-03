// Copyright 2019-2020 Raphael Hungria
#include <string>

#pragma once

#include "RaphEn/general/core.h"
#include "RaphEn/events/event.h"
#include "RaphEn/events/event_type.h"

namespace raphen::events {
enum class EventType;
enum EventCategory;

class RE_API WindowResizeEvent : public Event {
 public:
    WindowResizeEvent(unsigned int height, unsigned int width);

    inline unsigned int GetHeight() const;
    inline unsigned int GetWidth() const;

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

    unsigned int GetCategoryFlags() const override;
 protected:
    unsigned int m_height, m_width;
};

class RE_API WindowCloseEvent : public Event {
 public:
    WindowCloseEvent();

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

    unsigned int GetCategoryFlags() const override;
};
}  // namespace raphen::events

