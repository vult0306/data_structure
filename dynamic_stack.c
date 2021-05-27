// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynamic_stack.h"
 
struct StackNode* ds_newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int ds_isEmpty(struct StackNode* root)
{
    return !root;
}
 
void ds_push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = ds_newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
 
int ds_pop(struct StackNode** root)
{
    if (ds_isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
int ds_peek(struct StackNode* root)
{
    if (ds_isEmpty(root))
        return INT_MIN;
    return root->data;
}