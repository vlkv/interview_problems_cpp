#ifndef MERGE_SORT_HPP__
#define MERGE_SORT_HPP__

#include <vector>
#include <iostream>

template<class T>
class MergeSort {
public:
    static void sort(std::vector<T>& array) {
        std::vector<T> helper(array.size());
        sort(array, helper, 0, array.size());
    }

private:
    static void sort(std::vector<T>& array, std::vector<T>& helper, int beg, int end) {
        if (beg < end - 1) {
            int mid = (beg + end) / 2;
            sort(array, helper, beg, mid);
            sort(array, helper, mid, end);
            merge(array, helper, beg, mid, end);
        }
    }

    static void merge(std::vector<T>& array, std::vector<T> helper, int beg, int mid, int end) {
        // Copy the whole range of data from array to helper
        for (int i = beg; i < end; ++i) {
            helper[i] = array[i];
        }

        int i = beg;
        int iLeft = beg;
        int iRight = mid;
        while (iLeft < mid && iRight < end) {
            if (helper[iLeft] < helper[iRight]) {
                array[i++] = helper[iLeft++];
            } else {
                array[i++] = helper[iRight++];
            }
        }
        while (iLeft < mid) {
            array[i++] = helper[iLeft++];
        }
        while (iRight < end) {
            array[i++] = helper[iRight++];
        }
        // NOTE: We don't need to copy from helper[iRight] because that data is already in the array
    }
};

#endif