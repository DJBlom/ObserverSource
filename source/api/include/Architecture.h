/*******************************************************************************
 * Contents: Architecture interface
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _ARCHITECTURE_H_
#define _ARCHITECTURE_H_
#include <pthread.h>
namespace Interface {
    class Architecture {
        public:
            virtual ~Architecture() = default;
            [[nodiscard]] virtual bool AddThreadAttributes(pthread_attr_t*) = 0;
            [[nodiscard]] virtual bool SetupArchitecture(pthread_attr_t*) = 0;
            [[nodiscard]] virtual bool CreateThreads(pthread_attr_t*) = 0;
    };
}
#endif
