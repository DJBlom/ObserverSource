
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

            [[nodiscard]] virtual bool ValidatePid(const pid_t& pid) noexcept override;
            [[nodiscard]] virtual int GetPriority(const int policy) noexcept override;
            [[nodiscard]] virtual bool SetScheduler(const struct sched_param* param) noexcept override;

        private:
            int policy{-1};
            pid_t mainPID{-1};
            bool isValid{false};
    };
}
#endif
