/*******************************************************************************
 * Contents: Device interface
 * Author: Dawid Blom
 * Date: October 23, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _DEVICE_H_
#define _DEVICE_H_
namespace Interface {
    class Device {
        public:
            virtual ~Device() = default;

            [[nodiscard]] bool Start() = 0;
            [[nodiscard]] bool Stop() = 0;
    };
}
#endif
