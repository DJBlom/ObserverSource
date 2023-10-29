/*******************************************************************************
 * Contents: Device Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <linux/videodev2.h>
#include <sys/ioctl.h>

#include <Device.h>

extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) A device is constructed with a path used to open the device file
 * 2) A method exists that allows for low level I/O
 *******************************************************************************/
TEST_GROUP(DeviceTest)
{
    const char path[20]{"/dev/video0"};
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(DeviceTest, LowLevelIoCtl)
{
    struct v4l2_capability cap;
    Hardware::Device device{path};

    CHECK_EQUAL(true, device.Control(VIDIOC_QUERYCAP, cap));
}
