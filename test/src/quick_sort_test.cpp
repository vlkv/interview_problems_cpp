#include "quick_sort.hpp"
#include "vector_util.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(QuickSortTest, Test1) {
    int dataArray[] = {21, 15, 6, 48, 12, 217, 18, 221, 132, 56};
    // indices:         0   1  2   3   4    5   6    7    8   9   10
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test2) {
    int dataArray[] = {21, 15, 6, 48, 12, 217, 18, 221, 132};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test3) {
    int dataArray[] = {21};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], dataArray[0]);
}

TEST(QuickSortTest, Test4) {
    std::vector<int> data;
    QuickSort<int>::sort(data);
    ASSERT_EQ(data.size(), 0);
}

TEST(QuickSortTest, Test5) {
    int dataArray[] = {21, 6};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test6) {
    int dataArray[] = {6, 21};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test7) {
    int dataArray[] = {21, 6, 15};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test8) {
    int dataArray[] = {6, 21, 15};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test9) {
    int dataArray[] = {1, 1};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}

TEST(QuickSortTest, Test10) {
    int dataArray[] = {148, 3, 63, 32, 48, 108, 17, 76, 45, 109, 118};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    std::cout << toStr(data) << std::endl;

    QuickSort<int>::sort(data);
    std::cout << toStr(data) << std::endl;

    for (int i = 0; i < data.size() - 1; ++i) {
        ASSERT_LE(data[i], data[i+1]);
    }
}