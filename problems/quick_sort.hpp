#ifndef QUICK_SORT_HPP__
#define QUICK_SORT_HPP__

#include <vector>
#include "vector_util.hpp"
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
        std::cout << toStr(array, beg, end) << " pivot=" << pivot << " ";
        int mid = partition(array, pivot, beg, end);
        std::cout << toStr(array, beg, mid) << " " << toStr(array, mid, end) << " mid=" << mid - beg << std::endl;
        sort(array, beg, mid);
        sort(array, mid, end);
    }

    // NOTE: the main problem with partition to be aware of
    // it should not return empty partition never. Otherwise
    // your algorithm is going to loop forever
    static int partition(std::vector<T>& array, T pivot, int beg, int end) {
        if (end - beg <= 1) {
            return end;
        }
        int i = beg;
        int j = end - 1;
        while (true) {
            while (array[i] < pivot) {
                i++;
            }
            while (array[j] > pivot) {
                j--;
            }
            if (i >= j) {
                return i;
            }
            
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
};

#endif