#ifndef _ADVANCE_
#define _ADVANCE_

#include <type_traits>

namespace detail
{
    template <typename It>
    constexpr void do_advance(It &, typename std::iterator_traits<It>::difference_type, std::input_iterator_tag);

    template <class It>
    constexpr void do_advance(It &, typename std::iterator_traits<It>::difference_type, std::bidirectional_iterator_tag);

    template <typename It>
    constexpr void do_advance(It &, typename std::iterator_traits<It>::difference_type, std::random_access_iterator_tag);
}   

namespace nonstd
{
    template <typename It, typename Distance>
    constexpr void advance(It &, Distance);
}

#include "advance.cpp"

#endif //_ADVANCE_