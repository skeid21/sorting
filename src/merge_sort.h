#include <vector>
#include <algorithm>
#include <iterator>

template <typename RANDOM_ACCESS_ITR>
void mergeSort(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last)
{
    using value_type = typename std::iterator_traits<RANDOM_ACCESS_ITR>::value_type;

    if (_first == _last || _first + 1 == _last)
    {
        return;
    }
    const auto count = _last - _first;
    const auto halfCount = count / 2;
    auto mid = _first + halfCount;
    mergeSort(_first, mid);
    mergeSort(mid, _last);

    std::vector<value_type> mergedVector;
    mergedVector.reserve(count);
    auto lhvCurrent = _first;
    auto rhvCurrent = mid;
    while (lhvCurrent != mid && rhvCurrent != _last)
    {
        if (*lhvCurrent < *rhvCurrent)
        {
            mergedVector.push_back(*lhvCurrent);
            lhvCurrent++;
        }
        else
        {
            mergedVector.push_back(*rhvCurrent);
            rhvCurrent++;
        }
    }
    if (lhvCurrent != mid)
    {
        mergedVector.insert(mergedVector.end(), lhvCurrent, mid);
    }
    else if (rhvCurrent != _last)
    {
        mergedVector.insert(mergedVector.end(), rhvCurrent, _last);
    }
    std::copy(mergedVector.begin(), mergedVector.end(), _first);
}