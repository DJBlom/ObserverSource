/*******************************************************************************
 * Contents: Services class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include <Services.h>


void* System::Services::Input(void*) noexcept
{
    int num{0};
    while (!System::Services::abortInput)
    {
        if (System::Services::inputSem.Acquire() == true)
        {
            if (num == 120)
                System::Services::abortSystem = true;
            syslog(LOG_CRIT, "Data Input on core: %d for the %d cycle\n", sched_getcpu(), num++);
        }
    }

    pthread_exit(nullptr);
}


void* System::Services::ProcessData(void*) noexcept
{
    int num{0};
    while (!System::Services::abortProcessData)
    {
        if (System::Services::processDataSem.Acquire() == true)
            syslog(LOG_CRIT, "Data Process on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }

    pthread_exit(nullptr);
}


void* System::Services::Output(void*) noexcept
{
    int num{0};
    while (!System::Services::abortOutput)
    {
        if (System::Services::outputSem.Acquire() == true)
            syslog(LOG_CRIT, "Data Output on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }

    pthread_exit(nullptr);
}


void* System::Services::Sequencer(void*) noexcept
{
    int executionCount{0};
    while (!System::Services::abortSystem)
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(10000000));
        executionCount++;
        if ((executionCount % 2) == 0)
        {
            if (System::Services::inputSem.Release() == false)
                break;
        }

        if ((executionCount % 10) == 0)
        {
            if (System::Services::processDataSem.Release() == false)
                break;
        }

        if ((executionCount % 20) == 0)
        {
            if (System::Services::outputSem.Release() == false)
                break;
        }
    }

    if (System::Services::inputSem.Release() == false)
    {
        pthread_exit(nullptr);
    }

    if (System::Services::processDataSem.Release() == false)
    {
        pthread_exit(nullptr);
    }

    if (System::Services::outputSem.Release() == false)
    {
        pthread_exit(nullptr);
    }

    System::Services::abortInput = true;
    System::Services::abortProcessData = true;
    System::Services::abortOutput = true;

    pthread_exit(nullptr);
}


[[nodiscard]] bool System::Services::Abort(const bool& abort) noexcept
{
    if (abort == true)
        System::Services::abortSystem = abort;

    return System::Services::abortSystem;
}
