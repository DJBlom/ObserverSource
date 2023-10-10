/********************************************************************************
 * Contents: The main function
 * Author: Dawid Blom
 * Date: April 13, 2023
 *
 * Note:
 *******************************************************************************/
#include <unistd.h>
#include "Control.h"


int main(void)
{
    pid_t pid = getpid();
    System::Control controlBoard{pid};
    if (controlBoard.IsReady() == true)
    {
    }

    return 0;
}

























