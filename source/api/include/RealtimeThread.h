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
            RealtimeThread() = default;
            RealtimeThread(const std::size_t& core, const int& priority);
            RealtimeThread(const RealtimeThread&) = default;
            RealtimeThread(RealtimeThread&&) = delete;
            RealtimeThread& operator= (const RealtimeThread&) = default;
            RealtimeThread& operator= (RealtimeThread&&) = default;
            virtual ~RealtimeThread();

            [[nodiscard]] virtual bool Prepare(void* (*serviceFunction)(void*)) noexcept;
            [[nodiscard]] virtual bool Start() noexcept;

        private:
            cpu_set_t cpuSet{0};
            pthread_t thread{0};
            pthread_attr_t attribute;
            int inheritSched{PTHREAD_EXPLICIT_SCHED};
            int policy{SCHED_FIFO};
            int threadPriority{0};
            enum status {
                ok = 0
            };
            enum cores {
                max = 4
            };
    };
}
#endif
