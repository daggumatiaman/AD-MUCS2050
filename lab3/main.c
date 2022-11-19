#include "lab3.h"

void printArray(int *array, int size) {
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
	srand(time(NULL));
	int size = 10; 
	int offset = 5; 
	int *array = makeArray(size); 

	if(!array) {
		puts("ERROR: makeArray unexpectedly returned NULL");
		return -1;
	}

	puts("Printing array values");
	printArray(array, size);

	puts("Offsetting values");
	offsetArray(array, offset); 

	puts("Printing indices that have 9");
	printNines(array, size, offset); 
	

	printf("Array before free: %p\n", array);
	freeArray(array, offset);
	printf("Array after free: %p\n", array);
}


