// Copyright 2021 Raphael 
#include <CppUnitTest.h>
#include <cstddef>

#include "RaphEn/memory/linear_allocator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::size_t;


namespace raphen::tests::memory {

struct dummy {
    int a;
    double b;
    int* c;
    char* d;

    explicit dummy(int _a) : a(_a), b(1.0), c(nullptr), d(nullptr) {}
};

// Holds all tests related to the linear allocator
TEST_CLASS(LinearAllocatorTests) {
 public:
    raphen::memory::LinearAllocator* linear_allocator;

    TEST_METHOD_INITIALIZE(InitializeTests) {
        // 1KB for each test
        linear_allocator = new raphen::memory::LinearAllocator(1024);
    }

    TEST_METHOD_CLEANUP(CleanupTests) {
        delete linear_allocator;
    }

    // Tests if align method properly returns 64bit aligned sizes
    TEST_METHOD(TestAlign) {
        size_t size = 13;  // number that will never be a valid alignment
        size_t aligned_size = linear_allocator->align(size);
        size_t system_default_size = sizeof(void*);

        Assert::AreNotEqual(size, aligned_size, L"Modifies the input");
        Assert::IsTrue
            (aligned_size % system_default_size == 0, L"Returns aligned value");

        size_t inv_size = linear_allocator->align((size_t)-5);

        Assert::AreEqual(inv_size, (size_t)0, L"Respects a default max size");
    }

    TEST_METHOD(TestAllocateSize) {
        void* raw = linear_allocator->allocate(sizeof(int));
        void* raw2 = linear_allocator->allocate(sizeof(dummy));

        int* int1 = new (raw) int(1);
        dummy* dummy1 = new (raw2) dummy(1);

        Assert::AreEqual(
            linear_allocator->align(sizeof(int)),
            linear_allocator->align(sizeof(*int1))
        );
        Assert::AreEqual(
            linear_allocator->align(sizeof(dummy)),
            linear_allocator->align(sizeof(*dummy1))
        );
    }

    TEST_METHOD(TestAllocatePrimitives) {
        void* raw1 = linear_allocator->allocate(sizeof(int));
        void* raw2 = linear_allocator->allocate(sizeof(int));

        int* int1 = new (raw1) int(1<<31);
        int* int2 = new (raw2) int(1<<31);

        Assert::AreEqual(*int1, 1<<31);
        Assert::AreEqual(*int2, 1<<31);
    }

    TEST_METHOD(TestAllocateObjects) {
        void* raw1 = linear_allocator->allocate(sizeof(dummy));

        dummy* d = new (raw1) dummy(1);

        Assert::AreEqual(d->a, 1);
        Assert::AreEqual(d->b, 1.);
    }

    TEST_METHOD(TestAllocateOverflow) {
        void* raw = linear_allocator->allocate(2048);

        Assert::IsNull(raw);
    }

    // code doesn't even run in debug mode, so never write it
    //TEST_METHOD(TestReset) {
    //    void* raw = linear_allocator->allocate(sizeof(long));
    //    long* data = new (raw) long(255);

    //    linear_allocator->reset();

    //    // EXTREMELY DANGEROUS NEVER DO THIS IN ACTUAL CODE
    //    // RESET IS LIABLE TO CHANGE IN FUTURE TO NOT EVEN MEMSET...
    //    Assert::AreEqual(*data, (long)0);
    //}
};
}  // namespace raphen::tests::memory
