#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

bool **keep;

void search(char **board, int i, int j, int m, int n){
    if (i + 1 < m && board[i + 1][j] == 'O' && !keep[i + 1][j]){
        keep[i + 1][j] = true;
        search(board, i + 1, j, m, n);
    }

    if (i > 0 && board[i - 1][j] == 'O' && !keep[i - 1][j]){
        keep[i - 1][j] = true;
        search(board, i - 1, j, m, n);
    }

    if (j + 1 < n && board[i][j + 1] == 'O' && !keep[i][j + 1]){
        keep[i][j + 1] = true;
        search(board, i, j + 1, m, n);
    }

    if (j > 0 && board[i][j - 1] == 'O' && !keep[i][j - 1]){
        keep[i][j - 1] = true;
        search(board, i, j - 1, m, n);
    }
}

void solve(char **board, int boardSize, int *boardColSize){
    int m = boardSize;
    int n = boardColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(boardColSize[i] == n);
    }

    // initialize
    keep = (bool**)malloc(sizeof(bool*) * m);
    for (int i = 0; i < m; i += 1){
        keep[i] = (bool*)malloc(sizeof(bool) * n);
        memset(keep[i], false, sizeof(bool) * n);
    }

    // search
    for (int j = 0; j < n; j += 1){
        if (board[0][j] == 'O' && !keep[0][j]){
            keep[0][j] = true;
            search(board, 0, j, m, n);
        }
    }
    
    for (int i = 1; i < m; i += 1){
        if (board[i][0] == 'O' && !keep[i][0]){
            keep[i][0] = true;
            search(board, i, 0, m, n);
        }
    }

    for (int j = 1; j < n; j += 1){
        if (board[m - 1][j] == 'O' && !keep[m - 1][j]){
            keep[m - 1][j] = true;
            search(board, m - 1, j, m, n);
        }
    }

    for (int i = 1; i < m - 1; i += 1){
        if (board[i][n - 1] == 'O' && !keep[i][n - 1]){
            keep[i][n - 1] = true;
            search(board, i, n - 1, m, n);        
        }
    }

    // edit
    for (int i = 1; i < m - 1; i += 1){
        for (int j = 1; j < n - 1; j += 1){
            if (board[i][j] == 'O' && !keep[i][j]){
                board[i][j] = 'X';
            }
        }
    }    
}

void main(){
    char *line = "O";
    int m = 1;
    int n = 1;

    solve(&line, m, &n);
    printf("%s\n", line);
}