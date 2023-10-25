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
    isAcquired = !static_cast<bool> (sem_wait(&this->semaphore));

    return isAcquired;
}


[[nodiscard]] bool Api::BinarySemaphore::Release() noexcept
{
    bool isReleased{false};
    isReleased = !static_cast<bool> (sem_post(&this->semaphore));

    return isReleased;
}
