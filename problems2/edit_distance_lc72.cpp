#include <string>
#include <unordered_set>
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    /*
    dist[i][j] - is a min distance for transforming word1 subrange [0, i] to word2 subrange [0, j];
      r o s
    h
    o
    r
    s
    e
    */
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.length();
        if (word2.empty()) return word1.length();
        // ATTENTION: Need one more row and one more col for the empty strings cases...
        vector<vector<int>> dist(word1.length() + 1, vector<int>(word2.length() + 1, numeric_limits<int>::max()));

        for (int i = 0; i <= word1.length(); ++i) {
            dist[i][0] = i;
        }
        for (int j = 0; j <= word2.length(); ++j) {
            dist[0][j] = j;
        }

        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                auto minDist = numeric_limits<int>::max();
                minDist = min(minDist, dist[i - 1][j]);
                minDist = min(minDist, dist[i][j - 1]);
                if (word1[i - 1] == word2[j - 1]) {
                    minDist = min(minDist, dist[i - 1][j - 1] - 1); // ATTENTION here to `- 1` thing!
                } else {
                    minDist = min(minDist, dist[i - 1][j - 1]);
                }
                dist[i][j] = 1 + minDist;
            }
        }
        print(dist);
        return dist[word1.length()][word2.length()];
    }
private:
    void print(vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                cout << v[i][j] << ", ";
            }
            cout << endl;
        }

    }
};

TEST(EditWords, T0) {
    ASSERT_EQ(Solution().minDistance("horse", "apple"), 4);
}

TEST(EditWords, T1) {
    ASSERT_EQ(Solution().minDistance("horse", "ros"), 3);
}

TEST(EditWords, T2) {
    ASSERT_EQ(Solution().minDistance("intention", "execution"), 5);
}

TEST(EditWords, T3) {
    ASSERT_EQ(Solution().minDistance("a", "b"), 1);
}

TEST(EditWords, T4) {
    ASSERT_EQ(Solution().minDistance("", ""), 0);
}

TEST(EditWords, T5) {
    ASSERT_EQ(Solution().minDistance("", "a"), 1);
}

TEST(EditWords, T6) {
    ASSERT_EQ(Solution().minDistance("a", ""), 1);
}
