#include<stdio.h>
#include<stdbool.h>

bool row[9][9];
bool column[9][9];
bool square[3][3][9];

bool solveSudokuRecursively(char **board, int i, int j){
    while (board[i][j] != '.'){
        if (j < 8) j++;
        else if (i < 8){j = 0; i++;}
        else return true;
    }

    for (int num = 0; num < 9; num++){
        if (!row[i][num] && !column[j][num] && !square[i / 3][j / 3][num]){
            board[i][j] = num + '1';
            row[i][num] = true;
            column[j][num] = true;
            square[i / 3][j / 3][num] = true;

            if (solveSudokuRecursively(board, i, j)){
                return true;
            }

            board[i][j] = '.';
            row[i][num] = false;
            column[j][num] = false;
            square[i / 3][j / 3][num] = false;
        }
    }
    return false;
}

void solveSudoku(char **board, int boardSize, int *boardColSize){
    memset(row, false, sizeof(row));
    memset(column, false, sizeof(column));
    memset(square, false, sizeof(square));

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.'){
                int num = board[i][j] - '1';
                row[i][num] = true;
                column[j][num] = true;
                square[i / 3][j / 3][num] = true;
            }
        }
    }
    solveSudokuRecursively(board, 0, 0);
}

void main(){
    char *board[9] = {"53..7....", "6..195...", ".98....6.",
                      "8...6...3", "4..8.3..1", "7...2...6",
                      ".6....28.", "...419..5", "....8..79"};
    solveSudoku(board, 9, NULL);
}