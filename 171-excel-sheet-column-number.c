#include<stdio.h>

int titleToNumber(char *columnTitle){
    int columnNumber = 0;

    int index = strlen(columnTitle) - 1;
    long exp = 1;
    while (index >= 0){
        columnNumber += (columnTitle[index] - '@') * exp;
        index -= 1;
        exp *= 26;
    }
    
    return columnNumber;
}

void main(){
    printf("%d\n", titleToNumber("FXSHRXW"));
}