#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    // hour is in range [1, 12]
    // minute is in range [0, 59]
    // returns minimal angle between hour and minute hands of a clock
    double Solve(int hour, int minute) {
        // 12 hours - 360 degrees
        // 3 hours - 90
        // 6 hours - 180
        // 9 hours - 270
        double hoursRough = (hour % 12) / 12.0 * 360;
        double hoursCorrection = minute / 60.0 * 30; // 30 = 360 / 12
        auto hours = hoursRough + hoursCorrection;

        // 0 minutes - 0 degress
        // 30 minutes - 180
        // 45 minutes - 270
        // ...
        double minutes = minute / 60.0 * 360;

        auto smaller = min(hours, minutes);
        auto bigger = max(hours, minutes);

        return min(bigger - smaller, smaller + 360 - bigger);
    }
};

TEST(AngleBetweenHandsOfClock, T1) {
    ASSERT_EQ(Solution().Solve(12, 0), 0);
}

TEST(AngleBetweenHandsOfClock, T2) {
    ASSERT_EQ(Solution().Solve(12, 15), 82.5);
}

TEST(AngleBetweenHandsOfClock, T3) {
    ASSERT_EQ(Solution().Solve(12,  30), 165);
}
