#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashing.h"

// #define SIZE 20

// struct dataItem {
//         int data;
//         int key;
// };

struct dataItem* hashArray[SIZE];
struct dataItem* dummyItem;
struct dataItem* item;

int hashCode(int key) {
        return key%SIZE;
}


// insert at first place
void insert(int data, int key)
{
        struct dataItem* new_item = (struct dataItem*)malloc(sizeof(struct dataItem));
        new_item->data = data;
        new_item->key = key;

        //calculate hash index
        int hashIndex = hashCode(key);
        while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
                hashIndex += 1;
                hashIndex %= SIZE;
        }
        hashArray[hashIndex] = new_item;
}

struct dataItem* search(int key)
{
        // get hash index
        int hashIndex = hashCode(key);

        // move in array until find empty
        while(hashArray[hashIndex] != NULL) {
                if (hashArray[hashIndex]->key == key)
                        return hashArray[hashIndex];

                hashIndex += 1;
                hashIndex %= SIZE;
        }
        return NULL;
}

struct dataItem* delete(struct dataItem* item)
{
        int key = item->key;
        //get hash index
        int hashIndex = hashCode(key);

        while(hashArray[hashIndex] != NULL) {
                if (hashArray[hashIndex]->key == key){
                        struct dataItem* temp = hashArray[hashIndex];
                        hashArray[hashIndex] = dummyItem;
                        return temp;
                }

                hashIndex += 1;
                hashIndex %= SIZE;
        }
        return NULL;
}
// display the list
void display() {
        int i = 0;
	
        for(i = 0; i<SIZE; i++) {
                if(hashArray[i] != NULL)
                        printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
                else
                        printf(" ~~ ");
        }

        printf("\n");
}
