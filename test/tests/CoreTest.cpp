/*******************************************************************************
 * Contents: Core Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Core.h"
#include <iostream>
extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) Setup the core system
 * 2) Clean the core system up
 * 3) The should not not continue if the PID is fake
 *
 * Set the priority of the scheduler
 * 1) Get the priority based on the SCHED_FIFO policy A.K.A 1 (Done)
 * 2) Ensure that that the policy is SCHED_FIFO (Done)
 *
 * Set the scheduler to be a FIFO scheduler
 * 3) The system should not run on negative PIDs (Done)
 * 4) Set the scheduler and make sure that sched_param argument is not NULL
 * 5) Test on failure because we need sudo priviledges to run successfully
 ******************************************************************************/
TEST_GROUP(CoreTest)
{
    Control::Core core;
    void setup()
    {
        core = Control::Core{1};
    }

    void teardown()
    {
    }
};


TEST(CoreTest, SetupCoreSystemWithCorrectPolicy)
{
    CHECK_EQUAL(true, core.Setup(1));
}


TEST(CoreTest, SetupCoreSystemWithWrongPolicy)
{
    CHECK_EQUAL(false, core.Setup(-1));
}
