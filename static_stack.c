// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* ss_createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int ss_isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int ss_isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void ss_push(struct Stack* stack, int item)
{
    if (ss_isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int ss_pop(struct Stack* stack)
{
    if (ss_isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int ss_peek(struct Stack* stack)
{
    if (ss_isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}