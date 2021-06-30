#include <gtest/gtest.h>
#include <string>

using namespace std;

void CompactSpaces(string& s) {
    auto i = s.begin();
    while (i != s.end()) {
        // find the begining of the next word
        auto j = i;
        while (j != s.end() && *j == ' ') {
            ++j;
        }
        // find the length of the word
        auto k = j;
        while (k != s.end() && isalnum(*k)) {
            ++k;
        }
        auto len = k - j;

        if (i != j) { // move word from j to i
            auto iter = len;
            while (iter > 0) {
                *i = *j;
                *j = ' ';
                ++i;
                ++j;
                --iter;
            }
        } else { // skip to the end of the current word
            i += len;
        }
        if (i != s.end()) { // NOTE: It's UB to increment end() iterator!!!
            ++i; // leave one space
        }
    }
}

void Reverse(string& s, string::iterator i, size_t count) {
    auto j = i + count - 1;
    while (i < j) {
        swap(*i, *j);
        ++i;
        --j;
    }
}

void ReverseWordsLetters(string& s) {
    auto i = s.begin();
    while (i != s.end()) {
        while (i != s.end() && *i == ' ') { // find the begining of the next word
            ++i;
        }
        auto j = i;
        while (j != s.end() && isalnum(*j)) { // skip to the end of the word
            ++j;
        }

        Reverse(s, i, j - i);
        i = j; // skip the reversed word
    }
}

void TrimTrailingSpace(string& s) {
    auto i = s.rbegin();
    while (i != s.rend() && *i == ' ') {
        ++i;
    }
    auto trailingSpacesCount = i - s.rbegin();
    s.resize(s.length() - trailingSpacesCount);
}

// https://leetcode.com/problems/reverse-words-in-a-string/
void ReverseWords(string& s) {
    ReverseWordsLetters(s);
    Reverse(s, s.begin(), s.length()); // the whole string
    CompactSpaces(s);
    TrimTrailingSpace(s);
}

TEST(TestCase, Test0) {
    string s("  Bob  likes Alice   much   ");
    ReverseWords(s);
    ASSERT_EQ(s, "much Alice likes Bob");
}

TEST(TestCase, Test1) {
    string s("Bob likes Alice");
    ReverseWords(s);
    ASSERT_EQ(s, "Alice likes Bob");
}

TEST(TestCase, Test2) {
    string s("Bob likes Alice much");
    ReverseWords(s);
    ASSERT_EQ(s, "much Alice likes Bob");
}

TEST(TestCase, Test3) {
    string s("A quick red fox jumps over the lazy dog.");
    ReverseWords(s);
    ASSERT_EQ(s, "dog. lazy the over jumps fox red quick A");
}
