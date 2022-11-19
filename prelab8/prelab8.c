#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct {
    int key;
    struct nodestruct *next;
}Node; 

typedef struct{
   Node *rear; 
   int *ec; 
   int size; 
} Queueinfo;

typedef struct queue{
    QueueInfo * info; 
}Queue; 

//int getQueueErrorCode(Queue);
Queue queueInit(); 
int enqueue(void*, Queue); 
void * dequeue(Queue);
int getQueueSize(Queue); 
void freeQueue(Queue); 
 


int main(void) {
    /*
 srand(time(NULL));
    int n;
    Queue * queue = queueInit(); 
    //if((queue=initQueue())==NULL) return -1; //error check for malloc
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    dequeue(queue, &n);
    printf("Dequeued info: %d\n", n);
    dequeue(queue, &n);
    printf("Dequeued info: %d\n", n);
    freeQueue(queue);
  return 0;
  */
}

/*
int getQueueErrorCode(Queue error){
    if ()
}
*/


Queue queueInit(){

  Queue * queue = malloc(sizeof(Queue)); 

  if (queue == NULL) return NULL; 


  //dummy -> next = NULL: 
  queue -> rear = NULL; 

  return queue; 
}



int enqueue(void * object, Queue queue){
    Queueinfo * info = queue -> info; 
  Node * new = malloc(sizeof(Node)); 

  if( new == NULL) return 1; 

  new -> key = object; 

  if( Queue -> info -> size == 0){
    new -> next = new; 
    info.rear = new; 
    
  }

  new -> next = info.rear -> next; //set the new node to point to the prev newest node
  info.rear -> next = new; //set previous rear of queue to point to new queue node
  info.rear = new; //set rear of queue to newly queued Node 

 queue.size++; 
  return 0; 
}
  

void * dequeue(Queue queue){
     Queueinfo * info = queue.info;
    if(info->rear==NULL) return 1; //*(queue.ec ) = 2;

    Node * temp = info.rear -> next; 
    
    info.rear -> next = temp -> next; 
    void * data = temp -> key; 
    free(temp);

    info.size--; 
    return data; 
}

int getQueueSize(Queue q){
    Queueinfo * info = q.info; 
    return info.size; 
}


void freeQueue(Queue q){    
    Queueinfo * info = q.info;
    Node * temp = info.rear -> next; 

    while( temp -> next != NULL){
        free(temp -> next); 
        temp -> next = temp -> next -> next; 
    }

    free(temp); 
    
}