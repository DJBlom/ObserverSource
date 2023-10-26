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
            BinarySemaphore();
            BinarySemaphore(const BinarySemaphore&) = default;
            BinarySemaphore(BinarySemaphore&&) = default;
            BinarySemaphore& operator= (const BinarySemaphore&) = default;
            BinarySemaphore& operator= (BinarySemaphore&&) = default;
            virtual ~BinarySemaphore();

            [[nodiscard]] virtual bool Acquire() noexcept;
            [[nodiscard]] virtual bool Release() noexcept;

        private:
            sem_t semaphore{0};
            enum status {
                ok
            };
            enum init {
                p_shared = 0,
                value = 1
            };
    };
}
#endif
