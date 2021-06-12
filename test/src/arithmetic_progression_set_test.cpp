#include "arithmetic_progression_set.h"
#include <gtest/gtest.h>

TEST(ArithmeticProgressionSet, Test1) {
    Solution s(4, 5);
    s.insert(2);
    s.insert(7);
    s.insert(12);
    EXPECT_FALSE(s.containsArithProgression());
    s.insert(17);
    EXPECT_TRUE(s.containsArithProgression());
}

TEST(ArithmeticProgressionSet, Test2) {
    Solution s(4, 5);
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(12);
    EXPECT_FALSE(s.containsArithProgression());
    s.insert(17);
    EXPECT_TRUE(s.containsArithProgression());
}

TEST(ArithmeticProgressionSet, Test3) {
    Solution s(4, 5);
    s.insert(2);
    s.insert(7);
    s.insert(12);
    s.insert(17);
    EXPECT_TRUE(s.containsArithProgression());
    s.insert(22);
    EXPECT_TRUE(s.containsArithProgression());
    s.remove(2);
    EXPECT_TRUE(s.containsArithProgression());
    s.remove(7);
    EXPECT_FALSE(s.containsArithProgression());
}

TEST(ArithmeticProgressionSet, Test4) {
    Solution s(4, 5);
    s.insert(2);
    s.insert(2);
    s.insert(7);
    s.insert(12);
    s.insert(17);
    EXPECT_TRUE(s.containsArithProgression());
    s.remove(2);
    EXPECT_TRUE(s.containsArithProgression());
    s.remove(2);
    EXPECT_FALSE(s.containsArithProgression());
}
