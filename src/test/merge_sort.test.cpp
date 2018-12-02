#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "../merge_sort.h"

static bool isSorted(std::vector<int>& vector)
{
    bool sorted = true;
    for(int scan = 0; scan < vector.size(); ++scan)
    {
        auto nextScan = scan + 1;
        if (nextScan < vector.size())
        {
            if(vector[scan] > vector[nextScan]) 
            {
                std::cout << vector[scan] << std::endl;
                sorted = false;
            }
        }
    }

    return sorted;
}

TEST(MergeSort, SortedListIsSorted)
{
    auto testVector = std::vector<int>{1, 2, 3, 4, 5, 6};
    mergeSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(MergeSort, SortsEmptyVector)
{
    auto testVector = std::vector<int>();
    mergeSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(MergeSort, SortsBackwardSortedList)
{
    auto testVector = std::vector<int>{6, 5, 4, 3, 2, 1};
    mergeSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(MergeSort, SortsSortsRandomList)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 100; ++scan)
    {
        testVector.push_back(std::rand());
    }
    mergeSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}
