#include <stdio.h>

// Prototypes

void freeDoubleArray( double * array, int minIndex );
double * createDoubleArray(int minIndex, int maxIndex);

int main( void ) 
{
    // Local Variables
  
    double *dblPtr = NULL;
  
    int minIndex = 10; // 1900;
    int maxIndex = 20; // 2800;
  
    printf( "\nProgram Starting...\n" );
  
    dblPtr = createDoubleArray( minIndex, maxIndex );

    // TEST: Fill array with index value

   for ( int i = minIndex; i <= maxIndex; i++ ) 
    {
      // Assign index to memory location
      
      *( dblPtr + i ) = ( i * 1.0 );
    }

    // TEST: Print the values in the array

    printf( "\n" );
    for ( int i = minIndex; i <= maxIndex; i++ ) 
    {
      printf( "[%d] --> %f\n", i, *(dblPtr + i ) );
    }
  
    // free allocated memory
    printf("Array before free: %p\n", dblPtr);
    freeDoubleArray( dblPtr, minIndex );
  printf("Array after free: %p\n", dblPtr);
   
    printf( "\nProgram Exiting...\n" );
  
    return 0;
}

// main helper functions

double * createDoubleArray( int minIndex, int maxIndex )
{
  // Local Variables
  
  double *dblPtr = NULL; //pointer to integer

  int size = maxIndex - minIndex + 1; 
  
  // Allocate appropriate memory
  
  dblPtr = (double *) malloc( size * sizeof( double ) );

  // Change starting index to be 0 so it can be indexed
  //    from minIndex to maxIndex

  dblPtr = dblPtr - minIndex; 
  
  // Check to see if allocation was successful
  
  if ( dblPtr == NULL )
  {
     printf( "\nAllocation was not successful!" );
     return -1;
  }
  
  return dblPtr;  
}

void freeDoubleArray( double *array, int minIndex )
{
  // free allocated memory, but first adjust ptr to be start
  //    of allocation

  array = array + minIndex; 
  
  free( array ); 
}