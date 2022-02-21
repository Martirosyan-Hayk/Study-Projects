#include <new>
#include "handler.h"

// implementations of function and operators

template <typename T>
std::new_handler nonstd::NewHandlerSupport<T>::set_new_handler(std::new_handler p) // set_new_handler
{
    std::new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}

template <typename T>
void *nonstd::NewHandlerSupport<T>::operator new(size_t size) // operator new
{
    std::new_handler globalHandler = std::set_new_handler(currentHandler);
    void *memory;

    try
    {
        memory = ::operator new(size);
    }
    catch (std::bad_alloc &)
    {
        set_new_handler(globalHandler);
        throw;
    }
    std::set_new_handler(globalHandler);
    return memory;
}

template <typename T>
void *nonstd::NewHandlerSupport<T>::operator new[](std::size_t size) // operator new[]
{
    std::new_handler globalHandler = std::set_new_handler(currentHandler);
    void *memory;

    try
    {
        memory = ::operator new[](size);
    }
    catch (std::bad_alloc &)
    {
        set_new_handler(globalHandler);
        throw;
    }
    std::set_new_handler(globalHandler);
    return memory;
}

template <typename T>
void nonstd::NewHandlerSupport<T>::operator delete(void *rawMemory, std::size_t size) // operator delete
{
    if (size == 0)
        return;
    ::operator delete(rawMemory);
}

template <typename T>
void nonstd::NewHandlerSupport<T>::operator delete[](void *rawMemory, std::size_t size) // operator delete[]
{
    if (size == 0)
        return;
    ::operator delete[](rawMemory);
}

template <typename T>
std::new_handler nonstd::NewHandlerSupport<T>::currentHandler; // set each currentHandler in zero