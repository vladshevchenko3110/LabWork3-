void merge(int array[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int *left = new int[mid];
    int *right = new int[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(array, left, right, mid, size - mid);

    delete[] right;
    delete[] left;
}