/*******************************************************************************
 * Contents: System class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _SYSTEM_H_
#define _SYSTEM_H_
#include <sys/types.h>
#include "Core.h"
#include "Asymmetric.h"
namespace Control {
    class System {
        public:
            System() = delete;
            explicit System(pid_t pid): mainPID{pid} {}
            System(const System&) = default;
            System(System&&) = default;
            System& operator= (const System&) = default;
            System& operator= (System&&) = default;
            ~System() = default;

            [[nodiscard]] bool IsReady();
            [[nodiscard]] bool Start();
            [[nodiscard]] bool Shutdown();


        private:
            pid_t mainPID;
            Core core;
            Asymmetric amp;
    };
}
#endif
