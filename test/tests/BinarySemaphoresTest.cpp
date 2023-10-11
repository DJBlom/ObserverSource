/*******************************************************************************
 * Contents: BinarySemaphores Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <semaphore.h>

#include "BinarySemaphores.h"
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
TEST_GROUP(BinarySemaphoresTest)
{
    Api::BinarySemaphores sem;
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(BinarySemaphoresTest, InitializeBinarySemaphore)
{
    CHECK_EQUAL(true, sem.InitializeSemaphores(&semaphore));
}


TEST(BinarySemaphoresTest, DestroyInitializedBinarySemaphore)
{
    CHECK_EQUAL(true, sem.DestroySemaphores(&semaphore));
}


TEST(BinarySemaphoresTest, DestroyUnintializedBinarySemaphore)
{
    sem_t* semaphoreNullptr{nullptr};
    CHECK_EQUAL(false, sem.DestroySemaphores(semaphoreNullptr));
}


TEST(BinarySemaphoresTest, LockAndUnlockAnInitializedSemaphore)
{
    CHECK_EQUAL(true, sem.InitializeSemaphores(&semaphore));
    CHECK_EQUAL(true, sem.SemWait(&semaphore));
    CHECK_EQUAL(true, sem.SemPost(&semaphore));
    CHECK_EQUAL(true, sem.DestroySemaphores(&semaphore));
}


TEST(BinarySemaphoresTest, AttemptToLockAndUnlockAnUnitializedNullptrSemaphore)
{
    sem_t* semaphoreNullptr{nullptr};
    CHECK_EQUAL(false, sem.SemWait(semaphoreNullptr));
    CHECK_EQUAL(false, sem.SemPost(semaphoreNullptr));
}
