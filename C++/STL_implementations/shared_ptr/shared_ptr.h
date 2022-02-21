#ifndef _SHARED_PTR_
#define _SHARED_PTR_

#include <iostream>
#include <functional>
//#include"realization_of_source/shared_ptr.hpp"

namespace NSTD
{
    template<typename T>
    class shared_ptr
    {
    private:
    /* Control blok for resource */
        struct control_blok 
        {
            /* Member for pointers count*/
            int m_resource_count; 
            /* Member for deleter */
            std::function<void(T*)> m_deleter;
            /* Default constructor */
            control_blok() noexcept;
            /* Constructor white parametor's */
            control_blok(int, std::function<void(T*)>) noexcept;
        };
        
    public: 
    /* Constructors */
        /* Default constructor */
        constexpr shared_ptr() noexcept;
        /* Constructor white NULL's */
        constexpr shared_ptr(std::nullptr_t) noexcept; 
        /* Constructor white parametor pointer */
        shared_ptr(T*) noexcept;    
        /* Constructor white parametor pointer and deleter */
        shared_ptr(T*, const std::function<void(T*)>&) noexcept;    
        /*  Constructs a shared_ptr which shares ownership of the object managed by r. 
        If rhs manages no object, *this manages no object too. */
        shared_ptr(const shared_ptr&) noexcept;
        /* Move-constructs a shared_ptr from r. After the construction, 
        *this contains a copy of the previous state of r, rhs is empty and its stored pointer is null. */
        shared_ptr(shared_ptr&&) noexcept;
        /* Destructor */
        ~shared_ptr() noexcept;
    public:
    /* Operators */
        /* Copy assignment */
        shared_ptr& operator=(const shared_ptr&) noexcept;
        /* Move assignment */
        shared_ptr& operator=(shared_ptr&&) noexcept;
        /* Operator* */
        T& operator*() const noexcept;
        /* Operator-> */
        T* operator->() const noexcept;
        /* Operator[] */
        T& operator[](std::size_t) const;
        /* Operator bool */
        explicit operator bool() const noexcept;
    public:
    /* Functions */
        /* Get pointer */
        T* get() const noexcept;
        /* Get count (resource_count) */
        long use_count() const;
        /* if resource_count == 1 */
        bool unique() const;
        /* Releases ownership of the managed object, if any. */
        void reset() noexcept;
        /* Replaces the managed object with the object pointed to by ptr. */
        void reset(T*) noexcept;
        /* Replaces the managed object with the object pointed to by ptr.And entered deleter */
        void reset(T*, const std::function<void(T*)>&) noexcept;
    private: 
    /* Functions */
       /* Default deleter */
       constexpr void __default_delete() noexcept;
    private:
        T* m_pointer;
        control_blok* m_blok;
    };
}
#include"shared_ptr.hpp"

#endif /* _SHARED_PTR_ */