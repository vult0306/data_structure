// CPP program to construct binary 
// tree from given array in level 
// order fashion Tree Node 
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, 
pointer to left child and a 
pointer to right child */
struct node 
{ 
	int data; 
	struct node* left, * right; 
}; 

/* Helper function that allocates a 
new node */
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Function to insert nodes in level order 
struct node* insertLevelOrder(int arr[], struct node* root, int i, int n) 
{ 
	// Base case for recursion 
	if (i < n && arr[i] != -1)
	{ 
		struct node* temp = newNode(arr[i]); 
		root = temp;

		// insert left child 
		root->left = insertLevelOrder(arr, 
			root->left, 2 * i + 1, n); 

		// insert right child 
		root->right = insertLevelOrder(arr, 
			root->right, 2 * i + 2, n); 
	} 
	return root; 
} 

// Function to print tree nodes in 
// InOrder fashion 
void inOrder(struct node* root) 
{ 
	if (root != NULL) 
	{ 
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	} 
} 

void sum_branch(struct node* root, int* sum) 
{ 
        *sum += root->data;
	if (root->left != NULL) { 
                sum_branch(root->left, sum);
	}
	if (root->right != NULL) { 
                sum_branch(root->right, sum);
	}
}

// Driver program to test above function 
int main() 
{ 
	// int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; 
        int arr[] = { 3, 6, 2, 9,-1, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
        int sum = 0;
	struct node* root = insertLevelOrder(arr, root, 0, n); 
	inOrder(root->left);
        inOrder(root->right);
        // sum_branch(root->left,&sum);
        // printf("%d \n",sum);
        // sum = 0;
        // sum_branch(root->right,&sum);
        // printf("%d \n",sum);
        return 0;
} 

// This code is contributed by Chhavi 
