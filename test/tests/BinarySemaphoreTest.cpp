/*******************************************************************************
 * Contents: BinarySemaphore Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <semaphore.h>

#include "BinarySemaphore.h"
extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) Initialize binary semaphore (Done)
 * 2) Destroy the binary semaphore created (Done)
 * 3) Semaphores should not be destroyed if they are nullptr (Done)
 * 4) We should be able to wait on a semaphore (Done)
 * 5) We should be able to post a semaphore (Done)
 * 6) We should not be able to wait or post on an uninitialized semaphore (Done)
 ******************************************************************************/
TEST_GROUP(BinarySemaphoreTest)
{
    Api::BinarySemaphore sem;
    void setup()
    {
        sem = Api::BinarySemaphore{6};
    }

    void teardown()
    {
    }
};


TEST(BinarySemaphoreTest, LockUnlockInRangeSemaphore)
{
    CHECK_EQUAL(true, sem.SemWait(3));
    CHECK_EQUAL(true, sem.SemPost(3));
}


TEST(BinarySemaphoreTest, VerifyTheCorrectRangeOfSemaphoreInitialization)
{
    CHECK_EQUAL(true, sem.SemWait(0));
    CHECK_EQUAL(true, sem.SemPost(0));

    CHECK_EQUAL(true, sem.SemWait(6));
    CHECK_EQUAL(true, sem.SemPost(6));
}


TEST(BinarySemaphoreTest, UpperBoundaryChecking)
{
    CHECK_EQUAL(false, sem.SemWait(7));
    CHECK_EQUAL(false, sem.SemPost(7));
}


TEST(BinarySemaphoreTest, LowerBoundaryChecking)
{
    CHECK_EQUAL(false, sem.SemWait(-1));
    CHECK_EQUAL(false, sem.SemPost(-1));
}
