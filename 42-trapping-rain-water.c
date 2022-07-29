#include<stdio.h>
#include<stdbool.h>


/* original awkward solution
bool trapRecursively(int *result, int *height, int heightSize){
    int former = 0;
    bool downward = true;
    bool change = false;

    for (int index = 1; index <= heightSize; index++){
        if (downward && index < heightSize && height[index] > height[index - 1]){
            downward = false;
        }
        else if (!downward && (index == heightSize || height[index] < height[index - 1])){
            // left side: former
            // right side: index - 1
            int heightMax = height[former] < height[index - 1] ? height[former] : height[index - 1];
            for (int current = former + 1; current < index - 1; current++){
                if (heightMax > height[current]){
                    *result += heightMax - height[current];
                    height[current] = heightMax;
                    change = true;
                }
            }
            former = index - 1;
            downward = true;
        }
    }

    return change;
}

int trap(int *height, int heightSize){
    int result = 0;
    while (trapRecursively(&result, height, heightSize));
    return result;
}
*/


// the following solutions are referred to
// https://leetcode.cn/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/
// dynamic programming but buffer overflow
/*
int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

int trap(int *height, int heightSize){
    int *leftMax = (int*)malloc(sizeof(int) * heightSize);
    memset(leftMax, 0, sizeof(leftMax));
    leftMax[0] = height[0];
    for (int index = 1; index < heightSize; index++){
        leftMax[index] = max(leftMax[index - 1], height[index]);
    }

    int *rightMax = (int*)malloc(sizeof(int) * heightSize);
    memset(rightMax, 0, sizeof(rightMax));
    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int index = heightSize - 2; index >= 0; index--){
        rightMax[index] = max(rightMax[index + 1], height[index]);
    }

    int result = 0;
    for (int index = 0; index < heightSize; index++){
        result += min(leftMax[index], rightMax[index]) - height[index];
    }
    return result;
}
*/


// stack
// harder to think of
/*
int min(int a, int b){
    return a < b ? a : b;
}

int trap(int* height, int heightSize){
    int result = 0;

    int *stack = (int*)malloc(sizeof(int) * heightSize);
    int top = 0;

    for (int index = 0; index < heightSize; index++){
        while (top && height[index] > height[stack[top - 1]]){
            top--;
            if (top == 0) break;
            int left = stack[top - 1];
            int widthCurrent = index - left - 1;
            int heightCurrent = min(height[left], height[index]) - height[stack[top]];
            result += widthCurrent * heightCurrent;
        }
        stack[top] = index;
        top++;
    }

    return result;
}
*/


// double pointer
// also hard to think of
int max(int a, int b){
    return a > b ? a : b;
}

int trap(int *height, int heightSize){
    int result = 0;
    
    int left = 0;
    int right = heightSize - 1;
    int leftMax = 0;
    int rightMax = 0;

    while (left < right){
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (leftMax < rightMax){
            result += leftMax - height[left];
            left++;
        }
        else{  // leftMax >= rightMax
            result += rightMax - height[right];
            right--;
        }
    }

    return result;
}


void main(){
    int height[1] = {0};
    printf("%d\n", trap(height, 1));
}