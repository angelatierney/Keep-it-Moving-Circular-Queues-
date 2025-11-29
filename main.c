#include <stdio.h>
#include "queue.h"


int main() {
    queue_t my_queue;
    //1. initalize circular queue size 10 
    queue_init(&my_queue, 10);
    printf("queue initalized size 10\n"); 

    //2.enqueue ints 1 thro 10 
    for (int i= 1; i<= 10; i++){ 
	    if(queue_enqueue(&my_queue, i)){
		    printf("enqueued: %d\n", i); 
	    }else{
		    printf("failed to enqueue: %d (could be full)\n", i); 
	    }
    }
    //3. attemopt to enqueue one more value (should fail) 
    if (!queue_enqueue(&my_queue, 11)) {
	    printf("queue is full. cant enqueue 11\n"); 
    }

    //4. dequeue 2 elements 2 elements and print them 
    int value; 
    for (int i= 0; i<2; i++){
	    if(queue_dequeue(&my_queue, &value)){
		    printf("dequeued: %d\n", value); 
	    }else{
		    printf("queue is empty"); 
	    }
    }
    //5. print full queue contents 
    printf("current queue: \n"); 
    queue_print(&my_queue); 

    //6. free queue memory 
    printf("queue memory freed\n"); 

    return 0; 


}
