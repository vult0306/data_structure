#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct dataItem {
        int data;
        int key;
};

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


int main(void)
{
        dummyItem = (struct dataItem*) malloc(sizeof(struct dataItem));
        dummyItem->data = -1;  
        dummyItem->key = -1; 

        insert(1, 21);
        insert(2, 71);
        insert(42, 81);
        insert(52, 91);
        insert(62, 44);
        insert(14, 32);
        insert(17, 11);
        insert(13, 78);
        insert(37, 97);

        display();
        item = search(91);

        if(item != NULL) {
                printf("Element found: %d\n", item->data);
        } else {
                printf("Element not found\n");
        }
        return 0;
}