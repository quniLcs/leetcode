#include<stdio.h>
#include<stdbool.h>

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

void main(){
    int height[4] = {5, 4, 1, 2};
    printf("%d\n", trap(height, 4));
}