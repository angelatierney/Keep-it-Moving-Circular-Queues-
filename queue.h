#ifndef QUEUE_H
#define QUEUE_H
#include "list.h" 
//include list.h becuase building the queue using the list.h 

/* to change frinm a linked list to a queue 
 * change list_h to queue_h 
 */ 
//linked list is LIFO 
//queue is FIFO 

typedef struct queue_s {

    /*need to point to the front - dequeue
     * need to point to the tail - enqueue
     * node_t in linked list holds int &  pointer 
     * use the queue to keep a head pointer to remove
     * user queue to keep a tail pointer for adding 
     */ 
	node_t* head; 
	node_t* tail; 
	int size; 
	int count; 
	//size is the number of elemeents in teh que 
	//count is teh current number of elements int eh queue 

} queue_t; 
//changed from node to queue


/*functions*/ 


void queue_init(queue_t* q, int n);
//allocate n nodes and connect them in a circular linked list 
//its creating a loop of n nodes using malloc 
//seat head to the first node
//seat tail to last node (before head) 
//head->next, tail-> next and it connect the circle 
//it should returnthe pointer to the new queue 


int queue_is_empty(queue_t* q);
//returns 1 (T) if queue is empty or count ==0 

int queue_is_full(queue_t* q);
//returns 1 if the queue is full or count ==size 

int queue_enqueue(queue_t* q, int value);
// if not full 
// store the value at the current tail node 
// move tail to teh next node 
// increase the count 

int queue_dequeue(queue_t* q, int* value);
//read value at the current head node 
//clear the node (set 0) 
//move head to the next node
//decrease count 

void queue_print(queue_t* q);
//prints the count number of eleemts from thte head and on 

void queue_free(queue_t* q);
//frees ALL node_t nodes and then queue_t struct 

#endif

