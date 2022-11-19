#include <stdio.h>

float * readFloatFileIntoArray( FILE *fPtr, int *length )
{
  // Local Variables
  
  float* floatArray;
  
  // Read in 1st line that has # of floats following

  printf( "before length: %d\n", *length );
  fscanf( fPtr, "%d", length );
  printf( "after length: %d\n", *length );

  // Allocate for array to hold floats

  floatArray = (float *) malloc( *length*sizeof( float ) );

  printf( "after allocation\n" );
  
  // Test allocation
  
  if ( floatArray == NULL )
  {
    printf( "Allocation failed!\n" );
    return -1;
  }

  printf( "---got here\n" );
    
  // Read floats into array

  for ( int i = 0; i < *length; i++ )
  {
    printf( "%d\n", i );
    fscanf( fPtr, "%f", ( floatArray + i ) );
    
    //printf( "%d %f\n", i-1, floatArray[ i ] );
  }

  return floatArray;
}

void freeFloatArray( float **x )
{
  free( x );
  x = NULL;
}

int main() 
{
  // Local Variables
  
	FILE *fPtr; 
	float* floatArray;

  int length = 0;

  printf( "Got here!\n" );
  
  fPtr = fopen( "file.txt", "r" );
  if ( !fPtr ) 
  {
    printf( "Error opening file\n" );
	  return -1;
  }

  printf( "File was opened!\n" );

  floatArray = readFloatFileIntoArray( fPtr, &length );

  // Display array of floats for verification

  for ( int i = 0; i < length; i++ )
  {
    printf( "%f\n", *( floatArray + i ) );
  }

  freeFloatArray( floatArray );
  
  printf( "Closing File!\n" );
  
  fclose( fPtr ); // closing of file
        
  return  0;
}