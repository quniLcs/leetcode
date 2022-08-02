#include<stdio.h>
#include<stdbool.h>

bool *column;
int *row;
int ansSize;

void solveNQueensRecursively(int n, int i){
    if (i == n){
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

int totalNQueens(int n){
    column = (bool*)malloc(sizeof(bool) * n);
    row = (int*)malloc(sizeof(int) * n);
    memset(column, false, sizeof(bool) * n);
    ansSize = 0;

    solveNQueensRecursively(n, 0);
    return ansSize;
}

void main(){
    for (int n = 1; n < 10; n++){
        printf("%d\n", totalNQueens(n));
    }
}


/*
int totalNQueens(int n){
    switch (n){
        case 1: return 1;
        case 2: return 0;
        case 3: return 0;
        case 4: return 2;
        case 5: return 10;
        case 6: return 4;
        case 7: return 40;
        case 8: return 92;
        case 9: return 352;
        default: return -1;
    }
}
*/