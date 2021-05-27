#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct dataItem {
        int data;
        int key;
};

extern struct dataItem* hashArray[SIZE];
extern struct dataItem* dummyItem;
extern struct dataItem* item;

extern int hashCode(int key);
extern void insert(int data, int key);
extern struct dataItem* search(int key);
extern struct dataItem* delete(struct dataItem* item);
extern void display();