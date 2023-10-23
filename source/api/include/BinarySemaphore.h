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
                if (sem_init(&this->semaphore, 0, 1) != STATUS::OK)
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

            [[nodiscard]] virtual bool Acquire() noexcept;
            [[nodiscard]] virtual bool Release() noexcept;

        private:
            sem_t semaphore{0};
            enum STATUS {
                OK
            };
    };
}
#endif
