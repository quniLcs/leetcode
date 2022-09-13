#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    int kk;
    int vv;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int num){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &num, item);
    return item;
}

void hashInsert(int num, int index){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item -> kk = num;
    item -> vv = index;
    HASH_ADD_INT(hashTable, kk, item);
}

bool hashUpdate(struct hashItem *item, int index, int k){
    if (index - item -> vv <= k) return false;
    else item -> vv = index; return true;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    hashTable = NULL;
    for (int index = 0; index < numsSize; index += 1){
        struct hashItem *item = hashFind(nums[index]);
        if (item == NULL) hashInsert(nums[index], index);
        else if (!hashUpdate(item, index, k)) return true;
    }
    return false;
}