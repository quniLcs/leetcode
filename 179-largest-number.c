#include<stdio.h>

int compare(const void *a, const void *b){
    return -strcmp(*(char**)a, *(char**)b);
}

char *largestNumber(int *nums, int numsSize){
    char **strs = (char**)malloc(sizeof(char*) * numsSize);
    int strSize = 1;

    for (int i = 0; i < numsSize; i += 1){
        strs[i] = (char*)malloc(sizeof(char) * 11);
        int j = 0;
        if (nums[i]){
            while (nums[i]){
                strs[i][j++] = nums[i] % 10 + '0';
                nums[i] /= 10;
            }
            for (int k = 0; k < j / 2; k += 1){
                char temp = strs[i][k];
                strs[i][k] = strs[i][j - k - 1];
                strs[i][j - k - 1] = temp;
            }
            strs[i][j] = '\0';
        }
        else{
            strs[i][j++] = '0';
            strs[i][j] = '\0';
        }
        strSize += j;
        // printf("%s\n", strs[i]);
    }

    char *str = (char*)malloc(sizeof(char) * strSize);
    qsort((void*)strs, (size_t)numsSize, sizeof(char*), compare);

    for (int i = 0, j = 0; i < numsSize; j += strlen(strs[i]), i += 1){
        // printf("%s\n", strs[i]);
        strcpy(str + j, strs[i]);
    }

    return str;
}

void main(){
    int numsSize = 5;
    int *nums = (int*)malloc(sizeof(int) * numsSize);

    nums[0] = 3;
    nums[1] = 30;
    nums[2] = 34;
    nums[3] = 5;
    nums[4] = 9;

    printf("%s\n", largestNumber(nums, numsSize));
}