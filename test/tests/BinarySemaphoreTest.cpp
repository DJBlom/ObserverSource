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

static sem_t semaphore{0};

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
    }

    void teardown()
    {
    }
};


TEST(BinarySemaphoreTest, InitializeBinarySemaphore)
{
    CHECK_EQUAL(true, sem.InitializeSemaphore(&semaphore));
}


TEST(BinarySemaphoreTest, DestroyInitializedBinarySemaphore)
{
    CHECK_EQUAL(true, sem.DestroySemaphore(&semaphore));
}


TEST(BinarySemaphoreTest, DestroyUnintializedBinarySemaphore)
{
    sem_t* semaphoreNullptr{nullptr};
    CHECK_EQUAL(false, sem.DestroySemaphore(semaphoreNullptr));
}


TEST(BinarySemaphoreTest, LockAndUnlockAnInitializedSemaphore)
{
    CHECK_EQUAL(true, sem.InitializeSemaphore(&semaphore));
    CHECK_EQUAL(true, sem.SemWait(&semaphore));
    CHECK_EQUAL(true, sem.SemPost(&semaphore));
    CHECK_EQUAL(true, sem.DestroySemaphore(&semaphore));
}


TEST(BinarySemaphoreTest, AttemptToLockAndUnlockAnUnitializedNullptrSemaphore)
{
    sem_t* semaphoreNullptr{nullptr};
    CHECK_EQUAL(false, sem.SemWait(semaphoreNullptr));
    CHECK_EQUAL(false, sem.SemPost(semaphoreNullptr));
}
