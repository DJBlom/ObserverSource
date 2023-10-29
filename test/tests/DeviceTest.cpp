/*******************************************************************************
 * Contents: IoControl Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) The ioctl should be constructed with a file descriptor. A.K.A an int type
 *******************************************************************************/
TEST_GROUP(IoControlTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(IoControlTest, Pass)
{
    CHECK_EQUAL(1, 1);
}
