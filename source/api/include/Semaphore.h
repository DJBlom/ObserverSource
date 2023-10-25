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
            [[nodiscard]] virtual bool Acquire(const bool& acquire) = 0;
            [[nodiscard]] virtual bool Release(const bool& release) = 0;
    };
}
#endif
