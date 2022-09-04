#include<stdio.h>

int titleToNumber(char *columnTitle){
    int columnNumber = 0;
    for (int index = strlen(columnTitle) - 1, exp = 1; index >= 0; index -= 1){
        exp *= 26;
        columnNumber += (columnTitle[index] - '@') * exp;
    }
    return columnNumber;
}

void main(){
    printf("%d\n", titleToNumber("FXSHRXW"));
}