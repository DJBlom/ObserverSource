/*******************************************************************************
 * Contents: Sched Unit Tests
 * Author: Dawid Blom
 * Date: October 2, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <sched.h>
#include <unistd.h>

#include "SystemSched.h"
extern "C"
{

}

static const pid_t mainPID = getpid();

/**********************************TEST LIST************************************
 * Set the priority of the scheduler
 * 1) Get the priority based on the SCHED_FIFO policy A.K.A 1 (Done)
 * 2) Ensure that that the policy is SCHED_FIFO (Done)
 *
 * Set the scheduler to be a FIFO scheduler
 * 3) The system should not run on negative PIDs (Done)
 * 4) Set the scheduler and make sure that sched_param argument is not NULL
 * 5) Test on failure because we need sudo priviledges to run successfully
 ******************************************************************************/
TEST_GROUP(SystemSchedTest)
{
    Api::SystemSched sched;
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(SystemSchedTest, VerifyPidForPositiveNumbers)
{
    CHECK_EQUAL(true, sched.ValidatePid(mainPID));
    CHECK_EQUAL(true, sched.ValidatePid(0));
}


TEST(SystemSchedTest, VerifyPidForNegativeNumbers)
{
    CHECK_EQUAL(false, sched.ValidatePid(-1));
    CHECK_EQUAL(false, sched.ValidatePid(-5));
}


TEST(SystemSchedTest, PriorityRangeInBound)
{
    CHECK_EQUAL(99, sched.GetPriority(1));
}


TEST(SystemSchedTest, PriorityRangeOutOfBound)
{
    CHECK_EQUAL(-1, sched.GetPriority(-1));
}


TEST(SystemSchedTest, SetSchedulerOnNullValueParam)
{
    struct sched_param* param{nullptr};
    CHECK_EQUAL(false, sched.SetScheduler(param));
}


TEST(SystemSchedTest, SetSchedulerWithValueParam)
{
    struct sched_param param;
    pid_t pid = getpid();
    CHECK(sched.ValidatePid(pid));
    param.sched_priority = sched.GetPriority(SCHED_FIFO);

    CHECK_EQUAL(true, sched.SetScheduler(&param));
}
