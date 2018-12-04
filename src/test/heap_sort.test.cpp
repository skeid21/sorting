#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "../heap_sort.h"

static bool isSorted(std::vector<int> &vector)
{
    bool sorted = true;
    for (int scan = 0; scan < vector.size(); ++scan)
    {
        // std::cout << scan << ":" << vector[scan] << std::endl;
        auto nextScan = scan + 1;
        if (nextScan < vector.size())
        {
            if (vector[scan] > vector[nextScan])
            {
                sorted = false;
            }
        }
    }

    return sorted;
}

TEST(HeapSort, SortedListIsSorted)
{
    auto testVector = std::vector<int>{1, 2, 3, 4, 5, 6};
    heapSort(testVector.begin(), testVector.end());
    sort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(HeapSort, SortsEmptyVector)
{
    auto testVector = std::vector<int>();
    heapSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(HeapSort, SortsBackwardSortedList)
{
    auto testVector = std::vector<int>{6, 5, 4, 3, 2, 1};
    heapSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(HeapSort, SortsSortsOne)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 1; ++scan)
    {
        testVector.push_back(std::rand());
    }
    heapSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(HeapSort, SortsSortsTwo)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 2; ++scan)
    {
        testVector.push_back(std::rand());
    }
    heapSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}
TEST(HeapSort, SortsSortsAFew)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 13; ++scan)
    {
        testVector.push_back(std::rand());
    }
    heapSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(HeapSort, SortsSortsMany)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 1000; ++scan)
    {
        testVector.push_back(std::rand()%200);
    }
    heapSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}