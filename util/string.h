#pragma once
#include <string>
#include <unordered_set>
#include <vector>

namespace My {

std::vector<std::string> Split(const std::string& str, char ch) {
    if (str.empty())  {
        return {str};
    }
    std::vector<std::string> result;
    size_t i = 0;
    while (i < str.length()) {
        auto j = str.find(ch, i);
        if (j != std::string::npos) {
            result.push_back(str.substr(i, j - i));
        } else {
            result.push_back(str.substr(i, str.length() - i));
            break;
        }
        i = j + 1;
    }
    return result;
}

std::string Trim(const std::string& str, std::unordered_set<char> chs={' '}) {
    if (str.empty()) {
        return str;
    }
    auto i = 0;
    while (i < str.length() && chs.count(str[i]) > 0) {
        ++i;
    }

    auto j = static_cast<int>(str.length()) - 1;
    while (j >= 0 && chs.count(str[j]) > 0) {
        --j;
    }

    if (i == str.length()) {
        return {};
    }
    return str.substr(i, j - i + 1);
}

std::string Join(const std::vector<std::string>& strs, std::string seq) {
    std::string result;
    for (int i = 0; i < strs.size(); ++i) {
        result += strs.at(i);
        if (i < strs.size() - 1) {
            result += seq;
        }
    }
    return result;
}

} // namespace My
