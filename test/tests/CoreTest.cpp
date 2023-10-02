/*******************************************************************************
 * Contents: Core Unit Tests
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note: Refer to the TEST LIST for details on what this fixture tests.
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <sys/types.h>
#include <unistd.h>

#include "Core.h"

extern "C"
{

}


static const pid_t mainPID = getpid();

/**********************************TEST LIST************************************
 * 1) Setup the core system
 * 2) Clean the core system up
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
    CHECK(core.Setup(mainPID));
}


TEST(CoreTest, CleanupOfCoreSystem)
{
    CHECK(core.Cleanup());
}
