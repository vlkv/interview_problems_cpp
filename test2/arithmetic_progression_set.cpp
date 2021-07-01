#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

class Solution {
    int len;
    int diff;
    unordered_multiset<int> nums;
    unordered_set<int> progStarts;
public:
    Solution(int len, int diff)
        : len(len)
        , diff(diff)
    {}

    // Insertion of one number x, may produce at most len arithmetic progressions. Suppose for len=3, diff=2
    // nums=[1, 3, 7, 9]. We have no arith progssions. We insert 5, we get:
    // nums=[1, 3, 5, 7, 9]. Now we have 3 progressions: [1, 3, 5], [3, 5, 7], [5, 7, 9].
    // Another point: arith progression could be mixed with some other numbers, for example this:
    // nums=[1, 2, 3, 5] are still hold valid arith progression with len = 3 and diff = 2. The number 2 is OK.
    void insert(int x) {
        nums.insert(x);
        auto xMin = x - (len - 1) * diff;
        auto xMax = x + (len - 1) * diff;

        auto xLeft = x;
        auto i = x;
        while (i >= xMin) {
            auto it = nums.find(i);
            if (it == nums.end()) {
                break;
            }
            xLeft = *it;
            i -= diff;
        }

        auto xRight = x;
        i = x;
        while (i <= xMax) {
            auto it = nums.find(i);
            if (it == nums.end()) {
                break;
            }
            xRight = *it;
            i += diff;
        }

        while (xLeft + (len - 1) * diff <= xRight) {
            progStarts.insert(xLeft);
            xLeft += diff;
        }
    }

    // Removing one number x, we may break at most len arith progresions.d
    // Suppose we had: nums=[1, 3, 5, 7, 9] and we remove 5
    // This breaks progressions wich start from 1, 3 and 5 correspondingly
    // Another point: there could be duplicates of x in nums.
    void remove(int x) {
        if (auto xt = nums.find(x); xt != nums.end()) {
            nums.erase(xt);
        }
        if (nums.count(x) > 0) {
            return; // Then, we did not break any progressions
        }
        // Find out, what progressions we could break, and forget about them
        auto i = x - (len - 1) * diff;
        while (i <= x) {
            if (auto it = progStarts.find(i); it != progStarts.end()) {
                progStarts.erase(it);
            }
            i += diff;
        }
    }

    bool containsArithProgression() {
        return !progStarts.empty();
    }
};

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
