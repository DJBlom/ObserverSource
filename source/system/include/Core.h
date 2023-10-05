/*******************************************************************************
 * Contents: Core class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CORE_H_
#define _CORE_H_
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
namespace Control {
    class Core {
        public:
            Core() = default;
            explicit Core(const pid_t& pid) : mainPID{pid} {}
            Core(const Core&) = default;
            Core(Core&&) = default;
            Core& operator= (const Core&) = default;
            Core& operator= (Core&&) = default;
            virtual ~Core() = default;

            [[nodiscard]] virtual bool Setup(const int& policy) noexcept;

        private:
            [[nodiscard]] int GetPriority(const int& policy) noexcept;
            [[nodiscard]] bool SetScheduler(const int& priority) noexcept;
            [[nodiscard]] bool PolicyIsValid(const int& policy) noexcept;

        private:
            int schedPolicy{0};
            pid_t mainPID{0};

    };
}
#endif
