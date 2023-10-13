/*******************************************************************************
 * Contents: ThreadAttr interface
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _THREAD_ATTR_H_
#define _THREAD_ATTR_H_
#include <pthread.h>
namespace Interface {
    class ThreadAttr {
        public:
            virtual ~ThreadAttr() = default;
            [[nodiscard]] virtual bool Initialize(pthread_attr_t*) = 0;
            [[nodiscard]] virtual bool NoInheritance(pthread_attr_t*) = 0;
            [[nodiscard]] virtual bool RunWithSchedFifo(pthread_attr_t*) = 0;
    };
}
#endif
