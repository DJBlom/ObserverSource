/*******************************************************************************
 * Contents: Control class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CONTROL_H_
#define _CONTROL_H_
#include <sys/types.h>
#include "Core.h"
#include "FifoSched.h"
#include "AsymmetricArch.h"

namespace System {
    constexpr int policy{SCHED_FIFO};
    class Control {
        public:
            Control() = delete;
            explicit Control(const pid_t& pid);
            Control(const Control&) = default;
            Control(Control&&) = default;
            Control& operator= (const Control&) = default;
            Control& operator= (Control&&) = default;
            ~Control() = default;

            [[nodiscard]] bool IsReady() noexcept;
            [[nodiscard]] bool Start() noexcept;
            [[nodiscard]] bool Shutdown() noexcept;

        private:
            Api::RealTimeSched sched;
            System::Core core;
            System::Asymmetric amp;
    };
}
#endif
