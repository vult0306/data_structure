#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

struct treenode* treenode_create(unsigned value)
{
    struct treenode *new_node = (struct treenode*)malloc(sizeof(struct treenode));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct treenode* insert_left(struct treenode* root, int value)
{
    root->left = treenode_create(value);
    return root->left;
}

struct treenode* insert_right(struct treenode* root, int value)
{
    root->right = treenode_create(value);
    return root->right;
}

bool isfullbinarytree(struct treenode* root)
{
    // check if tree is empty
    if (root == NULL)
        return true;
    
    // check the presence of children
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->left && root->right)
        return (isfullbinarytree(root->left) && isfullbinarytree(root->right));
}

int depth(struct treenode* root)
{
    int d=0;
    while(root != NULL) {
        d++;
        root = root->left;
    }
    return d;
}

bool isperfect(struct treenode* root, int d, int level)
{
    if (root == NULL)
        return true;
    
    if (root->left ==  NULL && root->right ==  NULL)
        return (d == level+1);
    
    if (root->left ==  NULL || root->right ==  NULL)
        return false;
    
    return (isperfect(root->left, d, level+1) && isperfect(root->right, d, level+1));
}

bool isperfectbinarytree(struct treenode* root)
{
    int d = depth(root);
    return isperfect(root, d, 0);
}

void inorder_travesal(struct treenode* root)
{
    if (root == NULL) return;
    inorder_travesal(root->left);
    printf("%d, ",root->data);
    inorder_travesal(root->right);
}

void preorder_travesal(struct treenode* root)
{
    if (root == NULL) return;
    printf("%d, ",root->data);
    inorder_travesal(root->left);
    inorder_travesal(root->right);
}
void postorder_travesal(struct treenode* root)
{
    if (root == NULL) return;
    inorder_travesal(root->left);
    inorder_travesal(root->right);
    printf("%d, ",root->data);
}