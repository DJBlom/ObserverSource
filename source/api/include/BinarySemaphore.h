/*******************************************************************************
 * Contents: BinarySemaphore class
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _BINARY_SEMAPHORE_H_
#define _BINARY_SEMAPHORE_H_
#include <Exception.h>
#include <Semaphore.h>
namespace Api {
    class BinarySemaphore : public Interface::Semaphore {
        public:
            BinarySemaphore()
            {
                if (sem_init(&this->semaphore, INIT::P_SHARED, INIT::VALUE) != STATUS::OK)
                    throw Api::Exception::SEM;
            }
            BinarySemaphore(const BinarySemaphore&) = default;
            BinarySemaphore(BinarySemaphore&&) = default;
            BinarySemaphore& operator= (const BinarySemaphore&) = default;
            BinarySemaphore& operator= (BinarySemaphore&&) = default;
            virtual ~BinarySemaphore()
            {
                sem_destroy(&this->semaphore);
            }

            [[nodiscard]] virtual bool Acquire(const bool& acquire) noexcept;
            [[nodiscard]] virtual bool Release(const bool& release) noexcept;

        private:
            sem_t semaphore{0};
            enum STATUS {
                OK
            };
            enum INIT {
                P_SHARED = 0,
                VALUE = 1
            };
    };
}
#endif
