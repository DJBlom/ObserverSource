/*******************************************************************************
* Contents: CameraMock definition
* Author: Dawid Blom
* Date: November 2, 2023
*
* Note:
******************************************************************************/
#include <CameraMock.h>
#include "CppUTestExt/MockSupport.h"


[[nodiscard]] bool Mock::CameraMock::IsOpened() const noexcept
{
    return mock().actualCall("IsOpened").returnBoolValue();
}

[[nodiscard]] cv::Mat Mock::CameraMock::ReadFrame() noexcept
{
    cv::Mat frame;
    mock().actualCall("ReadFrame");
    return frame;
}
