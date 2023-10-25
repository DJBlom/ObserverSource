/*******************************************************************************
 * Contents: BinarySemaphore implementation
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#include <BinarySemaphore.h>


[[nodiscard]] bool Api::BinarySemaphore::Acquire(const bool& acquire) noexcept
{
    bool isAcquired{false};
    if (acquire == true)
        isAcquired = !static_cast<bool> (sem_wait(&this->semaphore));

    return isAcquired;
}


[[nodiscard]] bool Api::BinarySemaphore::Release(const bool& release) noexcept
{
    bool isReleased{false};
    if (release == true)
        isReleased = !static_cast<bool> (sem_post(&this->semaphore));

    return isReleased;
}
