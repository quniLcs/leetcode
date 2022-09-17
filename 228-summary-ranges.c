#include<stdbool.h>
#define INT_MIN -2147483648

char *num2str(int num){
    if (num == 0) return "0";
    if (num == INT_MIN) return "-2147483648";

    char *str = (char*)malloc(sizeof(char) * 12);
    int i = 0;

    bool neg = false;
    if (num < 0){
        neg = true;
        num = -num;
        str[i++] = '-';
    }
    
    while (num){
        str[i++] = '0' + num % 10;
        num /= 10;
    }
    str[i--] = '\0';

    for (int j = neg ? 1 : 0; j < i; j++, i--){
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

char **summaryRanges(int *nums, int numsSize, int *returnSize){
    char **result = (char**)malloc(sizeof(char*) * numsSize);
    *returnSize = 0;

    for (int i = 0, j = 1; j <= numsSize; j += 1){
        if (j == numsSize || nums[j] != nums[j - 1] + 1){
            if (j - 1 == i){
                result[*returnSize] = num2str(nums[i]);
                *returnSize += 1;
            }
            else{
                char *a = num2str(nums[i]);
                char *b = num2str(nums[j - 1]);
                int p = strlen(a);
                int q = strlen(b);
                result[*returnSize] = (char*)malloc(sizeof(char) * (p + q + 3));
                strncpy(result[*returnSize], a, p);
                strncpy(result[*returnSize] + p + 2, b, q);
                result[*returnSize][p] = '-';
                result[*returnSize][p + 1] = '>';
                result[*returnSize][p + q + 2] = '\0';
                *returnSize += 1;
            }
            i = j;
        }
    }

    return result;
}