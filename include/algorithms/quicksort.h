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
protected:
    typename std::vector<T>::iterator partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        auto mid = start + std::distance(start, end) / 2;
        auto last = end - 1;

        //uzywamy techniki mediany z pocztaku konca i sorku przedizlau co zapobiega posortowanym tablica ktore moga zwolnic algorytm
        if (*mid < *start) std::iter_swap(mid, start);
        if (*last < *start) std::iter_swap(last, start);
        if (*last < *mid) std::iter_swap(last, mid);

        std::iter_swap(mid, last);

        T wartosc = *last;
        typename std::vector<T>::iterator granica = start;
        for(auto it = start; it != end - 1; it++){
            if(*it <= wartosc){
                //przesuniecie granicy w prawo gdy iterator jest mneijszy od pivota
                std::iter_swap(it, granica);
                ++granica;
            }
        }
        std::iter_swap(granica, last);
        return granica;
    };
};
#endif //SORTING_ALGORITHMS_QUICKSORT_H
