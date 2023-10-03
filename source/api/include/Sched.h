



#ifndef _SCHED_H_
#define _SCHED_H_
#include <sys/types.h>
#include <cstdint>
namespace Interface {
    class Sched {
        public:
            virtual ~Sched() = default;
            [[nodiscard]] virtual bool PIDValidate(const pid_t&) = 0;
            //[[nodiscard]] virtual bool PiorityValidate(const std::int32_t) = 0;
            //[[nodiscard]] virtual bool SchedulerValidate(const struct sched_param*) = 0;
    };
}
#endif
