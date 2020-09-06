#include "RaphEn/Events/KeyEvent.h"
#include <sstream>
#include <string>

namespace raphen::events
{
	// --------------- KEY EVENT -----------------------

	KeyEvent::KeyEvent(unsigned int key_code) :
		m_key_code(key_code) {};

	inline unsigned int KeyEvent::GetKeyCode() const { return m_key_code; }

	unsigned int KeyEvent::GetCategoryFlags() const { return EventCategoryKeyboard | EventCategoryInput; }

	// --------------- KEY DOWN EVENT -----------------------

	KeyDownEvent::KeyDownEvent(unsigned int key_code, unsigned int repeat_count) :
		KeyEvent(key_code), m_repeat_count(repeat_count) {}

	inline unsigned int KeyDownEvent::GetRepeatCount() const { return m_repeat_count; }

	EventType KeyDownEvent::GetStaticType() { return EventType::KeyDown; }
	EventType KeyDownEvent::GetEventType() const { return GetStaticType(); }
	const char* KeyDownEvent::GetName() const { return "KeyDownEvent"; }

	std::string KeyDownEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyDownEvent: " << m_key_code << "(" << m_repeat_count << " repeats)";
		return ss.str();
	}

	// --------------- KEY UP VENT -----------------------

	KeyUpEvent::KeyUpEvent(unsigned int key_code) :
		KeyEvent(key_code) {}

	EventType KeyUpEvent::GetStaticType() { return EventType::KeyUp; }
	EventType KeyUpEvent::GetEventType() const { return GetStaticType(); }
	const char* KeyUpEvent::GetName() const { return "KeyUpEvent"; }

	std::string KeyUpEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyUpEvent: " << m_key_code << std::endl;
		return ss.str();
	}
}