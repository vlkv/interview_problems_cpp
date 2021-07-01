#include "vector.h"
#include <vector>
#include <gtest/gtest.h>

using namespace std;
using namespace My;

TEST(Vector, Test1) {
    vector<int> v = {1, 2, -3, 0};
    ASSERT_EQ(ToStr(v), "[1, 2, -3, 0]");
}

TEST(Vector, Test2) {
    vector<int> v;
    ASSERT_EQ(ToStr(v), "[]");
}
