


#include "SystemSched.h"



[[nodiscard]] bool Api::SystemSched::ValidatePid(const pid_t& pid) noexcept
{
    this->isValid = true;
    if (pid < 0)
    {
        perror("Validate PID");
        this->isValid = false;
    }
    else
    {
        this->mainPID = pid;
    }

    return this->isValid;
}


[[nodiscard]] int Api::SystemSched::GetPriority(const int newPolicy) noexcept
{
    int priority =  sched_get_priority_max(newPolicy);
    if (priority == -1)
    {
        perror("Get Priority");
    }
    else
    {
        this->policy = newPolicy;
    }

    return priority;
}


[[nodiscard]] bool Api::SystemSched::SetScheduler(const struct sched_param* param) noexcept
{
    this->isValid = false;
    int result = sched_setscheduler(this->mainPID, this->policy, param);
    if (result < 0)
    {
        perror("Set Scheduler");
    }
    else
    {
        this->isValid = true;
    }

    return this->isValid;
}
