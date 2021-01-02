#include "pch.h"
#include "CppUnitTest.h"
#include "RaphEn/logger/logger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace raphen::tests {
	TEST_CLASS(RETests) {
     public:
        TEST_METHOD(TestDLLPrivateMethods) {
            auto value = raphen::logger::return2();
            Assert::AreEqual(value, 2);
		}
	};
}
