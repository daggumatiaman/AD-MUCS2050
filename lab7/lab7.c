#include "lab7.h"

/* MakeList 
returns a pointer to a list that is empty and makes it and returns NULL if it doesnt 
work properly
*/

Node * makeList(){
    //initializing local variables 
    Node * list = malloc(sizeof(Node)); 

    //checking if NULL 
    if(list != NULL){
        list -> next = NULL;  

    //initializing new 
        Node * new = malloc(sizeof(Node));
        
        //making new attach to list and then returning it 
        new -> next = list; 
        new -> data = NULL; 
        return new; 

    } else {
        //otherwise returning NULL 
        return NULL; 
    }
}



/* getSize 
This function takes the list and then counts the size and returns int
*/
int getSize(Node *head){
    //intializing local variables 
    int count = 0; 
    //excluding dummy node 
    head = head -> next; 

    //checking if null and then counting size 
    while(head != NULL){
        count++; 
        head = head -> next; 
    }

    //returning size 
    return count - 2; 
}



int insertAtIndex(Node *head, void *data, int index){

  int i = 0; 
  Node * fn = malloc(sizeof(Node));
  Node * temp; 

  fn -> data = data; 
  fn -> next = NULL; 
  temp =  head -> next; 
  for (i = 0; i < index ; i++){
    temp = temp -> next; 
    if(temp == NULL){
        return 0;  
    }
  }
   if (temp != NULL){
    fn -> next = temp -> next; 
    temp -> next = fn; 
    return 1; 
   } else {
    return 0; 
   }


}



void * removeFromHead(Node *head){
    head = head -> next; 

    if(head -> data == NULL) {
        return NULL; 
    }

    Node * temp = head -> next; 
    head -> next = temp -> next; 
    free(temp); 
    return head -> data; 
}



void * getAtIndex(Node * head, int index){
    int i = 0;
    head = head -> next; 
    Node * temp = head; 
    for (i = 0; i < index ; i++){
    temp = temp -> next; 
  }

   return temp -> data; 
}



/*freeList 
freeing the node and list
*/
void freeList(Node *head){
    while(head -> next != NULL){
        removeFromHead(head); 
    }

    free(head); 

}