#include "minimal_tree.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(MinimalTreeTest, Test1) {

    std::cout << "Minimal Tree Test";
	int data[] = {2, 5, 6, 8, 12, 17, 18, 21, 32, 56};
	int len = sizeof(data)/sizeof(data[0]);
	auto res = MinimalTree<int>::buildTree(data, 0, len);
    
    EXPECT_TRUE(res);
    EXPECT_EQ(res->_value, 17);
    // TODO: print the tree;
}
