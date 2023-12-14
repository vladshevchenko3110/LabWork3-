#include <iostream>
#include <chrono>
#include <time.h>
#include <vector>
#include <algorithm>
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "CountSort.h"
#include "RadixSort.h"

using namespace std;

const int randomN = 100;
const int veryrandomN = 1000000;

const int very_small_size = 10;
const int small_size = 1000;
const int average_size = 10000;
const int big_size = 1000000;
const int very_big_size = 100000000;

class Timer {
private: 
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, ratio<1,1000> >;
    chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now()) {}
    void reset() { m_beg = clock_t::now(); }
    double elapsed() const {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void FillArrays(int* array1, int* array2, int* array3, int* array4, int* array5) {
    for (int i = 0; i < very_small_size; i++) {
        array1[i] = rand() % randomN;
    }
    for (int i = 0; i < small_size; i++) {
        array2[i] = rand() % randomN;
    }
    for (int i = 0; i < average_size; i++) {
        array3[i] = rand() % randomN;
    }
    for (int i = 0; i < big_size; i++) {
        array4[i] = rand() % randomN;
    }
    for (int i = 0; i < very_big_size; i++) {
        array5[i] = rand() % randomN;
    }
}

void VFillArrays(int* array1, int* array2, int* array3, int* array4, int* array5) {
    for (int i = 0; i < very_small_size; i++) {
        array1[i] = rand() % veryrandomN;
    }
    for (int i = 0; i < small_size; i++) {
        array2[i] = rand() % veryrandomN;
    }
    for (int i = 0; i < average_size; i++) {
        array3[i] = rand() % veryrandomN;
    }
    for (int i = 0; i < big_size; i++) {
        array4[i] = rand() % veryrandomN;
    }
    for (int i = 0; i < very_big_size; i++) {
        array5[i] = rand() % veryrandomN;
    }
}

void SortArrays(int* array1, int* array2, int* array3, int* array4, int* array5) {
    sort(array1, array1 + very_small_size, greater<>());
    sort(array2, array2 + small_size, greater<>());
    sort(array3, array3 + average_size, greater<>());
    sort(array4, array4 + big_size, greater<>());
    sort(array5, array5 + very_big_size, greater<>());
}

void InsertionSortTest(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "InsertionSort\t";
    Timer t1;
    insertionSort(array1, very_small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    insertionSort(array2, small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    insertionSort(array3, average_size);
    cout << t1.elapsed() << " ms\t";
    /*t1.reset();
    insertionSort(array4, big_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    insertionSort(array5, very_big_size);
    cout << t1.elapsed() << " ms"\t;*/
    cout << endl;
}
void BubbleSortTest(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "BubbleSort\t";
    Timer t1;
    bubbleSort(array1, very_small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    bubbleSort(array2, small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    bubbleSort(array3, average_size);
    cout << t1.elapsed() << " ms\t";
    /*t1.reset();
    bubbleSort(array4, big_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    bubbleSort(array5, very_big_size);
    cout << t1.elapsed() << " ms"\t;*/
    cout << endl;
}
void QuickSortTest(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "QuickSort\t";
    Timer t1;
    quickSort(array1, 0, very_small_size - 1);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    quickSort(array2, 0, small_size - 1);
    cout << t1.elapsed() << " ms\t";
    t1.reset();;
    quickSort(array3, 0, average_size - 1);
    cout << t1.elapsed() << " ms\t";
    t1.reset();;
    quickSort(array4, 0, big_size - 1);
    cout << t1.elapsed() << " ms\t";
   /* t1.reset();;
    quickSort(array5, 0, very_big_size - 1);
    cout << t1.elapsed() << " ms\t";*/
    cout << endl;
}

void QuickSortTest3(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "QuickSort\t";
    Timer t1;
    quickSort(array1, 0, very_small_size - 1);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    quickSort(array2, 0, small_size - 1);
    cout << t1.elapsed() << " ms\t";
    t1.reset();;
    quickSort(array3, 0, average_size - 1);
    cout << t1.elapsed() << " ms\t";
    /*t1.reset();;
    quickSort(array4, 0, big_size - 1);
    cout << t1.elapsed() << " ms\t";*/
    /* t1.reset();;
     quickSort(array5, 0, very_big_size - 1);
     cout << t1.elapsed() << " ms\t";*/
    cout << endl;
}

void MergeSortTest(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "MergeSort\t";
    Timer t1;
    mergeSort(array1, very_small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    mergeSort(array2, small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();;
    mergeSort(array3, average_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();;
    mergeSort(array4, big_size);
    cout << t1.elapsed() << " ms\t";
    /*t1.reset();;
    mergeSort(array5, very_big_size);
    cout << t1.elapsed() << " ms\t";*/
    cout << endl;
}

void CountSortTest(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "CountSort\t";
    Timer t1;
    countSort(array1, very_small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    countSort(array2, small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    countSort(array3, average_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    countSort(array4, big_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    countSort(array5, very_big_size);
    cout << t1.elapsed() << " ms\t";
    cout << endl;
}

void RadixSortTest(int* array1, int* array2, int* array3, int* array4, int* array5) {
    cout << "RadixSort\t";
    Timer t1;
    radixSort(array1, very_small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    radixSort(array2, small_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    radixSort(array3, average_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    radixSort(array4, big_size);
    cout << t1.elapsed() << " ms\t";
    t1.reset();
    radixSort(array5, very_big_size);
    cout << t1.elapsed() << " ms\t";
    cout << endl;
}

int main()
{
    srand((unsigned int)time(0));
    int *array1 = new int[very_small_size];
    int *array2 = new int[small_size];
    int *array3 = new int[average_size];
    int *array4 = new int[big_size];
    int *array5 = new int[very_big_size];
    
    VFillArrays(array1, array2, array3, array4, array5);
    cout << "\t\t\t\t======== First Comparison ========" << endl;
    cout << "\t\t10 elem" << "\t\t1000 elem\t" << "10000 elem\t" << "1000000 elem\t" << "100000000 elem\t" << endl;

    InsertionSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    BubbleSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    QuickSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    MergeSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    CountSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    RadixSortTest(array1, array2, array3, array4, array5);
    cout << endl << endl;

    FillArrays(array1, array2, array3, array4, array5);
    cout << "\t\t\t\t======== Second Comparison ========" << endl;
    cout << "\t\t10 elem" << "\t\t1000 elem\t" << "10000 elem\t" << "1000000 elem\t" << "100000000 elem\t" << endl;
    
    InsertionSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    BubbleSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    QuickSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    MergeSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    CountSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    RadixSortTest(array1, array2, array3, array4, array5);
    cout << endl << endl;

    
    cout << "\t\t\t\t======== Third Comparison ========" << endl;
    cout << "\t\t10 elem" << "\t\t1000 elem\t" << "10000 elem\t" << "1000000 elem\t" << "100000000 elem\t" << endl;

    VFillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    InsertionSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    BubbleSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    QuickSortTest3(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    MergeSortTest(array1, array2, array3, array4, array5);
    VFillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    CountSortTest(array1, array2, array3, array4, array5);    
    VFillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    RadixSortTest(array1, array2, array3, array4, array5);
    cout << endl << endl;

    
    cout << "\t\t\t\t======== Forth Comparison ========" << endl;
    cout << "\t\t10 elem" << "\t\t1000 elem\t" << "10000 elem\t" << "1000000 elem\t" << "100000000 elem\t" << endl;
    FillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    InsertionSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    BubbleSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    QuickSortTest3(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    MergeSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    CountSortTest(array1, array2, array3, array4, array5);
    FillArrays(array1, array2, array3, array4, array5);
    SortArrays(array1, array2, array3, array4, array5);
    RadixSortTest(array1, array2, array3, array4, array5);
    cout << endl << endl;          

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;
}


