#include<stdio.h>

int *diffWaysToCompute(char *expression, int *returnSize){
    // turn the string to operands and operators
    int index = 0;
    int length = strlen(expression);

    int *operand = (int*)malloc(sizeof(int) * ((length + 1) / 2));
    int *operator = (int*)malloc(sizeof(int) * (length / 2));
    int operandSize = 0;
    int operatorSize = 0;

    while (index < length){
        if (expression[index] >= '0' && expression[index] <= '9'){
            operand[operandSize] = expression[index++] - '0';
            if (expression[index] >= '0' && expression[index] <= '9'){
                operand[operandSize] = operand[operandSize] * 10 + (expression[index++] - '0');
            }
            operandSize++;
        }
        else{
            operator[operatorSize] = expression[index++];
            operatorSize++;
        }
    }

    // dynamic programming
    // ans[row][col] means starting from operand col, and the number of operator is row
    // 0 <= row <= operatorSize or 0 <= row < operandSize
    // 0 <= col < operandSize - row

    int ***ans = (int***)malloc(sizeof(int**) * operandSize);
    int **ansSize = (int**)malloc(sizeof(int*) * operandSize);

    for (int row = 0; row < operandSize; row += 1){
        ans[row] = (int**)malloc(sizeof(int*) * (operandSize - row));
        ansSize[row] = (int*)malloc(sizeof(int) * (operandSize - row));
        for (int col = 0; col < operandSize - row; col += 1){
            if (row == 0){
                ansSize[row][col] = 1;
                ans[row][col] = (int*)malloc(sizeof(int));
                ans[row][col][0] = operand[col];
            }
            else{
                ansSize[row][col] = 0;
                for (int split = 1; split <= row; split += 1){
                    ansSize[row][col] += ansSize[split - 1][col] * ansSize[row - split][col + split];
                }
                ans[row][col] = (int*)malloc(sizeof(int) * ansSize[row][col]);
                for (int split = 1, cur = 0; split <= row; split += 1){
                    for (int left = 0; left < ansSize[split - 1][col]; left += 1){
                        for (int right = 0; right < ansSize[row - split][col + split]; right += 1){
                            switch (operator[col + split - 1]){
                                case '+': ans[row][col][cur++] = ans[split - 1][col][left] + ans[row - split][col + split][right]; break;
                                case '-': ans[row][col][cur++] = ans[split - 1][col][left] - ans[row - split][col + split][right]; break;
                                default: ans[row][col][cur++] = ans[split - 1][col][left] * ans[row - split][col + split][right];
                            }
                        }
                    }
                }
            }
        }
    }

    *returnSize = ansSize[operatorSize][0];
    return ans[operatorSize][0];
}

void main(){
    int returnSize = 0;
    int *result = diffWaysToCompute("11", &returnSize);

    for (int index = 0; index < returnSize; index += 1){
        printf("%d\t", result[index]);
    }
    printf("\n");
}