template <typename RANDOM_ACCESS_ITR>
RANDOM_ACCESS_ITR partition(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last)
{
    auto pivot = _last;
    auto low = _first;
    for (auto current = _first; current != _last; ++current)
    {
        if (*current < *pivot)
        {
            if (current != low)
            {
                std::swap(*current, *low);
            }
            low++;
        }
    }
    if (low != _last)
    {
        std::swap(*low,*_last);
    }

    return low;
}

template <typename RANDOM_ACCESS_ITR>
void _quickSort(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last)
{
    if (_first >= _last)
    {
        return;
    }
    auto itr = partition(_first, _last);
    _quickSort(_first, itr-1);
    _quickSort(itr+1, _last);
}

template <typename RANDOM_ACCESS_ITR>
void quickSort(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last){
    if (_first == _last){
        return;
    }
    _quickSort(_first, _last-1);
}