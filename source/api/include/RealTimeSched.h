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
            [[nodiscard]] virtual bool InitializeSemaphores(sem_t semaphores[], const int& size) noexcept override;
            [[nodiscard]] virtual bool DestroySemaphores(sem_t semaphores[], const int& size) noexcept override;

        private:
            [[nodiscard]] bool PolicyIsValid(const int& policy) noexcept;
            [[nodiscard]] bool PriorityIsValid(const int& priority) noexcept;

        private:
            int policy{Default::initialize};
            pid_t pid{Default::initialize};

            enum Default {
                initialize = -1,
                pshared = 0,
                value = pshared
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
