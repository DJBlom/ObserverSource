/*******************************************************************************
 * Contents: BinarySemaphore class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "BinarySemaphore.h"


[[nodiscard]] bool Api::BinarySemaphore::InitializeSemaphore(sem_t* semaphore) noexcept
{
    return ~(sem_init(semaphore, Default::PSHARED, Default::VALUE));
}


[[nodiscard]] bool Api::BinarySemaphore::DestroySemaphore(sem_t* semaphore) noexcept
{
    bool isDestroyed{true};
    if (IsNullptr(semaphore) == true)
    {
        isDestroyed = false;
    }
    else
    {
        sem_destroy(semaphore);
    }

    return isDestroyed;
}


[[nodiscard]] bool Api::BinarySemaphore::SemWait(sem_t* semaphore) noexcept
{
    bool isWaiting{true};
    if (IsNullptr(semaphore) == true)
    {
        isWaiting = false;
    }
    else
    {
        sem_wait(semaphore);
    }

    return isWaiting;
}


[[nodiscard]] bool Api::BinarySemaphore::SemPost(sem_t* semaphore) noexcept
{
    bool isPosted{true};
    if (IsNullptr(semaphore) == true)
    {
        isPosted = false;
    }
    else
    {
        sem_post(semaphore);
    }

    return isPosted;
}


[[nodiscard]] bool Api::BinarySemaphore::IsNullptr(sem_t* semaphore) noexcept
{
    return (semaphore == nullptr);
}
