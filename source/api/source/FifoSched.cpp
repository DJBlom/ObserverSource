/*******************************************************************************
 * Contents: FifoSched implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "FifoSched.h"


[[nodiscard]] int Api::FifoSched::PriorityGet(const int& schedPolicy) noexcept
{
    int priority{Default::INIT};
    if (PolicyIsValid(schedPolicy) == true)
    {
        priority = sched_get_priority_max(schedPolicy);
    }

    return priority;
}


[[nodiscard]] bool Api::FifoSched::SchedulerSet(const int& priority) noexcept
{
    bool isReady{false};
    struct sched_param param{Default::INIT};
    if (PriorityIsValid(priority) == true)
    {
        param.sched_priority = priority;
    }

    if (sched_setscheduler(pid, this->policy, &param) == Status::OK)
    {
        isReady = true;
    }

    return isReady;
}


[[nodiscard]] bool Api::FifoSched::PolicyIsValid(const int& schedPolicy) noexcept
{
    bool isReady{false};
    if ((schedPolicy > Bounds::SCHED_LOWER) && (schedPolicy < Bounds::SCHED_UPPER))
    {
        isReady = true;
        this->policy = schedPolicy;
    }

    return isReady;
}


[[nodiscard]] bool Api::FifoSched::PriorityIsValid(const int& priority) noexcept
{
    return ((priority > Bounds::PRIORITY_LOWER) && (priority < Bounds::PRIORITY_UPPER));
}
