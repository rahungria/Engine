
#include "repch.h"

#include "memory/linear_allocator.h"
#include "general/profiler_core.h"

using std::size_t;


namespace raphen::memory {
LinearAllocator::LinearAllocator(size_t size)
	: _buffer_size(0), _max_buffer_size(0), _buffer(nullptr) {
	PROFILE_FUNCTION();

	size = align(size);

	if (size == 0) {
		// TODO(rapha): Log error, assert, etc
		return;
	}

	_buffer = malloc(size);
	_buffer_size = 0;

	_max_buffer_size = size;

	// Assertion maybe
	if (!_buffer) {
		// m_max_buffer_size = 0;
		// TODO(rapha): use logger
		std::cout << "Linear Allocator constructor failed malloc\n";
	}
}

LinearAllocator::~LinearAllocator() {
	PROFILE_FUNCTION();

	::free(_buffer);
}

void* LinearAllocator::allocate(size_t size) {
	PROFILE_FUNCTION();

	void* buffer_block = nullptr;
	size = align(size);

	// HACK(rapha): replace with assert later
	#ifdef RE_DEBUG
	// maybe do the checking diferently if is expensive for hot code
	if (size <= 0 || _buffer_size + size > _max_buffer_size) {
		// return null pointer
		return buffer_block;
	}
	#endif  // RE_DEBUG

	buffer_block = reinterpret_cast<char*>(_buffer) + _buffer_size;
	_buffer_size += size;

	return buffer_block;
}

void LinearAllocator::reset() {
	PROFILE_FUNCTION();

	_buffer = reinterpret_cast<char*>(_buffer) - _buffer_size;
	_buffer_size = 0;

	// HACK(rapha): maybe not needed?
	memset(_buffer, 0, _max_buffer_size);
}

size_t LinearAllocator::align(const size_t size) {
	// TODO: replace with assertion
	// should crash, throw exception or at least log...
	if (size > MAX_BLOCK_SIZE) {
		return (size_t)0;
	}
	return (size + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
}
}  // namespace raphen::memory
