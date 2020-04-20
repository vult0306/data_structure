#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct node {
        int data;
        struct node* left;
        struct node* right;
};

struct node* root = NULL;

// insert at first place
void insert(int data)
{
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        if (root == NULL) {
                root = new_node;
                return;
        }
        struct node* cur_node = (struct node*)malloc(sizeof(struct node));
        cur_node = root;
        while(cur_node != NULL) {
                if (cur_node->data > data) {
                        if (cur_node->left ==  NULL) {
                                cur_node->left = new_node;
                                return;
                        } else
                                cur_node = cur_node->left;
                } else {
                        if (cur_node->right ==  NULL) {
                                cur_node->right = new_node;
                                return;
                        } else
                                cur_node = cur_node->right;
                }
        }

        return;
}

// insert at first place
struct node* search(int data)
{
        struct node* cur_node = (struct node*)malloc(sizeof(struct node));
        cur_node = root;

        if (root == NULL) {
                return root;
        }

        while(cur_node != NULL) {
                if (cur_node->data == data)
                        return cur_node;
                else if (cur_node->data > data)
                        cur_node = cur_node->left;
                else
                        cur_node = cur_node->right;
        }

        return cur_node;
}

// in-order travesal
// recursive left node
// read root
// recursive right node
void inorder_travesal(struct node* root)
{
        if (root == NULL)
                return;
        inorder_travesal(root->left);
        printf("%d, ",root->data);
        inorder_travesal(root->right);
        return;
}

// pre-order travesal
// read root
// recursive left node
// recursive right node
void preorder_travesal(struct node* root)
{
        if (root == NULL)
                return;
        printf("%d, ",root->data);
        preorder_travesal(root->left);
        preorder_travesal(root->right);
        return;
}

// post-order travesal
// recursive left node
// recursive right node
// read root
void postorder_travesal(struct node* root)
{
        if (root == NULL)
                return;
        postorder_travesal(root->left);
        postorder_travesal(root->right);
        printf("%d, ",root->data);
        return;
}

// check if tree is empty
bool isempty(void)
{
        return (root == NULL);
}

int main(void)
{
        printf("tree data example\n");
        int n = 8;
        printf("%f\n",log(n)/log(2));
        return 0;
        insert(27);
        insert(14);
        insert(35);
        insert(19);
        insert(10);
        insert(31);
        insert(42);
        insert(13);
        insert(20);
        insert(30);
        insert(43);
        insert(32);
        insert(40);

        struct node* Item = (struct node*)malloc(sizeof(struct node));
        inorder_travesal(root);
        printf("\n");
        preorder_travesal(root);
        printf("\n");
        postorder_travesal(root);
        printf("\n");
        return 0;
}