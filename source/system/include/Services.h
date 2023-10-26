/*******************************************************************************
 * Contents: Services class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _SERVICES_H_
#define _SERVICES_H_
#include <BinarySemaphore.h>
#include <PrioInheritMutex.h>
#include <chrono>
#include <thread>
#include <syslog.h>
namespace System {
    class Services {
        public:
            Services() = default;
            Services(const Services&) = delete;
            Services(Services&&) = delete;
            Services& operator= (const Services&) = delete;
            Services& operator= (Services&&) = delete;
            ~Services() = default;

            static void* Input(void*);
            static void* ProcessData(void*);
            static void* Output(void*);
            static void* Sequencer(void*);
            [[nodiscard]] static bool Abort(const bool& abort);

        private:
            [[nodiscard]] static bool InputReleased(const int& count);
            [[nodiscard]] static bool ProcessDataReleased(const int& count);
            [[nodiscard]] static bool OutputReleased(const int& count);
            [[nodiscard]] static bool EnsureThreadAbort();

        private:
            inline static bool abortSystem{false};
            inline static bool abortInput{false};
            inline static bool abortProcessData{false};
            inline static bool abortOutput{false};
            inline static Api::PrioInheritMutex criticalSection;
            inline static Api::BinarySemaphore inputSem;
            inline static Api::BinarySemaphore processDataSem;
            inline static Api::BinarySemaphore outputSem;
            inline static Api::BinarySemaphore sequencerSem;
            enum Hz {
                FIFTY = 2,
                TEN = 10,
                FIVE = 20
            };

            enum SLEEP {
                MS_1 = 10000000
            };

            enum STATUS {
                OK = 0
            };
    };
}
#endif
