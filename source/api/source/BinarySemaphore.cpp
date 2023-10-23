/*******************************************************************************
 * Contents: BinarySemaphore implementation
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#include <BinarySemaphore.h>


[[nodiscard]] bool Api::BinarySemaphore::Acquire() noexcept
{
    bool isAcquired{false};
    if (sem_wait(&this->semaphore) == 0)
        isAcquired = true;

    return isAcquired;
}


[[nodiscard]] bool Api::BinarySemaphore::Release() noexcept
{
    bool isReleased{false};
    if (sem_post(&this->semaphore) == 0)
        isReleased = true;

    return isReleased;
}
