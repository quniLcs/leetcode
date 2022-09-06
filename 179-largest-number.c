#include<stdio.h>

int compare(const void *a, const void *b){
    int n = strlen(*(char**)a);
    int m = strlen(*(char**)b);
    char *s = (char*)malloc(sizeof(char) * (m + n + 1));
    char *t = (char*)malloc(sizeof(char) * (m + n + 1));

    strcpy(s, *(char**)a);
    strcpy(t, *(char**)b);
    strcpy(s + n, *(char**)b);
    strcpy(t + m, *(char**)a);

    int c = -strcmp(s, t);
    free(s);
    free(t);    
    return c;
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
    
    qsort((void*)strs, (size_t)numsSize, sizeof(char*), compare);
    if (strs[0][0] == '0' && strs[0][1] == '\0') return "0";

    char *str = (char*)malloc(sizeof(char) * strSize);
    for (int i = 0, j = 0; i < numsSize; j += strlen(strs[i]), i += 1){
        // printf("%s\n", strs[i]);
        strcpy(str + j, strs[i]);
    }
    return str;
}

void main(){
    int numsSize = 2;
    int *nums = (int*)malloc(sizeof(int) * numsSize);

    nums[0] = 0;
    nums[1] = 0;

    printf("%s\n", largestNumber(nums, numsSize));
}