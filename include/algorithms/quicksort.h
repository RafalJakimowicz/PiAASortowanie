#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>

// quicksort

template <typename T>
class QuickSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        if(start >= end){
            return;
        }

        typename std::vector<T>::iterator pivot = partition(start,end);
        sort(start, pivot );
        sort(pivot+1, end);
    };

    typename std::vector<T>::iterator partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        //pivot jako ostatnia pozycja w przedziale
        typename std::vector<T>::iterator pivot = end - 1;
        T wartosc = *pivot;
        typename std::vector<T>::iterator granica = start;
        for(;start != end - 1; start++){
            if(*start <= wartosc){
                //przesuniecie granicy w prawo gdy iterator jest mneijszy od pivota
                T tmp = *start;
                *start = *granica;
                *granica = tmp;
                granica +=1;
            }
        }
        T t_granica = *granica;
        *granica = *pivot;
        *pivot = t_granica;
        return granica;
    };
};
#endif //SORTING_ALGORITHMS_QUICKSORT_H
