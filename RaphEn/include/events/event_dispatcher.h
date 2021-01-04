
#pragma once

#include "events/event.h"

namespace raphen::events {
// Pseudo Functor
// Construct with an event, call Dispatch to handle
class EventDispatcher {
	// template<typename T>
	// using EventFn = bool(*)(T&);
 public:
	explicit EventDispatcher(Event& evnt) : 
		_event(evnt) {}

	// Handle event with given function
	// @param bool(*func)(T&) function to call to handle event cast to template
	template<typename T>
	const bool Dispatch(bool(*func)(T&)) {
		if (m_event.GetEventType == T::GetStaticType()) {
			m_event.m_handled = func(*(T*)&_event); 
			return true;
		}
		return false;
	}
 private:
	Event& _event;
};
}  // namespace raphen::events
