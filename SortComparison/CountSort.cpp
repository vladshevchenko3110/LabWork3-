void countSort(int array[], int size) {  
    
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

   
    int* count = new int[max + 1] {0};

    
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    
    int index = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < count[i];j++) {
            array[index] = i;
            index++;            
        }
    }

   
    delete[] count;
}