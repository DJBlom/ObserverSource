/*******************************************************************************
 * Contents: Architecture implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include <Architecture.h>


[[nodiscard]] bool System::Architecture::IsValid() noexcept
{
    return (this->policy == SCHED_FIFO);
}


[[nodiscard]] bool System::Architecture::SetAttributes(std::thread& systemThread) noexcept
{
    bool isSet{false};
    this->threadPriority.sched_priority = this->priority;
    this->priority--;
    isSet = ~pthread_setschedparam(systemThread.native_handle(), this->policy, &threadPriority);

    return isSet;
}


[[nodiscard]] bool System::Architecture::BindServiceToCore(std::thread& systemThread, const std::size_t& coreNum) noexcept
{
    bool isBound{false};
    CPU_SET(coreNum, &this->cpuCores);
    isBound = ~pthread_setaffinity_np(systemThread.native_handle(), sizeof(cpu_set_t), &this->cpuCores);

    return isBound;
}
