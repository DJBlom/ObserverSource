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
#include "BinarySemaphores.h"
extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) Setup the core system with correct pid (Done)
 * 2) Setup the core system with incorrect pid (Done)
 * 3) Setup the core semaphores
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
    CHECK_EQUAL(true, core.SchedulerSetup(sched));
}


TEST(CoreTest, SystemSetupWithWrongScheduler)
{
    core = System::Core{-1};
    CHECK_EQUAL(false, core.SchedulerSetup(sched));
}


TEST(CoreTest, SettingUpTheCoreSeamphores)
{
    Api::BinarySemaphores sem{4};
    CHECK_EQUAL(true, core.SemaphoreSetup(sem));
}


TEST(CoreTest, CleanupCoreSystem)
{
    Api::BinarySemaphores sem{4};
    CHECK_EQUAL(true, core.SemaphoreSetup(sem));
    CHECK_EQUAL(true, core.Cleanup(sem));
}


TEST(CoreTest, BoundaryCheckForSettingUpCoreSeamphores)
{
    Api::BinarySemaphores sem{-1};
    CHECK_EQUAL(false, core.SemaphoreSetup(sem));
    CHECK_EQUAL(false, core.Cleanup(sem));
}
