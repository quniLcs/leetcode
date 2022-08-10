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

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(char** board, int boardSize, int boardColSize, int** visited, int i, int j, char* s, int sSize, int k) {
    if (board[i][j] != s[k]) {
        return false;
    } else if (k == sSize - 1) {
        return true;
    }
    visited[i][j] = true;
    bool result = false;
    for (int sel = 0; sel < 4; sel++) {
        int newi = i + directions[sel][0], newj = j + directions[sel][1];
        if (newi >= 0 && newi < boardSize && newj >= 0 && newj < boardColSize) {
            if (!visited[newi][newj]) {
                bool flag = check(board, boardSize, boardColSize, visited, newi, newj, s, sSize, k + 1);
                if (flag) {
                    result = true;
                    break;
                }
            }
        }
    }
    visited[i][j] = false;
    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int** visited = malloc(sizeof(int*) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        visited[i] = malloc(sizeof(int) * boardColSize[0]);
        memset(visited[i], 0, sizeof(int) * boardColSize[0]);
    }
    int wordSize = strlen(word);
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            bool flag = check(board, boardSize, boardColSize[0], visited, i, j, word, wordSize, 0);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}