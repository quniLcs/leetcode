#include<stdio.h>
#include"uthash.h"

struct hashItem{
    int num;
    int begin;
    int end;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *find(int key){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &key, item);
    return item;
}

int insert(int key){
    struct hashItem *item = find(key);

    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> num = key;
        item -> begin = key;
        item -> end = key;

        struct hashItem *left = find(key - 1);
        struct hashItem *right = find(key + 1);

        if (left) left = find(left -> begin);
        if (right) right = find(right -> end);

        if (left) item -> begin = left -> begin;
        if (right) item -> end = right -> end;

        if (left) left -> end = item -> end;
        if (right) right -> begin = item -> begin;

        HASH_ADD_INT(hashTable, num, item);
    }

    return item -> end - item -> begin + 1;
}

int longestConsecutive(int *nums, int numsSize){
    int max = 0;
    hashTable = NULL;

    for (int index = 0; index < numsSize; index += 1){
        int cur = insert(nums[index]);
        max = max > cur ? max : cur;
    }

    return max;
}