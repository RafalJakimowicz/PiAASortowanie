#ifndef SORTING_ALGORITHMS_SHELLSORT_H
#define SORTING_ALGORITHMS_SHELLSORT_H
#include <vector>

// sortowanie Shella

template <typename T>
class ShellSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        for (int przerwa = (end-start) / 2; przerwa >= 1; przerwa /= 2){
            for (int i = przerwa; i < (end - start); i++){
               T key = *(start + i);
               typename std::vector<T>::iterator j = start + i;

               while (j - start >= przerwa && *(j-przerwa) > key){
                    *j = *(j - przerwa);
                    j-=przerwa;
               }
               *j=key;
            }
        }
    };
};
#endif //SORTING_ALGORITHMS_SHELLSORT_H
