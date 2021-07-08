#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isLineOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) &&
               isLineOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }

private:
    bool isLineOverlap(int beg1, int end1, int beg2, int end2) {
        // We want begX to be less or equal to endX
        if (beg1 > end1) {
            swap(beg1, end1);
        }

        if (beg2 > end2) {
            swap(beg2, end2);
        }

        // We want the first line to start first
        if (beg1 > beg2) {
            swap(beg1, beg2);
            swap(end1, end2);
        }

        return beg2 < end1;
    }
};

TEST(IsRectangleOverlap, T1) {
    Solution s;
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), true);
}

TEST(IsRectangleOverlap, T2) {
    Solution s;
    vector<int> rec1 = {0, 0, 1, 1};
    vector<int> rec2 = {1, 0, 2, 1};
    ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
}

TEST(IsRectangleOverlap, T3) {
    Solution s;
    vector<int> rec1 = {0, 0, 1, 1};
    vector<int> rec2 = {2, 2, 3, 3};
    ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
}
