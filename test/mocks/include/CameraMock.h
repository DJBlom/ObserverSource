/*******************************************************************************
* Contents: CameraMock class
* Author: Dawid Blom
* Date: October 23, 2023
*
* Note:
******************************************************************************/
#ifndef _CAMERA_MOCK_H_
#define _CAMERA_MOCK_H_
#include <Camera.h>
#include "CppUTestExt/MockSupport.h"
namespace Mock {
    class CameraMock : public Interface::Camera {
        public:
            CameraMock() : constructed{true} {}
            CameraMock(const CameraMock& copy) : camera{copy.camera} {}
            CameraMock(CameraMock&& rhs) : camera{std::move(rhs.camera)} {}
            CameraMock& operator=(const CameraMock& rhs)
            {
               CameraMock temp{rhs};
               std::swap(temp, *this);
               return *this;
            }
            CameraMock& operator=(CameraMock&& rhs)
            {
                std::swap(camera, rhs.camera);
                return *this;
            }
            virtual ~CameraMock()
            {
                constructed = false;
            }

            [[nodiscard]] virtual bool IsOpened() const noexcept;
            [[nodiscard]] virtual cv::Mat ReadFrame() noexcept;

        private:
            bool constructed{false};
            cv::VideoCapture camera;
    };
}
#endif
