#include <algorithm>
#include <iostream>
#include <cmath>

template <typename RANDOM_ACCESS_ITR>
void maintainHeap(
    const RANDOM_ACCESS_ITR _first,
    const RANDOM_ACCESS_ITR _last,
    const RANDOM_ACCESS_ITR _current)
{
    auto index = ((_current - _first) * 2) + 1;
    auto left = _first + index;
    auto right = _first + (index + 1);
    auto largest = _current;
    if (left < _last && *left > *largest)
    {
        largest = left;
    }   

    if (right < _last && *right > *largest)
    {
        largest = right;
    }

    if (largest != _current) 
    {
        std::swap(*largest, *_current);
        maintainHeap(_first, _last, largest);
    }
}

template <typename RANDOM_ACCESS_ITR>
void makeHeap(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last)
{
    int halfIndex = (int)std::floor((float)(_last - _first) / 2.f);
    halfIndex -= 1;
    for (auto itr = _last - 1; itr >= _first; itr--)
    {
        maintainHeap(_first, _last, itr);
    }
    
}

template <typename RANDOM_ACCESS_ITR>
void heapSort(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last)
{
    if (_first == _last)
    {
        return;
    }

    makeHeap(_first, _last);
    for (auto itr = _last - 1; itr != _first; --itr)
    {
        std::swap(*_first, *itr);
        maintainHeap(_first, itr, _first);
    }
}