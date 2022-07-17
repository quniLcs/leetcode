// completely independently written

#include<stdio.h>

/*
2 abc
3 def
4 ghi
5 jkl
6 mno
7 pqrs
8 tuv
9 wxyz
*/

char **letterCombinations(char *digits, int *returnSize){
    char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **ans = (char**)malloc(sizeof(char*) * 256);
    *returnSize = 0;

    int n = strlen(digits);
    if (n > 0){
        int digit = digits[0] - '0';
        int repetition = strlen(map[digit]);
        for (int k = 0; k < repetition; k++){
            ans[k] = (char*)malloc(sizeof(char) * 5);
            ans[k][0] = map[digit][k];
            ans[k][1] = '\0';
        }
        *returnSize = repetition;
    }
    for (int i = 1; i < n; i++){
        int digit = digits[i] - '0';
        int repetition = strlen(map[digit]);
        for (int j = 0; j < *returnSize; j++){
            for (int k = 1; k < repetition; k++){
                ans[j + k * (*returnSize)] = (char*)malloc(sizeof(char) * 5);
                strcpy(ans[j + k * (*returnSize)], ans[j]);
            }
        }
        for (int j = 0; j < *returnSize; j++){
            for (int k = 0; k < repetition; k++){
                ans[j + k * (*returnSize)][i] = map[digit][k];
                ans[j + k * (*returnSize)][i + 1] = '\0';
            }
        }
        *returnSize *= repetition;
    }

    return ans;
}

void main(){
    int returnSize = 0;
    char **ans = (char**)malloc(sizeof(char*) * 256);
    ans = letterCombinations("23", &returnSize);
}