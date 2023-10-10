/*******************************************************************************
 * Contents: BinarySemaphores class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "BinarySemaphores.h"


[[nodiscard]] bool Api::BinarySemaphores::InitializeSemaphores(sem_t* semaphores) noexcept
{
    bool isReady{true};
    if (OutOfBounds(semaphores))
    {
        isReady = false;
    }
    else
    {
        for (int i = 0; i < this->count; i++)
        {
            sem_init(&semaphores[i], Default::PSHARED, Default::VALUE);
        }
    }

    return isReady;
}


[[nodiscard]] bool Api::BinarySemaphores::DestroySemaphores(sem_t* semaphores) noexcept
{
    bool isDestroyed{true};
    if (OutOfBounds(semaphores) == true)
    {
        isDestroyed = false;
    }
    else
    {
        for (int i = 0; i < this->count; i++)
        {
            sem_destroy(&semaphores[i]);
        }
    }

    return isDestroyed;
}


[[nodiscard]] bool Api::BinarySemaphores::SemWait(sem_t* semaphore) noexcept
{
    bool isWaiting{true};
    if (OutOfBounds(semaphore) == true)
    {
        isWaiting = false;
    }
    else
    {
        sem_wait(semaphore);
    }

    return isWaiting;
}


[[nodiscard]] bool Api::BinarySemaphores::SemPost(sem_t* semaphore) noexcept
{
    bool isPosted{true};
    if (OutOfBounds(semaphore) == true)
    {
        isPosted = false;
    }
    else
    {
        sem_wait(semaphore);
    }

    return isPosted;
}


[[nodiscard]] bool Api::BinarySemaphores::OutOfBounds(sem_t* semaphores) noexcept
{
    return ((semaphores == nullptr) || (this->count < Bounds::COUNTLOWER));
}



