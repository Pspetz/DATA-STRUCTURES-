#ifndef SORTING_H
#define SORTING_H

#include "utils.h"

#define VALUE_RANGE 100

int mergeSort(Data *arr, int low, int high);
int quickSort(Data *arr, int low, int high);

int heapSort(Data *arr, int N);
int countSort(Data *arr, int N);

void timestampSort(Data *arr, int N);

#endif