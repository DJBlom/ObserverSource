/*******************************************************************************
 * Contents: Control implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include <Control.h>


System::Control::Control(const pid_t& pid) //LCOV_EXCL_START
{
    struct sched_param param{0};
    this->priority = sched_get_priority_max(this->policy);
    param.sched_priority = this->priority;
    if (sched_setscheduler(pid, this->policy, &param) != status::ok)
        throw System::Errors::construction;
    //LCOV_EXCL_STOP
}


[[nodiscard]] bool System::Control::Start() noexcept
{
    if (this->sequencer.Prepare(&System::Services::Sequencer) == false) //LCOV_EXCL_START
        return false;

    if (this->input.Prepare(&System::Services::Input) == false)
        return false;

    if (this->processData.Prepare(&System::Services::ProcessData) == false)
        return false;

    if (this->output.Prepare(&System::Services::Output) == false)
        return false;

    if (this->sequencer.Start() == false)
        return false;

    if (this->input.Start() == false)
        return false;

    if (this->processData.Start() == false)
        return false;

    if (this->output.Start() == false)
        return false;
    //LCOV_EXCL_STOP

    return true;
}


[[nodiscard]] bool System::Control::Shutdown() noexcept
{
    bool isOff{false};
    isOff = System::Services::Abort(true);

    return isOff;
}
