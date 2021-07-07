#include <queue>
#include <gtest/gtest.h>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap; // holds greater nums
    priority_queue<int> maxHeap; // holds lesser nums
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        minHeap.push(num);

        auto num2 = minHeap.top();

        // Optimization: maybe we do not need to pass num2 to the maxHeap
        if (minHeap.size() - maxHeap.size() <= 1 && (maxHeap.empty() || num2 >= maxHeap.top())) {
            return;
        }

        minHeap.pop();

        maxHeap.push(num2);

        if (maxHeap.size() - minHeap.size() > 1) {
            auto num3 = maxHeap.top();
            maxHeap.pop();
            minHeap.push(num3);
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

TEST(MedianFinder, T1) {
    MedianFinder mf;
    mf.addNum(-1);
    ASSERT_EQ(mf.findMedian(), -1);

    mf.addNum(-2);
    ASSERT_EQ(mf.findMedian(), -1.5);

    mf.addNum(-3);
    ASSERT_EQ(mf.findMedian(), -2);

    mf.addNum(-4);
    ASSERT_EQ(mf.findMedian(), -2.5);

    mf.addNum(-5);
    ASSERT_EQ(mf.findMedian(), -3);
}

TEST(MedianFinder, T2) {
    MedianFinder mf;
    mf.addNum(1);
    ASSERT_EQ(mf.findMedian(), 1);

    mf.addNum(2);
    ASSERT_EQ(mf.findMedian(), 1.5);

    mf.addNum(3);
    ASSERT_EQ(mf.findMedian(), 2);

    mf.addNum(4);
    ASSERT_EQ(mf.findMedian(), 2.5);

    mf.addNum(5);
    ASSERT_EQ(mf.findMedian(), 3);
}