#include "repch.h"

#include "RaphEn/Memory/LinearAllocator.h"
#include "RaphEn/Core/ProfilerCore.h"

namespace raphen::memory
{
	LinearAllocator::LinearAllocator(size_t size)
	{
		PROFILE_FUNCTION();

		if (size <= 0)
		{
			m_buffer = nullptr;
			m_buffer_size = 0;
			return;
		}

		size = align(size);
		
		m_buffer = malloc(size);
		m_buffer_size = 0;

		m_max_buffer_size = size;

		if (!m_buffer)
		{
			//m_max_buffer_size = 0;
			// assertion, log, something
			std::cout << "Linear Allocator constructor failed malloc\n";
		}
		std::cout << "Linear Allocator @ " << m_buffer << std::endl;
	}

	LinearAllocator::~LinearAllocator()
	{
		PROFILE_FUNCTION();

		::free(m_buffer);
	}

	void* LinearAllocator::allocate(size_t size)
	{
		PROFILE_FUNCTION();

		void* buffer_block = nullptr;
		size = align(size);

		if (size <= 0 || m_buffer_size + size > m_max_buffer_size)
		{
			//return null pointer 
			return buffer_block;
		}

		buffer_block = (char*)m_buffer + m_buffer_size;

		m_buffer_size += size;

		return buffer_block;
	}

	void LinearAllocator::free(void* ptr)
	{
		// maybe undefined behaviour
		// shouldn't be called or used
	}

	void LinearAllocator::reset()
	{
		PROFILE_FUNCTION();

		m_buffer = (char*)m_buffer - m_buffer_size;
		m_buffer_size = 0;

		// maybe not needed?
		memset(m_buffer, 0, m_max_buffer_size);
	}
}
