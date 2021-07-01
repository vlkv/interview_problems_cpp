#pragma once
#include "string.h"
#include <vector>
#include <queue>
#include <optional>
#include <string>

namespace My {

struct TreeNode;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
        : left(nullptr)
        , right(nullptr) {
    }
};

namespace Impl {

TreeNode* DeserializeTree(const std::vector<std::optional<int>>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    int i = 0;
    TreeNode* root = new TreeNode(vals[i++].value());
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (i == vals.size()) break;
        auto left = vals[i++];
        if (left.has_value()) {
            node->left = new TreeNode(left.value());
            q.push(node->left);
        }

        if (i == vals.size()) break;
        auto right = vals[i++];
        if (right.has_value()) {
            node->right = new TreeNode(right.value());
            q.push(node->right);
        }
    }
    return root;
}

std::vector<std::optional<int>> ParseTreeRepr(const std::string& vals) {
    std::vector<std::optional<int>> result;
    auto splittedVals = Split(Trim(vals, {'[', ']'}), ',');
    for (const auto& val : splittedVals) {
        auto valTrimmed = Trim(val);
        if (valTrimmed == "null") {
            result.push_back(std::nullopt);
        } else {
            result.push_back(stoi(valTrimmed));
        }
    }
    return result;
}

} // namespace Impl

/* vals = [1, 2, 3, null, null, 4, 5]
tree is
             1
        2         3
                4   5
*/
TreeNode* DeserializeTree(const std::string& vals) {
    auto repr = Impl::ParseTreeRepr(vals);
    return Impl::DeserializeTree(repr);
}

} // namespace My
