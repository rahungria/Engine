#pragma once

#include "RaphEn/Events/Event.h"

namespace raphen::events {
	
	// Pseudo Functor
	// Construct with an event, call Dispatch to handle
	class EventDispatcher
	{
		//template<typename T>
		//using EventFn = bool(*)(T&);
	public:
		EventDispatcher(Event& evnt) :
			m_event(evnt) {}

		// Handle event with given function 
		// @param bool(*func)(T&) function to call to handle event cast to template T
		template<typename T>
		const bool Dispatch(bool(*func)(T&))
		{
			if (m_event.GetEventType == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private:
		Event& m_event;
	};
}