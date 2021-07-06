#include "util/tree.h"
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;
using namespace My;

class Solution {
public:
    vector<int> BinTreeBoundary(TreeNode* root) {
        auto lb = LeftBoundary(root);
        vector<int> result;
        if (root->left || root->right) { // if root is not a leaf
            result.push_back(root->val);
        }
        result.insert(result.end(), lb.begin(), lb.end());

        Leaves(root, result);

        auto rb = RightBoundary(root);
        reverse(rb.begin(), rb.end());
        result.insert(result.end(), rb.begin(), rb.end());

        return result;
    }
private:
    vector<int> LeftBoundary(TreeNode* root) {
        if (!root->left) {
            return {};
        }
        vector<int> result;
        const TreeNode* node = root->left;
        while (node && (node->left || node->right)) {
            result.push_back(node->val);
            if (node->left) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return result;
    }

    vector<int> RightBoundary(TreeNode* root) {
        if (!root->right) {
            return {};
        }
        vector<int> result;
        const TreeNode* node = root->right;
        while (node && (node->left || node->right)) {
            result.push_back(node->val);
            if (node->right) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return result;
    }

    void Leaves(TreeNode* node, vector<int>& result) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            result.push_back(node->val);
        }
        Leaves(node->left, result);
        Leaves(node->right, result);
    }
};

TEST(BinTreeBoundary, T1) {
    auto* root = DeserializeTree("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]");
    auto result = Solution().BinTreeBoundary(root);
    vector<int> expected = {1, 2, 4, 8, 9, 10, 11, 12, 13, 14, 15, 7, 3};
    ASSERT_EQ(result, expected);
}

TEST(BinTreeBoundary, T2) {
    auto* root = DeserializeTree("[1, 2, 3, 4, 5, 6, 7, null, 8, 9, 10, null, null, null, null, null, null, null, null, 11, 12]");
    // cout << PrintTree(root) << endl;
    auto result = Solution().BinTreeBoundary(root);
    vector<int> expected = {1, 2, 4, 8, 9, 11, 12, 6, 7, 3};
    ASSERT_EQ(result, expected);
}

TEST(BinTreeBoundary, T3) {
    auto* root = DeserializeTree("[1,null,2,3,4]");
    auto result = Solution().BinTreeBoundary(root);
    vector<int> expected = {1, 3, 4, 2};
    ASSERT_EQ(result, expected);
}

TEST(BinTreeBoundary, T4) {
    auto* root = DeserializeTree("[1]");
    auto result = Solution().BinTreeBoundary(root);
    vector<int> expected = {1};
    ASSERT_EQ(result, expected);
}

TEST(BinTreeBoundary, T5) {
    auto* root = DeserializeTree("[1,2,null,3,null,4]");
    auto result = Solution().BinTreeBoundary(root);
    vector<int> expected = {1, 2, 3, 4};
    ASSERT_EQ(result, expected);
}
