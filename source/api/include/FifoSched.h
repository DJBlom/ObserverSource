/*******************************************************************************
 * Contents: FifoSched class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _FIFO_SCHED_H_
#define _FIFO_SCHED_H_
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
            int policy{Default::INIT};
            pid_t pid{Default::INIT};

            enum Default {
                INIT = -1,
            };

            enum Bounds {
                SCHED_LOWER = 0,
                SCHED_UPPER = 2,
                PRIORITY_LOWER = SCHED_LOWER,
                PRIORITY_UPPER = 100
            };

            enum Status {
                OK = 0
            };
    };
}
#endif
