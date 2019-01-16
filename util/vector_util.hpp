#ifndef VECTOR_UTIL_HPP__
#define VECTOR_UTIL_HPP__

#include <sstream>
#include <string>

template <class T>
static std::string toStr(const std::vector<T>& v, std::size_t beg, std::size_t end) {
    std::ostringstream res;
    res << "[";
    for (int i = beg; i < end; ++i) {
        res << v[i];
        if (i < end - 1) {
            res << ", ";
        }
    }
    res << "]" << std::endl;
    return res.str();
}

template <class T>
static std::string toStr(const std::vector<T>& v) {
    return toStr(v, 0, v.size());
}

#endif
