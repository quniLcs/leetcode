#include<stdbool.h>

bool canJump(int* nums, int numsSize){
    int end = 0;
    int next = 0;

    for (int i = 0; i < numsSize - 1; i++){
        next = next > i + nums[i] ? next : i + nums[i];
        if (i == end){
            if (end == next) return false;
            else end = next;
        }
    }

    return true;
}