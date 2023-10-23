/********************************************************************************
 * Contents: The main function
 * Author: Dawid Blom
 * Date: April 13, 2023
 *
 * Note:
 *******************************************************************************/
#include <unistd.h>


#include <iostream>
#include <Services.h>
#include <RealtimeThread.h>


int main(void)
{
    pid_t pid = getpid();
    struct sched_param param{0};
    int priority = sched_get_priority_max(SCHED_FIFO);
    param.sched_priority = priority;
    if (sched_setscheduler(pid, SCHED_FIFO, &param) < 0)
    {
        std::cout << "Failed to set the scheduler.\n";
        return 0;
    }


    Api::RealtimeThread sequencer{1, priority - 1};
    Api::RealtimeThread input{2, priority - 2};
    Api::RealtimeThread processData{2, priority - 3};
    Api::RealtimeThread output{3, priority - 4};

    syslog(LOG_CRIT, "System Started\n");

    if (sequencer.Start(&System::Services::Sequencer) == false)
        return 0;

    if (input.Start(&System::Services::Input) == false)
        return 0;

    if (processData.Start(&System::Services::ProcessData) == false)
        return 0;

    if (output.Start(&System::Services::Output) == false)
        return 0;

    //if (System::Services::Abort(true) == false)
    //{
        if (sequencer.Stop() == false)
            std::cout << "Failed to join sequencer\n";

        if (input.Stop() == false)
            std::cout << "Failed to join input\n";

        if (processData.Stop() == false)
            std::cout << "Failed to join process data\n";

        if (output.Stop() == false)
            std::cout << "Failed to join output\n";
    //}
        syslog(LOG_CRIT, "System Shutdown\n");

    return 0;
}

























