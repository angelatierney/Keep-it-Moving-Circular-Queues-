# Keep-it-Moving-Circular-Queues-
You are now a systems engineer tasked with implementing a memory-efficient queue manager for a low-power IoT device. In this assignment, you will implement a circular queue using a singly linked list and reuse existing memory rather than dynamically allocating new nodes every time.
Goals
To gain experience with:

structs in C
dynamic memory allocation
using and adapting linked lists
implementing and testing a queue data structure
handling edge cases with memory reuse
Problem
You are now a systems engineer tasked with implementing a memory-efficient queue manager for a low-power IoT device. In this assignment, you will implement a circular queue using a singly linked list and reuse existing memory rather than dynamically allocating new nodes every time.

Analysis
[Software Engineers first attempt to determine WHAT is to be done (analysis) before determining HOW to do it (design).]

What is a queue?
A queue is a First-In-First-Out (FIFO) data structure. The first element added to the queue is the first one to be removed. Your queue will have a head and tail pointer.

You are building a circular queue using a singly linked list. That means once the tail reaches the end of the list, it wraps around to the front, reusing existing nodes. You are not allowed to use arrays for this assignment.

What operations should a queue support?
A queue must support the following:

Create an empty queue with a fixed size n
Enqueue a value (if space is available)
Dequeue a value (if the queue is not empty)
Check if the queue is full or empty
Print the queue
Free the queue memory
Design
You are given list.c and list.h which implement a basic singly linked list.
You will create queue.c and queue.h to implement the circular queue.
Your queue will preallocate n nodes during initialization and connect them in a circular fashion.
enqueue will add data to the current tail node and move the tail forward.
dequeue will return the value at head and move the head forward.
Once initialized, the queue does not allocate or free nodes during normal operation.
Track how many elements are in the queue to detect full/empty state.
Suggested functions in queue.h:

typedef struct queue_s{
    node_t* head;
    node_t* tail;
    int size;     // max size
    int count;    // current number of elements
} queue_t;

void queue_init(queue_t* q, int n); // preallocates n nodes
int queue_is_empty(queue_t* q);
int queue_is_full(queue_t* q);
int queue_enqueue(queue_t* q, int value);
int queue_dequeue(queue_t* q, int* value);
void queue_print(queue_t* q);
void queue_free(queue_t* q);
All data will be stored inside the existing node_t from list.h.

Note: Your queue will be initialized as a circular linked list with all node_ts pointing to each other in a cycle. You’ll use the value field to store meaningful data, and perhaps reserve a special marker (e.g., -999) to indicate "this node is currently unused."

Simulation
After building the queue, write a main.c that simulates the following:

Initialize a circular queue of size 10.
Enqueue integers 1 through 10.
Attempt to enqueue one more value (should fail with a warning).
Dequeue two elements and print them.
Print the full queue.
Free the queue.
Style
You are expected to follow a consistent style. Pay particular attention to:

File headers: You should have a file header at the top of every file explaining the purpose and author of the file.
Function comments: Every function should explain its purpose, parameter, and return.
Variable names: use meaningful names in all lowercase with underscore separators between words
Constant names: use all uppercase
Your code should have appropriate whitespace and avoid overly long line lengths.
You should have no warnings when compiled with gcc -Wall
Use header guards for your .h files.
Use of git: use meaningful commit messages and commit after reasonable milestones
A single commit for the whole project is not a good use of git
Functions should do one thing and one thing only.
Your program should include reasonable HCI such that the user does not have to guess what they are supposed to do.
