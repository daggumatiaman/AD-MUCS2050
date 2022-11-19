#include "lab3.h"

/* makeArray
    Takes an integer representing the size of the array and then creates a integer array 
    and then allocatess an array pointer using malloc and then tests whether or not it 
    allocates NULL then it uses a random function to randomly assign the values in to 
    array to integers between 0 and 9 and then returns a pointer
    */
int * makeArray(int size){
    //local variables 

    int * array1;
    int first = 0; 
    int last = 9; 

    //memory allocation of variable array1
    array1 = (int*) malloc(size* sizeof(int));

    //checks whether array allocation is NULL
    //The following if statement is for when it is NULL, it will output that it failed and returns NULL
    if (array1 == NULL){
        printf("Allocation was not successful!\n");
        return NULL;
    }

    //If allocation is not NULL, it will print successful
    printf("Allocation successfull!\n");
    //creates random value
    srand(time(0));
    //makes the random value between 0 and 9 and assignes it to the array 
    for(int i = 0; i < size; i++){
        int random = (rand() % (last - first + 1)) + first; 
        *(array1 + i) = random; 
    }
    
    return array1; 
}

/* offsetArray
    The following function takes an integer array and a value to offset it by and then 
    subtracts that ofset from the array so that it is offsetted by that specific amount
*/
int * offsetArray(int *array, int offset){
    //offset array by subtracting 
    array = array - offset; 
    return array; 
}

/*printNines 
    It will take an integer arry and the offset values and will print all of the indices 
    that contain the number 9 after the random assining
*/
void printNines(int *array, int size, int offset){
    //Adds the offset back to the array to make sure its the orignal values  
    array = array + offset; 

    //for ever 9 in the values it prints its index 
    for(int i = 0; i < size; i++){
        if (*(array + i) == 9){
            printf("%d, ", i + offset); 
        } 
    }

    printf("\n");
    //subtracts the offset from the orignal array to make it the offsetted vallues 
    array = array - offset; 

}

/* freeArray
    The followint function takes a pointer and will free the memomry that has been allocated
    into the array after it makes the array back to its original value by adding the offset back
    and it also makes the arry pointer NULL
*/

void freeArray(int *array, int offset){
    //adds the offset back to the array to make it the orginal value 
    array = array + offset; 
    //frees that original array
    free( array ); 
    array = NULL; 

}
