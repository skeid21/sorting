
template <typename RANDOM_ACCESS_ITR>
void insertionSort(RANDOM_ACCESS_ITR _first, RANDOM_ACCESS_ITR _last)
{
    if (_first == _last) 
    {
        return;
    }

    for (auto marker = _first + 1; marker != _last; ++marker)
    {
        auto current = marker;
        auto previous = marker - 1;
        while (current != _first && *previous > *current)
        {
            auto temp = *previous;
            *previous = *current;
            *current = temp;
            --current;
            --previous;
        }
    }
}