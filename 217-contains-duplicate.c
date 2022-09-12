#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    int kk;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int num){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &num, item);
    return item;
}

void hashInsert(int num){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item -> kk = num;
    HASH_ADD_INT(hashTable, kk, item);
}

bool containsDuplicate(int *nums, int numsSize){
    hashTable = NULL;
    for (int index = 0; index < numsSize; index += 1){
        if (hashFind(nums[index]) == NULL) hashInsert(nums[index]);
        else return true;
    }
    return false;
}