/*******************************************************************************
 * Contents: Core implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "Core.h"


[[nodiscard]] bool Control::Core::Setup(const int& policy) noexcept
{
    bool isReady{true};
    int priority = GetPriority(policy);
    if (SetScheduler(priority) == false)
    {
        isReady = false;
    }

    return isReady;
}


[[nodiscard]] int Control::Core::GetPriority(const int& policy) noexcept
{
    int priority{0};
    if (PolicyIsValid(policy) == false)
    {
        priority = -1;
    }
    else
    {
        priority = sched_get_priority_max(policy);
    }

    return priority;
}


[[nodiscard]] bool Control::Core::SetScheduler(const int& priority) noexcept
{
    bool isReady{true};
    struct sched_param schedPriority;
    schedPriority.sched_priority = priority;
    if (sched_setscheduler(this->mainPID, this->schedPolicy, &schedPriority) == -1)
    {
        isReady = false;
    }

    return isReady;
}


[[nodiscard]] bool Control::Core::PolicyIsValid(const int& policy) noexcept
{
    bool isReady{true};
    if (policy < 0 || (policy > 2))
    {
        isReady = false;
        perror("POLICY");
    }
    else
    {
        this->schedPolicy = policy;
        isReady = true;
    }

    return isReady;
}
