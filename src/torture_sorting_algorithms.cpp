#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// Dodane brakujące biblioteki standardowe
#include <vector>
#include <random>
#include <algorithm>

// Twoje nagłówki
#include "algorithms/bubblesort.h"
#include "algorithms/insertsort.h"
#include "algorithms/heapsort.h"
#include "algorithms/mergesort.h"
#include "algorithms/shellsort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"

using namespace std::string_literals;

std::vector<int> getTestData()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> rezultat {};
    
    rezultat.reserve(10000); 
    
    for(int i = 0; i < 10000; i++){
        rezultat.push_back(gen());
    }
    return rezultat;
}


TEST_CASE("BubbleSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    BubbleSort<int> bubbleSort;
    bubbleSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}

TEST_CASE("InsertSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    InsertSort<int> insertSort;
    insertSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}

TEST_CASE("HeapSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    HeapSort<int> heapSort;
    heapSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}

TEST_CASE("MergeSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    MergeSort<int> mergeSort;
    mergeSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}

TEST_CASE("ShellSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    ShellSort<int> shellSort;
    shellSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}

TEST_CASE("QuickSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    QuickSort<int> quickSort;
    quickSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}

TEST_CASE("IntroSort")
{
    auto data = getTestData();
    
    auto expectedData = data;
    std::sort(expectedData.begin(), expectedData.end());

    IntroSort<int> introSort;
    introSort.sort(data.begin(), data.end());

    REQUIRE(data == expectedData);
}