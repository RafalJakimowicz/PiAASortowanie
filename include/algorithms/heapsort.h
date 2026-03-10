#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

template <typename T>
class Heap
{
  private:
    std::size_t h_size;
    typename std::vector<T>::iterator h_start;
    typename std::vector<T>::iterator h_end;
    void heapify(int index);

  public:
    Heap(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        this->h_size = (end - start);
        this->h_start = start;
        this->h_end = end;

        for(int i = this->h_size/2; i >= 1; i--){
            this->heapify(i);
        }
    }
    void removeMax();
    std::size_t size();
    bool empty();
    T& operator[](int index);
};

template <typename T>
void Heap<T>::heapify(int index){
    int najwiekszy = index;
    int lewe_dziecko_index = 2 * index;
    int prawe_dziecko_index = 2 * index + 1;

    if(lewe_dziecko_index <= this->h_size && (*this)[lewe_dziecko_index] > (*this)[najwiekszy]){
        najwiekszy = lewe_dziecko_index;
    }

    if(prawe_dziecko_index <= this->h_size && (*this)[prawe_dziecko_index] > (*this)[najwiekszy]){
        najwiekszy = prawe_dziecko_index;
    }

    if(najwiekszy != index){
        T tmp = (*this)[index];
        (*this)[index] = (*this)[najwiekszy];
        (*this)[najwiekszy] = tmp;
        this->heapify(najwiekszy);
    }
}

template <typename T>
void Heap<T>::removeMax()
{
    if (this->h_size == 0) {
        return; 
    }

    T tmp = (*this)[1];
    (*this)[1] = (*this)[this->h_size];
    (*this)[this->h_size] = tmp;

    this->h_size -= 1;

    this->heapify(1);
}

template <typename T>
std::size_t Heap<T>::size()
{
    return this->h_size;
}

template <typename T>
bool Heap<T>::empty()
{
    if(this->h_size > 0){
        return false;
    }
    return true;
}

template <typename T>
T& Heap<T>::operator[](int index)
{
    return *(this->h_start + index - 1);
}


// sortowanie przez kopcowanie

template <typename T>
class HeapSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        if (start == end) return;

        Heap<T> kopiec(start, end);
        while (kopiec.size() > 1)
        {
            kopiec.removeMax();
        }
    };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
