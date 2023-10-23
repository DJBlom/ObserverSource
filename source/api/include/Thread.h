/*******************************************************************************
 * Contents: Thread interface
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _THREAD_H_
#define _THREAD_H_
#include <pthread.h>
namespace Interface {
    class Thread {
        public:
            virtual ~Thread() = default;
            [[nodiscard]] virtual bool Start(void* (*serviceFunction)(void*)) = 0;
            [[nodiscard]] virtual bool Stop() = 0;
    };
}
#endif
