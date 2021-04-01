#include <stdio.h>

#include "../libs/utils.h"
#include "../libs/sorting.h"
#include "../libs/search.h"

#define N_DATAPOINTS 100

int main(int argc, char** argv) {
    if (argc != 3)
        exit(EXIT_FAILURE);
    
    FILE* input;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (strncmp(argv[1], "temp", 4) == 0)
        input = fopen("data/temp.txt", "r");
    else
        input = fopen("data/hum.txt", "r");
    
    if (input == NULL)
        exit(1);

    int complexity = 0, count = 0;
    while ((read = getline(&line, &len, input)) != -1) {
        Data datapoints[N_DATAPOINTS];

        int N = readdata(line, &datapoints[0]);

        Timestamp time = datapoints[0].time;
        if (strncmp(argv[2], "binary", 4) == 0)
            complexity += binarySearch(datapoints, 0, N-1, time);
        else
            complexity += interpolationSearch(datapoints, N, time);
        
        count++;
        /* Used for testing purposes
        printf("%02d:%02d:%02d -> %f\n\n", t.hour, t.min, t.sec, value); */
    }

    printf("Average complexity: %.f\n", (float) complexity / count);
    fclose(input);

    return 0;
}