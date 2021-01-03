// Copyright 2019-2020 Raphael Hungria
#pragma once

#include <string>

#include "RaphEn/general/core.h"
#include "RaphEn/events/event_type.h"
#include "RaphEn/events/event.h"

namespace raphen::events {

class RE_API AppTickEvent : public Event {
 public:
    AppTickEvent();

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

    unsigned int GetCategoryFlags() const override;
};

class RE_API AppUpdateEvent : public Event {
 public:
    AppUpdateEvent();

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

    unsigned int GetCategoryFlags() const override;
};

class RE_API AppRenderEvent : public Event {
 public:
    AppRenderEvent();

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

    unsigned int GetCategoryFlags() const override;
};
}  // namespace raphen::events