#ifndef QUICK_SORT_HPP__
#define QUICK_SORT_HPP__

#include <vector>
#include <iostream>

template<class T>
class QuickSort {
public:
    static void sort(std::vector<T>& array) {
        sort(array, 0, array.size());
    }

private:
    static void sort(std::vector<T>& array, int beg, int end) {
        int length = end - beg;
        if (length <= 1) {
            return;
        }
        int pivotIndex = (beg + end) / 2;
        T pivot = array[pivotIndex];
        int mid = partition(array, pivot, beg, end);
        sort(array, beg, mid);
        sort(array, mid, end);
    }

    static int partition(std::vector<T>& array, T pivot, int beg, int end) {
        int i = beg;
        int j = end - 1;
        while (i < j) {
            while (array[i] < pivot && i < j) {
                i++;
            }
            while (array[j] > pivot && i < j) {
                j--;
            }
            if (i < j) {
                T tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
        return i;
    }
};

#endif