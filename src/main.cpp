#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <thread>
#include <format>
#include <fstream>
#include <algorithm>
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"

std::vector<uint32_t> wygenerujTablice(double procentPosortowanych, int dlugosc);
int zmierzMergeSort(std::vector<int> liczbyElementow, std::vector<double> procentyPosortowanych);
int zmierzQuickSort(std::vector<int> liczbyElementow, std::vector<double> procentyPosortowanych);
int zmierzIntroSort(std::vector<int> liczbyElementow, std::vector<double> procentyPosortowanych);
bool porownajDouble(double a, double b);

int main(int argc, char* argv[])
{
    const std::vector<int> liczbyElementow {10000, 50000, 100000, 500000, 1000000};
    const std::vector<double> procentyPosortowanych {0.00, 0.250, 0.500, 0.750, 0.950, 0.990, 0.997, -1.00};
    std::cout<< "-----Test Efektywnosci algorytmow sortowania-----"<<std::endl;

    std::thread mergeThread(zmierzMergeSort, liczbyElementow, procentyPosortowanych);
    std::thread quickThread(zmierzQuickSort, liczbyElementow, procentyPosortowanych);
    std::thread introThread(zmierzIntroSort, liczbyElementow, procentyPosortowanych);

    if(mergeThread.joinable()){
        mergeThread.join();
    }

    if(quickThread.joinable()){
        quickThread.join();
    }

    if(introThread.joinable()){
        introThread.join();
    }

    return 0;
}

std::vector<uint32_t> wygenerujTablice(double procentPosortowanych, int dlugosc){
    std::random_device rd;
    std::mt19937 gen(rd());
    if(porownajDouble(procentPosortowanych, 0.00)){
        std::vector<uint32_t> rezultat {};
        for(int i = 0; i < dlugosc; i++){
            rezultat.push_back(gen());
        }
        return rezultat;
    }
    //posortowana odwrotnie
    else if(porownajDouble(procentPosortowanych, -1.00)){
        std::vector<uint32_t> rezultat {};
        for(int i = 0; i < dlugosc; i++){
            rezultat.push_back(gen());
        }
        std::sort(rezultat.begin(), rezultat.end());
        return rezultat;
    }
    else {
        std::vector<uint32_t> rezultat {};
        for(int i = 0; i < dlugosc; i++){
            rezultat.push_back(gen());
        }
        int indexPosortowaneCzesci = std::floor(dlugosc * procentPosortowanych);
        std::sort(rezultat.begin(), rezultat.begin() + indexPosortowaneCzesci);
        return rezultat;
    }
}

bool porownajDouble(double a, double b){
    const double epsilon = 1e-6;
    return std::abs(a - b) <= epsilon;
}

int zmierzMergeSort(std::vector<int> liczbyElementow, std::vector<double> procentyPosortowanych){
    std::cout << "Rozpoczynam testy Merge Sorta" << std::endl;
    std::string nazwaPliku = "mergesort.csv";
    std::ofstream plikWynikow(nazwaPliku, std::ios::app);
    uint32_t indexWPliku = 0;

    if(!plikWynikow.is_open()){
        std::cout << "Blad w otwieraniu pliku konczenie..." << std::endl;
        return -1;
    }

    for(int liczbaElementow: liczbyElementow){
        for(double procentPosortowanych: procentyPosortowanych){
            for(int n = 1; n <= 100; n++){
                std::cout << "MergeSort -> L.elementow: " << liczbaElementow << ". P.posortowanych: " << procentPosortowanych << ". Test nr." << n << std::endl;
                MergeSort<uint32_t> merge;
                std::vector<uint32_t> doSortowania = wygenerujTablice(procentPosortowanych, liczbaElementow);

                auto start = std::chrono::high_resolution_clock::now();
                merge.sort(doSortowania.begin(), doSortowania.end());
                auto stop = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> delta = stop - start;
                plikWynikow << indexWPliku << "," << liczbaElementow << "," << procentPosortowanych << "," << delta.count() << std::endl;
                plikWynikow.flush();
                indexWPliku++;
            }
        }
    }

    plikWynikow.close();
    std::cout << "Testy Merge Sorta zakonczone" << std::endl;
    return 1;
};

int zmierzQuickSort(std::vector<int> liczbyElementow, std::vector<double> procentyPosortowanych){
    std::cout << "Rozpoczynam testy Quick Sorta" << std::endl;
    std::string nazwaPliku = "quicksort.csv";
    std::ofstream plikWynikow(nazwaPliku, std::ios::app);
    uint32_t indexWPliku = 0;

    if(!plikWynikow.is_open()){
        std::cout << "Blad w otwieraniu pliku konczenie..." << std::endl;
        return -1;
    }

    for(int liczbaElementow: liczbyElementow){
        for(double procentPosortowanych: procentyPosortowanych){
            for(int n = 1; n <= 100; n++){
                std::cout << "QuickSort -> L.elementow: " << liczbaElementow << ". P.posortowanych: " << procentPosortowanych << ". Test nr." << n << std::endl;
                MergeSort<uint32_t> merge;
                std::vector<uint32_t> doSortowania = wygenerujTablice(procentPosortowanych, liczbaElementow);

                auto start = std::chrono::high_resolution_clock::now();
                merge.sort(doSortowania.begin(), doSortowania.end());
                auto stop = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> delta = stop - start;
                plikWynikow << indexWPliku << "," << liczbaElementow << "," << procentPosortowanych << "," << delta.count() << std::endl;
                plikWynikow.flush();
                indexWPliku++;
            }
        }
    }

    plikWynikow.close();
    std::cout << "Testy Quick Sorta zakonczone" << std::endl;
    return 1;
};

int zmierzIntroSort(std::vector<int> liczbyElementow, std::vector<double> procentyPosortowanych){
    std::cout << "Rozpoczynam testy Intro Sorta" << std::endl;
    std::string nazwaPliku = "introsort.csv";
    std::ofstream plikWynikow(nazwaPliku, std::ios::app);
    uint32_t indexWPliku = 0;

    if(!plikWynikow.is_open()){
        std::cout << "Blad w otwieraniu pliku konczenie..." << std::endl;
        return -1;
    }

    for(int liczbaElementow: liczbyElementow){
        for(double procentPosortowanych: procentyPosortowanych){
            for(int n = 1; n <= 100; n++){
                std::cout << "IntroSort -> L.elementow: " << liczbaElementow << ". P.posortowanych: " << procentPosortowanych << ". Test nr." << n << std::endl;
                MergeSort<uint32_t> merge;
                std::vector<uint32_t> doSortowania = wygenerujTablice(procentPosortowanych, liczbaElementow);

                auto start = std::chrono::high_resolution_clock::now();
                merge.sort(doSortowania.begin(), doSortowania.end());
                auto stop = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> delta = stop - start;
                plikWynikow << indexWPliku << "," << liczbaElementow << "," << procentPosortowanych << "," << delta.count() << std::endl;
                plikWynikow.flush();
                indexWPliku++;
            }
        }
    }

    plikWynikow.close();
    std::cout << "Testy Intro Sorta zakonczone" << std::endl;
    return 1;
};
