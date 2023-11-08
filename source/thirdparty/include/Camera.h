/*******************************************************************************
 * Contents: Camera interface
 * Author: Dawid Blom
 * Date: October 23, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <opencv2/opencv.hpp>
namespace Interface {
    class Camera {
        public:
            virtual ~Camera() = default;

            [[nodiscard]] virtual bool Open() = 0;
            [[nodiscard]] virtual cv::Mat ReadFrame() = 0;
    };
}
#endif
