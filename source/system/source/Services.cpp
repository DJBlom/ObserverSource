/*******************************************************************************
 * Contents: Services class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include <Services.h>


void* System::Services::Input(void*)
{
    int num{0};
    while (!System::Services::abortInput)
    {
        if (System::Services::inputSem.Acquire(true) == false)
            break;

        // Business logic goes here

        syslog(LOG_CRIT, "Data Input on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }

    pthread_exit(nullptr);
}


void* System::Services::ProcessData(void*)
{
    int num{0};
    while (!System::Services::abortProcessData)
    {
        if (System::Services::processDataSem.Acquire(true) == false)
            break;

        // Business logic goes here

        syslog(LOG_CRIT, "Data Process on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }

    pthread_exit(nullptr);
}


void* System::Services::Output(void*)
{
    int num{0};
    while (!System::Services::abortOutput)
    {
        if (System::Services::outputSem.Acquire(true) == false)
            break;

        // Business logic goes here

        syslog(LOG_CRIT, "Data Output on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }

    pthread_exit(nullptr);
}


void* System::Services::Sequencer(void*)
{
    int executionCount{0};
    bool synch{true};
    while (!System::Services::abortSystem && synch)
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(10000000));
        executionCount++;
        if ((executionCount % 2) == 0)
            synch = System::Services::inputSem.Release(true);

        if ((executionCount % 10) == 0)
            synch = System::Services::processDataSem.Release(true);

        if ((executionCount % 20) == 0)
            synch = System::Services::outputSem.Release(true);
    }

    /*
    if (System::Services::inputSem.Release(true) == true)
        System::Services::abortInput = true;

    if (System::Services::processDataSem.Release(true) == true)
        System::Services::abortProcessData = true;

    if (System::Services::outputSem.Release(true) == true)
        System::Services::abortOutput = true;
    */

    pthread_exit(nullptr);
}


[[nodiscard]] bool System::Services::Abort(const bool& abort)
{
    if (abort == true)
    {
        System::Services::abortSystem = abort;
        if (System::Services::inputSem.Release(true) == true)
            System::Services::abortInput = true;

        if (System::Services::processDataSem.Release(true) == true)
            System::Services::abortProcessData = true;

        if (System::Services::outputSem.Release(true) == true)
            System::Services::abortOutput = true;
    }

    return System::Services::abortSystem;
}
