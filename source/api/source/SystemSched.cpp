


#include "SystemSched.h"



[[nodiscard]] bool Api::SystemSched::PIDValidate(const pid_t& pid) noexcept
{
    this->isValid = true;
    if (pid < 0)
    {
        this->isValid = false;
    }
    else
    {
        this->mainPID = pid;
    }

    return this->isValid;
}


//[[nodiscard]] bool Api::SystemSched::PiorityValidate(const std::int32_t policy)
//{
//    return true;
//}
//
//
//[[nodiscard]] bool Api::SystemSched::SchedulerValidate(const struct sched_param* param)
//{
//    return true;
//}
