#include <gtest/gtest.h>
using namespace std;

class Solution {
    const vector<vector<bool>> graph;
public:
    Solution(const vector<vector<bool>>& graph)
        : graph(graph) {
    }

    int solve() {
        for (int i = 0; i < graph.size(); ++i) {
            // if i is a celebrity, then for all j
            // knows(i, j) must be false
            // knows(j, i) must be true
            bool isCeleb = true;
            for (int j = 0; j < graph.size(); ++j) {
                if (i == j) continue;
                if (knows(i, j)) { // i is not a celebrity because i knows j
                    isCeleb = false;
                    break;
                    // We will check the next i
                }
                if (!knows(j, i)) { // i is not a celebrity because j doesn't know i
                    isCeleb = false;
                    i = max(i, j); // but j could be a celebrity... BUT: Avoid cycle
                    break;
                }
            }
            if (isCeleb) {
                return i;
            }
        }

        return -1;
    }

private:
    bool knows(int a, int b) {
        return graph[a][b];
    }
};

TEST(FindTheCelebrity, T1) {
    Solution s({
//       0  1  2  3  4  5
        {1, 1, 1, 0, 0, 0}, // 0
        {0, 1, 1, 1, 0, 0}, // 1
        {0, 0, 1, 0, 0, 0}, // 2
        {0, 0, 1, 1, 0, 0}, // 3
        {1, 0, 1, 0, 1, 0}, // 4
        {0, 0, 1, 0, 1, 1}, // 5
    });
    ASSERT_EQ(s.solve(), 2);
}

TEST(FindTheCelebrity, T2) {
    Solution s({
//       0  1  2  3  4  5
        {1, 1, 1, 0, 0, 0}, // 0
        {0, 1, 1, 1, 0, 0}, // 1
        {0, 0, 1, 0, 0, 0}, // 2
        {0, 0, 1, 1, 0, 0}, // 3
        {1, 0, 0, 0, 1, 0}, // 4
        {0, 0, 1, 0, 1, 1}, // 5
    });
    ASSERT_EQ(s.solve(), -1);
}

TEST(FindTheCelebrity, T3) {
    Solution s({
        {1,1,1},
        {1,1,0},
        {0,0,1},
    });
    ASSERT_EQ(s.solve(), -1);
}