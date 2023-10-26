/*******************************************************************************
 * Contents: RealtimeThread class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _REALTIME_THREAD_H_
#define _REALTIME_THREAD_H_
#include <cstddef>
#include <Thread.h>
#include <Exception.h>
namespace Config {
    constexpr int systemMaxCores{4};
}

namespace Api {
    class RealtimeThread {
        public:
            RealtimeThread() = delete;
            RealtimeThread(const std::size_t& core, const int& priority);
            RealtimeThread(const RealtimeThread&) = delete;
            RealtimeThread(RealtimeThread&&) = delete;
            RealtimeThread& operator= (const RealtimeThread&) = delete;
            RealtimeThread& operator= (RealtimeThread&&) = delete;
            virtual ~RealtimeThread();

            [[nodiscard]] virtual bool Start(void* (*serviceFunction)(void*)) noexcept;
            [[nodiscard]] virtual bool Stop() noexcept;

        private:
            cpu_set_t cpuSet;
            pthread_t thread;
            pthread_attr_t attribute;
            int inheritSched{PTHREAD_EXPLICIT_SCHED};
            int policy{SCHED_FIFO};
            int threadPriority{0};
            enum status {
                ok
            };
    };
}
#endif
