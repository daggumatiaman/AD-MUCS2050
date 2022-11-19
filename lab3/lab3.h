#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * makeArray(int size);

int * offsetArray(int *array, int offset);

void printNines(int *array, int size, int offset);

void freeArray(int *array, int offset);
