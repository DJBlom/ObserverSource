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
    if (pthread_create(&this->thread, &this->attribute, serviceFunction, nullptr) == 0)
        isStarted = true;

    return isStarted;
}


[[nodiscard]] bool Api::RealtimeThread::Stop() noexcept
{
    bool isStopped{false};
    if (pthread_join(this->thread, nullptr) == 0)
        isStopped = true;

    return isStopped;
}
