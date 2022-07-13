// Almost directedly copied from:
// https://leetcode.cn/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/

#include<stdio.h>
#include"uthash.h"
// NULL is also defined in this file
// The usage of uthash.h is referred to: https://zhuanlan.zhihu.com/p/340692819
// The installation is referred to: https://blog.csdn.net/a123441/article/details/89045293

/* The following is a brutal solution
int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *ret = (int*)malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
*/

struct hashTable{
    int key;
    int val;
    UT_hash_handle hh;  // makes this structure hashable
};

struct hashTable *hashtable;

struct hashTable *find(int ikey){
    struct hashTable *item;
    HASH_FIND_INT(hashtable, &ikey, item);
    return item;
}

void insert(int ikey, int ival){
    struct hashTable* item = find(ikey);
    if (item == NULL){
        item = malloc(sizeof(struct hashTable));
        item->key = ikey;
        item->val = ival;
        HASH_ADD_INT(hashtable, key, item);
    }
    else{
        item->val = ival;
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    hashtable = NULL;
    for(int i = 0; i < numsSize; i++){
        struct hashTable* item = find(target - nums[i]);
        if (item != NULL){
            int *ret = (int*)malloc(sizeof(int) * 2);
            ret[0] = item->val;
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        else {
            insert(nums[i], i);
        }
    }
    *returnSize = 0;
    return NULL;
}

void main(){
    int nums[4] = {2, 7, 11, 15}, return_size;
    int *ret = (int*)malloc(sizeof(int) * 2);
    ret = twoSum(nums, 4, 9, &return_size);
    printf("[%d,%d]\n", ret[0], ret[1]);
}