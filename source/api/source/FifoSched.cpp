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
    int priority{Default::initialize};
    if (PolicyIsValid(schedPolicy) == true)
    {
        priority = sched_get_priority_max(schedPolicy);
    }

    return priority;
}


[[nodiscard]] bool Api::FifoSched::SchedulerSet(const int& priority) noexcept
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


[[nodiscard]] bool Api::FifoSched::PolicyIsValid(const int& schedPolicy) noexcept
{
    bool isReady{false};
    if ((schedPolicy > Bounds::schedLower) && (schedPolicy < Bounds::schedUpper))
    {
        isReady = true;
        this->policy = schedPolicy;
    }

    return isReady;
}


[[nodiscard]] bool Api::FifoSched::PriorityIsValid(const int& priority) noexcept
{
    return ((priority > Bounds::priorityLower) && (priority < Bounds::priorityUpper));
}
