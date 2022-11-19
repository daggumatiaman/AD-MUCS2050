#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	float height;
	double kilometers;
} Runner;

// O(n^2)
void sortByKM(Runner *array, int size);

// O(log(n))
int getByKM(Runner *array, int size, double kilometers);
