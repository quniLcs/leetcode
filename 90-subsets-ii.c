#include<stdio.h>
#include"uthash.h"


struct hashItem{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int ikey){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &ikey, item);
    return item;
}

void hashEdit(int ikey){
    struct hashItem *item = hashFind(ikey);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> key = ikey;
        item -> val = 1;
        HASH_ADD_INT(hashTable, key, item);
    }
    else{
        item -> val += 1;
    }
}


int **ans;
int *ansColumnSizes;
int ansSize;

int *cur;
int curSize;

void subsetsRecursively(){
    if (hashTable == NULL){
        ans[ansSize] = (int*)malloc(sizeof(int) * curSize);
        memcpy(ans[ansSize], cur, sizeof(int) * curSize);
        ansColumnSizes[ansSize] = curSize;
        ansSize += 1;
    }
    else{
        struct hashItem *item = hashTable;
        hashTable = hashTable -> hh.next;

        subsetsRecursively();        
        for (int index = 1; index <= item -> val; index += 1){
            cur[curSize] = item -> key;
            curSize += 1;
            subsetsRecursively();
        }

        curSize -= item -> val;
        hashTable = item;
    }
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    ans = (int**)malloc(sizeof(int*) * (1 << numsSize));
    ansColumnSizes = (int*)malloc(sizeof(int) * (1 << numsSize));
    ansSize = 0;

    cur = (int*)malloc(sizeof(int) * numsSize);
    curSize = 0;

    hashTable = NULL;
    for (int index = 0; index < numsSize; index += 1){
        hashEdit(nums[index]);
    }

    subsetsRecursively();
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSizes;
    return ans;
}