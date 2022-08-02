#include<stdio.h>
#include<stdbool.h>

bool *column;
int *row;

char ***ans;
int *ansColumnSizes;
int ansSize;

void solveNQueensRecursively(int n, int i){
    if (i == n){
        ans[ansSize] = (char**)malloc(sizeof(char*) * n);
        for (int j = 0; j < n; j++){
            ans[ansSize][j] = (char*)malloc(sizeof(char) * (n + 1));
            memset(ans[ansSize][j], '.', sizeof(char) * n);
            ans[ansSize][j][row[j]] = 'Q';
            ans[ansSize][j][n] = '\0';
        }
        ansColumnSizes[ansSize] = n;
        ansSize++;
    }
    else{
        for (int j = 0; j < n; j++){
            if (column[j] == false){
                bool feasible = true;
                for (int k = 0; k < i; k++){
                    if (abs(i - k) == abs(j - row[k])){
                        feasible = false;
                        break;
                    }
                }
                if (feasible){
                    column[j] = true;
                    row[i] = j;
                    solveNQueensRecursively(n, i + 1);
                    column[j] = false;          
                }
            }
        }
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes){
    column = (bool*)malloc(sizeof(bool) * n);
    row = (int*)malloc(sizeof(int) * n);
    memset(column, false, sizeof(bool) * n);

    ans = (char***)malloc(sizeof(char**) * 400);
    ansColumnSizes = (int*)malloc(sizeof(int) * 400);
    ansSize = 0;

    solveNQueensRecursively(n, 0);
    *returnColumnSizes = ansColumnSizes;
    *returnSize = ansSize;
    return ans;
}

void main(){
    int returnSize;
    int *returnColumnSizes;

    for (int n = 1; n < 10; n++){
        solveNQueens(n, &returnSize, &returnColumnSizes);
        printf("%d\n", returnSize);
    }
}