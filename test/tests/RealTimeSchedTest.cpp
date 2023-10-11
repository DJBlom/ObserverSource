/*******************************************************************************
 * Contents: RealTimeSched Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <unistd.h>

#include "RealTimeSched.h"
extern "C"
{

}


/**********************************TEST LIST************************************
 * General
 * 1) Get the priroity based on the scheduler policy (Done)
 * 2) Set the scheduler based on the process ID (Done)
 * 3) Inititalize all the semaphores (Done)
 * 4) Destroy semaphores (Done)
 * 5) Initialize the systems core (Done)
 *
 * Boundaries
 * 6) A valid priority is between 1 - 99 (Done)
 * 7) A valid policy is 1 (Done)
 * 8) The number of semaphores = number of services (Done)
 ******************************************************************************/
TEST_GROUP(RealTimeSchedTest)
{
    Api::RealTimeSched sched;
    void setup()
    {
        pid_t pid = getpid();
        sched = Api::RealTimeSched{pid};
    }

    void teardown()
    {
    }
};


TEST(RealTimeSchedTest, GetSystemsPriority)
{
    CHECK_EQUAL(99, sched.PriorityGet(SCHED_FIFO));
}


TEST(RealTimeSchedTest, PriorityIsInBounds)
{
    CHECK_EQUAL(-1, sched.PriorityGet(SCHED_RR));
    CHECK_EQUAL(-1, sched.PriorityGet(SCHED_OTHER));
}


TEST(RealTimeSchedTest, CorrectlySetTheSystemsScheduler)
{
    int priority = sched.PriorityGet(SCHED_FIFO);
    CHECK_EQUAL(true, sched.SchedulerSet(priority));
}


TEST(RealTimeSchedTest, IncorrectlySetTheSystemsScheduler)
{
    int priority = sched.PriorityGet(SCHED_RR);
    CHECK_EQUAL(false, sched.SchedulerSet(priority));
}
