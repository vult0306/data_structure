// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
extern struct Queue* q_createQueue(unsigned capacity);
 
// Queue is full when size becomes
// equal to the capacity
extern int q_isFull(struct Queue* queue);
 
// Queue is empty when size is 0
extern int q_isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
// It changes rear and size
extern void q_enqueue(struct Queue* queue, int item);
 
// Function to remove an item from queue.
// It changes front and size
extern int q_dequeue(struct Queue* queue);
 
// Function to get front of queue
extern int q_front(struct Queue* queue);
 
// Function to get rear of queue
extern int q_rear(struct Queue* queue);