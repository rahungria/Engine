#pragma once

#include "RaphEn/Events/Event.h"
#include "RaphEn/Events/EventType.h"
#include "RaphEn/Core/Core.h"

namespace raphen::events
{
	class RE_API KeyEvent : public Event
	{
	public:
		inline unsigned int GetKeyCode() const;
		virtual unsigned int GetCategoryFlags() const override;

	protected:
		KeyEvent(unsigned int key_code);

		unsigned int m_key_code;
	};

	class RE_API KeyDownEvent : public KeyEvent
	{
	public:
		KeyDownEvent(unsigned int key_code, unsigned int repeat_count);

		inline unsigned int GetRepeatCount() const;

		static EventType GetStaticType();
		virtual EventType GetEventType() const override;
		virtual const char* GetName() const override;

		std::string ToString() const override;

	private:
		unsigned int m_repeat_count;
	};

	class RE_API KeyUpEvent : public KeyEvent
	{
	public:
		KeyUpEvent(unsigned int key_code);

		std::string ToString() const override;

		static EventType GetStaticType();
		virtual EventType GetEventType() const override;
		virtual const char* GetName() const override;
	};
}