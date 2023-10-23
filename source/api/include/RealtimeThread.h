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
            RealtimeThread(const std::size_t& core, const int& priority)
            {
                this->threadPriority = sched_get_priority_max(SCHED_FIFO);
                if (priority > this->threadPriority)
                    throw Api::Exception::THREAD;

                if (core > Config::systemMaxCores)
                    throw Api::Exception::THREAD;

                if (pthread_attr_init(&this->attribute) != STATUS::OK)
                    throw Api::Exception::THREAD;

                if (pthread_attr_setinheritsched(&this->attribute, PTHREAD_EXPLICIT_SCHED) != STATUS::OK)
                    throw Api::Exception::THREAD;

                if (pthread_attr_setschedpolicy(&attribute, SCHED_FIFO) != STATUS::OK)
                    throw Api::Exception::THREAD;

                CPU_ZERO(&this->cpuSet);
                CPU_SET(core, &this->cpuSet);
                if (pthread_attr_setaffinity_np(&this->attribute, sizeof(cpu_set_t), &this->cpuSet) != STATUS::OK)
                    throw Api::Exception::THREAD;

                struct sched_param param{priority};
                if (pthread_attr_setschedparam(&this->attribute, &param) != STATUS::OK)
                    throw Api::Exception::THREAD;
            }
            RealtimeThread(const RealtimeThread&) = default;
            RealtimeThread(RealtimeThread&&) = default;
            RealtimeThread& operator= (const RealtimeThread&) = default;
            RealtimeThread& operator= (RealtimeThread&&) = default;
            virtual ~RealtimeThread()
            {
                pthread_attr_destroy(&this->attribute);
            }

            [[nodiscard]] virtual bool Start(void* (*serviceFunction)(void*)) noexcept;
            [[nodiscard]] virtual bool Stop() noexcept;

        private:
            cpu_set_t cpuSet;
            pthread_t thread;
            pthread_attr_t attribute;
            int policy{SCHED_FIFO};
            int threadPriority{0};
            enum STATUS {
                OK
            };
    };
}
#endif
