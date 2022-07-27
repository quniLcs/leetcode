#include<stdbool.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize){
    // check rows
    for (int i = 0; i < 9; i++){
        bool nums[9] = {false};
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.'){
                int num = board[i][j] - '1';
                if (nums[num]) return false;
                else nums[num] = true;
            }
        }
    }

    // check columns
    for (int j = 0; j < 9; j++){
        bool nums[9] = {false};
        for (int i = 0; i < 9; i++){
            if (board[i][j] != '.'){
                int num = board[i][j] - '1';
                if (nums[num]) return false;
                else nums[num] = true;
            }
        }
    }
    
    // check squares
    for (int m = 0; m < 3; m++){
        for (int n = 0; n < 3; n++){
            bool nums[9] = {false};
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (board[3 * m + i][3 * n + j] != '.'){
                        int num = board[3 * m + i][3 * n + j] - '1';
                        if (nums[num]) return false;
                        else nums[num] = true;
                    }
                }
            }
        }
    }

    return true;
}