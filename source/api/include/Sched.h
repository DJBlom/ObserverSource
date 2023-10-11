/*******************************************************************************
 * Contents: Sched class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _SCHED_H_
#define _SCHED_H_
#include <stdio.h>
#include <sched.h>
#include <semaphore.h>
namespace Interface {
    class Sched {
        public:
            virtual ~Sched() = default;
            [[nodiscard]] virtual int PriorityGet(const int&) = 0;
            [[nodiscard]] virtual bool SchedulerSet(const pid_t&) = 0;
    };
}
#endif
