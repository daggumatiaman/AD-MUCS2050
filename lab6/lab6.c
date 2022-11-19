#include "lab6.h"

/* createArray
Takes a int that is the size and then allocates an int array with the values of a student
array as well as the size hidden in the int part and then checks if NULL. Then it 
makes the first value of the array the size and then hides it by casting it to a student
array*/

Student * createArray(int size){
    //iniailizing variables
    int * array = (int *) malloc (size * sizeof (Student) + sizeof(int));

    //checking for null
    if (array == NULL){
        printf("Allocation was not successful!");
        return NULL; 
    }
    //making first part of array size
    array[0] = size; 

    //casting the int array to a student array
    return((Student *)(++array)); 
}

/*getSize
takes the student array given, changes it back into an int array to find the hidden
variable and then prints the hidden variable which is the size
*/
int getSize(Student *array){
    //initializing variables 
    int * sizearray = (int *)(array);

    //returns the hidden size variable
    return(sizearray[-1]);
}

/*getStudent
takes the array student array and an index and then returns a pointer to the 
spot of the index in the student array
*/
Student * getStudent(Student * array, int index){
    //initializing local variables 
    Student * temp = (Student *)array; 
    
    //returning the pointer to student array of the index
    return temp + index - 1;
}


/*getGPA
takes the student struct given and returns the gpa 
*/
float getGPA(Student *s){
    //initializing local variables 
    float fgpa = 0; 
    Student * temp = (Student *)s; 

    //gets gpa from the student struct
    fgpa = temp->gpa;

    //returns gpa
    return fgpa;    
}
/*getID
takes the student struct given and returns the id
*/
int getID(Student *s){
    //initializing local variables 
    int finalid = 0;

    //gets id from the student struct
    Student * temp = (Student *)s; 
    finalid = temp->id; 

    //returns id
    return finalid; 
}

/*GetMaxGPA
takes the student struct and then finds the maximum value the struct
*/

Student * getMaxGPA(Student *array){
    //initializing local variables
    int word = 0;

    //for statement checking where the maximum value is 
    for( int i = 0; i < getSize(array); i++){
        if (array[word].gpa > array[i + 1].gpa){
          
           word = i; 
        } else {
           // max = array[i + 1].gpa; 
            word = i + 1; 
        }
    }
    //returns a pointer back 
    return array + word - 1; 
}


/*freeArray
takes the student array and casts it back into a int array and then gets the hidden 
variable and then frees the entire array
*/
void freeArray(Student *array){
    //initializing local variables 
    int * freearray = (int *)(array);

    //finds the hidden variable 
    freearray = &freearray[-1]; 


    //frees entire array
    free(freearray); 

    //makes array NULL
    array = NULL; 
}