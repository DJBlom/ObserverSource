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
            [[nodiscard]] virtual bool SemWait(const int&) = 0;
            [[nodiscard]] virtual bool SemPost(const int&) = 0;
    };
}
#endif
