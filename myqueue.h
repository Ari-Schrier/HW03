
/*  ========== H03 - Personal Queue Implementation ============
 *
 *   Student: UPDATE
 *   Semester: UPDATE
 *
 * A simple queue implementation to hold int values.
 *
 */
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h> // for malloc/free

// The main data structure for the queue
struct queue
{
    unsigned int back;     // The next free position in the queue
                           // (i.e. the end or tail of the line)
    unsigned int front;    // Current 'head' of the queue
                           // (i.e. the front or head of the line)
    unsigned int size;     // How many total elements we currently have enqueued.
    unsigned int capacity; // Maximum number of items the queue can hold
    int *data;             // The 'integer' data our queue holds
};
// Creates a global definition of 'queue_t' so we
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

/** Create a queue
 * Returns a pointer to a newly created queue.
 * data should be stored on the heap (malloc)
 */
queue_t *create_queue(unsigned int _capacity)
{
    queue_t *myQueue = NULL;
    // TODO: Implement me!

    return myQueue;
}

/** Check if the queue is empty
 *  Returns 1 if true (The queue is completely empty)
 * Returns 0 if false (the queue has at least one element enqueued)
 **/
int queue_empty(queue_t *q)
{
    // TODO: Implement me!

    return NULL;
}

/** Check if the queue is Full
 *  Returns 1 if true (The queue is completely full)
 *  Returns 0 if false (the queue has more space available to enqueue items)
 **/
int queue_full(queue_t *q)
{
    // TODO: Implement me!

    return NULL;
}

/** Enqueue a new item
 *  push a new item into our data structure
 *  Returns a -1 if the operation fails (otherwise returns 0 on success).
 **/
int queue_enqueue(queue_t *q, int item)
{
    // TODO: Implement me!

    return NULL;
}

/** Dequeue an item
 *  Returns the item at the front of the queue and
 *  removes an item from the queue.
 *  Removing an item from the empty queue should
 *  print to stderr, and return the EXIT_FAILURE value
 *   Example:
     fputs("no items to dequeue!\n", stderr);
     return EXIT_FAILURE
 */
int queue_dequeue(queue_t *q)
{
    // TODO: Implement me!

    return NULL; // Note: This line is a filler so the code compiles.
}

/** Queries the current size of a queue
 *  A queue that has not been created, should return size -1,
 *  and print a warning to standard error (see above)
 **/
unsigned int queue_size(queue_t *q)
{
    // TODO: Implement me!

    return NULL;
}

/** Removes a queue and all of its elements from memory.
 *  This should be called before the program terminates.
 *  If the queue doesn't exist, simply ignore it
 **/
void free_queue(queue_t *q)
{
    // TODO: Implement me!
}

#endif