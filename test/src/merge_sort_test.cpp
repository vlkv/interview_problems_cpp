#include "merge_sort.hpp"
#include "util/vector.h"
#include <iostream>
#include <gtest/gtest.h>

using namespace My;

TEST(MergeSortTest, Test1) {
    int dataArray[] = {21, 15, 6, 48, 12, 217, 18, 221, 132, 56};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::cout << "dataArray len = " << len << std::endl;
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    ToStr(data);

    MergeSort<int>::sort(data);
    ToStr(data);

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(MergeSortTest, Test2) {
    int dataArray[] = {21, 15, 6, 48, 12, 217, 18, 221, 132};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::cout << "dataArray len = " << len << std::endl;
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    ToStr(data);

    MergeSort<int>::sort(data);
    ToStr(data);

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(MergeSortTest, Test3) {
    int dataArray[] = {21};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << ToStr(data);

    MergeSort<int>::sort(data);
    std::cout << ToStr(data);

    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], dataArray[0]);
}

TEST(MergeSortTest, Test4) {
    std::vector<int> data;
    MergeSort<int>::sort(data);
    ASSERT_EQ(data.size(), 0);
}
