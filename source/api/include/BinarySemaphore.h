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
            explicit BinarySemaphore(const int& numberOfThreads);
            BinarySemaphore(const BinarySemaphore&) = default;
            BinarySemaphore(BinarySemaphore&&) = default;
            BinarySemaphore& operator= (const BinarySemaphore&) = default;
            BinarySemaphore& operator= (BinarySemaphore&&) = default;
            virtual ~BinarySemaphore()
            {
                for (int i = 0; i < this->threadCount; i++)
                {
                    sem_destroy(&semaphores[i]);
                }
            }

            [[nodiscard]] virtual bool SemWait(const int& threadNum) noexcept override;
            [[nodiscard]] virtual bool SemPost(const int& threadNum) noexcept override;

        private:
            [[nodiscard]] bool ThreadNumNotInRange(const int& threadNum) noexcept;

        private:
            enum Buffer {
                SIZE = 255
            };

            enum Default {
                PSHARED = 0,
                VALUE = 1
            };

            int threadCount{0};
            sem_t semaphores[Buffer::SIZE]{0};
    };
}
#endif
