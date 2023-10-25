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
    isLocked = !static_cast<bool> (pthread_mutex_lock(&this->mutex));

    return isLocked;
}


[[nodiscard]] bool Api::PrioInheritMutex::Unlock() noexcept
{
    bool isUnlocked{false};
    isUnlocked = !static_cast<bool> (pthread_mutex_unlock(&this->mutex));

    return isUnlocked;
}
