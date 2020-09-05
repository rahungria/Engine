#include "RaphEn/Events/WindowEvent.h"
#include "RaphEn/Core/EventCore.h"
#include <string>

namespace raphen::events
{
	WindowResizeEvent::WindowResizeEvent(unsigned int height, unsigned int width) :
		m_height(height), m_width(width) {}

	inline unsigned int WindowResizeEvent::GetHeight() const { return m_height; }
	inline unsigned int WindowResizeEvent::GetWidth() const { return m_width; }

	std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: [h,w](" << m_height << "," << m_width << ")";
		return ss.str();
	}
	EVENT_CLASS_CATEGORY_T(WindowResizeEvent,EventCategoryWindow)
	EVENT_CLASS_TYPE_T(WindowResizeEvent,WindowResize)
	// ---------- WINDOW CLOSE EVENT -------------------

	WindowCloseEvent::WindowCloseEvent() {}

	std::string WindowCloseEvent::ToString() const
	{
		return "WindowCloseEvent";
	}
}