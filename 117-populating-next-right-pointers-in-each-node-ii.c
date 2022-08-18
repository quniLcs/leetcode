#include<stdio.h>
#include<stdbool.h>

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node *root){
    struct Node *current = root;
    struct Node *reference = NULL;
    bool isLeft = true;

    while (current){
        struct Node *start = current;

        while (reference){
            while (reference && reference -> left == NULL && reference -> right == NULL){
                reference = reference -> next;
            }
            if (reference){
                if (isLeft && reference -> left){
                    current = current -> next = reference -> left;
                    if (reference -> right) isLeft = false;
                    else reference = reference -> next;
                }
                else{
                    current = current -> next = reference -> right;
                    isLeft = true;
                    reference = reference -> next;
                }
            }
        }

        current = NULL;
        reference = start;
        while (reference && reference -> left == NULL && reference -> right == NULL){
            reference = reference -> next;
        }
        if (reference){
            if (reference -> left){
                current = reference -> left;
                if (reference -> right) isLeft = false;
                else reference = reference -> next;
            }
            else{
                current = reference -> right;
                reference = reference -> next;
            }
        }
    }

    return root;
}