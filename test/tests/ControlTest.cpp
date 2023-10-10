/*******************************************************************************
 * Contents: System Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Control.h"
extern "C"
{

}



/**********************************TEST LIST************************************
 * 1) Verify that the system is ready to begin operation
 * 2) Start the system up if it's ready
 * 3) Shutdown the system when on command
 ******************************************************************************/
TEST_GROUP(ControlTest)
{
    System::Control control{6};
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(ControlTest, VerifyTheSystemIsReadyForOperation)
{
    CHECK_EQUAL(true, control.IsReady());
}


TEST(ControlTest, VerifyTheSystemIsNotReadyForOperation)
{
    System::Control failControl{-1};
    CHECK_EQUAL(false, failControl.IsReady());
}


TEST(ControlTest, IfTheSystemIsReadyStartIt)
{
    CHECK_EQUAL(true, control.IsReady());
    CHECK_EQUAL(true, control.Start());
}


TEST(ControlTest, ShutTheSystemDown)
{
    CHECK_EQUAL(true, control.Shutdown());
}






