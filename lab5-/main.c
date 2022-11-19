#include "lab5.h"

void printArray(int *array) {
	int size = getSize(array);
	printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%d", array[i]);
		if((i + 1) == size) {
			printf(" ]\n");
		} else {
			printf(", ");
		}
	}
}

int main() {
	srand(255);
	int size = 20;

	printf("Allocating array of size %d\n", 20);

	int *arr = createArray(size);
	int tsize = getSize(arr);
	if(tsize != size) {
		printf("Error: getSize() returned %d, but we expected: %d\n", tsize, size);
		return -1;
	} else {
		puts("getSize() returned the expected value");
	}

	puts("Filling array");
	for(int i = 0; i < size; ++i) {
		arr[i] = rand() % 11;
	}

	printArray(arr);

	puts("Calling sumThrees()");
	sumThrees(arr);
	printLastCalculation(arr);

	puts("Calling sumFives()");
	sumFives(arr);
	printLastCalculation(arr);

	puts("Calling sumFours()");
	sumFours(arr);
	printLastCalculation(arr);

	puts("Freeing array");
	freeArray(arr);
}
