/*******************************************************************************
 * Contents: RealTimeSched class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _REAL_TIME_SCHED_H_
#define _REAL_TIME_SCHED_H_
#include <cstring>
#include "Sched.h"
namespace Api {
    class RealTimeSched : public Interface::Sched {
        public:
            RealTimeSched() = default;
            explicit RealTimeSched(const pid_t& mainPid) : pid{mainPid} {}
            RealTimeSched(const RealTimeSched&) = default;
            RealTimeSched(RealTimeSched&&) = default;
            RealTimeSched& operator= (const RealTimeSched&) = default;
            RealTimeSched& operator= (RealTimeSched&&) = default;
            virtual ~RealTimeSched() = default;

            [[nodiscard]] virtual int PriorityGet(const int& schedPolicy) noexcept override;
            [[nodiscard]] virtual bool SchedulerSet(const int& priority) noexcept override;

        private:
            [[nodiscard]] bool PolicyIsValid(const int& policy) noexcept;
            [[nodiscard]] bool PriorityIsValid(const int& priority) noexcept;

        private:
            int policy{Default::initialize};
            pid_t pid{Default::initialize};

            enum Default {
                initialize = -1,
            };

            enum Bounds {
                schedLower = 0,
                schedUpper = 2,
                priorityLower = schedLower,
                priorityUpper = 100
            };

            enum Status {
                ok = 0
            };
    };
}
#endif
