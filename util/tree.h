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
        : val(val)
        , left(nullptr)
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

std::string SerializeTree(const TreeNode* root) {
    std::vector<std::string> data;
    std::queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto* node = q.front();
        q.pop();
        if (node) {
            data.push_back(std::to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            data.push_back("null");
        }
    }
    // Remove trailing nulls
    for (int i = data.size() - 1; i >= 0; --i) {
        if (data[i] == "null") {
            data.erase(data.begin() + i);
        } else {
            break;
        }
    }
    return '[' + Join(data, ", ") + ']';
}

std::string PrintTree(const TreeNode* node, int level = 0) {
    std::string padding;
    for (int i = 0; i < level; ++i) {
        padding += "  ";
    }
    std::string result = padding + "(";
    if (node) {
        result += std::to_string(node->val) + ",\n";
        result += padding + PrintTree(node->right, level + 1) + ",\n";
        result += padding + PrintTree(node->left, level + 1);
    }
    return result + ")";
}

} // namespace My
