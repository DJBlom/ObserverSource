/*******************************************************************************
 * Contents: Core implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "Core.h"


[[nodiscard]] bool Control::Core::Setup(const pid_t& mainPID) noexcept
{
    this->isReady = true;

    if (mainPID < 0)
    {
        this->isReady = false;
    }
    this->isReady = PrioritySetup();
//    else if (PrioritySetup() == false)
//    {
//        this->isReady = false;
//    }
    this->isReady = SchedulerSetup(mainPID);
//    else if (SchedulerSetup(mainPID) == false)
//    {
//        this->isReady = false;
//    }
//    else
//    {
        for (int i = 0; i < Services::COUNT; i++)
        {
            sem_init(&this->serviceSem[i], 0, 0);
//            if (sem_init(&this->serviceSem[i], 0, 0) < 0)
//            {
//                this->isReady = false;
//                break;
//            }
        }
//    }

    return this->isReady;
}


[[nodiscard]] bool Control::Core::Cleanup() noexcept
{
    this->isReady = true;
    for (int i = 0; i < Services::COUNT; i++)
	{
		sem_destroy(&this->serviceSem[i]);
//		if (sem_destroy(&this->serviceSem[i]) < 0)
//        {
//            this->isReady = false;
//        }
	}

    return this->isReady;
}


[[nodiscard]] bool Control::Core::PrioritySetup() noexcept
{
    this->isReady = true;
    std::int32_t result = sched_get_priority_max(Info::policy);
//    if (result < 0)
//    {
//        this->isReady = false;
//    }
//    else
//    {
        this->sched.sched_priority = result;
//    }

    return this->isReady;
}


[[nodiscard]] bool Control::Core::SchedulerSetup(const pid_t& mainPID) noexcept
{
    this->isReady = true;
    std::int32_t result = sched_setscheduler(mainPID, Info::policy, &this->sched);
    result++;
//    if (result < 0)
//    {
//        this->isReady = false;
//    }

    return this->isReady;
}
