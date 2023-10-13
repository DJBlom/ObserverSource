/*******************************************************************************
 * Contents: BinarySemaphore class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#include "BinarySemaphore.h"


Api::BinarySemaphore::BinarySemaphore(const int& numberOfThreads) : threadCount{numberOfThreads}
{
    for (int i = 0; i < this->threadCount; i++)
    {
        sem_init(&semaphores[i], Default::PSHARED, Default::VALUE);
    }
}


//Api::BinarySemaphore::~BinarySemaphore()
//{
//    for (int i = 0; i < this->threadCount; i++)
//    {
//        sem_destroy(&semaphores[i]);
//    }
//}


[[nodiscard]] bool Api::BinarySemaphore::SemWait(const int& threadNum) noexcept
{
    bool isWaiting{true};
    if (ThreadNumNotInRange(threadNum) == true)
    {
        isWaiting = false;
    }
    else
    {
        sem_post(&this->semaphores[threadNum]);
    }

    return isWaiting;
}


[[nodiscard]] bool Api::BinarySemaphore::SemPost(const int& threadNum) noexcept
{
    bool isPosted{true};
    if (ThreadNumNotInRange(threadNum) == true)
    {
        isPosted = false;
    }
    else
    {
        sem_post(&semaphores[threadNum]);
    }

    return isPosted;
}


[[nodiscard]] bool Api::BinarySemaphore::ThreadNumNotInRange(const int& threadNum) noexcept
{
    return ((threadNum < 0) || (threadNum > this->threadCount));
}
