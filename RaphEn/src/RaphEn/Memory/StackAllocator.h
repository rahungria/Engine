#pragma once

#include "RaphEn/Memory/MemoryAllocator.h"
#include <utility>

namespace raphen::memory {

	// lorem boilerplate
	// maybe internal block objects to keep track of allocated data to help freeing/defraging (play around with it)
	class StackAllocator : public MemoryAllocator
	{
	public:

		// Allocates a big block on the heap on construction
		// @param stack_size: size of the memory the Stack Allocator manages in bytes
		explicit StackAllocator(size_t stack_size);

		// No Copy or move constructors, or assignement
		StackAllocator(const StackAllocator&) = delete;
		StackAllocator(StackAllocator&&) = delete;
		StackAllocator& operator = (const StackAllocator&) = delete;

		// Allocate bloack of memory in StackAllocator managed memory
		// @param size: size in bytes of memory block
		// @return pointer to memory block, or nullptr if couldn't allocate
		virtual void* allocate(size_t size) override;

		// Stops managing block of data in pointer and opens space in the Allocator (doesn't actually free memory to the OS)
		// @param ptr: ptr to block of data to stop managing access
		virtual void free(void* ptr) override;

	protected:
		void* stack_base;
		size_t allocated_memory;
	};
}