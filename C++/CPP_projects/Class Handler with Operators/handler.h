#ifndef _HANDLER_
#define _HANDLER_

#include <new>

namespace nonstd
{
    template <typename T>   // Base mixin class for support
    class NewHandlerSupport //set_new_handler at the class level
    {
    public:
        static std::new_handler set_new_handler(std::new_handler); // function set_new_handler for class
        static void *operator new(size_t);                         // operator new
        static void *operator new[](size_t);                       // operator new[]
        static void operator delete(void *, size_t);               // operator delete
        static void operator delete[](void *, size_t);             // operator delete[]
    private:
        static std::new_handler currentHandler; // member pointer [std::new_handler == typedef void (*new_handler)()]
    };
}
#include "handler.hpp"

#endif //_HANDLER_!