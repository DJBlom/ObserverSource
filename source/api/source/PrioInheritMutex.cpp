/*******************************************************************************
 * Contents: PrioInheritMute implementaion
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#include <PrioInheritMutex.h>


[[nodiscard]] bool Api::PrioInheritMutex::Lock() noexcept
{
    bool isLocked{false};
    if (pthread_mutex_lock(&this->mutex) == 0)
        isLocked = true;

    return isLocked;
}


[[nodiscard]] bool Api::PrioInheritMutex::Unlock() noexcept
{
    bool isUnlocked{false};
    if (pthread_mutex_unlock(&this->mutex) == 0)
        isUnlocked = true;

    return isUnlocked;
}
