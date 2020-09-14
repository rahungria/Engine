#pragma once

#include "RaphEn/Core/Core.h"

namespace raphen::memory
{

	//Interface for every memory allocator designed (linear, stack, double stack ...)
	class RE_API MemoryAllocator
	{
	public:
		// Allocate bloack of memory in the Allocator managed memory
		// @param size: size in bytes of memory block
		// @return pointer to memory block, or nullptr if couldn't allocate
		virtual void* allocate(size_t size) = 0;

		// Stops managing block of data in pointer and opens space in the Allocator (doesn't actually free memory to the OS)
		// @param ptr: ptr to block of data to stop managing access
		virtual void free(void* ptr) = 0;
	protected:
		// maybe not virtual
		// returns memory aligned of given size
		// ex: x64 -> align(3) = 8, align(15) = 16 ...
		virtual size_t align(const size_t size)
		{
			return (size + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
		}
	};
}