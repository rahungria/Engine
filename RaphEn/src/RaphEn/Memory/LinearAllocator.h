#pragma once

#include "RaphEn/Memory/MemoryAllocator.h"
#include "RaphEn/Core/Core.h"

namespace raphen::memory
{
	// e
	class RE_API LinearAllocator : public MemoryAllocator
	{
	public:

		// Allocates a big block of memory on the heap on construction
		// @param stack_size: size of the memory the Linear Allocator manages in bytes
		explicit LinearAllocator(size_t stack_size);

		~LinearAllocator();

		// No Copy or move constructors, or assignement
		LinearAllocator(const LinearAllocator&) = delete;
		LinearAllocator(LinearAllocator&&) = delete;
		LinearAllocator& operator = (const LinearAllocator&) = delete;

		// Simply allocates a block of memory managed by the allocator. 
		// (Allocation is just one pointer addition)
		// @param size: size of the block in bytes
		// @return pointer to block of data managed or nullptr if couldn't allocate
		virtual void* allocate(size_t size) override;

		// Stops managing the block
		// (doesn't actually free the memory to the OS)
		// @param ptr: ptr to block of data in the Allocator
		virtual void free(void* ptr) override;

		// Resets the entire block of memory
		// memset(m_buffer, 0, m_buffer_size) maybe???
		void reset();

	private:

		void* m_buffer;
		size_t m_buffer_size;
		size_t m_max_buffer_size;
	};
}