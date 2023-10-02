/*******************************************************************************
 * Contents: Core implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "Core.h"


[[nodiscard]] bool Control::Core::Setup(const pid_t& mainPID)
{
    this->isReady = true;

    if (mainPID < 0)
    {
        this->isReady = false;
    }
    else if (PrioritySetup() == false)
    {
        this->isReady = false;
    }
    else if (SchedulerSetup(mainPID) == false)
    {
        this->isReady = false;
    }
    else
    {
        for (int i = 0; i < Services::COUNT; i++)
        {
            if (sem_init(&this->serviceSem[i], 0, 0) < 0)
            {
                this->isReady = false;
                break;
            }
        }
    }

    return this->isReady;
}


[[nodiscard]] bool Control::Core::Cleanup()
{
    this->isReady = true;
    for (int i = 0; i < Services::COUNT; i++)
	{
		if (sem_destroy(&this->serviceSem[i]) < 0)
        {
            this->isReady = false;
        }
	}

    return this->isReady;
}


[[nodiscard]] bool Control::Core::PrioritySetup()
{
    this->isReady = true;
    std::int32_t result = sched_get_priority_max(Info::policy);
    if (result < 0)
    {
        this->isReady = false;
    }
    else
    {
        this->sched.sched_priority = result;
    }

    return this->isReady;
}


[[nodiscard]] bool Control::Core::SchedulerSetup(const pid_t& mainPID)
{
    this->isReady = true;
    std::int32_t result = sched_setscheduler(mainPID, Info::policy, &this->sched);
    if (result < 0)
    {
        this->isReady = false;
    }

    return this->isReady;
}
