/*******************************************************************************
 * Contents: Exception class
 * Author: Dawid Blom
 * Date: October 22, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
namespace Api {
    enum class Exception {
        SEM = 1,
        MUTEX = 2,
        THREAD= 3,
    };
}
#endif
