/*******************************************************************************
 * Contents: RealtimeThread implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include <RealtimeThread.h>


[[nodiscard]] bool Api::RealtimeThread::Start(void* (*serviceFunction)(void*)) noexcept
{
    bool isStarted{false};
    isStarted = !static_cast<bool> (pthread_create(&this->thread, &this->attribute, serviceFunction, nullptr));

    return isStarted;
}


[[nodiscard]] bool Api::RealtimeThread::Stop() noexcept
{
    bool isStopped{false};
    isStopped = !static_cast<bool> (pthread_join(this->thread, nullptr));

    return isStopped;
}
