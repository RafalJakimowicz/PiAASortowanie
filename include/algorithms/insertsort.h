#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H
#include <vector>

// sortowanie przez wstawianie

template <typename T>
class InsertSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        for(typename std::vector<T>::iterator i = start+1; i != end; i++){
            T key = *i;
            typename std::vector<T>::iterator j = i;

            while (*(j-1) > key && j > start){
                *j = *(j-1);
                j = j - 1;
            }
            *j = key;
        }
    };
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
