/*******************************************************************************
 * Contents: Device class
 * Author: Dawid Blom
 * Date: October 23, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _DEVICE_H_
#define _DEVICE_H_
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <Errors.h>
namespace Hardware {
    class Device {
        public:
            Device() = delete;
            explicit Device(const char* pathToDevice)
            {
                this->fileDescriptor = open(pathToDevice, O_RDWR | O_NONBLOCK);
                if (this->fileDescriptor < 0)//LCOV_EXCL_START
                    throw System::Errors::construction;
                //LCOV_EXCL_STOP
            }
            Device(const Device&) = delete;
            Device(Device&&) = delete;
            Device& operator= (const Device&) = delete;
            Device& operator= (Device&&) = delete;
            virtual ~Device()
            {
                close(this->fileDescriptor); //LCOV_EXCL_LINE
            }

            [[nodiscard]] bool Control(const unsigned long&& request, auto& data...) noexcept
            {
                bool isControlled{false};
                isControlled = !static_cast<bool> (ioctl(this->fileDescriptor, request, data));

                return isControlled;
            }

        private:
            int fileDescriptor{-1};
    };
}
#endif
