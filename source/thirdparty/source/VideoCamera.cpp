/*******************************************************************************
* Contents: VideoCamera definition
* Author: Dawid Blom
* Date: November 2, 2023
*
* Note:
******************************************************************************/
#include <VideoCamera.h>


Device::VideoCamera::VideoCamera() //LCOV_EXCL_START
{
    if (this->camera.open(0, cv::CAP_V4L2) == false)
        throw System::Errors::construction;
    //LCOV_EXCL_STOP
}


Device::VideoCamera::~VideoCamera()
{
    this->camera.release();
}


[[nodiscard]] bool Device::VideoCamera::IsOpened() const noexcept
{
    return camera.isOpened();
}


[[nodiscard]] cv::Mat Device::VideoCamera::ReadFrame() noexcept
{
    cv::Mat frame;
    if (this->camera.isOpened() == true) //LCOV_EXCL_START
        this->camera.read(frame);

    return frame;
}
