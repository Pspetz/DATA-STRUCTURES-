#include "search.h"

int binarySearch(Data *arr, int low, int high, Timestamp time) {
    int complexity = 0;

    if (low <= high) { 
        int mid = (low + high) / 2;
        complexity++;
  
        if (compare(arr[mid].time, time) == 0) 
            return ++complexity;//arr[mid].value;
        else if (compare(arr[mid].time, time) > 0) 
            return ++complexity + binarySearch(arr, low, mid-1, time);
        else
            return ++complexity + binarySearch(arr, mid+1, high, time); 
    } 

    return complexity;//-1; 
}

int interpolationSearch(Data *arr, int N, Timestamp time) {
    int low = 0;
    int high = N - 1;
    int complexity = 0;
  
    while (low <= high &&
           compare(time, arr[low].time) >= 0 &&
           compare(time, arr[high].time) <= 0) {

        if (low == high){ 
            if (compare(arr[low].time, time) == 0)
                return ++complexity; //arr[low].value;
            else
                return ++complexity; //-1; 
        }

        int pos = low + (((double)(high-low) / 
              (timestamp2int(arr[high].time)-timestamp2int(arr[low].time)))*
              (timestamp2int(time) - timestamp2int(arr[low].time)));
        complexity++;
  
        if (compare(arr[pos].time, time) == 0) 
            return complexity; //arr[pos].value; 
        else if (compare(arr[pos].time, time) < 0)
            low = pos + 1; 
        else
            high = pos - 1;
        complexity++;
    }

    return complexity; //-1; 
} 