#include<stdio.h>

int *plusOne(int *digits, int digitsSize, int *returnSize){
    int *result = (int*)malloc(sizeof(int) * (digitsSize + 1)); 
    memcpy(result + 1, digits, sizeof(int) * digitsSize);
    result[0] = 0;

    int index = digitsSize;
    while (result[index] == 9){
        result[index] = 0;
        index--;
    }
    result[index]++;

    if (result[0]){
        *returnSize = digitsSize + 1;
        return result;
    }
    else{
        *returnSize = digitsSize;
        return result + 1;
    }
}

void main(){
    int digits[] = {1, 2, 3};
    int returnSize = 0;
    int *result = plusOne(digits, 3, &returnSize);

    for (int index = 0; index < returnSize; index++){
        printf("%d\t", result[index]);
    }
    printf("\n");
}