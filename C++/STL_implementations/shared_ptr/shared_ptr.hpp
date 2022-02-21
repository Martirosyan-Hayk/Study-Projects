#include "shared_ptr.h"

/* Constructors of control_blok */

/* Default constructor */
template<typename T>
NSTD::shared_ptr<T>::control_blok::control_blok() noexcept 
    : m_resource_count{ 0 }
    , m_deleter{ nullptr }
{
}
/* Constructor white parametor's */
template<typename T>
NSTD::shared_ptr<T>::control_blok::control_blok(int resource_count, std::function<void(T*)> deleter) noexcept 
    : m_resource_count{ resource_count }
    , m_deleter( deleter )
{
}

/* Constructors of sharet_ptr */

/* Default constructor */
template<typename T>
constexpr NSTD::shared_ptr<T>::shared_ptr() noexcept 
    : m_pointer{ nullptr } 
    , m_blok{ nullptr }
{
}
 /* Constructor white NULL's */
template<typename T>
constexpr NSTD::shared_ptr<T>::shared_ptr(std::nullptr_t) noexcept
    : m_pointer{ nullptr } 
    , m_blok{ nullptr }
{
}
/* Constructor white parametor pointer */
template<typename T>
NSTD::shared_ptr<T>::shared_ptr(T* ptr) noexcept
{
    m_pointer = ptr;
    try
    {
        m_blok = new control_blok();
    }
    catch(std::exception& error)
    {
        std::cout << "a exception was caught, with message " << error.what();

    }
    m_blok->m_resource_count++;
}
/* Constructor white parametor pointer and deleter */
template<typename T>
NSTD::shared_ptr<T>::shared_ptr(T* ptr, const std::function<void(T*)>& deleter) noexcept
{
    m_pointer = ptr;
    try
    {
        m_blok = new control_blok(0, deleter);
    }
    catch(std::exception& error)
    {
        std::cout << "a exception was caught, with message " << error.what();

    }
    m_blok->m_resource_count++;
} 
/*  Constructs a shared_ptr which shares ownership of the object managed by r. 
    If rhs manages no object, *this manages no object too.
*/
template<typename T>
NSTD::shared_ptr<T>::shared_ptr(const shared_ptr<T>& rhs) noexcept
{
    m_pointer = rhs.m_pointer;
    m_blok = rhs.m_blok;
    m_blok->m_resource_count++;
}
/* Move-constructs a shared_ptr from r. After the construction, 
   *this contains a copy of the previous state of r, 
   rhs is empty and its stored pointer is null.
*/
template<typename T>
NSTD::shared_ptr<T>::shared_ptr(shared_ptr<T>&& rhs) noexcept
{
    m_pointer = rhs.m_pointer;
    m_blok = rhs.m_blok;
    m_blok->m_resource_count++;
    rhs.m_pointer = nullptr;
    rhs.m_blok = nullptr;
}
/* Destructor */
template<typename T>  
NSTD::shared_ptr<T>::~shared_ptr() noexcept 
{      
    if(m_blok->m_deleter != nullptr)  
    {
        if(m_blok->m_resource_count != 1)
        {
            m_blok->m_resource_count--;
        }
        else
        {
            m_blok->m_deleter(m_pointer);
            delete m_blok;
        }
    }
    else
    {
        __default_delete();

    }
}
/* Operator's */

/* Copy assignment */
template<typename T>
NSTD::shared_ptr<T>& NSTD::shared_ptr<T>::operator=(const shared_ptr<T>& rhs) noexcept
{
    if(this == &rhs)
    {
        return *this;
    }
    m_pointer = rhs.m_pointer;
    m_blok = rhs.m_blok;
    m_blok->m_resource_count++;
    return *this;
}
/* Move assignment */
template<typename T>
NSTD::shared_ptr<T>& NSTD::shared_ptr<T>::operator=(shared_ptr<T>&& rhs) noexcept
{
    m_pointer = rhs.m_pointer;
    m_blok = rhs.m_blok;
    m_blok->m_resource_count++;
    rhs.m_pointer = nullptr;
    rhs.m_blok = nullptr;
    return *this;
}
/* Operator* */
template<typename T>
T& NSTD::shared_ptr<T>::operator*() const noexcept
{
    return *m_pointer;

}
/* Operator-> */
template<typename T>
T* NSTD::shared_ptr<T>::operator->() const noexcept
{
    return m_pointer;

}
/* Operator[] */
template<typename T>
T& NSTD::shared_ptr<T>::operator[](std::size_t index) const
{
    return *m_pointer[index];
}
/* Operator bool */
template<typename T>
NSTD::shared_ptr<T>::operator bool() const noexcept
{
      if (get())
    {
        return true;
    }
    return false;
}
/* Publice functions of sharet_ptr */

/* Get pointer */
template <typename T>
T* NSTD::shared_ptr<T>::get() const noexcept
{
    return this->m_pointer;
}
/* Get count (resource_count) */
template<typename T>
long NSTD::shared_ptr<T>::use_count() const
{

}
/* if resource_count == 1 */
template <typename T>
bool NSTD::shared_ptr<T>::unique() const
{
    if(this->ref_count_->count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Releases ownership of the managed object, if any. */
template<typename T>
void NSTD::shared_ptr<T>::reset() noexcept
{
    if(m_pointer != nullptr)
    {
        m_pointer = nullptr;
        m_blok->m_resource_count--;
        m_blok = nullptr;
    }
}
/* Replaces the managed object with the object pointed to by ptr. */
template<typename T>
void NSTD::shared_ptr<T>::reset(T* ptr) noexcept
{
    if(m_pointer != nullptr)
    {
        m_pointer = nullptr;
        m_blok->m_resource_count--;
        m_blok = nullptr;
    }
    m_pointer = ptr;
    try
    {
        m_blok = new control_blok();
    }
    catch(std::exception& error)
    {
        std::cout << "a exception was caught, with message " << error.what();
    }
    m_blok->m_resource_count++;
}
/* Replaces the managed object with the object pointed to by ptr.And entered deleter */
template<typename T>
void NSTD::shared_ptr<T>::reset(T* ptr, const std::function<void(T*)>& deleter) noexcept
{
    if(m_pointer != nullptr)
    {
        m_pointer = nullptr;
        m_blok->m_resource_count--;
        m_blok = nullptr;
    }
    m_pointer = ptr;
    try
    {
        m_blok = new control_blok(0, deleter);
    }
    catch(std::exception& error)
    {
        std::cout << "a exception was caught, with message " << error.what();

    }
    m_blok->m_resource_count++;

}
/* Private functions of sharet_ptr */

template<typename T>
constexpr void NSTD::shared_ptr<T>::__default_delete() noexcept
{
    delete m_pointer;
    delete m_blok;
    m_pointer = nullptr;
    m_blok = nullptr;
}

