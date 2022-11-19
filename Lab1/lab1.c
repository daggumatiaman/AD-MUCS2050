#include "lab1.h"
/* getMax
    takes an integer sizeand the array given from main and checks if the array is NULL 
    or not, if it is then it will return -1 otherwise itll return 0 and same for if the size is at least 1 or not. 
    The rest of the function is checking for the maximum value the outputig it. 


*/
int getMax(int size, int *array, int *result){
    int max = 0; 
    if (array != NULL){
       printf("Success\n");
 

    for(int i = 0; i < size - 1; i++){
       if(array[i] >= array[i + 1]){
        max = array[i];
        
       }
       else if (array[i] <= array[i + 1]){
        max = array[i + 1];
       
       }
       else if (array[i] == array[i + 1]){
        max = array[i + 1]; 
        
       }

    }
    printf("Maximum value is %d\n", max);
    *result = max;

        return 0;
    } else {
        printf("Failure: array pointer = NULL\n");

        return -1;
    }

    if(size < 1){
        printf("Failure: size is less than 1\n");
        return -1; 
    } else {
        printf("Success\n");
 

    for(int i = 0; i < size - 1; i++){
       if(array[i] >= array[i + 1]){
        max = array[i];
        printf("Greater value is %d\n", array[i]);
       }
       else if (array[i] <= array[i + 1]){
        max = array[i + 1];
        printf("Greater value is %d\n", array[i + 1]);
       }
       else if (array[i] == array[i + 1]){
        max = array[i + 1]; 
        printf("Comparison is the same with value %d\n", array[i + 1]);
       }

    }
    printf("Maximum value is %d\n", max);
    *result = max;

        return 0;
    }

    


}