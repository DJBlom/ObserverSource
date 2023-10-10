/*******************************************************************************
 * Contents: Core class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CORE_H_
#define _CORE_H_
#include "Sched.h"
namespace System {
    constexpr int servicesCount{4};
    class Core {
        public:
            Core() = default;
            explicit Core(const int& policy) : schedPolicy{policy} {}
            Core(const Core&) = default;
            Core(Core&&) = default;
            Core& operator= (const Core&) = default;
            Core& operator= (Core&&) = default;
            virtual ~Core() = default;

            [[nodiscard]] virtual bool Setup(Interface::Sched& sched) noexcept;

        private:
            int schedPolicy{Default::initialize};
            sem_t semaphores[servicesCount]{Default::initialize};

            enum Default {
                initialize = 0
            };
    };
}
#endif
