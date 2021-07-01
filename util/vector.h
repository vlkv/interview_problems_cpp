#pragma once
#include <vector>
#include <sstream>
#include <string>

namespace My {

template <class T>
static std::string ToStr(const std::vector<T>& v, std::size_t beg, std::size_t end) {
    std::ostringstream res;
    res << "[";
    for (int i = beg; i < end; ++i) {
        res << v[i];
        if (i < end - 1) {
            res << ", ";
        }
    }
    res << "]";
    return res.str();
}

template <class T>
static std::string ToStr(const std::vector<T>& v) {
    return ToStr(v, 0, v.size());
}

} // namespace My
