#pragma once

#include "RaphEn/Memory/MemoryAllocator.h"

namespace raphen::memory
{
	// e
	class LinearAllocator : public MemoryAllocator
	{
	public:

		// Simply allocates a block of memory managed by the allocator
		// @param size: size of the block in bytes
		// @return pointer to block of data managed or nullptr if couldn't allocate
		virtual void* allocate(size_t size) override;

		// Stops managing the block
		// (doesn't actually free the memory to the OS)
		// @param ptr: ptr to block of data in the Allocator
		virtual void free(void* ptr) override;

		// Resets the entire block of memory
		// memset(m_buffer, 0, m_buffer_size) maybe???
		void Reset();

	private:

		void* m_buffer;
		size_t m_buffer_size;
	};
}