/*******************************************************************************
* Contents: VideoCamera class
* Author: Dawid Blom
* Date: October 23, 2023
*
* Note:
******************************************************************************/
#ifndef _VIDEO_CAMERA_H_
#define _VIDEO_CAMERA_H_
#include <Errors.h>
#include <Camera.h>
namespace Device {
    class VideoCamera : public Interface::Camera {
        public:
            VideoCamera();
            VideoCamera(const int& width, const int& height);
            VideoCamera(const VideoCamera& rhs) : camera{rhs.camera} {}
            VideoCamera(VideoCamera&& rhs) : camera{std::move(rhs.camera)} {}
            VideoCamera& operator= (const VideoCamera& rhs) noexcept;
            VideoCamera& operator= (VideoCamera&& rhs) noexcept;
            virtual ~VideoCamera();

            [[nodiscard]] virtual bool Open() noexcept override;
            [[nodiscard]] virtual cv::Mat ReadFrame() noexcept override;

    private:
            cv::VideoCapture camera;
    };
}
#endif
