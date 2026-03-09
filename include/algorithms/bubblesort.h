#ifndef SORTING_ALGORITHMS_BUBBLESORT_H
#define SORTING_ALGORITHMS_BUBBLESORT_H
#include <vector>

// sortowanie bąbelkowe

template <typename T>
class BubbleSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        for(typename std::vector<T>::iterator i = start; i != end; i++){
            for(typename std::vector<T>::iterator j = i + 1; j != end; j++){
                if(*i > *j){
                    T tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
            }
        }
    };
};

#endif //SORTING_ALGORITHMS_BUBBLESORT_H
