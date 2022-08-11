#include<stdio.h>

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}


/* original code but time limit exceeded
int largestRectangleArea(int *heights, int heightsSize){
    // heightsMin[i][j] means the minimun height in the range [i, i + j]
    // where i = 0, 1, ..., heightsSize - 1
    // and j = 0, 1, ..., heightsSize - i - 1

    int **heightsMin = (int**)malloc(sizeof(int*) * heightsSize);
    for (int i = 0; i < heightsSize; i++){
        heightsMin[i] = (int*)malloc(sizeof(int) * (heightsSize - i));
        heightsMin[i][0] = heights[i];
        for (int j = 1; j < heightsSize - i; j++){
            heightsMin[i][j] = min(heightsMin[i][j - 1], heights[i + j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < heightsSize; i++){
        for (int j = 0; j < heightsSize - i; j++){
            ans = max(ans, heightsMin[i][j] * (j + 1));
        }
    }
    return ans;
}
*/


// monotonous stack with reference to
// https://leetcode.cn/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
int largestRectangleArea(int *heights, int heightsSize){
    int *left = (int*)malloc(sizeof(int) * heightsSize);
    int *right = (int*)malloc(sizeof(int) * heightsSize);
    int *stack = (int*)malloc(sizeof(int) * heightsSize);

    int top = 0;
    for (int i = 0; i < heightsSize; i++){
        while (top > 0 && heights[stack[top - 1]] >= heights[i]) top--;
        left[i] = top > 0 ? stack[top - 1] : -1;
        stack[top++] = i;
        // printf("%d\t", left[i]);
    }
    // printf("\n");

    top = 0;
    for (int i = heightsSize - 1; i >= 0; i--){
        while (top > 0 && heights[stack[top - 1]] >= heights[i]) top--;
        right[i] = top > 0 ? stack[top - 1] : heightsSize;
        stack[top++] = i;
        // printf("%d\t", right[i]);
    }
    // printf("\n");

    int ans = 0;
    for (int i = 0; i < heightsSize; i++){
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
}


void main(){
    int heightsSize = 8;
    int *heights = (int*)malloc(sizeof(int) * heightsSize);

    heights[0] = 6;
    heights[1] = 7;
    heights[2] = 5;
    heights[3] = 2;
    heights[4] = 4;
    heights[5] = 5;
    heights[6] = 9;
    heights[7] = 3;

    largestRectangleArea(heights, heightsSize);
}