/*******************************************************************************
 * Contents: Sched Unit Tests
 * Author: Dawid Blom
 * Date: October 2, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#include "SystemSched.h"

extern "C"
{

}

static const pid_t mainPID = getpid();

/**********************************TEST LIST************************************
 * Set the priority of the scheduler
 * 1) Verify that the priority p in range 1 <= p <= 99
 * 2) Verify priority p out of range 0 > p > 99
 * 2) Ensure that that the policy is SCHED_FIFO
 *
 * Set the scheduler to be a FIFO scheduler
 * 3) Verify that the PID is not negative
 * 4) Verify that the sched_param argument is not NULL
 * 5) Ensure that that the policy is SCHED_FIFO
 * 6) Test on failure because we need sudo priviledges to run successfully
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


TEST(SystemSchedTest, VerifyThePriorityInRange)
{
    CHECK_EQUAL(true, sched.PIDValidate(mainPID));
    CHECK_EQUAL(true, sched.PIDValidate(0));
}


TEST(SystemSchedTest, VerifyThePriorityOutOfRange)
{
    CHECK_EQUAL(false, sched.PIDValidate(-1));
    CHECK_EQUAL(false, sched.PIDValidate(-5));
}




