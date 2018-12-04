#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "../insertion_sort.h"

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

TEST(InsertionSort, SortedListIsSorted)
{
    auto testVector = std::vector<int>{1, 2, 3, 4, 5, 6};
    insertionSort(testVector.begin(), testVector.end());
    sort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(InsertionSort, SortsEmptyVector)
{
    auto testVector = std::vector<int>();
    insertionSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(InsertionSort, SortsBackwardSortedList)
{
    auto testVector = std::vector<int>{6, 5, 4, 3, 2, 1};
    insertionSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(InsertionSort, SortsSortsOne)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 1; ++scan)
    {
        testVector.push_back(std::rand());
    }
    insertionSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(InsertionSort, SortsSortsTwo)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 2; ++scan)
    {
        testVector.push_back(std::rand());
    }
    insertionSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(InsertionSort, SortsSortsAFew)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 13; ++scan)
    {
        testVector.push_back(std::rand());
    }
    insertionSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}

TEST(InsertionSort, SortsSortsMany)
{
    auto testVector = std::vector<int>();
    for (size_t scan = 0; scan < 1000; ++scan)
    {
        testVector.push_back(std::rand()%200);
    }
    insertionSort(testVector.begin(), testVector.end());
    ASSERT_TRUE(isSorted(testVector));
}
