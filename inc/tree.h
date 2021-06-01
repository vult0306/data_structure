#include <stdlib.h>
#include <stdbool.h>

struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
};

extern struct treenode* treenode_create(unsigned value);
extern struct treenode* insert_left(struct treenode* root, int value);
extern struct treenode* insert_right(struct treenode* root, int value);
extern bool isfullbinarytree(struct treenode* root);
extern bool isperfectbinarytree(struct treenode* root);
extern void inorder_travesal(struct treenode* root);
extern void preorder_travesal(struct treenode* root);
extern void postorder_travesal(struct treenode* root);