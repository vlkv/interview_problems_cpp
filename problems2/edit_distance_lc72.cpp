#include <string>
#include <unordered_set>
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    struct Item {
        string word;
        int count;
    };
public:
    /* Edit `source` word to `target`, transforming it with one of three operations:
        - remove a letter
        - insert a letter
        - replace a letter
    Return minimun number of operations needed. */
    int Solve(const string& source, const string& target) {
        unordered_set<string> visited;
        queue<Item> q;
        q.push({source, 0});
        while (!q.empty()) {
            auto item = q.front();
            q.pop();
            if (visited.count(item.word) > 0) {
                continue;
            }
            visited.insert(item.word);
            if (item.word == target) {
                return item.count;
            }

            for (const auto mut : MakeMutations(item.word, target)) {
                if (visited.count(mut) > 0) {
                    continue;
                }
                q.push({mut, item.count + 1});
            }
        }
        return 0;
    }
private:
    vector<string> MakeMutations(string word, const string& target) {
        vector<string> result;
        // replace a letter
        for (int i = 0; i < word.length(); ++i) {
            auto ch = word[i];
            for (int j = 0; j < target.length(); ++j) {
                word[i] = target.at(j);
                result.push_back(word);
            }
            word[i] = ch;
        }

        // TODO: insert a letter

        // TODO: remove a letter
        return result;
    }
};

TEST(EditWords, T0) {
    ASSERT_EQ(Solution().Solve("horse", "apple"), 4);
}

TEST(EditWords, T1) {
    ASSERT_EQ(Solution().Solve("horse", "ros"), 3);
}

TEST(EditWords, T2) {
    ASSERT_EQ(Solution().Solve("intention", "execution"), 5);
}
