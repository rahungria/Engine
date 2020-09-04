#pragma once

#include "RaphEn/Events/Event.h"

namespace raphen::events
{
	class KeyEvent : public Event
	{
	public:
		inline unsigned int GetKeyCode() const { return m_key_code; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyEvent(unsigned int key_code) :
			m_key_code(key_code) {}

		unsigned int m_key_code;
	};
}