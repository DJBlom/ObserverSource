/*******************************************************************************
 * Contents: Sched class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_
#include <sched.h>
namespace Interface {
    class Scheduler {
        public:
            virtual ~Scheduler() = default;
            [[nodiscard]] virtual bool Which() = 0;
    };
}
#endif
