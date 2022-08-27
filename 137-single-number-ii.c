// almost directly copied from
// https://leetcode.cn/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/

/*
int singleNumber(int *nums, int numsSize){
    int a = 0;
    int b = 0;

    for (int i = 0; i < numsSize; i += 1){
        int aTemp = (~a & b & nums[i]) | (a & ~b & ~nums[i]);
        int bTemp = ~a & (b ^ nums[i]);
        a = aTemp;
        b = bTemp;
    }

    return b;
}
*/

int singleNumber(int *nums, int numsSize){
    int a = 0;
    int b = 0;

    for (int i = 0; i < numsSize; i++) {
        b = ~a & (b ^ nums[i]);
        a = ~b & (a ^ nums[i]);
    }

    return b;
}