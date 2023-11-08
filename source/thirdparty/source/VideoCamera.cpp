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
    this->camera.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    this->camera.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    //LCOV_EXCL_STOP
}


Device::VideoCamera::VideoCamera(const int& width, const int& height) //LCOV_EXCL_START
{
    this->camera.set(cv::CAP_PROP_FRAME_WIDTH, width);
    this->camera.set(cv::CAP_PROP_FRAME_HEIGHT, height);
} //LCOV_EXCL_LINE


Device::VideoCamera& Device::VideoCamera::operator= (const VideoCamera& rhs) noexcept //LCOV_EXCL_START
{
    VideoCamera temp{rhs};
    std::swap(temp, *this);
    return *this;
} //LCOV_EXCL_LINE


Device::VideoCamera& Device::VideoCamera::operator= (VideoCamera&& rhs) noexcept //LCOV_EXCL_START
{
    std::swap(camera, rhs.camera);
    return *this;
} //LCOV_EXCL_LINE


Device::VideoCamera::~VideoCamera()
{
    this->camera.release();
}


[[nodiscard]] bool Device::VideoCamera::Open() noexcept //LCOV_EXCL_START
{
    bool isOpen{true};
    if (this->camera.open(0, cv::CAP_V4L2) == false)
        isOpen = false;

    return isOpen;
    //LCOV_EXCL_STOP
}


[[nodiscard]] cv::Mat Device::VideoCamera::ReadFrame() noexcept //LCOV_EXCL_START
{
    cv::Mat frame;
    if (this->camera.isOpened() == true) //LCOV_EXCL_START
        this->camera >> frame;

    return frame;
    //LCOV_EXCL_STOP
}
