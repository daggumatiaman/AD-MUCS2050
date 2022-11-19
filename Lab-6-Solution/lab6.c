#include "lab6.h"

/* Creates an array with the given size. Stores
 * the size before the array pointer as an
 * integer, and returns a pointer to the start
 * of the array on success, or NULL on failure.
 */
Student * createArray(int size) {
	int *array = malloc(sizeof(int) + sizeof(Student) * size);

	if(array) {
		*array = size;
		++array;
	}

	return (Student *)array;
}

/* Takes an array with the size stored before
 * the array as an integer, and returns that
 * size.
 */
int getSize(Student *array) {
	int *arr = (int *)array;
	return arr[-1];
}

/* Takes an array created with createArray, and
 * an index in the array. Returns a pointer to
 * the provided index in the array.
 */
Student * getStudent(Student *array, int index) {
	return array + index;
}

/* Takes a pointer to a student struct,
 * and returns the value of the GPA member
 * stored within that struct.
 */
float getGPA(Student *s) {
	return s->gpa;
}

/* Takes a pointer to a student struct,
 * and returns the value of the ID member
 * stored within that struct.
 */
int getID(Student *s) {
	return s->id;
}

/* Takes an array created with createArray, and
 * returns a pointer to the Student struct in the
 * array which contains the highest ID value.
 */
Student * getMaxID(Student *array) {
	Student *max = getStudent(array, 0);
	int size = getSize(array);

	for(int i = 1; i < size; ++i) {
		Student *s = getStudent(array, i);
		if(getID(max) < getID(s)) {
			max = s;
		}
	}

	return max;
}

/* Takes an array created with createArray, and
 * returns a pointer to the Student struct in the
 * array which contains the lowest GPA value.
 */
Student * getMinGPA(Student *array) {
	Student *min = getStudent(array, 0);
	int size = getSize(array);

	for(int i = 1; i < size; ++i) {
		Student *s = getStudent(array, i);
		if(getGPA(min) > getGPA(s)) {
			min = s;
		}
	}

	return min;
}

/* Takes an array created with createArray, and
 * returns a pointer to the Student struct in the
 * array which contains the highest GPA value.
 */
Student * getMaxGPA(Student *array) {
	Student *max = getStudent(array, 0);
	int size = getSize(array);

	for(int i = 1; i < size; ++i) {
		Student *s = getStudent(array, i);
		if(getGPA(max) < getGPA(s)) {
			max = s;
		}
	}

	return max;
}

/* Takes an array created with createArray, and
 * frees all of the memory allocated to that array.
 */
void freeArray(Student *array) {
	int *arr = (int *)array;
	free(arr - 1);
}




















