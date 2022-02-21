#ifndef _DISTANCE_
#define _DISTANCE_

#include <type_traits>

namespace detail
{
    template <typename It>
    constexpr typename std::iterator_traits<It>::difference_type do_distance(It, It, std::input_iterator_tag);

    template <typename It>
    constexpr typename std::iterator_traits<It>::difference_type do_distance(It, It, std::random_access_iterator_tag);
}

namespace nonstd
{
    template <class It>
    constexpr typename std::iterator_traits<It>::difference_type distance(It, It);
}

#include "distance.cpp"

#endif //_DISTANCE_