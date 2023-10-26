/*******************************************************************************
 * Contents: BinarySemaphore implementation
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#include <BinarySemaphore.h>


Api::BinarySemaphore::BinarySemaphore()
{
    if (sem_init(&this->semaphore, init::p_shared, init::value) != status::ok) //LCOV_EXCL_START
        throw Api::Exception::SEM;
    //LCOV_EXCL_STOP
}


Api::BinarySemaphore::~BinarySemaphore()
{
    sem_destroy(&this->semaphore); //LCOV_EXCL_LINE
}


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
