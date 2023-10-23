/*******************************************************************************
 * Contents: Control implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include <Control.h>

System::Control::Control(const pid_t& pid)
{
    this->mainpid = pid;
}

[[nodiscard]] bool System::Control::IsReady() noexcept
{
    return true;
}


[[nodiscard]] bool System::Control::Start() noexcept
{
    return true;
}


[[nodiscard]] bool System::Control::Shutdown() noexcept
{
    return true;
}
