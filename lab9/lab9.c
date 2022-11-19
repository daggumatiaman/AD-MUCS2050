#include "lab9.h"
#include <string.h> //used for memcpy


/*createArray
Time Complexity: O(n)
This function creates an array and mallocs it as well as checks if the malloc is null and 
then returns the array created 
*/
Runner * createArray(int size){
    Runner * array = malloc(size * sizeof(Runner)); //creating array

    if (array == NULL) return NULL; //chekcs if null

    return array; //returns the created array

}


/*sortByKM
Time Complexity: O(n^2)
This function takes in an array and its size and then it sorts the function from lowest
to greatest order by the number of kilometers
*/
void sortByKM(Runner *array1, int size){

    Runner * array = malloc(size * sizeof(Runner));  //creates a new array to copy into
    memcpy(array, array1, size * sizeof(Runner)); //copys array to make it easier 

    for(int i = 1; i<size; i++){ //insersion sorting the kilometers 
        for (int j = i; j-1 >= 0; j--){
            if (array[j].kilometers < array[j-1].kilometers){  //checking which one is greater
                Runner temp = array[j-1];  //creating a temp to store

                array[j-1] = array[j];  //changing check variable 
                array[j] = temp; 
            } else if(array[j].kilometers == array[j-1].kilometers){ //does the same thing if duplicate
                Runner temp = array[j-1]; 

                array[j-1] = array[j]; 
                array[j] = temp; 
            } else {  //otherwise it breaks and goes through the loop again 
                break; 
            }
        }
    }
}


/*getByKM
Time Complexity: O(log(n))
This function takes an array that has already been sorted to ascending order and then
it searches the array for the kilometer amount inputted and then outputs the index of the element
*/
int getByKM(Runner *array, int size, double kilometers){
    //initializing local variables 
    int high = size;  
    int low = 0;  

    while(low != high) {  //while statement that searches between lowest and highest size 
        int mid = low + (high-low)/2;
        if(array[mid].kilometers == kilometers) { //searches if the input is the same as the array value 
            return mid;   //if so it returns the value 
        } 
        else if(array[mid].kilometers > kilometers){ //checks if input is smaller
            high = mid - 1;  //if so it goes to an even smaller index to check 
        }
        else if(array[mid].kilometers < kilometers){ //checks if input is larger 
            low = mid +1; 
        }
    } 
    return -1; //returns -1 if value is not in array 
}


/*freeArray
Time Complexity: O(n)
This function frees the Runner array created 
*/
void freeArray(Runner *array){
    free(array);  //frees array created 
}