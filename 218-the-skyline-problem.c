#include<stdio.h>
#include<assert.h>

#define INT_MAX 2147483647

struct node{
    int x;
    int y;
    struct node* next;
};

int **getSkyline(int **buildings, int buildingsSize, int *buildingsColSize, int *returnSize, int **returnColumnSizes){
    for (int index = 0; index < buildingsSize; index += 1){
        assert(buildingsColSize[index] == 3);
    }

    int **result = (int**)malloc(sizeof(int*) * (2 * buildingsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (2 * buildingsSize));
    *returnSize = 0;

    /*
    result[0] = (int*)malloc(sizeof(int) * 2);
    result[0][0] = buildings[0][0];
    result[0][1] = buildings[0][2];
    (*returnColumnSizes)[0] = 2;
    *returnSize = 1;
    */

    struct node *tail = (struct node*)malloc(sizeof(struct node));
    tail -> x = INT_MAX;
    tail -> y = 0;
    tail -> next = NULL;

    /*
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> x = buildings[0][1];
    head -> y = buildings[0][2];
    head -> next = tail;
    */

    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    dummy -> x = 0;
    dummy -> y = 0;
    dummy -> next = tail;

    for (int index = 0; index < buildingsSize; index += 1){
        while (dummy -> next -> x < buildings[index][0]){
            struct node *old = dummy;
            dummy = dummy -> next;
            free(old);
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = dummy -> x;
            result[*returnSize][1] = dummy -> next -> y;
            (*returnColumnSizes)[*returnSize] = 2;
            *returnSize += 1;
        }
        if (buildings[index][2] > dummy -> next -> y){
            if (*returnSize && result[*returnSize - 1][0] == buildings[index][0]){
                if (result[*returnSize - 1][1] < buildings[index][2]){
                    result[*returnSize - 1][1] = buildings[index][2];
                }
            }
            else{
                result[*returnSize] = (int*)malloc(sizeof(int) * 2);
                result[*returnSize][0] = buildings[index][0];
                result[*returnSize][1] = buildings[index][2];
                (*returnColumnSizes)[*returnSize] = 2;
                *returnSize += 1;
            }
        }

        struct node *current = dummy;
        while (current -> next -> x < buildings[index][1]){
            if (current -> next -> y <= buildings[index][2]){
                struct node *old = current -> next;
                current -> next = current -> next -> next;
                free(old);
            }
            else{
                current = current -> next;
            }
        }
        if (buildings[index][2] > current -> next -> y){
            if (current -> next -> x == buildings[index][1]){
                current -> next -> y = buildings[index][2];
            }
            else{
                struct node *new = (struct node*)malloc(sizeof(struct node));
                new -> x = buildings[index][1];
                new -> y = buildings[index][2];
                new -> next = current -> next;
                current -> next = new;
            }
        }
    }

    while (dummy -> next -> next){
        struct node *old = dummy;
        dummy = dummy -> next;
        free(old);
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = dummy -> x;
        result[*returnSize][1] = dummy -> next -> y;
        (*returnColumnSizes)[*returnSize] = 2;
        *returnSize += 1;
    }
    if (dummy -> next -> y){
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = dummy -> next -> x;
        result[*returnSize][1] = 0;
        (*returnColumnSizes)[*returnSize] = 2;
        *returnSize += 1;
    }

    free(dummy -> next);
    free(dummy);

    return result;
}

void main(){
    int buildingsSize = 2;
    int *buildingsColSize = (int*)malloc(sizeof(int) * buildingsSize);
    for (int index = 0; index < buildingsSize; index += 1){
        buildingsColSize[index] = 3;
    }

    int **buildings = (int**)malloc(sizeof(int*) * buildingsSize);
    for (int index = 0; index < buildingsSize; index += 1){
        buildings[index] = (int*)malloc(sizeof(int) * 3);
    }
    buildings[0][0] = 0;
    buildings[0][1] = 2;
    buildings[0][2] = 3;
    buildings[1][0] = 2;
    buildings[1][1] = 5;
    buildings[1][2] = 3;

    int returnSize;
    int *returnColumnSizes;
    int **result = getSkyline(buildings, buildingsSize, buildingsColSize, &returnSize, &returnColumnSizes);
    for (int index = 0; index < returnSize; index += 1){
        assert(returnColumnSizes[index] == 2);
        printf("%d\t%d\n", result[index][0], result[index][1]);
    }
}