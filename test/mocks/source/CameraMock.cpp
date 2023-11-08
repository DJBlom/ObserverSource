/*******************************************************************************
* Contents: CameraMock definition
* Author: Dawid Blom
* Date: November 2, 2023
*
* Note:
******************************************************************************/
#include <CameraMock.h>
#include "CppUTestExt/MockSupport.h"


Mock::CameraMock& Mock::CameraMock::operator=(const CameraMock& rhs) noexcept
{
    CameraMock temp{rhs};
    std::swap(temp, *this);
    return *this;
}


Mock::CameraMock& Mock::CameraMock::operator=(CameraMock&& rhs) noexcept
{
    std::swap(camera, rhs.camera);
    return *this;
}


[[nodiscard]] bool Mock::CameraMock::Open() noexcept
{
    return mock().actualCall("Open").returnBoolValue();
}


[[nodiscard]] cv::Mat Mock::CameraMock::ReadFrame() noexcept
{
    cv::Mat frame;
    mock().actualCall("ReadFrame");
    return frame;
}
