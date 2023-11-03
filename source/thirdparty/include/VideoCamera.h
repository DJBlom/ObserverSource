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
            VideoCamera(const VideoCamera& rhs) : camera{rhs.camera} {}
            VideoCamera(VideoCamera&& rhs) : camera{std::move(rhs.camera)} {}
            VideoCamera& operator=(const VideoCamera& rhs)
            {
               VideoCamera temp{rhs};
               std::swap(temp, *this);
               return *this;
            }
            VideoCamera& operator=(VideoCamera&& rhs)
            {
                std::swap(camera, rhs.camera);
                return *this;
            }
            virtual ~VideoCamera();

            [[nodiscard]] virtual bool IsOpened() const noexcept override;
            [[nodiscard]] virtual cv::Mat ReadFrame() noexcept override;

    private:
            cv::VideoCapture camera;
    };
}
#endif
