/*******************************************************************************
 * Contents: RealTimeSched implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "RealTimeSched.h"


[[nodiscard]] int Api::RealTimeSched::PriorityGet(const int& schedFifo) noexcept
{
    int priority{Default::initialize};
    if (PolicyIsValid(schedFifo) == true)
    {
        priority = sched_get_priority_max(schedFifo);
    }

    return priority;
}


[[nodiscard]] bool Api::RealTimeSched::SchedulerSet(const int& priority) noexcept
{
    bool isReady{false};
    struct sched_param param{Default::initialize};
    if (PriorityIsValid(priority) == true)
    {
        param.sched_priority = priority;
    }

    if (sched_setscheduler(pid, this->policy, &param) == Status::ok)
    {
        isReady = true;
    }

    return isReady;
}


[[nodiscard]] bool Api::RealTimeSched::InitializeSemaphores(sem_t semaphores[], const int& size) noexcept
{
    bool isReady{false};
    for (int i = 0; i < size; i++)
    {
        sem_init(&semaphores[i], Default::pshared, Default::value);
        isReady = true;
    }

    return isReady;
}


[[nodiscard]] bool Api::RealTimeSched::DestroySemaphores(sem_t semaphores[], const int& size) noexcept
{
    bool isReady{false};
    for (int i = 0; i < size; i++)
    {
        sem_destroy(&semaphores[i]);
        isReady = true;
    }

    return isReady;
}


[[nodiscard]] bool Api::RealTimeSched::PolicyIsValid(const int& schedPolicy) noexcept
{
    bool isReady{false};
    if ((schedPolicy > Bounds::schedLower) && (schedPolicy < Bounds::schedUpper))
    {
        isReady = true;
        this->policy = schedPolicy;
    }

    return isReady;
}


[[nodiscard]] bool Api::RealTimeSched::PriorityIsValid(const int& priority) noexcept
{
    return ((priority > Bounds::priorityLower) && (priority < Bounds::priorityUpper));
}
