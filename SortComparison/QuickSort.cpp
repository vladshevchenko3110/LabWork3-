#include <iostream>
using namespace std;
void quickSort(int array[], int low, int high) {

    if (low < high) {
        int pivot = array[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[high]);
        int pi = (i + 1);        
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}