#include "string.h"
#include <string>
#include <gtest/gtest.h>

using namespace std;
using namespace My;

TEST(StdString, Test1) {
    string s;
    ASSERT_EQ(s.substr(0, 0), "");
}

TEST(Split, Test1) {
    vector<string> expected = {"[1", " 2", " 3]"};
    ASSERT_EQ(Split("[1, 2, 3]", ','), expected);
}

TEST(Split, Test2) {
    vector<string> expected = {"[1, 2, 3]"};
    ASSERT_EQ(Split("[1, 2, 3]", '.'), expected);
}

TEST(Split, Test3) {
    vector<string> expected = {""};
    ASSERT_EQ(Split("", ','), expected);
}


TEST(Trim, Test1) {
    ASSERT_EQ(Trim(" abc  def   "), "abc  def");
}

TEST(Trim, Test2) {
    ASSERT_EQ(Trim("abc  def"), "abc  def");
}

TEST(Trim, Test3) {
    ASSERT_EQ(Trim(""), "");
}

TEST(Trim, Test4) {
    ASSERT_EQ(Trim(" "), "");
}

TEST(Trim, Test5) {
    ASSERT_EQ(Trim("  "), "");
}

TEST(Trim, Test6) {
    ASSERT_EQ(Trim("[1, 2, 3]", {'[', ']'}), "1, 2, 3");
}
