/*******************************************************************************
 * Contents: Semaphore interface
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_
#include <semaphore.h>
namespace Interface {
    class Semaphore {
        public:
            virtual ~Semaphore() = default;
            [[nodiscard]] virtual bool InitializeSemaphore(sem_t*) = 0;
            [[nodiscard]] virtual bool DestroySemaphore(sem_t*) = 0;
            [[nodiscard]] virtual bool SemWait(sem_t*) = 0;
            [[nodiscard]] virtual bool SemPost(sem_t*) = 0;
    };
}
#endif
