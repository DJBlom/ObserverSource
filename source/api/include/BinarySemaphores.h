/*******************************************************************************
 * Contents: BinarySemaphores class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _BINARY_SEMAPHORES_H_
#define _BINARY_SEMAPHORES_H_
#include "Semaphore.h"
namespace Api {
    class BinarySemaphores : public Interface::Semaphore {
        public:
            BinarySemaphores() = default;
            explicit BinarySemaphores(const int& serviceCount) : count{serviceCount} {}
            BinarySemaphores(const BinarySemaphores&) = default;
            BinarySemaphores(BinarySemaphores&&) = default;
            BinarySemaphores& operator= (const BinarySemaphores&) = default;
            BinarySemaphores& operator= (BinarySemaphores&&) = default;
            virtual ~BinarySemaphores() = default;

            [[nodiscard]] virtual bool InitializeSemaphores(sem_t* semaphores) noexcept override;
            [[nodiscard]] virtual bool DestroySemaphores(sem_t* semaphores) noexcept override;
            [[nodiscard]] virtual bool SemWait(sem_t* semaphore) noexcept override;
            [[nodiscard]] virtual bool SemPost(sem_t* semaphore) noexcept override;

        private:
            [[nodiscard]] virtual bool OutOfBounds(sem_t* semaphores) noexcept;

        private:
            int count{1};

            enum Default {
                PSHARED = 0,
                VALUE = 1
            };

            enum Bounds {
                COUNTLOWER = 1
            };
    };
}
#endif
