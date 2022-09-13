// almost directly copied from
// https://leetcode.cn/problems/contains-duplicate-iii/solution/cun-zai-zhong-fu-yuan-su-iii-by-leetcode-bbkt/

#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    int kk;
    int vv;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(int key){
    struct hashItem *item;
    HASH_FIND_INT(hashTable, &key, item);
    return item;
}

void hashInsert(int key, int num){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item -> kk = key;
    item -> vv = num;
    HASH_ADD_INT(hashTable, kk, item);
}

void hashDelete(int key){
    struct hashItem *item = hashFind(key);
    HASH_DEL(hashTable, item);
}

int getBucket(int num, int width){
    if (num >= 0) return num / width;
    else return (num + 1) / width - 1; 
}

int diff(int a, int b){
    if (a >= b) return a - b;
    else return b - a;
}

bool checkOne(int key, int num, int t){
    struct hashItem *item;
    
    item = hashFind(key);
    if (item) return true;
    item = hashFind(key - 1);
    if (item && diff(num, item -> vv) <= t) return true;
    item = hashFind(key + 1);
    if (item && diff(num, item -> vv) <= t) return true;

    return false;
}

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t){
    hashTable = NULL;
    int width = t ? t : 1;
    for (int index = 0; index < numsSize; index += 1){
        int key = getBucket(nums[index], width);
        if (checkOne(key, nums[index], t)) return true;
        else hashInsert(key, nums[index]);
        if (index >= k) hashDelete(getBucket(nums[index - k], width));        
    }
    return false;
}