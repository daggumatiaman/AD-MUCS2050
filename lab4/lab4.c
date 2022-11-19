#include "lab4.h"

/*createArray
    Takes in the size of the array and then creates a int array and then allocates that
    short array and an int array so the in array can hold the size of the short function
    and thn tests whether its successful, if so it will return a short array by casting 
    the int array and changing the 0 spot from size to the actual array. 
    */
short * createArray(int size){
    //local variable for array 
    int * array = NULL;  

    //memory allocation of variable array plus short
    array = (int *) malloc (size * sizeof (short) + sizeof(int));

    //Test if it was successful allocation 
    if (array == NULL){
        printf("\nAllocation was not successful!");
        return NULL; 
    }

    //setting the first value of the arry to the size of the function
    array[0] = size; 

    //casting that integer array to a short array and changing the value of the [0] spot
    return ((short *)(++array)); 

}



/*getSize
    The function takes that short array that was created earlier and turns it back into 
    an integer revealing the hidden size that used to be in the [0] value. Then it
    returns that value which is the size
*/
int getSize(short *array){
    //creating a new variable and then casting the short array back into an integer array
    int * firstarray = (int *)(array); 
    
    //returning the [-1] value because its the hidden size
    return firstarray[-1]; 
}



/*countDivisible
    Takes the short array as well as a query integer and then counts the number of elements
    in the array are divisible by that query integer and then returning that count value
*/

int countDivisible(short *array, int query){
    //local variable 
    int count = 0;

    //for statement to loop through all elements in array to find count
    for (int i = 0; array[i] != '\0'; i++){
        if (array[i] % query == 0){
            count++;
        }
    }

    //returning count of elements divisible 
    return count; 
}



/*freeArray
    The following function takes the short array and turns it back into an integer array
    in order to free the entire malloc from earlier.
    Then it will free all the memory that has been allocated 
*/

void freeArray(short *array){
    //creates new array and turns the short array from earlier into integer array by casting
    int * firstarray = (int *)(array); 

    //makes the value go back to include the hidden size
    firstarray = &firstarray[-1]; 

    //free memory allocation of the short and integer arrays
    free(firstarray); 

    //Makes the array pointer NULL
    array = NULL; 
}