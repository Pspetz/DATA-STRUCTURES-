#include "sorting.h"


/* Helper function for mergeSort */
int merge(Data *arr, int low, int mid, int high) {
    int l1, l2, i, complexity = 0;
    Data *tmp = malloc(sizeof(Data) * (high+1));

    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if(arr[l1].value <= arr[l2].value)
            tmp[i]  = arr[l1++];
        else
            tmp[i]  = arr[l2++];

        complexity++;
    }
   
    while(l1 <= mid) {
        tmp[i++] = arr[l1++];
        complexity++;
    }

    while(l2 <= high) {
        tmp[i++] = arr[l2++];
        complexity++;
    }

    for(i = low; i <= high; i++) {
        arr[i]= tmp[i];
        complexity++;
    }

    free(tmp);
    return complexity;
}


int mergeSort(Data *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        
        int c1 = mergeSort(arr, low, mid);
        int c2 = mergeSort(arr, mid+1, high);

        int c3 = merge(arr, low, mid, high);

        return c1 + c2 + c3;
   }

   return 0;
}


/* Helper function for quickSort */
void swap(Data *arr, int i, int j) {
    Data tmp = arr[i];
    arr[i] = arr[j];
    arr[j]  = tmp;
}


/* Helper function for quickSort */
int partition(Data *arr, int low, int high, int *pos) {
    float pivot = arr[high].value;
    int lowPointer  = low - 1;
    int highPointer = high;
    int complexity;

    while (1) {
        while (lowPointer < high && arr[++lowPointer].value < pivot) complexity++;
        while (highPointer > low && arr[--highPointer].value > pivot) complexity++;

        if (lowPointer >= highPointer)
            break;
        else
            swap(arr, lowPointer, highPointer);

        complexity++;
    }

    swap(arr, lowPointer, high);
    complexity++;

    *pos = lowPointer;
    return complexity;
}


int quickSort(Data *arr, int low, int high) {
    if (low < high) {
        int pos;
        
        int c1 = partition(arr, low, high, &pos);

        int c2 = quickSort(arr, low, pos-1);
        int c3 = quickSort(arr, pos+1, high);

        return c1 + c2 + c3;
    }

    return 0;
}


/* Helper function for heapSort */
int heapify(Data *arr, int N) {
    int parent, current, complexity = 0;

    for(int i = 1; i <= N; i++) {
        current = i;
        parent = (int) current / 2;
        complexity++;

        while(parent >= 1) {
            if(arr[parent].value < arr[current].value) {
                swap(arr, current, parent);
                complexity++;
            }
            
            // traverse heap
            current = parent;
            parent = (int) current / 2;
            complexity++;
        }
    }

    return complexity;
}


int heapSort(Data *arr, int N) {
    int complexity = 0;

    for (int i = N; i >= 1; i--)
        arr[i] = arr[i-1];

    for (int i = N; i >= 1; i--) {
        complexity += heapify(arr, i);
        swap(arr, 1, i);
        complexity++;
    }

    for (int i = 0; i < N; i++)
        arr[i] = arr[i+1];

    return complexity;
}

int countSort(Data *arr, int N) {
    Data *sorted = malloc(sizeof(Data) * N);

    int i, count[VALUE_RANGE + 1], complexity = 0;
    memset(count, 0, sizeof(count));
  
    for(i = 0; i < N; i++) 
        count[(int) arr[i].value]++;
  
    for (i = 1; i <= VALUE_RANGE; i++)  {
        count[i] += count[i-1];
        complexity++;
    }
  
    for (i = 0; i < N; i++) { 
        sorted[count[(int) arr[i].value]-1].time  = arr[i].time;
        sorted[count[(int) arr[i].value]-1].value = arr[i].value;
        --count[(int) arr[i].value];
        complexity++;
    } 

    for (i = 0; i < N; i++) {
        arr[i] = sorted[i];
        complexity++;
    }

    free(sorted);
    return complexity;
}

void timestampSort(Data *arr, int N) {
    for (int i = N; i >= 1; i--)
        arr[i] = arr[i-1];

    for (int i = N; i >= 1; i--) {
        int parent, current;

        for(int j = 1; j <= i; j++) {
            current = j;
            parent = (int) current / 2;

            while(parent >= 1) {
                if (compare(arr[parent].time, arr[current].time) < 0)
                    swap(arr, current, parent);
                
                // traverse heap
                current = parent;
                parent = (int) current / 2;
            }
        }

        swap(arr, 1, i);
    }

    for (int i = 0; i < N; i++)
        arr[i] = arr[i+1];
}