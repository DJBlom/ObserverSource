/*******************************************************************************
 * Contents: RealtimeThread Unit Tests
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <iostream>

#include <RealtimeThread.h>
extern "C"
{

}



/**********************************TEST LIST************************************
 * 1) Each thread should be initialized with the following attributes (Done)
 * > - inheritance = PTHREAD_EXPLICIT_SCHED
 * > - policy = SCHED_FIFO
 * > - affinity = a specified core number
 * > - priority = in decremented order
 * 2) The thread should ready to start after creation (Done)
 * 3) The thread should stop when specified (Done)
 ******************************************************************************/
TEST_GROUP(RealtimeThreadTest)
{
    bool expectedReturn{true};
    Api::RealtimeThread service{1, 99};
    void setup()
    {
    }

    void teardown()
    {
    }
};


void* Service(void*)
{
    std::cout << "Working...\n";
    pthread_exit(nullptr);
}

TEST(RealtimeThreadTest, VerifyThreadCreationAndDestruction)
{
    CHECK_EQUAL(expectedReturn, service.Start(&Service));
    CHECK_EQUAL(expectedReturn, service.Stop());
}
