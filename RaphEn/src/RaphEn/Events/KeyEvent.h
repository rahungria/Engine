// Copyright 2019-2020 Raphael Hungria
#pragma once

#include <string>

#include "RaphEn/Core/Core.h"
#include "RaphEn/Events/Event.h"
#include "RaphEn/Events/EventType.h"


namespace raphen::events {
class RE_API KeyEvent : public Event {
 public:
    inline unsigned int GetKeyCode() const;
    unsigned int GetCategoryFlags() const override;

 protected:
    explicit KeyEvent(unsigned int key_code);

    unsigned int m_key_code;
};

class RE_API KeyDownEvent : public KeyEvent {
 public:
    KeyDownEvent(unsigned int key_code, unsigned int repeat_count);

    inline unsigned int GetRepeatCount() const;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;

    std::string ToString() const override;

 private:
    unsigned int m_repeat_count;
};

class RE_API KeyUpEvent : public KeyEvent {
 public:
    explicit KeyUpEvent(unsigned int key_code);

    std::string ToString() const override;

    static EventType GetStaticType();
    EventType GetEventType() const override;
    const char* GetName() const override;
};
}  // namespace raphen::events
