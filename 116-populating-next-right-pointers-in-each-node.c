#include<stdio.h>

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void connectRecursively(struct Node *root, struct Node *beside){
	root -> next = beside;
    if (root -> left){
        connectRecursively(root -> left, root -> right);
        connectRecursively(root -> right, beside ? beside -> left : NULL);
    }
}

struct Node *connect(struct Node *root){
	if (root) connectRecursively(root, NULL);
    return root;
}