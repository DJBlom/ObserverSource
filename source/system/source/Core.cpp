/*******************************************************************************
 * Contents: Core implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "Core.h"


[[nodiscard]] bool System::Core::Setup(Interface::Sched& sched) noexcept
{
    bool isReady{false};
    int priority = sched.PriorityGet(this->schedPolicy);
    if (sched.SchedulerSet(priority) == true)
    {
        isReady = sched.InitializeSemaphores(this->semaphores, servicesCount);
    }

    return isReady;
}
