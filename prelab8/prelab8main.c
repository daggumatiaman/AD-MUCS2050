#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
    int key;
    struct nodestruct *next;
)Node; 

typedef struct{
   Node *front, *rear; 
} Queue; 

int getQueueErrorCode(Queue);
Queue queueInit(); 
int enqueue(void*, Queue); 
void * dequeue(Queue);
int getQueueSize(Queue); 
void freeQueue(Queue); 



int main(void) {
  printf("Hello World\n");
  return 0;
}


int getQueueErrorCode(Queue){
  
}

Queue queueInit(){
  Queue * queue = malloc(sizeof(Queue)); 

  if (queue == NULL) return NULL; 

  queue -> rear = NULL; 

  return queue; 
}

int enqueue(void * object, Queue * queue){
  
}