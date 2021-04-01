#ifndef SEARCH_H
#define SEARCH_H

#include "utils.h"

int binarySearch(Data *arr, int low, int high, Timestamp t);
int interpolationSearch(Data *arr, int N, Timestamp time);

#endif