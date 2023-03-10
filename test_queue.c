/*  ========== H03 - Personal Queue Implementation ============
 *
 *   Student: Aidan Schrier
 *   Semester: Spring 2023
 *
 * A simple queue unit-tst implementation 
 *
 */

// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall queue_test.c -o queue_test
//
// Run with: ./queue_test
//

#include "myqueue.h"

#include <stdio.h> // For IO operations


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.

// Tests that a new queue was created and the capacity
// was properly set.
int unitTest1(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(30);
    if (30 == testq->capacity)
    {
        passed = 1;
    }
    free_queue(testq);

    return passed;
}

// Tests adding multiple items to a queue
int unitTest2(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(10);
    queue_enqueue(testq, 1);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 3);
    queue_enqueue(testq, 4);
    queue_enqueue(testq, 5);
    queue_enqueue(testq, 6);
    queue_enqueue(testq, 7);
    queue_enqueue(testq, 8);
    queue_enqueue(testq, 9);
    queue_enqueue(testq, 10);
    if (10 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing
int unitTest3(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing multiple times
int unitTest4(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

int unitTest5(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(1);
    queue_enqueue(testq, 1);
    if (1 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        free_queue(testq);
        return 0;
    }

    queue_dequeue(testq);
    if (0 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_queue(testq);

    return passed;
}

int unitTest6(int status)
{
    int passed = 0;
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->back = 2;
    q->front = 3;
    q->size = 3;
    q->capacity = 4;
    q->data = (int *)calloc(q->capacity, sizeof(int));

    q->data[3] = 34;
    q->data[0] = 4;
    q->data[1] = 14;

    int a = queue_dequeue(q);
    int b = queue_dequeue(q);
    int c = queue_dequeue(q);
    if(c == 14){
        passed = 1;
    }

    return passed;
    
}
//How do I make this expect to not be able to dequeue?
int testEmptyDequeue(int status){
    int passed = 0;
    queue_t *testq = create_queue(1);
    queue_dequeue(testq);
    passed = 1;
    return passed;
}

int testOverfullQueue(int status){
    int passed = 0;
    queue_t *testq = create_queue(3);
    queue_enqueue(testq, 1);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 3);
    int bad_enqueue = queue_enqueue(testq, 4);
    if (bad_enqueue == -1){
        passed = 1;
    }
    return passed;
}

int testDequeueValue(int status){
    int passed = 1;
    queue_t *testq = create_queue(3);
    queue_enqueue(testq, 1);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 3);
    int dequeued = queue_dequeue(testq);
    if (dequeued == 1){
        passed = 1;
    }
    return passed;
}

// TODO: Add more tests here
// add your own, and uncomment the provided tests as 
// things are implemented
int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    testEmptyDequeue,
    testOverfullQueue,
    testDequeueValue,
    NULL};
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter + 1);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}