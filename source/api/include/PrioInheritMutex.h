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
#include <Exception.h>
namespace Api {
    class PrioInheritMutex : Interface::Mutex {
        public:
            PrioInheritMutex()
            {
                if (pthread_mutexattr_init(&this->attribute) != STATUS::OK)
                    throw Api::Exception::MUTEX;

                if (pthread_mutexattr_setprotocol(&this->attribute, PTHREAD_PRIO_INHERIT) != STATUS::OK)
                    throw Api::Exception::MUTEX;

                if (pthread_mutex_init(&this->mutex, &this->attribute) != STATUS::OK)
                    throw Api::Exception::MUTEX;
            }
            PrioInheritMutex(PrioInheritMutex&&) = default;
            PrioInheritMutex(PrioInheritMutex&) = default;
            PrioInheritMutex& operator= (const PrioInheritMutex&) = default;
            PrioInheritMutex& operator= (PrioInheritMutex&&) = default;
            virtual ~PrioInheritMutex()
            {
                pthread_mutexattr_destroy(&this->attribute);
                pthread_mutex_destroy(&this->mutex);
            }

            [[nodiscard]] virtual bool Lock() noexcept;
            [[nodiscard]] virtual bool Unlock() noexcept;

        private:
            pthread_mutex_t mutex;
            pthread_mutexattr_t attribute;
            enum STATUS {
                OK
            };
    };
}
#endif
