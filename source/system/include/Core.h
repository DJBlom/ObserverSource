/*******************************************************************************
 * Contents: Core class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CORE_H_
#define _CORE_H_
#include <sched.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <cstdint>
namespace Services {
    constexpr std::uint8_t COUNT{4};
}
namespace Control {
    class Core {
        public:
            Core() = default;
            Core(const Core&) = default;
            Core(Core&&) = default;
            Core& operator= (const Core&) = default;
            Core& operator= (Core&&) = default;
            virtual ~Core() = default;

            [[nodiscard]] virtual bool Setup(const pid_t& mainPID) noexcept;
            [[nodiscard]] virtual bool Cleanup() noexcept;

            //[[nodiscard]] virtual bool SemTakeService1();
            //[[nodiscard]] virtual bool SemTakeService2();
            //[[nodiscard]] virtual bool SemTakeService3();
            //[[nodiscard]] virtual bool SemTakeService4();

            //[[nodiscard]] virtual bool SemGiveService1();
            //[[nodiscard]] virtual bool SemGiveService2();
            //[[nodiscard]] virtual bool SemGiveService3();
            //[[nodiscard]] virtual bool SemGiveService4();
        protected:
            [[nodiscard]] bool PrioritySetup() noexcept;
            [[nodiscard]] bool SchedulerSetup(const pid_t& mainPID) noexcept;

        private:
            bool isReady{false};
            struct sched_param sched;
            sem_t serviceSem[Services::COUNT]{0};

            enum Info {
                policy = SCHED_FIFO,
            };

            enum Service {
                ONE = 1,
                TWO = 2,
                THREE = 3,
                FOUR =4
            };

    };
}
#endif
