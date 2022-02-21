template <typename It>
constexpr void detail::do_advance(It &it, typename std::iterator_traits<It>::difference_type n,  std::input_iterator_tag)
{
    while (n > 0)
    {
        --n;
        ++it;
    }
}

template <class It>
constexpr void detail::do_advance(It &it, typename std::iterator_traits<It>::difference_type n, std::bidirectional_iterator_tag)
{
    while (n > 0)
    {
        --n;
        ++it;
    }
    while (n < 0)
    {
        ++n;
        --it;
    }
}

template <typename It>
constexpr void detail::do_advance(It & it, typename std::iterator_traits<It>::difference_type n, std::random_access_iterator_tag)
{
    it += n;
}

template <typename It, typename Distance>
constexpr void nonstd::advance(It & it, Distance n)
{
    detail::do_advance(it, typename std::iterator_traits<It>::difference_type(n),  typename std::iterator_traits<It>::iterator_category());
}