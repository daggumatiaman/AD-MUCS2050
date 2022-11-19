#include "lab1.h"

int main() {
	int size = 9, error,
			array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int iResult;

	error = getMax(size, array, &iResult);
	printf("getMax() returned %d, result = %d\n", error, iResult);
	puts("Testing NULL checking");
	error = getMax(size, NULL, &iResult);
	printf("getMax() returned %d, result = %d\n", error, iResult);
	puts("Testing zero size checking");
	error = getMax(0, array, &iResult);
	printf("getMax() returned %d, result = %d\n", error, iResult);
	puts("Testing both");
	error = getMax(0, NULL, &iResult);
	printf("getMax() returned %d, result = %d\n", error, iResult);
}
