// Copyright 2019-2020 Raphael Hungria
#pragma once

#include "RaphEn/Events/Event.h"

namespace raphen::events {
// Pseudo Functor
// Construct with an event, call Dispatch to handle
class EventDispatcher {
    // template<typename T>
    // using EventFn = bool(*)(T&);
 public:
    explicit EventDispatcher(Event& evnt) : //NOLINT (runtime/references)
        m_event(evnt) {}

    // Handle event with given function
    // @param bool(*func)(T&) function to call to handle event cast to template
    template<typename T>
    const bool Dispatch(bool(*func)(T&)) {
        if (m_event.GetEventType == T::GetStaticType()) {
            m_event.m_handled = func(*(T*)&m_event); //NOLINT (readability/casting)
            return true;
        }
        return false;
    }
 private:
    Event& m_event;
};
}  // namespace raphen::events
