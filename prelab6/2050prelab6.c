#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct List{
  void* key; 
  struct List* next; 
} List; 

List * initList(int * n);
List * insertAtHead(void*, List *, int*);
void * getAtIndex(int, List*);
int getListLength(List*);
List * freeList(List*);

int main(void) {
  int array[10];
  int error  = 0; 
  List * t = initList(&error);
  if(1 == error) printf("Error occured\n"); 
  srand(time(NULL));
  for(int i = 0; array[i] != '\0'; i++ ){
    int * j = malloc(sizeof(int)); 
    *j = rand()%10;
    insertAtHead(j,t,&error); 
    printf("%d", array[i]); 
    if(1 == error) printf("Error occured\n"); 
  }

  int location = 3; 
  int * indexamount = *((int*)getAtIndex(location, t)); 
  printf("object %d at %d", indexamount, location); 
  printf("Length: %d", getListLength(t)); 
  freeList(t); 
  return 0; 
  
}

List * initList(int * n){
  List *p; 
  p = malloc( sizeof(List)); 
  if (p != NULL){
    printf("Operation successful");
    //p -> key = n; 
    p -> next = NULL;
    *n = 0; 
    return 0;
  } else if ( p == NULL){
    printf("insufficient memory avaliable to initialize the list"); 
    *n = 1; 
    return 1;
  }
}

List * insertAtHead(void* var, List *p, int* s){
  List* new = malloc( sizeof(List)); 
  if (new != NULL){ 
    new -> next = p -> next ; 
    p -> next = new; 
    new -> key = var; 
    *s = 0; 
    
  } else if ( new == NULL){
    *s = 1; 
  }  
  return new;
}

void * getAtIndex(int num, List* p){ 
  for(int i = 0; i < num; i++){
    p = p -> next; 
  }
  return p->key;
}

int getListLength(List* p ){
  int count = 0;  
  //Move past dummy node
  p = p -> next;  
  while (p != NULL ){
    count++; 
    p = p -> next;  
  }
  return count; 
}

List * freeList(List* head){
  List * temp; 
  while(head != NULL){
    temp = head -> next; 
    head -> next = temp -> next; 
    free(temp); 
  }
  free(head);
  head = NULL; 
  return head; 
}
