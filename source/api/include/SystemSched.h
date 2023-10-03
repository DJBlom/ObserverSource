
#ifndef _SYSTEM_SCHED_H_
#define _SYSTEM_SCHED_H_
#include "Sched.h"
namespace Api {
    class SystemSched : public Interface::Sched {
        public:
            SystemSched() = default;
            SystemSched(const SystemSched&) = default;
            SystemSched(SystemSched&&) = default;
            SystemSched& operator= (const SystemSched&) = default;
            SystemSched& operator= (SystemSched&&) = default;
            virtual ~SystemSched() = default;

            [[nodiscard]] virtual bool PIDValidate(const pid_t& pid) noexcept override;
            //[[nodiscard]] virtual bool PiorityValidate(const std::int32_t policy) noexcept override;
            //[[nodiscard]] virtual bool SchedulerValidate(const struct sched_param* param) noexcept override;

        private:
            bool isValid{false};
            pid_t mainPID{-1};
    };
}
#endif
