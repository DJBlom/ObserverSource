/*******************************************************************************
* Contents: Camera class
* Author: Dawid Blom
* Date: October 23, 2023
*
* Note:
******************************************************************************/
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <Errors.h>
namespace Hardware {
class Camera : public Interface::Device {
    public:
        Camera() = delete;
        explicit Camera(const char* pathToDevice)
        {
            this->fileDescriptor = open(pathToDevice, O_RDWR | O_NONBLOCK);
            if (this->fileDescriptor < 0)//LCOV_EXCL_START
                throw System::Errors::construction;
            //LCOV_EXCL_STOP
        }
        Camera(const Camera&) = delete;
        Camera(Camera&&) = delete;
        Camera& operator= (const Camera&) = delete;
        Camera& operator= (Camera&&) = delete;
        virtual ~Camera()
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
