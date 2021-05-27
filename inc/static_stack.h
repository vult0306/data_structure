// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
extern struct Stack* ss_createStack(unsigned capacity);
 
// Stack is full when top is equal to the last index
extern int ss_isFull(struct Stack* stack);
 
// Stack is empty when top is equal to -1
extern int ss_isEmpty(struct Stack* stack);
 
// Function to add an item to stack.  It increases top by 1
extern void ss_push(struct Stack* stack, int item);
 
// Function to remove an item from stack.  It decreases top by 1
extern int ss_pop(struct Stack* stack);
 
// Function to return the top from stack without removing it
extern int ss_peek(struct Stack* stack);