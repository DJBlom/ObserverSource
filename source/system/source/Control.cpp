/*******************************************************************************
 * Contents: Control implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "Control.h"

System::Control::Control(const pid_t& pid)
{
    this->sched = Api::RealTimeSched{pid};
    this->core = System::Core{policy};
}

[[nodiscard]] bool System::Control::IsReady() noexcept
{
    bool isReady{false};
    if (this->core.Setup(this->sched) == true)
    {
        isReady = true;
    }

    return isReady;
}


[[nodiscard]] bool System::Control::Start() noexcept
{
    return true;
}


[[nodiscard]] bool System::Control::Shutdown() noexcept
{
    return true;
}
