template <typename It>
constexpr typename std::iterator_traits<It>::difference_type detail::do_distance(It first, It last, std::input_iterator_tag)
{
    typename std::iterator_traits<It>::difference_type result = 0;

    while (first != last)
    {
        ++first;
        ++result;
    }

    return result;
}

template <typename It>
constexpr typename std::iterator_traits<It>::difference_type detail::do_distance(It first, It last, std::random_access_iterator_tag)
{
    return last - first;
}

template <class It>
constexpr typename std::iterator_traits<It>::difference_type nonstd::distance(It first, It last)
{
    return detail::do_distance(first, last, typename std::iterator_traits<It>::iterator_category());
}