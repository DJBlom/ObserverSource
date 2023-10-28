/*******************************************************************************
 * Contents: PrioInheritMute class
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _PRIO_INHERIT_MUTEX_H_
#define _PRIO_INHERIT_MUTEX_H_
#include <Mutex.h>
#include <Errors.h>
namespace Api {
    class PrioInheritMutex : public Interface::Mutex {
        public:
            PrioInheritMutex();
            PrioInheritMutex(PrioInheritMutex&&) = default;
            PrioInheritMutex(PrioInheritMutex&) = default;
            PrioInheritMutex& operator= (const PrioInheritMutex&) = default;
            PrioInheritMutex& operator= (PrioInheritMutex&&) = default;
            virtual ~PrioInheritMutex();

            [[nodiscard]] virtual bool Lock() noexcept;
            [[nodiscard]] virtual bool Unlock() noexcept;

        private:
            pthread_mutex_t mutex;
            pthread_mutexattr_t attribute;
            enum status {
                ok = 0
            };
    };
}
#endif
