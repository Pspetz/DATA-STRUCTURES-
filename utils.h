#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct timestamp {
    int day, month, year;
    int hour, min, sec;
} Timestamp;

typedef struct data {
    Timestamp time;
    float value;
} Data;

int compare(Timestamp t1, Timestamp t2);
Timestamp str2timestamp(char* s);
long long timestamp2int(Timestamp t);
int readdata(char* line, Data* datapoints);

#endif