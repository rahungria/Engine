// Copyright 2020 Raphael Hungria
#include <CppUnitTest.h>

#include "repch.h"

using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

// TODO(rapha): REFACTOR A COMPREHENSIVE TEST SUIT FOR ALL SYSTEMS SO FAR
namespace raphen::tests {
TEST_CLASS(UnitTest1) {
    TEST_METHOD(TestMethod1) {
        Assert::AreEqual(1, 1);
    }
};
}  // namespace raphen::tests
