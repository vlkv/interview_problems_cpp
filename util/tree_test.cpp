#include "tree.h"
#include <gtest/gtest.h>
#include <optional>

using namespace My::Impl;
using namespace std;

TEST(ParseTreeRepr, Test1) {
    auto result = ParseTreeRepr("[1, 2, -3, null, null, 0, 5]");
    vector<optional<int>> expected = {1, 2, -3, nullopt, nullopt, 0, 5};
    ASSERT_EQ(result, expected);
}