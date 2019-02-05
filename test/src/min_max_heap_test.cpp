#include "min_max_heap.hpp"
#include "vector_util.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <optional>

TEST(MinMaxHeapTest, Test1) {
    int dataArray[] = {21, 12, 6, 48, 12, 217, 18, 221, 132, 56};
    int len = sizeof(dataArray)/sizeof(dataArray[0]);
    std::cout << "dataArray len = " << len << std::endl;
    std::vector<int> data(&dataArray[0], &dataArray[len]);
    toStr(data);

    MinMaxHeap<int> heap;
    for (int i = 0; i < data.size(); ++i) {
        heap.add(data[i]);
    }
    
    std::optional<int> prev;
    while (heap.size() > 0) {
        int curr = heap.pop();
        std::cout << curr << std::endl;
        if (prev.has_value()) {
            ASSERT_GE(prev.value(), curr);
        }
        
        prev = curr;
    }
}