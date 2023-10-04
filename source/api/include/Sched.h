



#ifndef _SCHED_H_
#define _SCHED_H_
#include <stdio.h>
#include <sched.h>
namespace Interface {
    class Sched {
        public:
            virtual ~Sched() = default;
            [[nodiscard]] virtual bool ValidatePid(const pid_t&) = 0;
            [[nodiscard]] virtual int GetPriority(const int) = 0;
            [[nodiscard]] virtual bool SetScheduler(const struct sched_param*) = 0;
    };
}
#endif
