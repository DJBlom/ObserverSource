/*******************************************************************************
 * Contents: FifoSched class
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
    class FifoSched : public Interface::Sched {
        public:
            FifoSched() = default;
            explicit FifoSched(const pid_t& mainPid) : pid{mainPid} {}
            FifoSched(const FifoSched&) = default;
            FifoSched(FifoSched&&) = default;
            FifoSched& operator= (const FifoSched&) = default;
            FifoSched& operator= (FifoSched&&) = default;
            virtual ~FifoSched() = default;

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
