// Copyright 2021 Raphael Hungria
#include <CppUnitTest.h>
#include <iostream>

#include "RaphEn/logger/logger.h"
// #include "RaphEn/logger/conf.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace raphen::tests::logger {

// default ostream conf tests
TEST_CLASS(LoggerConfTests) {

    // creates some base Confs to test on
    TEST_METHOD_INITIALIZE(ConfInitialize) {

    }

    TEST_METHOD_CLEANUP(ConfCleanUp) {

    }

    // tests if selected minimum priority is respect
    TEST_METHOD(TestMiniumPriority) {

    }
    TEST_METHOD(TestSetUp) {

    }
    TEST_METHOD(TestCleanUp) {

    }
};

//ofstream conf tests
TEST_CLASS(LoggerFConfTests) {

    // creates some base FConfs to test on
    TEST_METHOD_INITIALIZE(FConfInitialize) {
        
    }

    TEST_METHOD_CLEANUP(FConfCleanUp) {

    }


    // tests FConf setup func (opens file, gen file name, ...)
    TEST_METHOD(TestSetUp) {

    }
};
}  // namespace raphen::tests::logger
