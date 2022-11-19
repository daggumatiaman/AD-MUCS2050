#include "lab8.h"

struct Node {
	void *data;
	Node* next; 
};

struct Queue{
	Node *rear;
	int size;
};

/* makeQueue 
	Time Complexity = O(1)
This will create and return a queue or will return NULL if failed
*/
Queue * makeQueue(){
	Queue * q = malloc(sizeof(Queue));  // creates the queue and mallocs it 

	if (q == NULL) return NULL; //test whether malloc failed or not

	q -> size = 0;  //sets size to 0
	q -> rear = NULL; //makes the rear Null in order to make it a list(queue)

	return q; //returns the queue
}



/* getSize 
	Time Complexity = O(1)
takes in the queue and returns the size of the queue
*/
int getSize(Queue * q){

	return q -> size; //returns the size stored in the struct
}



/* enQueue
	Time Complexity = O(n)
takes in the queue and the data value the user wants to add in to the queue and enqueues
it into the queue as well as adds one to the size
*/
int enQueue(Queue *q, void *data){
	Node * new = malloc(sizeof(Node)); //creates a node for adding into queue

	if (new == NULL) return 1; //tests whether malloc has failed 

	new -> data = data;  //inserts the users data into new node

	if(q -> size == 0){    //checks if size is 0 if so adds the new node to the rear 
		new -> next = new; 
		q -> rear = new; 
		q -> size++;   //adds to size and outputs 0
		return 0; 
	}

	new -> next = q -> rear -> next; //sets the new node to the old new node 
	q -> rear -> next = new;  //sets the old new to the new one created 
	q -> rear = new;  //sets rear to new node making circular linked list

	q -> size++; //adds to size 
	return 0; //return 0 success
}



/* deQueue
	Time complexity = O(1)
Takes in the queue and then dequeues at the front of the queue but if empty will return
NULL
*/
void * deQueue(Queue * q){

	if(q -> size == 0) return NULL; //check if q is empty, if so will return NULL

	Node * temp = malloc(sizeof(Node)); //setting up temp 

	temp = q -> rear -> next;  //sets temp the end of list 
	q -> rear -> next = q -> rear -> next -> next; // changes what is the end of list 
	void * key = temp -> data;  //makes data point to output it 

	q -> size--; //decreases size 

	free(temp); //frees/dequeues the node 
	return key; //returns the variable that was dequeued 
}


/* peek
	Time Complexity = O(1)
Takes in the queue and then outputs the value that would be dequeued without dequeueing it
*/
void * peek(Queue *q){

	if(q -> size == 0) return NULL; //check if q is empty, if so will return NULL

	Node * temp = malloc(sizeof(Node)); //setting up temp 

	temp = q -> rear -> next;  //sets the temp to next value 
	void * key = temp -> data;  //gets data from next value

	return key; //returns next value 
}



/* freeQueue
	Time Complexity = O(n)
takes in the queue and then frees all nodes in the queue
*/
void freeQueue(Queue *q){

	Node * temp; //create temp node to help free
	
	while( q -> rear -> next != q -> rear){ //goes through the list of nodes and frees one by one
		temp = q -> rear -> next; 
		q -> rear -> next = q -> rear -> next -> next; 
		free(temp); //frees the value before head
	}

	free(q -> rear); //frees head node

	
	q-> rear = NULL; 


	q -> size = 0;  //makes size 0
}