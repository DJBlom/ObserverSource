/*******************************************************************************
 * Contents: Camera Unit Tests
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"



extern "C"
{

}



/**********************************TEST LIST************************************
 * 1) Capture 5 video frames per cycle
 * 2) Capture a specified number of frames per second
 * 3) Ensured that frame capturing does not hog up the system
 * 4) Frames should be time and data stamp
 * 5) If the camera does not support streaming provide error
 * 6) All frames should be kept in RAM and passed to the next thread
 * 7) The Camera is in charge of opening and closing the file it will use
 * 8) The Camera device should be ready to start streaming upon construction
 * 9) The Camera is created with a path to the hardware device node
 * 10) The Camera is created with the frame size specified
 * 11) All buffers are created and ready for use upon Camera creation
 ******************************************************************************/
TEST_GROUP(CameraTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(CameraTest, CreateTheCameraWithAPathToHardwareNodeAndFrameSize)
{
    CHECK_EQUAL(1, 1);
}
