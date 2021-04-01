#include <stdio.h>

#include "../libs/utils.h"
#include "../libs/sorting.h"

#define N_DATAPOINTS 100

int main(int argc, char** argv) {
    if (argc != 2)
        exit(EXIT_FAILURE);

    FILE* input = fopen("data/hum.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (input == NULL)
        exit(EXIT_FAILURE);

    int complexity = 0, count = 0;
    while ((read = getline(&line, &len, input)) != -1) {
        Data datapoints[N_DATAPOINTS];

        int N = readdata(line, &datapoints[0]);

        if (strncmp(argv[1], "heap", 4) == 0)
            complexity += heapSort(datapoints, N);
        else
            complexity += countSort(datapoints, N);

        count++;
        /* Used for testing purposes
        for (int i = 0; i < N; i++)
            printf("%.1f ", datapoints[i].value);
        printf("\n\n"); */
    }

    printf("Average complexity: %.1f\n", (float) complexity / count);
    fclose(input);

    return 0;
}