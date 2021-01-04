
#include "repch.h"

#include "memory/stack_allocator.h"

namespace raphen::memory {
StackAllocator::StackAllocator(size_t size) {
	throw std::exception("Stack Allocator not implemented yet");
	// if (size == 0)
	// {
	//	// can't allocate size 0
	//	stack_base = nullptr;
	//	allocated_memory = 0;
	//	return;
	// }

	// size = align(size);

	// stack_base = malloc(size);

	//// test to see if memory was allocated properly

	// if (!stack_base)
	// {
	//	std::cout << "Stack Allocator failed malloc!!!!!!!\n";
	// }
}

void* StackAllocator::allocate(size_t size) {
	throw std::exception("Not Implemented");
}
}  // namespace raphen::memory
