#include "lab2.h"

/* makeArray
    Takes an integer representing the size of the array and then it allocates an array pointer
    using malloc and then tests whether or not it allocates NULL
    then it turns every value in the array to 0 and then 
    returns a pointer
*/
int * makeArray(int size){
    //local varaible
    int* array1; 

    //memory allocation of variable array1
    array1 = (int*) malloc(size*sizeof(int));


    //checks whether array allocation is NULL 
    //The following if statement is for when it is NULL, it will output that it failed and will return NULL
    if (array1 == NULL){
        printf("Allocation failed\n");
        return NULL; 
    }

    //If the allocation is not NULL, it will print successful and make all of the values 0, then returns it 
    printf("Allocation successful\n");
    *array1 = 0; 
    return array1; 

}


/* fillFives
        The following function takes the created array as well as size
        and makes its values increase by multiples of 5
        until the size of the array which is given
*/
void fillFives(int *array, int size){
    //local variables 
    int x = 0;

    //The following for loop makes values, that are being added into the array, all multiples of 5
    for(int i = 0; i < size; i++){
        *(array + i) = x;
        x += 5;
    }

}



/*freeArray
    The following funciton takes a double pointer and will free the memory that has been allocated
    into the array and it also makes the array pointer NULL 
*/
void freeArray(int **array){
    //free memory allocation of array pointer function
    free( *array );

    //Makes the array pointer NULL
    *array = NULL;
}


