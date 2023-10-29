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
    while (!System::Services::abortInput) //LCOV_EXCL_START
    {
        if (System::Services::inputSem.Acquire() == false)
            break;

        // Business logic goes here

        syslog(LOG_CRIT, "Data Input on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }
    //LCOV_EXCL_STOP

    pthread_exit(nullptr);
}


void* System::Services::ProcessData(void*)
{
    int num{0};
    while (!System::Services::abortProcessData) //LCOV_EXCL_START
    {
        if (System::Services::processDataSem.Acquire() == false)
            break;

        // Business logic goes here

        syslog(LOG_CRIT, "Data Process on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }
    //LCOV_EXCL_STOP

    pthread_exit(nullptr);
}


void* System::Services::Output(void*)
{
    int num{0};
    while (!System::Services::abortOutput) //LCOV_EXCL_START
    {
        if (System::Services::outputSem.Acquire() == false)
            break;

        // Business logic goes here

        syslog(LOG_CRIT, "Data Output on core: %d for the %d cycle\n", sched_getcpu(), num++);
    }
    //LCOV_EXCL_STOP

    pthread_exit(nullptr);
}


void* System::Services::Sequencer(void*)
{
    int executionCount{0};
    while (!System::Services::abortSystem) //LCOV_EXCL_START
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds(1ms));
        executionCount++;
        if (System::Services::InputReleased(executionCount) == false)
            break;

        if (System::Services::ProcessDataReleased(executionCount) == false)
            break;

        if (System::Services::OutputReleased(executionCount) == false)
            break;
    }

    if (EnsureThreadAbort() == true)
        syslog(LOG_CRIT, "SYSTEM INFO: Preparing To Shutdown. Last Thread Cycle.");
    //LCOV_EXCL_STOP

    pthread_exit(nullptr);
}


[[nodiscard]] bool System::Services::Abort(const bool& abort)
{
    System::Services::abortSystem = abort;

    return System::Services::abortSystem;
}


[[nodiscard]] bool System::Services::InputReleased(const int& count)
{
    bool isReleased{true};
    if ((count % Hz::FIFTY) == STATUS::OK)
        isReleased = System::Services::inputSem.Release();

    return isReleased;
}


[[nodiscard]] bool System::Services::ProcessDataReleased(const int& count)
{
    bool isReleased{true};
    if ((count % Hz::TEN) == STATUS::OK)
        isReleased = System::Services::processDataSem.Release();

    return isReleased;
}


[[nodiscard]] bool System::Services::OutputReleased(const int& count)
{
    bool isReleased{true};
    if ((count % Hz::FIVE) == STATUS::OK)
        isReleased = System::Services::outputSem.Release();

    return isReleased;
}


[[nodiscard]] bool System::Services::EnsureThreadAbort()
{
    bool isAborted{true};
    if (System::Services::inputSem.Release() == true) //LCOV_EXCL_START
        System::Services::abortInput = isAborted;

    if (System::Services::processDataSem.Release() == true)
        System::Services::abortProcessData = isAborted;

    if (System::Services::outputSem.Release() == true)
        System::Services::abortOutput = isAborted;
    //LCOV_EXCL_STOP

    return isAborted;
}
