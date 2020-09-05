#pragma once

#include "RaphEn/Events/Event.h"
#include "RaphEn/Core.h"
#include <sstream>

namespace raphen::events
{
	class KeyEvent : public Event
	{
	public:
		inline unsigned int GetKeyCode() const { return m_key_code; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyEvent(unsigned int key_code) :
			m_key_code(key_code) {};

		unsigned int m_key_code;
	};

	class RE_API KeyDownEvent : public KeyEvent
	{
	public:
		KeyDownEvent(unsigned int key_code, unsigned int repeat_count) :
			KeyEvent(key_code), m_repeat_count(repeat_count) {}

		inline unsigned int GetRepeatCount() const { return m_repeat_count; }

		EVENT_CLASS_TYPE(KeyDown)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyDownEvent: " << m_key_code << "(" << m_repeat_count << " repeats)";
			return ss.str();
		}

	private:
		unsigned int m_repeat_count;
	};

	class RE_API KeyUpEvent : public KeyEvent
	{
	public:
		KeyUpEvent(unsigned int key_code) :
			KeyEvent (key_code) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyUpEvent: " << m_key_code << std::endl;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyUp)
	};
}