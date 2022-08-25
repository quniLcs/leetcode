#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(char *s, int n){
    for (int i = 0, j = n - 1; i < j; i += 1, j -= 1){
        if (s[i] != s[j]) return false;
    }
    return true;
}


char ***ans;
int *ansColumnSize;
int ansSize;

char **cur;
int curSize;

void partitionRecursively(char *s){
    int n = strlen(s);

    if (n == 0){
        ans[ansSize] = (char**)malloc(sizeof(char*) * curSize);
        for (int i = 0; i < curSize; i += 1){
            ans[ansSize][i] = (char*)malloc(sizeof(char) * (strlen(cur[i]) + 1));
            strcpy(ans[ansSize][i], cur[i]);
        }
        ansColumnSize[ansSize] = curSize;
        ansSize += 1;
    }
    else{
        for (int i = 1; i <= n; i += 1){
            if (isPalindrome(s, i)){
                strncpy(cur[curSize], s, i);
                cur[curSize][i] = '\0';
                curSize += 1;
                partitionRecursively(s + i);
                curSize -= 1;
            }
        }
    }
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes){
    int n = strlen(s);

    ans = (char***)malloc(sizeof(char**) * (1 << (n - 1)));
    ansColumnSize = (int*)malloc(sizeof(int) * (1 << (n - 1)));
    ansSize = 0;

    cur = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i += 1){
        cur[i] = (char*)malloc(sizeof(char) * (n + 1));
    }
    curSize = 0;

    partitionRecursively(s);

    *returnColumnSizes = ansColumnSize;
    *returnSize = ansSize;
    return ans;
}


void main(){
    int returnSize;
    int *returnColumnSizes;
    char ***result = partition("dddddddddd", &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i += 1){
        for (int j = 0; j < returnColumnSizes[i]; j += 1){
            printf("%s\t", result[i][j]);
        }
        printf("\n");
    }
}