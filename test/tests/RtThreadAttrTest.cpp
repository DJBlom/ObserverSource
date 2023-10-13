/*******************************************************************************
 * Contents: RtThreadAttr Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "RtThreadAttr.h"
extern "C"
{

}


/**********************************TEST LIST************************************
 * General
 * 1) Inititalize a pthread attribute to be used
 * 2) Set the inheritance policy for the thread
 * 3) Set the systems scheduling policy
 * 4) Set the priority of the thread
 * 5) Set the affinity of the thread
 * Boundaries
 ******************************************************************************/
TEST_GROUP(RtThreadAttrTest)
{
    Api::RtThreadAttr attr;
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(RtThreadAttrTest, InitializeTheThreadAttribute)
{
    pthread_attr_t threadAttr{0};
    CHECK_EQUAL(true, attr.Initialize(&threadAttr));
}


TEST(RtThreadAttrTest, NoParentInheritanceForTheThread)
{
    pthread_attr_t threadAttr{0};
    CHECK_EQUAL(true, attr.NoInheritance(&threadAttr));
}


TEST(RtThreadAttrTest, ThreadWillRunWithSchedFifo)
{
    pthread_attr_t threadAttr{0};
    CHECK_EQUAL(true, attr.RunWithSchedFifo(&threadAttr));
}


//TEST(RtThreadAttrTest, RunTheThreadAtASpecificPriority)
//{
//    const int prio{99};
//    pthread_attr_t threadAttr{0};
//    CHECK_EQUAL(true, attr.ThreadPrioritySet(&threadAttr, prio));
//}


TEST(RtThreadAttrTest, VerifyThatThreadAttrIsNotNullptr)
{
    pthread_attr_t* threadAttr{nullptr};
    CHECK_EQUAL(false, attr.NoInheritance(threadAttr));
    CHECK_EQUAL(false, attr.RunWithSchedFifo(threadAttr));
}
