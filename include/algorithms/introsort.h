#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H

#include <vector>
#include <cmath>
#include "heapsort.h"
#include "insertsort.h"
#include "quicksort.h"

template <typename T>
class IntroSort : protected QuickSort<T>
{
public:
    IntroSort() : maksymalnaGlebokosc(0) {}

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        this->maksymalnaGlebokosc = 2 * std::floor(std::log2(std::distance(start, end)));
        this->introSort(start, end, 1);
    }

private:
    int maksymalnaGlebokosc;

    void introSort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, int layer)
    {
        if(start >= end) {
            return;
        }

        if(layer >= this->maksymalnaGlebokosc) {
            HeapSort<T> h_sort;
            h_sort.sort(start, end);
        }
        else {
            if(std::distance(start, end) <= 16) {
                InsertSort<T> i_sort;
                i_sort.sort(start, end);
            }
            else {
                typename std::vector<T>::iterator pivot = this->partition(start, end);
                
                this->introSort(start, pivot, layer + 1);
                this->introSort(pivot + 1, end, layer + 1);
            }
        }
    }
};

#endif //SORTING_ALGORITHMS_INTROSORT_H