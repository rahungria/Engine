// Copyright 2019-2020 Raphael Hungria
#pragma once

#include "RaphEn/general/core.h"

using std::size_t;


namespace raphen::memory {

// TODO: change this to a more common location for this namespace
// Maximum memory block size (500MB)
constexpr size_t MAX_BLOCK_SIZE = 1024 * 1024 * 50;

// Linear allocator to use for single frame memory.
// Doesn't support freeing memory, as it will be reset
// at the end of every frame.
class RE_API LinearAllocator {
 public:
    // Allocates a big block of memory on the heap on construction.
    // ALL MEMORY MUST BE MANAGED MANUALY.
    // EVERY OBJECT INSTANTIATED MUST CALL ITS OWN DESTRUCTOR MANUALY
    // @param stack_size: size of the memory the Linear Allocator
    // manages in bytes
    explicit LinearAllocator(size_t stack_size);

    // Returns all the managed memory to the OS only uppon destruction
    ~LinearAllocator();

    // No Copy or move constructors, or assignement
    LinearAllocator(const LinearAllocator&) = delete;
    LinearAllocator(LinearAllocator&&) = delete;
    LinearAllocator& operator=(const LinearAllocator&) = delete;
    LinearAllocator& operator=(LinearAllocator&&) = delete;

    // Simply allocates a block of memory managed by the allocator.
    // To use call allocate as if it were malloc() then use placement new to
    // call constructor of object at the right memory address
    // (Allocation is just one pointer addition)
    // @param size: size of the block in bytes
    // @return pointer to block of data managed or nullptr if couldn't allocate
    void* allocate(size_t size);

    // Resets the entire block of memory.
    // After the memory is reset, the code must NEVER attempt to access
    // any data that was previously in it, or delete it.
    // Instead just allocate memory again.
    void reset();

    // returns the aligned size
    // ex: align(3) = 8, align(15) = 16, align(32) = 32 ...
    size_t align(const size_t size);

 private:
    void* m_buffer;
    size_t m_buffer_size;
    size_t m_max_buffer_size;
};
}  // namespace raphen::memory
