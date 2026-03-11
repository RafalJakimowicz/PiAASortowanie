#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

// sortowanie przez scalanie

template <typename T>
class MergeSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        if (end - start <= 1){
            return;
        }
        typename std::vector<T>::iterator mid = start + std::distance(start, end) / 2;
        sort(start, mid);
        sort(mid, end);
        merge(start, mid, end);
    };
    
private:
    void merge(typename std::vector<T>::iterator start, typename std::vector<T>::iterator mid, typename std::vector<T>::iterator end){
        std::vector<T> tmp;

        tmp.reserve(std::distance(start, end));

        typename std::vector<T>::iterator lewyTmp = start;
        typename std::vector<T>::iterator prawyTmp = mid;

        while(lewyTmp != mid && prawyTmp != end){
            if (*lewyTmp <= *prawyTmp){
                tmp.push_back(*lewyTmp);
                ++lewyTmp; 
            }
            else {
                tmp.push_back(*prawyTmp);
                ++prawyTmp;
            }
        }

        while(lewyTmp != mid){
            tmp.push_back(*lewyTmp);
            ++lewyTmp;
        }

        while(prawyTmp != end){
            tmp.push_back(*prawyTmp);
            ++prawyTmp;
        }

        typename std::vector<T>::iterator oryginalnyPoczatek = start;
        for (const T& wartosc: tmp){
            *oryginalnyPoczatek = wartosc;
            ++oryginalnyPoczatek; 
        }
    };
};
#endif //SORTING_ALGORITHMS_MERGESORT_H
