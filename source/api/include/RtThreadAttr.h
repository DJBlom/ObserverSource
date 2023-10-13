/*******************************************************************************
 * Contents: RtThreadAttr class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _RT_THREAD_ATTR_H_
#define _RT_THREAD_ATTR_H_
#include "ThreadAttr.h"
namespace Api {
    class RtThreadAttr : public Interface::ThreadAttr {
        public:
            RtThreadAttr() = default;
            RtThreadAttr(const RtThreadAttr&) = default;
            RtThreadAttr(RtThreadAttr&&) = default;
            RtThreadAttr& operator= (const RtThreadAttr&) = default;
            RtThreadAttr& operator= (RtThreadAttr&&) = default;
            virtual ~RtThreadAttr() = default;

            [[nodiscard]] virtual bool Initialize(pthread_attr_t* attr) noexcept override;
            [[nodiscard]] virtual bool NoInheritance(pthread_attr_t* attr) noexcept override;
            [[nodiscard]] virtual bool RunWithSchedFifo(pthread_attr_t* attr) noexcept override;
    };
}
#endif
