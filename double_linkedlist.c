#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
        int data;
        int key;
        struct node* next;
        struct node* prev;
};

struct node* head = NULL;

// display the list
void display()
{
        struct node* node_ptr = head;
        while (node_ptr != NULL) {
                printf("data: %d, key: %d\n",node_ptr->data,node_ptr->key);
                node_ptr = node_ptr->next;
        }
        return;
}

// insert at first place
void insert(int data, int key)
{
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->key = key;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
}

// insert at the end
void insertLast(int data, int key)
{
        struct node* new_node = (struct node*)malloc(sizeof(struct node));

        if (head == NULL) {
                new_node->next = NULL;
                new_node->prev = NULL;
                new_node->data = data;
                new_node->key = key;
                head = new_node;
        } else {
                struct node* cur_node = head;
                while(cur_node->next != NULL)
                        cur_node = cur_node->next;

                cur_node->next = new_node;
                new_node->next = NULL;
                new_node->prev = cur_node;
                new_node->data = data;
                new_node->key = key;
        }
        return;
}

// delete at first place
struct node* delete(void)
{
        if (head == NULL) return head;
        struct node* del_node = head;
        //only one link
        if (head->next != NULL)
                head->next->prev = NULL;
        head = head->next;
        return del_node;
}

// delete at last place
struct node* deleteLast(void)
{
        if (head == NULL) return head;
        struct node* del_node = head;
        struct node* prev_node = NULL;

        if (del_node->next == NULL) {
                del_node = NULL;
                head = del_node;
        }
        else {
                while (del_node->next != NULL) {
                        prev_node = del_node;
                        del_node = del_node->next;
                }
                prev_node->next = NULL;
        }

        return del_node;
}

// check if link is empty
bool isempty(void)
{
        return (head == NULL);
}

int length()
{
        int len = 0;
        struct node* cur_node = head;
        while (cur_node) {
                len += 1;
                cur_node = cur_node->next;
        }
        return len;
}

struct node* find(int key)
{
        if (head == NULL)
                return head;
        struct node* cur_node = head;
        while (cur_node->key != key) {
                if (cur_node->next == NULL)
                        return NULL;
                cur_node = cur_node->next;
        }
        return cur_node;
}

struct node* delete_node(int key)
{
        if (head == NULL)
                return NULL;
        struct node* del_node = head;
        struct node* pre_node = NULL;
        
        while(del_node->key != key){
                if (del_node->next == NULL)
                        return NULL;
                else {
                        pre_node = del_node;
                        del_node = del_node->next;
                }
        }
        
        pre_node->next = del_node->next;
        return del_node;
}

void sort()
{
        int n = length();
        int i = 0;
        int j = 0;
        int k = n;
        struct node* cur_node = head;
        struct node* next_node = cur_node->next;
        int temp_data;
        int temp_key;
        for (i = 0; i < n-1; i++,k--){
                cur_node = head;
                next_node = head->next;
                for (j = 1; j < k; j++){
                        if (cur_node->data > next_node->data){
                                temp_data = cur_node->data;
                                cur_node->data = next_node->data;
                                next_node->data = temp_data;
                                temp_key = cur_node->key;
                                cur_node->key = next_node->key;
                                next_node->key = temp_key;
                        }
                        cur_node = cur_node->next;
                        next_node = next_node->next;
                }
        }
}

int main(void)
{
        printf("data structure example\n");
        insert(1,1);
        insert(2,2);
        insert(3,3);
        insert(4,4);
        insert(5,5);
        insert(5,6);
        insert(4,7);
        insert(3,8);
        insert(2,9);
        insert(1,10);
        if(!isempty())
                printf("num node: %d\n", length());
        printf("delete the first node...\n");
        delete();
        display();
        printf("find node with key = 3\n");
        struct node* node_find = find(3);
                if (node_find == NULL)
                        printf("not found\n");
                else
                        printf("node 3(data/key): (%d/%d)\n",node_find->data,node_find->key);
        printf("delete node with key = 3\n");
        delete_node(3);
        display();
        printf("sort list\n");
        sort();
        display();
        printf("insertLast\n");
        insertLast(13,34);
        display();
        printf("deletelast\n");
        deleteLast();
        display();
        return 0;
}