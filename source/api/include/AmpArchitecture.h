/*******************************************************************************
 * Contents: AmpArchitecture interface
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _AMP_ARCHITECTURE_H_
#define _AMP_ARCHITECTURE_H_
#include <pthread.h>
namespace Api {
    class AmpArchitecture {
        public:
            virtual ~AmpArchitecture() = default;
            [[nodiscard]] virtual bool AddThreadAttributes(pthread_attr_t*) = 0;
            [[nodiscard]] virtual bool SetupArchitecture(pthread_attr_t*) = 0;
            [[nodiscard]] virtual bool CreateThreads(pthread_attr_t*) = 0;
    };
}
#endif
