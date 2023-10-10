/*******************************************************************************
 * Contents: Core Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <unistd.h>

#include "Core.h"
#include "RealTimeSched.h"
extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) Setup the core system with correct pid (Done)
 * 2) Setup the core system with incorrect pid (Done)
 ******************************************************************************/
TEST_GROUP(CoreTest)
{
    System::Core core;
    Api::RealTimeSched sched;
    void setup()
    {
        int pid = getpid();
        sched = Api::RealTimeSched{pid};

    }

    void teardown()
    {
    }
};


TEST(CoreTest, SystemSetupWithFifoScheduler)
{
    core = System::Core{SCHED_FIFO};
    CHECK_EQUAL(true, core.Setup(sched));
}

TEST(CoreTest, SystemSetupWithWrongScheduler)
{
    core = System::Core{-1};
    CHECK_EQUAL(false, core.Setup(sched));
}
