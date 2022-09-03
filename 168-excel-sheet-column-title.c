#include<stdio.h>

char *convertToTitle(int columnNumber){
    char *columnTitle = (char*)malloc(sizeof(char) * 8);

    int length = 0;
    while (columnNumber){
        int remainder = columnNumber % 26;
        int singleNumber = remainder ? remainder : 26;
        columnNumber = (columnNumber - singleNumber) / 26;
        columnTitle[length++] = singleNumber + '@';
    }
    columnTitle[length] = '\0';

    for (int index = 0; index < length / 2; index++){
        int reverse = length - index - 1;
        char temp = columnTitle[index];
        columnTitle[index] = columnTitle[reverse];
        columnTitle[reverse] = temp;
    }

    return columnTitle;
}

void main(){
    printf("%s\n", convertToTitle(28));
}