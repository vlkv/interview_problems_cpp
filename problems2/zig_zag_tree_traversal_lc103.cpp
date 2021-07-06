#include "util/tree.h"
#include <gtest/gtest.h>
#include <string>
#include <stack>

using namespace std;
using namespace My;

class Solution {
    struct Item {
        const TreeNode* node;
        int level;
    };
    using Stack = stack<Item>;
public:
    vector<int> solve(const TreeNode* root) const {
        vector<int> result;
        Stack s1;
        Stack s2;
        Stack* curr = &s1;
        Stack* next = &s2;
        curr->push({root, 1});
        while (true) {
            while (!curr->empty()) {
                auto item = curr->top();
                curr->pop();
                if (!item.node) {
                    continue;
                }
                result.push_back(item.node->val);
                if (item.level % 2 == 1) {
                    next->push({item.node->left, item.level + 1});
                    next->push({item.node->right, item.level + 1});
                } else {
                    next->push({item.node->right, item.level + 1});
                    next->push({item.node->left, item.level + 1});
                }
            }
            if (next->empty()) {
                break;
            }
            swap(curr, next);
        }
        return result;
    }
};

TEST(ZigZagTreeTraversal, T1) {
    auto* root = DeserializeTree("[1, 2, 3, null, null, 4, 5]");
    auto expected = vector<int>{1, 3, 2, 4, 5};
    ASSERT_EQ(Solution().solve(root), expected);
}

TEST(ZigZagTreeTraversal, T2) {
    /*
                   1                    // -->
         2                 3            // <--
  4             5        6    7         // -->
8   9        10                         // <--
     */
    auto* root = DeserializeTree("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]");
    auto expected = vector<int>{1, 3, 2, 4, 5, 6, 7, 10, 9, 8};
    ASSERT_EQ(Solution().solve(root), expected);
}
