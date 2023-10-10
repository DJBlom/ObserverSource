/*******************************************************************************
 * Contents: Asymmetric class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _ASYMMETRIC_H_
#define _ASYMMETRIC_H_
namespace System {
    class Asymmetric {
        public:
            Asymmetric() = default;
            Asymmetric(const Asymmetric&) = default;
            Asymmetric(Asymmetric&&) = default;
            Asymmetric& operator= (const Asymmetric&) = default;
            Asymmetric& operator= (Asymmetric&&) = default;
            virtual ~Asymmetric() = default;
    };
}
#endif
