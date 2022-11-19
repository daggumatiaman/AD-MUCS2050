#include <stdio.h>

double * createDoubleArray(int n);
int getDoublesize(double *array);
void freeIntArray(double *array);


int main(void) {
  double * mainArray = NULL; 
  int n = 8; 
  int size = 0; 
  mainArray = createDoubleArray(n); 
  size = getDoubleArraysize(mainArray); 
  
  printf("%d", size); 
  
  freeDoubleArray(mainArray); 
  
}

double * createDoubleArray(int n){

  int * dblArray = NULL; 
  dblArray = (int *) malloc (n * sizeof (double ) + sizeof(int)); 

   if ( dblArray == NULL )
  {
     printf( "\nAllocation was not successful!" );
     return -1;
  }

  int size = 0;
  dblArray[0] = size; 
  
    
  return ((double*)(++array));  
}
  
int getDoubleSize(double *array){
  int * intarr = (int*)(array); // turns the doulbe pointer back into an int pointer so it can use the value that was in the first four bytes in the last function that also has the size value in it 
  
  return intarr[-1];   //returns that size  
}

void freeDoubleArray(double *array){
  int * ogarray = (int*)(array); 
  ogarray = ogarray[-1]; 
  free(ogarray); 
  
}

void * createArray(int n, int dataTypeSize){
  
}