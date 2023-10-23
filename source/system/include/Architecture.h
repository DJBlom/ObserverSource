/*******************************************************************************
 * Contents: Architecture class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _ARCHITECTURE_H_
#define _ARCHITECTURE_H_
#include <sched.h>
#include <thread>
namespace System {
    class Architecture {
        public:
            Architecture() = default;
            explicit Architecture(const int& schedPolicy) : policy{schedPolicy}
            {
                CPU_ZERO(&this->cpuCores);
                this->priority = sched_get_priority_max(schedPolicy);
            }
            Architecture(const Architecture&) = default;
            Architecture(Architecture&&) = default;
            Architecture& operator= (const Architecture&) = default;
            Architecture& operator= (Architecture&&) = default;
            ~Architecture() = default;

            [[nodiscard]] bool IsValid() noexcept;
            [[nodiscard]] bool SetAttributes(std::thread& systemThread) noexcept;
            [[nodiscard]] bool BindServiceToCore(std::thread& systemThread, const std::size_t& coreNum) noexcept;

        private:
            int priority{0};
            int policy{1};
            std::size_t core{0};
            cpu_set_t cpuCores{0};
            struct sched_param threadPriority{0};
    };
}
#endif
