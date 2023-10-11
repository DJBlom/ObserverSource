/*******************************************************************************
 * Contents: BinarySemaphore class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _BINARY_SEMAPHORES_H_
#define _BINARY_SEMAPHORES_H_
#include "Semaphore.h"
namespace Api {
    class BinarySemaphore : public Interface::Semaphore {
        public:
            BinarySemaphore() = default;
            BinarySemaphore(const BinarySemaphore&) = default;
            BinarySemaphore(BinarySemaphore&&) = default;
            BinarySemaphore& operator= (const BinarySemaphore&) = default;
            BinarySemaphore& operator= (BinarySemaphore&&) = default;
            virtual ~BinarySemaphore() = default;

            [[nodiscard]] virtual bool InitializeSemaphore(sem_t* semaphores) noexcept override;
            [[nodiscard]] virtual bool DestroySemaphore(sem_t* semaphores) noexcept override;
            [[nodiscard]] virtual bool SemWait(sem_t* semaphore) noexcept override;
            [[nodiscard]] virtual bool SemPost(sem_t* semaphore) noexcept override;

        private:
            [[nodiscard]] virtual bool IsNullptr(sem_t* semaphores) noexcept;

        private:
            enum Default {
                PSHARED = 0,
                VALUE = 1
            };
    };
}
#endif
