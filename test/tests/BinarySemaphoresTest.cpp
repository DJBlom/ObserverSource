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
 * 1) Create system semaphores with a dedicated service count (Done)
 * 2) Initialize binary semaphores (Done)
 * 3) Destroy the binary semaphores created (Done)
 * 4) Semaphores should not be created or destroyed if it's nullptr or
 *    services count is less than 1 (Done)
 * 5) We should be able to wait on a semaphore (Done)
 * 6) We should be able to post a semaphore (Done)
 *****************************************************************************/
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


TEST(BinarySemaphoresTest, DestroyBinarySemaphores)
{
    CHECK_EQUAL(true, sem.DestroySemaphores(&semaphore));
}


TEST(BinarySemaphoresTest, NullptrBoundaryCheckBinarySemaphore)
{
    sem_t* semaphoreNullptr{nullptr};
    CHECK_EQUAL(false, sem.InitializeSemaphores(semaphoreNullptr));
    CHECK_EQUAL(false, sem.DestroySemaphores(semaphoreNullptr));
}


TEST(BinarySemaphoresTest, CountBoundaryCheckBinarySemaphore)
{
    Api::BinarySemaphores failSem{-1};
    CHECK_EQUAL(false, failSem.InitializeSemaphores(&semaphore));
    CHECK_EQUAL(false, failSem.DestroySemaphores(&semaphore));
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
