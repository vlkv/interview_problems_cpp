#include "tree.h"
#include <gtest/gtest.h>
#include <optional>

using namespace My;
using namespace My::Impl;
using namespace std;

TEST(ParseTreeRepr, Test1) {
    auto result = ParseTreeRepr("[1, 2, -3, null, null, 0, 5]");
    vector<optional<int>> expected = {1, 2, -3, nullopt, nullopt, 0, 5};
    ASSERT_EQ(result, expected);
}

TEST(DeserializeSerialize, T1) {
    auto* root = DeserializeTree("[1, 2, -3, null, null, 0, 5]");
    auto repr = SerializeTree(root);
    ASSERT_EQ(repr, "[1, 2, -3, null, null, 0, 5]");
}

TEST(PrintTree, T1) {
    auto* root = DeserializeTree("[1, 2, 3, null, 5, 6]");
    auto repr = PrintTree(root);
    // TODO: Use multiline string literal here:
    auto expected = "(1,\n  (3,\n      (),\n      (6,\n          (),\n          ())),\n  (2,\n      (5,\n          (),\n          ()),\n      ()))";
    ASSERT_EQ(repr, expected);
}