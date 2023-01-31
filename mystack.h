/*  ========== H03 - Personal Stack Implementation ============
 *
 *   Student: Aidan Schrier
 *   Semester: Spring 2023
 *
 * A simple stack implementation to hold int values.
 *
 */

#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

/** Stores the maximum 'depth' of our stack.
(i.e. capacity cannot exceed MAX_DEPTH for any stack) **/
#define MAX_DEPTH 32

/** Create a node data structure to store data within
our stack. In our case, we will stores 'integers' */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/** Create a stack data structure
* Our stack holds a single pointer to a node, which
* is a linked list of nodes. 
**/
typedef struct stack
{
    int count;             // count keeps track of how many items
                           // are in the stack.
    unsigned int capacity; // Stores the maximum size of our stack
    node_t *head;          // head points to a node on the top of our stack.
} stack_t;


/**  Creates a stack
* Returns a pointer to a newly created stack.
* The stack should be initialized with data on the heap.
* (Think about what the means in terms of memory allocation)
* The stacks fields should also be initialized to default values.
*/
stack_t *create_stack(unsigned int capacity)
{
    stack_t *myStack = (stack_t *)malloc(sizeof(stack_t));
    if (myStack == NULL){
        return NULL;
    }
    myStack->count = 0;
    myStack->capacity = capacity;
    myStack->head = NULL;

    return myStack;
}

/** Check if the stack is empty
* Returns 1 if true (The stack is completely empty)
* Returns 0 if false (the stack has at least one element enqueued)
*/
int stack_empty(stack_t *s)
{
    if (s->count == 0){
        return 1;
    }

    return 0;
}

/** Check if the stack is full
* Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
* Returns 0 if false (the Stack has more space available to enqueue items)
**/
int stack_full(stack_t *s)
{
    if(s->count == s->capacity){
        return 1;
    }

    return 0;
}

/** Enqueue a new item
* i.e. push a new item into our data structure
* Returns a -1 if the operation fails (otherwise returns 0 on success).
*    -> if the Stack is full that is an error, but does not crash the program.
**/
int stack_enqueue(stack_t *s, int item)
{
    if (s->count == s->capacity){return -1;}
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if(newNode == NULL){return -1;}
    newNode->data = item;
    newNode->next = s->head;
    s->head = newNode;
    s->count ++;
    return  0; 
}

/** Dequeue an item
*   Returns the item at the front of the stack and
*   removes an item from the stack.
*   Removing an item from the empty stack should
*   print to stderr, and return the EXIT_FAILURE value
*   Example:
     fputs("no items to dequeue!\n", stderr);
     return EXIT_FAILURE
**/
int stack_dequeue(stack_t *s)
{
    if (s->count == 0) {
        fputs("No items to dequeue/n", stderr);
        return EXIT_FAILURE;
    }
    int plucked_data = s->head->data;
    node_t* new_head = s->head->next;
    free(s->head);
    s->head = new_head;
    s->count --;

    return plucked_data; 
}


/** returns the size of the stack. If the
 * stack hasn't been properly recreated, print to stderr, 
 * and return -1 
*/
unsigned int stack_size(stack_t *s)
{
    return s->count;
}

/** 
Frees all items in a list, starting from the head.
*/
void free_list(node_t* activeNode){
    node_t* nextNode;
    while (activeNode != NULL){
        nextNode = activeNode->next;
        free(activeNode);
        activeNode = nextNode;
    }
}

/** Removes a stack and ALL of its elements from memory.
 *  This should be called before any program terminates.
 *  Simple ignores if an invalid stack is passed to it.
 **/
void free_stack(stack_t *s)
{
    if (s != NULL){
        free_list(s->head);
        free(s);
    }
}

#endif