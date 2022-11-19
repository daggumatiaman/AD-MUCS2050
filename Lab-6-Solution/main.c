#include "lab6.h"

void initializeStudents(Student *array) {
	int size = getSize(array);

	for(int i = 0; i < size; ++i) {
		Student *s = getStudent(array, i);
		s->gpa = 1.0 + (float)(rand() % 300 + 1) / 100.0;

		int id = rand();
		char *bytes = (char *)(&id);
		// guarantee unique IDs but still random
		bytes[0] = (char)i;
		s->id = id;
	}
}

void printStudent(Student *s) {
	printf("Student(%.2f, %10d)", getGPA(s), getID(s));
}

void printStudents(Student *array) {
	int size = getSize(array);

	for(int i = 0; i < size; ++i) {
		Student *s = getStudent(array, i);
		printStudent(s);
		if((i + 1) % 5 == 0) {
			puts("");
		} else if((i + 1) != size) {
            printf(", ");
        }
	}
}

int main() {
	srand(255);
	int size = 10;

	puts("Creating array");
	Student *array = createArray(size);

	if(!array) {
		puts("ERROR: createArray returned NULL");
		return -1;
	}

	if(size != getSize(array)) {
		puts("ERROR: getSize returned unexpected value");
		return -1;
	}

	initializeStudents(array);

	puts("Printing array");
	printStudents(array);

	Student *result = getStudent(array, size / 2);
	if(result != (array + size / 2)) {
		puts("getStudent returned unexpected address");
	}

	result = array + (size / 2);
	if(getGPA(result) != result->gpa) {
		puts("ERROR: getGPA returned unexpected value");
	}

	if(getID(result) != result->id) {
		puts("ERROR: getID returned unexpected value");
	}

	result = getMaxID(array);
	printf("getMaxID() returns: ");
	printStudent(result); puts("");

	result = getMinGPA(array);
	printf("getMinGPA() returns: ");
	printStudent(result); puts("");

	result = getMaxGPA(array);
	printf("getMaxGPA() returns: ");
	printStudent(result); puts("");

	puts("Freeing array");
	freeArray(array);
}
