/*******************************************************************************
 * Contents: Core class
 * Author: Dawid Blom
 * Date: October 1, 2023
 *
 * Note:
 ******************************************************************************/
#ifndef _CORE_H_
#define _CORE_H_
namespace Control {
    class Core {
        public:
            Core() = default;
            Core(const Core&) = default;
            Core(Core&&) = default;
            Core& operator= (const Core&) = default;
            Core& operator= (Core&&) = default;
            virtual ~Core() = default;
    };
}
#endif
