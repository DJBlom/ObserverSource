/*******************************************************************************
 * Contents: System Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "System.h"
extern "C"
{

}



/**********************************TEST LIST************************************
 * 1) Verify that the system is ready to begin operation
 * 2) Start the system up if it's ready
 * 3) Shutdown the system when on command
 ******************************************************************************/
TEST_GROUP(SystemTest)
{
    Control::System system{6};
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(SystemTest, VerifyTheSystemIsReadyForOperation)
{
    CHECK(system.IsReady());
}


TEST(SystemTest, IfTheSystemIsReadyStartIt)
{
    if (system.IsReady())
        CHECK(system.Start());
}


TEST(SystemTest, ShutTheSystemDown)
{
    CHECK(system.Shutdown());
}






