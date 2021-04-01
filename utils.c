#include "utils.h"

int compare(Timestamp t1, Timestamp t2) {
    if (t1.year != t2.year)
        return t1.year-t2.year;
    if (t1.month != t2.month)
        return t1.month-t2.month;
    if (t1.day != t2.day)
        return t1.day-t2.day;
    if (t1.hour != t2.hour)
        return t1.hour-t2.hour;
    if (t1.min != t2.min)
        return t1.min-t2.min;
    if (t1.sec != t2.sec)
        return t1.sec-t2.sec;
    
    return 0;
}

Timestamp str2timestamp(char* s) {
    Timestamp t;

    sscanf(s, "%d-%d-%dT%d:%d:%d", &t.year, &t.month, &t.day, &t.hour, &t.min, &t.sec);

    return t;
}

long long timestamp2int(Timestamp t) {
    return t.year * 365 * 24 * 3600 + 
           t.month * 30 * 24 * 3600 + 
           t.day * 24 * 3600 + 
           t.hour * 3600 + 
           t.min * 60 +
           t.sec;
}

int readdata(char* line, Data* datapoints) {
    int N = 1;
    char timestamp[23], *value, *str;
    const char sep[2] = ",";

    /* Find datapoints in the line */
    for (char* c = line; *c != '\n'; c++)
        if (*c == ',')
            N++;

    int i = 0;

    /* Convert datapoints from string to Data */
    str = strtok(line, sep);
    do {
        // first character is either '{' or ' ' so we remove it
        str++;
        if (str[strlen(str)-3] == '}')
            str[strlen(str)-3] = '\0';

        // remove quotes from strings
        strncpy(timestamp, str+1, 19);
        value = str+24;
        value[strlen(value)-1] = '\0';

        // convert strings to Timestamp and float types
        datapoints[i].time = str2timestamp(&timestamp[0]);
        datapoints[i].value = atof(value);
        
        i++;
    } while ((str = strtok(NULL, sep)) != NULL);

    return N;
}