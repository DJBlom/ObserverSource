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

static const int size{4};
static sem_t semaphores[size]{0};

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
        sem = Api::BinarySemaphores{4};
    }

    void teardown()
    {
    }
};


TEST(BinarySemaphoresTest, InitializeBinarySemaphores)
{
    CHECK_EQUAL(true, sem.InitializeSemaphores(semaphores));
}


TEST(BinarySemaphoresTest, DestroyBinarySemaphores)
{
    CHECK_EQUAL(true, sem.DestroySemaphores(semaphores));
}


TEST(BinarySemaphoresTest, BoundaryCheckBinarySemaphores)
{
    sem_t* semaphore{nullptr};
    CHECK_EQUAL(false, sem.InitializeSemaphores(semaphore));
    CHECK_EQUAL(false, sem.DestroySemaphores(semaphore));
}


TEST(BinarySemaphoresTest, TakeASemaphoreToLockAProcessThenGiveItBack)
{
    CHECK_EQUAL(true, sem.InitializeSemaphores(semaphores));
    CHECK_EQUAL(true, sem.SemWait(&semaphores[0]));
    CHECK_EQUAL(true, sem.SemPost(&semaphores[0]));
    CHECK_EQUAL(true, sem.DestroySemaphores(semaphores));
}


TEST(BinarySemaphoresTest, TakeABadSemaphoreToLockAProcessThenGiveItBack)
{
    sem_t* semaphore{nullptr};
    CHECK_EQUAL(false, sem.SemWait(semaphore));
    CHECK_EQUAL(false, sem.SemPost(semaphore));
}
