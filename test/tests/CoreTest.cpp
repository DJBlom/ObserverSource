/*******************************************************************************
 * Contents: Core Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "Core.h"
extern "C"
{

}


/**********************************TEST LIST************************************
 * 1) Setup the core system
 * 2) Clean the core system up
 * 3) The should not not continue if the PID is fake
 ******************************************************************************/
TEST_GROUP(CoreTest)
{
    Control::Core core;
    void setup()
    {
    }

    void teardown()
    {
    }
};


TEST(CoreTest, SetupOfCoreSystem)
{
    CHECK_EQUAL(true, core.Setup(5));
}


TEST(CoreTest, VerifyThatPidIsNotFake)
{
    CHECK_EQUAL(true, core.Setup(-1));
}


TEST(CoreTest, CleanupOfCoreSystem)
{
    CHECK(core.Cleanup());
}
