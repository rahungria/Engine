// Copyright 2019-2020 Raphael Hungria
#include <string>

#include "repch.h"

#include "RaphEn/events/application_event.h"
#include "RaphEn/events/event_type.h"



namespace raphen::events {
// --------------- APP TICK EVENT -----------------------
AppTickEvent::AppTickEvent() {}

std::string AppTickEvent::ToString() const {
    return "AppTickEvent";
}

EventType AppTickEvent::GetStaticType() { return EventType::AppTick; }
EventType AppTickEvent::GetEventType() const { return GetStaticType(); }
const char* AppTickEvent::GetName() const { return "AppTickEvent"; }

unsigned int AppTickEvent::GetCategoryFlags() const {
    return EventCategoryApplication;
}

// --------------- APP UPDATE EVENT -----------------------

AppUpdateEvent::AppUpdateEvent() {}

std::string AppUpdateEvent::ToString() const {
    return "AppUpdateEvent";
}

EventType AppUpdateEvent::GetStaticType() { return EventType::AppUpdate; }
EventType AppUpdateEvent::GetEventType() const { return GetStaticType(); }
const char* AppUpdateEvent::GetName() const { return "AppUpdateEvent"; }

unsigned int AppUpdateEvent::GetCategoryFlags() const {
    return EventCategoryApplication;
}

// --------------- APP RENDER EVENT -----------------------

AppRenderEvent::AppRenderEvent() {}

std::string  AppRenderEvent::ToString() const {
    return "AppRenderEvent";
}

EventType AppRenderEvent::GetStaticType() { return EventType::AppTick; }
EventType AppRenderEvent::GetEventType() const { return GetStaticType(); }
const char* AppRenderEvent::GetName() const { return "AppUpdateEvent"; }

unsigned int AppRenderEvent::GetCategoryFlags() const {
    return EventCategoryApplication;
}
}  // namespace raphen::events
