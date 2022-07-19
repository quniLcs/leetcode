// Almost directly copied from:
// https://leetcode.cn/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/


#include<stdio.h>
#include<stdbool.h>


/*
bool isValid(char *string){
    int balance = 0;
    int length = strlen(string);

    for (int index = 0; index < length; index++){
        if (string[index] == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

void generateAll(char *current, int length, int n, char **result, int *returnSize){
    if (n == length){
        if (isValid(current)){
            result[*returnSize] = (char*)malloc(sizeof(char) * (n + 1));
            strcpy(result[*returnSize], current);
            (*returnSize)++;
        }
    }
    else{
        current[length] = '(';
        current[length + 1] = '\0';
        generateAll(current, length + 1, n, result, returnSize);
        current[length] = ')';
        generateAll(current, length + 1, n, result, returnSize);
        current[length] = '\0';
    }
}

char **generateParenthesis(int n, int *returnSize){
    char **result = (char**)malloc(sizeof(char*) * 16384);
    char *current = (char*)malloc(sizeof(char) * 17);
    *returnSize = 0;
    generateAll(current, 0, 2 * n, result, returnSize);
    return result;
}
*/


/* backtrack but heap overflow
void backTrack(char *current, int left, int right, int n, char **result, int *returnSize){
    if (strlen(current) == 2 * n){
        result[*returnSize] = (char*)malloc(sizeof(char) * (2 * n + 1));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
    }
    else{
        if (left < n){
            int length = left + right;
            current[length] = '(';
            current[length + 1] = '\0';
            backTrack(current, left + 1, right, n, result, returnSize);
            current[length] = '\0';
        }
        if (left > right){
            int length = left + right;
            current[length] = ')';
            current[length + 1] = '\0';
            backTrack(current, left, right + 1, n, result, returnSize);
            current[length] = '\0';
        }
    }
}

char **generateParenthesis(int n, int *returnSize){
    char **result = (char**)malloc(sizeof(char*) * 16384);
    char *current = (char*)malloc(sizeof(char) * 17);
    *returnSize = 0;
    backTrack(current, 0, 0, n, result, returnSize);
    return result;
}
*/


char **cache[9];
int cacheSize[9] = {0};

void generateParenthesisRecursively(int n){
    if (cacheSize[n] == 0){
        cache[n] = (char**)malloc(sizeof(char*) * 16384);

        if (n == 0){
            cache[0][0] = (char*)malloc(sizeof(char));
            strcpy(cache[0][0], "");
            cacheSize[0] = 1;
        }
        else{
            for (int i = 0; i < n; i++){
                generateParenthesisRecursively(i);
                generateParenthesisRecursively(n - i - 1);
                for (int j = 0; j < cacheSize[i]; j++){
                    for (int k = 0; k < cacheSize[n - i - 1]; k++){
                        cache[n][cacheSize[n]] = (char*)malloc(sizeof(char) * (2 * n + 1));
                        strcpy(cache[n][cacheSize[n]], "(");
                        strcpy(cache[n][cacheSize[n]] + 1, cache[i][j]);
                        strcpy(cache[n][cacheSize[n]] + 1 + 2 * i, ")");
                        strcpy(cache[n][cacheSize[n]] + 2 + 2 * i, cache[n - i - 1][k]);
                        cacheSize[n]++;
                    }
                }
            }
        }
    }    
}

char **generateParenthesis(int n, int *returnSize){
    generateParenthesisRecursively(n);
    *returnSize = cacheSize[n];
    return cache[n];
}


void main(){
    int returnSize = 0;
    char **result = generateParenthesis(3, &returnSize);

    for (int index = 0; index < returnSize; index++){
        printf("%s\n", result[index]);
    }
}