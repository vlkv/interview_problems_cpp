#include "minimal_tree.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>

TEST(MinimalTreeTest, Test1) {
    int data[] = {2, 5, 6, 8, 12, 17, 18, 21, 32, 56};
    // indices:   0  1  2  3  4   5   6   7   8   9    10
	int len = sizeof(data)/sizeof(data[0]);
	auto res = MinimalTree<int>::buildTree(data, 0, len);

    EXPECT_TRUE(res);
    EXPECT_EQ(res->_value, 17);
    EXPECT_EQ(res->_left->_value, 6);
    EXPECT_EQ(res->_right->_value, 32);
    
    int maxLevel = 0;
    auto fun = [&maxLevel](Node<int>* n, int level) mutable -> void {
        if (level > maxLevel) {
            maxLevel = level;
        }
        while (level-- > 0) {
            std::cout << "  ";
        }
        std::cout << std::setw(2) << n->_value << std::endl;
    };
    res->traverseInOrder(fun, 0);

    EXPECT_EQ(maxLevel, 3);
}
