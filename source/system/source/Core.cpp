/*******************************************************************************
 * Contents: Core implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "Core.h"


[[nodiscard]] bool System::Core::SchedulerSetup(Interface::Sched& sched) noexcept
{
    bool isSetup{false};
    int priority = sched.PriorityGet(this->schedPolicy);
    if (sched.SchedulerSet(priority) == true)
    {
        isSetup = true;
    }

    return isSetup;
}


[[nodiscard]] bool System::Core::SemaphoreSetup(Interface::Semaphore& sem) noexcept
{
    bool isSetup{false};
    if (sem.InitializeSemaphores(this->semaphores) == true)
    {
        isSetup = true;
    }

    return isSetup;
}


[[nodiscard]] bool System::Core::Cleanup(Interface::Semaphore& sem) noexcept
{
    bool isCleaned{false};
    if (sem.DestroySemaphores(this->semaphores) == true)
    {
        isCleaned = true;
    }

    return isCleaned;
}
