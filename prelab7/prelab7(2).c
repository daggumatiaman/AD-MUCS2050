#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct{
  void* key; 
  struct nodestruct* next; 
} Node;

typedef struct{
Node *head, *tail;
int size; 
} List; 

List * initList();

int insertAtHead(void*, List);
int insertAtTail(void*, List);

void * removeHead(List);
void * removeTail(List);

void freeList(List);

int main(void) {
  
}

List * initList(){
  List *p = malloc( sizeof(List)); 
  if (p != NULL){
    printf("Operation successful");
    //p -> key = n; 
    p -> head -> next = NULL;
  
    Node * dummy = malloc(sizeof(Node));   

    dummy -> next = NULL;

    p -> head = dummy; 
    p-> tail = NULL; 
    
  } else{
    printf("insufficient memory avaliable to initialize the list");  
  }
  return p;
}


int insertAtHead(void* var, List list){
 Node * new = malloc(sizeof(Node));

if (new != NULL){
new -> next = list.head -> next; 
list.head -> next = new; 
new -> key = var; 
  return 0; 
  } else {
  return 1; 
  }
}

int insertAtTail(void * var, List list){
  Node * new = malloc(sizeof(Node)); 

  if (new != NULL){
    Node * i = list.head -> next; 
while((i -> next = NULL)){ 
    i = i -> next; 
  }
    i -> next = new; 
    new -> key = var; 
    return 0; 
    
  }else{
    return 1; 
  }
}


void * removeHead(List list){
  
  Node * temp = list.head -> next; 
  list.head -> next = temp -> next;
} 

void freeList(List list){
  List * temp; 
  while(list.head -> next != NULL){
   removeHead(list);
}
  free(list.head);
  }