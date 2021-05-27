// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
// A structure to represent a stack
struct StackNode {
    int data;
    struct StackNode* next;
};

extern struct StackNode* ds_newNode(int data);
extern int ds_isEmpty(struct StackNode* root);
extern void ds_push(struct StackNode** root, int data);
extern int ds_pop(struct StackNode** root);
extern int ds_peek(struct StackNode* root);