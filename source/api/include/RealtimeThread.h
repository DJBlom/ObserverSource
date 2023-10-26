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
#include <Errors.h>
namespace Api {
    class RealtimeThread : public Interface::Thread {
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
            cpu_set_t cpuSet{0};
            pthread_t thread{0};
            pthread_attr_t attribute;
            int inheritSched{PTHREAD_EXPLICIT_SCHED};
            int policy{SCHED_FIFO};
            int threadPriority{0};
            enum status {
                ok
            };
            enum cores {
                max = 4
            };
    };
}
#endif
