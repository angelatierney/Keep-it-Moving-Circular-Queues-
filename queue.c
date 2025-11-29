#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*queue willl need a special marker like -999
 * inidcates the node is unused*/ 

#define UNUSED -999


/*
Purpose: Initializes a queue with a circular linked list.
Parameters:
- q: A pointer to the queue structure (queue_t) to initialize.
- n: The size (maximum number of nodes) for the queue.
Return: None.
*/
void queue_init(queue_t* q, int n){
	//setting size and count 
	q ->size = n; 
	q-> count= 0; 
	//size max is n
	//count is 0 and empty 

	/*allocate nnodes adn connect them in a circular linked list*/
	node_t* first= malloc(sizeof(node_t)); 
	if (first == NULL) {
		printf("allocation FAIL\n"); 
		return; 
	       //if memory alocation failed
	}	

	//allocate memory for a node 
	first ->value = UNUSED; 
	//sets value to unused marker 
	
	//allocate the link and the rest of the nodes 
	first -> next = first;
	q->head = first; 
        node_t* curr = first;

	//curr starts at first 
	for(int i= 1; i< n; i++){
		/*create a new node 
		 * set current nodes next to the new node 
		 * move to the new node*/
		//create a new node 
		node_t* new_node = malloc(sizeof(node_t));
		if(new_node == NULL){
			printf("memeory allocation issue\n"); 
			return; 
		}
		//move to the next node
		//value is an int ts the data the node stores 
		//mark unused 
		new_node->value = UNUSED; 
		//move to the next node 
		curr-> next= new_node;
	        //connects current node to teh next one	
		curr = new_node; 
		//move curr forward to th enew node 

		
	}


	curr-> next= first; 
	//makes it circular
	q->tail = curr;   	
} 

/*
Purpose: Checks if the queue is empty.
Parameters:
- q: A pointer to the queue structure to check.
Return: 1 if the queue is empty, 0 otherwise.
*/

int queue_is_empty(queue_t* q) {
	//check if its empty 
	return (q->count == 0); 

}

/*
Purpose: Checks if the queue is full.
Parameters:
- q: A pointer to the queue structure to check.
Return: 1 if the queue is full, 0 otherwise.
*/

int queue_is_full(queue_t* q) {
	/*checking if queue is full comparing the current count to max size */
	return (q-> count == q-> size); 
	//size = to n which is the max size
}
/*
Purpose: Adds a value to the queue.
Parameters:
- q: A pointer to the queue where the value will be enqueued.
- value: The value to enqueue.
Return: 1 if successful, 0 if the queue is full.
*/
int queue_enqueue(queue_t* q, int value) {
	/*call the queue is full function*/
	if(queue_is_full(q)){
		return 0; 
		//full and cant enqueue
	}
	//allocate memory for new node 
	 node_t* new_node = malloc(sizeof(node_t));
	 if (new_node == NULL) {
		 return 0; 
	 }
	 new_node->value = value;
	 new_node->next = NULL;

	if (queue_is_empty(q)) {
	       q->head = new_node;
	       q->tail = new_node;
	       new_node->next = q->head;
	}else{
		q->tail->next = new_node;
		q->tail = new_node;
		q->tail->next = q->head;
	}
	//increment the count 
	q-> count++; 
	return 1; 
}

/*
Purpose: Removes a value from the queue.
Parameters:
- q: A pointer to the queue from which the value will be dequeued.
- value: A pointer to store the dequeued value.
Return: 1 if successful, 0 if the queue is empty.
*/
int queue_dequeue(queue_t* q, int* value) {
	//if queue is empty then return 0, call is emoty function 
	if(queue_is_empty(q)){
		return 0; 
	}
	/*get the value from the head node 
	 */
	*value = q->head -> value;

	//mark the head node as unused 
	q-> head -> value= UNUSED; 

	//move head pointer forward 
	q->head = q->head->next;

	//deincrement count 
	q-> count --; 

	return 1; 
}


/*
Purpose: Prints the values of the queue in the order they are stored.
Parameters:
- q: A pointer to the queue to print.
Return: None.
*/
void queue_print(queue_t* q) {
	if (queue_is_empty(q)){
	       	printf("Queue is empty. Oops\n");
		return;
	}
	if (q->head == NULL || q->tail == NULL) {
		printf("Queue has invalid pointers. Something went wrong!\n");
		return; 
	}
	printf("Head value: %d\n", q->head->value);
	printf("Tail value: %d\n", q->tail->value);

	node_t* curr = q->head;
	int count = 0;

	//traverse the circular linked list 
	do {
		printf("Node value: %d\n", curr->value);
		curr = curr->next;
		count++;
	}while (curr != q->head);
	printf("Queue traversal complete, total nodes: %d\n", count);
}

/*
Purpose: Frees the memory allocated for the queue and its nodes.
Parameters:
- q: A pointer to the queue to free.
Return: None.
*/

void queue_free(queue_t* q){ 
	if(q == NULL ||q -> head ==NULL){
		return; 
	}
	//set the current to the head 
	//set the next node ot null 
	//two pointers to the head of the q 
	//curr points to hte head 
	//next_node is a temp pointer 
	node_t* curr= q->head; 	
	node_t* next_node;

	/*loop if current is not null*/
	for (int i = 0; i< q-> size; i++){
		next_node= curr -> next; 
		free (curr); 
		curr = next_node; 
	}
	q-> head = NULL; 
	q-> tail = NULL; 
        q -> count = 0; 	

}

