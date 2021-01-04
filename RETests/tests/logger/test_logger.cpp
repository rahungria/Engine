// Copyright 2021 Raphael Hungria
#include <CppUnitTest.h>

#include "RaphEn/logger/conf.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace raphen::tests::logger {

// default ostream conf tests
TEST_CLASS(LoggerConfTests) {
public:
    raphen::logger::Conf* conf;

    // creates some base Confs to test on
    TEST_METHOD_INITIALIZE(ConfInitialize) {
        conf = new raphen::logger::Conf(
            "test_logger",
            raphen::logger::Priority::Info
        );
    }

    TEST_METHOD_CLEANUP(ConfCleanUp) {
        delete conf;
    }

    // tests if selected minimum priority is respect
    TEST_METHOD(TestMiniumPriority) {
        auto error = raphen::logger::Priority::Error;
        auto debug = raphen::logger::Priority::Debug;

        Assert::IsTrue(conf->AcceptPriority(error));
        Assert::IsFalse(conf->AcceptPriority(debug));
    }
    TEST_METHOD(TestSetUpCleanUp) {
        Assert::IsTrue(conf->SetUp());
        Assert::IsTrue(conf->CleanUp());
    }
};
}  // namespace raphen::tests::logger
