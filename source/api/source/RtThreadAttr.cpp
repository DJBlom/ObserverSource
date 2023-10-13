/*******************************************************************************
 * Contents: RtThreadAttr implementation
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "RtThreadAttr.h"


[[nodiscard]] bool Api::RtThreadAttr::Initialize(pthread_attr_t* attr) noexcept
{
    return ~(pthread_attr_init(attr));
}


[[nodiscard]] bool Api::RtThreadAttr::NoInheritance(pthread_attr_t* attr) noexcept
{
    bool isSet{true};
    if (attr == nullptr)
    {
        isSet = false;
    }
    else
    {
        pthread_attr_setinheritsched(attr, PTHREAD_EXPLICIT_SCHED);
    }

    return isSet;
}


[[nodiscard]] bool Api::RtThreadAttr::RunWithSchedFifo(pthread_attr_t* attr) noexcept
{
    bool isSet{true};
    if (attr == nullptr)
    {
        isSet = false;
    }
    else
    {
        pthread_attr_setschedpolicy(attr, SCHED_FIFO);
    }

    return isSet;
}
