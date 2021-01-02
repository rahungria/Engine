// Copyright 2019-2020 Raphael Hungria
#include "repch.h"

#include "RaphEn/memory/linear_allocator.h"
#include "RaphEn/general/profiler_core.h"

namespace raphen::memory {
LinearAllocator::LinearAllocator(size_t size)
    : m_buffer_size(0), m_max_buffer_size(0) {
    PROFILE_FUNCTION();

    if (size <= 0) {
        m_buffer = nullptr;
        return;
    }

    size = align(size);

    m_buffer = malloc(size);
    m_buffer_size = 0;

    m_max_buffer_size = size;

    // Assertion maybe
    if (!m_buffer) {
        // m_max_buffer_size = 0;
        // TODO(rapha): use logger
        std::cout << "Linear Allocator constructor failed malloc\n";
    }
}

LinearAllocator::~LinearAllocator() {
    PROFILE_FUNCTION();

    ::free(m_buffer);
}

void* LinearAllocator::allocate(size_t size) {
    PROFILE_FUNCTION();

    void* buffer_block = nullptr;
    size = align(size);

    // HACK(rapha): replace with assert later
    #ifdef RE_DEBUG
    // maybe do the checking diferently if is expensive for hot code
    if (size <= 0 || m_buffer_size + size > m_max_buffer_size) {
        // return null pointer
        return buffer_block;
    }
    #endif  // RE_DEBUG

    buffer_block = reinterpret_cast<char*>(m_buffer) + m_buffer_size;
    m_buffer_size += size;

    return buffer_block;
}

void LinearAllocator::reset() {
    PROFILE_FUNCTION();

    m_buffer = reinterpret_cast<char*>(m_buffer) - m_buffer_size;
    m_buffer_size = 0;

    // HACK(rapha): maybe not needed?
    memset(m_buffer, 0, m_max_buffer_size);
}

size_t LinearAllocator::align(const size_t size) {
    return (size + sizeof(void*) - 1) & ~(sizeof(void*) - 1);
}
}  // namespace raphen::memory

