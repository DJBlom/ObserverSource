/*******************************************************************************
 * Contents: PosixApi Verification Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <sched.h>
#include <pthread.h>
extern "C"
{

}


/**********************************TEST LIST************************************
 * 1)
 ******************************************************************************/
TEST_GROUP(PosixApiTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(PosixApiTest, PthreadAttrInitCanNeverFail)
{
    pthread_attr_t attr{0};
    CHECK_EQUAL(0, pthread_attr_init(&attr));
}

TEST(PosixApiTest, PhtreadAttrSetInheritSched)
{
    pthread_attr_t attr;
    CHECK_EQUAL(0, pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED));
    CHECK_EQUAL(22, pthread_attr_setinheritsched(&attr, 3));
}


TEST(PosixApiTest, PhtreadAttrSetSchedPolicy)
{
    pthread_attr_t attr;
    CHECK_EQUAL(0, pthread_attr_setschedpolicy(&attr, SCHED_FIFO));
    CHECK_EQUAL(22, pthread_attr_setschedpolicy(&attr, 3));
}


TEST(PosixApiTest, PhtreadAttrSetSchedParam)
{
    struct sched_param priority{99};
    pthread_attr_t attr;
    CHECK_EQUAL(0, pthread_attr_setschedpolicy(&attr, SCHED_FIFO));
    CHECK_EQUAL(0, pthread_attr_setschedparam(&attr, &priority));
    priority.sched_priority = 199;
    CHECK_EQUAL(22, pthread_attr_setschedparam(&attr, &priority));
}


TEST(PosixApiTest, PhtreadAttrSetAffinityNp)
{
    // The attr and set of cpus must be initialized
    cpu_set_t setOfCPUs;
    CPU_ZERO(&setOfCPUs);
    CPU_SET(2, &setOfCPUs);
    CPU_SET(3, &setOfCPUs);
    CPU_SET(1, &setOfCPUs);
    pthread_attr_t attr;
    CHECK_EQUAL(0, pthread_attr_init(&attr));
    CHECK_EQUAL(0, pthread_attr_setaffinity_np(&attr, sizeof(setOfCPUs), &setOfCPUs));
    CHECK_EQUAL(3, CPU_COUNT(&setOfCPUs));
}
