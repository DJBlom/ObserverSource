/*******************************************************************************
 * Contents: CameraMock class
 * Author: Dawid Blom
 * Date: October 23, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CAMERA_MOCK_H_
#define _CAMERA_MOCK_H_
#include <VideoCamera.h>
#include "CppUTestExt/MockSupport.h"
namespace Mock {
    class CameraMock : public Device::VideoCamera {
        public:
            CameraMock() : constructed{true} {}
            CameraMock(const CameraMock& copy) : Device::VideoCamera{copy} {}
            CameraMock(CameraMock&& rhs) : camera{std::move(rhs.camera)} {}
            CameraMock& operator= (const CameraMock& rhs) noexcept;
            CameraMock& operator= (CameraMock&& rhs) noexcept;
            virtual ~CameraMock()
            {
                constructed = false;
            }

            [[nodiscard]] virtual bool Open() noexcept;
            [[nodiscard]] virtual cv::Mat ReadFrame() noexcept;

        private:
            bool constructed{false};
            cv::VideoCapture camera;
    };
}
#endif
