#include <stdio.h>

#include "../libs/utils.h"
#include "../libs/sorting.h"

#define N_DATAPOINTS 100

int main(int argc, char** argv) {
    if (argc != 2)
        exit(EXIT_FAILURE);

    FILE* input = fopen("data/temp.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (input == NULL)
        exit(EXIT_FAILURE);

    int complexity = 0, count = 0;
    while ((read = getline(&line, &len, input)) != -1) {
        Data datapoints[N_DATAPOINTS];

        int N = readdata(line, &datapoints[0]);

        if (strncmp(argv[1], "merge", 5) == 0)
            complexity += mergeSort(datapoints, 0, N-1);
        else
            complexity += quickSort(datapoints, 0, N-1);

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