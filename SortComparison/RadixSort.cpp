int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void radixSort(int array[], int size) {

    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int *output = new int[size];
        int count[10] = { 0 };

        for (int i = 0; i < size; i++) {
            count[(array[i] / exp) % 10]++;
        }
        
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = size - 1; i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }
        
        for (int i = 0; i < size; i++) {
            array[i] = output[i];
        }

        delete[] output;
    }
}