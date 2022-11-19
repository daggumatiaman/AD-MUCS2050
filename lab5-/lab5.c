#include "lab5.h"

/* Creates an array of the given size with the array information
 * stored before the returned pointer as an ArrayInfo struct. Will
 * return NULL if allocation was not successful.
 *
 * Param: int size;		The size of the array to allocate
 */
int * createArray(int size) {

	ArrayInfo *array = malloc(sizeof(ArrayInfo) + size * sizeof(int));

	if(array) {
		array->lastCalculation = -1;
		array->size = size;

		++array;
	}

	return (int *)array;
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and returns the size of the array.
 *
 * Param: int *array;	The array from which to return the size
 */
int getSize(int *array) {
	ArrayInfo *i = getInfo(array);
	return i->size;
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and returns a pointer to that struct.
 *
 * Param: int *array;	The array from which to return the info
 */
ArrayInfo * getInfo(int *array) {
	ArrayInfo *arr = (ArrayInfo *)array;
	return arr - 1;
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and prints the result of the last calculation
 * performed on that array.
 *
 * Param: int *array;	The array from which to print the info
 */
void printLastCalculation(int *array) {
	ArrayInfo *arr = getInfo(array);

	printf("Last calculation: %d\n", arr->lastCalculation);
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and calculates the sum of all the elements in the
 * array which are equal to 3.
 *
 * Param: int *array;	The array with which to perform the sum
 */
void sumThrees(int *array) {
	int sum = 0;

	for(int i = 0; i < getSize(array); ++i) {
		if(array[i] == 3) {
			sum += 3;
		}
	}

	getInfo(array)->lastCalculation = sum;
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and calculates the sum of all the elements in the
 * array which are equal to 5.
 *
 * Param: int *array;	The array with which to perform the sum
 */
void sumFives(int *array) {
	int sum = 0;

	for(int i = 0; i < getSize(array); ++i) {
		if(array[i] == 5) {
			sum += 5;
		}
	}

	getInfo(array)->lastCalculation = sum;
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and calculates the sum of all the elements in the
 * array which are equal to 4.
 *
 * Param: int *array;	The array with which to perform the sum
 */
void sumFours(int *array) {
	int sum = 0;

	for(int i = 0; i < getSize(array); ++i) {
		if(array[i] == 4) {
			sum += 4;
		}
	}

	getInfo(array)->lastCalculation = sum;
}

/* Takes an array pointer which is preceeded by an ArrayInfo
 * struct, and frees the memory allocated to it.
 *
 * Param: int *array;	The array to free
 */
void freeArray(int *array) {
	free(getInfo(array));
}
