#include<stdbool.h>
#include<assert.h>

bool existHere(char **board, bool **visit, int m, int n, int i, int j, char *word, int k){
    if (word[k]){
        visit[i][j] = true;
        if (i > 0 && board[i - 1][j] == word[k] && !visit[i - 1][j] && existHere(board, visit, m, n, i - 1, j, word, k + 1)) return true;
        else if (i < m - 1 && board[i + 1][j] == word[k] && !visit[i + 1][j] && existHere(board, visit, m, n, i + 1, j, word, k + 1)) return true;
        else if (j > 0 && board[i][j - 1] == word[k] && !visit[i][j - 1] && existHere(board, visit, m, n, i, j - 1, word, k + 1)) return true;
        else if (j < n - 1 && board[i][j + 1] == word[k] && !visit[i][j + 1] && existHere(board, visit, m, n, i, j + 1, word, k + 1)) return true;
        else {visit[i][j] = false; return false;}
    }
    else{
        return true;
    }
}

bool exist(char **board, int boardSize, int *boardColSize, char *word){
    int m = boardSize;
    int n = boardColSize[0];
    for (int i = 1; i < m; i++){
        assert(boardColSize[i] == n);
    }

    bool **visit = (bool**)malloc(sizeof(bool*) * m);
    for (int i = 0; i < m; i++){
        visit[i] = (bool*)malloc(sizeof(bool) * n);
        memset(visit[i], false, sizeof(bool) * n);
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j] == word[0] && existHere(board, visit, m, n, i, j, word, 1)) return true;           
        }
    }
    return false;
}