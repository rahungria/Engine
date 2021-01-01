#include "repch.h"

#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace raphen::debug::tests
{
	TEST_CLASS(UnitTest1)
	{
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 2);
		}
	};
}